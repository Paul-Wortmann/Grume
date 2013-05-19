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

#include "menu_main.hpp"
#include "../game.hpp"
#include "../core/misc.hpp"

extern game_class         game;

//----------------------------------------------------------Main menu Class ------------------------------------------------------------------------

void setup_character_window(int UID)
{
    int window_number = game.window_manager.window_get_number(UID);
    int element_number = 0;
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
    game.window_manager.window[window_number].texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/character_background.png");
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
    game.window_manager.window[window_number].title.text              = "Character";
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
    game.window_manager.window[window_number].number_of_elements = 7;
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
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    element_number = 1; //--- player portrait ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].click_enabled             = false;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = 0.129f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].element[element_number].size.x*1.5f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x / 3.73f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y / 4.02f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/character_portrait_frame.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/character_portrait_frame.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    element_number = 2; //--- Player Name ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "Name: ";
    game.window_manager.window[window_number].element[element_number].title.enabled               = true;
    game.window_manager.window[window_number].element[element_number].title.size.y                = 28;
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / 10.0f) * (float)game.window_manager.window[window_number].element[element_number].title.text.length();
    game.window_manager.window[window_number].element[element_number].title.position.x            = game.window_manager.window[window_number].position.x;// - (game.window_manager.window[window_number].size.x * 0.125f);
    game.window_manager.window[window_number].element[element_number].title.position.y            = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.32f);
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].click_enabled               = false;
    game.window_manager.window[window_number].element[element_number].type                        = TEXTLABEL;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].color.normal                = game.window_manager.window[window_number].element[element_number].color.highlighted;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.16f;
    game.window_manager.window[window_number].element[element_number].size.y                      = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].element[element_number].size.x)-(game.window_manager.window[window_number].size.x/2.0f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].element[element_number].size.y * 1.44f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 3; //--- Player Level ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "Level: ";
    game.window_manager.window[window_number].element[element_number].title.enabled               = true;
    game.window_manager.window[window_number].element[element_number].title.size.y                = 28;
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    game.window_manager.window[window_number].element[element_number].title.position.x            = game.window_manager.window[window_number].position.x;// - (game.window_manager.window[window_number].size.x * 0.125f);
    game.window_manager.window[window_number].element[element_number].title.position.y            = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.28f);
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].click_enabled               = false;
    game.window_manager.window[window_number].element[element_number].type                        = TEXTLABEL;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].color.normal                = game.window_manager.window[window_number].element[element_number].color.highlighted;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.16f;
    game.window_manager.window[window_number].element[element_number].size.y                      = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].element[element_number].size.x)-(game.window_manager.window[window_number].size.x/2.0f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].element[element_number].size.y * 1.44f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 4; //--- Player Experience ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "Exp: ";
    game.window_manager.window[window_number].element[element_number].title.enabled               = true;
    game.window_manager.window[window_number].element[element_number].title.size.y                = 28;
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    game.window_manager.window[window_number].element[element_number].title.position.x            = game.window_manager.window[window_number].position.x;// - (game.window_manager.window[window_number].size.x * 0.125f);
    game.window_manager.window[window_number].element[element_number].title.position.y            = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.24f);
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].click_enabled               = false;
    game.window_manager.window[window_number].element[element_number].type                        = TEXTLABEL;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].color.normal                = game.window_manager.window[window_number].element[element_number].color.highlighted;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.16f;
    game.window_manager.window[window_number].element[element_number].size.y                      = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].element[element_number].size.x)-(game.window_manager.window[window_number].size.x/2.0f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].element[element_number].size.y * 1.44f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 5; //--- Player Experience for next level ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "Next: ";
    game.window_manager.window[window_number].element[element_number].title.enabled               = true;
    game.window_manager.window[window_number].element[element_number].title.size.y                = 28;
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    game.window_manager.window[window_number].element[element_number].title.position.x            = game.window_manager.window[window_number].position.x;// - (game.window_manager.window[window_number].size.x * 0.125f);
    game.window_manager.window[window_number].element[element_number].title.position.y            = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.20f);
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].click_enabled               = false;
    game.window_manager.window[window_number].element[element_number].type                        = TEXTLABEL;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].color.normal                = game.window_manager.window[window_number].element[element_number].color.highlighted;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.16f;
    game.window_manager.window[window_number].element[element_number].size.y                      = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].element[element_number].size.x)-(game.window_manager.window[window_number].size.x/2.0f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].element[element_number].size.y * 1.44f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 6; //--- TEST INT VARIABLE OUTPUT ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "WINDOW: ";
    game.window_manager.window[window_number].element[element_number].title.enabled               = true;
    game.window_manager.window[window_number].element[element_number].title.size.y                = 28;
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    game.window_manager.window[window_number].element[element_number].title.position.x            = game.window_manager.window[window_number].position.x;// - (game.window_manager.window[window_number].size.x * 0.125f);
    game.window_manager.window[window_number].element[element_number].title.position.y            = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.0f);
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].click_enabled               = false;
    game.window_manager.window[window_number].element[element_number].type                        = TEXTLABEL;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].color.normal                = game.window_manager.window[window_number].element[element_number].color.highlighted;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.16f;
    game.window_manager.window[window_number].element[element_number].size.y                      = game.window_manager.window[window_number].element[element_number].size.x;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].element[element_number].size.x)-(game.window_manager.window[window_number].size.x/2.0f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].element[element_number].size.y * 1.44f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
};

