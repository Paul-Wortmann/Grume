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

}

void cAudioSourceManager::m_freeAll(void)
{
    for (sAudioSource* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

sAudioSource* cAudioSourceManager::newAudioSource(void)
{
    sAudioSource* rSource = getNew();
    alGenSources(1, &rSource->ID);
    return rSource;
}
