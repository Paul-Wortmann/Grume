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

#include "menu_game_new.hpp"
#include "../game.hpp"

extern game_class         game;

//----------------------------------------------------------

void setup_menu_game_new(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = new UI_form_struct;
    UI_form_pointer = game.UI_manager.UI_form_add(UID_MENU_GAME_NEW);

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
    UI_form_pointer->texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/background_02.png");
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
    UI_form_pointer->title.text              = "New Game";
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
    UI_form_pointer->number_of_elements = 10;
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
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].title.enabled             = false;
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
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;

    element_number = 1; //--- Main menu button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "Main Menu";
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

    element_number = 2; //--- Start game menu button ---
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "Start Game";
    UI_form_pointer->element[element_number].title.enabled             = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*80.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x;
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*7.5f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 30;

//----------------------------------------------------------------------------------------------------------------------
    UI_form_pointer->number_of_choice_selections = 1;
    UI_form_pointer->choice_selection = new choice_selection_type[UI_form_pointer->number_of_choice_selections];
    for (int choice_selection_count = 0; choice_selection_count < UI_form_pointer->number_of_choice_selections; choice_selection_count++)
    {
        UI_form_pointer->choice_selection[choice_selection_count].selected     = 0;
        UI_form_pointer->choice_selection[choice_selection_count].position     = 0;
        UI_form_pointer->choice_selection[choice_selection_count].position_max = 0;
        UI_form_pointer->choice_selection[choice_selection_count].number_of_data = 13;
        UI_form_pointer->choice_selection[choice_selection_count].data = new selection_data_type[UI_form_pointer->choice_selection[choice_selection_count].number_of_data];
        for (int data_count = 0; data_count < UI_form_pointer->choice_selection[choice_selection_count].number_of_data; data_count++)
        {
            UI_form_pointer->choice_selection[choice_selection_count].data[data_count].active       = false;
            UI_form_pointer->choice_selection[choice_selection_count].data[data_count].value_int    = 0;
            UI_form_pointer->choice_selection[choice_selection_count].data[data_count].value_string = "";
        }
    }
    int choice_selection_number = 0;

    UI_form_pointer->choice_selection[choice_selection_number].selected         = 0; // Player portrait selection
    UI_form_pointer->choice_selection[choice_selection_number].position         = 0;
    UI_form_pointer->choice_selection[choice_selection_number].position_max     = 12;
    for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
    {
        UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active = false;
    }
    UI_form_pointer->choice_selection[choice_selection_number].data[ 0].active     = true;
    UI_form_pointer->choice_selection[choice_selection_number].data[ 0].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_00.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 1].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_01.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 2].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_02.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 3].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_03.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 4].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_04.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 5].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_05.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 6].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_06.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 7].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_07.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 8].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_08.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[ 9].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_09.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[10].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_10.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[11].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_11.png");
    UI_form_pointer->choice_selection[choice_selection_number].data[12].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_12.png");
    game.player.portrait = UI_form_pointer->choice_selection[choice_selection_number].data[ 0].image;

    element_number = 3; // left arrow button for player portrait selection
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*10.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.0f)+(UI_form_pointer->element[element_number].size.x*1.0f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.0f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->element[element_number].texture.angle             = 0.0f;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 10;

    element_number = 4; // Right arrow button for player portrait selection
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = BUTTON;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*10.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x+(UI_form_pointer->size.x/2.0f)-(UI_form_pointer->element[element_number].size.x*1.0f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.0f);
    UI_form_pointer->element[element_number].texture                   = UI_form_pointer->texture;
    UI_form_pointer->element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->element[element_number].texture.angle             = 180.0f;
    UI_form_pointer->element[element_number].title.size.x              = UI_form_pointer->element[element_number].title.text.length()/1.2f;
    UI_form_pointer->element[element_number].title.size.y              = UI_form_pointer->element[element_number].title.size.x*4;;
    UI_form_pointer->element[element_number].title.position.x          = UI_form_pointer->element[element_number].position.x-(UI_form_pointer->element[element_number].title.size.x/100.0f);
    UI_form_pointer->element[element_number].title.position.y          = UI_form_pointer->element[element_number].position.y-(UI_form_pointer->element[element_number].title.size.y/1480.0f);
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 10;

    element_number = 5; // Image 0 of the player portrait selection
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].selected                  = true;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = IMAGE;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*10.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.0f)+(UI_form_pointer->element[element_number].size.x*2.5f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.00f);
    UI_form_pointer->element[element_number].texture.normal            = UI_form_pointer->choice_selection[choice_selection_number].data[0].image;
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 10;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;

    element_number = 6; // Image 1 of the player portrait selection
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].selected                  = false;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = IMAGE;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*10.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.0f)+(UI_form_pointer->element[element_number].size.x*3.75f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.00f);
    UI_form_pointer->element[element_number].texture.normal            = UI_form_pointer->choice_selection[choice_selection_number].data[1].image;
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 10;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;

    element_number = 7; // Image 2 of the player portrait selection
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].selected                  = false;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = IMAGE;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*10.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.0f)+(UI_form_pointer->element[element_number].size.x*5.0f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.00f);
    UI_form_pointer->element[element_number].texture.normal            = UI_form_pointer->choice_selection[choice_selection_number].data[2].image;
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 10;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;

    element_number = 8; // Image 3 of the player portrait selection
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].selected                  = false;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = IMAGE;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*10.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.0f)+(UI_form_pointer->element[element_number].size.x*6.25f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.00f);
    UI_form_pointer->element[element_number].texture.normal            = UI_form_pointer->choice_selection[choice_selection_number].data[3].image;
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 10;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;

    element_number = 9; // Image 4 of the player portrait selection
    UI_form_pointer->element[element_number].window_UID                = UI_form_pointer->UID;
    UI_form_pointer->element[element_number].element_UID               = element_number;
    UI_form_pointer->element[element_number].title.text                = "";
    UI_form_pointer->element[element_number].selected                  = false;
    UI_form_pointer->element[element_number].active                    = true;
    UI_form_pointer->element[element_number].type                      = IMAGE;
    UI_form_pointer->element[element_number].color                     = UI_form_pointer->color;
    UI_form_pointer->element[element_number].zoom                      = UI_form_pointer->zoom;
    UI_form_pointer->element[element_number].tooltip.enabled           = false;
    UI_form_pointer->element[element_number].size.x                    = (UI_form_pointer->size.x / 100.f)*10.0f;
    UI_form_pointer->element[element_number].size.y                    = UI_form_pointer->size.y / 10.0f;
    UI_form_pointer->element[element_number].position.x                = UI_form_pointer->position.x-(UI_form_pointer->size.x/2.0f)+(UI_form_pointer->element[element_number].size.x*7.5f);
    UI_form_pointer->element[element_number].position.y                = UI_form_pointer->position.y+(UI_form_pointer->size.y/2.0f)-(UI_form_pointer->element[element_number].size.y*2.00f);
    UI_form_pointer->element[element_number].texture.normal            = UI_form_pointer->choice_selection[choice_selection_number].data[4].image;
    UI_form_pointer->element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->element[element_number].sound                     = UI_form_pointer->sound;
    UI_form_pointer->element[element_number].mouse_delay.maximum       = 10;
    UI_form_pointer->element[element_number].font                      = UI_form_pointer->font;
};

