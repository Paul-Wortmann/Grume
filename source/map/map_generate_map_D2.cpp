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

static void splitRoom(sMap*& _map, const std::uint32_t _roomID)
{
    bool splitX = (_map->room[_roomID].w > static_cast<std::uint32_t>(((_map->generate->roomRadiusMin * 2) + _map->generate->roomBorder) * 2));
    bool splitY = (_map->room[_roomID].h > static_cast<std::uint32_t>(((_map->generate->roomRadiusMin * 2) + _map->generate->roomBorder) * 2));
    if (!splitX && !splitY)
    {
        _map->room[_roomID].p = false;
        return;
    }
    else
    {
        std::uint32_t newRoomID = _map->numRoom;
        sMapRoom *tRoom = new sMapRoom[_map->numRoom];
        for (std::uint32_t i = 0; i < _map->numRoom; i++)
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
        _map->numRoom++;
        _map->room = new sMapRoom[_map->numRoom];
        for (std::uint32_t i = 0; i < _map->numRoom-1; i++)
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
            std::uint32_t splitMaxX = _map->room[_roomID].w - ((_map->generate->roomRadiusMin + _map->generate->roomBorder) * 2);
            std::uint32_t splitDeltaX = rand() % splitMaxX;
            _map->room[_roomID].w = _map->generate->roomRadiusMin + _map->generate->roomBorder + (splitMaxX - splitDeltaX);
            _map->room[newRoomID].w = _map->generate->roomRadiusMin + _map->generate->roomBorder + splitDeltaX;
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
                _map->tile[(_map->room[_roomID].y * _map->info.size_x) + _map->room[newRoomID].posXMin - 1].type = eTileType::tileDoorway;
            }
        }
        if (splitY)
        {
            _map->room[newRoomID].p = true;
            _map->room[newRoomID].x = _map->room[_roomID].x;
            _map->room[newRoomID].w = _map->room[_roomID].w;
            _map->room[newRoomID].posXMin = _map->room[_roomID].posXMin;
            _map->room[newRoomID].posXMax = _map->room[_roomID].posXMax;
            std::uint32_t splitMaxY = _map->room[_roomID].h - ((_map->generate->roomRadiusMin + _map->generate->roomBorder) * 2);
            std::uint32_t splitDeltaY = rand() % splitMaxY;
            _map->room[_roomID].h = _map->generate->roomRadiusMin + _map->generate->roomBorder + (splitMaxY - splitDeltaY);
            _map->room[newRoomID].h = _map->generate->roomRadiusMin + _map->generate->roomBorder + splitDeltaY;
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
                _map->tile[((_map->room[newRoomID].posYMin - 1) * _map->info.size_x) + _map->room[_roomID].x].type = eTileType::tileDoorway;
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
    std::uint32_t availableRooms = 1;
    while (availableRooms != 0)
    {
        availableRooms = 0;
        for (std::uint32_t i = 0; i < _map->numRoom; i++)
        {
            if (_map->room[i].p)
            {
                splitRoom(_map, i);
                i = _map->numRoom;
            }
        }
        for (std::uint32_t i = 0; i < _map->numRoom; i++)
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
    for (std::uint32_t k = 0; k < _map->numRoom; k++)
    {
        for (std::uint32_t i = _map->room[k].posYMin; i < _map->room[k].posYMax; i++)
        {
            for (std::uint32_t j = _map->room[k].posXMin; j < _map->room[k].posXMax; j++)
            {
                _map->tile[(i * _map->info.size_x) + j].type = eTileType::tileFloor;
            }
        }
    }
}

static void removeAnomaliesRooms(sMap*& _map)
{
    for (std::uint32_t y = 1; y < _map->info.size_y - 1; y++)
    {
        for (std::uint32_t x = 1; x < _map->info.size_x - 1; x++)
        {
            std::uint32_t t = (y * _map->info.size_x) + x;
            if (_map->tile[t].type == eTileType::tileDoorway)
            {
                std::uint32_t n = 0;
                n += (_map->tile[t + 1].type == eTileType::tileWallTall) ? 1 : 0;
                n += (_map->tile[t - 1].type == eTileType::tileWallTall) ? 1 : 0;
                n += (_map->tile[t + _map->info.size_x].type == eTileType::tileWallTall) ? 1 : 0;
                n += (_map->tile[t - _map->info.size_x].type == eTileType::tileWallTall) ? 1 : 0;
                if (n > 2)
                {
                    _map->tile[t].type = eTileType::tileWallTall;
                    if (_map->tile[t + 1].type == eTileType::tileWallTall)
                    {
                        if ((_map->tile[t + 1 + _map->info.size_x].type == eTileType::tileFloor)
                         && (_map->tile[t + 1 - _map->info.size_x].type == eTileType::tileFloor))
                         {
                            _map->tile[t + 1].type = eTileType::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t + 2].type = eTileType::tileDoorway;
                         }
                    }
                    if (_map->tile[t - 1].type == eTileType::tileWallTall)
                    {
                        if ((_map->tile[t - 1 + _map->info.size_x].type == eTileType::tileFloor)
                         && (_map->tile[t - 1 - _map->info.size_x].type == eTileType::tileFloor))
                         {
                            _map->tile[t - 1].type = eTileType::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t - 2].type = eTileType::tileDoorway;
                         }
                    }
                    if (_map->tile[t + _map->info.size_x].type == eTileType::tileWallTall)
                    {
                        if ((_map->tile[t + _map->info.size_x + 1].type == eTileType::tileFloor)
                         && (_map->tile[t + _map->info.size_x - 1].type == eTileType::tileFloor))
                         {
                            _map->tile[t + _map->info.size_x].type = eTileType::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t + (2 * _map->info.size_x)].type = eTileType::tileDoorway;
                         }
                    }
                    if (_map->tile[t - _map->info.size_x].type == eTileType::tileWallTall)
                    {
                        if ((_map->tile[t - _map->info.size_x + 1].type == eTileType::tileFloor)
                         && (_map->tile[t - _map->info.size_x - 1].type == eTileType::tileFloor))
                         {
                            _map->tile[t - _map->info.size_x].type = eTileType::tileDoorway;
                         }
                         else
                         {
                            _map->tile[t - (2 * _map->info.size_x)].type = eTileType::tileDoorway;
                         }
                    }
                }
            }
        }
    }
}

