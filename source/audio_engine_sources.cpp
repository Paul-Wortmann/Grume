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

#include "audio_engine_sources.hpp"

sAudioSource* cAudioEngineSourceManager::newAudioSource(void)
{
    audioSourceCount++;
    if (m_head == nullptr)
    {
        m_head = new sAudioSource;
        alGenSources(1, &m_head->ID);
        return m_head;
    }
    else
    {
        sAudioSource *tAudioSource = m_head;
        for (tAudioSource = m_head; tAudioSource->next != nullptr; tAudioSource = tAudioSource->next);
        tAudioSource->next = new sAudioSource;
        alGenSources(1, &tAudioSource->next->ID);
        return tAudioSource->next;
    }
}

void cAudioEngineSourceManager::freeAudioSources(void)
{
    sAudioSource *tAudioSource = m_head;
    while (tAudioSource != nullptr)
    {
        sAudioSource *tAudioSourcePrevious = tAudioSource;
        tAudioSource = tAudioSource->next;

        alDeleteSources(1, &tAudioSourcePrevious->ID);

        delete tAudioSourcePrevious;
    }
}
