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

#ifndef LIBRMG_DEFINES_HPP
#define LIBRMG_DEFINES_HPP

#include "libRMG_includes.hpp"

#define LIBRMG_NOROOM -1

// Astar path weights
#define LIBRMG_AS_MOV_D  20
#define LIBRMG_AS_MOV_S  10
#define LIBRMG_AS_MOV_H  10

enum eGenerator:uint16_t        { generatorC1 = 0, generatorC2 = 1, generatorD1 = 2, generatorD2 = 3, generatorM1 = 4, generatorT1 = 5 };
enum eLayer:uint16_t            { layerNone = 0, layerBase = 1, layerObject = 2, layerEvent = 3 };
enum eBase:uint16_t             { baseFloor = 0, baseWall = 1, baseDoor = 2, baseLiquid = 3 };
enum eObject:uint16_t           { objectNone = 0, objectAsStart = 1, objectAsEnd = 2, objectAsPath = 3, objectChest = 4, objectKey = 5, objectSwitch = 6, objectStairs = 7, objectTree = 8 };
enum eEvent:uint16_t            { eventNone = 0, eventTrigger = 1, eventTarget = 2, eventPlayerGoal = 3, eventSpawnNPC = 4, eventSpawnMob = 5, eventSpawnBoss = 6, eventSpawnPlayer = 7, eventDoorLock = 8, eventDoorUnlock = 9, eventDoorOpen = 10, eventDoorClose = 11, eventDoorToggle = 12, eventSwitch = 13, eventWarp = 14 };
enum eDirection:uint16_t        { directionNone = 0, directionNorth = 1, directionSouth = 2, directionEast = 3, directionWest = 4 };
enum eRoomFunction:uint16_t     { roomEmpty = 0, roomSecret = 1, roomBridge = 2, roomWell = 3, roomBlacksmith = 4, roomStore = 5,roomWarp = 6, roomBoss = 7 };
enum eRoomShape:uint16_t        { roomShapeRandom = 0, roomShapeCircle = 1, roomShapeSquare = 2 };
enum ePathData:uint16_t         { pathNone = 0, pathStart = 1, pathEnd = 2, pathOpen = 3, pathClosed = 4 };
enum eConnectAlgorithm:uint16_t { connectSL = 0, connectND = 1, connectDW = 2 };
enum eEventState:uint16_t       { eventStateNone = 0, eventStateReady = 1, eventStateTriggered = 2, eventStateTrue = 3, eventStateFalse = 4 };

struct sLibRMGPrefabTile
{
    eBase    base   = eBase::baseFloor;
    uint16_t object = 0; // Object ID
    uint16_t event  = 0; // Event ID
};

struct sLibRMGPrefab
{
    sLibRMGPrefab     *next      = nullptr;
    std::string        filename  = "";
    uint16_t           w         = 0;
    uint16_t           h         = 0;
    uint16_t           size      = 0;
    uint32_t           tileCount = 0;
    sLibRMGPrefabTile *tile      = nullptr;
};

struct sLibRMGMapPath
{
    uint32_t *path    = nullptr; // array of path tile numbers
    uint32_t length   = 0;
    uint32_t position = 0; // current position on path
    uint32_t sx       = 0; //start x
    uint32_t sy       = 0; //start y
    uint32_t ex       = 0; //end x
    uint32_t ey       = 0; //end y
};
    
struct sLibRMGMapObject
{
    uint32_t ID   = 0;
    eObject  type = eObject::objectNone;
};

struct sLibRMGMapEvent
{
    uint32_t         ID               = 0;
    eEvent           type             = eEvent::eventNone;
    sLibRMGMapEvent *next             = nullptr;
    bool             enabled          = false;
    bool             reTriggerable    = true;
    uint16_t        *triggerTileID    = nullptr;
    uint16_t         triggerTileCount = 0;
    uint16_t        *targetTileID     = nullptr;
    uint16_t         targetTileCount  = 0;
    eEventState      state            = eEventState::eventStateNone;
    uint32_t         timer            = 3000; //ms
};

struct sLibRMGMapRoom
{
    eRoomFunction type    = eRoomFunction::roomEmpty;
    bool     p       = false; // processed flag
    uint16_t posXMin = 0;
    uint16_t posXMax = 0;
    uint16_t posYMin = 0;
    uint16_t posYMax = 0;
    uint16_t x       = 0;
    uint16_t y       = 0;
    uint16_t w       = 0;
    uint16_t h       = 0;
    int16_t exitN    = LIBRMG_NOROOM; // -1 for none, else connecting room ID
    int16_t exitS    = LIBRMG_NOROOM;
    int16_t exitE    = LIBRMG_NOROOM;
    int16_t exitW    = LIBRMG_NOROOM;
};

struct sLibRMGMapTile
{
    eBase     base     = eBase::baseFloor;
    uint32_t  objectID = 0;
    uint32_t  eventID  = 0;
    uint32_t  roomID   = 0;
    
    // internal processing
    uint32_t  x        = 0;
    uint32_t  y        = 0;
    bool      c        = false; // completed flag
    uint32_t  H        = 0; // Heuristic cost
    uint32_t  G        = 0; // Movement cost
    uint32_t  F        = 0; // Total cost
    ePathData A        = ePathData::pathNone; // Attribute
    ePathData L        = ePathData::pathNone; // List
    uint32_t  P        = 0; // Parent tile
};

struct sLibRMGMapData
{
    std::string       name                   = "libRMG generated map.";
    eGenerator        generator              = eGenerator::generatorC1;
    bool              genSeed                = true;
    uint32_t          seed                   = 0;
    sLibRMGMapObject *object                 = nullptr;
    uint32_t          object_count           = 0;
    sLibRMGMapEvent  *event                  = nullptr;
    uint32_t          event_count            = 0;
    sLibRMGMapRoom   *room                   = nullptr;
    uint32_t          room_count             = 0;
    uint16_t          room_min               = 3; // Guaranteed minimum number of rooms, maps with less are discarded (sMap.pass times)
    uint16_t          room_max               = density; // Will try generate up to roomMax rooms, on a tiny map 
    uint16_t          room_radius_max        = 8; // max room radius
    uint16_t          room_radius_min        = 2; // min room radius
    uint16_t          room_border            = 3;
    eRoomShape        room_shape             = eRoomShape::roomShapeSquare;
    eDirection        direction_bias         = eDirection::directionNone; // Favored direction
    uint16_t          direction_biasStrength = 2; // Favored direction strength
    uint16_t          floor_area_min         = 50; // percentage, min % floor area
    sLibRMGMapTile   *tile                   = nullptr;
    uint32_t          tile_x                 = 10;
    uint32_t          tile_y                 = 10;
    uint32_t          tile_count             = tile_x * tile_y;
    eConnectAlgorithm connect_algorithm      = eConnectAlgorithm::connectSL;
    uint16_t          connectivity_padding   = 0; // Tiles to pad on each side of generated paths, roomBorder 
    sLibRMGPrefab    *prefab                 = nullptr;
    bool              enablePrefabs          = true;
    std::string       prefabPath             = "data/prefabs";
    uint16_t          prefabCount            = 0;
    uint32_t          density                = 60; // percentage
    uint32_t          maxItterations         = 3;
};

#endif // LIBRMG_DEFINES_HPP

