#version 330 core

const int   MAX_BONES        = 140; // This has to match defines.hpp !!!!
const float PI               = 3.14159274;

layout (location = 0) in vec3  position;
layout (location = 1) in vec3  normal;
layout (location = 2) in vec2  texcoord;
layout (location = 3) in vec3  tangent;
layout (location = 4) in vec3  bitangent;
layout (location = 5) in vec4  boneWeights;
layout (location = 6) in ivec4 boneID;

uniform mat4  modelMatrix;
uniform mat4  viewMatrix;
uniform mat4  projectionMatrix;

uniform int   animationEnabled;
uniform mat4  boneMatrix[MAX_BONES];

uniform int   billboard;

uniform float time;
uniform float flexibility;

out vec2 vs_textcoord;

vec4 windEffect(vec4 _worldPos)
{
    vec4 worldPos = _worldPos;
    float amplitude = worldPos.y * flexibility;
    float wave_1 = sin(2.0 * PI * time + (worldPos.z + worldPos.x) * 0.8);
    float wave_2 = sin(2.0 * PI * time + (worldPos.z + worldPos.x) * 2.0);
    worldPos.x += (wave_1 + wave_2 * 0.4) * 0.06 * amplitude;
    worldPos.z -= (wave_1 - wave_2 * 0.4) * 0.03 * amplitude;
    return worldPos;
}

void main()
{
    // wind effect
    vec4 windPos = vec4(position, 1.0);
    if (flexibility > 0.001)
    {
        windPos = windEffect(windPos);
    }

    // Bone transforms
    mat4 boneTransform = mat4(1);
    if (animationEnabled > 0)
    {
        boneTransform  = boneMatrix[boneID[0]] * boneWeights[0];
        boneTransform += boneMatrix[boneID[1]] * boneWeights[1];
        boneTransform += boneMatrix[boneID[2]] * boneWeights[2];
        boneTransform += boneMatrix[boneID[3]] * boneWeights[3];
    }
    vec4 tPosition = boneTransform * windPos;
    
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
   
    // Output     
    vs_textcoord = texcoord;
    gl_Position  = projectionMatrix * modelViewMatrix * vec4(tPosition.xyz, 1.0);
}

