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

#ifndef LIB_MATH_PLANE_HPP
#define LIB_MATH_PLANE_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"
#include "libMath_vector.hpp"

vec3 planeLineIntersection(vec3 _planePoint, vec3 _planeNormal, vec3 _linePoint, vec3 _lineDirection);

#endif //LIB_MATH_PLANE_HPP

