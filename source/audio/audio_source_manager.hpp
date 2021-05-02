


#ifndef AUDIO_SOURCE_MANAGER_HPP
#define AUDIO_SOURCE_MANAGER_HPP

#include "../includes.hpp"
#include "../linked_list.hpp"
#include "audio_defines.hpp"

class cAudioSourceManager : public tcLinkedList<sAudioSource>
{
    public:
        void initialize(void);
        void terminate(void);
        sAudioSource* newAudioSource(void);
        
    protected:
        
    private:
        void m_freeAll(void);
        void m_freeData(sAudioSource*& _pointer);
};

#endif //AUDIO_SOURCE_MANAGER_HPP
