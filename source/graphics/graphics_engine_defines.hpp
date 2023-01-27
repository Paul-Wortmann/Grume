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

#ifndef GRAPHICS_ENGINE_DEFINES_HPP
#define GRAPHICS_ENGINE_DEFINES_HPP

#include "../core/includes.hpp"
#include "../core/game_config.hpp"
#include "../entity/entity_define.hpp"
#include "../io/io_define.hpp"
#include "../map/map_define.hpp"
#include "../ui/ui_manager.hpp"
#include "../player/player_storage.hpp"
#include "../resource/resource_manager.hpp"
#include "graphics_engine_camera.hpp"
#include "graphics_engine_debug.hpp"
#include "graphics_engine_light_define.hpp"
#include "graphics_engine_light_manager.hpp"
#include "graphics_engine_shader.hpp"
#include "graphics_engine_utils.hpp"

// Event type enum
enum eGraphicsEventType : std::uint32_t { graphicsEventType_none        = 0,    // null event
                                          graphicsEventType_windowClose = 1 };  // window close event

// Event struct
struct sGraphicsEvent
{
    sGraphicsEvent*    next = nullptr;
    eGraphicsEventType type = eGraphicsEventType::graphicsEventType_none;
    std::uint32_t      data = 0;
};

#endif // GRAPHICS_ENGINE_DEFINES_HPP
