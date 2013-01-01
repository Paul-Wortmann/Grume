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

#include "save_data.hpp"
#include "game.hpp"

extern game_class      game;
       save_data_type save_data;

void update_save_data(void)
{
    save_data.save_version = 0.01f;
    /*
    save_data.AB_MS_01     = game.UI.action_bar.menu_slot[ 1].button_type;
    save_data.AB_MS_02     = game.UI.action_bar.menu_slot[ 2].button_type;
    save_data.AB_MS_03     = game.UI.action_bar.menu_slot[ 3].button_type;
    save_data.AB_MS_04     = game.UI.action_bar.menu_slot[ 4].button_type;
    save_data.AB_MS_05     = game.UI.action_bar.menu_slot[ 5].button_type;
    save_data.AB_MS_06     = game.UI.action_bar.menu_slot[ 6].button_type;
    save_data.AB_AS_01     = game.UI.action_bar.action_slot[ 1].button_type;
    save_data.AB_AS_02     = game.UI.action_bar.action_slot[ 2].button_type;
    save_data.AB_AS_03     = game.UI.action_bar.action_slot[ 3].button_type;
    save_data.AB_AS_04     = game.UI.action_bar.action_slot[ 4].button_type;
    save_data.AB_AS_05     = game.UI.action_bar.action_slot[ 5].button_type;
    save_data.AB_AS_06     = game.UI.action_bar.action_slot[ 6].button_type;
    save_data.AB_AS_07     = game.UI.action_bar.action_slot[ 7].button_type;
    save_data.AB_AS_08     = game.UI.action_bar.action_slot[ 8].button_type;
    save_data.AB_AS_09     = game.UI.action_bar.action_slot[ 9].button_type;
    save_data.AB_AS_10     = game.UI.action_bar.action_slot[10].button_type;
    */
};

void update_game_data(void)
{
    /*
    game.UI.action_bar.menu_slot[ 1].button_type       = save_data.AB_MS_01;
    game.UI.action_bar.menu_slot[ 2].button_type       = save_data.AB_MS_02;
    game.UI.action_bar.menu_slot[ 3].button_type       = save_data.AB_MS_03;
    game.UI.action_bar.menu_slot[ 4].button_type       = save_data.AB_MS_04;
    game.UI.action_bar.menu_slot[ 5].button_type       = save_data.AB_MS_05;
    game.UI.action_bar.menu_slot[ 6].button_type       = save_data.AB_MS_06;
    game.UI.action_bar.action_slot[ 1].button_type     = save_data.AB_AS_01;
    game.UI.action_bar.action_slot[ 2].button_type     = save_data.AB_AS_02;
    game.UI.action_bar.action_slot[ 3].button_type     = save_data.AB_AS_03;
    game.UI.action_bar.action_slot[ 4].button_type     = save_data.AB_AS_04;
    game.UI.action_bar.action_slot[ 5].button_type     = save_data.AB_AS_05;
    game.UI.action_bar.action_slot[ 6].button_type     = save_data.AB_AS_06;
    game.UI.action_bar.action_slot[ 7].button_type     = save_data.AB_AS_07;
    game.UI.action_bar.action_slot[ 8].button_type     = save_data.AB_AS_08;
    game.UI.action_bar.action_slot[ 9].button_type     = save_data.AB_AS_09;
    game.UI.action_bar.action_slot[10].button_type     = save_data.AB_AS_10;
    */
};





