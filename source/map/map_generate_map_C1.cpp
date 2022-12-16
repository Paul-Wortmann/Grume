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

std::uint32_t cMapManager::m_numNeighborTiles(sMap*& _map, const std::uint32_t &_tile)
{
    // _tile is unsigned, as such use a signed variable.
    const std::int64_t tile_x = _tile % _map->info.size_x;
    const std::int64_t tile_y = _tile / _map->info.size_y;

    std::uint32_t numNeighbors = 0;

    if (m_isWall(tile_x - 1, tile_y))
        numNeighbors++;
    if (m_isWall(tile_x - 1, tile_y - 1))
        numNeighbors++;
    if (m_isWall(tile_x - 1, tile_y + 1))
        numNeighbors++;
    if (m_isWall(tile_x + 1, tile_y))
        numNeighbors++;
    if (m_isWall(tile_x + 1, tile_y - 1))
        numNeighbors++;
    if (m_isWall(tile_x + 1, tile_y + 1))
        numNeighbors++;
    if (m_isWall(tile_x, tile_y - 1))
        numNeighbors++;
    if (m_isWall(tile_x, tile_y + 1))
        numNeighbors++;

    return numNeighbors;
}

void cMapManager::m_generateMap_C1(sMap*& _map)
{
    std::uint32_t numItterations = 3;
    std::uint32_t density        = 100; // Density increases with smaller numbers

    // Randomly place walls
    for (std::uint32_t i = 0; i < _map->numTiles; ++i)
    {
        std::uint32_t randInt = rand() % density;
        _map->tile[i].type = (randInt < 45) ? eTileType::tileWallTall : eTileType::tileFloor;
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    // Generate 2 x 2 floors in the center: ensure this space is available for the floodfill

    // Use cellular automata to shape the map
    for (std::uint32_t j = 0; j < numItterations; ++j)
    {
        for (std::uint32_t i = _map->info.size_x; i < (_map->numTiles - _map->info.size_x); ++i)
        {
            // Dont process perimeter walls
            if (((i % _map->info.size_x) != 0) && ((i % _map->info.size_x) != (_map->info.size_x - 1)))
            {
                // Get the number of neigbor tiles which are walls
                std::uint32_t numNeighbors = m_numNeighborTiles(_map, i);

                // Apply the 4-5 rule
                if (((_map->tile[i].type == eTileType::tileWallTall) && numNeighbors >= 4) ||
                    ((_map->tile[i].type == eTileType::tileFloor) && numNeighbors >= 5))
                {
                    _map->tile[i].type = eTileType::tileWallTall;
                }
                else
                {
                    _map->tile[i].type = eTileType::tileFloor;
                }
            }
        }
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    m_mapInitRoomsND(m_map);
    m_mapConnectRooms(_map);
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
    m_addDebris();
    m_addNPC_mobs();
}
