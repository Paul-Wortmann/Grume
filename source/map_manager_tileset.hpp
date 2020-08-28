/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
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
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef MAP_MANAGER_TILESET_HPP
#define MAP_MANAGER_TILESET_HPP

#include "includes.hpp"
#include "defines.hpp"

#include "libRMG.hpp"
#include "map_defines.hpp"


struct sMapTileset
{
   std::string name                   = "";
   std::string music                  = "";
   std::string floor_texture          = "";
   eMapBiome   biome                  = eMapBiome::mapBiomeDefault;
   eMapType    type                   = eMapType::mapTypeDefault;
   eMapRace    race                   = eMapRace::mapRaceDefault;

   std::string wall_straight_mesh     = "";
   std::string wall_straight_texture  = "";
   std::string wall_corner_mesh       = "";
   std::string wall_corner_texture    = "";
   std::string wall_end_mesh          = "";
   std::string wall_end_texture       = "";
   std::string wall_tjunction_mesh    = "";
   std::string wall_tjunction_texture = "";
   std::string wall_xjunction_mesh    = "";
   std::string wall_xjunction_texture = "";
   std::string wall_arch_mesh         = "";
   std::string wall_arch_texture      = "";
};

#endif // MAP_MANAGER_TILESET_HPP
