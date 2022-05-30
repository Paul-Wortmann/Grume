/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP

#include "../core/includes.hpp"
#include "map_define.hpp"

std::uint32_t gMapPositionToTile(sMap*& _map, const glm::vec3 &_position);
glm::vec3     gMapTileToPosition(sMap*& _map, const std::uint32_t &_tile);
std::uint32_t gDistanceTiles(sMap*& _map, const std::uint32_t &_tile1, const std::uint32_t &_tile2);
std::uint32_t gClosestFreeTile(sMap*& _map, const std::uint32_t &_sTile, const std::uint32_t &_dTile);


#endif //MAP_UTILS_HPP

