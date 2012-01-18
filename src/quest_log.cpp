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

#include "quest_log.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

quest_log_button_class::quest_log_button_class(void)
{
    quest_log_button_class::image_normal       = 0;
    quest_log_button_class::image_highlighted  = 0;
    quest_log_button_class::mouse_over         = false;
    quest_log_button_class::activated          = false;
    quest_log_button_class::pos_x              = 0.0f;
    quest_log_button_class::pos_y              = 0.0f;
    quest_log_button_class::pos_z              = 0.0f;
    quest_log_button_class::width              = 0.0f;
    quest_log_button_class::height             = 0.0f;
};

quest_log_button_class::~quest_log_button_class(void)
{
};

void quest_log_button_class::process(void)
{
    if (!game.UI.drag_in_progress)
    {
        quest_log_button_class::mouse_over = game.core.physics.point_in_quadrangle(quest_log_button_class::pos_x,quest_log_button_class::width,quest_log_button_class::pos_y,quest_log_button_class::height,game.core.io.mouse_x,game.core.io.mouse_y);
        quest_log_button_class::activated  = (quest_log_button_class::mouse_over && game.core.io.mouse_button_left);
    }
};

void quest_log_button_class::draw(void)
{
    if (quest_log_button_class::mouse_over) draw_texture(false,quest_log_button_class::image_highlighted,quest_log_button_class::pos_x,quest_log_button_class::pos_y,quest_log_button_class::pos_z,quest_log_button_class::width,quest_log_button_class::height);
    else draw_texture(false,quest_log_button_class::image_normal,quest_log_button_class::pos_x,quest_log_button_class::pos_y,quest_log_button_class::pos_z,quest_log_button_class::width,quest_log_button_class::height);
};

//----------------------------------------------------------------------------------------------------------------

quest_log_slot_class::quest_log_slot_class(void)
{
    quest_log_slot_class::click_delay       =  0;
    quest_log_slot_class::click_delay_count =  0;
    quest_log_slot_class::highlighted       =  false;
    quest_log_slot_class::drag              =  false;
    quest_log_slot_class::button_type       =  0;
    quest_log_slot_class::mouse_over        =  false;
    quest_log_slot_class::mouse_over_count  =  0;
    quest_log_slot_class::tooltip_time      =  32;
    quest_log_slot_class::tooltip_active    =  false;
    quest_log_slot_class::pos_x             =  0.0f;
    quest_log_slot_class::pos_y             =  0.0f;
    quest_log_slot_class::pos_z             =  0.001f;
    quest_log_slot_class::base_pos_x        =  0.0f;
    quest_log_slot_class::base_pos_y        =  0.0f;
    quest_log_slot_class::width             =  0.0f;
    quest_log_slot_class::height            =  0.0f;
    quest_log_slot_class::drag_offset_x     =  0.0f;
    quest_log_slot_class::drag_offset_y     =  0.0f;
};

quest_log_slot_class::~quest_log_slot_class(void)
{

};

void quest_log_slot_class::process(void)
{
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(quest_log_slot_class::pos_x,quest_log_slot_class::width,quest_log_slot_class::pos_y,quest_log_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y))) quest_log_slot_class::mouse_over = true;
    else quest_log_slot_class::mouse_over = false;
    if (quest_log_slot_class::button_type > 0)
    {
        if (quest_log_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                quest_log_slot_class::pos_x = game.core.io.mouse_x + quest_log_slot_class::drag_offset_x;
                quest_log_slot_class::pos_y = game.core.io.mouse_y + quest_log_slot_class::drag_offset_y;
            }
            else
            {
                quest_log_slot_class::drag         = false;
                game.UI.drag_in_progress           = false;
                quest_log_slot_class::pos_x        = quest_log_slot_class::base_pos_x;
                quest_log_slot_class::pos_y        = quest_log_slot_class::base_pos_y;
            }
        }
        else
        {
            if ((!game.UI.drag_in_progress) && (quest_log_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                quest_log_slot_class::drag          = true;
                game.UI.drag_in_progress            = true;
                quest_log_slot_class::base_pos_x    = quest_log_slot_class::pos_x;
                quest_log_slot_class::base_pos_y    = quest_log_slot_class::pos_y;
                quest_log_slot_class::drag_offset_x = quest_log_slot_class::pos_x - game.core.io.mouse_x;
                quest_log_slot_class::drag_offset_y = quest_log_slot_class::pos_y - game.core.io.mouse_y;
            }
        }
    }
};

