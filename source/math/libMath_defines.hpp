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

#ifndef LIB_MATH_DEFINES_HPP
#define LIB_MATH_DEFINES_HPP

#include <cstdint>
#include <limits>

// Boolean type
typedef bool          boolean;

// Float types
typedef float         float32;
typedef double        float64;
typedef long double   float128;

// Integer types
typedef std::uint8_t  uint8;
typedef std::uint16_t uint16;
typedef std::uint32_t uint32;
typedef std::uint64_t uint64;

typedef std::int8_t   int8;
typedef std::int16_t  int16;
typedef std::int32_t  int32;
typedef std::int64_t  int64;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define CLAMP(x,a,b) MIN(MAX(x,a),b)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // M_PI
#ifndef M_PIl
#define M_PIl 3.141592653589793238462643383279502884L
#endif // M_PIl

#ifndef M_HPI // half pi
#define M_HPI 1.57079632679
#endif // M_HPI

#ifndef M_EPSILON
#define M_EPSILON 1e-21f
#endif // M_EPSILON

#ifndef DTOR_0
#define DTOR_0   0.0
#endif // DTOR_0

#ifndef DTOR_90
#define DTOR_90  1.5708
#endif // DTOR_90

#ifndef DTOR_180
#define DTOR_180 3.1416
#endif // DTOR_180

#ifndef DTOR_270
#define DTOR_270 4.7124
#endif // DTOR_270

#endif //LIB_MATH_DEFINES_HPP


