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

#ifndef PARTICLE_ENGINE_DEFINES_HPP
#define PARTICLE_ENGINE_DEFINES_HPP

#include "../core/includes.hpp"
#include "../entity/entity_define.hpp"
#include "../entity/entity_manager.hpp"
#include "../entity/entity_particle.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../map/map_manager_defines.hpp"
#include "../resource/database_manager.hpp"

struct sParticle
{
    std::string fileName = {};
};

#endif // PARTICLE_ENGINE_DEFINES_HPP
