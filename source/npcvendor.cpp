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

#include "core/misc.hpp"
#include "npcvendor.hpp"
#include "game.hpp"
#include "items.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

npcvendor_sound_class::npcvendor_sound_class(void)
{
    for (int sound_count = 0; sound_count < MAX_NPCVENDOR_SOUND; sound_count++)
    {
        npcvendor_sound_class::greating_begin[sound_count] = 0;
        npcvendor_sound_class::greating_leave[sound_count] = 0;
    }
    npcvendor_sound_class::number_of_greating_begin = 0;
    npcvendor_sound_class::number_of_greating_leave = 0;
};

npcvendor_sound_class::~npcvendor_sound_class(void)
{
};

void npcvendor_sound_class::play_greating_begin(void)
{
    int sound_count = random(npcvendor_sound_class::number_of_greating_begin);
    if (npcvendor_sound_class::greating_begin[sound_count] > 0)
    {
        game.resource.sound.play(npcvendor_sound_class::greating_begin[sound_count]);
    }
}

void npcvendor_sound_class::play_greating_leave(void)
{
    int sound_count = random(npcvendor_sound_class::number_of_greating_leave);
    if (npcvendor_sound_class::greating_leave[sound_count] > 0)
    {
        game.resource.sound.play(npcvendor_sound_class::greating_leave[sound_count]);
    }
}

void npcvendor_sound_class::calculate_number_of_sounds(void)
{
    npcvendor_sound_class::number_of_greating_begin = 0;
    npcvendor_sound_class::number_of_greating_leave = 0;
    for (int sound_count = 0; sound_count < MAX_NPCVENDOR_SOUND; sound_count++)
    {
        if (npcvendor_sound_class::greating_begin[sound_count] > 0)
        {
            npcvendor_sound_class::number_of_greating_begin++;
        }
        if (npcvendor_sound_class::greating_leave[sound_count] > 0)
        {
            npcvendor_sound_class::number_of_greating_leave++;
        }
    }
};

//----------------------------------------------------------------------------------------------------------------

npcvendor_button_class::npcvendor_button_class(void)
{
    npcvendor_button_class::image_normal       = 0;
    npcvendor_button_class::image_highlighted  = 0;
    npcvendor_button_class::mouse_over         = false;
    npcvendor_button_class::activated          = false;
    npcvendor_button_class::pos_x              = 0.0f;
    npcvendor_button_class::pos_y              = 0.0f;
    npcvendor_button_class::pos_z              = 0.0f;
    npcvendor_button_class::width              = 0.0f;
    npcvendor_button_class::height             = 0.0f;
};

npcvendor_button_class::~npcvendor_button_class(void)
{
};

void npcvendor_button_class::process(void)
{
    if (!game.UI.drag_in_progress)
    {
        npcvendor_button_class::mouse_over = game.core.physics.point_in_quadrangle(npcvendor_button_class::pos_x,npcvendor_button_class::width,npcvendor_button_class::pos_y,npcvendor_button_class::height,game.core.io.mouse_x,game.core.io.mouse_y);
        npcvendor_button_class::activated  = (npcvendor_button_class::mouse_over && game.core.io.mouse_button_left);
    }
};

void npcvendor_button_class::draw(void)
{
    if (npcvendor_button_class::mouse_over) game.resource.texture.render(false,npcvendor_button_class::image_highlighted,npcvendor_button_class::pos_x,npcvendor_button_class::pos_y,npcvendor_button_class::pos_z,npcvendor_button_class::width,npcvendor_button_class::height);
    else game.resource.texture.render(false,npcvendor_button_class::image_normal,npcvendor_button_class::pos_x,npcvendor_button_class::pos_y,npcvendor_button_class::pos_z,npcvendor_button_class::width,npcvendor_button_class::height);
};

//----------------------------------------------------------------------------------------------------------------

npcvendor_slot_class::npcvendor_slot_class(void)
{
    npcvendor_slot_class::click_delay       =  0;
    npcvendor_slot_class::click_delay_count =  0;
    npcvendor_slot_class::highlighted       =  false;
    npcvendor_slot_class::drag              =  false;
    npcvendor_slot_class::button_type       =  0;
    npcvendor_slot_class::mouse_over        =  false;
    npcvendor_slot_class::mouse_over_count  =  0;
    npcvendor_slot_class::tooltip_time      =  32;
    npcvendor_slot_class::tooltip_active    =  false;
    npcvendor_slot_class::pos_x             =  0.0f;
    npcvendor_slot_class::pos_y             =  0.0f;
    npcvendor_slot_class::pos_z             =  0.001f;
    npcvendor_slot_class::base_pos_x        =  0.0f;
    npcvendor_slot_class::base_pos_y        =  0.0f;
    npcvendor_slot_class::width             =  0.0f;
    npcvendor_slot_class::height            =  0.0f;
    npcvendor_slot_class::drag_offset_x     =  0.0f;
    npcvendor_slot_class::drag_offset_y     =  0.0f;
    npcvendor_slot_class::quantity          =  1;
    npcvendor_slot_class::max_quantity      =  1;
};

npcvendor_slot_class::~npcvendor_slot_class(void)
{

};

