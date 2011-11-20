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

#include "character.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

character_button_class::character_button_class(void)
{
    character_button_class::image_normal       = 0;
    character_button_class::image_highlighted  = 0;
    character_button_class::mouse_over         = false;
    character_button_class::activated          = false;
    character_button_class::pos_x              = 0.0f;
    character_button_class::pos_y              = 0.0f;
    character_button_class::pos_z              = 0.0f;
    character_button_class::width              = 0.0f;
    character_button_class::height             = 0.0f;
};

character_button_class::~character_button_class(void)
{
};

void character_button_class::process(void)
{
    if (!game.UI.drag_in_progress)
    {
        character_button_class::mouse_over = game.core.physics.point_in_quadrangle(character_button_class::pos_x,character_button_class::width,character_button_class::pos_y,character_button_class::height,game.core.io.mouse_x,game.core.io.mouse_y);
        character_button_class::activated  = (character_button_class::mouse_over && game.core.io.mouse_button_left);
    }
};

void character_button_class::draw(void)
{
    if (character_button_class::mouse_over) draw_texture(false,character_button_class::image_highlighted,character_button_class::pos_x,character_button_class::pos_y,character_button_class::pos_z,character_button_class::width,character_button_class::height);
    else draw_texture(false,character_button_class::image_normal,character_button_class::pos_x,character_button_class::pos_y,character_button_class::pos_z,character_button_class::width,character_button_class::height);
};

//----------------------------------------------------------------------------------------------------------------

character_slot_class::character_slot_class(void)
{
    character_slot_class::click_delay       =  0;
    character_slot_class::click_delay_count =  0;
    character_slot_class::highlighted       =  false;
    character_slot_class::drag              =  false;
    character_slot_class::button_type       =  0;
    character_slot_class::mouse_over        =  false;
    character_slot_class::mouse_over_count  =  0;
    character_slot_class::tooltip_time      =  32;
    character_slot_class::tooltip_active    =  false;
    character_slot_class::pos_x             =  0.0f;
    character_slot_class::pos_y             =  0.0f;
    character_slot_class::pos_z             =  0.001f;
    character_slot_class::base_pos_x        =  0.0f;
    character_slot_class::base_pos_y        =  0.0f;
    character_slot_class::width             =  0.0f;
    character_slot_class::height            =  0.0f;
    character_slot_class::drag_offset_x     =  0.0f;
    character_slot_class::drag_offset_y     =  0.0f;
};

character_slot_class::~character_slot_class(void)
{

};

void character_slot_class::process(void)
{
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(character_slot_class::pos_x,character_slot_class::width,character_slot_class::pos_y,character_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y))) character_slot_class::mouse_over = true;
    else character_slot_class::mouse_over = false;
    if (character_slot_class::button_type > 0)
    {
        if (character_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                character_slot_class::pos_x = game.core.io.mouse_x + character_slot_class::drag_offset_x;
                character_slot_class::pos_y = game.core.io.mouse_y + character_slot_class::drag_offset_y;
            }
            else
            {
                character_slot_class::drag         = false;
                game.UI.drag_in_progress           = false;
                character_slot_class::pos_x        = character_slot_class::base_pos_x;
                character_slot_class::pos_y        = character_slot_class::base_pos_y;
            }
        }
        else
        {
            if ((!game.UI.drag_in_progress) && (character_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                character_slot_class::drag          = true;
                game.UI.drag_in_progress            = true;
                character_slot_class::base_pos_x    = character_slot_class::pos_x;
                character_slot_class::base_pos_y    = character_slot_class::pos_y;
                character_slot_class::drag_offset_x = character_slot_class::pos_x - game.core.io.mouse_x;
                character_slot_class::drag_offset_y = character_slot_class::pos_y - game.core.io.mouse_y;
            }
        }
    }
};

void character_slot_class::draw(void)
{

};

void character_slot_class::draw_drag(void)
{

};

//----------------------------------------------------------------------------------------------------------------

character_class::character_class(void)
{
    character_class::pos_x         = 0.5f;
    character_class::pos_y         = 0.0f;
    character_class::pos_z         = 0.001;
    character_class::width         = 0.5f;
    character_class::height        = 1.0f;
    character_class::drag          = false;
    character_class::mouse_over    = false;
    character_class::drag_offset_x = 0.0f;
    character_class::drag_offset_y = 0.0f;
/*
    character_class::spell_slot_01.button_type  = 1;
    character_class::spell_slot_01.pos_x        = character_class::pos_x - (character_class::width /2.980f);
    character_class::spell_slot_01.pos_y        = character_class::pos_y + (character_class::height/3.72f);
    character_class::spell_slot_01.pos_z        = character_class::pos_z;
    character_class::spell_slot_01.width        = character_class::width / 8.2f;
    character_class::spell_slot_01.height       = character_class::height/10.4f;
*/
    character_class::close_button.image_normal       = game.texture.close_button.ref_number;
    character_class::close_button.image_highlighted  = game.texture.close_button_highlighted.ref_number;
    character_class::close_button.mouse_over         = false;
    character_class::close_button.activated          = false;
    character_class::close_button.pos_x              = character_class::pos_x + (character_class::width /2.406f);
    character_class::close_button.pos_y              = character_class::pos_y + (character_class::height/2.20f);
    character_class::close_button.pos_z              = character_class::pos_z;
    character_class::close_button.width              = character_class::width / 7.0f;
    character_class::close_button.height             = character_class::height/10.4f;
};

character_class::~character_class(void)
{

};

void character_class::process(void)
{
    character_class::close_button.process();
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(character_class::pos_x,character_class::width,character_class::pos_y+(character_class::height/2.2f),character_class::height/8.8f,game.core.io.mouse_x,game.core.io.mouse_y))) character_class::mouse_over = true;
    else character_class::mouse_over = false;
    if (character_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            character_class::pos_x = game.core.io.mouse_x + character_class::drag_offset_x;
            character_class::pos_y = game.core.io.mouse_y + character_class::drag_offset_y;
            character_class::close_button.pos_x = character_class::pos_x + (character_class::width /2.406f);
            character_class::close_button.pos_y = character_class::pos_y + (character_class::height/2.20f);
        }
        else
        {
            character_class::drag          = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (character_class::mouse_over) && (game.core.io.mouse_button_left))//drag
        {
            character_class::drag          = true;
            game.UI.drag_in_progress       = true;
            character_class::drag_offset_x = character_class::pos_x - game.core.io.mouse_x;
            character_class::drag_offset_y = character_class::pos_y - game.core.io.mouse_y;
        }
    }
    if (character_class::close_button.activated)
    {
        game.core.character_active     = false;
        character_class::drag          = false;
        game.UI.drag_in_progress       = false;
        game.sound.menu_select_00.play();
    }
};

void character_class::draw(void)
{
    game.texture.character_background.draw(false,character_class::pos_x,character_class::pos_y,character_class::pos_z,character_class::width,character_class::height);
    character_class::close_button.draw();
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /10.0f),character_class::pos_y + (character_class::height/2.30f),4.8f,32.0f,game.language.text.character_menu);
};




