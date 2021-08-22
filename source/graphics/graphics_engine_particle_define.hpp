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

#ifndef GRAPHICS_ENGINE_PARTICLE_DEFINE_HPP
#define GRAPHICS_ENGINE_PARTICLE_DEFINE_HPP

#include "../core/includes.hpp"

struct sParticle
{
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);
    float32   size     = 0.0f;
    float32   angle    = 0.0f;
    float32   weight   = 0.0f;
    float32   life     = 0.0f;

    float32   color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
};

#endif //GRAPHICS_ENGINE_PARTICLE_DEFINE_HPP