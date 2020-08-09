


#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "defines.hpp"
#include "includes.hpp"

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
    uint32_t         ID       = 0;
    
    // Pointer to the next entity in the linked list of entities
    sEntity         *next     = nullptr;
    
    // Components
    sEntityAudio    *audio    = nullptr;
    sEntityGraphics *graphics = nullptr;
    sEntityPhysics  *physics  = nullptr;
};

#endif // ENTITY_HPP
