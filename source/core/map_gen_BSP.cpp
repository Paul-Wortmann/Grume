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
#include "map_gen_BSP.hpp"
#include "map_gen.hpp"
#include "misc.hpp"
#include "pathfinding.hpp"
#include "physics.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

extern game_class    game;

int node_count         = 0;

void map_gen_BSP_split(fmx_map_type *fmx_map_pointer, map_node_type *map_node)
{
    int  x_range = map_node->data.size.x  - (ROOM_MAX_X*2);
    int  y_range = map_node->data.size.y  - (ROOM_MAX_Y*2);
    bool split_x = (x_range > 0) ? true : false;
    bool split_y = (y_range > 0) ? true : false;
    if (split_x && split_y)
    {
        if (x_range > y_range)
        {
            split_x = true;
            split_y = false;
        }
        if (y_range > x_range)
        {
            split_x = false;
            split_y = true;
        }
        if (x_range == y_range)
        {
            if (rand()%100 > 50) split_x = false;
            else split_y = false;
        }
    }
    if ((MAX_ROOMS > 0) && (node_count >= MAX_ROOMS))
    {
        split_x = false;
        split_y = false;
    }
    if (split_x) // split vertically
    {
        int tile_count_x_out = 0;
        int tile_count_y_out = 0;
        int tile_data_count  = 0;
        x_range = (x_range > 0) ? rand()%x_range : 0;
        int new_size_x_1 = ROOM_MAX_X + x_range + (map_node->data.size.x % 2);
        int new_size_x_2 = map_node->data.size.x - new_size_x_1;
        // left --------------------------------------------------------------------------------------------------------
        map_node->left = new map_node_type;
        map_node->left->leaf = false;
        map_node->left->data.size.x = new_size_x_1;
        map_node->left->data.size.y = map_node->data.size.y;
        map_node->left->data.number_of_tiles = map_node->left->data.size.x * map_node->left->data.size.y;
        map_node->left->data.tile = new fmx_tile_type[map_node->left->data.number_of_tiles];
        tile_count_x_out = 0;
        tile_count_y_out = 0;
        tile_data_count  = 0;
        node_count++;
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            tile_data_count = (tile_count_y_out*map_node->data.size.x)+tile_count_x_out;
            map_node->left->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->left->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->left->data.tile[tile_count].tile       = map_node->data.tile[tile_data_count].tile;
            tile_count_x_out++;
            if (tile_count_x_out >= new_size_x_1)
            {
                tile_count_x_out = 0;
                tile_count_y_out++;
            }
        }
        map_gen_BSP_split(fmx_map_pointer,map_node->left);
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            for(tile_data_count = 0; tile_data_count < map_node->data.number_of_tiles; tile_data_count++)
            {
                if ((map_node->data.tile[tile_data_count].position.x == map_node->left->data.tile[tile_count].position.x) &&
                    (map_node->data.tile[tile_data_count].position.y == map_node->left->data.tile[tile_count].position.y))
                     map_node->data.tile[tile_data_count].tile       = map_node->left->data.tile[tile_count].tile;
            }
        }
        // right --------------------------------------------------------------------------------------------------------
        map_node->right = new map_node_type;
        map_node->right->leaf = false;
        map_node->right->data.size.x = new_size_x_2;
        map_node->right->data.size.y = map_node->data.size.y;
        map_node->right->data.number_of_tiles = map_node->right->data.size.x * map_node->right->data.size.y;
        map_node->right->data.tile = new fmx_tile_type[map_node->right->data.number_of_tiles];
        tile_count_x_out = new_size_x_1;
        tile_count_y_out = 0;
        tile_data_count  = 0;
        node_count++;
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            tile_data_count = (tile_count_y_out*map_node->data.size.x)+tile_count_x_out;
            map_node->right->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->right->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->right->data.tile[tile_count].tile       = map_node->data.tile[tile_data_count].tile;
            tile_count_x_out++;
            if (tile_count_x_out >= map_node->data.size.x)
            {
                tile_count_x_out = new_size_x_1;
                tile_count_y_out++;
            }
        }
        map_gen_BSP_split(fmx_map_pointer,map_node->right);
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            for(tile_data_count = 0; tile_data_count < map_node->data.number_of_tiles; tile_data_count++)
            {
                if ((map_node->data.tile[tile_data_count].position.x == map_node->right->data.tile[tile_count].position.x) &&
                    (map_node->data.tile[tile_data_count].position.y == map_node->right->data.tile[tile_count].position.y))
                     map_node->data.tile[tile_data_count].tile       = map_node->right->data.tile[tile_count].tile;
            }
        }
        //generate horizontal passages
        /*
        int passage_y   =  map_node->data.size.y/2;
        int passage_x_1 =  map_node->left->data.size.x/2;
        int passage_x_2 = (map_node->right->data.size.x/2)+map_node->left->data.size.x;
        for (int pos_x = passage_x_1;pos_x < passage_x_2;pos_x++)
        {
            map_node->data.tile[((passage_y*map_node->data.size.x)+pos_x)].tile = TILE_FLOOR;
        }
        */
        delete [] map_node->left;
        delete [] map_node->right;
    }
    if (split_y) // split horizontally
    {
        int tile_count_x_out = 0;
        int tile_count_y_out = 0;
        int tile_data_count  = 0;
        y_range = (y_range > 0) ? rand()%y_range : 0;
        int new_size_y_1 = ROOM_MAX_Y + y_range + (map_node->data.size.y % 2);
        int new_size_y_2 = map_node->data.size.y - new_size_y_1;
        // left --------------------------------------------------------------------------------------------------------
        map_node->left = new map_node_type;
        map_node->left->leaf = false;
        map_node->left->data.size.x = map_node->data.size.x;
        map_node->left->data.size.y = new_size_y_1;
        map_node->left->data.number_of_tiles = map_node->left->data.size.x * map_node->left->data.size.y;
        map_node->left->data.tile = new fmx_tile_type[map_node->left->data.number_of_tiles];
        tile_count_x_out = 0;
        tile_count_y_out = 0;
        tile_data_count  = 0;
        node_count++;
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            tile_data_count = (tile_count_y_out*map_node->data.size.x)+tile_count_x_out;
            map_node->left->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->left->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->left->data.tile[tile_count].tile       = map_node->data.tile[tile_data_count].tile;
            tile_count_x_out++;
            if (tile_count_x_out >= map_node->left->data.size.x)
            {
                tile_count_x_out = 0;
                tile_count_y_out++;
            }
        }
        map_gen_BSP_split(fmx_map_pointer,map_node->left);
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            for(tile_data_count = 0; tile_data_count < map_node->data.number_of_tiles; tile_data_count++)
            {
                if ((map_node->data.tile[tile_data_count].position.x == map_node->left->data.tile[tile_count].position.x) &&
                    (map_node->data.tile[tile_data_count].position.y == map_node->left->data.tile[tile_count].position.y))
                     map_node->data.tile[tile_data_count].tile       = map_node->left->data.tile[tile_count].tile;
            }
        }
        // right --------------------------------------------------------------------------------------------------------
        map_node->right = new map_node_type;
        map_node->right->leaf = false;
        map_node->right->data.size.x = map_node->data.size.x;
        map_node->right->data.size.y = new_size_y_2;
        map_node->right->data.number_of_tiles = map_node->right->data.size.x * map_node->right->data.size.y;
        map_node->right->data.tile = new fmx_tile_type[map_node->right->data.number_of_tiles];
        tile_count_x_out = 0;
        tile_count_y_out = new_size_y_1;
        tile_data_count  = 0;
        node_count++;
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            tile_data_count = (tile_count_y_out*map_node->data.size.x)+tile_count_x_out;
            map_node->right->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->right->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->right->data.tile[tile_count].tile       = map_node->data.tile[tile_data_count].tile;
            tile_count_x_out++;
            if (tile_count_x_out >= map_node->right->data.size.x)
            {
                tile_count_x_out = 0;
                tile_count_y_out++;
            }
        }
        map_gen_BSP_split(fmx_map_pointer,map_node->right);
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            for(tile_data_count = 0; tile_data_count < map_node->data.number_of_tiles; tile_data_count++)
            {
                if ((map_node->data.tile[tile_data_count].position.x == map_node->right->data.tile[tile_count].position.x) &&
                    (map_node->data.tile[tile_data_count].position.y == map_node->right->data.tile[tile_count].position.y))
                     map_node->data.tile[tile_data_count].tile       = map_node->right->data.tile[tile_count].tile;
            }
        }
        //generate vertical passages
        /*
        int passage_x   =  map_node->data.size.x/2;
        int passage_y_1 =  map_node->left->data.size.y/2;
        int passage_y_2 = (map_node->right->data.size.y/2)+map_node->left->data.size.y;
        for (int pos_y = passage_y_1;pos_y < passage_y_2;pos_y++)
        {
            map_node->data.tile[((pos_y*map_node->data.size.x)+passage_x)].tile = TILE_FLOOR;
        }
        */
        delete [] map_node->left;
        delete [] map_node->right;
    }
    if (!split_x && !split_y)
    {
        map_node->leaf = true;
        // gen_room code goes here
        int room_size_x = 0;
        int room_size_y = 0;
        if (map_node->data.size.x > ROOM_MAX_X)
        {
            room_size_x = ((map_node->data.size.x - ROOM_MAX_X)/2);
            room_size_x = (room_size_x > 0) ? rand()%room_size_x : 0;
        }
        if (map_node->data.size.y > ROOM_MAX_Y)
        {
            room_size_y = ((map_node->data.size.y - ROOM_MAX_Y)/2);
            room_size_y = (room_size_y > 0) ? rand()%room_size_y : 0;
        }
        //room_size_x = 0; //test
        //room_size_y = 0; //test
        for (int y_position = (room_size_y+1); y_position < (map_node->data.size.y-1-room_size_y); y_position++)
        {
            for (int x_position = (room_size_x+1); x_position < (map_node->data.size.x-1-room_size_x); x_position++)
            {
                map_node->data.tile[((y_position*map_node->data.size.x)+x_position)].tile = TILE_FLOOR;
            }

        }
        // set room data for passage gen code
        map_node->room.size.x     = map_node->data.size.x-2-(room_size_x*2);
        map_node->room.size.y     = map_node->data.size.y-2-(room_size_y*2);
        map_node->room.position.x = map_node->data.tile[map_node->room.size.x/2].position.x;
        map_node->room.position.y = map_node->data.tile[map_node->room.size.y/2].position.y;
        // Save to room list for future usage?
        /*
        int room_num = map_gen_room_add(fmx_map_pointer);
        fmx_map_pointer->room[room_num].active                    = true;
        fmx_map_pointer->room[room_num].size.x                    = map_node->room.size.x;
        fmx_map_pointer->room[room_num].size.y                    = map_node->room.size.y;
        fmx_map_pointer->room[room_num].position.x                = map_node->room.position.x;
        fmx_map_pointer->room[room_num].position.y                = map_node->room.position.y;
        fmx_map_pointer->room[room_num].number_of_connected_rooms = 0;
        */
    }
};

