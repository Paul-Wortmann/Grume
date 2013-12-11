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

#include "pathfinding.hpp"
#include "loader_fmx.hpp"
#include "map_gen.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "../game/game.hpp"

extern game_class        game;

void map_path_reset (fmx_map_type *fmx_map_pointer)
{
    if (!fmx_map_pointer->path_data) fmx_map_pointer->path_data = new fmx_path_data_type[fmx_map_pointer->data.number_of_tiles+1];
    for (int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        fmx_map_pointer->path_data[tile_count].tile_data   = TILE_NONE;
        fmx_map_pointer->path_data[tile_count].parent_tile = -1;
        fmx_map_pointer->path_data[tile_count].closed_list = false;
        fmx_map_pointer->path_data[tile_count].open_list   = false;
        fmx_map_pointer->path_data[tile_count].G           = 0;
        fmx_map_pointer->path_data[tile_count].H           = 0;
        fmx_map_pointer->path_data[tile_count].F           = 0;
    }
    fmx_map_pointer->data.path_length = 0;
};

int  map_distance_H (fmx_map_type *fmx_map_pointer, int tile_current, int tile_end)
{
    int p_1_x = tile_current % fmx_map_pointer->data.map_width;
    int p_1_y = tile_current / fmx_map_pointer->data.map_width;
    int p_2_x = tile_end     % fmx_map_pointer->data.map_width;
    int p_2_y = tile_end     / fmx_map_pointer->data.map_width;
    return((abs(p_1_x - p_2_x)+abs(p_1_y - p_2_y))*10);
};

int  map_distance_G (fmx_map_type *fmx_map_pointer, int tile_current)
{
    int p_1_x = tile_current % fmx_map_pointer->data.map_width;
    int p_1_y = tile_current / fmx_map_pointer->data.map_width;
    int p_2_x = fmx_map_pointer->path_data[tile_current].parent_tile % fmx_map_pointer->data.map_width;
    int p_2_y = fmx_map_pointer->path_data[tile_current].parent_tile / fmx_map_pointer->data.map_width;
    int p_2_G = fmx_map_pointer->path_data[fmx_map_pointer->path_data[tile_current].parent_tile].G;
    return (p_2_G + ((p_1_x == p_2_x || p_1_y == p_2_y) ? 10 : 14));
};

int map_tile_calc (fmx_map_type *fmx_map_pointer, int tile_current, int tile_parent, int tile_end)
{
    int  return_value  = -1;
    int  layer_floor   = 0;
    if ((tile_current > -1) && (tile_current < fmx_map_pointer->data.number_of_tiles) && !fmx_map_pointer->path_data[tile_current].closed_list)
    {
        if (!fmx_map_pointer->layer[layer_floor].tile[tile_current].collision)
        {
            fmx_map_pointer->path_data[tile_current].parent_tile = tile_parent;
            fmx_map_pointer->path_data[tile_current].open_list   = true;
            fmx_map_pointer->path_data[tile_current].G           = map_distance_G(fmx_map_pointer,tile_current);
            fmx_map_pointer->path_data[tile_current].H           = map_distance_H(fmx_map_pointer,tile_current,tile_end);
            fmx_map_pointer->path_data[tile_current].F           = fmx_map_pointer->path_data[tile_current].G + fmx_map_pointer->path_data[tile_current].H;
            return_value = fmx_map_pointer->path_data[tile_current].F;
        }
    }
    return (return_value);
};

path_type* map_path_find(fmx_map_type *fmx_map_pointer, int position_1_x, int position_1_y, int position_2_x, int position_2_y)
{
    int tile_1 = (position_1_y * fmx_map_pointer->data.map_width) + position_1_x;
    int tile_2 = (position_2_y * fmx_map_pointer->data.map_width) + position_2_x;
    return(map_path_find (fmx_map_pointer,tile_1,tile_2));
}

