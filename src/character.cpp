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

#include "character.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

character_check_box_class::character_check_box_class(void)
{
    character_check_box_class::image_true_normal        = 0;
    character_check_box_class::image_true_highlighted   = 0;
    character_check_box_class::image_false_normal       = 0;
    character_check_box_class::image_false_highlighted  = 0;
    character_check_box_class::mouse_over               = false;
    character_check_box_class::activated                = false;
    character_check_box_class::state                    = false;
    character_check_box_class::pos_x                    = 0.0f;
    character_check_box_class::pos_y                    = 0.0f;
    character_check_box_class::pos_z                    = 0.0f;
    character_check_box_class::width                    = 0.0f;
    character_check_box_class::height                   = 0.0f;
};

character_check_box_class::~character_check_box_class(void)
{
};

void character_check_box_class::process(void)
{
    if (!game.UI.drag_in_progress)
    {
        character_check_box_class::mouse_over = game.core.physics.point_in_quadrangle(character_check_box_class::pos_x,character_check_box_class::width,character_check_box_class::pos_y,character_check_box_class::height,game.core.io.mouse_x,game.core.io.mouse_y);
        if (character_check_box_class::mouse_over && game.core.io.mouse_button_left && game.core.io.mouse_button_ready)
        {
            character_check_box_class::activated = true;
            character_check_box_class::state = !character_check_box_class::state;
            game.core.io.mouse_button_delay_count = 0;
            game.player.auto_allocate = character_check_box_class::state;
        }
    }
};

void character_check_box_class::draw(void)
{
    if(character_check_box_class::state)
    {
        if (character_check_box_class::mouse_over) draw_texture(false,character_check_box_class::image_true_highlighted,character_check_box_class::pos_x,character_check_box_class::pos_y,character_check_box_class::pos_z,character_check_box_class::width,character_check_box_class::height);
        else draw_texture(false,character_check_box_class::image_true_normal,character_check_box_class::pos_x,character_check_box_class::pos_y,character_check_box_class::pos_z,character_check_box_class::width,character_check_box_class::height);
    }
    else
    {
        if (character_check_box_class::mouse_over) draw_texture(false,character_check_box_class::image_false_highlighted,character_check_box_class::pos_x,character_check_box_class::pos_y,character_check_box_class::pos_z,character_check_box_class::width,character_check_box_class::height);
        else draw_texture(false,character_check_box_class::image_false_normal,character_check_box_class::pos_x,character_check_box_class::pos_y,character_check_box_class::pos_z,character_check_box_class::width,character_check_box_class::height);
    }
};

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

    character_class::close_button.image_normal       = game.texture.close_button.ref_number;
    character_class::close_button.image_highlighted  = game.texture.close_button_highlighted.ref_number;
    character_class::close_button.mouse_over         = false;
    character_class::close_button.activated          = false;
    character_class::close_button.pos_x              = character_class::pos_x + (character_class::width /2.406f);
    character_class::close_button.pos_y              = character_class::pos_y + (character_class::height/2.20f);
    character_class::close_button.pos_z              = character_class::pos_z;
    character_class::close_button.width              = character_class::width / 7.0f;
    character_class::close_button.height             = character_class::height/10.4f;

    character_class::auto_points_box.image_true_normal       = game.texture.close_button.ref_number;
    character_class::auto_points_box.image_true_highlighted  = game.texture.close_button_highlighted.ref_number;
    character_class::auto_points_box.mouse_over              = false;
    character_class::auto_points_box.activated               = false;
    character_class::auto_points_box.pos_x                   = character_class::pos_x - (character_class::width / 12.0f);
    character_class::auto_points_box.pos_y                   = character_class::pos_y - (character_class::height/ 2.28f);
    character_class::auto_points_box.pos_z                   = character_class::pos_z;
    character_class::auto_points_box.width                   = character_class::width /14.0f;
    character_class::auto_points_box.height                  = character_class::height/14.0f;
};

character_class::~character_class(void)
{

};

