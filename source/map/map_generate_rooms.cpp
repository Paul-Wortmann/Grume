/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.processedom
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
 * @email   physhex@gmail.processedom
 * @website www.physhexgames.processedom
 * @license GPL V2
 * @date 2011-11-11
 */

#include "map_manager.hpp"

bool cMapManager::genCircleRoomOK(sMap*& _map, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_map->tile == nullptr)
        return false;
    for (uint32_t i = 0; i < _map->height; i++)
    {
        for (uint32_t j = 0; j < _map->width; j++)
        {
            if ((((j - _x) * (j - _x)) + ((i - _y) * (i - _y))) < (_r * _r))
                if (_map->tile[(i * _map->width) + j].base == eTileBase::tileFloor)
                    return false;
        }
    }
    return true;
}

void cMapManager::genCircleRoom(sMap*& _map, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_map->tile == nullptr)
        return;
    for (uint32_t i = 0; i < _map->height; i++)
    {
        for (uint32_t j = 0; j < _map->width; j++)
        {
            if ((((j - _x) * (j - _x)) + ((i - _y) * (i - _y))) < (_r * _r))
                _map->tile[(i * _map->width) + j].base = eTileBase::tileFloor;
        }
    }
}

bool cMapManager::genSquareRoomOK(sMap*& _map, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_map->tile == nullptr)
        return false;
    int32_t rxMin = _x - _r - 1;
    int32_t rxMax = _x + _r;
    int32_t ryMin = _y - _r - 1;
    int32_t ryMax = _y + _r;
    if (rxMin < 1)
        return false;
    if (rxMax >= (int32_t)(_map->width-1))
        return false;
    if (ryMin < 1)
        return false;
    if (ryMax >= (int32_t)(_map->height-1))
        return false;
    for (uint32_t i = ryMin; i < (uint32_t)ryMax; i++)
    {
        for (uint32_t j = rxMin; j < (uint32_t)rxMax; j++)
        {
            if (_map->tile[(i * _map->width) + j].base != eTileBase::tileWall)
                return false;
        }
    }
    return true;
}

void cMapManager::genSquareRoom(sMap*& _map, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r)
{
    if (_map->tile == nullptr)
        return;
    uint32_t rxMin = _x - _r - 1;
    uint32_t rxMax = _x + _r;
    uint32_t ryMin = _y - _r - 1;
    uint32_t ryMax = _y + _r;
    for (uint32_t i = ryMin; i < ryMax; i++)
    {
        for (uint32_t j = rxMin; j < rxMax; j++)
        {
                _map->tile[(i * _map->width) + j].base = eTileBase::tileFloor;
        }
    }
}

static void mapFindRoom(sMap*& _map, const uint32_t &i)
{
    if (i  < _map->numTiles)
    {
        if ((!_map->tile[i].processed) && (_map->tile[i].base == eTileBase::tileFloor))
        {
            _map->tile[i].processed = true;
            _map->tile[i].room = _map->roomCount;
            if (((i + 1) > 0) && ((i + 1) < _map->numTiles))
                mapFindRoom(_map, i + 1);
            if (((i - 1) > 0) && ((i - 1) < _map->numTiles))
                mapFindRoom(_map, i - 1);
            if (((i + _map->width) > 0) && ((i + _map->width) < _map->numTiles))
                mapFindRoom(_map, i + _map->width);
            if (((i - _map->width) > 0) && ((i - _map->width) < _map->numTiles))
                mapFindRoom(_map, i - _map->width);
        }
    }
}

void cMapManager::mapFindRooms(sMap*& _map)
{
    if (_map->tile != nullptr)
    {
        _map->roomCount = 0;
        for (uint32_t i = 0; i < _map->numTiles; i++)
        {
            _map->tile[i].room = 0;
            _map->tile[i].processed = false;
        }
        for (uint32_t i = 0; i < _map->numTiles; i++)
        {
            if ((!_map->tile[i].processed) && (_map->tile[i].base == eTileBase::tileFloor))
            {
                mapFindRoom(_map, i);
                _map->roomCount++;
            }
        }
    }
}

