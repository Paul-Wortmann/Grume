

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

#ifndef AUDIO_ENGINE_TYPES_HPP
#define AUDIO_ENGINE_TYPES_HPP

#include "defines.hpp"
#include "includes.hpp"

struct sListener
{
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);
    float orientation[6] = {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    float gain = 1.0f;
};

struct sAudioData
{
    uint16_t audioFormat = 0;
    uint16_t channels = 2;
    uint32_t sampleRate = 48000;
    uint16_t bitsPerSample = 16;
    char *buffer = nullptr;
    uint64_t bufferSize = 0;
};

#endif // AUDIO_ENGINE_TYPES_HPP