void npcvendor_slot_class::process(void)
{
    int  temp_int    = 0;
    int  temp_button = 0;
    int  temp_ID = npcvendor_slot_class::button_type;
    int  active_npcvendor_slot = 0;
    for (int npcvendor_slot_count = 1; npcvendor_slot_count < MAX_NPCVENDOR_SLOTS; npcvendor_slot_count++)
    {
        if (game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].drag) active_npcvendor_slot = npcvendor_slot_count;
    }
    if (game.core.physics.point_in_quadrangle(npcvendor_slot_class::pos_x,npcvendor_slot_class::width,npcvendor_slot_class::pos_y,npcvendor_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y)) npcvendor_slot_class::mouse_over = true;
    else npcvendor_slot_class::mouse_over = false;
    if (npcvendor_slot_class::mouse_over)
    {
        npcvendor_slot_class::mouse_over_count++;
        if (npcvendor_slot_class::mouse_over_count > npcvendor_slot_class::tooltip_time) npcvendor_slot_class::mouse_over_count = npcvendor_slot_class::tooltip_time;
    }
    else npcvendor_slot_class::mouse_over_count = 0;
    if (npcvendor_slot_class::button_type > 0)
    {
        if (npcvendor_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                npcvendor_slot_class::pos_x = game.core.io.mouse_x + npcvendor_slot_class::drag_offset_x;
                npcvendor_slot_class::pos_y = game.core.io.mouse_y + npcvendor_slot_class::drag_offset_y;
            }
            else
            {
                if ((game.item[temp_ID].type == HEALTH_POTION) || (game.item[temp_ID].type == MANA_POTION))
                {
                    for (int action_slot_count = 1; action_slot_count < MAX_ACTION_SLOTS; action_slot_count++)
                    {
                        if (game.UI.action_bar.action_slot[action_slot_count].mouse_over)
                        {
                            game.UI.action_bar.action_slot[action_slot_count].button_type  = 1000 + active_npcvendor_slot;
                            game.UI.action_bar.action_slot[action_slot_count].current_item = npcvendor_slot_class::button_type;
                        }
                    }
                }
                for (int npcvendor_slot_count = 1; npcvendor_slot_count < MAX_NPCVENDOR_SLOTS; npcvendor_slot_count++)
                {
                    if (game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].mouse_over)
                    {
                        if   ((npcvendor_slot_class::button_type == game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].button_type)
                            && (npcvendor_slot_class::base_pos_x != game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].base_pos_x)
                            && (npcvendor_slot_class::base_pos_y != game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].base_pos_y))
                        {
                            game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].quantity += npcvendor_slot_class::quantity;
                            npcvendor_slot_class::quantity = 0;
                            if (game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].quantity > game.item[game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].button_type].max_stack_number)
                            {
                                npcvendor_slot_class::quantity = game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].quantity - game.item[game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].button_type].max_stack_number;
                                game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].quantity = game.item[game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].button_type].max_stack_number;
                            }
                            if (npcvendor_slot_class::quantity <= 0)
                            {
                                npcvendor_slot_class::button_type  = 0;
                                npcvendor_slot_class::quantity     = 1;
                                npcvendor_slot_class::max_quantity = 1;
                            }
                        }
                        else
                        {
                            temp_button = npcvendor_slot_class::button_type;
                            npcvendor_slot_class::button_type = game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].button_type;
                            game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].button_type = temp_button;
                            temp_button = npcvendor_slot_class::quantity;
                            npcvendor_slot_class::quantity = game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].quantity;
                            game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].quantity = temp_button;
                            temp_button = npcvendor_slot_class::max_quantity;
                            npcvendor_slot_class::max_quantity = game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].max_quantity;
                            game.UI.npcvendor.npcvendor_slot[npcvendor_slot_count].max_quantity = temp_button;
                        }
                        temp_ID = npcvendor_slot_class::button_type;
                        if (game.item[temp_ID].sound.quantity_relocate > 0)
                        {
                            if (game.item[temp_ID].sound.quantity_relocate == 1) temp_int = 0;
                            else temp_int = random(game.item[temp_ID].sound.quantity_relocate);
                            if (temp_int > game.item[temp_ID].sound.quantity_relocate-1) temp_int = game.item[temp_ID].sound.quantity_relocate-1;
                            if (temp_int < 0) temp_int = 0;
                            game.resource.sound.play(game.item[temp_ID].sound.relocate[temp_int]);
                        }
                    }
                }
                for (int equipment_slot_count = 1; equipment_slot_count < MAX_EQUIPMENT_SLOTS; equipment_slot_count++)
                {
                    if (game.UI.equipment.equipment_slot[equipment_slot_count].mouse_over)
                    {
                        if (game.UI.equipment.equipment_slot[equipment_slot_count].slot_type == game.item[temp_ID].type)
                        {
                            if(game.UI.equipment.equipment_slot[equipment_slot_count].button_type == 0)
                            {
                                game.item[temp_ID].equip();
                            }
                            else
                            {
                                game.item[game.UI.equipment.equipment_slot[equipment_slot_count].button_type].unequip();
                                game.item[temp_ID].equip();
                            }
                            temp_button = npcvendor_slot_class::button_type;
                            npcvendor_slot_class::button_type = game.UI.equipment.equipment_slot[equipment_slot_count].button_type;
                            game.UI.equipment.equipment_slot[equipment_slot_count].button_type = temp_button;
                            npcvendor_slot_class::quantity     = 1;
                            npcvendor_slot_class::max_quantity = 1;
                        }
                        if (game.UI.equipment.equipment_slot[equipment_slot_count].slot_type == WEAPON)
                        {
                            if ((game.item[temp_ID].type == WAND) || (game.item[temp_ID].type == SWORD) || (game.item[temp_ID].type == DAGGER)|| (game.item[temp_ID].type == BOW) || (game.item[temp_ID].type == SLING))
                            {
                            if(game.UI.equipment.equipment_slot[equipment_slot_count].button_type == 0)
                            {
                                game.item[temp_ID].equip();
                            }
                            else
                            {
                                game.item[game.UI.equipment.equipment_slot[equipment_slot_count].button_type].unequip();
                                game.item[temp_ID].equip();
                            }
                                temp_button = npcvendor_slot_class::button_type;
                                npcvendor_slot_class::button_type = game.UI.equipment.equipment_slot[equipment_slot_count].button_type;
                                game.UI.equipment.equipment_slot[equipment_slot_count].button_type = temp_button;
                                npcvendor_slot_class::quantity     = 1;
                                npcvendor_slot_class::max_quantity = 1;
                            }
                        }
                    }
                }
                npcvendor_slot_class::drag         = false;
                game.UI.drag_in_progress           = false;
                npcvendor_slot_class::pos_x        = npcvendor_slot_class::base_pos_x;
                npcvendor_slot_class::pos_y        = npcvendor_slot_class::base_pos_y;
            }
        }
        else
        {
            if ((!game.UI.drag_in_progress) && (npcvendor_slot_class::mouse_over) && (game.core.io.mouse_button_left))//drag
            {
                game.UI.active_window_list.add_to_list(NPCVENDOR_WINDOW);
                npcvendor_slot_class::drag          = true;
                game.UI.drag_in_progress            = true;
                npcvendor_slot_class::base_pos_x    = npcvendor_slot_class::pos_x;
                npcvendor_slot_class::base_pos_y    = npcvendor_slot_class::pos_y;
                npcvendor_slot_class::drag_offset_x = npcvendor_slot_class::pos_x - game.core.io.mouse_x;
                npcvendor_slot_class::drag_offset_y = npcvendor_slot_class::pos_y - game.core.io.mouse_y;
            }
        }
        if ((npcvendor_slot_class::mouse_over) && (game.core.io.mouse_button_right) && (game.core.io.mouse_button_ready))//use item
        {
            bool play_use_sound = true;
            game.core.io.mouse_button_delay_count = 0;
            switch (game.item[temp_ID].type)
            {
                case HEALTH_POTION:
                    if (game.player.health.current < game.player.health.maximum)
                    {
                        game.player.health.current += game.item[temp_ID].add_health;
                        npcvendor_slot_class::quantity--;
                        if(npcvendor_slot_class::quantity <= 0) npcvendor_slot_class::button_type = 0;
                    }
                    else play_use_sound = false;
                break;
                case MANA_POTION:
                    if (game.player.mana.current < game.player.mana.maximum)
                    {
                        game.player.mana.current += game.item[temp_ID].add_mana;
                        npcvendor_slot_class::quantity--;
                        if(npcvendor_slot_class::quantity <= 0)npcvendor_slot_class::button_type = 0;
                    }
                    else play_use_sound = false;
                break;
                case SPELL_BOOK:
                    if (game.spell[game.item[temp_ID].spell_type].level < 3)
                    {
                        npcvendor_slot_class::quantity--;
                        if(npcvendor_slot_class::quantity <= 0)npcvendor_slot_class::button_type = 0;
                        game.spell[game.item[temp_ID].spell_type].level++;
                        if (game.spell[game.item[temp_ID].spell_type].level > 3) game.spell[game.item[temp_ID].spell_type].level = 3;
                    }
                    else play_use_sound = false;
                break;
                case SPELL_SCROLL:
                    npcvendor_slot_class::quantity--;
                    if(npcvendor_slot_class::quantity <= 0)npcvendor_slot_class::button_type = 0;
                break;

                //equip items below on right click?

                case HELM:
                break;
                case BOOTS:
                break;
                case ARMOUR:
                break;
                case GLOVES:
                break;
                case RING:
                break;
                case AMULET:
                break;
                case SHIELD:
                break;
                case WAND:
                break;
                case SWORD:
                break;
                case DAGGER:
                break;
                case BELT:
                break;
                case BOW:
                break;
                case SLING:
                break;
                default:
                break;
            }
            if (play_use_sound)
            {
                temp_ID = npcvendor_slot_class::button_type;
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
};

void npcvendor_slot_class::draw(void)
{
    std::string spacing = "                ";
    if (npcvendor_slot_class::button_type > 0)
    {
        game.resource.texture.render(false,game.item[npcvendor_slot_class::button_type].image_ref,npcvendor_slot_class::pos_x,npcvendor_slot_class::pos_y,npcvendor_slot_class::pos_z,npcvendor_slot_class::width,npcvendor_slot_class::height);
        if ((npcvendor_slot_class::quantity > 1) && (!npcvendor_slot_class::drag))
        {
            if (npcvendor_slot_class::quantity >   9) spacing += " ";
            if (npcvendor_slot_class::quantity >  99) spacing += " ";
            if (npcvendor_slot_class::quantity > 999) spacing += " ";
            game.resource.font.font_1.Write(255,255,255,255,npcvendor_slot_class::pos_x+0.012f,npcvendor_slot_class::pos_y-0.036f,7.0f,48.0f,npcvendor_slot_class::quantity,spacing);
        }
    }
};

void npcvendor_slot_class::draw_drag(void)
{
    if ((npcvendor_slot_class::button_type > 0) && (npcvendor_slot_class::drag))
    {
        game.resource.texture.render(false,game.item[npcvendor_slot_class::button_type].image_ref,npcvendor_slot_class::pos_x,npcvendor_slot_class::pos_y,npcvendor_slot_class::pos_z,npcvendor_slot_class::width,npcvendor_slot_class::height);
    }
};

void npcvendor_slot_class::draw_tooltip(void)
{
    if ((npcvendor_slot_class::button_type > 0) && (!npcvendor_slot_class::drag) && (npcvendor_slot_class::mouse_over_count == npcvendor_slot_class::tooltip_time))
    {
        std::string text_padding    = "";
        int         number_of_lines = 0;
        if (game.item[npcvendor_slot_class::button_type].max_damage               > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].armour                   > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_max_health           > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].sub_max_health           > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_max_mana             > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].sub_max_mana             > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_health_regeneration  > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].sub_health_regeneration  > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_mana_regeneration    > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].sub_mana_regeneration    > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_crit_chance          > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].sub_crit_chance          > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_walk_speed           > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].sub_walk_speed           > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_light_radius         > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].sub_light_radius         > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_flame_damage         > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_frost_damage         > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_lightning_damage     > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_magic_damage         > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_flame_resistance     > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_frost_resistance     > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_lightning_resistance > 0) number_of_lines++;
        if (game.item[npcvendor_slot_class::button_type].add_all_resistances      > 0) number_of_lines++;
        if (number_of_lines > 0) number_of_lines += 2;
        else number_of_lines += 1;
        float line_height = 0.04f;
        float width       = line_height*7.4f;
        float height      = line_height*number_of_lines+(line_height/4);
        float x_pos       = game.core.io.mouse_x+line_height;
        float y_pos       = game.core.io.mouse_y-line_height;
        game.resource.texture.item_stat_background.draw(false,game.core.io.mouse_x+(width/2),game.core.io.mouse_y-(height/2),npcvendor_slot_class::pos_z,width,height);
        game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,game.item[npcvendor_slot_class::button_type].name);
        y_pos -= line_height;
        y_pos -= line_height;
        if(game.item[npcvendor_slot_class::button_type].max_damage > 0)
        {
            text_padding = "";
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Damage ->                  ",game.item[npcvendor_slot_class::button_type].min_damage, " - ",game.item[npcvendor_slot_class::button_type].max_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_frost_damage > 0)
        {
            text_padding = "";
            game.resource.font.font_1.Write(191,191,255,255,x_pos,y_pos,4.8f,32.0f,"Frost Damage ->            ",game.item[npcvendor_slot_class::button_type].add_frost_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_flame_damage > 0)
        {
            text_padding = "";
            game.resource.font.font_1.Write(255,191,191,255,x_pos,y_pos,4.8f,32.0f,"Fire Damage ->             ",game.item[npcvendor_slot_class::button_type].add_flame_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_lightning_damage > 0)
        {
            text_padding = "";
            game.resource.font.font_1.Write(255,255,191,255,x_pos,y_pos,4.8f,32.0f,"Lightning Damage ->        ",game.item[npcvendor_slot_class::button_type].add_lightning_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_magic_damage > 0)
        {
            text_padding = "";
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Magic Damage ->            ",game.item[npcvendor_slot_class::button_type].add_magic_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].armour > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Armour ->                  ",game.item[npcvendor_slot_class::button_type].armour);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_max_health > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add max health ->          ",game.item[npcvendor_slot_class::button_type].add_max_health);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].sub_max_health > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub max health ->          ",game.item[npcvendor_slot_class::button_type].sub_max_health);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_max_mana > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add max mana ->            ",game.item[npcvendor_slot_class::button_type].add_max_mana);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].sub_max_mana > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub max mana ->            ",game.item[npcvendor_slot_class::button_type].sub_max_mana);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_health_regeneration > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add health regeneration -> ",game.item[npcvendor_slot_class::button_type].add_health_regeneration);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].sub_health_regeneration > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub health regeneration -> ",game.item[npcvendor_slot_class::button_type].sub_health_regeneration);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_mana_regeneration > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add mana regeneration ->   ",game.item[npcvendor_slot_class::button_type].add_mana_regeneration);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].sub_mana_regeneration > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub mana regeneration ->   ",game.item[npcvendor_slot_class::button_type].sub_mana_regeneration);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_crit_chance > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add crit chance ->         ",game.item[npcvendor_slot_class::button_type].add_crit_chance);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].sub_crit_chance > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub crit chance ->         ",game.item[npcvendor_slot_class::button_type].sub_crit_chance);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_walk_speed > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add walk speed ->          ",game.item[npcvendor_slot_class::button_type].add_walk_speed);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].sub_walk_speed > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub walk speed ->          ",game.item[npcvendor_slot_class::button_type].sub_walk_speed);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_light_radius > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add light radius ->        ",game.item[npcvendor_slot_class::button_type].add_light_radius);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].sub_light_radius > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub light radius ->        ",game.item[npcvendor_slot_class::button_type].sub_light_radius);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_flame_resistance > 0)
        {
            game.resource.font.font_1.Write(255,191,191,255,x_pos,y_pos,4.8f,32.0f,"Add Flame Resistance ->     ",game.item[npcvendor_slot_class::button_type].add_flame_resistance);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_frost_resistance > 0)
        {
            game.resource.font.font_1.Write(191,191,255,255,x_pos,y_pos,4.8f,32.0f,"Add Frost Resistance ->     ",game.item[npcvendor_slot_class::button_type].add_frost_resistance);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_lightning_resistance > 0)
        {
            game.resource.font.font_1.Write(255,255,191,255,x_pos,y_pos,4.8f,32.0f,"Add Lightning Resistance -> ",game.item[npcvendor_slot_class::button_type].add_lightning_resistance);
            y_pos -= line_height;
        }
        if(game.item[npcvendor_slot_class::button_type].add_all_resistances > 0)
        {
            game.resource.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add All Resistances ->      ",game.item[npcvendor_slot_class::button_type].add_all_resistances);
            y_pos -= line_height;
        }
    }
};

