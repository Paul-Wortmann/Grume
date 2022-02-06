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
    double                time              = 0;
    glm::vec3             vector            = {};
};

struct sAnimationQuatKey
{
    double                time              = 0;
    glm::quat             quat              = {};
};

struct sAnimationMeshKey
{
    double                time              = 0;
    std::uint32_t         value             = {};
};

struct sAnimationChannel
{
    std::string            name              = "";
    std::int32_t           boneID            = -1;
    std::uint32_t          numPositionKeys   = 0;
    sAnimationVecKey*      positionKey       = nullptr;
    std::uint32_t          numRotationKeys   = 0;
    sAnimationQuatKey*     rotationKey       = nullptr;
    std::uint32_t          numScalingKeys    = 0;
    sAnimationVecKey*      scalingKey        = nullptr;
};

struct sAnimationMeshChannel
{
    std::string            name              = "";
    std::uint32_t          numKeys           = 0;
    sAnimationMeshKey*     meshKey           = nullptr;
};

struct sEntityAnimation
{
    std::string            name              = "";
    std::uint32_t          numChannels       = 0;
    sAnimationChannel*     channel           = nullptr;
    std::uint32_t          numMeshChannels   = 0;
    sAnimationMeshChannel* meshChannel       = nullptr;
    double                 duration          = 0.0; // duration in ticks
    double                 ticksPerSecond    = 0.0;
    double                 timeInSeconds     = 0.0;
    double                 animationTime     = 16.0; // never set this to 0.0 or lower

    double                 previousAnimTime  = 0.0;
    double                 currentAnimTime   = 0.0;
    double                 stopAnimTime      = 0.0;
    double                 startAnimTime     = 0.0;
    bool                   repeatAnimation   = true;
    bool                   finishedAnimation = false;
};

#endif // ENTITY_ANIMATION_HPP
