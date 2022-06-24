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

#include "biome_define.hpp"
#include "map_define_condition.hpp"
#include "map_define_debris.hpp"
#include "map_define_event.hpp"
#include "map_define_generate.hpp"
#include "map_define_npc.hpp"
#include "map_define_npc_mob.hpp"
#include "map_define_object.hpp"
#include "map_define_portal.hpp"
#include "map_define_room.hpp"
#include "map_define_sprite_tile.hpp"
#include "map_define_tile.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_define.hpp"

struct sMap
{
    // Linked list
    sMap*          next                = nullptr;
    std::uint32_t  UID                 = 0;

    // Infomation
    std::string    name                = {};
    std::string    fileName            = {};
    float          terrainHeight       = -1.0f; // Default == -1.0f

    // Music
    bool           musicDefined        = false;
    std::string    musicFileName       = {};
    std::string    musicTagName        = {};
    std::uint32_t  musicNumber         = 0;

    // Player start information
    std::uint32_t  playerStartPortal   = 0;
    std::uint32_t  playerStartTile     = 0;
    float          playerStartDir      = 0.0f;

    // information about next and previous maps
    std::uint32_t  map_previous        = 0;
    std::uint32_t  map_previous_portal = 0;
    std::uint32_t  map_next            = 0;
    std::uint32_t  map_next_portal     = 0;

    // Entity to hold the floor
    sEntity*       floor               = nullptr;

    // Tile
    std::uint32_t  width               = 0;
    std::uint32_t  height              = 0;
    std::uint32_t  numTiles            = 0;
    sMapTile*      tile                = nullptr;

    // PCG
    sMapGenData    genData             = {};

    // Biome
    sMapBiome*     biome               = nullptr;
    
    // Map conditions
    std::uint32_t  conditionCount      = 0;
    sMapCondition* condition           = nullptr;
    
    // Map events
    std::uint32_t  eventCount          = 0;
    sMapEvent*     event               = nullptr;
    
    // Map portals
    std::uint32_t  portalCount         = 0;
    sMapPortal*    portal              = nullptr;

    // Map Rooms
    std::uint32_t  roomCount           = 0;
    sMapRoom*      room                = nullptr;

    // Map Objects
    std::uint32_t  objectCount         = 0;
    sMapObject*    object              = nullptr;    

    // Map Debris
    std::uint32_t  debrisCount         = 0;
    sMapDebris*    debris              = nullptr;

    // Map NPC Mobs
    std::uint32_t  npcMobCount         = 0;
    sMapNPCMob*    npcMob              = nullptr;    

    // Map NPCs
    std::uint32_t  npcCount            = 0;
    sMapNPC*       npc                 = nullptr;
};

struct sMapPrefab
{
    // Tile
    std::uint32_t  width               = 0;
    std::uint32_t  height              = 0;
    std::uint32_t  numTiles            = 0;
    sMapTile*      tile                = nullptr;

    // Map events
    std::uint32_t  eventCount          = 0;
    sMapEvent*     event               = nullptr;
    
    // Map portals
    std::uint32_t  portalCount         = 0;
    sMapPortal*    portal              = nullptr;
};

#endif //MAP_DEFINE_HPP