//----------------------------------------------------------------------------------------------------------------

npcvendor_class::npcvendor_class(void)
{
    npcvendor_class::pos_x         = 0.5f;
    npcvendor_class::pos_y         = 0.0f;
    npcvendor_class::pos_z         = 0.001;
    npcvendor_class::width         = 0.5f;
    npcvendor_class::height        = 1.0f;
    npcvendor_class::drag          = false;
    npcvendor_class::mouse_over    = false;
    npcvendor_class::drag_offset_x = 0.0f;
    npcvendor_class::drag_offset_y = 0.0f;

    npcvendor_class::npcvendor_slot[ 1].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 1].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[ 1].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
    npcvendor_class::npcvendor_slot[ 1].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 1].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 1].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[ 2].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 2].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[ 2].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
    npcvendor_class::npcvendor_slot[ 2].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 2].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 2].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[ 3].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 3].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[ 3].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
    npcvendor_class::npcvendor_slot[ 3].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 3].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 3].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[ 4].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 4].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[ 4].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
    npcvendor_class::npcvendor_slot[ 4].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 4].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 4].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[ 5].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 5].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[ 5].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
    npcvendor_class::npcvendor_slot[ 5].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 5].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 5].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[ 6].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 6].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[ 6].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
    npcvendor_class::npcvendor_slot[ 6].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 6].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 6].height       = npcvendor_class::height/14.6f;

    npcvendor_class::npcvendor_slot[ 7].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 7].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[ 7].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
    npcvendor_class::npcvendor_slot[ 7].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 7].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 7].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[ 8].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 8].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[ 8].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
    npcvendor_class::npcvendor_slot[ 8].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 8].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 8].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[ 9].button_type  = 0;
    npcvendor_class::npcvendor_slot[ 9].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[ 9].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
    npcvendor_class::npcvendor_slot[ 9].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[ 9].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[ 9].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[10].button_type  = 0;
    npcvendor_class::npcvendor_slot[10].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[10].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
    npcvendor_class::npcvendor_slot[10].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[10].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[10].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[11].button_type  = 0;
    npcvendor_class::npcvendor_slot[11].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[11].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
    npcvendor_class::npcvendor_slot[11].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[11].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[11].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[12].button_type  = 0;
    npcvendor_class::npcvendor_slot[12].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[12].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
    npcvendor_class::npcvendor_slot[12].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[12].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[12].height       = npcvendor_class::height/14.6f;

    npcvendor_class::npcvendor_slot[13].button_type  = 0;
    npcvendor_class::npcvendor_slot[13].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[13].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
    npcvendor_class::npcvendor_slot[13].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[13].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[13].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[14].button_type  = 0;
    npcvendor_class::npcvendor_slot[14].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[14].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
    npcvendor_class::npcvendor_slot[14].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[14].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[14].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[15].button_type  = 0;
    npcvendor_class::npcvendor_slot[15].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[15].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
    npcvendor_class::npcvendor_slot[15].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[15].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[15].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[16].button_type  = 0;
    npcvendor_class::npcvendor_slot[16].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[16].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
    npcvendor_class::npcvendor_slot[16].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[16].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[16].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[17].button_type  = 0;
    npcvendor_class::npcvendor_slot[17].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[17].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
    npcvendor_class::npcvendor_slot[17].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[17].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[17].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[18].button_type  = 0;
    npcvendor_class::npcvendor_slot[18].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[18].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
    npcvendor_class::npcvendor_slot[18].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[18].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[18].height       = npcvendor_class::height/14.6f;

    npcvendor_class::npcvendor_slot[19].button_type  = 0;
    npcvendor_class::npcvendor_slot[19].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[19].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
    npcvendor_class::npcvendor_slot[19].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[19].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[19].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[20].button_type  = 0;
    npcvendor_class::npcvendor_slot[20].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[20].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
    npcvendor_class::npcvendor_slot[20].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[20].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[20].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[21].button_type  = 0;
    npcvendor_class::npcvendor_slot[21].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[21].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
    npcvendor_class::npcvendor_slot[21].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[21].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[21].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[22].button_type  = 0;
    npcvendor_class::npcvendor_slot[22].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[22].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
    npcvendor_class::npcvendor_slot[22].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[22].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[22].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[23].button_type  = 0;
    npcvendor_class::npcvendor_slot[23].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[23].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
    npcvendor_class::npcvendor_slot[23].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[23].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[23].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[24].button_type  = 0;
    npcvendor_class::npcvendor_slot[24].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[24].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
    npcvendor_class::npcvendor_slot[24].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[24].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[24].height       = npcvendor_class::height/14.6f;

    npcvendor_class::npcvendor_slot[25].button_type  = 0;
    npcvendor_class::npcvendor_slot[25].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[25].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
    npcvendor_class::npcvendor_slot[25].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[25].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[25].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[26].button_type  = 0;
    npcvendor_class::npcvendor_slot[26].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[26].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
    npcvendor_class::npcvendor_slot[26].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[26].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[26].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[27].button_type  = 0;
    npcvendor_class::npcvendor_slot[27].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[27].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
    npcvendor_class::npcvendor_slot[27].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[27].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[27].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[28].button_type  = 0;
    npcvendor_class::npcvendor_slot[28].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[28].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
    npcvendor_class::npcvendor_slot[28].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[28].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[28].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[29].button_type  = 0;
    npcvendor_class::npcvendor_slot[29].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[29].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
    npcvendor_class::npcvendor_slot[29].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[29].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[29].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[30].button_type  = 0;
    npcvendor_class::npcvendor_slot[30].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[30].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
    npcvendor_class::npcvendor_slot[30].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[30].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[30].height       = npcvendor_class::height/14.6f;

    npcvendor_class::npcvendor_slot[31].button_type  = 0;
    npcvendor_class::npcvendor_slot[31].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[31].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
    npcvendor_class::npcvendor_slot[31].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[31].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[31].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[32].button_type  = 0;
    npcvendor_class::npcvendor_slot[32].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[32].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
    npcvendor_class::npcvendor_slot[32].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[32].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[32].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[33].button_type  = 0;
    npcvendor_class::npcvendor_slot[33].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[33].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
    npcvendor_class::npcvendor_slot[33].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[33].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[33].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[34].button_type  = 0;
    npcvendor_class::npcvendor_slot[34].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[34].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
    npcvendor_class::npcvendor_slot[34].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[34].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[34].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[35].button_type  = 0;
    npcvendor_class::npcvendor_slot[35].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[35].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
    npcvendor_class::npcvendor_slot[35].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[35].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[35].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[36].button_type  = 0;
    npcvendor_class::npcvendor_slot[36].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[36].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
    npcvendor_class::npcvendor_slot[36].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[36].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[36].height       = npcvendor_class::height/14.6f;

    npcvendor_class::npcvendor_slot[37].button_type  = 0;
    npcvendor_class::npcvendor_slot[37].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[37].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
    npcvendor_class::npcvendor_slot[37].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[37].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[37].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[38].button_type  = 0;
    npcvendor_class::npcvendor_slot[38].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[38].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
    npcvendor_class::npcvendor_slot[38].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[38].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[38].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[39].button_type  = 0;
    npcvendor_class::npcvendor_slot[39].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[39].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
    npcvendor_class::npcvendor_slot[39].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[39].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[39].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[40].button_type  = 0;
    npcvendor_class::npcvendor_slot[40].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[40].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
    npcvendor_class::npcvendor_slot[40].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[40].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[40].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[41].button_type  = 0;
    npcvendor_class::npcvendor_slot[41].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[41].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
    npcvendor_class::npcvendor_slot[41].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[41].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[41].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[42].button_type  = 0;
    npcvendor_class::npcvendor_slot[42].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[42].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
    npcvendor_class::npcvendor_slot[42].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[42].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[42].height       = npcvendor_class::height/14.6f;

    npcvendor_class::npcvendor_slot[43].button_type  = 0;
    npcvendor_class::npcvendor_slot[43].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
    npcvendor_class::npcvendor_slot[43].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
    npcvendor_class::npcvendor_slot[43].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[43].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[43].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[44].button_type  = 0;
    npcvendor_class::npcvendor_slot[44].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
    npcvendor_class::npcvendor_slot[44].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
    npcvendor_class::npcvendor_slot[44].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[44].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[44].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[45].button_type  = 0;
    npcvendor_class::npcvendor_slot[45].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
    npcvendor_class::npcvendor_slot[45].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
    npcvendor_class::npcvendor_slot[45].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[45].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[45].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[46].button_type  = 0;
    npcvendor_class::npcvendor_slot[46].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
    npcvendor_class::npcvendor_slot[46].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
    npcvendor_class::npcvendor_slot[46].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[46].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[46].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[47].button_type  = 0;
    npcvendor_class::npcvendor_slot[47].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
    npcvendor_class::npcvendor_slot[47].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
    npcvendor_class::npcvendor_slot[47].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[47].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[47].height       = npcvendor_class::height/14.6f;
    npcvendor_class::npcvendor_slot[48].button_type  = 0;
    npcvendor_class::npcvendor_slot[48].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
    npcvendor_class::npcvendor_slot[48].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
    npcvendor_class::npcvendor_slot[48].pos_z        = npcvendor_class::pos_z;
    npcvendor_class::npcvendor_slot[48].width        = npcvendor_class::width / 9.6f;
    npcvendor_class::npcvendor_slot[48].height       = npcvendor_class::height/14.6f;

    npcvendor_class::close_button.image_normal       = game.resource.texture.close_button.ref_number;
    npcvendor_class::close_button.image_highlighted  = game.resource.texture.close_button_highlighted.ref_number;
    npcvendor_class::close_button.mouse_over         = false;
    npcvendor_class::close_button.activated          = false;
    npcvendor_class::close_button.pos_x              = npcvendor_class::pos_x + (npcvendor_class::width /2.406f);
    npcvendor_class::close_button.pos_y              = npcvendor_class::pos_y + (npcvendor_class::height/2.20f);
    npcvendor_class::close_button.pos_z              = npcvendor_class::pos_z;
    npcvendor_class::close_button.width              = npcvendor_class::width / 7.0f;
    npcvendor_class::close_button.height             = npcvendor_class::height/10.4f;
};

