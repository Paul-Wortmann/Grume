/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include "core/misc.hpp"

extern game_class game;

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
    for (int awl_count = MAX_ACTIVE_WINDOWS-1; awl_count > 0; awl_count--) //shift stack down
    {
        active_window_list_class::window_ID[awl_count] = active_window_list_class::window_ID[awl_count-1];
    }
    active_window_list_class::window_ID[0] = window_UID; // place window on top of list
};

//----------------------------------------------------------------------------------------------------------------

    player_stats_class::player_stats_class(void)
{
    player_stats_class::highlighted               = false;
    player_stats_class::drag                      = false;
    player_stats_class::portrait                  = 0;
    player_stats_class::mouse_over                = false;
    player_stats_class::mouse_over_count          = 0;
    player_stats_class::mouse_over_health_count   = 0;
    player_stats_class::mouse_over_mana_count     = 0;
    player_stats_class::mouse_over_portrait_count = 0;
    player_stats_class::tooltip_time              = 64;
    player_stats_class::tooltip_active            = false;
    player_stats_class::pos_x                     = 0.0f;
    player_stats_class::pos_y                     = 0.0f;
    player_stats_class::pos_z                     = 0.0f;
    player_stats_class::width                     = 0.0f;
    player_stats_class::height                    = 0.0f;
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
    if (game.core.physics.point_in_circle(player_stats_class::pos_x-(player_stats_class::width/3.3f),player_stats_class::pos_y,player_stats_class::width/4.8f,game.core.io.mouse_x,game.core.io.mouse_y)) player_stats_class::mouse_over_portrait_count++;
    else player_stats_class::mouse_over_portrait_count = 0;
    if (player_stats_class::mouse_over_portrait_count > player_stats_class::tooltip_time) player_stats_class::mouse_over_portrait_count = player_stats_class::tooltip_time;
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
    game.resource.texture.profile_background.draw(false,player_stats_class::pos_x-(player_stats_class::width/3.3f),player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width/2.8f,player_stats_class::height/1.1f);
    game.resource.texture.profile_main_background.draw(false,player_stats_class::pos_x,player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width,player_stats_class::height);
    game.resource.texture.render(false,game.player.portrait_image_ref,player_stats_class::pos_x-(player_stats_class::width/3.3f),player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width/4.2f,player_stats_class::height/1.6f);
    temp_float = ((player_stats_class::width/1.8f)*((float)game.player.health.current/(float)game.player.health.maximum));
    game.resource.texture.health_bar.draw(false,player_stats_class::pos_x-(player_stats_class::width/8.0f)+(temp_float/2),player_stats_class::pos_y+(player_stats_class::height/3.6f),player_stats_class::pos_z,temp_float,player_stats_class::height/6.2f);
    temp_float = ((player_stats_class::width/1.8f)*((float)game.player.mana.current/(float)game.player.mana.maximum));
    game.resource.texture.mana_bar.draw(false,player_stats_class::pos_x-(player_stats_class::width/8.0f)+(temp_float/2),player_stats_class::pos_y+(player_stats_class::height/9.0f),player_stats_class::pos_z,temp_float,player_stats_class::height/6.2f);
    game.resource.texture.profile_main.draw(false,player_stats_class::pos_x,player_stats_class::pos_y,player_stats_class::pos_z,player_stats_class::width,player_stats_class::height);
    player_stats_class::draw_tooltip();
};

void player_stats_class::draw_tooltip(void)
{
    if (player_stats_class::mouse_over_health_count     == player_stats_class::tooltip_time) game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,(int)((game.player.health.current/game.player.health.maximum)*100),"%             ");
    if (player_stats_class::mouse_over_mana_count       == player_stats_class::tooltip_time) game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,(int)((game.player.mana.current/game.player.mana.maximum)*100),"%             ");
    if (player_stats_class::mouse_over_portrait_count   == player_stats_class::tooltip_time) game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.player.name,"         ");
};

