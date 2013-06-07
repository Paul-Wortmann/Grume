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

//----------------------------------------------------------

void setup_inventory_window(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = new UI_form_struct;
    UI_form_pointer = game.UI_manager.add_window(UID_MENU_MAIN);

    UI_form_pointer->UID                     = UID;
    UI_form_pointer->active                  = false;
    UI_form_pointer->mouse_over_menu         = false;
    UI_form_pointer->mouse_over_title        = false;
    UI_form_pointer->position.x              = 0.0f;
    UI_form_pointer->position.y              = 0.0f;
    UI_form_pointer->position.z              = 0.0f;
    UI_form_pointer->size.x                  = 0.5f;
    UI_form_pointer->size.y                  = UI_form_pointer->size.x * 2.5f;
    UI_form_pointer->texture.angle           = 0.0f;
    UI_form_pointer->texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/inventory_background.png");
    UI_form_pointer->texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/button_normal.png");
    UI_form_pointer->texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/button_highlighted.png");
    UI_form_pointer->texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/button_disabled.png");
    UI_form_pointer->sound.on_click.enabled      = true;
    UI_form_pointer->sound.on_click.sound        = game.sound_manager.add_sound("data/sound/menu/menu_select_00.wav");
    UI_form_pointer->sound.on_mouse_over.enabled = true;
    UI_form_pointer->sound.on_mouse_over.sound   = game.sound_manager.add_sound("data/sound/menu/menu_move_00.wav");
    UI_form_pointer->font                        = game.font_manager.add_font("data/fonts/font_001.ttf");
    UI_form_pointer->mouse_delay.maximum     = 30;
    UI_form_pointer->event.id                = 0;
    UI_form_pointer->color.normal.r          = 128;
    UI_form_pointer->color.normal.b          = 128;
    UI_form_pointer->color.normal.g          = 128;
    UI_form_pointer->color.normal.a          = 255;
    UI_form_pointer->color.highlighted.r     = 192;
    UI_form_pointer->color.highlighted.b     = 192;
    UI_form_pointer->color.highlighted.g     = 192;
    UI_form_pointer->color.highlighted.a     = 255;
    UI_form_pointer->color.disabled.r        = 064;
    UI_form_pointer->color.disabled.b        = 064;
    UI_form_pointer->color.disabled.g        = 064;
    UI_form_pointer->color.disabled.a        = 128;
    UI_form_pointer->zoom.enabled            = true;
    UI_form_pointer->zoom.maximum            = 0.02f;
    UI_form_pointer->zoom.speed              = 0.004f;
    UI_form_pointer->texture.angle           = 0.0f;
    UI_form_pointer->title.text              = "Inventory";
    UI_form_pointer->title.enabled           = true;
    UI_form_pointer->title.size.x            = UI_form_pointer->title.text.length()/1.2f;
    UI_form_pointer->title.size.y            = UI_form_pointer->title.size.x*4;
    UI_form_pointer->title.position.x        = UI_form_pointer->position.x - (UI_form_pointer->title.size.x/100.0f);
    UI_form_pointer->title.position.y        = UI_form_pointer->position.y + (UI_form_pointer->size.y/2.0f) - (UI_form_pointer->title.size.y / 380.0f);
    UI_form_pointer->title_bar.size.x        = UI_form_pointer->size.x; // x/2.0f for middle section
    UI_form_pointer->title_bar.size.y        = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->title_bar.position.x    = UI_form_pointer->position.x;
    UI_form_pointer->title_bar.position.y    = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->title_bar.size.y/2.0f);

    // ---------------------------- Setup window elements ----------------------------------------------------
    UI_form_pointer->number_of_elements = 49;
    UI_form_pointer->element = new UI_element_struct[UI_form_pointer->number_of_elements];
    for (int element_count = 0; element_count < UI_form_pointer->number_of_elements; element_count++)
    {
        UI_form_pointer->element[element_count].window_UID                     = 0;
        UI_form_pointer->element[element_count].element_UID                    = 0;
        UI_form_pointer->element[element_count].mouse_over                     = false;
        UI_form_pointer->element[element_count].mouse_delay.ready              = false;
        UI_form_pointer->element[element_count].mouse_delay.value              = 0;
        UI_form_pointer->element[element_count].mouse_delay.maximum            = 0;
        UI_form_pointer->element[element_count].mouse_delay.enabled            = true;
        UI_form_pointer->element[element_count].size.x                         = 0.0f;
        UI_form_pointer->element[element_count].size.y                         = 0.0f;
        UI_form_pointer->element[element_count].size.z                         = 0.0f;
        UI_form_pointer->element[element_count].position.x                     = 0.0f;
        UI_form_pointer->element[element_count].position.y                     = 0.0f;
        UI_form_pointer->element[element_count].position.z                     = 0.0f;
        UI_form_pointer->element[element_count].title.enabled                  = false;
        UI_form_pointer->element[element_count].title.text                     = "";
        UI_form_pointer->element[element_count].title.position.x               = 0.0f;
        UI_form_pointer->element[element_count].title.position.y               = 0.0f;
        UI_form_pointer->element[element_count].title.position.z               = 0.0f;
        UI_form_pointer->element[element_count].title.size.x                   = 0.0f;
        UI_form_pointer->element[element_count].title.size.y                   = 0.0f;
        UI_form_pointer->element[element_count].title.size.z                   = 0.0f;
        UI_form_pointer->element[element_count].tooltip.enabled                = false;
        UI_form_pointer->element[element_count].tooltip.text                   = "";
        UI_form_pointer->element[element_count].tooltip.position.x             = 0.0f;
        UI_form_pointer->element[element_count].tooltip.position.y             = 0.0f;
        UI_form_pointer->element[element_count].tooltip.position.z             = 0.0f;
        UI_form_pointer->element[element_count].tooltip.size.x                 = 0.0f;
        UI_form_pointer->element[element_count].tooltip.size.y                 = 0.0f;
        UI_form_pointer->element[element_count].tooltip.size.z                 = 0.0f;
        UI_form_pointer->element[element_count].tooltip.image_enabled          = false;
        UI_form_pointer->element[element_count].tooltip.image_size.x           = 0.0f;
        UI_form_pointer->element[element_count].tooltip.image_size.y           = 0.0f;
        UI_form_pointer->element[element_count].tooltip.image_size.z           = 0.0f;
        UI_form_pointer->element[element_count].color.normal.r                 = 0;
        UI_form_pointer->element[element_count].color.normal.g                 = 0;
        UI_form_pointer->element[element_count].color.normal.b                 = 0;
        UI_form_pointer->element[element_count].color.normal.a                 = 0;
        UI_form_pointer->element[element_count].color.highlighted.r            = 0;
        UI_form_pointer->element[element_count].color.highlighted.g            = 0;
        UI_form_pointer->element[element_count].color.highlighted.b            = 0;
        UI_form_pointer->element[element_count].color.highlighted.a            = 0;
        UI_form_pointer->element[element_count].color.disabled.r               = 0;
        UI_form_pointer->element[element_count].color.disabled.g               = 0;
        UI_form_pointer->element[element_count].color.disabled.b               = 0;
        UI_form_pointer->element[element_count].color.disabled.a               = 0;
        UI_form_pointer->element[element_count].event.id                       = 0;
        UI_form_pointer->element[element_count].state                          = NORMAL;
        UI_form_pointer->element[element_count].selected                       = false;
        UI_form_pointer->element[element_count].type                           = BUTTON;
        UI_form_pointer->element[element_count].sub_type                       = 0;//ITEM_NONE;// TEST
        UI_form_pointer->element[element_count].quantity                       = 1;
        UI_form_pointer->element[element_count].value                          = 0.0f;
        UI_form_pointer->element[element_count].value_max                      = 0.0f;
        UI_form_pointer->element[element_count].active                         = false;
        UI_form_pointer->element[element_count].clicked                        = false;
        UI_form_pointer->element[element_count].click_enabled                  = true;
        UI_form_pointer->element[element_count].dragable                       = false;
        UI_form_pointer->element[element_count].drag_active                    = false;
        UI_form_pointer->element[element_count].texture.angle                  = 0.0f;
        UI_form_pointer->element[element_count].zoom.enabled                   = true;
        UI_form_pointer->element[element_count].zoom.maximum                   = 0.0f;
        UI_form_pointer->element[element_count].zoom.value                     = 0.0f;
        UI_form_pointer->element[element_count].zoom.speed                     = 0.0f;
    }
    element_number = 0; //--- Close button ---
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = BUTTON;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.1f;
    UI_form_pointer->element[element_number].size.y                      = 0.1f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.0f)-(UI_form_pointer->element[element_number].size.x/1.8f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->title.position.y+(UI_form_pointer->element[element_number].size.y/8.0f);
    UI_form_pointer->element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/close_button.png");
    UI_form_pointer->element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/close_button_highlighted.png");
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 1; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/3.26f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 2; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/3.26f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 3; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/3.26f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 4; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/3.26f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 5; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/3.26f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 6; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/3.26f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;

    element_number = 7; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/4.66f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 8; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/4.66f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 9; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/4.66f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 10; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/4.66f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 11; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/4.66f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 12; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/4.66f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;

    element_number = 13; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/8.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 14; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/8.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 15; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/8.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 16; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/8.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 17; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/8.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 18; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/8.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;

    element_number = 19; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/32.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 20; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/32.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 21; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/32.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 22; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/32.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 23; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/32.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 24; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y+(UI_form_pointer->size.y/32.10f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;

    element_number = 25; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/16.80f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 26; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/16.80f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 27; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/16.80f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 28; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/16.80f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 29; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/16.80f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 30; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/16.80f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;

    element_number = 31; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/6.56f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 32; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/6.56f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 33; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/6.56f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 34; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/6.56f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 35; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/6.56f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 36; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/6.56f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;

    element_number = 37; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/4.08f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 38; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/4.08f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 39; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/4.08f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 40; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/4.08f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 41; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/4.08f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 42; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/4.08f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;

    element_number = 43; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.82f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/2.98f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 44; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/4.72f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/2.98f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 45; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x-(UI_form_pointer->size.x/14.62f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/2.98f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 46; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/14.02f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/2.98f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 47; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/4.64f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/2.98f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
    element_number = 48; //--- Inventory cell
    UI_form_pointer->element[element_number].window_UID                  = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID                 = element_number;
    UI_form_pointer->element[element_number].title.text                  = "";
    UI_form_pointer->element[element_number].title.enabled               = false;
    UI_form_pointer->element[element_number].dragable                    = true;
    UI_form_pointer->element[element_number].active                      = true;
    UI_form_pointer->element[element_number].type                        = ITEM;
    UI_form_pointer->element[element_number].zoom.enabled                = false;
    UI_form_pointer->element[element_number].tooltip.enabled             = false;
    UI_form_pointer->element[element_number].value                       = -1;
    UI_form_pointer->element[element_number].color                       = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                      = 0.050f;
    UI_form_pointer->element[element_number].size.y                      = 0.085f;
    UI_form_pointer->element[element_number].position.x                  = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.80f);
    UI_form_pointer->element[element_number].position.y                  = UI_form_pointer->position.y-(UI_form_pointer->size.y/2.98f);
    UI_form_pointer->element[element_number].sound                       = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->element[element_number].font                        = UI_form_pointer->font;
};

void process_inventory_window(UI_form_struct *UI_form_pointer)
{
    /*
    if (UI_form_pointer->event.id > EVENT_NONE)
    {
        switch (UI_form_pointer->event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.window_manager.window_disable(INVENTORY_UID);
                game.core.inventory_active     = false;
                game.core.io.mouse_button_left = false;
            break;
            case (EVENT_WINDOW_STACK_SORT): //Window stack sort
                game.window_manager.window_stack_sort();
                game.window_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.window_manager.source.window = INVENTORY_UID;
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,1);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,2);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,3);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,4);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,5);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,6);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,7);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,8);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,9);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,10);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,11);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((12*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((12*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,12);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,13);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,14);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((15*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((15*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,15);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,16);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,17);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((18*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((18*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,18);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((19*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((19*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,19);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((20*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((20*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,20);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((21*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((21*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,21);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((22*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((22*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,22);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((23*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((23*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,23);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((24*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((24*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,24);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((25*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((25*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,25);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((26*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((26*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,26);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((27*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((27*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,27);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((28*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((28*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,28);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((29*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((29*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,29);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((30*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((30*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,30);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((31*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((31*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,31);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((32*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((32*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,32);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((33*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((33*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,33);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((34*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((34*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,34);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((35*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((35*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,35);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((36*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((36*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,36);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((37*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((37*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,37);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((38*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((38*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,38);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((39*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((39*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,39);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((40*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((40*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,40);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((41*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((41*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,41);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((42*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((42*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,42);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((43*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((43*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,43);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((44*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((44*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,44);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((45*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((45*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,45);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((46*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((46*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,46);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((47*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((47*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,47);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((48*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Process item 0
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            case ((48*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_RIGHT): // Process item 0
                use_item(window_number,48);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",UI_form_pointer->event.id, " - UID - ",UI_form_pointer->UID);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
        }
    }
    UI_form_pointer->event.id = EVENT_NONE;
    */
};

