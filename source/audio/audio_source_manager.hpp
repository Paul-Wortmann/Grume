

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

#ifndef AUDIO_SOURCE_MANAGER_HPP
#define AUDIO_SOURCE_MANAGER_HPP

#include "../includes.hpp"
#include "../linked_list.hpp"
#include "audio_defines.hpp"

class cAudioSourceManager : public tcLinkedList<sAudioSource>
{
    public:
        void initialize(void);
        void terminate(void);
        sAudioSource* newAudioSource(void);
        
    protected:
        
    private:
        void m_freeAll(void);
        void m_freeData(sAudioSource*& _pointer);
};

#endif //AUDIO_SOURCE_MANAGER_HPP