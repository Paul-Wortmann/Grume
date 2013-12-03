/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#ifndef MAP_GEN_HPP
#define MAP_GEN_HPP

#include <string>
#include "loader_tmx.hpp"
#include "types.hpp"

// ROOM_MAX should be an even number!
#define MAX_ROOMS  0 // 0 for unlimited number possible

#define TILE_NONE  -1
#define TILE_FLOOR  1
#define TILE_WALL   2
#define TILE_PATH   3

#define ROOM_PATH  2
#define ROOM_MIN_X 7
#define ROOM_MIN_Y 7
#define ROOM_MAX_X 9
#define ROOM_MAX_Y 9
#define ROOM_MAX_R (int)(sqrt(((ROOM_MAX_X/2) * (ROOM_MAX_X/2)) + ((ROOM_MAX_Y/2) * (ROOM_MAX_Y/2))) + ROOM_PATH)

struct room_type
{
    i2_type    size;
    i2_type    center;
};

struct map_type
{
    int            number_of_tiles;
    i2_type        size;
    tmx_tile_type *tile;
};

struct map_node_type
{
    bool           leaf;
    room_type      room;
    map_type       data;
    map_node_type *left;
    map_node_type *right;
};

void map_gen_base(tmx_map_type *tmx_map_pointer);
void map_gen_BSP_split(map_node_type *map_node);
void map_gen_BSP (tmx_map_type *tmx_map_pointer);
void map_gen_BSP (tmx_map_type *tmx_map_pointer, int seed);
void map_gen_CA  (tmx_map_type *tmx_map_pointer);
void map_gen_CA  (tmx_map_type *tmx_map_pointer, int seed);
void map_gen_GG  (tmx_map_type *tmx_map_pointer);
void map_gen_GG  (tmx_map_type *tmx_map_pointer, int seed);

#endif //MAP_GEN_HPP

