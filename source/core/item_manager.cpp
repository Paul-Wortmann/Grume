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
#include "item_manager.hpp"
#include "../game/game.hpp"
#include "../core/misc.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

item_manager_class::item_manager_class(void)
{
};

item_manager_class::~item_manager_class(void)
{
    delete [] item_manager_class::item;
};

item_type* item_manager_class::add_item(int item_UID)
{
    if (item_manager_class::number_of_items == 0)
    {
        item_manager_class::root = new item_type;
        item_manager_class::root->next = NULL;
        item_manager_class::last = new item_type;
        item_manager_class::last = root;
        item_manager_class::last->next = NULL;
    }
    else
    {
        item_type* temp_pointer;
        temp_pointer = new item_type;
        temp_pointer = item_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (temp_pointer->data.UID == item_UID) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        item_manager_class::last->next = new item_type;
        item_manager_class::last = item_manager_class::last->next;
        item_manager_class::last->next = new item_type;
        item_manager_class::last->next = NULL;
    }
    item_manager_class::last->data.active                 = false;
    item_manager_class::last->data.stackable              = false;
    item_manager_class::last->data.consumable             = false;
    item_manager_class::last->data.equipable              = false;
    item_manager_class::last->data.quest                  = false;
    item_manager_class::last->data.name                   = "";
    item_manager_class::last->data.number_of_item_effects = 0;
    item_manager_class::last->data.number_of_item_sockets = 0;
    item_manager_class::last->data.quantity               = 1;
    item_manager_class::last->data.quantity_max           = 1;
    item_manager_class::last->data.socketable             = false;
    item_manager_class::last->data.socket_max             = 0;
    item_manager_class::last->data.socket_type            = SOCKET_NONE;
    item_manager_class::last->data.type                   = ITEM_NONE;
    item_manager_class::last->data.sub_type               = ITEM_NONE;
    item_manager_class::last->data.UID                    = item_UID;
    item_manager_class::number_of_items++;
    return(item_manager_class::last);
};

int item_manager_class::get_new_item_UID(void)
{
    item_type* item_pointer;
    int  UID_max    = sizeof(int)*CHAR_BIT;
    bool found = true;
    for (int  temp_UID = 0; temp_UID < UID_max; temp_UID++)
    {
        found = true;
        for (item_pointer = item_manager_class::root; item_pointer != NULL; item_pointer = item_pointer->next)
        {
            if (item_pointer->data.UID == temp_UID) found = false;
        }
        if (found) return (temp_UID);
    }
    return (RETURN_FAIL);
};

void item_manager_class::load_items(std::string file_name)
{
    item_type*     item_pointer;
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
                        item_pointer = game.item_manager.add_item(atoi(temp_string_data.c_str()));
                        item_pointer->data.UID     = atoi(temp_string_data.c_str());
                        item_pointer->data.active   = true;
                    }
                    if (item_pointer != NULL)
                    {
                        item_pointer->data.consumable = ((temp_string_key == "CONSUMABLE")&&(temp_string_data == "TRUE")) ? true : false;
                        item_pointer->data.consumable = ((temp_string_key == "EQUIPABLE") &&(temp_string_data == "TRUE")) ? true : false;
                        item_pointer->data.consumable = ((temp_string_key == "QUEST")     &&(temp_string_data == "TRUE")) ? true : false;
                        if (temp_string_key == "NAME")             item_pointer->data.name                   = temp_string_data.c_str();
                        if (temp_string_key == "TYPE")             item_pointer->data.type                   = atoi(temp_string_data.c_str());
                        if (temp_string_key == "SUB_TYPE")         item_pointer->data.sub_type               = atoi(temp_string_data.c_str());
                        if (temp_string_key == "NUM_ITEM_EFFECTS") item_pointer->data.number_of_item_effects = atoi(temp_string_data.c_str());
                        if (temp_string_key == "NUM_ITEM_SOCKETS") item_pointer->data.number_of_item_sockets = atoi(temp_string_data.c_str());
                        if (temp_string_key == "IMAGE")            item_pointer->data.image                  = game.texture_manager.add_texture(temp_string_data.c_str());
                        if (temp_string_key == "SOUND_MOVE")       item_pointer->data.sound_move             = game.sound_manager.add_sound(temp_string_data.c_str());
                        if (temp_string_key == "SOUND_USE")        item_pointer->data.sound_use              = game.sound_manager.add_sound(temp_string_data.c_str());
                        if (temp_string_key == "EFFECT_0")         item_pointer->data.effect[0]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_1")         item_pointer->data.effect[1]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_2")         item_pointer->data.effect[2]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_3")         item_pointer->data.effect[3]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_4")         item_pointer->data.effect[4]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_5")         item_pointer->data.effect[5]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                    }
                }
            }
        }
        script_file.close();
    }
};

