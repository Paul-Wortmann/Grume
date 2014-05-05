/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include <iostream>
#include <limits.h>
#include "item_manager.hpp"
#include "../game/game.hpp"
#include "../core/misc.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

item_manager_class::item_manager_class(void)
{
    item_manager_class::item            = NULL;
    item_manager_class::last            = NULL;
    item_manager_class::root            = NULL;
    item_manager_class::number_of_items = 0;
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
    item_manager_class::last->data.spell                  = false;
    item_manager_class::last->data.quest                  = false;
    item_manager_class::last->data.name                   = "";
    item_manager_class::last->data.number_of_item_effects = 0;
    item_manager_class::last->data.number_of_item_sockets = 0;
    item_manager_class::last->data.material_type          = ITEM_MATERIAL_NONE;
    item_manager_class::last->data.qaulity_type           = ITEM_QUALITY_NORMAL;
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
    for (int  temp_UID = 0; temp_UID < UID_max; temp_UID++)
    {
        bool found = true;
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
    std::ifstream  script_file(file_name.c_str(),std::ios::in);
    if (script_file.is_open())
    {
        item_type*     item_pointer = NULL;
        int            temp_char_UTF32  = ' ';
        std::string    temp_string_data;
        std::string    temp_string_key;
        std::string    temp_string_value;
        int            position_count;
        std::string    data_line;
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
                    position_count = 0;
                    while(temp_char_UTF32 != ' ')
                    {
                        temp_char_UTF32 = data_line[position_count];
                        if(temp_char_UTF32 != ' ') temp_string_key += temp_char_UTF32;
                        position_count++;
                        if(position_count > (int)data_line.length()) (temp_char_UTF32 = ' ');
                    }
                    while((temp_char_UTF32 == ' ') || (temp_char_UTF32 == '='))
                    {
                        temp_char_UTF32 = data_line[position_count];
                        position_count++;
                        if(position_count > (int)data_line.length()) (temp_char_UTF32 = '#');
                    }
                    position_count--;
                    while(position_count < ((int)data_line.length()-1))
                    {
                        temp_char_UTF32  = data_line[position_count];
                        if (temp_char_UTF32 != '"') temp_string_value += temp_char_UTF32;
                        position_count++;
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
                        if (temp_string_key == "IMAGE")            item_pointer->data.image.level_0          = game.texture_manager.add_texture(temp_string_data.c_str());
                        if (temp_string_key == "SOUND_MOVE")       item_pointer->data.sound.on_move          = game.sound_manager.add_sound(temp_string_data.c_str());
                        if (temp_string_key == "SOUND_USE")        item_pointer->data.sound.on_use           = game.sound_manager.add_sound(temp_string_data.c_str());
                        /*
                        if (temp_string_key == "EFFECT_0")         item_pointer->data.effect[0]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_1")         item_pointer->data.effect[1]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_2")         item_pointer->data.effect[2]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_3")         item_pointer->data.effect[3]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_4")         item_pointer->data.effect[4]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        if (temp_string_key == "EFFECT_5")         item_pointer->data.effect[5]              = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        */
                    }
                }
            }
        }
        script_file.close();
    }
};

void item_manager_class::use_item(UI_form_struct *UI_form_pointer, int element_number)
{
    if (UI_form_pointer->data.element[element_number].active)
    {
        item_type* item_pointer = game.item_manager.add_item(UI_form_pointer->data.element[element_number].value);
        if (item_pointer->data.consumable)
        {
            bool used_item = false;
            //game.core.log.file_write("---- use item function ------");
            for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
            {
                if (item_pointer->data.effect[effect_count].enabled)
                {
                    if (used_item) game.effect_manager.use_effect(item_pointer->data.effect[effect_count].type,item_pointer->data.effect[effect_count].value);
                    else used_item = game.effect_manager.use_effect(item_pointer->data.effect[effect_count].type,item_pointer->data.effect[effect_count].value);
                }
            }
            if (used_item)
            {
                UI_form_pointer->data.element[element_number].quantity--;
                if (UI_form_pointer->data.element[element_number].quantity <= 0)
                {
                    UI_form_pointer->data.element[element_number].value    = -1;
                    UI_form_pointer->data.element[element_number].quantity = 0;
                }
                game.sound_manager.play(item_pointer->data.sound.on_use);
            }
        }
    }
};

void item_manager_class::equip_item(item_type* item_pointer)
{
    if (item_pointer->data.equipable)
    {
        for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
        {
            game.effect_manager.use_effect(item_pointer->data.effect[effect_count].type,item_pointer->data.effect[effect_count].value);
        }
        if (item_pointer->data.number_of_item_sockets > 0)
        {
            for (int socket_count = 0; socket_count < item_pointer->data.number_of_item_sockets; socket_count++)
            {
                if (item_pointer->data.socket[socket_count].enabled)
                {
                    int effect_count = 0;
                    item_type* socket_item_pointer = game.item_manager.add_item(item_pointer->data.socket[socket_count].value);
                    game.effect_manager.use_effect(socket_item_pointer->data.effect[effect_count].type,socket_item_pointer->data.effect[effect_count].value);
                }
            }
        }
    }
};

void item_manager_class::unequip_item(item_type* item_pointer)
{
    if (item_pointer->data.equipable)
    {
        for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
        {
            game.effect_manager.use_effect(item_pointer->data.effect[effect_count].type,(item_pointer->data.effect[effect_count].value * -1));
        }
        if (item_pointer->data.number_of_item_sockets > 0)
        {
            for (int socket_count = 0; socket_count < item_pointer->data.number_of_item_sockets; socket_count++)
            {
                if (item_pointer->data.socket[socket_count].enabled)
                {
                    int effect_count = 0;
                    item_type* socket_item_pointer = game.item_manager.add_item(item_pointer->data.socket[socket_count].value);
                    game.effect_manager.use_effect(socket_item_pointer->data.effect[effect_count].type,(socket_item_pointer->data.effect[effect_count].value * -1));
                }
            }
        }
    }
};

