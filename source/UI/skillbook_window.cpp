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

extern game_class         game;

//----------------------------------------------------------

void setup_skillbook_window(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = game.UI_manager.UI_form_add(UID_SKILLBOOK);

    UI_form_pointer->data.UID                         = UID;
    UI_form_pointer->data.enabled                     = false;
    UI_form_pointer->data.mouse_over_menu             = false;
    UI_form_pointer->data.mouse_over_title            = false;
    UI_form_pointer->data.position.x                  = 0.739583f;
    UI_form_pointer->data.position.y                  = 0.26f;
    UI_form_pointer->data.position.z                  = 0.001f;
    UI_form_pointer->data.size.x                      = 0.5f;
    UI_form_pointer->data.size.y                      = UI_form_pointer->data.size.x * 2.5f;
    UI_form_pointer->data.texture.angle               = 0.0f;
    UI_form_pointer->data.texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/skill_book_background.png");
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
    UI_form_pointer->data.title.text                  = game.texture_manager.add_texture(game.font_manager.root,"SkillBook",0.8f,0,0,TEXTURE_STRING);
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
    UI_form_pointer->data.number_of_elements = 21;
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
    UI_form_pointer->data.element[element_number].title.enabled             = false;
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
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    element_number = 1; //--- Spell slot 1
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_ARROW_FIRE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/3.06f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/3.62f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 2; //--- Spell slot 2
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_ARROW_ICE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/10.06f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/3.62f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/ice-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/ice-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-7-blue.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 3; //--- Spell slot 3
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_ARROW_LIGHTNING;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/8.16f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/3.62f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/lightning-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/lightning-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-5-orange.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 4; //--- Spell slot 4
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_ARROW_ELEMENTAL;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.86f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/3.62f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/beam-royal-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/beam-royal-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-8-eerie.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 5; //--- Spell slot 5
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_BALL_FIRE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/3.08f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/8.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fireball-red-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fireball-red-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 6; //--- Spell slot 6
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_BALL_ICE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/10.10f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/8.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fireball-sky-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fireball-sky-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-7-blue.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 7; //--- Spell slot 7
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_BALL_LIGHTNING;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/8.00f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/8.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/light-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/light-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-5-orange.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 8; //--- Spell slot 8
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_BALL_ELEMENTAL;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.84f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/8.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/explosion-royal-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/explosion-royal-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-8-eerie.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 9; //--- Spell slot 9
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/3.08f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/24.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 10; //--- Spell slot 10
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/10.10f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/24.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 11; //--- Spell slot 11
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/8.00f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/24.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 12; //--- Spell slot 12
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.84f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/24.32f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 13; //--- Spell slot 13
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_SHIELD_FIRE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/3.08f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/5.06f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-red-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-red-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 14; //--- Spell slot 14
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_SHIELD_ICE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/10.10f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/5.06f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-blue-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-7-blue.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 15; //--- Spell slot 15
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_SHIELD_LIGHTNING;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/8.00f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/5.06f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-sky-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-sky-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-5-orange.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 16; //--- Spell slot 16
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_SHIELD_ELEMENTAL;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.84f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/5.06f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-acid-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-acid-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-8-eerie.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 17; //--- Spell slot 17
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_SPELL_HEAL;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/3.08f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/2.78f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/heal-royal-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/heal-royal-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-9-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 18; //--- Spell slot 18
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/10.10f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/2.78f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 19; //--- Spell slot 19
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/8.00f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/2.78f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    element_number = 20; //--- Spell slot 16
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.text                  = NULL;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].title.image                 = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_form_pointer->data.element[element_number].title.image->data.render_positioning = TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN;
    UI_form_pointer->data.element[element_number].dragable                    = true;
    UI_form_pointer->data.element[element_number].active                      = false;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_ITEM;
    UI_form_pointer->data.element[element_number].sub_type                    = ITEM_SPELL;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].value                       = ITEM_NONE;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = (UI_form_pointer->data.size.x/6.2f);
    UI_form_pointer->data.element[element_number].size.y                      = (UI_form_pointer->data.size.y/9.3f);
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.84f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y-(UI_form_pointer->data.size.y/2.78f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].overlay_enabled             = true;
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    UI_form_pointer->data.element[element_number].texture.overlay             = game.texture_manager.add_texture("data/textures/UI/icons/spells/frame-3-red.png");
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
};

