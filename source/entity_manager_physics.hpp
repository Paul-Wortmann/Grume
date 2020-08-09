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

#ifndef ENTITY_MANAGER_PHYSICS_HPP
#define ENTITY_MANAGER_PHYSICS_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity_component_physics.hpp"

// The entity physics manager facilitates the creation and deletion of entity physics components.

class cEntityManagerPhysics
{
    private:
        // Linked list pointers
        sEntityPhysics *m_first = nullptr;
        sEntityPhysics *m_last  = nullptr;
        sEntityPhysics *m_temp  = nullptr;

        // Private member variables
        uint32_t m_numEntities = 0;

        // Private member functions
        void m_freeEntities(void);
        void m_freeEntityData(sEntityPhysics *_entity);

    protected:

    public:
        cEntityManagerPhysics(void);
        ~cEntityManagerPhysics(void);
        
        // Public members
        sEntityPhysics *getNew(void);
        sEntityPhysics *getFirst(void);
        
        // Public member functions
        void initialize(void);
        void terminate(void);

};

#endif // ENTITY_MANAGER_PHYSICS_HPP
