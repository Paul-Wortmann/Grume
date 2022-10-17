#version 330 core
const int MAX_BONES        = 140; // This has to match defines.hpp !!!!

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

uniform int  billboard;

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
    
    mat4 modelViewMatrix = viewMatrix * modelMatrix;
    
    if (billboard > 0)
    {
        float mx = length(vec3(modelViewMatrix[0][0], modelViewMatrix[0][1], modelViewMatrix[0][2]));
        float my = length(vec3(modelViewMatrix[1][0], modelViewMatrix[1][1], modelViewMatrix[1][2]));
        float mz = length(vec3(modelViewMatrix[2][0], modelViewMatrix[2][1], modelViewMatrix[2][2]));
    
        modelViewMatrix[0][0] = mx;
        modelViewMatrix[0][1] = 0;
        modelViewMatrix[0][2] = 0;
        modelViewMatrix[1][0] = 0;
        modelViewMatrix[1][1] = my;
        modelViewMatrix[1][2] = 0;
        modelViewMatrix[2][0] = 0;
        modelViewMatrix[2][1] = 0;
        modelViewMatrix[2][2] = mz;
    }
    
    gl_Position  = projectionMatrix * modelViewMatrix * vec4(tPosition.xyz, 1.0);
}

