#version 330 core
const int MAX_POINT_LIGHTS =  4; // !!! HAS to to match graphics_engine_defines.hpp - MAX_LIGHTS
const int MAX_BONES        = 128; // This has to match defines.hpp !!!!

layout (location = 0) in vec3  position;
layout (location = 1) in vec3  normal;
layout (location = 2) in vec2  texcoord;
layout (location = 3) in vec3  tangent;
layout (location = 4) in vec3  bitangent;
layout (location = 5) in vec4  boneWeights;
layout (location = 6) in ivec4 boneID;

uniform int  billboard;

uniform int  animationEnabled;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform vec3 cameraPosition;
uniform vec3 lightPosition[MAX_POINT_LIGHTS];
uniform mat4 directionalLightMatrix;
uniform mat4 boneMatrix[MAX_BONES];

out vec3 vs_fragPosition;
out vec2 vs_textcoord;
out vec3 vs_normal;
out vec3 vs_cameraPosition;
out vec3 vs_lightPosition[MAX_POINT_LIGHTS];
out vec3 vs_tangentfragPosition;
out vec3 vs_tangentCameraPosition;
out vec3 vs_tangentLightPosition[MAX_POINT_LIGHTS];
out vec4 vs_directionalLightSpace;
flat out int  vs_billboard;

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
    vec3 tNormal   = (boneTransform * vec4(normal, 1.0)).xyz;
    vec3 tTangent  = (boneTransform * vec4(tangent, 1.0)).xyz;

    mat3 normalMatrix = transpose(inverse(mat3(modelMatrix)));

    vs_fragPosition = vec3(modelMatrix * vec4(tPosition.xyz, 1.0));
    vs_textcoord = texcoord;
    vs_normal = normalMatrix * tNormal;
    vs_cameraPosition = cameraPosition;
    vs_directionalLightSpace = directionalLightMatrix * vec4(vs_fragPosition, 1.0);

    vec3 T = normalize(normalMatrix * tTangent);
    vec3 N = normalize(normalMatrix * tNormal);
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);
    
    mat3 TBN = transpose(mat3(T, B, N));
    vs_tangentCameraPosition  = TBN * cameraPosition;
    vs_tangentfragPosition  = TBN * vs_fragPosition;

    for(int i = 0; i < MAX_POINT_LIGHTS; i++)
    {
        vs_lightPosition[i] = lightPosition[i];
        vs_tangentLightPosition[i] = TBN * lightPosition[i];
    }
        
    mat4 modelViewMatrix = viewMatrix * modelMatrix;
    vs_billboard = billboard;
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

        gl_Position = projectionMatrix * modelViewMatrix * vec4(tPosition.xyz, 1.0);
    }
    else
    {
        gl_Position = projectionMatrix * viewMatrix * vec4(vs_fragPosition, 1.0);
    }
}
