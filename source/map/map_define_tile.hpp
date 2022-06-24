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

#ifndef MAP_DEFINE_TILE_HPP
#define MAP_DEFINE_TILE_HPP

enum class eTileBase : std::uint16_t 
{ 
    tileNone                           = 0,
    tileFloor                          = 1,
    tileWall                           = 2,
    tileDoorway                        = 3,
    tileWallShort                      = 4,
    tileFloorPath                      = 5,
    tileFloorNoGo                      = 6,
    tilePathNoGo                       = 7,
    tileLiquid                         = 8,
    tileIgnore                         = 9  // Used for prefab loading
};

struct sMapTile
{
    std::uint32_t processed            = 0; // Default == 0
    eTileBase     base                 = eTileBase::tileNone; // Default == eTileBase::tileNone
    std::uint32_t object               = 0; // Default == 0
    std::uint32_t npc                  = 0; // Default == 0, else the UID of an npc
    std::uint32_t room                 = 0; // Default == 0
};

#endif // MAP_DEFINE_TILE_HPP
