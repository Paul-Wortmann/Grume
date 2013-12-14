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
    fmx_map_pointer->data.path_length    = 0;
    fmx_map_pointer->data.path_end_found = false;
};

int map_tile_calc (fmx_map_type *fmx_map_pointer, int tile_current, int tile_parent, int tile_end)
{
    int p_1_x = 0;
    int p_1_y = 0;
    int  return_value  = -1;
    int  layer_floor   = 0;
    if ((tile_current > -1) && (tile_current < fmx_map_pointer->data.number_of_tiles) && !fmx_map_pointer->path_data[tile_current].closed_list)
    {
        if (!fmx_map_pointer->layer[layer_floor].tile[tile_current].collision)
        {
            if (fmx_map_pointer->path_data[tile_current].parent_tile == -1) fmx_map_pointer->path_data[tile_current].parent_tile = tile_parent;
            int p_1_x = tile_current % fmx_map_pointer->data.map_width;
            int p_1_y = tile_current / fmx_map_pointer->data.map_width;
            int p_2_x = fmx_map_pointer->path_data[tile_current].parent_tile % fmx_map_pointer->data.map_width;
            int p_2_y = fmx_map_pointer->path_data[tile_current].parent_tile / fmx_map_pointer->data.map_width;
            int p_2_G = fmx_map_pointer->path_data[fmx_map_pointer->path_data[tile_current].parent_tile].G;
            int p_3_x = tile_end     % fmx_map_pointer->data.map_width;
            int p_3_y = tile_end     / fmx_map_pointer->data.map_width;
            fmx_map_pointer->path_data[tile_current].parent_tile = tile_parent;
            fmx_map_pointer->path_data[tile_current].open_list   = true;
            fmx_map_pointer->path_data[tile_current].G           = (p_2_G + ((p_1_x == p_2_x || p_1_y == p_2_y) ? 10 : 14));
            fmx_map_pointer->path_data[tile_current].H           = ((abs(p_1_x - p_3_x)+abs(p_1_y - p_3_y))*10);
            fmx_map_pointer->path_data[tile_current].F           = fmx_map_pointer->path_data[tile_current].G + fmx_map_pointer->path_data[tile_current].H;
            return_value = fmx_map_pointer->path_data[tile_current].F;
        }
        else fmx_map_pointer->path_data[tile_current].closed_list = true;
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

path_type*  _map_path_find(fmx_map_type *fmx_map_pointer, int position_1_x, int position_1_y, int position_2_x, int position_2_y)
{
    int tile_1 = (position_1_y * fmx_map_pointer->data.map_width) + position_1_x;
    int tile_2 = (position_2_y * fmx_map_pointer->data.map_width) + position_2_x;
    return(_map_path_find (fmx_map_pointer,tile_1,tile_2));
};

path_type*  _map_path_find(fmx_map_type *fmx_map_pointer, int tile_start, int tile_end)
{
    map_path_reset(fmx_map_pointer);
    path_node_type* path_node_pointer = new path_node_type;
    path_node_pointer->root = path_node_pointer;
    path_node_pointer->next = path_node_pointer;
    path_node_pointer->last = path_node_pointer;
    path_node_pointer->tile = tile_start;
    path_type* return_path = _map_path_find_internal(fmx_map_pointer, path_node_pointer, tile_start , tile_end);
    return (return_path);
};

path_type*  _map_path_find_internal(fmx_map_type *fmx_map_pointer, path_node_type* path_node_pointer, int tile_start, int tile_end)
{
    fmx_map_pointer->path_data[path_node_pointer->tile].tile_data = TILE_PATH;
    int tile_current = path_node_pointer->tile;
    int node_1_F     = -1;
    int node_2_F     = -1;
    int node_3_F     = -1;
    int node_4_F     = -1;
    int node_5_F     = -1;
    int node_6_F     = -1;
    int node_7_F     = -1;
    int node_8_F     = -1;
    int node_1_tile  = -1;
    int node_2_tile  = -1;
    int node_3_tile  = -1;
    int node_4_tile  = -1;
    int node_5_tile  = -1;
    int node_6_tile  = -1;
    int node_7_tile  = -1;
    int node_8_tile  = -1;
    int node_next    = -1;
    int node_next_F  = -1;
    path_type* return_path = new path_type;
    fmx_map_pointer->data.path_end_found = (path_node_pointer->tile == tile_end) ? true : false;
    //for (int tile_count = 0; tile_count < ; tile_count++){};
    if (!fmx_map_pointer->data.path_end_found)
    {
        node_1_tile = path_node_pointer->tile-fmx_map_pointer->data.map_width-1;
        if ((node_1_tile >= 0) && (node_1_tile < fmx_map_pointer->data.number_of_tiles))
            node_1_F = map_tile_calc (fmx_map_pointer, node_1_tile, path_node_pointer->tile,tile_end);
        if ((node_1_tile > -1) && ((node_next_F == -1) || (node_next_F > node_1_F)))
        {
            node_next   = 1;
            node_next_F = node_1_F;
        }
        node_2_tile = path_node_pointer->tile-fmx_map_pointer->data.map_width;
        if ((node_2_tile >= 0) && (node_2_tile < fmx_map_pointer->data.number_of_tiles))
            node_2_F = map_tile_calc (fmx_map_pointer, node_2_tile, path_node_pointer->tile,tile_end);
        if ((node_2_tile > -1) && ((node_next_F == -1) || (node_next_F > node_2_F)))
        {
            node_next   = 2;
            node_next_F = node_2_F;
        }
        node_3_tile = path_node_pointer->tile-fmx_map_pointer->data.map_width+1;
        if ((node_3_tile >= 0) && (node_3_tile < fmx_map_pointer->data.number_of_tiles))
            node_3_F = map_tile_calc (fmx_map_pointer, node_3_tile, path_node_pointer->tile,tile_end);
        if ((node_3_tile > -1) && ((node_next_F == -1) || (node_next_F > node_3_F)))
        {
            node_next   = 3;
            node_next_F = node_3_F;
        }
        node_4_tile = path_node_pointer->tile-1;
        if ((node_4_tile >= 0) && (node_4_tile < fmx_map_pointer->data.number_of_tiles))
            node_4_F = map_tile_calc (fmx_map_pointer, node_4_tile, path_node_pointer->tile,tile_end);
        if ((node_4_tile > -1) && ((node_next_F == -1) || (node_next_F > node_4_F)))
        {
            node_next   = 4;
            node_next_F = node_4_F;
        }
        node_5_tile = path_node_pointer->tile+1;
        if ((node_5_tile >= 0) && (node_5_tile < fmx_map_pointer->data.number_of_tiles))
            node_5_F = map_tile_calc (fmx_map_pointer, node_5_tile, path_node_pointer->tile,tile_end);
        if ((node_5_tile > -1) && ((node_next_F == -1) || (node_next_F > node_5_F)))
        {
            node_next   = 5;
            node_next_F = node_5_F;
        }
        node_6_tile = path_node_pointer->tile+fmx_map_pointer->data.map_width-1;
        if ((node_6_tile >= 0) && (node_6_tile < fmx_map_pointer->data.number_of_tiles))
            node_6_F = map_tile_calc (fmx_map_pointer, node_6_tile, path_node_pointer->tile,tile_end);
        if ((node_6_tile > -1) && ((node_next_F == -1) || (node_next_F > node_6_F)))
        {
            node_next   = 6;
            node_next_F = node_6_F;
        }
        node_7_tile = path_node_pointer->tile+fmx_map_pointer->data.map_width;
        if ((node_7_tile >= 0) && (node_7_tile < fmx_map_pointer->data.number_of_tiles))
            node_7_F = map_tile_calc (fmx_map_pointer, node_7_tile, path_node_pointer->tile,tile_end);
        if ((node_7_tile > -1) && ((node_next_F == -1) || (node_next_F > node_7_F)))
        {
            node_next   = 7;
            node_next_F = node_7_F;
        }
        node_8_tile = path_node_pointer->tile+fmx_map_pointer->data.map_width+1;
        if ((node_8_tile >= 0) && (node_8_tile < fmx_map_pointer->data.number_of_tiles))
            node_8_F = map_tile_calc (fmx_map_pointer, node_8_tile, path_node_pointer->tile,tile_end);
        if ((node_8_tile > -1) && ((node_next_F == -1) || (node_next_F > node_8_F)))
        {
            node_next   = 8;
            node_next_F = node_8_F;
        }
            game.core.log.file_write("Node next -> ",node_next);
            game.core.log.file_write("Node F -> ",node_next_F);
        if (node_next == -1)
        {
            fmx_map_pointer->path_data->closed_list = true;
            fmx_map_pointer->data.path_end_found    = true;
        }
        if (!fmx_map_pointer->data.path_end_found)
        {
            if (!path_node_pointer->next != NULL) delete path_node_pointer->next;
            path_node_pointer->next = new path_node_type;
            switch (node_next)
            {
                case 1:
                    path_node_pointer->next->tile = node_1_tile;
                break;
                case 2:
                    path_node_pointer->next->tile = node_2_tile;
                break;
                case 3:
                    path_node_pointer->next->tile = node_3_tile;
                break;
                case 4:
                    path_node_pointer->next->tile = node_4_tile;
                break;
                case 5:
                    path_node_pointer->next->tile = node_5_tile;
                break;
                case 6:
                    path_node_pointer->next->tile = node_6_tile;
                break;
                case 7:
                    path_node_pointer->next->tile = node_7_tile;
                break;
                case 8:
                    path_node_pointer->next->tile = node_8_tile;
                break;
                default:
                break;
            }
            path_node_pointer->last = path_node_pointer->next;
            path_node_pointer = path_node_pointer->next;
            return_path = _map_path_find_internal(fmx_map_pointer, path_node_pointer, tile_start , tile_end);
        }
    }
    return (return_path);
};
