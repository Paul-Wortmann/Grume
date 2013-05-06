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

#include "action_bar.hpp"
#include "../game.hpp"
#include "../core/misc.hpp"

extern game_class         game;

void setup_action_bar(int UID)
{
    int menu_button_mouse_delay = 20;
    int window_number = game.window_manager.window_get_number(UID);
    int element_number = 0;
    game.window_manager.window[window_number].UID                     = UID;
    game.window_manager.window[window_number].active                  = false;
    game.window_manager.window[window_number].mouse_over_menu         = false;
    game.window_manager.window[window_number].mouse_over_title        = false;
    game.window_manager.window[window_number].drag_enabled            = false;
    game.window_manager.window[window_number].set_behind              = true;
    game.window_manager.window[window_number].size.x                  =  1.8f;
    game.window_manager.window[window_number].size.y                  =  0.2f;
    game.window_manager.window[window_number].position.x              =  0.0f;
    game.window_manager.window[window_number].position.y              = -1.0f + (game.window_manager.window[window_number].size.y/2.0f)-0.012f;
    game.window_manager.window[window_number].position.z              =  0.0f;
    game.window_manager.window[window_number].texture.angle           =  0.0f;
    game.window_manager.window[window_number].texture.base.image_path = "data/textures/UI/menu/action_bar.png";
    game.window_manager.window[window_number].texture.base.image.load_image(game.window_manager.window[window_number].texture.base.image_path);
    game.window_manager.window[window_number].texture.normal.image_path = "data/textures/UI/menu/button_normal.png";
    game.window_manager.window[window_number].texture.normal.image.load_image(game.window_manager.window[window_number].texture.normal.image_path);
    game.window_manager.window[window_number].texture.highlighted.image_path = "data/textures/UI/menu/button_highlighted.png";
    game.window_manager.window[window_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].texture.disabled.image_path = "data/textures/UI/menu/button_disabled.png";
    game.window_manager.window[window_number].texture.disabled.image.load_image(game.window_manager.window[window_number].texture.disabled.image_path);
    game.window_manager.window[window_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].sound.on_click.sound_path   = "data/sound/menu/menu_select_00.wav";
    game.window_manager.window[window_number].sound.on_click.sound.load(game.window_manager.window[window_number].sound.on_click.sound_path);
    game.window_manager.window[window_number].sound.on_mouse_over.enabled      = false;
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
    game.window_manager.window[window_number].zoom.enabled            = false;
    game.window_manager.window[window_number].zoom.maximum            = 0.02f;
    game.window_manager.window[window_number].zoom.speed              = 0.004f;
    game.window_manager.window[window_number].texture.angle           = 0.0f;
    game.window_manager.window[window_number].title.text              = "";
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
    element_number = 0; //--- Experience bar image ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].click_enabled             = false;
    game.window_manager.window[window_number].element[element_number].type                      = BAR;
    game.window_manager.window[window_number].element[element_number].value                     = 0;
    game.window_manager.window[window_number].element[element_number].value_max                 = 1000;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "0%";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = game.window_manager.window[window_number].size.x * 0.952f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y * 0.2f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;// - (game.window_manager.window[window_number].size.x * 0.25f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y - (game.window_manager.window[window_number].size.y * 0.38f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/experience_bar.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/experience_bar.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 1; //--- Action-bar foreground image ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].click_enabled             = false;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = game.window_manager.window[window_number].size.x;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y;
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/action_bar_front.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/action_bar_front.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 2; //--- Action-bar main menu button ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "Main Menu";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.072f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].size.x/2.0f) + (game.window_manager.window[window_number].element[element_number].size.x * 1.46f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].element[element_number].size.y * 0.1f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/icon_01.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/icon_01.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = true;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = true;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 3; //--- Action-bar quest log button ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "Quest Log";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.072f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].size.x/2.0f) + (game.window_manager.window[window_number].element[element_number].size.x * 2.85f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].element[element_number].size.y * 0.1f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/icon_03.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/icon_03.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = true;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = true;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 4; //--- Action-bar skill book button ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "Skill Book";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.072f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].size.x/2.0f) + (game.window_manager.window[window_number].element[element_number].size.x * 4.25f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].element[element_number].size.y * 0.1f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/icon_06.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/icon_06.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = true;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = true;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 5; //--- Action-bar character window button ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "Character";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.072f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x + (game.window_manager.window[window_number].size.x/2.0f) - (game.window_manager.window[window_number].element[element_number].size.x * 4.25f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].element[element_number].size.y * 0.1f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/icon_02.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/icon_02.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = true;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = true;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 6; //--- Action-bar equipment button ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "Equipment";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.072f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x + (game.window_manager.window[window_number].size.x/2.0f) - (game.window_manager.window[window_number].element[element_number].size.x * 2.85f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].element[element_number].size.y * 0.1f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/icon_04.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/icon_04.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = true;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = true;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 7; //--- Action-bar inventory button ---
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "Inventory";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BUTTON;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].zoom                      = game.window_manager.window[window_number].zoom;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.072f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x + (game.window_manager.window[window_number].size.x/2.0f) - (game.window_manager.window[window_number].element[element_number].size.x * 1.46f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].element[element_number].size.y * 0.1f);
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/icon_05.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/icon_05.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled    = true;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = true;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;

};

