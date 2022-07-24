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

#include "map_path_a_star.hpp"

/// static bool _pathAStileOK(sMap*& _map, std::uint32_t _tile)
static bool _pathAStileOK(sMap*& _map, std::uint32_t _tile, const bool &_flying, const bool &_overSize)
{

    // check tile object
    if (_map->tile[_tile].entity.type != eTileEntityType::tileEntityNone)
        return false;

    // check tile data
    if (_flying)
    {
        if (!((_map->tile[_tile].type == eTileType::tileFloor) ||
              (_map->tile[_tile].type == eTileType::tileDoorway) ||
              (_map->tile[_tile].type == eTileType::tilePath) ||
              (_map->tile[_tile].type == eTileType::tileWallShort)))
        {
            return false;
        }
    }
    else if (_overSize)
    {
        if (!((_map->tile[_tile].type == eTileType::tileFloor) ||
              (_map->tile[_tile].type == eTileType::tilePath)))
        {
            return false;
        }
    }
    else
    {
        if (!((_map->tile[_tile].type == eTileType::tileFloor) ||
              (_map->tile[_tile].type == eTileType::tileDoorway) ||
              (_map->tile[_tile].type == eTileType::tilePath)))
        {
            return false;
        }
    }

    // All checks passed
    return true;
}

/// static void _pathAScalcTile(sMap*& _map, sMapPath& _path, sASTileData*& _pathData, std::uint32_t _p, std::uint32_t _t)
static void _pathAScalcTile(sMap*& _map, sMapPath& _path, sASTileData*& _pathData, std::uint32_t _p, std::uint32_t _t)
{
    // Determine diagonal cost based on neighboring tiles
    std::uint32_t diagCost = AS_MOV_D;
    bool diagmove = ((_pathData[_t].x != _pathData[_p].x) && (_pathData[_t].y != _pathData[_p].y));
/*
    if (diagmove)
    {
        // check horizontal move
        if ((_pathData[_t].x < _pathData[_p].x) && (_pathData[_t].y < _pathData[_p].y))
            diagCost = (_pathAStileOK(_map, _p - 1) && _pathAStileOK(_map, _p - _map->info.size_x)) ? AS_MOV_D : AS_MOV_F;
        if ((_pathData[_t].x > _pathData[_p].x) && (_pathData[_t].y < _pathData[_p].y))
            diagCost = (_pathAStileOK(_map, _p + 1) && _pathAStileOK(_map, _p - _map->info.size_x)) ? AS_MOV_D : AS_MOV_F;
        if ((_pathData[_t].x < _pathData[_p].x) && (_pathData[_t].y > _pathData[_p].y))
            diagCost = (_pathAStileOK(_map, _p - 1) && _pathAStileOK(_map, _p + _map->info.size_x)) ? AS_MOV_D : AS_MOV_F;
        if ((_pathData[_t].x < _pathData[_p].x) && (_pathData[_t].y > _pathData[_p].y))
            diagCost = (_pathAStileOK(_map, _p + 1) && _pathAStileOK(_map, _p + _map->info.size_x)) ? AS_MOV_D : AS_MOV_F;
    }
*/
    if (_pathData[_t].l == ePathData::pathClosed)
        return;
    if (_pathData[_t].a == ePathData::pathStart)
        return;
    if (_pathData[_t].l == ePathData::pathOpen)
    {
        std::uint32_t newG = (diagmove ? diagCost : AS_MOV_S);
        if ((_pathData[_p].g + _pathData[_t].g) >= (_pathData[_p].g + newG))
            return;
    }

    std::uint32_t ex = _path.destinationTile % _map->info.size_x;
    std::uint32_t ey = _path.destinationTile / _map->info.size_x;

    _pathData[_t].p = _p;
    _pathData[_t].l = ePathData::pathOpen;

    _pathData[_t].h = (abs(static_cast<std::int32_t>(_pathData[_t].x) - static_cast<std::int32_t>(ex)) +
                       abs(static_cast<std::int32_t>(_pathData[_t].y) - static_cast<std::int32_t>(ey))) * AS_MOV_H;
    _pathData[_t].g = _pathData[_p].g + (diagmove ? diagCost : AS_MOV_S);
    _pathData[_t].f = _pathData[_t].h + _pathData[_t].g;
}

/// static bool _pathASinternal(sMap*& _map, sMapPath& _path, sASTileData*& _pathData, std::uint32_t _p, std::uint32_t _t)
    // _p  "parent tile"
    // _t  "target tile"
    // "tile" could be a std::int32_t and we could check if tile is < 0 too....
    // However tile 0 is always a wall tile and cannot be pathed to. ;)
