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

    // Start audio engine
    m_result = ma_engine_init(NULL, &m_engine);
    if (m_result == MA_SUCCESS)
    {
        gLogWrite(LOG_INFO, "Started MiniAudio Version: " + std::string(ma_version_string()), __FILE__, __LINE__, __FUNCTION__);

        return_value = EXIT_SUCCESS;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to start audio engine: " + std::string(ma_result_description(m_result)), __FILE__, __LINE__, __FUNCTION__);
        return_value = EXIT_FAILURE;
    }
    return return_value;
}

void cAudioEngine::terminate(void)
{
    freeAll();
    ma_engine_uninit(&m_engine);
}

void cAudioEngine::freeData(sAudio *&_pointer)
{
    ma_sound_uninit(&_pointer->data);
}

void cAudioEngine::loadSound(const std::string &_fileName, ma_sound &_ma_sound)
{
    std::string fileName = FILE_PATH_SOUND + _fileName;
    m_result = ma_sound_init_from_file(&m_engine, fileName.c_str(), 0, NULL, NULL, &_ma_sound);
    if (m_result != MA_SUCCESS)
    {
        gLogWrite(LOG_ERROR, "Failed to load sound: " + std::string(ma_result_description(m_result)) + " - " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        ma_sound_set_volume(&_ma_sound, static_cast<float>(m_volumeSound) / static_cast<float>(m_volumeMax));
    }
}

void cAudioEngine::playSound(ma_sound &_ma_sound)
{
    m_result = ma_sound_start(&_ma_sound);
    if (m_result != MA_SUCCESS)
    {
        gLogWrite(LOG_ERROR, "Failed to play sound: " + std::string(ma_result_description(m_result)), __FILE__, __LINE__, __FUNCTION__);
    }
}

void cAudioEngine::freeSound(sAudio *&_pointer)
{
    ma_sound_uninit(&_pointer->data);
}

void cAudioEngine::deleteSound(sAudio *&_pointer)
{
    if ((_pointer != nullptr) &&
        (_pointer->data.pDataSource != nullptr))
    {
        ma_sound_uninit(&_pointer->data);
        remove(_pointer);
    }
}

void cAudioEngine::loadMusic(const std::string &_fileName)
{
    // new node if needed
    if (m_music == nullptr)
    {
        m_music = getNew();
    }

    // if data, free first
    else
    {
        freeData(m_music);
    }

    std::string fileName = FILE_PATH_MUSIC + _fileName;
    m_result = ma_sound_init_from_file(&m_engine, fileName.c_str(), 0, NULL, NULL, &m_music->data);
    if (m_result != MA_SUCCESS)
    {
        gLogWrite(LOG_ERROR, "Failed to load music: " + std::string(ma_result_description(m_result)) + " - " + fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        ma_sound_set_volume(&m_music->data, static_cast<float>(m_volumeMusic) / static_cast<float>(m_volumeMax));
        ma_sound_set_looping(&m_music->data, true);
    }
}

void cAudioEngine::playMusic(void)
{
    m_result = ma_sound_start(&m_music->data);
    if (m_result != MA_SUCCESS)
    {
        gLogWrite(LOG_ERROR, "Failed to play music: " + std::string(ma_result_description(m_result)), __FILE__, __LINE__, __FUNCTION__);
    }
}

void cAudioEngine::m_updateVolume(void)
{
    // Master volume
    ma_device* device = ma_engine_get_device(&m_engine);
    m_result = ma_device_set_master_volume(device, static_cast<float>(m_volumeMaster) / static_cast<float>(m_volumeMax));
    if (m_result != MA_SUCCESS)
    {
        gLogWrite(LOG_ERROR, "Failed to set master volume : " + std::string(ma_result_description(m_result)), __FILE__, __LINE__, __FUNCTION__);
    }

    // music volume
    if (m_music != nullptr)
    {
        ma_sound_set_volume(&m_music->data, static_cast<float>(m_volumeMusic) / static_cast<float>(m_volumeMax));
    }

    // sound volumes
    float musicVolume = static_cast<float>(m_volumeMusic) / static_cast<float>(m_volumeMax);
    float soundVolume = static_cast<float>(m_volumeSound) / static_cast<float>(m_volumeMax);
    for (sAudio* tsAudio = getHead(); tsAudio != nullptr; tsAudio = tsAudio->next)
    {
        // music volume
        if (ma_sound_is_looping(&tsAudio->data))
        {
            ma_sound_set_volume(&tsAudio->data, musicVolume);
        }
        // sound volumes
        else
        {
            ma_sound_set_volume(&tsAudio->data, soundVolume);
        }
    }

    // loop through all and set
}
