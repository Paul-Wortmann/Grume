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
            game.effect_manager.use_effect(item_pointer->data.effect[effect_count].type,item_pointer->data.effect[effect_count].value);
        }
    }
};

void item_manager_class::unequip_item(item_type* item_pointer)
{
    for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
    {
        if (item_pointer->data.equipable)
        {
            game.effect_manager.use_effect(item_pointer->data.effect[effect_count].type,(item_pointer->data.effect[effect_count].value * -1));
        }
    }
};

int  item_manager_class::gen_item(int item_type_UID, int item_sub_type_UID, int quality_level)
{
    int  new_UID           = RETURN_FAIL;
    if (item_sub_type_UID == ITEM_GEM)
    {
        switch (random(5))
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
            default:
                item_sub_type_UID = ITEM_GEM_TOPAZ;
            break;
        }
    }
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
            item_type* item_pointer = new item_type;
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
                        item_pointer->data.qaulity_type = ITEM_QUALITY_EPIC; // delete me? O_o
                        item_pointer->data.consumable             = false;
                        item_pointer->data.stackable              = false;
                        item_pointer->data.quantity               = 1;
                        item_pointer->data.quantity_max           = 1;
                        if (item_pointer->data.number_of_item_sockets > 0) item_pointer->data.number_of_item_sockets = 0;
                        switch (item_sub_type_UID)
                        {
                            case ITEM_GEM_EMERALD:
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_DEXTERITY;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            case ITEM_GEM_OPAL:
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_STRENGTH;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            break;
                            case ITEM_GEM_RUBY:
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH_MAX;
                                item_pointer->data.effect[0].value        = random(quality_level);
                            break;
                            case ITEM_GEM_SAPPHIRE:
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_MANA_MAX;
                                item_pointer->data.effect[0].value        = random(quality_level);
                            break;
                            case ITEM_GEM_TOPAZ:
                                item_pointer->data.number_of_item_effects = 1;
                                item_pointer->data.effect[0].enabled      = true;
                                item_pointer->data.effect[0].type         = EFFECT_MOD_INTELLECT;
                                item_pointer->data.effect[0].value        = quality_level/10;
                            default:
                            break;
                        }
                        if ((item_pointer->data.effect[0].enabled) && (item_pointer->data.effect[0].value <= 0)) item_pointer->data.effect[0].value = 1;
                        if ((item_pointer->data.effect[1].enabled) && (item_pointer->data.effect[1].value <= 0)) item_pointer->data.effect[1].value = 1;
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
                        item_pointer->data.effect[0].enabled      = true;
                        item_pointer->data.effect[0].type         = EFFECT_MOD_ARMOR;
                        item_pointer->data.effect[0].value        = random(quality_level);
                        if (item_pointer->data.number_of_item_effects > 1)
                        {
                            item_pointer->data.qaulity_type = ITEM_QUALITY_MAGIC;
                            int  AVAILABLE_EFFECT_COUNT = 12;
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
                                        bool found                  = false;
                                        bool effect_used_source[AVAILABLE_EFFECT_COUNT];
                                        for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                                        {
                                            effect_used_source[temp_count] = false;
                                        }
                                        for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                                        {
                                            found = false;
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
                                        bool found                  = false;
                                        bool effect_used_shield[AVAILABLE_EFFECT_COUNT];
                                        for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                                        {
                                            effect_used_shield[temp_count] = false;
                                        }
                                        for (int effect_count = 1; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                                        {
                                            found = false;
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
                            bool found                  = false;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
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
                            bool found                  = false;
                            bool effect_used[AVAILABLE_EFFECT_COUNT];
                            for (int temp_count = 0; temp_count < AVAILABLE_EFFECT_COUNT; temp_count++)
                            {
                                effect_used[temp_count] = false;
                            }
                            for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
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
                case SPELL_FIRE_ARROW:
                    item_pointer->data.name = "of fire arrow";
                break;
                case SPELL_ICE_ARROW:
                    item_pointer->data.name = "of ice arrow";
                break;
                case SPELL_LIGHTNING_ARROW:
                    item_pointer->data.name = "of lightning arrow";
                break;
                case SPELL_ELEMENTAL_ARROW:
                    item_pointer->data.name = "of elemental arrow";
                break;
                default:
                    item_pointer->data.name = "of spell craft";
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
            switch (best_effect)
            {
                case EFFECT_MOD_DEXTERITY:
                    post_name = "of nimbus";
                break;
                case EFFECT_MOD_RESIST_PHYSICAL:
                    post_name = "of the brute";
                break;
                case EFFECT_MOD_RESIST_ICE:
                    post_name = "of frost";
                break;
                case EFFECT_MOD_RESIST_FIRE:
                    post_name = "of flame";
                break;
                case EFFECT_MOD_RESIST_LIGHTNING:
                    post_name = "of thunder";
                break;
                case EFFECT_MOD_RESIST_ALL:
                    post_name = "of resistance";
                break;
                case EFFECT_MOD_HEALTH_REGEN:
                    post_name = "of life";
                break;
                case EFFECT_MOD_MANA_MAX:
                    post_name = "of wizardry";
                break;
                case EFFECT_MOD_MOVEMENT_SPEED:
                    post_name = "of speed";
                break;
                case EFFECT_MOD_MAGIC_FIND:
                    post_name = "of luck";
                break;
                case EFFECT_MOD_GOLD_FIND:
                    post_name = "of the leprechaun";
                break;
                case EFFECT_MOD_ARMOR:
                default:
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
                break;
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_BELT:
            base_name = "belt ";
            switch (best_effect)
            {
                case EFFECT_MOD_STRENGTH:
                    post_name = "of power";
                break;
                case EFFECT_MOD_DEXTERITY:
                    post_name = "of nimbus";
                break;
                case EFFECT_MOD_RESIST_PHYSICAL:
                    post_name = "of the brute";
                break;
                case EFFECT_MOD_RESIST_ICE:
                    post_name = "of frost";
                break;
                case EFFECT_MOD_RESIST_FIRE:
                    post_name = "of flame";
                break;
                case EFFECT_MOD_RESIST_LIGHTNING:
                    post_name = "of thunder";
                break;
                case EFFECT_MOD_RESIST_ALL:
                    post_name = "of resistance";
                break;
                case EFFECT_MOD_MANA_REGEN:
                    post_name = "of hexing";
                break;
                case EFFECT_MOD_HEALTH_REGEN:
                    post_name = "of life";
                break;
                case EFFECT_MOD_MANA_MAX:
                    post_name = "of wizardry";
                break;
                case EFFECT_MOD_MAGIC_FIND:
                    post_name = "of luck";
                break;
                case EFFECT_MOD_GOLD_FIND:
                    post_name = "of the leprechaun";
                break;
                case EFFECT_MOD_ARMOR:
                default:
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
                break;
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_HEAD:
            base_name = "helm ";
            switch (best_effect)
            {
                case EFFECT_MOD_STRENGTH:
                    post_name = "of power";
                break;
                case EFFECT_MOD_DEXTERITY:
                    post_name = "of nimbus";
                break;
                case EFFECT_MOD_INTELLECT:
                    post_name = "of the mind";
                break;
                case EFFECT_MOD_ALL_ATTRIBUTES:
                    post_name = "of skill";
                break;
                case EFFECT_MOD_RESIST_PHYSICAL:
                    post_name = "of the brute";
                break;
                case EFFECT_MOD_RESIST_ICE:
                    post_name = "of frost";
                break;
                case EFFECT_MOD_RESIST_FIRE:
                    post_name = "of flame";
                break;
                case EFFECT_MOD_RESIST_LIGHTNING:
                    post_name = "of thunder";
                break;
                case EFFECT_MOD_RESIST_ALL:
                    post_name = "of resistance";
                break;
                case EFFECT_MOD_MANA_REGEN:
                    post_name = "of hexing";
                break;
                case EFFECT_MOD_HEALTH_REGEN:
                    post_name = "of life";
                break;
                case EFFECT_MOD_MANA_MAX:
                    post_name = "of wizardry";
                break;
                case EFFECT_MOD_MOVEMENT_SPEED:
                    post_name = "of speed";
                break;
                case EFFECT_MOD_MAGIC_FIND:
                    post_name = "of luck";
                break;
                case EFFECT_MOD_GOLD_FIND:
                    post_name = "of the leprechaun";
                break;
                case EFFECT_MOD_LIGHT_RADIUS:
                    post_name = "of the brilliance";
                break;
                case EFFECT_MOD_EXP_PER_KILL:
                    post_name = "of wisdom";
                break;
                case EFFECT_MOD_ARMOR:
                default:
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
                break;
            }
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_BODY:
            base_name = "armor ";

            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_HAND:
            base_name = "gloves ";

            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_RING:
            base_name = "ring ";

            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_NECK:
            base_name = "amulet ";

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
            item_pointer->data.name = pre_name+base_name+post_name;
        break;
        case ITEM_WEAPON:
            base_name = "sword ";

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
    switch (item_type_UID)
    {
        case ITEM_GEM:
            switch (item_sub_type_UID)
            {
                case ITEM_GEM_EMERALD:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_6_4.png");
                break;
                case ITEM_GEM_OPAL:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_8_4.png");
                break;
                case ITEM_GEM_RUBY:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_7_4.png");
                break;
                case ITEM_GEM_SAPPHIRE:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_1.png");
                if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_5_4.png");
                break;
                case ITEM_GEM_TOPAZ:
                default:
                    if (quality_level < (MAX_ITEM_QUALITY*0.2f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_0.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.2f))&&(quality_level < (MAX_ITEM_QUALITY*0.4f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_1.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.4f))&&(quality_level < (MAX_ITEM_QUALITY*0.6f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_2.png");
                    if ((quality_level >= (MAX_ITEM_QUALITY*0.6f))&&(quality_level < (MAX_ITEM_QUALITY*0.8f)))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_3.png");
                    if (quality_level >= (MAX_ITEM_QUALITY*0.8f))
                        item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gems/gem_9_4.png");
                break;
            }
        break;
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
            switch (item_sub_type_UID)
            {
                case SPELL_FIRE_ARROW:
                    item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/books/book_05.png");
                break;
                case SPELL_ICE_ARROW:
                    item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/books/book_19.png");
                break;
                case SPELL_LIGHTNING_ARROW:
                    item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/books/book_15.png");
                break;
                case SPELL_ELEMENTAL_ARROW:
                    item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/books/book_17.png");
                break;
                default:
                    item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/books/book_04.png");
                break;
            }
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
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/shields/shield_07.png");
        break;
        case ITEM_RING:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/rings/ring_00.png");
        break;
        case ITEM_WEAPON:
            item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/swords/sword_28.png");
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
        case ITEM_GEM:
            item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
            item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
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
            game.core.log.file_write("Unable to generate item sounds -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
        break;
    }
};





/*

//------------------------------ unique name generation based on randomly generated stats -------------------------------

    switch (type)
    {
        case HELM:
            temp_range = random(7);
            if (temp_range <=  0) temp_name_type = "hat";
            if (temp_range ==  1) temp_name_type = "bonnet";
            if (temp_range ==  2) temp_name_type = "headgear";
            if (temp_range ==  3) temp_name_type = "headpiece";
            if (temp_range ==  4) temp_name_type = "helmet";
            if (temp_range ==  5) temp_name_type = "cap";
            if (temp_range >=  6) temp_name_type = "helm";
        break;
        case BOOTS:
            temp_range = random(7);
            if (temp_range <=  0) temp_name_type = "slippers";
            if (temp_range ==  1) temp_name_type = "footwear";
            if (temp_range ==  2) temp_name_type = "footgear";
            if (temp_range ==  3) temp_name_type = "clogs";
            if (temp_range ==  4) temp_name_type = "sandals";
            if (temp_range ==  5) temp_name_type = "shoes";
            if (temp_range >=  6) temp_name_type = "boots";
        break;
        case ARMOUR:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_type = "guard";
            if (temp_range ==  1) temp_name_type = "vest";
            if (temp_range ==  2) temp_name_type = "mail";
            if (temp_range ==  3) temp_name_type = "plate";
            if (temp_range ==  4) temp_name_type = "husk";
            if (temp_range >=  5) temp_name_type = "armor";
        break;
        case SHIELD:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_type = "absorber";
            if (temp_range ==  1) temp_name_type = "armament";
            if (temp_range ==  2) temp_name_type = "buckler";
            if (temp_range ==  3) temp_name_type = "buffer";
            if (temp_range ==  4) temp_name_type = "ward";
            if (temp_range >=  5) temp_name_type = "shield";
        break;
        case GLOVES:
            temp_range = random(4);
            if (temp_range <=  0) temp_name_type = "gauntlets";
            if (temp_range ==  1) temp_name_type = "gage";
            if (temp_range ==  2) temp_name_type = "mitts";
            if (temp_range >=  3) temp_name_type = "gloves";
        break;
        case BELT:
            temp_range = random(4);
            if (temp_range <=  0) temp_name_type = "bind";
            if (temp_range ==  1) temp_name_type = "wrap";
            if (temp_range ==  2) temp_name_type = "sash";
            if (temp_range >=  3) temp_name_type = "belt";
        break;
        case RING:
            temp_range = random(4);
            if (temp_range <=  0) temp_name_type = "band";
            if (temp_range ==  1) temp_name_type = "loop";
            if (temp_range ==  2) temp_name_type = "ringlet";
            if (temp_range >=  3) temp_name_type = "ring";
        break;
        case AMULET:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_type = "ornament";
            if (temp_range ==  1) temp_name_type = "charm";
            if (temp_range ==  2) temp_name_type = "talisman";
            if (temp_range ==  3) temp_name_type = "chain";
            if (temp_range ==  4) temp_name_type = "pendant";
            if (temp_range >=  5) temp_name_type = "amulet";
        break;
        case WAND:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_type = "rod";
            if (temp_range ==  1) temp_name_type = "stick";
            if (temp_range ==  2) temp_name_type = "twig";
            if (temp_range ==  3) temp_name_type = "staff";
            if (temp_range ==  4) temp_name_type = "scepter";
            if (temp_range >=  5) temp_name_type = "wand";
        break;
        case SWORD:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_type = "scimitar";
            if (temp_range ==  1) temp_name_type = "rapier";
            if (temp_range ==  2) temp_name_type = "cutlass";
            if (temp_range ==  3) temp_name_type = "katana";
            if (temp_range ==  4) temp_name_type = "saber";
            if (temp_range >=  5) temp_name_type = "sword";
        break;
        case DAGGER:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_type = "knife";
            if (temp_range ==  1) temp_name_type = "dirk";
            if (temp_range ==  2) temp_name_type = "poniard";
            if (temp_range ==  3) temp_name_type = "edge";
            if (temp_range ==  4) temp_name_type = "blade";
            if (temp_range >=  5) temp_name_type = "dagger";
        break;
        case BOW:
            temp_range = random(4);
            if (temp_range <=  0) temp_name_type = "crossbow";
            if (temp_range ==  1) temp_name_type = "arbalest";
            if (temp_range ==  2) temp_name_type = "ballista";
            if (temp_range >=  3) temp_name_type = "bow";
        break;
    }
    switch (type)
    {
        case ARMOUR:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "gloom";
            if (temp_range ==  1) temp_name_suffix = "cover";
            if (temp_range ==  2) temp_name_suffix = "stealth";
            if (temp_range ==  3) temp_name_suffix = "honor";
            if (temp_range ==  4) temp_name_suffix = "courage";
            if (temp_range >=  5) temp_name_suffix = "bravery";
        break;
        case SHIELD:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "blocking";
            if (temp_range ==  1) temp_name_suffix = "warding";
            if (temp_range ==  2) temp_name_suffix = "stopping";
            if (temp_range ==  3) temp_name_suffix = "safety";
            if (temp_range ==  4) temp_name_suffix = "misery";
            if (temp_range >=  5) temp_name_suffix = "woe";
        break;
        case GLOVES:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "might";
            if (temp_range ==  1) temp_name_suffix = "fist";
            if (temp_range ==  2) temp_name_suffix = "straggle";
            if (temp_range ==  3) temp_name_suffix = "grip";
            if (temp_range ==  4) temp_name_suffix = "punching";
            if (temp_range >=  5) temp_name_suffix = "pounding";
        break;
        case RING:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "myth";
            if (temp_range ==  1) temp_name_suffix = "the adventurer";
            if (temp_range ==  2) temp_name_suffix = "trickery";
            if (temp_range ==  3) temp_name_suffix = "trade";
            if (temp_range ==  4) temp_name_suffix = "the lord";
            if (temp_range >=  5) temp_name_suffix = "infinity";
        break;
        case AMULET:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "glow";
            if (temp_range ==  1) temp_name_suffix = "luck";
            if (temp_range ==  2) temp_name_suffix = "dreams";
            if (temp_range ==  3) temp_name_suffix = "determination";
            if (temp_range ==  4) temp_name_suffix = "superstition";
            if (temp_range >=  5) temp_name_suffix = "witches";
        break;
        case WAND:
            temp_range = random(7);
            if (temp_range <=  0) temp_name_suffix = "wizardry";
            if (temp_range ==  1) temp_name_suffix = "magic";
            if (temp_range ==  2) temp_name_suffix = "witchcraft";
            if (temp_range ==  3) temp_name_suffix = "sorcery";
            if (temp_range ==  4) temp_name_suffix = "alchemy";
            if (temp_range ==  5) temp_name_suffix = "mysticism";
            if (temp_range >=  6) temp_name_suffix = "mystery";
        break;
        case SWORD:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "slashing";
            if (temp_range ==  1) temp_name_suffix = "chopping";
            if (temp_range ==  2) temp_name_suffix = "decapitation";
            if (temp_range ==  3) temp_name_suffix = "slicing";
            if (temp_range ==  4) temp_name_suffix = "slaying";
            if (temp_range >=  5) temp_name_suffix = "legends";
        break;
        case DAGGER:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "stabbing";
            if (temp_range ==  1) temp_name_suffix = "gouging";
            if (temp_range ==  2) temp_name_suffix = "piercing";
            if (temp_range ==  3) temp_name_suffix = "pain";
            if (temp_range ==  4) temp_name_suffix = "blinding";
            if (temp_range >=  5) temp_name_suffix = "sacrifice";
        break;
        case BOW:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "accuracy";
            if (temp_range ==  1) temp_name_suffix = "silent death";
            if (temp_range ==  2) temp_name_suffix = "raining death";
            if (temp_range ==  3) temp_name_suffix = "precision";
            if (temp_range ==  4) temp_name_suffix = "torture";
            if (temp_range >=  5) temp_name_suffix = "the hunt";
        break;
        case SLING:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "rebellion";
            if (temp_range ==  1) temp_name_suffix = "slaughter";
            if (temp_range ==  2) temp_name_suffix = "savagery";
            if (temp_range ==  3) temp_name_suffix = "punishment";
            if (temp_range ==  4) temp_name_suffix = "provoking";
            if (temp_range >=  5) temp_name_suffix = "the uprising";
        break;
        default:
        break;
    }
    game.item[item_ID].name = temp_name_prefix + " " + temp_name_type + " of " + temp_name_suffix;
    // add name padding...

    init_item_sounds(item_ID); // add sounds to item
};

*/






/*
                case EFFECT_MOD_STRENGTH:
                    post_name = "of power";
                break;
                case EFFECT_MOD_DEXTERITY:
                    post_name = "of nimbus";
                break;
                case EFFECT_MOD_INTELLECT:
                    post_name = "of the mind";
                break;
                case EFFECT_MOD_ALL_ATTRIBUTES:
                    post_name = "of skill";
                break;
                case EFFECT_MOD_RESIST_PHYSICAL:
                    post_name = "of the brute";
                break;
                case EFFECT_MOD_RESIST_ICE:
                    post_name = "of frost";
                break;
                case EFFECT_MOD_RESIST_FIRE:
                    post_name = "of flame";
                break;
                case EFFECT_MOD_RESIST_LIGHTNING:
                    post_name = "of thunder";
                break;
                case EFFECT_MOD_RESIST_ALL:
                    post_name = "of resistance";
                break;
                case EFFECT_MOD_MANA_REGEN:
                    post_name = "of hexing";
                break;
                case EFFECT_MOD_HEALTH_REGEN:
                    post_name = "of life";
                break;
                case EFFECT_MOD_MANA_MAX:
                    post_name = "of wizardry";
                break;
                case EFFECT_MOD_MOVEMENT_SPEED:
                    post_name = "of speed";
                break;
                case EFFECT_MOD_MAGIC_FIND:
                    post_name = "of luck";
                break;
                case EFFECT_MOD_GOLD_FIND:
                    post_name = "of the leprechaun";
                break;
                case EFFECT_MOD_LIGHT_RADIUS:
                    post_name = "of the brilliance";
                break;
                case EFFECT_MOD_EXP_PER_KILL:
                    post_name = "of wisdom";
                break;
                case EFFECT_MOD_ARMOR:
                break;
*/
