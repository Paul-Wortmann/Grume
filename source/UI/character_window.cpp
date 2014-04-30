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

#include "menu_main.hpp"
#include "../game/game.hpp"
#include "../core/misc.hpp"

extern game_class         game;

//----------------------------------------------------------

void setup_character_window(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = game.UI_manager.UI_form_add(UID_CHARACTER);

    UI_form_pointer->data.UID                         = UID;
    UI_form_pointer->data.enabled                     = false;
    UI_form_pointer->data.mouse_over_menu             = false;
    UI_form_pointer->data.mouse_over_title            = false;
    UI_form_pointer->data.position.x                  = -0.735417f;
    UI_form_pointer->data.position.y                  = 0.26f;
    UI_form_pointer->data.position.z                  = 0.0f;
    UI_form_pointer->data.size.x                      = 0.5f;
    UI_form_pointer->data.size.y                      = UI_form_pointer->data.size.x * 2.5f;
    UI_form_pointer->data.texture.angle               = 0.0f;
    UI_form_pointer->data.texture.enabled             = true;
    UI_form_pointer->data.texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/character_background.png");
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
    UI_form_pointer->data.title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Character",0.8f,0,0,TEXTURE_STRING);
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
    UI_form_pointer->data.number_of_elements = 37;
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
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = 0.1f;
    UI_form_pointer->data.element[element_number].size.y                      = 0.1f;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.5f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.25f);
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/close_button.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/close_button_highlighted.png");
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 1; //--- player portrait ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].click_enabled               = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = 0.128f;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.element[element_number].size.x*1.5f;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x / 3.59f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y / 3.97f);
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/character_portrait_frame.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/character_portrait_frame.png");
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 2; //--- Player Name ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Name: ",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.1f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.32f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 3; //--- Player Level ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Level: ",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.1f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.30f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 4; //--- Player Experience ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Exp: ",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.1f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.28f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 5; //--- Player Experience for next level ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Next: ",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.1f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.26f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 6; //--- Player Strength ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Strength: ",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.1f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.24f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 7; //--- Player Intellect ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Intellect: ",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.1f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.22f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 8; //--- Player Dexterity ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Dexterity: ",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.1f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.20f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 9; //--- Damage Label---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Damage:",1.0f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.14f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 10; //--- Player Damage ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Damage: ",0.75f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.10f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 11; //--- Player Damage - max ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Max Damage: ",0.75f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.08f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 12; //--- Player Damage - min ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Min Damage: ",0.75f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.06f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 13; //--- Player Damage - critical chance ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Critical Chance: ",0.75f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.04f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 14; //--- Player Damage - critical damage ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Critical Damage: ",0.75f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.02f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 15; //--- Player Damage - fire ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Fire Damage: ",0.75f,0,0,255,127,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.00f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 16; //--- Player Damage - ice ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Ice Damage: ",0.75f,0,0,127,127,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.02f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 17; //--- Player Damage - lightning ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Lightning Damage: ",0.75f,0,0,255,255,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.04f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;

    element_number = 18; //--- Armor / Resistance Label---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Resistances:",1.00f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.14f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 19; //--- Player armor ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Armor: " + ullint_to_string(game.player.stats.armor),0.75f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.10f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 20; //--- Player resistance - physical ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Physical resistance: " + ullint_to_string(game.player.stats.resist_physical),0.75f,0,0,255,255,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.08f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 21; //--- Player resistance - fire ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Fire resistance: " + ullint_to_string(game.player.stats.resist_fire),0.75f,0,0,255,127,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.06f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 22; //--- Player resistance - ice ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Ice resistance: " + ullint_to_string(game.player.stats.resist_ice),0.75f,0,0,127,127,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.04f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 23; //--- Player resistance - lightning ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Lightning resistance: " + ullint_to_string(game.player.stats.resist_ice),0.75f,0,0,255,255,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.02f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;

    element_number = 24; //--- Player mana ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Mana: ",0.75f,0,0,127,127,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.14f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 25; //--- Player mana on hit---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Mana on hit: ",0.75f,0,0,127,127,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.16f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 26; //--- Player mana on kill---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Mana on kill: ",0.75f,0,0,127,127,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.18f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 27; //--- Player mana regen ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Mana regen: ",0.75f,0,0,127,127,255,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.20f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;

    element_number = 28; //--- Player health ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Health: ",0.75f,0,0,255,127,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.22f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 29; //--- Player health on hit---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Health on hit: ",0.75f,0,0,255,127,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.24f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 30; //--- Player health on kill---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Health on kill: ",0.75f,0,0,255,127,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.26f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 31; //--- Player health regen ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Health regen: ",0.75f,0,0,255,127,127,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.38f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.28f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 32; //--- Player magic find ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Magic find: ",0.75f,0,0,191,191,191,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.14f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 33; //--- Player gold find ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Gold find: ",0.75f,0,0,191,191,191,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.16f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 34; //--- Player light radius ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Light radius: ",0.75f,0,0,191,191,191,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.18f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 35; //--- Player movement speed ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Movement speed: ",0.75f,0,0,191,191,191,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.20f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
    element_number = 36; //--- Player epx per kill ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Exp per kill: ",0.75f,0,0,191,191,191,255,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x + (UI_form_pointer->data.size.x * 0.036f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y - (UI_form_pointer->data.size.y * 0.22f);
    UI_form_pointer->data.element[element_number].active                      = true;
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
    UI_form_pointer->data.element[element_number].texture.enabled             = false;
};

