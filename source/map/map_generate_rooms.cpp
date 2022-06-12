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

#include "map_manager.hpp"

bool cMapManager::m_genCircleRoomOK(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r)
{
    if (_map->tile == nullptr)
        return false;
        
    for (std::uint32_t i = 0; i < _map->height; i++)
    {
        for (std::uint32_t j = 0; j < _map->width; j++)
        {
            if ((((j - _x) * (j - _x)) + ((i - _y) * (i - _y))) < (_r * _r))
                if (_map->tile[(i * _map->width) + j].base == eTileBase::tileFloor)
                    return false;
        }
    }
    return true;
}

void cMapManager::m_genCircleRoom(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r)
{
    if (_map->tile == nullptr)
        return;
        
    for (std::uint32_t i = 0; i < _map->height; i++)
    {
        for (std::uint32_t j = 0; j < _map->width; j++)
        {
            if ((((j - _x) * (j - _x)) + ((i - _y) * (i - _y))) < (_r * _r))
                _map->tile[(i * _map->width) + j].base = eTileBase::tileFloor;
        }
    }
}

bool cMapManager::m_genSquareRoomOK(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r)
{
    if (_map->tile == nullptr)
        return false;
        
    std::int32_t rxMin = _x - _r - 1;
    std::int32_t rxMax = _x + _r;
    std::int32_t ryMin = _y - _r - 1;
    std::int32_t ryMax = _y + _r;
    
    if (rxMin < 1)
        return false;
    if (rxMax >= (std::int32_t)(_map->width-1))
        return false;
    if (ryMin < 1)
        return false;
    if (ryMax >= (std::int32_t)(_map->height-1))
        return false;
        
    for (std::uint32_t i = ryMin; i < (std::uint32_t)ryMax; i++)
    {
        for (std::uint32_t j = rxMin; j < (std::uint32_t)rxMax; j++)
        {
            if (_map->tile[(i * _map->width) + j].base != eTileBase::tileWall)
                return false;
        }
    }
    return true;
}

void cMapManager::m_genSquareRoom(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r)
{
    if (_map->tile == nullptr)
        return;
        
    std::uint32_t rxMin = _x - _r - 1;
    std::uint32_t rxMax = _x + _r;
    std::uint32_t ryMin = _y - _r - 1;
    std::uint32_t ryMax = _y + _r;
    
    for (std::uint32_t i = ryMin; i < ryMax; i++)
    {
        for (std::uint32_t j = rxMin; j < rxMax; j++)
        {
                _map->tile[(i * _map->width) + j].base = eTileBase::tileFloor;
        }
    }
}

static void m_mapFindRoom(sMap*& _map, const std::uint32_t &i)
{
    if (i  < _map->numTiles)
    {
        if ((!_map->tile[i].processed) && (_map->tile[i].base == eTileBase::tileFloor))
        {
            _map->tile[i].processed = true;
            _map->tile[i].room = _map->roomCount;
            if (((i + 1) > 0) && ((i + 1) < _map->numTiles))
                m_mapFindRoom(_map, i + 1);
            if (((i - 1) > 0) && ((i - 1) < _map->numTiles))
                m_mapFindRoom(_map, i - 1);
            if (((i + _map->width) > 0) && ((i + _map->width) < _map->numTiles))
                m_mapFindRoom(_map, i + _map->width);
            if (((i - _map->width) > 0) && ((i - _map->width) < _map->numTiles))
                m_mapFindRoom(_map, i - _map->width);
        }
    }
}

void cMapManager::m_mapFindRooms(sMap*& _map)
{
    if (_map->tile != nullptr)
    {
        _map->roomCount = 0;
        for (std::uint32_t i = 0; i < _map->numTiles; i++)
        {
            _map->tile[i].room = 0;
            _map->tile[i].processed = false;
        }
        
        for (std::uint32_t i = 0; i < _map->numTiles; i++)
        {
            if ((!_map->tile[i].processed) && (_map->tile[i].base == eTileBase::tileFloor))
            {
                m_mapFindRoom(_map, i);
                _map->roomCount++;
            }
        }
    }
}

