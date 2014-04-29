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

#include "menu_options.hpp"
#include <string>
#include "../game/game.hpp"

extern game_class         game;

//----------------------------------------------------------

void setup_menu_options(int UID)
{
    int element_number = 0;
    UI_form_struct   *UI_form_pointer = game.UI_manager.UI_form_add(UID_MENU_OPTIONS);
    UI_form_pointer->data.UID                         = UID;
    UI_form_pointer->data.enabled                     = false;
    UI_form_pointer->data.mouse_over_menu             = false;
    UI_form_pointer->data.mouse_over_title            = false;
    UI_form_pointer->data.position.x                  = 0.0f;
    UI_form_pointer->data.position.y                  = -0.34f;
    UI_form_pointer->data.position.z                  = 0.0f;
    UI_form_pointer->data.size.x                      = 0.5f;
    UI_form_pointer->data.size.y                      = UI_form_pointer->data.size.x * 2.5f;
    UI_form_pointer->data.texture.angle               = 0.0f;
    UI_form_pointer->data.texture.enabled             = true;
    UI_form_pointer->data.texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/background_02.png");
    UI_form_pointer->data.texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/button_normal.png");
    UI_form_pointer->data.texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/button_highlighted.png");
    UI_form_pointer->data.texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/button_disabled.png");
    UI_form_pointer->data.sound.on_click.enabled      = true;
    UI_form_pointer->data.sound.on_click.sound        = game.sound_manager.add_sound("data/sound/menu/menu_select_00.wav");
    UI_form_pointer->data.sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.sound.on_mouse_over.sound   = game.sound_manager.add_sound("data/sound/menu/menu_move_00.wav");
    UI_form_pointer->data.font                        = game.font_manager.add_font("data/fonts/font_001.ttf");
    UI_form_pointer->data.mouse_delay.maximum         = 30;
    UI_form_pointer->data.event.id                    = 0;
    UI_form_pointer->data.color.normal.r              = 128;
    UI_form_pointer->data.color.normal.b              = 128;
    UI_form_pointer->data.color.normal.g              = 128;
    UI_form_pointer->data.color.normal.a              = 255;
    UI_form_pointer->data.color.highlighted.r         = 192;
    UI_form_pointer->data.color.highlighted.b         = 192;
    UI_form_pointer->data.color.highlighted.g         = 192;
    UI_form_pointer->data.color.highlighted.a         = 255;
    UI_form_pointer->data.color.disabled.r            = 064;
    UI_form_pointer->data.color.disabled.b            = 064;
    UI_form_pointer->data.color.disabled.g            = 064;
    UI_form_pointer->data.color.disabled.a            = 128;
    UI_form_pointer->data.zoom.enabled                = true;
    UI_form_pointer->data.zoom.maximum                = 0.02f;
    UI_form_pointer->data.zoom.speed                  = 0.004f;
    UI_form_pointer->data.texture.angle               = 0.0f;
    UI_form_pointer->data.texture.enabled             = true;
    UI_form_pointer->data.title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Options",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.title.enabled               = true;
    UI_form_pointer->data.title.size.x                = 0;//UI_form_pointer->data.title.text.length()/1.2f;
    UI_form_pointer->data.title.size.y                = 0;//UI_form_pointer->data.title.size.x*4;
    UI_form_pointer->data.title.position.x            = UI_form_pointer->data.position.x;
    UI_form_pointer->data.title.position.y            = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.24f);
    UI_form_pointer->data.title_bar.size.x            = UI_form_pointer->data.size.x; // x/2.0f for middle section
    UI_form_pointer->data.title_bar.size.y            = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.title_bar.position.x        = UI_form_pointer->data.position.x;
    UI_form_pointer->data.title_bar.position.y        = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.title_bar.size.y/2.0f);

    // ---------------------------- Setup window elements ----------------------------------------------------
    UI_form_pointer->data.number_of_elements = 25;
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
        UI_form_pointer->data.element[element_count].texture.enabled                = true;
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

    element_number = 1; //--- Background_frame_01 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.x/1.1f;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/5.6f;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x;//+(UI_form_pointer->data.size.x/2.0f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/3.5f);
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/frame_00.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/frame_00.png");
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;

    element_number = 2; //--- Main menu button ---
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
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;

// ------------------------------------------- Sound Volume ------------------------------------------------------------
    element_number = 3; // Sound volume selection left arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.maximum              = 0.01f;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*1.2f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*2.8f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 0.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 2;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 4; // Sound volume selection right arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.maximum              = 0.01f;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.0f)-(UI_form_pointer->data.element[element_number].size.x*1.2f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*2.8f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 180.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 2;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 5; // Sound volume selection - sound volume bar element
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Sound volume",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].value                       = game.core.config.audio_volume_sound;
    UI_form_pointer->data.element[element_number].value_max                   = 127.0f;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_BAR;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x / 100.f)*60.0f;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*2.8f);
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].title.size.x                = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.2f;
    UI_form_pointer->data.element[element_number].title.size.y                = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/60.0f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;

