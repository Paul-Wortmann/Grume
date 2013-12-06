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
#include "loader_fmx.hpp"
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

struct room_data_type
{
    i2_type    size;
    i2_type    position;
};

struct map_type
{
    int            number_of_tiles;
    i2_type        size;
    fmx_tile_type *tile;
};

struct map_node_type
{
    bool           leaf;
    room_data_type room;
    map_type       data;
    map_node_type *left;
    map_node_type *right;
};

void map_gen_base            (fmx_map_type *fmx_map_pointer);
void map_gen_BSP_split       (fmx_map_type *fmx_map_pointer, map_node_type *map_node);
void map_gen_BSP             (fmx_map_type *fmx_map_pointer);
void map_gen_BSP             (fmx_map_type *fmx_map_pointer, int seed);
void map_gen_CA              (fmx_map_type *fmx_map_pointer);
void map_gen_CA              (fmx_map_type *fmx_map_pointer, int seed);
void map_gen_GG              (fmx_map_type *fmx_map_pointer);
void map_gen_GG              (fmx_map_type *fmx_map_pointer, int seed);
int  map_gen_room_check_path (fmx_map_type *fmx_map_pointer, int room_1, int room_2, bool x_then_y);
void map_gen_room_connect    (fmx_map_type *fmx_map_pointer, int room_1, int room_2);
void map_gen_room_connections(fmx_map_type *fmx_map_pointer);
int  map_gen_room_add        (fmx_map_type *fmx_map_pointer);

#endif //MAP_GEN_HPP

