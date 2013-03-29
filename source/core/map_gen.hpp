/**
 * Copyright (C) 2013 Paul Wortmann, paul.wormann@gmail.com.
 * This file is part of "CS50 - project -> RDG(Random Dungeon Generator)"
 *
 * "CS50 - project -> RDG(Random Dungeon Generator)" is free software: you
 * can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * "CS50 - project -> RDG(Random Dungeon Generator)" is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "CS50 - project -> RDG(Random Dungeon Generator)" If not,
 * see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   paul.wortmann@gmail.com
 * @license GPL V3
 * @date 2013-03-11
 */

#ifndef MAP_GEN_HPP
#define MAP_GEN_HPP

// ROOM_MAX must be an even number!
#define MAX_ROOMS  0 // 0 for unlimited number possible
#define ROOM_MIN_X 8
#define ROOM_MIN_Y 8

struct i2_type
{
    int x;
    int y;
};

struct tile_type
{
    i2_type    position;
    int        layer;
};

struct room_type
{
    i2_type    size;
    i2_type    center;
};

struct map_type
{
    int        number_of_tiles;
    i2_type    size;
    tile_type *tile;
};

struct map_node_type
{
    bool           leaf;
    room_type      room;
    map_type       data;
    map_node_type *left;
    map_node_type *right;
};


void map_gen_init(int size_x, int size_y);
void map_gen_split(map_node_type *map_node);
void map_gen(map_type *map_pointer);
void map_gen_display(void);
void map_gen_save_file();

#endif //MAP_GEN_HPP

