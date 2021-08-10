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

void cMapManager::m_mapTilesFlipV(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < tileCount; i++)
    {
        _tiles[(tileCount-1)-i] = tile[i];
    }
    delete[] tile;
}

void cMapManager::m_mapTilesFlipH(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < _h; i++)
    {
        for (uint32_t j = 0; j < _w; j++)
        {
            _tiles[(i * _w) + j] = tile[(i * _w) + ((_w-1)-j)];
        }
    }
    delete[] tile;
}

void cMapManager::m_mapTilesRotate90(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < _h; i++)
    {
        for (uint32_t j = 0; j < _w; j++)
        {
            _tiles[(i * _w) + j] = tile[(j * _w) + ((_w-1)-i)];
        }
    }
    delete[] tile;
}

void cMapManager::m_mapTilesRotate270(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < _h; i++)
    {
        for (uint32_t j = 0; j < _w; j++)
        {
            _tiles[(i * _w) + j] = tile[(((_h-1)-j) * _w) + ((_w-1)-i)];
        }
    }
    delete[] tile;
}

void cMapManager::m_mapTilesRotate180(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < tileCount; i++)
    {
        _tiles[(tileCount-1)-i] = tile[i];
    }
    delete[] tile;
}

void cMapManager::m_mapGeneratePerimeterWall(sMap*& _map)
{
    for (uint32 i = 0; i < _map->numTiles; ++i)
    {
        if ((i < _map->width) ||
            (i > (_map->numTiles - _map->width - 1)) ||
            ((i % _map->width) == 0) ||
            ((i % _map->width) == (_map->width - 1)))
        {
            _map->tile[i].base = eTileBase::tileWall;
        }
    }
}

uint32_t cMapManager::m_mapGetFloorMin(sMap*& _map)
{
    if (_map->tile != nullptr)
    {
        for (uint32_t i = 0; i < _map->numTiles; i++)
        {
            if (_map->tile[i].base == eTileBase::tileFloor)
                return i;
        }
    }
    return 0;
}

uint32_t cMapManager::m_mapGetFloorMax(sMap*& _map)
{
    if (_map->tile != nullptr)
    {
        for (uint32_t i = _map->numTiles-_map->width; i > 0; i--)
        {
            if (_map->tile[i].base == eTileBase::tileFloor)
                return i;
        }
    }
    return 0;
}

uint32_t cMapManager::m_mapGetFloorArea(sMap*& _map)
{
    if (_map->tile != nullptr)
    {
        uint32_t tileCount = 0;
        for (uint32_t j = 0; j < _map->numTiles; j++)
        {
            if (_map->tile[j].base == eTileBase::tileFloor)
                tileCount++;
        }
        return tileCount;
    }
    return 0;
}

void cMapManager::m_mapRemoveAnomalies(sMap*& _map)
{
    uint32_t tileT = 0;
    for (uint16_t k = 0; k < _map->genData.pass; k++)
    {
        for (uint16_t i = 1; i < (_map->height - 1); i++)
        {
            for (uint16_t j = 1; j < (_map->width - 1); j++)
            {
                tileT = (i * _map->width) + j;
                if (_map->tile[tileT].base == eTileBase::tileFloor)
                {
                    // Remove single horizontal floor tiles
                    // ???
                    // XOX
                    // ???
                    //--------------------
                    if ((_map->tile[tileT+1].base == eTileBase::tileWall)
                     && (_map->tile[tileT-1].base == eTileBase::tileWall))
                    {
                        _map->tile[tileT+1].base = eTileBase::tileFloor;
                        _map->tile[tileT-1].base = eTileBase::tileFloor;
                        _map->tile[tileT+1].room = _map->tile[tileT].room;
                        _map->tile[tileT-1].room = _map->tile[tileT].room;
                    }
                    // Remove single vertical floor tiles
                    // ?X?
                    // ?O?
                    // ?X?
                    //--------------------
                    if ((_map->tile[tileT+_map->width].base == eTileBase::tileWall)
                     && (_map->tile[tileT-_map->width].base == eTileBase::tileWall))
                    {
                        _map->tile[tileT+_map->width].base = eTileBase::tileFloor;
                        _map->tile[tileT-_map->width].base = eTileBase::tileFloor;
                        _map->tile[tileT+_map->width].room = _map->tile[tileT].room;
                        _map->tile[tileT-_map->width].room = _map->tile[tileT].room;
                    }
                }
                else if (_map->tile[tileT].base == eTileBase::tileWall)
                {
                    // Remove single horizontal wall tiles
                    // ???
                    // OXO
                    // ???
                    //--------------------
                    if ((_map->tile[tileT+1].base == eTileBase::tileFloor)
                     && (_map->tile[tileT-1].base == eTileBase::tileFloor))
                    {
                        _map->tile[tileT].base = eTileBase::tileFloor;
                        _map->tile[tileT].room = _map->tile[tileT+1].room;
                    }
                    // Remove single vertical wall tiles
                    // ?O?
                    // ?X?
                    // ?O?
                    //--------------------
                    if ((_map->tile[tileT+_map->width].base == eTileBase::tileFloor)
                     && (_map->tile[tileT-_map->width].base == eTileBase::tileFloor))
                    {
                        _map->tile[tileT].base = eTileBase::tileFloor;
                        _map->tile[tileT].room = _map->tile[tileT+_map->width].room;
                    }
                    // Remove diagonal right wall tiles
                    // O?X
                    // ?X?
                    // X?O
                    //--------------------
                    if ((_map->tile[tileT+_map->width+1].base == eTileBase::tileWall)
                     && (_map->tile[tileT+_map->width-1].base == eTileBase::tileFloor)
                     && (_map->tile[tileT-_map->width+1].base == eTileBase::tileFloor)
                     && (_map->tile[tileT-_map->width-1].base == eTileBase::tileWall))
                    {
                        _map->tile[tileT+_map->width].base = eTileBase::tileFloor;
                        _map->tile[tileT-_map->width].base = eTileBase::tileFloor;
                        _map->tile[tileT+1].base = eTileBase::tileFloor;
                        _map->tile[tileT-1].base = eTileBase::tileFloor;
                    }
                    // Remove diagonal left wall tiles
                    // X?O
                    // ?X?
                    // O?X
                    //--------------------
                    if ((_map->tile[tileT+_map->width+1].base == eTileBase::tileFloor)
                     && (_map->tile[tileT+_map->width-1].base == eTileBase::tileWall)
                     && (_map->tile[tileT-_map->width+1].base == eTileBase::tileWall)
                     && (_map->tile[tileT-_map->width-1].base == eTileBase::tileFloor))
                    {
                        _map->tile[tileT+_map->width].base = eTileBase::tileFloor;
                        _map->tile[tileT-_map->width].base = eTileBase::tileFloor;
                        _map->tile[tileT+1].base = eTileBase::tileFloor;
                        _map->tile[tileT-1].base = eTileBase::tileFloor;
                    }
                }
            }
        }
    }
}

