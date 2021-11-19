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

#ifndef ENTITY_STATE_HPP
#define ENTITY_STATE_HPP

#include "../core/includes.hpp"

struct sEntityState
{
    // Infomation
    string        name          = "";

    // Object tile state
    uint32        tileState     = 1; // eTileBase::tileFloor

    // Animation (start, end, repeat)
    glm::vec3     animation     = glm::vec3(0, 0, 0);

    // SoundFX
    std::string   audioDBname   = "";    // Audio database name
    uint32        audioDBIndex  = 0;     // Audio database index
    bool          audioRepeat   = false; // Audio repeat
    std::string   audioFile     = "";    // Audio source File name
    uint32        audioSourceID = 0;     // Audio source
    uint32        auidoBufferID = 0;     // Audio buffer
};

#endif // ENTITY_STATE_HPP

