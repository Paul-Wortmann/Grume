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

#include "libRMG_generator_C1.hpp"


static void _libRMG_generator_C1_internal(sLibRMGMapData &_data)
{
    uint32_t density = (_data.tile_count * _data.density) / 100;
    sLibRMGMapTile tempMap[_data.tile_count];

    // copy the perimeter walls to the temp map
    _libRMG_utils_map_perimeter_walls(_data);
    for (size_t i = 0; i < _data.tile_count; i++)
    {
        tempMap[i].base = _data.tile[i].base;
    }
    
    // randomly place walls in the temp map
    for (size_t i = 0; i < density; i++)
    {
        tempMap[random() % _data.tile_count].base = eBase::baseWall;
    }
    
    // using cellula automata based rules,
    // populate the actual map from the temp map
    // then copy the actual map back to the temp 
    // map for the next itteration.
    for (size_t p = 0; p < _data.maxItterations; p++)
    {
        for (size_t y = 1; y < _data.tile_y - 1; y++)
        {
            for (size_t x = 1; x < _data.tile_x - 1; x++)
            {
                uint16_t tCount = 0;
                if (tempMap[(y * _data.tile_x) + x].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x + 1].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x - 1].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x + _data.tile_x].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x + _data.tile_x + 1].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x + _data.tile_x - 1].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x - _data.tile_x].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x - _data.tile_x + 1].base == eBase::baseWall)
                    tCount++;
                if (tempMap[(y * _data.tile_x) + x - _data.tile_x - 1].base == eBase::baseWall)
                    tCount++;
                    
                if (tCount >= 5)
                    _data.tile[(y * _data.tile_x) + x].base = eBase::baseWall;
                else
                    _data.tile[(y * _data.tile_x) + x].base = eBase::baseFloor;
            }
        }
        for (size_t i = 0; i < _data.tile_count; i++)
        {
            tempMap[i].base = _data.tile[i].base;
        }
    }
}

void _libRMG_generator_C1(sLibRMGMapData &_data)
{
    // make sure the map has been initialized
    // this also guarantees a new random seed is necessary
    _libRMG_utils_map_initialize(_data);
    if (!_data.genSeed)
    {
        _libRMG_generator_C1_internal(_data);
    }
    else
    {
        for (uint16_t i = 0; i < _data.maxItterations; i++)
        {
            _data.seed = time(NULL);
            srand (_data.seed);
            _libRMG_generator_C1_internal(_data);
            if (_libRMG_utils_map_get_floor_area(_data) > (_data.tile_count / _data.floor_area_min))
            {
                i = _data.maxItterations;
            }
        }
    }
    _libRMG_room_initRooms(_data);
    _libRMG_utils_map_remove_anomalies(_data);
    _libRMG_connect_rooms(_data);
}
