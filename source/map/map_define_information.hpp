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

#ifndef MAP_DEFINE_INFORMATION_HPP
#define MAP_DEFINE_INFORMATION_HPP

#include "../core/includes.hpp"

struct sMapInformation
{
    std::string    fileName      = {};
    std::string    name          = {};
    std::string    biome         = {};

    bool           enableWalls   = true;
    bool           enableFloors  = true;
    bool           enableRooms   = true;
    bool           enableDoors   = true;
    bool           enableTorches = true;
    bool           enableChests  = true;
    bool           enableObjects = true;
    bool           enableNpcs    = true;

    std::string    musicName     = {};
    std::uint32_t  musicNumber   = 0;

    std::uint32_t  size_x        = 0;
    std::uint32_t  size_y        = 0;
    float          terrainHeight = -1.0f;

    std::uint32_t  seed          = 0;
    float          windSpeed     = 1.0f;

    std::uint32_t  currentNumMob = 0; // How many NPC mobs are currently active on the map
};

#endif // MAP_DEFINE_INFORMATION_HPP




