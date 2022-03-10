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

// Straight Line
void cMapManager::m_mapConnectRooms_SL(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2)
{
    // If room IDs are invalid, exit early
    if ((_r1 < 0) || (_r2 < 0))
    {
        return;
    }
    
    // Determinte the direction of the room
    eDirectionBias direction = eDirectionBias::directionNone;
    if (_map->room[_r1].exitE == _r2)
    {
        direction = eDirectionBias::directionEast;
    }
    if (_map->room[_r1].exitW == _r2)
    {
        direction = eDirectionBias::directionWest;
    }
    if (_map->room[_r1].exitN == _r2)
    {
        direction = eDirectionBias::directionNorth;
    }
    if (_map->room[_r1].exitS == _r2)
    {
        direction = eDirectionBias::directionSouth;
    }
    
    // Determine the start and end points of the connecting path
    // Path start x
    std::uint32_t psx;
    if ((direction == eDirectionBias::directionEast) || (direction == eDirectionBias::directionWest))
    {
        if (direction == eDirectionBias::directionEast)
        {
            psx = _map->room[_r1].posXMin;
        }
        else
        {
            psx = _map->room[_r1].posXMax;
        }
    }
    else
    {
        psx = _map->room[_r1].x;
    }
    
    // Path start y
    std::uint32_t psy;
    if  ((direction == eDirectionBias::directionNorth) || (direction == eDirectionBias::directionSouth))
    {
        if (direction == eDirectionBias::directionNorth)
        {
            psy = _map->room[_r1].posYMin;
        }
        else
        {
            psy = _map->room[_r1].posYMax;
        }
    }
    else
    {
        psy = _map->room[_r1].y;
    }
    
    // Path end x
    std::uint32_t pex;
    if ((direction == eDirectionBias::directionEast) || (direction == eDirectionBias::directionWest))
    {
        if (direction == eDirectionBias::directionWest)
        {
            pex = _map->room[_r2].posXMin;
        }
        else
        {
            pex = _map->room[_r2].posXMax;
        }
    }
    else
    {
        pex = _map->room[_r2].x;
    }
    
    // Path end y
    std::uint32_t pey;
    if  ((direction == eDirectionBias::directionNorth) || (direction == eDirectionBias::directionSouth))
    {
        if (direction == eDirectionBias::directionSouth)
        {
            pey = _map->room[_r2].posYMin;
        }
        else
        {
            pey = _map->room[_r2].posYMax;
        }
    }
    else
    {
        pey = _map->room[_r2].y;
    }

    //std::cout << "X1: " << psx  << " Y1: " << psy << std::endl;
    //std::cout << "X2: " << pex  << " Y2: " << pey << std::endl;
    if (direction == eDirectionBias::directionEast)
    {
        while ((_map->tile[(psy * _map->width) + psx].base == eTileBase::tileWall) && (psx < _map->room[_r1].posXMax))
        {
            psx++;
        }
        while ((_map->tile[(pey * _map->width) + pex].base == eTileBase::tileWall) && (pex > _map->room[_r2].posXMin))
        {
            pex--;
        }
    }
    if (direction == eDirectionBias::directionWest)
    {
        while ((_map->tile[(psy * _map->width) + psx].base == eTileBase::tileWall) && (psx > _map->room[_r1].posXMin))
        {
            psx--;
        }
        while ((_map->tile[(pey * _map->width) + pex].base == eTileBase::tileWall) && (pex < _map->room[_r2].posXMax))
        {
            pex++;
        }
    }
    if (direction == eDirectionBias::directionNorth)
    {
        while ((_map->tile[(psy * _map->width) + psx].base == eTileBase::tileWall) && (psy < _map->room[_r1].posYMax))
        {
            psy++;
        }
        while ((_map->tile[(pey * _map->width) + pex].base == eTileBase::tileWall) && (pey > _map->room[_r2].posYMin))
        {
            pey--;
        }
    }
    if (direction == eDirectionBias::directionSouth)
    {
        while ((_map->tile[(psy * _map->width) + psx].base == eTileBase::tileWall) && (psy > _map->room[_r1].posYMin))
        {
            psy--;
        }
        while ((_map->tile[(pey * _map->width) + pex].base == eTileBase::tileWall) && (pey < _map->room[_r2].posYMax))
        {
            pey++;
        }
    }
    while ((psx != pex) || (psy != pey))
    {
        if (_map->tile[(psy * _map->width) + psx].base == eTileBase::tileWall)
        {
            _map->tile[(psy * _map->width) + psx].base = eTileBase::tileFloor;
            if (_map->genData.connectivityPadding > 0)
            {
                for (std::uint32_t i = 0; i <= _map->genData.connectivityPadding; i++)
                {
                    if (_map->tile[(psy * _map->width) + psx + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width - i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width - i].base = eTileBase::tileFloor;
                }
            }
        }
        psx = (psx == pex) ? psx : ((psx > pex) ? --psx : ++psx);
        psy = (psy == pey) ? psy : ((psy > pey) ? --psy : ++psy);
    }
}

// Straight Lines, 90 degree angle
void cMapManager::m_mapConnectRooms_ND(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2)
{
    // If room IDs are invalid, exit early
    if ((_r1 < 0) || (_r2 < 0))
    {
        return;
    }
    
    std::uint32_t psx = _map->room[_r1].x;
    std::uint32_t psy = _map->room[_r1].y;
    std::uint32_t pex = _map->room[_r2].x;
    std::uint32_t pey = _map->room[_r2].y;

    while (psy != pey)
    {
        if (_map->tile[(psy * _map->width) + psx].base == eTileBase::tileWall)
        {
            _map->tile[(psy * _map->width) + psx].base = eTileBase::tileFloor;
            if (_map->genData.connectivityPadding > 0)
            {
                for (std::uint32_t i = 0; i <= _map->genData.connectivityPadding; i++)
                {
                    if (_map->tile[(psy * _map->width) + psx + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width - i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width - i].base = eTileBase::tileFloor;
                }
            }
        }
        psy = (psy == pey) ? psy : ((psy > pey) ? --psy : ++psy);
    }
    while (psx != pex)
    {
        if (_map->tile[(psy * _map->width) + psx].base == eTileBase::tileWall)
        {
            _map->tile[(psy * _map->width) + psx].base = eTileBase::tileFloor;
            if (_map->genData.connectivityPadding > 0)
            {
                for (std::uint32_t i = 0; i <= _map->genData.connectivityPadding; i++)
                {
                    if (_map->tile[(psy * _map->width) + psx + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx + _map->width - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx + _map->width - i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width + i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width + i].base = eTileBase::tileFloor;
                    if (_map->tile[(psy * _map->width) + psx - _map->width - i].base == eTileBase::tileWall)
                        _map->tile[(psy * _map->width) + psx - _map->width - i].base = eTileBase::tileFloor;
                }
            }
        }
        psx = (psx == pex) ? psx : ((psx > pex) ? --psx : ++psx);
    }
}

// Drunken Walk
void cMapManager::m_mapConnectRooms_DW(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2)
{
    // If room IDs are invalid, exit early
    if ((_r1 < 0) || (_r2 < 0))
    {
        return;
    }
    

}

void cMapManager::m_mapConnectRooms(sMap*& _map)
{
    // If there are less than 2 rooms, exit early
    if (_map->roomCount < 2)
        return;

    std::uint32_t distanceT = 0; // temp distance
    std::uint32_t distanceN = UINT32_MAX; // size larger than possible distance
    std::uint32_t distanceE = UINT32_MAX; // size larger than possible distance
    std::uint32_t distanceW = UINT32_MAX; // size larger than possible distance
    std::uint32_t distanceS = UINT32_MAX; // size larger than possible distance
    // ray cast room finder
    for (std::uint32_t i = 0; i < _map->roomCount; i++)
    {
        //search horizontally
        for (std::uint32_t j = _map->room[i].posYMin; j < _map->room[i].posYMax; j++)
        {
            // right / west
            for (std::uint32_t k = _map->room[i].x; k < _map->width; k++)
            {
                std::uint32_t r = _map->tile[(j * _map->width) + k].room;
                if ((_map->tile[(j * _map->width) + k].base == eTileBase::tileFloor) && (r != i))
                {
                    distanceT = sqrt(((_map->room[r].x - _map->room[i].x) * (_map->room[r].x - _map->room[i].x)) + ((_map->room[r].y - _map->room[i].y) * (_map->room[r].y - _map->room[i].y)));
                    if (distanceT < distanceW)
                    {
                        distanceW = distanceT;
                        _map->room[i].exitW = r;
                        _map->room[r].exitE = i;
                    }
                }
            }
            // left / east
            for (std::uint32_t k = _map->room[i].x; k > 0; k--)
            {
                std::uint32_t r = _map->tile[(j * _map->width) + k].room;
                if ((_map->tile[(j * _map->width) + k].base == eTileBase::tileFloor) && (r != i))
                {
                    distanceT = sqrt(((_map->room[r].x - _map->room[i].x) * (_map->room[r].x - _map->room[i].x)) + ((_map->room[r].y - _map->room[i].y) * (_map->room[r].y - _map->room[i].y)));
                    if (distanceT < distanceE)
                    {
                        distanceE = distanceT;
                        _map->room[i].exitE = r;
                        _map->room[r].exitW = i;
                    }
                }
            }
        }
        //search vertically
        for (std::uint32_t k = _map->room[i].posXMin; k < _map->room[i].posXMax; k++)
        {
            // down / south
            for (std::uint32_t j = _map->room[i].y; j < _map->height; j++)
            {
                std::uint32_t r = _map->tile[(j * _map->width) + k].room;
                if ((_map->tile[(j * _map->width) + k].base == eTileBase::tileFloor) && (_map->tile[(j * _map->width) + k].room != i))
                {
                    distanceT = sqrt(((_map->room[r].x - _map->room[i].x) * (_map->room[r].x - _map->room[i].x)) + ((_map->room[r].y - _map->room[i].y) * (_map->room[r].y - _map->room[i].y)));
                    if (distanceT < distanceS)
                    {
                        distanceS = distanceT;
                        _map->room[i].exitS = _map->tile[(j * _map->width) + k].room;
                        _map->room[_map->tile[(j * _map->width) + k].room].exitN = i;
                    }
                }
            }
            // up / north
            for (std::uint32_t j = _map->room[i].y; j > 0; j--)
            {
                std::uint32_t r = _map->tile[(j * _map->width) + k].room;
                if ((_map->tile[(j * _map->width) + k].base == eTileBase::tileFloor) && (_map->tile[(j * _map->width) + k].room != i))
                {
                    distanceT = sqrt(((_map->room[r].x - _map->room[i].x) * (_map->room[r].x - _map->room[i].x)) + ((_map->room[r].y - _map->room[i].y) * (_map->room[r].y - _map->room[i].y)));
                    if (distanceT < distanceN)
                    {
                        distanceN = distanceT;
                        _map->room[i].exitN = _map->tile[(j * _map->width) + k].room;
                        _map->room[_map->tile[(j * _map->width) + k].room].exitS = i;
                    }
                }
            }
        }
    }
    // remove multiple connections to same neighbor
    for (std::uint32_t i = 0; i < _map->roomCount; i++)
    {
        for (std::uint32_t j = 0; j < _map->roomCount; j++)
        {
            std::uint32_t found = 0;
            if (_map->room[i].exitE == j)
                found++;
            if (_map->room[i].exitW == j)
            {
                if (found == 1)
                    _map->room[i].exitW = -1; // No room
                else
                    found++;
            }
            if (_map->room[i].exitN == j)
            {
                if (found == 1)
                    _map->room[i].exitN = -1; // No room
                else
                    found++;
            }
            if (_map->room[i].exitS == j)
            {
                if (found == 1)
                    _map->room[i].exitS = -1; // No room
                else
                    found++;
            }
        }
    }
    // try to connect detached rooms
    for (std::uint32_t i = (_map->roomCount-1); i > 0; i--)
    {
        if ((_map->room[i].exitE ==  -1) && (_map->room[i].exitW == -1) && (_map->room[i].exitN == -1) && (_map->room[i].exitS == -1))
        {
            //std::cout << "Detached room detected!" << std::endl;
            std::int32_t deltaX = _map->room[i].x - _map->room[i-1].x;
            std::int32_t deltaY = _map->room[i].y - _map->room[i-1].y;
            if (abs(deltaX) < abs(deltaY))
            {
                if (deltaX > 0)
                {
                    _map->room[i].exitE = i-1;
                    _map->room[i-1].exitW = i;
                }
                else
                {
                    _map->room[i].exitW = i-1;
                    _map->room[i-1].exitE = i;
                }
            }
            else
            {
                if (deltaY > 0)
                {
                    _map->room[i].exitN = i-1;
                    _map->room[i-1].exitS = i;
                }
                else
                {
                    _map->room[i].exitS = i-1;
                    _map->room[i-1].exitN = i;
                }
            }
        }
    }
    // apply room inter-connections
    for (std::uint32_t i = 0; i < _map->roomCount; i++)
    {
        switch (_map->genData.connectivityAlgorithm)
        {
            case eConnectAlgo::algorithm_SL:
                if (_map->room[i].exitE > i)
                    m_mapConnectRooms_SL(_map, i, _map->room[i].exitE);
                if (_map->room[i].exitW > i)
                    m_mapConnectRooms_SL(_map, i, _map->room[i].exitW);
                if (_map->room[i].exitN > i)
                    m_mapConnectRooms_SL(_map, i, _map->room[i].exitN);
                if (_map->room[i].exitS > i)
                    m_mapConnectRooms_SL(_map, i, _map->room[i].exitS);
            break;
            case eConnectAlgo::algorithm_ND:
                if (_map->room[i].exitE > i)
                    m_mapConnectRooms_ND(_map, i, _map->room[i].exitE);
                if (_map->room[i].exitW > i)
                    m_mapConnectRooms_ND(_map, i, _map->room[i].exitW);
                if (_map->room[i].exitN > i)
                    m_mapConnectRooms_ND(_map, i, _map->room[i].exitN);
                if (_map->room[i].exitS > i)
                    m_mapConnectRooms_ND(_map, i, _map->room[i].exitS);
            break;
            case eConnectAlgo::algorithm_DW:
                if (_map->room[i].exitE > i)
                    m_mapConnectRooms_DW(_map, i, _map->room[i].exitE);
                if (_map->room[i].exitW > i)
                    m_mapConnectRooms_DW(_map, i, _map->room[i].exitW);
                if (_map->room[i].exitN > i)
                    m_mapConnectRooms_DW(_map, i, _map->room[i].exitN);
                if (_map->room[i].exitS > i)
                    m_mapConnectRooms_DW(_map, i, _map->room[i].exitS);
            break;
            default:
                // throw error / set flag
            break;
        }
    }
    // use path finder to locate unreachable rooms and try connect them.
    if (_map->roomCount > 0)
    {
        for (std::uint32_t i = 0; i < _map->roomCount-1; i++)
        {
            sMapPath pathT;
            pathT.startTile       = ((_map->width * _map->room[i].y)   + _map->room[i].x);
            pathT.destinationTile = ((_map->width * _map->room[i+1].y) + _map->room[i+1].x);
            gAStar(_map, pathT);
            if (pathT.pathLength == 0)
            {
                if (_map->genData.connectivityAlgorithm == eConnectAlgo::algorithm_SL)
                    m_mapConnectRooms_SL(_map, i, i+1);
                if (_map->genData.connectivityAlgorithm == eConnectAlgo::algorithm_ND)
                    m_mapConnectRooms_ND(_map, i, i+1);
                if (_map->genData.connectivityAlgorithm == eConnectAlgo::algorithm_DW)
                    m_mapConnectRooms_DW(_map, i, i+1);
            }
            
            // Clean up
            if (pathT.path != nullptr)
            {
                delete [] pathT.path;
                pathT.path = nullptr;
            }
        }
    }
}
