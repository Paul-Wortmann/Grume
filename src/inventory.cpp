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

#include "inventory.hpp"
#include "game.hpp"
#include "items.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

inventory_button_class::inventory_button_class(void)
{
    inventory_button_class::image_normal       = 0;
    inventory_button_class::image_highlighted  = 0;
    inventory_button_class::mouse_over         = false;
    inventory_button_class::activated          = false;
    inventory_button_class::pos_x              = 0.0f;
    inventory_button_class::pos_y              = 0.0f;
    inventory_button_class::pos_z              = 0.0f;
    inventory_button_class::width              = 0.0f;
    inventory_button_class::height             = 0.0f;
};

inventory_button_class::~inventory_button_class(void)
{
};

void inventory_button_class::process(void)
{
    if (!game.UI.drag_in_progress)
    {
        inventory_button_class::mouse_over = game.core.physics.point_in_quadrangle(inventory_button_class::pos_x,inventory_button_class::width,inventory_button_class::pos_y,inventory_button_class::height,game.core.io.mouse_x,game.core.io.mouse_y);
        inventory_button_class::activated  = (inventory_button_class::mouse_over && game.core.io.mouse_button_left);
    }
};

void inventory_button_class::draw(void)
{
    if (inventory_button_class::mouse_over) draw_texture(false,inventory_button_class::image_highlighted,inventory_button_class::pos_x,inventory_button_class::pos_y,inventory_button_class::pos_z,inventory_button_class::width,inventory_button_class::height);
    else draw_texture(false,inventory_button_class::image_normal,inventory_button_class::pos_x,inventory_button_class::pos_y,inventory_button_class::pos_z,inventory_button_class::width,inventory_button_class::height);
};

//----------------------------------------------------------------------------------------------------------------

inventory_slot_class::inventory_slot_class(void)
{
    inventory_slot_class::click_delay       =  0;
    inventory_slot_class::click_delay_count =  0;
    inventory_slot_class::highlighted       =  false;
    inventory_slot_class::drag              =  false;
    inventory_slot_class::button_type       =  0;
    inventory_slot_class::mouse_over        =  false;
    inventory_slot_class::mouse_over_count  =  0;
    inventory_slot_class::tooltip_time      =  32;
    inventory_slot_class::tooltip_active    =  false;
    inventory_slot_class::pos_x             =  0.0f;
    inventory_slot_class::pos_y             =  0.0f;
    inventory_slot_class::pos_z             =  0.001f;
    inventory_slot_class::base_pos_x        =  0.0f;
    inventory_slot_class::base_pos_y        =  0.0f;
    inventory_slot_class::width             =  0.0f;
    inventory_slot_class::height            =  0.0f;
    inventory_slot_class::drag_offset_x     =  0.0f;
    inventory_slot_class::drag_offset_y     =  0.0f;
};

inventory_slot_class::~inventory_slot_class(void)
{

};

void inventory_slot_class::process(void)
{
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(inventory_slot_class::pos_x,inventory_slot_class::width,inventory_slot_class::pos_y,inventory_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y))) inventory_slot_class::mouse_over = true;
    else inventory_slot_class::mouse_over = false;
    if (inventory_slot_class::button_type > 0)
    {
        if (inventory_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                inventory_slot_class::pos_x = game.core.io.mouse_x + inventory_slot_class::drag_offset_x;
                inventory_slot_class::pos_y = game.core.io.mouse_y + inventory_slot_class::drag_offset_y;
            }
            else
            {
                inventory_slot_class::drag         = false;
                game.UI.drag_in_progress           = false;
                inventory_slot_class::pos_x        = inventory_slot_class::base_pos_x;
                inventory_slot_class::pos_y        = inventory_slot_class::base_pos_y;
            }
        }
        else
        {
            if ((!game.UI.drag_in_progress) && (inventory_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                inventory_slot_class::drag          = true;
                game.UI.drag_in_progress            = true;
                inventory_slot_class::base_pos_x    = inventory_slot_class::pos_x;
                inventory_slot_class::base_pos_y    = inventory_slot_class::pos_y;
                inventory_slot_class::drag_offset_x = inventory_slot_class::pos_x - game.core.io.mouse_x;
                inventory_slot_class::drag_offset_y = inventory_slot_class::pos_y - game.core.io.mouse_y;
            }
        }
    }
};

