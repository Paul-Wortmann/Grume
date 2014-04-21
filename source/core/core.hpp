/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>

#include "background.hpp"
#include "config.hpp"
#include "file.hpp"
#include "graphics_engine.hpp"
#include "io.hpp"
#include "log.hpp"
#include "math.hpp"
#include "physics.hpp"
#include "timer.hpp"

#define RETURN_FAIL -1

struct core_struct
{
    bool                  debug;
    const char*           application_name;
    const char*           application_icon;
    int                   FPS;
    int                   last_ticks;
    bool                  process_ready;
    bool                  game_paused;
    bool                  game_active;
    bool                  game_resume;
    bool                  game_menu_active;
    bool                  quest_log_active;
    bool                  character_active;
    bool                  skillbook_active;
    bool                  inventory_active;
    bool                  equipment_active;
    bool                  npcvendor_active;
    background_class      background;
    config_class          config;
    file_class            file;
    graphics_engine_class graphics;
    io_class              io;
    log_class             log;
    math_class            math;
    physics_class         physics;
    SDL_Event             event;
    timer_class           timer;
};

#endif //CORE_H


/*
        int               GAME_VERSION_MAJOR;
        int               GAME_VERSION_MINOR;
        bool              pdie_active;
        bool              nlvl_active;
        bool              outr_active;
        int               menu_level;
        network_class     network;
        emitter_class     emitter[MAX_EMITTERS];
        */
