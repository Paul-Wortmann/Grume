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

#ifndef ENTITY_FUNCTION_HPP
#define ENTITY_FUNCTION_HPP

#include "../core/includes.hpp"

struct sEntityFunctionData
{
    float         activationRange = 2.0f;
    bool          active          = false;
    std::int32_t  repeat          = 0;  // times to repeat, 0 for none, -1 for infinite
    std::uint32_t coolDownCurrent = 0;
    std::uint32_t coolDown        = 64; // 4 times frame rate

    std::uint32_t giveExperience  = 10; // Experience points

    std::uint32_t takeDamage      = 10; // percent
    std::uint32_t giveDamage      = 10; // percent
    std::string   soundFile       = {};

    std::uint32_t warpToMap       = 0; // Map number, 0  for none
    std::uint32_t warpToMapPortal = 0; // Map portal number

    std::uint32_t spawnType      = 0; // 0 for none, 1 for object, 2 for npc, 3 for loot
    std::string   spawnName      = {};
    std::uint32_t spawnNumber    = 1;

    std::uint32_t particleNumber = 0;  // 0 for none
    std::string   particleName   = {};
};

struct sEntityFunction
{
    sEntityFunctionData onClick  = {};
    sEntityFunctionData onDeath  = {};
};

#endif // ENTITY_FUNCTION_HPP