void inventory_slot_class::draw(void)
{
    if (inventory_slot_class::button_type > 0)
    {
        draw_texture(false,game.item[inventory_slot_class::button_type-101].image_ref,inventory_slot_class::pos_x,inventory_slot_class::pos_y,inventory_slot_class::pos_z,inventory_slot_class::width,inventory_slot_class::height);
    }
};

void inventory_slot_class::draw_drag(void)
{

};

//----------------------------------------------------------------------------------------------------------------

inventory_class::inventory_class(void)
{
    inventory_class::pos_x         = 0.5f;
    inventory_class::pos_y         = 0.0f;
    inventory_class::pos_z         = 0.001;
    inventory_class::width         = 0.5f;
    inventory_class::height        = 1.0f;
    inventory_class::drag          = false;
    inventory_class::mouse_over    = false;
    inventory_class::drag_offset_x = 0.0f;
    inventory_class::drag_offset_y = 0.0f;

    inventory_class::inventory_slot[ 1].button_type  = 0;
    inventory_class::inventory_slot[ 1].pos_x        = inventory_class::pos_x - (inventory_class::width /2.82f);
    inventory_class::inventory_slot[ 1].pos_y        = inventory_class::pos_y + (inventory_class::height/3.26f);
    inventory_class::inventory_slot[ 1].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 1].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 1].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[ 2].button_type  = 0;
    inventory_class::inventory_slot[ 2].pos_x        = inventory_class::pos_x - (inventory_class::width /4.72f);
    inventory_class::inventory_slot[ 2].pos_y        = inventory_class::pos_y + (inventory_class::height/3.26f);
    inventory_class::inventory_slot[ 2].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 2].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 2].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[ 3].button_type  = 0;
    inventory_class::inventory_slot[ 3].pos_x        = inventory_class::pos_x - (inventory_class::width /14.62f);
    inventory_class::inventory_slot[ 3].pos_y        = inventory_class::pos_y + (inventory_class::height/3.26f);
    inventory_class::inventory_slot[ 3].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 3].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 3].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[ 4].button_type  = 0;
    inventory_class::inventory_slot[ 4].pos_x        = inventory_class::pos_x + (inventory_class::width /14.02f);
    inventory_class::inventory_slot[ 4].pos_y        = inventory_class::pos_y + (inventory_class::height/3.26f);
    inventory_class::inventory_slot[ 4].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 4].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 4].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[ 5].button_type  = 0;
    inventory_class::inventory_slot[ 5].pos_x        = inventory_class::pos_x + (inventory_class::width /4.64f);
    inventory_class::inventory_slot[ 5].pos_y        = inventory_class::pos_y + (inventory_class::height/3.26f);
    inventory_class::inventory_slot[ 5].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 5].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 5].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[ 6].button_type  = 0;
    inventory_class::inventory_slot[ 6].pos_x        = inventory_class::pos_x + (inventory_class::width /2.80f);
    inventory_class::inventory_slot[ 6].pos_y        = inventory_class::pos_y + (inventory_class::height/3.26f);
    inventory_class::inventory_slot[ 6].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 6].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 6].height       = inventory_class::height/14.6f;

    inventory_class::inventory_slot[ 7].button_type  = 0;
    inventory_class::inventory_slot[ 7].pos_x        = inventory_class::pos_x - (inventory_class::width /2.82f);
    inventory_class::inventory_slot[ 7].pos_y        = inventory_class::pos_y + (inventory_class::height/4.66f);
    inventory_class::inventory_slot[ 7].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 7].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 7].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[ 8].button_type  = 0;
    inventory_class::inventory_slot[ 8].pos_x        = inventory_class::pos_x - (inventory_class::width /4.72f);
    inventory_class::inventory_slot[ 8].pos_y        = inventory_class::pos_y + (inventory_class::height/4.66f);
    inventory_class::inventory_slot[ 8].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 8].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 8].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[ 9].button_type  = 0;
    inventory_class::inventory_slot[ 9].pos_x        = inventory_class::pos_x - (inventory_class::width /14.62f);
    inventory_class::inventory_slot[ 9].pos_y        = inventory_class::pos_y + (inventory_class::height/4.66f);
    inventory_class::inventory_slot[ 9].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[ 9].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[ 9].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[10].button_type  = 0;
    inventory_class::inventory_slot[10].pos_x        = inventory_class::pos_x + (inventory_class::width /14.02f);
    inventory_class::inventory_slot[10].pos_y        = inventory_class::pos_y + (inventory_class::height/4.66f);
    inventory_class::inventory_slot[10].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[10].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[10].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[11].button_type  = 0;
    inventory_class::inventory_slot[11].pos_x        = inventory_class::pos_x + (inventory_class::width /4.64f);
    inventory_class::inventory_slot[11].pos_y        = inventory_class::pos_y + (inventory_class::height/4.66f);
    inventory_class::inventory_slot[11].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[11].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[11].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[12].button_type  = 0;
    inventory_class::inventory_slot[12].pos_x        = inventory_class::pos_x + (inventory_class::width /2.80f);
    inventory_class::inventory_slot[12].pos_y        = inventory_class::pos_y + (inventory_class::height/4.66f);
    inventory_class::inventory_slot[12].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[12].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[12].height       = inventory_class::height/14.6f;

    inventory_class::inventory_slot[13].button_type  = 0;
    inventory_class::inventory_slot[13].pos_x        = inventory_class::pos_x - (inventory_class::width /2.82f);
    inventory_class::inventory_slot[13].pos_y        = inventory_class::pos_y + (inventory_class::height/8.10f);
    inventory_class::inventory_slot[13].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[13].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[13].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[14].button_type  = 0;
    inventory_class::inventory_slot[14].pos_x        = inventory_class::pos_x - (inventory_class::width /4.72f);
    inventory_class::inventory_slot[14].pos_y        = inventory_class::pos_y + (inventory_class::height/8.10f);
    inventory_class::inventory_slot[14].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[14].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[14].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[15].button_type  = 0;
    inventory_class::inventory_slot[15].pos_x        = inventory_class::pos_x - (inventory_class::width /14.62f);
    inventory_class::inventory_slot[15].pos_y        = inventory_class::pos_y + (inventory_class::height/8.10f);
    inventory_class::inventory_slot[15].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[15].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[15].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[16].button_type  = 0;
    inventory_class::inventory_slot[16].pos_x        = inventory_class::pos_x + (inventory_class::width /14.02f);
    inventory_class::inventory_slot[16].pos_y        = inventory_class::pos_y + (inventory_class::height/8.10f);
    inventory_class::inventory_slot[16].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[16].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[16].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[17].button_type  = 0;
    inventory_class::inventory_slot[17].pos_x        = inventory_class::pos_x + (inventory_class::width /4.64f);
    inventory_class::inventory_slot[17].pos_y        = inventory_class::pos_y + (inventory_class::height/8.10f);
    inventory_class::inventory_slot[17].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[17].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[17].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[18].button_type  = 0;
    inventory_class::inventory_slot[18].pos_x        = inventory_class::pos_x + (inventory_class::width /2.80f);
    inventory_class::inventory_slot[18].pos_y        = inventory_class::pos_y + (inventory_class::height/8.10f);
    inventory_class::inventory_slot[18].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[18].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[18].height       = inventory_class::height/14.6f;

    inventory_class::inventory_slot[19].button_type  = 0;
    inventory_class::inventory_slot[19].pos_x        = inventory_class::pos_x - (inventory_class::width /2.82f);
    inventory_class::inventory_slot[19].pos_y        = inventory_class::pos_y + (inventory_class::height/32.10f);
    inventory_class::inventory_slot[19].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[19].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[19].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[20].button_type  = 0;
    inventory_class::inventory_slot[20].pos_x        = inventory_class::pos_x - (inventory_class::width /4.72f);
    inventory_class::inventory_slot[20].pos_y        = inventory_class::pos_y + (inventory_class::height/32.10f);
    inventory_class::inventory_slot[20].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[20].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[20].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[21].button_type  = 0;
    inventory_class::inventory_slot[21].pos_x        = inventory_class::pos_x - (inventory_class::width /14.62f);
    inventory_class::inventory_slot[21].pos_y        = inventory_class::pos_y + (inventory_class::height/32.10f);
    inventory_class::inventory_slot[21].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[21].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[21].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[22].button_type  = 0;
    inventory_class::inventory_slot[22].pos_x        = inventory_class::pos_x + (inventory_class::width /14.02f);
    inventory_class::inventory_slot[22].pos_y        = inventory_class::pos_y + (inventory_class::height/32.10f);
    inventory_class::inventory_slot[22].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[22].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[22].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[23].button_type  = 0;
    inventory_class::inventory_slot[23].pos_x        = inventory_class::pos_x + (inventory_class::width /4.64f);
    inventory_class::inventory_slot[23].pos_y        = inventory_class::pos_y + (inventory_class::height/32.10f);
    inventory_class::inventory_slot[23].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[23].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[23].height       = inventory_class::height/14.6f;
    inventory_class::inventory_slot[24].button_type  = 0;
    inventory_class::inventory_slot[24].pos_x        = inventory_class::pos_x + (inventory_class::width /2.80f);
    inventory_class::inventory_slot[24].pos_y        = inventory_class::pos_y + (inventory_class::height/32.10f);
    inventory_class::inventory_slot[24].pos_z        = inventory_class::pos_z;
    inventory_class::inventory_slot[24].width        = inventory_class::width / 9.6f;
    inventory_class::inventory_slot[24].height       = inventory_class::height/14.6f;

    inventory_class::close_button.image_normal       = game.texture.close_button.ref_number;
    inventory_class::close_button.image_highlighted  = game.texture.close_button_highlighted.ref_number;
    inventory_class::close_button.mouse_over         = false;
    inventory_class::close_button.activated          = false;
    inventory_class::close_button.pos_x              = inventory_class::pos_x + (inventory_class::width /2.406f);
    inventory_class::close_button.pos_y              = inventory_class::pos_y + (inventory_class::height/2.20f);
    inventory_class::close_button.pos_z              = inventory_class::pos_z;
    inventory_class::close_button.width              = inventory_class::width / 7.0f;
    inventory_class::close_button.height             = inventory_class::height/10.4f;
};

