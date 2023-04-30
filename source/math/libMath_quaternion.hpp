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

#ifndef LIB_MATH_QUATERNION_HPP
#define LIB_MATH_QUATERNION_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"

template<typename T>
struct quaternion
{
    // data structures, variables and constants
    static const uint32 SIZE = 4; // quaternion == 4
    union
    {
        struct { T s = 0.0; vec3_t<T> v; };
        struct { T array[SIZE]; };
    };
    
    // construnctors and destructor
    quaternion(void) { this->s = 0.0; this->v = vec3_t<T>(0.0); }
    ~quaternion(void) = default;
    
    // opperators

    // functions
    uint32 size(void) { return SIZE; }
};

#endif // LIB_MATH_QUATERNION_HPP

