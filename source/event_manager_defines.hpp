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

#ifndef EVENT_MANAGER_DEFINES_HPP
#define EVENT_MANAGER_DEFINES_HPP

#include "core/includes.hpp"

enum class eEventType : std::uint32_t { eventType_none = 0,    // do nothing
                                        eventType_biome = 1,   // set biome
                                        eventType_music = 2,   // set music  (data: 0 == stop, 0 > track no.)
                                        eventType_sound = 3 }; // play sound (data: 0 == stop, 0 > track no.)

struct sEventData
{
    union
    {
        float         s, t, u, v, w, x, y, z;
        std::uint32_t data[8];
    };
};

struct sEvent
{
    eEventType    eventType = eEventType::eventType_none;
    std::uint32_t eventID   = 0;
    sEventData    eventData = {};
};

struct sEventPool
{
    static const std::int32_t eventCount        = 32;
    std::int32_t              eventCurrent      = 0;
    sEvent                    event[eventCount] = {};
};

#endif // EVENT_MANAGER_DEFINES_HPP
