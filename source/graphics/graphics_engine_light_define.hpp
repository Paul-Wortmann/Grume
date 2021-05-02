
#ifndef GRAPHICS_ENGINE_LIGHT_DEFINE_HPP
#define GRAPHICS_ENGINE_LIGHT_DEFINE_HPP

#include "../includes.hpp"

#define MAX_POINT_LIGHTS 4 // This HAS to match the shader!

// Hold data for each point light
struct sGraphicsEnginePointLight
{
    // Linked list management
    sGraphicsEnginePointLight* next = nullptr;

    // Data - needs to match the shader
    uint32    enabled      = 0; // 0 == disabled, 1 >= enabled

    glm::vec3 position     = glm::vec3(0.0f, 0.0f, 0.0f);

    float32   constant     = 0.0f;
    float32   linear       = 0.0f;
    float32   quadratic    = 0.0f;

    glm::vec3 ambient      = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 diffuse      = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 specular     = glm::vec3(0.0f, 0.0f, 0.0f);
};

// Uniform shader locations for a point light
struct sGraphicsEnginePointLightLocation
{
    uint32    enabled      = 0;
    uint32    position     = 0;
    uint32    constant     = 0;
    uint32    linear       = 0;
    uint32    quadratic    = 0;
    uint32    ambient      = 0;
    uint32    diffuse      = 0;
    uint32    specular     = 0;
};

// Hold data for a directional light
struct sGraphicsEngineDirectionalLight
{
    // Data - needs to match the shader
    uint32    enabled      = 1; // 0 == disabled, 1 >= enabled
    glm::vec3 direction    = glm::vec3(0.0f, 0.0f, 0.0f);

    glm::vec3 ambient      = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 diffuse      = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 specular     = glm::vec3(0.0f, 0.0f, 0.0f);
};

// Uniform shader locations for a directional light
struct sGraphicsEngineDirectionalLightLocation
{
    uint32    enabled      = 0;
    uint32    direction    = 0;
    uint32    ambient      = 0;
    uint32    diffuse      = 0;
    uint32    specular     = 0;
};

#endif //GRAPHICS_ENGINE_LIGHT_DEFINE_HPP

