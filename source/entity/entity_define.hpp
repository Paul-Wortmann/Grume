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
#include "entity_dialog.hpp"
#include "entity_interaction.hpp"
#include "entity_material.hpp"
#include "entity_model.hpp"
#include "entity_movement.hpp"
#include "entity_physics.hpp"
#include "entity_state.hpp"

enum eEntityOwner: std::uint16_t
{
    entityOwnerNone     = 0,
    entityOwnerUI       = 1,
    entityOwnerMap      = 2
};

enum eEntityType: std::uint16_t
{
    entityTypeOther     = 0,
    entityTypeStatic    = 1,
    entityTypeObject    = 2,
    entityTypeNPCmob    = 3,
    entityTypeNPC       = 4,
    entityTypeWall      = 5,
    entityTypeFloor     = 6
};

struct sEntity
{
    // Linked list
    sEntity*            next                 = nullptr;
    std::uint32_t       UID                  = 0;

    // Infomation
    std::string         name                 = {};
    bool                enabled              = true;
    eEntityType         type                 = eEntityType::entityTypeStatic;
    eEntityOwner        owner                = eEntityOwner::entityOwnerNone;
    std::uint32_t       tile                 = 0; // Current tile

    // Base
    glm::vec3           position             = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3           scale                = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3           rotation             = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3           rotationOffset       = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::ivec3          rotationAxis         = glm::ivec3(0, 1, 0);

    // Animation (per entity, not shared)
    bool                animationIndependent = false;
    std::uint32_t       numBones             = 0;
    glm::mat4*          boneTransform        = nullptr;

    std::uint32_t       currentAnimation     = 0;
    double              previousAnimTime     = 0.0;
    double              currentAnimTime      = 0.0;
    double              stopAnimTime         = 0.0;
    double              startAnimTime        = 0.0;
    bool                repeatAnimation      = false;
    bool                finishedAnimation    = true;

    // Graphics
    sEntityModel*       model                = nullptr; // (Entity shared animation data)
    glm::mat4           modelMatrix          = glm::mat4(1);
    sEntityMaterial*    material             = nullptr;

    // Collision
    sEntityCollision*   collision            = nullptr;

    // State
    std::uint32_t       stateCount           = 0;
    std::uint32_t       stateInitial         = 0;
    std::uint32_t       stateCurrent         = 0;
    sEntityState*       state                = nullptr;
    bool                terminate            = false;

    // AI
    sEntityAI*          ai                   = nullptr;
    
    // Character - player
    sEntityCharacter*   character            = nullptr;
    
    // Dialog
    sEntityDialog*      dialog               = nullptr;
    
    // Interaction
    sEntityInteraction* interaction          = nullptr;
    std::uint32_t       triggerTile          = 0; // Trigger tile on interaction, 0 for none

    // Pathing
    sEntityMovement*    movement             = nullptr;

    // Physics
    sEntityPhysics*     physics              = nullptr;
    
    // Screen shake on death
    std::uint32_t       deathShakeChance     = 100;
    std::uint32_t       deathShakeDuration   = 2000;
    float               deathShakeForce      = 0.5f;
};

#endif //ENTITY_HPP

