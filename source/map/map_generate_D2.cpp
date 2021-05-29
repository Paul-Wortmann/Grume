/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
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
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "map_manager.hpp"

static void splitRoom(sMap*& _map, const uint16_t _roomID)
{
    bool splitX = (_map->room[_roomID].w > (((_map->genData.roomRadiusMin * 2) + _map->genData.roomBorder) * 2));
    bool splitY = (_map->room[_roomID].h > (((_map->genData.roomRadiusMin * 2) + _map->genData.roomBorder) * 2));
    if (!splitX && !splitY)
    {
        _map->room[_roomID].p = false;
        return;
    }
    else
    {
        uint16_t newRoomID = _map->roomCount;
        sMapRoom *tRoom = new sMapRoom[_map->roomCount];
        for (uint16_t i = 0; i < _map->roomCount; i++)
        {
            tRoom[i].type    = _map->room[i].type;
            tRoom[i].p       = _map->room[i].p;
            tRoom[i].posXMin = _map->room[i].posXMin;
            tRoom[i].posXMax = _map->room[i].posXMax;
            tRoom[i].posYMin = _map->room[i].posYMin;
            tRoom[i].posYMax = _map->room[i].posYMax;
            tRoom[i].x       = _map->room[i].x;
            tRoom[i].y       = _map->room[i].y;
            tRoom[i].w       = _map->room[i].w;
            tRoom[i].h       = _map->room[i].h;
            tRoom[i].exitN   = _map->room[i].exitN;
            tRoom[i].exitS   = _map->room[i].exitS;
            tRoom[i].exitE   = _map->room[i].exitE;
            tRoom[i].exitW   = _map->room[i].exitW;
        }
        delete[] _map->room;
        _map->roomCount++;
        _map->room = new sMapRoom[_map->roomCount];
        for (uint16_t i = 0; i < _map->roomCount-1; i++)
        {
            _map->room[i].type    = tRoom[i].type;
            _map->room[i].p       = tRoom[i].p;
            _map->room[i].posXMin = tRoom[i].posXMin;
            _map->room[i].posXMax = tRoom[i].posXMax;
            _map->room[i].posYMin = tRoom[i].posYMin;
            _map->room[i].posYMax = tRoom[i].posYMax;
            _map->room[i].x       = tRoom[i].x;
            _map->room[i].y       = tRoom[i].y;
            _map->room[i].w       = tRoom[i].w;
            _map->room[i].h       = tRoom[i].h;
            _map->room[i].exitN   = tRoom[i].exitN;
            _map->room[i].exitS   = tRoom[i].exitS;
            _map->room[i].exitE   = tRoom[i].exitE;
            _map->room[i].exitW   = tRoom[i].exitW;
        }
        if (splitX && splitY)
        {
            (_map->room[_roomID].w > _map->room[_roomID].h) ? (splitY = !splitY) : (splitX = !splitX);
        }
        if (splitX)
        {
            _map->room[newRoomID].p = true;
            _map->room[newRoomID].y = _map->room[_roomID].y;
            _map->room[newRoomID].h = _map->room[_roomID].h;
            _map->room[newRoomID].posYMin = _map->room[_roomID].posYMin;
            _map->room[newRoomID].posYMax = _map->room[_roomID].posYMax;
            uint16_t splitMaxX = _map->room[_roomID].w - ((_map->genData.roomRadiusMin + _map->genData.roomBorder) * 2);
            uint16_t splitDeltaX = rand() % splitMaxX;
            _map->room[_roomID].w = _map->genData.roomRadiusMin + _map->genData.roomBorder + (splitMaxX - splitDeltaX);
            _map->room[newRoomID].w = _map->genData.roomRadiusMin + _map->genData.roomBorder + splitDeltaX;
            _map->room[_roomID].x = _map->room[_roomID].posXMin + (_map->room[_roomID].w / 2);
            _map->room[newRoomID].x = _map->room[_roomID].posXMax - (_map->room[newRoomID].w / 2);
            _map->room[newRoomID].posXMin = _map->room[_roomID].posXMin + _map->room[_roomID].w;
            _map->room[newRoomID].posXMax = _map->room[_roomID].posXMax;
            _map->room[_roomID].posXMax = _map->room[_roomID].posXMin + _map->room[_roomID].w - 1;
            
            // Set neighbor room IDs
            _map->room[newRoomID].exitN = _map->room[_roomID].exitN;
            _map->room[newRoomID].exitS = _map->room[_roomID].exitS;
            _map->room[newRoomID].exitE = _map->room[_roomID].exitE;
            _map->room[newRoomID].exitW = _map->room[_roomID].exitW;
            _map->room[newRoomID].exitE = _roomID;
            _map->room[_roomID].exitW = newRoomID;

            // Set doorway
            //for (std::uint32_t i = _map->room[_roomID].x; i < _map->room[newRoomID].x; ++i)
            {
                _map->tile[(_map->room[_roomID].y * _map->width) + _map->room[newRoomID].posXMin - 1].base = eTileBase::tileDoorway;
            }
        }
        if (splitY)
        {
            _map->room[newRoomID].p = true;
            _map->room[newRoomID].x = _map->room[_roomID].x;
            _map->room[newRoomID].w = _map->room[_roomID].w;
            _map->room[newRoomID].posXMin = _map->room[_roomID].posXMin;
            _map->room[newRoomID].posXMax = _map->room[_roomID].posXMax;
            uint16_t splitMaxY = _map->room[_roomID].h - ((_map->genData.roomRadiusMin + _map->genData.roomBorder) * 2);
            uint16_t splitDeltaY = rand() % splitMaxY;
            _map->room[_roomID].h = _map->genData.roomRadiusMin + _map->genData.roomBorder + (splitMaxY - splitDeltaY);
            _map->room[newRoomID].h = _map->genData.roomRadiusMin + _map->genData.roomBorder + splitDeltaY;
            _map->room[_roomID].y = _map->room[_roomID].posYMin + (_map->room[_roomID].h / 2);
            _map->room[newRoomID].y = _map->room[_roomID].posYMax - (_map->room[newRoomID].h / 2);
            _map->room[newRoomID].posYMin = _map->room[_roomID].posYMin + _map->room[_roomID].h;
            _map->room[newRoomID].posYMax = _map->room[_roomID].posYMax;
            _map->room[_roomID].posYMax = _map->room[_roomID].posYMin + _map->room[_roomID].h - 1;

            // Set neighbor room IDs
            _map->room[newRoomID].exitN = _map->room[_roomID].exitN;
            _map->room[newRoomID].exitS = _map->room[_roomID].exitS;
            _map->room[newRoomID].exitE = _map->room[_roomID].exitE;
            _map->room[newRoomID].exitW = _map->room[_roomID].exitW;
            _map->room[newRoomID].exitN = _roomID;
            _map->room[_roomID].exitS = newRoomID;

            // Set doorway
            //for (std::uint32_t i = _map->room[_roomID].y; i < _map->room[newRoomID].y; ++i)
            {
                _map->tile[((_map->room[newRoomID].posYMin - 1) * _map->width) + _map->room[_roomID].x].base = eTileBase::tileDoorway;
            }
        }
        if (tRoom != nullptr)
        {
            delete[] tRoom;
            tRoom = nullptr;
        }
    }
}

