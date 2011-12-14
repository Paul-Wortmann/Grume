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

#include "spell_book.hpp"
#include "spells.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------
spell_book_button_class::spell_book_button_class(void)
{
    spell_book_button_class::image_normal       = 0;
    spell_book_button_class::image_highlighted  = 0;
    spell_book_button_class::mouse_over         = false;
    spell_book_button_class::activated          = false;
    spell_book_button_class::pos_x              = 0.0f;
    spell_book_button_class::pos_y              = 0.0f;
    spell_book_button_class::pos_z              = 0.0f;
    spell_book_button_class::width              = 0.0f;
    spell_book_button_class::height             = 0.0f;
};

spell_book_button_class::~spell_book_button_class(void)
{
};

void spell_book_button_class::process(void)
{
    if (!game.UI.drag_in_progress)
    {
        spell_book_button_class::mouse_over = game.core.physics.point_in_quadrangle(spell_book_button_class::pos_x,spell_book_button_class::width,spell_book_button_class::pos_y,spell_book_button_class::height,game.core.io.mouse_x,game.core.io.mouse_y);
        spell_book_button_class::activated  = (spell_book_button_class::mouse_over && game.core.io.mouse_button_left);
    }
};

void spell_book_button_class::draw(void)
{
    if (spell_book_button_class::mouse_over) draw_texture(false,spell_book_button_class::image_highlighted,spell_book_button_class::pos_x,spell_book_button_class::pos_y,spell_book_button_class::pos_z,spell_book_button_class::width,spell_book_button_class::height);
    else draw_texture(false,spell_book_button_class::image_normal,spell_book_button_class::pos_x,spell_book_button_class::pos_y,spell_book_button_class::pos_z,spell_book_button_class::width,spell_book_button_class::height);
};

//----------------------------------------------------------------------------------------------------------------

spell_slot_class::spell_slot_class(void)
{
    spell_slot_class::click_delay       =  0;
    spell_slot_class::click_delay_count =  0;
    spell_slot_class::highlighted       =  false;
    spell_slot_class::drag              =  false;
    spell_slot_class::button_type       =  0;
    spell_slot_class::mouse_over        =  false;
    spell_slot_class::mouse_over_count  =  0;
    spell_slot_class::tooltip_time      =  32;
    spell_slot_class::tooltip_active    =  false;
    spell_slot_class::pos_x             =  0.0f;
    spell_slot_class::pos_y             =  0.0f;
    spell_slot_class::pos_z             =  0.001f;
    spell_slot_class::base_pos_x        =  0.0f;
    spell_slot_class::base_pos_y        =  0.0f;
    spell_slot_class::width             =  0.0f;
    spell_slot_class::height            =  0.0f;
    spell_slot_class::drag_offset_x     =  0.0f;
    spell_slot_class::drag_offset_y     =  0.0f;
};

spell_slot_class::~spell_slot_class(void)
{

};

void spell_slot_class::process(void)
{
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(spell_slot_class::pos_x,spell_slot_class::width,spell_slot_class::pos_y,spell_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y))) spell_slot_class::mouse_over = true;
    else spell_slot_class::mouse_over = false;
    if (spell_slot_class::button_type > 0)
    {
        if (spell_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                spell_slot_class::pos_x = game.core.io.mouse_x + spell_slot_class::drag_offset_x;
                spell_slot_class::pos_y = game.core.io.mouse_y + spell_slot_class::drag_offset_y;
            }
            else
            {
                for (int action_slot_count = 1; action_slot_count < MAX_ACTION_SLOTS; action_slot_count++)
                {
                    if ((game.UI.action_bar.action_slot[action_slot_count].mouse_over) && (game.UI.action_bar.action_slot[action_slot_count].button_type != spell_slot_class::button_type)) game.UI.action_bar.action_slot[action_slot_count].button_type = spell_slot_class::button_type;
                }
                spell_slot_class::drag         = false;
                game.UI.drag_in_progress       = false;
                spell_slot_class::pos_x        = spell_slot_class::base_pos_x;
                spell_slot_class::pos_y        = spell_slot_class::base_pos_y;
            }
        }
        else
        {
            if ((!game.UI.drag_in_progress) && (spell_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                spell_slot_class::drag          = true;
                game.UI.drag_in_progress        = true;
                spell_slot_class::base_pos_x    = spell_slot_class::pos_x;
                spell_slot_class::base_pos_y    = spell_slot_class::pos_y;
                spell_slot_class::drag_offset_x = spell_slot_class::pos_x - game.core.io.mouse_x;
                spell_slot_class::drag_offset_y = spell_slot_class::pos_y - game.core.io.mouse_y;
            }
        }
    }
};