void update_menu_game_new(int UID)
{
    int element_number          = 0;
    int choice_selection_number = 0;
    UI_form_struct *UI_form_pointer;
    UI_form_pointer = game.UI_manager.UI_form_get(UID);
    element_number = 5; // Image 0 of the player portrait selection
    UI_form_pointer->element[element_number].texture.normal      = UI_form_pointer->choice_selection[choice_selection_number].data[element_number-5].image;
    UI_form_pointer->element[element_number].texture.highlighted = UI_form_pointer->element[element_number].texture.highlighted;
    element_number = 6; // Image 1 of the player portrait selection
    UI_form_pointer->element[element_number].texture.normal      = UI_form_pointer->choice_selection[choice_selection_number].data[element_number-5].image;
    UI_form_pointer->element[element_number].texture.highlighted = UI_form_pointer->element[element_number].texture.highlighted;
    element_number = 7; // Image 2 of the player portrait selection
    UI_form_pointer->element[element_number].texture.normal      = UI_form_pointer->choice_selection[choice_selection_number].data[element_number-5].image;
    UI_form_pointer->element[element_number].texture.highlighted = UI_form_pointer->element[element_number].texture.highlighted;
    element_number = 8; // Image 3 of the player portrait selection
    UI_form_pointer->element[element_number].texture.normal      = UI_form_pointer->choice_selection[choice_selection_number].data[element_number-5].image;
    UI_form_pointer->element[element_number].texture.highlighted = UI_form_pointer->element[element_number].texture.highlighted;
    element_number = 9; // Image 4 of the player portrait selection
    UI_form_pointer->element[element_number].texture.normal      = UI_form_pointer->choice_selection[choice_selection_number].data[element_number-5].image;
    UI_form_pointer->element[element_number].texture.highlighted = UI_form_pointer->element[element_number].texture.highlighted;
};

