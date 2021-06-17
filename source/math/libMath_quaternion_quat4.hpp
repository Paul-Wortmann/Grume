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

#ifndef LIB_MATH_QUAT4_HPP
#define LIB_MATH_QUAT4_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"
#include "libMath_vector_vec3.hpp"

template<typename T>
struct quat4_t
{
    // data structures, variables and constants
    static const uint32 SIZE = 4; // quat4_t == 4
    union
    {
        struct { T w; T x; T y; T z; };
        struct { T s; vec3_t<T> v; };
        struct { T array[SIZE]; };
    };
    
    // construnctors and destructor
    quat4_t<T>(const T &_w, const T &_x, const T &_y, const T &_z) { this->w = _w; this->x = _x; this->y = _y; this->z = _z; }
    quat4_t(void) { this->s = 0.0; this->v = vec3_t<T>(0.0); }
    ~quat4_t(void) = default;
    
    // opperators

    // functions
    uint32 size(void) { return SIZE; }
};

#endif // LIB_MATH_QUAT4_HPP

