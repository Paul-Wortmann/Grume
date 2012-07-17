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

#ifndef GAME_H
#define GAME_H

#include "core/core.hpp"
#include "core/menu.hpp"
#include "core/savegame.hpp"
#include "items.hpp"
#include "language.hpp"
#include "resources.hpp"
#include "menu_system.hpp"
#include "player.hpp"
#include "npc.hpp"
#include "spells.hpp"
#include "UI.hpp"

#define STATE_QUIT 0
#define STATE_MENU 1
#define STATE_GAME 2

struct zoom_type
{
    float            current;
    float            max;
    float            min;
    float            speed;
};

class game_class
{
    private:
    public:
        int               event;
        int               state;
        save_game_class   save_01;
        save_game_class   save_02;
        save_game_class   save_03;
        save_game_class   save_04;
        save_game_class   save_05;
        save_game_class   save_06;
        save_game_class   save_07;
        core_class        core;
        resource_class    resource;
        zoom_type         zoom;
        player_class      player;
        npc_class         npc;
        light_type        global_ambient;
        light_type        world_ambient;
        spell_class       spell[MAX_SPELLS];
        item_class        item [MAX_ITEMS];
        UI_class          UI;
        language_class    language;
        menu_system_class menu;
        game_class(void);
        void             init(void);
        void             process(void);
        void             render(void);
};

#endif //GAME_H

