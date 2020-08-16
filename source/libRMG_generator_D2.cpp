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

#include "libRMG_generator_D2.hpp"

void _libRMG_splitRoom(sLibRMGMapData &_data, const uint16_t _roomID)
{
    bool splitX = (_data.room[_roomID].w > (((_data.room_radius_min * 2) + _data.room_border) * 2));
    bool splitY = (_data.room[_roomID].h > (((_data.room_radius_min * 2) + _data.room_border) * 2));
    if (!splitX && !splitY)
    {
        _data.room[_roomID].p = false;
        return;
    }
    else
    {
        uint16_t newRoomID = _data.room_count;
        sLibRMGMapRoom *tRoom = new sLibRMGMapRoom[_data.room_count];
        for (uint16_t i = 0; i < _data.room_count; i++)
        {
            tRoom[i].type = _data.room[i].type;
            tRoom[i].p = _data.room[i].p;
            tRoom[i].posXMin = _data.room[i].posXMin;
            tRoom[i].posXMax = _data.room[i].posXMax;
            tRoom[i].posYMin = _data.room[i].posYMin;
            tRoom[i].posYMax = _data.room[i].posYMax;
            tRoom[i].x = _data.room[i].x;
            tRoom[i].y = _data.room[i].y;
            tRoom[i].w = _data.room[i].w;
            tRoom[i].h = _data.room[i].h;
            tRoom[i].exitN = _data.room[i].exitN;
            tRoom[i].exitS = _data.room[i].exitS;
            tRoom[i].exitE = _data.room[i].exitE;
            tRoom[i].exitW = _data.room[i].exitW;
        }
        delete _data.room;
        _data.room_count++;
        _data.room = new sLibRMGMapRoom[_data.room_count];
        for (uint16_t i = 0; i < _data.room_count-1; i++)
        {
            _data.room[i].type = tRoom[i].type;
            _data.room[i].p = tRoom[i].p;
            _data.room[i].posXMin = tRoom[i].posXMin;
            _data.room[i].posXMax = tRoom[i].posXMax;
            _data.room[i].posYMin = tRoom[i].posYMin;
            _data.room[i].posYMax = tRoom[i].posYMax;
            _data.room[i].x = tRoom[i].x;
            _data.room[i].y = tRoom[i].y;
            _data.room[i].w = tRoom[i].w;
            _data.room[i].h = tRoom[i].h;
            _data.room[i].exitN = tRoom[i].exitN;
            _data.room[i].exitS = tRoom[i].exitS;
            _data.room[i].exitE = tRoom[i].exitE;
            _data.room[i].exitW = tRoom[i].exitW;
        }
        if (splitX && splitY)
            (_data.room[_roomID].w > _data.room[_roomID].h) ? (splitY = !splitY) : (splitX = !splitX);
        if (splitX)
        {
            _data.room[newRoomID].p = true;
            _data.room[newRoomID].y = _data.room[_roomID].y;
            _data.room[newRoomID].h = _data.room[_roomID].h;
            _data.room[newRoomID].posYMin = _data.room[_roomID].posYMin;
            _data.room[newRoomID].posYMax = _data.room[_roomID].posYMax;
            uint16_t splitMaxX = _data.room[_roomID].w - ((_data.room_radius_min + _data.room_border) * 2);
            uint16_t splitDeltaX = rand() % splitMaxX;
            _data.room[_roomID].w = _data.room_radius_min + _data.room_border + (splitMaxX - splitDeltaX);
            _data.room[newRoomID].w = _data.room_radius_min + _data.room_border + splitDeltaX;
            _data.room[_roomID].x = _data.room[_roomID].posXMin + (_data.room[_roomID].w / 2);
            _data.room[newRoomID].x = _data.room[_roomID].posXMax - (_data.room[newRoomID].w / 2);
            _data.room[newRoomID].posXMin = _data.room[_roomID].posXMin + _data.room[_roomID].w;
            _data.room[newRoomID].posXMax = _data.room[_roomID].posXMax;
            _data.room[_roomID].posXMax = _data.room[_roomID].posXMin + _data.room[_roomID].w - 1;
        }
        if (splitY)
        {
            _data.room[newRoomID].p = true;
            _data.room[newRoomID].x = _data.room[_roomID].x;
            _data.room[newRoomID].w = _data.room[_roomID].w;
            _data.room[newRoomID].posXMin = _data.room[_roomID].posXMin;
            _data.room[newRoomID].posXMax = _data.room[_roomID].posXMax;
            uint16_t splitMaxY = _data.room[_roomID].h - ((_data.room_radius_min + _data.room_border) * 2);
            uint16_t splitDeltaY = rand() % splitMaxY;
            _data.room[_roomID].h = _data.room_radius_min + _data.room_border + (splitMaxY - splitDeltaY);
            _data.room[newRoomID].h = _data.room_radius_min + _data.room_border + splitDeltaY;
            _data.room[_roomID].y = _data.room[_roomID].posYMin + (_data.room[_roomID].h / 2);
            _data.room[newRoomID].y = _data.room[_roomID].posYMax - (_data.room[newRoomID].h / 2);
            _data.room[newRoomID].posYMin = _data.room[_roomID].posYMin + _data.room[_roomID].h;
            _data.room[newRoomID].posYMax = _data.room[_roomID].posYMax;
            _data.room[_roomID].posYMax = _data.room[_roomID].posYMin + _data.room[_roomID].h - 1;
        }
        if (tRoom != nullptr)
            delete[] tRoom;
    }
}