// ------------------------------------------- Music Volume ------------------------------------------------------------
    element_number = 6; // Music volume selection left arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.maximum              = 0.01f;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*1.2f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 0.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 5;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 7; // Music volume selection right arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.maximum              = 0.01f;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.0f)-(UI_form_pointer->data.element[element_number].size.x*1.2f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 180.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 5;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 8; // Music volume selection - music volume bar element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Music volume",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].value                     = game.core.config.audio_volume_music;
    UI_form_pointer->data.element[element_number].value_max                 = 127.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BAR;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*60.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/60.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;

// ------------------------------------------- Display Settings ------------------------------------------------------------
    element_number = 9; //--- Background_frame_02 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.x/1.1f;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.2f;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x;//+(UI_form_pointer->data.size.x/2.0f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/10.5f);
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/frame_00.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/frame_00.png");
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;

    element_number = 10; //--- Full screen button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    if (game.core.config.display_fullscreen)
    {
        UI_form_pointer->data.element[element_number].title.text            = game.texture_manager.add_texture(game.font_manager.root,"Disable Full Screen",0.8f,0,0,TEXTURE_STRING);
    }
    else
    {
        UI_form_pointer->data.element[element_number].title.text            = game.texture_manager.add_texture(game.font_manager.root,"Enable Full Screen",0.8f,0,0,TEXTURE_STRING);
    }
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*60.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 20.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/2.0f)+(UI_form_pointer->data.element[element_number].size.y*13.25f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;

    element_number   = 11; //--- Display resolution button 1 ---
    int display_mode = 0;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.1f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = true;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom                        = UI_form_pointer->data.zoom;
        UI_form_pointer->data.element[element_number].zoom.enabled                = true;
        UI_form_pointer->data.element[element_number].zoom.maximum                = 0.1f;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = true;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = true;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
        UI_form_pointer->data.element[element_number].texture.enabled             = false;
    }
    element_number = 12; //--- Display resolution button 2 ---
    display_mode   = 1;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.07f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 13; //--- Display resolution button 3 ---
    display_mode   = 2;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.04f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 14; //--- Display resolution button 4 ---
    display_mode   = 3;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.01f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 15; //--- Display resolution button 5 ---
    display_mode   = 4;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.02f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 16; //--- Display resolution button 6 ---
    display_mode   = 5;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.05f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 17; //--- Display resolution button 7 ---
    display_mode   = 6;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.08f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 18; //--- Display resolution button 8 ---
    display_mode   = 7;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.11f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 19; //--- Display resolution button 9 ---
    display_mode   = 8;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.14f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 20; //--- Display resolution button 10 ---
    display_mode   = 9;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.17f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 21; //--- Display resolution button 11 ---
    display_mode   = 10;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.2f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 22; //--- Display resolution button 12 ---
    display_mode   = 11;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.23f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 23; //--- Display resolution button 13 ---
    display_mode   = 12;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.26f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }
    element_number = 24; //--- Display resolution button 14 ---
    display_mode   = 13;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_number].element_UID                 = element_number;
        UI_form_pointer->data.element[element_number].title.text                  = new texture_type;
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].title.enabled               = true;
        UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x;
        UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.29f);
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
        UI_form_pointer->data.element[element_number].click_enabled               = false;
        UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_TEXTLABEL;
        UI_form_pointer->data.element[element_number].zoom.enabled                = false;
        UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
        UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
        UI_form_pointer->data.element[element_number].color.normal                = UI_form_pointer->data.element[element_number].color.highlighted;
        UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
        UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
        UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
        UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
        UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    }

};

void update_options_menu(void)
{
// ------------------------------------------- Display Settings ------------------------------------------------------------
    int element_number = 9; //--- Background_frame_02 ---
    UI_form_struct   *UI_form_pointer = game.UI_manager.UI_form_get(UID_MENU_OPTIONS);
    UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    element_number = 10; //--- Full screen button ---
    if (game.core.config.display_fullscreen)
    {
        UI_form_pointer->data.element[element_number].title.text            = game.texture_manager.add_texture(game.font_manager.root,"Disable Full Screen",0.8f,0,0,TEXTURE_STRING);
    }
    else
    {
        UI_form_pointer->data.element[element_number].title.text            = game.texture_manager.add_texture(game.font_manager.root,"Enable Full Screen",0.8f,0,0,TEXTURE_STRING);
    }
    element_number   = 11; //--- Display resolution button 1 ---
    int display_mode = 0;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 12; //--- Display resolution button 2 ---
    display_mode   = 1;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 13; //--- Display resolution button 3 ---
    display_mode   = 2;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 14; //--- Display resolution button 4 ---
    display_mode   = 3;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 15; //--- Display resolution button 5 ---
    display_mode   = 4;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 16; //--- Display resolution button 6 ---
    display_mode   = 5;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 17; //--- Display resolution button 7 ---
    display_mode   = 6;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 18; //--- Display resolution button 8 ---
    display_mode   = 7;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 19; //--- Display resolution button 9 ---
    display_mode   = 8;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 20; //--- Display resolution button 10 ---
    display_mode   = 9;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 21; //--- Display resolution button 11 ---
    display_mode   = 10;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 22; //--- Display resolution button 12 ---
    display_mode   = 11;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 23; //--- Display resolution button 13 ---
    display_mode   = 12;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
    element_number = 24; //--- Display resolution button 14 ---
    display_mode   = 13;
    if (game.core.graphics.menu_mode_length > display_mode)
    {
        if (game.core.config.display_resolution == game.core.graphics.menu_mode_list[display_mode])
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,255,255,255,255,TEXTURE_RENDER_CENTERED);
        }
        else
        {
            game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,game.core.graphics.get_display_mode(display_mode),0.8f,127,127,127,255,TEXTURE_RENDER_CENTERED);
        }
        UI_form_pointer->data.element[element_number].active                      = !game.core.config.display_fullscreen;
    }
}

