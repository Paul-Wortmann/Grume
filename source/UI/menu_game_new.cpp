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

#include "menu_game_new.hpp"
#include "../game.hpp"

extern game_class         game;

//----------------------------------------------------------Main menu Class ------------------------------------------------------------------------

void setup_menu_game_new(int UID)
{
    int window_number = game.window_manager.window_get_number(UID);
    int element_number = 1;
    game.window_manager.window[window_number].UID                     = UID;
    game.window_manager.window[window_number].active                  = false;
    game.window_manager.window[window_number].mouse_over_menu         = false;
    game.window_manager.window[window_number].mouse_over_title        = false;
    game.window_manager.window[window_number].position.x              = 0.0f;
    game.window_manager.window[window_number].position.y              = 0.0f;
    game.window_manager.window[window_number].position.z              = 0.0f;
    game.window_manager.window[window_number].size.x                  = 0.5f;
    game.window_manager.window[window_number].size.y                  = game.window_manager.window[window_number].size.x * 2.5f;
    game.window_manager.window[window_number].texture.angle           = 0.0f;
    game.window_manager.window[window_number].texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/background_02.png");
    game.window_manager.window[window_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/button_normal.png");
    game.window_manager.window[window_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/button_highlighted.png");
    game.window_manager.window[window_number].texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/button_disabled.png");
    game.window_manager.window[window_number].sound.on_click.enabled      = true;
    game.window_manager.window[window_number].sound.on_click.sound_path   = "data/sound/menu/menu_select_00.wav";
    game.window_manager.window[window_number].sound.on_click.sound.load(game.window_manager.window[window_number].sound.on_click.sound_path);
    game.window_manager.window[window_number].sound.on_mouse_over.enabled      = true;
    game.window_manager.window[window_number].sound.on_mouse_over.sound_path   = "data/sound/menu/menu_move_00.wav";
    game.window_manager.window[window_number].sound.on_mouse_over.sound.load(game.window_manager.window[window_number].sound.on_mouse_over.sound_path);
    game.window_manager.window[window_number].font_path                   = "data/fonts/font_001.ttf";
    game.window_manager.window[window_number].font.load(game.window_manager.window[window_number].font_path);
    game.window_manager.window[window_number].mouse_delay.maximum     = 30;
    game.window_manager.window[window_number].event.id                = 0;
    game.window_manager.window[window_number].color.normal.r          = 128;
    game.window_manager.window[window_number].color.normal.b          = 128;
    game.window_manager.window[window_number].color.normal.g          = 128;
    game.window_manager.window[window_number].color.normal.a          = 255;
    game.window_manager.window[window_number].color.highlighted.r     = 192;
    game.window_manager.window[window_number].color.highlighted.b     = 192;
    game.window_manager.window[window_number].color.highlighted.g     = 192;
    game.window_manager.window[window_number].color.highlighted.a     = 255;
    game.window_manager.window[window_number].color.disabled.r        = 064;
    game.window_manager.window[window_number].color.disabled.b        = 064;
    game.window_manager.window[window_number].color.disabled.g        = 064;
    game.window_manager.window[window_number].color.disabled.a        = 128;
    game.window_manager.window[window_number].zoom.enabled            = true;
    game.window_manager.window[window_number].zoom.maximum            = 0.02f;
    game.window_manager.window[window_number].zoom.speed              = 0.004f;
    game.window_manager.window[window_number].texture.angle           = 0.0f;
    game.window_manager.window[window_number].title.text              = "New Game";
    game.window_manager.window[window_number].title.enabled           = true;
    game.window_manager.window[window_number].title.size.x            = game.window_manager.window[window_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].title.size.y            = game.window_manager.window[window_number].title.size.x*4;
    game.window_manager.window[window_number].title.position.x        = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].title.size.x/100.0f);
    game.window_manager.window[window_number].title.position.y        = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y/2.0f) - (game.window_manager.window[window_number].title.size.y / 380.0f);
    game.window_manager.window[window_number].title_bar.size.x        = game.window_manager.window[window_number].size.x; // x/2.0f for middle section
    game.window_manager.window[window_number].title_bar.size.y        = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].title_bar.position.x    = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].title_bar.position.y    = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].title_bar.size.y/2.0f);

    // ---------------------------- Setup window elements ----------------------------------------------------
    game.window_manager.window[window_number].number_of_elements = 10;
    game.window_manager.window[window_number].element = new window_element_class[game.window_manager.window[window_number].number_of_elements];
    element_number = 0; //--- Close button ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.1f;
    game.window_manager.window[window_number].element[element_number].size.y                    = 0.1f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/2.0f)-(game.window_manager.window[window_number].element[element_number].size.x/1.8f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].title.position.y+(game.window_manager.window[window_number].element[element_number].size.y/8.0f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/close_button.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/close_button_highlighted.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;

    element_number = 1; //--- Main menu button ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "Main Menu";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*80.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*9.0f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/100.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;

    element_number = 2; //--- Start game menu button ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "Start Game";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*80.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*7.5f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/100.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;

//----------------------------------------------------------------------------------------------------------------------

    game.window_manager.window[window_number].choice_selection[0].selected         = 0; // Player portrait selection
    game.window_manager.window[window_number].choice_selection[0].position         = 0;
    game.window_manager.window[window_number].choice_selection[0].position_max     = 12;
    for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
    {
        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active = false;
    }
    game.window_manager.window[window_number].choice_selection[0].data[ 0].active     = true;
    game.window_manager.window[window_number].choice_selection[0].data[ 0].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_00.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 1].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_01.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 2].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_02.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 3].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_03.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 4].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_04.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 5].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_05.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 6].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_06.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 7].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_07.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 8].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_08.png");
    game.window_manager.window[window_number].choice_selection[0].data[ 9].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_09.png");
    game.window_manager.window[window_number].choice_selection[0].data[10].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_10.png");
    game.window_manager.window[window_number].choice_selection[0].data[11].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_11.png");
    game.window_manager.window[window_number].choice_selection[0].data[12].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_12.png");
    game.player.portrait = game.window_manager.window[window_number].choice_selection[0].data[ 0].image;

    element_number = 3; // left arrow button for player portrait selection
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.0f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    game.window_manager.window[window_number].element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    game.window_manager.window[window_number].element[element_number].texture.angle             = 0.0f;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/100.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;

    element_number = 4; // Right arrow button for player portrait selection
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/2.0f)-(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.0f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    game.window_manager.window[window_number].element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    game.window_manager.window[window_number].element[element_number].texture.angle             = 180.0f;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/100.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;

    element_number = 5; // Image 0 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].selected                  = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*2.5f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.00f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.window_manager.window[window_number].choice_selection[0].data[0].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;

    element_number = 6; // Image 1 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].selected                  = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*3.75f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.00f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.window_manager.window[window_number].choice_selection[0].data[1].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;

    element_number = 7; // Image 2 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].selected                  = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*5.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.00f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.window_manager.window[window_number].choice_selection[0].data[2].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;

    element_number = 8; // Image 3 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].selected                  = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*6.25f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.00f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.window_manager.window[window_number].choice_selection[0].data[3].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;

    element_number = 9; // Image 4 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].selected                  = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*7.5f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.00f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.window_manager.window[window_number].choice_selection[0].data[4].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
};

