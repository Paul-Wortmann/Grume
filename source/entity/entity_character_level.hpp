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

#ifndef ENTITY_CHARACTER_LEVEL_HPP
#define ENTITY_CHARACTER_LEVEL_HPP

#include "../core/includes.hpp"

struct sCharacterLevel
{
    std::uint32_t  current        = 0;          // Current level
    std::uint32_t  max            = 10;         // Max level

    std::uint64_t  exp            = 0;          // Current experience
    std::uint64_t  expNext        = 1024;       // Experience for next level
    float          expMultiplier  = 1.5f;       // Experience multiplier
    std::uint64_t  expMax         = UINT64_MAX; // Max experence
};

#endif // ENTITY_CHARACTER_LEVEL_HPP
