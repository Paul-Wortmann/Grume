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

#ifndef ENTITY_VERTEX_HPP
#define ENTITY_VERTEX_HPP

#include "../includes.hpp"

struct sEntityVertex
{
    glm::vec3  position    = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3  normal      = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec2  texcoord    = glm::vec2(0.0f, 0.0f);
    glm::vec3  tangent     = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3  bitangent   = glm::vec3(0.0f, 0.0f, 0.0f);
};

struct sEntityVertexBone
{
    glm::vec4  boneWeight  = glm::vec4(0.0);
    glm::ivec4 boneID      = glm::ivec4(0);
};

#endif // ENTITY_VERTEX_HPP
