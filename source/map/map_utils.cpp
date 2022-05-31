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

std::uint32_t gMapPositionToTile(sMap*& _map, const glm::vec3 &_position)
{
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(_map->width) / 2.0f;
    float zo = static_cast<float>(_map->height) / 2.0f;

    std::uint32_t x = static_cast<std::uint32_t>(_position.x + xo);
    std::uint32_t z = static_cast<std::uint32_t>(_position.z + zo);
    return (z * _map->width) + x;
}

glm::vec3 gMapTileToPosition(sMap*& _map, const std::uint32_t &_tile)
{
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(_map->width) / 2.0f;
    float zo = static_cast<float>(_map->height) / 2.0f;

    float x = static_cast<float>(_tile % _map->width) - xo;
    float z = static_cast<float>(_tile / _map->width) - zo;
    return glm::vec3(x, _map->terrainHeight, z);
}

std::uint32_t gDistanceTiles(sMap*& _map, const std::uint32_t &_tile1, const std::uint32_t &_tile2)
{
    std::uint32_t t1x = _tile1 % _map->width;
    std::uint32_t t1y = _tile1 / _map->width;
    std::uint32_t t2x = _tile2 % _map->width;
    std::uint32_t t2y = _tile2 / _map->width;

    std::uint32_t dx = (t1x > t2x) ? t1x - t2x : t2x - t1x;
    std::uint32_t dy = (t1y > t2y) ? t1y - t2y : t2y - t1y;

    return dx + dy;
}

std::uint32_t gIsClearTile(sMap*& _map, const std::uint32_t &_tile)
{
    return ((_map->tile[_tile].npc == 0) &&
           ((_map->tile[_tile].base == eTileBase::tileFloor) ||
            (_map->tile[_tile].base == eTileBase::tileFloorPath)));
}

std::uint32_t gClosestFreeTile(sMap*& _map, const std::uint32_t &_sTile, const std::uint32_t &_dTile)
{
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

        tTile = _dTile + _map->width;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile + _map->width + 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile + _map->width - 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile - _map->width;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile - _map->width + 1;
        tDistance = gDistanceTiles(_map, _sTile, tTile);
        if ((tDistance < closetDistance) && (gIsClearTile(_map, tTile)))
        {
            closetDistance = tDistance;
            closetTile = tTile;
        }

        tTile = _dTile - _map->width - 1;
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
        std::uint32_t tile_x = _tile % _map->width;
        std::uint32_t tile_y = _tile / _map->width;

        // Max iterations
        std::uint32_t iterations = (_map->width > _map->height) ? _map->width : _map->height;

        // Second try random placement
        std::uint32_t radius = 1;
        for (std::uint32_t i = 0; i < iterations; ++i)
        {
            std::uint32_t rand_x = (rand() % (radius * 2) - radius) + tile_x + 1;
            std::uint32_t rand_y = (rand() % (radius * 2) - radius) + tile_y + 1;

            if (rand_x > _map->width - 2)
                rand_x = _map->width - 2;
            if (rand_y > _map->height - 2)
                rand_y = _map->height - 2;

            std::uint32_t tTile = (rand_y * _map->width) + rand_x;
            if (gIsClearTile(_map, tTile))
                return tTile;

            radius++;
        }

        // Third a very iterative approach
        for (std::uint32_t radius = 1; radius < iterations; ++radius)
        {
            std::uint32_t tile_xStart = tile_x - radius;
            std::uint32_t tile_yStart = tile_y - radius;
            std::uint32_t tile_xEnd = ((tile_x + radius) > _map->width) ? _map->width : (tile_x + radius);
            std::uint32_t tile_yEnd = ((tile_y + radius) > _map->height) ? _map->height : (tile_y + radius);
            for (std::uint32_t y = tile_yStart; y < tile_yEnd; ++y)
            {
                for (std::uint32_t x = tile_xStart; x < tile_xEnd; ++x)
                {
                    std::uint32_t tTile = (y * _map->width) + x;
                    if (gIsClearTile(_map, tTile))
                        return tTile;
                }
            }
        }
    }

    // If no free tile is found, return the original tile.
    return _tile;
}