void character_class::process(void)
{
    character_class::close_button.process();
    character_class::auto_points_box.process();
    if ((!game.UI.drag_in_progress) && (game.core.physics.point_in_quadrangle(character_class::pos_x,character_class::width,character_class::pos_y+(character_class::height/2.2f),character_class::height/8.8f,game.core.io.mouse_x,game.core.io.mouse_y))) character_class::mouse_over = true;
    else character_class::mouse_over = false;
    if (character_class::drag)
    {
        if (game.core.io.mouse_button_left)
        {
            character_class::pos_x = game.core.io.mouse_x + character_class::drag_offset_x;
            character_class::pos_y = game.core.io.mouse_y + character_class::drag_offset_y;
            character_class::close_button.pos_x    = character_class::pos_x + (character_class::width /2.406f);
            character_class::close_button.pos_y    = character_class::pos_y + (character_class::height/2.20f);
            character_class::auto_points_box.pos_x = character_class::pos_x - (character_class::width / 12.0f);
            character_class::auto_points_box.pos_y = character_class::pos_y - (character_class::height/ 2.28f);
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
            game.UI.active_window_list.add_to_list(CHARACTER_WINDOW);
            character_class::drag          = true;
            game.UI.drag_in_progress       = true;
            character_class::drag_offset_x = character_class::pos_x - game.core.io.mouse_x;
            character_class::drag_offset_y = character_class::pos_y - game.core.io.mouse_y;
        }
    }
    if (character_class::close_button.activated)
    {
        game.UI.active_window_list.remove_from_list(CHARACTER_WINDOW);
        game.core.character_active     = false;
        character_class::drag          = false;
        game.UI.drag_in_progress       = false;
        game.sound.menu_select_00.play();
    }
};