static void mapDiscardMinRooms(sMap*& _map)
{
    uint16_t discardCount = 0;
    if (_map->tile != nullptr)
    {
        for (uint16_t i = 0; i < _map->roomCount; i++)
        {
            uint32_t tileCount = 0;
            for (uint32_t j = 0; j < _map->numTiles; j++)
            {
                if ((_map->tile[j].room == i) && (_map->tile[j].base == eTileBase::tileFloor))
                    tileCount++;
            }
            if (tileCount < (uint32_t)(_map->genData.roomRadiusMin * _map->genData.roomRadiusMin))
            {
                discardCount++;
                for (uint32_t j = 0; j < _map->numTiles; j++)
                {
                    if (_map->tile[j].room == i)
                    {
                        _map->tile[j].room = 0;
                        _map->tile[j].base = eTileBase::tileWall;
                    }
                }
            }
        }
    }
    _map->roomCount -= discardCount;
}

static void mapRoomSizeLocation(sMap*& _map)
{
    if ((_map->roomCount > 0) && (_map->room != nullptr))
    {
        for (uint16_t i = 0; i < _map->roomCount; i++)
        {
            _map->room[i].posXMin = _map->width;
            _map->room[i].posXMax = 0;
            _map->room[i].posYMin = _map->height;
            _map->room[i].posYMax = 0;
            for (uint32_t j = 0; j < _map->height; j++)
            {
                for (uint32_t k = 0; k < _map->width; k++)
                {
                    if ((_map->tile[(j * _map->width) + k].room == i) && (_map->tile[(j * _map->width) + k].base == eTileBase::tileFloor))
                    {
                        if (k < _map->room[i].posXMin)
                            _map->room[i].posXMin = k;
                        if (k > _map->room[i].posXMax)
                            _map->room[i].posXMax = k;
                        if (j < _map->room[i].posYMin)
                            _map->room[i].posYMin = j;
                        if (j > _map->room[i].posYMax)
                            _map->room[i].posYMax = j;
                    }
                }
            }
            _map->room[i].w = _map->room[i].posXMax - _map->room[i].posXMin + 1;
            _map->room[i].h = _map->room[i].posYMax - _map->room[i].posYMin + 1;
            //if ((_map->room[i].w % 2) == 0)
                _map->room[i].x = (_map->room[i].w / 2) + _map->room[i].posXMin;
            //else
                //_map->room[i].x = ((_map->room[i].w - 1) / 2) + _map->room[i].posXMin + 1;

            //if ((_map->room[i].h % 2) == 0)
                _map->room[i].y = (_map->room[i].h / 2) + _map->room[i].posYMin;
            //else
                //_map->room[i].y = ((_map->room[i].h - 1) / 2) + _map->room[i].posYMin + 1;
        }
    }
}

uint32_t cMapManager::mapGetRoomArea(sMap*& _map, const uint16_t &_r)
{
    uint32_t returnValue = 0;
    if (_map->tile != nullptr)
    {
        for (uint32_t i = 0; i < _map->numTiles; i++)
            if ((_map->tile[i].room == _r) && (_map->tile[i].base == eTileBase::tileFloor))
                returnValue++;
    }
    return returnValue;
}

void cMapManager::mapRoomDiscardAllButLargest(sMap*& _map)
{
    if ((_map->roomCount > 0) && (_map->room != nullptr) && (_map->tile != nullptr))
    {
        uint32_t roomSizeT = 0;
        uint32_t roomSize = 0;
        uint32_t roomNumber = 0;
        for (uint16_t i = 0; i < _map->roomCount; i++)
        {
            roomSizeT = mapGetRoomArea(_map, i);
            if (roomSizeT > roomSize)
            {
                roomSize = roomSizeT;
                roomNumber = i;
            }
        }
        for (uint32_t i = 0; i < _map->numTiles; i++)
        {
            if ((_map->tile[i].room != roomNumber) && (_map->tile[i].base == eTileBase::tileFloor))
            {
                _map->tile[i].room = -1; // No room
                _map->tile[i].base = eTileBase::tileWall;
            }
            else
                _map->tile[i].room = 0;
        }
    }
    _map->roomCount = 1;
    if (_map->room != nullptr)
        delete _map->room;
    _map->room = new sMapRoom[_map->roomCount];
    mapRoomSizeLocation(_map);
}

void cMapManager::mapInitRooms(sMap*& _map)
{
    mapFindRooms(_map);
    mapDiscardMinRooms(_map);
    mapFindRooms(_map);
    if (_map->roomCount > 0)
    {
        if (_map->room != nullptr)
            delete _map->room;
        _map->room = new sMapRoom[_map->roomCount];
        for (uint16_t i = 0; i < _map->roomCount; i++)
        {
            _map->room[i].exitE = -1; // No room
            _map->room[i].exitW = -1; // No room
            _map->room[i].exitS = -1; // No room
            _map->room[i].exitN = -1; // No room
        }
        mapRoomSizeLocation(_map);
    }
}
