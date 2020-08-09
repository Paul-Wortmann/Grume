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


#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity_component_animation.hpp"
#include "entity_component_audio.hpp"
#include "entity_component_graphics.hpp"
#include "entity_component_physics.hpp"

// Entity contaions only a list of component pointers, and a unique ID
// Component pointers are managed by thier respective managers
// Entities are managed by the Entity manager, which handles thier creation and deletion

// Entities are stored in a linked list,
// entity components are stored in seperate linked lists,
// pointers to which are the components of entites.
// Entities can share components.
// Systems for components can be itterated on without the overhead of checking each entity
// for the presence of compatible components.

struct sEntity
{
    // UID
    uint32_t         ID        = 0;
    
    // Pointer to the next entity in the linked list of entities
    sEntity         *next      = nullptr;
    
    // Components
    sEntityAudio    *animation = nullptr;
    sEntityAudio    *audio     = nullptr;
    sEntityGraphics *graphics  = nullptr;
    sEntityPhysics  *physics   = nullptr;
};

#endif // ENTITY_HPP
