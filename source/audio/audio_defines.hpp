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

#ifndef AUDIO_DEFINES_HPP
#define AUDIO_DEFINES_HPP

#include "../core/includes.hpp"

struct sListener
{
    glm::vec3 position       = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 velocity       = glm::vec3(0.0f, 0.0f, 0.0f);
    float     orientation[6] = {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f};
    float     gain           = 1.0f;
};

struct sAudioData
{
    uint16 audioFormat     = 0;
    int32  channels        = 2;
    int64  sampleRate      = 48000;
    int64  bitsPerSample   = 16;
    char*    buffer        = nullptr;
    ALsizei  bufferSize    = 0;
};

struct sAudioBuffer
{
    // Linked list
    sAudioBuffer* next       = nullptr;
    uint32        UID        = 0;

    // Data
    uint32        ID         = 0; // OpenAl ID
    std::string   name       = "";
};

struct sAudioSource
{
    // Linked list
    sAudioSource* next       = nullptr;
    uint32        UID        = 0;

    // Data
    uint32        ID         = 0; // OpenAl ID
    int32         state      = 0;
    float         pitch      = 1.0f;
    float         gain       = 1.0f; // Volume
    bool          looping    = false;
    glm::vec3     position   = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3     velocity   = glm::vec3(0.0f, 0.0f, 0.0f);
};

#endif //AUDIO_DEFINES_HPP


