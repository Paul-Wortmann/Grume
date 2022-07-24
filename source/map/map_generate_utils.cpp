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
    for (std::uint32_t i = 0; i < _map->numTiles; ++i)
    {
        if ((i < _map->info.size_x) ||
            (i > (_map->numTiles - _map->info.size_x - 1)) ||
            ((i % _map->info.size_x) == 0) ||
            ((i % _map->info.size_x) == (_map->info.size_x - 1)))
        {
            _map->tile[i].type = eTileType::tileWallTall;
        }
    }
}

uint32_t cMapManager::m_mapGetFloorMin(sMap*& _map)
{
    if (_map->tile != nullptr)
    {
        for (uint32_t i = 0; i < _map->numTiles; i++)
        {
            if (_map->tile[i].type == eTileType::tileFloor)
                return i;
        }
    }
    return 0;
}

uint32_t cMapManager::m_mapGetFloorMax(sMap*& _map)
{
    if (_map->tile != nullptr)
    {
        for (uint32_t i = _map->numTiles-_map->info.size_x; i > 0; i--)
        {
            if (_map->tile[i].type == eTileType::tileFloor)
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
            if (_map->tile[j].type == eTileType::tileFloor)
                tileCount++;
        }
        return tileCount;
    }
    return 0;
}

void cMapManager::m_mapRemoveAnomalies(sMap*& _map)
{
    for (uint16_t p = 0; p < _map->generate->pass; p++)
    {
        for (uint16_t y = 1; y < (_map->info.size_y - 1); y++)
        {
            for (uint16_t x = 1; x < (_map->info.size_x - 1); x++)
            {
                uint32_t tileT = (y * _map->info.size_x) + x;

                if (_map->tile[tileT].type == eTileType::tileFloor)
                {
                    // Remove single horizontal floor tiles
                    // ???
                    // XOX
                    // ???
                    //--------------------
                    if ((_map->tile[tileT+1].type == eTileType::tileWallTall)
                     && (_map->tile[tileT-1].type == eTileType::tileWallTall))
                    {
                        _map->tile[tileT+1].type = eTileType::tileFloor;
                        _map->tile[tileT-1].type = eTileType::tileFloor;
                        _map->tile[tileT+1].room = _map->tile[tileT].room;
                        _map->tile[tileT-1].room = _map->tile[tileT].room;
                    }
                    // Remove single vertical floor tiles
                    // ?X?
                    // ?O?
                    // ?X?
                    //--------------------
                    if ((_map->tile[tileT+_map->info.size_x].type == eTileType::tileWallTall)
                     && (_map->tile[tileT-_map->info.size_x].type == eTileType::tileWallTall))
                    {
                        _map->tile[tileT+_map->info.size_x].type = eTileType::tileFloor;
                        _map->tile[tileT-_map->info.size_x].type = eTileType::tileFloor;
                        _map->tile[tileT+_map->info.size_x].room = _map->tile[tileT].room;
                        _map->tile[tileT-_map->info.size_x].room = _map->tile[tileT].room;
                    }
                }
                else if (_map->tile[tileT].type == eTileType::tileWallTall)
                {
                    // Remove single horizontal wall tiles
                    // ???
                    // OXO
                    // ???
                    //--------------------
                    if ((_map->tile[tileT+1].type == eTileType::tileFloor)
                     && (_map->tile[tileT-1].type == eTileType::tileFloor))
                    {
                        _map->tile[tileT].type = eTileType::tileFloor;
                        _map->tile[tileT].room = _map->tile[tileT+1].room;
                    }
                    // Remove single vertical wall tiles
                    // ?O?
                    // ?X?
                    // ?O?
                    //--------------------
                    if ((_map->tile[tileT+_map->info.size_x].type == eTileType::tileFloor)
                     && (_map->tile[tileT-_map->info.size_x].type == eTileType::tileFloor))
                    {
                        _map->tile[tileT].type = eTileType::tileFloor;
                        _map->tile[tileT].room = _map->tile[tileT+_map->info.size_x].room;
                    }
                    // Remove diagonal right wall tiles
                    // O?X
                    // ?X?
                    // X?O
                    //--------------------
                    if ((_map->tile[tileT+_map->info.size_x+1].type == eTileType::tileWallTall)
                     && (_map->tile[tileT+_map->info.size_x-1].type == eTileType::tileFloor)
                     && (_map->tile[tileT-_map->info.size_x+1].type == eTileType::tileFloor)
                     && (_map->tile[tileT-_map->info.size_x-1].type == eTileType::tileWallTall))
                    {
                        _map->tile[tileT+_map->info.size_x].type = eTileType::tileFloor;
                        _map->tile[tileT-_map->info.size_x].type = eTileType::tileFloor;
                        _map->tile[tileT+1].type = eTileType::tileFloor;
                        _map->tile[tileT-1].type = eTileType::tileFloor;
                    }
                    // Remove diagonal left wall tiles
                    // X?O
                    // ?X?
                    // O?X
                    //--------------------
                    if ((_map->tile[tileT+_map->info.size_x+1].type == eTileType::tileFloor)
                     && (_map->tile[tileT+_map->info.size_x-1].type == eTileType::tileWallTall)
                     && (_map->tile[tileT-_map->info.size_x+1].type == eTileType::tileWallTall)
                     && (_map->tile[tileT-_map->info.size_x-1].type == eTileType::tileFloor))
                    {
                        _map->tile[tileT+_map->info.size_x].type = eTileType::tileFloor;
                        _map->tile[tileT-_map->info.size_x].type = eTileType::tileFloor;
                        _map->tile[tileT+1].type = eTileType::tileFloor;
                        _map->tile[tileT-1].type = eTileType::tileFloor;
                    }
                }
            }
        }
    }
}

