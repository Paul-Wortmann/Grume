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

#ifndef LIBRMG_ROOMS_HPP
#define LIBRMG_ROOMS_HPP

#include "libRMG_defines.hpp"
#include "libRMG_includes.hpp"
#include "libRMG_utils.hpp"

bool _libRMG_room_genCircleRoomOK(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r);
void _libRMG_room_genCircleRoom(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r);
bool _libRMG_room_genSquareRoomOK(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r);
void _libRMG_room_genSquareRoom(sLibRMGMapData &_data, const uint32_t &_x, const uint32_t &_y, const uint32_t &_r);
//static void _libRMG_room_locateRoom(sLibRMGMapData &_data, const uint32_t &i)
void _libRMG_room_locateRooms(sLibRMGMapData &_data);
uint32_t _libRMG_room_getArea(sLibRMGMapData &_data, const uint32_t &_r);
//static void _libRMG_room_discardMinRooms(sLibRMGMapData &_data)
//static void _libRMG_room_sizeLocation(sLibRMGMapData &_data)
void _libRMG_room_discardAllButLargest(sLibRMGMapData &_data);
void _libRMG_room_initRooms(sLibRMGMapData &_data);
    
#endif // LIBRMG_ROOMS_HPP
