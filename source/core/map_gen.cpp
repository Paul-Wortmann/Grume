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

#include "map_gen.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

int node_count         = 0;
int map_gen_size_x     = 100;
int map_gen_size_y     = 100;

void map_gen_BSP_split(map_node_type *map_node)
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
        map_node->left->data.tile = new tmx_tile_type[map_node->left->data.number_of_tiles];
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
        map_gen_BSP_split(map_node->left);
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
        map_node->right->data.tile = new tmx_tile_type[map_node->right->data.number_of_tiles];
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
        map_gen_BSP_split(map_node->right);
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
        int passage_y   =  map_node->data.size.y/2;
        int passage_x_1 =  map_node->left->data.size.x/2;
        int passage_x_2 = (map_node->right->data.size.x/2)+map_node->left->data.size.x;
        for (int pos_x = passage_x_1;pos_x < passage_x_2;pos_x++)
        {
            map_node->data.tile[((passage_y*map_node->data.size.x)+pos_x)].tile = FLOOR_TILE;
        }
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
        map_node->left->data.tile = new tmx_tile_type[map_node->left->data.number_of_tiles];
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
        map_gen_BSP_split(map_node->left);
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
        map_node->right->data.tile = new tmx_tile_type[map_node->right->data.number_of_tiles];
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
        map_gen_BSP_split(map_node->right);
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
        int passage_x   =  map_node->data.size.x/2;
        int passage_y_1 =  map_node->left->data.size.y/2;
        int passage_y_2 = (map_node->right->data.size.y/2)+map_node->left->data.size.y;
        for (int pos_y = passage_y_1;pos_y < passage_y_2;pos_y++)
        {
            map_node->data.tile[((pos_y*map_node->data.size.x)+passage_x)].tile = FLOOR_TILE;
        }
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
        room_size_x = 0; //test
        room_size_y = 0; //test
        for (int y_position = (room_size_y+1); y_position < (map_node->data.size.y-1-room_size_y); y_position++)
        {
            for (int x_position = (room_size_x+1); x_position < (map_node->data.size.x-1-room_size_x); x_position++)
            {
                map_node->data.tile[((y_position*map_node->data.size.x)+x_position)].tile = FLOOR_TILE;
            }

        }
        // set room data for passage gen code
        map_node->room.size.x = map_node->data.size.x-2-(room_size_x*2);
        map_node->room.size.y = map_node->data.size.y-2-(room_size_y*2);
        map_node->room.center.x = map_node->data.tile[map_node->room.size.x/2].position.x;
        map_node->room.center.y = map_node->data.tile[map_node->room.size.y/2].position.y;
        // Save to room list for future usage?
    }
};

