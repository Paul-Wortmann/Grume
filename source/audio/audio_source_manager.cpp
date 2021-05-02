
#include "audio_source_manager.hpp"

void cAudioSourceManager::initialize(void)
{

}

void cAudioSourceManager::terminate(void)
{
    m_freeAll();
}

void cAudioSourceManager::m_freeData(sAudioSource*& _pointer)
{

}

void cAudioSourceManager::m_freeAll(void)
{
    for (sAudioSource* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

sAudioSource* cAudioSourceManager::newAudioSource(void)
{
    sAudioSource* rSource = getNew();
    alGenSources(1, &rSource->ID);
    return rSource;
}
