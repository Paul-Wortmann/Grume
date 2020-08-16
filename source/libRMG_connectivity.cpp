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

#include "libRMG_connectivity.hpp"

void _libRMG_connect_rooms(sLibRMGMapData &_data)
{
    uint32_t distanceT = 0; // temp distance
    uint32_t distanceN = _data.tile_count; // size larger than possible distance
    uint32_t distanceE = _data.tile_count; // size larger than possible distance
    uint32_t distanceW = _data.tile_count; // size larger than possible distance
    uint32_t distanceS = _data.tile_count; // size larger than possible distance
    // ray cast room finder
    for (uint16_t i = 0; i < _data.room_count; i++)
    {
        //search horizontally
        for (uint16_t j = _data.room[i].posYMin; j < _data.room[i].posYMax; j++)
        {
            // right / west
            for (uint16_t k = _data.room[i].x; k < _data.tile_x; k++)
            {
                uint16_t r = _data.tile[(j * _data.tile_x) + k].roomID;
                if ((_data.tile[(j * _data.tile_x) + k].base == eBase::baseFloor) && (r != i))
                {
                    distanceT = sqrt(((_data.room[r].x - _data.room[i].x) * (_data.room[r].x - _data.room[i].x)) + ((_data.room[r].y - _data.room[i].y) * (_data.room[r].y - _data.room[i].y)));
                    if (distanceT < distanceW)
                    {
                        distanceW = distanceT;
                        _data.room[i].exitW = r;
                        _data.room[r].exitE = i;
                    }
                }
            }
            // left / east
            for (uint16_t k = _data.room[i].x; k > 0; k--)
            {
                uint16_t r = _data.tile[(j * _data.tile_x) + k].roomID;
                if ((_data.tile[(j * _data.tile_x) + k].base == eBase::baseFloor) && (r != i))
                {
                    distanceT = sqrt(((_data.room[r].x - _data.room[i].x) * (_data.room[r].x - _data.room[i].x)) + ((_data.room[r].y - _data.room[i].y) * (_data.room[r].y - _data.room[i].y)));
                    if (distanceT < distanceE)
                    {
                        distanceE = distanceT;
                        _data.room[i].exitE = r;
                        _data.room[r].exitW = i;
                    }
                }
            }
        }
        //search vertically
        for (uint16_t k = _data.room[i].posXMin; k < _data.room[i].posXMax; k++)
        {
            // down / south
            for (uint16_t j = _data.room[i].y; j < _data.tile_y; j++)
            {
                uint16_t r = _data.tile[(j * _data.tile_x) + k].roomID;
                if ((_data.tile[(j * _data.tile_x) + k].base == eBase::baseFloor) && (_data.tile[(j * _data.tile_x) + k].roomID != i))
                {
                    distanceT = sqrt(((_data.room[r].x - _data.room[i].x) * (_data.room[r].x - _data.room[i].x)) + ((_data.room[r].y - _data.room[i].y) * (_data.room[r].y - _data.room[i].y)));
                    if (distanceT < distanceS)
                    {
                        distanceS = distanceT;
                        _data.room[i].exitS = _data.tile[(j * _data.tile_x) + k].roomID;
                        _data.room[_data.tile[(j * _data.tile_x) + k].roomID].exitN = i;
                    }
                }
            }
            // up / north
            for (uint16_t j = _data.room[i].y; j > 0; j--)
            {
                uint16_t r = _data.tile[(j * _data.tile_x) + k].roomID;
                if ((_data.tile[(j * _data.tile_x) + k].base == eBase::baseFloor) && (_data.tile[(j * _data.tile_x) + k].roomID != i))
                {
                    distanceT = sqrt(((_data.room[r].x - _data.room[i].x) * (_data.room[r].x - _data.room[i].x)) + ((_data.room[r].y - _data.room[i].y) * (_data.room[r].y - _data.room[i].y)));
                    if (distanceT < distanceN)
                    {
                        distanceN = distanceT;
                        _data.room[i].exitN = _data.tile[(j * _data.tile_x) + k].roomID;
                        _data.room[_data.tile[(j * _data.tile_x) + k].roomID].exitS = i;
                    }
                }
            }
        }
    }
    // remove multiple connections to same neighbor
    for (uint16_t i = 0; i < _data.room_count; i++)
    {
        for (uint16_t j = 0; j < _data.room_count; j++)
        {
            uint16_t found = 0;
            if (_data.room[i].exitE == j)
                found++;
            if (_data.room[i].exitW == j)
            {
                if (found == 1)
                    _data.room[i].exitW = LIBRMG_NOROOM;
                else
                    found++;
            }
            if (_data.room[i].exitN == j)
            {
                if (found == 1)
                    _data.room[i].exitN = LIBRMG_NOROOM;
                else
                    found++;
            }
            if (_data.room[i].exitS == j)
            {
                if (found == 1)
                    _data.room[i].exitS = LIBRMG_NOROOM;
                else
                    found++;
            }
        }
    }
    // try to connect lonely rooms
    for (uint16_t i = (_data.room_count-1); i > 0; i--)
    {
        int32_t deltaX = 0;
        int32_t deltaY = 0;
        if ((_data.room[i].exitE == LIBRMG_NOROOM) && (_data.room[i].exitW == LIBRMG_NOROOM) && (_data.room[i].exitN == LIBRMG_NOROOM) && (_data.room[i].exitS == LIBRMG_NOROOM))
        {
            //std::cout << "Lonely room detected!" << std::endl;
            deltaX = _data.room[i].x - _data.room[i-1].x;
            deltaY = _data.room[i].y - _data.room[i-1].y;
            if (abs(deltaX) < abs(deltaY))
            {
                if (deltaX > 0)
                {
                    _data.room[i].exitE = i-1;
                    _data.room[i-1].exitW = i;
                }
                else
                {
                    _data.room[i].exitW = i-1;
                    _data.room[i-1].exitE = i;
                }
            }
            else
            {
                if (deltaY > 0)
                {
                    _data.room[i].exitN = i-1;
                    _data.room[i-1].exitS = i;
                }
                else
                {
                    _data.room[i].exitS = i-1;
                    _data.room[i-1].exitN = i;
                }
            }
        }
    }
    // apply room inter-connections
    for (uint16_t i = 0; i < _data.room_count; i++)
    {
        switch (_data.connect_algorithm)
        {
            case eConnectAlgorithm::connectSL:
                if (_data.room[i].exitE > i)
                    _libRMG_connect_rooms_SL(_data, i, _data.room[i].exitE);
                if (_data.room[i].exitW > i)
                    _libRMG_connect_rooms_SL(_data, i, _data.room[i].exitW);
                if (_data.room[i].exitN > i)
                    _libRMG_connect_rooms_SL(_data, i, _data.room[i].exitN);
                if (_data.room[i].exitS > i)
                    _libRMG_connect_rooms_SL(_data, i, _data.room[i].exitS);
            break;
            case eConnectAlgorithm::connectND:
                if (_data.room[i].exitE > i)
                    _libRMG_connect_rooms_ND(_data, i, _data.room[i].exitE);
                if (_data.room[i].exitW > i)
                    _libRMG_connect_rooms_ND(_data, i, _data.room[i].exitW);
                if (_data.room[i].exitN > i)
                    _libRMG_connect_rooms_ND(_data, i, _data.room[i].exitN);
                if (_data.room[i].exitS > i)
                    _libRMG_connect_rooms_ND(_data, i, _data.room[i].exitS);
            break;
            case eConnectAlgorithm::connectDW:
                if (_data.room[i].exitE > i)
                    _libRMG_connect_rooms_DW(_data, i, _data.room[i].exitE);
                if (_data.room[i].exitW > i)
                    _libRMG_connect_rooms_DW(_data, i, _data.room[i].exitW);
                if (_data.room[i].exitN > i)
                    _libRMG_connect_rooms_DW(_data, i, _data.room[i].exitN);
                if (_data.room[i].exitS > i)
                    _libRMG_connect_rooms_DW(_data, i, _data.room[i].exitS);
            break;
            default:
                // throw error / set flag
            break;
        }
    }
    // use path finder to locate unreachable rooms and try connect them.
    if (_data.room_count > 0)
    {
        for (uint16_t i = 0; i < _data.room_count-1; i++)
        {
            sLibRMGMapPath pathT;
            pathT.sx = _data.room[i].x;
            pathT.sy = _data.room[i].y;
            pathT.ex = _data.room[i+1].x;
            pathT.ey = _data.room[i+1].y;
            if (_libRMG_pathAS(_data, pathT) == false)
            {
                if (_data.connect_algorithm == eConnectAlgorithm::connectSL)
                    _libRMG_connect_rooms_SL(_data, i, i+1);
                if (_data.connect_algorithm == eConnectAlgorithm::connectND)
                    _libRMG_connect_rooms_ND(_data, i, i+1);
                if (_data.connect_algorithm == eConnectAlgorithm::connectDW)
                    _libRMG_connect_rooms_DW(_data, i, i+1);
            }
            _libRMG_pathASFree(pathT);
        }
    }
}

