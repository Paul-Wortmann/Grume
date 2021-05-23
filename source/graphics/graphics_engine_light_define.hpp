/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef GRAPHICS_ENGINE_LIGHT_DEFINE_HPP
#define GRAPHICS_ENGINE_LIGHT_DEFINE_HPP

#include "../core/includes.hpp"

#define MAX_POINT_LIGHTS 4 // This HAS to match the shader!

// Hold data for each point light
struct sGraphicsEnginePointLight
{
    // Linked list management
    sGraphicsEnginePointLight* next = nullptr;
    std::uint32_t              UID  = 0;

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

