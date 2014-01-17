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

#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "loader_fmx.hpp"

struct path_node_type
{
    int             tile;
    path_node_type* root;
    path_node_type* next;
    path_node_type* last;
};

struct path_type
{
    bool      end_found;
    int       tile_start;
    int       tile_end;
    int       tile_current;
    int       path_length;
    int*      path_data;
};

void map_path_reset (fmx_map_type *fmx_map_pointer);
int  map_tile_calc  (fmx_map_type *fmx_map_pointer, int tile_current, int tile_parent, int tile_end);
path_type*  map_path_find(fmx_map_type *fmx_map_pointer, int position_1_x, int position_1_y, int position_2_x, int position_2_y);
path_type*  map_path_find(fmx_map_type *fmx_map_pointer, int tile_start, int tile_end);
path_type*  map_path_find_internal(fmx_map_type *fmx_map_pointer, path_node_type* path_node_pointer, int tile_start, int tile_end);

int map_path_find_heuristic_manhattan(int tile_1_x, int tile_1_y, int tile_2_x, int tile_2_y);
int map_path_find_heuristic_chebyshev(int tile_1_x, int tile_1_y, int tile_2_x, int tile_2_y);
int map_path_find_heuristic_euclidean(int tile_1_x, int tile_1_y, int tile_2_x, int tile_2_y);

#endif //PATHFINDING_H











