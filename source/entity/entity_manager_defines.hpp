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

#ifndef ENTITY_MANAGER_DEFINES_HPP
#define ENTITY_MANAGER_DEFINES_HPP

#include "../core/includes.hpp"

// Event type enum
enum sEntityManagerEventType : std::uint32_t
{
    entityManagerEventType_none          = 0,    // null event
    entityManagerEventType_modCollisions = 1,    // Map collision data has changed
    entityManagerEventType_spawnEntity   = 2     // An entity was spawned
};

// Event struct
struct sEntityManagerEvent
{
    sEntityManagerEvent*    next = nullptr;
    sEntityManagerEventType type = sEntityManagerEventType::entityManagerEventType_none;
    std::uint32_t           data = 0;
};

#endif // ENTITY_MANAGER_DEFINES_HPP