void item_manager_class::use_item(UI_form_struct *UI_form_pointer, int element_number)
{
    bool used_item = false;
    if (UI_form_pointer->data.element[element_number].active)
    {
        item_type* item_pointer;
        item_pointer = game.item_manager.add_item(UI_form_pointer->data.element[element_number].value);
        if (item_pointer->data.consumable)
        {
            //game.core.log.file_write("---- use item function ------");
            for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
            {
                used_item = game.effect_manager.use_effect(item_pointer->data.effect[effect_count]);
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
                game.sound_manager.play(item_pointer->data.sound_use);
            }
        }
    }
};

void item_manager_class::equip_item(item_type* item_pointer)
{
    for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
    {
        if (item_pointer->data.equipable)
        {
            game.effect_manager.use_effect(item_pointer->data.effect[effect_count]);
        }
    }
};

void item_manager_class::unequip_item(item_type* item_pointer)
{
    for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
    {
        if (item_pointer->data.equipable)
        {
            game.effect_manager.use_effect(item_pointer->data.effect[effect_count],(item_pointer->data.effect[effect_count]->data.value * -1));
        }
    }
};

int  item_manager_class::gen_item(int item_type_UID, int item_sub_type_UID, int quality_level)
{
    int  new_UID           = RETURN_FAIL;
    if (item_sub_type_UID == ITEM_POTION)
    {
        switch (random(3))
        {
            case 0:
                item_sub_type_UID = ITEM_POTION_SMALL;
            break;
            case 1:
                item_sub_type_UID = ITEM_POTION_MEDIUM;
            break;
            case 2:
                item_sub_type_UID = ITEM_POTION_LARGE;
            break;
            default:
                item_sub_type_UID = ITEM_POTION_LARGE;
            break;
        }
    }
    if (item_type_UID == ITEM_POTION)
    {
        switch (random(3))
        {
            case 0:
                switch (item_sub_type_UID)
                {
                    case ITEM_POTION_SMALL:
                        item_type_UID = ITEM_POTION_S_HEALTH;
                    break;
                    case ITEM_POTION_MEDIUM:
                        item_type_UID = ITEM_POTION_M_HEALTH;
                    break;
                    case ITEM_POTION_LARGE:
                        item_type_UID = ITEM_POTION_L_HEALTH;
                    break;
                    default:
                        item_type_UID = ITEM_POTION_L_HEALTH;
                    break;
                }
            break;
            case 1:
                switch (item_sub_type_UID)
                {
                    case ITEM_POTION_SMALL:
                        item_type_UID = ITEM_POTION_S_MANA;
                    break;
                    case ITEM_POTION_MEDIUM:
                        item_type_UID = ITEM_POTION_M_MANA;
                    break;
                    case ITEM_POTION_LARGE:
                        item_type_UID = ITEM_POTION_L_MANA;
                    break;
                    default:
                        item_type_UID = ITEM_POTION_L_MANA;
                    break;
                }
            break;
            case 2:
                switch (item_sub_type_UID)
                {
                    case ITEM_POTION_SMALL:
                        item_type_UID = ITEM_POTION_S_REJUVENATION;
                    break;
                    case ITEM_POTION_MEDIUM:
                        item_type_UID = ITEM_POTION_M_REJUVENATION;
                    break;
                    case ITEM_POTION_LARGE:
                        item_type_UID = ITEM_POTION_L_REJUVENATION;
                    break;
                    default:
                        item_type_UID = ITEM_POTION_L_REJUVENATION;
                    break;
                }
            break;
            default:
                switch (item_sub_type_UID)
                {
                    case ITEM_POTION_SMALL:
                        item_type_UID = ITEM_POTION_S_HEALTH;
                    break;
                    case ITEM_POTION_MEDIUM:
                        item_type_UID = ITEM_POTION_M_HEALTH;
                    break;
                    case ITEM_POTION_LARGE:
                        item_type_UID = ITEM_POTION_L_HEALTH;
                    break;
                    default:
                        item_type_UID = ITEM_POTION_L_HEALTH;
                    break;
                }
            break;
        }
    }
    //if (item_type_UID == ITEM_POTION) item_type_UID = (random(2) == 1) ? ITEM_HEALTH_POTION : ITEM_MANA_POTION;
    if ((item_sub_type_UID == ITEM_POTION_SMALL) || (item_sub_type_UID == ITEM_POTION_MEDIUM) || (item_sub_type_UID == ITEM_POTION_LARGE)) new_UID = item_type_UID;
    else new_UID = game.item_manager.get_new_item_UID();
    if (new_UID >= 0)
    {
        item_type* item_pointer = new item_type;
        item_pointer = game.item_manager.add_item(new_UID);
        if (item_pointer)
        {
            // ----------------> Socket and Effect <---------------------------------------------
            if (quality_level <= 10)
            {
                item_pointer->data.number_of_item_sockets = 0;
                item_pointer->data.number_of_item_effects = 1;
            }
            if ((quality_level > 10)&&(quality_level <= 20))
            {
                item_pointer->data.number_of_item_sockets = 0;
                item_pointer->data.number_of_item_effects = random_int(1,2);
            }
            if ((quality_level > 20)&&(quality_level <= 30))
            {
                item_pointer->data.number_of_item_sockets = random_int(0,1);
                item_pointer->data.number_of_item_effects = random_int(1,2);
            }
            if ((quality_level > 30)&&(quality_level <= 40))
            {
                item_pointer->data.number_of_item_sockets = random_int(0,1);
                item_pointer->data.number_of_item_effects = random_int(2,3);
            }
            if ((quality_level > 40)&&(quality_level <= 50))
            {
                item_pointer->data.number_of_item_sockets = random_int(1,2);
                item_pointer->data.number_of_item_effects = random_int(2,3);
            }
            if ((quality_level > 50)&&(quality_level <= 60))
            {
                item_pointer->data.number_of_item_sockets = random_int(1,2);
                item_pointer->data.number_of_item_effects = random_int(3,4);
            }
            if ((quality_level > 60)&&(quality_level <= 70))
            {
                item_pointer->data.number_of_item_sockets = random_int(2,3);
                item_pointer->data.number_of_item_effects = random_int(3,4);
            }
            if ((quality_level > 70)&&(quality_level <= 80))
            {
                item_pointer->data.number_of_item_sockets = random_int(2,3);
                item_pointer->data.number_of_item_effects = random_int(4,5);
            }
            if (quality_level > 80)
            {
                item_pointer->data.number_of_item_sockets = random_int(3,4);
                item_pointer->data.number_of_item_effects = random_int(5,6);
            }
            if (item_pointer->data.number_of_item_sockets < 0) item_pointer->data.number_of_item_sockets = 0;
            if (item_pointer->data.number_of_item_effects < 1) item_pointer->data.number_of_item_effects = 1;
            if (item_pointer->data.number_of_item_sockets > MAX_ITEM_SOCKETS) item_pointer->data.number_of_item_sockets = MAX_ITEM_SOCKETS;
            if (item_pointer->data.number_of_item_effects > MAX_ITEM_EFFECTS) item_pointer->data.number_of_item_effects = MAX_ITEM_EFFECTS;
            for (int socket_count = 0; socket_count < MAX_ITEM_SOCKETS; socket_count++)
            {
                item_pointer->data.socket[socket_count].enabled = false;
            }
            if (item_pointer->data.number_of_item_effects > 0)
            {
                for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                {
                    item_pointer->data.effect[effect_count] = new effect_type;
                    item_pointer->data.effect[effect_count]->data.active = false;
                }
            }
            // ----------------------------------------------------------------------------------
            item_pointer->data.active = true;
            switch (item_type_UID)
            {
                case ITEM_POTION_S_HEALTH:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_SMALL;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 1;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 5;
                break;
                case ITEM_POTION_M_HEALTH:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_MEDIUM;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 1;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 15;
                break;
                case ITEM_POTION_L_HEALTH:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_LARGE;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 1;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 45;
                break;
                case ITEM_POTION_S_MANA:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_SMALL;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 1;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 5;
                break;
                case ITEM_POTION_M_MANA:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_MEDIUM;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 1;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 15;
                break;
                case ITEM_POTION_L_MANA:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_LARGE;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 1;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 45;
                break;
                case ITEM_POTION_S_REJUVENATION:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_SMALL;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 2;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 5;
                    item_pointer->data.effect[1]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
                    item_pointer->data.effect[1]->data.active = true;
                    item_pointer->data.effect[1]->data.value  = 5;
                break;
                case ITEM_POTION_M_REJUVENATION:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_MEDIUM;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 2;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 5;
                    item_pointer->data.effect[1]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
                    item_pointer->data.effect[1]->data.active = true;
                    item_pointer->data.effect[1]->data.value  = 15;
                break;
                case ITEM_POTION_L_REJUVENATION:
                    item_pointer->data.type                   = ITEM_POTION;
                    item_pointer->data.sub_type               = ITEM_POTION_LARGE;
                    item_pointer->data.stackable              = true;
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 100;
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 2;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
                    item_pointer->data.effect[0]->data.active = true;
                    item_pointer->data.effect[0]->data.value  = 5;
                    item_pointer->data.effect[1]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
                    item_pointer->data.effect[1]->data.active = true;
                    item_pointer->data.effect[1]->data.value  = 45;
                break;
                case ITEM_SPELL_BOOK:
                    item_pointer->data.consumable             = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                    if (item_pointer->data.number_of_item_effects > 1) item_pointer->data.number_of_item_effects = 1;
                break;
                case ITEM_BELT:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                break;
                case ITEM_BODY:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                break;
                case ITEM_FEET:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                break;
                case ITEM_HAND:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                break;
                case ITEM_HEAD:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    if (item_pointer->data.number_of_item_sockets > 1) item_pointer->data.number_of_item_sockets = 1;
                break;
                case ITEM_NECK:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                break;
                case ITEM_OFFHAND:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                break;
                case ITEM_RING:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                break;
                case ITEM_WEAPON:
                    item_pointer->data.equipable              = true;
                    item_pointer->data.quantity               = 1;
                    item_pointer->data.quantity_max           = 1;
                    item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE);
                    item_pointer->data.effect[0]->data.value  = random(quality_level);
                    if (item_pointer->data.number_of_item_effects > 1)
                    {
                        int  AVAILABLE_EFFECT_COUNT = 13;
                        int  add_effect             = 0;
                        bool found                  = false;
                        bool effect_used[AVAILABLE_EFFECT_COUNT];
                        for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                        {
                            effect_used[temp_count] = false;
                        }
                        for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                        {
                            found = false;
                            while (!found)
                            {
                                add_effect = random(AVAILABLE_EFFECT_COUNT);
                                if (!effect_used[add_effect])
                                {
                                    effect_used[add_effect] = true;
                                    found = true;
                                }
                            }
                            switch (add_effect)
                            {
                                case 0:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_MAX);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 1:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_MIN);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 2:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_ICE);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 3:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_FIRE);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 4:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_LIGHTNING);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 5:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_DAMAGE_ELEMENTAL);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 6:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_MANA_HIT);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 7:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_MANA_KILL);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 8:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH_HIT);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 9:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH_KILL);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 10:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_CRIT_CHANCE);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 11:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_CRIT_DAMAGE);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                case 12:
                                    item_pointer->data.effect[effect_count]              = game.effect_manager.add_effect(EFFECT_MOD_EXP_PER_KILL);
                                    item_pointer->data.effect[effect_count]->data.value  = random(quality_level);
                                break;
                                default:
                                    item_pointer->data.effect[effect_count]->data.active = false;
                                break;
                            }
                        }
                    }
                break;
                default:
                    game.core.log.file_write("Unable to generate item -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
                break;
            }
            item_pointer->data.type     = item_type_UID;
            item_pointer->data.sub_type = item_sub_type_UID;
            item_manager_class::gen_item_name   (item_pointer,item_type_UID, item_sub_type_UID, quality_level);
            item_manager_class::gen_item_texture(item_pointer,item_type_UID, item_sub_type_UID, quality_level);
            item_manager_class::gen_item_sounds (item_pointer,item_type_UID, item_sub_type_UID, quality_level);
        }
        else new_UID = RETURN_FAIL;
    }
    return (new_UID);
};

