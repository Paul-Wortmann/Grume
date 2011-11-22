/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "UI.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

active_window_list_class::active_window_list_class(void)
{
    for (int awl_count = 0; awl_count < MAX_ACTIVE_WINDOWS; awl_count++)
    {
        active_window_list_class::window_ID[awl_count] = 0;
    }
};

active_window_list_class::~active_window_list_class(void)
{

};

void active_window_list_class::remove_from_list(int window_UID)
{
    for (int awl_count = 0; awl_count < MAX_ACTIVE_WINDOWS; awl_count++)
    {
        if (active_window_list_class::window_ID[awl_count] == window_UID)
        {
            for(int awl_count_2 = awl_count; awl_count_2 < MAX_ACTIVE_WINDOWS-1; awl_count_2++)
            {
                active_window_list_class::window_ID[awl_count_2] = active_window_list_class::window_ID[awl_count_2+1];
            }
        }
    }
};

void active_window_list_class::add_to_list(int window_UID)
{
    for (int awl_count = 0; awl_count < MAX_ACTIVE_WINDOWS; awl_count++) // first kill any previous instances of the window
    {
        if (active_window_list_class::window_ID[awl_count] == window_UID)
        {
            for(int awl_count_2 = awl_count; awl_count_2 < MAX_ACTIVE_WINDOWS-1; awl_count_2++)
            {
                active_window_list_class::window_ID[awl_count_2] = active_window_list_class::window_ID[awl_count_2+1];
            }
        }
    }
    for (int awl_count = MAX_ACTIVE_WINDOWS; awl_count >= 0; awl_count--) //shift stack down
    {
        active_window_list_class::window_ID[awl_count] = active_window_list_class::window_ID[awl_count-1];
    }
    active_window_list_class::window_ID[0] = window_UID; // place window on top of list
};

//----------------------------------------------------------------------------------------------------------------

    player_stats_class::player_stats_class(void)
{
    player_stats_class::highlighted             = false;
    player_stats_class::drag                    = false;
    player_stats_class::portrait                = 0;
    player_stats_class::mouse_over              = false;
    player_stats_class::mouse_over_count        = 0;
    player_stats_class::mouse_over_health_count = 0;
    player_stats_class::mouse_over_mana_count   = 0;
    player_stats_class::tooltip_time            = 64;
    player_stats_class::tooltip_active          = false;
    player_stats_class::pos_x                   = 0.0f;
    player_stats_class::pos_y                   = 0.0f;
    player_stats_class::pos_z                   = 0.0f;
    player_stats_class::width                   = 0.0f;
    player_stats_class::height                  = 0.0f;
};

    player_stats_class::~player_stats_class(void)
{

};

void player_stats_class::process(void)
{
    if (game.core.physics.point_in_quadrangle(player_stats_class::pos_x+(player_stats_class::width/7.2f),player_stats_class::width/1.8f,player_stats_class::pos_y+(player_stats_class::height/3.6f),player_stats_class::height/6.2f,game.core.io.mouse_x,game.core.io.mouse_y)) player_stats_class::mouse_over_health_count++;
    else player_stats_class::mouse_over_health_count = 0;
    if (player_stats_class::mouse_over_health_count > player_stats_class::tooltip_time) player_stats_class::mouse_over_health_count = player_stats_class::tooltip_time;
    if (game.core.physics.point_in_quadrangle(player_stats_class::pos_x+(player_stats_class::width/7.2f),player_stats_class::width/1.8f,player_stats_class::pos_y+(player_stats_class::height/9.0f),player_stats_class::height/6.2f,game.core.io.mouse_x,game.core.io.mouse_y)) player_stats_class::mouse_over_mana_count++;
    else player_stats_class::mouse_over_mana_count = 0;
    if (player_stats_class::mouse_over_mana_count > player_stats_class::tooltip_time) player_stats_class::mouse_over_mana_count = player_stats_class::tooltip_time;
    if (game.core.physics.point_in_quadrangle(player_stats_class::pos_x,player_stats_class::width,player_stats_class::pos_y+(player_stats_class::height/4.0f),player_stats_class::height/2,game.core.io.mouse_x,game.core.io.mouse_y)) player_stats_class::mouse_over = true;
    else if (game.core.physics.point_in_circle(player_stats_class::pos_x-(player_stats_class::width/3.3f),player_stats_class::pos_y,player_stats_class::height/2.2f,game.core.io.mouse_x,game.core.io.mouse_y)) player_stats_class::mouse_over = true;
    else player_stats_class::mouse_over = false;
    if (player_stats_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            player_stats_class::pos_x = game.core.io.mouse_x;
            player_stats_class::pos_y = game.core.io.mouse_y;
        }
        else
        {
            player_stats_class::drag       = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (player_stats_class::mouse_over) && (game.core.io.mouse_button_left))//drag
        {
            game.UI.active_window_list.add_to_list(PCPROFILE_WINDOW);
            player_stats_class::drag       = true;
            game.UI.drag_in_progress       = true;
            player_stats_class::pos_x      = game.core.io.mouse_x;
            player_stats_class::pos_y      = game.core.io.mouse_y;
        }
    }
};