path_type* map_path_find (fmx_map_type *fmx_map_pointer, int tile_1, int tile_2)
{
    map_path_reset(fmx_map_pointer);
    int      tile_start     = tile_1;
    int      tile_end       = tile_2;
    int      tile_current   = tile_start;
    int      path_length    =  0;
    int      tile_next      =  0;
    int      tile_next_t1   = -1;
    int      tile_next_t2   =  0;
    bool     border_left    = ((tile_current % fmx_map_pointer->data.map_width) == 0);
    bool     border_right   = (((tile_current+1) % fmx_map_pointer->data.map_width) == 0);
    fmx_map_pointer->path_data[tile_current].open_list = true;
    fmx_map_pointer->path_data[tile_current].tile_data = TILE_PATH;
    while ((tile_current <= tile_end) && (tile_next_t2 >= 0))
    {
        tile_next       =  -1;
        if (!border_left)
        {
            tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current - fmx_map_pointer->data.map_width - 1),tile_current,tile_end);
            if (tile_next  <= -1)
            {
                tile_next    = tile_next_t1;
                tile_next_t2 = (tile_current - fmx_map_pointer->data.map_width - 1);
            }
            if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current - fmx_map_pointer->data.map_width - 1);
            }
        }
        tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current - fmx_map_pointer->data.map_width    ),tile_current,tile_end);
        if (tile_next  <= -1)
        {
            tile_next = tile_next_t1;
            tile_next_t2 = (tile_current - fmx_map_pointer->data.map_width);
        }
        if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
        {
            tile_next = tile_next_t1;
            tile_next_t2 = (tile_current - fmx_map_pointer->data.map_width);
        }
        if (!border_right)
        {
            tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current - fmx_map_pointer->data.map_width + 1),tile_current,tile_end);
            if (tile_next  <= -1)
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current - fmx_map_pointer->data.map_width + 1);
            }
            if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current - fmx_map_pointer->data.map_width + 1);
            }
        }
        if (!border_left)
        {
            tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current - 1                          ),tile_current,tile_end);
            if (tile_next  <= -1)
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current - 1);
            }
            if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current - 1);
            }
        }
        if (!border_right)
        {
            tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current + 1                          ),tile_current,tile_end);
            if (tile_next  <= -1)
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current + 1);
            }
            if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current + 1);
            }
        }
        if (!border_left)
        {
            tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current + fmx_map_pointer->data.map_width - 1),tile_current,tile_end);
            if (tile_next  <= -1)
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current + fmx_map_pointer->data.map_width - 1);
            }
            if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current + fmx_map_pointer->data.map_width - 1);
            }
        }
        tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current + fmx_map_pointer->data.map_width    ),tile_current,tile_end);
        if (tile_next  <= -1)
        {
            tile_next = tile_next_t1;
            tile_next_t2 = (tile_current + fmx_map_pointer->data.map_width);
        }
        if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
        {
            tile_next = tile_next_t1;
            tile_next_t2 = (tile_current + fmx_map_pointer->data.map_width);
        }
        if (!border_right)
        {
            tile_next_t1    = map_tile_calc(fmx_map_pointer,(tile_current + fmx_map_pointer->data.map_width + 1),tile_current,tile_end);
            if (tile_next  <= -1)
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current + fmx_map_pointer->data.map_width + 1);
            }
            if ((tile_next_t1 > -1) && (tile_next_t1 < tile_next))
            {
                tile_next = tile_next_t1;
                tile_next_t2 = (tile_current + fmx_map_pointer->data.map_width + 1);
            }
        }
        path_length++;
        fmx_map_pointer->path_data[tile_current].tile_data   = TILE_PATH;
        fmx_map_pointer->path_data[tile_current].closed_list = true;
        tile_current    = tile_next_t2;
        border_left    = ((tile_current % fmx_map_pointer->data.map_width) == 0);
        border_right   = (((tile_current+1) % fmx_map_pointer->data.map_width) == 0);
    }
    fmx_map_pointer->path_data[tile_2].tile_data = TILE_PATH;
    // Return path.
    path_type* return_path;
    int  previous_tile_1      = -1;
    int  previous_tile_2      = -1;
    int  temp_tile            = -1;
    bool found_next_tile      = false;
    return_path               = new path_type;
    return_path->path_length  = path_length;
    return_path->tile_start   = tile_1;
    return_path->tile_end     = tile_2;
    return_path->tile_current = return_path->tile_start;
    return_path->path_length  = path_length;
    return_path->path_data    = new int[return_path->path_length];
    return_path->path_data[0] = tile_1;
    for (int current_tile = tile_1, path_position = 0; path_position  < path_length; path_position++)
    {
        //game.core.log.file_write("Path: ",current_tile);
        found_next_tile      = false;
        temp_tile = previous_tile_1 - fmx_map_pointer->data.map_width - 1;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        temp_tile = previous_tile_1 - fmx_map_pointer->data.map_width;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        temp_tile = previous_tile_1 - fmx_map_pointer->data.map_width + 1;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        temp_tile = previous_tile_1 - 1;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        temp_tile = previous_tile_1 + 1;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        temp_tile = previous_tile_1 + fmx_map_pointer->data.map_width - 1;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        temp_tile = previous_tile_1 + fmx_map_pointer->data.map_width;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        temp_tile = previous_tile_1 + fmx_map_pointer->data.map_width + 1;
        if ((!found_next_tile) && (temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->path_data[temp_tile].tile_data == TILE_PATH) && (temp_tile != previous_tile_2))
        {
            current_tile    = temp_tile;
            found_next_tile = true;
        }
        if (fmx_map_pointer->path_data[current_tile].tile_data == TILE_PATH) return_path->path_data[path_position] = current_tile;
        previous_tile_2 = previous_tile_1;
        previous_tile_1 = current_tile;
    }
    return(return_path);
};




