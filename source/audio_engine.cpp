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
 
#include "audio_engine.hpp"

cAudioEngine::cAudioEngine(void)
{
    
};

cAudioEngine::~cAudioEngine(void)
{
    
};

void cAudioEngine::setEntityHandle(sEntityAudio *_entity)
{
    m_entityFirst = _entity;
}

void cAudioEngine::initialize(void)
{
    m_device = alcOpenDevice(nullptr);
    if (m_device != nullptr)
    {
        gLogWrite(LOG_INFO, "Started audio device: " + std::string(alcGetString(m_device, ALC_DEVICE_SPECIFIER)), __FILE__, __LINE__, __FUNCTION__);
        m_context = alcCreateContext(m_device, nullptr);
        if (alcMakeContextCurrent(m_context))
        {
            alListener3f(AL_POSITION, m_listener.position.x, m_listener.position.y, m_listener.position.z);
            alListener3f(AL_VELOCITY, m_listener.velocity.x, m_listener.velocity.y, m_listener.velocity.z);
            alListenerfv(AL_ORIENTATION, m_listener.orientation);
            
            ALCint alcMajorVersion;
            ALCint alcMinorVersion;
            alcGetIntegerv(m_device, ALC_MAJOR_VERSION, 1, &alcMajorVersion);
            alcGetIntegerv(m_device, ALC_MINOR_VERSION, 1, &alcMinorVersion);
            gLogWrite(LOG_INFO, "OpenAL Version: " + std::to_string(alcMajorVersion) + "." + std::to_string(alcMinorVersion), __FILE__, __LINE__, __FUNCTION__);
            
        }
        else
        {
            gLogWrite(LOG_ERROR, "Failed to create audio context.", __FILE__, __LINE__, __FUNCTION__);
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to open audio device.", __FILE__, __LINE__, __FUNCTION__);
    }

    checkAudioError();
}

void cAudioEngine::terminate(void)
{
    m_sourceManager.freeAudioSources();
    m_bufferManager.freeAudioBuffers();
    m_context = alcGetCurrentContext();
    m_device = alcGetContextsDevice(m_context);
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(m_context);
    alcCloseDevice(m_device);
}

void cAudioEngine::loadBufferWav(uint32_t _ID, const std::string &_fileName)
{
    sAudioData *audioData = new sAudioData;
    loadWav(_fileName, audioData);
    alBufferData(_ID, audioData->audioFormat, audioData->buffer, audioData->bufferSize, audioData->sampleRate);
    delete[] audioData->buffer;
    delete audioData;
}

void cAudioEngine::loadBufferOgg(uint32_t _ID, const std::string &_fileName)
{
    sAudioData *audioData = new sAudioData;
    loadOgg(_fileName, audioData);
    alBufferData(_ID, audioData->audioFormat, audioData->buffer, audioData->bufferSize, audioData->sampleRate);
    delete[] audioData->buffer;
    delete audioData;
}

void cAudioEngine::setAudioBufferName(uint32_t _ID, const std::string &_name)
{
    sAudioBuffer* tB = m_bufferManager.findAudioBuffer(_ID);
    if (tB == nullptr) return;
    tB->nameLength = _name.length();
    if (tB->name != nullptr)
        delete[] tB->name;
    tB->name = new char[tB->nameLength];
    for (uint32_t i = 0; i < tB->nameLength; i++)
        tB->name[i] = _name[i];
}

void cAudioEngine::process(void)
{
    for (m_entityTemp = m_entityFirst; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        
    }
    
    sAudioSource *tSource = m_sourceManager.getHead();
    for (; tSource != nullptr; tSource = tSource->next)
    {
        alGetSourcei(tSource->ID, AL_SOURCE_STATE, &tSource->state);
    }

}
