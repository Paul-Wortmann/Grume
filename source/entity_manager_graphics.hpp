


#ifndef ENTITY_MANAGER_GRAPHICS_HPP
#define ENTITY_MANAGER_GRAPHICS_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity_component_graphics.hpp"

// The entity graphics manager facilitates the creation and deletion of entity graphics components.

class cEntityManagerGraphics
{
    private:
        // Linked list pointers
        sEntityGraphics *m_first = nullptr;
        sEntityGraphics *m_last  = nullptr;
        sEntityGraphics *m_temp  = nullptr;

        // Private member variables
        uint32_t m_numEntities = 0;

        // Private member functions
        void m_freeEntities(void);
        void m_freeEntityData(sEntityGraphics *_entity);

    protected:

    public:
        cEntityManagerGraphics(void);
        ~cEntityManagerGraphics(void);
        
        // Public members
        sEntityGraphics *getNew(void);
        sEntityGraphics *getFirst(void);
        
        // Public member functions
        void initialize(void);
        void terminate(void);

};

#endif // ENTITY_MANAGER_GRAPHICS_HPP