// ------------------  new ----------------------------


path_type* _map_path_find(fmx_map_type *fmx_map_pointer, int position_1_x, int position_1_y, int position_2_x, int position_2_y)
{
    map_path_reset (fmx_map_pointer);
    path_node_type* path_node_pointer = new path_node_type;
    path_node_pointer->closed_list    = false;
    path_node_pointer->end_found      = false;
    path_node_pointer->tile_start_x   = position_1_x;
    path_node_pointer->tile_start_y   = position_1_y;
    path_node_pointer->tile_end_x     = position_2_x;
    path_node_pointer->tile_end_y     = position_2_y;
    path_node_pointer->tile_x         = position_1_x;
    path_node_pointer->tile_y         = position_1_y;
    path_node_pointer->F              = 0;
    path_node_pointer->G              = 0;
    path_node_pointer->H              = 0;
    path_node_pointer->path_length    = 0;
    path_node_pointer->parent         = NULL;
    return (map_path_find_internal(fmx_map_pointer, path_node_pointer, position_1_x, position_1_y));
};

path_node_type* map_path_find_internal_calc(fmx_map_type *fmx_map_pointer, path_node_type* parent_node_pointer, int position_1_x, int position_1_y)
{
    path_node_type* return_node_pointer = NULL;
    if ((position_1_x >= 0) && (position_1_x < fmx_map_pointer->data.map_width) &&
        (position_1_y >= 0) && (position_1_y < fmx_map_pointer->data.map_height) &&
        (!fmx_map_pointer->layer[LAYER_FLOOR].tile[position_1_x+(position_1_y*fmx_map_pointer->data.map_width)].collision))
    {
        return_node_pointer                 = new path_node_type;
        return_node_pointer->closed_list    = false;
        return_node_pointer->end_found      = false;
        return_node_pointer->tile_start_x   = parent_node_pointer->tile_start_x;
        return_node_pointer->tile_start_y   = parent_node_pointer->tile_start_y;
        return_node_pointer->tile_end_x     = parent_node_pointer->tile_end_x;
        return_node_pointer->tile_end_y     = parent_node_pointer->tile_end_y;
        return_node_pointer->tile_x         = position_1_x;
        return_node_pointer->tile_y         = position_1_y;
        return_node_pointer->parent         = parent_node_pointer;
        if ((return_node_pointer->tile_end_x == return_node_pointer->tile_x) && (return_node_pointer->tile_end_y == return_node_pointer->tile_y)) return_node_pointer->end_found = true;
        game.core.log.file_write(" Tile end x -> ",return_node_pointer->tile_end_x);
        game.core.log.file_write(" Tile end y -> ",return_node_pointer->tile_end_y);
        game.core.log.file_write(" Tile     x -> ",return_node_pointer->tile_x);
        game.core.log.file_write(" Tile     y -> ",return_node_pointer->tile_y);
        return_node_pointer->H              = ((abs(return_node_pointer->tile_x - return_node_pointer->tile_end_x)+abs(return_node_pointer->tile_y - return_node_pointer->tile_end_y))*10);
        return_node_pointer->G              = (parent_node_pointer->G + ((return_node_pointer->tile_x == parent_node_pointer->tile_y || return_node_pointer->tile_y == parent_node_pointer->tile_y) ? 10 : 14));
        return_node_pointer->F              = return_node_pointer->H + return_node_pointer->G;
        return_node_pointer->path_length    = parent_node_pointer->path_length + 1;
    }
    return (return_node_pointer);
};

