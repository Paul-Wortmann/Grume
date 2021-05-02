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

#ifndef LIB_MATH_VECTOR_HPP
#define LIB_MATH_VECTOR_HPP

#include "libMath_vector_vec2.hpp"
#include "libMath_vector_vec3.hpp"
#include "libMath_vector_vec4.hpp"

typedef vec2_t<float32> vec2;
typedef vec2_t<float32> vec2f;
typedef vec2_t<float64> vec2d;

typedef vec3_t<float32> vec3;
typedef vec3_t<float32> vec3f;
typedef vec3_t<float64> vec3d;

typedef vec4_t<float32> vec4;
typedef vec4_t<float32> vec4f;
typedef vec4_t<float64> vec4d;

#endif // LIB_MATH_VECTOR_HPP