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
        std::uint32_t next_tile =_tile - _map->info.size_x;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        next_tile =_tile + _map->info.size_x;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        next_tile =_tile - 1;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        next_tile =_tile + 1;
        if (!_map->tile[next_tile].processed)
            tileCount++;
        loopCount++;
        if (loopCount > (_map->generate->pass * _map->generate->directionBiasStrength))
            tileCount = 0;
        std::uint32_t randBase = 25;
        eDirectionBias direction = _map->generate->directionBias;
        std::uint32_t directionRand = (direction == eDirectionBias::directionNone) ? (rand() % (randBase * 4)) :  (rand() % (randBase * (4 + _map->generate->directionBiasStrength)));
        if (directionRand < randBase)
            direction = eDirectionBias::directionNorth;
        if ((directionRand > (randBase * 1)) && (directionRand < (randBase * 2)))
            direction = eDirectionBias::directionSouth;
        if ((directionRand > (randBase * 2)) && (directionRand < (randBase * 3)))
            direction = eDirectionBias::directionEast;
        if ((directionRand > (randBase * 3)) && (directionRand < (randBase * 4)))
            direction = eDirectionBias::directionWest;
        if (_map->generate->directionBias != eDirectionBias::directionNone)
            _map->generate->directionBias = direction;
        next_tile =_tile - _map->info.size_x;
        if ((direction == eDirectionBias::directionNorth) && (next_tile > 0) && (next_tile < _map->numTiles))
        {
            if (!_map->tile[next_tile].processed)
            {
                if ((!_map->tile[next_tile + 1].processed) && (!_map->tile[next_tile - 1].processed))
                {
                    if ((_map->tile[next_tile - _map->info.size_x].type == eTileType::tileWallTall) && (_map->tile[next_tile - _map->info.size_x + 1].type == eTileType::tileWallTall) && (_map->tile[next_tile - _map->info.size_x - 1].type == eTileType::tileWallTall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].type = eTileType::tileFloor;
                        m_genM1_maze(_map, (next_tile));
                    }
                }
            }
        }
        next_tile =_tile + _map->info.size_x;
        if ((direction == eDirectionBias::directionSouth) && (next_tile > 0) && (next_tile < _map->numTiles))
        {
            if (!_map->tile[next_tile].processed)
            {
                if ((!_map->tile[next_tile + 1].processed) && (!_map->tile[next_tile - 1].processed))
                {
                    if ((_map->tile[next_tile + _map->info.size_x].type == eTileType::tileWallTall) && (_map->tile[next_tile + _map->info.size_x + 1].type == eTileType::tileWallTall) && (_map->tile[next_tile + _map->info.size_x - 1].type == eTileType::tileWallTall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].type = eTileType::tileFloor;
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
                if ((!_map->tile[next_tile + _map->info.size_x].processed) && (!_map->tile[next_tile - _map->info.size_x].processed))
                {
                    if ((_map->tile[next_tile - _map->info.size_x].type == eTileType::tileWallTall) && (_map->tile[next_tile - 1 + _map->info.size_x].type == eTileType::tileWallTall) && (_map->tile[next_tile - 1 - _map->info.size_x].type == eTileType::tileWallTall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].type = eTileType::tileFloor;
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
                if ((!_map->tile[next_tile + _map->info.size_x].processed) && (!_map->tile[next_tile - _map->info.size_x].processed))
                {
                    if ((_map->tile[next_tile - _map->info.size_x].type == eTileType::tileWallTall) && (_map->tile[next_tile + 1 + _map->info.size_x].type == eTileType::tileWallTall) && (_map->tile[next_tile + 1 - _map->info.size_x].type == eTileType::tileWallTall))
                    {
                        _map->tile[next_tile].processed = true;
                        _map->tile[next_tile].type = eTileType::tileFloor;
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
    eRoomShape roomShape = _map->generate->roomShape;
    std::uint16_t roomCount = 0;
    for (std::uint32_t i = 0; i < _map->numTiles; i++)
    {
        _map->tile[i].type      = eTileType::tileWallTall;
        _map->tile[i].processed = false;
    }

    // add rooms
    for (std::uint32_t i = 0; i < _map->generate->roomMax; i++)
    {
        if (roomCount < _map->generate->roomMin)
        {
            std::uint32_t r = (rand() % (_map->generate->roomRadiusMax - _map->generate->roomRadiusMin)) + _map->generate->roomRadiusMin;
            std::int32_t x = (rand() % (_map->info.size_x - r - r)) + r;
            std::int32_t y = (rand() % (_map->info.size_y - r - r)) + r;
            if ((x > 1) && (x < (std::int32_t)(_map->info.size_x-1)) && (y > 1) && (y < (std::int32_t)(_map->info.size_y-1)))
            {
                if (_map->generate->roomShape == eRoomShape::shapeRandom)
                {
                    roomShape = ((rand() % 100) < 50) ? eRoomShape::shapeCircle : eRoomShape::shapeSquare;
                }
                if (roomShape == eRoomShape::shapeCircle)
                {
                    if (m_genCircleRoomOK(_map, x, y, r + _map->generate->roomBorder))
                    {
                        m_genCircleRoom(_map, x, y, r);
                        roomCount++;
                    }
                }
                if (roomShape == eRoomShape::shapeSquare)
                {
                    if (m_genSquareRoomOK(_map, x, y, r + _map->generate->roomBorder))
                    {
                        m_genSquareRoom(_map, x, y, r);
                        roomCount++;
                    }
                }
            }
        }
    }

    // Find and initialize rooms
    m_mapInitRooms(_map);

    // set unmodifiable tiles.
    for (std::uint32_t i = 0; i < _map->info.size_y; i++)
    {
        for (std::uint32_t j = 0; j < _map->info.size_x; j++)
        {
            _map->tile[(i * _map->info.size_x) + j].processed = ((i == 0) || (i == (_map->info.size_y-1)) || (j == 0) || (j == (_map->info.size_x-1)) || (_map->tile[(i * _map->info.size_x) + j].type != eTileType::tileWallTall));
        }
    }

    // maze.
    std::uint32_t  randBase = 25;
    eDirectionBias direction = _map->generate->directionBias;
    std::uint32_t  directionRand = (direction == eDirectionBias::directionNone) ? (rand() % (randBase * 4)) : (rand() % (randBase * (4 + _map->generate->directionBiasStrength)));
    if (directionRand < randBase)
        direction = eDirectionBias::directionNorth;
    if ((directionRand > (randBase * 1)) && (directionRand < (randBase * 2)))
        direction = eDirectionBias::directionSouth;
    if ((directionRand > (randBase * 2)) && (directionRand < (randBase * 3)))
        direction = eDirectionBias::directionEast;
    if ((directionRand > (randBase * 3)) && (directionRand < (randBase * 4)))
        direction = eDirectionBias::directionWest;
    if (_map->generate->directionBias != eDirectionBias::directionNone)
        _map->generate->directionBias = direction;
    std::uint32_t startX = _map->info.size_x / 2;
    std::uint32_t startY = _map->info.size_y / 2;
    if (direction == eDirectionBias::directionNorth)
        startY = 1;
    if (direction == eDirectionBias::directionSouth)
        startY = _map->info.size_y - 2;
    if (direction == eDirectionBias::directionEast)
        startX = 1;
    if (direction == eDirectionBias::directionWest)
        startX = _map->info.size_x - 2;
    std::uint32_t nextTile = (startY * _map->info.size_x) + startX;
    _map->tile[nextTile].type = eTileType::tileFloor;
    _map->tile[nextTile].processed = true;
    m_genM1_maze(_map, nextTile);

    // connect rooms
    for (std::uint32_t i = 0; i < _map->numRoom; i++)
    {
        std::uint16_t deltaX = std::abs (static_cast<std::int16_t>((_map->info.size_x / 2) - _map->room[i].x));
        std::uint16_t deltaY = std::abs (static_cast<std::int16_t>((_map->info.size_y / 2) - _map->room[i].y));
        direction = (deltaX > deltaY) ? ((_map->room[i].x < (_map->info.size_x / 2)) ? eDirectionBias::directionWest : eDirectionBias::directionEast) : ((_map->room[i].y < (_map->info.size_y / 2)) ? eDirectionBias::directionSouth : eDirectionBias::directionNorth);
        std::uint32_t tile = 0;
        if (direction == eDirectionBias::directionNorth)
        {
            tile = ((_map->room[i].y - ((_map->room[i].h+1) / 2)) * _map->info.size_x) + _map->room[i].x;
            _map->tile[tile].type = eTileType::tileFloor;
            if (_map->tile[tile-_map->info.size_x].type == eTileType::tileWallTall)
            {
                while (_map->tile[tile-_map->info.size_x].type == eTileType::tileWallTall)
                {
                    tile -= _map->info.size_x;
                    _map->tile[tile].type = eTileType::tileFloor;
                }
            }
        }
        if (direction == eDirectionBias::directionSouth)
        {
            tile = ((_map->room[i].y + ((_map->room[i].h+3) / 2)) * _map->info.size_x) + _map->room[i].x;
            _map->tile[tile].type = eTileType::tileFloor;
            if (_map->tile[tile+_map->info.size_x].type == eTileType::tileWallTall)
            {
                while (_map->tile[tile+_map->info.size_x].type == eTileType::tileWallTall)
                {
                    tile += _map->info.size_x;
                    _map->tile[tile].type = eTileType::tileFloor;
                }
            }
        }
        if (direction == eDirectionBias::directionEast)
        {
            tile = ((_map->room[i].y * _map->info.size_x) + _map->room[i].x - ((_map->room[i].w+1) / 2));
            _map->tile[tile].type = eTileType::tileFloor;
            if (_map->tile[tile-1].type == eTileType::tileWallTall)
            {
                while (_map->tile[tile-1].type == eTileType::tileWallTall)
                {
                    tile--;
                    _map->tile[tile].type = eTileType::tileFloor;
                }
            }
        }
        if (direction == eDirectionBias::directionWest)
        {
            tile = ((_map->room[i].y * _map->info.size_x) + _map->room[i].x + ((_map->room[i].w+3) / 2));
            _map->tile[tile].type = eTileType::tileFloor;
            if (_map->tile[tile+1].type == eTileType::tileWallTall)
            {
                while (_map->tile[tile+1].type == eTileType::tileWallTall)
                {
                    tile++;
                    _map->tile[tile].type = eTileType::tileFloor;
                }
            }
        }
    }
}

void cMapManager::m_generateMap_M1(sMap*& _map)
{
    for (std::uint16_t i = 0; i < _map->generate->pass; i++)
    {
        m_genM1_internal(_map);
        if ((m_mapGetFloorArea(_map) > (_map->numTiles / _map->generate->floorAreaMin)) && (_map->numRoom >= _map->generate->roomMin))
        {
            i = _map->generate->pass;
        }
        else
        {
            // epoch in microseconds
            std::uint64_t milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

            _map->info.seed = static_cast<std::uint32_t>(milliseconds_since_epoch);
            srand (_map->info.seed);
            mapList[_map->info.name] = _map->info.seed;
        }
    }

    // Generate a perimeter wall
    m_mapGeneratePerimeterWall(_map);

//    m_mapInitRoomsND(m_map);
    m_mapConnectRooms(_map);
//    m_mapAddDooryways(_map);

    m_playMapMusic();
    m_addWalls();
    m_addFloors();
    m_addPaths();
    m_addEvents();
    m_addPortals();

    m_generatePortals(_map);

    m_addPrefabs();
    m_addDoors();
    m_addTorches();
    m_addObjects();
    m_addNPCs();
    m_addChests();
    m_addDebris();
    m_addNPC_mobs();
}