void process_menu_game_new(UI_form_struct *UI_form_pointer)
{
    int choice_selection_number = 0;
    texture_type *temp_data_texture;
    bool temp_data_bool = false;
    if(UI_form_pointer->event.id > EVENT_NONE)
    {
        switch (UI_form_pointer->event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_NEW,UID_MENU_MAIN);
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Main menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_NEW,UID_MENU_MAIN);
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Start game menu button
                switch (game.state)
                {
                    case STATE_MENU:
                    break;
                    case STATE_GAME:
                        game.init();
                    break;
                    default:
                        game.init();
                    break;
                }
                game.state = STATE_GAME;
                game.music_manager.next_track = true;
                game.UI_manager.UI_form_transition(UID_MENU_GAME_NEW,UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active = false;
                game.UI_manager.UI_form_disable(UID_EQUIPMENT);
                game.core.equipment_active = false;
                game.UI_manager.UI_form_disable(UID_QUEST_LOG);
                game.core.quest_log_active = false;
                game.UI_manager.UI_form_disable(UID_CHARACTER);
                game.core.character_active = false;
                game.UI_manager.UI_form_disable(UID_INVENTORY);
                game.core.inventory_active = false;
                game.UI_manager.UI_form_disable(UID_SKILLBOOK);
                game.core.skillbook_active = false;
                game.UI_manager.UI_form_disable(UID_NPCVENDOR);
                game.core.npcvendor_active = false;
                game.UI_manager.UI_form_enable(UID_PCPROFILE);
                game.UI_manager.UI_form_set_active(UID_PCPROFILE);
                game.UI_manager.UI_form_enable(UID_ACTIONBAR);
                game.UI_manager.UI_form_set_active(UID_ACTIONBAR);
                UI_form_pointer->element[3].state = NORMAL; // Save game
                UI_form_pointer->element[4].state = NORMAL; // Resume game
                //set player portrait
                for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
                {
                    if (UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active)
                    {
                        game.player.portrait = UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].image;
                    };
                }
                update_player_profile  (game.UI_manager.UI_form_get(UID_PCPROFILE));
                update_character_window(game.UI_manager.UI_form_get(UID_CHARACTER));
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // left arrow button for player portrait selection
                UI_form_pointer->choice_selection[choice_selection_number].position++;
                if (UI_form_pointer->choice_selection[choice_selection_number].position > UI_form_pointer->choice_selection[choice_selection_number].position_max+1) UI_form_pointer->choice_selection[choice_selection_number].position = 0;
                temp_data_texture      = UI_form_pointer->choice_selection[choice_selection_number].data[0].image;
                temp_data_bool         = UI_form_pointer->choice_selection[choice_selection_number].data[0].active;
                for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
                {
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].image      = UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count+1].image;
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active     = UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count+1].active;
                }
                UI_form_pointer->choice_selection[choice_selection_number].data[UI_form_pointer->choice_selection[choice_selection_number].position_max].image      = temp_data_texture;
                UI_form_pointer->choice_selection[choice_selection_number].data[UI_form_pointer->choice_selection[choice_selection_number].position_max].active     = temp_data_bool;
                UI_form_pointer->element[5].texture.normal              = UI_form_pointer->choice_selection[choice_selection_number].data[0].image;
                UI_form_pointer->element[6].texture.normal              = UI_form_pointer->choice_selection[choice_selection_number].data[1].image;
                UI_form_pointer->element[7].texture.normal              = UI_form_pointer->choice_selection[choice_selection_number].data[2].image;
                UI_form_pointer->element[8].texture.normal              = UI_form_pointer->choice_selection[choice_selection_number].data[3].image;
                UI_form_pointer->element[9].texture.normal              = UI_form_pointer->choice_selection[choice_selection_number].data[4].image;
                UI_form_pointer->element[5].selected                    = UI_form_pointer->choice_selection[choice_selection_number].data[0].active;
                UI_form_pointer->element[6].selected                    = UI_form_pointer->choice_selection[choice_selection_number].data[1].active;
                UI_form_pointer->element[7].selected                    = UI_form_pointer->choice_selection[choice_selection_number].data[2].active;
                UI_form_pointer->element[8].selected                    = UI_form_pointer->choice_selection[choice_selection_number].data[3].active;
                UI_form_pointer->element[9].selected                    = UI_form_pointer->choice_selection[choice_selection_number].data[4].active;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Right arrow button for player portrait selection
                UI_form_pointer->choice_selection[choice_selection_number].position--;
                if (UI_form_pointer->choice_selection[choice_selection_number].position < 0) UI_form_pointer->choice_selection[choice_selection_number].position = UI_form_pointer->choice_selection[choice_selection_number].position_max;
                temp_data_texture      = UI_form_pointer->choice_selection[choice_selection_number].data[UI_form_pointer->choice_selection[choice_selection_number].position_max-1].image;
                temp_data_bool         = UI_form_pointer->choice_selection[choice_selection_number].data[UI_form_pointer->choice_selection[choice_selection_number].position_max-1].active;
                for (int data_position_count = UI_form_pointer->choice_selection[choice_selection_number].position_max-1; data_position_count > 0;data_position_count--)
                {
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].image      = UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count-1].image;
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active     = UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count-1].active;
                }
                UI_form_pointer->choice_selection[choice_selection_number].data[0].image       = temp_data_texture;
                UI_form_pointer->choice_selection[choice_selection_number].data[0].active      = temp_data_bool;
                UI_form_pointer->element[5].texture.normal               = UI_form_pointer->choice_selection[choice_selection_number].data[0].image;
                UI_form_pointer->element[6].texture.normal               = UI_form_pointer->choice_selection[choice_selection_number].data[1].image;
                UI_form_pointer->element[7].texture.normal               = UI_form_pointer->choice_selection[choice_selection_number].data[2].image;
                UI_form_pointer->element[8].texture.normal               = UI_form_pointer->choice_selection[choice_selection_number].data[3].image;
                UI_form_pointer->element[9].texture.normal               = UI_form_pointer->choice_selection[choice_selection_number].data[4].image;
                UI_form_pointer->element[5].selected                     = UI_form_pointer->choice_selection[choice_selection_number].data[0].active;
                UI_form_pointer->element[6].selected                     = UI_form_pointer->choice_selection[choice_selection_number].data[1].active;
                UI_form_pointer->element[7].selected                     = UI_form_pointer->choice_selection[choice_selection_number].data[2].active;
                UI_form_pointer->element[8].selected                     = UI_form_pointer->choice_selection[choice_selection_number].data[3].active;
                UI_form_pointer->element[9].selected                     = UI_form_pointer->choice_selection[choice_selection_number].data[4].active;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 0 selected
                for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
                {
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active = false;
                }
                UI_form_pointer->element[5].selected                  = true;
                UI_form_pointer->element[6].selected                  = false;
                UI_form_pointer->element[7].selected                  = false;
                UI_form_pointer->element[8].selected                  = false;
                UI_form_pointer->element[9].selected                  = false;
                UI_form_pointer->choice_selection[choice_selection_number].data[0].active   = true;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 1 selected
                for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
                {
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active = false;
                }
                UI_form_pointer->element[5].selected                  = false;
                UI_form_pointer->element[6].selected                  = true;
                UI_form_pointer->element[7].selected                  = false;
                UI_form_pointer->element[8].selected                  = false;
                UI_form_pointer->element[9].selected                  = false;
                UI_form_pointer->choice_selection[choice_selection_number].data[1].active   = true;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 2 selected
                for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
                {
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active = false;
                }
                UI_form_pointer->element[5].selected                  = false;
                UI_form_pointer->element[6].selected                  = false;
                UI_form_pointer->element[7].selected                  = true;
                UI_form_pointer->element[8].selected                  = false;
                UI_form_pointer->element[9].selected                  = false;
                UI_form_pointer->choice_selection[choice_selection_number].data[2].active   = true;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 3 selected
                for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
                {
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active = false;
                }
                UI_form_pointer->element[5].selected                  = false;
                UI_form_pointer->element[6].selected                  = false;
                UI_form_pointer->element[7].selected                  = false;
                UI_form_pointer->element[8].selected                  = true;
                UI_form_pointer->element[9].selected                  = false;
                UI_form_pointer->choice_selection[choice_selection_number].data[3].active   = true;
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 4 selected
                for (int data_position_count = 0; data_position_count <= UI_form_pointer->choice_selection[choice_selection_number].position_max;data_position_count++)
                {
                    UI_form_pointer->choice_selection[choice_selection_number].data[data_position_count].active = false;
                }
                UI_form_pointer->element[5].selected                  = false;
                UI_form_pointer->element[6].selected                  = false;
                UI_form_pointer->element[7].selected                  = false;
                UI_form_pointer->element[8].selected                  = false;
                UI_form_pointer->element[9].selected                  = true;
                UI_form_pointer->choice_selection[choice_selection_number].data[4].active   = true;
            break;
            case (EVENT_UI_STACK_SORT): //Window stack sort
                game.UI_manager.UI_form_stack_sort();
                game.UI_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = UID_MENU_GAME_NEW;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",UI_form_pointer->event.id, " - UID - ",UI_form_pointer->UID);
                UI_form_pointer->event.id = EVENT_NONE;
            break;
        }
    }
    UI_form_pointer->event.id = EVENT_NONE;
};






