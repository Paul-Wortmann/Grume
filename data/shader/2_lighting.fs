#version 330 core

// To the frame buffer
layout(location = 0) out vec4 fragColor;

// Lights
const int MAX_POINT_LIGHTS = 4; // !!! HAS to to match graphics_engine_defines.hpp - MAX_LIGHTS

// From the vertex shader
in vec3 vs_fragPosition;
in vec2 vs_textcoord;
in vec3 vs_normal;
in vec3 vs_cameraPosition;
in vec3 vs_lightPosition[MAX_POINT_LIGHTS];
in vec3 vs_tangentfragPosition;
in vec3 vs_tangentCameraPosition;
in vec3 vs_tangentLightPosition[MAX_POINT_LIGHTS];
in vec4 vs_directionalLightSpace;

// Material
struct sMaterial
{
    samplerCube depthCube[MAX_POINT_LIGHTS];
    sampler2D   depthMap;
    sampler2D   diffuse;
    sampler2D   normal;
    sampler2D   specular;
    float       shininess;
};
uniform sMaterial material;

// These structs needs to match the data frond in graphics_engine_light_define.hpp
struct sPointLight
{
    int     enabled;

    vec3    ambient;
    vec3    diffuse;
    vec3    specular;

    float   constant;
    float   linear;
    float   quadratic;
};
uniform sPointLight pointLight[MAX_POINT_LIGHTS];

struct sDirectionalLight
{
    int     enabled;

    vec3    ambient;
    vec3    diffuse;
    vec3    specular;

    vec3    direction;
};
uniform sDirectionalLight directionalLight;

// Shadow
uniform float farPlane;

// The array of offset directions for sampling the depthcubeMap
vec3 gridSamplingDisk[20] = vec3[]
(
   vec3(1, 1,  1), vec3( 1, -1,  1), vec3(-1, -1,  1), vec3(-1, 1,  1), 
   vec3(1, 1, -1), vec3( 1, -1, -1), vec3(-1, -1, -1), vec3(-1, 1, -1),
   vec3(1, 1,  0), vec3( 1, -1,  0), vec3(-1, -1,  0), vec3(-1, 1,  0),
   vec3(1, 0,  1), vec3(-1,  0,  1), vec3( 1,  0, -1), vec3(-1, 0, -1),
   vec3(0, 1,  1), vec3( 0, -1,  1), vec3( 0, -1, -1), vec3( 0, 1, -1)
);

// Function prototypes
float ShadowCalculation(int _lightNum);
float ShadowCalculation2(int _lightNum);
vec3  PointLightCalculation(int _lightNum, vec3 _normal);

void main()
{
    vec4 diffuseColor = texture(material.normal, vs_textcoord).rgba;
    if (diffuseColor.a < 0.1f)
    {
        discard;
    }

    vec3 normal = texture(material.normal, vs_textcoord).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    vec3 result = vec3(0.0f, 0.0f, 0.0f);

    if (directionalLight.enabled > 0)
    {
        //result += DirectionalLightCalculation(directionalLight, normal);
    }

    for(int i = 0; i < MAX_POINT_LIGHTS; i++)
    {
        if (pointLight[i].enabled > 0)
        {
            result += PointLightCalculation(i, normal);
        }
    }   

    fragColor = vec4(result, 1.0);
}


float ShadowCalculation2(int _lightNum)
{
    vec3 fragToLight = vs_fragPosition - vs_lightPosition[_lightNum];
    float closestDepth = texture(material.depthCube[_lightNum], fragToLight).r;
    closestDepth *= farPlane;
    float currentDepth = length(fragToLight);
    float bias = 0.05; 
    float shadow = currentDepth - bias > closestDepth ? 1.0 : 0.0;

    return shadow;
}

float ShadowCalculation(int _lightNum)
{
    vec3 fragToLight = vs_fragPosition - vs_lightPosition[_lightNum];
    float currentDepth = length(fragToLight);
    float shadow = 0.0;
    float bias = 0.15;
    int samples = 20;
    float viewDistance = length(vs_cameraPosition - vs_fragPosition);
    float diskRadius = (1.0 + (viewDistance / farPlane)) / 25.0;
    for(int i = 0; i < samples; ++i)
    {
        float closestDepth = texture(material.depthCube[_lightNum], fragToLight + gridSamplingDisk[i] * diskRadius).r;
        closestDepth *= farPlane;   // undo mapping [0;1]
        if(currentDepth - bias > closestDepth)
            shadow += 1.0;
    }
    shadow /= float(samples);

    return shadow;
}

vec3 PointLightCalculation(int _lightNum, vec3 _normal)
{
    // ambient
    vec3 ambient = pointLight[_lightNum].ambient * 0.1 * texture(material.diffuse, vs_textcoord).rgb;
   
    // diffuse
    vec3 lightDir = normalize(vs_tangentLightPosition[_lightNum] - vs_tangentfragPosition);
    float diff = max(dot(lightDir, _normal), 0.0);
    vec3 diffuse = pointLight[_lightNum].diffuse * diff * texture(material.diffuse, vs_textcoord).rgb;
    
    // specular
    vec3 viewDir = normalize(vs_tangentCameraPosition - vs_tangentfragPosition);
    vec3 reflectDir = reflect(-lightDir, _normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);  
    float spec = pow(max(dot(_normal, halfwayDir), 0.0), material.shininess);
    vec3 specular = pointLight[_lightNum].specular * spec * texture(material.specular, vs_textcoord).rgb; 
    //vec3 specular = vec3(0.2) * spec;

    // Attenuation
    float distance    = length(vs_tangentLightPosition[_lightNum] - vs_tangentfragPosition);
    float attenuation = 1.0 / (pointLight[_lightNum].constant + pointLight[_lightNum].linear * distance + pointLight[_lightNum].quadratic * (distance * distance));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

    // calculate shadow
    float shadow = ShadowCalculation(_lightNum);

    return (ambient + diffuse + specular) * (1.0 - shadow);
}





