std::uint32_t cMapManager::m_mapGetFootprintCount(sMap*& _map, sEntity*& _entity)
{
    // Footprint count
    std::uint32_t footPrintCount = 0;

    // Early exit if no data
    if ((_map == nullptr) || (_map->tile == nullptr) ||
        (_entity == nullptr) || (_entity->footprint == nullptr) || (_entity->footprint->data == nullptr))
    {
        return footPrintCount;// footPrintCount == 0
    }

    // loop through the map tile by tile
    std::uint32_t size_x  = _map->info.size_x - _entity->footprint->size_x;
    std::uint32_t size_y  = _map->info.size_y - _entity->footprint->size_y;
    for (std::uint32_t my = 0; my < size_y; ++my)
    {
        for (std::uint32_t mx = 0; mx < size_x; ++mx)
        {
            bool footprintFound = true;

            // Loop through the footprint data tile by tile
            for (std::uint32_t fy = 0; fy < _entity->footprint->size_y; ++fy)
            {
                for (std::uint32_t fx = 0; fx < _entity->footprint->size_x; ++fx)
                {
                    std::uint32_t mapTile = static_cast<std::uint32_t>(_map->tile[((my + fy) * _map->info.size_x) + mx + fx].type);
                    if (mapTile != _entity->footprint->data[(fy * _entity->footprint->size_x) + fx])
                    {
                        footprintFound = false;
                    }
                }
            }
            if (footprintFound)
            {
                footPrintCount++;
            }
        }
    }
    return footPrintCount;
}

bool cMapManager::m_mapGetFootprint(sMap*& _map, sEntity*& _entity, const std::uint32_t &_num, std::uint32_t &_x, std::uint32_t &_y)
{
    // Early exit if no data
    if ((_map == nullptr) || (_map->tile == nullptr) ||
        (_entity == nullptr) || (_entity->footprint == nullptr) || (_entity->footprint->data == nullptr))
    {
        return false;
    }

    // loop through the map tile by tile
    std::uint32_t size_x  = _map->info.size_x - _entity->footprint->size_x;
    std::uint32_t size_y  = _map->info.size_y - _entity->footprint->size_y;
    std::uint32_t footPrintCount = 0;
    for (std::uint32_t my = 0; my < size_y; ++my)
    {
        for (std::uint32_t mx = 0; mx < size_x; ++mx)
        {
            bool footprintFound = true;

            // Loop through the footprint data tile by tile
            for (std::uint32_t fy = 0; fy < _entity->footprint->size_y; ++fy)
            {
                for (std::uint32_t fx = 0; fx < _entity->footprint->size_x; ++fx)
                {
                    std::uint32_t mapTile = static_cast<std::uint32_t>(_map->tile[((my + fy) * _map->info.size_x) + mx + fx].type);
                    if (mapTile != _entity->footprint->data[(fy * _entity->footprint->size_x) + fx])
                    {
                        footprintFound = false;
                    }
                }
            }
            if (footprintFound)
            {
                footPrintCount++;
                if (_num == footPrintCount)
                {
                    _x = mx;
                    _y = my;
                    return true;
                }
            }
        }
    }
    return false;
}
