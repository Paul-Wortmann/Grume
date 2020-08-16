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

#include "libRMG_pathing.hpp"

void _libRMG_pathASFree(sLibRMGMapPath &_path)
{
    if (_path.path != nullptr)
    {
        delete[] _path.path;
        _path.path = nullptr;
    }
}

static void _libRMG_pathAScalcTile(sLibRMGMapData &_data, sLibRMGMapPath &_path, uint32_t _p, uint32_t _t)
{
    if (_data.tile[_t].L == ePathData::pathClosed)
        return;
    if (_data.tile[_t].A == ePathData::pathStart)
        return;
    if (_data.tile[_t].L == ePathData::pathOpen)
    {
        uint32_t newG = (((_data.tile[_t].x == _data.tile[_p].x) || (_data.tile[_t].y == _data.tile[_p].y)) ? LIBRMG_AS_MOV_S : LIBRMG_AS_MOV_D);
        if ((_data.tile[_p].G + _data.tile[_t].G) >= (_data.tile[_p].G + newG))
            return;
    }
    _data.tile[_t].P = _p;
    _data.tile[_t].L = ePathData::pathOpen;
    _data.tile[_t].H = (abs(_data.tile[_t].x - _path.ex) + abs(_data.tile[_t].y - _path.ey)) * LIBRMG_AS_MOV_H;
    _data.tile[_t].G = _data.tile[_p].G + (((_data.tile[_t].x == _data.tile[_p].x) || (_data.tile[_t].y == _data.tile[_p].y)) ? LIBRMG_AS_MOV_S : LIBRMG_AS_MOV_D);
    _data.tile[_t].F = _data.tile[_t].H + _data.tile[_t].G;
}

static bool _libRMG_pathASinternal(sLibRMGMapData &_data, sLibRMGMapPath &_path, uint32_t _p, uint32_t _t)
{
    uint32_t tile = _t;
    if (_data.tile[_t].A == ePathData::pathEnd)
    {
        _data.tile[_t].P = _p;
        return true;
    }
    if (_data.tile[_t].L == ePathData::pathOpen)
        _data.tile[_t].L = ePathData::pathClosed;
    tile = _t + 1;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    tile = _t - 1;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    tile = _t + _data.tile_x;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    tile = _t - _data.tile_x;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    tile = _t + _data.tile_x + 1;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    tile = _t + _data.tile_x - 1;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    tile = _t - _data.tile_x + 1;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    tile = _t - _data.tile_x - 1;
    if (tile < _data.tile_count)
        _libRMG_pathAScalcTile(_data, _path, _t, tile);
    uint32_t nextTileF = UINT32_MAX;
    uint32_t nextTile  = 0;
    bool     nextFound = false;
    for (uint32_t i = 0; i < _data.tile_count; i++)
    {
        if ((_data.tile[i].L == ePathData::pathOpen) && (_data.tile[i].F < nextTileF))
        {
            nextTileF = _data.tile[i].F;
            nextTile = i;
            nextFound = true;
        }
    }
    if (nextFound)
        return _libRMG_pathASinternal(_data, _path, _t, nextTile);
    return false;
}

bool _libRMG_pathAS(sLibRMGMapData &_data, sLibRMGMapPath &_path)
{
    for (uint32_t i = 0; i < _data.tile_y; i++)
    {
        for (uint32_t j = 0; j < _data.tile_x; j++)
        {
            uint32_t tile = (i * _data.tile_x) + j;
            _data.tile[tile].x = j;
            _data.tile[tile].y = i;
            _data.tile[tile].L = (_data.tile[tile].base == eBase::baseWall) ? ePathData::pathClosed : ePathData::pathNone;
            _data.tile[tile].A = ePathData::pathNone;
        }
    }
    uint32_t st = (_path.sy * _data.tile_x) + _path.sx;
    uint32_t et = (_path.ey * _data.tile_x) + _path.ex;
    _data.tile[st].A = ePathData::pathStart;
    _data.tile[st].L = ePathData::pathClosed;
    _data.tile[et].A = ePathData::pathEnd;
    _data.tile[st].H = 0;
    _data.tile[st].G = 0;
    _data.tile[st].F = 0;
    _data.tile[st].P = st;
    if (!_libRMG_pathASinternal(_data, _path, st, st))
        return false;
    _path.length = 0;
    //build path data
    uint32_t pathPosition = et;
    while (pathPosition != st)
    {
        pathPosition = _data.tile[pathPosition].P;
        _path.length++;
    }
    _path.path = new uint32_t[_path.length];
    pathPosition = et;
    uint32_t i = _path.length;
    while (pathPosition != st)
    {
        _path.path[--i] = pathPosition;
        pathPosition = _data.tile[pathPosition].P;
    }
    return true;
}
