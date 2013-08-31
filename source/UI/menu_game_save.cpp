/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "menu_game_save.hpp"
#include "../game/game.hpp"

extern game_class         game;

//----------------------------------------------------------

void setup_menu_game_save(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = new UI_form_struct;
    UI_form_pointer = game.UI_manager.UI_form_add(UID_MENU_GAME_SAVE);

    UI_form_pointer->data.UID                     = UID;
    UI_form_pointer->data.enabled                 = false;
    UI_form_pointer->data.mouse_over_menu         = false;
    UI_form_pointer->data.mouse_over_title        = false;
    UI_form_pointer->data.position.x              = 0.0f;
    UI_form_pointer->data.position.y              = 0.0f;
    UI_form_pointer->data.position.z              = 0.0f;
    UI_form_pointer->data.size.x                  = 0.5f;
    UI_form_pointer->data.size.y                  = UI_form_pointer->data.size.x * 2.5f;
    UI_form_pointer->data.texture.angle           = 0.0f;
    UI_form_pointer->data.texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/background_02.png");
    UI_form_pointer->data.texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/button_normal.png");
    UI_form_pointer->data.texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/button_highlighted.png");
    UI_form_pointer->data.texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/button_disabled.png");
    UI_form_pointer->data.sound.on_click.enabled      = true;
    UI_form_pointer->data.sound.on_click.sound        = game.sound_manager.add_sound("data/sound/menu/menu_select_00.wav");
    UI_form_pointer->data.sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.sound.on_mouse_over.sound   = game.sound_manager.add_sound("data/sound/menu/menu_move_00.wav");
    UI_form_pointer->data.font                        = game.font_manager.add_font("data/fonts/font_001.ttf");
    UI_form_pointer->data.mouse_delay.maximum     = 30;
    UI_form_pointer->data.event.id                = 0;
    UI_form_pointer->data.color.normal.r          = 128;
    UI_form_pointer->data.color.normal.b          = 128;
    UI_form_pointer->data.color.normal.g          = 128;
    UI_form_pointer->data.color.normal.a          = 255;
    UI_form_pointer->data.color.highlighted.r     = 192;
    UI_form_pointer->data.color.highlighted.b     = 192;
    UI_form_pointer->data.color.highlighted.g     = 192;
    UI_form_pointer->data.color.highlighted.a     = 255;
    UI_form_pointer->data.color.disabled.r        = 064;
    UI_form_pointer->data.color.disabled.b        = 064;
    UI_form_pointer->data.color.disabled.g        = 064;
    UI_form_pointer->data.color.disabled.a        = 128;
    UI_form_pointer->data.zoom.enabled            = true;
    UI_form_pointer->data.zoom.maximum            = 0.02f;
    UI_form_pointer->data.zoom.speed              = 0.004f;
    UI_form_pointer->data.texture.angle           = 0.0f;
    UI_form_pointer->data.title.text              = game.texture_manager.add_texture(game.font_manager.root,"Save Game",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.title.enabled           = true;
    UI_form_pointer->data.title.size.x            = 0;//UI_form_pointer->data.title.text.length()/1.2f;
    UI_form_pointer->data.title.size.y            = 0;//UI_form_pointer->data.title.size.x*4;
    UI_form_pointer->data.title.position.x            = UI_form_pointer->data.position.x;
    UI_form_pointer->data.title.position.y            = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.24f);
    UI_form_pointer->data.title_bar.size.x        = UI_form_pointer->data.size.x; // x/2.0f for middle section
    UI_form_pointer->data.title_bar.size.y        = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.title_bar.position.x    = UI_form_pointer->data.position.x;
    UI_form_pointer->data.title_bar.position.y    = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.title_bar.size.y/2.0f);

    // ---------------------------- Setup window elements ----------------------------------------------------
    UI_form_pointer->data.number_of_elements = 7;
    UI_form_pointer->data.element = new UI_element_struct[UI_form_pointer->data.number_of_elements];
    for (int element_count = 0; element_count < UI_form_pointer->data.number_of_elements; element_count++)
    {
        UI_form_pointer->data.element[element_count].window_UID                     = 0;
        UI_form_pointer->data.element[element_count].element_UID                    = 0;
        UI_form_pointer->data.element[element_count].mouse_over                     = false;
        UI_form_pointer->data.element[element_count].mouse_delay.ready              = false;
        UI_form_pointer->data.element[element_count].mouse_delay.value              = 0;
        UI_form_pointer->data.element[element_count].mouse_delay.maximum            = 0;
        UI_form_pointer->data.element[element_count].mouse_delay.enabled            = true;
        UI_form_pointer->data.element[element_count].size.x                         = 0.0f;
        UI_form_pointer->data.element[element_count].size.y                         = 0.0f;
        UI_form_pointer->data.element[element_count].size.z                         = 0.0f;
        UI_form_pointer->data.element[element_count].overlay_enabled                = false;
        UI_form_pointer->data.element[element_count].position.x                     = 0.0f;
        UI_form_pointer->data.element[element_count].position.y                     = 0.0f;
        UI_form_pointer->data.element[element_count].position.z                     = 0.0f;
        UI_form_pointer->data.element[element_count].title.enabled                  = false;
        UI_form_pointer->data.element[element_count].title.text                     = NULL;
        UI_form_pointer->data.element[element_count].title.position.x               = 0.0f;
        UI_form_pointer->data.element[element_count].title.position.y               = 0.0f;
        UI_form_pointer->data.element[element_count].title.position.z               = 0.0f;
        UI_form_pointer->data.element[element_count].title.size.x                   = 0.0f;
        UI_form_pointer->data.element[element_count].title.size.y                   = 0.0f;
        UI_form_pointer->data.element[element_count].title.size.z                   = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.enabled                = false;
        UI_form_pointer->data.element[element_count].tooltip.text                   = NULL;
        UI_form_pointer->data.element[element_count].tooltip.position.x             = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.position.y             = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.position.z             = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.size.x                 = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.size.y                 = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.size.z                 = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.image_enabled          = false;
        UI_form_pointer->data.element[element_count].tooltip.image_size.x           = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.image_size.y           = 0.0f;
        UI_form_pointer->data.element[element_count].tooltip.image_size.z           = 0.0f;
        UI_form_pointer->data.element[element_count].color.normal.r                 = 0;
        UI_form_pointer->data.element[element_count].color.normal.g                 = 0;
        UI_form_pointer->data.element[element_count].color.normal.b                 = 0;
        UI_form_pointer->data.element[element_count].color.normal.a                 = 0;
        UI_form_pointer->data.element[element_count].color.highlighted.r            = 0;
        UI_form_pointer->data.element[element_count].color.highlighted.g            = 0;
        UI_form_pointer->data.element[element_count].color.highlighted.b            = 0;
        UI_form_pointer->data.element[element_count].color.highlighted.a            = 0;
        UI_form_pointer->data.element[element_count].color.disabled.r               = 0;
        UI_form_pointer->data.element[element_count].color.disabled.g               = 0;
        UI_form_pointer->data.element[element_count].color.disabled.b               = 0;
        UI_form_pointer->data.element[element_count].color.disabled.a               = 0;
        UI_form_pointer->data.element[element_count].event.id                       = 0;
        UI_form_pointer->data.element[element_count].state                          = UI_NORMAL;
        UI_form_pointer->data.element[element_count].selected                       = false;
        UI_form_pointer->data.element[element_count].type                           = UI_ELEMENT_BUTTON;
        UI_form_pointer->data.element[element_count].sub_type                       = ITEM_NONE;
        UI_form_pointer->data.element[element_count].quantity                       = 1;
        UI_form_pointer->data.element[element_count].value                          = 0.0f;
        UI_form_pointer->data.element[element_count].value_max                      = 0.0f;
        UI_form_pointer->data.element[element_count].active                         = false;
        UI_form_pointer->data.element[element_count].clicked                        = false;
        UI_form_pointer->data.element[element_count].click_enabled                  = true;
        UI_form_pointer->data.element[element_count].dragable                       = false;
        UI_form_pointer->data.element[element_count].drag_active                    = false;
        UI_form_pointer->data.element[element_count].texture.angle                  = 0.0f;
        UI_form_pointer->data.element[element_count].zoom.enabled                   = true;
        UI_form_pointer->data.element[element_count].zoom.maximum                   = 0.0f;
        UI_form_pointer->data.element[element_count].zoom.value                     = 0.0f;
        UI_form_pointer->data.element[element_count].zoom.speed                     = 0.0f;
    }
    element_number = 0; //--- Close button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                    = 0.1f;
    UI_form_pointer->data.element[element_number].size.y                    = 0.1f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.5f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.25f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/close_button.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/close_button_highlighted.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 1; //--- Save Game 1 ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Save Slot 1",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*80.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*2.0f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.0f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/70.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 2; //--- Save Game 2 ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Save Slot 2",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*80.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*3.25f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.0f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/70.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 3; //--- Save Game 3 ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Save Slot 3",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*80.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.5f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.0f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/70.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 4; //--- Save Game 4 ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Save Slot 4",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*80.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*5.75f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.0f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/70.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 5; //--- Save Game 5 ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Save Slot 5",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*80.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*7.0f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.0f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/70.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 6; //--- Main Menu button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Main Menu",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*80.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*9.0f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
};

