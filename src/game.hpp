/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef GAME_H
#define GAME_H

#include <string>
#include <SDL/SDL.h>
#include "language.hpp"
#include "core/core.hpp"
#include "load_resources.hpp"
#include "menu_system.hpp"
#include "UI.hpp"
#include "player.hpp"
#include "spells.hpp"

struct game_type
{
    spell_class      spell[MAX_SPELLS];
    UI_class         UI;
    map_type         map;
    sound_type       sound;
    music_type       music;
    texture_type     texture;
    font_type        font;
    core_class       core;
    language_class   language;
    menu_type        menu;
    menu_class       main_menu;
    menu_class       new_game_menu;
    menu_class       save_menu;
    menu_class       load_menu;
    menu_class       options_menu;
    menu_class       game_over_menu;
    menu_class       pause_menu;
    player_class     player;
};

int   init_game           (bool re_init);
int   process_game        (void);
int   display_game        (void);

bool  boss_level(void);

#endif //GAME_H