void update_character_window(int UID)
{
    int window_number = game.window_manager.window_get_number(UID);
    int element_number = 1; //--- player portrait ---
    game.window_manager.window[window_number].element[element_number].texture.normal              = game.player.portrait;
    game.window_manager.window[window_number].element[element_number].texture.highlighted         = game.player.portrait;
    element_number = 2; //--- Player Name ---
    game.window_manager.window[window_number].element[element_number].title.text                  = "Name: " + game.player.name;
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    element_number = 3; //--- Player Level ---
    game.window_manager.window[window_number].element[element_number].title.text                  = "Level: " + int_to_string(game.player.level.current);
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    element_number = 4; //--- Player Experience ---
    game.window_manager.window[window_number].element[element_number].title.text                  = "Exp: " + ullint_to_string(game.player.level.current_experience);
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    element_number = 5; //--- Player Experience for next level ---
    game.window_manager.window[window_number].element[element_number].title.text                  = "Next: " + ullint_to_string(game.player.level.experience[game.player.level.current+1]);
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
    element_number = 6; //--- TEST INT VARIABLE OUTPUT ---
    game.window_manager.window[window_number].element[element_number].title.text                  = "test: " + ullint_to_string(game.test);
    game.window_manager.window[window_number].element[element_number].title.size.x                = ((float)game.window_manager.window[window_number].element[element_number].title.size.y / (float)game.window_manager.window[window_number].element[element_number].title.text.length()) * 4.5f;
};

void process_character_window(int window_number)
{
    update_character_window(CHARACTER_UID);
    if(game.window_manager.window[window_number].event.id > EVENT_NONE)
    {
        switch (game.window_manager.window[window_number].event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.window_manager.window_disable(CHARACTER_UID);
                game.core.character_active= false;
            break;
            case (EVENT_WINDOW_STACK_SORT): //Window stack sort
                game.window_manager.window_stack_sort();
                game.window_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.window_manager.source.window = CHARACTER_UID;
            break;
            case (EVENT_ELEMENT_DROP): //Element drop event posted
                //game.window_manager.destination.window = CHARACTER_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",game.window_manager.window[window_number].event.id, " - UID - ",game.window_manager.window[window_number].UID);
                game.window_manager.window[window_number].event.id = EVENT_NONE;
            break;
        }
    }
    game.window_manager.window[window_number].event.id = EVENT_NONE;
};





