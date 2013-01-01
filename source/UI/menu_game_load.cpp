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

#include "menu_game_load.hpp"
#include "../game.hpp"

extern game_class         game;

//----------------------------------------------------------Main menu Class ------------------------------------------------------------------------

void setup_menu_game_load(int UID)
{
    int window_number = game.window_manager.window_get_number(UID);
    int element_number = 1;
    game.window_manager.window[window_number].active                  = false;
    game.window_manager.window[window_number].mouse_over_menu         = false;
    game.window_manager.window[window_number].mouse_over_title        = false;
    game.window_manager.window[window_number].position.x              = 0.0f;
    game.window_manager.window[window_number].position.y              = 0.0f;
    game.window_manager.window[window_number].position.z              = 0.0f;
    game.window_manager.window[window_number].size.x                  = 0.6f;
    game.window_manager.window[window_number].size.y                  = 1.0f;
    game.window_manager.window[window_number].texture.angle           = 0.0f;
    game.window_manager.window[window_number].texture.base.image_path = "data/textures/UI/menu/background_02.png";
    game.window_manager.window[window_number].texture.base.image.load_image(game.window_manager.window[window_number].texture.base.image_path);
    game.window_manager.window[window_number].texture.normal.image_path = "data/textures/UI/menu/button_normal.png";
    game.window_manager.window[window_number].texture.normal.image.load_image(game.window_manager.window[window_number].texture.normal.image_path);
    game.window_manager.window[window_number].texture.highlighted.image_path = "data/textures/UI/menu/button_highlighted.png";
    game.window_manager.window[window_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].texture.disabled.image_path = "data/textures/UI/menu/button_disabled.png";
    game.window_manager.window[window_number].texture.disabled.image.load_image(game.window_manager.window[window_number].texture.disabled.image_path);
    game.window_manager.window[window_number].sound.on_click.enabled      = true;
    game.window_manager.window[window_number].sound.on_click.sound_path   = "data/sound/menu/menu_select_00.wav";
    game.window_manager.window[window_number].sound.on_click.sound.load(game.window_manager.window[window_number].sound.on_click.sound_path);
    game.window_manager.window[window_number].sound.on_mouse_over.enabled      = true;
    game.window_manager.window[window_number].sound.on_mouse_over.sound_path   = "data/sound/menu/menu_move_00.wav";
    game.window_manager.window[window_number].sound.on_mouse_over.sound.load(game.window_manager.window[window_number].sound.on_mouse_over.sound_path);
    game.window_manager.window[window_number].font_path                   = "data/fonts/font_001.ttf";
    game.window_manager.window[window_number].font.load(game.window_manager.window[window_number].font_path);
    game.window_manager.window[window_number].mouse_delay.maximum     = 30;
    game.window_manager.window[window_number].event                   = 0;
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
    game.window_manager.window[window_number].title.enabled           = true;
    game.window_manager.window[window_number].title.text              = "Load Game";
    game.window_manager.window[window_number].title.size.x            = game.window_manager.window[window_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].title.size.y            = game.window_manager.window[window_number].title.size.x*4;
    game.window_manager.window[window_number].title.position.x        = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].title.size.x/100.0f);
    game.window_manager.window[window_number].title.position.y        = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y/2.0f) - (game.window_manager.window[window_number].title.size.y / 440.0f);
    game.window_manager.window[window_number].title_bar.size.x        = game.window_manager.window[window_number].size.x; // x/2.0f for middle section
    game.window_manager.window[window_number].title_bar.size.y        = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].title_bar.position.x    = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].title_bar.position.y    = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].title_bar.size.y/2.0f);

    // ---------------------------- Setup window elements ----------------------------------------------------
    game.window_manager.window[window_number].number_of_elements = 8;
    game.window_manager.window[window_number].element = new window_element_class[game.window_manager.window[window_number].number_of_elements];
    element_number = 1; //--- Close button ---
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
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/close_button.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/close_button_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 2; //--- Save Game 1 ---
    game.window_manager.window[window_number].element[element_number].title.text                = "Load Slot 1";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].state                     = DISABLED;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*80.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.0f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.0f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/70.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 3; //--- Save Game 2 ---
    game.window_manager.window[window_number].element[element_number].title.text                = "Load Slot 2";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].state                     = DISABLED;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*80.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*3.25f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.0f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/70.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 4; //--- Save Game 3 ---
    game.window_manager.window[window_number].element[element_number].title.text                = "Load Slot 3";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].state                     = DISABLED;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*80.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.5f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.0f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/70.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 5; //--- Save Game 4 ---
    game.window_manager.window[window_number].element[element_number].title.text                = "Load Slot 4";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].state                     = DISABLED;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*80.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*5.75f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.0f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/70.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 6; //--- Save Game 5 ---
    game.window_manager.window[window_number].element[element_number].title.text                = "Load Slot 5";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].state                     = DISABLED;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*80.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*7.0f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.0f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/70.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 7; //--- Main Menu button ---
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
};

