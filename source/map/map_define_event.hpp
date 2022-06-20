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


enum class eMapEventType : std::uint32_t 
{
    eventTypeNone                      = 0, // None
    eventTypeWarp                      = 1, // Warp to map
    eventTypeEntitySet                 = 2, // Set entity state
    eventTypeEntityToggle              = 3, // Toggle entity state
    eventTypeEntitySpawn               = 4, // Spawn entity
    eventTypeTriggerTile               = 5, // Trigger tile
    eventTypeSetCondition              = 6  // Set map condition
};

struct sMapEvent
{
    eMapEventType  type                = eMapEventType::eventTypeNone; // Default == eMapEventType::eventTypeNone
    std::uint32_t  tile                = 0; // The tile that triggers the event, default == 0
    std::uint32_t  data_1              = 0; // Default == 0
    std::uint32_t  data_2              = 0; // Default == 0
    std::uint32_t  data_3              = 0; // Default == 0
    bool           triggered           = false; // Default == false
};

#endif // MAP_DEFINE_EVENT_HPP
