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

#include "items.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

item_class::item_class(void)
{
    item_class::name                    = "None";
    item_class::image_ref               = 0;
    item_class::ID                      = 100;
    item_class::defense                 = 0;
    item_class::min_damage              = 0;
    item_class::max_damage              = 0;
    item_class::add_min_damage          = 0;
    item_class::add_max_damage          = 0;
    item_class::sub_min_damage          = 0;
    item_class::sub_max_damage          = 0;
    item_class::add_max_health          = 0;
    item_class::sub_max_health          = 0;
    item_class::add_max_mana            = 0;
    item_class::sub_max_mana            = 0;
    item_class::add_health_regeneration = 0;
    item_class::sub_health_regeneration = 0;
    item_class::add_mana_regeneration   = 0;
    item_class::sub_mana_regeneration   = 0;
    item_class::add_crit_chance         = 0;
    item_class::sub_crit_chance         = 0;
    item_class::add_spell               = 0;
    item_class::spell_type              = 0;
    item_class::usable                  = false;
};

item_class::~item_class(void)
{

};

void item_class::load(std::string file_name)
{
    char           temp_char_UTF8   = ' ';
    short          temp_char_UTF16  = ' ';
    int            temp_char_UTF32  = ' ';
    float          temp_float_data;
    int            temp_int_data;
    bool           temp_bool_data;
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
                        if(count > data_line.length()) (temp_char_UTF32 = ' ');
                    }
                    while((temp_char_UTF32 == ' ') || (temp_char_UTF32 == '='))
                    {
                        temp_char_UTF32 = data_line[count];
                        count++;
                        if(count > data_line.length()) (temp_char_UTF32 = '#');
                    }
                    count--;
                    while(count < (data_line.length()-1))
                    {
                        temp_char_UTF32  = data_line[count];
                        if (temp_char_UTF32 != '"') temp_string_value += temp_char_UTF32;
                        count++;
                    }
                    temp_string_data = temp_string_value.c_str();
                    temp_float_data  = (float) atof(temp_string_value.c_str());
                    temp_int_data    = (int)   atoi(temp_string_value.c_str());
                    if (temp_int_data == 1) temp_bool_data = true;
                    else temp_bool_data = false;
                    if (temp_string_key == "Name")                    item_class::name                    = temp_string_data;
                    if (temp_string_key == "ID")                      item_class::ID                      = temp_int_data;
                    if (temp_string_key == "type")                    item_class::type                    = temp_int_data;
                    if (temp_string_key == "stack_number")            item_class::stack_number            = temp_int_data;
                    if (temp_string_key == "max_stack_number")        item_class::max_stack_number        = temp_int_data;
                    if (temp_string_key == "defense")                 item_class::defense                 = temp_int_data;
                    if (temp_string_key == "add_defense")             item_class::add_defense             = temp_int_data;
                    if (temp_string_key == "sub_defense")             item_class::sub_defense             = temp_int_data;
                    if (temp_string_key == "min_damage")              item_class::min_damage              = temp_int_data;
                    if (temp_string_key == "max_damage")              item_class::max_damage              = temp_int_data;
                    if (temp_string_key == "add_min_damage")          item_class::add_min_damage          = temp_int_data;
                    if (temp_string_key == "add_max_damage")          item_class::add_max_damage          = temp_int_data;
                    if (temp_string_key == "sub_min_damage")          item_class::sub_min_damage          = temp_int_data;
                    if (temp_string_key == "sub_max_damage")          item_class::sub_max_damage          = temp_int_data;
                    if (temp_string_key == "add_max_health")          item_class::add_max_health          = temp_int_data;
                    if (temp_string_key == "sub_max_health")          item_class::sub_max_health          = temp_int_data;
                    if (temp_string_key == "add_max_mana")            item_class::add_max_mana            = temp_int_data;
                    if (temp_string_key == "sub_max_mana")            item_class::sub_max_mana            = temp_int_data;
                    if (temp_string_key == "add_health_regeneration") item_class::add_health_regeneration = temp_int_data;
                    if (temp_string_key == "sub_health_regeneration") item_class::sub_health_regeneration = temp_int_data;
                    if (temp_string_key == "add_mana_regeneration")   item_class::add_mana_regeneration   = temp_int_data;
                    if (temp_string_key == "sub_mana_regeneration")   item_class::sub_mana_regeneration   = temp_int_data;
                    if (temp_string_key == "add_crit_chance")         item_class::add_crit_chance         = temp_int_data;
                    if (temp_string_key == "sub_crit_chance")         item_class::sub_crit_chance         = temp_int_data;
                    if (temp_string_key == "add_walk_speed")          item_class::add_walk_speed          = temp_int_data;
                    if (temp_string_key == "sub_walk_speed")          item_class::sub_walk_speed          = temp_int_data;
                    if (temp_string_key == "add_light_radius")        item_class::add_light_radius        = temp_int_data;
                    if (temp_string_key == "sub_light_radius")        item_class::sub_light_radius        = temp_int_data;
                    if (temp_string_key == "add_spell")               item_class::add_spell               = temp_int_data;
                    if (temp_string_key == "spell_type")              item_class::spell_type              = temp_int_data;
                    if (temp_string_key == "add_health")              item_class::add_health              = temp_int_data;
                    if (temp_string_key == "add_mana")                item_class::add_mana                = temp_int_data;
                    if (temp_string_key == "usable")                  item_class::usable                  = temp_bool_data;
                }
            }
        }
        script_file.close();
    }
};

