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

#include "menu_options.hpp"
#include <string>
#include "../game.hpp"

extern game_class         game;

//----------------------------------------------------------Main menu Class ------------------------------------------------------------------------

void setup_menu_options(int UID)
{
    int window_number = game.window_manager.window_get_number(UID);
    int element_number = 0;
    game.window_manager.window[window_number].active                  = false;
    game.window_manager.window[window_number].mouse_over_menu         = false;
    game.window_manager.window[window_number].mouse_over_title        = false;
    game.window_manager.window[window_number].position.x              = 0.0f;
    game.window_manager.window[window_number].position.y              = 0.0f;
    game.window_manager.window[window_number].position.z              = 0.0f;
    game.window_manager.window[window_number].size.x                  = 0.5f;
    game.window_manager.window[window_number].size.y                  = game.window_manager.window[window_number].size.x * 2.5f;
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
    game.window_manager.window[window_number].title.text              = " Options ";
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
    game.window_manager.window[window_number].number_of_elements = 18;
    game.window_manager.window[window_number].element = new window_element_class[game.window_manager.window[window_number].number_of_elements];
    element_number = 0; //--- Close button ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
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

    element_number = 1; //--- Main menu button ---
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

// ------------------------------------- Resolution selection --------------------------------------------------------

    game.window_manager.window[window_number].choice_selection[0].selected                = 0; // Resolution selection
    game.window_manager.window[window_number].choice_selection[0].position                = 0;
    game.window_manager.window[window_number].choice_selection[0].position_max            = 7;
    game.window_manager.window[window_number].choice_selection[0].data[game.core.config.display_resolution].active          = true;
    game.window_manager.window[window_number].choice_selection[0].data[0].value_int       = 0;
    game.window_manager.window[window_number].choice_selection[0].data[0].value_string    = " 640 X 480 ";
    game.window_manager.window[window_number].choice_selection[0].data[1].value_int       = 1;
    game.window_manager.window[window_number].choice_selection[0].data[1].value_string    = " 800 X 600 ";
    game.window_manager.window[window_number].choice_selection[0].data[2].value_int       = 2;
    game.window_manager.window[window_number].choice_selection[0].data[2].value_string    = "1028 X 768 ";
    game.window_manager.window[window_number].choice_selection[0].data[3].value_int       = 3;
    game.window_manager.window[window_number].choice_selection[0].data[3].value_string    = "1280 X 1024";
    game.window_manager.window[window_number].choice_selection[0].data[4].value_int       = 4;
    game.window_manager.window[window_number].choice_selection[0].data[4].value_string    = "1366 X 768 ";
    game.window_manager.window[window_number].choice_selection[0].data[5].value_int       = 5;
    game.window_manager.window[window_number].choice_selection[0].data[5].value_string    = "1440 X 900 ";
    game.window_manager.window[window_number].choice_selection[0].data[6].value_int       = 6;
    game.window_manager.window[window_number].choice_selection[0].data[6].value_string    = "1680 X 1050";
    game.window_manager.window[window_number].choice_selection[0].data[7].value_int       = 7;
    game.window_manager.window[window_number].choice_selection[0].data[7].value_string    = "1920 X 1080";

    element_number = 2; // Resolution selection element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].state                     = DISABLED;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*60.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*5.75f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;

    element_number = 3; // Resolution selection element 0
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].title.text                = game.window_manager.window[window_number].choice_selection[0].data[0].value_string;
    game.window_manager.window[window_number].element[element_number].selected                  = game.window_manager.window[window_number].choice_selection[0].data[0].active;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*2.5f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.5f);
    game.window_manager.window[window_number].element[element_number].texture.base.image_path        = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.base.image.load_image(game.window_manager.window[window_number].element[element_number].texture.base.image_path);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/resolution_icon.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.4f;;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4.0f;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].element[element_number].title.size.x/42.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y - (game.window_manager.window[window_number].element[element_number].title.size.y/120.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;

    element_number = 4; // Resolution selection element 1
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].title.text                = game.window_manager.window[window_number].choice_selection[0].data[1].value_string;
    game.window_manager.window[window_number].element[element_number].selected                  = game.window_manager.window[window_number].choice_selection[0].data[1].active;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*3.75f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.5f);
    game.window_manager.window[window_number].element[element_number].texture.base.image_path        = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.base.image.load_image(game.window_manager.window[window_number].element[element_number].texture.base.image_path);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/resolution_icon.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.4f;;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4.0f;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].element[element_number].title.size.x/42.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y - (game.window_manager.window[window_number].element[element_number].title.size.y/120.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;

    element_number = 5; // Resolution selection element 2
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].title.text                = game.window_manager.window[window_number].choice_selection[0].data[2].value_string;
    game.window_manager.window[window_number].element[element_number].selected                  = game.window_manager.window[window_number].choice_selection[0].data[2].active;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*5.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.5f);
    game.window_manager.window[window_number].element[element_number].texture.base.image_path        = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.base.image.load_image(game.window_manager.window[window_number].element[element_number].texture.base.image_path);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/resolution_icon.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.4f;;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4.0f;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].element[element_number].title.size.x/42.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y - (game.window_manager.window[window_number].element[element_number].title.size.y/120.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;

    element_number = 6; // Resolution selection element 3
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].title.text                = game.window_manager.window[window_number].choice_selection[0].data[3].value_string;
    game.window_manager.window[window_number].element[element_number].selected                  = game.window_manager.window[window_number].choice_selection[0].data[3].active;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*6.25f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.5f);
    game.window_manager.window[window_number].element[element_number].texture.base.image_path        = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.base.image.load_image(game.window_manager.window[window_number].element[element_number].texture.base.image_path);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/resolution_icon.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.4f;;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4.0f;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].element[element_number].title.size.x/42.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y - (game.window_manager.window[window_number].element[element_number].title.size.y/120.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;

    element_number = 7; // Resolution selection element 4
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].title.text                = game.window_manager.window[window_number].choice_selection[0].data[4].value_string;
    game.window_manager.window[window_number].element[element_number].selected                  = game.window_manager.window[window_number].choice_selection[0].data[4].active;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*7.5f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.5f);
    game.window_manager.window[window_number].element[element_number].texture.base.image_path        = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.base.image.load_image(game.window_manager.window[window_number].element[element_number].texture.base.image_path);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/resolution_icon.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/selection_box.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.4f;;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4.0f;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].element[element_number].title.size.x/42.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y - (game.window_manager.window[window_number].element[element_number].title.size.y/120.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 10;

    element_number = 8; // Right arrow resolution selection element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.50f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/arrow_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/arrow_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/arrow_disabled.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].texture.angle             = 0.0f;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 5;
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;

    element_number = 9; // Left arrow resolution selection element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/2.0f)-(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*4.50f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/arrow_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/arrow_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/arrow_disabled.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].texture.angle             = 180.0f;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 5;
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;

// ------------------------------------------- Sound Volume ------------------------------------------------------------
    element_number = 10; // Sound volume selection left arrow element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.0f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/arrow_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/arrow_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/arrow_disabled.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].texture.angle             = 0.0f;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 2;
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = false;

    element_number = 11; // Sound volume selection right arrow element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/2.0f)-(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.0f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/arrow_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/arrow_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/arrow_disabled.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].texture.angle             = 180.0f;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 2;
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = false;

    element_number = 12; // Sound volume selection - sound volume bar element
    game.window_manager.window[window_number].element[element_number].title.text                = "Sound volume";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].value                     = game.core.config.audio_volume_sound;
    game.window_manager.window[window_number].element[element_number].value_max                 = 127.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BAR;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*60.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*2.0f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/slider_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/slider_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path      = "data/textures/UI/menu/slider_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.2f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/60.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;