void update_character_window(UI_form_struct *UI_form_pointer)
{
    int element_number = 1; //--- player portrait ---
    UI_form_pointer->data.element[element_number].texture.normal              = game.player.portrait;
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.player.portrait;
    element_number = 2; //--- Player Name ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Name: " + game.player.name,0.8f,255,255,255,255,TEXTURE_RENDER_LEFT);
    element_number = 3; //--- Player Level ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Level: " + int_to_string(game.player.level.current),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 4; //--- Player Experience ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Exp: " + ullint_to_string(game.player.level.current_experience),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 5; //--- Player Experience for next level ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Next: " + ullint_to_string(game.player.level.experience[game.player.level.current+1]),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 6; //--- Player Strength ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Strength: " + ullint_to_string(game.player.stats.strength),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 7; //--- Player Intellect ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Intellect: " + ullint_to_string(game.player.stats.intellect),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 8; //--- Player Dexterity ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Dexterity: " + ullint_to_string(game.player.stats.dexterity),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);

    element_number = 10; //--- Player Damage ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Damage: " + ullint_to_string(game.player.stats.damage),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 11; //--- Player Damage - Max ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Maximum: " + ullint_to_string(game.player.stats.damage_max),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 12; //--- Player Damage - Min ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Minimum: " + ullint_to_string(game.player.stats.damage_max),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 13; //--- Player Damage - critical chance ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Crit Chance: " + ullint_to_string(game.player.stats.crit_chance),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 14; //--- Player Damage - critical damage ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Crit Damage: " + ullint_to_string(game.player.stats.crit_damage),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 15; //--- Player Damage - Fire ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Fire: " + ullint_to_string(game.player.stats.damage_max),0.75f,255,127,127,255,TEXTURE_RENDER_LEFT);
    element_number = 16; //--- Player Damage - Ice ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Ice: " + ullint_to_string(game.player.stats.damage_max),0.75f,127,127,255,255,TEXTURE_RENDER_LEFT);
    element_number = 17; //--- Player Damage - Lightning ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Lightning: " + ullint_to_string(game.player.stats.damage_max),0.75f,255,255,127,255,TEXTURE_RENDER_LEFT);

    element_number = 19; //--- Player armor ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Armor: " + ullint_to_string(game.player.stats.armor),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 20; //--- Player resistance - physical---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Physical: " + ullint_to_string(game.player.stats.resist_physical),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 21; //--- Player resistance - fire ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Fire: " + ullint_to_string(game.player.stats.resist_fire),0.75f,255,127,127,255,TEXTURE_RENDER_LEFT);
    element_number = 22; //--- Player resistance - ice ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Ice: " + ullint_to_string(game.player.stats.resist_ice),0.75f,127,127,255,255,TEXTURE_RENDER_LEFT);
    element_number = 23; //--- Player resistance - lightning ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Lightning: " + ullint_to_string(game.player.stats.resist_lightning),0.75f,255,255,127,255,TEXTURE_RENDER_LEFT);

    element_number = 24; //--- Player mana ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Mana: " + ullint_to_string(game.player.mana.maximum),0.75f,127,127,255,255,TEXTURE_RENDER_LEFT);
    element_number = 25; //--- Player mana on hit---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Mana on hit: " + ullint_to_string(game.player.stats.mana_hit),0.75f,127,127,255,255,TEXTURE_RENDER_LEFT);
    element_number = 26; //--- Player mana on kill---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Mana on kill: " + ullint_to_string(game.player.stats.mana_kill),0.75f,127,127,255,255,TEXTURE_RENDER_LEFT);
    element_number = 27; //--- Player mana regen ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Mana regen: " + ullint_to_string(game.player.mana.regeneration*1000),0.75f,127,127,255,255,TEXTURE_RENDER_LEFT);
    element_number = 28; //--- Player health ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Health: " + ullint_to_string(game.player.health.maximum),0.75f,255,127,127,255,TEXTURE_RENDER_LEFT);
    element_number = 29; //--- Player health on hit---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Health on hit: " + ullint_to_string(game.player.stats.health_hit),0.75f,255,127,127,255,TEXTURE_RENDER_LEFT);
    element_number = 30; //--- Player health on kill---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Health on kill: " + ullint_to_string(game.player.stats.health_kill),0.75f,255,127,127,255,TEXTURE_RENDER_LEFT);
    element_number = 31; //--- Player health regen ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Health regen: " + ullint_to_string(game.player.health.regeneration*1000),0.75f,255,127,127,255,TEXTURE_RENDER_LEFT);

    element_number = 32; //--- Player magic find ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Magic find: " + ullint_to_string(game.player.stats.magic_find),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 33; //--- Player gold find ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Gold find: " + ullint_to_string(game.player.stats.gold_find),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 34; //--- Player light radius ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Light radius: " + ullint_to_string(game.player.stats.light_radius),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 35; //--- Player movement speed ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Movement: " + ullint_to_string(game.player.stats.movement_speed),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
    element_number = 36; //--- Player epx per kill ---
    game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,"Exp per kill: " + ullint_to_string(game.player.stats.exp_per_kill),0.75f,191,191,191,255,TEXTURE_RENDER_LEFT);
};

void process_character_window(UI_form_struct *UI_form_pointer)
{
    update_character_window(UI_form_pointer);
    if(UI_form_pointer->data.event.id > EVENT_NONE)
    {
        switch (UI_form_pointer->data.event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.UI_manager.UI_form_disable(UID_CHARACTER);
                game.core.character_active     = false;
                game.core.io.mouse_button_left = false;
            break;
            case (EVENT_UI_LIST_SORT): //Window stack sort
                UI_form_pointer->data.event.id = EVENT_NONE;
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
            break;
            case (EVENT_UI_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = CHARACTER_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",UI_form_pointer->data.event.id, " - UID - ",UI_form_pointer->data.UID, " - ",game.UI_manager.uid_to_string(UI_form_pointer->data.UID));
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

/* --- note ---

edit character window, indent blocks to hold specific data, ie:
block 1 -> basic 3, Str, Int, Dex
block 2 -> damage, fire, ice, poison etc...
block 3 -> resistances - fire, ice, elec etc...
block 4 -> misc -  magic / gold find etc...

-----------------*/
