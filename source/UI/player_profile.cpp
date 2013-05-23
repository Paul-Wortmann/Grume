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

#include "player_profile.hpp"
#include "../game.hpp"
#include "../core/misc.hpp"

extern game_class         game;

void setup_player_profile(int UID)
{
    int window_number = game.window_manager.window_get_number(UID);
    int element_number = 0;
    game.window_manager.window[window_number].UID                     = UID;
    game.window_manager.window[window_number].active                  = false;
    game.window_manager.window[window_number].mouse_over_menu         = false;
    game.window_manager.window[window_number].mouse_over_title        = false;
    game.window_manager.window[window_number].set_behind              = true;
    game.window_manager.window[window_number].size.x                  =  0.16f;
    game.window_manager.window[window_number].size.y                  =  game.window_manager.window[window_number].size.x;
    game.window_manager.window[window_number].position.x              = -1.0f + (game.window_manager.window[window_number].size.x / 2.0f);
    game.window_manager.window[window_number].position.y              =  1.0f - (game.window_manager.window[window_number].size.y / 2.0f);
    game.window_manager.window[window_number].position.z              =  0.0f;
    game.window_manager.window[window_number].texture.angle           =  0.0f;
    game.window_manager.window[window_number].texture.base                = game.texture_manager.add_texture("data/textures/UI/menu/profile_background.png");
    game.window_manager.window[window_number].texture.normal              = game.texture_manager.add_texture("data/textures/UI/menu/button_normal.png");
    game.window_manager.window[window_number].texture.highlighted         = game.texture_manager.add_texture("data/textures/UI/menu/button_highlighted.png");
    game.window_manager.window[window_number].texture.disabled            = game.texture_manager.add_texture("data/textures/UI/menu/button_disabled.png");
    game.window_manager.window[window_number].sound.on_click.enabled      = true;
    game.window_manager.window[window_number].sound.on_click.sound        = game.sound_manager.add_sound("data/sound/menu/menu_select_00.wav");
    game.window_manager.window[window_number].sound.on_mouse_over.enabled = true;
    game.window_manager.window[window_number].sound.on_mouse_over.sound   = game.sound_manager.add_sound("data/sound/menu/menu_move_00.wav");
    game.window_manager.window[window_number].font_path                   = "data/fonts/font_001.ttf";
    game.window_manager.window[window_number].font.load(game.window_manager.window[window_number].font_path);
    game.window_manager.window[window_number].mouse_delay.maximum     = 30;
    game.window_manager.window[window_number].event.id                = 0;
    game.window_manager.window[window_number].color.normal.r          = 128;
    game.window_manager.window[window_number].color.normal.b          = 128;
    game.window_manager.window[window_number].color.normal.g          = 128;
    game.window_manager.window[window_number].color.normal.a          = 255;
    game.window_manager.window[window_number].color.highlighted.r     = 192;
    game.window_manager.window[window_number].color.highlighted.b     = 192;
    game.window_manager.window[window_number].color.highlighted.g     = 192;
    game.window_manager.window[window_number].color.highlighted.a     = 255;
    game.window_manager.window[window_number].color.disabled.r        = 064;
    game.window_manager.window[window_number].color.disabled.b        = 064;
    game.window_manager.window[window_number].color.disabled.g        = 064;
    game.window_manager.window[window_number].color.disabled.a        = 128;
    game.window_manager.window[window_number].zoom.enabled            = false;
    game.window_manager.window[window_number].zoom.maximum            = 0.02f;
    game.window_manager.window[window_number].zoom.speed              = 0.004f;
    game.window_manager.window[window_number].texture.angle           = 0.0f;
    game.window_manager.window[window_number].title.text              = "";
    game.window_manager.window[window_number].title.size.x            = game.window_manager.window[window_number].title.text.length()/1.2f;
    game.window_manager.window[window_number].title.size.y            = game.window_manager.window[window_number].title.size.x*4;
    game.window_manager.window[window_number].title.position.x        = game.window_manager.window[window_number].position.x - (game.window_manager.window[window_number].title.size.x/100.0f);
    game.window_manager.window[window_number].title.position.y        = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y/2.0f) - (game.window_manager.window[window_number].title.size.y / 440.0f);
    game.window_manager.window[window_number].title_bar.size.x        = game.window_manager.window[window_number].size.x; // x/2.0f for middle section
    game.window_manager.window[window_number].title_bar.size.y        = game.window_manager.window[window_number].size.y / 10.0f;
    game.window_manager.window[window_number].title_bar.position.x    = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].title_bar.position.y    = game.window_manager.window[window_number].position.y+(game.window_manager.window[window_number].size.y/2.0f)-(game.window_manager.window[window_number].title_bar.size.y/2.0f);

    // ---------------------------- Setup window elements ----------------------------------------------------
    game.window_manager.window[window_number].number_of_elements = 5;
    game.window_manager.window[window_number].element = new window_element_class[game.window_manager.window[window_number].number_of_elements];
    element_number = 0; //--- Player profile image ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "Not Set";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = game.window_manager.window[window_number].size.x * 0.70f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y * 0.70f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x;
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.05f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.player.portrait;
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.player.portrait;
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 1; //--- Player profile bar background ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = game.window_manager.window[window_number].size.x * 2.8f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y * 1.1f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x + (game.window_manager.window[window_number].size.x * 0.85);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y;
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/profile_main_background.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/profile_main_background.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 2; //--- Player health bar ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BAR;
    game.window_manager.window[window_number].element[element_number].value                     = 0;
    game.window_manager.window[window_number].element[element_number].value_max                 = 100;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "0%";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = game.window_manager.window[window_number].size.x * 1.52f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y * 0.161f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x + (game.window_manager.window[window_number].size.x * 1.25f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.31f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/health_bar.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/health_bar.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 3; //--- Player mana bar ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = BAR;
    game.window_manager.window[window_number].element[element_number].value                     = 100;
    game.window_manager.window[window_number].element[element_number].value_max                 = 100;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].tooltip.enabled           = true;
    game.window_manager.window[window_number].element[element_number].tooltip.text              = "0%";
    game.window_manager.window[window_number].element[element_number].tooltip.size.x            = 12.0f;
    game.window_manager.window[window_number].element[element_number].tooltip.size.y            = 30.0f;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = game.window_manager.window[window_number].size.x * 1.52f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y * 0.161f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x + (game.window_manager.window[window_number].size.x * 1.25f);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y + (game.window_manager.window[window_number].size.y * 0.12f);
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/mana_bar.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/mana_bar.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
    element_number = 4; //--- Player profile bar foreground ---
    game.window_manager.window[window_number].element[element_number].window_UID                = game.window_manager.window[window_number].UID;
    game.window_manager.window[window_number].element[element_number].element_UID               = element_number;
    game.window_manager.window[window_number].element[element_number].title.text                = "";
    game.window_manager.window[window_number].element[element_number].title.enabled             = false;
    game.window_manager.window[window_number].element[element_number].active                    = true;
    game.window_manager.window[window_number].element[element_number].type                      = IMAGE;
    game.window_manager.window[window_number].element[element_number].zoom.enabled              = false;
    game.window_manager.window[window_number].element[element_number].color                     = game.window_manager.window[window_number].color;
    game.window_manager.window[window_number].element[element_number].size.x                    = game.window_manager.window[window_number].size.x * 2.8f;
    game.window_manager.window[window_number].element[element_number].size.y                    = game.window_manager.window[window_number].size.y * 1.1f;
    game.window_manager.window[window_number].element[element_number].position.x                = game.window_manager.window[window_number].position.x + (game.window_manager.window[window_number].size.x * 0.85);
    game.window_manager.window[window_number].element[element_number].position.y                = game.window_manager.window[window_number].position.y;
    game.window_manager.window[window_number].element[element_number].texture.normal            = game.texture_manager.add_texture("data/textures/UI/menu/profile_main.png");
    game.window_manager.window[window_number].element[element_number].texture.highlighted       = game.texture_manager.add_texture("data/textures/UI/menu/profile_main.png");
    game.window_manager.window[window_number].element[element_number].sound                     = game.window_manager.window[window_number].sound;
    game.window_manager.window[window_number].element[element_number].font                      = game.window_manager.window[window_number].font;
    game.window_manager.window[window_number].element[element_number].mouse_delay.maximum       = 30;
};