void process_skillbook_item(UI_form_struct *UI_form_pointer,int element_number)
{
    //item_type* item_pointer = new item_type;
    //item_pointer = NULL;
    UI_form_struct *UI_form_pointer_AB = game.UI_manager.UI_form_get(UID_ACTIONBAR);
    if ((UI_form_pointer->data.element[element_number].type == UI_ELEMENT_ITEM) && (UI_form_pointer->data.element[element_number].value != ITEM_NONE))
    {
        bool element_found   = false;
        int  dest_UI_element = 0;
        //item_pointer = game.item_manager.add_item(UI_form_pointer->data.element[element_number].value);
        for (int element_count = UI_form_pointer_AB->data.number_of_elements; element_count > 0; element_count--)
        {
            if ((!element_found) && (UI_form_pointer_AB->data.element[element_count].type == UI_ELEMENT_ITEM) && (UI_form_pointer_AB->data.element[element_count].value == ITEM_NONE))
            {
                game.UI_manager.swap_equipment(UID_SKILLBOOK,element_number,UID_ACTIONBAR);
                element_found      = true;
                dest_UI_element = element_count;
            }
        }
        if (element_found)
        {
            UI_form_pointer_AB->data.element[dest_UI_element].overlay_enabled = true;
            UI_form_pointer_AB->data.element[dest_UI_element].value           = UI_form_pointer->data.element[element_number].value;
            UI_form_pointer_AB->data.element[dest_UI_element].quantity        = UI_form_pointer->data.element[element_number].quantity;
            UI_form_pointer_AB->data.element[dest_UI_element].texture.normal  = UI_form_pointer->data.element[element_number].texture.normal;
            UI_form_pointer_AB->data.element[dest_UI_element].texture.overlay = UI_form_pointer->data.element[element_number].texture.overlay;
        }
    }
}

void process_skillbook_window(UI_form_struct *UI_form_pointer)
{
    int element_number = 1;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.arrow_fire;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 2;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.arrow_ice;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 3;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.arrow_lightning;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 4;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.arrow_elemental;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 5;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.ball_fire;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 6;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.ball_ice;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 7;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.ball_lightning;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 8;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.ball_elemental;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;

    element_number = 13;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.shield_fire;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 14;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.shield_ice;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 15;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.shield_lightning;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 16;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.shield_elemental;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;
    element_number = 17;
    UI_form_pointer->data.element[element_number].quantity = game.player.spells.heal;
    if (UI_form_pointer->data.element[element_number].quantity > 0) UI_form_pointer->data.element[element_number].active = true;


    if(UI_form_pointer->data.event.id > EVENT_NONE)
    {
        switch (UI_form_pointer->data.event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.UI_manager.UI_form_disable(UID_SKILLBOOK);
                game.core.skillbook_active     = false;
                game.core.io.mouse_button_left = false;
            break;
            case (EVENT_UI_LIST_SORT): //Window stack sort
                UI_form_pointer->data.event.id = EVENT_NONE;
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
            break;
            case (EVENT_UI_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = SKILLBOOK_UID;
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,1);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,2);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,3);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,4);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,5);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,6);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,7);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,8);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,9);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,10);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,11);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((12*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((12*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,12);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,13);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,14);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((15*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((15*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,15);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,16);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,17);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((18*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((18*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,18);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((19*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((19*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,19);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((20*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
            case ((20*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                process_skillbook_item(UI_form_pointer,20);
                UI_form_pointer->data.event.id = EVENT_NONE;
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





