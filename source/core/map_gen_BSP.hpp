/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef MAP_GEN_BSP_HPP
#define MAP_GEN_BSP_HPP

#include <string>
#include "loader_fmx.hpp"
#include "types.hpp"

void           map_gen_BSP_split       (fmx_map_type *fmx_map_pointer, map_node_type *map_node);
void           map_gen_BSP             (fmx_map_type *fmx_map_pointer);
void           map_gen_BSP_internal    (fmx_map_type *fmx_map_pointer);
void           map_gen_BSP             (fmx_map_type *fmx_map_pointer, int seed);

#endif //MAP_GEN_BSP_HPP