void map_gen_BSP_internal(fmx_map_type *fmx_map_pointer)
{
    map_gen_base(fmx_map_pointer);
    map_node_type* temp_map        = new map_node_type;
    temp_map->data.size.x          = fmx_map_pointer->data.map_width;
    temp_map->data.size.y          = fmx_map_pointer->data.map_height;
    temp_map->data.number_of_tiles = temp_map->data.size.x * temp_map->data.size.y;
    temp_map->data.tile            = new fmx_tile_type[temp_map->data.number_of_tiles];
    temp_map->data.tile            = fmx_map_pointer->layer[LAYER_FLOOR].tile;
    temp_map->leaf                 = false;
    map_gen_BSP_split(fmx_map_pointer,temp_map);
    fmx_map_pointer->layer[LAYER_FLOOR].tile = temp_map->data.tile;
    delete temp_map;
    map_gen_room_find(fmx_map_pointer);
    map_gen_room_connect(fmx_map_pointer);
};

void map_gen_BSP (fmx_map_type *fmx_map_pointer)
{
    map_gen_BSP_internal(fmx_map_pointer);
    while (!map_gen_room_flood_fill(fmx_map_pointer)) map_gen_BSP_internal(fmx_map_pointer);
    map_gen_check_tiles(fmx_map_pointer);
    map_gen_room_add_exits(fmx_map_pointer);
};

void map_gen_BSP(fmx_map_type *fmx_map_pointer, int seed)
{
    srand(seed);
    map_gen_BSP(fmx_map_pointer);
};
