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

#ifndef BIOME_DEFINE_HPP
#define BIOME_DEFINE_HPP

#include "../core/includes.hpp"

struct sMapFloorSpritesheet
{
    std::string name     = {};
    std::string fileName = {};
};

// Map music
struct sMapMusic
{
    std::string   name   = {}; // Tag
    std::uint32_t number = 0;  // Track, Default == 0 (random)
};

struct sMapWallSet
{
    std::string name     = {};
    std::string fileName = {};
};

struct sMapBiome
{
    // Linked list management
    sMapBiome*    next       = nullptr;
    std::uint32_t UID        = 0;

    // General information
    std::string   name       = {};
    std::string   fileName   = {};

    // Data
    sMapMusic     mapMusic   = {};
    sMapWallSet   wallSet    = {};

    // Map floor spritesheet
    sMapFloorSpritesheet floorSpritesheet = {};
};

#endif //BIOME_DEFINE_HPP
