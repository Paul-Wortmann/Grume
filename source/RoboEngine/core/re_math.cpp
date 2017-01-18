/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "re_math.hpp"

namespace RoboEngine
{

    float to_radians (float _degrees)
    {
        return(_degrees * (M_PI/180));
    }

    float to_degrees (float _radians)
    {
        return(_radians * (180/M_PI));
    }

    int32_t sigma (int32_t _n)
    {
        return (_n <= 0) ? 0 : _n + sigma(_n - 1);
    }

    bool areEqualRel(float _a, float _b, float _epsilon)
    {
        return (std::fabs(_a - _b) <= _epsilon * std::max(std::fabs(_a), std::fabs(_b)));
    }

    bool floatsEqual(float _a, float _b)
    {
        return (std::fabs(_a - _b) <= FLT_EPSILON * std::max(std::fabs(_a), std::fabs(_b)));
    }

}
