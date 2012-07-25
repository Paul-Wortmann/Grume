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

#include "menu_system.hpp"
#include "game.hpp"

extern  game_class                game;

void menu_system_class::init(void)
{
    //------ setup menu background -----------
    game.core.background.set_data ( 1, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, game.resource.texture.background_00.ref_number);
    game.core.background.set_data ( 2, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, game.resource.texture.background_00.ref_number);
    game.core.background.set_data ( 3, 1, 0, 0.0f, 0.0f, 0.0010f, 0.00065f, game.resource.texture.background_01.ref_number);
    game.core.background.set_data ( 4, 1, 0, 4.0f, 0.0f, 0.0010f, 0.00065f, game.resource.texture.background_01.ref_number);
    game.core.background.set_movement_type(FRONT_SCROLL);

    //------ setup "system base" menu defaults / initial values-----------
    menu_system_class::mouse_delay.maximum        = 30;
    menu_system_class::event                      = 0;
    menu_system_class::active_menu                = MENU_MAIN;
    menu_system_class::position_x                 = 0.0f;
    menu_system_class::position_y                 = 0.0f;
    menu_system_class::position_z                 = 0.0f;
    menu_system_class::size_x                     = 0.6f;
    menu_system_class::size_y                     = 1.0f;
    menu_system_class::size_z                     = 0.0f;
    menu_system_class::color.normal.r             = 128;
    menu_system_class::color.normal.b             = 128;
    menu_system_class::color.normal.g             = 128;
    menu_system_class::color.normal.a             = 255;
    menu_system_class::color.highlighted.r        = 192;
    menu_system_class::color.highlighted.b        = 192;
    menu_system_class::color.highlighted.g        = 192;
    menu_system_class::color.highlighted.a        = 255;
    menu_system_class::color.disabled.r           = 064;
    menu_system_class::color.disabled.b           = 064;
    menu_system_class::color.disabled.g           = 064;
    menu_system_class::color.disabled.a           = 128;
    menu_system_class::zoom.enabled               = true;
    menu_system_class::zoom.maximum               = 0.02f;
    menu_system_class::zoom.speed                 = 0.004f;
    menu_system_class::texture_ID.angle           = 0.0f;
    menu_system_class::texture_ID.base            = game.resource.texture.background_02.ref_number;
    menu_system_class::texture_ID.normal          = game.resource.texture.button_normal.ref_number;
    menu_system_class::texture_ID.highlighted     = game.resource.texture.button_highlighted.ref_number;
    menu_system_class::texture_ID.disabled        = game.resource.texture.button_disabled.ref_number;

    //------ setup "main" menu -----------
    menu_system_class::menu_main.mouse_delay                          = menu_system_class::mouse_delay;
    menu_system_class::menu_main.color                                = menu_system_class::color;
    menu_system_class::menu_main.zoom                                 = menu_system_class::zoom;
    menu_system_class::menu_main.texture_ID                           = menu_system_class::texture_ID;
    menu_system_class::menu_main.position_x                           = menu_system_class::position_x;
    menu_system_class::menu_main.position_y                           = menu_system_class::position_y;
    menu_system_class::menu_main.position_z                           = menu_system_class::position_z;
    menu_system_class::menu_main.size_x                               = menu_system_class::size_x;
    menu_system_class::menu_main.size_y                               = menu_system_class::size_y;
    menu_system_class::menu_main.size_z                               = menu_system_class::size_z;
    menu_system_class::menu_main.title.text                           = "Main menu";
    menu_system_class::menu_main.title.size_x                         = menu_system_class::menu_main.title.text.length()/1.2f;
    menu_system_class::menu_main.title.size_y                         = menu_system_class::menu_main.title.size_x*4;
    menu_system_class::menu_main.title.position_x                     = menu_system_class::menu_main.position_x - (menu_system_class::menu_main.title.size_x/100.0f);
    menu_system_class::menu_main.title.position_y                     = menu_system_class::menu_main.position_y + (menu_system_class::menu_main.size_y/2.0f) - (menu_system_class::menu_main.title.size_y / 440.0f);
    menu_system_class::menu_main.title_bar.size_x                     = menu_system_class::menu_main.size_x; // x/2.0f for middle section
    menu_system_class::menu_main.title_bar.size_y                     = menu_system_class::menu_main.size_y / 10.0f;
    menu_system_class::menu_main.title_bar.position_x                 = menu_system_class::menu_main.position_x;
    menu_system_class::menu_main.title_bar.position_y                 = menu_system_class::menu_main.position_y+(menu_system_class::menu_main.size_y/2.0f)-(menu_system_class::menu_main.title_bar.size_y/2.0f);

    menu_system_class::menu_main.element[0].title.text                = "";
    menu_system_class::menu_main.element[0].active                    = true;
    menu_system_class::menu_main.element[0].type                      = BUTTON;
    menu_system_class::menu_main.element[0].zoom.enabled              = false;
    menu_system_class::menu_main.element[0].color                     = menu_system_class::menu_main.color;
    menu_system_class::menu_main.element[0].size_x                    = 0.1f;
    menu_system_class::menu_main.element[0].size_y                    = 0.1f;
    menu_system_class::menu_main.element[0].position_x                = menu_system_class::menu_main.position_x+(menu_system_class::menu_main.size_x/2.0f)-(menu_system_class::menu_main.element[0].size_x/1.8f);
    menu_system_class::menu_main.element[0].position_y                = menu_system_class::menu_main.title.position_y+(menu_system_class::menu_main.element[0].size_y/8.0f);
    menu_system_class::menu_main.element[0].texture_ID.normal         = game.resource.texture.close_button.ref_number;
    menu_system_class::menu_main.element[0].texture_ID.highlighted    = game.resource.texture.close_button_highlighted.ref_number;

    menu_system_class::menu_main.element[1].title.text                = "New Game";
    menu_system_class::menu_main.element[1].active                    = true;
    menu_system_class::menu_main.element[1].type                      = BUTTON;
    menu_system_class::menu_main.element[1].color                     = menu_system_class::menu_main.color;
    menu_system_class::menu_main.element[1].zoom                      = menu_system_class::menu_main.zoom;
    menu_system_class::menu_main.element[1].size_x                    = (menu_system_class::menu_main.size_x / 100.f)*80.0f;
    menu_system_class::menu_main.element[1].size_y                    = menu_system_class::menu_main.size_y / 10.0f;
    menu_system_class::menu_main.element[1].position_x                = menu_system_class::menu_main.position_x;
    menu_system_class::menu_main.element[1].position_y                = menu_system_class::menu_main.position_y+(menu_system_class::menu_main.size_y/2.0f)-(menu_system_class::menu_main.element[1].size_y*2.0f);
    menu_system_class::menu_main.element[1].texture_ID                = menu_system_class::menu_main.texture_ID;
    menu_system_class::menu_main.element[1].title.size_x              = menu_system_class::menu_main.element[1].title.text.length()/1.2f;
    menu_system_class::menu_main.element[1].title.size_y              = menu_system_class::menu_main.element[1].title.size_x*4;;
    menu_system_class::menu_main.element[1].title.position_x          = menu_system_class::menu_main.element[1].position_x-(menu_system_class::menu_main.element[1].title.size_x/100.0f);
    menu_system_class::menu_main.element[1].title.position_y          = menu_system_class::menu_main.element[1].position_y-(menu_system_class::menu_main.element[1].title.size_y/1480.0f);

    menu_system_class::menu_main.element[2].title.text                = "Load Game";
    menu_system_class::menu_main.element[2].active                    = true;
    menu_system_class::menu_main.element[2].type                      = BUTTON;
    menu_system_class::menu_main.element[2].color                     = menu_system_class::menu_main.color;
    menu_system_class::menu_main.element[2].zoom                      = menu_system_class::menu_main.zoom;
    menu_system_class::menu_main.element[2].size_x                    = (menu_system_class::menu_main.size_x / 100.f)*80.0f;
    menu_system_class::menu_main.element[2].size_y                    = menu_system_class::menu_main.size_y / 10.0f;
    menu_system_class::menu_main.element[2].position_x                = menu_system_class::menu_main.position_x;
    menu_system_class::menu_main.element[2].position_y                = menu_system_class::menu_main.position_y+(menu_system_class::menu_main.size_y/2.0f)-(menu_system_class::menu_main.element[2].size_y*3.25f);
    menu_system_class::menu_main.element[2].texture_ID                = menu_system_class::menu_main.texture_ID;
    menu_system_class::menu_main.element[2].title.size_x              = menu_system_class::menu_main.element[2].title.text.length()/1.2f;
    menu_system_class::menu_main.element[2].title.size_y              = menu_system_class::menu_main.element[2].title.size_x*4;;
    menu_system_class::menu_main.element[2].title.position_x          = menu_system_class::menu_main.element[2].position_x-(menu_system_class::menu_main.element[2].title.size_x/100.0f);
    menu_system_class::menu_main.element[2].title.position_y          = menu_system_class::menu_main.element[2].position_y-(menu_system_class::menu_main.element[2].title.size_y/1480.0f);

    menu_system_class::menu_main.element[3].title.text                = "Save Game";
    menu_system_class::menu_main.element[3].active                    = true;
    menu_system_class::menu_main.element[3].type                      = BUTTON;
    menu_system_class::menu_main.element[3].color                     = menu_system_class::menu_main.color;
    menu_system_class::menu_main.element[3].zoom                      = menu_system_class::menu_main.zoom;
    menu_system_class::menu_main.element[3].size_x                    = (menu_system_class::menu_main.size_x / 100.f)*80.0f;
    menu_system_class::menu_main.element[3].size_y                    = menu_system_class::menu_main.size_y / 10.0f;
    menu_system_class::menu_main.element[3].position_x                = menu_system_class::menu_main.position_x;
    menu_system_class::menu_main.element[3].position_y                = menu_system_class::menu_main.position_y+(menu_system_class::menu_main.size_y/2.0f)-(menu_system_class::menu_main.element[3].size_y*4.5f);
    menu_system_class::menu_main.element[3].texture_ID                = menu_system_class::menu_main.texture_ID;
    menu_system_class::menu_main.element[3].title.size_x              = menu_system_class::menu_main.element[3].title.text.length()/1.2f;
    menu_system_class::menu_main.element[3].title.size_y              = menu_system_class::menu_main.element[3].title.size_x*4;;
    menu_system_class::menu_main.element[3].title.position_x          = menu_system_class::menu_main.element[3].position_x-(menu_system_class::menu_main.element[3].title.size_x/100.0f);
    menu_system_class::menu_main.element[3].title.position_y          = menu_system_class::menu_main.element[3].position_y-(menu_system_class::menu_main.element[3].title.size_y/1480.0f);

    menu_system_class::menu_main.element[4].title.text                = "Resume Game";
    menu_system_class::menu_main.element[4].active                    = true;
    menu_system_class::menu_main.element[4].type                      = BUTTON;
    menu_system_class::menu_main.element[4].color                     = menu_system_class::menu_main.color;
    menu_system_class::menu_main.element[4].zoom                      = menu_system_class::menu_main.zoom;
    menu_system_class::menu_main.element[4].size_x                    = (menu_system_class::menu_main.size_x / 100.f)*80.0f;
    menu_system_class::menu_main.element[4].size_y                    = menu_system_class::menu_main.size_y / 10.0f;
    menu_system_class::menu_main.element[4].position_x                = menu_system_class::menu_main.position_x;
    menu_system_class::menu_main.element[4].position_y                = menu_system_class::menu_main.position_y+(menu_system_class::menu_main.size_y/2.0f)-(menu_system_class::menu_main.element[4].size_y*5.75f);
    menu_system_class::menu_main.element[4].texture_ID                = menu_system_class::menu_main.texture_ID;
    menu_system_class::menu_main.element[4].title.size_x              = menu_system_class::menu_main.element[4].title.text.length()/1.2f;
    menu_system_class::menu_main.element[4].title.size_y              = menu_system_class::menu_main.element[4].title.size_x*4;;
    menu_system_class::menu_main.element[4].title.position_x          = menu_system_class::menu_main.element[4].position_x-(menu_system_class::menu_main.element[4].title.size_x/100.0f);
    menu_system_class::menu_main.element[4].title.position_y          = menu_system_class::menu_main.element[4].position_y-(menu_system_class::menu_main.element[4].title.size_y/1480.0f);

    menu_system_class::menu_main.element[5].title.text                = "Options";
    menu_system_class::menu_main.element[5].active                    = true;
    menu_system_class::menu_main.element[5].type                      = BUTTON;
    menu_system_class::menu_main.element[5].color                     = menu_system_class::menu_main.color;
    menu_system_class::menu_main.element[5].zoom                      = menu_system_class::menu_main.zoom;
    menu_system_class::menu_main.element[5].size_x                    = (menu_system_class::menu_main.size_x / 100.f)*80.0f;
    menu_system_class::menu_main.element[5].size_y                    = menu_system_class::menu_main.size_y / 10.0f;
    menu_system_class::menu_main.element[5].position_x                = menu_system_class::menu_main.position_x;
    menu_system_class::menu_main.element[5].position_y                = menu_system_class::menu_main.position_y+(menu_system_class::menu_main.size_y/2.0f)-(menu_system_class::menu_main.element[3].size_y*7.0f);
    menu_system_class::menu_main.element[5].texture_ID                = menu_system_class::menu_main.texture_ID;
    menu_system_class::menu_main.element[5].title.size_x              = menu_system_class::menu_main.element[5].title.text.length()/1.0f;
    menu_system_class::menu_main.element[5].title.size_y              = menu_system_class::menu_main.element[5].title.size_x*4;;
    menu_system_class::menu_main.element[5].title.position_x          = menu_system_class::menu_main.element[5].position_x-(menu_system_class::menu_main.element[5].title.size_x/100.0f);
    menu_system_class::menu_main.element[5].title.position_y          = menu_system_class::menu_main.element[5].position_y-(menu_system_class::menu_main.element[5].title.size_y/1480.0f);

    menu_system_class::menu_main.element[7].title.text                = "Exit Game";
    menu_system_class::menu_main.element[7].active                    = true;
    menu_system_class::menu_main.element[7].type                      = BUTTON;
    menu_system_class::menu_main.element[7].color                     = menu_system_class::menu_main.color;
    menu_system_class::menu_main.element[7].zoom                      = menu_system_class::menu_main.zoom;
    menu_system_class::menu_main.element[7].size_x                    = (menu_system_class::menu_main.size_x / 100.f)*80.0f;
    menu_system_class::menu_main.element[7].size_y                    = menu_system_class::menu_main.size_y / 10.0f;
    menu_system_class::menu_main.element[7].position_x                = menu_system_class::menu_main.position_x;
    menu_system_class::menu_main.element[7].position_y                = menu_system_class::menu_main.position_y+(menu_system_class::menu_main.size_y/2.0f)-(menu_system_class::menu_main.element[7].size_y*9.0f);
    menu_system_class::menu_main.element[7].texture_ID                = menu_system_class::menu_main.texture_ID;
    menu_system_class::menu_main.element[7].title.size_x              = menu_system_class::menu_main.element[7].title.text.length()/1.2f;
    menu_system_class::menu_main.element[7].title.size_y              = menu_system_class::menu_main.element[7].title.size_x*4;;
    menu_system_class::menu_main.element[7].title.position_x          = menu_system_class::menu_main.element[7].position_x-(menu_system_class::menu_main.element[7].title.size_x/100.0f);
    menu_system_class::menu_main.element[7].title.position_y          = menu_system_class::menu_main.element[7].position_y-(menu_system_class::menu_main.element[7].title.size_y/1480.0f);

    //------ setup "new game" menu -----------
    menu_system_class::menu_new_game.mouse_delay                          = menu_system_class::mouse_delay;
    menu_system_class::menu_new_game.color                                = menu_system_class::color;
    menu_system_class::menu_new_game.zoom                                 = menu_system_class::zoom;
    menu_system_class::menu_new_game.texture_ID                           = menu_system_class::texture_ID;
    menu_system_class::menu_new_game.position_x                           = menu_system_class::position_x;
    menu_system_class::menu_new_game.position_y                           = menu_system_class::position_y;
    menu_system_class::menu_new_game.position_z                           = menu_system_class::position_z;
    menu_system_class::menu_new_game.size_x                               = menu_system_class::size_x;
    menu_system_class::menu_new_game.size_y                               = menu_system_class::size_y;
    menu_system_class::menu_new_game.size_z                               = menu_system_class::size_z;
    menu_system_class::menu_new_game.title.text                           = "New Game";
    menu_system_class::menu_new_game.title.size_x                         = menu_system_class::menu_new_game.title.text.length()/1.2f;
    menu_system_class::menu_new_game.title.size_y                         = menu_system_class::menu_new_game.title.size_x*4;
    menu_system_class::menu_new_game.title.position_x                     = menu_system_class::menu_new_game.position_x - (menu_system_class::menu_new_game.title.size_x/100.0f);
    menu_system_class::menu_new_game.title.position_y                     = menu_system_class::menu_new_game.position_y + (menu_system_class::menu_new_game.size_y/2.0f) - (menu_system_class::menu_new_game.title.size_y / 440.0f);
    menu_system_class::menu_new_game.title_bar.size_x                     = menu_system_class::menu_new_game.size_x; // x/2.0f for middle section
    menu_system_class::menu_new_game.title_bar.size_y                     = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.title_bar.position_x                 = menu_system_class::menu_new_game.position_x;
    menu_system_class::menu_new_game.title_bar.position_y                 = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.title_bar.size_y/2.0f);

    menu_system_class::menu_new_game.element[0].title.text                = "";
    menu_system_class::menu_new_game.element[0].active                    = true;
    menu_system_class::menu_new_game.element[0].type                      = BUTTON;
    menu_system_class::menu_new_game.element[0].zoom.enabled              = false;
    menu_system_class::menu_new_game.element[0].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[0].size_x                    = 0.1f;
    menu_system_class::menu_new_game.element[0].size_y                    = 0.1f;
    menu_system_class::menu_new_game.element[0].position_x                = menu_system_class::menu_new_game.position_x+(menu_system_class::menu_new_game.size_x/2.0f)-(menu_system_class::menu_new_game.element[0].size_x/1.8f);
    menu_system_class::menu_new_game.element[0].position_y                = menu_system_class::menu_new_game.title.position_y+(menu_system_class::menu_new_game.element[0].size_y/8.0f);
    menu_system_class::menu_new_game.element[0].texture_ID.normal         = game.resource.texture.close_button.ref_number;
    menu_system_class::menu_new_game.element[0].texture_ID.highlighted    = game.resource.texture.close_button_highlighted.ref_number;

    menu_system_class::menu_new_game.element[2].title.text                = "";
    menu_system_class::menu_new_game.element[2].active                    = true;
    menu_system_class::menu_new_game.element[2].type                      = BUTTON;
    menu_system_class::menu_new_game.element[2].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[2].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[2].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[2].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[2].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[2].size_x*1.0f);
    menu_system_class::menu_new_game.element[2].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[2].size_y*2.00f);
    menu_system_class::menu_new_game.element[2].texture_ID.angle          = 0.0f;
    menu_system_class::menu_new_game.element[2].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_new_game.element[2].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_new_game.element[2].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;

    menu_system_class::menu_new_game.element[3].title.text                = "";
    menu_system_class::menu_new_game.element[3].active                    = true;
    menu_system_class::menu_new_game.element[3].type                      = BUTTON;
    menu_system_class::menu_new_game.element[3].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[3].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[3].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[3].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[3].position_x                = menu_system_class::menu_new_game.position_x+(menu_system_class::menu_new_game.size_x/2.0f)-(menu_system_class::menu_new_game.element[3].size_x*1.0f);
    menu_system_class::menu_new_game.element[3].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[3].size_y*2.00f);
    menu_system_class::menu_new_game.element[3].texture_ID.angle          = 180.0f;
    menu_system_class::menu_new_game.element[3].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_new_game.element[3].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_new_game.element[3].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;

    menu_system_class::menu_new_game.element[4].title.text                = "";
    menu_system_class::menu_new_game.element[4].active                    = true;
    menu_system_class::menu_new_game.element[4].type                      = IMAGE;
    menu_system_class::menu_new_game.element[4].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[4].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[4].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[4].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[4].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[4].size_x*2.5f);
    menu_system_class::menu_new_game.element[4].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[4].size_y*2.00f);
    menu_system_class::menu_new_game.element[4].texture_ID.normal         = game.resource.texture.portrait_00.ref_number;

    menu_system_class::menu_new_game.element[5].title.text                = "";
    menu_system_class::menu_new_game.element[5].active                    = true;
    menu_system_class::menu_new_game.element[5].type                      = IMAGE;
    menu_system_class::menu_new_game.element[5].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[5].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[5].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[5].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[5].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[5].size_x*3.75f);
    menu_system_class::menu_new_game.element[5].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[5].size_y*2.00f);
    menu_system_class::menu_new_game.element[5].texture_ID.normal         = game.resource.texture.portrait_01.ref_number;

    menu_system_class::menu_new_game.element[6].title.text                = "";
    menu_system_class::menu_new_game.element[6].active                    = true;
    menu_system_class::menu_new_game.element[6].type                      = IMAGE;
    menu_system_class::menu_new_game.element[6].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[6].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[6].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[6].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[6].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[6].size_x*5.0f);
    menu_system_class::menu_new_game.element[6].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[6].size_y*2.00f);
    menu_system_class::menu_new_game.element[6].texture_ID.normal         = game.resource.texture.portrait_02.ref_number;

    menu_system_class::menu_new_game.element[7].title.text                = "";
    menu_system_class::menu_new_game.element[7].active                    = true;
    menu_system_class::menu_new_game.element[7].type                      = IMAGE;
    menu_system_class::menu_new_game.element[7].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[7].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[7].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[7].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[7].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[7].size_x*6.25f);
    menu_system_class::menu_new_game.element[7].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[7].size_y*2.00f);
    menu_system_class::menu_new_game.element[7].texture_ID.normal         = game.resource.texture.portrait_03.ref_number;

    menu_system_class::menu_new_game.element[8].title.text                = "";
    menu_system_class::menu_new_game.element[8].active                    = true;
    menu_system_class::menu_new_game.element[8].type                      = IMAGE;
    menu_system_class::menu_new_game.element[8].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[8].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[8].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[8].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[8].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[8].size_x*7.5f);
    menu_system_class::menu_new_game.element[8].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[8].size_y*2.00f);
    menu_system_class::menu_new_game.element[8].texture_ID.normal         = game.resource.texture.portrait_04.ref_number;

    menu_system_class::menu_new_game.element[1].title.text                = "Start Game";
    menu_system_class::menu_new_game.element[1].active                    = true;
    menu_system_class::menu_new_game.element[1].type                      = BUTTON;
    menu_system_class::menu_new_game.element[1].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[1].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[1].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*80.0f;
    menu_system_class::menu_new_game.element[1].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[1].position_x                = menu_system_class::menu_new_game.position_x;
    menu_system_class::menu_new_game.element[1].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[1].size_y*5.0f);
    menu_system_class::menu_new_game.element[1].texture_ID                = menu_system_class::menu_new_game.texture_ID;
    menu_system_class::menu_new_game.element[1].title.size_x              = menu_system_class::menu_new_game.element[1].title.text.length()/1.2f;
    menu_system_class::menu_new_game.element[1].title.size_y              = menu_system_class::menu_new_game.element[1].title.size_x*4;;
    menu_system_class::menu_new_game.element[1].title.position_x          = menu_system_class::menu_new_game.element[1].position_x-(menu_system_class::menu_new_game.element[1].title.size_x/100.0f);
    menu_system_class::menu_new_game.element[1].title.position_y          = menu_system_class::menu_new_game.element[1].position_y-(menu_system_class::menu_new_game.element[1].title.size_y/1480.0f);

    menu_system_class::menu_new_game.element[15].title.text                = "Main Menu";
    menu_system_class::menu_new_game.element[15].active                    = true;
    menu_system_class::menu_new_game.element[15].type                      = BUTTON;
    menu_system_class::menu_new_game.element[15].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[15].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[15].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*80.0f;
    menu_system_class::menu_new_game.element[15].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[15].position_x                = menu_system_class::menu_new_game.position_x;
    menu_system_class::menu_new_game.element[15].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[15].size_y*9.0f);
    menu_system_class::menu_new_game.element[15].texture_ID                = menu_system_class::menu_new_game.texture_ID;
    menu_system_class::menu_new_game.element[15].title.size_x              = menu_system_class::menu_new_game.element[15].title.text.length()/1.2f;
    menu_system_class::menu_new_game.element[15].title.size_y              = menu_system_class::menu_new_game.element[15].title.size_x*4;;
    menu_system_class::menu_new_game.element[15].title.position_x          = menu_system_class::menu_new_game.element[15].position_x-(menu_system_class::menu_new_game.element[15].title.size_x/100.0f);
    menu_system_class::menu_new_game.element[15].title.position_y          = menu_system_class::menu_new_game.element[15].position_y-(menu_system_class::menu_new_game.element[15].title.size_y/1480.0f);

    //------ setup "save game" menu -----------
    menu_system_class::menu_save.mouse_delay                          = menu_system_class::mouse_delay;
    menu_system_class::menu_save.color                                = menu_system_class::color;
    menu_system_class::menu_save.zoom                                 = menu_system_class::zoom;
    menu_system_class::menu_save.texture_ID                           = menu_system_class::texture_ID;
    menu_system_class::menu_save.position_x                           = menu_system_class::position_x;
    menu_system_class::menu_save.position_y                           = menu_system_class::position_y;
    menu_system_class::menu_save.position_z                           = menu_system_class::position_z;
    menu_system_class::menu_save.size_x                               = menu_system_class::size_x;
    menu_system_class::menu_save.size_y                               = menu_system_class::size_y;
    menu_system_class::menu_save.size_z                               = menu_system_class::size_z;
    menu_system_class::menu_save.title.text                           = "Save Game";
    menu_system_class::menu_save.title.size_x                         = menu_system_class::menu_save.title.text.length()/1.2f;
    menu_system_class::menu_save.title.size_y                         = menu_system_class::menu_save.title.size_x*4;
    menu_system_class::menu_save.title.position_x                     = menu_system_class::menu_save.position_x - (menu_system_class::menu_save.title.size_x/100.0f);
    menu_system_class::menu_save.title.position_y                     = menu_system_class::menu_save.position_y + (menu_system_class::menu_save.size_y/2.0f) - (menu_system_class::menu_save.title.size_y / 440.0f);
    menu_system_class::menu_save.title_bar.size_x                     = menu_system_class::menu_save.size_x; // x/2.0f for middle section
    menu_system_class::menu_save.title_bar.size_y                     = menu_system_class::menu_save.size_y / 10.0f;
    menu_system_class::menu_save.title_bar.position_x                 = menu_system_class::menu_save.position_x;
    menu_system_class::menu_save.title_bar.position_y                 = menu_system_class::menu_save.position_y+(menu_system_class::menu_save.size_y/2.0f)-(menu_system_class::menu_save.title_bar.size_y/2.0f);

    menu_system_class::menu_save.element[0].title.text                = "";
    menu_system_class::menu_save.element[0].active                    = true;
    menu_system_class::menu_save.element[0].type                      = BUTTON;
    menu_system_class::menu_save.element[0].zoom.enabled              = false;
    menu_system_class::menu_save.element[0].color                     = menu_system_class::menu_save.color;
    menu_system_class::menu_save.element[0].size_x                    = 0.1f;
    menu_system_class::menu_save.element[0].size_y                    = 0.1f;
    menu_system_class::menu_save.element[0].position_x                = menu_system_class::menu_save.position_x+(menu_system_class::menu_save.size_x/2.0f)-(menu_system_class::menu_save.element[0].size_x/1.8f);
    menu_system_class::menu_save.element[0].position_y                = menu_system_class::menu_save.title.position_y+(menu_system_class::menu_save.element[0].size_y/8.0f);
    menu_system_class::menu_save.element[0].texture_ID.normal         = game.resource.texture.close_button.ref_number;
    menu_system_class::menu_save.element[0].texture_ID.highlighted    = game.resource.texture.close_button_highlighted.ref_number;

    menu_system_class::menu_save.element[1].title.text                = "Save slot 1";
    menu_system_class::menu_save.element[1].active                    = true;
    menu_system_class::menu_save.element[1].type                      = BUTTON;
    menu_system_class::menu_save.element[1].color                     = menu_system_class::menu_save.color;
    menu_system_class::menu_save.element[1].zoom                      = menu_system_class::menu_save.zoom;
    menu_system_class::menu_save.element[1].size_x                    = (menu_system_class::menu_save.size_x / 100.f)*80.0f;
    menu_system_class::menu_save.element[1].size_y                    = menu_system_class::menu_save.size_y / 10.0f;
    menu_system_class::menu_save.element[1].position_x                = menu_system_class::menu_save.position_x;
    menu_system_class::menu_save.element[1].position_y                = menu_system_class::menu_save.position_y+(menu_system_class::menu_save.size_y/2.0f)-(menu_system_class::menu_save.element[1].size_y*2.0f);
    menu_system_class::menu_save.element[1].texture_ID                = menu_system_class::menu_save.texture_ID;
    menu_system_class::menu_save.element[1].title.size_x              = menu_system_class::menu_save.element[1].title.text.length()/1.2f;
    menu_system_class::menu_save.element[1].title.size_y              = menu_system_class::menu_save.element[1].title.size_x*4;;
    menu_system_class::menu_save.element[1].title.position_x          = menu_system_class::menu_save.element[1].position_x-(menu_system_class::menu_save.element[1].title.size_x/100.0f);
    menu_system_class::menu_save.element[1].title.position_y          = menu_system_class::menu_save.element[1].position_y-(menu_system_class::menu_save.element[1].title.size_y/1480.0f);

    menu_system_class::menu_save.element[2].title.text                = "Save slot 2";
    menu_system_class::menu_save.element[2].active                    = true;
    menu_system_class::menu_save.element[2].type                      = BUTTON;
    menu_system_class::menu_save.element[2].color                     = menu_system_class::menu_save.color;
    menu_system_class::menu_save.element[2].zoom                      = menu_system_class::menu_save.zoom;
    menu_system_class::menu_save.element[2].size_x                    = (menu_system_class::menu_save.size_x / 100.f)*80.0f;
    menu_system_class::menu_save.element[2].size_y                    = menu_system_class::menu_save.size_y / 10.0f;
    menu_system_class::menu_save.element[2].position_x                = menu_system_class::menu_save.position_x;
    menu_system_class::menu_save.element[2].position_y                = menu_system_class::menu_save.position_y+(menu_system_class::menu_save.size_y/2.0f)-(menu_system_class::menu_save.element[1].size_y*3.25f);
    menu_system_class::menu_save.element[2].texture_ID                = menu_system_class::menu_save.texture_ID;
    menu_system_class::menu_save.element[2].title.size_x              = menu_system_class::menu_save.element[2].title.text.length()/1.2f;
    menu_system_class::menu_save.element[2].title.size_y              = menu_system_class::menu_save.element[2].title.size_x*4;;
    menu_system_class::menu_save.element[2].title.position_x          = menu_system_class::menu_save.element[2].position_x-(menu_system_class::menu_save.element[2].title.size_x/100.0f);
    menu_system_class::menu_save.element[2].title.position_y          = menu_system_class::menu_save.element[2].position_y-(menu_system_class::menu_save.element[2].title.size_y/1480.0f);

    menu_system_class::menu_save.element[3].title.text                = "Save slot 3";
    menu_system_class::menu_save.element[3].active                    = true;
    menu_system_class::menu_save.element[3].type                      = BUTTON;
    menu_system_class::menu_save.element[3].color                     = menu_system_class::menu_save.color;
    menu_system_class::menu_save.element[3].zoom                      = menu_system_class::menu_save.zoom;
    menu_system_class::menu_save.element[3].size_x                    = (menu_system_class::menu_save.size_x / 100.f)*80.0f;
    menu_system_class::menu_save.element[3].size_y                    = menu_system_class::menu_save.size_y / 10.0f;
    menu_system_class::menu_save.element[3].position_x                = menu_system_class::menu_save.position_x;
    menu_system_class::menu_save.element[3].position_y                = menu_system_class::menu_save.position_y+(menu_system_class::menu_save.size_y/2.0f)-(menu_system_class::menu_save.element[3].size_y*4.50f);
    menu_system_class::menu_save.element[3].texture_ID                = menu_system_class::menu_save.texture_ID;
    menu_system_class::menu_save.element[3].title.size_x              = menu_system_class::menu_save.element[3].title.text.length()/1.2f;
    menu_system_class::menu_save.element[3].title.size_y              = menu_system_class::menu_save.element[3].title.size_x*4;;
    menu_system_class::menu_save.element[3].title.position_x          = menu_system_class::menu_save.element[3].position_x-(menu_system_class::menu_save.element[3].title.size_x/100.0f);
    menu_system_class::menu_save.element[3].title.position_y          = menu_system_class::menu_save.element[3].position_y-(menu_system_class::menu_save.element[3].title.size_y/1480.0f);

    menu_system_class::menu_save.element[4].title.text                = "Save slot 4";
    menu_system_class::menu_save.element[4].active                    = true;
    menu_system_class::menu_save.element[4].type                      = BUTTON;
    menu_system_class::menu_save.element[4].color                     = menu_system_class::menu_save.color;
    menu_system_class::menu_save.element[4].zoom                      = menu_system_class::menu_save.zoom;
    menu_system_class::menu_save.element[4].size_x                    = (menu_system_class::menu_save.size_x / 100.f)*80.0f;
    menu_system_class::menu_save.element[4].size_y                    = menu_system_class::menu_save.size_y / 10.0f;
    menu_system_class::menu_save.element[4].position_x                = menu_system_class::menu_save.position_x;
    menu_system_class::menu_save.element[4].position_y                = menu_system_class::menu_save.position_y+(menu_system_class::menu_save.size_y/2.0f)-(menu_system_class::menu_save.element[4].size_y*5.75f);
    menu_system_class::menu_save.element[4].texture_ID                = menu_system_class::menu_save.texture_ID;
    menu_system_class::menu_save.element[4].title.size_x              = menu_system_class::menu_save.element[4].title.text.length()/1.2f;
    menu_system_class::menu_save.element[4].title.size_y              = menu_system_class::menu_save.element[4].title.size_x*4;;
    menu_system_class::menu_save.element[4].title.position_x          = menu_system_class::menu_save.element[4].position_x-(menu_system_class::menu_save.element[4].title.size_x/100.0f);
    menu_system_class::menu_save.element[4].title.position_y          = menu_system_class::menu_save.element[4].position_y-(menu_system_class::menu_save.element[4].title.size_y/1480.0f);

    menu_system_class::menu_save.element[5].title.text                = "Save slot 5";
    menu_system_class::menu_save.element[5].active                    = true;
    menu_system_class::menu_save.element[5].type                      = BUTTON;
    menu_system_class::menu_save.element[5].color                     = menu_system_class::menu_save.color;
    menu_system_class::menu_save.element[5].zoom                      = menu_system_class::menu_save.zoom;
    menu_system_class::menu_save.element[5].size_x                    = (menu_system_class::menu_save.size_x / 100.f)*80.0f;
    menu_system_class::menu_save.element[5].size_y                    = menu_system_class::menu_save.size_y / 10.0f;
    menu_system_class::menu_save.element[5].position_x                = menu_system_class::menu_save.position_x;
    menu_system_class::menu_save.element[5].position_y                = menu_system_class::menu_save.position_y+(menu_system_class::menu_save.size_y/2.0f)-(menu_system_class::menu_save.element[5].size_y*7.00f);
    menu_system_class::menu_save.element[5].texture_ID                = menu_system_class::menu_save.texture_ID;
    menu_system_class::menu_save.element[5].title.size_x              = menu_system_class::menu_save.element[5].title.text.length()/1.2f;
    menu_system_class::menu_save.element[5].title.size_y              = menu_system_class::menu_save.element[5].title.size_x*4;;
    menu_system_class::menu_save.element[5].title.position_x          = menu_system_class::menu_save.element[5].position_x-(menu_system_class::menu_save.element[5].title.size_x/100.0f);
    menu_system_class::menu_save.element[5].title.position_y          = menu_system_class::menu_save.element[5].position_y-(menu_system_class::menu_save.element[5].title.size_y/1480.0f);

    menu_system_class::menu_save.element[7].title.text                = "Main menu";
    menu_system_class::menu_save.element[7].active                    = true;
    menu_system_class::menu_save.element[7].type                      = BUTTON;
    menu_system_class::menu_save.element[7].color                     = menu_system_class::menu_save.color;
    menu_system_class::menu_save.element[7].zoom                      = menu_system_class::menu_save.zoom;
    menu_system_class::menu_save.element[7].size_x                    = (menu_system_class::menu_save.size_x / 100.f)*80.0f;
    menu_system_class::menu_save.element[7].size_y                    = menu_system_class::menu_save.size_y / 10.0f;
    menu_system_class::menu_save.element[7].position_x                = menu_system_class::menu_save.position_x;
    menu_system_class::menu_save.element[7].position_y                = menu_system_class::menu_save.position_y+(menu_system_class::menu_save.size_y/2.0f)-(menu_system_class::menu_save.element[7].size_y*9.0f);
    menu_system_class::menu_save.element[7].texture_ID                = menu_system_class::menu_save.texture_ID;
    menu_system_class::menu_save.element[7].title.size_x              = menu_system_class::menu_save.element[7].title.text.length()/1.2f;
    menu_system_class::menu_save.element[7].title.size_y              = menu_system_class::menu_save.element[7].title.size_x*4;;
    menu_system_class::menu_save.element[7].title.position_x          = menu_system_class::menu_save.element[7].position_x-(menu_system_class::menu_save.element[7].title.size_x/100.0f);
    menu_system_class::menu_save.element[7].title.position_y          = menu_system_class::menu_save.element[7].position_y-(menu_system_class::menu_save.element[7].title.size_y/1480.0f);

    //------ setup "load game" menu -----------
    menu_system_class::menu_load.mouse_delay                          = menu_system_class::mouse_delay;
    menu_system_class::menu_load.color                                = menu_system_class::color;
    menu_system_class::menu_load.zoom                                 = menu_system_class::zoom;
    menu_system_class::menu_load.texture_ID                           = menu_system_class::texture_ID;
    menu_system_class::menu_load.position_x                           = menu_system_class::position_x;
    menu_system_class::menu_load.position_y                           = menu_system_class::position_y;
    menu_system_class::menu_load.position_z                           = menu_system_class::position_z;
    menu_system_class::menu_load.size_x                               = menu_system_class::size_x;
    menu_system_class::menu_load.size_y                               = menu_system_class::size_y;
    menu_system_class::menu_load.size_z                               = menu_system_class::size_z;
    menu_system_class::menu_load.title.text                           = "Load Game";
    menu_system_class::menu_load.title.size_x                         = menu_system_class::menu_load.title.text.length()/1.2f;
    menu_system_class::menu_load.title.size_y                         = menu_system_class::menu_load.title.size_x*4;
    menu_system_class::menu_load.title.position_x                     = menu_system_class::menu_load.position_x - (menu_system_class::menu_load.title.size_x/100.0f);
    menu_system_class::menu_load.title.position_y                     = menu_system_class::menu_load.position_y + (menu_system_class::menu_load.size_y/2.0f) - (menu_system_class::menu_load.title.size_y / 440.0f);
    menu_system_class::menu_load.title_bar.size_x                     = menu_system_class::menu_load.size_x; // x/2.0f for middle section
    menu_system_class::menu_load.title_bar.size_y                     = menu_system_class::menu_load.size_y / 10.0f;
    menu_system_class::menu_load.title_bar.position_x                 = menu_system_class::menu_load.position_x;
    menu_system_class::menu_load.title_bar.position_y                 = menu_system_class::menu_load.position_y+(menu_system_class::menu_load.size_y/2.0f)-(menu_system_class::menu_load.title_bar.size_y/2.0f);

    menu_system_class::menu_load.element[0].title.text                = "";
    menu_system_class::menu_load.element[0].active                    = true;
    menu_system_class::menu_load.element[0].type                      = BUTTON;
    menu_system_class::menu_load.element[0].zoom.enabled              = false;
    menu_system_class::menu_load.element[0].color                     = menu_system_class::menu_load.color;
    menu_system_class::menu_load.element[0].size_x                    = 0.1f;
    menu_system_class::menu_load.element[0].size_y                    = 0.1f;
    menu_system_class::menu_load.element[0].position_x                = menu_system_class::menu_load.position_x+(menu_system_class::menu_load.size_x/2.0f)-(menu_system_class::menu_load.element[0].size_x/1.8f);
    menu_system_class::menu_load.element[0].position_y                = menu_system_class::menu_load.title.position_y+(menu_system_class::menu_load.element[0].size_y/8.0f);
    menu_system_class::menu_load.element[0].texture_ID.normal         = game.resource.texture.close_button.ref_number;
    menu_system_class::menu_load.element[0].texture_ID.highlighted    = game.resource.texture.close_button_highlighted.ref_number;

    menu_system_class::menu_load.element[1].title.text                = "Load slot 1";
    menu_system_class::menu_load.element[1].active                    = true;
    menu_system_class::menu_load.element[1].type                      = BUTTON;
    menu_system_class::menu_load.element[1].color                     = menu_system_class::menu_load.color;
    menu_system_class::menu_load.element[1].zoom                      = menu_system_class::menu_load.zoom;
    menu_system_class::menu_load.element[1].size_x                    = (menu_system_class::menu_load.size_x / 100.f)*80.0f;
    menu_system_class::menu_load.element[1].size_y                    = menu_system_class::menu_load.size_y / 10.0f;
    menu_system_class::menu_load.element[1].position_x                = menu_system_class::menu_load.position_x;
    menu_system_class::menu_load.element[1].position_y                = menu_system_class::menu_load.position_y+(menu_system_class::menu_load.size_y/2.0f)-(menu_system_class::menu_load.element[1].size_y*2.0f);
    menu_system_class::menu_load.element[1].texture_ID                = menu_system_class::menu_load.texture_ID;
    menu_system_class::menu_load.element[1].title.size_x              = menu_system_class::menu_load.element[1].title.text.length()/1.2f;
    menu_system_class::menu_load.element[1].title.size_y              = menu_system_class::menu_load.element[1].title.size_x*4;;
    menu_system_class::menu_load.element[1].title.position_x          = menu_system_class::menu_load.element[1].position_x-(menu_system_class::menu_load.element[1].title.size_x/100.0f);
    menu_system_class::menu_load.element[1].title.position_y          = menu_system_class::menu_load.element[1].position_y-(menu_system_class::menu_load.element[1].title.size_y/1480.0f);

    menu_system_class::menu_load.element[2].title.text                = "Load slot 2";
    menu_system_class::menu_load.element[2].active                    = true;
    menu_system_class::menu_load.element[2].type                      = BUTTON;
    menu_system_class::menu_load.element[2].color                     = menu_system_class::menu_load.color;
    menu_system_class::menu_load.element[2].zoom                      = menu_system_class::menu_load.zoom;
    menu_system_class::menu_load.element[2].size_x                    = (menu_system_class::menu_load.size_x / 100.f)*80.0f;
    menu_system_class::menu_load.element[2].size_y                    = menu_system_class::menu_load.size_y / 10.0f;
    menu_system_class::menu_load.element[2].position_x                = menu_system_class::menu_load.position_x;
    menu_system_class::menu_load.element[2].position_y                = menu_system_class::menu_load.position_y+(menu_system_class::menu_load.size_y/2.0f)-(menu_system_class::menu_load.element[1].size_y*3.25f);
    menu_system_class::menu_load.element[2].texture_ID                = menu_system_class::menu_load.texture_ID;
    menu_system_class::menu_load.element[2].title.size_x              = menu_system_class::menu_load.element[2].title.text.length()/1.2f;
    menu_system_class::menu_load.element[2].title.size_y              = menu_system_class::menu_load.element[2].title.size_x*4;;
    menu_system_class::menu_load.element[2].title.position_x          = menu_system_class::menu_load.element[2].position_x-(menu_system_class::menu_load.element[2].title.size_x/100.0f);
    menu_system_class::menu_load.element[2].title.position_y          = menu_system_class::menu_load.element[2].position_y-(menu_system_class::menu_load.element[2].title.size_y/1480.0f);

    menu_system_class::menu_load.element[3].title.text                = "Load slot 3";
    menu_system_class::menu_load.element[3].active                    = true;
    menu_system_class::menu_load.element[3].type                      = BUTTON;
    menu_system_class::menu_load.element[3].color                     = menu_system_class::menu_load.color;
    menu_system_class::menu_load.element[3].zoom                      = menu_system_class::menu_load.zoom;
    menu_system_class::menu_load.element[3].size_x                    = (menu_system_class::menu_load.size_x / 100.f)*80.0f;
    menu_system_class::menu_load.element[3].size_y                    = menu_system_class::menu_load.size_y / 10.0f;
    menu_system_class::menu_load.element[3].position_x                = menu_system_class::menu_load.position_x;
    menu_system_class::menu_load.element[3].position_y                = menu_system_class::menu_load.position_y+(menu_system_class::menu_load.size_y/2.0f)-(menu_system_class::menu_load.element[3].size_y*4.50f);
    menu_system_class::menu_load.element[3].texture_ID                = menu_system_class::menu_load.texture_ID;
    menu_system_class::menu_load.element[3].title.size_x              = menu_system_class::menu_load.element[3].title.text.length()/1.2f;
    menu_system_class::menu_load.element[3].title.size_y              = menu_system_class::menu_load.element[3].title.size_x*4;;
    menu_system_class::menu_load.element[3].title.position_x          = menu_system_class::menu_load.element[3].position_x-(menu_system_class::menu_load.element[3].title.size_x/100.0f);
    menu_system_class::menu_load.element[3].title.position_y          = menu_system_class::menu_load.element[3].position_y-(menu_system_class::menu_load.element[3].title.size_y/1480.0f);

    menu_system_class::menu_load.element[4].title.text                = "Load slot 4";
    menu_system_class::menu_load.element[4].active                    = true;
    menu_system_class::menu_load.element[4].type                      = BUTTON;
    menu_system_class::menu_load.element[4].color                     = menu_system_class::menu_load.color;
    menu_system_class::menu_load.element[4].zoom                      = menu_system_class::menu_load.zoom;
    menu_system_class::menu_load.element[4].size_x                    = (menu_system_class::menu_load.size_x / 100.f)*80.0f;
    menu_system_class::menu_load.element[4].size_y                    = menu_system_class::menu_load.size_y / 10.0f;
    menu_system_class::menu_load.element[4].position_x                = menu_system_class::menu_load.position_x;
    menu_system_class::menu_load.element[4].position_y                = menu_system_class::menu_load.position_y+(menu_system_class::menu_load.size_y/2.0f)-(menu_system_class::menu_load.element[4].size_y*5.75f);
    menu_system_class::menu_load.element[4].texture_ID                = menu_system_class::menu_load.texture_ID;
    menu_system_class::menu_load.element[4].title.size_x              = menu_system_class::menu_load.element[4].title.text.length()/1.2f;
    menu_system_class::menu_load.element[4].title.size_y              = menu_system_class::menu_load.element[4].title.size_x*4;;
    menu_system_class::menu_load.element[4].title.position_x          = menu_system_class::menu_load.element[4].position_x-(menu_system_class::menu_load.element[4].title.size_x/100.0f);
    menu_system_class::menu_load.element[4].title.position_y          = menu_system_class::menu_load.element[4].position_y-(menu_system_class::menu_load.element[4].title.size_y/1480.0f);

    menu_system_class::menu_load.element[5].title.text                = "Load slot 5";
    menu_system_class::menu_load.element[5].active                    = true;
    menu_system_class::menu_load.element[5].type                      = BUTTON;
    menu_system_class::menu_load.element[5].color                     = menu_system_class::menu_load.color;
    menu_system_class::menu_load.element[5].zoom                      = menu_system_class::menu_load.zoom;
    menu_system_class::menu_load.element[5].size_x                    = (menu_system_class::menu_load.size_x / 100.f)*80.0f;
    menu_system_class::menu_load.element[5].size_y                    = menu_system_class::menu_load.size_y / 10.0f;
    menu_system_class::menu_load.element[5].position_x                = menu_system_class::menu_load.position_x;
    menu_system_class::menu_load.element[5].position_y                = menu_system_class::menu_load.position_y+(menu_system_class::menu_load.size_y/2.0f)-(menu_system_class::menu_load.element[5].size_y*7.00f);
    menu_system_class::menu_load.element[5].texture_ID                = menu_system_class::menu_load.texture_ID;
    menu_system_class::menu_load.element[5].title.size_x              = menu_system_class::menu_load.element[5].title.text.length()/1.2f;
    menu_system_class::menu_load.element[5].title.size_y              = menu_system_class::menu_load.element[5].title.size_x*4;;
    menu_system_class::menu_load.element[5].title.position_x          = menu_system_class::menu_load.element[5].position_x-(menu_system_class::menu_load.element[5].title.size_x/100.0f);
    menu_system_class::menu_load.element[5].title.position_y          = menu_system_class::menu_load.element[5].position_y-(menu_system_class::menu_load.element[5].title.size_y/1480.0f);

    menu_system_class::menu_load.element[7].title.text                = "Main menu";
    menu_system_class::menu_load.element[7].active                    = true;
    menu_system_class::menu_load.element[7].type                      = BUTTON;
    menu_system_class::menu_load.element[7].color                     = menu_system_class::menu_load.color;
    menu_system_class::menu_load.element[7].zoom                      = menu_system_class::menu_load.zoom;
    menu_system_class::menu_load.element[7].size_x                    = (menu_system_class::menu_load.size_x / 100.f)*80.0f;
    menu_system_class::menu_load.element[7].size_y                    = menu_system_class::menu_load.size_y / 10.0f;
    menu_system_class::menu_load.element[7].position_x                = menu_system_class::menu_load.position_x;
    menu_system_class::menu_load.element[7].position_y                = menu_system_class::menu_load.position_y+(menu_system_class::menu_load.size_y/2.0f)-(menu_system_class::menu_load.element[7].size_y*9.0f);
    menu_system_class::menu_load.element[7].texture_ID                = menu_system_class::menu_load.texture_ID;
    menu_system_class::menu_load.element[7].title.size_x              = menu_system_class::menu_load.element[7].title.text.length()/1.2f;
    menu_system_class::menu_load.element[7].title.size_y              = menu_system_class::menu_load.element[7].title.size_x*4;;
    menu_system_class::menu_load.element[7].title.position_x          = menu_system_class::menu_load.element[7].position_x-(menu_system_class::menu_load.element[7].title.size_x/100.0f);
    menu_system_class::menu_load.element[7].title.position_y          = menu_system_class::menu_load.element[7].position_y-(menu_system_class::menu_load.element[7].title.size_y/1480.0f);

    //------ setup "options" menu -----------
    menu_system_class::menu_options.mouse_delay                          = menu_system_class::mouse_delay;
    menu_system_class::menu_options.color                                = menu_system_class::color;
    menu_system_class::menu_options.zoom                                 = menu_system_class::zoom;
    menu_system_class::menu_options.texture_ID                           = menu_system_class::texture_ID;
    menu_system_class::menu_options.position_x                           = menu_system_class::position_x;
    menu_system_class::menu_options.position_y                           = menu_system_class::position_y;
    menu_system_class::menu_options.position_z                           = menu_system_class::position_z;
    menu_system_class::menu_options.size_x                               = menu_system_class::size_x;
    menu_system_class::menu_options.size_y                               = menu_system_class::size_y;
    menu_system_class::menu_options.size_z                               = menu_system_class::size_z;
    menu_system_class::menu_options.title.text                           = "Options";
    menu_system_class::menu_options.title.size_x                         = menu_system_class::menu_options.title.text.length()/1.0f;
    menu_system_class::menu_options.title.size_y                         = menu_system_class::menu_options.title.size_x*4;
    menu_system_class::menu_options.title.position_x                     = menu_system_class::menu_options.position_x - (menu_system_class::menu_options.title.size_x/100.0f);
    menu_system_class::menu_options.title.position_y                     = menu_system_class::menu_options.position_y + (menu_system_class::menu_options.size_y/2.0f) - (menu_system_class::menu_options.title.size_y / 440.0f);
    menu_system_class::menu_options.title_bar.size_x                     = menu_system_class::menu_options.size_x; // x/2.0f for middle section
    menu_system_class::menu_options.title_bar.size_y                     = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.title_bar.position_x                 = menu_system_class::menu_options.position_x;
    menu_system_class::menu_options.title_bar.position_y                 = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.title_bar.size_y/2.0f);

    menu_system_class::menu_options.element[0].title.text                = "";
    menu_system_class::menu_options.element[0].active                    = true;
    menu_system_class::menu_options.element[0].type                      = BUTTON;
    menu_system_class::menu_options.element[0].zoom.enabled              = false;
    menu_system_class::menu_options.element[0].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[0].size_x                    = 0.1f;
    menu_system_class::menu_options.element[0].size_y                    = 0.1f;
    menu_system_class::menu_options.element[0].position_x                = menu_system_class::menu_options.position_x+(menu_system_class::menu_options.size_x/2.0f)-(menu_system_class::menu_options.element[0].size_x/1.8f);
    menu_system_class::menu_options.element[0].position_y                = menu_system_class::menu_options.title.position_y+(menu_system_class::menu_options.element[0].size_y/8.0f);
    menu_system_class::menu_options.element[0].texture_ID.normal         = game.resource.texture.close_button.ref_number;
    menu_system_class::menu_options.element[0].texture_ID.highlighted    = game.resource.texture.close_button_highlighted.ref_number;

    menu_system_class::menu_options.element[1].title.text                = "";
    menu_system_class::menu_options.element[1].mouse_delay               = 5;
    menu_system_class::menu_options.element[1].active                    = true;
    menu_system_class::menu_options.element[1].type                      = BUTTON;
    menu_system_class::menu_options.element[1].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[1].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[1].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[1].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[1].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[1].size_x*1.0f);
    menu_system_class::menu_options.element[1].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[1].size_y*2.0f);
    menu_system_class::menu_options.element[1].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_options.element[1].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_options.element[1].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;

    menu_system_class::menu_options.element[2].title.text                = "";
    menu_system_class::menu_options.element[2].mouse_delay               = 5;
    menu_system_class::menu_options.element[2].active                    = true;
    menu_system_class::menu_options.element[2].type                      = BUTTON;
    menu_system_class::menu_options.element[2].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[2].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[2].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[2].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[2].position_x                = menu_system_class::menu_options.position_x+(menu_system_class::menu_options.size_x/2.0f)-(menu_system_class::menu_options.element[2].size_x*1.0f);
    menu_system_class::menu_options.element[2].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[2].size_y*2.0f);
    menu_system_class::menu_options.element[2].texture_ID.angle          = 180.0f;
    menu_system_class::menu_options.element[2].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_options.element[2].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_options.element[2].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;

    menu_system_class::menu_options.element[3].title.text                = "Sound volume";
    menu_system_class::menu_options.element[3].value                     = game.core.config.audio_volume_sound;
    menu_system_class::menu_options.element[3].value_max                 = 127.0f;
    menu_system_class::menu_options.element[3].active                    = true;
    menu_system_class::menu_options.element[3].type                      = BAR;
    menu_system_class::menu_options.element[3].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[3].zoom.enabled              = false;
    menu_system_class::menu_options.element[3].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*60.0f;
    menu_system_class::menu_options.element[3].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[3].position_x                = menu_system_class::menu_options.position_x;
    menu_system_class::menu_options.element[3].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[3].size_y*2.0f);
    menu_system_class::menu_options.element[3].texture_ID.normal         = game.resource.texture.slider_button_normal.ref_number;
    menu_system_class::menu_options.element[3].texture_ID.highlighted    = game.resource.texture.slider_button_highlighted.ref_number;
    menu_system_class::menu_options.element[3].title.size_x              = menu_system_class::menu_options.element[3].title.text.length()/2.2f;
    menu_system_class::menu_options.element[3].title.size_y              = menu_system_class::menu_options.element[3].title.size_x*4;;
    menu_system_class::menu_options.element[3].title.position_x          = menu_system_class::menu_options.element[3].position_x-(menu_system_class::menu_options.element[3].title.size_x/60.0f);
    menu_system_class::menu_options.element[3].title.position_y          = menu_system_class::menu_options.element[3].position_y-(menu_system_class::menu_options.element[3].title.size_y/1480.0f);

    menu_system_class::menu_options.element[4].title.text                = "";
    menu_system_class::menu_options.element[4].mouse_delay               = 5;
    menu_system_class::menu_options.element[4].active                    = true;
    menu_system_class::menu_options.element[4].type                      = BUTTON;
    menu_system_class::menu_options.element[4].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[4].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[4].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[4].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[4].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[4].size_x*1.0f);
    menu_system_class::menu_options.element[4].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[4].size_y*3.25f);
    menu_system_class::menu_options.element[4].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_options.element[4].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_options.element[4].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;

    menu_system_class::menu_options.element[5].title.text                = "";
    menu_system_class::menu_options.element[5].mouse_delay               = 5;
    menu_system_class::menu_options.element[5].active                    = true;
    menu_system_class::menu_options.element[5].type                      = BUTTON;
    menu_system_class::menu_options.element[5].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[5].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[5].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[5].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[5].position_x                = menu_system_class::menu_options.position_x+(menu_system_class::menu_options.size_x/2.0f)-(menu_system_class::menu_options.element[5].size_x*1.0f);
    menu_system_class::menu_options.element[5].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[5].size_y*3.25f);
    menu_system_class::menu_options.element[5].texture_ID.angle          = 180.0f;
    menu_system_class::menu_options.element[5].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_options.element[5].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_options.element[5].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;

    menu_system_class::menu_options.element[6].title.text                = "Music volume";
    menu_system_class::menu_options.element[6].value                     = game.core.config.audio_volume_music;
    menu_system_class::menu_options.element[6].value_max                 = 127.0f;
    menu_system_class::menu_options.element[6].active                    = true;
    menu_system_class::menu_options.element[6].type                      = BAR;
    menu_system_class::menu_options.element[6].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[6].zoom.enabled              = false;
    menu_system_class::menu_options.element[6].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*60.0f;
    menu_system_class::menu_options.element[6].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[6].position_x                = menu_system_class::menu_options.position_x;
    menu_system_class::menu_options.element[6].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[6].size_y*3.25f);
    menu_system_class::menu_options.element[6].texture_ID.normal         = game.resource.texture.slider_button_normal.ref_number;
    menu_system_class::menu_options.element[6].texture_ID.highlighted    = game.resource.texture.slider_button_highlighted.ref_number;
    menu_system_class::menu_options.element[6].title.size_x              = menu_system_class::menu_options.element[6].title.text.length()/2.2f;
    menu_system_class::menu_options.element[6].title.size_y              = menu_system_class::menu_options.element[6].title.size_x*4;;
    menu_system_class::menu_options.element[6].title.position_x          = menu_system_class::menu_options.element[6].position_x-(menu_system_class::menu_options.element[6].title.size_x/60.0f);
    menu_system_class::menu_options.element[6].title.position_y          = menu_system_class::menu_options.element[6].position_y-(menu_system_class::menu_options.element[6].title.size_y/1480.0f);

    menu_system_class::menu_options.element[7].title.text                = "";
    menu_system_class::menu_options.element[7].active                    = true;
    menu_system_class::menu_options.element[7].type                      = BUTTON;
    menu_system_class::menu_options.element[7].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[7].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[7].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[7].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[7].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[7].size_x*1.0f);
    menu_system_class::menu_options.element[7].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[7].size_y*4.50f);
    menu_system_class::menu_options.element[7].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_options.element[7].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_options.element[7].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;

    menu_system_class::menu_options.element[8].title.text                = "";
    menu_system_class::menu_options.element[8].active                    = true;
    menu_system_class::menu_options.element[8].type                      = BUTTON;
    menu_system_class::menu_options.element[8].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[8].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[8].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[8].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[8].position_x                = menu_system_class::menu_options.position_x+(menu_system_class::menu_options.size_x/2.0f)-(menu_system_class::menu_options.element[8].size_x*1.0f);
    menu_system_class::menu_options.element[8].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[8].size_y*4.50f);
    menu_system_class::menu_options.element[8].texture_ID.angle          = 180.0f;
    menu_system_class::menu_options.element[8].texture_ID.normal         = game.resource.texture.arrow_button_normal.ref_number;
    menu_system_class::menu_options.element[8].texture_ID.highlighted    = game.resource.texture.arrow_button_highlighted.ref_number;
    menu_system_class::menu_options.element[8].texture_ID.disabled       = game.resource.texture.arrow_button_disabled.ref_number;


    menu_system_class::menu_options.element[15].title.text                = "Main menu";
    menu_system_class::menu_options.element[15].active                    = true;
    menu_system_class::menu_options.element[15].type                      = BUTTON;
    menu_system_class::menu_options.element[15].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[15].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[15].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*80.0f;
    menu_system_class::menu_options.element[15].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[15].position_x                = menu_system_class::menu_options.position_x;
    menu_system_class::menu_options.element[15].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[15].size_y*9.0f);
    menu_system_class::menu_options.element[15].texture_ID                = menu_system_class::menu_options.texture_ID;
    menu_system_class::menu_options.element[15].title.size_x              = menu_system_class::menu_options.element[15].title.text.length()/1.2f;
    menu_system_class::menu_options.element[15].title.size_y              = menu_system_class::menu_options.element[15].title.size_x*4;;
    menu_system_class::menu_options.element[15].title.position_x          = menu_system_class::menu_options.element[15].position_x-(menu_system_class::menu_options.element[15].title.size_x/100.0f);
    menu_system_class::menu_options.element[15].title.position_y          = menu_system_class::menu_options.element[15].position_y-(menu_system_class::menu_options.element[15].title.size_y/1480.0f);

    //------ setup "game over" menu -----------
    menu_system_class::menu_game_over.mouse_delay                        = menu_system_class::mouse_delay;
    menu_system_class::menu_game_over.position_x                         = menu_system_class::position_x;
    menu_system_class::menu_game_over.position_y                         = menu_system_class::position_y;
    menu_system_class::menu_game_over.position_z                         = menu_system_class::position_z;
    menu_system_class::menu_game_over.size_x                             = menu_system_class::size_x;
    menu_system_class::menu_game_over.size_y                             = menu_system_class::size_y;
    menu_system_class::menu_game_over.size_z                             = menu_system_class::size_z;

    //------ setup "pause" menu -----------
    menu_system_class::menu_pause.mouse_delay                            = menu_system_class::mouse_delay;
    menu_system_class::menu_pause.position_x                             = menu_system_class::position_x;
    menu_system_class::menu_pause.position_y                             = menu_system_class::position_y;
    menu_system_class::menu_pause.position_z                             = menu_system_class::position_z;
    menu_system_class::menu_pause.size_x                                 = menu_system_class::size_x;
    menu_system_class::menu_pause.size_y                                 = menu_system_class::size_y;
    menu_system_class::menu_pause.size_z                                 = menu_system_class::size_z;

}

