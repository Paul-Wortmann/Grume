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

#include "libRMG_rooms.hpp"

bool _libRMG_room_genCircleRoomOK(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_data.tile == nullptr)
        return false;
    for (uint32_t i = 0; i < _data.tile_y; i++)
    {
        for (uint32_t j = 0; j < _data.tile_x; j++)
        {
            if ((((j - _x) * (j - _x)) + ((i - _y) * (i - _y))) < (_r * _r))
                if (_data.tile[(i * _data.tile_x) + j].base == eBase::baseFloor)
                    return false;
        }
    }
    return true;
}

void _libRMG_room_genCircleRoom(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_data.tile == nullptr)
        return;
    for (uint32_t i = 0; i < _data.tile_y; i++)
    {
        for (uint32_t j = 0; j < _data.tile_x; j++)
        {
            if ((((j - _x) * (j - _x)) + ((i - _y) * (i - _y))) < (_r * _r))
                _data.tile[(i * _data.tile_x) + j].base = eBase::baseFloor;
        }
    }
}

bool _libRMG_room_genSquareRoomOK(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_data.tile == nullptr)
        return false;
    int32_t rxMin = _x - _r - 1;
    int32_t rxMax = _x + _r;
    int32_t ryMin = _y - _r - 1;
    int32_t ryMax = _y + _r;
    if (rxMin < 1)
        return false;
    if (rxMax >= (int32_t)(_data.tile_x-1))
        return false;
    if (ryMin < 1)
        return false;
    if (ryMax >= (int32_t)(_data.tile_y-1))
        return false;
    for (uint32_t i = ryMin; i < (uint32_t)ryMax; i++)
    {
        for (uint32_t j = rxMin; j < (uint32_t)rxMax; j++)
        {
            if (_data.tile[(i * _data.tile_x) + j].base != eBase::baseWall)
                return false;
        }
    }
    return true;
}

void _libRMG_room_genSquareRoom(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_data.tile == nullptr)
        return;
    uint32_t rxMin = _x - _r - 1;
    uint32_t rxMax = _x + _r;
    uint32_t ryMin = _y - _r - 1;
    uint32_t ryMax = _y + _r;
    for (uint32_t i = ryMin; i < ryMax; i++)
    {
        for (uint32_t j = rxMin; j < rxMax; j++)
        {
                _data.tile[(i * _data.tile_x) + j].base = eBase::baseFloor;
        }
    }
}

static void _libRMG_room_locateRoom(sLibRMGMapData &_data, const uint32_t &i)
{
    if (i  < _data.tile_count)
    {
        if ((!_data.tile[i].c) && (_data.tile[i].base == eBase::baseFloor))
        {
            _data.tile[i].c = true;
            _data.tile[i].roomID = _data.room_count;
            if (((i + 1) > 0) && ((i + 1) < _data.tile_count))
                _libRMG_room_locateRoom(_data, i + 1);
            if (((i - 1) > 0) && ((i - 1) < _data.tile_count))
                _libRMG_room_locateRoom(_data, i - 1);
            if (((i + _data.tile_x) > 0) && ((i + _data.tile_x) < _data.tile_count))
                _libRMG_room_locateRoom(_data, i + _data.tile_x);
            if (((i - _data.tile_x) > 0) && ((i - _data.tile_x) < _data.tile_count))
                _libRMG_room_locateRoom(_data, i - _data.tile_x);
        }
    }
}

void _libRMG_room_locateRooms(sLibRMGMapData &_data)
{
    if (_data.tile == nullptr)
        _libRMG_utils_map_initialize(_data);
    if (_data.tile != nullptr)
    {
        _data.room_count = 0;
        for (uint32_t i = 0; i < _data.tile_count; i++)
        {
            _data.tile[i].roomID = 0;
            _data.tile[i].c = false;
        }
        for (uint32_t i = 0; i < _data.tile_count; i++)
        {
            if ((!_data.tile[i].c) && (_data.tile[i].base == eBase::baseFloor))
            {
                _libRMG_room_locateRoom(_data, i);
                _data.room_count++;
            }
        }
    }
}

uint32_t _libRMG_room_getArea(sLibRMGMapData &_data, const uint32_t &_r)
{
    uint32_t returnValue = 0;
    if (_data.tile != nullptr)
    {
        for (uint32_t i = 0; i < _data.tile_count; i++)
            if ((_data.tile[i].roomID == _r) && (_data.tile[i].base == eBase::baseFloor))
                returnValue++;
    }
    return returnValue;
}

