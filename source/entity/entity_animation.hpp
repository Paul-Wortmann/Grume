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

struct sEntityAnimation
{
    // Animation (per entity, not shared)
    bool                animationIndependent = false;
    std::uint32_t       numBones             = 0;
    glm::mat4*          boneTransform        = nullptr;

    std::uint32_t       currentAnimation     = 0;
    float               previousAnimTime     = 0.0f;
    float               currentAnimTime      = 0.0f;
    float               stopAnimTime         = 0.0f;
    float               startAnimTime        = 0.0f;
    bool                repeatAnimation      = false;
    bool                finishedAnimation    = true;
};

#endif // ENTITY_ANIMATION_HPP