void  item_manager_class::gen_item_name(item_type* item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    switch (item_type_UID)
    {
        case ITEM_POTION:
            item_pointer->data.name = "Potion";
        break;
        case ITEM_POTION_S_HEALTH:
            item_pointer->data.name = "Small Health Potion";
        break;
        case ITEM_POTION_M_HEALTH:
            item_pointer->data.name = "Medium Health Potion";
        break;
        case ITEM_POTION_L_HEALTH:
            item_pointer->data.name = "Large Health Potion";
        break;
        case ITEM_POTION_S_MANA:
            item_pointer->data.name = "Small Mana Potion";
        break;
        case ITEM_POTION_M_MANA:
            item_pointer->data.name = "Medium Mana Potion";
        break;
        case ITEM_POTION_L_MANA:
            item_pointer->data.name = "Large Mana Potion";
        break;
        case ITEM_POTION_S_REJUVENATION:
            item_pointer->data.name = "Small Rejuvenation Potion";
        break;
        case ITEM_POTION_M_REJUVENATION:
            item_pointer->data.name = "Medium Rejuvenation Potion";
        break;
        case ITEM_POTION_L_REJUVENATION:
            item_pointer->data.name = "Large Rejuvenation Potion";
        break;
        case ITEM_FEET:
            item_pointer->data.name = "Randomly generated item";
        break;
        default:
            //game.core.log.file_write("Unable to generate item -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
            item_pointer->data.name = "Randomly generated item";
        break;
    }
};