//----------------------------------------------------------------------------------------------------------------

    action_slot_class::action_slot_class(void)
{
    action_slot_class::current_item     = 0;
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
    int  temp_ID  = 0;
    int  temp_int = 0;
    if  (action_slot_class::current_item != game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type) action_slot_class::button_type = 0;
    bool discard_icon   = false;
    int  temp_button    = 0;
    int  temp_item      = 0;
    if  (game.core.physics.point_in_quadrangle(action_slot_class::pos_x,action_slot_class::width,action_slot_class::pos_y,action_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y)) action_slot_class::mouse_over = true;
    else action_slot_class::mouse_over = false;
    if  (action_slot_class::mouse_over)
    {
        action_slot_class::mouse_over_count++;
        if (action_slot_class::mouse_over_count > action_slot_class::tooltip_time) action_slot_class::mouse_over_count = action_slot_class::tooltip_time;
    }
    else action_slot_class::mouse_over_count = 0;
    if  (action_slot_class::button_type > 0)
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
                for (int action_slot_count = 1; action_slot_count < MAX_ACTION_SLOTS; action_slot_count++)
                {
                    if ((game.UI.action_bar.action_slot[action_slot_count].mouse_over) && (game.UI.action_bar.action_slot[action_slot_count].button_type != action_slot_class::button_type))
                    {
                        temp_ID = game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type;
                        temp_button = action_slot_class::button_type;
                        action_slot_class::button_type = game.UI.action_bar.action_slot[action_slot_count].button_type;
                        game.UI.action_bar.action_slot[action_slot_count].button_type = temp_button;
                        temp_item = action_slot_class::current_item;
                        action_slot_class::current_item = game.UI.action_bar.action_slot[action_slot_count].current_item;
                        game.UI.action_bar.action_slot[action_slot_count].current_item = temp_item;
                        if (temp_button < 1000) // move spell
                        {

                        }
                        else if (temp_button > 1000) // move item
                        {
                            if (game.item[temp_ID].sound.quantity_relocate > 0)
                            {
                                if (game.item[temp_ID].sound.quantity_relocate == 1) temp_int = 0;
                                else temp_int = random(game.item[temp_ID].sound.quantity_relocate);
                                if (temp_int > game.item[temp_ID].sound.quantity_relocate-1) temp_int = game.item[temp_ID].sound.quantity_relocate-1;
                                if (temp_int < 0) temp_int = 0;
                                game.resource.sound.play(game.item[temp_ID].sound.relocate[temp_int]);
                            }
                        }
                        discard_icon = false;
                    }
                    if (game.UI.action_bar.action_slot[action_slot_count].button_type == action_slot_class::button_type) discard_icon = false;
                }
                if ((discard_icon) && (game.core.physics.point_in_quadrangle(game.UI.action_bar.pos_x,game.UI.action_bar.width,game.UI.action_bar.pos_y,game.UI.action_bar.height,game.core.io.mouse_x,game.core.io.mouse_y))) discard_icon = false;
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
        if ((action_slot_class::mouse_over) && (game.core.io.mouse_button_right) && (game.core.io.mouse_button_ready))//use item
        {
            game.core.io.mouse_button_delay_count = 0;
            if (action_slot_class::button_type < 1000) // use spell
            {

            }
            else if (action_slot_class::button_type > 1000) // use item
            {
                bool play_use_sound = true;
                temp_ID = game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type;
                switch (game.item[temp_ID].type)
                {
                    case HEALTH_POTION:
                        if (game.player.health.current < game.player.health.maximum)
                        {
                            game.player.health.current += game.item[temp_ID].add_health;
                            game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].quantity--;
                            if(game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].quantity <= 0) game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type = 0;
                        }
                        else play_use_sound = false;
                    break;
                    case MANA_POTION:
                        if (game.player.mana.current < game.player.mana.maximum)
                        {
                            game.player.mana.current += game.item[temp_ID].add_mana;
                            game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].quantity--;
                            if(game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].quantity <= 0)game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type = 0;
                        }
                        else play_use_sound = false;
                    break;
                    default:
                    break;
                }
            if (play_use_sound)
            {
                temp_ID = game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type;
                if (game.item[temp_ID].sound.quantity_use > 0)
                {
                    if (game.item[temp_ID].sound.quantity_use == 1) temp_int = 0;
                    else temp_int = random(game.item[temp_ID].sound.quantity_use);
                    if (temp_int > game.item[temp_ID].sound.quantity_use-1) temp_int = game.item[temp_ID].sound.quantity_use-1;
                    if (temp_int < 0) temp_int = 0;
                    game.resource.sound.play(game.item[temp_ID].sound.use[temp_int]);
                }
            }
            }
        }
    }
};

