
#include "audio_buffer_manager.hpp"

void cAudioBufferManager::initialize(void)
{

}

void cAudioBufferManager::terminate(void)
{
    m_freeAll();
}

void cAudioBufferManager::m_freeData(sAudioBuffer*& _pointer)
{
    alDeleteBuffers(1, &_pointer->ID);
}

void cAudioBufferManager::m_freeAll(void)
{
    for (sAudioBuffer* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

sAudioBuffer* cAudioBufferManager::newAudioBuffer(void)
{
    sAudioBuffer* rBuffer = getNew();
    alGenBuffers(1, &rBuffer->ID);
    return rBuffer;
}

sAudioBuffer* cAudioBufferManager::findAudioBuffer(const std::string &_name)
{
    for (sAudioBuffer* tBuffer = getHead(); tBuffer != nullptr; tBuffer = tBuffer->next)
    {
        if (tBuffer->name.compare(_name) == 0)
        {
        return tBuffer;
        }
    }
    return nullptr;
}

sAudioBuffer* cAudioBufferManager::findAudioBuffer(uint32_t _ID)
{
    for (sAudioBuffer* tBuffer = getHead(); tBuffer != nullptr; tBuffer = tBuffer->next)
    {
        if (tBuffer->ID == _ID)
        {
        return tBuffer;
        }
    }
    return nullptr;
}