void spell_slot_class::draw(void)
{
    switch (game.spell[spell_slot_class::button_type].level)
    {
        case 1:
            draw_texture(false,game.spell[spell_slot_class::button_type].image_level_1,spell_slot_class::pos_x,spell_slot_class::pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
            if (spell_slot_class::drag) draw_texture(false,game.spell[spell_slot_class::button_type].image_level_1,spell_slot_class::base_pos_x,spell_slot_class::base_pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
        break;
        case 2:
            draw_texture(false,game.spell[spell_slot_class::button_type].image_level_2,spell_slot_class::pos_x,spell_slot_class::pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
            if (spell_slot_class::drag) draw_texture(false,game.spell[spell_slot_class::button_type].image_level_2,spell_slot_class::base_pos_x,spell_slot_class::base_pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
        break;
        case 3:
            draw_texture(false,game.spell[spell_slot_class::button_type].image_level_3,spell_slot_class::pos_x,spell_slot_class::pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
            if (spell_slot_class::drag) draw_texture(false,game.spell[spell_slot_class::button_type].image_level_3,spell_slot_class::base_pos_x,spell_slot_class::base_pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
        break;
        default:
        break;
    }
    if (!spell_slot_class::drag) game.texture.spell_book_spell_cover.draw(false,spell_slot_class::pos_x,spell_slot_class::pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
    else game.texture.spell_book_spell_cover.draw(false,spell_slot_class::base_pos_x,spell_slot_class::base_pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
};

void spell_slot_class::draw_drag(void)
{
    switch (game.spell[spell_slot_class::button_type].level)
    {
        case 1:
            draw_texture(false,game.spell[spell_slot_class::button_type].image_level_1,spell_slot_class::pos_x,spell_slot_class::pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
        break;
        case 2:
            draw_texture(false,game.spell[spell_slot_class::button_type].image_level_2,spell_slot_class::pos_x,spell_slot_class::pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
        break;
        case 3:
            draw_texture(false,game.spell[spell_slot_class::button_type].image_level_3,spell_slot_class::pos_x,spell_slot_class::pos_y,spell_slot_class::pos_z,spell_slot_class::width,spell_slot_class::height);
        break;
        default:
        break;
    }
};

//----------------------------------------------------------------------------------------------------------------

spell_book_class::spell_book_class(void)
{
    spell_book_class::pos_x         = 0.5f;
    spell_book_class::pos_y         = 0.0f;
    spell_book_class::pos_z         = 0.001;
    spell_book_class::width         = 0.5f;
    spell_book_class::height        = 1.0f;
    spell_book_class::drag          = false;
    spell_book_class::mouse_over    = false;
    spell_book_class::drag_offset_x = 0.0f;
    spell_book_class::drag_offset_y = 0.0f;
    spell_book_class::spell_slot[ 1].button_type  = 1;
    spell_book_class::spell_slot[ 1].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
    spell_book_class::spell_slot[ 1].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
    spell_book_class::spell_slot[ 1].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 1].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 1].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 2].button_type  = 2;
    spell_book_class::spell_slot[ 2].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
    spell_book_class::spell_slot[ 2].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
    spell_book_class::spell_slot[ 2].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 2].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 2].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 3].button_type  = 3;
    spell_book_class::spell_slot[ 3].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
    spell_book_class::spell_slot[ 3].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
    spell_book_class::spell_slot[ 3].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 3].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 3].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 4].button_type  = 4;
    spell_book_class::spell_slot[ 4].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
    spell_book_class::spell_slot[ 4].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
    spell_book_class::spell_slot[ 4].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 4].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 4].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 5].button_type  = 5;
    spell_book_class::spell_slot[ 5].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
    spell_book_class::spell_slot[ 5].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
    spell_book_class::spell_slot[ 5].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 5].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 5].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 6].button_type  = 6;
    spell_book_class::spell_slot[ 6].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
    spell_book_class::spell_slot[ 6].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
    spell_book_class::spell_slot[ 6].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 6].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 6].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 7].button_type  = 7;
    spell_book_class::spell_slot[ 7].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
    spell_book_class::spell_slot[ 7].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
    spell_book_class::spell_slot[ 7].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 7].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 7].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 8].button_type  = 8;
    spell_book_class::spell_slot[ 8].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
    spell_book_class::spell_slot[ 8].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
    spell_book_class::spell_slot[ 8].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 8].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 8].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[ 9].button_type  = 9;
    spell_book_class::spell_slot[ 9].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
    spell_book_class::spell_slot[ 9].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
    spell_book_class::spell_slot[ 9].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[ 9].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[ 9].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[10].button_type  = 10;
    spell_book_class::spell_slot[10].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
    spell_book_class::spell_slot[10].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
    spell_book_class::spell_slot[10].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[10].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[10].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[11].button_type  = 11;
    spell_book_class::spell_slot[11].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
    spell_book_class::spell_slot[11].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
    spell_book_class::spell_slot[11].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[11].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[11].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[12].button_type  = 12;
    spell_book_class::spell_slot[12].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
    spell_book_class::spell_slot[12].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
    spell_book_class::spell_slot[12].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[12].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[12].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[13].button_type  = 13;
    spell_book_class::spell_slot[13].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
    spell_book_class::spell_slot[13].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
    spell_book_class::spell_slot[13].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[13].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[13].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[14].button_type  = 14;
    spell_book_class::spell_slot[14].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
    spell_book_class::spell_slot[14].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
    spell_book_class::spell_slot[14].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[14].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[14].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[15].button_type  = 15;
    spell_book_class::spell_slot[15].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
    spell_book_class::spell_slot[15].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
    spell_book_class::spell_slot[15].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[15].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[15].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[16].button_type  = 16;
    spell_book_class::spell_slot[16].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
    spell_book_class::spell_slot[16].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
    spell_book_class::spell_slot[16].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[16].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[16].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[17].button_type  = 17;
    spell_book_class::spell_slot[17].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
    spell_book_class::spell_slot[17].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
    spell_book_class::spell_slot[17].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[17].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[17].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[18].button_type  = 18;
    spell_book_class::spell_slot[18].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
    spell_book_class::spell_slot[18].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
    spell_book_class::spell_slot[18].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[18].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[18].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[19].button_type  = 19;
    spell_book_class::spell_slot[19].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
    spell_book_class::spell_slot[19].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
    spell_book_class::spell_slot[19].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[19].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[19].height       = spell_book_class::height/10.4f;
    spell_book_class::spell_slot[20].button_type  = 20;
    spell_book_class::spell_slot[20].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
    spell_book_class::spell_slot[20].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
    spell_book_class::spell_slot[20].pos_z        = spell_book_class::pos_z;
    spell_book_class::spell_slot[20].width        = spell_book_class::width / 8.2f;
    spell_book_class::spell_slot[20].height       = spell_book_class::height/10.4f;
    spell_book_class::close_button.image_normal       = game.texture.close_button.ref_number;
    spell_book_class::close_button.image_highlighted  = game.texture.close_button_highlighted.ref_number;
    spell_book_class::close_button.mouse_over         = false;
    spell_book_class::close_button.activated          = false;
    spell_book_class::close_button.pos_x              = spell_book_class::pos_x + (spell_book_class::width /2.406f);
    spell_book_class::close_button.pos_y              = spell_book_class::pos_y + (spell_book_class::height/2.20f);
    spell_book_class::close_button.pos_z              = spell_book_class::pos_z;
    spell_book_class::close_button.width              = spell_book_class::width / 7.0f;
    spell_book_class::close_button.height             = spell_book_class::height/10.4f;
};

