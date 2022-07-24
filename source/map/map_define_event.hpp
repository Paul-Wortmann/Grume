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

#ifndef MAP_DEFINE_EVENT_HPP
#define MAP_DEFINE_EVENT_HPP

#include "../core/includes.hpp"

enum class eMapEventType : std::uint32_t
{
    eventTypeNone         = 0, // None
    eventTypeTriggerTile  = 1, // Trigger tile
    eventTypeMapWarp      = 2, // Map warp
    eventTypeMapCondition = 3, // Map condition set
    eventTypeMenuActivate = 4  // Menu activate
};

struct sMapEvent
{
    eMapEventType type         = eMapEventType::eventTypeNone; // Event type
    std::string   trigger_name = {};    // String data for a trigger event, eg. map name
    std::uint32_t tile         = 0;     // The tile that triggers the event
    std::uint32_t trigger_tile = 0;     // The tile that holds a static object to trigger
    bool          triggered    = false; // Flag to prevent multiple triggers
    bool          thisFrame    = false; // Flag to prevent multiple triggers per frame
    bool          repeat       = true;  // Flag to alow repeat triggers
};

#endif // MAP_DEFINE_EVENT_HPP