int  item_manager_class::gen_item(int item_type_UID, int item_sub_type_UID, int quality_level)
{
    if (quality_level < 1) quality_level = 1;
    int  new_UID           = RETURN_FAIL;
    if (item_sub_type_UID == ITEM_POTION)
    {
        int rand_number = 1;
        if (quality_level <= (MAX_ITEM_QUALITY*0.8f)) rand_number = 3;
        if (quality_level <= (MAX_ITEM_QUALITY*0.5f)) rand_number = 2;
        if (quality_level <= (MAX_ITEM_QUALITY*0.2f)) rand_number = 1;
        switch (random(rand_number))
        {
            case 0:
                item_sub_type_UID = ITEM_POTION_SMALL;
            break;
            case 1:
                item_sub_type_UID = ITEM_POTION_MEDIUM;
            break;
            case 2:
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
    if ((item_type_UID == ITEM_POTION_S_HEALTH) ||
        (item_type_UID == ITEM_POTION_M_HEALTH) ||
        (item_type_UID == ITEM_POTION_L_HEALTH) ||
        (item_type_UID == ITEM_POTION_S_MANA) ||
        (item_type_UID == ITEM_POTION_M_MANA) ||
        (item_type_UID == ITEM_POTION_L_MANA) ||
        (item_type_UID == ITEM_POTION_S_REJUVENATION) ||
        (item_type_UID == ITEM_POTION_M_REJUVENATION) ||
        (item_type_UID == ITEM_POTION_L_REJUVENATION)) new_UID = item_type_UID;
    else
    {
        new_UID = game.item_manager.get_new_item_UID();
        if (new_UID >= 0)
        {
            item_type* item_pointer;
            item_pointer = game.item_manager.add_item(new_UID);
            if (item_pointer)
            {
                // ----------------> Socket and Effect <---------------------------------------------
                if (quality_level <= (MAX_ITEM_QUALITY*0.1f))
                {
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = 1;
                }
                if ((quality_level > (MAX_ITEM_QUALITY*0.1f))&&(quality_level <= (MAX_ITEM_QUALITY*0.2f)))
                {
                    item_pointer->data.number_of_item_sockets = 0;
                    item_pointer->data.number_of_item_effects = random_int(1,2);
                }
                if ((quality_level > (MAX_ITEM_QUALITY*0.2f))&&(quality_level <= (MAX_ITEM_QUALITY*0.3f)))
                {
                    item_pointer->data.number_of_item_sockets = random_int(0,1);
                    item_pointer->data.number_of_item_effects = random_int(1,2);
                }
                if ((quality_level > (MAX_ITEM_QUALITY*0.3f))&&(quality_level <= (MAX_ITEM_QUALITY*0.4f)))
                {
                    item_pointer->data.number_of_item_sockets = random_int(0,1);
                    item_pointer->data.number_of_item_effects = random_int(2,3);
                }
                if ((quality_level > (MAX_ITEM_QUALITY*0.4f))&&(quality_level <= (MAX_ITEM_QUALITY*0.5f)))
                {
                    item_pointer->data.number_of_item_sockets = random_int(1,2);
                    item_pointer->data.number_of_item_effects = random_int(2,3);
                }
                if ((quality_level > (MAX_ITEM_QUALITY*0.5f))&&(quality_level <= (MAX_ITEM_QUALITY*0.6f)))
                {
                    item_pointer->data.number_of_item_sockets = random_int(1,2);
                    item_pointer->data.number_of_item_effects = random_int(3,4);
                }
                if ((quality_level > (MAX_ITEM_QUALITY*0.6f))&&(quality_level <= (MAX_ITEM_QUALITY*0.7f)))
                {
                    item_pointer->data.number_of_item_sockets = random_int(2,3);
                    item_pointer->data.number_of_item_effects = random_int(3,4);
                }
                if ((quality_level > (MAX_ITEM_QUALITY*0.7f))&&(quality_level <= (MAX_ITEM_QUALITY*0.8f)))
                {
                    item_pointer->data.number_of_item_sockets = random_int(2,3);
                    item_pointer->data.number_of_item_effects = random_int(4,5);
                }
                if (quality_level > (MAX_ITEM_QUALITY*0.8f))
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
                        //item_pointer->data.effect[effect_count] = new effect_type;
                        item_pointer->data.effect[effect_count].enabled = false;
                    }
                }
                // ----------------------------------------------------------------------------------
                item_pointer->data.active = true;
                switch (item_type_UID)
                {
                    case ITEM_GEM:
                        if (item_sub_type_UID == ITEM_GEM)
                        {
                            switch (random(9))
                            {
                                case 0:
                                    item_sub_type_UID = ITEM_GEM_EMERALD;
                                break;
                                case 1:
                                    item_sub_type_UID = ITEM_GEM_OPAL;
                                break;
                                case 2:
                                    item_sub_type_UID = ITEM_GEM_RUBY;
                                break;
                                case 3:
                                    item_sub_type_UID = ITEM_GEM_SAPPHIRE;
                                break;
                                case 4:
                                    item_sub_type_UID = ITEM_GEM_TOPAZ;
                                break;
                                case 5:
                                    item_sub_type_UID = ITEM_GEM_JADE;
                                break;
                                case 6:
                                    item_sub_type_UID = ITEM_GEM_MORGANITE;
                                break;
                                case 7:
                                    item_sub_type_UID = ITEM_GEM_AMERTINE;
                                break;
                                case 8:
                                default:
                                    item_sub_type_UID = ITEM_GEM_AQUAMARINE;
                                break;
                            }
                        }
                        item_pointer->data.consumable             = false;
                        item_pointer->data.stackable              = false;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                        switch (item_sub_type_UID)
                        {
                            case ITEM_GEM_EMERALD:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_EPIC;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_DEXTERITY;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            case ITEM_GEM_OPAL:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_EPIC;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_STRENGTH;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            case ITEM_GEM_RUBY:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_EPIC;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH_MAX;
                                item_pointer->data.effect[0].value        = random(quality_level);
                            break;
                            case ITEM_GEM_SAPPHIRE:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_EPIC;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_MANA_MAX;
                                item_pointer->data.effect[0].value        = random(quality_level);
                            break;
                            case ITEM_GEM_TOPAZ:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_EPIC;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_INTELLECT;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            case ITEM_GEM_AMERTINE:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_SET;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_SPELL_DURATION;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            case ITEM_GEM_AQUAMARINE:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_SET;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_SPELL_COOLDOWN;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            case ITEM_GEM_JADE:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_SET;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_SPELL_DAMAGE;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            default:
                            case ITEM_GEM_MORGANITE:
                                item_pointer->data.qaulity_type           = ITEM_QUALITY_SET;
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_SPELL_MANA_COST;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                        }
                        if ((item_pointer->data.effect[0].enabled) && (item_pointer->data.effect[0].value <= 0)) item_pointer->data.effect[0].value = 1;
                    break;
                    case ITEM_SPELL_BOOK:
                        {
                            int spell_level = 4;
                            if (quality_level <= (MAX_ITEM_QUALITY*0.2f))                                              spell_level = 4;
                            if ((quality_level > (MAX_ITEM_QUALITY*0.2f))&&(quality_level <= (MAX_ITEM_QUALITY*0.4f))) spell_level = 8;
                            if ((quality_level > (MAX_ITEM_QUALITY*0.4f))&&(quality_level <= (MAX_ITEM_QUALITY*0.6f))) spell_level = 12;
                            if ((quality_level > (MAX_ITEM_QUALITY*0.6f))&&(quality_level <= (MAX_ITEM_QUALITY*0.8f))) spell_level = 16;
                            if (quality_level > (MAX_ITEM_QUALITY*0.8f))                                               spell_level = 20;
                            spell_level = 13; // remove for testing-------------!!!!----
                            if (item_sub_type_UID == ITEM_SPELL_BOOK)
                            {
                                switch (random(spell_level))
                                {
                                    case 0:
                                        item_sub_type_UID = ITEM_SPELL_ARROW_FIRE;
                                    break;
                                    case 1:
                                        item_sub_type_UID = ITEM_SPELL_ARROW_ICE;
                                    break;
                                    case 2:
                                        item_sub_type_UID = ITEM_SPELL_ARROW_LIGHTNING;
                                    break;
                                    case 3:
                                        item_sub_type_UID = ITEM_SPELL_ARROW_ELEMENTAL;
                                    break;
                                    case 4:
                                        item_sub_type_UID = ITEM_SPELL_BALL_FIRE;
                                    break;
                                    case 5:
                                        item_sub_type_UID = ITEM_SPELL_BALL_ICE;
                                    break;
                                    case 6:
                                        item_sub_type_UID = ITEM_SPELL_BALL_LIGHTNING;
                                    break;
                                    case 7:
                                        item_sub_type_UID = ITEM_SPELL_BALL_ELEMENTAL;
                                    break;


                                    case 8: // should be 13!!!
                                        item_sub_type_UID = ITEM_SPELL_SHIELD_FIRE;
                                    break;
                                    case 9:
                                        item_sub_type_UID = ITEM_SPELL_SHIELD_ICE;
                                    break;
                                    case 10:
                                        item_sub_type_UID = ITEM_SPELL_SHIELD_LIGHTNING;
                                    break;
                                    case 11:
                                        item_sub_type_UID = ITEM_SPELL_SHIELD_ELEMENTAL;
                                    break;
                                    case 12:
                                        item_sub_type_UID = ITEM_SPELL_HEAL;
                                    break;
                                    default:
                                        item_sub_type_UID = ITEM_SPELL_ARROW_ELEMENTAL;
                                    break;
                                }
                            }
                            item_pointer->data.consumable             = true;
                            item_pointer->data.quantity               = 1;
                            item_pointer->data.quantity_max           = 1;
                            if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                            if (item_pointer->data.number_of_item_effects > 1) item_pointer->data.number_of_item_effects = 1;
                            item_pointer->data.effect[0].enabled      = true;
                            item_pointer->data.effect[0].type         = EFFECT_MOD_SPELL;
                            item_pointer->data.effect[0].value        = item_sub_type_UID;
                        }
                    break;
                    case ITEM_BELT:
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_ARMOR;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 12;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_STRENGTH;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DEXTERITY;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_PHYSICAL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ICE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_FIRE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_LIGHTNING;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ALL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_REGEN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_REGEN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 9:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_MAX;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 10:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MAGIC_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 11:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_GOLD_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
                                    break;
                                }
                            }
                        }
                    break;
                    case ITEM_BODY:
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_ARMOR;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 11;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_STRENGTH;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DEXTERITY;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_PHYSICAL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ICE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_FIRE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_LIGHTNING;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ALL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_REGEN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_REGEN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 9:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_EXP_PER_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 10:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_CAST_DMG;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
                                    break;
                                }
                            }
                        }
                    break;
                    case ITEM_FEET:
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_ARMOR;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 11;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DEXTERITY;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_PHYSICAL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ICE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_FIRE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_LIGHTNING;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ALL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_REGEN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_MAX;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MOVEMENT_SPEED;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 9:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MAGIC_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 10:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_GOLD_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
                                    break;
                                }
                            }
                        }
                    break;
                    case ITEM_HAND:
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_ARMOR;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 12;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DEXTERITY;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_PHYSICAL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ICE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_FIRE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_LIGHTNING;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ALL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_HIT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_HIT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 9:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 10:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_CAST_HIT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 11:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_CAST_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
                                    break;
                                }
                            }
                        }
                    break;
                    case ITEM_HEAD:
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 1) item_pointer->data.number_of_item_sockets = 1;
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_ARMOR;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 9;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_INTELLECT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_ALL_ATTRIBUTES;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_PHYSICAL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ICE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_FIRE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_LIGHTNING;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ALL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_LIGHT_RADIUS;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_EXP_PER_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
                                    break;
                                }
                            }
                        }
                    break;
                    case ITEM_OFFHAND:
                        if (item_sub_type_UID == ITEM_OFFHAND)
                        {
                            switch (random(2))
                            {
                                case 0:
                                    item_sub_type_UID = ITEM_SOURCE;
                                break;
                                case 1:
                                default:
                                    item_sub_type_UID = ITEM_SHIELD;
                                break;
                            }
                        }
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_ARMOR;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            switch (item_sub_type_UID)
                            {
                                case ITEM_SOURCE:
                                    {
                                        item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                                        int  AVAILABLE_EFFECT_COUNT = 14;
                                        int  add_effect             = 0;
                                        bool effect_used_source[AVAILABLE_EFFECT_COUNT];
                                        for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                                        {
                                            effect_used_source[temp_count] = false;
                                        }
                                        for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                                        {
                                            bool found = false;
                                            while (!found)
                                            {
                                                add_effect = random(AVAILABLE_EFFECT_COUNT);
                                                if (!effect_used_source[add_effect])
                                                {
                                                    effect_used_source[add_effect] = true;
                                                    found = true;
                                                }
                                            }
                                            switch (add_effect)
                                            {
                                                case 0:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_INTELLECT;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 1:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_ALL_ATTRIBUTES;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 2:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_PHYSICAL;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 3:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_FIRE;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 4:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ICE;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 5:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_LIGHTNING;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 6:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ALL;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 7:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_REGEN;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 8:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_REGEN;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 9:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_CAST_DMG;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 10:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_LIGHT_RADIUS;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 11:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 12:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_TYPE;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 13:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_ALL;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                default:
                                                    item_pointer->data.effect[effect_count].enabled       = false;
                                                break;
                                            }
                                        }
                                    }
                                break;
                                case ITEM_SHIELD:
                                default:
                                    {
                                        item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                                        int  AVAILABLE_EFFECT_COUNT = 14;
                                        int  add_effect             = 0;
                                        bool effect_used_shield[AVAILABLE_EFFECT_COUNT];
                                        for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                                        {
                                            effect_used_shield[temp_count] = false;
                                        }
                                        for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                                        {
                                            bool found = false;
                                            while (!found)
                                            {
                                                add_effect = random(AVAILABLE_EFFECT_COUNT);
                                                if (!effect_used_shield[add_effect])
                                                {
                                                    effect_used_shield[add_effect] = true;
                                                    found = true;
                                                }
                                            }
                                            switch (add_effect)
                                            {
                                                case 0:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_STRENGTH;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 1:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DEXTERITY;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 2:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_PHYSICAL;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 3:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_FIRE;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 4:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ICE;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 5:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_LIGHTNING;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 6:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_RESIST_ALL;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 7:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_MAX;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 8:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_MAX;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                case 9:
                                                    item_pointer->data.effect[effect_count].enabled      = true;
                                                    item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_CAST_DMG;
                                                    item_pointer->data.effect[effect_count].value        = random(quality_level);
                                                break;
                                                default:
                                                    item_pointer->data.effect[effect_count].enabled       = false;
                                                break;
                                            }
                                        }
                                    }
                                break;
                            }
                        }
                    break;
                    case ITEM_NECK:
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                        if (item_pointer->data.number_of_item_effects >= 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 12;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_STRENGTH;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_INTELLECT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DEXTERITY;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_ALL_ATTRIBUTES;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_REGEN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_REGEN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_LIGHT_RADIUS;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MAGIC_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_GOLD_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 9:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 10:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_TYPE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 11:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_ALL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
                                    break;
                                }
                            }
                        }
                    break;
                    case ITEM_RING:
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                        if (item_pointer->data.number_of_item_effects >= 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 12;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_STRENGTH;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_INTELLECT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DEXTERITY;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_ALL_ATTRIBUTES;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_MAX;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_MAX;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_LIGHT_RADIUS;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MAGIC_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_GOLD_FIND;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 9:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 10:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_TYPE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 11:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_SPELL_ALL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
                                    break;
                                }
                            }
                        }
                    break;
                    case ITEM_WEAPON:
                        if (item_sub_type_UID == ITEM_WEAPON)
                        {
                            switch (random(8))
                            {
                                case 0:
                                    item_sub_type_UID = ITEM_SWORD;
                                break;
                                case 1:
                                    item_sub_type_UID = ITEM_MACE;
                                break;
                                case 2:
                                    item_sub_type_UID = ITEM_HAMMER;
                                break;
                                case 3:
                                    item_sub_type_UID = ITEM_BOW;
                                break;
                                case 4:
                                    item_sub_type_UID = ITEM_AXE;
                                break;
                                case 5:
                                    item_sub_type_UID = ITEM_DAGGER;
                                break;
                                case 6:
                                    item_sub_type_UID = ITEM_SICKLE;
                                break;
                                case 7:
                                default:
                                    item_sub_type_UID = ITEM_WAND;
                                break;
                            }
                        }
                        item_pointer->data.equipable              = true;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_DAMAGE;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 13;
                            int  add_effect             = 0;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                            {
                                bool found = false;
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
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DAMAGE_MAX;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 1:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DAMAGE_MIN;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 2:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DAMAGE_ICE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 3:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DAMAGE_FIRE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 4:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DAMAGE_LIGHTNING;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 5:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_DAMAGE_ELEMENTAL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 6:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_HIT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 7:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_MANA_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 8:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_HIT;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 9:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_HEALTH_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 10:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_CRIT_CHANCE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 11:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_CRIT_DAMAGE;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    case 12:
                                        item_pointer->data.effect[effect_count].enabled      = true;
                                        item_pointer->data.effect[effect_count].type         = EFFECT_MOD_EXP_PER_KILL;
                                        item_pointer->data.effect[effect_count].value        = random(quality_level);
                                    break;
                                    default:
                                        item_pointer->data.effect[effect_count].enabled       = false;
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
    }
    return (new_UID);
};

