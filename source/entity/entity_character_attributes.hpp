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

#ifndef ENTITY_CHARACTER_ATTRIBUTES_HPP
#define ENTITY_CHARACTER_ATTRIBUTES_HPP

#include "../core/includes.hpp"

struct sCharacterAttributeRegen
{
    std::uint32_t max            = 0;     // Maximum
    std::uint32_t current        = 0;     // Current
    float32       regen          = 0.0f;  // Amount per second
};

struct sCharacterAttributeDamage
{
    std::uint32_t base           = 0;     // Base damage
    float32       critMultiplier = 0.0f;  // Critical hit multiplier
    std::uint32_t critChancev    = 0;     // Critical hit chance
};

struct sCharacterAttributeArmor
{
    std::uint32_t base           = 0;     // Base armor
};

struct sEntityCharAttrib // Character attributes
{
    // Depletable types
    sCharacterAttributeRegen  health         = {};
    sCharacterAttributeRegen  mana           = {};
    
    // Damage types
    sCharacterAttributeDamage damagePhysical = {};
    sCharacterAttributeDamage damageFire     = {};
    sCharacterAttributeDamage damageFrost    = {};
    
    // Armor types
    sCharacterAttributeArmor armorPhysical   = {};
    sCharacterAttributeArmor resistanceFire  = {};
    sCharacterAttributeArmor resistanceFrost = {};
    
    // gen points with base attack, when enough spend points on uber attack
    // 
};

#endif // ENTITY_CHARACTER_ATTRIBUTES_HPP

