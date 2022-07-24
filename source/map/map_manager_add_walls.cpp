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

#include "map_manager.hpp"

bool cMapManager::m_isWallConfig(const std::uint32_t &_tile,
                                 const std::uint32_t &_tile_00, const std::uint32_t &_tile_10, const std::uint32_t &_tile_20,
                                 const std::uint32_t &_tile_01, const std::uint32_t &_tile_11, const std::uint32_t &_tile_21,
                                 const std::uint32_t &_tile_02, const std::uint32_t &_tile_12, const std::uint32_t &_tile_22)
{

    // Tile position
    const std::int32_t tile_x = _tile % m_map->info.size_x;
    const std::int32_t tile_y = _tile / m_map->info.size_x;

    // Flags
    const std::uint32_t floor    = 0;
    const std::uint32_t wall     = 1;
    const std::uint32_t wildCard = 2;

    // Tiles
    // 00 10 20
    // 01 11 21
    // 02 12 22
    std::uint32_t t00 = floor;
    std::uint32_t t10 = floor;
    std::uint32_t t20 = floor;
    std::uint32_t t01 = floor;
    std::uint32_t t11 = floor;
    std::uint32_t t21 = floor;
    std::uint32_t t02 = floor;
    std::uint32_t t12 = floor;
    std::uint32_t t22 = floor;

    /// Tile 00
    t00 = (m_isWall(tile_x - 1, tile_y - 1)) ? wall : floor;
    t00 = (_tile_00 == wildCard) ? _tile_00 : t00;

    /// Tile 10
    t10 = (m_isWall(tile_x, tile_y - 1)) ? wall : floor;
    t10 = (_tile_10 == wildCard) ? _tile_10 : t10;

    /// Tile 20
    t20 = (m_isWall(tile_x + 1, tile_y - 1)) ? wall : floor;
    t20 = (_tile_20 == wildCard) ? _tile_20 : t20;

    /// Tile 01
    t01 = (m_isWall(tile_x - 1, tile_y)) ? wall : floor;
    t01 = (_tile_01 == wildCard) ? _tile_01 : t01;

    /// Tile 11
    t11 = (m_isWall(tile_x, tile_y)) ? wall : floor;
    t11 = (_tile_11 == wildCard) ? _tile_11 : t11;

    /// Tile 21
    t21 = (m_isWall(tile_x + 1, tile_y)) ? wall : floor;
    t21 = (_tile_21 == wildCard) ? _tile_21 : t21;

    /// Tile 02
    t02 = (m_isWall(tile_x - 1, tile_y + 1)) ? wall : floor;
    t02 = (_tile_02 == wildCard) ? _tile_02 : t02;

    /// Tile 12
    t12 = (m_isWall(tile_x, tile_y + 1)) ? wall : floor;
    t12 = (_tile_12 == wildCard) ? _tile_12 : t12;

    /// Tile 22
    t22 = (m_isWall(tile_x + 1, tile_y + 1)) ? wall : floor;
    t22 = (_tile_22 == wildCard) ? _tile_22 : t22;

    // Return result
    return ((t00 == _tile_00) && (t10 == _tile_10) && (t20 == _tile_20) &&
            (t01 == _tile_01) && (t11 == _tile_11) && (t21 == _tile_21) &&
            (t02 == _tile_02) && (t12 == _tile_12) && (t22 == _tile_22));
}

