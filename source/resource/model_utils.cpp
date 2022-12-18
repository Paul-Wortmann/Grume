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
    _v1.tangent = (delta_pos1 * delta_uv2.y - delta_pos2 * delta_uv1.y) * r;
    _v1.bitangent = (delta_pos2 * delta_uv1.x - delta_pos1 * delta_uv2.x) * r;

    _v2.tangent = _v1.tangent;
    _v2.bitangent = _v1.bitangent;
    _v3.tangent = _v1.tangent;
    _v3.bitangent = _v1.bitangent;
}
