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

uint32 cMapManager::m_numNeighborTiles(sMap*& _map, const uint32 &_tile)
{
    uint32 numNeighbors = 0;

    if (((_tile - 1) >= 0) && _map->tile[_tile - 1].base == eTileBase::tileWall)
        numNeighbors++;
    if (((_tile - _map->width) >= 0) && _map->tile[_tile - _map->width].base == eTileBase::tileWall)
        numNeighbors++;
    if (((_tile - _map->width + 1) >= 0) && _map->tile[_tile - _map->width + 1].base == eTileBase::tileWall)
        numNeighbors++;
    if (((_tile - _map->width - 1) >= 0) && _map->tile[_tile - _map->width - 1].base == eTileBase::tileWall)
        numNeighbors++;
    if (((_tile + 1) < _map->numTiles) && _map->tile[_tile + 1].base == eTileBase::tileWall)
        numNeighbors++;
    if (((_tile + _map->width) < _map->numTiles) && _map->tile[_tile + _map->width].base == eTileBase::tileWall)
        numNeighbors++;
    if (((_tile + _map->width - 1) < _map->numTiles) && _map->tile[_tile + _map->width - 1].base == eTileBase::tileWall)
        numNeighbors++;
    if (((_tile + _map->width + 1) < _map->numTiles) && _map->tile[_tile + _map->width + 1].base == eTileBase::tileWall)
        numNeighbors++;

    return numNeighbors;
}

void cMapManager::m_generateMap_C1(sMap*& _map)
{
    uint32 numItterations = 3;
    uint32 density        = 100; // Density increases with smaller numbers

    // Randomly place walls
    for (uint32 i = 0; i < _map->numTiles; ++i)
    {
        uint32 randInt = rand() % density;
        _map->tile[i].base = (randInt < 45) ? eTileBase::tileWall : eTileBase::tileFloor;
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    // Generate 2 x 2 floors in the center: ensure this space is available for the floodfill

    // Use cellular automata to shape the map
    for (uint32 j = 0; j < numItterations; ++j)
    {
        for (uint32 i = _map->width; i < (_map->numTiles - _map->width); ++i)
        {
            // Dont process perimeter walls
            if (((i % _map->width) != 0) && ((i % _map->width) != (_map->width - 1)))
            {
                // Get the number of neigbor tiles which are walls
                uint32 numNeighbors = m_numNeighborTiles(_map, i);

                // Apply the 4-5 rule
                if (((_map->tile[i].base == eTileBase::tileWall) && numNeighbors >= 4) ||
                    ((_map->tile[i].base == eTileBase::tileFloor) && numNeighbors >= 5))
                {
                    _map->tile[i].base = eTileBase::tileWall;
                }
                else
                {
                    _map->tile[i].base = eTileBase::tileFloor;
                }
            }
        }
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    // Smoothing pass to remove artifacts

    // Flood fill, delete rooms that are too small

    // Room identification

    // Room connection

    // Populate the map with objects
    m_generateMap_objects(_map);

    // Populate the map with npcs
    m_generateMap_npcs(_map);
}