void map_gen_BSP(tmx_map_type *tmx_map_pointer)
{
    int tile_count_temp                                     = 0;
    int layer_floor                                         = 0;
    int layer_object                                        = 1;
    int layer_wall                                          = 2;
    int tileset_count                                       = 0;
    tmx_map_pointer->data.map_width                         = map_gen_size_x;
    tmx_map_pointer->data.map_height                        = map_gen_size_y;
    tmx_map_pointer->data.map_tile_width                    = 64;
    tmx_map_pointer->data.map_tile_height                   = 32;
    tmx_map_pointer->data.number_of_tiles                   = map_gen_size_x*map_gen_size_y;
    tmx_map_pointer->data.number_of_layers                  = 3;
    tmx_map_pointer->data.number_of_tilesets                = 1;
    tmx_map_pointer->layer                                  = new tmx_layer_type[tmx_map_pointer->data.number_of_layers];
    tmx_map_pointer->layer[layer_floor].name                = "generated_floor";
    tmx_map_pointer->layer[layer_floor].width               = map_gen_size_x;
    tmx_map_pointer->layer[layer_floor].height              = map_gen_size_y;
    tmx_map_pointer->layer[layer_object].name               = "generated_object";
    tmx_map_pointer->layer[layer_object].width              = map_gen_size_x;
    tmx_map_pointer->layer[layer_object].height             = map_gen_size_y;
    tmx_map_pointer->layer[layer_wall].name                 = "generated_wall";
    tmx_map_pointer->layer[layer_wall].width                = map_gen_size_x;
    tmx_map_pointer->layer[layer_wall].height               = map_gen_size_y;
    tmx_map_pointer->tileset                                = new tmx_tileset_type[tmx_map_pointer->data.number_of_tilesets];
    tmx_map_pointer->tileset[tileset_count].first_gid       = 1;
    tmx_map_pointer->tileset[tileset_count].image_source    = "data/tilesets/default_tileset.png";
    tmx_map_pointer->tileset[tileset_count].image_loaded    = false;
    tmx_map_pointer->tileset[tileset_count].image_width     = 256;
    tmx_map_pointer->tileset[tileset_count].image_height    = 32;
    tmx_map_pointer->tileset[tileset_count].tile_width      = 64;
    tmx_map_pointer->tileset[tileset_count].tile_height     = 32;
    tmx_map_pointer->tileset[tileset_count].number_of_tiles = 4;
    tmx_map_pointer->layer[layer_floor].tile   = new tmx_tile_type [tmx_map_pointer->data.number_of_tiles];
    for (int tile_count_x = 0; tile_count_x < tmx_map_pointer->data.map_width; tile_count_x++)
    {
        for (int tile_count_y = 0; tile_count_y < tmx_map_pointer->data.map_height; tile_count_y++)
        {
            tile_count_temp = (tile_count_y * tmx_map_pointer->data.map_width) + tile_count_x;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].position.x   = tile_count_x;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].position.y   = tile_count_y;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].tile         = WALL_TILE;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].tile_tileset = tileset_count;
        }
    }
    tmx_map_pointer->layer[layer_object].tile = new tmx_tile_type [tmx_map_pointer->data.number_of_tiles];
    tmx_map_pointer->layer[layer_wall].tile   = new tmx_tile_type [tmx_map_pointer->data.number_of_tiles];
    for (int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        tmx_map_pointer->layer[layer_object].tile[tile_count].position.x   = 0;
        tmx_map_pointer->layer[layer_object].tile[tile_count].position.y   = 0;
        tmx_map_pointer->layer[layer_object].tile[tile_count].tile         = -1;
        tmx_map_pointer->layer[layer_object].tile[tile_count].tile_tileset = 0;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].position.x     = 0;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].position.y     = 0;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile           = -1;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset   = 0;
    }
    map_node_type temp_map;
    temp_map.data.size.x          = tmx_map_pointer->data.map_width;
    temp_map.data.size.y          = tmx_map_pointer->data.map_height;
    temp_map.data.number_of_tiles = temp_map.data.size.x * temp_map.data.size.y;
    temp_map.data.tile            = new tmx_tile_type[temp_map.data.number_of_tiles];
    temp_map.data.tile            = tmx_map_pointer->layer[layer_floor].tile;
    temp_map.leaf                 = false;
    map_gen_BSP_split(&temp_map);
    tmx_map_pointer->layer[layer_floor].tile = temp_map.data.tile;
    delete [] &temp_map;
};

void map_gen_BSP(tmx_map_type *tmx_map_pointer, int seed)
{
    srand(seed);
    map_gen_BSP(tmx_map_pointer);
};

