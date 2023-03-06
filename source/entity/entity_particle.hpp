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

#ifndef ENTITY_PARTICLE_HPP
#define ENTITY_PARTICLE_HPP

#include "../core/includes.hpp"

enum eParticleType  : std::uint32_t
{
    particleType_none     = 0,    // none
    particleType_blood    = 1,    // blood
    particleType_fire     = 2,    // fire
    particleType_smoke    = 3,    // smoke
    particleType_dust     = 4,    // dust
    particleType_slime    = 5,    // slime
    particleType_ice      = 6     // ice
};

struct sEntityParticle
{
    float life          = 0.0f;
    float accelerationZ = 0.0f;
    float gravity       = 1.0f;
};

#endif // ENTITY_PARTICLE_HPP

