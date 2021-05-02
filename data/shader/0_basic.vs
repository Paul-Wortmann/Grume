#version 330 core
const int MAX_BONES        = 128; // This has to match defines.hpp !!!!

layout (location = 0) in vec3  position;
layout (location = 1) in vec3  normal;
layout (location = 2) in vec2  texcoord;
layout (location = 3) in vec3  tangent;
layout (location = 4) in vec3  bitangent;
layout (location = 5) in vec4  boneWeights;
layout (location = 6) in ivec4 boneID;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

uniform int  animationEnabled;
uniform mat4 boneMatrix[MAX_BONES];

out vec2 vs_textcoord;

void main()
{
    // Bone transforms
    mat4 boneTransform = mat4(1);
    if (animationEnabled > 0)
    {
        boneTransform  = boneMatrix[boneID[0]] * boneWeights[0];
        boneTransform += boneMatrix[boneID[1]] * boneWeights[1];
        boneTransform += boneMatrix[boneID[2]] * boneWeights[2];
        boneTransform += boneMatrix[boneID[3]] * boneWeights[3];
    }
    vec4 tPosition = boneTransform * vec4(position, 1.0);

    vs_textcoord = texcoord;
    gl_Position  = projectionMatrix * viewMatrix * modelMatrix * vec4(tPosition.xyz, 1.0);
}