int   item_manager_class::get_item_best_effect(item_type* item_pointer)
{
    int return_value = EFFECT_NONE;
    int temp_value   = 0;
    for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
    {
        if (item_pointer->data.effect[effect_count].enabled)
        {
            if (item_pointer->data.effect[effect_count].value > temp_value)
            {
                temp_value   = item_pointer->data.effect[effect_count].value;
                return_value = item_pointer->data.effect[effect_count].type;
            }
        }
    }
    return (return_value);
}

std::string item_manager_class::get_item_effect_string(int effect_name)
{
    std::string return_value = "of error";
    switch (effect_name)
    {
        case EFFECT_MOD_STRENGTH:
            return_value = "of power";
        break;
        case EFFECT_MOD_INTELLECT:
            return_value = "of the mind";
        break;
        case EFFECT_MOD_DEXTERITY:
            return_value = "of nimbus";
        break;
        case EFFECT_MOD_ALL_ATTRIBUTES:
            return_value = "of skill";
        break;
        case EFFECT_MOD_ARMOR:
            return_value = "of armor";
        break;
        case EFFECT_MOD_DAMAGE:
            return_value = "of damage";
        break;
        case EFFECT_MOD_DAMAGE_MAX:
            return_value = "of might";
        break;
        case EFFECT_MOD_DAMAGE_MIN:
            return_value = "of skill";
        break;
        case EFFECT_MOD_DAMAGE_ELEMENTAL:
            return_value = "of wizardry";
        break;
        case EFFECT_MOD_RESIST_PHYSICAL:
            return_value = "of the brute";
        break;
        case EFFECT_MOD_DAMAGE_ICE:
        case EFFECT_MOD_RESIST_ICE:
            switch (random(2))
            {
                case 0:
                    return_value = "of frost";
                break;
                case 1:
                default:
                    return_value = "of cold";
                break;
            }
        break;
        case EFFECT_MOD_DAMAGE_FIRE:
        case EFFECT_MOD_RESIST_FIRE:
            switch (random(6))
            {
                case 0:
                    return_value = "of flame";
                break;
                case 1:
                    return_value = "of burning";
                break;
                case 2:
                    return_value = "of hellfire";
                break;
                case 3:
                    return_value = "of brimstone";
                break;
                case 4:
                    return_value = "of charing";
                break;
                case 5:
                default:
                    return_value = "of the flame";
                break;
            }
        break;
        case EFFECT_MOD_DAMAGE_LIGHTNING:
        case EFFECT_MOD_RESIST_LIGHTNING:
            switch (random(3))
            {
                case 0:
                    return_value = "of thunder";
                break;
                case 1:
                    return_value = "of lightning";
                break;
                case 2:
                default:
                    return_value = "of sparking";
                break;
            }
        break;
        case EFFECT_MOD_RESIST_ALL:
            return_value = "of resistance";
        break;
        case EFFECT_MOD_HEALTH:
            return_value = "of health";
        break;
        case EFFECT_MOD_HEALTH_MAX:
            return_value = "of constitution";
        break;
        case EFFECT_MOD_HEALTH_REGEN:
            return_value = "of life";
        break;
        case EFFECT_MOD_HEALTH_HIT:
            return_value = "of life leach";
        break;
        case EFFECT_MOD_HEALTH_KILL:
            return_value = "of life steal";
        break;
        case EFFECT_MOD_MANA:
            return_value = "of mana";
        break;
        case EFFECT_MOD_MANA_MAX:
            return_value = "of wizardry";
        break;
        case EFFECT_MOD_MANA_REGEN:
            return_value = "of hexing";
        break;
        case EFFECT_MOD_MANA_HIT:
            return_value = "of mana drain";
        break;
        case EFFECT_MOD_MANA_KILL:
            return_value = "of mana steal";
        break;
        case EFFECT_MOD_CRIT_CHANCE:
        break;
        case EFFECT_MOD_CRIT_DAMAGE:
        break;
        case EFFECT_MOD_MOVEMENT_SPEED:
            switch (random(2))
            {
                case 0:
                    return_value = "of speed";
                break;
                case 1:
                default:
                    return_value = "of haste";
                break;
            }
        break;
        case EFFECT_MOD_LIGHT_RADIUS:
            return_value = "of brilliance";
        break;
        case EFFECT_MOD_MAGIC_FIND:
            return_value = "of luck";
        break;
        case EFFECT_MOD_GOLD_FIND:
            return_value = "of the leprechaun";
        break;
        case EFFECT_MOD_EXP_PER_KILL:
            return_value = "of wisdom";
        break;
        case EFFECT_MOD_SPELL:
            return_value = "of Beltane";
        break;
        case EFFECT_MOD_SPELL_TYPE:
            return_value = "of Samhain";
        break;
        case EFFECT_MOD_SPELL_ALL:
            return_value = "of the Coven";
        break;
        case EFFECT_MOD_SPELL_CAST_KILL:
            return_value = "of spawning";
        break;
        case EFFECT_MOD_SPELL_CAST_HIT:
            return_value = "of magic";
        break;
        case EFFECT_MOD_SPELL_CAST_DMG:
            return_value = "of reflection";
        break;
        case EFFECT_MOD_SPELL_MANA_COST:
        break;
        case EFFECT_MOD_SPELL_DAMAGE:
        break;
        case EFFECT_MOD_SPELL_COOLDOWN:
        break;
        case EFFECT_MOD_SPELL_DURATION:
        break;
        case EFFECT_NONE:
        default:
            return_value = "of nothing";
        break;
    }
    return (return_value);
}