// ------------------------------------------- Music Volume ------------------------------------------------------------
    element_number = 13; // Music volume selection left arrow element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*3.25f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/arrow_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/arrow_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/arrow_disabled.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].texture.angle             = 0.0f;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 5;
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = false;

    element_number = 14; // Music volume selection right arrow element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/2.0f)-(game.window_manager.window[window_number].element[element_number].size.x*1.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*3.25f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/arrow_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/arrow_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/arrow_disabled.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].texture.angle             = 180.0f;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 5;
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = false;

    element_number = 15; // Music volume selection - music volume bar element
    game.window_manager.window[window_number].element[element_number].title.text                = "Music volume";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].value                     = game.core.config.audio_volume_music;
    game.window_manager.window[window_number].element[element_number].value_max                 = 127.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BAR;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*60.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*3.25f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/slider_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/slider_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path      = "data/textures/UI/menu/slider_normal.png";
    game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/2.2f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/60.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;

    element_number = 16; // Full screen button element
    game.window_manager.window[window_number].element[element_number].title.text                = "Fullscreen";
    game.window_manager.window[window_number].element[element_number].title.enabled             = true;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*48.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].element[element_number].size.x/8.0f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*7.0f);
    game.window_manager.window[window_number].element[element_number].texture                   = game.window_manager.window[window_number].texture;
    game.window_manager.window[window_number].element[element_number].title.size.x              = game.window_manager.window[window_number].element[element_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].element[element_number].title.size.y              = game.window_manager.window[window_number].element[element_number].title.size.x*4;;
    game.window_manager.window[window_number].element[element_number].title.position.x          = game.window_manager.window[window_number].element[element_number].position.x-(game.window_manager.window[window_number].element[element_number].title.size.x/100.0f);
    game.window_manager.window[window_number].element[element_number].title.position.y          = game.window_manager.window[window_number].element[element_number].position.y-(game.window_manager.window[window_number].element[element_number].title.size.y/1480.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;

    element_number = 17; // Full screen colored button element
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].value                     = 1.0f;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = (game.window_manager.window[window_number].size.x / 100.f)*10.0f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.0f)+(game.window_manager.window[window_number].element[element_number].size.x*7.5f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].element[element_number].size.y*7.0f);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    if (game.core.config.display_fullscreen)
    {
        game.window_manager.window[window_number].element[element_number].value                            = 1.0f;
        game.window_manager.window[window_number].element[element_number].texture.normal.image_path        = "data/textures/UI/menu/green_button.png";
        game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
        game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path   = "data/textures/UI/menu/green_button_highlighted.png";
        game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
        game.window_manager.window[window_number].element[element_number].texture.disabled.image_path      = "data/textures/UI/menu/red_button.png";
        game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
        game.window_manager.window[window_number].element[element_number].texture.base.image_path          = "data/textures/UI/menu/red_button_highlighted.png";
        game.window_manager.window[window_number].element[element_number].texture.base.image.load_image(game.window_manager.window[window_number].element[element_number].texture.base.image_path);
    }
    else
    {
        game.window_manager.window[window_number].element[element_number].value                            = 0.0f;
        game.window_manager.window[window_number].element[element_number].texture.normal.image_path        = "data/textures/UI/menu/red_button.png";
        game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
        game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path   = "data/textures/UI/menu/red_button_highlighted.png";
        game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
        game.window_manager.window[window_number].element[element_number].texture.disabled.image_path      = "data/textures/UI/menu/green_button.png";
        game.window_manager.window[window_number].element[element_number].texture.disabled.image.load_image(game.window_manager.window[window_number].element[element_number].texture.disabled.image_path);
        game.window_manager.window[window_number].element[element_number].texture.base.image_path          = "data/textures/UI/menu/green_button_highlighted.png";
        game.window_manager.window[window_number].element[element_number].texture.base.image.load_image(game.window_manager.window[window_number].element[element_number].texture.base.image_path);
    }
};

