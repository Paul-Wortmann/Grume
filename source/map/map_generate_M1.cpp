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

static void m_genM1_maze(sMap*& _map, const std::uint32_t &_tile)
{
    std::uint16_t tileCount = 4;
    std::uint16_t loopCount = 0; // exit instead of getting stuck in the loop
    while (tileCount > 0)
    {
        tileCount = 0;
        std::uint32_t next_tile =_tile - _map->width;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        next_tile =_tile + _map->width;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        next_tile =_tile - 1;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        next_tile =_tile + 1;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        loopCount++;
        if (loopCount > (_map->genData.pass * _map->genData.directionBiasStrength))
            tileCount = 0;
        std::uint32_t randBase = 25;
        eDirectionBias direction = _map->genData.directionBias;
        std::uint32_t directionRand = (direction == eDirectionBias::directionNone) ? (rand() % (randBase * 4)) :  (rand() % (randBase * (4 + _map->genData.directionBiasStrength)));
        if (directionRand < randBase)
            direction = eDirectionBias::directionNorth;
        if ((directionRand > (randBase * 1)) && (directionRand < (randBase * 2)))
            direction = eDirectionBias::directionSouth;
        if ((directionRand > (randBase * 2)) && (directionRand < (randBase * 3)))
            direction = eDirectionBias::directionEast;
        if ((directionRand > (randBase * 3)) && (directionRand < (randBase * 4)))
            direction = eDirectionBias::directionWest;
        if (_map->genData.directionBias != eDirectionBias::directionNone)
            _map->genData.directionBias = direction;
        next_tile =_tile - _map->width;
        if ((direction == eDirectionBias::directionNorth) && (next_tile > 0) && (next_tile < _map->numTiles))
        {
            if (!_map->tile[next_tile].processed)
            {
                if ((!_map->tile[next_tile + 1].processed) && (!_map->tile[next_tile - 1].processed))
                {
                    if ((_map->tile[next_tile - _map->width].base == eTileBase::tileWall) && (_map->tile[next_tile - _map->width + 1].base == eTileBase::tileWall) && (_map->tile[next_tile - _map->width - 1].base == eTileBase::tileWall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].base = eTileBase::tileFloor;
                        m_genM1_maze(_map, (next_tile));
                    }
                }
            }
        }
        next_tile =_tile + _map->width;
        if ((direction == eDirectionBias::directionSouth) && (next_tile > 0) && (next_tile < _map->numTiles))
        {
            if (!_map->tile[next_tile].processed)
            {
                if ((!_map->tile[next_tile + 1].processed) && (!_map->tile[next_tile - 1].processed))
                {
                    if ((_map->tile[next_tile + _map->width].base == eTileBase::tileWall) && (_map->tile[next_tile + _map->width + 1].base == eTileBase::tileWall) && (_map->tile[next_tile + _map->width - 1].base == eTileBase::tileWall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].base = eTileBase::tileFloor;
                        m_genM1_maze(_map, (next_tile));
                    }
                }
            }
        }
        next_tile =_tile - 1;
        if ((direction == eDirectionBias::directionEast) && (next_tile > 0) && (next_tile < _map->numTiles))
        {
            if (!_map->tile[next_tile].processed)
            {
                if ((!_map->tile[next_tile + _map->width].processed) && (!_map->tile[next_tile - _map->width].processed))
                {
                    if ((_map->tile[next_tile - _map->width].base == eTileBase::tileWall) && (_map->tile[next_tile - 1 + _map->width].base == eTileBase::tileWall) && (_map->tile[next_tile - 1 - _map->width].base == eTileBase::tileWall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].base = eTileBase::tileFloor;
                        m_genM1_maze(_map, (next_tile));
                    }
                }
            }
        }
        next_tile =_tile + 1;
        if ((direction == eDirectionBias::directionWest) && (next_tile > 0) && (next_tile < _map->numTiles))
        {
            if (!_map->tile[next_tile].processed)
            {
                if ((!_map->tile[next_tile + _map->width].processed) && (!_map->tile[next_tile - _map->width].processed))
                {
                    if ((_map->tile[next_tile - _map->width].base == eTileBase::tileWall) && (_map->tile[next_tile + 1 + _map->width].base == eTileBase::tileWall) && (_map->tile[next_tile + 1 - _map->width].base == eTileBase::tileWall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].base = eTileBase::tileFloor;
                        m_genM1_maze(_map, (next_tile));
                    }
                }
            }
        }
    }
}

