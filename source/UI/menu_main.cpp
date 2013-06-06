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

void setup_menu_main(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = new UI_form_struct;
    UI_form_pointer = game.UI_manager.add_window(UID_MENU_MAIN);

    UI_form_pointer->UID                         = UID;
    UI_form_pointer->active                      = false;
    UI_form_pointer->enabled                     = true;
    UI_form_pointer->mouse_over_menu             = false;
    UI_form_pointer->mouse_over_title            = false;
    UI_form_pointer->position.x                  = 0.0f;
    UI_form_pointer->position.y                  = 0.0f;
    UI_form_pointer->position.z                  = 0.0f;
    UI_form_pointer->size.x                      = 0.5f;
    UI_form_pointer->size.y                      = UI_form_pointer->size.x * 2.5f;
    UI_form_pointer->texture.angle               = 0.0f;
    UI_form_pointer->texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/background_02.png");
    UI_form_pointer->texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/button_normal.png");
    UI_form_pointer->texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/button_highlighted.png");
    UI_form_pointer->texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/button_disabled.png");
    UI_form_pointer->sound.on_click.enabled      = true;
    UI_form_pointer->sound.on_click.sound        = game.sound_manager.add_sound("data/sound/menu/menu_select_00.wav");
    UI_form_pointer->sound.on_mouse_over.enabled = true;
    UI_form_pointer->sound.on_mouse_over.sound   = game.sound_manager.add_sound("data/sound/menu/menu_move_00.wav");
    UI_form_pointer->font                        = game.font_manager.add_font("data/fonts/font_001.ttf");
    UI_form_pointer->mouse_delay.maximum         = 30;
    UI_form_pointer->event.id                    = 0;
    UI_form_pointer->color.normal.r              = 128;
    UI_form_pointer->color.normal.b              = 128;
    UI_form_pointer->color.normal.g              = 128;
    UI_form_pointer->color.normal.a              = 255;
    UI_form_pointer->color.highlighted.r         = 192;
    UI_form_pointer->color.highlighted.b         = 192;
    UI_form_pointer->color.highlighted.g         = 192;
    UI_form_pointer->color.highlighted.a         = 255;
    UI_form_pointer->color.disabled.r            = 064;
    UI_form_pointer->color.disabled.b            = 064;
    UI_form_pointer->color.disabled.g            = 064;
    UI_form_pointer->color.disabled.a            = 128;
    UI_form_pointer->zoom.enabled                = true;
    UI_form_pointer->zoom.maximum                = 0.02f;
    UI_form_pointer->zoom.speed                  = 0.004f;
    UI_form_pointer->texture.angle               = 0.0f;
    UI_form_pointer->title.text                  = "Main menu";
    UI_form_pointer->title.enabled               = true;
    UI_form_pointer->title_color.a               = 255;
    UI_form_pointer->title_color.r               = 255;
    UI_form_pointer->title_color.g               = 255;
    UI_form_pointer->title_color.b               = 255;
    UI_form_pointer->title.size.x                = UI_form_pointer->title.text.length()/1.2f;
    UI_form_pointer->title.size.y                = UI_form_pointer->title.size.x*4;
    UI_form_pointer->title.position.x            = UI_form_pointer->position.x - (UI_form_pointer->title.size.x/100.0f);
    UI_form_pointer->title.position.y            = UI_form_pointer->position.y + (UI_form_pointer->size.y/2.0f) - (UI_form_pointer->title.size.y / 380.0f);
    UI_form_pointer->title_bar.size.x            = UI_form_pointer->size.x; // x/2.0f for middle section
    UI_form_pointer->title_bar.size.y            = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->title_bar.position.x        = UI_form_pointer->position.x;
    UI_form_pointer->title_bar.position.y        = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->title_bar.size.y/2.0f);
    // ---------------------------- Setup window elements ----------------------------------------------------
    UI_form_pointer->number_of_elements = 7;
    UI_form_pointer->element = new UI_element_struct[UI_form_pointer->number_of_elements];
    for (int element_count = 0; element_count < UI_form_pointer->number_of_elements; element_count++)
    {
        UI_form_pointer->element[element_count].state                 = NORMAL;
    }
    element_number = 0; //--- Close button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].zoom.enabled              = false;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].size.x                    = 0.1f;
    UI_form_pointer->element[element_number].size.y                    = 0.1f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.0f)-(UI_form_pointer->element[element_number].size.x/1.8f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->title.position.y+(UI_form_pointer->element[element_number].size.y/8.0f);
    UI_form_pointer->element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/close_button.png");
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/close_button_highlighted.png");
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    element_number = 1; //--- new game button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "New Game";
    UI_form_pointer->element[element_number].title.enabled             = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*80.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x;
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.0f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;
    element_number = 2; //--- load game button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "Load Game";
    UI_form_pointer->element[element_number].title.enabled             = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*80.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x;
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*3.25f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;
    element_number = 3; //--- save game button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "Save Game";
    UI_form_pointer->element[element_number].title.enabled             = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].state                     = DISABLED;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*80.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x;
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*4.5f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;
    element_number = 4; //--- resume button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "Resume Game";
    UI_form_pointer->element[element_number].title.enabled             = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].state                     = DISABLED;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*80.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x;
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*5.75f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;
    element_number = 5; //--- options button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "Options";
    UI_form_pointer->element[element_number].title.enabled             = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*80.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x;
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*7.0f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.0f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;
    element_number = 6; //--- exit button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "Exit Game";
    UI_form_pointer->element[element_number].title.enabled             = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*80.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x;
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*9.0f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;
};

