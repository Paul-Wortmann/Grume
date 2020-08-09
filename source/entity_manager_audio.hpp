


#ifndef ENTITY_MANAGER_AUDIO_HPP
#define ENTITY_MANAGER_AUDIO_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity_component_audio.hpp"

// The entity audio manager facilitates the creation and deletion of entity audio components.

class cEntityManagerAudio
{
    private:
        // Linked list pointers
        sEntityAudio *m_first = nullptr;
        sEntityAudio *m_last  = nullptr;
        sEntityAudio *m_temp  = nullptr;

        // Private member variables
        uint32_t m_numEntities = 0;

        // Private member functions
        void m_freeEntities(void);
        void m_freeEntityData(sEntityAudio *_entity);

    protected:

    public:
        cEntityManagerAudio(void);
        ~cEntityManagerAudio(void);
        
        // Public members
        sEntityAudio *getNew(void);
        sEntityAudio *getFirst(void);
        
        // Public member functions
        void initialize(void);
        void terminate(void);

};

#endif // ENTITY_MANAGER_AUDIO_HPP
