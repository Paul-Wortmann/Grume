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

#ifndef ENTITY_PHYSICS_HPP
#define ENTITY_PHYSICS_HPP

#include "../core/includes.hpp"

enum ePhysicsType : std::uint32_t { physicsTypeNone    = 0,
                                    physicsTypeStatic  = 1,
                                    physicsTypeDynamic = 2,
                                    physicsTypeIgnore  = 3 };

enum ePhysicsBoundingVolumeType : std::uint32_t { physicsBoundingVolumeTypeNone    = 0,
                                                  physicsBoundingVolumeTypeAABS    = 1,
                                                  physicsBoundingVolumeTypeCircle  = 2 };

struct sEntityPhysics
{
    bool                       collision          = false;
    bool                       mouseOver          = false;
    float                      radius             = 0.5f;
    glm::vec3                  halfDimentions     = glm::vec3(0.5f, 0.5f, 0.5f);
    float                      halfHeight         = 0.5f;
    float                      mass               = 0.125f;
    float                      acceleration       = 0.25f;
    glm::vec3                  velocity           = glm::vec3(0.0f, 0.0f, 0.0f);
    float                      velocityMax        = 0.95f;
    ePhysicsType               type               = ePhysicsType::physicsTypeNone;
    ePhysicsBoundingVolumeType boundingVolumeType = ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeCircle;

    float                      dammage            = 0.0f;
};

#endif // ENTITY_PHYSICS_HPP