void update_menu_game_new(int UID)
{
    int element_number = 0;
    int window_number = game.window_manager.window_get_number(UID);
    element_number = 5; // Image 0 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].texture.normal      = game.window_manager.window[window_number].choice_selection[0].data[element_number-5].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted = game.window_manager.window[window_number].element[element_number].texture.highlighted;
    element_number = 6; // Image 1 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].texture.normal      = game.window_manager.window[window_number].choice_selection[0].data[element_number-5].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted = game.window_manager.window[window_number].element[element_number].texture.highlighted;
    element_number = 7; // Image 2 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].texture.normal      = game.window_manager.window[window_number].choice_selection[0].data[element_number-5].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted = game.window_manager.window[window_number].element[element_number].texture.highlighted;
    element_number = 8; // Image 3 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].texture.normal      = game.window_manager.window[window_number].choice_selection[0].data[element_number-5].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted = game.window_manager.window[window_number].element[element_number].texture.highlighted;
    element_number = 9; // Image 4 of the player portrait selection
    game.window_manager.window[window_number].element[element_number].texture.normal      = game.window_manager.window[window_number].choice_selection[0].data[element_number-5].image;
    game.window_manager.window[window_number].element[element_number].texture.highlighted = game.window_manager.window[window_number].element[element_number].texture.highlighted;
};

