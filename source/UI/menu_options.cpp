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

#include "menu_options.hpp"
#include <string>
#include "../game/game.hpp"

extern game_class         game;
extern tmx_map_type       tmx_map;

//----------------------------------------------------------

void setup_menu_options(int UID)
{
    int element_number = 0;

    UI_form_struct   *UI_form_pointer;
    UI_form_pointer = new UI_form_struct;
    UI_form_pointer = game.UI_manager.UI_form_add(UID_MENU_OPTIONS);

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
    UI_form_pointer->data.title.text              = game.texture_manager.add_texture(game.font_manager.root,"Options",0.8f,0,0,TEXTURE_STRING);
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
        UI_form_pointer->data.element[element_count].state                          = NORMAL;
        UI_form_pointer->data.element[element_count].selected                       = false;
        UI_form_pointer->data.element[element_count].type                           = UI_ELEMENT_BUTTON;
        UI_form_pointer->data.element[element_count].sub_type                       = 0;//ITEM_NONE;// TEST
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
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 30;

// ------------------------------------- Resolution selection --------------------------------------------------------
    UI_form_pointer->data.number_of_choice_selections = 1;
    UI_form_pointer->data.choice_selection = new choice_selection_type[UI_form_pointer->data.number_of_choice_selections];
    for (int choice_selection_count = 0; choice_selection_count < UI_form_pointer->data.number_of_choice_selections; choice_selection_count++)
    {
        UI_form_pointer->data.choice_selection[choice_selection_count].selected     = 0;
        UI_form_pointer->data.choice_selection[choice_selection_count].position     = 0;
        UI_form_pointer->data.choice_selection[choice_selection_count].position_max = 0;
        UI_form_pointer->data.choice_selection[choice_selection_count].number_of_data = 13;
        UI_form_pointer->data.choice_selection[choice_selection_count].data = new selection_data_type[UI_form_pointer->data.choice_selection[choice_selection_count].number_of_data];
        for (int data_count = 0; data_count < UI_form_pointer->data.choice_selection[choice_selection_count].number_of_data; data_count++)
        {
            UI_form_pointer->data.choice_selection[choice_selection_count].data[data_count].active       = false;
            UI_form_pointer->data.choice_selection[choice_selection_count].data[data_count].value_int    = 0;
            UI_form_pointer->data.choice_selection[choice_selection_count].data[data_count].value_string = NULL;
        }
    }
    int choice_selection_number = 0;

    UI_form_pointer->data.choice_selection[choice_selection_number].selected         = 0; // Resolution selection
    UI_form_pointer->data.choice_selection[choice_selection_number].position         = 0;
    UI_form_pointer->data.choice_selection[choice_selection_number].position_max     = 7;
    for (int data_position_count = 0; data_position_count <= UI_form_pointer->data.choice_selection[choice_selection_number].position_max;data_position_count++)
    {
        UI_form_pointer->data.choice_selection[choice_selection_number].data[data_position_count].active = false;
    }
    UI_form_pointer->data.choice_selection[choice_selection_number].data[game.core.config.display_resolution].active          = true;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[0].value_int       = 0;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[0].value_string    = game.texture_manager.add_texture(game.font_manager.root,"640 X 480",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.choice_selection[choice_selection_number].data[1].value_int       = 1;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[1].value_string    = game.texture_manager.add_texture(game.font_manager.root,"800 X 600",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.choice_selection[choice_selection_number].data[2].value_int       = 2;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[2].value_string    = game.texture_manager.add_texture(game.font_manager.root,"1028 X 768",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.choice_selection[choice_selection_number].data[3].value_int       = 3;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[3].value_string    = game.texture_manager.add_texture(game.font_manager.root,"1280 X 1024",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.choice_selection[choice_selection_number].data[4].value_int       = 4;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[4].value_string    = game.texture_manager.add_texture(game.font_manager.root,"1366 X 768",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.choice_selection[choice_selection_number].data[5].value_int       = 5;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[5].value_string    = game.texture_manager.add_texture(game.font_manager.root,"1440 X 900",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.choice_selection[choice_selection_number].data[6].value_int       = 6;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[6].value_string    = game.texture_manager.add_texture(game.font_manager.root,"1680 X 1050",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.choice_selection[choice_selection_number].data[7].value_int       = 7;
    UI_form_pointer->data.choice_selection[choice_selection_number].data[7].value_string    = game.texture_manager.add_texture(game.font_manager.root,"1920 X 1080",0.8f,0,0,TEXTURE_STRING);
//----------------------------------------------------------------------------------------------------------------------
    element_number = 2; // Resolution selection element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].state                     = DISABLED;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*60.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*5.75f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;

    element_number = 3; // Resolution selection element 0
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].title.text                = UI_form_pointer->data.choice_selection[0].data[0].value_string;
    UI_form_pointer->data.element[element_number].selected                  = UI_form_pointer->data.choice_selection[0].data[0].active;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*2.5f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.5f);
    UI_form_pointer->data.element[element_number].texture.base              = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/resolution_icon.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//0;//UI_form_pointer->data.element[element_number].title.text.length()/2.4f;;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//0;//UI_form_pointer->data.element[element_number].title.size.x*4.0f;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.position.x - (UI_form_pointer->data.element[element_number].title.size.x/42.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y - (UI_form_pointer->data.element[element_number].title.size.y/120.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 10;

    element_number = 4; // Resolution selection element 1
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].title.text                = UI_form_pointer->data.choice_selection[0].data[1].value_string;
    UI_form_pointer->data.element[element_number].selected                  = UI_form_pointer->data.choice_selection[0].data[1].active;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*3.75f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.5f);
    UI_form_pointer->data.element[element_number].texture.base              = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/resolution_icon.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.4f;;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4.0f;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.position.x - (UI_form_pointer->data.element[element_number].title.size.x/42.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y - (UI_form_pointer->data.element[element_number].title.size.y/120.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 10;

    element_number = 5; // Resolution selection element 2
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].title.text                = UI_form_pointer->data.choice_selection[0].data[2].value_string;
    UI_form_pointer->data.element[element_number].selected                  = UI_form_pointer->data.choice_selection[0].data[2].active;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*5.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.5f);
    UI_form_pointer->data.element[element_number].texture.base              = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/resolution_icon.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.4f;;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4.0f;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.position.x - (UI_form_pointer->data.element[element_number].title.size.x/42.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y - (UI_form_pointer->data.element[element_number].title.size.y/120.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 10;

    element_number = 6; // Resolution selection element 3
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].title.text                = UI_form_pointer->data.choice_selection[0].data[3].value_string;
    UI_form_pointer->data.element[element_number].selected                  = UI_form_pointer->data.choice_selection[0].data[3].active;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*6.25f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.5f);
    UI_form_pointer->data.element[element_number].texture.base              = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/resolution_icon.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.4f;;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4.0f;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.position.x - (UI_form_pointer->data.element[element_number].title.size.x/42.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y - (UI_form_pointer->data.element[element_number].title.size.y/120.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 10;

    element_number = 7; // Resolution selection element 4
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].title.text                = UI_form_pointer->data.choice_selection[0].data[4].value_string;
    UI_form_pointer->data.element[element_number].selected                  = UI_form_pointer->data.choice_selection[0].data[4].active;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_IMAGE;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*7.5f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.5f);
    UI_form_pointer->data.element[element_number].texture.base              = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/resolution_icon.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/selection_box.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.4f;;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4.0f;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.position.x - (UI_form_pointer->data.element[element_number].title.size.x/42.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y - (UI_form_pointer->data.element[element_number].title.size.y/120.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 10;

    element_number = 8; // Right arrow resolution selection element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.50f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 0.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 5;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;

    element_number = 9; // Left arrow resolution selection element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.0f)-(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*4.50f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 180.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 5;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;

// ------------------------------------------- Sound Volume ------------------------------------------------------------
    element_number = 10; // Sound volume selection left arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*2.0f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 0.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 2;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 11; // Sound volume selection right arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.0f)-(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*2.0f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 180.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 2;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 12; // Sound volume selection - sound volume bar element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Sound volume",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].value                     = game.core.config.audio_volume_sound;
    UI_form_pointer->data.element[element_number].value_max                 = 127.0f;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BAR;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*60.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*2.0f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/slider_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/60.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;

// ------------------------------------------- Music Volume ------------------------------------------------------------
    element_number = 13; // Music volume selection left arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*3.25f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 0.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 5;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 14; // Music volume selection right arrow element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x+(UI_form_pointer->data.size.x/2.0f)-(UI_form_pointer->data.element[element_number].size.x*1.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*3.25f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    UI_form_pointer->data.element[element_number].texture.angle             = 180.0f;
    UI_form_pointer->data.element[element_number].mouse_delay.maximum       = 5;
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].sound.on_click.enabled    = false;

    element_number = 15; // Music volume selection - music volume bar element
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
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x;
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*3.25f);
    UI_form_pointer->data.element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/slider_highlighted.png");
    UI_form_pointer->data.element[element_number].texture.disabled          = game.texture_manager.add_texture("data/textures/UI/menu/slider_normal.png");
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/2.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/60.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;

    element_number = 16; // Full screen button element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = game.texture_manager.add_texture(game.font_manager.root,"Fullscreen",0.8f,0,0,TEXTURE_STRING);
    UI_form_pointer->data.element[element_number].title.enabled             = true;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].zoom                      = UI_form_pointer->data.zoom;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*48.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.element[element_number].size.x/8.0f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*7.0f);
    UI_form_pointer->data.element[element_number].texture                   = UI_form_pointer->data.texture;
    UI_form_pointer->data.element[element_number].title.size.x              = 0;//UI_form_pointer->data.element[element_number].title.text.length()/1.2f;
    UI_form_pointer->data.element[element_number].title.size.y              = 0;//UI_form_pointer->data.element[element_number].title.size.x*4;;
    UI_form_pointer->data.element[element_number].title.position.x          = UI_form_pointer->data.element[element_number].position.x-(UI_form_pointer->data.element[element_number].title.size.x/100.0f);
    UI_form_pointer->data.element[element_number].title.position.y          = UI_form_pointer->data.element[element_number].position.y-(UI_form_pointer->data.element[element_number].title.size.y/1480.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;

    element_number = 17; // Full screen colored button element
    UI_form_pointer->data.element[element_number].window_UID                = UI_form_pointer->data.UID;
    UI_form_pointer->data.element[element_number].element_UID               = element_number;
    UI_form_pointer->data.element[element_number].title.text                = NULL;
    UI_form_pointer->data.element[element_number].active                    = true;
    UI_form_pointer->data.element[element_number].type                      = UI_ELEMENT_BUTTON;
    UI_form_pointer->data.element[element_number].zoom.enabled              = false;
    UI_form_pointer->data.element[element_number].tooltip.enabled           = false;
    UI_form_pointer->data.element[element_number].value                     = 1.0f;
    UI_form_pointer->data.element[element_number].color                     = UI_form_pointer->data.color;
    UI_form_pointer->data.element[element_number].size.x                    = (UI_form_pointer->data.size.x / 100.f)*10.0f;
    UI_form_pointer->data.element[element_number].size.y                    = UI_form_pointer->data.size.y / 10.0f;
    UI_form_pointer->data.element[element_number].position.x                = UI_form_pointer->data.position.x-(UI_form_pointer->data.size.x/2.0f)+(UI_form_pointer->data.element[element_number].size.x*7.5f);
    UI_form_pointer->data.element[element_number].position.y                = UI_form_pointer->data.position.y+(UI_form_pointer->data.size.y/2.0f)-(UI_form_pointer->data.element[element_number].size.y*7.0f);
    UI_form_pointer->data.element[element_number].sound                     = UI_form_pointer->data.sound;
    UI_form_pointer->data.element[element_number].font                      = UI_form_pointer->data.font;
    if (game.core.config.display_fullscreen)
    {
        UI_form_pointer->data.element[element_number].value                 = 1.0f;
        UI_form_pointer->data.element[element_number].texture.normal        = game.texture_manager.add_texture("data/textures/UI/menu/green_button.png");
        UI_form_pointer->data.element[element_number].texture.highlighted   = game.texture_manager.add_texture("data/textures/UI/menu/green_button_highlighted.png");
        UI_form_pointer->data.element[element_number].texture.disabled      = game.texture_manager.add_texture("data/textures/UI/menu/red_button.png");
        UI_form_pointer->data.element[element_number].texture.base          = game.texture_manager.add_texture("data/textures/UI/menu/red_button_highlighted.png");
    }
    else
    {
        UI_form_pointer->data.element[element_number].value                 = 0.0f;
        UI_form_pointer->data.element[element_number].texture.normal        = game.texture_manager.add_texture("data/textures/UI/menu/red_button.png");
        UI_form_pointer->data.element[element_number].texture.highlighted   = game.texture_manager.add_texture("data/textures/UI/menu/red_button_highlighted.png");
        UI_form_pointer->data.element[element_number].texture.disabled      = game.texture_manager.add_texture("data/textures/UI/menu/green_button.png");
        UI_form_pointer->data.element[element_number].texture.base          = game.texture_manager.add_texture("data/textures/UI/menu/green_button_highlighted.png");
    }
};

void process_menu_options(UI_form_struct *UI_form_pointer)
{
    if (UI_form_pointer->data.event.id > EVENT_NONE)
    {
        bool reset_display        = false;
        bool resolution_selection = false;
        int  resolution_element   = 0;
        game.core.log.file_write("Processing event - ",UI_form_pointer->data.event.id);
        switch (UI_form_pointer->data.event.id)
        {
            case ((0*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Close menu button
                game.UI_manager.UI_form_transition(UID_MENU_OPTIONS,UID_MENU_MAIN);
            break;
            case ((1*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Main menu button
                game.UI_manager.UI_form_transition(UID_MENU_OPTIONS,UID_MENU_MAIN);
            break;
            case ((3*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection element 0
                resolution_selection = true;
                resolution_element   = 0;
            break;
            case ((4*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection element 1
                resolution_selection = true;
                resolution_element   = 1;
            break;
            case ((5*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection element 2
                resolution_selection = true;
                resolution_element   = 2;
            break;
            case ((6*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection element 3
                resolution_selection = true;
                resolution_element   = 3;
            break;
            case ((7*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution selection element 4
                resolution_selection = true;
                resolution_element   = 4;
            break;
            case ((8*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution left arrow button
                {
                    UI_form_pointer->data.choice_selection[0].position++;
                    if (UI_form_pointer->data.choice_selection[0].position > UI_form_pointer->data.choice_selection[0].position_max) UI_form_pointer->data.choice_selection[0].position = 0;
                    int           temp_data_value   = UI_form_pointer->data.choice_selection[0].data[0].value_int;
                    bool          temp_data_bool    = UI_form_pointer->data.choice_selection[0].data[0].active;
                    texture_type* temp_data_string  = UI_form_pointer->data.choice_selection[0].data[0].value_string;
                    for (int data_position_count  = 0; data_position_count < UI_form_pointer->data.choice_selection[0].position_max;data_position_count++)
                    {
                        UI_form_pointer->data.choice_selection[0].data[data_position_count].value_int    = UI_form_pointer->data.choice_selection[0].data[data_position_count+1].value_int;
                        UI_form_pointer->data.choice_selection[0].data[data_position_count].active       = UI_form_pointer->data.choice_selection[0].data[data_position_count+1].active;
                        UI_form_pointer->data.choice_selection[0].data[data_position_count].value_string = UI_form_pointer->data.choice_selection[0].data[data_position_count+1].value_string;
                    }
                    UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position_max].value_int    = temp_data_value;
                    UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position_max].active       = temp_data_bool;
                    UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position_max].value_string = temp_data_string;
                    UI_form_pointer->data.element[3].selected                  = UI_form_pointer->data.choice_selection[0].data[0].active;
                    UI_form_pointer->data.element[4].selected                  = UI_form_pointer->data.choice_selection[0].data[1].active;
                    UI_form_pointer->data.element[5].selected                  = UI_form_pointer->data.choice_selection[0].data[2].active;
                    UI_form_pointer->data.element[6].selected                  = UI_form_pointer->data.choice_selection[0].data[3].active;
                    UI_form_pointer->data.element[7].selected                  = UI_form_pointer->data.choice_selection[0].data[4].active;
                    UI_form_pointer->data.element[3].title.text                = UI_form_pointer->data.choice_selection[0].data[0].value_string;
                    UI_form_pointer->data.element[4].title.text                = UI_form_pointer->data.choice_selection[0].data[1].value_string;
                    UI_form_pointer->data.element[5].title.text                = UI_form_pointer->data.choice_selection[0].data[2].value_string;
                    UI_form_pointer->data.element[6].title.text                = UI_form_pointer->data.choice_selection[0].data[3].value_string;
                    UI_form_pointer->data.element[7].title.text                = UI_form_pointer->data.choice_selection[0].data[4].value_string;
                }
            break;
            case ((9*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Resolution right arrow button
                {
                    UI_form_pointer->data.choice_selection[0].position--;
                    if (UI_form_pointer->data.choice_selection[0].position < 0) UI_form_pointer->data.choice_selection[0].position = UI_form_pointer->data.choice_selection[0].position_max;
                    int           temp_data_value   = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position_max-1].value_int;
                    bool          temp_data_bool    = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position_max-1].active;
                    texture_type* temp_data_string  = UI_form_pointer->data.choice_selection[0].data[UI_form_pointer->data.choice_selection[0].position_max-1].value_string;
                    for (int data_position_count  = UI_form_pointer->data.choice_selection[0].position_max-1; data_position_count > 0;data_position_count--)
                    {
                        UI_form_pointer->data.choice_selection[0].data[data_position_count].value_int    = UI_form_pointer->data.choice_selection[0].data[data_position_count-1].value_int;
                        UI_form_pointer->data.choice_selection[0].data[data_position_count].active       = UI_form_pointer->data.choice_selection[0].data[data_position_count-1].active;
                        UI_form_pointer->data.choice_selection[0].data[data_position_count].value_string = UI_form_pointer->data.choice_selection[0].data[data_position_count-1].value_string;
                    }
                    UI_form_pointer->data.choice_selection[0].data[0].value_int    = temp_data_value;
                    UI_form_pointer->data.choice_selection[0].data[0].active       = temp_data_bool;
                    UI_form_pointer->data.choice_selection[0].data[0].value_string = temp_data_string;
                    UI_form_pointer->data.element[3].selected                  = UI_form_pointer->data.choice_selection[0].data[0].active;
                    UI_form_pointer->data.element[4].selected                  = UI_form_pointer->data.choice_selection[0].data[1].active;
                    UI_form_pointer->data.element[5].selected                  = UI_form_pointer->data.choice_selection[0].data[2].active;
                    UI_form_pointer->data.element[6].selected                  = UI_form_pointer->data.choice_selection[0].data[3].active;
                    UI_form_pointer->data.element[7].selected                  = UI_form_pointer->data.choice_selection[0].data[4].active;
                    UI_form_pointer->data.element[3].title.text                = UI_form_pointer->data.choice_selection[0].data[0].value_string;
                    UI_form_pointer->data.element[4].title.text                = UI_form_pointer->data.choice_selection[0].data[1].value_string;
                    UI_form_pointer->data.element[5].title.text                = UI_form_pointer->data.choice_selection[0].data[2].value_string;
                    UI_form_pointer->data.element[6].title.text                = UI_form_pointer->data.choice_selection[0].data[3].value_string;
                    UI_form_pointer->data.element[7].title.text                = UI_form_pointer->data.choice_selection[0].data[4].value_string;
                }
            break;
            case ((10*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Sound volume left arrow button
                game.core.config.audio_volume_sound--;
                if (game.core.config.audio_volume_sound < 0.0f) game.core.config.audio_volume_sound = 0.0f;
                UI_form_pointer->data.element[12].value = game.core.config.audio_volume_sound;
                Mix_Volume(-1,game.core.config.audio_volume_sound);
            break;
            case ((11*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Sound volume right arrow button
                game.core.config.audio_volume_sound++;
                if (game.core.config.audio_volume_sound > UI_form_pointer->data.element[12].value_max) game.core.config.audio_volume_sound = UI_form_pointer->data.element[12].value_max;
                UI_form_pointer->data.element[12].value = game.core.config.audio_volume_sound;
                Mix_Volume(-1,game.core.config.audio_volume_sound);
            break;
            case ((13*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Music volume left arrow button
                game.core.config.audio_volume_music--;
                if (game.core.config.audio_volume_music < 0.0f) game.core.config.audio_volume_music = 0.0f;
                UI_form_pointer->data.element[15].value = game.core.config.audio_volume_music;
                Mix_VolumeMusic(game.core.config.audio_volume_music);
            break;
            case ((14*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Music volume right arrow button
                game.core.config.audio_volume_music++;
                if (game.core.config.audio_volume_music > UI_form_pointer->data.element[15].value_max) game.core.config.audio_volume_music = UI_form_pointer->data.element[15].value_max;
                UI_form_pointer->data.element[15].value = game.core.config.audio_volume_music;
                Mix_VolumeMusic(game.core.config.audio_volume_music);
            break;
            case ((16*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Full screen button
            case ((17*EVENT_BUTTON_MULTIPLIER)+EVENT_ELEMENT_MOUSE_LEFT): // Full screen colored button
                if (game.core.config.display_fullscreen)
                {
                    int element_number = 17;
                    game.core.config.display_fullscreen                                     = false;
                    UI_form_pointer->data.element[element_number].value = 0.0f;
                    UI_form_pointer->data.element[element_number].texture.normal        = game.texture_manager.add_texture("data/textures/UI/menu/red_button.png");
                    UI_form_pointer->data.element[element_number].texture.highlighted   = game.texture_manager.add_texture("data/textures/UI/menu/red_button_highlighted.png");
                    UI_form_pointer->data.element[element_number].texture.disabled      = game.texture_manager.add_texture("data/textures/UI/menu/green_button.png");
                    UI_form_pointer->data.element[element_number].texture.base          = game.texture_manager.add_texture("data/textures/UI/menu/green_button_highlighted.png");
                    reset_display = true;
                }
                else
                {
                    int element_number = 17;
                    game.core.config.display_fullscreen                                     = true;
                    UI_form_pointer->data.element[element_number].value = 1.0f;
                    UI_form_pointer->data.element[element_number].texture.normal      = game.texture_manager.add_texture("data/textures/UI/menu/green_button.png");
                    UI_form_pointer->data.element[element_number].texture.highlighted = game.texture_manager.add_texture("data/textures/UI/menu/green_button_highlighted.png");
                    UI_form_pointer->data.element[element_number].texture.disabled    = game.texture_manager.add_texture("data/textures/UI/menu/red_button.png");
                    UI_form_pointer->data.element[element_number].texture.base        = game.texture_manager.add_texture("data/textures/UI/menu/red_button_highlighted.png");
                    reset_display = true;
                }
            break;
            case (EVENT_UI_LIST_SORT): //Window stack sort
                UI_form_pointer->data.event.id = EVENT_NONE;
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
            break;
            case (EVENT_UI_ELEMENT_DRAG): //Element drag event posted
                //game.UI_manager.source.window = MENU_OPTIONS_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",UI_form_pointer->data.event.id, " - UID - ",UI_form_pointer->data.UID);
                UI_form_pointer->data.event.id = EVENT_NONE;
            break;
        }
        if (resolution_selection)
        {
            int   temp_resolution      = 0;
            int   temp_resolution_x    = 0;
            int   temp_resolution_y    = 0;
            int   temp_data_value      = resolution_element;
            if (UI_form_pointer->data.choice_selection[0].data[temp_data_value].value_int != game.core.config.display_resolution)
            {
                temp_resolution      = game.core.config.display_resolution;
                temp_resolution_x    = game.core.config.display_resolution_x;
                temp_resolution_y    = game.core.config.display_resolution_y;
                game.core.config.display_resolution = UI_form_pointer->data.choice_selection[0].data[temp_data_value].value_int;
                if (game.core.config.display_resolution == 0)
                {
                    game.core.config.display_resolution_x = 640;
                    game.core.config.display_resolution_y = 480;
                }
                if (game.core.config.display_resolution == 1)
                {
                    game.core.config.display_resolution_x = 800;
                    game.core.config.display_resolution_y = 600;
                }
                if (game.core.config.display_resolution == 2)
                {
                    game.core.config.display_resolution_x = 1024;
                    game.core.config.display_resolution_y = 768;
                }
                if (game.core.config.display_resolution == 3)
                {
                    game.core.config.display_resolution_x = 1280;
                    game.core.config.display_resolution_y = 1024;
                }
                if (game.core.config.display_resolution == 4)
                {
                    game.core.config.display_resolution_x = 1366;
                    game.core.config.display_resolution_y = 768;
                }
                if (game.core.config.display_resolution == 5)
                {
                    game.core.config.display_resolution_x = 1440;
                    game.core.config.display_resolution_y = 900;
                }
                if (game.core.config.display_resolution == 6)
                {
                    game.core.config.display_resolution_x = 1680;
                    game.core.config.display_resolution_y = 1050;
                }
                if (game.core.config.display_resolution == 7)
                {
                    game.core.config.display_resolution_x = 1920;
                    game.core.config.display_resolution_y = 1080;
                }
                if (!game.core.graphics.init_sdl())
                {
                    game.core.log.file_write("Reverting graphics configuration...");
                    game.core.config.display_resolution    = temp_resolution;
                    game.core.config.display_resolution_x  = temp_resolution_x;
                    game.core.config.display_resolution_y  = temp_resolution_y;
                    game.core.graphics.init_sdl();
                }
                else
                {
                    game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
                    game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
                    for (int data_position_count = 0; data_position_count < UI_form_pointer->data.choice_selection[0].position_max;data_position_count++)
                    {
                        UI_form_pointer->data.choice_selection[0].data[data_position_count].active = false;
                    }
                    UI_form_pointer->data.choice_selection[0].data[temp_data_value].active    = true;
                    UI_form_pointer->data.element[3].selected                  = false;
                    UI_form_pointer->data.element[4].selected                  = false;
                    UI_form_pointer->data.element[5].selected                  = false;
                    UI_form_pointer->data.element[6].selected                  = false;
                    UI_form_pointer->data.element[7].selected                  = false;
                    UI_form_pointer->data.element[temp_data_value+3].selected  = true;
                }
                reset_display = true;
            }
        }
        if (reset_display)
        {
            game.core.log.file_write("Reinitializing SDL...");
            game.core.graphics.init_sdl();
            game.core.log.file_write("Reinitializing OpenGL...");
            game.core.graphics.init_gl();
            game.loading_screen.display("data/loading_screen.png");
            game.core.log.file_write("Reloading resources....");
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
