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

#include "audio_engine.hpp"

std::uint32_t cAudioEngine::initialize(void)
{
    std::uint32_t return_value = EXIT_SUCCESS;

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
            return_value = EXIT_FAILURE;
            gLogWrite(LOG_ERROR, "Failed to create audio context.", __FILE__, __LINE__, __FUNCTION__);
        }
    }
    else
    {
        return_value = EXIT_FAILURE;
        gLogWrite(LOG_ERROR, "Failed to open audio device.", __FILE__, __LINE__, __FUNCTION__);
    }

    checkAudioError();

    return return_value;
}

void cAudioEngine::terminate(void)
{
    m_bufferManager.terminate();
    m_sourceManager.terminate();
    m_context = alcGetCurrentContext();
    m_device = alcGetContextsDevice(m_context);
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(m_context);
    alcCloseDevice(m_device);
}

void cAudioEngine::m_updateVolume(void)
{
    m_listener.gain = m_volumeMaster / 100.0f;
    alListenerf(AL_GAIN, m_listener.gain);
    for (sAudioSource* temp = m_sourceManager.getHead(); temp != nullptr; temp = temp->next)
    {
        // Determine if the source is looping
        std::int32_t looping = 0;
        alGetSourcei(temp->ID, AL_LOOPING, &looping);
        checkAudioError();

        // Music
        if (looping > 0)
        {
            temp->gain = m_volumeMusic  / 100.0f;
        }
        // SFX
        else
        {
            temp->gain = m_volumeSound  / 100.0f;
        }
        alSourcef(temp->ID, AL_GAIN, temp->gain);
    }
}

void cAudioEngine::loadBufferWav(std::uint32_t _ID, const std::string &_fileName)
{
    sAudioData *audioData = new sAudioData;
    loadWav(_fileName, audioData);
    alBufferData(_ID, audioData->audioFormat, audioData->buffer, audioData->bufferSize, static_cast<ALsizei>(audioData->sampleRate));
    delete[] audioData->buffer;
    delete audioData;
}

void cAudioEngine::loadBufferOgg(std::uint32_t _ID, const std::string &_fileName)
{
    sAudioData *audioData = new sAudioData;
    loadOgg(_fileName, audioData);
    alBufferData(_ID, audioData->audioFormat, audioData->buffer, audioData->bufferSize, static_cast<ALsizei>(audioData->sampleRate));
    delete[] audioData->buffer;
    delete audioData;
}

void cAudioEngine::process(float _dt)
{
    sAudioSource *tSource = m_sourceManager.getHead();
    for (; tSource != nullptr; tSource = tSource->next)
    {
        alGetSourcei(tSource->ID, AL_SOURCE_STATE, &tSource->state);
    }
}

void cAudioEngine::loadMusic(const std::string &_fileName)
{
    // First see if the file is already loaded, if so return the buffer
    for (sAudioBuffer* tBuffer = m_bufferManager.getHead(); tBuffer != nullptr; tBuffer = tBuffer->next)
    {
        if (tBuffer->name.compare(_fileName) == 0)
        {
            m_musicBufferID = tBuffer->ID;
            return;
        }
    }

    // Else create a new buffer and load the file
    sAudioBuffer* tBuffer = m_bufferManager.getNew();
    alGenBuffers(1, &tBuffer->ID);
    tBuffer->name = _fileName;
    loadBufferOgg(tBuffer->ID, FILE_PATH_MUSIC + _fileName);

    m_musicBufferID = tBuffer->ID;
}

void cAudioEngine::playMusic(void)
{
    // If the music source has not yet been created, create it
    if (m_musicSource == nullptr)
    {
        m_musicSource = m_sourceManager.getNew();
        alGenSources(1, &m_musicSource->ID);
    }

    // Stop previous music if it is playing
    stopSource(m_musicSource->ID);

    setAudioSourcePosition(m_musicSource->ID, 0.0f, 0.0f, 0.0f);
    attachSourceBuffer(m_musicSource->ID, m_musicBufferID);
    setAudioSourceLooping(m_musicSource->ID, true);
    playSource(m_musicSource->ID);

    m_musicSource->gain = m_volumeMusic  / 100.0f;
    alSourcef(m_musicSource->ID, AL_GAIN, m_musicSource->gain);
}

std::uint32_t cAudioEngine::loadSound(const std::string &_fileName)
{
    // First see if the file is already loaded, if so return the buffer
    for (sAudioBuffer* tBuffer = m_bufferManager.getHead(); tBuffer != nullptr; tBuffer = tBuffer->next)
    {
        if (tBuffer->name.compare(_fileName) == 0)
        {
            return tBuffer->ID;
        }
    }

    // Else create a new buffer and load the file
    sAudioBuffer* tBuffer = m_bufferManager.getNew();
    alGenBuffers(1, &tBuffer->ID);
    tBuffer->name = _fileName;
    loadBufferOgg(tBuffer->ID, FILE_PATH_SOUND + _fileName);
    return tBuffer->ID;
}

void cAudioEngine::playSound(const std::uint32_t &_bufferID)
{
    // No buffer, early exit
    if (_bufferID == 0)
        return;

    sAudioSource* tSource = nullptr;

    // First see if there is a free audio source, else create a new one
    for (sAudioSource* fSource = m_sourceManager.getHead(); fSource != nullptr; fSource = fSource->next)
    {
        ALenum state;
        alGetSourcei(fSource->ID, AL_SOURCE_STATE, &state);
        if (state != AL_PLAYING)
        {
            tSource = fSource;
            break;
        }
    }

    // If we could't find a free source, create a new one
    if (tSource == nullptr)
    {
        tSource = m_sourceManager.getNew();
    }

    // If no ID, generate one
    if (tSource->ID == 0)
    {
        alGenSources(1, &tSource->ID);
    }

    setAudioSourcePosition(tSource->ID, 0.0f, 0.0f, 0.0f);
    attachSourceBuffer(tSource->ID, _bufferID);
    playSource(tSource->ID);

    tSource->gain = m_volumeSound  / 100.0f;
    alSourcef(tSource->ID, AL_GAIN, tSource->gain);
}




