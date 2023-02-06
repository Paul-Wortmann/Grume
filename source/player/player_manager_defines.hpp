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

#ifndef PLAYER_MANAGER_DEFINES_HPP
#define PLAYER_MANAGER_DEFINES_HPP

#include "../core/includes.hpp"

#include "../audio/audio_engine.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../map/map_manager_defines.hpp"
#include "../physics/physics_collision.hpp"
#include "../resource/database_manager.hpp"
#include "../ui/ui_manager.hpp"

#include "player_storage.hpp"

// Event type enum
enum ePlayerEventType : std::uint32_t
{
    playerEventType_none        = 0,    // null event
    playerEventType_newPosition = 1     // player has been repositioned
};

// Event struct
struct sPlayerEvent
{
    sPlayerEvent*      next = nullptr;
    ePlayerEventType   type = ePlayerEventType::playerEventType_none;
    std::uint32_t      data = 0;
};

#endif // PLAYER_MANAGER_DEFINES_HPP