void init_items(void)
{
//-------------------------------- Skills / Spells -------------------------------------------------------------------
    game.item[1].name              = "Book of Chain Lightning";
    game.item[1].image_ref         = game.texture.book_15.ref_number;
    game.item[1].stack_number      = 5;
    game.item[1].max_stack_number  = 10;
    game.item[1].ID                = 101;
    game.item[1].type              = SPELL_BOOK;
    game.item[1].add_spell         = 1;
    game.item[1].spell_type        = 2;
    game.item[1].usable            = true;
    game.item[2].name              = "Book of Stalagmite";
    game.item[2].image_ref         = game.texture.book_19.ref_number;
    game.item[2].stack_number      = 5;
    game.item[2].max_stack_number  = 10;
    game.item[2].ID                = 102;
    game.item[2].type              = SPELL_BOOK;
    game.item[2].add_spell         = 1;
    game.item[2].spell_type        = 1;
    game.item[2].usable            = true;

//-------------------------------- Potions --------------------------------------------------------------------------
    game.item[101].name              = "Minuscule Health Potion";
    game.item[101].image_ref         = game.texture.potion_01.ref_number;
    game.item[101].stack_number      = 1;
    game.item[101].max_stack_number  = 20;
    game.item[101].ID                = 201;
    game.item[101].type              = HEALTH_POTION;
    game.item[101].add_health        = 5;
    game.item[102].name              = "Tiny Health Potion";
    game.item[102].image_ref         = game.texture.potion_02.ref_number;
    game.item[102].stack_number      = 1;
    game.item[102].max_stack_number  = 20;
    game.item[102].ID                = 202;
    game.item[102].type              = HEALTH_POTION;
    game.item[102].add_health        = 10;
    game.item[103].name              = "Small Health Potion";
    game.item[103].image_ref         = game.texture.potion_03.ref_number;
    game.item[103].stack_number      = 1;
    game.item[103].max_stack_number  = 20;
    game.item[103].ID                = 203;
    game.item[103].type              = HEALTH_POTION;
    game.item[103].add_health        = 20;
    game.item[104].name              = "Medium Health Potion";
    game.item[104].image_ref         = game.texture.potion_04.ref_number;
    game.item[104].stack_number      = 1;
    game.item[104].max_stack_number  = 20;
    game.item[104].ID                = 204;
    game.item[104].type              = HEALTH_POTION;
    game.item[104].add_health        = 40;
    game.item[105].name              = "Large Health Potion";
    game.item[105].image_ref         = game.texture.potion_05.ref_number;
    game.item[105].stack_number      = 1;
    game.item[105].max_stack_number  = 20;
    game.item[105].ID                = 205;
    game.item[105].type              = HEALTH_POTION;
    game.item[105].add_health        = 80;
    game.item[106].name              = "Huge Health Potion";
    game.item[106].image_ref         = game.texture.potion_06.ref_number;
    game.item[106].stack_number      = 1;
    game.item[106].max_stack_number  = 20;
    game.item[106].ID                = 206;
    game.item[106].type              = HEALTH_POTION;
    game.item[106].add_health        = 160;
    game.item[107].name              = "Gigantic Health Potion";
    game.item[107].image_ref         = game.texture.potion_07.ref_number;
    game.item[107].stack_number      = 1;
    game.item[107].max_stack_number  = 20;
    game.item[107].ID                = 207;
    game.item[107].type              = HEALTH_POTION;
    game.item[107].add_health        = 320;

    game.item[108].name              = "Minuscule Mana Potion";
    game.item[108].image_ref         = game.texture.potion_08.ref_number;
    game.item[108].stack_number      = 1;
    game.item[108].max_stack_number  = 20;
    game.item[108].ID                = 208;
    game.item[108].type              = MANA_POTION;
    game.item[108].add_mana          = 5;
    game.item[109].name              = "Tiny Mana Potion";
    game.item[109].image_ref         = game.texture.potion_09.ref_number;
    game.item[109].stack_number      = 1;
    game.item[109].max_stack_number  = 20;
    game.item[109].ID                = 209;
    game.item[109].type              = MANA_POTION;
    game.item[109].add_mana          = 10;
    game.item[110].name              = "Small Mana Potion";
    game.item[110].image_ref         = game.texture.potion_10.ref_number;
    game.item[110].stack_number      = 1;
    game.item[110].max_stack_number  = 20;
    game.item[110].ID                = 210;
    game.item[110].type              = MANA_POTION;
    game.item[110].add_mana          = 20;
    game.item[111].name              = "Medium Mana Potion";
    game.item[111].image_ref         = game.texture.potion_11.ref_number;
    game.item[111].stack_number      = 1;
    game.item[111].max_stack_number  = 20;
    game.item[111].ID                = 211;
    game.item[111].type              = MANA_POTION;
    game.item[111].add_mana          = 40;
    game.item[112].name              = "Large Mana Potion";
    game.item[112].image_ref         = game.texture.potion_12.ref_number;
    game.item[112].stack_number      = 1;
    game.item[112].max_stack_number  = 20;
    game.item[112].ID                = 212;
    game.item[112].type              = MANA_POTION;
    game.item[112].add_mana          = 80;
    game.item[113].name              = "Huge Mana Potion";
    game.item[113].image_ref         = game.texture.potion_13.ref_number;
    game.item[113].stack_number      = 1;
    game.item[113].max_stack_number  = 20;
    game.item[113].ID                = 213;
    game.item[113].type              = MANA_POTION;
    game.item[113].add_mana          = 160;
    game.item[114].name              = "Gigantic Mana Potion";
    game.item[114].image_ref         = game.texture.potion_14.ref_number;
    game.item[114].stack_number      = 1;
    game.item[114].max_stack_number  = 20;
    game.item[114].ID                = 214;
    game.item[114].type              = MANA_POTION;
    game.item[114].add_mana          = 320;

//-------------------------------- Boots ----------------------------------------------------------------------------
    game.item[201].name              = "Boots of Haste";
    game.item[201].image_ref         = game.texture.boots_09.ref_number;
    game.item[201].stack_number      = 1;
    game.item[201].max_stack_number  = 1;
    game.item[201].ID                = 301;
    game.item[201].type              = BOOTS;
    game.item[201].defense           = 4;
    game.item[202].name              = "Boots of Flame walk";
    game.item[202].image_ref         = game.texture.boots_06.ref_number;
    game.item[202].stack_number      = 1;
    game.item[202].max_stack_number  = 1;
    game.item[202].ID                = 302;
    game.item[202].type              = BOOTS;
    game.item[202].defense           = 2;

//-------------------------------- Armour ----------------------------------------------------------------------------
    game.item[301].name              = "Plate Armour";
    game.item[301].image_ref         = game.texture.armour_00.ref_number;
    game.item[301].stack_number      = 1;
    game.item[301].max_stack_number  = 1;
    game.item[301].ID                = 401;
    game.item[301].type              = ARMOUR;
    game.item[301].defense           = 10;

//-------------------------------- Bows ----------------------------------------------------------------------------
    game.item[401].name              = "Bow";

//-------------------------------- Daggers ----------------------------------------------------------------------------
    game.item[501].name              = "Frost Dagger";
    game.item[501].image_ref         = game.texture.dagger_00.ref_number;
    game.item[501].stack_number      = 1;
    game.item[501].max_stack_number  = 1;
    game.item[501].ID                = 601;
    game.item[501].type              = DAGGER;
    game.item[501].min_damage        = 6;
    game.item[501].max_damage        = 12;

};






