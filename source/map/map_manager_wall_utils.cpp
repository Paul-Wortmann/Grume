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

bool cMapManager::m_isFloor(const std::int32_t &_tile_x, const std::int32_t &_tile_y)
{
    // Tile check out of map bounds
    if ((_tile_x < 0) || (_tile_y < 0) || (_tile_x > (static_cast<std::int32_t>(m_map->info.size_x) - 1)) || (_tile_y > (static_cast<std::int32_t>(m_map->info.size_y) - 1)))
        return false;

    // Calculate tile number
    const std::uint32_t tile = (m_map->info.size_x * _tile_y) + _tile_x;

    // None tile data
    if (m_map->tile[tile].type == eTileType::tileNone)
        return false;

    // Check tile type
    return ((m_map->tile[tile].type == eTileType::tileFloor) ||
            (m_map->tile[tile].type == eTileType::tileFloorNoGo) ||
            (m_map->tile[tile].type == eTileType::tileDoorway) ||
            (m_map->tile[tile].type == eTileType::tileDoorwayNoGo));
}

bool cMapManager::m_isPath(const std::int32_t &_tile_x, const std::int32_t &_tile_y)
{
    // Tile check out of map bounds
    if ((_tile_x < 0) || (_tile_y < 0) || (_tile_x > (static_cast<std::int32_t>(m_map->info.size_x) - 1)) || (_tile_y > (static_cast<std::int32_t>(m_map->info.size_y) - 1)))
        return false;

    // Calculate tile number
    const std::uint32_t tile = (m_map->info.size_x * _tile_y) + _tile_x;

    // None tile data
    if (m_map->tile[tile].type == eTileType::tileNone)
        return false;

    // Check tile type
    return ((m_map->tile[tile].type == eTileType::tilePath) ||
            (m_map->tile[tile].type == eTileType::tilePathNoGo));
}

bool cMapManager::m_isDoorway(const std::int32_t &_tile_x, const std::int32_t &_tile_y)
{
    // Tile check out of map bounds
    if ((_tile_x < 0) || (_tile_y < 0) || (_tile_x > (static_cast<std::int32_t>(m_map->info.size_x) - 1)) || (_tile_y > (static_cast<std::int32_t>(m_map->info.size_y) - 1)))
        return false;

    // Calculate tile number
    const std::uint32_t tile = (m_map->info.size_x * _tile_y) + _tile_x;

    // None tile data
    if (m_map->tile[tile].type == eTileType::tileNone)
        return false;

    // Check tile type
    return ((m_map->tile[tile].type == eTileType::tileDoorway) ||
            (m_map->tile[tile].type == eTileType::tileDoorwayNoGo));
}

bool cMapManager::m_isWall(const std::int32_t &_tile_x, const std::int32_t &_tile_y)
{
    // Tile check out of map bounds
    if ((_tile_x < 0) || (_tile_y < 0) || (_tile_x > (static_cast<std::int32_t>(m_map->info.size_x) - 1)) || (_tile_y > (static_cast<std::int32_t>(m_map->info.size_y) - 1)))
        return false;

    // Calculate tile number
    const std::uint32_t tile = (m_map->info.size_x * _tile_y) + _tile_x;

    // None tile data
    if (m_map->tile[tile].type == eTileType::tileNone)
        return false;

    // Check tile type
    return ((m_map->tile[tile].type == eTileType::tileWallShort) ||
            (m_map->tile[tile].type == eTileType::tileWallTall) ||
            (m_map->tile[tile].type == eTileType::tileWallTallHole) ||
            (m_map->tile[tile].type == eTileType::tileDoorway) ||
            (m_map->tile[tile].type == eTileType::tileDoorwayNoGo));
}

bool cMapManager::m_isFullWall(const std::int32_t &_tile_x, const std::int32_t &_tile_y)
{
    // Tile check out of map bounds
    if ((_tile_x < 0) || (_tile_y < 0) || (_tile_x > (static_cast<std::int32_t>(m_map->info.size_x) - 1)) || (_tile_y > (static_cast<std::int32_t>(m_map->info.size_y) - 1)))
        return false;

    // Calculate tile number
    const std::uint32_t tile = (m_map->info.size_x * _tile_y) + _tile_x;

    // None tile data
    if (m_map->tile[tile].type == eTileType::tileNone)
        return false;

    // Check tile type
    return (m_map->tile[tile].type == eTileType::tileWallTall);
}

bool cMapManager::m_isSolidWall(const std::int32_t &_tile_x, const std::int32_t &_tile_y)
{
    // Tile check out of map bounds
    if ((_tile_x < 0) || (_tile_y < 0) || (_tile_x > (static_cast<std::int32_t>(m_map->info.size_x) - 1)) || (_tile_y > (static_cast<std::int32_t>(m_map->info.size_y) - 1)))
        return false;

    // Calculate tile number
    const std::uint32_t tile = (m_map->info.size_x * _tile_y) + _tile_x;

    // None tile data
    if (m_map->tile[tile].type == eTileType::tileNone)
        return false;

    // Check tile type
    return ((m_map->tile[tile].type == eTileType::tileWallShort) ||
            (m_map->tile[tile].type == eTileType::tileWallTall) ||
            (m_map->tile[tile].type == eTileType::tileWallTallHole));
}
