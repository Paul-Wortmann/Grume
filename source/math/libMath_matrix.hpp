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

#ifndef LIB_MATH_MATRIX_HPP
#define LIB_MATH_MATRIX_HPP

#include "libMath_matrix_mat2.hpp"
#include "libMath_matrix_mat3.hpp"
#include "libMath_matrix_mat4.hpp"

typedef mat2_t<float32> mat2;
typedef mat2_t<float32> mat2f;
typedef mat2_t<float64> mat2d;

typedef mat3_t<float32> mat3;
typedef mat3_t<float32> mat3f;
typedef mat3_t<float64> mat3d;

typedef mat4_t<float32> mat4;
typedef mat4_t<float32> mat4f;
typedef mat4_t<float64> mat4d;

#endif // LIB_MATH_MATRIX_HPP