spell_book_class::~spell_book_class(void)
{

};

void spell_book_class::process(void)
{
    for (int spell_slot_count = 1; spell_slot_count < MAX_SPELL_SLOTS; spell_slot_count++)
    {
        spell_book_class::spell_slot[spell_slot_count].process();
    }
    spell_book_class::close_button.process();
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(spell_book_class::pos_x,spell_book_class::width,spell_book_class::pos_y+(spell_book_class::height/2.2f),spell_book_class::height/8.8f,game.core.io.mouse_x,game.core.io.mouse_y))) spell_book_class::mouse_over = true;
    else spell_book_class::mouse_over = false;
    if (spell_book_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            spell_book_class::pos_x = game.core.io.mouse_x + spell_book_class::drag_offset_x;
            spell_book_class::pos_y = game.core.io.mouse_y + spell_book_class::drag_offset_y;
            spell_book_class::spell_slot[ 1].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
            spell_book_class::spell_slot[ 1].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
            spell_book_class::spell_slot[ 2].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
            spell_book_class::spell_slot[ 2].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
            spell_book_class::spell_slot[ 3].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
            spell_book_class::spell_slot[ 3].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
            spell_book_class::spell_slot[ 4].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
            spell_book_class::spell_slot[ 4].pos_y        = spell_book_class::pos_y + (spell_book_class::height/3.72f);
            spell_book_class::spell_slot[ 5].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
            spell_book_class::spell_slot[ 5].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
            spell_book_class::spell_slot[ 6].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
            spell_book_class::spell_slot[ 6].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
            spell_book_class::spell_slot[ 7].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
            spell_book_class::spell_slot[ 7].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
            spell_book_class::spell_slot[ 8].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
            spell_book_class::spell_slot[ 8].pos_y        = spell_book_class::pos_y + (spell_book_class::height/7.22f);
            spell_book_class::spell_slot[ 9].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
            spell_book_class::spell_slot[ 9].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
            spell_book_class::spell_slot[10].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
            spell_book_class::spell_slot[10].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
            spell_book_class::spell_slot[11].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
            spell_book_class::spell_slot[11].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
            spell_book_class::spell_slot[12].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
            spell_book_class::spell_slot[12].pos_y        = spell_book_class::pos_y + (spell_book_class::height/120.22f);
            spell_book_class::spell_slot[13].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
            spell_book_class::spell_slot[13].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
            spell_book_class::spell_slot[14].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
            spell_book_class::spell_slot[14].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
            spell_book_class::spell_slot[15].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
            spell_book_class::spell_slot[15].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
            spell_book_class::spell_slot[16].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
            spell_book_class::spell_slot[16].pos_y        = spell_book_class::pos_y - (spell_book_class::height/8.00f);
            spell_book_class::spell_slot[17].pos_x        = spell_book_class::pos_x - (spell_book_class::width /2.980f);
            spell_book_class::spell_slot[17].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
            spell_book_class::spell_slot[18].pos_x        = spell_book_class::pos_x - (spell_book_class::width /8.2f);
            spell_book_class::spell_slot[18].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
            spell_book_class::spell_slot[19].pos_x        = spell_book_class::pos_x + (spell_book_class::width /10.4f);
            spell_book_class::spell_slot[19].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
            spell_book_class::spell_slot[20].pos_x        = spell_book_class::pos_x + (spell_book_class::width /3.206f);
            spell_book_class::spell_slot[20].pos_y        = spell_book_class::pos_y - (spell_book_class::height/3.90f);
            spell_book_class::close_button.pos_x          = spell_book_class::pos_x + (spell_book_class::width /2.406f);
            spell_book_class::close_button.pos_y          = spell_book_class::pos_y + (spell_book_class::height/2.20f);
        }
        else
        {
            spell_book_class::drag         = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (spell_book_class::mouse_over) && (game.core.io.mouse_button_left))//drag
        {
            game.UI.active_window_list.add_to_list(SPELLBOOK_WINDOW);
            spell_book_class::drag          = true;
            game.UI.drag_in_progress        = true;
            spell_book_class::drag_offset_x = spell_book_class::pos_x - game.core.io.mouse_x;
            spell_book_class::drag_offset_y = spell_book_class::pos_y - game.core.io.mouse_y;
        }
    }
    if (spell_book_class::close_button.activated)
    {
        game.UI.active_window_list.remove_from_list(SPELLBOOK_WINDOW);
        game.core.spellbook_active     = false;
        spell_book_class::drag         = false;
        game.UI.drag_in_progress       = false;
        game.sound.menu_select_00.play();
    }
};

void spell_book_class::draw(void)
{
    game.texture.spell_book_background.draw(false,spell_book_class::pos_x,spell_book_class::pos_y,spell_book_class::pos_z,spell_book_class::width,spell_book_class::height);
    for (int spell_slot_count = 1; spell_slot_count < MAX_SPELL_SLOTS; spell_slot_count++)
    {
        if(spell_book_class::spell_slot[spell_slot_count].button_type > 0) spell_book_class::spell_slot[spell_slot_count].draw();
    }
    game.texture.spell_book.draw(false,spell_book_class::pos_x,spell_book_class::pos_y,spell_book_class::pos_z,spell_book_class::width,spell_book_class::height);
    spell_book_class::close_button.draw();
    game.font.font_1.Write(255,255,255,255,spell_book_class::pos_x - (spell_book_class::width /10.0f),spell_book_class::pos_y + (spell_book_class::height/2.30f),4.8f,32.0f,game.language.text.spell_book);
};