static bool _pathASinternal(sMap*& _map, sMapPath& _path, sASTileData*& _pathData, std::uint32_t _p, std::uint32_t _t)
{
    if (_pathData[_t].a == ePathData::pathEnd)
    {
        _pathData[_t].p = _p;
        return true;
    }
    if (_pathData[_t].l == ePathData::pathOpen)
        _pathData[_t].l = ePathData::pathClosed;
    std::int32_t tile = _t + 1;
    if (tile < static_cast<std::int32_t>(_map->numTiles))
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    tile = _t - 1;
    if (tile > 0)
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    tile = _t + _map->info.size_x;
    if (tile < static_cast<std::int32_t>(_map->numTiles))
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    tile = _t - _map->info.size_x;
    if (tile > 0)
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    tile = _t + _map->info.size_x + 1;
    if (tile < static_cast<std::int32_t>(_map->numTiles))
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    tile = _t + _map->info.size_x - 1;
    if (tile < static_cast<std::int32_t>(_map->numTiles))
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    tile = _t - _map->info.size_x + 1;
    if (tile > 0)
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    tile = _t - _map->info.size_x - 1;
    if (tile > 0)
        _pathAScalcTile(_map, _path, _pathData, _t, tile);
    std::uint32_t nextTileF = UINT32_MAX;
    std::uint32_t nextTile  = 0;
    bool nextFound = false;
    for (uint32_t i = 0; i < _map->numTiles; i++)
    {
        if ((_pathData[i].l == ePathData::pathOpen) && (_pathData[i].f < nextTileF))
        {
            nextTileF = _pathData[i].f;
            nextTile  = i;
            nextFound = true;
        }
    }
    if (nextFound)
        return _pathASinternal(_map, _path, _pathData, _t, nextTile);
    return false;
}

/// void gAStar(sMap*& _map, sMapPath& _path)
void gAStar(sMap*& _map, sMapPath& _path, const bool &_flying, const bool &_overSize)
{
    // Don't proceed if there is no map data
    if (_map == nullptr)
    {
        return;
    }

    // Player clicked out of map bounds
    if (_path.destinationTile > _map->numTiles)
    {
        _path.pathLength = 0;
        return;
    }

    // Set up
    _path.pathLength = 0;
    if (_path.path != nullptr)
    {
        delete [] _path.path;
        _path.path = nullptr;
    }

    sASTileData* pathData = new sASTileData[_map->numTiles];
    for (std::uint32_t i = 0; i < _map->info.size_y; i++)
    {
        for (std::uint32_t j = 0; j < _map->info.size_x; j++)
        {
            std::uint32_t tile = (i * _map->info.size_x) + j;
            pathData[tile].x = j;
            pathData[tile].y = i;
            pathData[tile].l = (_pathAStileOK(_map, tile, _flying, _overSize)) ? ePathData::pathNone : ePathData::pathClosed;
            pathData[tile].a = ePathData::pathNone;
        }
    }
    pathData[_path.currentTile].a = ePathData::pathStart;
    pathData[_path.currentTile].l = ePathData::pathClosed;
    pathData[_path.currentTile].h = 0;
    pathData[_path.currentTile].g = 0;
    pathData[_path.currentTile].f = 0;
    pathData[_path.currentTile].p = _path.currentTile;
    pathData[_path.destinationTile].a = ePathData::pathEnd;

    // Process
    _path.pathLength = 0;
    if (!_pathASinternal(_map, _path, pathData, _path.currentTile, _path.currentTile))
    {
        // No path found, cleanup and return
        delete [] pathData;
        return;
    }

    //build path data
    std::uint32_t pathPosition = _path.destinationTile;
    while (pathPosition != _path.currentTile)
    {
        pathPosition = pathData[pathPosition].p;
        _path.pathLength++;
    }
    _path.path = new std::uint32_t[_path.pathLength + 2];
    _path.path[_path.pathLength + 1] = _path.destinationTile;
    pathPosition = _path.destinationTile;
    std::uint32_t i = _path.pathLength + 1;
    while (pathPosition != _path.currentTile)
    {
        _path.path[--i] = pathPosition;
        pathPosition = pathData[pathPosition].p;
    }
    _path.path[0] = _path.currentTile;
    _path.pathLength++;

    // Clean up
    delete [] pathData;
}