npcvendor_class::~npcvendor_class(void)
{

};

void npcvendor_class::process(void)
{
    npcvendor_class::close_button.process();
    for (int npcvendor_slot_count = 1; npcvendor_slot_count < MAX_NPCVENDOR_SLOTS; npcvendor_slot_count++)
    {
        npcvendor_class::npcvendor_slot[npcvendor_slot_count].process();
    }
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(npcvendor_class::pos_x,npcvendor_class::width,npcvendor_class::pos_y+(npcvendor_class::height/2.2f),npcvendor_class::height/8.8f,game.core.io.mouse_x,game.core.io.mouse_y))) npcvendor_class::mouse_over = true;
    else npcvendor_class::mouse_over = false;
    if (npcvendor_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            npcvendor_class::pos_x = game.core.io.mouse_x + npcvendor_class::drag_offset_x;
            npcvendor_class::pos_y = game.core.io.mouse_y + npcvendor_class::drag_offset_y;
            npcvendor_class::close_button.pos_x = npcvendor_class::pos_x + (npcvendor_class::width /2.406f);
            npcvendor_class::close_button.pos_y = npcvendor_class::pos_y + (npcvendor_class::height/2.20f);
            npcvendor_class::npcvendor_slot[ 1].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[ 1].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
            npcvendor_class::npcvendor_slot[ 2].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[ 2].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
            npcvendor_class::npcvendor_slot[ 3].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[ 3].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
            npcvendor_class::npcvendor_slot[ 4].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[ 4].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
            npcvendor_class::npcvendor_slot[ 5].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[ 5].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
            npcvendor_class::npcvendor_slot[ 6].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[ 6].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/3.26f);
            npcvendor_class::npcvendor_slot[ 7].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[ 7].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
            npcvendor_class::npcvendor_slot[ 8].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[ 8].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
            npcvendor_class::npcvendor_slot[ 9].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[ 9].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
            npcvendor_class::npcvendor_slot[10].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[10].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
            npcvendor_class::npcvendor_slot[11].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[11].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
            npcvendor_class::npcvendor_slot[12].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[12].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/4.66f);
            npcvendor_class::npcvendor_slot[13].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[13].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
            npcvendor_class::npcvendor_slot[14].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[14].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
            npcvendor_class::npcvendor_slot[15].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[15].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
            npcvendor_class::npcvendor_slot[16].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[16].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
            npcvendor_class::npcvendor_slot[17].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[17].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
            npcvendor_class::npcvendor_slot[18].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[18].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/8.10f);
            npcvendor_class::npcvendor_slot[19].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[19].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
            npcvendor_class::npcvendor_slot[20].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[20].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
            npcvendor_class::npcvendor_slot[21].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[21].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
            npcvendor_class::npcvendor_slot[22].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[22].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
            npcvendor_class::npcvendor_slot[23].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[23].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
            npcvendor_class::npcvendor_slot[24].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[24].pos_y        = npcvendor_class::pos_y + (npcvendor_class::height/32.10f);
            npcvendor_class::npcvendor_slot[25].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[25].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
            npcvendor_class::npcvendor_slot[26].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[26].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
            npcvendor_class::npcvendor_slot[27].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[27].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
            npcvendor_class::npcvendor_slot[28].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[28].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
            npcvendor_class::npcvendor_slot[29].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[29].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
            npcvendor_class::npcvendor_slot[30].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[30].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/16.80f);
            npcvendor_class::npcvendor_slot[31].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[31].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
            npcvendor_class::npcvendor_slot[32].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[32].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
            npcvendor_class::npcvendor_slot[33].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[33].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
            npcvendor_class::npcvendor_slot[34].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[34].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
            npcvendor_class::npcvendor_slot[35].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[35].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
            npcvendor_class::npcvendor_slot[36].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[36].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/6.56f);
            npcvendor_class::npcvendor_slot[37].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[37].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
            npcvendor_class::npcvendor_slot[38].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[38].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
            npcvendor_class::npcvendor_slot[39].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[39].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
            npcvendor_class::npcvendor_slot[40].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[40].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
            npcvendor_class::npcvendor_slot[41].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[41].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
            npcvendor_class::npcvendor_slot[42].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[42].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/4.08f);
            npcvendor_class::npcvendor_slot[43].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /2.82f);
            npcvendor_class::npcvendor_slot[43].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
            npcvendor_class::npcvendor_slot[44].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /4.72f);
            npcvendor_class::npcvendor_slot[44].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
            npcvendor_class::npcvendor_slot[45].pos_x        = npcvendor_class::pos_x - (npcvendor_class::width /14.62f);
            npcvendor_class::npcvendor_slot[45].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
            npcvendor_class::npcvendor_slot[46].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /14.02f);
            npcvendor_class::npcvendor_slot[46].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
            npcvendor_class::npcvendor_slot[47].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /4.64f);
            npcvendor_class::npcvendor_slot[47].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
            npcvendor_class::npcvendor_slot[48].pos_x        = npcvendor_class::pos_x + (npcvendor_class::width /2.80f);
            npcvendor_class::npcvendor_slot[48].pos_y        = npcvendor_class::pos_y - (npcvendor_class::height/2.98f);
        }
        else
        {
            npcvendor_class::drag          = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (npcvendor_class::mouse_over) && (game.core.io.mouse_button_left))//drag
        {
            game.UI.active_window_list.add_to_list(NPCVENDOR_WINDOW);
            npcvendor_class::drag          = true;
            game.UI.drag_in_progress       = true;
            npcvendor_class::drag_offset_x = npcvendor_class::pos_x - game.core.io.mouse_x;
            npcvendor_class::drag_offset_y = npcvendor_class::pos_y - game.core.io.mouse_y;
        }
    }
    if (npcvendor_class::close_button.activated)
    {
        game.UI.active_window_list.remove_from_list(NPCVENDOR_WINDOW);
        game.core.npcvendor_active     = false;
        npcvendor_class::drag          = false;
        game.UI.drag_in_progress       = false;
        game.resource.sound.menu_select_00.play();
    }
};