static void _libRMG_room_discardMinRooms(sLibRMGMapData &_data)
{
    uint16_t discardCount = 0;
    if (_data.tile == nullptr)
        _libRMG_utils_map_initialize(_data);
    if (_data.tile != nullptr)
    {
        for (uint16_t i = 0; i < _data.room_count; i++)
        {
            uint32_t tileCount = 0;
            for (uint32_t j = 0; j < _data.tile_count; j++)
            {
                if ((_data.tile[j].roomID == i) && (_data.tile[j].base == eBase::baseFloor))
                    tileCount++;
            }
            if (tileCount < (uint32_t)(_data.room_radius_min * _data.room_radius_min))
            {
                discardCount++;
                for (uint32_t j = 0; j < _data.tile_count; j++)
                {
                    if (_data.tile[j].roomID == i)
                    {
                        _data.tile[j].roomID = 0;
                        _data.tile[j].base = eBase::baseWall;
                    }
                }
            }
        }
    }
    _data.room_count -= discardCount;
}

static void _libRMG_room_sizeLocation(sLibRMGMapData &_data)
{
    if ((_data.room_count > 0) && (_data.room != nullptr))
    {
        for (uint16_t i = 0; i < _data.room_count; i++)
        {
            _data.room[i].posXMin = _data.tile_x;
            _data.room[i].posXMax = 0;
            _data.room[i].posYMin = _data.tile_y;
            _data.room[i].posYMax = 0;
            for (uint32_t j = 0; j < _data.tile_y; j++)
            {
                for (uint32_t k = 0; k < _data.tile_x; k++)
                {
                    if ((_data.tile[(j * _data.tile_x) + k].roomID == i) && (_data.tile[(j * _data.tile_x) + k].base == eBase::baseFloor))
                    {
                        if (k < _data.room[i].posXMin)
                            _data.room[i].posXMin = k;
                        if (k > _data.room[i].posXMax)
                            _data.room[i].posXMax = k;
                        if (j < _data.room[i].posYMin)
                            _data.room[i].posYMin = j;
                        if (j > _data.room[i].posYMax)
                            _data.room[i].posYMax = j;
                    }
                }
            }
            _data.room[i].w = _data.room[i].posXMax - _data.room[i].posXMin + 1;
            _data.room[i].h = _data.room[i].posYMax - _data.room[i].posYMin + 1;
            //if ((_data.room[i].w % 2) == 0)
                _data.room[i].x = (_data.room[i].w / 2) + _data.room[i].posXMin;
            //else
                //_data.room[i].x = ((_data.room[i].w - 1) / 2) + _data.room[i].posXMin + 1;

            //if ((_data.room[i].h % 2) == 0)
                _data.room[i].y = (_data.room[i].h / 2) + _data.room[i].posYMin;
            //else
                //_data.room[i].y = ((_data.room[i].h - 1) / 2) + _data.room[i].posYMin + 1;
        }
    }
}

void _libRMG_room_discardAllButLargest(sLibRMGMapData &_data)
{
    if ((_data.room_count > 0) && (_data.room != nullptr) && (_data.tile != nullptr))
    {
        uint32_t roomSizeT = 0;
        uint32_t roomSize = 0;
        uint32_t roomNumber = 0;
        for (uint16_t i = 0; i < _data.room_count; i++)
        {
            roomSizeT = _libRMG_room_getArea(_data, i);
            if (roomSizeT > roomSize)
            {
                roomSize = roomSizeT;
                roomNumber = i;
            }
        }
        for (uint32_t i = 0; i < _data.tile_count; i++)
        {
            if ((_data.tile[i].roomID != roomNumber) && (_data.tile[i].base == eBase::baseFloor))
            {
                _data.tile[i].roomID = LIBRMG_NOROOM;
                _data.tile[i].base = eBase::baseWall;
            }
            else
                _data.tile[i].roomID = 0;
        }
    }
    _data.room_count = 1;
    if (_data.room != nullptr)
        delete _data.room;
    _data.room = new sLibRMGMapRoom[_data.room_count];
    _libRMG_room_sizeLocation(_data);
}

void _libRMG_room_initRooms(sLibRMGMapData &_data)
{
    _libRMG_room_locateRooms(_data);
    _libRMG_room_discardMinRooms(_data);
    _libRMG_room_locateRooms(_data);
    if (_data.room_count > 0)
    {
        if (_data.room != nullptr)
            delete _data.room;
        _data.room = new sLibRMGMapRoom[_data.room_count];
        for (uint16_t i = 0; i < _data.room_count; i++)
        {
            _data.room[i].exitE = LIBRMG_NOROOM;
            _data.room[i].exitW = LIBRMG_NOROOM;
            _data.room[i].exitS = LIBRMG_NOROOM;
            _data.room[i].exitN = LIBRMG_NOROOM;
        }
        _libRMG_room_sizeLocation(_data);
    }
}

