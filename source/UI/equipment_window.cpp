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

extern game_class         game;

//----------------------------------------------------------Main menu Class ------------------------------------------------------------------------

void setup_equipment_window(int UID)
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
    game.window_manager.window[window_number].texture.base.image_path = "data/textures/UI/menu/equipment_background.png";
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
    game.window_manager.window[window_number].title.text              = "Equipment";
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
    game.window_manager.window[window_number].number_of_elements = 14;
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
    game.window_manager.window[window_number].element[element_number].texture.normal.image_path = "data/textures/UI/menu/close_button.png";
    game.window_manager.window[window_number].element[element_number].texture.normal.image.load_image(game.window_manager.window[window_number].element[element_number].texture.normal.image_path);
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path = "data/textures/UI/menu/close_button_highlighted.png";
    game.window_manager.window[window_number].element[element_number].texture.highlighted.image.load_image(game.window_manager.window[window_number].element[element_number].texture.highlighted.image_path);
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    element_number = 1; //--- Neck 1
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_NECK;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.050f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.085f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/4.72f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/4.66f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 2; //--- Neck 2
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_NECK;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.050f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.085f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/4.64f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/4.66f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 3; //--- Ring 1
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_RING;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.050f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.085f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/2.82f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/8.10f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 4; //--- Ring 2
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_RING;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.050f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.085f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.x/4.72f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/8.10f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 5; //--- Ring 3
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_RING;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.050f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.085f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/4.64f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/8.10f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 6; //--- Ring 4
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_RING;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.050f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.085f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.x/2.80f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/8.10f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 7; //--- Helm
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_HEAD;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.125f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.200f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/3.82f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 8; //--- Boots
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_FEET;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.125f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.200f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.y/8.85f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y-(game.window_manager.window[window_number].size.y/3.45f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 9; //--- Gloves
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_HAND;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.125f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.200f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.y/8.80f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y-(game.window_manager.window[window_number].size.y/3.45f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 10; //--- Belt
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_BELT;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.125f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.088f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y-(game.window_manager.window[window_number].size.y/4.10f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 11; //--- Body Armour
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_BODY;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.125f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.320f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y-(game.window_manager.window[window_number].size.y/16.20f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 12; //--- Off hand
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_SHIELD;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.125f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.320f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x-(game.window_manager.window[window_number].size.y/8.85f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y-(game.window_manager.window[window_number].size.y/16.20f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
    element_number = 13; //--- Weapon
    game.window_manager.window[window_number].element[element_number].window_UID                  = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID                 = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                  = "";
    game.window_manager.window[window_number].element[element_number].title.enabled               = false;
    game.window_manager.window[window_number].element[element_number].dragable                    = true;
    game.window_manager.window[window_number].element[element_number].active                      = true;
    game.window_manager.window[window_number].element[element_number].type                        = ITEM;
    game.window_manager.window[window_number].element[element_number].sub_type                    = ITEM_WEAPON;
    game.window_manager.window[window_number].element[element_number].zoom.enabled                = false;
    game.window_manager.window[window_number].element[element_number].value                       = -1;
    game.window_manager.window[window_number].element[element_number].color                       = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                      = 0.125f;
    game.window_manager.window[window_number].element[element_number].size.y                      = 0.320f;
    game.window_manager.window[window_number].element[element_number].position.x                  = game.window_manager.window[window_number].position.x+(game.window_manager.window[window_number].size.y/8.80f);
    game.window_manager.window[window_number].element[element_number].position.y                  = game.window_manager.window[window_number].position.y-(game.window_manager.window[window_number].size.y/16.20f);
    game.window_manager.window[window_number].element[element_number].sound                       = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].sound.on_click.enabled      = false;
    game.window_manager.window[window_number].element[element_number].sound.on_mouse_over.enabled = false;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum         = 30;
    game.window_manager.window[window_number].element[element_number].font                        = game.window_manager.window[window_number].font;
};

void process_equipment_window(int window_number)
{
    if(game.window_manager.window[window_number].event.id > EVENT_NONE)
    {
        switch (game.window_manager.window[window_number].event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.window_manager.window_disable(EQUIPMENT_UID);
                game.core.equipment_active= false;
            break;
            case (EVENT_WINDOW_STACK_SORT): //Window stack sort
                game.window_manager.window_stack_sort();
                game.window_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.window_manager.source.window = EQUIPMENT_UID;
            break;
            case (EVENT_ELEMENT_DROP): //Element drop event posted
                //game.window_manager.destination.window = EQUIPMENT_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",game.window_manager.window[window_number].event.id, " - UID - ",game.window_manager.window[window_number].UID);
                game.window_manager.window[window_number].event.id = EVENT_NONE;
            break;
        }
    }
    game.window_manager.window[window_number].event.id = EVENT_NONE;
};


/*

#define ITEM_NONE       30
#define ITEM_RING       31
#define ITEM_NECK       32
#define ITEM_HEAD       33
#define ITEM_HAND       34
#define ITEM_FEET       35
#define ITEM_BODY       36
#define ITEM_SHIELD     37
#define ITEM_WEAPON     38

#define ITEM_POTION     39
#define ITEM_SPELL      40
#define ITEM_SPELL_BOOK 41

*/