void player_stats_class::draw(void)
{
    float temp_float = 0.0f;
    game.texture.profile_background.draw(false,player_stats_class::pos_x-(player_stats_class::width/3.3f),player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width/2.8f,player_stats_class::height/1.1f);
    game.texture.profile_main_background.draw(false,player_stats_class::pos_x,player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width,player_stats_class::height);
    temp_float = ((player_stats_class::width/1.8f)*((float)game.player.health.current/(float)game.player.health.maximum));
    game.texture.health_bar.draw(false,player_stats_class::pos_x-(player_stats_class::width/8.0f)+(temp_float/2),player_stats_class::pos_y+(player_stats_class::height/3.6f),player_stats_class::pos_z,temp_float,player_stats_class::height/6.2f);
    temp_float = ((player_stats_class::width/1.8f)*((float)game.player.mana.current/(float)game.player.mana.maximum));
    game.texture.mana_bar.draw(false,player_stats_class::pos_x-(player_stats_class::width/8.0f)+(temp_float/2),player_stats_class::pos_y+(player_stats_class::height/9.0f),player_stats_class::pos_z,temp_float,player_stats_class::height/6.2f);
    game.texture.profile_main.draw(false,player_stats_class::pos_x,player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width,player_stats_class::height);
    player_stats_class::draw_tooltip();
};

void player_stats_class::draw_tooltip(void)
{
    if (player_stats_class::mouse_over_health_count == player_stats_class::tooltip_time) game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,(int)((game.player.health.current/game.player.health.maximum)*100),"%             ");
    if (player_stats_class::mouse_over_mana_count   == player_stats_class::tooltip_time) game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,(int)((game.player.mana.current/game.player.mana.maximum)*100),"%             ");
};

//----------------------------------------------------------------------------------------------------------------

    action_slot_class::action_slot_class(void)
{
    action_slot_class::highlighted      = false;
    action_slot_class::drag             = false;
    action_slot_class::button_type      = 0;
    action_slot_class::mouse_over       = false;
    action_slot_class::mouse_over_count = 0;
    action_slot_class::tooltip_time     = 128;
    action_slot_class::tooltip_active   = false;
    action_slot_class::pos_x            = 0.0f;
    action_slot_class::pos_y            = 0.0f;
    action_slot_class::pos_z            = 0.0f;
    action_slot_class::width            = 0.0f;
    action_slot_class::height           = 0.0f;
    action_slot_class::drag_offset_x    = 0.0f;
    action_slot_class::drag_offset_y    = 0.0f;
    action_slot_class::base_pos_x       = 0.0f;
    action_slot_class::base_pos_y       = 0.0f;
};

    action_slot_class::~action_slot_class(void)
{

};

