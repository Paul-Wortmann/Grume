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

void cMapManager::m_genD1_internal(sMap*& _map)
{
    // If room data, free
    if (_map->room != nullptr)
    {
        delete[] _map->room;
        _map->room = nullptr;
        _map->numRoom = 0;
    }

    // Fill map with default wall tiles
    eRoomShape roomShape = _map->generate->roomShape;
    std::uint32_t roomMax = _map->generate->density * _map->generate->pass;
    for (std::uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].type = eTileType::tileWallTall;
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    for (std::uint32_t i = 0; i < roomMax; i++)
    {
        std::uint32_t r = (rand() % (_map->generate->roomRadiusMax - _map->generate->roomRadiusMin)) + _map->generate->roomRadiusMin;
        if ((r % 2) != 0)
        {
            r++;
        }
        if (r < _map->generate->roomRadiusMin)
        {
            r = _map->generate->roomRadiusMin;
        }
        if (r > _map->generate->roomRadiusMax)
        {
            r = _map->generate->roomRadiusMax;
        }
        std::uint32_t x = (rand() % (_map->info.size_x - r - r)) + r;
        std::uint32_t y = (rand() % (_map->info.size_y - r - r)) + r;
        if ((x > r) && (x < _map->info.size_x - r) && (y > r) && (y < _map->info.size_y - r))
        {
            if (_map->generate->roomShape == eRoomShape::shapeRandom)
            {
                roomShape = ((rand() % 100) < 50) ? eRoomShape::shapeCircle : eRoomShape::shapeSquare;
            }
            if (roomShape == eRoomShape::shapeCircle)
            {
                if (m_genCircleRoomOK(_map, x, y, r + _map->generate->roomBorder))
                {
                    m_genCircleRoom(_map, x, y, r);
                }
            }
            if (roomShape == eRoomShape::shapeSquare)
            {
                if (m_genSquareRoomOK(_map, x, y, r + _map->generate->roomBorder))
                {
                    m_genSquareRoom(_map, x, y, r);
                }
            }
        }
    }
    m_mapInitRoomsND(m_map);
}

void cMapManager::m_generateMap_D1(sMap*& _map)
{
    for (std::uint16_t i = 0; i < _map->generate->pass; i++)
    {
        m_genD1_internal(_map);
        if ((m_mapGetFloorArea(_map) > (_map->numTiles / _map->generate->floorAreaMin)) && (_map->numRoom >= _map->generate->roomMin))
        {
            i = _map->generate->pass;
        }
        else
        {
            // epoch in microseconds
            std::uint64_t milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

            _map->info.seed = milliseconds_since_epoch;
            srand (_map->info.seed);
            mapList[_map->info.name] = _map->info.seed;
        }
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

//    m_mapInitRoomsND(m_map);
    m_mapConnectRooms(_map);
    m_mapAddDooryways(_map);

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
    m_addDebris();
    m_addNPC_mobs();
}