void process_menu_game_save(UI_form_struct *UI_form_pointer)
{
    if(UI_form_pointer->data.event.id > EVENT_NONE)
    {
        switch (UI_form_pointer->data.event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_SAVE,UID_MENU_MAIN);
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Save slot 1 - menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_SAVE,UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active = false;
                game.save_01.Assign_File("save/slot_01.sav");
                if (game.save_01.Save())
                {
                    game.core.log.file_write("Game saved to slot 1");
                }
                else game.core.log.file_write("ERROR -> Error saving game to slot 1");
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Save slot 2 - menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_SAVE,UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active = false;
                game.save_02.Assign_File("save/slot_02.sav");
                if (game.save_02.Save())
                {
                    game.core.log.file_write("Game saved to slot 2");
                }
                else game.core.log.file_write("ERROR -> Error saving game to slot 2");
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Save slot 3 - menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_SAVE,UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active = false;
                game.save_03.Assign_File("save/slot_03.sav");
                if (game.save_03.Save())
                {
                    game.core.log.file_write("Game saved to slot 3");
                }
                else game.core.log.file_write("ERROR -> Error saving game to slot 3");
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Save slot 4 - menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_SAVE,UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active = false;
                game.save_04.Assign_File("save/slot_04.sav");
                if (game.save_04.Save())
                {
                    game.core.log.file_write("Game saved to slot 4");
                }
                else game.core.log.file_write("ERROR -> Error saving game to slot 4");
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Save slot 5 - menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_SAVE,UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active = false;
                game.save_05.Assign_File("save/slot_05.sav");
                if (game.save_05.Save())
                {
                    game.core.log.file_write("Game saved to slot 5");
                }
                else game.core.log.file_write("ERROR -> Error saving game to slot 5");
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Main menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_SAVE,UID_MENU_MAIN);
            break;
            case (EVENT_UI_LIST_SORT): //Window stack sort
                UI_form_pointer->data.event.id = EVENT_NONE;
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
            break;
            case (EVENT_UI_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = UID_MENU_GAME_SAVE;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",UI_form_pointer->data.event.id, " - UID - ",UI_form_pointer->data.UID);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
        }
    }
    if (UI_form_pointer->data.event.id != EVENT_NONE)
    {
        game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
        game.UI_manager.data.event.value = UI_form_pointer->data.UID;
    }
    UI_form_pointer->data.event.id = EVENT_NONE;
};