void process_menu_game_new(int window_number)
{
    texture_type *temp_data_texture;
    bool temp_data_bool = false;
    if(game.window_manager.window[window_number].event.id > EVENT_NONE)
    {
        switch (game.window_manager.window[window_number].event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.window_manager.window_transition(MENU_GAME_NEW_UID,MENU_MAIN_UID);
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Main menu button
                game.window_manager.window_transition(MENU_GAME_NEW_UID,MENU_MAIN_UID);
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Start game menu button
                switch (game.state)
                {
                    case STATE_MENU:
                    break;
                    case STATE_GAME:
                        game.init();
                    break;
                    default:
                        game.init();
                    break;
                }
                game.state = STATE_GAME;
                game.core.music_next_track = true;
                game.window_manager.window_transition(MENU_GAME_NEW_UID,MENU_MAIN_UID);
                game.window_manager.window_disable(MENU_MAIN_UID);
                game.core.game_menu_active = false;
                game.window_manager.window_disable(EQUIPMENT_UID);
                game.core.equipment_active = false;
                game.window_manager.window_disable(QUEST_LOG_UID);
                game.core.quest_log_active = false;
                game.window_manager.window_disable(CHARACTER_UID);
                game.core.character_active = false;
                game.window_manager.window_disable(INVENTORY_UID);
                game.core.inventory_active = false;
                game.window_manager.window_disable(SKILLBOOK_UID);
                game.core.skillbook_active = false;
                game.window_manager.window_disable(NPCVENDOR_UID);
                game.core.npcvendor_active = false;
                game.window_manager.window_enable(PCPROFILE_UID);
                game.window_manager.window_set_active(PCPROFILE_UID);
                game.window_manager.window_enable(ACTIONBAR_UID);
                game.window_manager.window_set_active(ACTIONBAR_UID);
                game.window_manager.window[game.window_manager.window_get_number(MENU_MAIN_UID)].element[3].state = NORMAL; // Save game
                game.window_manager.window[game.window_manager.window_get_number(MENU_MAIN_UID)].element[4].state = NORMAL; // Resume game
                //set player portrait
                for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                {
                    if (game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active)
                    {
                        game.player.portrait = game.window_manager.window[window_number].choice_selection[0].data[data_position_count].image;
                    };
                }
                update_player_profile(game.window_manager.window_get_number(PCPROFILE_UID));
                update_character_window(CHARACTER_UID);
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // left arrow button for player portrait selection
                game.window_manager.window[window_number].choice_selection[0].position++;
                if (game.window_manager.window[window_number].choice_selection[0].position > game.window_manager.window[window_number].choice_selection[0].position_max+1) game.window_manager.window[window_number].choice_selection[0].position = 0;
                temp_data_texture      = game.window_manager.window[window_number].choice_selection[0].data[0].image;
                temp_data_bool         = game.window_manager.window[window_number].choice_selection[0].data[0].active;
                for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                {
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].image      = game.window_manager.window[window_number].choice_selection[0].data[data_position_count+1].image;
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active     = game.window_manager.window[window_number].choice_selection[0].data[data_position_count+1].active;
                }
                game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max].image      = temp_data_texture;
                game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max].active     = temp_data_bool;
                game.window_manager.window[window_number].element[5].texture.normal              = game.window_manager.window[window_number].choice_selection[0].data[0].image;
                game.window_manager.window[window_number].element[6].texture.normal              = game.window_manager.window[window_number].choice_selection[0].data[1].image;
                game.window_manager.window[window_number].element[7].texture.normal              = game.window_manager.window[window_number].choice_selection[0].data[2].image;
                game.window_manager.window[window_number].element[8].texture.normal              = game.window_manager.window[window_number].choice_selection[0].data[3].image;
                game.window_manager.window[window_number].element[9].texture.normal              = game.window_manager.window[window_number].choice_selection[0].data[4].image;
                game.window_manager.window[window_number].element[5].selected                    = game.window_manager.window[window_number].choice_selection[0].data[0].active;
                game.window_manager.window[window_number].element[6].selected                    = game.window_manager.window[window_number].choice_selection[0].data[1].active;
                game.window_manager.window[window_number].element[7].selected                    = game.window_manager.window[window_number].choice_selection[0].data[2].active;
                game.window_manager.window[window_number].element[8].selected                    = game.window_manager.window[window_number].choice_selection[0].data[3].active;
                game.window_manager.window[window_number].element[9].selected                    = game.window_manager.window[window_number].choice_selection[0].data[4].active;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Right arrow button for player portrait selection
                game.window_manager.window[window_number].choice_selection[0].position--;
                if (game.window_manager.window[window_number].choice_selection[0].position < 0) game.window_manager.window[window_number].choice_selection[0].position = game.window_manager.window[window_number].choice_selection[0].position_max;
                temp_data_texture      = game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max-1].image;
                temp_data_bool         = game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max-1].active;
                for (int data_position_count = game.window_manager.window[window_number].choice_selection[0].position_max-1; data_position_count > 0;data_position_count--)
                {
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].image      = game.window_manager.window[window_number].choice_selection[0].data[data_position_count-1].image;
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active     = game.window_manager.window[window_number].choice_selection[0].data[data_position_count-1].active;
                }
                game.window_manager.window[window_number].choice_selection[0].data[0].image       = temp_data_texture;
                game.window_manager.window[window_number].choice_selection[0].data[0].active      = temp_data_bool;
                game.window_manager.window[window_number].element[5].texture.normal               = game.window_manager.window[window_number].choice_selection[0].data[0].image;
                game.window_manager.window[window_number].element[6].texture.normal               = game.window_manager.window[window_number].choice_selection[0].data[1].image;
                game.window_manager.window[window_number].element[7].texture.normal               = game.window_manager.window[window_number].choice_selection[0].data[2].image;
                game.window_manager.window[window_number].element[8].texture.normal               = game.window_manager.window[window_number].choice_selection[0].data[3].image;
                game.window_manager.window[window_number].element[9].texture.normal               = game.window_manager.window[window_number].choice_selection[0].data[4].image;
                game.window_manager.window[window_number].element[5].selected                     = game.window_manager.window[window_number].choice_selection[0].data[0].active;
                game.window_manager.window[window_number].element[6].selected                     = game.window_manager.window[window_number].choice_selection[0].data[1].active;
                game.window_manager.window[window_number].element[7].selected                     = game.window_manager.window[window_number].choice_selection[0].data[2].active;
                game.window_manager.window[window_number].element[8].selected                     = game.window_manager.window[window_number].choice_selection[0].data[3].active;
                game.window_manager.window[window_number].element[9].selected                     = game.window_manager.window[window_number].choice_selection[0].data[4].active;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 0 selected
                for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                {
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active = false;
                }
                game.window_manager.window[window_number].element[5].selected                  = true;
                game.window_manager.window[window_number].element[6].selected                  = false;
                game.window_manager.window[window_number].element[7].selected                  = false;
                game.window_manager.window[window_number].element[8].selected                  = false;
                game.window_manager.window[window_number].element[9].selected                  = false;
                game.window_manager.window[window_number].choice_selection[0].data[0].active   = true;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 1 selected
                for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                {
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active = false;
                }
                game.window_manager.window[window_number].element[5].selected                  = false;
                game.window_manager.window[window_number].element[6].selected                  = true;
                game.window_manager.window[window_number].element[7].selected                  = false;
                game.window_manager.window[window_number].element[8].selected                  = false;
                game.window_manager.window[window_number].element[9].selected                  = false;
                game.window_manager.window[window_number].choice_selection[0].data[1].active   = true;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 2 selected
                for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                {
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active = false;
                }
                game.window_manager.window[window_number].element[5].selected                  = false;
                game.window_manager.window[window_number].element[6].selected                  = false;
                game.window_manager.window[window_number].element[7].selected                  = true;
                game.window_manager.window[window_number].element[8].selected                  = false;
                game.window_manager.window[window_number].element[9].selected                  = false;
                game.window_manager.window[window_number].choice_selection[0].data[2].active   = true;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 3 selected
                for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                {
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active = false;
                }
                game.window_manager.window[window_number].element[5].selected                  = false;
                game.window_manager.window[window_number].element[6].selected                  = false;
                game.window_manager.window[window_number].element[7].selected                  = false;
                game.window_manager.window[window_number].element[8].selected                  = true;
                game.window_manager.window[window_number].element[9].selected                  = false;
                game.window_manager.window[window_number].choice_selection[0].data[3].active   = true;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 4 selected
                for (int data_position_count = 0; data_position_count <= game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                {
                    game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active = false;
                }
                game.window_manager.window[window_number].element[5].selected                  = false;
                game.window_manager.window[window_number].element[6].selected                  = false;
                game.window_manager.window[window_number].element[7].selected                  = false;
                game.window_manager.window[window_number].element[8].selected                  = false;
                game.window_manager.window[window_number].element[9].selected                  = true;
                game.window_manager.window[window_number].choice_selection[0].data[4].active   = true;
            break;
            case (EVENT_WINDOW_STACK_SORT): //Window stack sort
                game.window_manager.window_stack_sort();
                game.window_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.window_manager.source.window = MENU_GAME_NEW_UID;
            break;
            case (EVENT_ELEMENT_DROP): //Element drop event posted
                //game.window_manager.destination.window = MENU_GAME_NEW_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",game.window_manager.window[window_number].event.id, " - UID - ",game.window_manager.window[window_number].UID);
                game.window_manager.window[window_number].event.id = EVENT_NONE;
            break;
        }
    }
    game.window_manager.window[window_number].event.id = EVENT_NONE;
};