void process_menu_options(int window_number)
{
    if (game.window_manager.window[window_number].event > 0)
    {
        bool reset_display        = false;
        bool resolution_selection = false;
        int  resolution_element   = 0;
        game.core.log.file_write("Processing event - ",game.window_manager.window[window_number].event);
        switch (game.window_manager.window[window_number].event)
        {
            case 001: // Close menu button
                game.window_manager.window_transition(MENU_OPTIONS_UID,MENU_MAIN_UID);
            break;
            case 101: // Main menu button
                game.window_manager.window_transition(MENU_OPTIONS_UID,MENU_MAIN_UID);
            break;
            case 301: // Resolution selection element 0
                resolution_selection = true;
                resolution_element   = 0;
            break;
            case 401: // Resolution selection element 1
                resolution_selection = true;
                resolution_element   = 1;
            break;
            case 501: // Resolution selection element 2
                resolution_selection = true;
                resolution_element   = 2;
            break;
            case 601: // Resolution selection element 3
                resolution_selection = true;
                resolution_element   = 3;
            break;
            case 701: // Resolution selection element 4
                resolution_selection = true;
                resolution_element   = 4;
            break;
            case 801: // Resolution left arrow button
                {
                    game.window_manager.window[window_number].choice_selection[0].position++;
                    if (game.window_manager.window[window_number].choice_selection[0].position > game.window_manager.window[window_number].choice_selection[0].position_max) game.window_manager.window[window_number].choice_selection[0].position = 0;
                    int         temp_data_value   = game.window_manager.window[window_number].choice_selection[0].data[0].value_int;
                    bool        temp_data_bool    = game.window_manager.window[window_number].choice_selection[0].data[0].active;
                    std::string temp_data_string  = game.window_manager.window[window_number].choice_selection[0].data[0].value_string;
                    for (int data_position_count  = 0; data_position_count < game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                    {
                        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].value_int    = game.window_manager.window[window_number].choice_selection[0].data[data_position_count+1].value_int;
                        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active       = game.window_manager.window[window_number].choice_selection[0].data[data_position_count+1].active;
                        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].value_string = game.window_manager.window[window_number].choice_selection[0].data[data_position_count+1].value_string;
                    }
                    game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max].value_int    = temp_data_value;
                    game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max].active       = temp_data_bool;
                    game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max].value_string = temp_data_string;
                    game.window_manager.window[window_number].element[3].selected                  = game.window_manager.window[window_number].choice_selection[0].data[0].active;
                    game.window_manager.window[window_number].element[4].selected                  = game.window_manager.window[window_number].choice_selection[0].data[1].active;
                    game.window_manager.window[window_number].element[5].selected                  = game.window_manager.window[window_number].choice_selection[0].data[2].active;
                    game.window_manager.window[window_number].element[6].selected                  = game.window_manager.window[window_number].choice_selection[0].data[3].active;
                    game.window_manager.window[window_number].element[7].selected                  = game.window_manager.window[window_number].choice_selection[0].data[4].active;
                    game.window_manager.window[window_number].element[3].title.text                = game.window_manager.window[window_number].choice_selection[0].data[0].value_string;
                    game.window_manager.window[window_number].element[4].title.text                = game.window_manager.window[window_number].choice_selection[0].data[1].value_string;
                    game.window_manager.window[window_number].element[5].title.text                = game.window_manager.window[window_number].choice_selection[0].data[2].value_string;
                    game.window_manager.window[window_number].element[6].title.text                = game.window_manager.window[window_number].choice_selection[0].data[3].value_string;
                    game.window_manager.window[window_number].element[7].title.text                = game.window_manager.window[window_number].choice_selection[0].data[4].value_string;
                }
            break;
            case 901: // Resolution right arrow button
                {
                    game.window_manager.window[window_number].choice_selection[0].position--;
                    if (game.window_manager.window[window_number].choice_selection[0].position < 0) game.window_manager.window[window_number].choice_selection[0].position = game.window_manager.window[window_number].choice_selection[0].position_max;
                    int         temp_data_value   = game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max-1].value_int;
                    bool        temp_data_bool    = game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max-1].active;
                    std::string temp_data_string  = game.window_manager.window[window_number].choice_selection[0].data[game.window_manager.window[window_number].choice_selection[0].position_max-1].value_string;
                    for (int data_position_count  = game.window_manager.window[window_number].choice_selection[0].position_max-1; data_position_count > 0;data_position_count--)
                    {
                        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].value_int    = game.window_manager.window[window_number].choice_selection[0].data[data_position_count-1].value_int;
                        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active       = game.window_manager.window[window_number].choice_selection[0].data[data_position_count-1].active;
                        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].value_string = game.window_manager.window[window_number].choice_selection[0].data[data_position_count-1].value_string;
                    }
                    game.window_manager.window[window_number].choice_selection[0].data[0].value_int    = temp_data_value;
                    game.window_manager.window[window_number].choice_selection[0].data[0].active       = temp_data_bool;
                    game.window_manager.window[window_number].choice_selection[0].data[0].value_string = temp_data_string;
                    game.window_manager.window[window_number].element[3].selected                  = game.window_manager.window[window_number].choice_selection[0].data[0].active;
                    game.window_manager.window[window_number].element[4].selected                  = game.window_manager.window[window_number].choice_selection[0].data[1].active;
                    game.window_manager.window[window_number].element[5].selected                  = game.window_manager.window[window_number].choice_selection[0].data[2].active;
                    game.window_manager.window[window_number].element[6].selected                  = game.window_manager.window[window_number].choice_selection[0].data[3].active;
                    game.window_manager.window[window_number].element[7].selected                  = game.window_manager.window[window_number].choice_selection[0].data[4].active;
                    game.window_manager.window[window_number].element[3].title.text                = game.window_manager.window[window_number].choice_selection[0].data[0].value_string;
                    game.window_manager.window[window_number].element[4].title.text                = game.window_manager.window[window_number].choice_selection[0].data[1].value_string;
                    game.window_manager.window[window_number].element[5].title.text                = game.window_manager.window[window_number].choice_selection[0].data[2].value_string;
                    game.window_manager.window[window_number].element[6].title.text                = game.window_manager.window[window_number].choice_selection[0].data[3].value_string;
                    game.window_manager.window[window_number].element[7].title.text                = game.window_manager.window[window_number].choice_selection[0].data[4].value_string;
                }
            break;
            case 1001: // Sound volume left arrow button
                game.core.config.audio_volume_sound--;
                if (game.core.config.audio_volume_sound < 0.0f) game.core.config.audio_volume_sound = 0.0f;
                game.window_manager.window[window_number].element[12].value = game.core.config.audio_volume_sound;
                Mix_Volume(-1,game.core.config.audio_volume_sound);
            break;
            case 1101: // Sound volume right arrow button
                game.core.config.audio_volume_sound++;
                if (game.core.config.audio_volume_sound > game.window_manager.window[window_number].element[12].value_max) game.core.config.audio_volume_sound = game.window_manager.window[window_number].element[12].value_max;
                game.window_manager.window[window_number].element[12].value = game.core.config.audio_volume_sound;
                Mix_Volume(-1,game.core.config.audio_volume_sound);
            break;
            case 1301: // Music volume left arrow button
                game.core.config.audio_volume_music--;
                if (game.core.config.audio_volume_music < 0.0f) game.core.config.audio_volume_music = 0.0f;
                game.window_manager.window[window_number].element[15].value = game.core.config.audio_volume_music;
                Mix_VolumeMusic(game.core.config.audio_volume_music);
            break;
            case 1401: // Music volume right arrow button
                game.core.config.audio_volume_music++;
                if (game.core.config.audio_volume_music > game.window_manager.window[window_number].element[15].value_max) game.core.config.audio_volume_music = game.window_manager.window[window_number].element[15].value_max;
                game.window_manager.window[window_number].element[15].value = game.core.config.audio_volume_music;
                Mix_VolumeMusic(game.core.config.audio_volume_music);
            break;
            case 1601: // Full screen button
            case 1701: // Full screen colored button
                if (game.core.config.display_fullscreen)
                {
                    int element_number = 17;
                    game.core.config.display_fullscreen                                     = false;
                    game.window_manager.window[window_number].element[element_number].value = 0.0f;
                    game.window_manager.window[window_number].element[element_number].texture.normal.image_path        = "data/textures/UI/menu/red_button.png";
                    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path   = "data/textures/UI/menu/red_button_highlighted.png";
                    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path      = "data/textures/UI/menu/green_button.png";
                    game.window_manager.window[window_number].element[element_number].texture.base.image_path          = "data/textures/UI/menu/green_button_highlighted.png";
                    reset_display = true;
                }
                else
                {
                    int element_number = 17;
                    game.core.config.display_fullscreen                                     = true;
                    game.window_manager.window[window_number].element[element_number].value = 1.0f;
                    game.window_manager.window[window_number].element[element_number].texture.normal.image_path      = "data/textures/UI/menu/green_button.png";
                    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/green_button_highlighted.png";
                    game.window_manager.window[window_number].element[element_number].texture.disabled.image_path    = "data/textures/UI/menu/red_button.png";
                    game.window_manager.window[window_number].element[element_number].texture.base.image_path        = "data/textures/UI/menu/red_button_highlighted.png";
                    reset_display = true;
                }
            break;
            default:
                game.core.log.file_write("Unable to process event - ",game.window_manager.window[window_number].event, " - UID - ",game.window_manager.window[window_number].UID);
                game.window_manager.window[window_number].event = 0;
            break;
        }
        if (resolution_selection)
        {
            int   temp_resolution      = 0;
            int   temp_resolution_x    = 0;
            int   temp_resolution_y    = 0;
            int   temp_data_value      = resolution_element;
            if (game.window_manager.window[window_number].choice_selection[0].data[temp_data_value].value_int != game.core.config.display_resolution)
            {
                temp_resolution      = game.core.config.display_resolution;
                temp_resolution_x    = game.core.config.display_resolution_x;
                temp_resolution_y    = game.core.config.display_resolution_y;
                game.core.config.display_resolution = game.window_manager.window[window_number].choice_selection[0].data[temp_data_value].value_int;
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
                    for (int data_position_count = 0; data_position_count < game.window_manager.window[window_number].choice_selection[0].position_max;data_position_count++)
                    {
                        game.window_manager.window[window_number].choice_selection[0].data[data_position_count].active = false;
                    }
                    game.window_manager.window[window_number].choice_selection[0].data[temp_data_value].active    = true;
                    game.window_manager.window[window_number].element[3].selected                  = false;
                    game.window_manager.window[window_number].element[4].selected                  = false;
                    game.window_manager.window[window_number].element[5].selected                  = false;
                    game.window_manager.window[window_number].element[6].selected                  = false;
                    game.window_manager.window[window_number].element[7].selected                  = false;
                    game.window_manager.window[window_number].element[temp_data_value+3].selected  = true;
                }
                reset_display = true;
            }
        }
        if (reset_display)
        {
            game.core.log.file_write("Reinitializing SDL...");
            game.core.graphics.init_sdl();
            game.core.log.file_write("Reinitializing OpenGL...");
            game.core.graphics.init_gl();
            game.loading_screen.display("data/loading_screen.png");
            game.core.log.file_write("Reloading resources....");
            game.UI.UI_reload_textures();
        }
    }
    game.window_manager.window[window_number].event = 0;
};
