/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "random.hpp"

void gRandSeed(std::uint64_t &_seed)
{
    if (_seed == 0)
        _seed = static_cast <unsigned> (time(0));
    srand (_seed);
}

float gRandFloatNormalized(void)
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

float gRandFloatMax(const float &_max)
{
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / _max));
}

float gRandFloatMinMax(const float &_min, const float &_max)
{
    return _min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX / (_max - _min)));
}
