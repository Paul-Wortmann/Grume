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

#ifndef MAP_GEN_M1_HPP
#define MAP_GEN_M1_HPP

#include <string>
#include "loader_fmx.hpp"
#include "types.hpp"

bool           map_gen_maze_tile_OK    (fmx_map_type *fmx_map_pointer, int tile_number);
void           map_gen_maze            (fmx_map_type *fmx_map_pointer, int tile_x, int tile_y);
void           map_gen_M1              (fmx_map_type *fmx_map_pointer, int seed);
void           map_gen_M1              (fmx_map_type *fmx_map_pointer);

#endif //MAP_GEN_M1_HPP

