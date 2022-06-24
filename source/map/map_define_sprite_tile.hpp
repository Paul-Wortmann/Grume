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

#ifndef MAP_DEFINE_SPRITE_TILE_HPP
#define MAP_DEFINE_SPRITE_TILE_HPP

// These are the dimentions, in sprites, used for the floor texture.
#define FLOOR_SPRITESHEET_WIDTH  4
#define FLOOR_SPRITESHEET_HEIGHT 4
    
enum class eSpriteType : std::uint16_t 
{ 
    tileNone                           = 0, // None
    tileFloor                          = 1, // Floor tile
    tilePath                           = 2, // Path  tile
    tilePathLine                       = 3, // Path  tile -> Line
    tilePathOuter                      = 4, // Path  tile -> Corner, Outer
    tilePathInner                      = 5, // Path  tile -> Corner, Inner
};

struct sMapSpriteTile
{
    eSpriteType   type                 = eSpriteType::tileFloor; // Default == eSpriteType::tileFloor
    std::uint32_t processed            = 0; // Default == 0
    std::uint32_t spriteNumX           = 0; // Default == 0
    std::uint32_t spriteNumY           = 0; // Default == 0
    std::uint32_t rotation             = 0; // Default == 0 (0 -> 0 degrees, 1 -> 90 degrees, 2 -> 180 degrees, 3 -> 270 degrees)
};

#endif // MAP_DEFINE_SPRITE_TILE_HPP
