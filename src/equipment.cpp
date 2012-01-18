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
    int  temp_button = 0;
    int  temp_ID = 0;
    if (game.core.physics.point_in_quadrangle(equipment_slot_class::pos_x,equipment_slot_class::width,equipment_slot_class::pos_y,equipment_slot_class::height,game.core.io.mouse_x,game.core.io.mouse_y)) equipment_slot_class::mouse_over = true;
    else equipment_slot_class::mouse_over = false;
    if (equipment_slot_class::mouse_over)
    {
        equipment_slot_class::mouse_over_count++;
        if (equipment_slot_class::mouse_over_count > equipment_slot_class::tooltip_time) equipment_slot_class::mouse_over_count = equipment_slot_class::tooltip_time;
    }
    else equipment_slot_class::mouse_over_count = 0;
    if (equipment_slot_class::button_type > 0)
    {
        if (equipment_slot_class::drag)
        {
            if (game.core.io.mouse_button_left)
            {
                equipment_slot_class::pos_x      = game.core.io.mouse_x + equipment_slot_class::drag_offset_x;
                equipment_slot_class::pos_y      = game.core.io.mouse_y + equipment_slot_class::drag_offset_y;
            }
            else
            {
                for (int inventory_slot_count = 1; inventory_slot_count < MAX_INVENTORY_SLOTS; inventory_slot_count++)
                {
                    if (game.UI.inventory.inventory_slot[inventory_slot_count].mouse_over)
                    {
                        temp_ID = game.UI.inventory.inventory_slot[inventory_slot_count].button_type;
                        if (game.UI.inventory.inventory_slot[inventory_slot_count].button_type <= 0)
                        {
                            game.item[equipment_slot_class::button_type].unequip();
                            temp_button = equipment_slot_class::button_type;
                            equipment_slot_class::button_type = game.UI.inventory.inventory_slot[inventory_slot_count].button_type;
                            game.UI.inventory.inventory_slot[inventory_slot_count].button_type = temp_button;
                        }
                        else if (equipment_slot_class::slot_type == game.item[temp_ID].type)
                        {
                            game.item[equipment_slot_class::button_type].unequip();
                            game.item[game.UI.inventory.inventory_slot[inventory_slot_count].button_type].equip();
                            temp_button = equipment_slot_class::button_type;
                            equipment_slot_class::button_type = game.UI.inventory.inventory_slot[inventory_slot_count].button_type;
                            game.UI.inventory.inventory_slot[inventory_slot_count].button_type = temp_button;
                        }
                        else if (equipment_slot_class::slot_type == WEAPON)
                        {
                            if ((game.item[temp_ID].type == WAND) || (game.item[temp_ID].type == SWORD) || (game.item[temp_ID].type == DAGGER)|| (game.item[temp_ID].type == BOW) || (game.item[temp_ID].type == SLING))
                            {
                                game.item[equipment_slot_class::button_type].unequip();
                                game.item[game.UI.inventory.inventory_slot[inventory_slot_count].button_type].equip();
                                temp_button = equipment_slot_class::button_type;
                                equipment_slot_class::button_type = game.UI.inventory.inventory_slot[inventory_slot_count].button_type;
                                game.UI.inventory.inventory_slot[inventory_slot_count].button_type = temp_button;
                            }
                        }
                    }
                }
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
                game.UI.active_window_list.add_to_list(EQUIPMENT_WINDOW);
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
    if (equipment_slot_class::drag)
    {
        if (equipment_slot_class::slot_size == 1) game.texture.equipment_slot_32x32.draw(false,equipment_slot_class::base_pos_x,equipment_slot_class::base_pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
        if (equipment_slot_class::slot_size == 2) game.texture.equipment_slot_64x32.draw(false,equipment_slot_class::base_pos_x,equipment_slot_class::base_pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
        if (equipment_slot_class::slot_size == 3) game.texture.equipment_slot_64x64.draw(false,equipment_slot_class::base_pos_x,equipment_slot_class::base_pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
        if (equipment_slot_class::slot_size == 4) game.texture.equipment_slot_64x96.draw(false,equipment_slot_class::base_pos_x,equipment_slot_class::base_pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
    }
    else
    {
        if (equipment_slot_class::slot_size == 1) game.texture.equipment_slot_32x32.draw(false,equipment_slot_class::pos_x,equipment_slot_class::pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
        if (equipment_slot_class::slot_size == 2) game.texture.equipment_slot_64x32.draw(false,equipment_slot_class::pos_x,equipment_slot_class::pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
        if (equipment_slot_class::slot_size == 3) game.texture.equipment_slot_64x64.draw(false,equipment_slot_class::pos_x,equipment_slot_class::pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
        if (equipment_slot_class::slot_size == 4) game.texture.equipment_slot_64x96.draw(false,equipment_slot_class::pos_x,equipment_slot_class::pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
    }
    if (equipment_slot_class::button_type > 0)
    {
        draw_texture(false,game.item[equipment_slot_class::button_type].image_ref,equipment_slot_class::pos_x,equipment_slot_class::pos_y,equipment_slot_class::pos_z,equipment_slot_class::width*0.90f,equipment_slot_class::height*0.90f);
    }
};

void equipment_slot_class::draw_drag(void)
{
    if ((equipment_slot_class::button_type > 0) && (equipment_slot_class::drag))
    {
        draw_texture(false,game.item[equipment_slot_class::button_type].image_ref,equipment_slot_class::pos_x,equipment_slot_class::pos_y,equipment_slot_class::pos_z,equipment_slot_class::width,equipment_slot_class::height);
    }
};

void equipment_slot_class::draw_tooltip(void)
{
    if ((equipment_slot_class::button_type > 0) && (!equipment_slot_class::drag) && (equipment_slot_class::mouse_over_count == equipment_slot_class::tooltip_time))
    {
        std::string text_padding    = "";
        int         number_of_lines = 0;
        if (game.item[equipment_slot_class::button_type].max_damage               > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].armour                   > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_max_health           > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].sub_max_health           > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_max_mana             > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].sub_max_mana             > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_health_regeneration  > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].sub_health_regeneration  > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_mana_regeneration    > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].sub_mana_regeneration    > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_crit_chance          > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].sub_crit_chance          > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_walk_speed           > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].sub_walk_speed           > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_light_radius         > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].sub_light_radius         > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_flame_damage         > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_frost_damage         > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_lightning_damage     > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_magic_damage         > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_flame_resistance     > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_frost_resistance     > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_lightning_resistance > 0) number_of_lines++;
        if (game.item[equipment_slot_class::button_type].add_all_resistances      > 0) number_of_lines++;
        if (number_of_lines > 0) number_of_lines += 2;
        else number_of_lines += 1;
        float line_height = 0.04f;
        float width       = line_height*7.4f;
        float height      = line_height*number_of_lines+(line_height/4);
        float x_pos       = game.core.io.mouse_x+line_height;
        float y_pos       = game.core.io.mouse_y-line_height;
        game.texture.item_stat_background.draw(false,game.core.io.mouse_x+(width/2),game.core.io.mouse_y-(height/2),equipment_slot_class::pos_z,width,height);
        game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,game.item[equipment_slot_class::button_type].name);
        y_pos -= line_height;
        y_pos -= line_height;
        if(game.item[equipment_slot_class::button_type].max_damage > 0)
        {
            text_padding = "";
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Damage ->                  ",game.item[equipment_slot_class::button_type].min_damage, " - ",game.item[equipment_slot_class::button_type].max_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_frost_damage > 0)
        {
            text_padding = "";
            game.font.font_1.Write(191,191,255,255,x_pos,y_pos,4.8f,32.0f,"Frost Damage ->            ",game.item[equipment_slot_class::button_type].add_frost_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_flame_damage > 0)
        {
            text_padding = "";
            game.font.font_1.Write(255,191,191,255,x_pos,y_pos,4.8f,32.0f,"Fire Damage ->             ",game.item[equipment_slot_class::button_type].add_flame_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_lightning_damage > 0)
        {
            text_padding = "";
            game.font.font_1.Write(255,255,191,255,x_pos,y_pos,4.8f,32.0f,"Lightning Damage ->        ",game.item[equipment_slot_class::button_type].add_lightning_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_magic_damage > 0)
        {
            text_padding = "";
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Magic Damage ->            ",game.item[equipment_slot_class::button_type].add_magic_damage,text_padding);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].armour > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Armour ->                  ",game.item[equipment_slot_class::button_type].armour);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_max_health > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add max health ->          ",game.item[equipment_slot_class::button_type].add_max_health);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].sub_max_health > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub max health ->          ",game.item[equipment_slot_class::button_type].sub_max_health);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_max_mana > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add max mana ->            ",game.item[equipment_slot_class::button_type].add_max_mana);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].sub_max_mana > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub max mana ->            ",game.item[equipment_slot_class::button_type].sub_max_mana);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_health_regeneration > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add health regeneration -> ",game.item[equipment_slot_class::button_type].add_health_regeneration);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].sub_health_regeneration > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub health regeneration -> ",game.item[equipment_slot_class::button_type].sub_health_regeneration);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_mana_regeneration > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add mana regeneration ->   ",game.item[equipment_slot_class::button_type].add_mana_regeneration);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].sub_mana_regeneration > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub mana regeneration ->   ",game.item[equipment_slot_class::button_type].sub_mana_regeneration);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_crit_chance > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add crit chance ->         ",game.item[equipment_slot_class::button_type].add_crit_chance);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].sub_crit_chance > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub crit chance ->         ",game.item[equipment_slot_class::button_type].sub_crit_chance);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_walk_speed > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add walk speed ->          ",game.item[equipment_slot_class::button_type].add_walk_speed);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].sub_walk_speed > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub walk speed ->          ",game.item[equipment_slot_class::button_type].sub_walk_speed);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_light_radius > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add light radius ->        ",game.item[equipment_slot_class::button_type].add_light_radius);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].sub_light_radius > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Sub light radius ->        ",game.item[equipment_slot_class::button_type].sub_light_radius);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_flame_resistance > 0)
        {
            game.font.font_1.Write(255,191,191,255,x_pos,y_pos,4.8f,32.0f,"Add Flame Resistance ->     ",game.item[equipment_slot_class::button_type].add_flame_resistance);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_frost_resistance > 0)
        {
            game.font.font_1.Write(191,191,255,255,x_pos,y_pos,4.8f,32.0f,"Add Frost Resistance ->     ",game.item[equipment_slot_class::button_type].add_frost_resistance);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_lightning_resistance > 0)
        {
            game.font.font_1.Write(255,255,191,255,x_pos,y_pos,4.8f,32.0f,"Add Lightning Resistance -> ",game.item[equipment_slot_class::button_type].add_lightning_resistance);
            y_pos -= line_height;
        }
        if(game.item[equipment_slot_class::button_type].add_all_resistances > 0)
        {
            game.font.font_1.Write(255,255,255,255,x_pos,y_pos,4.8f,32.0f,"Add All Resistances ->      ",game.item[equipment_slot_class::button_type].add_all_resistances);
            y_pos -= line_height;
        }
    }
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

    equipment_class::equipment_slot[ 1].button_type  = 0; // Helm
    equipment_class::equipment_slot[ 1].slot_size    = 3;
    equipment_class::equipment_slot[ 1].slot_type    = HELM;
    equipment_class::equipment_slot[ 1].pos_x        = equipment_class::pos_x; //- (equipment_class::width /2.0f);
    equipment_class::equipment_slot[ 1].pos_y        = equipment_class::pos_y + (equipment_class::height/4.0f);
    equipment_class::equipment_slot[ 1].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 2].button_type  = 0; // Armour
    equipment_class::equipment_slot[ 2].slot_size    = 4;
    equipment_class::equipment_slot[ 2].slot_type    = ARMOUR;
    equipment_class::equipment_slot[ 2].pos_x        = equipment_class::pos_x; //- (equipment_class::width /2.0f);
    equipment_class::equipment_slot[ 2].pos_y        = equipment_class::pos_y - (equipment_class::height/48.0f);
    equipment_class::equipment_slot[ 2].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 3].button_type  = 0; // Belt
    equipment_class::equipment_slot[ 3].slot_size    = 2;
    equipment_class::equipment_slot[ 3].slot_type    = BELT;
    equipment_class::equipment_slot[ 3].pos_x        = equipment_class::pos_x; //- (equipment_class::width /2.0f);
    equipment_class::equipment_slot[ 3].pos_y        = equipment_class::pos_y - (equipment_class::height/4.0f);
    equipment_class::equipment_slot[ 3].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 4].button_type  = 0; // Weapon
    equipment_class::equipment_slot[ 4].slot_size    = 4;
    equipment_class::equipment_slot[ 4].slot_type    = WEAPON;
    equipment_class::equipment_slot[ 4].pos_x        = equipment_class::pos_x - (equipment_class::width / 4.0f);
    equipment_class::equipment_slot[ 4].pos_y        = equipment_class::pos_y + (equipment_class::height/24.0f);
    equipment_class::equipment_slot[ 4].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 5].button_type  = 0; // Shield
    equipment_class::equipment_slot[ 5].slot_size    = 4;
    equipment_class::equipment_slot[ 5].slot_type    = SHIELD;
    equipment_class::equipment_slot[ 5].pos_x        = equipment_class::pos_x + (equipment_class::width / 4.0f);
    equipment_class::equipment_slot[ 5].pos_y        = equipment_class::pos_y + (equipment_class::height/24.0f);
    equipment_class::equipment_slot[ 5].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 6].button_type  = 0; // Gloves
    equipment_class::equipment_slot[ 6].slot_size    = 3;
    equipment_class::equipment_slot[ 6].slot_type    = GLOVES;
    equipment_class::equipment_slot[ 6].pos_x        = equipment_class::pos_x - (equipment_class::width / 4.0f);
    equipment_class::equipment_slot[ 6].pos_y        = equipment_class::pos_y - (equipment_class::height/ 4.8f);
    equipment_class::equipment_slot[ 6].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 7].button_type  = 0; // Boots
    equipment_class::equipment_slot[ 7].slot_size    = 3;
    equipment_class::equipment_slot[ 7].slot_type    = BOOTS;
    equipment_class::equipment_slot[ 7].pos_x        = equipment_class::pos_x + (equipment_class::width / 4.0f);
    equipment_class::equipment_slot[ 7].pos_y        = equipment_class::pos_y - (equipment_class::height/ 4.8f);
    equipment_class::equipment_slot[ 7].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 8].button_type  = 0; // Amulet Left
    equipment_class::equipment_slot[ 8].slot_size    = 1;
    equipment_class::equipment_slot[ 8].slot_type    = AMULET;
    equipment_class::equipment_slot[ 8].pos_x        = equipment_class::pos_x - (equipment_class::width / 4.8f);
    equipment_class::equipment_slot[ 8].pos_y        = equipment_class::pos_y + (equipment_class::height/ 4.0f);
    equipment_class::equipment_slot[ 8].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[ 9].button_type  = 0; // Amulet Right
    equipment_class::equipment_slot[ 9].slot_size    = 1;
    equipment_class::equipment_slot[ 9].slot_type    = AMULET;
    equipment_class::equipment_slot[ 9].pos_x        = equipment_class::pos_x + (equipment_class::width / 4.8f);
    equipment_class::equipment_slot[ 9].pos_y        = equipment_class::pos_y + (equipment_class::height/ 4.0f);
    equipment_class::equipment_slot[ 9].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[10].button_type  = 0; // Ring 1
    equipment_class::equipment_slot[10].slot_size    = 1;
    equipment_class::equipment_slot[10].slot_type    = RING;
    equipment_class::equipment_slot[10].pos_x        = equipment_class::pos_x - (equipment_class::width / 3.4f);
    equipment_class::equipment_slot[10].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
    equipment_class::equipment_slot[10].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[11].button_type  = 0; // Ring 2
    equipment_class::equipment_slot[11].slot_size    = 1;
    equipment_class::equipment_slot[11].slot_type    = RING;
    equipment_class::equipment_slot[11].pos_x        = equipment_class::pos_x - (equipment_class::width / 8.0f);
    equipment_class::equipment_slot[11].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
    equipment_class::equipment_slot[11].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[12].button_type  = 0; // Ring 3
    equipment_class::equipment_slot[12].slot_size    = 1;
    equipment_class::equipment_slot[12].slot_type    = RING;
    equipment_class::equipment_slot[12].pos_x        = equipment_class::pos_x + (equipment_class::width / 8.0f);
    equipment_class::equipment_slot[12].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
    equipment_class::equipment_slot[12].pos_z        = equipment_class::pos_z;
    equipment_class::equipment_slot[13].button_type  = 0; // Ring 4
    equipment_class::equipment_slot[13].slot_size    = 1;
    equipment_class::equipment_slot[13].slot_type    = RING;
    equipment_class::equipment_slot[13].pos_x        = equipment_class::pos_x + (equipment_class::width / 3.4f);
    equipment_class::equipment_slot[13].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
    equipment_class::equipment_slot[13].pos_z        = equipment_class::pos_z;

    for (int equipment_slot_count = 1; equipment_slot_count < MAX_EQUIPMENT_SLOTS; equipment_slot_count++)
    {
        equipment_class::equipment_slot[equipment_slot_count].base_pos_x = equipment_class::equipment_slot[equipment_slot_count].pos_x;
        equipment_class::equipment_slot[equipment_slot_count].base_pos_y = equipment_class::equipment_slot[equipment_slot_count].pos_y;
        switch (equipment_class::equipment_slot[equipment_slot_count].slot_size)
        {
            case 1: //32x32
                equipment_class::equipment_slot[equipment_slot_count].width        = equipment_class::width /12.0f;
                equipment_class::equipment_slot[equipment_slot_count].height       = equipment_class::height/12.0f;
            break;
            case 2: //64x32
                equipment_class::equipment_slot[equipment_slot_count].width        = equipment_class::width / 6.0f;
                equipment_class::equipment_slot[equipment_slot_count].height       = equipment_class::height/12.0f;
            break;
            case 3: //64x64
                equipment_class::equipment_slot[equipment_slot_count].width        = equipment_class::width / 6.0f;
                equipment_class::equipment_slot[equipment_slot_count].height       = equipment_class::height/ 6.0f;
            break;
            case 4: //64x96
                equipment_class::equipment_slot[equipment_slot_count].width        = equipment_class::width / 6.0f;
                equipment_class::equipment_slot[equipment_slot_count].height       = equipment_class::height/ 4.0f;
            break;
            default:
            break;
        }
    }

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
    for (int equipment_slot_count = 1; equipment_slot_count < MAX_EQUIPMENT_SLOTS; equipment_slot_count++)
    {
        equipment_class::equipment_slot[equipment_slot_count].process();
    }
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
            equipment_class::equipment_slot[ 1].pos_x        = equipment_class::pos_x; //- (equipment_class::width /2.0f);
            equipment_class::equipment_slot[ 1].pos_y        = equipment_class::pos_y + (equipment_class::height/4.0f);
            equipment_class::equipment_slot[ 2].pos_x        = equipment_class::pos_x; //- (equipment_class::width /2.0f);
            equipment_class::equipment_slot[ 2].pos_y        = equipment_class::pos_y - (equipment_class::height/48.0f);
            equipment_class::equipment_slot[ 3].pos_x        = equipment_class::pos_x; //- (equipment_class::width /2.0f);
            equipment_class::equipment_slot[ 3].pos_y        = equipment_class::pos_y - (equipment_class::height/4.0f);
            equipment_class::equipment_slot[ 4].pos_x        = equipment_class::pos_x - (equipment_class::width / 4.0f);
            equipment_class::equipment_slot[ 4].pos_y        = equipment_class::pos_y + (equipment_class::height/24.0f);
            equipment_class::equipment_slot[ 5].pos_x        = equipment_class::pos_x + (equipment_class::width / 4.0f);
            equipment_class::equipment_slot[ 5].pos_y        = equipment_class::pos_y + (equipment_class::height/24.0f);
            equipment_class::equipment_slot[ 6].pos_x        = equipment_class::pos_x - (equipment_class::width / 4.0f);
            equipment_class::equipment_slot[ 6].pos_y        = equipment_class::pos_y - (equipment_class::height/ 4.8f);
            equipment_class::equipment_slot[ 7].pos_x        = equipment_class::pos_x + (equipment_class::width / 4.0f);
            equipment_class::equipment_slot[ 7].pos_y        = equipment_class::pos_y - (equipment_class::height/ 4.8f);
            equipment_class::equipment_slot[ 8].pos_x        = equipment_class::pos_x - (equipment_class::width / 4.8f);
            equipment_class::equipment_slot[ 8].pos_y        = equipment_class::pos_y + (equipment_class::height/ 4.0f);
            equipment_class::equipment_slot[ 9].pos_x        = equipment_class::pos_x + (equipment_class::width / 4.8f);
            equipment_class::equipment_slot[ 9].pos_y        = equipment_class::pos_y + (equipment_class::height/ 4.0f);
            equipment_class::equipment_slot[10].pos_x        = equipment_class::pos_x - (equipment_class::width / 3.4f);
            equipment_class::equipment_slot[10].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
            equipment_class::equipment_slot[11].pos_x        = equipment_class::pos_x - (equipment_class::width / 8.0f);
            equipment_class::equipment_slot[11].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
            equipment_class::equipment_slot[12].pos_x        = equipment_class::pos_x + (equipment_class::width / 8.0f);
            equipment_class::equipment_slot[12].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
            equipment_class::equipment_slot[13].pos_x        = equipment_class::pos_x + (equipment_class::width / 3.4f);
            equipment_class::equipment_slot[13].pos_y        = equipment_class::pos_y - (equipment_class::height/ 2.6f);
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
    for (int equipment_slot_count = 1; equipment_slot_count < MAX_EQUIPMENT_SLOTS; equipment_slot_count++)
    {
        equipment_class::equipment_slot[equipment_slot_count].draw();
    }
    for (int equipment_slot_count = 1; equipment_slot_count < MAX_EQUIPMENT_SLOTS; equipment_slot_count++)
    {
        equipment_class::equipment_slot[equipment_slot_count].draw_tooltip();
    }
    for (int equipment_slot_count = 1; equipment_slot_count < MAX_EQUIPMENT_SLOTS; equipment_slot_count++)
    {
        equipment_class::equipment_slot[equipment_slot_count].draw_drag();
    }
};




