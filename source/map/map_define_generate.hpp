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

#ifndef MAP_DEFINE_GENERATE_HPP
#define MAP_DEFINE_GENERATE_HPP

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

#endif // MAP_DEFINE_GENERATE_HPP
