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

#ifndef ENTITY_CHARACTER_SKILL_HPP
#define ENTITY_CHARACTER_SKILL_HPP

#include "../core/includes.hpp"

struct sCharacterSkillLevel
{
    std::uint32_t        current        = 0;          // Current skill level
    std::uint32_t        max            = 10;         // Max skill level

    std::uint64_t        exp            = 0;          // Current skill experience
    std::uint64_t        expNext        = 1024;       // Experience for next level
    float32              expMultiplier  = 1.5f;       // Experience multiplier
    std::uint64_t        expMax         = UINT64_MAX; // Max skill experence
};


struct sCharacterSkillAttack
{
    std::uint32_t        damage              = 10;     // Maximum damage
    float32              damageMultiplier    = 1.5f;   // Damage multiplier
    std::uint32_t        duration            = 2000;   // Duration in miliseconds
    float32              durationMultiplier  = 1.1f;   // Duration multiplier
    float32              aoe                 = 1.0f;   // Radius for area of effect
    float32              aoeMultiplier       = 1.25f;  // AOE multiplier
    std::uint32_t        numProjectiles      = 1;      // Duration in miliseconds
    float32              numProFloat         = 1.0f;   // Number of projectiles float value
    float32              numProMultiplier    = 1.5f;   // Number of projectiles multiplier

    bool                 enabled        = false;  // Available to the character
    sCharacterSkillLevel level          = {};     // Skill level struct
};

struct sCharacterSkillDefend
{
    std::uint32_t        duration            = 10000;  // Duration in miliseconds
    float32              durationMultiplier  = 1.1f;   // Duration multiplier
    float32              aoe                 = 1.0f;   // Radius for area of effect
    float32              aoeMultiplier       = 1.25f;  // AOE multiplier

    bool                 enabled        = false;  // Available to the character
    sCharacterSkillLevel level          = {};     // Skill level struct
};

struct sEntityCharSkill // Character skills
{
    // Pysical - Meele - Attack skills
    sCharacterSkillAttack   earthquake      = {};

    // Magic - Fire - Attack skills
    sCharacterSkillAttack   fireBall        = {};
    
    // Magic - Forcefield - Defence skills
    sCharacterSkillDefend   forceField      = {};
};

#endif // ENTITY_CHARACTER_SKILL_HPP

