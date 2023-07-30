/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "model_utils.hpp"

void gCalculateTangentBiTangent(sEntityModelVertex &_v1,
                                sEntityModelVertex &_v2,
                                sEntityModelVertex &_v3)
{
    glm::vec3 delta_pos1 = _v2.position - _v1.position;
    glm::vec3 delta_pos2 = _v3.position - _v1.position;

    glm::vec2 delta_uv1 = _v2.texcoord - _v1.texcoord;
    glm::vec2 delta_uv2 = _v3.texcoord - _v1.texcoord;

    float r = static_cast<float>(1.0 / (delta_uv1.x * delta_uv2.y - delta_uv1.y * delta_uv2.x));
    _v1.tangent   = (delta_pos1 * delta_uv2.y - delta_pos2 * delta_uv1.y) * r;
    _v1.bitangent = (delta_pos2 * delta_uv1.x - delta_pos1 * delta_uv2.x) * r;

    _v2.tangent   = _v1.tangent;
    _v2.bitangent = _v1.bitangent;
    _v3.tangent   = _v1.tangent;
    _v3.bitangent = _v1.bitangent;
}

glm::quat gMat4ToQuat(const glm::mat4 &_mat4)
{
    float w = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    float diagonal = _mat4[0][0] + _mat4[1][1] + _mat4[2][2];

    if (diagonal > 0.0f)
    {
        float w4 = static_cast<float>(sqrtf(diagonal + 1.0f) * 2.0f);
        w = w4 / 4.0f;
        x = (_mat4[2][1] - _mat4[1][2]) / w4;
        y = (_mat4[0][2] - _mat4[2][0]) / w4;
        z = (_mat4[1][0] - _mat4[0][1]) / w4;
    }
    else if ((_mat4[0][0] > _mat4[1][1]) && (_mat4[0][0] > _mat4[2][2]))
    {
        float x4 = static_cast<float>(sqrtf(1.0f + _mat4[0][0] - _mat4[1][1] - _mat4[2][2]) * 2.0f);
        w = (_mat4[2][1] - _mat4[1][2]) / x4;
        x = x4 / 4.0f;
        y = (_mat4[0][1] - _mat4[1][0]) / x4;
        z = (_mat4[0][2] - _mat4[2][0]) / x4;
    }
    else if (_mat4[1][1] > _mat4[2][2])
    {
        float y4 = static_cast<float>(sqrtf(1.0f + _mat4[1][1] - _mat4[0][0] - _mat4[2][2]) * 2.0f);
        w = (_mat4[0][2] - _mat4[2][0]) / y4;
        x = (_mat4[0][1] - _mat4[1][0]) / y4;
        y = y4 / 4.0f;
        z = (_mat4[1][2] - _mat4[2][1]) / y4;
    }
    else
    {
        float z4 = static_cast<float>(sqrtf(1.0f + _mat4[2][2] - _mat4[0][0] - _mat4[1][1]) * 2.0f);
        w = (_mat4[1][0] - _mat4[0][1]) / z4;
        x = (_mat4[0][2] - _mat4[2][0]) / z4;
        y = (_mat4[1][2] - _mat4[2][0]) / z4;
        z = z4 / 4.0f;
    }

    return glm::quat(w, x , y, z);
}

glm::vec3 gMat4ToPosition(const glm::mat4 &_mat4)
{
    return glm::vec3(_mat4[3]);
}

glm::vec3 gMat4ToScale(const glm::mat4 &_mat4)
{
    return glm::vec3(glm::length(glm::vec3(_mat4[0])), glm::length(glm::vec3(_mat4[1])), glm::length(glm::vec3(_mat4[2])));
}