void cMapManager::m_wallTypeOrientation(const std::uint32_t &_tile, eWallType &_type, float &_orientation)
{
    // ******* high single sided roof *******
    // W W W
    // W W W
    // W W W
    if (m_isWallConfig(_tile,
                       1, 1, 1,
                       1, 1, 1,
                       0, 1, 1) ||
         m_isWallConfig(_tile,
                        0, 1, 1,
                        1, 1, 1,
                        1, 1, 1) ||
         m_isWallConfig(_tile,
                        1, 1, 0,
                        1, 1, 1,
                        1, 1, 1) ||
         m_isWallConfig(_tile,
                        1, 1, 1,
                        1, 1, 1,
                        1, 1, 0) ||
         m_isWallConfig(_tile,
                        1, 1, 1,
                        1, 1, 1,
                        1, 1, 1))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleRoof;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleRoof;

        // Orientation
        _orientation = rot000;
    }

    // ******* high single sided corner *******
    // W W ?
    // W W F
    // ? F ?
    else if (m_isWallConfig(_tile,
                            1, 1, 2,
                            1, 1, 0,
                            2, 0, 2) ||
             m_isWallConfig(_tile,
                            1, 1, 2,
                            1, 1, 0,
                            0, 1, 0) ||
             m_isWallConfig(_tile,
                            1, 1, 0,
                            1, 1, 1,
                            0, 1, 0) ||
             m_isWallConfig(_tile,
                            1, 1, 0,
                            1, 1, 1,
                            2, 0, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleCorner;

        // Orientation
        _orientation = rot270;
    }

    // ******* high single sided corner *******
    // ? W W
    // F W W
    // ? F ?
    else if (m_isWallConfig(_tile,
                            2, 1, 1,
                            0, 1, 1,
                            2, 0, 2) ||
             m_isWallConfig(_tile,
                            0, 1, 1,
                            1, 1, 1,
                            0, 0, 2) ||
             m_isWallConfig(_tile,
                            0, 1, 1,
                            1, 1, 1,
                            0, 1, 0) ||
             m_isWallConfig(_tile,
                            2, 1, 1,
                            0, 1, 1,
                            0, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleCorner;

        // Orientation
        _orientation = rot180;
    }

    // ******* high single sided corner *******
    // ? F ?
    // F W W
    // ? W W
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            0, 1, 1,
                            2, 1, 1) ||
             m_isWallConfig(_tile,
                            0, 0, 2,
                            1, 1, 1,
                            0, 1, 1) ||
             m_isWallConfig(_tile,
                            0, 1, 0,
                            1, 1, 1,
                            0, 1, 1) ||
             m_isWallConfig(_tile,
                            0, 1, 0,
                            0, 1, 1,
                            2, 1, 1))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleCorner;

        // Orientation
        _orientation = rot090;
    }

    // ******* high single sided corner *******
    // ? F ?
    // W W F
    // W W ?
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            1, 1, 0,
                            1, 1, 2) ||
             m_isWallConfig(_tile,
                            2, 0, 0,
                            1, 1, 1,
                            1, 1, 0) ||
             m_isWallConfig(_tile,
                            0, 1, 0,
                            1, 1, 1,
                            1, 1, 0) ||
             m_isWallConfig(_tile,
                            0, 1, 0,
                            1, 1, 0,
                            1, 1, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleCorner;

        // Orientation
        _orientation = rot000;
    }

    // ******* high single sided wall *******
    // W W W
    // W W W
    // ? F ?
    else if (m_isWallConfig(_tile,
                            1, 1, 1,
                            1, 1, 1,
                            2, 0, 2) ||
             m_isWallConfig(_tile,
                            1, 1, 1,
                            1, 1, 1,
                            0, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleStraight;

        // Orientation
        _orientation = rot180;
    }

    // ******* high single sided wall *******
    // ? W W
    // F W W
    // ? W W
    else if (m_isWallConfig(_tile,
                            2, 1, 1,
                            0, 1, 1,
                            2, 1, 1) ||
             m_isWallConfig(_tile,
                            0, 1, 1,
                            1, 1, 1,
                            0, 1, 1))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleStraight;

        // Orientation
        _orientation = rot090;
    }

    // ******* high single sided wall *******
    // ? F ?
    // W W W
    // W W W
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            1, 1, 1,
                            1, 1, 1) ||
             m_isWallConfig(_tile,
                            0, 1, 0,
                            1, 1, 1,
                            1, 1, 1))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleStraight;

        // Orientation
        _orientation = rot000;
    }

    // ******* high single sided wall *******
    // W W ?
    // W W F
    // W W ?
    else if (m_isWallConfig(_tile,
                            1, 1, 2,
                            1, 1, 0,
                            1, 1, 2) ||
             m_isWallConfig(_tile,
                            1, 1, 0,
                            1, 1, 1,
                            1, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeHighSingleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighSingleStraight;

        // Orientation
        _orientation = rot270;
    }

    // ******* high double sided pillar *******
    // ? F ?
    // F W F
    // ? F ?
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            0, 1, 0,
                            2, 0, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoublePillar;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoublePillar;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleXJunction;

        // Orientation
        _orientation = rot000;
    }
    // ******* high double sided x-junction *******
    // F W F
    // W W W
    // F W F
    else if (m_isWallConfig(_tile,
                            0, 1, 0,
                            1, 1, 1,
                            0, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleXJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleXJunction;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleXJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleXJunction;

        // Orientation
        _orientation = rot000;
    }
    // ******* high double sided end *******
    // ? F ?
    // W W F
    // ? F ?
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            1, 1, 0,
                            2, 0, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleEnd;

        // Orientation
        _orientation = rot000;
    }
    // ? F ?
    // F W W
    // ? F ?
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            0, 1, 1,
                            2, 0, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleEnd;

        // Orientation
        _orientation = rot180;
    }
    // ? W ?
    // F W F
    // ? F ?
    else if (m_isWallConfig(_tile,
                            2, 1, 2,
                            0, 1, 0,
                            2, 0, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleEnd;

        // Orientation
        _orientation = rot270;
    }
    // ? F ?
    // F W F
    // ? W ?
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            0, 1, 0,
                            2, 1, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleEnd;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleEnd;

        // Orientation
        _orientation = rot090;
    }

    // ******* high double sided corner *******
    // F F ?
    // W W F
    // F W F
    else if (m_isWallConfig(_tile,
                            0, 0, 2,
                            1, 1, 0,
                            0, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleCorner;

        // Orientation
        _orientation = rot000;
    }
    // F W F
    // F W W
    // ? F F
    else if (m_isWallConfig(_tile,
                            0, 1, 0,
                            0, 1, 1,
                            2, 0, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleCorner;

        // Orientation
        _orientation = rot180;
    }
    // ? F F
    // F W W
    // F W F
    else if (m_isWallConfig(_tile,
                            2, 0, 0,
                            0, 1, 1,
                            0, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleCorner;

        // Orientation
        _orientation = rot090;
    }
    // F W F
    // W W F
    // F F ?
    else if (m_isWallConfig(_tile,
                            0, 1, 0,
                            1, 1, 0,
                            0, 0, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleCorner;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleCorner;

        // Orientation
        _orientation = rot270;
    }

    // ******* high double sided wall *******
    // ? F ?
    // W W W
    // ? F ?
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            1, 1, 1,
                            2, 0, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleStraight;

        // Orientation
        _orientation = rot000;
    }
    // ? W ?
    // F W F
    // ? W ?
    else if (m_isWallConfig(_tile,
                            2, 1, 2,
                            0, 1, 0,
                            2, 1, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleStraight;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleStraight;

        // Orientation
        _orientation = rot090;
    }
    // ******* high double sided t-junction *******
    // ? F ?
    // W W W
    // F W F
    else if (m_isWallConfig(_tile,
                            2, 0, 2,
                            1, 1, 1,
                            0, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleTJunction;

        // Orientation
        _orientation = rot000;
    }
    // ? W F
    // F W W
    // ? W F
    else if (m_isWallConfig(_tile,
                            2, 1, 0,
                            0, 1, 1,
                            2, 1, 0))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleTJunction;

        // Orientation
        _orientation = rot090;
    }
    // F W F
    // W W W
    // ? F ?
    else if (m_isWallConfig(_tile,
                            0, 1, 0,
                            1, 1, 1,
                            2, 0, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleTJunction;

        // Orientation
        _orientation = rot180;
    }
    // F W ?
    // W W F
    // F W ?
    else if (m_isWallConfig(_tile,
                            0, 1, 2,
                            1, 1, 0,
                            0, 1, 2))
    {
        // Type
        if (m_map->tile[_tile].type == eTileType::tileWallShort)
            _type = eWallType::wallTypeLowDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTall)
            _type = eWallType::wallTypeHighDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileDoorway)
            _type = eWallType::wallTypeDoorwayDoubleTJunction;
        else if (m_map->tile[_tile].type == eTileType::tileWallTallHole)
            _type = eWallType::wallTypeHoleDoubleTJunction;

        // Orientation
        _orientation = rot270;
    }
}

void cMapManager::m_addWalls(void)
{
    sEntity*      tEntity        = nullptr;
    eWallType     wallType       = eWallType::wallTypeNone;
    float         orientation    = 0.0f;

    // Load the biome file
    std::string biomeFileName = m_databaseManager->getDatabaseEntryFileName(m_map->info.biome, 1, eDatabaseType::databaseTypeBiome);
    cXML biomeFile;
    biomeFile.load(std::string(FILE_PATH_BIOME) + biomeFileName);
    if (!biomeFile.isValid())
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + biomeFileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }

    // Reset processing flags
    for (std::uint32_t i = 0; i < m_map->numTiles; ++i)
    {
        m_map->tile[i].processed = false;
    }

    // Iterate over the data and add tiles accordingly
    for (std::uint32_t z = 0; z < m_map->info.size_y; ++z)
    {
        for (std::uint32_t x = 0; x < m_map->info.size_x; ++x)
        {
            tEntity     = nullptr;
            orientation = 0.0f;
            std::uint32_t tile = (z * m_map->info.size_x) + x;
            if ((m_map->tile[tile].processed == false) && (m_isWall(x, z)))
            {
                // Determine wall type
                m_wallTypeOrientation(tile, wallType, orientation);

                // Single sided high walls
                if (wallType == eWallType::wallTypeHighSingleStraight)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_single_sided_wall>"));
                }
                else if (wallType == eWallType::wallTypeHighSingleCorner)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_single_sided_corner>"));
                }
                else if (wallType == eWallType::wallTypeHighSingleRoof)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_single_sided_roof>"));
                }

                // High walls
                else if (wallType == eWallType::wallTypeHighDoubleStraight)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_double_sided_wall>"));
                }
                else if (wallType == eWallType::wallTypeHighDoubleEnd)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_double_sided_end>"));
                }
                else if (wallType == eWallType::wallTypeHighDoubleCorner)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_double_sided_corner>"));
                }
                else if (wallType == eWallType::wallTypeHighDoublePillar)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_double_sided_pillar>"));
                }
                else if (wallType == eWallType::wallTypeHighDoubleXJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_double_sided_x-junction>"));
                }
                else if (wallType == eWallType::wallTypeHighDoubleTJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<high_wall_double_sided_t-junction>"));
                }

                // Hole walls
                else if (wallType == eWallType::wallTypeHoleDoubleStraight)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<hole_wall_double_sided_wall>"));
                }
                else if (wallType == eWallType::wallTypeHoleDoubleEnd)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<hole_wall_double_sided_end>"));
                }
                else if (wallType == eWallType::wallTypeHoleDoubleCorner)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<hole_wall_double_sided_corner>"));
                }
                else if (wallType == eWallType::wallTypeHoleDoublePillar)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<hole_wall_double_sided_pillar>"));
                }
                else if (wallType == eWallType::wallTypeHoleDoubleXJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<hole_wall_double_sided_x-junction>"));
                }
                else if (wallType == eWallType::wallTypeHoleDoubleTJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<hole_wall_double_sided_t-junction>"));
                }

                // Low walls
                if (wallType == eWallType::wallTypeLowDoubleStraight)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<low_wall_double_sided_wall>"));
                }
                else if (wallType == eWallType::wallTypeLowDoubleEnd)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<low_wall_double_sided_end>"));
                }
                else if (wallType == eWallType::wallTypeLowDoubleCorner)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<low_wall_double_sided_corner>"));
                }
                else if (wallType == eWallType::wallTypeLowDoublePillar)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<low_wall_double_sided_pillar>"));
                }
                else if (wallType == eWallType::wallTypeLowDoubleXJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<low_wall_double_sided_x-junction>"));
                }
                else if (wallType == eWallType::wallTypeLowDoubleTJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<low_wall_double_sided_t-junction>"));
                }

                // Doorway walls
                if (wallType == eWallType::wallTypeDoorwayDoubleStraight)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<doorway_wall_double_sided_wall>"));
                }
                else if (wallType == eWallType::wallTypeDoorwayDoubleEnd)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<doorway_wall_double_sided_end>"));
                }
                else if (wallType == eWallType::wallTypeDoorwayDoubleCorner)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<doorway_wall_double_sided_corner>"));
                }
                else if (wallType == eWallType::wallTypeDoorwayDoubleXJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<doorway_wall_double_sided_x-junction>"));
                }
                else if (wallType == eWallType::wallTypeDoorwayDoubleTJunction)
                {
                    tEntity = m_entityManager->load(biomeFile.getString("<doorway_wall_double_sided_t-junction>"));
                }
            }

            if (tEntity != nullptr)
            {
                glm::vec3 tilePosition = gMapTileToPosition(m_map, tile);
                tEntity->base.position.x += tilePosition.x;
                tEntity->base.position.y += m_map->info.terrainHeight;
                tEntity->base.position.z += tilePosition.z;
                tEntity->base.rotation.y += orientation;
                tEntity->base.tileOnMap = tile;
                m_map->tile[tEntity->base.tileOnMap].processed = true;
                m_entityManager->updateModelMatrix(tEntity);
                tEntity->base.owner    = eEntityOwner::entityOwner_map;

                if (m_map->tile[tile].type == eTileType::tileWallShort)
                    tEntity->base.type = eEntityType::entityType_wallLow;
                else if (m_map->tile[tile].type == eTileType::tileWallTallHole)
                    tEntity->base.type = eEntityType::entityType_wallHole;
                else if (m_map->tile[tile].type == eTileType::tileWallTall)
                    tEntity->base.type = eEntityType::entityType_wallHigh;
                else if (m_map->tile[tile].type == eTileType::tileDoorway)
                    tEntity->base.type = eEntityType::entityType_wallHigh;
            }
        }
    }

    // Cleanup
    biomeFile.free();
}