void _libRMG_subdivideMap(sLibRMGMapData &_data)
{
    uint16_t availableRooms = 1;
    while (availableRooms != 0)
    {
        availableRooms = 0;
        for (uint16_t i = 0; i < _data.room_count; i++)
        {
            if (_data.room[i].p)
            {
                _libRMG_splitRoom(_data, i);
                i = _data.room_count;
            }
        }
        for (uint16_t i = 0; i < _data.room_count; i++)
            if (_data.room[i].p)
                availableRooms++;
    }
}

void _libRMG_fillRooms(sLibRMGMapData &_data)
{
    for (uint32_t k = 0; k < _data.room_count; k++)
    {
        for (uint32_t i = _data.room[k].posYMin; i < _data.room[k].posYMax; i++)
        {
            for (uint32_t j = _data.room[k].posXMin; j < _data.room[k].posXMax; j++)
            {
                _data.tile[(i * _data.tile_x) + j].base = eBase::baseFloor;
            }
        }
    }
}

static void _libRMG_generator_D2_internal(sLibRMGMapData &_data)
{
    for (uint32_t i = 0; i < _data.tile_count; i++)
        _data.tile[i].base = eBase::baseWall;
    if (_data.room != nullptr)
        delete _data.room;
    _data.room_count = 1;
    _data.room = new sLibRMGMapRoom[_data.room_count];
    _data.room[0].p = true;
    _data.room[0].x = (_data.tile_x-2) / 2;
    _data.room[0].y = (_data.tile_y-2) / 2;
    _data.room[0].w = (_data.tile_x-1);
    _data.room[0].h = (_data.tile_y-1);
    _data.room[0].posXMin = 1;
    _data.room[0].posXMax = _data.room[0].w;
    _data.room[0].posYMin = 1;
    _data.room[0].posYMax = _data.room[0].h;
    _libRMG_subdivideMap(_data);
    _libRMG_fillRooms(_data);
}

void _libRMG_generator_D2(sLibRMGMapData &_data)
{
    _libRMG_utils_map_initialize(_data);
    if (_data.genSeed)
    {
        srand (_data.seed);
        _libRMG_generator_D2_internal(_data);
    }
    else
    {
        for (uint16_t i = 0; i < _data.maxItterations; i++)
        {
            _data.seed = time(NULL);
            srand (_data.seed);
            _libRMG_generator_D2_internal(_data);
            if ((_libRMG_utils_map_get_floor_area(_data) > (_data.tile_count / _data.floor_area_min)) && (_data.room_count >= _data.room_min))
                i = _data.maxItterations;
        }
    }
    _libRMG_room_initRooms(_data);
    _libRMG_connect_rooms(_data);
    //_libRMG_utils_map_remove_anomalies(_data);
}
