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
#include "../game/game.hpp"
#include "../core/misc.hpp"

extern game_class         game;

//----------------------------------------------------------

void setup_action_bar(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = new UI_form_struct;
    UI_form_pointer = game.UI_manager.UI_form_add(UID_ACTIONBAR);

    int menu_button_mouse_delay = 20;
    UI_form_pointer->data.UID                         = UID;
    UI_form_pointer->data.enabled                     = false;
    UI_form_pointer->data.mouse_over_menu             = false;
    UI_form_pointer->data.mouse_over_title            = false;
    UI_form_pointer->data.drag_enabled                = false;
    UI_form_pointer->data.set_behind                  = true;
    UI_form_pointer->data.size.x                      =  1.8f;
    UI_form_pointer->data.size.y                      =  0.2f;
    UI_form_pointer->data.position.x                  =  0.0f;
    UI_form_pointer->data.position.y                  = -1.0f + (UI_form_pointer->data.size.y/2.0f)-0.012f;
    UI_form_pointer->data.position.z                  =  0.0f;
    UI_form_pointer->data.texture.angle               =  0.0f;
    UI_form_pointer->data.texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/action_bar.png");
    UI_form_pointer->data.texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/button_normal.png");
    UI_form_pointer->data.texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/button_highlighted.png");
    UI_form_pointer->data.texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/button_disabled.png");
    UI_form_pointer->data.sound.on_click.enabled      = false;
    UI_form_pointer->data.sound.on_click.sound        = game.sound_manager.add_sound("data/sound/menu/menu_select_00.wav");
    UI_form_pointer->data.sound.on_mouse_over.enabled = false;
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
    UI_form_pointer->data.zoom.enabled                = false;
    UI_form_pointer->data.zoom.maximum                = 0.02f;
    UI_form_pointer->data.zoom.speed                  = 0.004f;
    UI_form_pointer->data.texture.angle               = 0.0f;
    UI_form_pointer->data.title.text                  = NULL;
    UI_form_pointer->data.title.size.x                = 0;//UI_form_pointer->data.title.text.length()/1.2f;
    UI_form_pointer->data.title.size.y                = 0;//UI_form_pointer->data.title.size.x*4;
    UI_form_pointer->data.title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.title.size.x/100.0f);
    UI_form_pointer->data.title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y/2.0f) - (UI_form_pointer->data.title.size.y / 440.0f);
    UI_form_pointer->data.title_bar.size.x            = UI_form_pointer->data.size.x; // x/2.0f for middle section
    UI_form_pointer->data.title_bar.size.y            = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.title_bar.position.x        = UI_form_pointer->data.position.x;
    UI_form_pointer->data.title_bar.position.y        = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.title_bar.size.y/2.0f);

    // ---------------------------- Setup window elements ----------------------------------------------------
    UI_form_pointer->data.number_of_elements = 18;
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
    element_number = 0; //--- Experience bar image ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].click_enabled             = false;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BAR;
    UI_form_pointer->data.element[element_number].value                     = 0;
    UI_form_pointer->data.element[element_number].value_max                 = 1000;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = true;
    UI_form_pointer->data.element[element_number].tooltip.text              = new texture_type;
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,"0",0.8f,255,255,255,255);
    UI_form_pointer->data.element[element_number].tooltip.size.x            = 12.0f;
    UI_form_pointer->data.element[element_number].tooltip.size.y            = 30.0f;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                    = UI_form_pointer->data.size.x * 0.952f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y * 0.2f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;// - (UI_form_pointer->data.size.x * 0.25f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.38f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/experience_bar.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/experience_bar.png");
    UI_form_pointer->data.element[element_number].texture.normal->data.render_positioning = TEXTURE_RENDER_UP;
    UI_form_pointer->data.element[element_number].texture.highlighted->data.render_positioning = TEXTURE_RENDER_UP;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 1; //--- Action-bar foreground image ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].click_enabled             = false;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                    = UI_form_pointer->data.size.x;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y;
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/action_bar_front.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/action_bar_front.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    element_number = 2; //--- Action-bar main menu button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].title.enabled             = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = true;
    UI_form_pointer->data.element[element_number].tooltip.text              = new texture_type;
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,"Main Menu",0.8f,255,255,255,255,TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP);
    UI_form_pointer->data.element[element_number].tooltip.size.x            = 12.0f;
    UI_form_pointer->data.element[element_number].tooltip.size.y            = 30.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].size.x                    = 0.072f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.element[element_number].size.x;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x/2.0f) + (UI_form_pointer->data.element[element_number].size.x * 1.46f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y + (UI_form_pointer->data.element[element_number].size.y * 0.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/icon_01.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/icon_01.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = true;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 3; //--- Action-bar quest log button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].title.enabled             = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = true;
    UI_form_pointer->data.element[element_number].tooltip.text              = new texture_type;
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,"Quest Log",0.8f,255,255,255,255,TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP);
    UI_form_pointer->data.element[element_number].tooltip.size.x            = 12.0f;
    UI_form_pointer->data.element[element_number].tooltip.size.y            = 30.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].size.x                    = 0.072f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.element[element_number].size.x;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x/2.0f) + (UI_form_pointer->data.element[element_number].size.x * 2.85f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y + (UI_form_pointer->data.element[element_number].size.y * 0.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/icon_03.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/icon_03.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = true;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 4; //--- Action-bar skill book button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].title.enabled             = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = true;
    UI_form_pointer->data.element[element_number].tooltip.text              = new texture_type;
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,"Skill Book",0.8f,255,255,255,255,TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP);
    UI_form_pointer->data.element[element_number].tooltip.size.x            = 12.0f;
    UI_form_pointer->data.element[element_number].tooltip.size.y            = 30.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].size.x                    = 0.072f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.element[element_number].size.x;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x/2.0f) + (UI_form_pointer->data.element[element_number].size.x * 4.25f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y + (UI_form_pointer->data.element[element_number].size.y * 0.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/icon_06.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/icon_06.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = true;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 5; //--- Action-bar character window button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].title.enabled             = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = true;
    UI_form_pointer->data.element[element_number].tooltip.text              = new texture_type;
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,"Character",0.8f,255,255,255,255,TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP);
    UI_form_pointer->data.element[element_number].tooltip.size.x            = 12.0f;
    UI_form_pointer->data.element[element_number].tooltip.size.y            = 30.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].size.x                    = 0.072f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.element[element_number].size.x;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x/2.0f) - (UI_form_pointer->data.element[element_number].size.x * 4.25f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y + (UI_form_pointer->data.element[element_number].size.y * 0.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/icon_02.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/icon_02.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = true;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 6; //--- Action-bar equipment button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].title.enabled             = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = true;
    UI_form_pointer->data.element[element_number].tooltip.text              = new texture_type;
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,"Equipment",0.8f,255,255,255,255,TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP);
    UI_form_pointer->data.element[element_number].tooltip.size.x            = 12.0f;
    UI_form_pointer->data.element[element_number].tooltip.size.y            = 30.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].size.x                    = 0.072f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.element[element_number].size.x;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x/2.0f) - (UI_form_pointer->data.element[element_number].size.x * 2.85f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y + (UI_form_pointer->data.element[element_number].size.y * 0.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/icon_04.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/icon_04.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = true;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 7; //--- Action-bar inventory button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].title.enabled             = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = true;
    UI_form_pointer->data.element[element_number].tooltip.text              = new texture_type;
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,"Inventory",0.8f,255,255,255,255,TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP);
    UI_form_pointer->data.element[element_number].tooltip.size.x            = 12.0f;
    UI_form_pointer->data.element[element_number].tooltip.size.y            = 30.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].size.x                    = 0.072f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.element[element_number].size.x;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x/2.0f) - (UI_form_pointer->data.element[element_number].size.x * 1.46f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y + (UI_form_pointer->data.element[element_number].size.y * 0.1f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/icon_05.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/icon_05.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = true;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = true;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = menu_button_mouse_delay;
    element_number = 8; //--- Action-bar item 0 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/3.92f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 9; //--- Action-bar item 1 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/5.030f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 10; //--- Action-bar item 2 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/7.050f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 11; //--- Action-bar item 3 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/11.600f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 12; //--- Action-bar item 4 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/34.24f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 13; //--- Action-bar item 5 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/37.400f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 14; //--- Action-bar item 6 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/12.200f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 15; //--- Action-bar item 7 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/7.26f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 16; //--- Action-bar item 8 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/5.154f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.00f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 17; //--- Action-bar item 9 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].click_enabled               = true;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.y/2.35;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/2.25;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/3.98f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/20.0f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
};

/*
void update_action_bar(int window_number)
{
    // required function?
};
*/

void process_action_bar(UI_form_struct *UI_form_pointer)
{
    if (game.player.level.current < MAX_LEVELS)// exp bar
    {
        if (game.player.level.current_experience > 0)// && (game.player.level.experience[game.player.level.current] > 0))
        {
            int element_number = 0; //--- Player experience bar ---
            unsigned long long  temp_val = (game.player.level.current_experience - game.player.level.experience[game.player.level.current]);
            unsigned long long  temp_max = (game.player.level.experience[game.player.level.current+1] - game.player.level.experience[game.player.level.current]);
            int                 temp_per = (((float)temp_val / (float)temp_max) * UI_form_pointer->data.element[element_number].value_max);
            UI_form_pointer->data.element[element_number].value = temp_per;
            if (UI_form_pointer->data.element[element_number].mouse_over)
            {
                temp_per /= 10;
                std::string temp_string  = int_to_string(temp_per);
                temp_string += "%";
                game.texture_manager.load_string(UI_form_pointer->data.element[element_number].tooltip.text,game.font_manager.root,temp_string,0.8f,255,255,255,255,TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP);
            }
        }
    }
    if(UI_form_pointer->data.event.id > EVENT_NONE) // Handle element events
    {
        switch (UI_form_pointer->data.event.id)
        {
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle main menu
                game.UI_manager.UI_form_disable(UID_MENU_GAME_LOAD);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_NEW);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_SAVE);
                game.UI_manager.UI_form_disable(UID_MENU_OPTIONS);
                if (!game.core.game_menu_active)
                {
                    game.UI_manager.UI_form_enable(UID_MENU_MAIN);
                    game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                    game.UI_manager.data.event.value = UID_MENU_MAIN;
                    game.core.game_menu_active  = true;
                }
                else
                {
                    game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                    game.core.game_menu_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle quest log
                if (!game.core.quest_log_active)
                {
                    game.UI_manager.UI_form_enable(UID_QUEST_LOG);
                    game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                    game.UI_manager.data.event.value = UID_QUEST_LOG;
                    game.core.quest_log_active                   = true;
                }
                else
                {
                    game.UI_manager.UI_form_disable(UID_QUEST_LOG);
                    game.core.quest_log_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle skill book
                if (!game.core.skillbook_active)
                {
                    game.UI_manager.UI_form_enable(UID_SKILLBOOK);
                    game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                    game.UI_manager.data.event.value = UID_SKILLBOOK;
                    game.core.skillbook_active                   = true;
                }
                else
                {
                    game.UI_manager.UI_form_disable(UID_SKILLBOOK);
                    game.core.skillbook_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle Character menu
                if (!game.core.character_active)
                {
                    game.UI_manager.UI_form_enable(UID_CHARACTER);
                    game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                    game.UI_manager.data.event.value = UID_CHARACTER;
                    game.core.character_active                   = true;
                }
                else
                {
                    game.UI_manager.UI_form_disable(UID_CHARACTER);
                    game.core.character_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle equipment menu
                if (!game.core.equipment_active)
                {
                    game.UI_manager.UI_form_enable(UID_EQUIPMENT);
                    game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                    game.UI_manager.data.event.value = UID_EQUIPMENT;
                    game.core.equipment_active                   = true;
                }
                else
                {
                    game.UI_manager.UI_form_disable(UID_EQUIPMENT);
                    game.core.equipment_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Toggle Inventory menu
                if (!game.core.inventory_active)
                {
                    game.UI_manager.UI_form_enable(UID_INVENTORY);
                    game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                    game.UI_manager.data.event.value = UID_INVENTORY;
                    game.core.inventory_active                   = true;
                }
                else
                {
                    game.UI_manager.UI_form_disable(UID_INVENTORY);
                    game.core.inventory_active                   = false;
                }
                game.core.io.key_escape                = false;
                game.core.io.keyboard_delay_count      = 0;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,8);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,9);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,10);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,11);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((12*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((12*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,12);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,13);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,14);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((15*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((15*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,15);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,16);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                game.item_manager.use_item(UI_form_pointer,17);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case (EVENT_UI_LIST_SORT): //Window stack sort
                UI_form_pointer->data.event.id = EVENT_NONE;
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
            break;
            case (EVENT_UI_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = ACTIONBAR_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",UI_form_pointer->data.event.id, " - UID - ",UI_form_pointer->data.UID);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
        }
    }
    UI_form_pointer->data.event.id = EVENT_NONE;
};
