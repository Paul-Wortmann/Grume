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

// Used to add an stairs to the map
void cMapManager::m_addStairsEntity(sMap*& _map)
{
    std::uint32_t mapPrevious = 0; // previous map number
    std::uint32_t mapNext     = 0; // next     map number

    // Get the map numbers for use with stair event generation
    cXML xmlMapFile;
    xmlMapFile.load(FILE_PATH_MAP + _map->fileName);
    if (xmlMapFile.lineCount() > 0)
    {
        // Get data
        mapPrevious = xmlMapFile.getInteger("<map_previous>");
        mapNext     = xmlMapFile.getInteger("<map_next>");

        // Clean up
        xmlMapFile.free();
    }
    
    bool stairsUp    = false; // set if placed
    bool stairsDown  = false; // set if placed
    std::uint32_t ts = 4; // target space
    
    // Try to place the exit from a random position
    // Stairs up
    for (uint32_t y = (rand() % (_map->height - (ts * 2))) + ts; y < _map->height - ts; y++)
    {
        for (uint32_t x = (rand() % (_map->width - (ts * 2))) + ts; x < _map->width - ts; x++)
        {
            uint32_t t = (y * _map->width) + x;
            // W W W W
            // F F F F
            // F F F F
            // F F F F
            if ((stairsUp == false) &&
                (_map->tile[t + 0].base == eTileBase::tileWall) &&
                (_map->tile[t + 1].base == eTileBase::tileWall) &&
                (_map->tile[t + 2].base == eTileBase::tileWall) &&
                (_map->tile[t + 3].base == eTileBase::tileWall) &&
                (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsUp = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 3)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 3)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 1 + (_map->width * 4), 1, mapPrevious, 2, 0);
                m_addMapEvent(_map, t + 2 + (_map->width * 4), 1, mapPrevious, 2, 0);

                // Generate portal
                m_addMapPortal(_map, 1, t + 1 + (_map->width * 5), 0.0000);
            }
            // W F F F
            // W F F F
            // W F F F
            // W F F F
            else if ((stairsUp == false) &&
                     (_map->tile[t + 0].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsUp = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 3 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 3 + (_map->width * 2)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 4 + (_map->width * 1), 1, mapPrevious, 2, 0);
                m_addMapEvent(_map, t + 4 + (_map->width * 2), 1, mapPrevious, 2, 0);

                // Generate portal
                m_addMapPortal(_map, 1, t + 5 + (_map->width * 1), 0.0000);
            }
        }
    }
    
    // Stairs down
    for (uint32_t y = (rand() % (_map->height - (ts * 2))) + ts; y < _map->height - ts; y++)
    {
        for (uint32_t x = (rand() % (_map->width - (ts * 2))) + ts; x < _map->width - ts; x++)
        {
            uint32_t t = (y * _map->width) + x;
            // W W W W
            // F F F F
            // F F F F
            // F F F F
            if ((stairsDown == false) &&
                (_map->tile[t + 0].base == eTileBase::tileWall) &&
                (_map->tile[t + 1].base == eTileBase::tileWall) &&
                (_map->tile[t + 2].base == eTileBase::tileWall) &&
                (_map->tile[t + 3].base == eTileBase::tileWall) &&
                (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsDown = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 3)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 3)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 1 + (_map->width * 4), 1, mapNext, 1, 0);
                m_addMapEvent(_map, t + 2 + (_map->width * 4), 1, mapNext, 1, 0);

                // Generate portal
                m_addMapPortal(_map, 2, t + 1 + (_map->width * 5), 0.0000);
            }
            // W F F F
            // W F F F
            // W F F F
            // W F F F
            else if ((stairsDown == false) &&
                     (_map->tile[t + 0].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsDown = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 3 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 3 + (_map->width * 2)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 4 + (_map->width * 1), 1, mapNext, 1, 0);
                m_addMapEvent(_map, t + 4 + (_map->width * 2), 1, mapNext, 1, 0);

                // Generate portal
                m_addMapPortal(_map, 2, t + 5 + (_map->width * 1), 0.0000);
            }
        }
    }

    // Try to place the exit from the first tile available tile
    // Stairs up
    for (uint32_t y = ts; y < _map->height - ts; y++)
    {
        for (uint32_t x = ts; x < _map->width - ts; x++)
        {
            uint32_t t = (y * _map->width) + x;
            // W W W W
            // F F F F
            // F F F F
            // F F F F
            if ((stairsUp == false) &&
                (_map->tile[t + 0].base == eTileBase::tileWall) &&
                (_map->tile[t + 1].base == eTileBase::tileWall) &&
                (_map->tile[t + 2].base == eTileBase::tileWall) &&
                (_map->tile[t + 3].base == eTileBase::tileWall) &&
                (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsUp = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 3)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 3)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 1 + (_map->width * 4), 1, mapPrevious, 2, 0);
                m_addMapEvent(_map, t + 2 + (_map->width * 4), 1, mapPrevious, 2, 0);

                // Generate portal
                m_addMapPortal(_map, 1, t + 1 + (_map->width * 5), 0.0000);
            }
            // W F F F
            // W F F F
            // W F F F
            // W F F F
            else if ((stairsUp == false) &&
                     (_map->tile[t + 0].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsUp = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 3 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 3 + (_map->width * 2)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 4 + (_map->width * 1), 1, mapPrevious, 2, 0);
                m_addMapEvent(_map, t + 4 + (_map->width * 2), 1, mapPrevious, 2, 0);

                // Generate portal
                m_addMapPortal(_map, 1, t + 5 + (_map->width * 1), 0.0000);
            }
        }
    }
    
    // Stairs down
    for (uint32_t y = ts; y < _map->height - ts; y++)
    {
        for (uint32_t x = ts; x < _map->width - ts; x++)
        {
            uint32_t t = (y * _map->width) + x;
            // W W W W
            // F F F F
            // F F F F
            // F F F F
            if ((stairsDown == false) &&
                (_map->tile[t + 0].base == eTileBase::tileWall) &&
                (_map->tile[t + 1].base == eTileBase::tileWall) &&
                (_map->tile[t + 2].base == eTileBase::tileWall) &&
                (_map->tile[t + 3].base == eTileBase::tileWall) &&
                (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsDown = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 3)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 3)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 1 + (_map->width * 4), 1, mapNext, 1, 0);
                m_addMapEvent(_map, t + 2 + (_map->width * 4), 1, mapNext, 1, 0);

                // Generate portal
                m_addMapPortal(_map, 2, t + 1 + (_map->width * 5), 0.0000);
            }
            // W F F F
            // W F F F
            // W F F F
            // W F F F
            else if ((stairsDown == false) &&
                     (_map->tile[t + 0].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 1)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 1)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 2)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 2)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 0 + (_map->width * 3)].base == eTileBase::tileWall) &&
                     (_map->tile[t + 1 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 2 + (_map->width * 3)].base == eTileBase::tileFloor) &&
                     (_map->tile[t + 3 + (_map->width * 3)].base == eTileBase::tileFloor))
            {
                stairsDown = true;
                _map->room[m_getRoomFromTile(_map,t + _map->width + 1)].type = eMapRoomType::roomTypeStairwell;
                _map->tile[t + 1 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 1)].base = eTileBase::tileNone;
                _map->tile[t + 1 + (_map->width * 2)].base = eTileBase::tileNone;
                _map->tile[t + 2 + (_map->width * 2)].base = eTileBase::tileNone;

                // Generate events
                m_addMapEvent(_map, t + 4 + (_map->width * 1), 1, mapNext, 1, 0);
                m_addMapEvent(_map, t + 4 + (_map->width * 2), 1, mapNext, 1, 0);

                // Generate portal
                m_addMapPortal(_map, 2, t + 5 + (_map->width * 1), 0.0000);
            }
        }
    }
    
    
//    eRoomType::roomTypeStairwell
//        <map_previous>1</map_previous>
//        <map_next>3</map_next>

}

