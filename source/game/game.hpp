/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "../core/command_line_parser.hpp"
#include "../core/core.hpp"
#include "../core/effect_manager.hpp"
#include "../core/font_manager.hpp"
#include "../core/item_manager.hpp"
#include "../core/map_2D.hpp"
#include "../core/music_manager.hpp"
#include "../core/network.hpp"
#include "../core/savegame.hpp"
#include "../core/sound_manager.hpp"
#include "../core/spell_manager.hpp"
#include "../core/texture_manager.hpp"
#include "../core/types.hpp"
#include "../UI/UI_loading_screen.hpp"
#include "../UI/UI_manager.hpp"
#include "effects.hpp"
#include "items.hpp"
#include "language.hpp"
#include "npc.hpp"
#include "player.hpp"
#include "spells.hpp"

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

struct rumble_type
{
    f2_type counter;
};

class game_class
{
    private:
    public:
        bool                       debug;
        // ----------------------------------------------------------
        command_line_parser_class   command_line;
        core_class                  core;
        effect_class                effect;
        effect_manager_class        effect_manager;
        int                         event;
        font_manager_class          font_manager;
        light_type                  global_ambient;
        item_class                  item;
        item_manager_class          item_manager;
        language_class              language;
        map_2D_class                map_2D;
        music_manager_class         music_manager;
        network_manager_class       network_manager;
        npc_class                   npc;
        player_class                player;
        rumble_type                 rumble;
        save_game_class             save_01;
        save_game_class             save_02;
        save_game_class             save_03;
        save_game_class             save_04;
        save_game_class             save_05;
        save_game_class             save_06;
        save_game_class             save_07;
        spell_class                 spell;
        int                         state;
        sound_manager_class         sound_manager;
        spell_manager_class         spell_manager;
        texture_manager_class       texture_manager;
        UI_loading_screen_class     loading_screen;
        UI_manager_class            UI_manager;
        light_type                  world_ambient;
        zoom_type                   zoom;
        game_class(void);
        void                        init(void);
        void                        process(void);
        void                        render(void);
};

#endif //GAME_H

