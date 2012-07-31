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

    menu_system_class::menu_new_game.choice_selection[0].selected         = 0; // Player portrait selection
    menu_system_class::menu_new_game.choice_selection[0].position         = 0;
    menu_system_class::menu_new_game.choice_selection[0].position_max     = 12;
    menu_system_class::menu_new_game.choice_selection[0].data[0].active   = true;
    menu_system_class::menu_new_game.choice_selection[0].data[0].value    = game.resource.texture.portrait_00.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[1].value    = game.resource.texture.portrait_01.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[2].value    = game.resource.texture.portrait_02.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[3].value    = game.resource.texture.portrait_03.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[4].value    = game.resource.texture.portrait_04.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[5].value    = game.resource.texture.portrait_05.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[6].value    = game.resource.texture.portrait_06.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[7].value    = game.resource.texture.portrait_07.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[8].value    = game.resource.texture.portrait_08.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[9].value    = game.resource.texture.portrait_09.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[10].value   = game.resource.texture.portrait_10.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[11].value   = game.resource.texture.portrait_11.ref_number;
    menu_system_class::menu_new_game.choice_selection[0].data[12].value   = game.resource.texture.portrait_12.ref_number;
    game.player.portrait_image_ref = menu_system_class::menu_new_game.choice_selection[0].data[0].value;
    game.player.portrait_number    = menu_system_class::menu_new_game.choice_selection[0].position;

    menu_system_class::menu_new_game.element[0].title.text                = ""; // Close button
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
    menu_system_class::menu_new_game.element[2].mouse_delay               = 5;
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
    menu_system_class::menu_new_game.element[3].mouse_delay               = 5;
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
    menu_system_class::menu_new_game.element[4].selected                  = true;
    menu_system_class::menu_new_game.element[4].active                    = true;
    menu_system_class::menu_new_game.element[4].type                      = IMAGE;
    menu_system_class::menu_new_game.element[4].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[4].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[4].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[4].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[4].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[4].size_x*2.5f);
    menu_system_class::menu_new_game.element[4].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[4].size_y*2.00f);
    menu_system_class::menu_new_game.element[4].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[0].value;
    menu_system_class::menu_new_game.element[4].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;

    menu_system_class::menu_new_game.element[5].title.text                = "";
    menu_system_class::menu_new_game.element[5].active                    = true;
    menu_system_class::menu_new_game.element[5].type                      = IMAGE;
    menu_system_class::menu_new_game.element[5].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[5].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[5].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[5].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[5].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[5].size_x*3.75f);
    menu_system_class::menu_new_game.element[5].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[5].size_y*2.00f);
    menu_system_class::menu_new_game.element[5].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[1].value;
    menu_system_class::menu_new_game.element[5].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;

    menu_system_class::menu_new_game.element[6].title.text                = "";
    menu_system_class::menu_new_game.element[6].active                    = true;
    menu_system_class::menu_new_game.element[6].type                      = IMAGE;
    menu_system_class::menu_new_game.element[6].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[6].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[6].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[6].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[6].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[6].size_x*5.0f);
    menu_system_class::menu_new_game.element[6].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[6].size_y*2.00f);
    menu_system_class::menu_new_game.element[6].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[2].value;
    menu_system_class::menu_new_game.element[6].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;

    menu_system_class::menu_new_game.element[7].title.text                = "";
    menu_system_class::menu_new_game.element[7].active                    = true;
    menu_system_class::menu_new_game.element[7].type                      = IMAGE;
    menu_system_class::menu_new_game.element[7].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[7].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[7].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[7].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[7].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[7].size_x*6.25f);
    menu_system_class::menu_new_game.element[7].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[7].size_y*2.00f);
    menu_system_class::menu_new_game.element[7].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[3].value;
    menu_system_class::menu_new_game.element[7].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;

    menu_system_class::menu_new_game.element[8].title.text                = "";
    menu_system_class::menu_new_game.element[8].active                    = true;
    menu_system_class::menu_new_game.element[8].type                      = IMAGE;
    menu_system_class::menu_new_game.element[8].color                     = menu_system_class::menu_new_game.color;
    menu_system_class::menu_new_game.element[8].zoom                      = menu_system_class::menu_new_game.zoom;
    menu_system_class::menu_new_game.element[8].size_x                    = (menu_system_class::menu_new_game.size_x / 100.f)*10.0f;
    menu_system_class::menu_new_game.element[8].size_y                    = menu_system_class::menu_new_game.size_y / 10.0f;
    menu_system_class::menu_new_game.element[8].position_x                = menu_system_class::menu_new_game.position_x-(menu_system_class::menu_new_game.size_x/2.0f)+(menu_system_class::menu_new_game.element[8].size_x*7.5f);
    menu_system_class::menu_new_game.element[8].position_y                = menu_system_class::menu_new_game.position_y+(menu_system_class::menu_new_game.size_y/2.0f)-(menu_system_class::menu_new_game.element[8].size_y*2.00f);
    menu_system_class::menu_new_game.element[8].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[4].value;
    menu_system_class::menu_new_game.element[8].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;

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

    menu_system_class::menu_options.choice_selection[0].selected                = 0; // Resolution selection
    menu_system_class::menu_options.choice_selection[0].position                = 0;
    menu_system_class::menu_options.choice_selection[0].position_max            = 7;
    menu_system_class::menu_options.choice_selection[0].data[0].active          = true;
    menu_system_class::menu_options.choice_selection[0].data[0].value           = 0;
    menu_system_class::menu_options.choice_selection[0].data[0].value_string    = " 640 X 480 ";
    menu_system_class::menu_options.choice_selection[0].data[1].value           = 1;
    menu_system_class::menu_options.choice_selection[0].data[1].value_string    = " 800 X 600 ";
    menu_system_class::menu_options.choice_selection[0].data[2].value           = 2;
    menu_system_class::menu_options.choice_selection[0].data[2].value_string    = "1028 X 768 ";
    menu_system_class::menu_options.choice_selection[0].data[3].value           = 3;
    menu_system_class::menu_options.choice_selection[0].data[3].value_string    = "1280 X 1024";
    menu_system_class::menu_options.choice_selection[0].data[4].value           = 4;
    menu_system_class::menu_options.choice_selection[0].data[4].value_string    = "1366 X 768 ";
    menu_system_class::menu_options.choice_selection[0].data[5].value           = 5;
    menu_system_class::menu_options.choice_selection[0].data[5].value_string    = "1440 X 900 ";
    menu_system_class::menu_options.choice_selection[0].data[6].value           = 6;
    menu_system_class::menu_options.choice_selection[0].data[6].value_string    = "1680 X 1050";
    menu_system_class::menu_options.choice_selection[0].data[7].value           = 7;
    menu_system_class::menu_options.choice_selection[0].data[7].value_string    = "1920 X 1080";

    menu_system_class::menu_options.element[9].title.text                = menu_system_class::menu_options.choice_selection[0].data[0].value_string;
    menu_system_class::menu_options.element[9].selected                  = true;
    menu_system_class::menu_options.element[9].active                    = true;
    menu_system_class::menu_options.element[9].type                      = IMAGE;
    menu_system_class::menu_options.element[9].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[9].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[9].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[9].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[9].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[9].size_x*2.5f);
    menu_system_class::menu_options.element[9].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[9].size_y*4.5f);
    menu_system_class::menu_options.element[9].texture_ID.base           = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[9].texture_ID.normal         = game.resource.texture.resolution_icon.ref_number;
    menu_system_class::menu_options.element[9].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[9].texture_ID.disabled       = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[9].title.size_x              = menu_system_class::menu_options.element[9].title.text.length()/2.4f;;
    menu_system_class::menu_options.element[9].title.size_y              = menu_system_class::menu_options.element[9].title.size_x*4.0f;
    menu_system_class::menu_options.element[9].title.position_x          = menu_system_class::menu_options.position_x - (menu_system_class::menu_options.element[9].title.size_x/42.0f);
    menu_system_class::menu_options.element[9].title.position_y          = menu_system_class::menu_options.element[9].position_y - (menu_system_class::menu_options.element[9].title.size_y/120.0f);

    menu_system_class::menu_options.element[10].title.text                = menu_system_class::menu_options.choice_selection[0].data[1].value_string;
    menu_system_class::menu_options.element[10].active                    = true;
    menu_system_class::menu_options.element[10].type                      = IMAGE;
    menu_system_class::menu_options.element[10].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[10].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[10].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[10].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[10].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[10].size_x*3.75f);
    menu_system_class::menu_options.element[10].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[10].size_y*4.5f);
    menu_system_class::menu_options.element[10].texture_ID.base           = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[10].texture_ID.normal         = game.resource.texture.resolution_icon.ref_number;
    menu_system_class::menu_options.element[10].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[10].texture_ID.disabled       = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[10].title.size_x              = menu_system_class::menu_options.element[10].title.text.length()/2.4f;;
    menu_system_class::menu_options.element[10].title.size_y              = menu_system_class::menu_options.element[10].title.size_x*4.0f;
    menu_system_class::menu_options.element[10].title.position_x          = menu_system_class::menu_options.position_x - (menu_system_class::menu_options.element[10].title.size_x/42.0f);
    menu_system_class::menu_options.element[10].title.position_y          = menu_system_class::menu_options.element[10].position_y - (menu_system_class::menu_options.element[10].title.size_y/120.0f);

    menu_system_class::menu_options.element[11].title.text                = menu_system_class::menu_options.choice_selection[0].data[2].value_string;
    menu_system_class::menu_options.element[11].active                    = true;
    menu_system_class::menu_options.element[11].type                      = IMAGE;
    menu_system_class::menu_options.element[11].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[11].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[11].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[11].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[11].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[11].size_x*5.0f);
    menu_system_class::menu_options.element[11].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[11].size_y*4.5f);
    menu_system_class::menu_options.element[11].texture_ID.base           = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[11].texture_ID.normal         = game.resource.texture.resolution_icon.ref_number;
    menu_system_class::menu_options.element[11].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[11].texture_ID.disabled       = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[11].title.size_x              = menu_system_class::menu_options.element[11].title.text.length()/2.4f;;
    menu_system_class::menu_options.element[11].title.size_y              = menu_system_class::menu_options.element[11].title.size_x*4.0f;
    menu_system_class::menu_options.element[11].title.position_x          = menu_system_class::menu_options.position_x - (menu_system_class::menu_options.element[11].title.size_x/42.0f);
    menu_system_class::menu_options.element[11].title.position_y          = menu_system_class::menu_options.element[11].position_y - (menu_system_class::menu_options.element[11].title.size_y/120.0f);

    menu_system_class::menu_options.element[12].title.text                = menu_system_class::menu_options.choice_selection[0].data[3].value_string;
    menu_system_class::menu_options.element[12].active                    = true;
    menu_system_class::menu_options.element[12].type                      = IMAGE;
    menu_system_class::menu_options.element[12].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[12].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[12].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[12].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[12].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[12].size_x*6.25f);
    menu_system_class::menu_options.element[12].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[12].size_y*4.5f);
    menu_system_class::menu_options.element[12].texture_ID.base           = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[12].texture_ID.normal         = game.resource.texture.resolution_icon.ref_number;
    menu_system_class::menu_options.element[12].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[12].texture_ID.disabled       = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[12].title.size_x              = menu_system_class::menu_options.element[12].title.text.length()/2.4f;;
    menu_system_class::menu_options.element[12].title.size_y              = menu_system_class::menu_options.element[12].title.size_x*4.0f;
    menu_system_class::menu_options.element[12].title.position_x          = menu_system_class::menu_options.position_x - (menu_system_class::menu_options.element[12].title.size_x/42.0f);
    menu_system_class::menu_options.element[12].title.position_y          = menu_system_class::menu_options.element[12].position_y - (menu_system_class::menu_options.element[12].title.size_y/120.0f);

    menu_system_class::menu_options.element[13].title.text                = menu_system_class::menu_options.choice_selection[0].data[4].value_string;
    menu_system_class::menu_options.element[13].active                    = true;
    menu_system_class::menu_options.element[13].type                      = IMAGE;
    menu_system_class::menu_options.element[13].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[13].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[13].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[13].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[13].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[13].size_x*7.5f);
    menu_system_class::menu_options.element[13].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[13].size_y*4.5f);
    menu_system_class::menu_options.element[13].texture_ID.base           = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[13].texture_ID.normal         = game.resource.texture.resolution_icon.ref_number;
    menu_system_class::menu_options.element[13].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[13].texture_ID.disabled       = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[13].title.size_x              = menu_system_class::menu_options.element[13].title.text.length()/2.4f;;
    menu_system_class::menu_options.element[13].title.size_y              = menu_system_class::menu_options.element[13].title.size_x*4.0f;
    menu_system_class::menu_options.element[13].title.position_x          = menu_system_class::menu_options.position_x - (menu_system_class::menu_options.element[13].title.size_x/42.0f);
    menu_system_class::menu_options.element[13].title.position_y          = menu_system_class::menu_options.element[13].position_y - (menu_system_class::menu_options.element[13].title.size_y/120.0f);

    menu_system_class::menu_options.element[14].title.text                = "Fullscreen";
    menu_system_class::menu_options.element[14].active                    = true;
    menu_system_class::menu_options.element[14].type                      = BUTTON;
    menu_system_class::menu_options.element[14].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[14].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[14].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*48.0f;
    menu_system_class::menu_options.element[14].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[14].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.element[14].size_x/8.0f);
    menu_system_class::menu_options.element[14].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[14].size_y*7.0f);
    menu_system_class::menu_options.element[14].texture_ID                = menu_system_class::menu_options.texture_ID;
    menu_system_class::menu_options.element[14].title.size_x              = menu_system_class::menu_options.element[14].title.text.length()/1.2f;
    menu_system_class::menu_options.element[14].title.size_y              = menu_system_class::menu_options.element[14].title.size_x*4;;
    menu_system_class::menu_options.element[14].title.position_x          = menu_system_class::menu_options.element[14].position_x-(menu_system_class::menu_options.element[14].title.size_x/100.0f);
    menu_system_class::menu_options.element[14].title.position_y          = menu_system_class::menu_options.element[14].position_y-(menu_system_class::menu_options.element[14].title.size_y/1480.0f);

    menu_system_class::menu_options.element[16].title.text                = "";
    menu_system_class::menu_options.element[16].active                    = true;
    menu_system_class::menu_options.element[16].type                      = BUTTON;
    menu_system_class::menu_options.element[16].zoom.enabled              = false;
    menu_system_class::menu_options.element[16].value                     = 1.0f;
    menu_system_class::menu_options.element[16].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[16].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*10.0f;
    menu_system_class::menu_options.element[16].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[16].position_x                = menu_system_class::menu_options.position_x-(menu_system_class::menu_options.size_x/2.0f)+(menu_system_class::menu_options.element[16].size_x*7.5f);
    menu_system_class::menu_options.element[16].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[16].size_y*7.0f);
    menu_system_class::menu_options.element[16].texture_ID                = menu_system_class::menu_options.texture_ID;
    menu_system_class::menu_options.element[16].texture_ID.normal         = game.resource.texture.green_button.ref_number;
    menu_system_class::menu_options.element[16].texture_ID.highlighted    = game.resource.texture.green_button_highlighted.ref_number;
    menu_system_class::menu_options.element[16].texture_ID.disabled       = game.resource.texture.red_button.ref_number;
    menu_system_class::menu_options.element[16].texture_ID.base           = game.resource.texture.red_button_highlighted.ref_number;
    if (game.core.config.display_fullscreen)
    {
        menu_system_class::menu_options.element[16].value                     = 1.0f;
        menu_system_class::menu_options.element[16].texture_ID.normal         = game.resource.texture.green_button.ref_number;
        menu_system_class::menu_options.element[16].texture_ID.highlighted    = game.resource.texture.green_button_highlighted.ref_number;
        menu_system_class::menu_options.element[16].texture_ID.disabled       = game.resource.texture.red_button.ref_number;
        menu_system_class::menu_options.element[16].texture_ID.base           = game.resource.texture.red_button_highlighted.ref_number;
    }
    else
    {
        menu_system_class::menu_options.element[16].value                     = 0.0f;
        menu_system_class::menu_options.element[16].texture_ID.normal         = game.resource.texture.red_button.ref_number;
        menu_system_class::menu_options.element[16].texture_ID.highlighted    = game.resource.texture.red_button_highlighted.ref_number;
        menu_system_class::menu_options.element[16].texture_ID.disabled       = game.resource.texture.green_button.ref_number;
        menu_system_class::menu_options.element[16].texture_ID.base           = game.resource.texture.green_button_highlighted.ref_number;
    }

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

    menu_system_class::menu_options.element[7].title.text                = ""; // Left arrow resolution selection
    menu_system_class::menu_options.element[7].mouse_delay               = 5;
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

    menu_system_class::menu_options.element[8].title.text                = ""; // Right arrow resolution selection
    menu_system_class::menu_options.element[8].mouse_delay               = 5;
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

    menu_system_class::menu_options.element[0].title.text                = ""; // resolution display image
    menu_system_class::menu_options.element[0].active                    = true;
    menu_system_class::menu_options.element[0].state                     = DISABLED;
    menu_system_class::menu_options.element[0].type                      = IMAGE;
    menu_system_class::menu_options.element[0].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[0].zoom                      = menu_system_class::menu_options.zoom;
    menu_system_class::menu_options.element[0].zoom.enabled              = false;
    menu_system_class::menu_options.element[0].size_x                    = (menu_system_class::menu_options.size_x / 100.f)*60.0f;
    menu_system_class::menu_options.element[0].size_y                    = menu_system_class::menu_options.size_y / 10.0f;
    menu_system_class::menu_options.element[0].position_x                = menu_system_class::menu_options.position_x;
    menu_system_class::menu_options.element[0].position_y                = menu_system_class::menu_options.position_y+(menu_system_class::menu_options.size_y/2.0f)-(menu_system_class::menu_options.element[0].size_y*5.75f);
    menu_system_class::menu_options.element[0].texture_ID                = menu_system_class::menu_options.texture_ID;
    menu_system_class::menu_options.element[0].texture_ID.normal         = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[0].texture_ID.highlighted    = game.resource.texture.selection_box.ref_number;
    menu_system_class::menu_options.element[0].texture_ID.disabled       = game.resource.texture.selection_box.ref_number;

    menu_system_class::menu_options.element[17].title.text                = ""; // Close button
    menu_system_class::menu_options.element[17].active                    = true;
    menu_system_class::menu_options.element[17].type                      = BUTTON;
    menu_system_class::menu_options.element[17].zoom.enabled              = false;
    menu_system_class::menu_options.element[17].color                     = menu_system_class::menu_options.color;
    menu_system_class::menu_options.element[17].size_x                    = 0.1f;
    menu_system_class::menu_options.element[17].size_y                    = 0.1f;
    menu_system_class::menu_options.element[17].position_x                = menu_system_class::menu_options.position_x+(menu_system_class::menu_options.size_x/2.0f)-(menu_system_class::menu_options.element[17].size_x/1.8f);
    menu_system_class::menu_options.element[17].position_y                = menu_system_class::menu_options.title.position_y+(menu_system_class::menu_options.element[17].size_y/8.0f);
    menu_system_class::menu_options.element[17].texture_ID.normal         = game.resource.texture.close_button.ref_number;
    menu_system_class::menu_options.element[17].texture_ID.highlighted    = game.resource.texture.close_button_highlighted.ref_number;

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
    int         temp_resolution      = 0;
    int         temp_resolution_x    = 0;
    int         temp_resolution_y    = 0;
    int         old_event_state      = 0;
    int         old_mouse_over_state = 0;
    int         return_value         = 0;
    int         temp_data_value      = 0;
    bool        temp_data_bool       = false;
    std::string temp_data_string     = "Temp????";
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
                case 3: // left arrow button for player portrait selection
                    menu_system_class::menu_new_game.choice_selection[0].position++;
                    if (menu_system_class::menu_new_game.choice_selection[0].position > menu_system_class::menu_new_game.choice_selection[0].position_max) menu_system_class::menu_new_game.choice_selection[0].position = 0;
                    temp_data_value = menu_system_class::menu_new_game.choice_selection[0].data[0].value;
                    temp_data_bool  = menu_system_class::menu_new_game.choice_selection[0].data[0].active;
                    for (int data_position_count = 0; data_position_count < menu_system_class::menu_new_game.choice_selection[0].position_max;data_position_count++)
                    {
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].value  = menu_system_class::menu_new_game.choice_selection[0].data[data_position_count+1].value;
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].active = menu_system_class::menu_new_game.choice_selection[0].data[data_position_count+1].active;
                    }
                    menu_system_class::menu_new_game.choice_selection[0].data[menu_system_class::menu_new_game.choice_selection[0].position_max].value  = temp_data_value;
                    menu_system_class::menu_new_game.choice_selection[0].data[menu_system_class::menu_new_game.choice_selection[0].position_max].active = temp_data_bool;
                    menu_system_class::menu_new_game.element[4].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[0].value;
                    menu_system_class::menu_new_game.element[5].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[1].value;
                    menu_system_class::menu_new_game.element[6].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[2].value;
                    menu_system_class::menu_new_game.element[7].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[3].value;
                    menu_system_class::menu_new_game.element[8].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[4].value;
                    menu_system_class::menu_new_game.element[4].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[0].active;
                    menu_system_class::menu_new_game.element[5].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[1].active;
                    menu_system_class::menu_new_game.element[6].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[2].active;
                    menu_system_class::menu_new_game.element[7].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[3].active;
                    menu_system_class::menu_new_game.element[8].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[4].active;
                break;
                case 4: // Right arrow button for player portrait selection
                    menu_system_class::menu_new_game.choice_selection[0].position--;
                    if (menu_system_class::menu_new_game.choice_selection[0].position < 0) menu_system_class::menu_new_game.choice_selection[0].position = menu_system_class::menu_new_game.choice_selection[0].position_max;
                    temp_data_value = menu_system_class::menu_new_game.choice_selection[0].data[menu_system_class::menu_new_game.choice_selection[0].position_max-1].value;
                    temp_data_bool  = menu_system_class::menu_new_game.choice_selection[0].data[menu_system_class::menu_new_game.choice_selection[0].position_max-1].active;
                    for (int data_position_count = menu_system_class::menu_new_game.choice_selection[0].position_max-1; data_position_count > 0;data_position_count--)
                    {
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].value  = menu_system_class::menu_new_game.choice_selection[0].data[data_position_count-1].value;
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].active = menu_system_class::menu_new_game.choice_selection[0].data[data_position_count-1].active;
                    }
                    menu_system_class::menu_new_game.choice_selection[0].data[0].value    = temp_data_value;
                    menu_system_class::menu_new_game.choice_selection[0].data[0].active   = temp_data_bool;
                    menu_system_class::menu_new_game.element[4].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[0].value;
                    menu_system_class::menu_new_game.element[5].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[1].value;
                    menu_system_class::menu_new_game.element[6].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[2].value;
                    menu_system_class::menu_new_game.element[7].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[3].value;
                    menu_system_class::menu_new_game.element[8].texture_ID.normal         = menu_system_class::menu_new_game.choice_selection[0].data[4].value;
                    menu_system_class::menu_new_game.element[4].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[0].active;
                    menu_system_class::menu_new_game.element[5].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[1].active;
                    menu_system_class::menu_new_game.element[6].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[2].active;
                    menu_system_class::menu_new_game.element[7].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[3].active;
                    menu_system_class::menu_new_game.element[8].selected                  = menu_system_class::menu_new_game.choice_selection[0].data[4].active;
                break;
                case 5: // Portrait 0 selected
                    for (int data_position_count = 0; data_position_count < menu_system_class::menu_new_game.choice_selection[0].position_max;data_position_count++)
                    {
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].active = false;
                    }
                    menu_system_class::menu_new_game.element[4].selected                  = true;
                    menu_system_class::menu_new_game.element[5].selected                  = false;
                    menu_system_class::menu_new_game.element[6].selected                  = false;
                    menu_system_class::menu_new_game.element[7].selected                  = false;
                    menu_system_class::menu_new_game.element[8].selected                  = false;
                    menu_system_class::menu_new_game.choice_selection[0].data[0].active   = true;
                    game.player.portrait_image_ref = menu_system_class::menu_new_game.choice_selection[0].data[0].value;
                    game.player.portrait_number    = menu_system_class::menu_new_game.choice_selection[0].position;
                break;
                case 6: // Portrait 1 selected
                    for (int data_position_count = 0; data_position_count < menu_system_class::menu_new_game.choice_selection[0].position_max;data_position_count++)
                    {
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].active = false;
                    }
                    menu_system_class::menu_new_game.element[4].selected                  = false;
                    menu_system_class::menu_new_game.element[5].selected                  = true;
                    menu_system_class::menu_new_game.element[6].selected                  = false;
                    menu_system_class::menu_new_game.element[7].selected                  = false;
                    menu_system_class::menu_new_game.element[8].selected                  = false;
                    menu_system_class::menu_new_game.choice_selection[0].data[1].active   = true;
                    game.player.portrait_image_ref = menu_system_class::menu_new_game.choice_selection[0].data[1].value;
                    game.player.portrait_number    = menu_system_class::menu_new_game.choice_selection[0].position;
                break;
                case 7: // Portrait 2 selected
                    for (int data_position_count = 0; data_position_count < menu_system_class::menu_new_game.choice_selection[0].position_max;data_position_count++)
                    {
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].active = false;
                    }
                    menu_system_class::menu_new_game.element[4].selected                  = false;
                    menu_system_class::menu_new_game.element[5].selected                  = false;
                    menu_system_class::menu_new_game.element[6].selected                  = true;
                    menu_system_class::menu_new_game.element[7].selected                  = false;
                    menu_system_class::menu_new_game.element[8].selected                  = false;
                    menu_system_class::menu_new_game.choice_selection[0].data[2].active   = true;
                    game.player.portrait_image_ref = menu_system_class::menu_new_game.choice_selection[0].data[2].value;
                    game.player.portrait_number    = menu_system_class::menu_new_game.choice_selection[0].position;
                break;
                case 8: // Portrait 3 selected
                    for (int data_position_count = 0; data_position_count < menu_system_class::menu_new_game.choice_selection[0].position_max;data_position_count++)
                    {
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].active = false;
                    }
                    menu_system_class::menu_new_game.element[4].selected                  = false;
                    menu_system_class::menu_new_game.element[5].selected                  = false;
                    menu_system_class::menu_new_game.element[6].selected                  = false;
                    menu_system_class::menu_new_game.element[7].selected                  = true;
                    menu_system_class::menu_new_game.element[8].selected                  = false;
                    menu_system_class::menu_new_game.choice_selection[0].data[3].active   = true;
                    game.player.portrait_image_ref = menu_system_class::menu_new_game.choice_selection[0].data[3].value;
                    game.player.portrait_number    = menu_system_class::menu_new_game.choice_selection[0].position;
                break;
                case 9: // Portrait 4 selected
                    for (int data_position_count = 0; data_position_count < menu_system_class::menu_new_game.choice_selection[0].position_max;data_position_count++)
                    {
                        menu_system_class::menu_new_game.choice_selection[0].data[data_position_count].active = false;
                    }
                    menu_system_class::menu_new_game.element[4].selected                  = false;
                    menu_system_class::menu_new_game.element[5].selected                  = false;
                    menu_system_class::menu_new_game.element[6].selected                  = false;
                    menu_system_class::menu_new_game.element[7].selected                  = false;
                    menu_system_class::menu_new_game.element[8].selected                  = true;
                    menu_system_class::menu_new_game.choice_selection[0].data[4].active   = true;
                    game.player.portrait_image_ref = menu_system_class::menu_new_game.choice_selection[0].data[4].value;
                    game.player.portrait_number    = menu_system_class::menu_new_game.choice_selection[0].position;
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
            if (game.core.config.display_fullscreen)
            {
                menu_system_class::menu_options.element[16].value                     = 1.0f;
                menu_system_class::menu_options.element[16].texture_ID.normal         = game.resource.texture.green_button.ref_number;
                menu_system_class::menu_options.element[16].texture_ID.highlighted    = game.resource.texture.green_button_highlighted.ref_number;
                menu_system_class::menu_options.element[16].texture_ID.disabled       = game.resource.texture.red_button.ref_number;
                menu_system_class::menu_options.element[16].texture_ID.base           = game.resource.texture.red_button_highlighted.ref_number;
            }
            else
            {
                menu_system_class::menu_options.element[16].value                     = 0.0f;
                menu_system_class::menu_options.element[16].texture_ID.normal         = game.resource.texture.red_button.ref_number;
                menu_system_class::menu_options.element[16].texture_ID.highlighted    = game.resource.texture.red_button_highlighted.ref_number;
                menu_system_class::menu_options.element[16].texture_ID.disabled       = game.resource.texture.green_button.ref_number;
                menu_system_class::menu_options.element[16].texture_ID.base           = game.resource.texture.green_button_highlighted.ref_number;
            }
            old_event_state          = menu_system_class::menu_options.event;
            old_mouse_over_state     = menu_system_class::menu_options.mouse_over;
            return_value             = menu_system_class::menu_options.process();
            if (old_event_state      < menu_system_class::menu_options.event)      game.resource.sound.menu_select_00.play();
            if (old_mouse_over_state < menu_system_class::menu_options.mouse_over) game.resource.sound.menu_move_00.play();
            if (return_value != 0) menu_system_class::menu_options.mouse_delay.reset();
            switch (return_value)
            {
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
/*---------------------------------------------------------------------------------------------------------*/
                case 8: // left arrow button for resolution selection
                    menu_system_class::menu_options.choice_selection[0].position++;
                    if (menu_system_class::menu_options.choice_selection[0].position > menu_system_class::menu_options.choice_selection[0].position_max) menu_system_class::menu_options.choice_selection[0].position = 0;
                    temp_data_value   = menu_system_class::menu_options.choice_selection[0].data[0].value;
                    temp_data_bool    = menu_system_class::menu_options.choice_selection[0].data[0].active;
                    temp_data_string  = menu_system_class::menu_options.choice_selection[0].data[0].value_string;
                    for (int data_position_count = 0; data_position_count < menu_system_class::menu_options.choice_selection[0].position_max;data_position_count++)
                    {
                        menu_system_class::menu_options.choice_selection[0].data[data_position_count].value        = menu_system_class::menu_options.choice_selection[0].data[data_position_count+1].value;
                        menu_system_class::menu_options.choice_selection[0].data[data_position_count].active       = menu_system_class::menu_options.choice_selection[0].data[data_position_count+1].active;
                        menu_system_class::menu_options.choice_selection[0].data[data_position_count].value_string = menu_system_class::menu_options.choice_selection[0].data[data_position_count+1].value_string;
                    }
                    menu_system_class::menu_options.choice_selection[0].data[menu_system_class::menu_options.choice_selection[0].position_max].value        = temp_data_value;
                    menu_system_class::menu_options.choice_selection[0].data[menu_system_class::menu_options.choice_selection[0].position_max].active       = temp_data_bool;
                    menu_system_class::menu_options.choice_selection[0].data[menu_system_class::menu_options.choice_selection[0].position_max].value_string = temp_data_string;
                    menu_system_class::menu_options.element[ 9].selected                  = menu_system_class::menu_options.choice_selection[0].data[0].active;
                    menu_system_class::menu_options.element[10].selected                  = menu_system_class::menu_options.choice_selection[0].data[1].active;
                    menu_system_class::menu_options.element[11].selected                  = menu_system_class::menu_options.choice_selection[0].data[2].active;
                    menu_system_class::menu_options.element[12].selected                  = menu_system_class::menu_options.choice_selection[0].data[3].active;
                    menu_system_class::menu_options.element[13].selected                  = menu_system_class::menu_options.choice_selection[0].data[4].active;
                    menu_system_class::menu_options.element[ 9].title.text                = menu_system_class::menu_options.choice_selection[0].data[0].value_string;
                    menu_system_class::menu_options.element[10].title.text                = menu_system_class::menu_options.choice_selection[0].data[1].value_string;
                    menu_system_class::menu_options.element[11].title.text                = menu_system_class::menu_options.choice_selection[0].data[2].value_string;
                    menu_system_class::menu_options.element[12].title.text                = menu_system_class::menu_options.choice_selection[0].data[3].value_string;
                    menu_system_class::menu_options.element[13].title.text                = menu_system_class::menu_options.choice_selection[0].data[4].value_string;
                break;
                case 9: // Right arrow button for resolution selection
                    menu_system_class::menu_options.choice_selection[0].position--;
                    if (menu_system_class::menu_options.choice_selection[0].position < 0) menu_system_class::menu_options.choice_selection[0].position = menu_system_class::menu_options.choice_selection[0].position_max;
                    temp_data_value   = menu_system_class::menu_options.choice_selection[0].data[menu_system_class::menu_options.choice_selection[0].position_max-1].value;
                    temp_data_bool    = menu_system_class::menu_options.choice_selection[0].data[menu_system_class::menu_options.choice_selection[0].position_max-1].active;
                    temp_data_string  = menu_system_class::menu_options.choice_selection[0].data[menu_system_class::menu_options.choice_selection[0].position_max-1].value_string;
                    for (int data_position_count = menu_system_class::menu_options.choice_selection[0].position_max-1; data_position_count > 0;data_position_count--)
                    {
                        menu_system_class::menu_options.choice_selection[0].data[data_position_count].value        = menu_system_class::menu_options.choice_selection[0].data[data_position_count-1].value;
                        menu_system_class::menu_options.choice_selection[0].data[data_position_count].active       = menu_system_class::menu_options.choice_selection[0].data[data_position_count-1].active;
                        menu_system_class::menu_options.choice_selection[0].data[data_position_count].value_string = menu_system_class::menu_options.choice_selection[0].data[data_position_count-1].value_string;
                    }
                    menu_system_class::menu_options.choice_selection[0].data[0].value        = temp_data_value;
                    menu_system_class::menu_options.choice_selection[0].data[0].active       = temp_data_bool;
                    menu_system_class::menu_options.choice_selection[0].data[0].value_string = temp_data_string;
                    menu_system_class::menu_options.element[ 9].selected                  = menu_system_class::menu_options.choice_selection[0].data[0].active;
                    menu_system_class::menu_options.element[10].selected                  = menu_system_class::menu_options.choice_selection[0].data[1].active;
                    menu_system_class::menu_options.element[11].selected                  = menu_system_class::menu_options.choice_selection[0].data[2].active;
                    menu_system_class::menu_options.element[12].selected                  = menu_system_class::menu_options.choice_selection[0].data[3].active;
                    menu_system_class::menu_options.element[13].selected                  = menu_system_class::menu_options.choice_selection[0].data[4].active;
                    menu_system_class::menu_options.element[ 9].title.text                = menu_system_class::menu_options.choice_selection[0].data[0].value_string;
                    menu_system_class::menu_options.element[10].title.text                = menu_system_class::menu_options.choice_selection[0].data[1].value_string;
                    menu_system_class::menu_options.element[11].title.text                = menu_system_class::menu_options.choice_selection[0].data[2].value_string;
                    menu_system_class::menu_options.element[12].title.text                = menu_system_class::menu_options.choice_selection[0].data[3].value_string;
                    menu_system_class::menu_options.element[13].title.text                = menu_system_class::menu_options.choice_selection[0].data[4].value_string;
                break;
                case 10: // Resolution 0 selected
                    temp_data_value = 0;
                    if (menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value != game.core.config.display_resolution)
                    {
                        temp_resolution      = game.core.config.display_resolution;
                        temp_resolution_x    = game.core.config.display_resolution_x;
                        temp_resolution_y    = game.core.config.display_resolution_y;
                        game.core.config.display_resolution = menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value;
                        if (game.core.config.display_resolution == 0)
                        {
                            game.core.config.display_resolution_x = 640;
                            game.core.config.display_resolution_y = 480;
                        }
                        if (game.core.config.display_resolution == 1)
                        {
                            game.core.config.display_resolution_x = 800;
                            game.core.config.display_resolution_y = 600;
                        }
                        if (game.core.config.display_resolution == 2)
                        {
                            game.core.config.display_resolution_x = 1024;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 3)
                        {
                            game.core.config.display_resolution_x = 1280;
                            game.core.config.display_resolution_y = 1024;
                        }
                        if (game.core.config.display_resolution == 4)
                        {
                            game.core.config.display_resolution_x = 1366;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 5)
                        {
                            game.core.config.display_resolution_x = 1440;
                            game.core.config.display_resolution_y = 900;
                        }
                        if (game.core.config.display_resolution == 6)
                        {
                            game.core.config.display_resolution_x = 1680;
                            game.core.config.display_resolution_y = 1050;
                        }
                        if (game.core.config.display_resolution == 7)
                        {
                            game.core.config.display_resolution_x = 1920;
                            game.core.config.display_resolution_y = 1080;
                        }
                        if (!game.core.graphics.init_sdl())
                        {
                            game.core.log.file_write("Reverting graphics configuration...");
                            game.core.config.display_resolution    = temp_resolution;
                            game.core.config.display_resolution_x  = temp_resolution_x;
                            game.core.config.display_resolution_y  = temp_resolution_y;
                            game.core.graphics.init_sdl();
                        }
                        else
                        {
                            game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
                            game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
                            for (int data_position_count = 0; data_position_count < menu_system_class::menu_options.choice_selection[0].position_max;data_position_count++)
                            {
                                menu_system_class::menu_options.choice_selection[0].data[data_position_count].active = false;
                            }
                            menu_system_class::menu_options.element[ 9].selected                  = true;
                            menu_system_class::menu_options.element[10].selected                  = false;
                            menu_system_class::menu_options.element[11].selected                  = false;
                            menu_system_class::menu_options.element[12].selected                  = false;
                            menu_system_class::menu_options.element[13].selected                  = false;
                            menu_system_class::menu_options.choice_selection[0].data[temp_data_value].active    = true;
                        }
                        game.core.log.file_write("Initializing OpenGL...");
                        game.core.graphics.init_gl();
                        game.resource.loading_screen_display("data/loading_screen.png");
                        game.core.log.file_write("Loading resources....");
                        game.resource.load_all();
                    }
                break;
                case 11: // Resolution 1 selected
                    temp_data_value = 1;
                    if (menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value != game.core.config.display_resolution)
                    {
                        temp_resolution      = game.core.config.display_resolution;
                        temp_resolution_x    = game.core.config.display_resolution_x;
                        temp_resolution_y    = game.core.config.display_resolution_y;
                        game.core.config.display_resolution = menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value;
                        if (game.core.config.display_resolution == 0)
                        {
                            game.core.config.display_resolution_x = 640;
                            game.core.config.display_resolution_y = 480;
                        }
                        if (game.core.config.display_resolution == 1)
                        {
                            game.core.config.display_resolution_x = 800;
                            game.core.config.display_resolution_y = 600;
                        }
                        if (game.core.config.display_resolution == 2)
                        {
                            game.core.config.display_resolution_x = 1024;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 3)
                        {
                            game.core.config.display_resolution_x = 1280;
                            game.core.config.display_resolution_y = 1024;
                        }
                        if (game.core.config.display_resolution == 4)
                        {
                            game.core.config.display_resolution_x = 1366;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 5)
                        {
                            game.core.config.display_resolution_x = 1440;
                            game.core.config.display_resolution_y = 900;
                        }
                        if (game.core.config.display_resolution == 6)
                        {
                            game.core.config.display_resolution_x = 1680;
                            game.core.config.display_resolution_y = 1050;
                        }
                        if (game.core.config.display_resolution == 7)
                        {
                            game.core.config.display_resolution_x = 1920;
                            game.core.config.display_resolution_y = 1080;
                        }
                        if (!game.core.graphics.init_sdl())
                        {
                            game.core.log.file_write("Reverting graphics configuration...");
                            game.core.config.display_resolution    = temp_resolution;
                            game.core.config.display_resolution_x  = temp_resolution_x;
                            game.core.config.display_resolution_y  = temp_resolution_y;
                            game.core.graphics.init_sdl();
                        }
                        else
                        {
                            game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
                            game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
                            for (int data_position_count = 0; data_position_count < menu_system_class::menu_options.choice_selection[0].position_max;data_position_count++)
                            {
                                menu_system_class::menu_options.choice_selection[0].data[data_position_count].active = false;
                            }
                            menu_system_class::menu_options.element[ 9].selected                  = false;
                            menu_system_class::menu_options.element[10].selected                  = true;
                            menu_system_class::menu_options.element[11].selected                  = false;
                            menu_system_class::menu_options.element[12].selected                  = false;
                            menu_system_class::menu_options.element[13].selected                  = false;
                            menu_system_class::menu_options.choice_selection[0].data[temp_data_value].active    = true;
                        }
                        game.core.log.file_write("Initializing OpenGL...");
                        game.core.graphics.init_gl();
                        game.resource.loading_screen_display("data/loading_screen.png");
                        game.core.log.file_write("Loading resources....");
                        game.resource.load_all();
                    }
                break;
                case 12: // Resolution 2 selected
                    temp_data_value = 2;
                    if (menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value != game.core.config.display_resolution)
                    {
                        temp_resolution      = game.core.config.display_resolution;
                        temp_resolution_x    = game.core.config.display_resolution_x;
                        temp_resolution_y    = game.core.config.display_resolution_y;
                        game.core.config.display_resolution = menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value;
                        if (game.core.config.display_resolution == 0)
                        {
                            game.core.config.display_resolution_x = 640;
                            game.core.config.display_resolution_y = 480;
                        }
                        if (game.core.config.display_resolution == 1)
                        {
                            game.core.config.display_resolution_x = 800;
                            game.core.config.display_resolution_y = 600;
                        }
                        if (game.core.config.display_resolution == 2)
                        {
                            game.core.config.display_resolution_x = 1024;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 3)
                        {
                            game.core.config.display_resolution_x = 1280;
                            game.core.config.display_resolution_y = 1024;
                        }
                        if (game.core.config.display_resolution == 4)
                        {
                            game.core.config.display_resolution_x = 1366;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 5)
                        {
                            game.core.config.display_resolution_x = 1440;
                            game.core.config.display_resolution_y = 900;
                        }
                        if (game.core.config.display_resolution == 6)
                        {
                            game.core.config.display_resolution_x = 1680;
                            game.core.config.display_resolution_y = 1050;
                        }
                        if (game.core.config.display_resolution == 7)
                        {
                            game.core.config.display_resolution_x = 1920;
                            game.core.config.display_resolution_y = 1080;
                        }
                        if (!game.core.graphics.init_sdl())
                        {
                            game.core.log.file_write("Reverting graphics configuration...");
                            game.core.config.display_resolution    = temp_resolution;
                            game.core.config.display_resolution_x  = temp_resolution_x;
                            game.core.config.display_resolution_y  = temp_resolution_y;
                            game.core.graphics.init_sdl();
                        }
                        else
                        {
                            game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
                            game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
                            for (int data_position_count = 0; data_position_count < menu_system_class::menu_options.choice_selection[0].position_max;data_position_count++)
                            {
                                menu_system_class::menu_options.choice_selection[0].data[data_position_count].active = false;
                            }
                            menu_system_class::menu_options.element[ 9].selected                  = false;
                            menu_system_class::menu_options.element[10].selected                  = false;
                            menu_system_class::menu_options.element[11].selected                  = true;
                            menu_system_class::menu_options.element[12].selected                  = false;
                            menu_system_class::menu_options.element[13].selected                  = false;
                            menu_system_class::menu_options.choice_selection[0].data[temp_data_value].active    = true;
                        }
                        game.core.log.file_write("Initializing OpenGL...");
                        game.core.graphics.init_gl();
                        game.resource.loading_screen_display("data/loading_screen.png");
                        game.core.log.file_write("Loading resources....");
                        game.resource.load_all();
                    }
                break;
                case 13: // Resolution 3 selected
                    temp_data_value = 3;
                    if (menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value != game.core.config.display_resolution)
                    {
                        temp_resolution      = game.core.config.display_resolution;
                        temp_resolution_x    = game.core.config.display_resolution_x;
                        temp_resolution_y    = game.core.config.display_resolution_y;
                        game.core.config.display_resolution = menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value;
                        if (game.core.config.display_resolution == 0)
                        {
                            game.core.config.display_resolution_x = 640;
                            game.core.config.display_resolution_y = 480;
                        }
                        if (game.core.config.display_resolution == 1)
                        {
                            game.core.config.display_resolution_x = 800;
                            game.core.config.display_resolution_y = 600;
                        }
                        if (game.core.config.display_resolution == 2)
                        {
                            game.core.config.display_resolution_x = 1024;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 3)
                        {
                            game.core.config.display_resolution_x = 1280;
                            game.core.config.display_resolution_y = 1024;
                        }
                        if (game.core.config.display_resolution == 4)
                        {
                            game.core.config.display_resolution_x = 1366;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 5)
                        {
                            game.core.config.display_resolution_x = 1440;
                            game.core.config.display_resolution_y = 900;
                        }
                        if (game.core.config.display_resolution == 6)
                        {
                            game.core.config.display_resolution_x = 1680;
                            game.core.config.display_resolution_y = 1050;
                        }
                        if (game.core.config.display_resolution == 7)
                        {
                            game.core.config.display_resolution_x = 1920;
                            game.core.config.display_resolution_y = 1080;
                        }
                        if (!game.core.graphics.init_sdl())
                        {
                            game.core.log.file_write("Reverting graphics configuration...");
                            game.core.config.display_resolution    = temp_resolution;
                            game.core.config.display_resolution_x  = temp_resolution_x;
                            game.core.config.display_resolution_y  = temp_resolution_y;
                            game.core.graphics.init_sdl();
                        }
                        else
                        {
                            game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
                            game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
                            for (int data_position_count = 0; data_position_count < menu_system_class::menu_options.choice_selection[0].position_max;data_position_count++)
                            {
                                menu_system_class::menu_options.choice_selection[0].data[data_position_count].active = false;
                            }
                            menu_system_class::menu_options.element[ 9].selected                  = false;
                            menu_system_class::menu_options.element[10].selected                  = false;
                            menu_system_class::menu_options.element[11].selected                  = false;
                            menu_system_class::menu_options.element[12].selected                  = true;
                            menu_system_class::menu_options.element[13].selected                  = false;
                            menu_system_class::menu_options.choice_selection[0].data[temp_data_value].active    = true;
                        }
                        game.core.log.file_write("Initializing OpenGL...");
                        game.core.graphics.init_gl();
                        game.resource.loading_screen_display("data/loading_screen.png");
                        game.core.log.file_write("Loading resources....");
                        game.resource.load_all();
                    }
                break;
                case 14: // Resolution 4 selected
                    temp_data_value = 4;
                    if (menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value != game.core.config.display_resolution)
                    {
                        temp_resolution      = game.core.config.display_resolution;
                        temp_resolution_x    = game.core.config.display_resolution_x;
                        temp_resolution_y    = game.core.config.display_resolution_y;
                        game.core.config.display_resolution = menu_system_class::menu_options.choice_selection[0].data[temp_data_value].value;
                        if (game.core.config.display_resolution == 0)
                        {
                            game.core.config.display_resolution_x = 640;
                            game.core.config.display_resolution_y = 480;
                        }
                        if (game.core.config.display_resolution == 1)
                        {
                            game.core.config.display_resolution_x = 800;
                            game.core.config.display_resolution_y = 600;
                        }
                        if (game.core.config.display_resolution == 2)
                        {
                            game.core.config.display_resolution_x = 1024;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 3)
                        {
                            game.core.config.display_resolution_x = 1280;
                            game.core.config.display_resolution_y = 1024;
                        }
                        if (game.core.config.display_resolution == 4)
                        {
                            game.core.config.display_resolution_x = 1366;
                            game.core.config.display_resolution_y = 768;
                        }
                        if (game.core.config.display_resolution == 5)
                        {
                            game.core.config.display_resolution_x = 1440;
                            game.core.config.display_resolution_y = 900;
                        }
                        if (game.core.config.display_resolution == 6)
                        {
                            game.core.config.display_resolution_x = 1680;
                            game.core.config.display_resolution_y = 1050;
                        }
                        if (game.core.config.display_resolution == 7)
                        {
                            game.core.config.display_resolution_x = 1920;
                            game.core.config.display_resolution_y = 1080;
                        }
                        if (!game.core.graphics.init_sdl())
                        {
                            game.core.log.file_write("Reverting graphics configuration...");
                            game.core.config.display_resolution    = temp_resolution;
                            game.core.config.display_resolution_x  = temp_resolution_x;
                            game.core.config.display_resolution_y  = temp_resolution_y;
                            game.core.graphics.init_sdl();
                        }
                        else
                        {
                            game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
                            game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
                            for (int data_position_count = 0; data_position_count < menu_system_class::menu_options.choice_selection[0].position_max;data_position_count++)
                            {
                                menu_system_class::menu_options.choice_selection[0].data[data_position_count].active = false;
                            }
                            menu_system_class::menu_options.element[ 9].selected                  = false;
                            menu_system_class::menu_options.element[10].selected                  = false;
                            menu_system_class::menu_options.element[11].selected                  = false;
                            menu_system_class::menu_options.element[12].selected                  = false;
                            menu_system_class::menu_options.element[13].selected                  = true;
                            menu_system_class::menu_options.choice_selection[0].data[temp_data_value].active    = true;
                        }
                        game.core.log.file_write("Initializing OpenGL...");
                        game.core.graphics.init_gl();
                        game.resource.loading_screen_display("data/loading_screen.png");
                        game.core.log.file_write("Loading resources....");
                        game.resource.load_all();
                    }
                break;
/*---------------------------------------------------------------------------------------------------------*/

                case 15: // toggle full screen
                    if (game.core.config.display_fullscreen)
                    {
                        game.core.config.display_fullscreen                                   = false;
                        menu_system_class::menu_options.element[16].value                     = 0.0f;
                        menu_system_class::menu_options.element[16].texture_ID.normal         = game.resource.texture.red_button.ref_number;
                        menu_system_class::menu_options.element[16].texture_ID.highlighted    = game.resource.texture.red_button_highlighted.ref_number;
                        menu_system_class::menu_options.element[16].texture_ID.disabled       = game.resource.texture.green_button.ref_number;
                        menu_system_class::menu_options.element[16].texture_ID.base           = game.resource.texture.green_button_highlighted.ref_number;
                        game.core.graphics.init_sdl();
                        game.core.graphics.init_gl();
                        game.resource.loading_screen_display("data/loading_screen.png");
                        game.core.log.file_write("Loading resources....");
                        game.resource.load_all();
                    }
                    else
                    {
                        game.core.config.display_fullscreen                                   = true;
                        menu_system_class::menu_options.element[16].value                     = 1.0f;
                        menu_system_class::menu_options.element[16].texture_ID.normal         = game.resource.texture.green_button.ref_number;
                        menu_system_class::menu_options.element[16].texture_ID.highlighted    = game.resource.texture.green_button_highlighted.ref_number;
                        menu_system_class::menu_options.element[16].texture_ID.disabled       = game.resource.texture.red_button.ref_number;
                        menu_system_class::menu_options.element[16].texture_ID.base           = game.resource.texture.red_button_highlighted.ref_number;
                        game.core.graphics.init_sdl();
                        game.core.graphics.init_gl();
                        game.resource.loading_screen_display("data/loading_screen.png");
                        game.core.log.file_write("Loading resources....");
                        game.resource.load_all();
                    }
                break;
                case 16: // main menu button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_options.position_x,menu_system_class::menu_options.position_y);
                    game.resource.sound.menu_select_00.play();
                break;
                case 18: // close button
                    menu_system_class::active_menu = MENU_MAIN;
                    menu_system_class::menu_main.set_position(menu_system_class::menu_options.position_x,menu_system_class::menu_options.position_y);
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
