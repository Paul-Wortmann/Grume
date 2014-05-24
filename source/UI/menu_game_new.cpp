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

#include "menu_game_new.hpp"
#include "../game/game.hpp"

extern game_class         game;

//----------------------------------------------------------

void setup_menu_game_new(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = game.UI_manager.UI_form_add(UID_MENU_GAME_NEW);

    UI_form_pointer->data.UID                     = UID;
    UI_form_pointer->data.enabled                 = false;
    UI_form_pointer->data.mouse_over_menu         = false;
    UI_form_pointer->data.mouse_over_title        = false;
    UI_form_pointer->data.position.x              = 0.0f;
    UI_form_pointer->data.position.y              = -0.34f;
    UI_form_pointer->data.position.z              = 0.0f;
    UI_form_pointer->data.size.x                  = 0.5f;
    UI_form_pointer->data.size.y                  = UI_form_pointer->data.size.x * 2.5f;
    UI_form_pointer->data.texture.angle           = 0.0f;
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
    UI_form_pointer->data.title.text              = game.texture_manager.add_texture(game.font_manager.root,"New Game",0.8f,0,0,TEXTURE_STRING);
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
    UI_form_pointer->data.number_of_elements = 8;
    UI_form_pointer->data.element = new UI_element_struct[UI_form_pointer->data.number_of_elements];
    for (int element_count = 0; element_count < UI_form_pointer->data.number_of_elements; element_count++)
    {
        UI_form_pointer->data.element[element_count].window_UID                     = UI_form_pointer->data.UID;
        UI_form_pointer->data.element[element_count].element_UID                    = element_count;
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
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;

    element_number = 1; //--- Main menu button ---
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

    element_number = 2; //--- Start game menu button ---
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Start Game",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*80.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*7.5f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;

//----------------------------------------------------------------------------------------------------------------------
    UI_form_pointer->data.number_of_choice_selections = 1;
    UI_form_pointer->data.choice_selection = new choice_selection_type[UI_form_pointer->data.number_of_choice_selections];
    for (int choice_selection_count = 0; choice_selection_count < UI_form_pointer->data.number_of_choice_selections; choice_selection_count++)
    {
        UI_form_pointer->data.choice_selection[choice_selection_count].selected       = 0;
        UI_form_pointer->data.choice_selection[choice_selection_count].position       = 0;
        UI_form_pointer->data.choice_selection[choice_selection_count].position_max   = 0;
        UI_form_pointer->data.choice_selection[choice_selection_count].number_of_data = 44;
        UI_form_pointer->data.choice_selection[choice_selection_count].data = new selection_data_type[UI_form_pointer->data.choice_selection[choice_selection_count].number_of_data];
        for (int data_count = 0; data_count < UI_form_pointer->data.choice_selection[choice_selection_count].number_of_data; data_count++)
        {
            UI_form_pointer->data.choice_selection[choice_selection_count].data[data_count].active       = false;
            UI_form_pointer->data.choice_selection[choice_selection_count].data[data_count].value_int    = 0;
            UI_form_pointer->data.choice_selection[choice_selection_count].data[data_count].value_string = NULL;
        }
    }
    int choice_selection_number = 0;

    UI_form_pointer->data.choice_selection[choice_selection_number].selected            = 0; // Player portrait selection
    UI_form_pointer->data.choice_selection[choice_selection_number].position            = 0;
    UI_form_pointer->data.choice_selection[choice_selection_number].position_max        = 43;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 0].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_00.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 1].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_01.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 2].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_02.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 3].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_03.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 4].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_04.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 5].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_05.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 6].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_06.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 7].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_07.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 8].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_08.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[ 9].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_09.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[10].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_10.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[11].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_11.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[12].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_12.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[13].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_13.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[14].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_14.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[15].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_15.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[16].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_16.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[17].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_17.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[18].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_18.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[19].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_19.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[20].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_20.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[21].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_21.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[22].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_22.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[23].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_23.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[24].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_24.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[25].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_25.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[26].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_26.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[27].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_27.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[28].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_28.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[29].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_29.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[30].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_30.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[31].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_31.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[32].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_32.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[33].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_33.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[34].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_34.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[35].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_35.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[36].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_36.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[37].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_37.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[38].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_38.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[39].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_39.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[40].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_40.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[41].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_41.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[42].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_42.png");
    UI_form_pointer->data.choice_selection[choice_selection_number].data[43].image      = game.texture_manager.add_texture("data/textures/UI/portraits/portrait_43.png");
    game.player.portrait = UI_form_pointer->data.choice_selection[choice_selection_number].data[ 0].image;