static void subdivideMap(sMap*& _map)
{
    uint16_t availableRooms = 1;
    while (availableRooms != 0)
    {
        availableRooms = 0;
        for (uint16_t i = 0; i < _map->roomCount; i++)
        {
            if (_map->room[i].p)
            {
                splitRoom(_map, i);
                i = _map->roomCount;
            }
        }
        for (uint16_t i = 0; i < _map->roomCount; i++)
        {
            if (_map->room[i].p)
            {
                availableRooms++;
            }
        }
    }
}

static void fillRooms(sMap*& _map)
{
    for (uint32_t k = 0; k < _map->roomCount; k++)
    {
        for (uint32_t i = _map->room[k].posYMin; i < _map->room[k].posYMax; i++)
        {
            for (uint32_t j = _map->room[k].posXMin; j < _map->room[k].posXMax; j++)
            {
                _map->tile[(i * _map->width) + j].base = eTileBase::tileFloor;
            }
        }
    }
}

static void removeAnomaliesRooms(sMap*& _map)
{
    for (uint32_t y = 1; y < _map->height - 1; y++)
    {
        for (uint32_t x = 1; x < _map->width - 1; x++)
        {
            uint32_t t = (y * _map->width) + x;
            if (_map->tile[t].base == eTileBase::tileDoorway)
            {
                uint32_t n = 0;
                n += (_map->tile[t + 1].base == eTileBase::tileWall) ? 1 : 0;
                n += (_map->tile[t - 1].base == eTileBase::tileWall) ? 1 : 0;
                n += (_map->tile[t + _map->width].base == eTileBase::tileWall) ? 1 : 0;
                n += (_map->tile[t - _map->width].base == eTileBase::tileWall) ? 1 : 0;
                if (n > 2)
                {
                    _map->tile[t].base = eTileBase::tileWall;
                    if (_map->tile[t + 1].base == eTileBase::tileWall)
                    {
                        if ((_map->tile[t + 1 + _map->width].base == eTileBase::tileFloor)
                         && (_map->tile[t + 1 - _map->width].base == eTileBase::tileFloor))
                         {
                            _map->tile[t + 1].base = eTileBase::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t + 2].base = eTileBase::tileDoorway;
                         }
                    }
                    if (_map->tile[t - 1].base == eTileBase::tileWall)
                    {
                        if ((_map->tile[t - 1 + _map->width].base == eTileBase::tileFloor)
                         && (_map->tile[t - 1 - _map->width].base == eTileBase::tileFloor))
                         {
                            _map->tile[t - 1].base = eTileBase::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t - 2].base = eTileBase::tileDoorway;
                         }
                    }
                    if (_map->tile[t + _map->width].base == eTileBase::tileWall)
                    {
                        if ((_map->tile[t + _map->width + 1].base == eTileBase::tileFloor)
                         && (_map->tile[t + _map->width - 1].base == eTileBase::tileFloor))
                         {
                            _map->tile[t + _map->width].base = eTileBase::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t + (2 * _map->width)].base = eTileBase::tileDoorway;
                         }
                    }
                    if (_map->tile[t - _map->width].base == eTileBase::tileWall)
                    {
                        if ((_map->tile[t - _map->width + 1].base == eTileBase::tileFloor)
                         && (_map->tile[t - _map->width - 1].base == eTileBase::tileFloor))
                         {
                            _map->tile[t - _map->width].base = eTileBase::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t - (2 * _map->width)].base = eTileBase::tileDoorway;
                         }
                    }
                }
            }
        }
    }
}

