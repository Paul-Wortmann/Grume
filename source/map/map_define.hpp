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

#include "../core/includes.hpp"
#include "biome_define.hpp"
#include "../entity/entity_define.hpp"

#define FLOOR_SPRITESHEET_WIDTH  4
#define FLOOR_SPRITESHEET_HEIGHT 4
    
enum class eSpriteType : std::uint16_t 
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

enum class eTileBase : std::uint16_t 
    { 
        tileNone      = 0,
        tileFloor     = 1,
        tileWall      = 2,
        tileDoorway   = 3,
        tileWallShort = 4,
        tileFloorPath = 5,
        tileFloorNoGo = 6,
        tilePathNoGo  = 7,
        tileLiquid    = 8,
        tileIgnore    = 9  // Used for prefab loading
    };

enum class eAlgorithm : std::uint16_t 
    { 
        algorithm_C1  = 0, // Cave generation algorithm 1
        algorithm_C2  = 1, // Cave generation algorithm 2
        algorithm_D1  = 2, // Dungeon generation algorithm 1
        algorithm_D2  = 3, // Dungeon generation algorithm 2
        algorithm_M1  = 4, // Maze generation algorithm 1
        algorithm_T1  = 5  // Town generation algorithm 1
    };

enum class eConnectAlgo : std::uint16_t // Connectivity algorithm
    { 
        algorithm_SL  = 0, // Straight Line
        algorithm_ND  = 1, // Ninety Degree angle lines
        algorithm_DW  = 2  // Drunken Walk
    };

enum class eRoomShape : std::uint16_t // Room shape
    { 
        shapeRandom  = 0, // Random
        shapeCircle  = 1, // Circle
        shapeSquare  = 2  // Square
    };

enum class eDirectionBias : std::int16_t // Direction bias
    { 
        noRoom         = -1, // No room
        directionNone  =  0, // None
        directionNorth =  1, // North
        directionSouth =  2, // South
        directionEast  =  3, // East
        directionWest  =  4  // West
    };

struct sMapGenData
{
    std::uint32_t  seed                   = 0; // 0 for random seed
    eAlgorithm     algorithm              = eAlgorithm::algorithm_C1; // 0: C1,
    std::uint32_t  wallSize               = 0; // 0: Wide, 1: Thin

    std::uint16_t  pass                   = 4; // General number of passes, smoothing etc...
    std::uint16_t  density                = 10; // Percentage / 2, rough approximate
    std::uint16_t  roomMin                = 3; // Guaranteed minimum number of rooms, maps with less are discarded (sMap.pass times)
    std::uint16_t  roomMax                = static_cast<std::uint16_t>(density * pass); // Will try generate up to roomMax rooms, on a tiny map reaching this is impossible
    std::uint16_t  roomRadiusMax          = 8; // max room radius
    std::uint16_t  roomRadiusMin          = 2; // min room radius
    std::uint16_t  roomBorder             = 3; // Wall width
    eRoomShape     roomShape              = eRoomShape::shapeSquare;
    std::uint16_t  floorAreaMin           = 60; // percentage, min % floor area
    eConnectAlgo   connectivityAlgorithm  = eConnectAlgo::algorithm_SL;
    std::uint16_t  connectivityComplexity = 50; // percentage, rand % connect neighbors
    std::uint16_t  connectivityPadding    = 0; // Tiles to pad on each side of generated paths, roomBorder should be taken into consideration!
    eDirectionBias directionBias          = eDirectionBias::directionNone; // Favored direction
    std::uint16_t  directionBiasStrength  = 2; // Favored direction strength
};

struct sMapTile
{
    std::uint32_t processed = 0; // Default == 0
    eTileBase     base      = eTileBase::tileFloor; // Default == 0
    std::uint32_t object    = 0; // Default == 0
    std::uint32_t room      = 0; // Default == 0
};

enum class eMapEventType : std::uint32_t 
{ 
    eventTypeNone         = 0, // None
    eventTypeWarp         = 1, // Warp to map
    eventTypeEntitySet    = 2, // Set entity state
    eventTypeEntityToggle = 3, // Toggle entity state
    eventTypeEntitySpawn  = 4  // Spawn entity
};

struct sMapEvent
{
    eMapEventType type      = eMapEventType::eventTypeNone;
    std::uint32_t tile      = 0; // The tile that triggers the event
    std::uint32_t data_1    = 0;
    std::uint32_t data_2    = 0;
    std::uint32_t data_3    = 0;
    bool          triggered = false;
};

struct sMapPortal
{
    std::uint32_t portalNo  = 0;
    std::uint32_t tile      = 0;
    float32       direction = 0.0f;
};

enum class eMapRoomType : std::uint16_t 
{ 
    roomTypeNone         =  0, // None / empty
    roomTypeCell         =  1, // Prison Cell
    roomTypeSecret       =  2, // Secret room
    roomTypeStairwell    =  3, // Stairwell
    roomTypeStore        =  4, // Store
    roomTypeBlacksmith   =  5, // Blacksmith
    roomTypeCanteen      =  6, // Canteen
    roomTypeStorage      =  7, // Storage room
    roomTypeLibrary      =  8, // Library
    roomTypeAlchemyLab   =  9, // Alchemy Lab
    roomTypeLaboratory   = 10, // Laboratory
    roomTypeTorture      = 11  // Torture Chamber
};

struct sMapRoom
{
    eMapRoomType type    =  eMapRoomType::roomTypeNone;
    bool         p       =  false; // processed flag
    uint16_t     posXMin =  0;
    uint16_t     posXMax =  0;
    uint16_t     posYMin =  0;
    uint16_t     posYMax =  0;
    uint16_t     x       =  0; // x position
    uint16_t     y       =  0; // y position
    uint16_t     w       =  0; // room width
    uint16_t     h       =  0; // room height
    int16_t      exitN   = -1; // -1 for none, else connecting room ID
    int16_t      exitS   = -1; // -1 for none, else connecting room ID
    int16_t      exitE   = -1; // -1 for none, else connecting room ID
    int16_t      exitW   = -1; // -1 for none, else connecting room ID
};

struct sMap
{
    // Linked list
    sMap*          next              = nullptr;
    std::uint32_t  UID               = 0;

    // Infomation
    std::string    name              = "";
    std::string    fileName          = "";

    // Player start information
    std::uint32_t  playerStartPortal = 0;
    std::uint32_t  playerStartTile   = 0;
    float          playerStartDir    = 0.0f;

    // Entity to hold the floor
    sEntity*       floor             = nullptr;

    // Tile
    std::uint32_t  width             = 0;
    std::uint32_t  height            = 0;
    std::uint32_t  numTiles          = 0;
    sMapTile*      tile              = nullptr;

    // PCG
    sMapGenData    genData           = {};

    // Biome
    sMapBiome*     biome             = nullptr;
    
    // Map events
    std::uint32_t  eventCount        = 0;
    sMapEvent*     event             = nullptr;
    
    // Map portals
    std::uint32_t  portalCount       = 0;
    sMapPortal*    portal            = nullptr;

    // Map Rooms
    std::uint32_t  roomCount         = 0;
    sMapRoom*      room              = nullptr;
};


struct sMapPrefab
{
    // Tile
    std::uint32_t  width             = 0;
    std::uint32_t  height            = 0;
    std::uint32_t  numTiles          = 0;
    sMapTile*      tile              = nullptr;

    // Map events
    std::uint32_t  eventCount        = 0;
    sMapEvent*     event             = nullptr;
    
    // Map portals
    std::uint32_t  portalCount       = 0;
    sMapPortal*    portal            = nullptr;
};

#endif //MAP_DEFINE_HPP