void character_class::draw(void)
{
    int temp_level = 0;
    std::string string_padding = "";
    game.texture.character_background.draw(false,character_class::pos_x,character_class::pos_y,character_class::pos_z,character_class::width,character_class::height);
    character_class::close_button.draw();
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /7.0f),character_class::pos_y + (character_class::height/2.30f),4.8f,32.0f,game.language.text.character_menu);
    game.texture.character_portrait_frame.draw(false,character_class::pos_x-(character_class::width/3.2f),character_class::pos_y+(character_class::height/4.0f),character_class::pos_z,character_class::width/6.0f,character_class::height/6.0f);
    draw_texture(false,game.player.portrait_image_ref,character_class::pos_x-(character_class::width/3.2f),character_class::pos_y+(character_class::height/4.0f),character_class::pos_z,character_class::width/6.7f,character_class::height/6.7f);
    string_padding = "   ";
    while (game.player.name.size() < 14) game.player.name += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /6.0f),character_class::pos_y + (character_class::height/3.2f),4.8f,32.0f,"Name: ",game.player.name+string_padding);
    string_padding = "                ";
    temp_level = game.player.level.current;
    if ((unsigned)temp_level <                   9u) string_padding += " ";
    if ((unsigned)temp_level <                  99u) string_padding += " ";
    if ((unsigned)temp_level <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /6.0f),character_class::pos_y + (character_class::height/3.6f),4.8f,32.0f,"Level: ",game.player.level.current,string_padding);
    string_padding = "";
    temp_level = game.player.level.current_experience;
    if ((unsigned)temp_level <                   9u) string_padding += " ";
    if ((unsigned)temp_level <                  99u) string_padding += " ";
    if ((unsigned)temp_level <                 999u) string_padding += " ";
    if ((unsigned)temp_level <                9999u) string_padding += " ";
    if ((unsigned)temp_level <               99999u) string_padding += " ";
    if ((unsigned)temp_level <              999999u) string_padding += " ";
    if ((unsigned)temp_level <             9999999u) string_padding += " ";
    if ((unsigned)temp_level <            99999999u) string_padding += " ";
    if ((unsigned)temp_level <           999999999u) string_padding += " ";
    if ((unsigned)temp_level <          9999999999u) string_padding += " ";
    if ((unsigned)temp_level <         99999999999u) string_padding += " ";
    if ((unsigned)temp_level <        999999999999u) string_padding += " ";
    if ((unsigned)temp_level <       9999999999999u) string_padding += " ";
    if ((unsigned)temp_level <      99999999999999u) string_padding += " ";
    if ((unsigned)temp_level <     999999999999999u) string_padding += " ";
    if ((unsigned)temp_level <    9999999999999999u) string_padding += " ";
    if ((unsigned)temp_level <   99999999999999999u) string_padding += " ";
    if ((unsigned)temp_level <  999999999999999999u) string_padding += " ";
    if ((unsigned)temp_level < 9999999999999999999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /6.0f),character_class::pos_y + (character_class::height/4.2f),4.8f,32.0f,"EXP:   ",game.player.level.current_experience,string_padding);
    string_padding = "";
    temp_level = game.player.level.experience[game.player.level.current+1];
    if (game.player.level.current+1 > MAX_LEVELS) temp_level = game.player.level.experience[game.player.level.current];
    if ((unsigned)temp_level <                  99u) string_padding += " ";
    if ((unsigned)temp_level <                  99u) string_padding += " ";
    if ((unsigned)temp_level <                 999u) string_padding += " ";
    if ((unsigned)temp_level <                9999u) string_padding += " ";
    if ((unsigned)temp_level <               99999u) string_padding += " ";
    if ((unsigned)temp_level <              999999u) string_padding += " ";
    if ((unsigned)temp_level <             9999999u) string_padding += " ";
    if ((unsigned)temp_level <            99999999u) string_padding += " ";
    if ((unsigned)temp_level <           999999999u) string_padding += " ";
    if ((unsigned)temp_level <          9999999999u) string_padding += " ";
    if ((unsigned)temp_level <         99999999999u) string_padding += " ";
    if ((unsigned)temp_level <        999999999999u) string_padding += " ";
    if ((unsigned)temp_level <       9999999999999u) string_padding += " ";
    if ((unsigned)temp_level <      99999999999999u) string_padding += " ";
    if ((unsigned)temp_level <     999999999999999u) string_padding += " ";
    if ((unsigned)temp_level <    9999999999999999u) string_padding += " ";
    if ((unsigned)temp_level <   99999999999999999u) string_padding += " ";
    if ((unsigned)temp_level <  999999999999999999u) string_padding += " ";
    if ((unsigned)temp_level < 9999999999999999999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /6.0f),character_class::pos_y + (character_class::height/5.0f),4.8f,32.0f,"Next:  ",temp_level,string_padding);
    string_padding = "         ";
    if ((unsigned)game.player.offence <                   9u) string_padding += " ";
    if ((unsigned)game.player.offence <                  99u) string_padding += " ";
    if ((unsigned)game.player.offence <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y + (character_class::height/10.0f),4.8f,32.0f,"Offence:   ",game.player.offence,string_padding);
    string_padding = "         ";
    if ((unsigned)game.player.defense <                   9u) string_padding += " ";
    if ((unsigned)game.player.defense <                  99u) string_padding += " ";
    if ((unsigned)game.player.defense <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y + (character_class::height/16.0f),4.8f,32.0f,"Defense:   ",game.player.defense,string_padding);
    string_padding = "         ";
    if ((unsigned)game.player.intellect <                   9u) string_padding += " ";
    if ((unsigned)game.player.intellect <                  99u) string_padding += " ";
    if ((unsigned)game.player.intellect <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y + (character_class::height/36.0f),4.8f,32.0f,"Intellect: ",game.player.intellect,string_padding);

    string_padding = "        ";
    if ((unsigned)game.player.armor <                   9u) string_padding += " ";
    if ((unsigned)game.player.armor <                  99u) string_padding += " ";
    if ((unsigned)game.player.armor <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/48.0f),4.8f,32.0f,"Total Armor     ",(int)game.player.armor,string_padding);
    string_padding = "         ";
    if ((unsigned)game.player.critical_chance <                   9u) string_padding += " ";
    if ((unsigned)game.player.critical_chance <                  99u) string_padding += " ";
    if ((unsigned)game.player.critical_chance <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/16.0f),4.8f,32.0f,"Critical Chance: ",(int)game.player.critical_chance,string_padding);
    string_padding = "";
    if ((unsigned)game.player.damage_physical_maximum <                   9u) string_padding += " ";
    if ((unsigned)game.player.damage_physical_maximum <                  99u) string_padding += " ";
    if ((unsigned)game.player.damage_physical_maximum <                 999u) string_padding += " ";
    if ((unsigned)game.player.damage_physical_minimum <                   9u) string_padding += " ";
    if ((unsigned)game.player.damage_physical_minimum <                  99u) string_padding += " ";
    if ((unsigned)game.player.damage_physical_minimum <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/10.0f),4.8f,32.0f,"Physical Damage: ",(int)game.player.damage_physical_minimum," - ",(int)game.player.damage_physical_maximum,string_padding);

    string_padding = "";
    if ((unsigned)game.player.damage_frost <                   9u) string_padding += " ";
    if ((unsigned)game.player.damage_frost <                  99u) string_padding += " ";
    if ((unsigned)game.player.damage_frost <                 999u) string_padding += " ";
    game.font.font_1.Write(191,191,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 6.6f),4.8f,32.0f,"Frost Damage:         ",(int)game.player.damage_frost,string_padding);
    string_padding = "";
    if ((unsigned)game.player.damage_flame <                   9u) string_padding += " ";
    if ((unsigned)game.player.damage_flame <                  99u) string_padding += " ";
    if ((unsigned)game.player.damage_flame <                 999u) string_padding += " ";
    game.font.font_1.Write(255,191,191,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 5.4f),4.8f,32.0f,"Flame Damage:         ",(int)game.player.damage_flame,string_padding);
    string_padding = "";
    if ((unsigned)game.player.damage_lightning <                   9u) string_padding += " ";
    if ((unsigned)game.player.damage_lightning <                  99u) string_padding += " ";
    if ((unsigned)game.player.damage_lightning <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,191,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 4.6f),4.8f,32.0f,"Lightning Damage:     ",(int)game.player.damage_lightning,string_padding);

    string_padding = "";
    if ((unsigned)game.player.resistance_frost <                   9u) string_padding += " ";
    if ((unsigned)game.player.resistance_frost <                  99u) string_padding += " ";
    if ((unsigned)game.player.resistance_frost <                 999u) string_padding += " ";
    game.font.font_1.Write(191,191,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 3.8f),4.8f,32.0f,"Frost Resistance:     ",(int)game.player.resistance_frost,string_padding);
    string_padding = "";
    if ((unsigned)game.player.resistance_flame <                   9u) string_padding += " ";
    if ((unsigned)game.player.resistance_flame <                  99u) string_padding += " ";
    if ((unsigned)game.player.resistance_flame <                 999u) string_padding += " ";
    game.font.font_1.Write(255,191,191,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 3.4f),4.8f,32.0f,"Flame Resistance:     ",(int)game.player.resistance_flame,string_padding);
    string_padding = "";
    if ((unsigned)game.player.resistance_lightning <                   9u) string_padding += " ";
    if ((unsigned)game.player.resistance_lightning <                  99u) string_padding += " ";
    if ((unsigned)game.player.resistance_lightning <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,191,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 3.1f),4.8f,32.0f,"Lightning Resistance: ",(int)game.player.resistance_lightning,string_padding);

    string_padding = "";
    if ((unsigned)game.player.allocatable_points <                   9u) string_padding += " ";
    if ((unsigned)game.player.allocatable_points <                  99u) string_padding += " ";
    if ((unsigned)game.player.allocatable_points <                 999u) string_padding += " ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 2.4f),4.8f,32.0f,"Allocatable Points: ",(int)game.player.allocatable_points,string_padding);
    string_padding = "   ";
    game.font.font_1.Write(255,255,255,255,character_class::pos_x - (character_class::width /2.5f),character_class::pos_y - (character_class::height/ 2.2f),4.8f,32.0f,"Auto Allocate:      ",string_padding);
    character_class::auto_points_box.draw();
};