//----------------------------------------------------------------------------------------------------------------------

    element_number = 3; //--- Background_frame_01 ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].title.enabled               = false;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.x/1.6f;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/3.0f;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x;//+(UI_form_pointer->data.size.x/2.0f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/5.0f);
    UI_form_pointer->data.element[element_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/frame_00.png");
    UI_form_pointer->data.element[element_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/frame_00.png");
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 30;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;

    element_number = 4; // left arrow button for player portrait selection
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.8f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 0.0f;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 10;

    element_number = 5; // Right arrow button for player portrait selection
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 16.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.0f)-(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.8f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 180.0f;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 10;

    element_number = 6; // Image of the player portrait selection
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    UI_form_pointer->data.element[element_number].active                      = true;
    UI_form_pointer->data.element[element_number].type                        = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                       = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                        = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled                = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled             = false;
    UI_form_pointer->data.element[element_number].size.x                      = UI_form_pointer->data.size.x/1.6f;
    UI_form_pointer->data.element[element_number].size.y                      = UI_form_pointer->data.size.y/3.0f;
    UI_form_pointer->data.element[element_number].position.x                  = UI_form_pointer->data.position.x;//+(UI_form_pointer->data.size.x/2.0f);
    UI_form_pointer->data.element[element_number].position.y                  = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/5.0f);
    UI_form_pointer->data.element[element_number].texture                     = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].texture.normal              = UI_form_pointer->data.choice_selection[choice_selection_number].data[0].image;
    UI_form_pointer->data.element[element_number].texture.highlighted         = UI_form_pointer->data.choice_selection[choice_selection_number].data[0].image;
    UI_form_pointer->data.element[element_number].texture.disabled            = UI_form_pointer->data.choice_selection[choice_selection_number].data[0].image;
    UI_form_pointer->data.element[element_number].title.size.x                = 0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y                = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                       = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled      = false;
    UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled = false;
    UI_form_pointer->data.element[element_number].font                        = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum         = 10;
    element_number = 7; //--- Enter player name: ---
    UI_form_pointer->data.element[element_number].window_UID                  = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID                 = element_number;
    //UI_form_pointer->data.element[element_number].title.text                  = game.texture_manager.add_texture(game.font_manager.root,"Player name: ",0.75f,0,0,191,191,191,255,TEXTURE_STRING);
    if (UI_form_pointer->data.element[element_number].title.text != NULL) UI_form_pointer->data.element[element_number].title.text->data.render_positioning = TEXTURE_RENDER_LEFT;
    UI_form_pointer->data.element[element_number].title.enabled               = true;
    UI_form_pointer->data.element[element_number].title.position.x            = UI_form_pointer->data.position.x - (UI_form_pointer->data.size.x * 0.4f);
    UI_form_pointer->data.element[element_number].title.position.y            = UI_form_pointer->data.position.y + (UI_form_pointer->data.size.y * 0.005f);
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

}

void update_menu_game_new(int UID)
{

}

void process_menu_game_new(UI_form_struct *UI_form_pointer)
{
    if(UI_form_pointer->data.event.id > EVENT_NONE)
    {
        int element_number = 0;
        switch (UI_form_pointer->data.event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_NEW,UID_MENU_MAIN);
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Main menu button
                game.UI_manager.UI_form_transition(UID_MENU_GAME_NEW,UID_MENU_MAIN);
            break;
            case ((2*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Start game menu button
                //set player portrait
                game.player.portrait->data.frame[0].data = UI_form_pointer->data.element[6].texture.normal->data.frame[0].data;
                update_player_profile  (game.UI_manager.UI_form_get(UID_PCPROFILE));
                update_character_window(game.UI_manager.UI_form_get(UID_CHARACTER));
                switch (game.state)
                {
                    case STATE_MENU:
                    break;
                    case STATE_GAME:
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
                game.UI_manager.UI_form_enable(UID_ACTIONBAR);
                UI_form_pointer->data.element[3].state = UI_NORMAL; // Save game
                UI_form_pointer->data.element[4].state = UI_NORMAL; // Resume game
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // image background box 1
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // left arrow button for player portrait selection
                element_number = 6;
                UI_form_pointer->data.choice_selection[0].position--;
                if (UI_form_pointer->data.choice_selection[0].position < 0) UI_form_pointer->data.choice_selection[0].position = UI_form_pointer->data.choice_selection[0].position_max;
                UI_form_pointer->data.element[element_number].texture.normal              = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position].image;
                UI_form_pointer->data.element[element_number].texture.highlighted         = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position].image;
                UI_form_pointer->data.element[element_number].texture.disabled            = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position].image;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Right arrow button for player portrait selection
                element_number = 6;
                UI_form_pointer->data.choice_selection[0].position++;
                if (UI_form_pointer->data.choice_selection[0].position > UI_form_pointer->data.choice_selection[0].position_max) UI_form_pointer->data.choice_selection[0].position = 0;
                UI_form_pointer->data.element[element_number].texture.normal              = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position].image;
                UI_form_pointer->data.element[element_number].texture.highlighted         = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position].image;
                UI_form_pointer->data.element[element_number].texture.disabled            = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position].image;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Portrait 0 selected
            break;
            case (EVENT_UI_LIST_SORT): //Window stack sort
                UI_form_pointer->data.event.id = EVENT_NONE;
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
            break;
            case (EVENT_UI_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = UID_MENU_GAME_NEW;
            break;
            default:
                game.core.log.write("Unable to process event - ",UI_form_pointer->data.event.id, " - UID - ",UI_form_pointer->data.UID, " - ",game.UI_manager.uid_to_string(UI_form_pointer->data.UID));
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






