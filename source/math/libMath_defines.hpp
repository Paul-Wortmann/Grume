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
#ifndef boolean
    typedef bool          boolean;
#endif

// Float types
#ifndef float32
    typedef float         float32;
#endif
#ifndef float64
    typedef double        float64;
#endif
#ifndef float128
    typedef long double   float128;
#endif

// Integer types
#ifndef uint8
    typedef std::uint8_t  uint8;
#endif
#ifndef uint16
    typedef std::uint16_t uint16;
#endif
#ifndef uint32
    typedef std::uint32_t uint32;
#endif
#ifndef uint64
    typedef std::uint64_t uint64;
#endif

#ifndef int8
    typedef std::int8_t   int8;
#endif
#ifndef int16
    typedef std::int16_t  int16;
#endif
#ifndef int32
    typedef std::int32_t  int32;
#endif
#ifndef int64
    typedef std::int64_t  int64;
#endif

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define CLAMP(x,a,b) MIN(MAX(x,a),b)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // M_PI
#ifndef M_PIl
#define M_PIl 3.141592653589793238462643383279502884L
#endif // M_PIl

#ifndef M_SQR2
#define M_SQR2 1.41421356237
#endif // M_SQR2

#ifndef M_HPI // half pi
#define M_HPI 1.57079632679
#endif // M_HPI

#ifndef M_EPSILON
#define M_EPSILON 1e-21f
#endif // M_EPSILON

#ifndef DTOR_0
#define DTOR_0    0.0
#endif // DTOR_0

#ifndef DTOR_45
#define DTOR_45   0.785398
#endif // DTOR_45

#ifndef DTOR_90
#define DTOR_90   1.5708
#endif // DTOR_90

#ifndef DTOR_135
#define DTOR_135  2.35619
#endif // DTOR_90

#ifndef DTOR_180
#define DTOR_180  3.1416
#endif // DTOR_180

#ifndef DTOR_225
#define DTOR_225  3.92699
#endif // DTOR_225

#ifndef DTOR_270
#define DTOR_270  4.7124
#endif // DTOR_270

#ifndef DTOR_315
#define DTOR_315  5.49779
#endif // DTOR_315

#endif //LIB_MATH_DEFINES_HPP


