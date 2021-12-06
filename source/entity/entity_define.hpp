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

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../core/includes.hpp"
#include "entity_ai.hpp"
#include "entity_character.hpp"
#include "entity_collision.hpp"
#include "entity_interaction.hpp"
#include "entity_material.hpp"
#include "entity_model.hpp"
#include "entity_movement.hpp"
#include "entity_physics.hpp"
#include "entity_state.hpp"

enum eEntityOwner: uint16
{
    ownerNone = 0,
    ownerUI   = 1,
    ownerMap  = 2
};

enum eEntityType: uint16
{
    entityTypeOther     = 0,
    entityTypeStatic    = 1,
    entityTypeObject    = 2,
    entityTypeNPCmob    = 3,
    entityTypeNPC       = 4
};

struct sEntity
{
    // Linked list
    sEntity*            next                 = nullptr;
    uint32              UID                  = 0;

    // Infomation
    std::string         name                 = "";
    bool                enabled              = true;
    eEntityType         type                 = eEntityType::entityTypeStatic;
    eEntityOwner        owner                = eEntityOwner::ownerNone;
    uint32              tile                 = 0; // Current tile

    // Base
    glm::vec3           position             = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3           scale                = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3           rotation             = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3           rotationOffset       = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::ivec3          rotationAxis         = glm::ivec3(0, 1, 0);

    // Animation (per entity, not shared)
    bool                animationIndependent = false;
    uint32              numBones             = 0;
    glm::mat4*          boneTransform        = nullptr;

    uint32              currentAnimation     = 0;
    float64             previousAnimTime     = 0.0;
    float64             currentAnimTime      = 0.0;
    float64             stopAnimTime         = 0.0;
    float64             startAnimTime        = 0.0;
    bool                repeatAnimation      = false;
    bool                finishedAnimation    = true;

    // Graphics
    sEntityModel*       model                = nullptr; // (Entity shared animation data)
    glm::mat4           modelMatrix          = glm::mat4(1);
    sEntityMaterial*    material             = nullptr;

    // Collision
    sEntityCollision*   collision            = nullptr;

    // State
    uint32              stateCount           = 0;
    uint32              stateInitial         = 0;
    uint32              stateCurrent         = 0;
    sEntityState*       state                = nullptr;
    bool                terminate            = false;

    // AI
    sEntityAI*          ai                   = nullptr;
    
    // Character - player
    sEntityCharacter*   character            = nullptr;
    
    // Interaction
    sEntityInteraction* interaction          = nullptr;
    uint32              triggerTile          = 0; // Trigger tile on interaction, 0 for none

    // Pathing
    sEntityMovement*    movement             = nullptr;

    // Physics
    sEntityPhysics*     physics              = nullptr;
    
    // Screen shake on death
    uint32              deathShakeChance     = 100;
    uint32              deathShakeDuration   = 2000;
    float32             deathShakeForce      = 0.5f;
};

#endif //ENTITY_HPP

