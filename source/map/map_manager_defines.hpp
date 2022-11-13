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

#ifndef MAP_MANAGER_DEFINES_HPP
#define MAP_MANAGER_DEFINES_HPP

#include "map_define.hpp"
#include "map_utils.hpp"
#include "map_path_a_star_define.hpp"
#include "map_path_a_star.hpp"
#include "../animation/animation_engine.hpp"
#include "../audio/audio_engine.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../player/player_manager.hpp"

// Event type enum
enum sMapManagerEventType : std::uint32_t { sMapManagerEventType_none         = 0,    // null event
                                            sMapManagerEventType_mapWarp      = 1,    // map warp
                                            sMapManagerEventType_mapLoad      = 2,    // map load
                                            sMapManagerEventType_menuActivate = 3 };  // menu activate

// Event struct
struct sMapManagerEvent
{
    sMapManagerEvent*    next = nullptr;
    sMapManagerEventType type = sMapManagerEventType::sMapManagerEventType_none;
    std::uint32_t        data = 0;
    std::string          text = {};
};

#endif // MAP_MANAGER_DEFINES_HPP
