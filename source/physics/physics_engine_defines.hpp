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

#ifndef PHYSICS_ENGINE_DEFINES_HPP
#define PHYSICS_ENGINE_DEFINES_HPP

#include "../entity/entity_physics.hpp"
#include "../core/includes.hpp"
#include "../map/map_utils.hpp"

#include "physics_collision.hpp"
#include "physics_resolution.hpp"


// Event type enum
enum ePhysicsEventType : std::uint32_t
{
    physicsEventType_none        = 0,    // null event
    physicsEventType_collision   = 1,    // collision event
    physicsEventType_objectClick = 2,    // object click event
    physicsEventType_tileClick   = 3     // tile click event
};

// Event struct
struct sPhysicsEvent
{
    sPhysicsEvent*    next = nullptr;
    ePhysicsEventType type = ePhysicsEventType::physicsEventType_none;
    std::uint32_t     data = 0;
};

#endif // PHYSICS_ENGINE_DEFINES_HPP
