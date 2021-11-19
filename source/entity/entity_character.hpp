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

#ifndef ENTITY_CHARACTER_HPP
#define ENTITY_CHARACTER_HPP

#include "../core/includes.hpp"

#include "entity_character_attributes.hpp"
#include "entity_character_drop.hpp"
#include "entity_character_skills.hpp"

struct sCharacterLevel
{
    uint32  current        = 0;          // Current level
    uint32  max            = 10;         // Max level

    uint64  exp            = 0;          // Current experience
    uint64  expNext        = 1024;       // Experience for next level
    float32 expMultiplier  = 1.5f;       // Experience multiplier
    uint64  expMax         = UINT64_MAX; // Max experence
};

struct sEntityCharacter
{
    sCharacterLevel   level      = {};
    sEntityCharAttrib attributes = {};
    sEntityCharSkill  skills     = {};
    sEntityCharDrop   drop       = {};
};

#endif // ENTITY_CHARACTER_HPP

