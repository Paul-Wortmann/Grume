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

#include "libRMG_utils.hpp"

void _libRMG_utils_map_initialize(sLibRMGMapData &_data)
{
    // prepare the map
    _libRMG_utils_map_free(_data);
    _data.tile_count = _data.tile_x * _data.tile_y;
    _data.tile = new sLibRMGMapTile[_data.tile_count];
    _data.room_count = 0;

    // seed the random number generator
    if (_data.genSeed)
    {
        _data.seed = time(0);
    }
    srand(_data.seed);
    
    // if prefabs need loading, load them
    if (_data.enablePrefabs)
    {
        _libRMG_prefab_find(_data);
    }
}

void _libRMG_utils_map_free(sLibRMGMapData &_data)
{
    _libRMG_prefab_freeAll(_data);
    _libRMG_prefab_eventFreeAll(_data);
    
    // object
    if (_data.object != nullptr)
    {
        delete[] _data.object;
        _data.object = nullptr;
    }

    // room
    if (_data.room != nullptr)
    {
        delete[] _data.room;
        _data.room = nullptr;
    }

    // tile
    if (_data.tile != nullptr)
    {
        delete[] _data.tile;
        _data.tile = nullptr;
    }

}

void _libRMG_utils_map_perimeter_walls(sLibRMGMapData &_data)
{
    if (_data.tile == nullptr)
    {
        _libRMG_utils_map_initialize(_data);
    }
    for (size_t i = 0; i < _data.tile_count; i++)
    {
        if (((i % _data.tile_x) == 0) || ((i % _data.tile_x) == (_data.tile_x - 1)) || ( i < _data.tile_x) || (i > (_data.tile_count - _data.tile_x)))
        {
            _data.tile[i].base = eBase::baseWall;
        }
    }
}

void _libRMG_utils_map_draw(sLibRMGMapData &_data)
{
    if (_data.tile != nullptr)
    {
        for (uint32_t i = 0; i < _data.tile_y; i++)
        {
            for (uint32_t j = 0; j < _data.tile_x; j++)
            {
                switch (_data.tile[(i * _data.tile_x) + j].base)
                {
                    case eBase::baseWall:
                        std::cout << "#";
                    break;
                    case eBase::baseLiquid:
                        std::cout << "O";
                    break;
                    case eBase::baseFloor:
                        if (_data.tile[(i * _data.tile_x) + j].objectID == 0)
                        {
                            //std::cout << _data.tile[(i * _data.tile_x) + j].roomID;
                            std::cout << " ";
                        }
                        else
                        {
                            // loop through the object list
                        }
                    break;
                    default:
                        std::cout << "?";
                    break;
                }
            }
            std::cout << std::endl;
        }
        std::cout << "Map seed: " << _data.seed << std::endl;
        std::cout << "Room Count: " << _data.room_count << std::endl;
    }
}

uint32_t _libRMG_utils_map_get_floor_min(sLibRMGMapData &_data)
{
    if (_data.tile == nullptr)
        _libRMG_utils_map_initialize(_data);
    if (_data.tile != nullptr)
    {
        for (uint32_t i = 0; i < _data.tile_count; i++)
        {
            if (_data.tile[i].base == eBase::baseFloor)
                return i;
        }
    }
    return 0;
}

uint32_t _libRMG_utils_map_get_floor_max(sLibRMGMapData &_data)
{
    if (_data.tile == nullptr)
        _libRMG_utils_map_initialize(_data);
    if (_data.tile != nullptr)
    {
        for (uint32_t i = _data.tile_count-_data.tile_x; i > 0; i--)
        {
            if (_data.tile[i].base == eBase::baseFloor)
                return i;
        }
    }
    return 0;
}

uint32_t _libRMG_utils_map_get_floor_area(sLibRMGMapData &_data)
{
    if (_data.tile == nullptr)
        _libRMG_utils_map_initialize(_data);
    if (_data.tile != nullptr)
    {
        uint32_t tileCount = 0;
        for (uint32_t j = 0; j < _data.tile_count; j++)
        {
            if (_data.tile[j].base == eBase::baseFloor)
                tileCount++;
        }
        return tileCount;
    }
    return 0;
}

