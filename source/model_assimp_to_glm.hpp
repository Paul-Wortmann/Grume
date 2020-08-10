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

#ifndef ASSIMP_TO_GLM_HPP
#define ASSIMP_TO_GLM_HPP

#include "includes.hpp"

static inline glm::vec3 toVec3(const aiVector3D &v) { return glm::vec3(v.x, v.y, v.z); }
static inline glm::vec2 toVec2(const aiVector3D &v) { return glm::vec2(v.x, v.y); }
static inline glm::quat toQuat(const aiQuaternion &q) { return glm::quat(q.w, q.x, q.y, q.z); }
static inline glm::mat4 toMat4(const aiMatrix4x4 &m) { return glm::transpose(glm::make_mat4(&m.a1)); }
static inline glm::mat4 toMat4(const aiMatrix3x3 &m) { return glm::transpose(glm::make_mat3(&m.a1)); }

static inline void printMat4(const glm::mat4 &_mat4)
{
    double tArray[16] = {0.0};
    const float *tData = (const float*)glm::value_ptr(_mat4);
    for (int i = 0; i < 16; ++i)
    {
        tArray[i] = tData[i];
    }
    std::cout << "----- GLM-Mat4 ----" << std::endl;
    for (int i = 0; i < 16; ++i)
    {
        std::cout << "[" << tArray[i] << "] ";
        if ((i % 4) == 3)
        {
            std::cout << std::endl;
        }
    }
    std::cout << "-------------------" << std::endl;
}

#endif // ASSIMP_TO_GLM_HPP
