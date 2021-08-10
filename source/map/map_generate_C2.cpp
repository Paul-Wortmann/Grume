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

void cMapManager::m_generateMap_C2(sMap*& _map)
{
    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);




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