void cMapManager::m_genD2_internal(sMap*& _map)
{
    for (std::uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].type = eTileType::tileWallTall;
    }
    if (_map->room != nullptr)
    {
        delete[] _map->room;
    }
    _map->numRoom = 1;
    _map->room = new sMapRoom[_map->numRoom];
    _map->room[0].p = true;
    _map->room[0].x = (_map->info.size_x-2) / 2;
    _map->room[0].y = (_map->info.size_y-2) / 2;
    _map->room[0].w = (_map->info.size_x-1);
    _map->room[0].h = (_map->info.size_y-1);
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
    for (std::uint16_t i = 0; i < _map->generate->pass; i++)
    {
        m_genD2_internal(_map);
        if ((m_mapGetFloorArea(_map) > (_map->numTiles / _map->generate->floorAreaMin)) && (_map->numRoom >= _map->generate->roomMin))
        {
            i = _map->generate->pass;
        }
        else
        {
            _map->info.seed = time(nullptr);
            srand (_map->info.seed);
            mapList[_map->info.name] = _map->info.seed;
        }
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    m_mapInitRoomsND(m_map);
//    m_mapConnectRooms(_map);
//    m_mapAddDooryways(_map);

    m_playMapMusic();
    m_addWalls();
    m_addFloors();
    m_addPaths();
    m_addEvents();
    m_addPortals();

    m_generatePortals(_map);

    m_addPrefabs();
    m_addDoors();
    m_addTorches();
    m_addObjects();
    m_addNPCs();
    m_addChests();
    m_addDestructibles();
    m_addDebris();
    m_addNPC_mobs();
}