void process_menu_options(UI_form_struct *UI_form_pointer)
{
    if (UI_form_pointer->data.event.id > EVENT_NONE)
    {
        bool update_display = false;
        update_options_menu();
        if (game.core.debug) game.core.log.file_write("Processing event - ",UI_form_pointer->data.event.id, " - UID - ",UI_form_pointer->data.UID, " - ",game.UI_manager.uid_to_string(UI_form_pointer->data.UID));
        switch (UI_form_pointer->data.event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.UI_manager.UI_form_transition(UID_MENU_OPTIONS,UID_MENU_MAIN);
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Main menu button
                game.UI_manager.UI_form_transition(UID_MENU_OPTIONS,UID_MENU_MAIN);
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Sound volume left arrow button
                game.core.config.audio_volume_sound--;
                if (game.core.config.audio_volume_sound < 0.0f) game.core.config.audio_volume_sound = 0.0f;
                UI_form_pointer->data.element[5].value = game.core.config.audio_volume_sound;
                Mix_Volume(-1,game.core.config.audio_volume_sound);
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Sound volume right arrow button
                game.core.config.audio_volume_sound++;
                if (game.core.config.audio_volume_sound > UI_form_pointer->data.element[5].value_max) game.core.config.audio_volume_sound = UI_form_pointer->data.element[5].value_max;
                UI_form_pointer->data.element[5].value = game.core.config.audio_volume_sound;
                Mix_Volume(-1,game.core.config.audio_volume_sound);
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Music volume left arrow button
                game.core.config.audio_volume_music--;
                if (game.core.config.audio_volume_music < 0.0f) game.core.config.audio_volume_music = 0.0f;
                UI_form_pointer->data.element[8].value = game.core.config.audio_volume_music;
                Mix_VolumeMusic(game.core.config.audio_volume_music);
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Music volume right arrow button
                game.core.config.audio_volume_music++;
                if (game.core.config.audio_volume_music > UI_form_pointer->data.element[8].value_max) game.core.config.audio_volume_music = UI_form_pointer->data.element[8].value_max;
                UI_form_pointer->data.element[8].value = game.core.config.audio_volume_music;
                Mix_VolumeMusic(game.core.config.audio_volume_music);
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Full screen button 1
                update_display = true;
                game.core.config.display_fullscreen = !game.core.config.display_fullscreen;
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 1
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[0]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[0]].h;
            break;
            case ((12*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 2
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[1]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[1]].h;
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 3
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[2]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[2]].h;
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 4
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[3]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[3]].h;
            break;
            case ((15*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 5
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[4]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[4]].h;
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 6
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[5]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[5]].h;
            break;
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 7
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[6]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[6]].h;
            break;
            case ((18*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 8
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[7]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[7]].h;
            break;
            case ((19*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 9
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[8]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[8]].h;
            break;
            case ((20*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 10
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[9]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[9]].h;
            break;
            case ((21*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 11
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[10]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[10]].h;
            break;
            case ((22*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 12
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[11]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[11]].h;
            break;
            case ((23*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 13
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[12]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[12]].h;
            break;
            case ((24*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection button 14
                update_display = true;
                game.core.config.display_resolution_x = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[13]].w;
                game.core.config.display_resolution_y = game.core.graphics.display_mode[game.core.graphics.menu_mode_list[13]].h;
            break;
            case (EVENT_UI_LIST_SORT): //Window stack sort
                UI_form_pointer->data.event.id   = EVENT_NONE;
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
            break;
            case (EVENT_UI_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = MENU_OPTIONS_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",UI_form_pointer->data.event.id, " - UID - ",UI_form_pointer->data.UID, " - ",game.UI_manager.uid_to_string(UI_form_pointer->data.UID));
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
        }
        if (update_display)
        {
            game.core.log.file_write("Reinitializing OpenGL...");
            game.core.graphics.init();
            game.core.io.mouse_button_left = false;
            game.loading_screen.display("data/loading_screen.png");
            game.texture_manager.reload_textures();
            update_menu_game_new(UID_MENU_GAME_NEW);
        }
    }
    if (UI_form_pointer->data.event.id != EVENT_NONE)
    {
        game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
        game.UI_manager.data.event.value = UI_form_pointer->data.UID;
    }
    UI_form_pointer->data.event.id = EVENT_NONE;
};
