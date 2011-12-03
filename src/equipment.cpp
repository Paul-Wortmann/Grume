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

#include "equipment.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

equipment_button_class::equipment_button_class(void)
{
    equipment_button_class::image_normal       = 0;
    equipment_button_class::image_highlighted  = 0;
    equipment_button_class::mouse_over         = false;
    equipment_button_class::activated          = false;
    equipment_button_class::pos_x              = 0.0f;
    equipment_button_class::pos_y              = 0.0f;
    equipment_button_class::pos_z              = 0.0f;
    equipment_button_class::width              = 0.0f;
    equipment_button_class::height             = 0.0f;
};

equipment_button_class::~equipment_button_class(void)
{
};

void equipment_button_class::process(void)
{
    if (!game.UI.drag_in_progress)
    {
        equipment_button_class::mouse_over = game.core.physics.point_in_quadrangle(equipment_button_class::pos_x,equipment_button_class::width,equipment_button_class::pos_y,equipment_button_class::height,game.core.io.mouse_x,game.core.io.mouse_y);
        equipment_button_class::activated  = (equipment_button_class::mouse_over && game.core.io.mouse_button_left);
    }
};

void equipment_button_class::draw(void)
{
    if (equipment_button_class::mouse_over) draw_texture(false,equipment_button_class::image_highlighted,equipment_button_class::pos_x,equipment_button_class::pos_y,equipment_button_class::pos_z,equipment_button_class::width,equipment_button_class::height);
    else draw_texture(false,equipment_button_class::image_normal,equipment_button_class::pos_x,equipment_button_class::pos_y,equipment_button_class::pos_z,equipment_button_class::width,equipment_button_class::height);
};

//----------------------------------------------------------------------------------------------------------------

equipment_slot_class::equipment_slot_class(void)
{
    equipment_slot_class::click_delay       =  0;
    equipment_slot_class::click_delay_count =  0;
    equipment_slot_class::highlighted       =  false;
    equipment_slot_class::drag              =  false;
    equipment_slot_class::button_type       =  0;
    equipment_slot_class::mouse_over        =  false;
    equipment_slot_class::mouse_over_count  =  0;
    equipment_slot_class::tooltip_time      =  32;
    equipment_slot_class::tooltip_active    =  false;
    equipment_slot_class::pos_x             =  0.0f;
    equipment_slot_class::pos_y             =  0.0f;
    equipment_slot_class::pos_z             =  0.001f;
    equipment_slot_class::base_pos_x        =  0.0f;
    equipment_slot_class::base_pos_y        =  0.0f;
    equipment_slot_class::width             =  0.0f;
    equipment_slot_class::height            =  0.0f;
    equipment_slot_class::drag_offset_x     =  0.0f;
    equipment_slot_class::drag_offset_y     =  0.0f;
};

equipment_slot_class::~equipment_slot_class(void)
{

};

void equipment_slot_class::process(void)
{
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(equipment_slot_class::pos_x,equipment_slot_class::width,equipment_slot_class::pos_y,equipment_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y))) equipment_slot_class::mouse_over = true;
    else equipment_slot_class::mouse_over = false;
    if (equipment_slot_class::button_type > 0)
    {
        if (equipment_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                equipment_slot_class::pos_x = game.core.io.mouse_x + equipment_slot_class::drag_offset_x;
                equipment_slot_class::pos_y = game.core.io.mouse_y + equipment_slot_class::drag_offset_y;
            }
            else
            {
                equipment_slot_class::drag         = false;
                game.UI.drag_in_progress           = false;
                equipment_slot_class::pos_x        = equipment_slot_class::base_pos_x;
                equipment_slot_class::pos_y        = equipment_slot_class::base_pos_y;
            }
        }
        else
        {
            if ((!game.UI.drag_in_progress) && (equipment_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                equipment_slot_class::drag          = true;
                game.UI.drag_in_progress            = true;
                equipment_slot_class::base_pos_x    = equipment_slot_class::pos_x;
                equipment_slot_class::base_pos_y    = equipment_slot_class::pos_y;
                equipment_slot_class::drag_offset_x = equipment_slot_class::pos_x - game.core.io.mouse_x;
                equipment_slot_class::drag_offset_y = equipment_slot_class::pos_y - game.core.io.mouse_y;
            }
        }
    }
};

