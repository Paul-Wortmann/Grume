/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libMath"
 *
 * "libMath" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libMath" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libMath" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#include "libMath_points.hpp"

float32 distanceSquared(const float32 &_x1, const float32 &_y1, const float32 &_x2, const float32 &_y2)
{
    return (((_x2 - _x1) * (_x2 - _x1)) + ((_y2 - _y1) * (_y2 - _y1)));
}

float64 distanceSquared(const float64 &_x1, const float64 &_y1, const float64 &_x2, const float64 &_y2)
{
    return (((_x2 - _x1) * (_x2 - _x1)) + ((_y2 - _y1) * (_y2 - _y1)));
}

float64 distanceSquared(const vec2 &_v1, const vec2 &_v2)
{
    return (((_v2.x - _v1.x) * (_v2.x - _v1.x)) + ((_v2.y - _v1.y) * (_v2.y - _v1.y)));
}

float64 distanceSquared(const vec3 &_v1, const vec3 &_v2)
{
    return (((_v2.x - _v1.x) * (_v2.x - _v1.x)) + ((_v2.y - _v1.y) * (_v2.y - _v1.y)) + ((_v2.z - _v1.z) * (_v2.z - _v1.z)));
}
