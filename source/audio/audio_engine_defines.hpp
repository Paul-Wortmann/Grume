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


#ifndef AUDIO_ENGINE_DEFINES_HPP
#define AUDIO_ENGINE_DEFINES_HPP

#include "../core/defines.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_audio.hpp"
#include "../templates/template_engine.hpp"
#include "audio_defines.hpp"

// Event
enum eEventAudioType : std::uint32_t { eventAudioType_none      = 0,    // null event
                                       eventAudioType_collision = 1 };  // collision event

struct sEventAudioData
{
    eEventAudioType type = eEventAudioType::eventAudioType_none;
    std::uint32_t   x    = 0;
    std::uint32_t   y    = 0;
    std::uint32_t   z    = 0;
};

struct sEventAudio
{
    sEventAudio*       next = nullptr;
    sEventAudioData    data = {};
};

// Other

#endif // AUDIO_ENGINE_DEFINES_HPP