void _libRMG_utils_map_remove_anomalies(sLibRMGMapData &_data)
{
    uint32_t tileT = 0;
    for (uint16_t k = 0; k < _data.maxItterations; k++)
    {
        for (uint16_t i = 1; i < (_data.tile_y - 1); i++)
        {
            for (uint16_t j = 1; j < (_data.tile_x - 1); j++)
            {
                tileT = (i * _data.tile_x) + j;
                if (_data.tile[tileT].base == eBase::baseFloor)
                {
                    // Remove single horizontal floor tiles
                    // ???
                    // XOX
                    // ???
                    //--------------------
                    if ((_data.tile[tileT+1].base == eBase::baseWall)
                     && (_data.tile[tileT-1].base == eBase::baseWall))
                    {
                        _data.tile[tileT+1].base = eBase::baseFloor;
                        _data.tile[tileT-1].base = eBase::baseFloor;
                        _data.tile[tileT+1].roomID = _data.tile[tileT].roomID;
                        _data.tile[tileT-1].roomID = _data.tile[tileT].roomID;
                    }
                    // Remove single vertical floor tiles
                    // ?X?
                    // ?O?
                    // ?X?
                    //--------------------
                    if ((_data.tile[tileT+_data.tile_x].base == eBase::baseWall)
                     && (_data.tile[tileT-_data.tile_x].base == eBase::baseWall))
                    {
                        _data.tile[tileT+_data.tile_x].base = eBase::baseFloor;
                        _data.tile[tileT-_data.tile_x].base = eBase::baseFloor;
                        _data.tile[tileT+_data.tile_x].roomID = _data.tile[tileT].roomID;
                        _data.tile[tileT-_data.tile_x].roomID = _data.tile[tileT].roomID;
                    }
                }
                else if (_data.tile[tileT].base == eBase::baseWall)
                {
                    // Remove single horizontal wall tiles
                    // ???
                    // OXO
                    // ???
                    //--------------------
                    if ((_data.tile[tileT+1].base == eBase::baseFloor)
                     && (_data.tile[tileT-1].base == eBase::baseFloor))
                    {
                        _data.tile[tileT].base = eBase::baseFloor;
                        _data.tile[tileT].roomID = _data.tile[tileT+1].roomID;
                    }
                    // Remove single vertical wall tiles
                    // ?O?
                    // ?X?
                    // ?O?
                    //--------------------
                    if ((_data.tile[tileT+_data.tile_x].base == eBase::baseFloor)
                     && (_data.tile[tileT-_data.tile_x].base == eBase::baseFloor))
                    {
                        _data.tile[tileT].base = eBase::baseFloor;
                        _data.tile[tileT].roomID = _data.tile[tileT+_data.tile_x].roomID;
                    }
                    // Remove diagonal right wall tiles
                    // O?X
                    // ?X?
                    // X?O
                    //--------------------
                    if ((_data.tile[tileT+_data.tile_x+1].base == eBase::baseWall)
                     && (_data.tile[tileT+_data.tile_x-1].base == eBase::baseFloor)
                     && (_data.tile[tileT-_data.tile_x+1].base == eBase::baseFloor)
                     && (_data.tile[tileT-_data.tile_x-1].base == eBase::baseWall))
                    {
                        _data.tile[tileT+_data.tile_x].base = eBase::baseFloor;
                        _data.tile[tileT-_data.tile_x].base = eBase::baseFloor;
                        _data.tile[tileT+1].base = eBase::baseFloor;
                        _data.tile[tileT-1].base = eBase::baseFloor;
                    }
                    // Remove diagonal left wall tiles
                    // X?O
                    // ?X?
                    // O?X
                    //--------------------
                    if ((_data.tile[tileT+_data.tile_x+1].base == eBase::baseFloor)
                     && (_data.tile[tileT+_data.tile_x-1].base == eBase::baseWall)
                     && (_data.tile[tileT-_data.tile_x+1].base == eBase::baseWall)
                     && (_data.tile[tileT-_data.tile_x-1].base == eBase::baseFloor))
                    {
                        _data.tile[tileT+_data.tile_x].base = eBase::baseFloor;
                        _data.tile[tileT-_data.tile_x].base = eBase::baseFloor;
                        _data.tile[tileT+1].base = eBase::baseFloor;
                        _data.tile[tileT-1].base = eBase::baseFloor;
                    }
                }
            }
        }
    }
}
