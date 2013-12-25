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
#include "map_gen_RC.hpp"
#include "misc.hpp"

extern game_class    game;

void map_gen_RC_internal (fmx_map_type *fmx_map_pointer)
{
    int number_of_circles = (fmx_map_pointer->data.map_width / ROOM_MAX_X) * (fmx_map_pointer->data.map_height / ROOM_MAX_Y);
    struct room_node_type
    {
        bool    active;
        i2_type position;
        i2_type dimension;
    };
    room_node_type room_node[number_of_circles+1];
    room_node[0].position.x = (fmx_map_pointer->data.map_width  / 2);
    room_node[0].position.y = (fmx_map_pointer->data.map_height / 2);
    for (int node_count = 1; node_count < number_of_circles; node_count++)
    {
        room_node[node_count].active     = true;
        room_node[node_count].position.x = random_int(ROOM_MAX_R,(fmx_map_pointer->data.map_width  - ROOM_MAX_R));
        room_node[node_count].position.y = random_int(ROOM_MAX_R,(fmx_map_pointer->data.map_height - ROOM_MAX_R));
    }
    for (int node_count_1 = 0; node_count_1 < number_of_circles; node_count_1++)
    {
        if (room_node[node_count_1].active)
        {
            for (int node_count_2 = 0; node_count_2 < number_of_circles; node_count_2++)
            {
                if ((room_node[node_count_2].active) && (node_count_1 != node_count_2))
                {
                    if (game.core.physics.circle_collision(room_node[node_count_1].position.x,room_node[node_count_1].position.y,ROOM_MAX_R,room_node[node_count_2].position.x,room_node[node_count_2].position.y,ROOM_MAX_R))
                    {
                        room_node[node_count_2].active = false;
                    }
                }
            }
        }
    }
    // gen rooms in the circles
    for (int node_count_1 = 0; node_count_1 < number_of_circles; node_count_1++)
    {
        if (room_node[node_count_1].active)
        {
            fmx_map_pointer->data.number_of_rooms++;
            room_node[node_count_1].dimension.x = random_int(ROOM_MIN_X,ROOM_MAX_X);
            room_node[node_count_1].dimension.y = random_int(ROOM_MIN_Y,ROOM_MAX_Y);
            int room_start_x = room_node[node_count_1].position.x - (room_node[node_count_1].dimension.x/2);
            int room_start_y = room_node[node_count_1].position.y - (room_node[node_count_1].dimension.y/2);
            for (int count_y = 0; count_y < room_node[node_count_1].dimension.y; count_y++)
            {
                for (int count_x = 0; count_x < room_node[node_count_1].dimension.x; count_x++)
                {
                    int tile_count_temp = (count_x + room_start_x) + (fmx_map_pointer->data.map_width * (count_y + room_start_y));
                    fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count_temp].tile = TILE_FLOOR;
                }
            }
        }
    }
    fmx_map_pointer->room = new fmx_room_data_type[fmx_map_pointer->data.number_of_rooms+1];
    int room_count = 0;
    for (int node_count_1 = 0; node_count_1 < number_of_circles; node_count_1++)
    {
        if (room_node[node_count_1].active)
        {
            fmx_map_pointer->room[room_count].active                    = true;
            fmx_map_pointer->room[room_count].size.x                    = room_node[node_count_1].dimension.x;
            fmx_map_pointer->room[room_count].size.y                    = room_node[node_count_1].dimension.y;
            fmx_map_pointer->room[room_count].position.x                = room_node[node_count_1].position.x;
            fmx_map_pointer->room[room_count].position.y                = room_node[node_count_1].position.y;
            fmx_map_pointer->room[room_count].number_of_connected_rooms = 0;
            room_count++;
        }
    }
    map_gen_room_connect(fmx_map_pointer);
};

void map_gen_RC (fmx_map_type *fmx_map_pointer, int seed)
{
    srand(seed);
    map_gen_RC(fmx_map_pointer);
};

void map_gen_RC (fmx_map_type *fmx_map_pointer)
{
    map_gen_base(fmx_map_pointer);
    map_gen_RC_internal(fmx_map_pointer);
    while (!map_gen_room_flood_fill(fmx_map_pointer)) map_gen_RC_internal(fmx_map_pointer);
    map_gen_check_tiles(fmx_map_pointer);
    map_gen_room_add_exits(fmx_map_pointer);
};
