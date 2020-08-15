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
 
#include "audio_engine_buffers.hpp"

sAudioBuffer* cAudioEngineBufferManager::findAudioBuffer(const std::string &_name)
{
    if (m_head == nullptr)
        return nullptr;
    sAudioBuffer *tAudioBuffer = m_head;
    for (; tAudioBuffer != nullptr; tAudioBuffer = tAudioBuffer->next)
    {
        if ((tAudioBuffer->name != nullptr) && (_name.length() == tAudioBuffer->nameLength))
        {
            bool found = true;
            for (uint32_t i = 0; i < tAudioBuffer->nameLength; i++)
            {
                if (tAudioBuffer->name[i] != _name[i])
                    found = false;
            }
            if (found)
                return tAudioBuffer;
        }
    }
    return nullptr;
}

sAudioBuffer* cAudioEngineBufferManager::findAudioBuffer(uint32_t _ID)
{
    if (m_head == nullptr)
        return nullptr;
    sAudioBuffer *tAudioBuffer = m_head;
    for (; tAudioBuffer != nullptr; tAudioBuffer = tAudioBuffer->next)
    {
        if (tAudioBuffer->ID == _ID)
            return tAudioBuffer;
    }
    return nullptr;
}

sAudioBuffer* cAudioEngineBufferManager::newAudioBuffer(void)
{
    audioBufferCount++;
    if (m_head == nullptr)
    {
        m_head = new sAudioBuffer;
        alGenBuffers(1, &m_head->ID);
        return m_head;
    }
    else
    {
        sAudioBuffer *tAudioBuffer = m_head;
        for (tAudioBuffer = m_head; tAudioBuffer->next != nullptr; tAudioBuffer = tAudioBuffer->next);
        tAudioBuffer->next = new sAudioBuffer;
        alGenBuffers(1, &tAudioBuffer->next->ID);
        return tAudioBuffer->next;
    }
}

void cAudioEngineBufferManager::freeAudioBuffers(void)
{
    sAudioBuffer *tAudioBuffer = m_head;
    while (tAudioBuffer != nullptr)
    {
        sAudioBuffer *tAudioBufferPrevious = tAudioBuffer;
        tAudioBuffer = tAudioBuffer->next;
        if (tAudioBufferPrevious->name != nullptr)
            delete[] tAudioBufferPrevious->name;
        alDeleteBuffers(1, &tAudioBufferPrevious->ID);

        delete tAudioBufferPrevious;
    }
}
