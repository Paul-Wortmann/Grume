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

#ifndef LIBRMG_PREFAB_HPP
#define LIBRMG_PREFAB_HPP

#include "libRMG_defines.hpp"
#include "libRMG_includes.hpp"

//static void _libRMG_prefab_stripSpaces(std::string &_string);
//static int32_t _libRMG_prefab_xmlGetSingleInt(const std::string &_string);
//static int32_t _libRMG_prefab_xmlGetIntValueCount(const std::string &_string);
//static int32_t _libRMG_prefab_xmlGetIntValue(const std::string &_string, const uint16_t &_pos);
void _libRMG_prefab_freeAll(sLibRMGMapData &_data);
void _libRMG_prefab_eventFreeAll(sLibRMGMapData &_data);
bool _libRMG_prefab_find(sLibRMGMapData &_data);
void _libRMG_prefab_load(sLibRMGMapData &_data, const std::string &_fileName);
void _libRMG_prefab_rooms(sLibRMGMapData &_data);
void _libRMG_prefab_roomFlipV(sLibRMGPrefab &_prefab); // Flip Vertically
void _libRMG_prefab_roomFlipH(sLibRMGPrefab &_prefab); // Flip Horizontally
void _libRMG_prefab_rotateR90(sLibRMGPrefab &_prefab); // Rotate right 90 degrees
void _libRMG_prefab_rotateL90(sLibRMGPrefab &_prefab); // Rotate left 90 degrees
void _libRMG_prefab_rotate180(sLibRMGPrefab &_prefab); // Rotate 180 degrees

#endif // LIBRMG_PREFAB_HPP