/*
void update_action_bar(int window_number)
{
    // required function?
};
*/

void process_action_bar(int window_number)
{
    if (game.player.level.current < MAX_LEVELS)// exp bar
    {
        if (game.player.level.current_experience > 0)// && (game.player.level.experience[game.player.level.current] > 0))
        {
            int element_number = 0; //--- Player experience bar ---
            unsigned long long  temp_val = (game.player.level.current_experience - game.player.level.experience[game.player.level.current]);
            unsigned long long  temp_max = (game.player.level.experience[game.player.level.current+1] - game.player.level.experience[game.player.level.current]);
            int                 temp_per = (((float)temp_val / (float)temp_max) * game.window_manager.window[window_number].element[element_number].value_max);
            game.window_manager.window[window_number].element[element_number].value = temp_per;
            temp_per /= 10;
            std::string temp_string  = int_to_string(temp_per);
            temp_string += "%";
            if (temp_per >  9) temp_string += ' ';
            if (temp_per > 99) temp_string += ' ';
            temp_string += "    ";
            game.window_manager.window[window_number].element[element_number].tooltip.text = temp_string;
        }
    }
    if(game.window_manager.window[window_number].event.id > EVENT_NONE) // Handle element events
    {
        switch (game.window_manager.window[window_number].event.id)
        {
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle main menu
                if (!game.core.game_menu_active)
                {
                    game.window_manager.window_enable(MENU_MAIN_UID);
                    game.core.game_menu_active                   = true;
                }
                else
                {
                    game.window_manager.window_disable(MENU_MAIN_UID);
                    game.core.game_menu_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle quest log
                if (!game.core.quest_log_active)
                {
                    game.window_manager.window_enable(QUEST_LOG_UID);
                    game.core.quest_log_active                   = true;
                }
                else
                {
                    game.window_manager.window_disable(QUEST_LOG_UID);
                    game.core.quest_log_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle skill book
                if (!game.core.skillbook_active)
                {
                    game.window_manager.window_enable(SKILLBOOK_UID);
                    game.core.skillbook_active                   = true;
                }
                else
                {
                    game.window_manager.window_disable(SKILLBOOK_UID);
                    game.core.skillbook_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle Character menu
                if (!game.core.character_active)
                {
                    game.window_manager.window_enable(CHARACTER_UID);
                    game.core.character_active                   = true;
                }
                else
                {
                    game.window_manager.window_disable(CHARACTER_UID);
                    game.core.character_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle equipment menu
                if (!game.core.equipment_active)
                {
                    game.window_manager.window_enable(EQUIPMENT_UID);
                    game.core.equipment_active                   = true;
                }
                else
                {
                    game.window_manager.window_disable(EQUIPMENT_UID);
                    game.core.equipment_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle Inventory menu
                if (!game.core.inventory_active)
                {
                    game.window_manager.window_enable(INVENTORY_UID);
                    game.core.inventory_active                   = true;
                }
                else
                {
                    game.window_manager.window_disable(INVENTORY_UID);
                    game.core.inventory_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case (EVENT_WINDOW_STACK_SORT): //Window stack sort
                game.window_manager.window_stack_sort();
                game.window_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.window_manager.source.window = ACTIONBAR_UID;
            break;
            case (EVENT_ELEMENT_DROP): //Element drop event posted
                //game.window_manager.destination.window = ACTIONBAR_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",game.window_manager.window[window_number].event.id, " - UID - ",game.window_manager.window[window_number].UID);
                game.window_manager.window[window_number].event.id = EVENT_NONE;
            break;
        }
    }
    game.window_manager.window[window_number].event.id = EVENT_NONE;
};
