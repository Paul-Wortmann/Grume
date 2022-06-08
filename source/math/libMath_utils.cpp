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

#include "libMath_utils.hpp"

uint32 fibonacci(uint32 _n)
{
    if (_n == 1)
        return 0;
    if (_n == 2)
        return 1;

    uint32 t1 = 0;
    uint32 t2 = 1;
    uint32 sum = 0;
    for (uint32 i = 3; i <= _n; ++i)
    {
        sum = t1 + t2;
        t1 = t2;
        t2 = sum;
    }
    return sum;
}

uint32 factorial(uint32 _n)
{
    uint32 product = 1;
    for(uint32 i = 1; i <= _n; ++i)
    {    
      product = product * i;
    }
    return product;
}