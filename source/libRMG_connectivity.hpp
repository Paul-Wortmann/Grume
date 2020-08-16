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

#ifndef LIBRMG_CONNECTIVITY_HPP
#define LIBRMG_CONNECTIVITY_HPP

#include "libRMG_defines.hpp"
#include "libRMG_includes.hpp"
#include "libRMG_pathing.hpp"

void _libRMG_connect_rooms(sLibRMGMapData &_data);
void _libRMG_connect_rooms_SL(sLibRMGMapData &_data, const uint16_t &_r1, const uint16_t &_r2);
void _libRMG_connect_rooms_ND(sLibRMGMapData &_data, const uint16_t &_r1, const uint16_t &_r2);
void _libRMG_connect_rooms_DW(sLibRMGMapData &_data, const uint16_t &_r1, const uint16_t &_r2);

#endif // LIBRMG_CONNECTIVITY_HPP

