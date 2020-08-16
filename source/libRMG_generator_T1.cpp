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

#include "libRMG_generator_T1.hpp"

static void _libRMG_generator_T1_internal(sLibRMGMapData &_data)
{
    for (uint32_t i = 0; i < _data.tile_count; i++)
        _data.tile[i].base = eBase::baseFloor;
    bool seeded = (_data.seed != 0);
    if (seeded)
    {
        srand (_data.seed);
        _libRMG_generator_C1(_data);
    }
    else
    {
        while (_data.room_count != 1)
        {
            _data.seed = time(NULL);
            srand (_data.seed);
            _libRMG_generator_C1(_data);
        }
    }
    for (uint32_t i = 0; i < _data.tile_count; i++)
    {
        if (_data.tile[i].base == eBase::baseWall)
        {
            _data.tile[i].base = eBase::baseFloor;
            //_data.tile[i].objectID = RMG_OBJECT_TREE;
        }
    }
    // generate town center
    // generate river
    // generate bridge
    // generate roads
    // generate buildings

}

void _libRMG_generator_T1(sLibRMGMapData &_data)
{
    _libRMG_utils_map_initialize(_data);
    if (_data.genSeed)
    {
        srand (_data.seed);
        _libRMG_generator_T1_internal(_data);
    }
    else
    {
        for (uint16_t i = 0; i < _data.maxItterations; i++)
        {
            _data.seed = time(NULL);
            srand (_data.seed);
            _libRMG_generator_T1_internal(_data);
        }
    }
}
