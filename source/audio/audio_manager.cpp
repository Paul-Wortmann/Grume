/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "audio_manager.hpp"

void cAudioManager::initialize(void)
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
            m_sourceManager.initialize();
            m_bufferManager.initialize();
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

void cAudioManager::terminate(void)
{
    m_sourceManager.terminate();
    m_bufferManager.terminate();
    m_context = alcGetCurrentContext();
    m_device = alcGetContextsDevice(m_context);
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(m_context);
    alcCloseDevice(m_device);
    m_freeAll();
}

void cAudioManager::m_freeData(sEntityAudio*& _pointer)
{
    
}

void cAudioManager::m_freeAll(void)
{
    for (sEntityAudio* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        m_freeData(temp);
    }
}

void cAudioManager::loadBufferWav(uint32_t _ID, const std::string &_fileName)
{
    sAudioData *audioData = new sAudioData;
    loadWav(_fileName, audioData);
    alBufferData(_ID, audioData->audioFormat, audioData->buffer, audioData->bufferSize, static_cast<ALsizei>(audioData->sampleRate));
    delete[] audioData->buffer;
    delete audioData;
}

void cAudioManager::loadBufferOgg(uint32_t _ID, const std::string &_fileName)
{
    sAudioData *audioData = new sAudioData;
    loadOgg(_fileName, audioData);
    alBufferData(_ID, audioData->audioFormat, audioData->buffer, audioData->bufferSize, static_cast<ALsizei>(audioData->sampleRate));
    delete[] audioData->buffer;
    delete audioData;
}

void cAudioManager::setAudioBufferName(uint32_t _ID, const std::string &_name)
{
    sAudioBuffer* tB = m_bufferManager.findAudioBuffer(_ID);
    if (tB == nullptr)
        return;
    tB->name = _name;
}

void cAudioManager::process(float32 _dt)
{


    sAudioSource *tSource = m_sourceManager.getHead();
    for (; tSource != nullptr; tSource = tSource->next)
    {
        alGetSourcei(tSource->ID, AL_SOURCE_STATE, &tSource->state);
    }

}