void process_menu_main(UI_form_struct *UI_form_pointer)
{
    int load_menu_number = 0;
    int element_number   = 0;
    /*
    if(UI_form_pointer->event.id > EVENT_NONE)
    {
        if (game.state == STATE_GAME) UI_form_pointer->element[3].state = NORMAL; // Save game
        else UI_form_pointer->element[3].state = DISABLED;
        if (game.state == STATE_GAME) UI_form_pointer->element[4].state = NORMAL; // Resume game
        else UI_form_pointer->element[4].state = DISABLED;
        switch (UI_form_pointer->event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                if (game.state == STATE_GAME)
                {
                    UI_form_pointer->enabled   = false;;
                }
                else
                {
                    game.state = STATE_QUIT;
                    UI_form_pointer->enabled   = false;;
                }
                game.core.game_menu_active     = false;
                game.core.io.mouse_button_left = false;
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // New game menu
                game.window_manager.window_transition(MENU_MAIN_UID,MENU_GAME_NEW_UID);
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Load game menu
                load_menu_number = game.window_manager.window_get_number(MENU_GAME_LOAD_UID);
                element_number   = 1;
                game.save_01.Assign_File("save/slot_01.sav");
                if (game.save_01.File_Exists()) game.window_manager.window[load_menu_number].element[element_number].state = NORMAL;
                else game.window_manager.window[load_menu_number].element[element_number].state = DISABLED;
                element_number   = 2;
                game.save_02.Assign_File("save/slot_02.sav");
                if (game.save_02.File_Exists()) game.window_manager.window[load_menu_number].element[element_number].state = NORMAL;
                else game.window_manager.window[load_menu_number].element[element_number].state = DISABLED;
                element_number   = 3;
                game.save_03.Assign_File("save/slot_03.sav");
                if (game.save_03.File_Exists()) game.window_manager.window[load_menu_number].element[element_number].state = NORMAL;
                else game.window_manager.window[load_menu_number].element[element_number].state = DISABLED;
                element_number   = 4;
                game.save_04.Assign_File("save/slot_04.sav");
                if (game.save_04.File_Exists()) game.window_manager.window[load_menu_number].element[element_number].state = NORMAL;
                else game.window_manager.window[load_menu_number].element[element_number].state = DISABLED;
                element_number   = 5;
                game.save_05.Assign_File("save/slot_05.sav");
                if (game.save_05.File_Exists()) game.window_manager.window[load_menu_number].element[element_number].state = NORMAL;
                else game.window_manager.window[load_menu_number].element[element_number].state = DISABLED;
                game.window_manager.window_transition(MENU_MAIN_UID,MENU_GAME_LOAD_UID);
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Save game menu
                game.window_manager.window_transition(MENU_MAIN_UID,MENU_GAME_SAVE_UID);
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resume Game
                if (game.state == STATE_GAME)
                {
                    game.window_manager.window_disable(MENU_MAIN_UID);
                    game.core.game_menu_active     = false;
                    game.core.io.mouse_button_left = false;
                }
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Options menu
                game.window_manager.window_transition(MENU_MAIN_UID,MENU_OPTIONS_UID);
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Exit button
                game.state = STATE_QUIT;
                game.window_manager.window_disable(MENU_MAIN_UID);
                game.core.game_menu_active     = false;
                game.core.io.mouse_button_left = false;
            break;
            case (EVENT_WINDOW_STACK_SORT): //Window stack sort
                game.window_manager.window_stack_sort();
                game.window_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.window_manager.source.window = MENU_MAIN_UID;
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





