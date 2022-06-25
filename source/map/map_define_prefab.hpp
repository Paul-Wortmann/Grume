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

#ifndef MAP_DEFINE_PREFAB_HPP
#define MAP_DEFINE_PREFAB_HPP

#include "map_define_event.hpp"
#include "map_define_portal.hpp"
#include "map_define_tile.hpp"

struct sMapPrefab
{
    // Tile
    std::uint32_t  width               = 0;
    std::uint32_t  height              = 0;
    std::uint32_t  numTiles            = 0;
    sMapTile*      tile                = nullptr;

    // Map events
    std::uint32_t  eventCount          = 0;
    sMapEvent*     event               = nullptr;
    
    // Map portals
    std::uint32_t  portalCount         = 0;
    sMapPortal*    portal              = nullptr;
};

#endif // MAP_DEFINE_PREFAB_HPP
