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

#ifndef GAME_ENGINE_DEFINES_HPP
#define GAME_ENGINE_DEFINES_HPP

#include "includes.hpp"
#include "game_config.hpp"
#include "version.hpp"

#include "../event_manager.hpp"

#include "../animation/animation_engine.hpp"
#include "../audio/audio_engine.hpp"
#include "../entity/entity_manager.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../loot/loot_manager.hpp"
#include "../map/map_manager.hpp"
#include "../npc/npc_manager.hpp"
#include "../object/object_manager.hpp"
#include "../particles/particle_engine.hpp"
#include "../physics/physics_engine.hpp"
#include "../player/player_manager.hpp"
#include "../resource/database_manager.hpp"
#include "../resource/resource_manager.hpp"
#include "../ui/ui_manager.hpp"
#include "../utils/timer.hpp"

enum eEngineState : std::uint32_t {engineStateNone  = 0,
                                   engineStateInit  = 1,
                                   engineStateTerm  = 2,
                                   engineStatePause = 3,
                                   engineStateProc  = 4 };

#endif // GAME_ENGINE_DEFINES_HPP
