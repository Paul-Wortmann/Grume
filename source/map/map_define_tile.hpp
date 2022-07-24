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

#ifndef MAP_DEFINE_TILE_HPP
#define MAP_DEFINE_TILE_HPP

#include "../core/includes.hpp"


enum class eWallType : std::uint16_t
{
    // None
    wallTypeNone                   =  0, // None

    // High double sided
    wallTypeHighDoubleStraight     =  1, // High Double sided straight wall
    wallTypeHighDoubleEnd          =  2, // High Double sided straight wall end
    wallTypeHighDoubleCorner       =  3, // High Double sided straight wall corner
    wallTypeHighDoublePillar       =  4, // High Double sided straight wall pillar
    wallTypeHighDoubleXJunction    =  5, // High Double sided straight wall x-junction
    wallTypeHighDoubleTJunction    =  6, // High Double sided straight wall t-junction

    // Hole double sided
    wallTypeHoleDoubleStraight     =  7, // Hole Double sided straight wall
    wallTypeHoleDoubleEnd          =  8, // Hole Double sided straight wall end
    wallTypeHoleDoubleCorner       =  9, // Hole Double sided straight wall corner
    wallTypeHoleDoublePillar       = 10, // Hole Double sided straight wall pillar
    wallTypeHoleDoubleXJunction    = 11, // Hole Double sided straight wall x-junction
    wallTypeHoleDoubleTJunction    = 12, // Hole Double sided straight wall t-junction

    // Low double sided
    wallTypeLowDoubleStraight      = 13, // Low Double sided straight wall
    wallTypeLowDoubleEnd           = 14, // Low Double sided straight wall end
    wallTypeLowDoubleCorner        = 15, // Low Double sided straight wall corner
    wallTypeLowDoublePillar        = 16, // Low Double sided straight wall pillar
    wallTypeLowDoubleXJunction     = 17, // Low Double sided straight wall x-junction
    wallTypeLowDoubleTJunction     = 18, // Low Double sided straight wall t-junction

    // Doorway double sided
    wallTypeDoorwayDoubleStraight  = 19, // Doorway Double sided straight wall
    wallTypeDoorwayDoubleEnd       = 20, // Doorway Double sided straight wall end
    wallTypeDoorwayDoubleCorner    = 21, // Doorway Double sided straight wall corner
    wallTypeDoorwayDoublePillar    = 22, // Doorway Double sided straight wall pillar
    wallTypeDoorwayDoubleXJunction = 23, // Doorway Double sided straight wall x-junction
    wallTypeDoorwayDoubleTJunction = 24, // Doorway Double sided straight wall t-junction

    // High single sided
    wallTypeHighSingleStraight     = 25, // Hight Single sided straight wall
    wallTypeHighSingleCorner       = 26, // Hight Single sided straight corner
    wallTypeHighSingleRoof         = 27  // Hight Single sided straight roof

};

enum class eFloorType : std::uint16_t
{
    floorTypeNone              =  0, // None
    floorTypeFull              =  1, // Floor tile: full
};

enum class ePathType : std::uint16_t
{
    pathTypeNone                =  0,  // None
    pathTypeCorner              =  1,  // Path tile: corner
    pathTypeDouble              =  2,  // Path tile: double sided
    pathTypeFour                =  3,  // Path tile: four sided
    pathTypeMain                =  4,  // Path tile: main
    pathTypeSingle              =  5,  // Path tile: single
    pathTypeTriple              =  6,  // Path tile: triple
    pathTypeInnerCornerSingle   =  7,  // Path tile: inner corner single
    pathTypeInnerCornerDouble   =  8,  // Path tile: inner corner double
    pathTypeInnerCornerOpposite =  9,  // Path tile: inner corner opposite
    pathTypeInnerCornerTriple   =  10, // Path tile: inner corner triple
    pathTypeInnerCornerQuad     =  11  // Path tile: inner corner quad
};

enum class eTileType : std::uint16_t
{
    tileNone           =  0, // None
    tileFloor          =  1, // Floor tile
    tilePath           =  2, // Path tile
    tileFloorNoGo      =  3, // Floor no go tile
    tilePathNoGo       =  4, // Path no go tile
    tileWallTall       =  5, // Wall tall tile
    tileWallTallHole   =  6, // Wall tall tile - hole
    tileWallShort      =  7, // Wall short tile
    tileDoorway        =  8, // Doorway tile
    tileDoorwayNoGo    =  9  // Doorway no go tile
};

enum class eTileEntityType : std::uint16_t
{
    tileEntityNone             = 0, // None
    tileEntityNPC              = 1, // NPC
    tileEntityPlayer           = 2, // Player
    tileEntityObjectStatic     = 3, // Object static
    tileEntityObjectDynamic    = 4, // Object dynamic
    tileEntityObjectStaticLow  = 4, // Object static Low
    tileEntityObjectDynamicLow = 5  // Object dynamic Low
};

struct sMapTileEntity
{
    eTileEntityType type      = eTileEntityType::tileEntityNone; // Default == eTileBase::tileNone
    std::uint32_t   UID       = 0;                               // Default == 0
};

struct sMapTile
{
    std::uint32_t  processed = 0;                   // Default == 0
    eTileType      type      = eTileType::tileNone; // Default == eTileBase::tileNone
    sMapTileEntity entity    = {};                  // Default == {}
    std::uint32_t  room      = 0;                   // Default == 0
};

#endif // MAP_DEFINE_TILE_HPP




