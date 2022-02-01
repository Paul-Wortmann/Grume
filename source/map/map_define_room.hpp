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

#ifndef MAP_DEFINE_ROOM_HPP
#define MAP_DEFINE_ROOM_HPP

enum class eMapRoomType : std::uint16_t 
{ 
    roomTypeNone         =  0, // None / empty
    roomTypeCell         =  1, // Prison Cell
    roomTypeSecret       =  2, // Secret room
    roomTypeStairwell    =  3, // Stairwell
    roomTypeStore        =  4, // Store
    roomTypeBlacksmith   =  5, // Blacksmith
    roomTypeCanteen      =  6, // Canteen
    roomTypeStorage      =  7, // Storage room
    roomTypeLibrary      =  8, // Library
    roomTypeAlchemyLab   =  9, // Alchemy Lab
    roomTypeLaboratory   = 10, // Laboratory
    roomTypeTorture      = 11  // Torture Chamber
};

struct sMapRoom
{
    eMapRoomType  type    =  eMapRoomType::roomTypeNone;
    bool          p       =  false; // processed flag
    std::uint32_t posXMin =  0; // room min x, lowest tile number
    std::uint32_t posXMax =  0; // room max x, highest tile number
    std::uint32_t posYMin =  0; // room min y, lowest tile number
    std::uint32_t posYMax =  0; // room max y, highest tile number
    std::uint32_t x       =  0; // x position
    std::uint32_t y       =  0; // y position
    std::uint32_t w       =  0; // room width
    std::uint32_t h       =  0; // room height
    std::int32_t  exitN   = -1; // -1 for none, else connecting room ID
    std::int32_t  exitS   = -1; // -1 for none, else connecting room ID
    std::int32_t  exitE   = -1; // -1 for none, else connecting room ID
    std::int32_t  exitW   = -1; // -1 for none, else connecting room ID
};

#endif // MAP_DEFINE_ROOM_HPP
