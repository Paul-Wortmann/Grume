/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <fstream>
#include "items.hpp"
#include "game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

void  item_class::init_items(void) // Initialize hard-coded default items, such as health potions etc...
{
    item_type*      temp_item_pointer;
    //------------------------- Health Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_HEALTH_POTION);
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.name                   = "Health Potion";
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_23.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    //------------------------- Mana Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_MANA_POTION);
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.name                   = "Mana Potion";
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_22.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = EFFECT_MOD_MANA;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
    //------------------------- Rejuvination Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_REJUVENATION_POTION);
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.name                   = "Rejuvenation Potion";
    temp_item_pointer->data.number_of_item_effects = 2;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    temp_item_pointer->data.effect[1]              = new effect_type;
    temp_item_pointer->data.effect[1]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
    //------------------------------------------------------------------------------------------------------------
    item_class::load_items("data/scripts/items.txt");
};

void item_class::load_items(std::string file_name)
{
    item_type*     temp_item_pointer;
    int            temp_char_UTF32  = ' ';
    std::string    temp_string_data;
    std::string    temp_string_key;
    std::string    temp_string_value;
    int            count;
    std::string    data_line;
    std::ifstream  script_file(file_name.c_str(),std::ios::in);
    if (script_file.is_open())
    {
        while ( script_file.good() )
        {
            getline(script_file,data_line);
            if (data_line.length() > 0)
            {
                if ('\r' == data_line.at(data_line.length()-1))
                {
                    data_line = data_line.substr(0, data_line.length()-1);
                }
            }
            {
                temp_char_UTF32 = data_line[0];
                if((temp_char_UTF32 != '#') && (data_line.length() > 2))
                {
                    temp_char_UTF32   = '#';
                    temp_string_key   = "";
                    temp_string_value = "";
                    count = 0;
                    while(temp_char_UTF32 != ' ')
                    {
                        temp_char_UTF32 = data_line[count];
                        if(temp_char_UTF32 != ' ') temp_string_key += temp_char_UTF32;
                        count++;
                        if(count > (int)data_line.length()) (temp_char_UTF32 = ' ');
                    }
                    while((temp_char_UTF32 == ' ') || (temp_char_UTF32 == '='))
                    {
                        temp_char_UTF32 = data_line[count];
                        count++;
                        if(count > (int)data_line.length()) (temp_char_UTF32 = '#');
                    }
                    count--;
                    while(count < ((int)data_line.length()-1))
                    {
                        temp_char_UTF32  = data_line[count];
                        if (temp_char_UTF32 != '"') temp_string_value += temp_char_UTF32;
                        count++;
                    }
                    temp_string_data = temp_string_value.c_str();
                    if (temp_string_key == "UID")
                    {
                        temp_item_pointer = game.item_manager.add_item(atoi(temp_string_data.c_str()));
                        temp_item_pointer->data.UID     = atoi(temp_string_data.c_str());
                        temp_item_pointer->data.active   = true;
                    }
                    if (temp_item_pointer != NULL)
                    {
                        temp_item_pointer->data.consumable = ((temp_string_key == "CONSUMABLE")&&(temp_string_data == "TRUE")) ? true : false;
                        if (temp_string_key == "NAME")             temp_item_pointer->data.name                   = temp_string_data.c_str();
                        if (temp_string_key == "TYPE")             temp_item_pointer->data.type                   = atoi(temp_string_data.c_str());
                        if (temp_string_key == "SUB_TYPE")         temp_item_pointer->data.sub_type               = atoi(temp_string_data.c_str());
                        if (temp_string_key == "NUM_ITEM_EFFECTS") temp_item_pointer->data.number_of_item_effects = atoi(temp_string_data.c_str());
                        if (temp_string_key == "NUM_ITEM_SOCKETS") temp_item_pointer->data.number_of_item_sockets = atoi(temp_string_data.c_str());
                        if (temp_string_key == "IMAGE")            temp_item_pointer->data.image                  = game.texture_manager.add_texture(temp_string_data.c_str());
                        if (temp_string_key == "SOUND_MOVE")       temp_item_pointer->data.sound_move             = game.sound_manager.add_sound(temp_string_data.c_str());
                        if (temp_string_key == "SOUND_USE")        temp_item_pointer->data.sound_use              = game.sound_manager.add_sound(temp_string_data.c_str());
                        if (temp_string_key == "EFFECT_0")         temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_1")         temp_item_pointer->data.effect[1]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_2")         temp_item_pointer->data.effect[2]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_3")         temp_item_pointer->data.effect[3]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_4")         temp_item_pointer->data.effect[4]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_5")         temp_item_pointer->data.effect[5]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                    }
                }
            }
        }
        script_file.close();
    }
};

