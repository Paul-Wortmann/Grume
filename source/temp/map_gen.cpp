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

#include "map_gen.hpp"
#include <stdio.h>
#include <stdlib.h>

map_type rdg_map;

void map_gen_init(int size_x, int size_y)
{
    int tile_count = 0;
    rdg_map.size.x = size_x;
    rdg_map.size.y = size_y;
    rdg_map.number_of_tiles = size_x*size_y;
    rdg_map.tile = new tile_type[(rdg_map.size.x*rdg_map.size.y)+1];
    for (int tile_count_y = 0; tile_count_y < rdg_map.size.y; tile_count_y++)
    {
        for (int tile_count_x = 0; tile_count_x < rdg_map.size.x; tile_count_x++)
        {
            tile_count = (tile_count_y * rdg_map.size.x) + tile_count_x;
            rdg_map.tile[tile_count].position.x = tile_count_x;
            rdg_map.tile[tile_count].position.y = tile_count_y;
            rdg_map.tile[tile_count].layer = 0;
        }
    }
};

void map_gen_split(map_node_type *map_node)
{
    int  x_range = map_node->data.size.x  - (ROOM_MAX_X*2);
    int  y_range = map_node->data.size.y  - (ROOM_MAX_Y*2);
    bool split_x = (x_range > 0) ? true : false;
    bool split_y = (y_range > 0) ? true : false;
    if (split_x && split_y)
    {
        if (rand()%100 > 50) split_x = false;
        else split_y = false;
    }
    if (split_y) // split horizontally
    {
        y_range = (y_range > 0) ? rand()%y_range : 0;
        int new_size_y_1 = ROOM_MAX_Y + y_range + (map_node->data.size.y % 2);
        int new_size_y_2 = map_node->data.size.y - new_size_y_1;
        // left --------------------------------------------------------------------------------------------------------
        map_node->left = new map_node_type;
        map_node->left->leaf = false;
        map_node->left->data.size.x = map_node->data.size.x;
        map_node->left->data.size.y = new_size_y_1;
        map_node->left->data.number_of_tiles = map_node->left->data.size.x * map_node->left->data.size.y;
        map_node->left->data.tile = new tile_type[(map_node->left->data.size.x*map_node->left->data.size.y)+1];
        printf("Creating node...\n");
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->left->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->left->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->left->data.tile[tile_count].layer = 1;//test
        }
        /*
        for (int tile_count_y = 0; tile_count_y < map_node->left->data.size.y; tile_count_y++)
        {
            for (int tile_count_x = 0; tile_count_x < map_node->left->data.size.x; tile_count_x++)
            {
                tile_count = (tile_count_y * map_node->left->data.size.x) + tile_count_x;
                map_node->left->data.tile[tile_count].position.x = map_node->data.tile[tile_count].position.x;
                map_node->left->data.tile[tile_count].position.y = map_node->data.tile[tile_count].position.y;
                map_node->left->data.tile[tile_count].layer = 0;//test
//printf("in loop - 1 - tile count %d\n",tile_count);
            }
        }
        */
        map_gen_split(map_node->left);
        printf("Pushing node data back to parent...\n");
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->data.tile[tile_data_count].position.x = map_node->left->data.tile[tile_count].position.x;
            map_node->data.tile[tile_data_count].position.y = map_node->left->data.tile[tile_count].position.y;
            map_node->data.tile[tile_data_count].layer      = map_node->left->data.tile[tile_count].layer;
        }
        /*
        for (int tile_count_y = 0; tile_count_y < map_node->left->data.size.y; tile_count_y++)
        {
            for (int tile_count_x = 0; tile_count_x < map_node->left->data.size.x; tile_count_x++)
            {
                tile_count = (tile_count_y * map_node->left->data.size.x) + tile_count_x;
                map_node->left->data.tile[tile_count].position.x = map_node->data.tile[tile_count].position.x;
                map_node->left->data.tile[tile_count].position.y = map_node->data.tile[tile_count].position.y;
                map_node->left->data.tile[tile_count].layer = 0;//test
//printf("in loop - 1 - tile count %d\n",tile_count);
            }
        }
        */
        delete [] map_node->left;
        // right --------------------------------------------------------------------------------------------------------
        map_node->right = new map_node_type;
        map_node->right->leaf = false;
        map_node->right->data.size.x = map_node->data.size.x;
        map_node->right->data.size.y = new_size_y_2;
        map_node->right->data.number_of_tiles = map_node->right->data.size.x * map_node->right->data.size.y;
        map_node->right->data.tile = new tile_type[(map_node->right->data.size.x*map_node->right->data.size.y)+1];
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->right->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->right->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->right->data.tile[tile_count].layer = 2;//test
        }
        /*
        for (int tile_count_y = map_node->right->data.size.y ; tile_count_y < map_node->data.size.y; tile_count_y++)
        {
            for (int tile_count_x = 0; tile_count_x < map_node->right->data.size.x; tile_count_x++)
            {
                tile_count = (tile_count_y * map_node->right->data.size.x) + tile_count_x;
                map_node->right->data.tile[tile_count].position.x = map_node->data.tile[tile_count].position.x;
                map_node->right->data.tile[tile_count].position.y = map_node->data.tile[tile_count].position.y;
                map_node->right->data.tile[tile_count].layer = 0;//test
printf("in loop - 2 - tile count %d\n",tile_count);
            }
        }
        */
        map_gen_split(map_node->right);
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->data.tile[tile_data_count].position.x = map_node->right->data.tile[tile_count].position.x;
            map_node->data.tile[tile_data_count].position.y = map_node->right->data.tile[tile_count].position.y;
            //map_node->data.tile[tile_data_count].layer      = map_node->right->data.tile[tile_count].layer;
        }
        delete [] map_node->right;
    }
    if (split_x) // split vertically
    {
//printf("Splitting node - size_x -> %d - size_y -> %d\n",map_node->data.size.x,map_node->data.size.y);
        x_range = (x_range > 0) ? rand()%x_range : 0;
        int new_size_x_1 = ROOM_MAX_X + x_range + (map_node->data.size.x % 2);
        int new_size_x_2 = map_node->data.size.x - new_size_x_1;
        // left --------------------------------------------------------------------------------------------------------
        map_node->left = new map_node_type;
        map_node->left->leaf = false;
        map_node->left->data.size.x = new_size_x_1;
        map_node->left->data.size.y = map_node->data.size.y;
        map_node->left->data.number_of_tiles = map_node->left->data.size.x * map_node->left->data.size.y;
        map_node->left->data.tile = new tile_type[(map_node->left->data.size.x*map_node->left->data.size.y)+1];
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->left->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->left->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->left->data.tile[tile_count].layer = 3;//test
        }
        /*
        for (int tile_count_y = 0; tile_count_y < map_node->left->data.size.y; tile_count_y++)
        {
            for (int tile_count_x = 0; tile_count_x < map_node->left->data.size.x; tile_count_x++)
            {
                tile_count = (tile_count_y * map_node->left->data.size.x) + tile_count_x;
                map_node->left->data.tile[tile_count].position.x = map_node->data.tile[tile_count].position.x;
                map_node->left->data.tile[tile_count].position.y = map_node->data.tile[tile_count].position.y;
                map_node->left->data.tile[tile_count].layer = 0;//test
//printf("in loop - 3 - tile count %d\n",tile_count);
            }
        }
        */
        map_gen_split(map_node->left);
        for(int tile_count = 0; tile_count < map_node->left->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->data.tile[tile_data_count].position.x = map_node->left->data.tile[tile_count].position.x;
            map_node->data.tile[tile_data_count].position.y = map_node->left->data.tile[tile_count].position.y;
            //map_node->data.tile[tile_data_count].layer      = map_node->left->data.tile[tile_count].layer;
        }
        delete [] map_node->left;
        // right --------------------------------------------------------------------------------------------------------
        map_node->right = new map_node_type;
        map_node->right->leaf = false;
        map_node->right->data.size.x = new_size_x_2;
        map_node->right->data.size.y = map_node->data.size.y;
        map_node->right->data.number_of_tiles = map_node->right->data.size.x * map_node->right->data.size.y;
        map_node->right->data.tile = new tile_type[(map_node->right->data.size.x*map_node->right->data.size.y)+1];
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->right->data.tile[tile_count].position.x = map_node->data.tile[tile_data_count].position.x;
            map_node->right->data.tile[tile_count].position.y = map_node->data.tile[tile_data_count].position.y;
            map_node->right->data.tile[tile_count].layer = 4;//test
        }
        /*
        for (int tile_count_y = 0; tile_count_y < map_node->right->data.size.y; tile_count_y++)
        {
            for (int tile_count_x = map_node->right->data.size.x; tile_count_x < map_node->data.size.x; tile_count_x++)
            {
                tile_count = (tile_count_y * map_node->right->data.size.x) + tile_count_x;
                map_node->right->data.tile[tile_count].position.x = map_node->data.tile[tile_count].position.x;
                map_node->right->data.tile[tile_count].position.y = map_node->data.tile[tile_count].position.y;
                map_node->right->data.tile[tile_count].layer = 0;//test
printf("in loop - 4 - tile count %d\n",tile_count);
            }

        */
        map_gen_split(map_node->right);
        for(int tile_count = 0; tile_count < map_node->right->data.number_of_tiles; tile_count++)
        {
            int tile_data_count = tile_count; //for test only!
            map_node->data.tile[tile_data_count].position.x = map_node->right->data.tile[tile_count].position.x;
            map_node->data.tile[tile_data_count].position.y = map_node->right->data.tile[tile_count].position.y;
            //map_node->data.tile[tile_data_count].layer      = map_node->right->data.tile[tile_count].layer;
        }
        delete [] map_node->right;
    }
    if (!split_x && !split_y)
    {
        map_node->leaf = true;
        // gen_room code goes here
        // passage gen here?
        // add room_data to different data structure -> linked list of rooms?
    }
};

void map_gen(map_type *map_pointer)
{
    map_node_type temp_map;
    temp_map.data.size.x          = map_pointer->size.x;
    temp_map.data.size.y          = map_pointer->size.y;
    temp_map.data.number_of_tiles = temp_map.data.size.x * temp_map.data.size.y;
    temp_map.data.tile            = new tile_type[sizeof(map_pointer->tile)];
    temp_map.data.tile            = map_pointer->tile;
    temp_map.leaf                 = false;
    map_gen_split(&temp_map);
    map_pointer->tile             = temp_map.data.tile;
    delete [] &temp_map;
};

void map_gen_display(void)
{
    for (int tile_count_y = 0; tile_count_y < rdg_map.size.y; tile_count_y++)
    {
        for (int tile_count_x = 0; tile_count_x < rdg_map.size.x; tile_count_x++)
        {
            printf("%d",rdg_map.tile[(tile_count_y * rdg_map.size.x) + tile_count_x].layer);
        }
        if (rdg_map.size.x < 80) printf("\n");
    }
};
