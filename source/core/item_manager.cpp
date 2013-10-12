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
    item_manager_class::last->data.consumable             = false;
    item_manager_class::last->data.equipable              = false;
    item_manager_class::last->data.quest                  = false;
    item_manager_class::last->data.name                   = "";
    item_manager_class::last->data.number_of_item_effects = 0;
    item_manager_class::last->data.number_of_item_sockets = 0;
    item_manager_class::last->data.quantity               = 0;
    item_manager_class::last->data.quantity_max           = 0;
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
    int  UID_max    = sizeof(int);
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
    return (-1);
};

void item_manager_class::load_items(std::string file_name)
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
                        temp_item_pointer->data.consumable = ((temp_string_key == "EQUIPABLE") &&(temp_string_data == "TRUE")) ? true : false;
                        temp_item_pointer->data.consumable = ((temp_string_key == "QUEST")     &&(temp_string_data == "TRUE")) ? true : false;
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

void item_manager_class::use_item(UI_form_struct *UI_form_pointer, int element_number)
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
                used_item = game.effect_manager.use_effect(temp_item_pointer->data.effect[effect_count]);
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
    int new_UID = RETURN_FAIL;
        new_UID = game.item_manager.get_new_item_UID();
    if (new_UID >= 0)
    {
        item_type*      temp_item_pointer;
        temp_item_pointer = game.item_manager.add_item(new_UID);
        if (temp_item_pointer)
        {
            temp_item_pointer->data.active = true;
            switch (item_type_UID)
            {
                case ITEM_POTION:
                    temp_item_pointer->data.consumable = true;
                break;
                case ITEM_SPELL_BOOK:
                    temp_item_pointer->data.consumable = true;
                break;
                case ITEM_BELT:
                    temp_item_pointer->data.equipable = true;
                break;
                case ITEM_BODY:
                    temp_item_pointer->data.equipable = true;
                break;
                case ITEM_FEET:
                    temp_item_pointer->data.equipable = true;
                break;
                case ITEM_HAND:
                    temp_item_pointer->data.equipable = true;
                break;
                case ITEM_HEAD:
                    temp_item_pointer->data.equipable = true;
                break;
                case ITEM_NECK:
                    temp_item_pointer->data.equipable = true;
                break;
                case ITEM_OFFHAND:
                    temp_item_pointer->data.equipable = true;
                break;
                case ITEM_RING:
                    temp_item_pointer->data.equipable = true;
                break;
                default:
                    game.core.log.file_write("Unable to generate item -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
                break;
            }
            item_manager_class::gen_item_name   (temp_item_pointer,item_type_UID, item_sub_type_UID, quality_level);
            item_manager_class::gen_item_texture(temp_item_pointer,item_type_UID, item_sub_type_UID, quality_level);
            item_manager_class::gen_item_sounds (temp_item_pointer,item_type_UID, item_sub_type_UID, quality_level);
        }
        else new_UID = RETURN_FAIL;
    }
    return (new_UID);
};

void  item_manager_class::gen_item_name(item_type* temp_item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    temp_item_pointer->data.name = "Randomly generated item";
    //game.core.log.file_write("Unable to generate item -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
};

void  item_manager_class::gen_item_texture(item_type* temp_item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    switch (item_type_UID)
    {
        case ITEM_POTION:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
        break;
        case ITEM_SPELL_BOOK:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/books/book_19.png");
        break;
        case ITEM_BELT:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/belts/belt_00.png");
        break;
        case ITEM_BODY:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/armour/armour_00.png");
        break;
        case ITEM_FEET:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/boots/boots_06.png");
        break;
        case ITEM_HAND:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/gloves/gloves_00.png");
        break;
        case ITEM_HEAD:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/helms/helm_00.png");
        break;
        case ITEM_NECK:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/amulets/amulet_00.png");
        break;
        case ITEM_OFFHAND:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/shields/shield_03.png");
        break;
        case ITEM_RING:
            temp_item_pointer->data.image = game.texture_manager.add_texture("data/textures/UI/icons/rings/ring_00.png");
        break;
        default:
            game.core.log.file_write("Unable to generate item textures -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
        break;
    }
};

void  item_manager_class::gen_item_sounds(item_type* temp_item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level)
{
    switch (item_type_UID)
    {
        case ITEM_POTION:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_SPELL_BOOK:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/book_02.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/book_00.wav");
        break;
        case ITEM_BELT:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_BODY:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_FEET:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_HAND:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_HEAD:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_NECK:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_OFFHAND:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
        break;
        case ITEM_RING:
            temp_item_pointer->data.sound_move = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
            temp_item_pointer->data.sound_use  = game.sound_manager.add_sound("data/sound/inventory/ring_00.wav");
        break;
        default:
            game.core.log.file_write("Unable to generate item textures -> ",item_type_UID," - ", item_sub_type_UID," - ", quality_level);
        break;
    }
};
