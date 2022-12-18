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

#ifndef ENTITY_BASE_HPP
#define ENTITY_BASE_HPP

#include "entity_particle.hpp"
#include "../core/includes.hpp"

enum eEntityType  : std::uint32_t { entityType_none             =  0,    // none
                                    entityType_player           =  1,    // player
                                    entityType_objectDynamic    =  2,    // object dynamic
                                    entityType_objectStatic     =  3,    // object static
                                    entityType_objectDynamicLow =  4,    // object dynamic, low
                                    entityType_objectStaticLow  =  5,    // object static, low
                                    entityType_npc              =  6,    // npc
                                    entityType_npc_fly          =  7,    // npc flying
                                    entityType_npc_boss         =  8,    // npc boss
                                    entityType_npc_trader       =  9,    // npc trader
                                    entityType_npc_quest        = 10,    // npc quest
                                    entityType_floor            = 11,    // floor
                                    entityType_wallHigh         = 12,    // wall high
                                    entityType_wallLow          = 13,    // wall low
                                    entityType_wallHole         = 14,    // wall hole
                                    entityType_particle         = 15 };  // particle

enum eEntityOwner : std::uint32_t { entityOwner_none     = 0,    // none
                                    entityOwner_player   = 1,    // player
                                    entityOwner_map      = 2,    // map
                                    entityOwner_particle = 3 };  // particle engine

struct sEntityBase
{
    std::string     name            = {};
    bool            enabled         = true;
    bool            dying           = false;
    bool            inRnge          = true;
    eEntityType     type            = eEntityType::entityType_none;
    eEntityOwner    owner           = eEntityOwner::entityOwner_none;
    std::uint32_t   tileOnMap       = 0;

    bool            flyOver         = false; // This entity can be flown over
    bool            flying          = false; // This entity can fly
    bool            overSize        = false; // This entity is larger than a doorway
    float           flexibility     = 0.0f;  // How much the entity is affected by wind, etc..

    std::uint32_t   hitPoints       = 40; // Used for objects that can take damage
    std::string     debris          = {};
    bool            clicked         = false;
	bool            destructible    = false;
	bool            collectable     = false;
	bool            interactable    = false;
	eParticleType   particleType    = eParticleType::particleType_blood; // blood
	float           particleHeight  = 0.0f; // spawn offset y axis

    bool            textActive      = false;
    bool            textHover       = false;
    std::string     textData        = {};
    glm::vec3       textColor       = glm::vec3(1.0f, 1.0f, 1.0f);
    // timer / transparency / fade out?

    std::uint32_t   deathShakeChance   = 0;
    std::uint32_t   deathShakeDuration = 0;
    float           deathShakeForce    = 0;

    glm::vec3       position        = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3       rotation        = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3       rotationOffset  = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3       rotationAxis    = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3       scale           = glm::vec3(1.0f, 1.0f, 1.0f);

    bool            initialized     = false;
    bool            hasFunction     = false;
};

#endif // ENTITY_BASE_HPP
