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

enum class eEntityAIState : std::uint16_t
{
    entityAIStateIdle       = 0, // Idle
    entityAIStateAttack     = 1, // Attack
    entityAIStateRetreat    = 2, // Retreat / Flee
    entityAIStatePursue     = 3, // Pursue player / leader npc
    entityAIStatePatrol     = 4, // Patrol
    entityAIStateGoToTile   = 5, // Go to tile
    entityAIStateReturn     = 6, // Return to spawn tile
    entityAIStateCorpse     = 7  // Entity dead, can be revived
};

struct sEntityAIPatrol
{
    std::uint32_t  waypointCount   = 0;
    std::uint32_t  waypointCurrent = 0;
    std::uint32_t *waypoint        = nullptr;
};

struct sEntityAIMinion
{
    std::uint32_t  UID             = 0;       // UID of minion
    void          *entity          = nullptr; // sEntity of minion
};

struct sEntityAILeader
{
    // Minion data
    bool             minionManaged   = true;    // leader manages minion
    std::uint32_t    minionCurrent   = 0;       // current number of minions
    std::uint32_t    minionMax       = 0;       // maximum number of minions to spawn
    std::string      minionName      = {};      // database minion name
    std::uint32_t    minionNumber    = 0;       // database minion number
    sEntityAIMinion *minion          = nullptr; // array of minions

    // Ability data -> move to character skills?
    bool             spawn           = false;   // Leader can spawn minions?
    std::uint32_t    spawnCost       = 1000;    // Spawn mana cost

    bool             revive          = false;   // Leader can revive minions?
    std::uint32_t    reviveCost      = 1000;    // Revive mana cost

    bool             heal            = false;   // Leader can heal minions?
    std::uint32_t    healCost        = 1000;    // Heal mana cost

};

struct sEntityAI
{
    // Information
    std::string      modelAlive          = {};
    std::string      modelCorpse         = {};

    // State
    eEntityAIState   state               = eEntityAIState::entityAIStateIdle;
    bool             stateChange         = false;

    // Characteristics
    float            awareRange          = 10.0f;
    std::uint32_t    lastKnownPlayerTile = 0;
    std::uint32_t    spawnTile           = 0;

    // Attack
    float            attackRange         = 1.0f;
    std::uint32_t    attackFrequency     = 32;
    std::uint32_t    attackCounter       = 0;

    // Movement
    float            moveRange           = 5.0f;    // distance range to initiate pursue player
    float            retreatRange        = 0.95f;   // distance range to initiate retreat
    float            retreatThreshold    = 0.10f;   // % health to initiate retreat
    sEntityAIPatrol *patrol              = nullptr; // patrol a series of waypoints

    // Social
    sEntityAILeader *leader              = nullptr;
    void            *leaderEntity        = nullptr; // sEnitiy pointer to leader
};

#endif // ENTITY_AI_HPP
