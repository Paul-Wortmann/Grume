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

#include "graphics_engine_utils.hpp"

glm::vec3 generateNormal(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c)
{
    return glm::normalize(glm::cross(_b - _a, _c - _a));
}

glm::vec3 generateTangent(glm::vec3 _normal)
{
    glm::vec3 rTangent;
    glm::vec3 c1 = glm::cross(_normal, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec3 c2 = glm::cross(_normal, glm::vec3(0.0f, 1.0f, 0.0f));
    
    rTangent = (glm::length(c1) > glm::length(c2)) ? c1 : c2;
        
    return glm::normalize(rTangent);
}

glm::vec3 generateBitangent(glm::vec3 _normal, glm::vec3 _tangent)
{
    return glm::normalize(glm::cross(_normal, _tangent));
}