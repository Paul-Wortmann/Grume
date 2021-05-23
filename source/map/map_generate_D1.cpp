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

void cMapManager::m_genD1_internal(sMap*& _map)
{
    eRoomShape roomShape = _map->genData.roomShape;
    uint32_t roomMax = _map->genData.density * _map->genData.pass;
    for (uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].base = eTileBase::tileWall;
    }

    // Generate a perimeter wall
    m_generatePerimeterWall(_map);

    for (uint32_t i = 0; i < roomMax; i++)
    {
        uint32_t r = (rand() % (_map->genData.roomRadiusMax - _map->genData.roomRadiusMin)) + _map->genData.roomRadiusMin;
        if ((r % 2) != 0)
        {
            r++;
        }
        if (r < _map->genData.roomRadiusMin)
        {
            r = _map->genData.roomRadiusMin;
        }
        if (r > _map->genData.roomRadiusMax)
        {
            r = _map->genData.roomRadiusMax;
        }
        uint32_t x = (rand() % (_map->width - r - r)) + r;
        uint32_t y = (rand() % (_map->height - r - r)) + r;
        if ((x > r) && (x < _map->width-r) && (y > r) && (y < _map->height-r))
        {
            if (_map->genData.roomShape == eRoomShape::shapeRandom)
            {
                roomShape = ((rand() % 100) < 50) ? eRoomShape::shapeCircle : eRoomShape::shapeSquare;
            }
            if (roomShape == eRoomShape::shapeCircle)
            {
                if (m_genCircleRoomOK(_map, x, y, r + _map->genData.roomBorder))
                {
                    m_genCircleRoom(_map, x, y, r);
                }
            }
            if (roomShape == eRoomShape::shapeSquare)
            {
                if (m_genSquareRoomOK(_map, x, y, r + _map->genData.roomBorder))
                {
                    m_genSquareRoom(_map, x, y, r);
                }
            }
        }
    }
}

void cMapManager::m_generateMap_D1(sMap*& _map)
{
    bool seeded = !(_map->genData.seed == 0);
    if (seeded)
    {
        srand (_map->genData.seed);
        m_genD1_internal(_map);
    }
    else
    {
        for (uint16_t i = 0; i < _map->genData.pass; i++)
        {
            _map->genData.seed = time(NULL);
            srand (_map->genData.seed);
            m_genD1_internal(_map);
            if ((m_mapGetFloorArea(_map) > (_map->numTiles / _map->genData.floorAreaMin)) && (_map->roomCount >= _map->genData.roomMin))
            {
                i = _map->genData.pass;
            }
        }
    }

    // Generate a perimeter wall
    m_generatePerimeterWall(_map);

    // Room identification
    m_mapInitRooms(_map);

    // Room connection
    m_mapConnectRooms(_map);

    // Room add prefab
    m_mapPrefabRooms(_map);

    // Populate the map with objects
    m_generateMap_objects(_map);

    // Populate the map with npcs
    m_generateMap_npcs(_map);
}