void cMapManager::m_genM1_internal(sMap*& _map)
{

    // map preparation
    eRoomShape roomShape = _map->genData.roomShape;
    std::uint16_t roomCount = 0;
    for (std::uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].base      = eTileBase::tileWall;
        _map->tile[i].processed = false;
    }

    // add rooms
    for (std::uint32_t i = 0; i < _map->genData.roomMax; i++)
    {
        if (roomCount < _map->genData.roomMin)
        {
            std::uint32_t r = (rand() % (_map->genData.roomRadiusMax - _map->genData.roomRadiusMin)) + _map->genData.roomRadiusMin;
            std::int32_t x = (rand() % (_map->width - r - r)) + r;
            std::int32_t y = (rand() % (_map->height - r - r)) + r;
            if ((x > 1) && (x < (std::int32_t)(_map->width-1)) && (y > 1) && (y < (std::int32_t)(_map->height-1)))
            {
                if (_map->genData.roomShape == eRoomShape::shapeRandom)
                {
                    roomShape = ((rand() % 100) < 50) ? eRoomShape::shapeCircle : eRoomShape::shapeSquare;
                }
                if (roomShape == eRoomShape::shapeCircle)
                {
                    if (m_genCircleRoomOK(_map, x, y, r + _map->genData.roomBorder))
                    {
                        m_genCircleRoom(_map, x, y, r);
                        roomCount++;
                    }
                }
                if (roomShape == eRoomShape::shapeSquare)
                {
                    if (m_genSquareRoomOK(_map, x, y, r + _map->genData.roomBorder))
                    {
                        m_genSquareRoom(_map, x, y, r);
                        roomCount++;
                    }
                }
            }
        }
    }
    m_mapInitRooms(_map);
    // set unmodifiable tiles.
    for (std::uint32_t i = 0; i < _map->height; i++)
        for (std::uint32_t j = 0; j < _map->width; j++)
            _map->tile[(i * _map->width) + j].processed = ((i == 0) || (i == (_map->height-1)) || (j == 0) || (j == (_map->width-1)) || (_map->tile[(i * _map->width) + j].base != eTileBase::tileWall));
    // maze.
    std::uint32_t  randBase = 25;
    eDirectionBias direction = _map->genData.directionBias;
    std::uint32_t  directionRand = (direction == eDirectionBias::directionNone) ? (rand() % (randBase * 4)) : (rand() % (randBase * (4 + _map->genData.directionBiasStrength)));
    if (directionRand < randBase)
        direction = eDirectionBias::directionNorth;
    if ((directionRand > (randBase * 1)) && (directionRand < (randBase * 2)))
        direction = eDirectionBias::directionSouth;
    if ((directionRand > (randBase * 2)) && (directionRand < (randBase * 3)))
        direction = eDirectionBias::directionEast;
    if ((directionRand > (randBase * 3)) && (directionRand < (randBase * 4)))
        direction = eDirectionBias::directionWest;
    if (_map->genData.directionBias != eDirectionBias::directionNone)
        _map->genData.directionBias = direction;
    std::uint32_t startX = _map->width / 2;
    std::uint32_t startY = _map->height / 2;
    if (direction == eDirectionBias::directionNorth)
        startY = 1;
    if (direction == eDirectionBias::directionSouth)
        startY = _map->height - 2;
    if (direction == eDirectionBias::directionEast)
        startX = 1;
    if (direction == eDirectionBias::directionWest)
        startX = _map->width - 2;
    std::uint32_t nextTile = (startY * _map->width) + startX;
    _map->tile[nextTile].base = eTileBase::tileFloor;
    _map->tile[nextTile].processed = true;
    m_genM1_maze(_map, nextTile);
    // connect rooms
    for (std::uint32_t i = 0; i < _map->roomCount; i++)
    {
        std::uint16_t deltaX = std::abs (static_cast<std::int16_t>((_map->width / 2) - _map->room[i].x));
        std::uint16_t deltaY = std::abs (static_cast<std::int16_t>((_map->height / 2) - _map->room[i].y));
        direction = (deltaX > deltaY) ? ((_map->room[i].x < (_map->width / 2)) ? eDirectionBias::directionWest : eDirectionBias::directionEast) : ((_map->room[i].y < (_map->height / 2)) ? eDirectionBias::directionSouth : eDirectionBias::directionNorth);
        std::uint32_t tile = 0;
        if (direction == eDirectionBias::directionNorth)
        {
            tile = ((_map->room[i].y - ((_map->room[i].h+1) / 2)) * _map->width) + _map->room[i].x;
            _map->tile[tile].base = eTileBase::tileFloor;
            if (_map->tile[tile-_map->width].base == eTileBase::tileWall)
            {
                while (_map->tile[tile-_map->width].base == eTileBase::tileWall)
                {
                    tile -= _map->width;
                    _map->tile[tile].base = eTileBase::tileFloor;
                }
            }
        }
        if (direction == eDirectionBias::directionSouth)
        {
            tile = ((_map->room[i].y + ((_map->room[i].h+3) / 2)) * _map->width) + _map->room[i].x;
            _map->tile[tile].base = eTileBase::tileFloor;
            if (_map->tile[tile+_map->width].base == eTileBase::tileWall)
            {
                while (_map->tile[tile+_map->width].base == eTileBase::tileWall)
                {
                    tile += _map->width;
                    _map->tile[tile].base = eTileBase::tileFloor;
                }
            }
        }
        if (direction == eDirectionBias::directionEast)
        {
            tile = ((_map->room[i].y * _map->width) + _map->room[i].x - ((_map->room[i].w+1) / 2));
            _map->tile[tile].base = eTileBase::tileFloor;
            if (_map->tile[tile-1].base == eTileBase::tileWall)
            {
                while (_map->tile[tile-1].base == eTileBase::tileWall)
                {
                    tile--;
                    _map->tile[tile].base = eTileBase::tileFloor;
                }
            }
        }
        if (direction == eDirectionBias::directionWest)
        {
            tile = ((_map->room[i].y * _map->width) + _map->room[i].x + ((_map->room[i].w+3) / 2));
            _map->tile[tile].base = eTileBase::tileFloor;
            if (_map->tile[tile+1].base == eTileBase::tileWall)
            {
                while (_map->tile[tile+1].base == eTileBase::tileWall)
                {
                    tile++;
                    _map->tile[tile].base = eTileBase::tileFloor;
                }
            }
        }
    }
}

void cMapManager::m_generateMap_M1(sMap*& _map)
{
    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    if (_map->tile != nullptr)
    {
        if (_map->genData.seed != 0)
        {
            srand (_map->genData.seed);
            m_genD2_internal(_map);
        }
        else
        {
            for (std::uint16_t i = 0; i < _map->genData.pass; i++)
            {
                _map->genData.seed = time(nullptr);
                srand (_map->genData.seed);
                m_genM1_internal(_map);
                if ((m_mapGetFloorArea(_map) > (_map->numTiles / _map->genData.floorAreaMin)) && (_map->roomCount >= _map->genData.roomMin))
                {
                    i = _map->genData.pass;
                }
            }
        }
    }
    
    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

    // Smoothing pass to remove artifacts

    // Flood fill, delete rooms that are too small

    // Room identification

    // Room connection

    // Populate the map with objects
    m_generateMap_objects(_map);

    // Populate the map with npcs
    m_generateMap_npcs(_map);
}
