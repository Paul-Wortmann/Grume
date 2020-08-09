


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