int menu_system_class::process(void)
{
    int old_event_state      = 0;
    int old_mouse_over_state = 0;
    int return_value         = 0;
    switch(menu_system_class::active_menu)
    {
        case MENU_MAIN:
            if (game.core.game_resume) menu_system_class::menu_main.element[3].state = NORMAL; // Save game
            else menu_system_class::menu_main.element[3].state = DISABLED;
            if (game.core.game_resume) menu_system_class::menu_main.element[4].state = NORMAL; // Resume game
            else menu_system_class::menu_main.element[4].state = DISABLED;
            old_event_state          = menu_system_class::menu_main.event;
            old_mouse_over_state     = menu_system_class::menu_main.mouse_over;
            return_value             = menu_system_class::menu_main.process();
            if (old_event_state      < menu_system_class::menu_main.event)      game.resource.sound.menu_select_00.play();
            if (old_mouse_over_state < menu_system_class::menu_main.mouse_over) game.resource.sound.menu_move_00.play();
            if (return_value != 0) menu_system_class::menu_main.mouse_delay.reset();
            switch (return_value)
            {
                case 1: // close button
                    if (game.state == STATE_GAME)
                    {
                        game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                        game.core.game_menu_active                   = false;
                    }
                    menu_system_class::event = 65535;
                    game.resource.sound.menu_select_00.play();
                break;
                case 2: // new game button
                    menu_system_class::active_menu = MENU_NEW_GAME;
                    menu_system_class::menu_new_game.set_position(menu_system_class::menu_main.position_x,menu_system_class::menu_main.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
                case 3: // load game button
                    menu_system_class::active_menu = MENU_LOAD;
                    menu_system_class::menu_load.set_position(menu_system_class::menu_main.position_x,menu_system_class::menu_main.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
                case 4: // save game button
                    menu_system_class::active_menu = MENU_SAVE;
                    menu_system_class::menu_save.set_position(menu_system_class::menu_main.position_x,menu_system_class::menu_main.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
                case 5: // resume game button
                    if (game.state == STATE_GAME)
                    {
                        game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                        game.core.game_menu_active                   = false;
                    }
                    game.resource.sound.menu_select_00.play();
               break;
                case 6: // options button
                    menu_system_class::active_menu = MENU_OPTIONS;
                    menu_system_class::menu_options.set_position(menu_system_class::menu_main.position_x,menu_system_class::menu_main.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
                case 8: // Exit game button
                    game.state = STATE_QUIT;
                    game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                    game.core.game_menu_active                   = false;
                    menu_system_class::event = 65535;
                    game.resource.sound.menu_select_00.play();
                break;
            }
        break;
        case MENU_NEW_GAME:
            old_event_state          = menu_system_class::menu_new_game.event;
            old_mouse_over_state     = menu_system_class::menu_new_game.mouse_over;
            return_value             = menu_system_class::menu_new_game.process();
            if (old_event_state      < menu_system_class::menu_new_game.event)      game.resource.sound.menu_select_00.play();
            if (old_mouse_over_state < menu_system_class::menu_new_game.mouse_over) game.resource.sound.menu_move_00.play();
            if (return_value != 0) menu_system_class::menu_new_game.mouse_delay.reset();
            switch (return_value)
            {
                case 1: // close button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_new_game.set_position(menu_system_class::menu_load.position_x,menu_system_class::menu_load.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
                case 2: // start new game button
                    game.init();
                    game.state = STATE_GAME;
                    game.core.music_next_track = true;
                    game.resource.sound.menu_select_00.play();
                break;
                case 16: // Main menu button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_new_game.set_position(menu_system_class::menu_load.position_x,menu_system_class::menu_load.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
            }
        break;
        case MENU_SAVE:
            old_event_state          = menu_system_class::menu_save.event;
            old_mouse_over_state     = menu_system_class::menu_save.mouse_over;
            return_value             = menu_system_class::menu_save.process();
            if (old_event_state      < menu_system_class::menu_save.event)      game.resource.sound.menu_select_00.play();
            if (old_mouse_over_state < menu_system_class::menu_save.mouse_over) game.resource.sound.menu_move_00.play();
            if (return_value != 0) menu_system_class::menu_save.mouse_delay.reset();
            switch (return_value)
            {
                case 1: // close button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_save.position_x,menu_system_class::menu_save.position_y);
                break;
                case 2: // Save slot 1 button
                    game.save_01.Assign_File("save/slot_01.sav");
                    if (game.save_01.Save())
                    {
                        game.core.log.file_write("Saved to slot 1");
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error saving to slot 1");
                break;
                case 3: // Save slot 2 button
                    game.save_02.Assign_File("save/slot_02.sav");
                    if (game.save_02.Save())
                    {
                        game.core.log.file_write("Saved to slot 2");
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error saving to slot 2");
                break;
                case 4: // Save slot 3 button
                    game.save_03.Assign_File("save/slot_03.sav");
                    if (game.save_03.Save())
                    {
                        game.core.log.file_write("Saved to slot 3");
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error saving to slot 3");
                break;
                case 5: // Save slot 4 button
                    game.save_04.Assign_File("save/slot_04.sav");
                    if (game.save_04.Save())
                    {
                        game.core.log.file_write("Saved to slot 4");
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error saving to slot 4");
                break;
                case 6: // Save slot 5 button
                    game.save_05.Assign_File("save/slot_05.sav");
                    if (game.save_05.Save())
                    {
                        game.core.log.file_write("Saved to slot 5");
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error saving to slot 5");
                break;
                case 8: // main menu button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_save.position_x,menu_system_class::menu_save.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
            }
        break;
        case MENU_LOAD:
            game.save_01.Assign_File("save/slot_01.sav");
            if (game.save_01.File_Exists()) menu_system_class::menu_load.element[2].state = true;
            else menu_system_class::menu_load.element[2].state = false;
            game.save_02.Assign_File("save/slot_02.sav");
            if (game.save_02.File_Exists()) menu_system_class::menu_load.element[3].state = true;
            else menu_system_class::menu_load.element[3].state = false;
            game.save_03.Assign_File("save/slot_03.sav");
            if (game.save_03.File_Exists()) menu_system_class::menu_load.element[4].state = true;
            else menu_system_class::menu_load.element[4].state = false;
            game.save_04.Assign_File("save/slot_04.sav");
            if (game.save_04.File_Exists()) menu_system_class::menu_load.element[5].state = true;
            else menu_system_class::menu_load.element[5].state = false;
            game.save_05.Assign_File("save/slot_05.sav");
            if (game.save_05.File_Exists()) menu_system_class::menu_load.element[6].state = true;
            else menu_system_class::menu_load.element[6].state = false;
            old_event_state          = menu_system_class::menu_load.event;
            old_mouse_over_state     = menu_system_class::menu_load.mouse_over;
            return_value             = menu_system_class::menu_load.process();
            if (old_event_state      < menu_system_class::menu_load.event)      game.resource.sound.menu_select_00.play();
            if (old_mouse_over_state < menu_system_class::menu_load.mouse_over) game.resource.sound.menu_move_00.play();
            if (return_value != 0) menu_system_class::menu_load.mouse_delay.reset();
            switch (return_value)
            {
                case 1: // close button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_load.position_x,menu_system_class::menu_load.position_y);
                break;
                case 2: // load slot 1 button
                    game.save_01.Assign_File("save/slot_01.sav");
                    if (game.save_01.Load())
                    {
                        game.core.log.file_write("Loading from slot 1");
                        game.state = STATE_GAME;
                        game.core.music_next_track = true;
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error loading from slot 1");
                break;
                case 3: // load slot 2 button
                    game.save_02.Assign_File("save/slot_02.sav");
                    if (game.save_02.Load())
                    {
                        game.core.log.file_write("Loading from slot 2");
                        game.state = STATE_GAME;
                        game.core.music_next_track = true;
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error loading from slot 2");
                break;
                case 4: // load slot 3 button
                    game.save_03.Assign_File("save/slot_03.sav");
                    if (game.save_03.Load())
                    {
                        game.core.log.file_write("Loading from slot 3");
                        game.state = STATE_GAME;
                        game.core.music_next_track = true;
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error loading from slot 3");
                break;
                case 5: // load slot 4 button
                    game.save_04.Assign_File("save/slot_04.sav");
                    if (game.save_04.Load())
                    {
                        game.core.log.file_write("Loading from slot 4");
                        game.state = STATE_GAME;
                        game.core.music_next_track = true;
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error loading from slot 4");
                break;
                case 6: // load slot 5 button
                    game.save_05.Assign_File("save/slot_05.sav");
                    if (game.save_05.Load())
                    {
                        game.core.log.file_write("Loading from slot 5");
                        game.state = STATE_GAME;
                        game.core.music_next_track = true;
                        game.resource.sound.menu_select_00.play();
                    }
                    else game.core.log.file_write("ERROR -> Error loading from slot 5");
                break;
                case 8: // main menu button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_load.position_x,menu_system_class::menu_load.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
            }
        break;
        case MENU_OPTIONS:
            old_event_state          = menu_system_class::menu_options.event;
            old_mouse_over_state     = menu_system_class::menu_options.mouse_over;
            return_value             = menu_system_class::menu_options.process();
            if (old_event_state      < menu_system_class::menu_options.event)      game.resource.sound.menu_select_00.play();
            if (old_mouse_over_state < menu_system_class::menu_options.mouse_over) game.resource.sound.menu_move_00.play();
            if (return_value != 0) menu_system_class::menu_options.mouse_delay.reset();
            switch (return_value)
            {
                case 1: // close button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_options.position_x,menu_system_class::menu_options.position_y);
                break;
                case 2: // sound volume left arrow
                    game.core.config.audio_volume_sound--;
                    if (game.core.config.audio_volume_sound < 0.0f) game.core.config.audio_volume_sound = 0.0f;
                    menu_system_class::menu_options.element[3].value = game.core.config.audio_volume_sound;
                    Mix_Volume(-1,game.core.config.audio_volume_sound);
                break;
                case 3: // sound volume right arrow
                    game.core.config.audio_volume_sound++;
                    if (game.core.config.audio_volume_sound > menu_system_class::menu_options.element[3].value_max) game.core.config.audio_volume_sound = menu_system_class::menu_options.element[3].value_max;
                    menu_system_class::menu_options.element[3].value = game.core.config.audio_volume_sound;
                    Mix_Volume(-1,game.core.config.audio_volume_sound);
                break;
                case 5: // music volume left arrow
                    game.core.config.audio_volume_music--;
                    if (game.core.config.audio_volume_music < 0.0f) game.core.config.audio_volume_music = 0.0f;
                    menu_system_class::menu_options.element[6].value = game.core.config.audio_volume_music;
                    Mix_VolumeMusic(game.core.config.audio_volume_music);
                break;
                case 6: // music volume right arrow
                    game.core.config.audio_volume_music++;
                    if (game.core.config.audio_volume_music > menu_system_class::menu_options.element[6].value_max) game.core.config.audio_volume_music = menu_system_class::menu_options.element[6].value_max;
                    menu_system_class::menu_options.element[6].value = game.core.config.audio_volume_music;
                    Mix_VolumeMusic(game.core.config.audio_volume_music);
                break;
                case 16: // main menu button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_options.position_x,menu_system_class::menu_options.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
            }
        break;
        case MENU_GAME_OVER:
           return_value  =  menu_system_class::menu_game_over.process();
            return_value += (100*(MENU_GAME_OVER+1));
        break;
        case MENU_PAUSE:
            return_value  = menu_system_class::menu_pause.process();
            return_value += (100*(MENU_PAUSE+1));
        break;
        default:
        break;
    }
    return(return_value);
}

void menu_system_class::render(void)
{
    if (game.state != STATE_GAME)
    {
        game.resource.texture.logo.draw(true,0.0f,0.9f,0.001f,1.6f,0.2f);
        game.resource.font.font_1.Write(255,255,255,64,-0.98f,-0.98f,2,16,"www.PhysHexGames.co.nr");
    }


    switch(menu_system_class::active_menu)
    {
        case MENU_MAIN:
            menu_system_class::menu_main.render();
        break;
        case MENU_NEW_GAME:
            menu_system_class::menu_new_game.render();
        break;
        case MENU_SAVE:
            menu_system_class::menu_save.render();
        break;
        case MENU_LOAD:
            menu_system_class::menu_load.render();
        break;
        case MENU_OPTIONS:
            menu_system_class::menu_options.render();
        break;
        case MENU_GAME_OVER:
            menu_system_class::menu_game_over.render();
        break;
        case MENU_PAUSE:
            menu_system_class::menu_pause.render();
        break;
        default:
        break;
    }
}



void init_menu   (void)
{

/*
    game.main_menu.set_menu_title(game.language.text.main_menu);
    game.main_menu.set_keyboard_delay(16);
    game.main_menu.set_mouse_delay(24);
    game.main_menu.set_pos(0.0f,0.0f,0.001f);
    game.main_menu.set_size(0.5f,1.0f);
    game.main_menu.set_menu_font(1);
    game.main_menu.set_image_background(game.resource.texture.background_02.ref_number);
    game.main_menu.set_button_zoom(true,0.008f,0.0005f);
    game.main_menu.set_button_images(game.resource.texture.button_normal.ref_number,game.resource.texture.button_highlighted.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.selection_box.ref_number,game.resource.texture.slider_button_normal.ref_number,game.resource.texture.slider_button_highlighted.ref_number,game.resource.texture.arrow_button_normal.ref_number,game.resource.texture.arrow_button_highlighted.ref_number,game.resource.texture.arrow_button_disabled.ref_number);
    game.main_menu.set_color_normal(128,128,128,255);
    game.main_menu.set_color_highlighted(192,192,192,255);
    game.main_menu.set_color_disabled(064,064,064,128);
    game.main_menu.set_number_of_buttons(7);
    game.main_menu.set_button_data  ( 1,game.language.text.new_game);
    game.main_menu.set_button_data  ( 2,game.language.text.load_game);
    game.main_menu.set_button_data  ( 3,game.language.text.save_game);
    game.main_menu.set_button_data  ( 4,game.language.text.resume_game);
    game.main_menu.set_button_data  ( 5,game.language.text.options);
    game.main_menu.set_button_active( 6,false);
    game.main_menu.set_button_data  ( 7,game.language.text.quit_game);
    game.main_menu.set_buttons_auto();
    game.main_menu.set_close_button_data(game.resource.texture.close_button.ref_number,game.resource.texture.close_button_highlighted.ref_number);
    game.main_menu.set_title_data(game.language.text.main_menu);//needs to be called last due to size generated by number of buttons etc....
    game.main_menu.set_color_title(255,255,255,255);
    game.main_menu.set_text_size(4.8f,32.0f);
    //------ setup "new game" menu -----------
    game.new_game_menu.set_menu_title(game.language.text.new_game);
    game.new_game_menu.set_keyboard_delay(16);
    game.new_game_menu.set_mouse_delay(8);
    game.new_game_menu.set_pos(0.0f,0.0f,0.001f);
    game.new_game_menu.set_size(0.4f,0.6f);
    game.new_game_menu.set_menu_font(1);
    game.new_game_menu.set_image_background(game.resource.texture.background_02.ref_number);
    game.new_game_menu.set_button_zoom(true,0.008f,0.0005f);
    game.new_game_menu.set_toggle_button_images(game.resource.texture.green_button_highlighted.ref_number,game.resource.texture.green_button.ref_number,game.resource.texture.red_button_highlighted.ref_number,game.resource.texture.red_button.ref_number);
    game.new_game_menu.set_button_images(game.resource.texture.button_normal.ref_number,game.resource.texture.button_highlighted.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.selection_box.ref_number,game.resource.texture.slider_button_normal.ref_number,game.resource.texture.slider_button_highlighted.ref_number,game.resource.texture.arrow_button_normal.ref_number,game.resource.texture.arrow_button_highlighted.ref_number,game.resource.texture.arrow_button_disabled.ref_number);
    game.new_game_menu.set_color_normal(128,128,128,255);
    game.new_game_menu.set_color_highlighted(192,192,192,255);
    game.new_game_menu.set_color_disabled(064,064,064,128);
    game.new_game_menu.set_number_of_buttons(4);

    game.new_game_menu.set_button_data  ( 1,"Player portrait");
    game.new_game_menu.set_number_of_choices(1,13);
    game.new_game_menu.set_number_of_visible_choices(1,5);
    game.new_game_menu.set_button_choice_position(1,1);
    game.new_game_menu.set_button_disabled_text_label("Locked");
    game.new_game_menu.set_button_current_choice(1,1);
    game.new_game_menu.set_button_choice_data(1, 1,game.resource.texture.portrait_00.ref_number,"Portrait 00",   true, true);
    game.new_game_menu.set_button_choice_data(1, 2,game.resource.texture.portrait_01.ref_number,"Portrait 01",   true, true);
    game.new_game_menu.set_button_choice_data(1, 3,game.resource.texture.portrait_02.ref_number,"Portrait 02",   true, true);
    game.new_game_menu.set_button_choice_data(1, 4,game.resource.texture.portrait_03.ref_number,"Portrait 03",   true, true);
    game.new_game_menu.set_button_choice_data(1, 5,game.resource.texture.portrait_04.ref_number,"Portrait 04",   true, true);
    game.new_game_menu.set_button_choice_data(1, 6,game.resource.texture.portrait_05.ref_number,"Portrait 05",   true, true);
    game.new_game_menu.set_button_choice_data(1, 7,game.resource.texture.portrait_06.ref_number,"Portrait 06",   true, true);
    game.new_game_menu.set_button_choice_data(1, 8,game.resource.texture.portrait_07.ref_number,"Portrait 07",   true, true);
    game.new_game_menu.set_button_choice_data(1, 9,game.resource.texture.portrait_08.ref_number,"Portrait 08",   true, true);
    game.new_game_menu.set_button_choice_data(1,10,game.resource.texture.portrait_09.ref_number,"Portrait 09",   true, true);
    game.new_game_menu.set_button_choice_data(1,11,game.resource.texture.portrait_10.ref_number,"Portrait 10",   true, true);
    game.new_game_menu.set_button_choice_data(1,12,game.resource.texture.portrait_11.ref_number,"Portrait 11",   true, true);
    game.new_game_menu.set_button_choice_data(1,13,game.resource.texture.portrait_12.ref_number,"Portrait 12",   true, true);

    game.new_game_menu.set_button_data  ( 2,game.language.text.new_game);
    game.new_game_menu.set_button_active( 3,false);
    game.new_game_menu.set_button_data  ( 4,game.language.text.main_menu);
    game.new_game_menu.set_buttons_auto();
    game.new_game_menu.set_close_button_data(game.resource.texture.close_button.ref_number,game.resource.texture.close_button_highlighted.ref_number);
    game.new_game_menu.set_button_arrow_data_auto(1);
    game.new_game_menu.set_title_data(game.language.text.new_game);//needs to be called last due to size generated by number of buttons etc....
    game.new_game_menu.set_color_title(255,255,255,255);
    game.new_game_menu.set_text_size(4.8f,32.0f);
    //------ setup "save game" menu -----------
    game.save_menu.set_menu_title(game.language.text.save_menu);
    game.save_menu.set_keyboard_delay(16);
    game.save_menu.set_mouse_delay(24);
    game.save_menu.set_pos(0.0f,0.0f,0.001f);
    game.save_menu.set_size(0.5f,1.0f);
    game.save_menu.set_menu_font(1);
    game.save_menu.set_image_background(game.resource.texture.background_02.ref_number);
    game.save_menu.set_button_zoom(true,0.008f,0.0005f);
    game.save_menu.set_button_images(game.resource.texture.button_normal.ref_number,game.resource.texture.button_highlighted.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.selection_box.ref_number,game.resource.texture.slider_button_normal.ref_number,game.resource.texture.slider_button_highlighted.ref_number,game.resource.texture.arrow_button_normal.ref_number,game.resource.texture.arrow_button_highlighted.ref_number,game.resource.texture.arrow_button_disabled.ref_number);
    game.save_menu.set_color_normal(128,128,128,255);
    game.save_menu.set_color_highlighted(192,192,192,255);
    game.save_menu.set_color_disabled(064,064,064,128);
    game.save_menu.set_number_of_buttons(9);
    game.save_menu.set_button_data  ( 1,game.language.text.save_slot_1);
    game.save_menu.set_button_data  ( 2,game.language.text.save_slot_2);
    game.save_menu.set_button_data  ( 3,game.language.text.save_slot_3);
    game.save_menu.set_button_data  ( 4,game.language.text.save_slot_4);
    game.save_menu.set_button_data  ( 5,game.language.text.save_slot_5);
    game.save_menu.set_button_data  ( 6,game.language.text.save_slot_6);
    game.save_menu.set_button_data  ( 7,game.language.text.save_slot_7);
    game.save_menu.set_button_active( 8,false);
    game.save_menu.set_button_data  ( 9,game.language.text.main_menu);
    game.save_menu.set_buttons_auto();
    game.save_menu.set_close_button_data(game.resource.texture.close_button.ref_number,game.resource.texture.close_button_highlighted.ref_number);
    game.save_menu.set_title_data(game.language.text.save_menu);//needs to be called last due to size generated by number of buttons etc....
    game.save_menu.set_color_title(255,255,255,255);
    game.save_menu.set_text_size(4.8f,32.0f);
    //------ setup "load game" menu -----------
    game.load_menu.set_menu_title(game.language.text.load_menu);
    game.load_menu.set_keyboard_delay(16);
    game.load_menu.set_mouse_delay(24);
    game.load_menu.set_pos(0.0f,0.0f,0.001f);
    game.load_menu.set_size(0.5f,1.0f);
    game.load_menu.set_menu_font(1);
    game.load_menu.set_image_background(game.resource.texture.background_02.ref_number);
    game.load_menu.set_button_zoom(true,0.008f,0.0005f);
    game.load_menu.set_button_images(game.resource.texture.button_normal.ref_number,game.resource.texture.button_highlighted.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.selection_box.ref_number,game.resource.texture.slider_button_normal.ref_number,game.resource.texture.slider_button_highlighted.ref_number,game.resource.texture.arrow_button_normal.ref_number,game.resource.texture.arrow_button_highlighted.ref_number,game.resource.texture.arrow_button_disabled.ref_number);
    game.load_menu.set_color_normal(128,128,128,255);
    game.load_menu.set_color_highlighted(192,192,192,255);
    game.load_menu.set_color_disabled(064,064,064,128);
    game.load_menu.set_number_of_buttons(9);
    game.load_menu.set_button_data  ( 1,game.language.text.save_slot_1);
    game.load_menu.set_button_data  ( 2,game.language.text.save_slot_2);
    game.load_menu.set_button_data  ( 3,game.language.text.save_slot_3);
    game.load_menu.set_button_data  ( 4,game.language.text.save_slot_4);
    game.load_menu.set_button_data  ( 5,game.language.text.save_slot_5);
    game.load_menu.set_button_data  ( 6,game.language.text.save_slot_6);
    game.load_menu.set_button_data  ( 7,game.language.text.save_slot_7);
    game.load_menu.set_button_active( 8,false);
    game.load_menu.set_button_data  ( 9,game.language.text.main_menu);
    game.load_menu.set_buttons_auto();
    game.load_menu.set_close_button_data(game.resource.texture.close_button.ref_number,game.resource.texture.close_button_highlighted.ref_number);
    game.load_menu.set_title_data(game.language.text.load_menu);//needs to be called last due to size generated by number of buttons etc....
    game.core.save_01.Assign_File("save/slot_01.sav");
    if (game.core.save_01.File_Exists()) game.load_menu.button[1].set_enabled(true);
    else game.load_menu.button[1].set_enabled(false);
    game.core.save_02.Assign_File("save/slot_02.sav");
    if (game.core.save_02.File_Exists()) game.load_menu.button[2].set_enabled(true);
    else game.load_menu.button[2].set_enabled(false);
    game.core.save_03.Assign_File("save/slot_03.sav");
    if (game.core.save_03.File_Exists()) game.load_menu.button[3].set_enabled(true);
    else game.load_menu.button[3].set_enabled(false);
    game.core.save_04.Assign_File("save/slot_04.sav");
    if (game.core.save_04.File_Exists()) game.load_menu.button[4].set_enabled(true);
    else game.load_menu.button[4].set_enabled(false);
    game.core.save_05.Assign_File("save/slot_05.sav");
    if (game.core.save_05.File_Exists()) game.load_menu.button[5].set_enabled(true);
    else game.load_menu.button[5].set_enabled(false);
    game.core.save_06.Assign_File("save/slot_06.sav");
    if (game.core.save_06.File_Exists()) game.load_menu.button[6].set_enabled(true);
    else game.load_menu.button[6].set_enabled(false);
    game.core.save_07.Assign_File("save/slot_07.sav");
    if (game.core.save_07.File_Exists()) game.load_menu.button[7].set_enabled(true);
    else game.load_menu.button[7].set_enabled(false);
    game.load_menu.set_color_title(255,255,255,255);
    game.load_menu.set_text_size(4.8f,32.0f);
    //------ setup "options" menu -----------
    game.options_menu.set_menu_title(game.language.text.options);
    game.options_menu.set_keyboard_delay(16);
    game.options_menu.set_mouse_delay(24);
    game.options_menu.set_pos(0.0f,0.0f,0.001f);
    game.options_menu.set_size(0.5f,1.0f);
    game.options_menu.set_menu_font(1);
    game.options_menu.set_image_background(game.resource.texture.background_02.ref_number);
    game.options_menu.set_button_zoom(true,0.008f,0.0005f);
    game.options_menu.set_button_images(game.resource.texture.button_normal.ref_number,game.resource.texture.button_highlighted.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.selection_box.ref_number,game.resource.texture.slider_button_normal.ref_number,game.resource.texture.slider_button_highlighted.ref_number,game.resource.texture.arrow_button_normal.ref_number,game.resource.texture.arrow_button_highlighted.ref_number,game.resource.texture.arrow_button_disabled.ref_number);
    game.options_menu.set_toggle_button_images(game.resource.texture.green_button_highlighted.ref_number,game.resource.texture.green_button.ref_number,game.resource.texture.red_button_highlighted.ref_number,game.resource.texture.red_button.ref_number);
    game.options_menu.set_color_normal(128,128,128,255);
    game.options_menu.set_color_highlighted(192,192,192,255);
    game.options_menu.set_color_disabled(064,064,064,128);
    game.options_menu.set_number_of_buttons(6);
    game.options_menu.set_button_data  ( 1,game.language.text.sound_volume);
    game.options_menu.set_button_type  ( 1,SLIDER);
    game.options_menu.set_button_slider_position(1,game.core.config.Audio_Sound_Volume);
    game.options_menu.set_button_slider_position_max(1,128);
    game.options_menu.set_button_data  ( 2,game.language.text.music_volume);
    game.options_menu.set_button_type  ( 2,SLIDER);
    game.options_menu.set_button_slider_position(2,game.core.config.Audio_Music_Volume);
    game.options_menu.set_button_slider_position_max(2,128);
    game.options_menu.set_button_data  ( 3,game.language.text.screen_resolution);
    game.options_menu.set_number_of_choices(3,8);
    game.options_menu.set_number_of_visible_choices(3,5);
    game.options_menu.set_button_choice_position(3,1);
    game.options_menu.set_button_disabled_text_label(game.language.text.menu_item_unavailable);
    game.options_menu.set_button_current_choice(3,game.core.config.Display_resolution);
    game.options_menu.set_button_choice_data(3, 1,game.resource.texture.resolution_icon.ref_number,game.language.text.res_640_x_480,   true, true);
    game.options_menu.set_button_choice_data(3, 2,game.resource.texture.resolution_icon.ref_number,game.language.text.res_800_x_600,   true, true);
    game.options_menu.set_button_choice_data(3, 3,game.resource.texture.resolution_icon.ref_number,game.language.text.res_1024_x_768,  true, true);
    game.options_menu.set_button_choice_data(3, 4,game.resource.texture.resolution_icon.ref_number,game.language.text.res_1280_x_1024, true, true);
    game.options_menu.set_button_choice_data(3, 5,game.resource.texture.resolution_icon.ref_number,game.language.text.res_1366_x_768,  true, true);
    game.options_menu.set_button_choice_data(3, 6,game.resource.texture.resolution_icon.ref_number,game.language.text.res_1440_x_900,  true, true);
    game.options_menu.set_button_choice_data(3, 7,game.resource.texture.resolution_icon.ref_number,game.language.text.res_1680_x_1050, true, true);
    game.options_menu.set_button_choice_data(3, 8,game.resource.texture.resolution_icon.ref_number,game.language.text.res_1920_x_1080, true, true);
    game.options_menu.set_button_data  ( 4,game.language.text.full_screen);
    game.options_menu.set_button_type  ( 4,TOGGLE);
    game.options_menu.set_button_active( 5,false);
    game.options_menu.set_button_data  ( 6,game.language.text.main_menu);
    game.options_menu.set_buttons_auto();
    game.options_menu.set_close_button_data(game.resource.texture.close_button.ref_number,game.resource.texture.close_button_highlighted.ref_number);
    game.options_menu.set_title_data(game.language.text.options);//needs to be called last due to size generated by number of buttons etc....
    game.options_menu.set_color_title(255,255,255,255);
    game.options_menu.set_text_size(4.8f,32.0f);
    //------ setup "game over" menu -----------
    game.game_over_menu.set_menu_title(game.language.text.game_over);
    game.game_over_menu.set_keyboard_delay(16);
    game.game_over_menu.set_mouse_delay(24);
    game.game_over_menu.set_pos(0.0f,0.0f,0.001f);
    game.game_over_menu.set_size(0.4f,0.2f);
    game.game_over_menu.set_menu_font(1);
    game.game_over_menu.set_image_background(game.resource.texture.background_03.ref_number);
    game.game_over_menu.set_button_zoom(true,0.008f,0.0005f);
    game.game_over_menu.set_button_images(game.resource.texture.button_normal.ref_number,game.resource.texture.button_highlighted.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.selection_box.ref_number,game.resource.texture.slider_button_normal.ref_number,game.resource.texture.slider_button_highlighted.ref_number,game.resource.texture.arrow_button_normal.ref_number,game.resource.texture.arrow_button_highlighted.ref_number,game.resource.texture.arrow_button_disabled.ref_number);
    game.game_over_menu.set_color_normal(128,128,128,255);
    game.game_over_menu.set_color_highlighted(192,192,192,255);
    game.game_over_menu.set_color_disabled(064,064,064,128);
    game.game_over_menu.set_number_of_buttons(1);
    game.game_over_menu.set_button_data  ( 1,game.language.text.main_menu);
    game.game_over_menu.set_buttons_auto();
    game.game_over_menu.set_close_button_data(game.resource.texture.close_button.ref_number,game.resource.texture.close_button_highlighted.ref_number);
    game.game_over_menu.set_title_data(game.language.text.game_over);//needs to be called last due to size generated by number of buttons etc....
    game.game_over_menu.set_color_title(255,255,255,255);
    game.game_over_menu.set_text_size(4.8f,32.0f);
    //------ setup "pause" menu -----------
    game.pause_menu.set_menu_title(game.language.text.game_paused);
    game.pause_menu.set_keyboard_delay(16);
    game.pause_menu.set_mouse_delay(24);
    game.pause_menu.set_pos(0.0f,0.0f,0.001f);
    game.pause_menu.set_size(0.4f,0.2f);
    game.pause_menu.set_menu_font(1);
    game.pause_menu.set_image_background(game.resource.texture.background_03.ref_number);
    game.pause_menu.set_button_zoom(true,0.008f,0.0005f);
    game.pause_menu.set_button_images(game.resource.texture.button_normal.ref_number,game.resource.texture.button_highlighted.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.button_disabled.ref_number,game.resource.texture.selection_box.ref_number,game.resource.texture.slider_button_normal.ref_number,game.resource.texture.slider_button_highlighted.ref_number,game.resource.texture.arrow_button_normal.ref_number,game.resource.texture.arrow_button_highlighted.ref_number,game.resource.texture.arrow_button_disabled.ref_number);
    game.pause_menu.set_color_normal(128,128,128,255);
    game.pause_menu.set_color_highlighted(192,192,192,255);
    game.pause_menu.set_color_disabled(064,064,064,128);
    game.pause_menu.set_number_of_buttons(1);
    game.pause_menu.set_button_data  ( 1,game.language.text.resume_game);
    game.pause_menu.set_buttons_auto();
    game.pause_menu.set_close_button_data(game.resource.texture.close_button.ref_number,game.resource.texture.close_button_highlighted.ref_number);
    game.pause_menu.set_title_data(game.language.text.game_paused);//needs to be called last due to size generated by number of buttons etc....
    game.pause_menu.set_color_title(255,255,255,255);
    game.pause_menu.set_text_size(4.8f,32.0f);
    return(0);
*/
};


//---------------------------------------------------------------------------------------
void process_menu(void)
{
/*
    int  activated_button = -1;
    bool set_resolution   = false;
    // ------------------- main menu ------------
    activated_button = -1;
    if (game.core.menu_level == 1)
    {
        if (game.core.game_resume) game.main_menu.button[3].set_enabled(true);
        else game.main_menu.button[3].set_enabled(false);
        if (game.core.game_resume) game.main_menu.button[4].set_enabled(true);
        else game.main_menu.button[4].set_enabled(false);
        activated_button = game.main_menu.process();
        switch (activated_button)
        {
            case 1://New Game
                game.sound.menu_select_00.play();
                game.core.menu_level = 2;
                game.core.log.File_Write("Entering 'New Game' menu.");
            break;
            case 2://Load Game
                game.sound.menu_select_00.play();
                game.core.menu_level = 3;
                game.core.log.File_Write("Entering 'Load Game' menu.");
            break;
            case 3://Save Game
                if (game.core.game_resume)
                {
                    game.sound.menu_select_00.play();
                    game.core.menu_level = 4;
                    game.core.log.File_Write("Entering 'Save Game' menu.");
                }
            break;
            case 4://Resume Game
                if (game.core.game_resume)
                {
                    game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.music_next_track = true;
                    game.core.game_active      = true;
                    game.core.menu_active      = false;
                    game.core.log.File_Write("Resuming Game");
                }
            break;
            case 5://Options
                game.sound.menu_select_00.play();
                game.core.menu_level = 5;
                game.core.log.File_Write("Entering 'Options' menu.");
            break;
            case 6://NA
            break;
            case 7://Quit Game
                game.sound.menu_select_00.play();
                game.core.status_quit_active = true;
                game.core.log.File_Write("User terminating game - 'Quit Game' selected!");
            break;
            case 65533://only move no select.
                game.sound.menu_move_00.play();
            break;
            case 65534:// escape pressed on keyboard.
                game.core.log.File_Write("User closing main menu - keyboard escape pressed!");
            break;
            case 65535:// close button clicked.
                if (!game.core.game_active)
                {
                    game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.status_quit_active      = true;
                    game.core.io.key_escape           = false;
                    game.core.log.File_Write("User closing main menu - clicked close button!");
                }
                else
                {
                    game.sound.menu_select_00.play();
                    game.core.menu_active = false;
                }
            break;
            default:
            break;
        };
    };
    // ------------------- New_Game Menu ------------
    activated_button = -1;
    if (game.core.menu_level == 2)
    {
        game.new_game_menu.set_button_current_choice(1,game.player.portrait_number-1);
        activated_button = game.new_game_menu.process();
        switch (activated_button)
        {
            case 101://Choice 1 selected
                game.player.portrait_number = game.new_game_menu.get_button_choice_position(1) + 0 -1;
            break;
            case 102://Choice 2 selected
                game.player.portrait_number = game.new_game_menu.get_button_choice_position(1) + 1 -1;
            break;
            case 103://Choice 3 selected
                game.player.portrait_number = game.new_game_menu.get_button_choice_position(1) + 2 -1;
            break;
            case 104://Choice 4 selected
                game.player.portrait_number = game.new_game_menu.get_button_choice_position(1) + 3 -1;
            break;
            case 105://Choice 5 selected
                game.player.portrait_number = game.new_game_menu.get_button_choice_position(1) + 4 -1;
            break;
            case 4001://left arrow on button 1
                game.new_game_menu.set_button_choice_position(1,game.new_game_menu.get_button_choice_position(1)-1);
                if (game.new_game_menu.get_button_choice_position(1) < 1) game.new_game_menu.set_button_choice_position(1,1);
            break;
            case 5001://right arrow on button 1
                game.new_game_menu.set_button_choice_position(1,game.new_game_menu.get_button_choice_position(1)+1);
                if (game.new_game_menu.get_button_choice_position(1) >= game.new_game_menu.get_number_of_choices(1)-(game.new_game_menu.get_number_of_visible_choices(1)-1)) game.new_game_menu.set_button_choice_position(1,game.new_game_menu.get_number_of_choices(1)-(game.new_game_menu.get_number_of_visible_choices(1)-1));
            break;
            case 2://Choice 1 selected
                {
                    if (game.player.portrait_number ==  0) game.player.portrait_image_ref = game.resource.texture.portrait_00.ref_number;
                    if (game.player.portrait_number ==  1) game.player.portrait_image_ref = game.resource.texture.portrait_01.ref_number;
                    if (game.player.portrait_number ==  2) game.player.portrait_image_ref = game.resource.texture.portrait_02.ref_number;
                    if (game.player.portrait_number ==  3) game.player.portrait_image_ref = game.resource.texture.portrait_03.ref_number;
                    if (game.player.portrait_number ==  4) game.player.portrait_image_ref = game.resource.texture.portrait_04.ref_number;
                    if (game.player.portrait_number ==  5) game.player.portrait_image_ref = game.resource.texture.portrait_05.ref_number;
                    if (game.player.portrait_number ==  6) game.player.portrait_image_ref = game.resource.texture.portrait_06.ref_number;
                    if (game.player.portrait_number ==  7) game.player.portrait_image_ref = game.resource.texture.portrait_07.ref_number;
                    if (game.player.portrait_number ==  8) game.player.portrait_image_ref = game.resource.texture.portrait_08.ref_number;
                    if (game.player.portrait_number ==  9) game.player.portrait_image_ref = game.resource.texture.portrait_09.ref_number;
                    if (game.player.portrait_number == 10) game.player.portrait_image_ref = game.resource.texture.portrait_10.ref_number;
                    if (game.player.portrait_number == 11) game.player.portrait_image_ref = game.resource.texture.portrait_11.ref_number;
                    if (game.player.portrait_number == 12) game.player.portrait_image_ref = game.resource.texture.portrait_12.ref_number;
                    game.sound.menu_select_00.play();
                    game.core.music_next_track = true;
                    game.core.game_active = true;
                    game.core.menu_active = false;
                    game.core.log.File_Write("Entering game world, starting new game.");
                }
            break;
            case 4://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from New_Game menu. - button selected.");
            break;
            case 65533://menu choice changed
                game.sound.menu_move_00.play();
            break;
            case 65534://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.io.key_escape           = false;
                game.core.log.File_Write("Entering main menu, from New_Game menu. - escape preses.");
            break;
            case 65535://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from New_Game menu. - button clicked.");
            break;
            default:
            break;
        };
    };
    // ------------------- Load menu ------------
    activated_button = -1;
    if (game.core.menu_level == 3)
    {
        activated_button = game.load_menu.process();
        switch (activated_button)
        {
            case 1://Save Slot 1 selected.
                if (game.load_menu.get_button_enabled(1))
                {
                    game.core.save_01.Assign_File("save/slot_01.sav");
                    if (game.core.save_01.Load())
                    {
                        game.core.log.File_Write("Loading from slot 1");
                        //game.loaded.spawn();
                        game.core.game_active = true;
                        game.core.menu_active = false;
                        game.core.log.File_Write("Resuming game");
                        game.core.music_next_track = true;
                        game.sound.menu_select_00.play();
                    }
                }
            break;
            case 2://Save Slot 2 selected.
                if (game.load_menu.get_button_enabled(2))
                {
                    game.core.save_02.Assign_File("save/slot_02.sav");
                    if (game.core.save_02.Load())
                    {
                        game.core.log.File_Write("Loading from slot 2");
                        //game.loaded.spawn();
                        game.core.game_active = true;
                        game.core.menu_active = false;
                        game.core.log.File_Write("Resuming game");
                        game.core.music_next_track = true;
                        game.sound.menu_select_00.play();
                    }
                }
            break;
            case 3://Save Slot 3 selected.
                if (game.load_menu.get_button_enabled(3))
                {
                    game.core.save_03.Assign_File("save/slot_03.sav");
                    if (game.core.save_03.Load())
                    {
                        game.core.log.File_Write("Loading from slot 3");
                        //game.loaded.spawn();
                        game.core.game_active = true;
                        game.core.menu_active = false;
                        game.core.log.File_Write("Resuming game");
                        game.core.music_next_track = true;
                        game.sound.menu_select_00.play();
                    }
                }
            break;
            case 4://Save Slot 4 selected.
                if (game.load_menu.get_button_enabled(4))
                {
                    game.core.save_04.Assign_File("save/slot_04.sav");
                    if (game.core.save_04.Load())
                    {
                        game.core.log.File_Write("Loading from slot 4");
                        //game.loaded.spawn();
                        game.core.game_active = true;
                        game.core.menu_active = false;
                        game.core.log.File_Write("Resuming game");
                        game.core.music_next_track = true;
                        game.sound.menu_select_00.play();
                    }
                }
            break;
            case 5://Save Slot 5 selected.
                if (game.load_menu.get_button_enabled(5))
                {
                    game.core.save_05.Assign_File("save/slot_05.sav");
                    if (game.core.save_05.Load())
                    {
                        game.core.log.File_Write("Loading from slot 5");
                        //game.loaded.spawn();
                        game.core.game_active = true;
                        game.core.menu_active = false;
                        game.core.log.File_Write("Resuming game");
                        game.core.music_next_track = true;
                        game.sound.menu_select_00.play();
                    }
                }
            break;
            case 6://Save Slot 6 selected.
                if (game.load_menu.get_button_enabled(6))
                {
                    game.core.save_06.Assign_File("save/slot_06.sav");
                    if (game.core.save_06.Load())
                    {
                        game.core.log.File_Write("Loading from slot 6");
                        //game.loaded.spawn();
                        game.core.game_active = true;
                        game.core.menu_active = false;
                        game.core.log.File_Write("Resuming game");
                        game.core.music_next_track = true;
                        game.sound.menu_select_00.play();
                    }
                }
            break;
            case 7://Save Slot 7 selected.
                if (game.load_menu.get_button_enabled(7))
                {
                    game.core.save_07.Assign_File("save/slot_07.sav");
                    if (game.core.save_07.Load())
                    {
                        game.core.log.File_Write("Loading from slot 7");
                        //game.loaded.spawn();
                        game.core.game_active = true;
                        game.core.menu_active = false;
                        game.core.log.File_Write("Resuming game");
                        game.core.music_next_track = true;
                        game.sound.menu_select_00.play();
                    }
                }
            break;
            case 9://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from load menu. - button selected.");
            break;
            case 65533://menu choice changed
                game.sound.menu_move_00.play();
            break;
            case 65534://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.io.key_escape           = false;
                game.core.log.File_Write("Entering main menu, from load menu. - escape preses.");
            break;
            case 65535://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from load menu. - button clicked.");
            break;
            default:
            break;
        };
    };
    // ------------------- Save menu ------------
    activated_button = -1;
    if (game.core.menu_level == 4)
    {
        activated_button = game.save_menu.process();
        switch (activated_button)
        {
            case 1://Save Slot 1 selected.
                game.core.save_01.Assign_File("save/slot_01.sav");
                game.core.save_01.Save();
                game.core.log.File_Write("Saving to slot 1");
                //game.saved.spawn();
                game.core.game_active = true;
                game.core.menu_active = false;
                game.core.log.File_Write("Resuming game");
                game.core.music_next_track = true;
                game.sound.menu_select_00.play();
                game.load_menu.button[1].set_enabled(true);
            break;
            case 2://Save Slot 2 selected.
                game.core.save_02.Assign_File("save/slot_02.sav");
                game.core.save_02.Save();
                game.core.log.File_Write("Saving to slot 2");
                //game.saved.spawn();
                game.core.game_active = true;
                game.core.menu_active = false;
                game.core.log.File_Write("Resuming game");
                game.core.music_next_track = true;
                game.sound.menu_select_00.play();
                game.load_menu.button[2].set_enabled(true);
            break;
            case 3://Save Slot 3 selected.
                game.core.save_03.Assign_File("save/slot_03.sav");
                game.core.save_03.Save();
                game.core.log.File_Write("Saving to slot 3");
                //game.saved.spawn();
                game.core.game_active = true;
                game.core.menu_active = false;
                game.core.log.File_Write("Resuming game");
                game.core.music_next_track = true;
                game.sound.menu_select_00.play();
                game.load_menu.button[3].set_enabled(true);
            break;
            case 4://Save Slot 4 selected.
                game.core.save_04.Assign_File("save/slot_04.sav");
                game.core.save_04.Save();
                game.core.log.File_Write("Saving to slot 4");
                //game.saved.spawn();
                game.core.game_active = true;
                game.core.menu_active = false;
                game.core.log.File_Write("Resuming game");
                game.core.music_next_track = true;
                game.sound.menu_select_00.play();
                game.load_menu.button[4].set_enabled(true);
            break;
            case 5://Save Slot 5 selected.
                game.core.save_05.Assign_File("save/slot_05.sav");
                game.core.save_05.Save();
                game.core.log.File_Write("Saving to slot 5");
                //game.saved.spawn();
                game.core.game_active = true;
                game.core.menu_active = false;
                game.core.log.File_Write("Resuming game");
                game.core.music_next_track = true;
                game.sound.menu_select_00.play();
                game.load_menu.button[5].set_enabled(true);
            break;
            case 6://Save Slot 6 selected.
                game.core.save_06.Assign_File("save/slot_06.sav");
                game.core.save_06.Save();
                game.core.log.File_Write("Saving to slot 6");
                //game.saved.spawn();
                game.core.game_active = true;
                game.core.menu_active = false;
                game.core.log.File_Write("Resuming game");
                game.core.music_next_track = true;
                game.sound.menu_select_00.play();
                game.load_menu.button[6].set_enabled(true);
            break;
            case 7://Save Slot 7 selected.
                game.core.save_07.Assign_File("save/slot_07.sav");
                game.core.save_07.Save();
                game.core.log.File_Write("Saving to slot 7");
                //game.saved.spawn();
                game.core.game_active = true;
                game.core.menu_active = false;
                game.core.log.File_Write("Resuming game");
                game.core.music_next_track = true;
                game.sound.menu_select_00.play();
                game.load_menu.button[7].set_enabled(true);
            break;
            case 9://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from save menu. - button selected.");
            break;
            case 65533://menu choice changed
                game.sound.menu_move_00.play();
            break;
            case 65534://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.io.key_escape           = false;
                game.core.log.File_Write("Entering main menu, from save menu. - escape preses.");
            break;
            case 65535://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from save menu. - button clicked.");
            break;
            default:
            break;
        };
    };
    // ------------------- Options Menu ------------
    activated_button = -1;
    if (game.core.menu_level == 5)
    {
        game.options_menu.set_toggle_data(4,game.core.config.Display_Fullscreen);
        activated_button = game.options_menu.process();
        game.options_menu.set_button_current_choice(3,game.core.config.Display_resolution-1);
        switch (activated_button)
        {
            case 4://Toggle Full-screen
                game.options_menu.set_toggle_data(4,!game.options_menu.get_toggle_data(4));
                game.core.config.Display_Fullscreen   = !game.core.config.Display_Fullscreen;
                if (game.core.config.Display_Fullscreen) SDL_SetVideoMode(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution,game.core.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
                else                                SDL_SetVideoMode(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution,game.core.config.Display_BPS,SDL_OPENGL);
                game.core.graphics.init_gl(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution);
                load_textures();
            break;
            case 301://Choice 1 selected
                if (game.core.config.Display_resolution != game.options_menu.get_button_choice_position(3) + 0 -1)
                {
                    game.core.config.Display_resolution = game.options_menu.get_button_choice_position(3) + 0 -1;
                    set_resolution = true;
                }
            break;
            case 302://Choice 2 selected
                if (game.core.config.Display_resolution != game.options_menu.get_button_choice_position(3) + 1 -1)
                {
                    game.core.config.Display_resolution = game.options_menu.get_button_choice_position(3) + 1 -1;
                    set_resolution = true;
                }
            break;
            case 303://Choice 3 selected
                if (game.core.config.Display_resolution != game.options_menu.get_button_choice_position(3) + 2 -1)
                {
                    game.core.config.Display_resolution = game.options_menu.get_button_choice_position(3) + 2 -1;
                    set_resolution = true;
                }
            break;
            case 304://Choice 4 selected
                if (game.core.config.Display_resolution != game.options_menu.get_button_choice_position(3) + 3 -1)
                {
                    game.core.config.Display_resolution = game.options_menu.get_button_choice_position(3) + 3 -1;
                    set_resolution = true;
                }
            break;
            case 305://Choice 5 selected
                if (game.core.config.Display_resolution != game.options_menu.get_button_choice_position(3) + 4 -1)
                {
                    game.core.config.Display_resolution = game.options_menu.get_button_choice_position(3) + 4 -1;
                    set_resolution = true;
                }
            break;
            case 4001://left arrow on button 1
                game.core.config.Audio_Sound_Volume --;
                if (game.core.config.Audio_Sound_Volume < 0) game.core.config.Audio_Sound_Volume = 0;
                Mix_Volume(-1,game.core.config.Audio_Sound_Volume);
                game.options_menu.set_button_slider_position(1,game.core.config.Audio_Sound_Volume);
            break;
            case 5001://right arrow on button 1
                game.core.config.Audio_Sound_Volume++;
                if (game.core.config.Audio_Sound_Volume > 128) game.core.config.Audio_Sound_Volume = 128;
                Mix_Volume(-1,game.core.config.Audio_Sound_Volume);
                game.options_menu.set_button_slider_position(1,game.core.config.Audio_Sound_Volume);
            break;
            case 4002://left arrow on button 2
                game.core.config.Audio_Music_Volume--;
                if (game.core.config.Audio_Music_Volume < 0) game.core.config.Audio_Music_Volume = 0;
                Mix_VolumeMusic(game.core.config.Audio_Music_Volume);
                game.options_menu.set_button_slider_position(2,game.core.config.Audio_Music_Volume);
            break;
            case 5002://right arrow on button 2
                game.core.config.Audio_Music_Volume++;
                if (game.core.config.Audio_Music_Volume > 128) game.core.config.Audio_Music_Volume = 128;
                Mix_VolumeMusic(game.core.config.Audio_Music_Volume);
                game.options_menu.set_button_slider_position(2,game.core.config.Audio_Music_Volume);
            break;
            case 4003://left arrow on button 3
                game.options_menu.set_button_choice_position(3,game.options_menu.get_button_choice_position(3)-1);
                if (game.options_menu.get_button_choice_position(3) < 1) game.options_menu.set_button_choice_position(3,1);
            break;
            case 5003://right arrow on button 3
                game.options_menu.set_button_choice_position(3,game.options_menu.get_button_choice_position(3)+1);
                if (game.options_menu.get_button_choice_position(3) >= game.options_menu.get_number_of_choices(3)-(game.options_menu.get_number_of_visible_choices(3)-1)) game.options_menu.set_button_choice_position(3,game.options_menu.get_number_of_choices(3)-(game.options_menu.get_number_of_visible_choices(3)-1));
            break;
            case 6://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from Options menu. - button selected.");
            break;
            case 65533://menu choice changed
                game.sound.menu_move_00.play();
            break;
            case 65534://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.io.key_escape           = false;
                game.core.log.File_Write("Entering main menu, from Options menu. - escape preses.");
            break;
            case 65535://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level = 1;
                game.core.log.File_Write("Entering main menu, from Options menu. - button clicked.");
            break;
            default:
            break;
        };
        if (set_resolution)
        {
            set_resolution = false;
            if (game.core.config.Display_resolution == 0)
            {
                game.core.config.Display_X_Resolution = 640;
                game.core.config.Display_Y_Resolution = 480;
            }
            if (game.core.config.Display_resolution == 1)
            {
                game.core.config.Display_X_Resolution = 800;
                game.core.config.Display_Y_Resolution = 600;
            }
            if (game.core.config.Display_resolution == 2)
            {
                game.core.config.Display_X_Resolution = 1024;
                game.core.config.Display_Y_Resolution = 768;
            }
            if (game.core.config.Display_resolution == 3)
            {
                game.core.config.Display_X_Resolution = 1280;
                game.core.config.Display_Y_Resolution = 1024;
            }
            if (game.core.config.Display_resolution == 4)
            {
                game.core.config.Display_X_Resolution = 1366;
                game.core.config.Display_Y_Resolution = 768;
            }
            if (game.core.config.Display_resolution == 5)
            {
                game.core.config.Display_X_Resolution = 1440;
                game.core.config.Display_Y_Resolution = 900;
            }
            if (game.core.config.Display_resolution == 6)
            {
                game.core.config.Display_X_Resolution = 1680;
                game.core.config.Display_Y_Resolution = 1050;
            }
            if (game.core.config.Display_resolution == 7)
            {
                game.core.config.Display_X_Resolution = 1920;
                game.core.config.Display_Y_Resolution = 1080;
            }
            game.core.config.mouse_resolution_x   = game.core.config.Display_X_Resolution;
            game.core.config.mouse_resolution_y   = game.core.config.Display_Y_Resolution;
            if (game.core.config.Display_Fullscreen) SDL_SetVideoMode(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution,game.core.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
            else                                SDL_SetVideoMode(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution,game.core.config.Display_BPS,SDL_OPENGL);
            game.core.graphics.init_gl(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution);
            load_textures();
        }
    };
    // ------------------- Game Over Menu ------------
    activated_button = -1;
    if (game.core.menu_level == 6)
    {
        activated_button = game.game_over_menu.process();
        switch (activated_button)
        {
            case 1://Button 1 selected.
                game.sound.menu_select_00.play();
                game.core.menu_level              = 1;
                game.core.menu_active             = true;
                game.core.pdie_active             = false;
                game.core.outr_active             = false;
                game.core.game_active             = false;
                game.core.nlvl_active             = false;
                game.core.io.key_escape           = false;
                game.core.music_next_track        = true;
                game.core.log.File_Write("Entering main menu, from game over menu. - button 1 selected.");
                game.main_menu.set_keyboard_delay_count(0);
                game.main_menu.set_mouse_delay_count(0);
                SDL_WarpMouse(game.core.graphics.gl_to_res(game.main_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.main_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
            break;
            case 65533://menu choice changed
                game.sound.menu_move_00.play();
            break;
            case 65534://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level              = 1;
                game.core.menu_active             = true;
                game.core.pdie_active             = false;
                game.core.outr_active             = false;
                game.core.game_active             = false;
                game.core.nlvl_active             = false;
                game.core.io.key_escape           = false;
                game.core.music_next_track        = true;
                game.core.log.File_Write("Entering main menu, from game over menu. - button 1 selected.");
                game.main_menu.set_keyboard_delay_count(0);
                game.main_menu.set_mouse_delay_count(0);
                SDL_WarpMouse(game.core.graphics.gl_to_res(game.main_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.main_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
            break;
            case 65535://Return to main menu
                game.sound.menu_select_00.play();
                game.core.menu_level              = 1;
                game.core.menu_active             = true;
                game.core.pdie_active             = false;
                game.core.outr_active             = false;
                game.core.game_active             = false;
                game.core.nlvl_active             = false;
                game.core.io.key_escape           = false;
                game.core.music_next_track        = true;
                game.core.log.File_Write("Entering main menu, from game over menu. - button 1 selected.");
                game.main_menu.set_keyboard_delay_count(0);
                game.main_menu.set_mouse_delay_count(0);
                SDL_WarpMouse(game.core.graphics.gl_to_res(game.main_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.main_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
            break;
            default:
            break;
        };
    };
    // ------------------- Pause Menu ------------
    activated_button = -1;
    if (game.core.menu_level == 7)
    {
        activated_button = game.pause_menu.process();
        switch (activated_button)
        {
            case 1://Button 1 selected.
                game.sound.menu_select_00.play();
                game.core.game_paused      = false;
                game.core.game_active      = true;
                game.core.io.key_escape    = false;
                game.core.io.select        = false;
                game.core.io.pause         = false;
                SDL_WarpMouse(game.core.graphics.gl_to_res(game.main_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.main_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
                game.core.io.key_space  = false;
                game.core.io.key_enter  = false;
                game.core.io.select     = false;
                game.main_menu.set_keyboard_delay(128);
                game.main_menu.set_keyboard_delay_count(0);
                game.main_menu.set_mouse_delay_count(0);
                game.core.log.File_Write("Entering game menu, from pause menu. - button 1 selected.");
            break;
            case 65533://menu choice changed
                game.sound.menu_move_00.play();
            break;
            case 65534://Return to game
                game.sound.menu_select_00.play();
                game.core.game_paused      = false;
                game.core.game_active      = true;
                game.core.io.key_escape    = false;
                game.core.io.select        = false;
                game.core.io.pause         = false;
                SDL_WarpMouse(game.core.graphics.gl_to_res(game.main_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.main_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
                game.core.io.key_space  = false;
                game.core.io.key_enter  = false;
                game.core.io.select     = false;
                game.main_menu.set_keyboard_delay(128);
                game.main_menu.set_keyboard_delay_count(0);
                game.main_menu.set_mouse_delay_count(0);
                game.core.log.File_Write("Entering game menu, from pause menu. - button 1 selected.");
            break;
            case 65535://Return to game
                game.sound.menu_select_00.play();
                game.core.game_paused      = false;
                game.core.game_active      = true;
                game.core.io.key_escape    = false;
                game.core.io.select        = false;
                game.core.io.pause         = false;
                SDL_WarpMouse(game.core.graphics.gl_to_res(game.main_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.main_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
                game.core.io.key_space  = false;
                game.core.io.key_enter  = false;
                game.core.io.select     = false;
                game.main_menu.set_keyboard_delay(128);
                game.main_menu.set_keyboard_delay_count(0);
                game.main_menu.set_mouse_delay_count(0);
                game.core.log.File_Write("Entering game menu, from pause menu. - button 1 selected.");
            break;
            default:
            break;
        };
    };
    //-------------------------------------------------------------------------------------------------------------------
   return(0);
*/
};

//---------------------------------------------------------------------------------------------------------------
void diplay_menu (void)
{
/*
    glPushMatrix();
    glDisable(GL_DEPTH_TEST);
    if (game.state != STATE_GAME)
    {
        if (game.core.menu_level !=  7)
        {
            game.core.background.draw();
        }
        game.resource.texture.logo.draw(true,0.0f,0.9f,0.001f,1.6f,0.2f);
        game.font.font_1.Write(255,255,255,64,-0.98f,-0.98f,2,16,"www.PhysHexGames.co.nr");
        //-----------------------------------------------------------------------------//
        if (game.core.menu_level ==  7) //Pause screen
        {
            ;
        }
    }
//-----------------------------------------------------------------------------//
   if (game.core.menu_level ==  1) game.main_menu.draw();//main_menu
   if (game.core.menu_level ==  2) game.new_game_menu.draw();//new_game_menu
   if (game.core.menu_level ==  3) game.load_menu.draw();//load_menu
   if (game.core.menu_level ==  4) game.save_menu.draw();//save_menu
   if (game.core.menu_level ==  5) game.options_menu.draw();//options_menu
   if (game.core.menu_level ==  6) game.game_over_menu.draw();//game_over_menu
   if (game.core.menu_level ==  7) game.pause_menu.draw(); //pause_menu
//-----------------------------------------------------------------------------//
   glPopMatrix();
   return(0);
*/
};