void update_player_profile(int window_number)
{
    int element_number = 0; //--- Player profile image ---
    game.window_manager.window[window_number].element[element_number].texture.normal      = game.player.portrait;
    game.window_manager.window[window_number].element[element_number].texture.highlighted = game.player.portrait;
    element_number = 2; //--- Player health bar ---
    game.window_manager.window[window_number].element[element_number].value = game.player.health.current;
    element_number = 3; //--- Player mana bar ---
    game.window_manager.window[window_number].element[element_number].value = game.player.mana.current;
};

void process_player_profile(int window_number)
{
    int element_number = 0; //--- Player name ---
    game.window_manager.window[window_number].element[element_number].tooltip.text = game.player.name;
    //Update the health and mana bars.
    std::string temp_string = "";
    element_number = 2; //--- Player health bar ---
    game.window_manager.window[window_number].element[element_number].value = game.player.health.current;
    temp_string  = int_to_string(game.player.health.current);
    temp_string += "%";
    if (game.player.health.current >  9) temp_string += ' ';
    if (game.player.health.current > 99) temp_string += ' ';
    temp_string += "    ";
    game.window_manager.window[window_number].element[element_number].tooltip.text = temp_string;
    element_number     = 3; //--- Player mana bar ---
    game.window_manager.window[window_number].element[element_number].value = game.player.mana.current;
    temp_string  = int_to_string(game.player.mana.current);
    temp_string += "%";
    if (game.player.mana.current >  9) temp_string += ' ';
    if (game.player.mana.current > 99) temp_string += ' ';
    temp_string += "    ";
    game.window_manager.window[window_number].element[element_number].tooltip.text = temp_string;
    if(game.window_manager.window[window_number].event.id > EVENT_NONE)
    {
        switch (game.window_manager.window[window_number].event.id)
        {
            case (EVENT_WINDOW_STACK_SORT): //Window stack sort
                game.window_manager.window_stack_sort();
                game.window_manager.event.id = EVENT_NONE;
            break;
            case (EVENT_ELEMENT_DRAG): //Element drag event posted
                //game.window_manager.source.window = PCPROFILE_UID;
            break;
            case (EVENT_ELEMENT_DROP): //Element drop event posted
                //game.window_manager.destination.window = PCPROFILE_UID;
            break;
            default:
                game.core.log.file_write("Unable to process event - ",game.window_manager.window[window_number].event.id, " - UID - ",game.window_manager.window[window_number].UID);
                game.window_manager.window[window_number].event.id = EVENT_NONE;
            break;
        }
    }
    game.window_manager.window[window_number].event.id = EVENT_NONE;
};



