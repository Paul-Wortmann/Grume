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

#ifndef ENTITY_AI_HPP
#define ENTITY_AI_HPP

#include "../core/includes.hpp"

enum class eEntityAttack : std::uint16_t 
    { 
        entityAttackNone      = 0, // None
        entityAttackAgressive = 1, // Agressive
        entityAttackCasual    = 2  // Casual
    };

enum class eEntityDefence : std::uint16_t 
    { 
        entityDefenceNone   = 0, // None
        entityDefenceShield = 1  // Shield
    };

enum class eEntityMovement : std::uint16_t 
    { 
        entityMovementNone   = 0, // None
        entityMovementCharge = 1, // Charge
        entityMovementFlee   = 2, // Flee
        entityMovementCircle = 3, // Circle
        entityMovementAvoid  = 4  // Avoid
    };

enum class eEntitySocial : std::uint16_t 
    { 
        entitySocialNone   = 0, // None
        entitySocialSwarm  = 1, // Swarm 
        entitySocialLead   = 2, // Lead
        entitySocialFollow = 3  // Follow
    };

struct sEntityAI
{
    eEntityAttack   attack   = eEntityAttack::entityAttackAgressive;
    eEntityDefence  defence  = eEntityDefence::entityDefenceShield;
    eEntityMovement movement = eEntityMovement::entityMovementCharge;
    eEntitySocial   social   = eEntitySocial::entitySocialNone;
};

#endif // ENTITY_AI_HPP