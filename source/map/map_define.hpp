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

#ifndef MAP_DEFINE_HPP
#define MAP_DEFINE_HPP

#include "../core/includes.hpp"
#include "map_define_condition.hpp"
#include "map_define_debris.hpp"
#include "map_define_event.hpp"
#include "map_define_generate.hpp"
#include "map_define_information.hpp"
#include "map_define_npc.hpp"
#include "map_define_npc_mob.hpp"
#include "map_define_object.hpp"
#include "map_define_portal.hpp"
#include "map_define_room.hpp"
#include "map_define_tile.hpp"

const float rot000 = 0.0f;
const float rot090 = 1.57079632679f;
const float rot180 = 3.14159265359f;
const float rot270 = 4.71238898038f;

struct sMap
{
    // Base
    sMapInformation info          = {};

    // Map Conditions
    std::uint32_t  numCondition   = 0;
    sMapCondition* condition      = nullptr;

    // Map debris
    std::uint32_t  numDebris      = 0;
    sMapDebris*    debris         = nullptr;

    // Map events
    std::uint32_t  numEvent       = 0;
    sMapEvent*     event          = nullptr;

    // Map generation data
    sMapGenerate*  generate       = nullptr;

    // Map NPCs
    std::uint32_t  numNPC         = 0;
    sMapNPC*       npc            = nullptr;

    // Map NPC mobs
    std::uint32_t  numNPCmob      = 0;
    sMapNPCMob*    npcMob         = nullptr;

    // Map objects
    std::uint32_t  numObject      = 0;
    sMapObject*    object         = nullptr;

    // Map portals
    std::uint32_t  numPortal      = 0;
    sMapPortal*    portal         = nullptr;

    // Map rooms
    std::uint32_t  numRoom        = 0;
    sMapRoom*      room           = nullptr;

    // Tiles
    std::uint32_t   numTiles      = 0;
    sMapTile*       tile          = nullptr;
};

#endif // MAP_DEFINE_HPP

