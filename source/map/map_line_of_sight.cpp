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

#include "map_line_of_sight.hpp"

bool _isObstacle(sMap*& _map, const std::uint32_t& _x, const std::uint32_t& _y)
{
    std::uint32_t tile = (_y * _map->info.size_x) + _x;

    return (_map->tile[tile].type == eTileType::tileWallTall);

    if ((_map->tile[tile].type == eTileType::tileFloor))// ||
        //(_map->tile[tile].type == eTileType::tileDoorway) ||
        //(_map->tile[tile].type == eTileType::tilePath))
    {
        return false;
    }
    return true;
}

/// bool gLineOfSight(sMap*& _map, const std::uint32_t& _x1, const std::uint32_t& _y1, const std::uint32_t& _x2, const std::uint32_t& _y2)
bool gLineOfSight(sMap*& _map, const std::uint32_t& _x1, const std::uint32_t& _y1, const std::uint32_t& _x2, const std::uint32_t& _y2)
{
    // Calculate distance
    std::uint32_t distance = std::abs(static_cast<std::int32_t>(_x1 - _x2)) + std::abs(static_cast<std::int32_t>(_y1 - _y2));

    // Double to avoid sparse interpolation
    distance = distance * 2;

    // If distance = 0 return early
    if (distance < 0)
    {
        return true;
    }

    // Check for collisions
    for (std::uint32_t i = 0; i < distance; ++i)
    {
        // interpolate between (x1,y1) and (x2,y2)
        float dt = float(i) / distance;

        // at t=0.0 we get (x1,y1); at t=1.0 we get (x2,y2)
        std::uint32_t x = std::uint32_t(_x2 * (1.0 - dt) + _x1 * dt);
        std::uint32_t y = std::uint32_t(_y2 * (1.0 - dt) + _y1 * dt);

        // now check tile (x,y)
        if (_isObstacle(_map, x, y))
        {
            return false;
        }
    }
    return true;
}

bool gLineOfSight(sMap*& _map, const std::uint32_t& _t1, const std::uint32_t& _t2)
{
    return gLineOfSight(_map, _t1 % _map->info.size_x, _t1 / _map->info.size_x, _t2 % _map->info.size_x, _t2 / _map->info.size_x);
}
