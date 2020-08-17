/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libRMG"
 *
 * "libRMG" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libRMG" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libRMG" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#include "libRMG_map.hpp"

void cLibRMGMap::init(void)
{
    _libRMG_utils_map_initialize(data);
}

void cLibRMGMap::free(void)
{
    _libRMG_utils_map_free(data);
}

void cLibRMGMap::generate(void)
{
    // prepare the data struct
    _libRMG_utils_map_initialize(data);
    
    // generate
    switch (data.generator)
    {
        case eMapGenerator::mapGeneratorC1:
            _libRMG_generator_C1(data);
        break;
        case eMapGenerator::mapGeneratorC2:
            _libRMG_generator_C2(data);
        break;
        case eMapGenerator::mapGeneratorD1:
            _libRMG_generator_D1(data);
        break;
        case eMapGenerator::mapGeneratorD2:
            _libRMG_generator_D2(data);
        break;
        case eMapGenerator::mapGeneratorM1:
            _libRMG_generator_M1(data);
        break;
        case eMapGenerator::mapGeneratorT1:
            _libRMG_generator_T1(data);
        break;
    }
}

void cLibRMGMap::draw(void)
{
    _libRMG_utils_map_draw(data);
}