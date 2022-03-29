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

#ifndef LIB_MATH_POINTS_HPP
#define LIB_MATH_POINTS_HPP

#include "libMath_defines.hpp"
#include "libMath_vector.hpp"

float  distanceSquared(const float &_x1, const float &_y1, const float &_x2, const float &_y2);
double distanceSquared(const double &_x1, const double &_y1, const double &_x2, const double &_y2);
double distanceSquared(const vec2 &_v1, const vec2 &_v2);
double distanceSquared(const vec3 &_v1, const vec3 &_v2);

#endif // LIB_MATH_POINTS_HPP