inventory_class::~inventory_class(void)
{

};

void inventory_class::process(void)
{
    inventory_class::close_button.process();
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(inventory_class::pos_x,inventory_class::width,inventory_class::pos_y+(inventory_class::height/2.2f),inventory_class::height/8.8f,game.core.io.mouse_x,game.core.io.mouse_y))) inventory_class::mouse_over = true;
    else inventory_class::mouse_over = false;
    if (inventory_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            inventory_class::pos_x = game.core.io.mouse_x + inventory_class::drag_offset_x;
            inventory_class::pos_y = game.core.io.mouse_y + inventory_class::drag_offset_y;
            inventory_class::close_button.pos_x = inventory_class::pos_x + (inventory_class::width /2.406f);
            inventory_class::close_button.pos_y = inventory_class::pos_y + (inventory_class::height/2.20f);
        }
        else
        {
            inventory_class::drag          = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (inventory_class::mouse_over) && (game.core.io.mouse_button_left))//drag
        {
            game.UI.active_window_list.add_to_list(INVENTORY_WINDOW);
            inventory_class::drag          = true;
            game.UI.drag_in_progress       = true;
            inventory_class::drag_offset_x = inventory_class::pos_x - game.core.io.mouse_x;
            inventory_class::drag_offset_y = inventory_class::pos_y - game.core.io.mouse_y;
        }
    }
    if (inventory_class::close_button.activated)
    {
        game.UI.active_window_list.remove_from_list(INVENTORY_WINDOW);
        game.core.inventory_active     = false;
        inventory_class::drag          = false;
        game.UI.drag_in_progress       = false;
        game.sound.menu_select_00.play();
    }
};

void inventory_class::draw(void)
{
    game.texture.inventory_background.draw(false,inventory_class::pos_x,inventory_class::pos_y,inventory_class::pos_z,inventory_class::width,inventory_class::height);
    inventory_class::close_button.draw();
    game.font.font_1.Write(255,255,255,255,inventory_class::pos_x - (inventory_class::width /10.0f),inventory_class::pos_y + (inventory_class::height/2.30f),4.8f,32.0f,game.language.text.inventory);
    for (int inventory_slot_count = 1; inventory_slot_count < MAX_INVENTORY_SLOTS; inventory_slot_count++)
    {
        if(inventory_class::inventory_slot[inventory_slot_count].button_type > 0) inventory_class::inventory_slot[inventory_slot_count].draw();
    }
};

void init_inventory(void)
{
    game.UI.inventory.inventory_slot[ 1].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 2].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 3].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 4].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 5].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 6].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 7].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 8].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[ 9].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[10].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[11].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[12].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[13].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[14].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[15].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[16].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[17].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[18].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[19].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[20].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[21].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[22].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[23].button_type  = game.item[1].item_ID;
    game.UI.inventory.inventory_slot[24].button_type  = game.item[1].item_ID;
};