void  item_manager_class::gen_item_texture(item_type* item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    switch (item_type_UID)
    {
        case ITEM_POTION:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_21.png");
        break;
        case ITEM_POTION_S_HEALTH:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_01.png");
        break;
        case ITEM_POTION_M_HEALTH:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_02.png");
        break;
        case ITEM_POTION_L_HEALTH:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_23.png");
        break;
        case ITEM_POTION_S_MANA:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_08.png");
        break;
        case ITEM_POTION_M_MANA:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_09.png");
        break;
        case ITEM_POTION_L_MANA:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_22.png");
        break;
        case ITEM_POTION_S_REJUVENATION:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
        break;
        case ITEM_POTION_M_REJUVENATION:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
        break;
        case ITEM_POTION_L_REJUVENATION:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
        break;
        case ITEM_SPELL_BOOK:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/books/book_19.png");
        break;
        case ITEM_BELT:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/belts/belt_00.png");
        break;
        case ITEM_BODY:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/armour/armour_00.png");
        break;
        case ITEM_FEET:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/boots/boots_06.png");
        break;
        case ITEM_HAND:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gloves/gloves_03.png");
        break;
        case ITEM_HEAD:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/helms/helm_00.png");
        break;
        case ITEM_NECK:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/amulets/amulet_00.png");
        break;
        case ITEM_OFFHAND:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/shields/shield_03.png");
        break;
        case ITEM_RING:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/rings/ring_00.png");
        break;
        case ITEM_WEAPON:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/swords/sword_21.png");
        break;
        default:
            game.core.log.file_write("Unable to generate item textures -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
        break;
    }
};

void  item_manager_class::gen_item_sounds(item_type* item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    switch (item_type_UID)
    {
        case ITEM_POTION:
        case ITEM_POTION_S_HEALTH:
        case ITEM_POTION_M_HEALTH:
        case ITEM_POTION_L_HEALTH:
        case ITEM_POTION_S_MANA:
        case ITEM_POTION_M_MANA:
        case ITEM_POTION_L_MANA:
        case ITEM_POTION_S_REJUVENATION:
        case ITEM_POTION_M_REJUVENATION:
        case ITEM_POTION_L_REJUVENATION:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_SPELL_BOOK:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/book_02.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/book_00.wav");
        break;
        case ITEM_BELT:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
        break;
        case ITEM_BODY:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
        break;
        case ITEM_FEET:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/cloth_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/cloth_00.wav");
        break;
        case ITEM_HAND:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/metal_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/metal_00.wav");
        break;
        case ITEM_HEAD:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
        break;
        case ITEM_NECK:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
        break;
        case ITEM_OFFHAND:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
        break;
        case ITEM_RING:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/ring_01.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/ring_01.wav");
        break;
        case ITEM_WEAPON:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/metal_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/metal_00.wav");
        break;
        default:
            game.core.log.file_write("Unable to generate item textures -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
        break;
    }
};



/*
#define EFFECT_NONE                 0
#define EFFECT_MOD_STRENGTH         1
#define EFFECT_MOD_INTELLECT        2
#define EFFECT_MOD_DEXTERITY        3
#define EFFECT_MOD_ALL_ATTRIBUTES   4
//---------------------------------------
#define EFFECT_MOD_ARMOUR           5
//---------------------------------------
#define EFFECT_MOD_DAMAGE           6
#define EFFECT_MOD_DAMAGE_MAX       7
#define EFFECT_MOD_DAMAGE_MIN       8
#define EFFECT_MOD_DAMAGE_ICE       9
#define EFFECT_MOD_DAMAGE_FIRE      10
#define EFFECT_MOD_DAMAGE_LIGHTNING 11
#define EFFECT_MOD_DAMAGE_ELEMENTAL 12
//---------------------------------------
#define EFFECT_MOD_RESIST_PHYSICAL  13
#define EFFECT_MOD_RESIST_ICE       14
#define EFFECT_MOD_RESIST_FIRE      15
#define EFFECT_MOD_RESIST_LIGHTNING 16
#define EFFECT_MOD_RESIST_ALL       17
//---------------------------------------
#define EFFECT_MOD_HEALTH           18
#define EFFECT_MOD_HEALTH_MAX       19
#define EFFECT_MOD_HEALTH_REGEN     20
#define EFFECT_MOD_HEALTH_HIT       21
#define EFFECT_MOD_HEALTH_KILL      22
//---------------------------------------
#define EFFECT_MOD_MANA             23
#define EFFECT_MOD_MANA_MAX         24
#define EFFECT_MOD_MANA_REGEN       25
#define EFFECT_MOD_MANA_HIT         26
#define EFFECT_MOD_MANA_KILL        27
//---------------------------------------
#define EFFECT_MOD_CRIT_CHANCE      28
#define EFFECT_MOD_CRIT_DAMAGE      29
#define EFFECT_MOD_MOVEMENT_SPEED   30
#define EFFECT_MOD_LIGHT_RADIUS     31
#define EFFECT_MOD_MAGIC_FIND       32
#define EFFECT_MOD_GOLD_FIND        33
#define EFFECT_MOD_EXP_PER_KILL     34
//---------------------------------------
#define EFFECT_MOD_SPELL            35
#define EFFECT_MOD_SPELL_TYPE       36
#define EFFECT_MOD_SPELL_ALL        37
#define EFFECT_MOD_SPELL_CAST_KILL  38
#define EFFECT_MOD_SPELL_CAST_HIT   39
#define EFFECT_MOD_SPELL_CAST_DMG   40
*/