void npcvendor_class::draw(void)
{
    std::string string_padding = "";
    game.resource.texture.inventory_background.draw(false,npcvendor_class::pos_x,npcvendor_class::pos_y,npcvendor_class::pos_z,npcvendor_class::width,npcvendor_class::height);
    npcvendor_class::close_button.draw();
    game.resource.font.font_1.Write(255,255,255,255,npcvendor_class::pos_x - (npcvendor_class::width /10.0f),npcvendor_class::pos_y + (npcvendor_class::height/2.30f),4.8f,32.0f,game.language.text.npcvendor);
    for (int npcvendor_slot_count = 1; npcvendor_slot_count < MAX_NPCVENDOR_SLOTS; npcvendor_slot_count++)
    {
        npcvendor_class::npcvendor_slot[npcvendor_slot_count].draw();
    }
    for (int npcvendor_slot_count = 1; npcvendor_slot_count < MAX_NPCVENDOR_SLOTS; npcvendor_slot_count++)
    {
        npcvendor_class::npcvendor_slot[npcvendor_slot_count].draw_tooltip();
    }
    for (int npcvendor_slot_count = 1; npcvendor_slot_count < MAX_NPCVENDOR_SLOTS; npcvendor_slot_count++)
    {
        npcvendor_class::npcvendor_slot[npcvendor_slot_count].draw_drag();
    }
};

