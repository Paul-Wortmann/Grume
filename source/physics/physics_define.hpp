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

#ifndef PHYISCS_DEFINE_HPP
#define PHYISCS_DEFINE_HPP

#include "../core/includes.hpp"
#include "physics_collision.hpp"

enum class ePhysicsEventType : uint16 
{
    physicsEventNone      =  0, // No physics event
    physicsEventCollision =  1  // Collision
};

struct sPhysicsEvent
{
    ePhysicsEventType eventType = ePhysicsEventType::physicsEventNone;
    struct sData
    {
        uint32  ID_1  = 0;    // entity UID
        uint32  ID_2  = 0;    // entity UID
        float32 depth = 0.0f; // penetration depth
        float32 angle = 0.0f; // radians
    } data;
};

#endif //PHYISCS_DEFINE_HPP

