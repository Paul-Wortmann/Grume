


#ifndef AUDIO_BUFFER_MANAGER_HPP
#define AUDIO_BUFFER_MANAGER_HPP

#include "../includes.hpp"
#include "../linked_list.hpp"
#include "audio_defines.hpp"

class cAudioBufferManager : public tcLinkedList<sAudioBuffer>
{
    public:
        void initialize(void);
        void terminate(void);
        sAudioBuffer* newAudioBuffer(void);
        sAudioBuffer* findAudioBuffer(const std::string &_name);
        sAudioBuffer* findAudioBuffer(uint32_t _ID);
        
    protected:
        
    private:
        void m_freeAll(void);
        void m_freeData(sAudioBuffer*& _pointer);
};

#endif //AUDIO_BUFFER_MANAGER_HPP