path_type* map_path_find_internal(fmx_map_type *fmx_map_pointer, path_node_type* path_node_pointer, int position_1_x, int position_1_y)
{
    #define NUM_NODES 8
    int        temp_F     = 0;
    int        temp_node  = 0;
    bool       end_found  = false;
    path_type* return_path;
    // -------------- compute adjoining node values ------------------------
    path_node_pointer->node_1 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x+1,path_node_pointer->tile_y);
    path_node_pointer->node_2 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x-1,path_node_pointer->tile_y);
    path_node_pointer->node_3 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x  ,path_node_pointer->tile_y+1);
    path_node_pointer->node_4 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x+1,path_node_pointer->tile_y+1);
    path_node_pointer->node_5 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x-1,path_node_pointer->tile_y+1);
    path_node_pointer->node_6 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x  ,path_node_pointer->tile_y-1);
    path_node_pointer->node_7 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x+1,path_node_pointer->tile_y-1);
    path_node_pointer->node_8 = map_path_find_internal_calc(fmx_map_pointer,path_node_pointer,path_node_pointer->tile_x-1,path_node_pointer->tile_y-1);
    if ((path_node_pointer->node_1 != NULL) && (path_node_pointer->node_1->end_found)) end_found = true;
    if ((path_node_pointer->node_2 != NULL) && (path_node_pointer->node_2->end_found)) end_found = true;
    if ((path_node_pointer->node_3 != NULL) && (path_node_pointer->node_3->end_found)) end_found = true;
    if ((path_node_pointer->node_4 != NULL) && (path_node_pointer->node_4->end_found)) end_found = true;
    if ((path_node_pointer->node_5 != NULL) && (path_node_pointer->node_5->end_found)) end_found = true;
    if ((path_node_pointer->node_6 != NULL) && (path_node_pointer->node_6->end_found)) end_found = true;
    if ((path_node_pointer->node_7 != NULL) && (path_node_pointer->node_7->end_found)) end_found = true;
    if ((path_node_pointer->node_8 != NULL) && (path_node_pointer->node_8->end_found)) end_found = true;
    if (end_found) path_node_pointer->end_found = true;
    if (end_found) game.core.log.file_write("END FOUND!!!!");
    for (int node_count = 0; node_count < NUM_NODES; node_count++)
    {
        int  temp_F     = 0;
        int  temp_node  = 0;
        if ((!end_found) && (path_node_pointer->node_1 != NULL) && (!path_node_pointer->node_1->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_1->F < temp_F))
            {
                temp_F    = path_node_pointer->node_1->F;
                temp_node = 1;
            }
        }
        if ((!end_found) && (path_node_pointer->node_2 != NULL) && (!path_node_pointer->node_2->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_2->F < temp_F))
            {
                temp_F    = path_node_pointer->node_2->F;
                temp_node = 2;
            }
        }
        if ((!end_found) && (path_node_pointer->node_3 != NULL) && (!path_node_pointer->node_3->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_3->F < temp_F))
            {
                temp_F    = path_node_pointer->node_3->F;
                temp_node = 3;
            }
        }
        if ((!end_found) && (path_node_pointer->node_4 != NULL) && (!path_node_pointer->node_4->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_4->F < temp_F))
            {
                temp_F    = path_node_pointer->node_4->F;
                temp_node = 4;
            }
        }
        if ((!end_found) && (path_node_pointer->node_5 != NULL) && (!path_node_pointer->node_5->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_5->F < temp_F))
            {
                temp_F    = path_node_pointer->node_5->F;
                temp_node = 5;
            }
        }
        if ((!end_found) && (path_node_pointer->node_6 != NULL) && (!path_node_pointer->node_6->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_6->F < temp_F))
            {
                temp_F    = path_node_pointer->node_6->F;
                temp_node = 6;
            }
        }
        if ((!end_found) && (path_node_pointer->node_7 != NULL) && (!path_node_pointer->node_7->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_7->F < temp_F))
            {
                temp_F    = path_node_pointer->node_7->F;
                temp_node = 7;
            }
        }
        if ((!end_found) && (path_node_pointer->node_8 != NULL) && (!path_node_pointer->node_8->closed_list))
        {
            if ((temp_F = 0) || (path_node_pointer->node_8->F < temp_F))
            {
                temp_F    = path_node_pointer->node_8->F;
                temp_node = 8;
            }
        }
        switch (temp_node)
        {
            case 1:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_1, path_node_pointer->node_1->tile_x, path_node_pointer->node_1->tile_y);
            break;
            case 2:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_2, path_node_pointer->node_2->tile_x, path_node_pointer->node_2->tile_y);
            break;
            case 3:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_3, path_node_pointer->node_3->tile_x, path_node_pointer->node_3->tile_y);
            break;
            case 4:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_4, path_node_pointer->node_4->tile_x, path_node_pointer->node_4->tile_y);
            break;
            case 5:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_5, path_node_pointer->node_5->tile_x, path_node_pointer->node_5->tile_y);
            break;
            case 6:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_6, path_node_pointer->node_6->tile_x, path_node_pointer->node_6->tile_y);
            break;
            case 7:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_7, path_node_pointer->node_7->tile_x, path_node_pointer->node_7->tile_y);
            break;
            case 8:
                return_path = map_path_find_internal(fmx_map_pointer,path_node_pointer->node_8, path_node_pointer->node_8->tile_x, path_node_pointer->node_8->tile_y);
            break;
            default:
            break;
        }
    }
    if (end_found)
    {
        return_path->path_length++;
        game.core.log.file_write("- - -  is called? - - - ");
        fmx_map_pointer->path_data[position_1_x+(position_1_y*fmx_map_pointer->data.map_width)].tile_data = TILE_PATH;
        fmx_map_pointer->data.path_length = return_path->path_length;
    }
    return (return_path);
};


