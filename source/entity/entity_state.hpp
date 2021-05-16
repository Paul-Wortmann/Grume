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

#ifndef ENTITY_STATE_HPP
#define ENTITY_STATE_HPP

#include "../includes.hpp"

struct sEntityState
{
    // Infomation
    std::string   name          = "";

    // Animation (start, end, repeat)
    glm::vec3     animation     = glm::vec3(0, 0, 0);

    // SoundFX
    std::string   audioFile     = ""; // Audio source File name
    std::uint32_t audioSourceID = 0;  // Audio source
    std::uint32_t auidoBufferID = 0;  // Audio buffer
};

#endif // ENTITY_STATE_HPP