void cMapManager::m_genD2_internal(sMap*& _map)
{
    for (uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].base = eTileBase::tileWall;
    }
    if (_map->room != nullptr)
    {
        delete[] _map->room;
    }
    _map->roomCount = 1;
    _map->room = new sMapRoom[_map->roomCount];
    _map->room[0].p = true;
    _map->room[0].x = (_map->width-2) / 2;
    _map->room[0].y = (_map->height-2) / 2;
    _map->room[0].w = (_map->width-1);
    _map->room[0].h = (_map->height-1);
    _map->room[0].posXMin = 1;
    _map->room[0].posXMax = _map->room[0].w;
    _map->room[0].posYMin = 1;
    _map->room[0].posYMax = _map->room[0].h;
    subdivideMap(_map);
    fillRooms(_map);
    removeAnomaliesRooms(_map);
}

void cMapManager::m_generateMap_D2(sMap*& _map)
{
    // Generate Rooms
    if (_map->tile != nullptr)
    {
        bool seeded = !(_map->genData.seed == 0);
        if (seeded)
        {
            srand (_map->genData.seed);
            m_genD2_internal(_map);
        }
        else
        {
            for (uint16_t i = 0; i < _map->genData.pass; i++)
            {
                _map->genData.seed = time(NULL);
                srand (_map->genData.seed);
                m_genD2_internal(_map);
                if ((m_mapGetFloorArea(_map) > (_map->numTiles / _map->genData.floorAreaMin)) && (_map->roomCount >= _map->genData.roomMin))
                {
                    i = _map->genData.pass;
                }
            }
        }
    }
    
    // Generate a perimeter wall
    m_generatePerimeterWall(_map);

    // Room identification
    m_mapInitRooms(_map);

    // Room connection
    //m_mapConnectRooms(_map);

    // Room add stairs
    m_addStairsEntity(_map);

    // Room add prefab
    m_mapPrefabRooms(_map);

    // Populate the map with objects
    m_generateMap_objects(_map);

    // Populate the map with npcs
    m_generateMap_npcs(_map);
}
