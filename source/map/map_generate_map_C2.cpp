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

void cMapManager::m_genC2_internal(sMap*& _map)
{
    // Fill the map with wall tiles
    for (std::uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].type = eTileType::tileWallTall;
    }

    // Generate random circles to create the room/s
    std::uint32_t blobCount = _map->generate->density * _map->generate->pass;
    for (std::uint32_t i = 0; i < blobCount; i++)
    {
        std::uint32_t r = (rand() % (_map->generate->roomRadiusMax - _map->generate->roomRadiusMin)) + _map->generate->roomRadiusMin;

        std::uint32_t x = (rand() % (_map->info.size_x  - r - r)) + r;
        std::uint32_t y = (rand() % (_map->info.size_y - r - r)) + r;

        m_genCircleRoom(_map, x, y, r);
    }
}

void cMapManager::m_generateMap_C2(sMap*& _map)
{
    // Generate Rooms
    for (std::uint16_t i = 0; i < _map->generate->pass; i++)
    {
        m_genC2_internal(_map);
        m_mapInitRooms(_map);
        m_mapRoomDiscardAllButLargest(_map);
        m_mapRemoveAnomalies(_map);

        if (m_mapGetFloorArea(_map) > (_map->numTiles * (_map->generate->floorAreaMin / 100.0f)))
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

    // Smoothing pass to remove artifacts
//    m_mapRemoveAnomalies(_map);

    // Flood fill, delete rooms that are too small
    m_mapRoomDiscardAllButLargest(_map);

//    m_mapInitRoomsND(m_map);
    m_mapConnectRooms(_map);

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
