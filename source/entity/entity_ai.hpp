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

#ifndef ENTITY_AI_HPP
#define ENTITY_AI_HPP

#include "../core/includes.hpp"

enum class eEntityClass : std::uint16_t 
{ 
    entityClassNone       = 0, // None
    entityClassMeele      = 1, // Meele
    entityClassMage       = 2, // Mage
    entityClassRanged     = 3  // Ranged
};

enum class eEntityAttack : std::uint16_t 
{ 
    entityAttackNone      = 0, // None
    entityAttackAgressive = 1, // Agressive
    entityAttackCasual    = 2  // Casual
};

enum class eEntityDefence : std::uint16_t 
{ 
    entityDefenceNone     = 0, // None
    entityDefenceShield   = 1  // Shield
};

enum class eEntityMovement : std::uint16_t 
{ 
    entityMovementNone    = 0, // None
    entityMovementCharge  = 1, // Charge
    entityMovementFlee    = 2, // Flee
    entityMovementCircle  = 3, // Circle
    entityMovementAvoid   = 4  // Avoid
};

enum class eEntitySocial : std::uint16_t 
{ 
    entitySocialNone      = 0, // None
    entitySocialSwarm     = 1, // Swarm 
    entitySocialLead      = 2, // Lead
    entitySocialFollow    = 3  // Follow
};

struct sEntityAIPatrol
{
    std::uint32_t  waypointCount   = 0;
    std::uint32_t  waypointCurrent = 0;
    std::uint32_t *waypoint        = nullptr;
};

struct sEntityAI
{
    // Characteristics
    float           distanceAttack      = 1.0f;
    float           distanceMove        = 5.0f;
    std::uint32_t   lastKnownPlayerTile = 0;
    std::uint32_t   spawnTile           = 0;
    
    // Movement
    sEntityAIPatrol *patrol             = nullptr; // patrol a series of waypoints
    std::uint32_t    followID           = 0;       // 0 == none, else entity ID to follow
    
    // Attack
    std::uint32_t   attackFrequency     = 32;
    std::uint32_t   attackCounter       = 0;
    
    // Enums
    eEntityAttack   attack   = eEntityAttack::entityAttackAgressive;
    eEntityDefence  defence  = eEntityDefence::entityDefenceShield;
    eEntityMovement movement = eEntityMovement::entityMovementCharge;
    eEntitySocial   social   = eEntitySocial::entitySocialNone;
};

#endif // ENTITY_AI_HPP
