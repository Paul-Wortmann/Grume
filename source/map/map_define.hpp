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

#ifndef MAP_DEFINE_HPP
#define MAP_DEFINE_HPP

#include "../includes.hpp"
#include "biome_define.hpp"
#include "../entity/entity_define.hpp"

#define FLOOR_SPRITESHEET_WIDTH  4
#define FLOOR_SPRITESHEET_HEIGHT 4
    
enum class eSpriteType : std::uint32_t 
    { 
        tileNone      = 0, // None
        tileFloor     = 1, // Floor tile
        tilePath      = 2, // Path  tile
        tilePathLine  = 3, // Path  tile -> Line
        tilePathOuter = 4, // Path  tile -> Corner, Outer
        tilePathInner = 5, // Path  tile -> Corner, Inner
    };

struct sMapSpriteTile
{
    eSpriteType   type       = eSpriteType::tileFloor;
    std::uint32_t processed  = 0; // Default == 0
    std::uint32_t spriteNumX = 0; // Default == 0
    std::uint32_t spriteNumY = 0; // Default == 0
    std::uint32_t rotation   = 0; // Default == 0 (0 -> 0 degrees, 1 -> 90 degrees, 2 -> 180 degrees, 3 -> 270 degrees)
};

enum class eTileBase : std::uint32_t 
    { 
        tileNone      = 0,
        tileFloor     = 1,
        tileWall      = 2,
        tileDoorway   = 3,
        tileWallShort = 4,
        tileFloorPath = 5,
        tileFloorNoGo = 6,
        tilePathNoGo  = 7,
        tileLiquid    = 8
    };

struct sMapGenData
{
    std::uint32_t seed      = 0; // 0 for random seed
    std::uint32_t algorithm = 0; // 0: C1,
    std::uint32_t wallSize  = 0; // 0: Wide, 1: Thin
};

struct sMapTile
{
    std::uint32_t processed = 0; // Default == 0
    eTileBase     base      = eTileBase::tileFloor; // Default == 0
    std::uint32_t object    = 0; // Default == 0
    //std::uint32_t event = 0;
};

enum class eMapEventType : std::uint32_t 
{ 
    eventTypeNone         = 0, // None
    eventTypeWarp         = 1, // Warp to map
    eventTypeEntitySet    = 2, // Set entity state
    eventTypeEntitySpawn  = 3  // Spawn entity
};

struct sMapEvent
{
    eMapEventType type      = eMapEventType::eventTypeNone;
    std::uint32_t tile      = 0;
    std::uint32_t data_1    = 0;
    std::uint32_t data_2    = 0;
    bool          triggered = false;
};

struct sMapPortal
{
    std::uint32_t portalNo  = 0;
    std::uint32_t tile      = 0;
    float32       direction = 0.0f;
};

struct sMap
{
    // Linked list
    sMap*          next            = nullptr;
    std::uint32_t  UID             = 0;

    // Infomation
    std::string    name            = "";
    std::string    fileName        = "";

    // Player start information
    std::uint32_t  playerStartPortal = 0;
    std::uint32_t  playerStartTile   = 0;
    float          playerStartDir    = 0.0f;

    // Entity to hold the floor
    sEntity*       floor           = nullptr;

    // Tile
    std::uint32_t  width           = 0;
    std::uint32_t  height          = 0;
    std::uint32_t  numTiles        = 0;
    sMapTile*      tile            = nullptr;

    // PCG
    sMapGenData    genData         = {};

    // Biome
    sMapBiome*     biome           = nullptr;
    
    // Map events
    std::uint32_t  eventCount      = 0;
    sMapEvent*     event           = nullptr;
    
    // Map portals
    std::uint32_t  portalCount     = 0;
    sMapPortal*    portal          = nullptr;
};

#endif //MAP_DEFINE_HPP

