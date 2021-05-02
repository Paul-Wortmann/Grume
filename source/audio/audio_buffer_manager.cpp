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

