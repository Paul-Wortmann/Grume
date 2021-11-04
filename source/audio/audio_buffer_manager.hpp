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

#ifndef AUDIO_BUFFER_MANAGER_HPP
#define AUDIO_BUFFER_MANAGER_HPP

#include "../core/includes.hpp"
#include "../core/linked_list.hpp"
#include "audio_defines.hpp"

class cAudioBufferManager : public tcLinkedList<sAudioBuffer>
{
    public:
        void initialize(void);
        void terminate(void);
        sAudioBuffer* newAudioBuffer(void);
        sAudioBuffer* findAudioBuffer(const std::string &_name);
        sAudioBuffer* findAudioBuffer(const std::uint32_t &_ID);
        
    protected:
        
    private:
        void m_freeAll(void);
        void m_freeData(sAudioBuffer*& _pointer);
};

#endif //AUDIO_BUFFER_MANAGER_HPP
