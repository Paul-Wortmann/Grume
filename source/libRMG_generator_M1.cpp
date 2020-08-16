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

#include "libRMG_generator_M1.hpp"

static void _libRMG_generator_M1_maze(sLibRMGMapData &_data, const uint32_t &_tile)
{
    uint16_t tileCount = 4;
    uint16_t loopCount = 0; // exit instead of getting stuck in the loop
    while (tileCount > 0)
    {
        tileCount = 0;
        uint32_t next_tile =_tile - _data.tile_x;
        if (!_data.tile[next_tile].c)
            tileCount++;
        next_tile =_tile + _data.tile_x;
        if (!_data.tile[next_tile].c)
            tileCount++;
        next_tile =_tile - 1;
        if (!_data.tile[next_tile].c)
            tileCount++;
        next_tile =_tile + 1;
        if (!_data.tile[next_tile].c)
            tileCount++;
        loopCount++;
        if (loopCount > (_data.maxItterations * _data.direction_biasStrength))
            tileCount = 0;
        uint32_t randBase = 25;
        eDirection direction = _data.direction_bias;
        uint32_t directionRand = (direction == eDirection::directionNone) ? (rand() % (randBase * 4)) :  (rand() % (randBase * (4 + _data.direction_biasStrength)));
        if (directionRand < randBase)
            direction = eDirection::directionNorth;
        if ((directionRand > (randBase * 1)) && (directionRand < (randBase * 2)))
            direction = eDirection::directionSouth;
        if ((directionRand > (randBase * 2)) && (directionRand < (randBase * 3)))
            direction = eDirection::directionEast;
        if ((directionRand > (randBase * 3)) && (directionRand < (randBase * 4)))
            direction = eDirection::directionWest;
        if (_data.direction_bias != eDirection::directionNone)
            _data.direction_bias = direction;
        next_tile =_tile - _data.tile_x;
        if ((direction == eDirection::directionNorth) && (next_tile > 0) && (next_tile < _data.tile_count))
        {
            if (!_data.tile[next_tile].c)
            {
                if ((!_data.tile[next_tile + 1].c) && (!_data.tile[next_tile - 1].c))
                {
                    if ((_data.tile[next_tile - _data.tile_x].base == eBase::baseWall) && (_data.tile[next_tile - _data.tile_x + 1].base == eBase::baseWall) && (_data.tile[next_tile - _data.tile_x - 1].base == eBase::baseWall))
                    {
                        _data.tile[next_tile].c = true;
                        _data.tile[next_tile].base = eBase::baseFloor;
                        _libRMG_generator_M1_maze(_data, (next_tile));
                    }
                }
            }
        }
        next_tile =_tile + _data.tile_x;
        if ((direction == eDirection::directionSouth) && (next_tile > 0) && (next_tile < _data.tile_count))
        {
            if (!_data.tile[next_tile].c)
            {
                if ((!_data.tile[next_tile + 1].c) && (!_data.tile[next_tile - 1].c))
                {
                    if ((_data.tile[next_tile + _data.tile_x].base == eBase::baseWall) && (_data.tile[next_tile + _data.tile_x + 1].base == eBase::baseWall) && (_data.tile[next_tile + _data.tile_x - 1].base == eBase::baseWall))
                    {
                        _data.tile[next_tile].c = true;
                        _data.tile[next_tile].base = eBase::baseFloor;
                        _libRMG_generator_M1_maze(_data, (next_tile));
                    }
                }
            }
        }
        next_tile =_tile - 1;
        if ((direction == eDirection::directionEast) && (next_tile > 0) && (next_tile < _data.tile_count))
        {
            if (!_data.tile[next_tile].c)
            {
                if ((!_data.tile[next_tile + _data.tile_x].c) && (!_data.tile[next_tile - _data.tile_x].c))
                {
                    if ((_data.tile[next_tile - _data.tile_x].base == eBase::baseWall) && (_data.tile[next_tile - 1 + _data.tile_x].base == eBase::baseWall) && (_data.tile[next_tile - 1 - _data.tile_x].base == eBase::baseWall))
                    {
                        _data.tile[next_tile].c = true;
                        _data.tile[next_tile].base = eBase::baseFloor;
                        _libRMG_generator_M1_maze(_data, (next_tile));
                    }
                }
            }
        }
        next_tile =_tile + 1;
        if ((direction == eDirection::directionWest) && (next_tile > 0) && (next_tile < _data.tile_count))
        {
            if (!_data.tile[next_tile].c)
            {
                if ((!_data.tile[next_tile + _data.tile_x].c) && (!_data.tile[next_tile - _data.tile_x].c))
                {
                    if ((_data.tile[next_tile - _data.tile_x].base == eBase::baseWall) && (_data.tile[next_tile + 1 + _data.tile_x].base == eBase::baseWall) && (_data.tile[next_tile + 1 - _data.tile_x].base == eBase::baseWall))
                    {
                        _data.tile[next_tile].c = true;
                        _data.tile[next_tile].base = eBase::baseFloor;
                        _libRMG_generator_M1_maze(_data, (next_tile));
                    }
                }
            }
        }
    }
}

