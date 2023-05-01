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

#include "libMath_sqrt.hpp"

float64 Q_rsqrt(float64 _number)
{
    uint32_t i;
    float64 x2, y;
    const float64 threeHalfs = 1.5f;

    x2 = _number * 0.5f;
    y  = _number;
    i  = * (uint32_t*) &y;
    i  = 0x5f3759df - ( i >> 1 );
    y  = * (float64*) &i;
    y  = y * (threeHalfs - (x2 * y * y));
    return y;
}

float64 rsqrt(float64 _x)
{
    float64 y;
    asm("rsqrtss %[_x], %%xmm0;" "movss %%xmm0, %[y];" : : [ _x ] "m" ( _x ), [ y ] "m" ( y ) : "xmm0");
    return y;
}