void action_slot_class::process(void)
{
    bool discard_icon   = false;
    int  swap_button    = 0;
    int  temp_button    = 0;
    if (game.core.physics.point_in_quadrangle(action_slot_class::pos_x,action_slot_class::width,action_slot_class::pos_y,action_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y)) action_slot_class::mouse_over = true;
    else action_slot_class::mouse_over = false;
    if (action_slot_class::button_type > 0)
    {
        if (action_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                action_slot_class::pos_x = game.core.io.mouse_x + action_slot_class::drag_offset_x;
                action_slot_class::pos_y = game.core.io.mouse_y + action_slot_class::drag_offset_y;
            }
            else
            {
                discard_icon = true;
                if ((game.UI.action_bar.action_slot_01.mouse_over) && (game.UI.action_bar.action_slot_01.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_01.button_type;
                    game.UI.action_bar.action_slot_01.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_02.mouse_over) && (game.UI.action_bar.action_slot_02.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_02.button_type;
                    game.UI.action_bar.action_slot_02.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_03.mouse_over) && (game.UI.action_bar.action_slot_03.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_03.button_type;
                    game.UI.action_bar.action_slot_03.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_04.mouse_over) && (game.UI.action_bar.action_slot_04.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_04.button_type;
                    game.UI.action_bar.action_slot_04.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_05.mouse_over) && (game.UI.action_bar.action_slot_05.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_05.button_type;
                    game.UI.action_bar.action_slot_05.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_06.mouse_over) && (game.UI.action_bar.action_slot_06.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_06.button_type;
                    game.UI.action_bar.action_slot_06.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_07.mouse_over) && (game.UI.action_bar.action_slot_07.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_07.button_type;
                    game.UI.action_bar.action_slot_07.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_08.mouse_over) && (game.UI.action_bar.action_slot_08.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_08.button_type;
                    game.UI.action_bar.action_slot_08.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_09.mouse_over) && (game.UI.action_bar.action_slot_09.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_09.button_type;
                    game.UI.action_bar.action_slot_09.button_type = temp_button;
                    discard_icon = false;
                }
                if ((game.UI.action_bar.action_slot_10.mouse_over) && (game.UI.action_bar.action_slot_10.button_type != action_slot_class::button_type))
                {
                    temp_button = action_slot_class::button_type;
                    action_slot_class::button_type = game.UI.action_bar.action_slot_10.button_type;
                    game.UI.action_bar.action_slot_10.button_type = temp_button;
                    discard_icon = false;
                }
                action_slot_class::drag         = false;
                game.UI.drag_in_progress        = false;
                action_slot_class::pos_x        = action_slot_class::base_pos_x;
                action_slot_class::pos_y        = action_slot_class::base_pos_y;
                if (discard_icon) action_slot_class::button_type = 0;
            }
        }
        else
        {
            if ((!game.UI.drag_in_progress) && (action_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                action_slot_class::drag          = true;
                game.UI.drag_in_progress         = true;
                action_slot_class::base_pos_x    = action_slot_class::pos_x;
                action_slot_class::base_pos_y    = action_slot_class::pos_y;
                action_slot_class::drag_offset_x = action_slot_class::pos_x - game.core.io.mouse_x;
                action_slot_class::drag_offset_y = action_slot_class::pos_y - game.core.io.mouse_y;
            }
        }
    }
};

void action_slot_class::draw(void)
{
    switch (game.spell[action_slot_class::button_type].level)
    {
        case 1:
            draw_texture(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
            if (action_slot_class::drag) draw_texture(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
        break;
        case 2:
            draw_texture(false,game.spell[action_slot_class::button_type].image_level_2,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
            if (action_slot_class::drag) draw_texture(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
        break;
        case 3:
            if (action_slot_class::drag) draw_texture(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
        break;
        default:
        break;
    }
    if (action_slot_class::drag) game.texture.glass_cover_01.draw(false,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
    else game.texture.glass_cover_01.draw(false,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
};

void action_slot_class::draw_drag(void)
{
    switch (game.spell[action_slot_class::button_type].level)
    {
        case 1:
            draw_texture(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);        break;
        case 2:
            draw_texture(false,game.spell[action_slot_class::button_type].image_level_2,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);        break;
        break;
        case 3:
            draw_texture(false,game.spell[action_slot_class::button_type].image_level_3,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);        break;
        break;
        default:
        break;
    }
};

void action_slot_class::draw_tooltip(void)
{

};

//----------------------------------------------------------------------------------------------------------------

    menu_slot_class::menu_slot_class(void)
{
    menu_slot_class::click_delay       = 32;
    menu_slot_class::click_delay_count = 0;
    menu_slot_class::highlighted       = false;
    menu_slot_class::drag              = false;
    menu_slot_class::button_type       = 0;
    menu_slot_class::mouse_over        = false;
    menu_slot_class::mouse_over_count  = 0;
    menu_slot_class::tooltip_time      = 64;
    menu_slot_class::tooltip_active    = false;
    menu_slot_class::pos_x             = 0.0f;
    menu_slot_class::pos_y             = 0.0f;
    menu_slot_class::pos_z             = 0.0f;
    menu_slot_class::base_pos_x        = 0.0f;
    menu_slot_class::base_pos_y        = 0.0f;
    menu_slot_class::width             = 0.0f;
    menu_slot_class::height            = 0.0f;
};

    menu_slot_class::~menu_slot_class(void)
{

};

void menu_slot_class::process(void)
{
    int  swap_button = 0;
    int  temp_button = 0;
    if (menu_slot_class::mouse_over) // timers
    {
        menu_slot_class::click_delay_count++;
        menu_slot_class::mouse_over_count++;
    }
    else
    {
        menu_slot_class::mouse_over_count = 0;
        menu_slot_class::click_delay_count = 0;
    }
    if (menu_slot_class::mouse_over_count > menu_slot_class::tooltip_time) menu_slot_class::mouse_over_count = menu_slot_class::tooltip_time;
    if (menu_slot_class::click_delay_count > menu_slot_class::click_delay) menu_slot_class::click_delay_count = menu_slot_class::click_delay;
    if (game.core.physics.point_in_circle(menu_slot_class::pos_x,menu_slot_class::pos_y,(menu_slot_class::height/2),game.core.io.mouse_x,game.core.io.mouse_y)) menu_slot_class::mouse_over = true;
    else menu_slot_class::mouse_over = false;
    if ((!game.UI.drag_in_progress) && (menu_slot_class::mouse_over) && (game.core.io.mouse_button_left) && (menu_slot_class::click_delay_count == menu_slot_class::click_delay))
    {
        menu_slot_class::click_delay_count = 0;
        switch (menu_slot_class::button_type) // process mouse click
        {
            case MAIN_MENU_WINDOW: // main menu
                if (!game.core.menu_active)
                {
                    game.UI.active_window_list.add_to_list(MAIN_MENU_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.menu_level              = 1;
                    game.core.menu_active             = true;
                    game.core.io.escape               = false;
                    game.core.io.keyboard_delay_count = 0;
                    game.core.config.menu_delay_count = 0;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.menu_level              = 1;
                    game.core.menu_active             = false;
                    game.core.io.escape               = false;
                    game.core.io.keyboard_delay_count = 0;
                    game.core.config.menu_delay_count = 0;
                }
            break;
            case UNKNOWN___WINDOW: // NA??
                if (!game.core.menu_active)
                {
                    game.UI.active_window_list.add_to_list(UNKNOWN___WINDOW);
                    game.sound.menu_select_00.play();
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(UNKNOWN___WINDOW);
                    game.sound.menu_select_00.play();
                }
            break;
            case QUEST_LOG_WINDOW: // Quest Log
                if (!game.core.quest_log_active)
                {
                    game.UI.active_window_list.add_to_list(QUEST_LOG_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.quest_log_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(QUEST_LOG_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.quest_log_active        = false;
                }
            break;
            case CHARACTER_WINDOW: // Character Menu
                if (!game.core.character_active)
                {
                    game.UI.active_window_list.add_to_list(CHARACTER_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.character_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(CHARACTER_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.character_active        = false;
                }
            break;
            case INVENTORY_WINDOW: // Inventory
                if (!game.core.inventory_active)
                {
                    game.UI.active_window_list.add_to_list(INVENTORY_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.inventory_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(INVENTORY_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.inventory_active        = false;
                }
            break;
            case SPELLBOOK_WINDOW: // Spell Book
                if (!game.core.spellbook_active)
                {
                    game.UI.active_window_list.add_to_list(SPELLBOOK_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.spellbook_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(SPELLBOOK_WINDOW);
                    game.sound.menu_select_00.play();
                    game.core.spellbook_active        = false;
                }
            break;
            default:
            break;
        }
    }
    if (menu_slot_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            menu_slot_class::pos_x = game.core.io.mouse_x;
            menu_slot_class::pos_y = game.core.io.mouse_y;
        }
        else
        {
            if ((game.UI.action_bar.menu_slot_01.mouse_over) && (game.UI.action_bar.menu_slot_01.button_type != menu_slot_class::button_type))
            {
                temp_button = menu_slot_class::button_type;
                menu_slot_class::button_type = game.UI.action_bar.menu_slot_01.button_type;
                game.UI.action_bar.menu_slot_01.button_type = temp_button;
            }
            if ((game.UI.action_bar.menu_slot_02.mouse_over) && (game.UI.action_bar.menu_slot_02.button_type != menu_slot_class::button_type))
            {
                temp_button = menu_slot_class::button_type;
                menu_slot_class::button_type = game.UI.action_bar.menu_slot_02.button_type;
                game.UI.action_bar.menu_slot_02.button_type = temp_button;
            }
            if ((game.UI.action_bar.menu_slot_03.mouse_over) && (game.UI.action_bar.menu_slot_03.button_type != menu_slot_class::button_type))
            {
                temp_button = menu_slot_class::button_type;
                menu_slot_class::button_type = game.UI.action_bar.menu_slot_03.button_type;
                game.UI.action_bar.menu_slot_03.button_type = temp_button;
            }
            if ((game.UI.action_bar.menu_slot_04.mouse_over) && (game.UI.action_bar.menu_slot_04.button_type != menu_slot_class::button_type))
            {
                temp_button = menu_slot_class::button_type;
                menu_slot_class::button_type = game.UI.action_bar.menu_slot_04.button_type;
                game.UI.action_bar.menu_slot_04.button_type = temp_button;
            }
            if ((game.UI.action_bar.menu_slot_05.mouse_over) && (game.UI.action_bar.menu_slot_05.button_type != menu_slot_class::button_type))
            {
                temp_button = menu_slot_class::button_type;
                menu_slot_class::button_type = game.UI.action_bar.menu_slot_05.button_type;
                game.UI.action_bar.menu_slot_05.button_type = temp_button;
            }
            if ((game.UI.action_bar.menu_slot_06.mouse_over) && (game.UI.action_bar.menu_slot_06.button_type != menu_slot_class::button_type))
            {
                temp_button = menu_slot_class::button_type;
                menu_slot_class::button_type = game.UI.action_bar.menu_slot_06.button_type;
                game.UI.action_bar.menu_slot_06.button_type = temp_button;
            }
            menu_slot_class::drag       = false;
            game.UI.drag_in_progress    = false;
            menu_slot_class::pos_x      = menu_slot_class::base_pos_x;
            menu_slot_class::pos_y      = menu_slot_class::base_pos_y;
        }
    }
    else
    {
        if (menu_slot_class::mouse_over_count >= menu_slot_class::tooltip_time)
        {
            if ((!game.UI.drag_in_progress) && (menu_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                menu_slot_class::base_pos_x = menu_slot_class::pos_x;
                menu_slot_class::base_pos_y = menu_slot_class::pos_y;
                menu_slot_class::drag       = true;
                game.UI.drag_in_progress    = true;
                menu_slot_class::pos_x      = game.core.io.mouse_x;
                menu_slot_class::pos_y      = game.core.io.mouse_y;
            }
        }
    }
};

void menu_slot_class::draw(void)
{
    if (menu_slot_class::button_type == 1) game.texture.icon_01.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 2) game.texture.icon_02.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 3) game.texture.icon_03.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 4) game.texture.icon_04.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 5) game.texture.icon_05.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 6) game.texture.icon_06.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    game.texture.glass_cover_02.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
};

void menu_slot_class::draw_tooltip(void)
{
    if (menu_slot_class::mouse_over_count == menu_slot_class::tooltip_time)
    {
        switch (menu_slot_class::button_type) // display tool tip
        {
            case 1: // main menu
                game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.main_menu);
            break;
            case 2: // NA??
                game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.menu_item_unavailable);
            break;
            case 3: // Quest Log
                game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.quest_log);
            break;
            case 4: // Character Menu
                game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.character_menu);
            break;
            case 5: // Inventory
                game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.inventory);
            break;
            case 6: // Spell Book
                game.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.spell_book);
            default:
            break;
        }
    }
};

//----------------------------------------------------------------------------------------------------------------

    action_bar_class::action_bar_class(void)
{
    action_bar_class::pos_x            = 0.0f;
    action_bar_class::pos_y            = 0.0f;
    action_bar_class::pos_z            = 0.0f;
    action_bar_class::width            = 0.0f;
    action_bar_class::height           = 0.0f;
};

    action_bar_class::~action_bar_class(void)
{

};

void action_bar_class::process(void)
{
    action_bar_class::menu_slot_01.process();
    action_bar_class::menu_slot_02.process();
    action_bar_class::menu_slot_03.process();
    action_bar_class::menu_slot_04.process();
    action_bar_class::menu_slot_05.process();
    action_bar_class::menu_slot_06.process();
    action_bar_class::action_slot_01.process();
    action_bar_class::action_slot_02.process();
    action_bar_class::action_slot_03.process();
    action_bar_class::action_slot_04.process();
    action_bar_class::action_slot_05.process();
    action_bar_class::action_slot_06.process();
    action_bar_class::action_slot_07.process();
    action_bar_class::action_slot_08.process();
    action_bar_class::action_slot_09.process();
    action_bar_class::action_slot_10.process();
};

void action_bar_class::draw(void)
{
    game.texture.action_bar.draw(false,action_bar_class::pos_x,action_bar_class::pos_y,action_bar_class::pos_z,action_bar_class::width,action_bar_class::height);
    action_bar_class::action_slot_01.draw();
    action_bar_class::action_slot_02.draw();
    action_bar_class::action_slot_03.draw();
    action_bar_class::action_slot_04.draw();
    action_bar_class::action_slot_05.draw();
    action_bar_class::action_slot_06.draw();
    action_bar_class::action_slot_07.draw();
    action_bar_class::action_slot_08.draw();
    action_bar_class::action_slot_09.draw();
    action_bar_class::action_slot_10.draw();
    game.texture.action_bar_front.draw(false,action_bar_class::pos_x,action_bar_class::pos_y,action_bar_class::pos_z,action_bar_class::width,action_bar_class::height);
    action_bar_class::menu_slot_01.draw();
    action_bar_class::menu_slot_02.draw();
    action_bar_class::menu_slot_03.draw();
    action_bar_class::menu_slot_04.draw();
    action_bar_class::menu_slot_05.draw();
    action_bar_class::menu_slot_06.draw();
    if (action_bar_class::menu_slot_01.drag) action_bar_class::menu_slot_01.draw();
    if (action_bar_class::menu_slot_02.drag) action_bar_class::menu_slot_02.draw();
    if (action_bar_class::menu_slot_03.drag) action_bar_class::menu_slot_03.draw();
    if (action_bar_class::menu_slot_04.drag) action_bar_class::menu_slot_04.draw();
    if (action_bar_class::menu_slot_05.drag) action_bar_class::menu_slot_05.draw();
    if (action_bar_class::menu_slot_06.drag) action_bar_class::menu_slot_06.draw();
    action_bar_class::menu_slot_01.draw_tooltip();
    action_bar_class::menu_slot_02.draw_tooltip();
    action_bar_class::menu_slot_03.draw_tooltip();
    action_bar_class::menu_slot_04.draw_tooltip();
    action_bar_class::menu_slot_05.draw_tooltip();
    action_bar_class::menu_slot_06.draw_tooltip();
    action_bar_class::action_slot_01.draw_tooltip();
    action_bar_class::action_slot_02.draw_tooltip();
    action_bar_class::action_slot_03.draw_tooltip();
    action_bar_class::action_slot_04.draw_tooltip();
    action_bar_class::action_slot_05.draw_tooltip();
    action_bar_class::action_slot_06.draw_tooltip();
    action_bar_class::action_slot_07.draw_tooltip();
    action_bar_class::action_slot_08.draw_tooltip();
    action_bar_class::action_slot_09.draw_tooltip();
    action_bar_class::action_slot_10.draw_tooltip();
    if (game.UI.spell_book.spell_slot_01.drag) game.UI.spell_book.spell_slot_01.draw_drag();
    if (game.UI.spell_book.spell_slot_02.drag) game.UI.spell_book.spell_slot_02.draw_drag();
    if (game.UI.spell_book.spell_slot_03.drag) game.UI.spell_book.spell_slot_03.draw_drag();
    if (game.UI.spell_book.spell_slot_04.drag) game.UI.spell_book.spell_slot_04.draw_drag();
    if (game.UI.spell_book.spell_slot_05.drag) game.UI.spell_book.spell_slot_05.draw_drag();
    if (game.UI.spell_book.spell_slot_06.drag) game.UI.spell_book.spell_slot_06.draw_drag();
    if (game.UI.spell_book.spell_slot_07.drag) game.UI.spell_book.spell_slot_07.draw_drag();
    if (game.UI.spell_book.spell_slot_08.drag) game.UI.spell_book.spell_slot_08.draw_drag();
    if (game.UI.spell_book.spell_slot_09.drag) game.UI.spell_book.spell_slot_09.draw_drag();
    if (game.UI.spell_book.spell_slot_10.drag) game.UI.spell_book.spell_slot_10.draw_drag();
    if (game.UI.spell_book.spell_slot_11.drag) game.UI.spell_book.spell_slot_11.draw_drag();
    if (game.UI.spell_book.spell_slot_12.drag) game.UI.spell_book.spell_slot_12.draw_drag();
    if (game.UI.spell_book.spell_slot_13.drag) game.UI.spell_book.spell_slot_13.draw_drag();
    if (game.UI.spell_book.spell_slot_14.drag) game.UI.spell_book.spell_slot_14.draw_drag();
    if (game.UI.spell_book.spell_slot_15.drag) game.UI.spell_book.spell_slot_15.draw_drag();
    if (game.UI.spell_book.spell_slot_16.drag) game.UI.spell_book.spell_slot_16.draw_drag();
    if (game.UI.spell_book.spell_slot_17.drag) game.UI.spell_book.spell_slot_17.draw_drag();
    if (game.UI.spell_book.spell_slot_18.drag) game.UI.spell_book.spell_slot_18.draw_drag();
    if (game.UI.spell_book.spell_slot_19.drag) game.UI.spell_book.spell_slot_19.draw_drag();
    if (game.UI.spell_book.spell_slot_20.drag) game.UI.spell_book.spell_slot_20.draw_drag();
    if (action_bar_class::action_slot_01.drag) action_bar_class::action_slot_01.draw_drag();
    if (action_bar_class::action_slot_02.drag) action_bar_class::action_slot_02.draw_drag();
    if (action_bar_class::action_slot_03.drag) action_bar_class::action_slot_03.draw_drag();
    if (action_bar_class::action_slot_04.drag) action_bar_class::action_slot_04.draw_drag();
    if (action_bar_class::action_slot_05.drag) action_bar_class::action_slot_05.draw_drag();
    if (action_bar_class::action_slot_06.drag) action_bar_class::action_slot_06.draw_drag();
    if (action_bar_class::action_slot_07.drag) action_bar_class::action_slot_07.draw_drag();
    if (action_bar_class::action_slot_08.drag) action_bar_class::action_slot_08.draw_drag();
    if (action_bar_class::action_slot_09.drag) action_bar_class::action_slot_09.draw_drag();
    if (action_bar_class::action_slot_10.drag) action_bar_class::action_slot_10.draw_drag();
};

//----------------------------------------------------------------------------------------------------------------
    UI_class::UI_class(void)
{
    UI_class::drag_in_progress                      =  false;
    UI_class::action_bar.width                      =  1.2f;
    UI_class::action_bar.height                     =  UI_class::action_bar.width/10.0f;
    UI_class::action_bar.pos_x                      =  0.0f;
    UI_class::action_bar.pos_y                      = -1.0f + (UI_class::action_bar.height/2);
    UI_class::action_bar.pos_z                      =  0.001f;
    UI_class::action_bar.menu_slot_01.button_type   =  1;
    UI_class::action_bar.menu_slot_01.pos_x         =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/2.282f);
    UI_class::action_bar.menu_slot_01.pos_y         =  UI_class::action_bar.pos_y - (UI_class::action_bar.height/16.0f);
    UI_class::action_bar.menu_slot_01.pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot_01.width         =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_01.height        =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_01.base_pos_x    =  UI_class::action_bar.menu_slot_01.pos_x;
    UI_class::action_bar.menu_slot_01.base_pos_y    =  UI_class::action_bar.menu_slot_01.pos_y;
    UI_class::action_bar.menu_slot_01.drag          =  false;
    UI_class::action_bar.menu_slot_02.button_type   =  2;
    UI_class::action_bar.menu_slot_02.pos_x         =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/2.620f);
    UI_class::action_bar.menu_slot_02.pos_y         = -1.0f + (UI_class::action_bar.height/2.4);
    UI_class::action_bar.menu_slot_02.pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot_02.width         =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_02.height        =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_02.base_pos_x    =  UI_class::action_bar.menu_slot_02.pos_x;
    UI_class::action_bar.menu_slot_02.base_pos_y    =  UI_class::action_bar.menu_slot_02.pos_y;
    UI_class::action_bar.menu_slot_02.drag          =  false;
    UI_class::action_bar.menu_slot_03.button_type   =  3;
    UI_class::action_bar.menu_slot_03.pos_x         =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/3.062f);
    UI_class::action_bar.menu_slot_03.pos_y         = -1.0f + (UI_class::action_bar.height/2.4);
    UI_class::action_bar.menu_slot_03.pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot_03.width         =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_03.height        =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_03.base_pos_x    =  UI_class::action_bar.menu_slot_03.pos_x;
    UI_class::action_bar.menu_slot_03.base_pos_y    =  UI_class::action_bar.menu_slot_03.pos_y;
    UI_class::action_bar.menu_slot_03.drag          =  false;
    UI_class::action_bar.menu_slot_04.button_type   =  4;
    UI_class::action_bar.menu_slot_04.pos_x         =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/3.010f);
    UI_class::action_bar.menu_slot_04.pos_y         = -1.0f + (UI_class::action_bar.height/2.4);
    UI_class::action_bar.menu_slot_04.pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot_04.width         =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_04.height        =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_04.base_pos_x    =  UI_class::action_bar.menu_slot_04.pos_x;
    UI_class::action_bar.menu_slot_04.base_pos_y    =  UI_class::action_bar.menu_slot_04.pos_y;
    UI_class::action_bar.menu_slot_04.drag          =  false;
    UI_class::action_bar.menu_slot_05.button_type   =  5;
    UI_class::action_bar.menu_slot_05.pos_x         =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/2.572f);
    UI_class::action_bar.menu_slot_05.pos_y         = -1.0f + (UI_class::action_bar.height/2.4);
    UI_class::action_bar.menu_slot_05.pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot_05.width         =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_05.height        =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_05.base_pos_x    =  UI_class::action_bar.menu_slot_05.pos_x;
    UI_class::action_bar.menu_slot_05.base_pos_y    =  UI_class::action_bar.menu_slot_05.pos_y;
    UI_class::action_bar.menu_slot_05.drag          =  false;
    UI_class::action_bar.menu_slot_06.button_type   =  6;
    UI_class::action_bar.menu_slot_06.pos_x         =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/2.250f);
    UI_class::action_bar.menu_slot_06.pos_y         = -1.0f + (UI_class::action_bar.height/2.4);
    UI_class::action_bar.menu_slot_06.pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot_06.width         =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_06.height        =  UI_class::action_bar.height/2.34f;
    UI_class::action_bar.menu_slot_06.base_pos_x    =  UI_class::action_bar.menu_slot_06.pos_x;
    UI_class::action_bar.menu_slot_06.base_pos_y    =  UI_class::action_bar.menu_slot_06.pos_y;
    UI_class::action_bar.menu_slot_06.drag          =  false;

    UI_class::action_bar.action_slot_01.button_type =  0;
    UI_class::action_bar.action_slot_01.pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/3.970f);
    UI_class::action_bar.action_slot_01.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_01.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_01.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_01.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_02.button_type =  0;
    UI_class::action_bar.action_slot_02.pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/5.100f);
    UI_class::action_bar.action_slot_02.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_02.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_02.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_02.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_03.button_type =  0;
    UI_class::action_bar.action_slot_03.pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/7.120f);
    UI_class::action_bar.action_slot_03.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_03.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_03.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_03.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_04.button_type =  0;
    UI_class::action_bar.action_slot_04.pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/12.000f);
    UI_class::action_bar.action_slot_04.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_04.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_04.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_04.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_05.button_type =  0;
    UI_class::action_bar.action_slot_05.pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/36.600f);
    UI_class::action_bar.action_slot_05.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_05.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_05.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_05.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_06.button_type =  0;
    UI_class::action_bar.action_slot_06.pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/35.000f);
    UI_class::action_bar.action_slot_06.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_06.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_06.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_06.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_07.button_type =  0;
    UI_class::action_bar.action_slot_07.pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/11.700f);
    UI_class::action_bar.action_slot_07.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_07.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_07.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_07.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_08.button_type =  0;
    UI_class::action_bar.action_slot_08.pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/7.060f);
    UI_class::action_bar.action_slot_08.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_08.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_08.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_08.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_09.button_type =  0;
    UI_class::action_bar.action_slot_09.pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/5.054f);
    UI_class::action_bar.action_slot_09.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_09.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_09.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_09.width       =  UI_class::action_bar.action_slot_01.height/1.450f;
    UI_class::action_bar.action_slot_10.button_type =  1;
    UI_class::action_bar.action_slot_10.pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/3.940f);
    UI_class::action_bar.action_slot_10.pos_y       = -1.0f + (UI_class::action_bar.height/2.00f);
    UI_class::action_bar.action_slot_10.pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot_10.height      =  UI_class::action_bar.height/1.34f;
    UI_class::action_bar.action_slot_10.width       =  UI_class::action_bar.action_slot_01.height/1.450f;

    UI_class::active_window_list.add_to_list(PCPROFILE_WINDOW);
    UI_class::player_stats.portrait                 =  0;
    UI_class::player_stats.pos_x                    = -0.8f;
    UI_class::player_stats.pos_y                    =  0.88f;
    UI_class::player_stats.pos_z                    =  0.001f;
    UI_class::player_stats.width                    =  0.4f;
    UI_class::player_stats.height                   =  0.24f;
};

    UI_class::~UI_class(void)
{

};

