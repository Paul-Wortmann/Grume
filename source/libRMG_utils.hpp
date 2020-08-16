/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libRMG"
 *
 * "libRMG" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libRMG" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libRMG" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#ifndef LIBRMG_UTILS_HPP
#define LIBRMG_UTILS_HPP

#include "libRMG_defines.hpp"
#include "libRMG_includes.hpp"
#include "libRMG_prefab.hpp"

void _libRMG_utils_map_initialize(sLibRMGMapData &_data);
void _libRMG_utils_map_free(sLibRMGMapData &_data);
void _libRMG_utils_map_perimeter_walls(sLibRMGMapData &_data);
void _libRMG_utils_map_draw(sLibRMGMapData &_data);
uint32_t _libRMG_utils_map_get_floor_min(sLibRMGMapData &_data);
uint32_t _libRMG_utils_map_get_floor_max(sLibRMGMapData &_data);
uint32_t _libRMG_utils_map_get_floor_area(sLibRMGMapData &_data);
void _libRMG_utils_map_remove_anomalies(sLibRMGMapData &_data);

#endif // LIBRMG_UTILS_HPP

