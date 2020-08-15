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

#ifndef AUDIO_ENGINE_SOURCES_HPP
#define AUDIO_ENGINE_SOURCES_HPP

#include "defines.hpp"
#include "includes.hpp"

struct sAudioSource
{
    sAudioSource *next = nullptr;
    uint32_t ID = 0;
    int32_t state = 0;
    float pitch = 1;
    float gain = 1;
    bool loopint = false;
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);
};

class cAudioEngineSourceManager
{
    public:
        cAudioEngineSourceManager(void) = default;
        ~cAudioEngineSourceManager(void) = default;
        cAudioEngineSourceManager(cAudioEngineSourceManager &_other) = delete;
        cAudioEngineSourceManager(const cAudioEngineSourceManager &_other) = delete;
        cAudioEngineSourceManager&operator=(const cAudioEngineSourceManager& other) = delete;

        sAudioSource* newAudioSource(void);
        void freeAudioSources(void);
        sAudioSource* getHead(void) { return m_head;}
        uint32_t audioSourceCount = 0;
    protected:
    private:
        sAudioSource *m_head = nullptr;
};

#endif // AUDIO_ENGINE_SOURCES_HPP
