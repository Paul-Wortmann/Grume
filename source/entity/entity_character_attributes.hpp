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
    float max            = 100;     // Maximum
    float current        = 100;     // Current
    float regen          = 0.025f;  // Amount per second
};

struct sCharacterAttributeDamage
{
    float base           = 1.0f;    // Base damage
    float critMultiplier = 0.25f;   // Critical hit multiplier
    float critChance     = 1.0f;    // Critical hit chance
};

struct sCharacterAttributeArmor
{
    float base           = 1.0f;    // Base armor
};

struct sEntityCharAttrib // Character attributes
{
    // Core stats / attributes
    std::uint32_t pointsOnLevel    = 5; // Attribute points awarded each level
    std::uint32_t pointsCurrent    = 0; // unspent attribute points
    std::uint32_t strength         = 0;
    std::uint32_t dexterity        = 0;
    std::uint32_t vitality         = 0;
    std::uint32_t energy           = 0;

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

};

#endif // ENTITY_CHARACTER_ATTRIBUTES_HPP

/*

   passive skill: (augment attack)
     imbue -> weapon / spell with attribute, ie. fire
     increase projectile count / damage -> weapon / spell with attribute, ie. fire
     regen health / mana speed.


*/


