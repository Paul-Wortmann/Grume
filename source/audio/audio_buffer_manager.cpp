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

#include "audio_buffer_manager.hpp"

void cAudioBufferManager::initialize(void)
{

}

void cAudioBufferManager::terminate(void)
{
    freeAll();
}

void cAudioBufferManager::freeData(sAudioBuffer*& _pointer)
{
    alDeleteBuffers(1, &_pointer->ID);
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

sAudioBuffer* cAudioBufferManager::findAudioBuffer(const std::uint32_t &_ID)
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

