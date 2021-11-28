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

#include "includes.hpp"
#include "../templates/template_manager.hpp"

enum class eEventType : uint32 { eventType_none = 0};

struct sEventData
{
    union
    {
        float  x, y, z, w;
        uint32 data[4];
    };
};

struct sEvent
{
    eEventType eventType = eEventType::eventType_none;
    uint32     eventID   = 0;
    sEventData eventDate = {};
};

struct sEventPool
{
    static const int32 eventCount        = 32;
    int32              eventCurrent      = 0;
    sEvent             event[eventCount] = {};
};

#endif // EVENT_MANAGER_DEFINES_HPP