void UI_class::process(void)
{
    for (int awl_count = 0; awl_count < MAX_ACTIVE_WINDOWS; awl_count++)
    {
        switch (UI_class::active_window_list.window_ID[awl_count])
        {
            case MAIN_MENU_WINDOW:
                if (game.core.menu_active)      process_menu ();
            break;
            case UNKNOWN___WINDOW:
            break;
            case QUEST_LOG_WINDOW:
                if (game.core.quest_log_active) UI_class::quest_log.process();
            break;
            case CHARACTER_WINDOW:
                if (game.core.character_active) UI_class::character.process();
            break;
            case INVENTORY_WINDOW:
                if (game.core.inventory_active) UI_class::inventory.process();
            break;
            case SPELLBOOK_WINDOW:
                if (game.core.spellbook_active) UI_class::spell_book.process();
            break;
            case PCPROFILE_WINDOW:
                UI_class::player_stats.process();
            break;
            default:
            break;
        };
    };
    UI_class::action_bar.process();
};

void UI_class::draw(void)
{
    for (int awl_count = MAX_ACTIVE_WINDOWS; awl_count >= 0; awl_count--)
    {
        switch (UI_class::active_window_list.window_ID[awl_count])
        {
            case MAIN_MENU_WINDOW:
                if (game.core.menu_active)      diplay_menu ();
            break;
            case UNKNOWN___WINDOW:
            break;
            case QUEST_LOG_WINDOW:
                if (game.core.quest_log_active) UI_class::quest_log.draw();
            break;
            case CHARACTER_WINDOW:
                if (game.core.character_active) UI_class::character.draw();
            break;
            case INVENTORY_WINDOW:
                if (game.core.inventory_active) UI_class::inventory.draw();
            break;
            case SPELLBOOK_WINDOW:
                if (game.core.spellbook_active) UI_class::spell_book.draw();
            break;
            case PCPROFILE_WINDOW:
                UI_class::player_stats.draw();
            break;
            default:
            break;
        };
    };
    UI_class::action_bar.draw();
};