void  item_manager_class::gen_item_name(item_type* item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    int         best_effect = item_manager_class::get_item_best_effect(item_pointer);
    std::string pre_name    = "Randomly ";
    std::string base_name   = "generated ";
    std::string post_name   = "item";
    if  (quality_level <= (MAX_ITEM_QUALITY*0.1f))                                              pre_name = "Standard ";
    if ((quality_level >= (MAX_ITEM_QUALITY*0.1f))&&(quality_level <= (MAX_ITEM_QUALITY*0.2f))) pre_name = "Adventurer's ";
    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level <= (MAX_ITEM_QUALITY*0.3f))) pre_name = "Superb ";
    if ((quality_level >= (MAX_ITEM_QUALITY*0.3f))&&(quality_level <= (MAX_ITEM_QUALITY*0.4f))) pre_name = "Excellent ";
    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level <= (MAX_ITEM_QUALITY*0.5f))) pre_name = "Superior ";
    if ((quality_level >= (MAX_ITEM_QUALITY*0.5f))&&(quality_level <= (MAX_ITEM_QUALITY*0.6f))) pre_name = "Exceptional ";
    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level <= (MAX_ITEM_QUALITY*0.7f))) pre_name = "Wondrous ";
    if ((quality_level >= (MAX_ITEM_QUALITY*0.7f))&&(quality_level <= (MAX_ITEM_QUALITY*0.8f))) pre_name = "Heroic ";
    if  (quality_level >= (MAX_ITEM_QUALITY*0.8f))                                              pre_name = "Legendary ";
    switch (item_type_UID)
    {
        case ITEM_GEM:
            switch (item_sub_type_UID)
            {
                case ITEM_GEM_EMERALD:
                    item_pointer->data.name = "Emerald";
                break;
                case ITEM_GEM_OPAL:
                    item_pointer->data.name = "Opal";
                break;
                case ITEM_GEM_RUBY:
                    item_pointer->data.name = "Ruby";
                break;
                case ITEM_GEM_SAPPHIRE:
                    item_pointer->data.name = "Sapphire";
                break;
                case ITEM_GEM_TOPAZ:
                    item_pointer->data.name = "Topaz";
                break;
                case ITEM_GEM_AMERTINE:
                    item_pointer->data.name = "Amertine";
                break;
                case ITEM_GEM_AQUAMARINE:
                    item_pointer->data.name = "Aquamarine";
                break;
                case ITEM_GEM_JADE:
                    item_pointer->data.name = "Jade";
                break;
                case ITEM_GEM_MORGANITE:
                    item_pointer->data.name = "Morganite";
                break;
                default:
                    item_pointer->data.name = "Gem";
                break;
            }
        break;
        case ITEM_SPELL_BOOK:
            pre_name  = "Wizard's ";
            base_name = "tome ";
            switch (item_sub_type_UID)
            {
                case ITEM_SPELL_ARROW_FIRE:
                    post_name = "of fire arrow";
                break;
                case ITEM_SPELL_ARROW_ICE:
                    post_name = "of ice arrow";
                break;
                case ITEM_SPELL_ARROW_LIGHTNING:
                    post_name = "of lightning arrow";
                break;
                case ITEM_SPELL_ARROW_ELEMENTAL:
                    post_name = "of elemental arrow";
                break;
                case ITEM_SPELL_BALL_FIRE:
                    post_name = "of fire ball";
                break;
                case ITEM_SPELL_BALL_ICE:
                    post_name = "of ice ball";
                break;
                case ITEM_SPELL_BALL_LIGHTNING:
                    post_name = "of lightning ball";
                break;
                case ITEM_SPELL_BALL_ELEMENTAL:
                    post_name = "of elemental ball";
                break;

                case ITEM_SPELL_SHIELD_FIRE:
                    post_name = "of fire shield";
                break;
                case ITEM_SPELL_SHIELD_ICE:
                    post_name = "of ice shield";
                break;
                case ITEM_SPELL_SHIELD_LIGHTNING:
                    post_name = "of lightning shield";
                break;
                case ITEM_SPELL_SHIELD_ELEMENTAL:
                    post_name = "of elemental shield";
                break;
                case ITEM_SPELL_HEAL:
                    post_name = "of healing";
                break;
                default:
                    post_name = "of spell craft";
                break;
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
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
            base_name = "boots ";
            if ((best_effect != EFFECT_NONE) && (best_effect != EFFECT_MOD_ARMOR))
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(6))
                {
                    case 0:
                        post_name = "of walking";
                    break;
                    case 1:
                        post_name = "of stomping";
                    break;
                    case 2:
                        post_name = "of running";
                    break;
                    case 3:
                        post_name = "of striding";
                    break;
                    case 4:
                        post_name = "of treading";
                    break;
                    case 5:
                    default:
                        post_name = "of kicking";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_BELT:
            base_name = "belt ";
            if ((best_effect != EFFECT_NONE) && (best_effect != EFFECT_MOD_ARMOR))
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(6))
                {
                    case 0:
                        post_name = "of security";
                    break;
                    case 1:
                        post_name = "of perseverance";
                    break;
                    case 2:
                        post_name = "of deliverance";
                    break;
                    case 3:
                        post_name = "of justice";
                    break;
                    case 4:
                        post_name = "of pride";
                    break;
                    case 5:
                    default:
                        post_name = "of holding";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_HEAD:
            base_name = "helm ";
            if ((best_effect != EFFECT_NONE) && (best_effect != EFFECT_MOD_ARMOR))
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(4))
                {
                    case 0:
                        post_name = "of protection";
                    break;
                    case 1:
                        post_name = "of wrath";
                    break;
                    case 2:
                        post_name = "of doom";
                    break;
                    case 3:
                    default:
                        post_name = "of glory";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_BODY:
            base_name = "armor ";
            if ((best_effect != EFFECT_NONE) && (best_effect != EFFECT_MOD_ARMOR))
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(6))
                {
                    case 0:
                        post_name = "of gloom";
                    break;
                    case 1:
                        post_name = "of cover";
                    break;
                    case 2:
                        post_name = "of stealth";
                    break;
                    case 3:
                        post_name = "of honor";
                    break;
                    case 4:
                        post_name = "of courage";
                    break;
                    case 5:
                    default:
                        post_name = "of bravery";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_HAND:
            base_name = "gloves ";
            if ((best_effect != EFFECT_NONE) && (best_effect != EFFECT_MOD_ARMOR))
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(6))
                {
                    case 0:
                        post_name = "of might";
                    break;
                    case 1:
                        post_name = "of iron fist";
                    break;
                    case 2:
                        post_name = "of straggle";
                    break;
                    case 3:
                        post_name = "of grip";
                    break;
                    case 4:
                        post_name = "of punching";
                    break;
                    case 5:
                    default:
                        post_name = "of pounding";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_RING:
            base_name = "ring ";
            if (best_effect != EFFECT_NONE)
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(2))
                {
                    case 0:
                        post_name = "of myth";
                    break;
                    case 1:
                    default:
                        post_name = "of infinity";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_NECK:
            base_name = "amulet ";
            if (best_effect != EFFECT_NONE)
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(6))
                {
                    case 0:
                        post_name = "of glow";
                    break;
                    case 1:
                        post_name = "of luck";
                    break;
                    case 2:
                        post_name = "of dreams";
                    break;
                    case 3:
                        post_name = "of determination";
                    break;
                    case 4:
                        post_name = "of superstition";
                    break;
                    case 5:
                    default:
                        post_name = "of witches";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_OFFHAND:
            switch (item_sub_type_UID)
            {
                case ITEM_SOURCE:
                    base_name = "source ";
                break;
                case ITEM_SHIELD:
                default:
                    base_name = "shield ";
                break;
            }
            if (best_effect != EFFECT_NONE)
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (random(6))
                {
                    case 0:
                        post_name = "of blocking";
                    break;
                    case 1:
                        post_name = "of warding";
                    break;
                    case 2:
                        post_name = "of stopping";
                    break;
                    case 3:
                        post_name = "of safety";
                    break;
                    case 4:
                        post_name = "of misery";
                    break;
                    case 5:
                    default:
                        post_name = "of woe";
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_WEAPON:
            switch (item_sub_type_UID)
            {
                case ITEM_DAGGER:
                    base_name = "dagger ";
                break;
                case ITEM_BOW:
                    base_name = "bow ";
                break;
                case ITEM_MACE:
                    base_name = "mace ";
                break;
                case ITEM_SWORD:
                    base_name = "sword ";
                break;
                case ITEM_HAMMER:
                    base_name = "hammer ";
                break;
                case ITEM_AXE:
                    base_name = "axe ";
                break;
                case ITEM_SICKLE:
                    base_name = "sickle ";
                break;
                case ITEM_WAND:
                default:
                    base_name = "wand ";
                break;
            }
            if ((best_effect != EFFECT_NONE) && (best_effect != EFFECT_MOD_DAMAGE))
            {
                post_name = item_manager_class::get_item_effect_string(best_effect);
            }
            else
            {
                switch (item_sub_type_UID)
                {
                    case ITEM_DAGGER:
                        switch (random(6))
                        {
                            case 0:
                                post_name = "of puncturing";
                            break;
                            case 1:
                                post_name = "of poking";
                            break;
                            case 2:
                                post_name = "of penetration";
                            break;
                            case 3:
                                post_name = "of severing";
                            break;
                            case 4:
                                post_name = "of pricking";
                            break;
                            case 5:
                            default:
                                post_name = "of probing";
                            break;
                        }
                    break;
                    case ITEM_BOW:
                        switch (random(6))
                        {
                            case 0:
                                post_name = "of puncturing";
                            break;
                            case 1:
                                post_name = "of piercing";
                            break;
                            case 2:
                                post_name = "of penetration";
                            break;
                            case 3:
                                post_name = "of sniping";
                            break;
                            case 4:
                                post_name = "of pricking";
                            break;
                            case 5:
                            default:
                                post_name = "of probing";
                            break;
                        }
                    break;
                    case ITEM_MACE:
                        switch (random(6))
                        {
                            case 0:
                                post_name = "of bashing";
                            break;
                            case 1:
                                post_name = "of maiming";
                            break;
                            case 2:
                                post_name = "of force";
                            break;
                            case 3:
                                post_name = "of concussion";
                            break;
                            case 4:
                                post_name = "of killing";
                            break;
                            case 5:
                            default:
                                post_name = "of awe";
                            break;
                        }
                    break;
                    case ITEM_SWORD:
                        switch (random(6))
                        {
                            case 0:
                                post_name = "of slashing";
                            break;
                            case 1:
                                post_name = "of chopping";
                            break;
                            case 2:
                                post_name = "of decapitation";
                            break;
                            case 3:
                                post_name = "of slicing";
                            break;
                            case 4:
                                post_name = "of slaying";
                            break;
                            case 5:
                            default:
                                post_name = "of legends";
                            break;
                        }
                    break;
                    case ITEM_HAMMER:
                        switch (random(6))
                        {
                            case 0:
                                post_name = "of bashing";
                            break;
                            case 1:
                                post_name = "of maiming";
                            break;
                            case 2:
                                post_name = "of force";
                            break;
                            case 3:
                                post_name = "of concussion";
                            break;
                            case 4:
                                post_name = "of smashing";
                            break;
                            case 5:
                            default:
                                post_name = "of pounding";
                            break;
                        }
                    break;
                    case ITEM_AXE:
                        switch (random(6))
                        {
                            case 0:
                                post_name = "of chopping";
                            break;
                            case 1:
                                post_name = "of slashing";
                            break;
                            case 2:
                                post_name = "of dicing";
                            break;
                            case 3:
                                post_name = "of hacking";
                            break;
                            case 4:
                                post_name = "of mauling";
                            break;
                            case 5:
                            default:
                                post_name = "of slicing";
                            break;
                        }
                    break;
                    case ITEM_SICKLE:
                        switch (random(6))
                        {
                            case 0:
                                post_name = "of chopping";
                            break;
                            case 1:
                                post_name = "of slashing";
                            break;
                            case 2:
                                post_name = "of dicing";
                            break;
                            case 3:
                                post_name = "of hacking";
                            break;
                            case 4:
                                post_name = "of piercing";
                            break;
                            case 5:
                            default:
                                post_name = "of slicing";
                            break;
                        }
                    break;
                    case ITEM_WAND:
                    default:
                        switch (random(7))
                        {
                            case 0:
                                post_name = "of wizardry";
                            break;
                            case 1:
                                post_name = "of magic";
                            break;
                            case 2:
                                post_name = "of witchcraft";
                            break;
                            case 3:
                                post_name = "of sorcery";
                            break;
                            case 4:
                                post_name = "of alchemy";
                            break;
                            case 5:
                                post_name = "of mystery";
                            break;
                            case 6:
                            default:
                                post_name = "of mysticism";
                            break;
                        }
                    break;
                }
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        default:
            //game.core.log.file_write("Unable to generate item -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
    }
};

void  item_manager_class::gen_item_texture(item_type* item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    std::string temp_string = "";
    int         temp_int    =  0;
    switch (item_type_UID)
    {
        case ITEM_GEM:
            item_pointer->data.material_type = ITEM_MATERIAL_GEM;
            switch (item_sub_type_UID)
            {
                case ITEM_GEM_EMERALD:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_4.png");
                break;
                case ITEM_GEM_OPAL:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_4.png");
                break;
                case ITEM_GEM_RUBY:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_4.png");
                break;
                case ITEM_GEM_SAPPHIRE:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_4.png");
                break;
                case ITEM_GEM_TOPAZ:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_4.png");
                break;
                case ITEM_GEM_AMERTINE:
                    if (quality_level < (MAX_ITEM_QUALITY*0.33f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_0_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.33f))&&(quality_level < (MAX_ITEM_QUALITY*0.66f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_0_1.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.66f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_0_2.png");
                break;
                case ITEM_GEM_AQUAMARINE:
                    if (quality_level < (MAX_ITEM_QUALITY*0.33f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_1_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.33f))&&(quality_level < (MAX_ITEM_QUALITY*0.66f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_1_1.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.66f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_1_2.png");
                break;
                case ITEM_GEM_JADE:
                    if (quality_level < (MAX_ITEM_QUALITY*0.33f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_2_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.33f))&&(quality_level < (MAX_ITEM_QUALITY*0.66f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_2_1.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.66f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_2_2.png");
                break;
                case ITEM_GEM_MORGANITE:
                default:
                    if (quality_level < (MAX_ITEM_QUALITY*0.33f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_3_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.33f))&&(quality_level < (MAX_ITEM_QUALITY*0.66f)))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_3_1.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.66f))
                        item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_3_2.png");
                break;
            }
        break;
        case ITEM_POTION:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_21.png");
        break;
        case ITEM_POTION_S_HEALTH:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_01.png");
        break;
        case ITEM_POTION_M_HEALTH:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_02.png");
        break;
        case ITEM_POTION_L_HEALTH:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_23.png");
        break;
        case ITEM_POTION_S_MANA:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_08.png");
        break;
        case ITEM_POTION_M_MANA:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_09.png");
        break;
        case ITEM_POTION_L_MANA:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_22.png");
        break;
        case ITEM_POTION_S_REJUVENATION:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
        break;
        case ITEM_POTION_M_REJUVENATION:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
        break;
        case ITEM_POTION_L_REJUVENATION:
            item_pointer->data.material_type = ITEM_MATERIAL_POTION;
            item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
        break;
        case ITEM_SPELL_BOOK:
            item_pointer->data.material_type = ITEM_MATERIAL_BOOK;
            switch (item_sub_type_UID)
            {
                case ITEM_SPELL_ARROW_FIRE:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_00.png");
                break;
                case ITEM_SPELL_ARROW_ICE:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_04.png");
                break;
                case ITEM_SPELL_ARROW_LIGHTNING:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_07.png");
                break;
                case ITEM_SPELL_ARROW_ELEMENTAL:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_01.png");
                break;
                case ITEM_SPELL_BALL_FIRE:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_00.png");
                break;
                case ITEM_SPELL_BALL_ICE:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_04.png");
                break;
                case ITEM_SPELL_BALL_LIGHTNING:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_07.png");
                break;
                case ITEM_SPELL_BALL_ELEMENTAL:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_01.png");
                break;

                case ITEM_SPELL_SHIELD_FIRE:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_00.png");
                break;
                case ITEM_SPELL_SHIELD_ICE:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_04.png");
                break;
                case ITEM_SPELL_SHIELD_LIGHTNING:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_07.png");
                break;
                case ITEM_SPELL_SHIELD_ELEMENTAL:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_01.png");
                break;
                case ITEM_SPELL_HEAL:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_06.png");
                break;
                default:
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture("data/textures/UI/icons/books/book_02i.png");
                break;
            }
        break;
        case ITEM_BELT:
            item_pointer->data.material_type = ITEM_MATERIAL_LEATHER;
            temp_int = random(6);
            temp_string = "data/textures/UI/icons/belts/belt_";
            if (temp_int < 10) temp_string += "0";
            temp_string += int_to_string(temp_int) + ".png";
            item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
        break;
        case ITEM_BODY:
            item_pointer->data.material_type = ITEM_MATERIAL_METAL;
            temp_int = random(2);
            temp_string = "data/textures/UI/icons/armor/armor_";
            if (temp_int < 10) temp_string += "0";
            temp_string += int_to_string(temp_int) + ".png";
            item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
        break;
        case ITEM_FEET:
            item_pointer->data.material_type = ITEM_MATERIAL_LEATHER;
            temp_int = random(7);
            temp_string = "data/textures/UI/icons/boots/boots_";
            if (temp_int < 10) temp_string += "0";
            temp_string += int_to_string(temp_int) + ".png";
            item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
        break;
        case ITEM_HAND:
            item_pointer->data.material_type = ITEM_MATERIAL_METAL;
            temp_int = random(4);
            temp_string = "data/textures/UI/icons/gloves/gloves_";
            if (temp_int < 10) temp_string += "0";
            temp_string += int_to_string(temp_int) + ".png";
            item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
        break;
        case ITEM_HEAD:
            item_pointer->data.material_type = ITEM_MATERIAL_METAL;
            temp_int = random(4);
            temp_string = "data/textures/UI/icons/helms/helm_";
            if (temp_int < 10) temp_string += "0";
            temp_string += int_to_string(temp_int) + ".png";
            item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
        break;
        case ITEM_NECK:
            item_pointer->data.material_type = ITEM_MATERIAL_AMULET;
            temp_int = random(14);
            temp_string = "data/textures/UI/icons/amulets/amulet_";
            if (temp_int < 10) temp_string += "0";
            temp_string += int_to_string(temp_int) + ".png";
            item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
        break;
        case ITEM_OFFHAND:
            switch (item_sub_type_UID)
            {
                case ITEM_SHIELD:
                    item_pointer->data.material_type = ITEM_MATERIAL_WOOD;
                    temp_int = random(15);
                    temp_string = "data/textures/UI/icons/shields/shield_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_SOURCE:
                default:
                    item_pointer->data.material_type = ITEM_MATERIAL_GEM;
                    temp_int = random(4);
                    temp_string = "data/textures/UI/icons/sources/source_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
            }
        break;
        case ITEM_RING:
            item_pointer->data.material_type = ITEM_MATERIAL_RING;
            temp_int = random(13);
            temp_string = "data/textures/UI/icons/rings/ring_";
            if (temp_int < 10) temp_string += "0";
            temp_string += int_to_string(temp_int) + ".png";
            item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
        break;
        case ITEM_WEAPON:
            //item_sub_type_UID = ITEM_SWORD;
            switch (item_sub_type_UID)
            {
                case ITEM_AXE:
                    item_pointer->data.material_type = ITEM_MATERIAL_METAL;
                    temp_int = random(6);
                    temp_string = "data/textures/UI/icons/axes/axe_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_BOW:
                    item_pointer->data.material_type = ITEM_MATERIAL_WOOD;
                    temp_int = random(2);
                    temp_string = "data/textures/UI/icons/bows/bow_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_DAGGER:
                    item_pointer->data.material_type = ITEM_MATERIAL_METAL;
                    temp_int = random(2);
                    temp_string = "data/textures/UI/icons/daggers/dagger_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_HAMMER:
                    item_pointer->data.material_type = ITEM_MATERIAL_METAL;
                    temp_int = random(3);
                    temp_string = "data/textures/UI/icons/hammers/hammer_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_MACE:
                    item_pointer->data.material_type = ITEM_MATERIAL_METAL;
                    temp_int = random(2);
                    temp_string = "data/textures/UI/icons/maces/mace_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_SICKLE:
                    item_pointer->data.material_type = ITEM_MATERIAL_METAL;
                    temp_int = 0;//random(4);
                    temp_string = "data/textures/UI/icons/sickles/sickle_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_SWORD:
                    item_pointer->data.material_type = ITEM_MATERIAL_METAL;
                    temp_int = random(13);
                    temp_string = "data/textures/UI/icons/swords/sword_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
                case ITEM_WAND:
                default:
                    item_pointer->data.material_type = ITEM_MATERIAL_WOOD;
                    temp_int = random(3);
                    if (temp_int == 22) item_pointer->data.material_type = ITEM_MATERIAL_METAL;
                    temp_string = "data/textures/UI/icons/wands/wand_";
                    if (temp_int < 10) temp_string += "0";
                    temp_string += int_to_string(temp_int) + ".png";
                    item_pointer->data.image.level_0 = game.texture_manager.add_texture(temp_string);
                break;
            }
        break;
        default:
            game.core.log.file_write("Unable to generate item textures -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
        break;
    }
};

void  item_manager_class::gen_item_sounds(item_type* item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    switch (item_pointer->data.material_type)
    {
        case ITEM_MATERIAL_POTION:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_MATERIAL_GEM:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
        break;
        case ITEM_MATERIAL_BOOK:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/book_02.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/book_00.wav");
        break;
        case ITEM_MATERIAL_RING:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/ring_01.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/ring_01.wav");
        break;
        case ITEM_MATERIAL_AMULET:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/cloth_00.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/cloth_00.wav");
        break;
        case ITEM_MATERIAL_METAL:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/metal_00.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/metal_00.wav");
        break;
        case ITEM_MATERIAL_WOOD:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/wood_00.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/wood_03.wav");
        break;
        case ITEM_MATERIAL_LEATHER:
            item_pointer->data.sound.on_move = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
            item_pointer->data.sound.on_use  = game.sound_manager.add_sound("data/sound/inventory/leather_00.wav");
        break;
        default:
            game.core.log.file_write("Unable to generate item sounds -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
        break;
    }
};


