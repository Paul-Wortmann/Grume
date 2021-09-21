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
    for (uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].base = eTileBase::tileWall;
    }

    // Generate random circles to create the room/s
    uint32_t blobCount = _map->genData.density * _map->genData.pass;
    for (uint32_t i = 0; i < blobCount; i++)
    {
        uint32_t r = (rand() % (_map->genData.roomRadiusMax - _map->genData.roomRadiusMin)) + _map->genData.roomRadiusMin;

        uint32_t x = (rand() % (_map->width  - r - r)) + r;
        uint32_t y = (rand() % (_map->height - r - r)) + r;

        m_genCircleRoom(_map, x, y, r);
    }
}

void cMapManager::m_generateMap_C2(sMap*& _map)
{
    bool seeded = !(_map->genData.seed == 0);
    if (seeded)
    {
        srand (_map->genData.seed);
        m_genC2_internal(_map);
    }
    else
    {
        for (uint16_t i = 0; i < _map->genData.pass; i++)
        {
            _map->genData.seed = time(nullptr);
            srand (_map->genData.seed);
            m_genC2_internal(_map);
            m_mapInitRooms(_map);
            m_mapRoomDiscardAllButLargest(_map);
            m_mapRemoveAnomalies(_map);

            if (m_mapGetFloorArea(_map) > (_map->numTiles * (_map->genData.floorAreaMin / 100.0f)))
            {
                i = _map->genData.pass;
            }
        }
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    // Smoothing pass to remove artifacts
    m_mapRemoveAnomalies(_map);

    // Flood fill, delete rooms that are too small
    m_mapRoomDiscardAllButLargest(_map);

    // Room identification
    m_mapInitRooms(_map);
    
    // Room connection
    m_mapConnectRooms(_map);

    // Room add stairs
    m_addStairsEntity(_map);

    // Room add prefab
    m_mapPrefabRooms(_map);
    
    // Populate the map with objects
    m_generateMap_objects(_map);

    // Populate the map with npcs
    m_generateMap_npcs(_map);
}