void equipment_slot_class::draw(void)
{

};

void equipment_slot_class::draw_drag(void)
{

};

//----------------------------------------------------------------------------------------------------------------

equipment_class::equipment_class(void)
{
    equipment_class::pos_x         = 0.5f;
    equipment_class::pos_y         = 0.0f;
    equipment_class::pos_z         = 0.001;
    equipment_class::width         = 0.5f;
    equipment_class::height        = 1.0f;
    equipment_class::drag          = false;
    equipment_class::mouse_over    = false;
    equipment_class::drag_offset_x = 0.0f;
    equipment_class::drag_offset_y = 0.0f;
/*
    equipment_class::spell_slot_01.button_type  = 1;
    equipment_class::spell_slot_01.pos_x        = equipment_class::pos_x - (equipment_class::width /2.980f);
    equipment_class::spell_slot_01.pos_y        = equipment_class::pos_y + (equipment_class::height/3.72f);
    equipment_class::spell_slot_01.pos_z        = equipment_class::pos_z;
    equipment_class::spell_slot_01.width        = equipment_class::width / 8.2f;
    equipment_class::spell_slot_01.height       = equipment_class::height/10.4f;
*/
    equipment_class::close_button.image_normal       = game.texture.close_button.ref_number;
    equipment_class::close_button.image_highlighted  = game.texture.close_button_highlighted.ref_number;
    equipment_class::close_button.mouse_over         = false;
    equipment_class::close_button.activated          = false;
    equipment_class::close_button.pos_x              = equipment_class::pos_x + (equipment_class::width /2.406f);
    equipment_class::close_button.pos_y              = equipment_class::pos_y + (equipment_class::height/2.20f);
    equipment_class::close_button.pos_z              = equipment_class::pos_z;
    equipment_class::close_button.width              = equipment_class::width / 7.0f;
    equipment_class::close_button.height             = equipment_class::height/10.4f;
};

equipment_class::~equipment_class(void)
{

};

void equipment_class::process(void)
{
    equipment_class::close_button.process();
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(equipment_class::pos_x,equipment_class::width,equipment_class::pos_y+(equipment_class::height/2.2f),equipment_class::height/8.8f,game.core.io.mouse_x,game.core.io.mouse_y))) equipment_class::mouse_over = true;
    else equipment_class::mouse_over = false;
    if (equipment_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            equipment_class::pos_x = game.core.io.mouse_x + equipment_class::drag_offset_x;
            equipment_class::pos_y = game.core.io.mouse_y + equipment_class::drag_offset_y;
            equipment_class::close_button.pos_x = equipment_class::pos_x + (equipment_class::width /2.406f);
            equipment_class::close_button.pos_y = equipment_class::pos_y + (equipment_class::height/2.20f);
        }
        else
        {
            equipment_class::drag          = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (equipment_class::mouse_over) && (game.core.io.mouse_button_left))//drag
        {
            game.UI.active_window_list.add_to_list(EQUIPMENT_WINDOW);
            equipment_class::drag          = true;
            game.UI.drag_in_progress       = true;
            equipment_class::drag_offset_x = equipment_class::pos_x - game.core.io.mouse_x;
            equipment_class::drag_offset_y = equipment_class::pos_y - game.core.io.mouse_y;
        }
    }
    if (equipment_class::close_button.activated)
    {
        game.UI.active_window_list.remove_from_list(EQUIPMENT_WINDOW);
        game.core.equipment_active     = false;
        equipment_class::drag          = false;
        game.UI.drag_in_progress       = false;
        game.sound.menu_select_00.play();
    }
};

void equipment_class::draw(void)
{
    game.texture.equipment_background.draw(false,equipment_class::pos_x,equipment_class::pos_y,equipment_class::pos_z,equipment_class::width,equipment_class::height);
    equipment_class::close_button.draw();
    game.font.font_1.Write(255,255,255,255,equipment_class::pos_x - (equipment_class::width /10.0f),equipment_class::pos_y + (equipment_class::height/2.30f),4.8f,32.0f,game.language.text.equipment);
};