void map_gen_CA (tmx_map_type *tmx_map_pointer)
{
    int tile_count_temp                                     = 0;
    int layer_floor                                         = 0;
    int layer_object                                        = 1;
    int layer_wall                                          = 2;
    int tileset_count                                       = 0;
    tmx_map_pointer->data.map_width                         = map_gen_size_x;
    tmx_map_pointer->data.map_height                        = map_gen_size_y;
    tmx_map_pointer->data.map_tile_width                    = 64;
    tmx_map_pointer->data.map_tile_height                   = 32;
    tmx_map_pointer->data.number_of_tiles                   = map_gen_size_x*map_gen_size_y;
    tmx_map_pointer->data.number_of_layers                  = 3;
    tmx_map_pointer->data.number_of_tilesets                = 1;
    tmx_map_pointer->layer                                  = new tmx_layer_type[tmx_map_pointer->data.number_of_layers];
    tmx_map_pointer->layer[layer_floor].name                = "generated_floor";
    tmx_map_pointer->layer[layer_floor].width               = map_gen_size_x;
    tmx_map_pointer->layer[layer_floor].height              = map_gen_size_y;
    tmx_map_pointer->layer[layer_object].name               = "generated_object";
    tmx_map_pointer->layer[layer_object].width              = map_gen_size_x;
    tmx_map_pointer->layer[layer_object].height             = map_gen_size_y;
    tmx_map_pointer->layer[layer_wall].name                 = "generated_wall";
    tmx_map_pointer->layer[layer_wall].width                = map_gen_size_x;
    tmx_map_pointer->layer[layer_wall].height               = map_gen_size_y;
    tmx_map_pointer->tileset                                = new tmx_tileset_type[tmx_map_pointer->data.number_of_tilesets];
    tmx_map_pointer->tileset[tileset_count].first_gid       = 1;
    tmx_map_pointer->tileset[tileset_count].image_source    = "data/tilesets/default_tileset.png";
    tmx_map_pointer->tileset[tileset_count].image_loaded    = false;
    tmx_map_pointer->tileset[tileset_count].image_width     = 256;
    tmx_map_pointer->tileset[tileset_count].image_height    = 32;
    tmx_map_pointer->tileset[tileset_count].tile_width      = 64;
    tmx_map_pointer->tileset[tileset_count].tile_height     = 32;
    tmx_map_pointer->tileset[tileset_count].number_of_tiles = 4;
    tmx_map_pointer->layer[layer_floor].tile   = new tmx_tile_type [tmx_map_pointer->data.number_of_tiles];
    for (int tile_count_x = 0; tile_count_x < tmx_map_pointer->data.map_width; tile_count_x++)
    {
        for (int tile_count_y = 0; tile_count_y < tmx_map_pointer->data.map_height; tile_count_y++)
        {
            tile_count_temp = (tile_count_y * tmx_map_pointer->data.map_width) + tile_count_x;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].position.x   = tile_count_x;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].position.y   = tile_count_y;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].tile         = WALL_TILE;
            tmx_map_pointer->layer[layer_floor].tile[tile_count_temp].tile_tileset = tileset_count;
        }
    }
    tmx_map_pointer->layer[layer_object].tile = new tmx_tile_type [tmx_map_pointer->data.number_of_tiles];
    tmx_map_pointer->layer[layer_wall].tile   = new tmx_tile_type [tmx_map_pointer->data.number_of_tiles];
    for (int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        tmx_map_pointer->layer[layer_object].tile[tile_count].position.x   = 0;
        tmx_map_pointer->layer[layer_object].tile[tile_count].position.y   = 0;
        tmx_map_pointer->layer[layer_object].tile[tile_count].tile         = -1;
        tmx_map_pointer->layer[layer_object].tile[tile_count].tile_tileset = 0;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].position.x     = 0;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].position.y     = 0;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile           = -1;
        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset   = 0;
    }
    struct flood_fill_type
    {
        int  tile_data;
        bool processed;
        bool adjoining_tile;
    };
    flood_fill_type fill_data[tmx_map_pointer->data.number_of_tiles];
    bool ca_map_good               = false;
    int  ca_minimum_cave_size      = 60;
    int  ca_wall_stay              = 4;
    int  ca_wall_new               = 5;
    int  ca_iterations             = 4;
    int  ca_random_tile_number     = ((tmx_map_pointer->data.map_width * tmx_map_pointer->data.map_height) * ca_minimum_cave_size) / 100;
    tmx_tile_type temp_map[tmx_map_pointer->data.number_of_tiles];
    //------------------------------------------------------------
    while (!ca_map_good)
    {
        for (int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            tmx_map_pointer->layer[layer_floor].tile[tile_count].tile  = FLOOR_TILE;
        }
        for (int tile_count = 0; tile_count < ca_random_tile_number; tile_count++)
        {
            tmx_map_pointer->layer[layer_floor].tile[rand()%tmx_map_pointer->data.number_of_tiles].tile = WALL_TILE;
        }
        //add a 3x3 floored room to the middle of the map
        //this is for use later when checking for disjointed parts.
        {
            int middle_tile_number = ((tmx_map_pointer->data.number_of_tiles/2)+(tmx_map_pointer->data.map_width/2));
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number].tile                       = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number+1].tile                     = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number-1].tile                     = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number+tmx_map_pointer->data.map_width].tile   = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number+tmx_map_pointer->data.map_width+1].tile = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number+tmx_map_pointer->data.map_width-1].tile = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number-tmx_map_pointer->data.map_width].tile   = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number-tmx_map_pointer->data.map_width+1].tile = FLOOR_TILE;
            tmx_map_pointer->layer[layer_floor].tile[middle_tile_number-tmx_map_pointer->data.map_width-1].tile = FLOOR_TILE;
        }
        //fill perimeter with wall tiles
        for (int tile_count = 0; tile_count < tmx_map_pointer->data.map_width; tile_count++)
        {
            tmx_map_pointer->layer[layer_floor].tile[tile_count].tile                                = WALL_TILE;
            tmx_map_pointer->layer[layer_floor].tile[tmx_map_pointer->data.number_of_tiles-tile_count].tile  = WALL_TILE;
        }
        for (int tile_count = 0; tile_count < tmx_map_pointer->data.map_height; tile_count++)
        {
            tmx_map_pointer->layer[layer_floor].tile[tile_count*tmx_map_pointer->data.map_width].tile                         = WALL_TILE;
            tmx_map_pointer->layer[layer_floor].tile[(tile_count*tmx_map_pointer->data.map_width)+tmx_map_pointer->data.map_width-1].tile = WALL_TILE;
        }
        //smooth map, depending on neighboring tiles.
        for (int refine_count = 0; refine_count < ca_iterations; refine_count++)
        {
            int number_of_neighbors = 0;
            int temp_tile_number    = 0;
            for(int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
            {
                number_of_neighbors = 0;
                temp_tile_number    = 0;
                temp_map[tile_count].tile = FLOOR_TILE; // new tile is initially a floor tile
                temp_tile_number = tile_count+1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                temp_tile_number = tile_count-1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                temp_tile_number = tile_count+tmx_map_pointer->data.map_width;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                temp_tile_number = tile_count+tmx_map_pointer->data.map_width+1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                temp_tile_number = tile_count+tmx_map_pointer->data.map_width-1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                temp_tile_number = tile_count-tmx_map_pointer->data.map_width;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                temp_tile_number = tile_count-tmx_map_pointer->data.map_width+1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                temp_tile_number = tile_count-tmx_map_pointer->data.map_width-1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= tmx_map_pointer->data.number_of_tiles) && (tmx_map_pointer->layer[layer_floor].tile[temp_tile_number].tile == WALL_TILE)) number_of_neighbors++;
                if ((tmx_map_pointer->layer[layer_floor].tile[tile_count].tile  == WALL_TILE)  && (number_of_neighbors >= ca_wall_stay)) temp_map[tile_count].tile = WALL_TILE; //Tile on temp map is a wall
                if ((tmx_map_pointer->layer[layer_floor].tile[tile_count].tile  == FLOOR_TILE) && (number_of_neighbors >= ca_wall_new )) temp_map[tile_count].tile = WALL_TILE; //Tile on temp map is a wall
            }
            //copy tiles from temp map to the main map.
            for(int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
            {
                tmx_map_pointer->layer[layer_floor].tile[tile_count].tile  = temp_map[tile_count].tile;
            }
            //fill perimeter with wall tiles
            for (int tile_count = 0; tile_count < tmx_map_pointer->data.map_width; tile_count++)
            {
                tmx_map_pointer->layer[layer_floor].tile[tile_count].tile                                = WALL_TILE;
                tmx_map_pointer->layer[layer_floor].tile[tmx_map_pointer->data.number_of_tiles-tile_count].tile  = WALL_TILE;
            }
            for (int tile_count = 0; tile_count < tmx_map_pointer->data.map_height; tile_count++)
            {
                tmx_map_pointer->layer[layer_floor].tile[tile_count*tmx_map_pointer->data.map_width].tile                         = WALL_TILE;
                tmx_map_pointer->layer[layer_floor].tile[(tile_count*tmx_map_pointer->data.map_width)+tmx_map_pointer->data.map_width-1].tile = WALL_TILE;
            }
        }
        // find out if cave from the center is the largest part, and discard disjointed parts
        // if main cave is of adequate size, keep and return good, else regenerate.
        for(int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            fill_data[tile_count].tile_data      = tmx_map_pointer->layer[layer_floor].tile[tile_count].tile ;
            fill_data[tile_count].processed      = false;
            fill_data[tile_count].adjoining_tile = false;
        }
        // we already know these are floor tiles, so mark as part of the fill.
        int middle_tile_number = ((tmx_map_pointer->data.number_of_tiles/2)+(tmx_map_pointer->data.map_width/2));
        fill_data[middle_tile_number].processed                            = true;
        fill_data[middle_tile_number+1].processed                          = true;
        fill_data[middle_tile_number-1].processed                          = true;
        fill_data[middle_tile_number+tmx_map_pointer->data.map_width].processed        = true;
        fill_data[middle_tile_number+tmx_map_pointer->data.map_width+1].processed      = true;
        fill_data[middle_tile_number+tmx_map_pointer->data.map_width-1].processed      = true;
        fill_data[middle_tile_number-tmx_map_pointer->data.map_width].processed        = true;
        fill_data[middle_tile_number-tmx_map_pointer->data.map_width+1].processed      = true;
        fill_data[middle_tile_number-tmx_map_pointer->data.map_width-1].processed      = true;
        fill_data[middle_tile_number].adjoining_tile                       = true;
        fill_data[middle_tile_number+1].adjoining_tile                     = true;
        fill_data[middle_tile_number-1].adjoining_tile                     = true;
        fill_data[middle_tile_number+tmx_map_pointer->data.map_width].adjoining_tile   = true;
        fill_data[middle_tile_number+tmx_map_pointer->data.map_width+1].adjoining_tile = true;
        fill_data[middle_tile_number+tmx_map_pointer->data.map_width-1].adjoining_tile = true;
        fill_data[middle_tile_number-tmx_map_pointer->data.map_width].adjoining_tile   = true;
        fill_data[middle_tile_number-tmx_map_pointer->data.map_width+1].adjoining_tile = true;
        fill_data[middle_tile_number-tmx_map_pointer->data.map_width-1].adjoining_tile = true;
        int   number_found         = 0;
        int   temp_tile            = 0;
        bool  is_an_adjoining_tile = false;
        //while((!fill_data[0].processed) && (!fill_data[tmx_map_pointer->data.number_of_tiles-1].processed))
        for(int repeat_count = 0; repeat_count < ((tmx_map_pointer->data.map_width+tmx_map_pointer->data.map_height)/2); repeat_count++)
        {
            for(int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
            {
                // we don't need to check if temp_tile is going passed the borders as the borders are always walls
                is_an_adjoining_tile  = false;
                temp_tile = tile_count+1;
                if((temp_tile >= 0) && (temp_tile <= tmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                temp_tile = tile_count-1;
                if((temp_tile >= 0) && (temp_tile <= tmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                temp_tile = tile_count+tmx_map_pointer->data.map_width;
                if((temp_tile >= 0) && (temp_tile <= tmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                temp_tile = tile_count-tmx_map_pointer->data.map_width;
                if((temp_tile >= 0) && (temp_tile <= tmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                fill_data[tile_count].processed = true;
                if ((is_an_adjoining_tile) and (fill_data[tile_count].tile_data == FLOOR_TILE)) fill_data[tile_count].adjoining_tile = true;
            }
        }
        ca_map_good = (number_found >= ((tmx_map_pointer->data.number_of_tiles*ca_minimum_cave_size)/100.0f)) ? true : false;
    }
    // write new values to array discarding disjointed tiles
    for (int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        if (fill_data[tile_count].adjoining_tile) fill_data[tile_count].tile_data = FLOOR_TILE;
        else fill_data[tile_count].tile_data = WALL_TILE;
    }
    for (int iteration_count = 0; iteration_count < 5; iteration_count++)
    {
        //remove single tiles / tile formations that are not supported
        for (int tile_count = 1; tile_count < (tmx_map_pointer->data.number_of_tiles-tmx_map_pointer->data.map_width-1); tile_count++)
        {
            if(fill_data[tile_count].tile_data == WALL_TILE)
            {
//-------------------- Loose single tiles on a joining wall "T" shape.
                if ((fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data == WALL_TILE)
                    && (fill_data[tile_count+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                    fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                }
                if ((fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                }
                if ((fill_data[tile_count+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                }
                if ((fill_data[tile_count+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                }
//-------------------- Loose single tiles on a joining wall other shape.
                if ((fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data = WALL_TILE;
                    fill_data[tile_count-1].tile_data = WALL_TILE;
                }
                if ((fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data = WALL_TILE;
                    fill_data[tile_count+1].tile_data = WALL_TILE;
                }
//-------------------- Vertical sparse line segment.
                if ((fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data = WALL_TILE;
                    fill_data[tile_count-1].tile_data = WALL_TILE;
                }
                if ((fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data = WALL_TILE;
                    fill_data[tile_count+1].tile_data = WALL_TILE;
                }
//-------------------- Horizontal sparse line segment.
                if ((fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data = WALL_TILE;
                    fill_data[tile_count-1].tile_data = WALL_TILE;
                }
                if ((fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+1].tile_data == FLOOR_TILE))
                {
                    fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data = WALL_TILE;
                    fill_data[tile_count+1].tile_data = WALL_TILE;
                }
//-------------------- Single tile
                if (   (fill_data[tile_count+1].tile_data         == FLOOR_TILE)
                    && (fill_data[tile_count-1].tile_data         == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE))
                        fill_data[tile_count].tile_data = FLOOR_TILE;
                if ((fill_data[tile_count+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data == FLOOR_TILE))
                    fill_data[tile_count].tile_data = FLOOR_TILE;
//-------------------- Diagonally opposite tiles.
                if (   (fill_data[tile_count+1].tile_data         == FLOOR_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE))
                    {
                        fill_data[tile_count+1].tile_data = WALL_TILE;
                        fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE))
                    {
                        fill_data[tile_count-1].tile_data = WALL_TILE;
                        fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE))
                    {
                        fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   = WALL_TILE;
                        fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE))
                    {
                        fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   = WALL_TILE;
                        fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                    }
                //----
                if (   (fill_data[tile_count+1].tile_data         == FLOOR_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE))
                    {
                        fill_data[tile_count+1].tile_data = WALL_TILE;
                        fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE))
                    {
                        fill_data[tile_count-1].tile_data = WALL_TILE;
                        fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE))
                    {
                        fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   = WALL_TILE;
                        fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE))
                    {
                        fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   = WALL_TILE;
                        fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    }
//--------------------------- Corner with diagonal floors
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE))
                    {
                        fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                        fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE))
                    {
                        fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                        fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count-1].tile_data         == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width+1].tile_data == WALL_TILE)
                    && (fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width].tile_data   == WALL_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data == FLOOR_TILE)
                    && (fill_data[tile_count-tmx_map_pointer->data.map_width-1].tile_data == WALL_TILE))
                    {
                        fill_data[tile_count+tmx_map_pointer->data.map_width-1].tile_data = WALL_TILE;
                        fill_data[tile_count-tmx_map_pointer->data.map_width+1].tile_data = WALL_TILE;
                    }
            }
        }
    }
    // Push data from fill struct back to map.
    for(int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        tmx_map_pointer->layer[layer_floor].tile[tile_count].tile  = fill_data[tile_count].tile_data;
    }
};

void map_gen_CA (tmx_map_type *tmx_map_pointer, int seed)
{
    srand(seed);
    map_gen_CA(tmx_map_pointer);
};