void quest_log_slot_class::draw(void)
{

};

void quest_log_slot_class::draw_drag(void)
{

};

//----------------------------------------------------------------------------------------------------------------

quest_log_class::quest_log_class(void)
{
    quest_log_class::pos_x         = 0.5f;
    quest_log_class::pos_y         = 0.0f;
    quest_log_class::pos_z         = 0.001;
    quest_log_class::width         = 0.5f;
    quest_log_class::height        = 1.0f;
    quest_log_class::drag          = false;
    quest_log_class::mouse_over    = false;
    quest_log_class::drag_offset_x = 0.0f;
    quest_log_class::drag_offset_y = 0.0f;
/*
    quest_log_class::spell_slot_01.button_type  = 1;
    quest_log_class::spell_slot_01.pos_x        = quest_log_class::pos_x - (quest_log_class::width /2.980f);
    quest_log_class::spell_slot_01.pos_y        = quest_log_class::pos_y + (quest_log_class::height/3.72f);
    quest_log_class::spell_slot_01.pos_z        = quest_log_class::pos_z;
    quest_log_class::spell_slot_01.width        = quest_log_class::width / 8.2f;
    quest_log_class::spell_slot_01.height       = quest_log_class::height/10.4f;
*/
    quest_log_class::close_button.image_normal       = game.texture.close_button.ref_number;
    quest_log_class::close_button.image_highlighted  = game.texture.close_button_highlighted.ref_number;
    quest_log_class::close_button.mouse_over         = false;
    quest_log_class::close_button.activated          = false;
    quest_log_class::close_button.pos_x              = quest_log_class::pos_x + (quest_log_class::width /2.406f);
    quest_log_class::close_button.pos_y              = quest_log_class::pos_y + (quest_log_class::height/2.20f);
    quest_log_class::close_button.pos_z              = quest_log_class::pos_z;
    quest_log_class::close_button.width              = quest_log_class::width / 7.0f;
    quest_log_class::close_button.height             = quest_log_class::height/10.4f;
};

quest_log_class::~quest_log_class(void)
{

};

void quest_log_class::process(void)
{
    quest_log_class::close_button.process();
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(quest_log_class::pos_x,quest_log_class::width,quest_log_class::pos_y+(quest_log_class::height/2.2f),quest_log_class::height/8.8f,game.core.io.mouse_x,game.core.io.mouse_y))) quest_log_class::mouse_over = true;
    else quest_log_class::mouse_over = false;
    if (quest_log_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            quest_log_class::pos_x = game.core.io.mouse_x + quest_log_class::drag_offset_x;
            quest_log_class::pos_y = game.core.io.mouse_y + quest_log_class::drag_offset_y;
            quest_log_class::close_button.pos_x = quest_log_class::pos_x + (quest_log_class::width /2.406f);
            quest_log_class::close_button.pos_y = quest_log_class::pos_y + (quest_log_class::height/2.20f);
        }
        else
        {
            quest_log_class::drag          = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (quest_log_class::mouse_over) && (game.core.io.mouse_button_left))//drag
        {
            game.UI.active_window_list.add_to_list(QUEST_LOG_WINDOW);
            quest_log_class::drag          = true;
            game.UI.drag_in_progress       = true;
            quest_log_class::drag_offset_x = quest_log_class::pos_x - game.core.io.mouse_x;
            quest_log_class::drag_offset_y = quest_log_class::pos_y - game.core.io.mouse_y;
        }
    }
    if (quest_log_class::close_button.activated)
    {
        game.UI.active_window_list.remove_from_list(QUEST_LOG_WINDOW);
        game.core.quest_log_active     = false;
        quest_log_class::drag          = false;
        game.UI.drag_in_progress       = false;
        game.sound.menu_select_00.play();
    }
};

void quest_log_class::draw(void)
{
    game.texture.quest_log_background.draw(false,quest_log_class::pos_x,quest_log_class::pos_y,quest_log_class::pos_z,quest_log_class::width,quest_log_class::height);
    quest_log_class::close_button.draw();
    game.font.font_1.Write(255,255,255,255,quest_log_class::pos_x - (quest_log_class::width /10.0f),quest_log_class::pos_y + (quest_log_class::height/2.30f),4.8f,32.0f,game.language.text.quest_log);
};