void init_npcvendor(void)
{
    game.UI.npcvendor.npcvendor_slot[ 1].quantity     = 6;
    game.UI.npcvendor.npcvendor_slot[ 1].button_type  = game.item[ 101].ID;
    game.UI.npcvendor.npcvendor_slot[ 2].quantity     = 8;
    game.UI.npcvendor.npcvendor_slot[ 2].button_type  = game.item[ 102].ID;
    game.UI.npcvendor.npcvendor_slot[ 3].button_type  = game.item[ 301].ID;
    game.UI.npcvendor.npcvendor_slot[ 4].button_type  = game.item[ 302].ID;
    game.UI.npcvendor.npcvendor_slot[ 5].button_type  = game.item[ 401].ID;
    game.UI.npcvendor.npcvendor_slot[ 6].button_type  = game.item[ 601].ID;

    game.UI.npcvendor.npcvendor_slot[ 7].button_type  = game.item[ 701].ID;
    game.UI.npcvendor.npcvendor_slot[ 8].button_type  = game.item[ 702].ID;
    game.UI.npcvendor.npcvendor_slot[ 9].button_type  = game.item[ 703].ID;
    game.UI.npcvendor.npcvendor_slot[10].button_type  = game.item[ 702].ID;
    game.UI.npcvendor.npcvendor_slot[11].button_type  = game.item[ 703].ID;

    game.UI.npcvendor.npcvendor_slot[12].button_type  = game.item[ 801].ID;
    game.UI.npcvendor.npcvendor_slot[13].button_type  = game.item[ 802].ID;

    game.UI.npcvendor.npcvendor_slot[14].button_type  = game.item[ 704].ID;
    game.UI.npcvendor.npcvendor_slot[15].button_type  = game.item[ 705].ID;
    game.UI.npcvendor.npcvendor_slot[16].button_type  = game.item[ 501].ID;
    game.UI.npcvendor.npcvendor_slot[17].button_type  = game.item[ 502].ID;
    game.UI.npcvendor.npcvendor_slot[18].button_type  = game.item[ 602].ID;
    game.UI.npcvendor.npcvendor_slot[19].button_type  = game.item[ 901].ID;
    game.UI.npcvendor.npcvendor_slot[20].button_type  = game.item[ 303].ID;
    game.UI.npcvendor.npcvendor_slot[21].button_type  = game.item[ 402].ID;
    game.UI.npcvendor.npcvendor_slot[22].button_type  = game.item[ 403].ID;
    game.UI.npcvendor.npcvendor_slot[23].button_type  = game.item[ 902].ID;


    game.UI.npcvendor.npcvendor_slot[31].button_type  = game.item[1000].ID;
    game.UI.npcvendor.npcvendor_slot[32].button_type  = game.item[1001].ID;
    game.UI.npcvendor.npcvendor_slot[33].button_type  = game.item[1002].ID;
    game.UI.npcvendor.npcvendor_slot[34].button_type  = game.item[1003].ID;
    game.UI.npcvendor.npcvendor_slot[35].button_type  = game.item[1004].ID;
    game.UI.npcvendor.npcvendor_slot[36].button_type  = game.item[1005].ID;
    game.UI.npcvendor.npcvendor_slot[37].button_type  = game.item[1006].ID;
    game.UI.npcvendor.npcvendor_slot[38].button_type  = game.item[1007].ID;
    game.UI.npcvendor.npcvendor_slot[39].button_type  = game.item[1008].ID;
    game.UI.npcvendor.npcvendor_slot[40].button_type  = game.item[1009].ID;
    game.UI.npcvendor.npcvendor_slot[41].button_type  = game.item[1010].ID;
    game.UI.npcvendor.npcvendor_slot[42].button_type  = game.item[1011].ID;

    game.UI.npcvendor.npcvendor_slot[43].quantity     = 8;
    game.UI.npcvendor.npcvendor_slot[43].button_type  = game.item[ 201].ID;
    game.UI.npcvendor.npcvendor_slot[44].quantity     = 10;
    game.UI.npcvendor.npcvendor_slot[44].button_type  = game.item[ 201].ID;

    game.UI.npcvendor.npcvendor_slot[45].button_type  = game.item[ 201].ID;
    game.UI.npcvendor.npcvendor_slot[46].quantity     = 18;
    game.UI.npcvendor.npcvendor_slot[46].button_type  = game.item[ 207].ID;
    game.UI.npcvendor.npcvendor_slot[47].quantity     = 5;
    game.UI.npcvendor.npcvendor_slot[47].button_type  = game.item[ 208].ID;
    game.UI.npcvendor.npcvendor_slot[48].quantity     = 7;
    game.UI.npcvendor.npcvendor_slot[48].button_type  = game.item[ 214].ID;

};





