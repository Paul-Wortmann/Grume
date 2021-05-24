/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "map_manager.hpp"

// Add an event to the map
void cMapManager::m_addMapEvent(sMap*& _map,                 // Map pointer
                                const std::uint32_t &_tile,  // tile number
                                const std::uint32_t &_type,  // event type
                                const std::uint32_t &_data_1, // data 1
                                const std::uint32_t &_data_2, // data 2
                                const std::uint32_t &_data_3) // data 3
{
    // backup dynamic event array if it is not empty
    sMapEvent* tMapEvents = nullptr;
    if (_map->event != nullptr)
    {
        tMapEvents = new sMapEvent[_map->eventCount];
        for (std::uint32_t i = 0; i < _map->eventCount; ++i)
        {
            tMapEvents[i].tile      = _map->event[i].tile;
            tMapEvents[i].type      = _map->event[i].type;
            tMapEvents[i].data_1    = _map->event[i].data_1;
            tMapEvents[i].data_2    = _map->event[i].data_2;
            tMapEvents[i].data_3    = _map->event[i].data_3;
            tMapEvents[i].triggered = _map->event[i].triggered;
        }
        
        delete[] _map->event;
        _map->event = nullptr;
    }
    
    // Inlarge the map event array
    _map->eventCount++;
    _map->event = new sMapEvent[_map->eventCount];
    
    // Replace the saved data
    for (std::uint32_t i = 0; i < _map->eventCount - 1; ++i)
    {
        _map->event[i].tile      = tMapEvents[i].tile;
        _map->event[i].type      = tMapEvents[i].type;
        _map->event[i].data_1    = tMapEvents[i].data_1;
        _map->event[i].data_2    = tMapEvents[i].data_2;
        _map->event[i].data_3    = tMapEvents[i].data_3;
        _map->event[i].triggered = tMapEvents[i].triggered;
    }
    
    // Add the new event to the end of the array
    _map->event[_map->eventCount - 1].tile      = _tile;
    _map->event[_map->eventCount - 1].type      = static_cast<eMapEventType>(_type);
    _map->event[_map->eventCount - 1].data_1    = _data_1;
    _map->event[_map->eventCount - 1].data_2    = _data_2;
    _map->event[_map->eventCount - 1].data_3    = _data_3;
    _map->event[_map->eventCount - 1].triggered = false;
    
    // Clean up
    if (tMapEvents != nullptr)
    {
        delete[] tMapEvents;
        tMapEvents = nullptr;
    }
}
