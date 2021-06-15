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

#ifndef MAP_PATH_DEFINE_HPP
#define MAP_PATH_DEFINE_HPP

#include "../core/includes.hpp"

// ----- used externally -----
struct sMapPath
{
    std::uint32_t  startTile       = 0;
    std::uint32_t  destinationTile = 0;
    std::uint32_t  currentTile     = 0;
    std::uint32_t  currentPosition = 0;

    std::uint32_t  pathLength      = 0;
    std::uint32_t* path            = nullptr;
};

// ----- used internally -----
enum ePathData:uint16_t { pathNone = 0, pathStart = 1, pathEnd = 2, pathOpen = 3, pathClosed = 4 };

// Astar path weights
#define AS_MOV_D  15 // Directional cost
#define AS_MOV_S  10 // Straight cost, horizontal or vertical
#define AS_MOV_H  10 // Heuristic base cost

struct sASTileData
{
    bool          c = false;               // completed flag
    std::uint32_t x = 0;                   // tile x position
    std::uint32_t y = 0;                   // tile y position
    std::uint32_t h = 0;                   // heuristic cost
    std::uint32_t g = 0;                   // movement cost
    std::uint32_t f = 0;                   // total cost
    std::uint32_t p = 0;                   // parent tile
    ePathData     a = ePathData::pathNone; // attribute
    ePathData     l = ePathData::pathNone; // list
};

#endif //MAP_PATH_DEFINE_HPP

