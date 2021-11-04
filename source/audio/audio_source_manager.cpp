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

#include "audio_source_manager.hpp"

void cAudioSourceManager::initialize(void)
{

}

void cAudioSourceManager::terminate(void)
{
    m_freeAll();
}

void cAudioSourceManager::m_freeData(sAudioSource*& _pointer)
{
    // Remove association with audio buffer
    alSourcei(_pointer->ID, AL_BUFFER, NULL);
}

void cAudioSourceManager::m_freeAll(void)
{
    for (sAudioSource* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        m_freeData(temp);
    }
}

sAudioSource* cAudioSourceManager::newAudioSource(void)
{
    sAudioSource* rSource = getNew();
    alGenSources(1, &rSource->ID);
    return rSource;
}