static void _libRMG_generator_M1_internal(sLibRMGMapData &_data)
{
    // map preparation
    eRoomShape roomShape = _data.room_shape;
    uint16_t roomCount = 0;
    for (uint32_t i = 0; i < _data.tile_count; i++)
        _data.tile[i].base = eBase::baseWall;
    _libRMG_utils_map_perimeter_walls(_data);
    // add rooms
    for (uint32_t i = 0; i < _data.room_max; i++)
    {
        if (roomCount < _data.room_min)
        {
            uint32_t r = (rand() % (_data.room_radius_max - _data.room_radius_min)) + _data.room_radius_min;
            int32_t x = (rand() % (_data.tile_x - r - r)) + r;
            int32_t y = (rand() % (_data.tile_y - r - r)) + r;
            if ((x > 1) && (x < (int32_t)(_data.tile_x-1)) && (y > 1) && (y < (int32_t)(_data.tile_y-1)))
            {
                if (_data.room_shape == eRoomShape::roomShapeRandom)
                {
                    roomShape = ((rand() % 100) < 50) ? eRoomShape::roomShapeCircle : eRoomShape::roomShapeSquare;
                }
                if (roomShape == eRoomShape::roomShapeCircle)
                {
                    if (_libRMG_room_genCircleRoomOK(_data, x, y, r + _data.room_border))
                    {
                        _libRMG_room_genCircleRoom(_data, x, y, r);
                        roomCount++;
                    }
                }
                if (roomShape == eRoomShape::roomShapeSquare)
                {
                    if (_libRMG_room_genSquareRoomOK(_data, x, y, r + _data.room_border))
                    {
                        _libRMG_room_genSquareRoom(_data, x, y, r);
                        roomCount++;
                    }
                }
            }
        }
    }
    _libRMG_room_initRooms(_data);
    // set unmodifiable tiles.
    for (uint32_t i = 0; i < _data.tile_y; i++)
        for (uint32_t j = 0; j < _data.tile_x; j++)
            _data.tile[(i * _data.tile_x) + j].c = ((i == 0) || (i == (_data.tile_y-1)) || (j == 0) || (j == (_data.tile_x-1)) || (_data.tile[(i * _data.tile_x) + j].base != eBase::baseWall));
    // maze.
    uint32_t randBase = 25;
    eDirection direction = _data.direction_bias;
    uint32_t directionRand = (direction == eDirection::directionNone) ? (rand() % (randBase * 4)) : (rand() % (randBase * (4 + _data.direction_biasStrength)));
    if (directionRand < randBase)
        direction = eDirection::directionNorth;
    if ((directionRand > (randBase * 1)) && (directionRand < (randBase * 2)))
        direction = eDirection::directionSouth;
    if ((directionRand > (randBase * 2)) && (directionRand < (randBase * 3)))
        direction = eDirection::directionEast;
    if ((directionRand > (randBase * 3)) && (directionRand < (randBase * 4)))
        direction = eDirection::directionWest;
    if (_data.direction_bias != eDirection::directionNone)
        _data.direction_bias = direction;
    uint32_t startX = _data.tile_x / 2;
    uint32_t startY = _data.tile_y / 2;
    if (direction == eDirection::directionNorth)
        startY = 1;
    if (direction == eDirection::directionSouth)
        startY = _data.tile_y - 2;
    if (direction == eDirection::directionEast)
        startX = 1;
    if (direction == eDirection::directionWest)
        startX = _data.tile_x - 2;
    uint32_t nextTile = (startY * _data.tile_x) + startX;
    _data.tile[nextTile].base = eBase::baseFloor;
    _data.tile[nextTile].c = true;
    _libRMG_generator_M1_maze(_data, nextTile);
    // connect rooms
    for (uint32_t i = 0; i < _data.room_count; i++)
    {
        uint16_t deltaX = abs ((_data.tile_x / 2) - _data.room[i].x);
        uint16_t deltaY = abs ((_data.tile_y / 2) - _data.room[i].y);
        direction = (deltaX > deltaY) ? ((_data.room[i].x < (_data.tile_x / 2)) ? eDirection::directionWest : eDirection::directionEast) : ((_data.room[i].y < (_data.tile_y / 2)) ? eDirection::directionSouth : eDirection::directionNorth);
        uint32_t tile = 0;
        if (direction == eDirection::directionNorth)
        {
            tile = ((_data.room[i].y - ((_data.room[i].h+1) / 2)) * _data.tile_x) + _data.room[i].x;
            _data.tile[tile].base = eBase::baseFloor;
            if (_data.tile[tile-_data.tile_x].base == eBase::baseWall)
            {
                while (_data.tile[tile-_data.tile_x].base == eBase::baseWall)
                {
                    tile -= _data.tile_x;
                    _data.tile[tile].base = eBase::baseFloor;
                }
            }
        }
        if (direction == eDirection::directionSouth)
        {
            tile = ((_data.room[i].y + ((_data.room[i].h+3) / 2)) * _data.tile_x) + _data.room[i].x;
            _data.tile[tile].base = eBase::baseFloor;
            if (_data.tile[tile+_data.tile_x].base == eBase::baseWall)
            {
                while (_data.tile[tile+_data.tile_x].base == eBase::baseWall)
                {
                    tile += _data.tile_x;
                    _data.tile[tile].base = eBase::baseFloor;
                }
            }
        }
        if (direction == eDirection::directionEast)
        {
            tile = ((_data.room[i].y * _data.tile_x) + _data.room[i].x - ((_data.room[i].w+1) / 2));
            _data.tile[tile].base = eBase::baseFloor;
            if (_data.tile[tile-1].base == eBase::baseWall)
            {
                while (_data.tile[tile-1].base == eBase::baseWall)
                {
                    tile--;
                    _data.tile[tile].base = eBase::baseFloor;
                }
            }
        }
        if (direction == eDirection::directionWest)
        {
            tile = ((_data.room[i].y * _data.tile_x) + _data.room[i].x + ((_data.room[i].w+3) / 2));
            _data.tile[tile].base = eBase::baseFloor;
            if (_data.tile[tile+1].base == eBase::baseWall)
            {
                while (_data.tile[tile+1].base == eBase::baseWall)
                {
                    tile++;
                    _data.tile[tile].base = eBase::baseFloor;
                }
            }
        }
    }
}

void _libRMG_generator_M1(sLibRMGMapData &_data)
{
    _libRMG_utils_map_initialize(_data);
    if (_data.genSeed)
    {
        srand (_data.seed);
        _libRMG_generator_M1_internal(_data);
    }
    else
    {
        for (uint16_t i = 0; i < _data.maxItterations; i++)
        {
            _data.seed = time(NULL);
            srand (_data.seed);
            _libRMG_generator_M1_internal(_data);
            if ((_libRMG_utils_map_get_floor_area(_data) > (_data.tile_count / _data.floor_area_min)) && (_data.room_count >= _data.room_min))
                i = _data.maxItterations;
        }
    }
}