void item_class::use_item(UI_form_struct *UI_form_pointer, int element_number)
{
    bool used_item = false;
    if (UI_form_pointer->data.element[element_number].active)
    {
        item_type* temp_item_pointer;
        temp_item_pointer = game.item_manager.add_item(UI_form_pointer->data.element[element_number].value);
        if (temp_item_pointer->data.consumable)
        {
            //game.core.log.file_write("---- use item function ------");
            for (int effect_count = 0; effect_count < temp_item_pointer->data.number_of_item_effects; effect_count++)
            {
                switch (temp_item_pointer->data.effect[effect_count]->data.type)
                {
                    case EFFECT_MOD_HEALTH:
                        if (game.player.health.current < game.player.health.maximum)
                        {
                            used_item = true;
                            game.player.health.current += temp_item_pointer->data.effect[effect_count]->data.value;
                        }
                    break;
                    case EFFECT_MOD_MANA:
                        if (game.player.mana.current < game.player.mana.maximum)
                        {
                            used_item = true;
                            game.player.mana.current += temp_item_pointer->data.effect[effect_count]->data.value;
                        }
                    break;
                    default:
                    break;
                }
            }
            if (used_item)
            {
                UI_form_pointer->data.element[element_number].quantity--;
                if (UI_form_pointer->data.element[element_number].quantity <= 0)
                {
                    UI_form_pointer->data.element[element_number].active   = false;
                    UI_form_pointer->data.element[element_number].value    = -1;
                    UI_form_pointer->data.element[element_number].quantity = 0;
                }
                game.sound_manager.play(temp_item_pointer->data.sound_use);
            }
        }
    }
};

void item_class::equip_item(item_type* item_pointer)
{
    for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
    {
        switch (item_pointer->data.effect[effect_count]->data.type)
        {
            case EFFECT_MOD_CRIT_CHANCE:
            break;
            case EFFECT_MOD_CRIT_DAMMAGE:
            break;
            case EFFECT_MOD_HEALTH:
                if (item_pointer->data.effect[effect_count]->data.passive) game.player.health.regeneration += item_pointer->data.effect[effect_count]->data.value;
            break;
            case EFFECT_MOD_LIGHT_RADIUS:
            break;
            case EFFECT_MOD_MANA:
            break;
            case EFFECT_MOD_WALK_SPEED:
            break;
            case EFFECT_SPELL:
            break;
            default:
            break;
        }
    }
};

void item_class::unequip_item(item_type* item_pointer)
{
    for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
    {
        switch (item_pointer->data.effect[effect_count]->data.type)
        {
            case EFFECT_MOD_CRIT_CHANCE:
            break;
            case EFFECT_MOD_CRIT_DAMMAGE:
            break;
            case EFFECT_MOD_HEALTH:
                if (item_pointer->data.effect[effect_count]->data.passive) game.player.health.regeneration -= item_pointer->data.effect[effect_count]->data.value;
            break;
            case EFFECT_MOD_LIGHT_RADIUS:
            break;
            case EFFECT_MOD_MANA:
            break;
            case EFFECT_MOD_WALK_SPEED:
            break;
            case EFFECT_SPELL:
            break;
            default:
            break;
        }
    }
};