void action_slot_class::draw(void)
{
    if (action_slot_class::button_type > 1000)
    {
        int image_ref = game.item[game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type].image_ref;
        game.resource.texture.render(false,image_ref,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
    }
    else
    {
        switch (game.spell[action_slot_class::button_type].level)
        {
            case 1:
                game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
                if (action_slot_class::drag) game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
            break;
            case 2:
                game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_2,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
                if (action_slot_class::drag) game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_2,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
            break;
            case 3:
                game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_3,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
                if (action_slot_class::drag) game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_3,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
            break;
            default:
            break;
        }
    }
    if (action_slot_class::drag) game.resource.texture.glass_cover_01.draw(false,action_slot_class::base_pos_x,action_slot_class::base_pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
    else game.resource.texture.glass_cover_01.draw(false,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
};

void action_slot_class::draw_drag(void)
{
    if (action_slot_class::button_type > 1000)
    {
        int image_ref = game.item[game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type].image_ref;
        game.resource.texture.render(false,image_ref,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);
    }
    switch (game.spell[action_slot_class::button_type].level)
    {
        case 1:
            game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_1,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);        break;
        case 2:
            game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_2,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);        break;
        break;
        case 3:
            game.resource.texture.render(false,game.spell[action_slot_class::button_type].image_level_3,action_slot_class::pos_x,action_slot_class::pos_y,action_slot_class::pos_z,action_slot_class::width,action_slot_class::height);        break;
        break;
        default:
        break;
    }
};

void action_slot_class::draw_tooltip(void)
{
    if ((action_slot_class::button_type > 0) && (!action_slot_class::drag) && (action_slot_class::mouse_over_count == action_slot_class::tooltip_time))
    {
        std::string text_padding    = "";
        int         number_of_lines = 1;
        float       line_height     = 0.04f;
        float       width           = line_height*7.4f;
        float       height          = line_height*number_of_lines+(line_height/4);
        float       x_pos           = game.core.io.mouse_x+line_height;
        float       y_pos           = game.core.io.mouse_y-line_height;
        game.resource.texture.item_stat_background.draw(false,game.core.io.mouse_x+(width/2),game.core.io.mouse_y-(height/2),action_slot_class::pos_z,width,height);
        if (action_slot_class::button_type > 1000) game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,game.item[game.UI.inventory.inventory_slot[action_slot_class::button_type-1000].button_type].name);
        if (action_slot_class::button_type < 1000) game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,game.spell[action_slot_class::button_type].name);
    }
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
                if (!game.core.game_menu_active)
                {
                    game.UI.active_window_list.add_to_list(MAIN_MENU_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.menu.level              = 1;
                    game.core.game_menu_active        = true;
                    game.core.io.key_escape           = false;
                    game.core.io.keyboard_delay_count = 0;
                    game.core.config.menu_delay_count = 0;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.menu.level              = 1;
                    game.core.game_menu_active        = false;
                    game.core.io.key_escape           = false;
                    game.core.io.keyboard_delay_count = 0;
                    game.core.config.menu_delay_count = 0;
                }
            break;
            case EQUIPMENT_WINDOW: // Equipment Menu
                if (!game.core.equipment_active)
                {
                    game.UI.active_window_list.add_to_list(EQUIPMENT_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.equipment_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(EQUIPMENT_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.equipment_active        = false;
                }
            break;
            case QUEST_LOG_WINDOW: // Quest Log
                if (!game.core.quest_log_active)
                {
                    game.UI.active_window_list.add_to_list(QUEST_LOG_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.quest_log_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(QUEST_LOG_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.quest_log_active        = false;
                }
            break;
            case CHARACTER_WINDOW: // Character Menu
                if (!game.core.character_active)
                {
                    game.UI.active_window_list.add_to_list(CHARACTER_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.character_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(CHARACTER_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.character_active        = false;
                }
            break;
            case INVENTORY_WINDOW: // Inventory
                if (!game.core.inventory_active)
                {
                    game.UI.active_window_list.add_to_list(INVENTORY_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.inventory_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(INVENTORY_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.inventory_active        = false;
                }
            break;
            case SPELLBOOK_WINDOW: // Spell Book
                if (!game.core.spellbook_active)
                {
                    game.UI.active_window_list.add_to_list(SPELLBOOK_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.spellbook_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(SPELLBOOK_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.spellbook_active        = false;
                }
            break;
            case NPCVENDOR_WINDOW: // Vendor
                if (!game.core.npcvendor_active)
                {
                    game.UI.active_window_list.add_to_list(NPCVENDOR_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.npcvendor_active        = true;
                }
                else
                {
                    game.UI.active_window_list.remove_from_list(NPCVENDOR_WINDOW);
                    game.resource.sound.menu_select_00.play();
                    game.core.npcvendor_active        = false;
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
            for (int action_menu_slot_count = 1; action_menu_slot_count < MAX_ACTION_MENU_SLOTS; action_menu_slot_count++)
            {
                if ((game.UI.action_bar.menu_slot[action_menu_slot_count].mouse_over) && (game.UI.action_bar.menu_slot[action_menu_slot_count].button_type != menu_slot_class::button_type))
                {
                    temp_button = menu_slot_class::button_type;
                    menu_slot_class::button_type = game.UI.action_bar.menu_slot[action_menu_slot_count].button_type;
                    game.UI.action_bar.menu_slot[action_menu_slot_count].button_type = temp_button;
                }
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
    if (menu_slot_class::button_type == 1) game.resource.texture.icon_01.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 2) game.resource.texture.icon_02.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 3) game.resource.texture.icon_03.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 4) game.resource.texture.icon_04.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 5) game.resource.texture.icon_05.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    if (menu_slot_class::button_type == 6) game.resource.texture.icon_06.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width,menu_slot_class::height);
    game.resource.texture.glass_cover_02.draw(false,menu_slot_class::pos_x,menu_slot_class::pos_y,menu_slot_class::pos_z,menu_slot_class::width/1.1f,menu_slot_class::height/1.1f);
};

void menu_slot_class::draw_tooltip(void)
{
    if (menu_slot_class::mouse_over_count == menu_slot_class::tooltip_time)
    {
        switch (menu_slot_class::button_type) // display tool tip
        {
            case 1: // main menu
                game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.main_menu);
            break;
            case 2: // Equipment Menu
                game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.equipment);
            break;
            case 3: // Quest Log
                game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.quest_log);
            break;
            case 4: // Character Menu
                game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.character_menu);
            break;
            case 5: // Inventory
                game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.inventory);
            break;
            case 6: // Spell Book
                game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,game.language.text.spell_book);
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
    for (int action_menu_slot_count = 1; action_menu_slot_count < MAX_ACTION_MENU_SLOTS; action_menu_slot_count++)
    {
        action_bar_class::menu_slot[action_menu_slot_count].process();
    }
    for (int action_slot_count = 1; action_slot_count < MAX_ACTION_SLOTS; action_slot_count++)
    {
        action_bar_class::action_slot[action_slot_count].process();
    }
};

void action_bar_class::draw(void)
{
    float              temp_float   = 0.0f;
    game.resource.texture.action_bar.draw(false,action_bar_class::pos_x,action_bar_class::pos_y,action_bar_class::pos_z,action_bar_class::width,action_bar_class::height);
    for (int action_slot_count = 1; action_slot_count < MAX_ACTION_SLOTS; action_slot_count++)
    {
        action_bar_class::action_slot[action_slot_count].draw();
    }
    if (game.player.level.current < MAX_LEVELS)// exp bar
    {
        temp_float = (float)(game.player.level.current_experience - game.player.level.experience[game.player.level.current]) / (float)(game.player.level.experience[game.player.level.current+1] - game.player.level.experience[game.player.level.current]);
        temp_float = temp_float * (action_bar_class::width/1.048f);
    }
    game.resource.texture.experience_bar.draw(false,action_bar_class::pos_x-(action_bar_class::width/2.09f)+(temp_float/2),action_bar_class::pos_y-(action_bar_class::height/2.9f),action_bar_class::pos_z,temp_float,action_bar_class::height/16.0f);
    game.resource.texture.action_bar_front.draw(false,action_bar_class::pos_x,action_bar_class::pos_y,action_bar_class::pos_z,action_bar_class::width,action_bar_class::height);
    for (int action_menu_slot_count = 1; action_menu_slot_count < MAX_ACTION_MENU_SLOTS; action_menu_slot_count++)
    {
        action_bar_class::menu_slot[action_menu_slot_count].draw();
    }
    for (int action_menu_slot_count = 1; action_menu_slot_count < MAX_ACTION_MENU_SLOTS; action_menu_slot_count++)
    {
        if (action_bar_class::menu_slot[action_menu_slot_count].drag) action_bar_class::menu_slot[action_menu_slot_count].draw();
    }
    for (int action_menu_slot_count = 1; action_menu_slot_count < MAX_ACTION_MENU_SLOTS; action_menu_slot_count++)
    {
        action_bar_class::menu_slot[action_menu_slot_count].draw_tooltip();
    }
    for (int action_slot_count = 1; action_slot_count < MAX_ACTION_SLOTS; action_slot_count++)
    {
        action_bar_class::action_slot[action_slot_count].draw_tooltip();
    }
    for (int spell_slot_count = 1; spell_slot_count < MAX_SPELL_SLOTS; spell_slot_count++)
    {
        if (game.UI.spell_book.spell_slot[spell_slot_count].drag) game.UI.spell_book.spell_slot[spell_slot_count].draw_drag();
    }
    for (int action_slot_count = 1; action_slot_count < MAX_ACTION_SLOTS; action_slot_count++)
    {
        if (action_bar_class::action_slot[action_slot_count].drag) action_bar_class::action_slot[action_slot_count].draw_drag();
    }
    for (int inventory_slot_count = 1; inventory_slot_count < MAX_INVENTORY_SLOTS; inventory_slot_count++)
    {
        if (game.UI.inventory.inventory_slot[inventory_slot_count].drag) game.UI.inventory.inventory_slot[inventory_slot_count].draw_drag();
    }
    for (int equipment_slot_count = 1; equipment_slot_count < MAX_EQUIPMENT_SLOTS; equipment_slot_count++)
    {
        if (game.UI.equipment.equipment_slot[equipment_slot_count].drag) game.UI.equipment.equipment_slot[equipment_slot_count].draw_drag();
    }
    for (int ncpvendor_slot_count = 1; ncpvendor_slot_count < MAX_NPCVENDOR_SLOTS; ncpvendor_slot_count++)
    {
        if (game.UI.npcvendor.npcvendor_slot[ncpvendor_slot_count].drag) game.UI.npcvendor.npcvendor_slot[ncpvendor_slot_count].draw_drag();
    }
};

//----------------------------------------------------------------------------------------------------------------
    UI_class::UI_class(void)
{
    UI_class::drag_in_progress                      =  false;
    UI_class::action_bar.width                      =  1.4f;
    UI_class::action_bar.height                     =  UI_class::action_bar.width/8.0f;
    UI_class::action_bar.pos_x                      =  0.0f;
    UI_class::action_bar.pos_y                      = -1.0f + (UI_class::action_bar.height/2.4);
    UI_class::action_bar.pos_z                      =  0.001f;
    UI_class::action_bar.menu_slot[ 1].button_type   =  1;
    UI_class::action_bar.menu_slot[ 1].pos_x         =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/2.262f);
    UI_class::action_bar.menu_slot[ 1].pos_y         =  UI_class::action_bar.pos_y + (UI_class::action_bar.height/32.0f);
    UI_class::action_bar.menu_slot[ 1].pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot[ 1].width         =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 1].height        =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 1].base_pos_x    =  UI_class::action_bar.menu_slot[ 1].pos_x;
    UI_class::action_bar.menu_slot[ 1].base_pos_y    =  UI_class::action_bar.menu_slot[ 1].pos_y;
    UI_class::action_bar.menu_slot[ 1].drag          =  false;
    UI_class::action_bar.menu_slot[ 2].button_type   =  2;
    UI_class::action_bar.menu_slot[ 2].pos_x         =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/2.60f);
    UI_class::action_bar.menu_slot[ 2].pos_y         =  UI_class::action_bar.pos_y + (UI_class::action_bar.height/32.0f);
    UI_class::action_bar.menu_slot[ 2].pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot[ 2].width         =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 2].height        =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 2].base_pos_x    =  UI_class::action_bar.menu_slot[ 2].pos_x;
    UI_class::action_bar.menu_slot[ 2].base_pos_y    =  UI_class::action_bar.menu_slot[ 2].pos_y;
    UI_class::action_bar.menu_slot[ 2].drag          =  false;
    UI_class::action_bar.menu_slot[ 3].button_type   =  3;
    UI_class::action_bar.menu_slot[ 3].pos_x         =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/3.042f);
    UI_class::action_bar.menu_slot[ 3].pos_y         =  UI_class::action_bar.pos_y + (UI_class::action_bar.height/32.0f);
    UI_class::action_bar.menu_slot[ 3].pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot[ 3].width         =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 3].height        =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 3].base_pos_x    =  UI_class::action_bar.menu_slot[ 3].pos_x;
    UI_class::action_bar.menu_slot[ 3].base_pos_y    =  UI_class::action_bar.menu_slot[ 3].pos_y;
    UI_class::action_bar.menu_slot[ 3].drag          =  false;
    UI_class::action_bar.menu_slot[ 4].button_type   =  4;
    UI_class::action_bar.menu_slot[ 4].pos_x         =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/3.030f);
    UI_class::action_bar.menu_slot[ 4].pos_y         =  UI_class::action_bar.pos_y + (UI_class::action_bar.height/32.0f);
    UI_class::action_bar.menu_slot[ 4].pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot[ 4].width         =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 4].height        =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 4].base_pos_x    =  UI_class::action_bar.menu_slot[ 4].pos_x;
    UI_class::action_bar.menu_slot[ 4].base_pos_y    =  UI_class::action_bar.menu_slot[ 4].pos_y;
    UI_class::action_bar.menu_slot[ 4].drag          =  false;
    UI_class::action_bar.menu_slot[ 5].button_type   =  5;
    UI_class::action_bar.menu_slot[ 5].pos_x         =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/2.592f);
    UI_class::action_bar.menu_slot[ 5].pos_y         =  UI_class::action_bar.pos_y + (UI_class::action_bar.height/32.0f);
    UI_class::action_bar.menu_slot[ 5].pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot[ 5].width         =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 5].height        =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 5].base_pos_x    =  UI_class::action_bar.menu_slot[ 5].pos_x;
    UI_class::action_bar.menu_slot[ 5].base_pos_y    =  UI_class::action_bar.menu_slot[ 5].pos_y;
    UI_class::action_bar.menu_slot[ 5].drag          =  false;
    UI_class::action_bar.menu_slot[ 6].button_type   =  6;
    UI_class::action_bar.menu_slot[ 6].pos_x         =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/2.270f);
    UI_class::action_bar.menu_slot[ 6].pos_y         =  UI_class::action_bar.pos_y + (UI_class::action_bar.height/32.0f);
    UI_class::action_bar.menu_slot[ 6].pos_z         =  UI_class::action_bar.pos_z;
    UI_class::action_bar.menu_slot[ 6].width         =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 6].height        =  UI_class::action_bar.height/2.8f;
    UI_class::action_bar.menu_slot[ 6].base_pos_x    =  UI_class::action_bar.menu_slot[ 6].pos_x;
    UI_class::action_bar.menu_slot[ 6].base_pos_y    =  UI_class::action_bar.menu_slot[ 6].pos_y;
    UI_class::action_bar.menu_slot[ 6].drag          =  false;

    UI_class::action_bar.action_slot[ 1].button_type =  0;
    UI_class::action_bar.action_slot[ 1].pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/3.920f);
    UI_class::action_bar.action_slot[ 1].pos_y       =  UI_class::action_bar.pos_y + (UI_class::action_bar.height/22.0f);
    UI_class::action_bar.action_slot[ 1].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 1].height      =  UI_class::action_bar.height/1.90f;
    UI_class::action_bar.action_slot[ 1].width       =  UI_class::action_bar.action_slot[ 1].height/1.250f;
    UI_class::action_bar.action_slot[ 2].button_type =  0;
    UI_class::action_bar.action_slot[ 2].pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/5.030f);
    UI_class::action_bar.action_slot[ 2].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 2].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 2].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 2].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[ 3].button_type =  0;
    UI_class::action_bar.action_slot[ 3].pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/7.050f);
    UI_class::action_bar.action_slot[ 3].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 3].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 3].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 3].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[ 4].button_type =  0;
    UI_class::action_bar.action_slot[ 4].pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/11.600f);
    UI_class::action_bar.action_slot[ 4].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 4].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 4].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 4].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[ 5].button_type =  0;
    UI_class::action_bar.action_slot[ 5].pos_x       =  UI_class::action_bar.pos_x - (UI_class::action_bar.width/34.240f);
    UI_class::action_bar.action_slot[ 5].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 5].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 5].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 5].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[ 6].button_type =  0;
    UI_class::action_bar.action_slot[ 6].pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/37.400f);
    UI_class::action_bar.action_slot[ 6].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 6].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 6].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 6].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[ 7].button_type =  0;
    UI_class::action_bar.action_slot[ 7].pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/12.200f);
    UI_class::action_bar.action_slot[ 7].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 7].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 7].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 7].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[ 8].button_type =  0;
    UI_class::action_bar.action_slot[ 8].pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/7.260f);
    UI_class::action_bar.action_slot[ 8].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 8].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 8].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 8].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[ 9].button_type =  0;
    UI_class::action_bar.action_slot[ 9].pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/5.154f);
    UI_class::action_bar.action_slot[ 9].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[ 9].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[ 9].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[ 9].width       =  UI_class::action_bar.action_slot[ 1].width;
    UI_class::action_bar.action_slot[10].button_type =  1;
    UI_class::action_bar.action_slot[10].pos_x       =  UI_class::action_bar.pos_x + (UI_class::action_bar.width/3.990f);
    UI_class::action_bar.action_slot[10].pos_y       =  UI_class::action_bar.action_slot[ 1].pos_y;
    UI_class::action_bar.action_slot[10].pos_z       =  UI_class::action_bar.pos_z;
    UI_class::action_bar.action_slot[10].height      =  UI_class::action_bar.action_slot[ 1].height;
    UI_class::action_bar.action_slot[10].width       =  UI_class::action_bar.action_slot[ 1].width;

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
                if (game.core.game_menu_active) game.menu.process();
            break;
            case EQUIPMENT_WINDOW:
                if (game.core.equipment_active) UI_class::equipment.process();
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
            case NPCVENDOR_WINDOW:
                if (game.core.npcvendor_active) UI_class::npcvendor.process();
            break;
            default:
            break;
        };
    };
    UI_class::action_bar.process();
};

void UI_class::draw(void)
{
    glDisable(GL_DEPTH_TEST);
    for (int awl_count = MAX_ACTIVE_WINDOWS; awl_count >= 0; awl_count--)
    {
        switch (UI_class::active_window_list.window_ID[awl_count])
        {
            case MAIN_MENU_WINDOW:
                if (game.core.game_menu_active) game.menu.render();
            break;
            case EQUIPMENT_WINDOW:
                if (game.core.equipment_active) UI_class::equipment.draw();
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
            case NPCVENDOR_WINDOW:
                if (game.core.npcvendor_active) UI_class::npcvendor.draw();
            break;
            default:
            break;
        };
    };
    UI_class::action_bar.draw();
};

