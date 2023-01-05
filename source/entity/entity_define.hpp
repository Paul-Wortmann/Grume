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

#ifndef ENTITY_DEFINE_HPP
#define ENTITY_DEFINE_HPP

#include "entity_ai.hpp"
#include "entity_animation.hpp"
#include "entity_base.hpp"
#include "entity_character.hpp"
#include "entity_footprint.hpp"
#include "entity_graphics.hpp"
#include "entity_interaction.hpp"
#include "entity_item.hpp"
#include "entity_loot.hpp"
#include "entity_movement.hpp"
#include "entity_particle.hpp"
#include "entity_physics.hpp"
#include "entity_quest.hpp"
#include "entity_state.hpp"
#include "entity_tile_collision.hpp"

struct sEntity
{
    // Linked list management
    sEntity*              next          = nullptr;
    std::uint32_t         UID           = 0;

    sEntityAI*            ai            = nullptr;
    sEntityAnimation*     animation     = nullptr;
    sEntityBase           base          = {};
    sEntityCharacter*     character     = nullptr;
    sEntityFootprint*     footprint     = nullptr;
    sEntityGraphics*      graphics      = nullptr;
    sEntityInteraction*   interaction   = nullptr;
    sEntityItem*          item          = nullptr;
    sEntityLoot*          loot          = nullptr;
    sEntityMovement*      movement      = nullptr;
    sEntityParticle*      particle      = nullptr;
    sEntityPhysics*       physics       = nullptr;
    sEntityQuest*         quest         = nullptr;
    sEntityState*         state         = nullptr;
    sEntityTileCollision* tileCollision = nullptr;
};

#endif // ENTITY_DEFINE_HPP
