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

 #include "map_utils.hpp"

void gSetTileCollision(sMap*& _map, const std::uint32_t &_tile, const bool &_state)
{
    if (_state == true)
    {
        // Set tiles impassable
        if (_map->tile[_tile].type == eTileType::tileFloor)
            _map->tile[_tile].type = eTileType::tileFloorNoGo;
        else if (_map->tile[_tile].type == eTileType::tilePath)
            _map->tile[_tile].type = eTileType::tilePathNoGo;
        else if (_map->tile[_tile].type == eTileType::tileDoorway)
            _map->tile[_tile].type = eTileType::tileDoorwayNoGo;
    }
    else
    {
        // Set tiles passable
        if (_map->tile[_tile].type == eTileType::tileFloorNoGo)
            _map->tile[_tile].type = eTileType::tileFloor;
        else if (_map->tile[_tile].type == eTileType::tilePathNoGo)
            _map->tile[_tile].type = eTileType::tilePath;
        else if (_map->tile[_tile].type == eTileType::tileDoorwayNoGo)
            _map->tile[_tile].type = eTileType::tileDoorway;
    }
}

std::uint32_t gMapPositionToTile(sMap*& _map, const glm::vec3 &_position)
{
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(_map->info.size_x) / 2.0f;
    float zo = static_cast<float>(_map->info.size_y) / 2.0f;

    std::uint32_t x = static_cast<std::uint32_t>(_position.x + xo);
    std::uint32_t z = static_cast<std::uint32_t>(_position.z + zo);
    return (z * _map->info.size_x) + x;
}

glm::vec3 gMapTileToPosition(sMap*& _map, const std::uint32_t &_tile)
{
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(_map->info.size_x) / 2.0f;
    float zo = static_cast<float>(_map->info.size_y) / 2.0f;

    float x = static_cast<float>(_tile % _map->info.size_x) - xo;
    float z = static_cast<float>(_tile / _map->info.size_x) - zo;
    return glm::vec3(x, _map->info.terrainHeight, z);
}

std::uint32_t gDistanceTiles(sMap*& _map, const std::uint32_t &_tile1, const std::uint32_t &_tile2)
{
    std::uint32_t t1x = _tile1 % _map->info.size_x;
    std::uint32_t t1y = _tile1 / _map->info.size_x;
    std::uint32_t t2x = _tile2 % _map->info.size_x;
    std::uint32_t t2y = _tile2 / _map->info.size_x;

    std::uint32_t dx = (t1x > t2x) ? t1x - t2x : t2x - t1x;
    std::uint32_t dy = (t1y > t2y) ? t1y - t2y : t2y - t1y;

    return dx + dy;
}

std::uint32_t gIsClearTile(sMap*& _map, const std::uint32_t &_tile)
{
    return ((_map->tile[_tile].entity.type == eTileEntityType::tileEntityNone) &&
           ((_map->tile[_tile].type == eTileType::tileFloor) ||
            (_map->tile[_tile].type == eTileType::tilePath)));
}

std::uint32_t gClosestFreeTile(sMap*& _map, const std::uint32_t &_sTile, const std::uint32_t &_dTile)
{
    // If _dTile is out of bounds return _sTile
    if ((_dTile < _map->info.size_x - 1) ||
        (_dTile > _map->info.size_x * (_map->info.size_y - 1)))
    {
        return _sTile;
    }

    // First check destination tile
    if (gIsClearTile(_map, _dTile))
    {
        return _dTile;
    }
    else
    {
        std::uint32_t closetTile     = _dTile;
        std::uint32_t closetDistance = UINT32_MAX;
        std::uint32_t tDistance      = {};
        std::uint32_t tTile          = {};

        tTile = _dTile + 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile - 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile + _map->info.size_x;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile + _map->info.size_x + 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile + _map->info.size_x - 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile - _map->info.size_x;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile - _map->info.size_x + 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile - _map->info.size_x - 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        return closetTile;
    }

    // If no free tile is found, return the original tile.
    return _dTile;
}

std::uint32_t gClosestFreeTile(sMap*& _map, const std::uint32_t &_tile)
{
    // First try to use the position provided
    if (gIsClearTile(_map, _tile))
    {
        return _tile;
    }
    else
    {
        // Initial tile position
        std::uint32_t tile_x = _tile % _map->info.size_x;
        std::uint32_t tile_y = _tile / _map->info.size_x;

        // Max iterations
        std::uint32_t iterations = (_map->info.size_x > _map->info.size_y) ? _map->info.size_x : _map->info.size_y;

        // Second try random placement
        std::uint32_t radius = 1;
        for (std::uint32_t i = 0; i < iterations; ++i)
        {
            std::uint32_t rand_x = (rand() % (radius * 2) - radius) + tile_x + 1;
            std::uint32_t rand_y = (rand() % (radius * 2) - radius) + tile_y + 1;

            if (rand_x > _map->info.size_x - 2)
                rand_x = _map->info.size_x - 2;
            if (rand_y > _map->info.size_y - 2)
                rand_y = _map->info.size_y - 2;

            std::uint32_t tTile = (rand_y * _map->info.size_x) + rand_x;
            if (gIsClearTile(_map, tTile))
                return tTile;

            radius++;
        }

        // Third a very iterative approach
        for (std::uint32_t radius = 1; radius < iterations; ++radius)
        {
            std::uint32_t tile_xStart = tile_x - radius;
            std::uint32_t tile_yStart = tile_y - radius;
            std::uint32_t tile_xEnd = ((tile_x + radius) > _map->info.size_x) ? _map->info.size_x : (tile_x + radius);
            std::uint32_t tile_yEnd = ((tile_y + radius) > _map->info.size_y) ? _map->info.size_y : (tile_y + radius);
            for (std::uint32_t y = tile_yStart; y < tile_yEnd; ++y)
            {
                for (std::uint32_t x = tile_xStart; x < tile_xEnd; ++x)
                {
                    std::uint32_t tTile = (y * _map->info.size_x) + x;
                    if (gIsClearTile(_map, tTile))
                        return tTile;
                }
            }
        }
    }

    // If no free tile is found, return the original tile.
    return _tile;
}
