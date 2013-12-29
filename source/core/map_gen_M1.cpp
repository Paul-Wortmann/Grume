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

#include "../game/game.hpp"
#include "map_gen.hpp"
#include "map_gen_M1.hpp"

extern game_class    game;

void           map_gen_M1              (fmx_map_type *fmx_map_pointer, int seed)
{
    srand(seed);
    map_gen_M1(fmx_map_pointer);
};

bool map_gen_maze_tile_OK              (fmx_map_type *fmx_map_pointer, int tile_number)
{
    bool return_value = false;


    return (return_value);
}

void           map_gen_maze            (fmx_map_type *fmx_map_pointer, int tile_x, int tile_y)
{
    int start_tile = (tile_y * fmx_map_pointer->data.map_width) + tile_x;
    // recursive?
    // check tile func
};

void           map_gen_M1              (fmx_map_type *fmx_map_pointer)
{
    room_data_type room_data;
    room_data.position.x = 0;
    room_data.position.y = 0;
    room_data.size.x     = 0;
    room_data.size.y     = 0;
    map_gen_base(fmx_map_pointer);
    map_gen_room(fmx_map_pointer,room_data,1);
    map_gen_room(fmx_map_pointer,room_data,1);
    map_gen_room(fmx_map_pointer,room_data,2);
    map_gen_room(fmx_map_pointer,room_data,2);
    map_gen_maze(fmx_map_pointer,0,0);


    map_gen_check_tiles(fmx_map_pointer);
};
