/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "log.hpp"
#include "config.hpp"
#include "graphics.hpp"
#include "physics.hpp"
#include "network.hpp"
#include "timer.hpp"
#include "sound.hpp"
#include "savegame.hpp"
#include "font.hpp"
#include "menu.hpp"
#include "io.hpp"
#include "background.hpp"
#include "particles.hpp"
#include "map_2D.hpp"

class core_class
{
    public:
        int               GAME_VERSION_MAJOR;
        int               GAME_VERSION_MINOR;
        int               FPS;
        int               LastTicks;
        bool              process_ready;
        int               music_track;
        bool              music_next_track;
        bool              game_paused;
        bool              game_active;
        bool              game_resume;
        bool              menu_active;
        bool              quest_log_active;
        bool              character_active;
        bool              spellbook_active;
        bool              inventory_active;
        bool              equipment_active;
        bool              npcvendor_active;
        bool              pdie_active;
        bool              nlvl_active;
        bool              outr_active;
        bool              status_quit_active;
        int               menu_level;
        save_game_class   save_01;
        save_game_class   save_02;
        save_game_class   save_03;
        save_game_class   save_04;
        save_game_class   save_05;
        save_game_class   save_06;
        save_game_class   save_07;
        io_type           io;
        SDL_Event         event;
        log_file_class    log;
        config_file_class config;
        graphics_class    graphics;
        physics_class     physics;
        network_class     network;
        timer_class       timer;
        background_class  background;
        emitter_class     emitter[MAX_EMITTERS];
         core_class(void);
        ~core_class(void);
};


#endif //CORE_H