static void m_mapDiscardMinRooms(sMap*& _map)
{
    std::uint16_t discardCount = 0;
    if (_map->tile != nullptr)
    {
        for (std::uint16_t i = 0; i < _map->roomCount; i++)
        {
            std::uint32_t tileCount = 0;
            for (std::uint32_t j = 0; j < _map->numTiles; j++)
            {
                if ((_map->tile[j].room == i) && (_map->tile[j].base == eTileBase::tileFloor))
                    tileCount++;
            }
            
            if (tileCount < (std::uint32_t)(_map->genData.roomRadiusMin * _map->genData.roomRadiusMin))
            {
                discardCount++;
                for (std::uint32_t j = 0; j < _map->numTiles; j++)
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

static void m_mapRoomSizeLocation(sMap*& _map)
{
    if ((_map->roomCount > 0) && (_map->room != nullptr))
    {
        for (std::uint16_t i = 0; i < _map->roomCount; i++)
        {
            _map->room[i].posXMin = _map->width;
            _map->room[i].posXMax = 0;
            _map->room[i].posYMin = _map->height;
            _map->room[i].posYMax = 0;
            for (std::uint32_t j = 0; j < _map->height; j++)
            {
                for (std::uint32_t k = 0; k < _map->width; k++)
                {
                    if ((_map->tile[(j * _map->width) + k].room == i) && (_map->tile[(j * _map->width) + k].base == eTileBase::tileFloor))
                    {
                        if (k < _map->room[i].posXMin)
                        {
                            _map->room[i].posXMin = k;
                        }
                        if (k > _map->room[i].posXMax)
                        {
                            _map->room[i].posXMax = k;
                        }
                        if (j < _map->room[i].posYMin)
                        {
                            _map->room[i].posYMin = j;
                        }
                        if (j > _map->room[i].posYMax)
                        {
                            _map->room[i].posYMax = j;
                        }
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

std::uint32_t cMapManager::m_mapGetRoomArea(sMap*& _map, const std::uint16_t &_r)
{
    std::uint32_t returnValue = 0;
    if (_map->tile != nullptr)
    {
        for (std::uint32_t i = 0; i < _map->numTiles; i++)
        {
            if ((_map->tile[i].room == _r) && (_map->tile[i].base == eTileBase::tileFloor))
                returnValue++;
        }
    }
    return returnValue;
}

void cMapManager::m_mapRoomDiscardAllButLargest(sMap*& _map)
{
    if ((_map->roomCount > 0) && (_map->room != nullptr) && (_map->tile != nullptr))
    {
        std::uint32_t roomSize   = 0;
        std::uint32_t roomNumber = 0;
        for (std::uint16_t i = 0; i < _map->roomCount; i++)
        {
            std::uint32_t roomSizeT = m_mapGetRoomArea(_map, i);
            if (roomSizeT > roomSize)
            {
                roomSize = roomSizeT;
                roomNumber = i;
            }
        }
        for (std::uint32_t i = 0; i < _map->numTiles; i++)
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
    {
        delete[] _map->room;
        _map->room = nullptr;
    }
    _map->room = new sMapRoom[_map->roomCount];
    m_mapRoomSizeLocation(_map);
}

void cMapManager::m_mapInitRooms(sMap*& _map)
{
    m_mapFindRooms(_map);
    m_mapDiscardMinRooms(_map);
    m_mapFindRooms(_map);
    if (_map->roomCount > 0)
    {
        if (_map->room != nullptr)
        {
            delete[] _map->room;
            _map->room = nullptr;
        }
        _map->room = new sMapRoom[_map->roomCount];
        for (std::uint16_t i = 0; i < _map->roomCount; i++)
        {
            _map->room[i].exitE = -1; // No room
            _map->room[i].exitW = -1; // No room
            _map->room[i].exitS = -1; // No room
            _map->room[i].exitN = -1; // No room
        }
        m_mapRoomSizeLocation(_map);
    }
}

void cMapManager::m_mapInitRoomsND(sMap*& _map)
{
    m_mapFindRooms(_map);
    if (_map->roomCount > 0)
    {
        if (_map->room != nullptr)
        {
            delete[] _map->room;
            _map->room = nullptr;
        }
        _map->room = new sMapRoom[_map->roomCount];
        for (std::uint16_t i = 0; i < _map->roomCount; i++)
        {
            _map->room[i].exitE = -1; // No room
            _map->room[i].exitW = -1; // No room
            _map->room[i].exitS = -1; // No room
            _map->room[i].exitN = -1; // No room
        }
        m_mapRoomSizeLocation(_map);
    }
}

std::int32_t cMapManager::m_getRoomFromTile(sMap*& _map, const std::uint32_t &_tile, const std::int32_t &_roomIgnore)
{
    if (_map->roomCount > 0)
    {
        for (std::uint16_t i = 0; i < _map->roomCount; ++i)
        {
            if (static_cast<std::int32_t>(i) != _roomIgnore)
            {
                std::uint32_t sx = _map->room[i].x - (_map->room[i].w / 2);
                std::uint32_t sy = _map->room[i].y - (_map->room[i].h / 2);
                std::uint32_t ex = _map->room[i].x + (_map->room[i].w / 2);
                std::uint32_t ey = _map->room[i].y + (_map->room[i].h / 2);
                std::uint32_t tx = _tile % _map->width;
                std::uint32_t ty = _tile / _map->width;
                
                if ((tx >= sx) && (tx <= ex) && (ty >= sy) && (ty <= ey))
                {
                    return i;
                }
            }
        }
    }
    return -1;
}