void process_menu_game_load(int window_number)
{
    if(game.window_manager.window[window_number].event > 0)
    {
        switch (game.window_manager.window[window_number].event)
        {
            case 101: // Close menu button
                game.window_manager.window_transition(MENU_GAME_LOAD_UID,MENU_MAIN_UID);
            break;
            case 201: // Load slot 1 - menu button
                game.window_manager.window_transition(MENU_GAME_LOAD_UID,MENU_MAIN_UID);
                game.window_manager.window_disable(MENU_MAIN_UID);
                game.core.game_menu_active = false;
                game.save_01.Assign_File("save/slot_01.sav");
                if (game.save_01.Load())
                {
                    game.core.log.file_write("Loading game from slot 1");
                    game.state = STATE_GAME;
                    game.core.music_next_track = true;
                }
                else game.core.log.file_write("ERROR -> Error loading game from slot 1");
            break;
            case 301: // Load slot 2 - menu button
                game.window_manager.window_transition(MENU_GAME_LOAD_UID,MENU_MAIN_UID);
                game.window_manager.window_disable(MENU_MAIN_UID);
                game.core.game_menu_active = false;
                game.save_02.Assign_File("save/slot_02.sav");
                if (game.save_02.Load())
                {
                    game.core.log.file_write("Loading game from slot 2");
                    game.state = STATE_GAME;
                    game.core.music_next_track = true;
                }
                else game.core.log.file_write("ERROR -> Error loading game from slot 2");
            break;
            case 401: // Load slot 3 - menu button
                game.window_manager.window_transition(MENU_GAME_LOAD_UID,MENU_MAIN_UID);
                game.window_manager.window_disable(MENU_MAIN_UID);
                game.core.game_menu_active = false;
                game.save_03.Assign_File("save/slot_03.sav");
                if (game.save_03.Load())
                {
                    game.core.log.file_write("Loading game from slot 3");
                    game.state = STATE_GAME;
                    game.core.music_next_track = true;
                }
                else game.core.log.file_write("ERROR -> Error loading game from slot 3");
            break;
            case 501: // Load slot 4 - menu button
                game.window_manager.window_transition(MENU_GAME_LOAD_UID,MENU_MAIN_UID);
                game.window_manager.window_disable(MENU_MAIN_UID);
                game.core.game_menu_active = false;
                game.save_04.Assign_File("save/slot_04.sav");
                if (game.save_04.Load())
                {
                    game.core.log.file_write("Loading game from slot 4");
                    game.state = STATE_GAME;
                    game.core.music_next_track = true;
                }
                else game.core.log.file_write("ERROR -> Error loading game from slot 4");
            break;
            case 601: // Load slot 5 - menu button
                game.window_manager.window_transition(MENU_GAME_LOAD_UID,MENU_MAIN_UID);
                game.window_manager.window_disable(MENU_MAIN_UID);
                game.core.game_menu_active = false;
                game.save_05.Assign_File("save/slot_05.sav");
                if (game.save_05.Load())
                {
                    game.core.log.file_write("Loading game from slot 5");
                    game.state = STATE_GAME;
                    game.core.music_next_track = true;
                }
                else game.core.log.file_write("ERROR -> Error loading game from slot 5");
            break;
            case 701: // Main menu button
                game.window_manager.window_transition(MENU_GAME_LOAD_UID,MENU_MAIN_UID);
            break;
            default:
                game.core.log.file_write("Unable to process event - ",game.window_manager.window[window_number].event, " - UID - ",game.window_manager.window[window_number].UID);
                game.window_manager.window[window_number].event = 0;
            break;
        }
    }
    game.window_manager.window[window_number].event = 0;
};






