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


#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity.hpp"

#include "entity_manager_audio.hpp"
#include "entity_manager_graphics.hpp"
#include "entity_manager_physics.hpp"

// The entity manager facilitates the creation and deletion of entities,
// other entity component managers are handled by the entity manager as member instatnces


class cEntityManager
{
    private:
        // Linked list pointers
        sEntity *m_first = nullptr;
        sEntity *m_last  = nullptr;
        sEntity *m_temp  = nullptr;
        
        // Instances of component managers
        cEntityManagerAudio    managerAudio    = {};
        cEntityManagerGraphics managerGraphics = {};
        cEntityManagerPhysics  managerPhysics  = {};

        // Private member variables
        uint32_t m_numEntities = 0;

        // Private member functions
        void m_freeEntities(void);
        void m_freeEntityData(sEntity *_entity);
        
    protected:

    public:
        cEntityManager(void);
        ~cEntityManager(void);
        
        // Public members
        sEntity *getNew(void);
        sEntity *getFirst(void);
        
        // Public member functions
        void initialize(void);
        void terminate(void);
        void addComponentAudio(sEntity *_entity);
        void addComponentGraphics(sEntity *_entity);
        void addComponentPhysics(sEntity *_entity);
};

#endif // ENTITY_MANAGER_HPP

















#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "includes.hpp"
#include "entity.hpp"

class cEntityManager
{
    private:

    public:
        cEntityManager(void) = default;
        ~cEntityManager(void) = default;
        void     initialize(void);
        void     terminate(void);
        void     freeEntities(void);
        sEntity* newEntity(void);
        sEntity* getEntityHead(void) { return m_entityHead; }
        void     addComponentRender(sEntity* _entity);
        uint32_t getEntityCount(void) { return m_entityCount; }

    protected:

    private:
        void m_freeEntityData(sEntity *_entity);
        
        uint32_t m_entityCount = 0;
        sEntity* m_entityHead  = nullptr;
        sEntity* m_entityTail  = nullptr;
        sEntity* m_entityTemp  = nullptr;
};

#endif //ENTITY_MANAGER_HPP

