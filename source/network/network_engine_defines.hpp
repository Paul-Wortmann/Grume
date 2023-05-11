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

#ifndef NETWORK_ENGINE_DEFINES_HPP
#define NETWORK_ENGINE_DEFINES_HPP

#include "../core/includes.hpp"
#include "../game/game_config.hpp"

// Event type enum
enum eNetworkEventType : std::uint32_t
{
    networkEventType_none         = 0,    // null event
    networkEventType_dataRecieved = 1     // data recieved event
};

// Event struct
struct sNetworkEvent
{
    sNetworkEvent*    next = nullptr;
    eNetworkEventType type = eNetworkEventType::networkEventType_none;
    std::uint32_t     data = 0;
};

#endif // NETWORK_ENGINE_DEFINES_HPP
