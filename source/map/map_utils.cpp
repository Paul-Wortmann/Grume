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

std::uint32_t gClosestFreeTile(sMap*& _map, const std::uint32_t &_sTile, const std::uint32_t &_dTile)
{
    // First check destination tile
    if (_map->tile[_dTile].npc != 0)
        return (_dTile);

    std::uint32_t closetTile     = _dTile;
    std::uint32_t closetDistance = UINT32_MAX;
    std::uint32_t tDistance = {};
    std::uint32_t tTile     = {};

    tTile = _dTile + 1;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    tTile = _dTile - 1;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    tTile = _dTile + _map->width;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    tTile = _dTile + _map->width + 1;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    tTile = _dTile + _map->width - 1;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    tTile = _dTile - _map->width;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    tTile = _dTile - _map->width + 1;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    tTile = _dTile - _map->width - 1;
    tDistance = gDistanceTiles(_map, _sTile, tTile);
    if (tDistance < closetDistance)
    {
        closetDistance = tDistance;
        closetTile = tTile;
    }

    return closetTile;
}