// Straight Line
void _libRMG_connect_rooms_SL(sLibRMGMapData &_data, const uint16_t &_r1, const uint16_t &_r2)
{
    uint16_t direction = eDirection::directionNone;
    if (_data.room[_r1].exitE == _r2)
        direction = eDirection::directionEast;
    if (_data.room[_r1].exitW == _r2)
        direction = eDirection::directionWest;
    if (_data.room[_r1].exitN == _r2)
        direction = eDirection::directionNorth;
    if (_data.room[_r1].exitS == _r2)
        direction = eDirection::directionSouth;
    uint16_t psx = ((direction == eDirection::directionEast) || (direction == eDirection::directionWest)) ?  ((direction == eDirection::directionEast) ? _data.room[_r1].posXMin : _data.room[_r1].posXMax) : _data.room[_r1].x;
    uint16_t psy = ((direction == eDirection::directionNorth) || (direction == eDirection::directionSouth)) ?  ((direction == eDirection::directionNorth) ? _data.room[_r1].posYMin : _data.room[_r1].posYMax) : _data.room[_r1].y;
    uint16_t pex = ((direction == eDirection::directionEast) || (direction == eDirection::directionWest)) ?  ((direction == eDirection::directionWest) ? _data.room[_r2].posXMin : _data.room[_r2].posXMax) : _data.room[_r2].x;
    uint16_t pey = ((direction == eDirection::directionNorth) || (direction == eDirection::directionSouth)) ?  ((direction == eDirection::directionSouth) ? _data.room[_r2].posYMin : _data.room[_r2].posYMax) : _data.room[_r2].y;
    //std::cout << "X1: " << psx  << " Y1: " << psy << std::endl;
    //std::cout << "X2: " << pex  << " Y2: " << pey << std::endl;
    if (direction == eDirection::directionEast)
    {
        while ((_data.tile[(psy * _data.tile_x) + psx].base == eBase::baseWall) && (psx < _data.room[_r1].posXMax))
            psx++;
        while ((_data.tile[(pey * _data.tile_x) + pex].base == eBase::baseWall) && (pex > _data.room[_r2].posXMin))
            pex--;
    }
    if (direction == eDirection::directionWest)
    {
        while ((_data.tile[(psy * _data.tile_x) + psx].base == eBase::baseWall) && (psx > _data.room[_r1].posXMin))
            psx--;
        while ((_data.tile[(pey * _data.tile_x) + pex].base == eBase::baseWall) && (pex < _data.room[_r2].posXMax))
            pex++;
    }
    if (direction == eDirection::directionNorth)
    {
        while ((_data.tile[(psy * _data.tile_x) + psx].base == eBase::baseWall) && (psy < _data.room[_r1].posYMax))
            psy++;
        while ((_data.tile[(pey * _data.tile_x) + pex].base == eBase::baseWall) && (pey > _data.room[_r2].posYMin))
            pey--;
    }
    if (direction == eDirection::directionSouth)
    {
        while ((_data.tile[(psy * _data.tile_x) + psx].base == eBase::baseWall) && (psy > _data.room[_r1].posYMin))
            psy--;
        while ((_data.tile[(pey * _data.tile_x) + pex].base == eBase::baseWall) && (pey < _data.room[_r2].posYMax))
            pey++;
    }
    while ((psx != pex) || (psy != pey))
    {
        if (_data.tile[(psy * _data.tile_x) + psx].base == eBase::baseWall)
        {
            _data.tile[(psy * _data.tile_x) + psx].base = eBase::baseFloor;
            if (_data.connectivity_padding > 0)
            {
                for (uint16_t i = 0; i <= _data.connectivity_padding; i++)
                {
                    if (_data.tile[(psy * _data.tile_x) + psx + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x - i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x - i].base = eBase::baseFloor;
                }
            }
        }
        psx = (psx == pex) ? psx : ((psx > pex) ? --psx : ++psx);
        psy = (psy == pey) ? psy : ((psy > pey) ? --psy : ++psy);
    }
}

// Straight Lines, 90 degree angle
void _libRMG_connect_rooms_ND(sLibRMGMapData &_data, const uint16_t &_r1, const uint16_t &_r2)
{
    uint16_t psx = _data.room[_r1].x;
    uint16_t psy = _data.room[_r1].y;
    uint16_t pex = _data.room[_r2].x;
    uint16_t pey = _data.room[_r2].y;

    while (psy != pey)
    {
        if (_data.tile[(psy * _data.tile_x) + psx].base == eBase::baseWall)
        {
            _data.tile[(psy * _data.tile_x) + psx].base = eBase::baseFloor;
            if (_data.connectivity_padding > 0)
            {
                for (uint16_t i = 0; i <= _data.connectivity_padding; i++)
                {
                    if (_data.tile[(psy * _data.tile_x) + psx + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x - i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x - i].base = eBase::baseFloor;
                }
            }
        }
        psy = (psy == pey) ? psy : ((psy > pey) ? --psy : ++psy);
    }
    while (psx != pex)
    {
        if (_data.tile[(psy * _data.tile_x) + psx].base == eBase::baseWall)
        {
            _data.tile[(psy * _data.tile_x) + psx].base = eBase::baseFloor;
            if (_data.connectivity_padding > 0)
            {
                for (uint16_t i = 0; i <= _data.connectivity_padding; i++)
                {
                    if (_data.tile[(psy * _data.tile_x) + psx + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx + _data.tile_x - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx + _data.tile_x - i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x + i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x + i].base = eBase::baseFloor;
                    if (_data.tile[(psy * _data.tile_x) + psx - _data.tile_x - i].base == eBase::baseWall)
                        _data.tile[(psy * _data.tile_x) + psx - _data.tile_x - i].base = eBase::baseFloor;
                }
            }
        }
        psx = (psx == pex) ? psx : ((psx > pex) ? --psx : ++psx);
    }
}

// Drunken Walk
void _libRMG_connect_rooms_DW(sLibRMGMapData &_data, const uint16_t &_r1, const uint16_t &_r2)
{

}
