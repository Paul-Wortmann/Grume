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

#ifndef ENTITY_STATE_HPP
#define ENTITY_STATE_HPP

#include "../core/includes.hpp"
#include "entity_audio.hpp"
#include "entity_physics.hpp"

enum eEntityState : std::uint32_t
{
    entityState_none     = 0,    // none
    entityState_attack   = 1,    // attack
    entityState_defend   = 2,    // defend
    entityState_die      = 3,    // die
    entityState_idle     = 4,    // idle
    entityState_interact = 5,    // interact
    entityState_move     = 6,    // move
    entityState_spawn    = 7,    // spawn
    entityState_open     = 8,    // open
    entityState_close    = 9,    // close
    entityState_levelUp  = 10    // level up state
};

struct sEntityStateData
{
    // Audio
    sEntityAudioData audio         = {};

    // Object physics state
    ePhysicsType     physicsState  = ePhysicsType::physicsTypeIgnore; // ePhysicsType::physicsTypeIgnore

    // Object tile state
    bool             tileCollision = false;

    // Animation (start, end, repeat)
    glm::vec3        animation     = glm::vec3(0, 0, 0);
};

struct sEntityState
{
    eEntityState     stateInitial  = eEntityState::entityState_none;
    eEntityState     stateCurrent  = eEntityState::entityState_none;
    bool             terminate     = false;

    sEntityStateData attack        = {};
    sEntityStateData defend        = {};
    sEntityStateData die           = {};
    sEntityStateData idle          = {};
    sEntityStateData interact      = {};
    sEntityStateData move          = {};
    sEntityStateData spawn         = {};
    sEntityStateData open          = {};
    sEntityStateData close         = {};
    sEntityStateData levelUp       = {};
};

#endif // ENTITY_STATE_HPP

