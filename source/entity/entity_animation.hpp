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

#ifndef ENTITY_ANIMATION_HPP
#define ENTITY_ANIMATION_HPP

#include "../core/includes.hpp"

struct sAnimationVecKey
{
    float64                time              = 0;
    glm::vec3              vector            = {};
};

struct sAnimationQuatKey
{
    float64                time              = 0;
    glm::quat              quat              = {};
};

struct sAnimationMeshKey
{
    float64                time              = 0;
    uint32                 value             = {};
};

struct sAnimationChannel
{
    string                 name              = "";
    int32                  boneID            = -1;
    uint32                 numPositionKeys   = 0;
    sAnimationVecKey*      positionKey       = nullptr;
    uint32                 numRotationKeys   = 0;
    sAnimationQuatKey*     rotationKey       = nullptr;
    uint32                 numScalingKeys    = 0;
    sAnimationVecKey*      scalingKey        = nullptr;
};

struct sAnimationMeshChannel
{
    string                 name              = "";
    uint32                 numKeys           = 0;
    sAnimationMeshKey*     meshKey           = nullptr;
};

struct sEntityAnimation
{
    string                 name              = "";
    uint32                 numChannels       = 0;
    sAnimationChannel*     channel           = nullptr;
    uint32                 numMeshChannels   = 0;
    sAnimationMeshChannel* meshChannel       = nullptr;
    float64                duration          = 0.0; // duration in ticks
    float64                ticksPerSecond    = 0.0;
    float64                timeInSeconds     = 0.0;
    float64                animationTime     = 16.0; // never set this to 0.0 or lower

    float64                previousAnimTime  = 0.0;
    float64                currentAnimTime   = 0.0;
    float64                stopAnimTime      = 0.0;
    float64                startAnimTime     = 0.0;
    bool                   repeatAnimation   = true;
    bool                   finishedAnimation = false;
};

#endif // ENTITY_ANIMATION_HPP
