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

#ifndef ENTITY_MODEL_HPP
#define ENTITY_MODEL_HPP

#include "../core/defines_types.hpp"
#include "entity_model_animation.hpp"
#include "entity_model_bone.hpp"
#include "entity_model_mesh.hpp"

enum eUpAxis : uint32_t
{
    xUp   = 0,
    xDown = 1,
    yUp   = 2,
    yDown = 3,
    zUp   = 4,
    zDown = 5
};

struct sEntityModel
{
    // Linked list management
    sEntityModel*          next             = nullptr;
    std::uint32_t          UID              = 0;

    // Information
    std::string            fileName         = {};
    std::string            modelName        = {};
    eUpAxis                upAxis           = eUpAxis::yUp;

    // Animation
    bool                   animated         = false;
    bool                   animProcessed    = false; // Prevent advancing the animation multiple times per frame.
    std::uint32_t          numAnimations    = 0;
    sEntityModelAnimation* animation        = nullptr;
    std::uint32_t          currentAnimation = 0;

    // Bones
    glm::mat4              inverseTransform = glm::mat4(1); // global inverse transformation matrix
    std::uint32_t          numBones         = 0;
    sEntityBone*           bone             = nullptr;

    // Mesh
    std::uint32_t          numMesh          = 0;
    sEntityModelMesh*      mesh             = nullptr;

    glm::mat4*             matrixInstance   = {};
    std::uint32_t          numInstance      = 0;
};

#endif // ENTITY_MODEL_HPP
