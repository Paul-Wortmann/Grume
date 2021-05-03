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

#ifndef ENTITY_MODEL_HPP
#define ENTITY_MODEL_HPP

#include "../includes.hpp"
#include "entity_animation.hpp"
#include "entity_bone.hpp"
#include "entity_material.hpp"
#include "entity_mesh.hpp"

struct sEntityModel
{
    // Linked list management
    sEntityModel*     next             = nullptr;

    // Information
    bool              animated         = false;
    bool              animProcessed    = false; // Prevent advancing the animation multiple times per frame.
    std::string       fileName         = {};

    // Mesh
    uint32            numMesh          = 0;
    sEntityMesh*      mesh             = nullptr;

    // Bones
    glm::mat4         inverseTransform = glm::mat4(1); // global inverse transformation matrix
    uint32            numBones         = 0;
    sEntityBone*      bone             = nullptr;

    // Animation
    uint32            numAnimations    = 0;
    sEntityAnimation* animation        = nullptr;
    uint32            currentAnimation = 0;
};

#endif // ENTITY_MODEL_HPP
