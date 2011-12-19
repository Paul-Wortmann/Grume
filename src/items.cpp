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
#include "misc.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

item_class::item_class(void)
{
    item_class::name                     = "None";
    item_class::active                   = false;
    item_class::image_ref                = 0;
    item_class::sound_ref                = 0;
    item_class::ID                       = 100;
    item_class::type                     = 0;
    item_class::stack_number             = 1;
    item_class::max_stack_number         = 1;
    item_class::require_defence          = 0;
    item_class::require_strength         = 0;
    item_class::require_intelligence     = 0;
    item_class::armour                   = 0;
    item_class::add_armour               = 0;
    item_class::sub_armour               = 0;
    item_class::min_damage               = 0;
    item_class::max_damage               = 0;
    item_class::add_min_damage           = 0;
    item_class::add_max_damage           = 0;
    item_class::sub_min_damage           = 0;
    item_class::sub_max_damage           = 0;
    item_class::add_max_health           = 0;
    item_class::sub_max_health           = 0;
    item_class::add_max_mana             = 0;
    item_class::sub_max_mana             = 0;
    item_class::add_health_regeneration  = 0;
    item_class::sub_health_regeneration  = 0;
    item_class::add_mana_regeneration    = 0;
    item_class::sub_mana_regeneration    = 0;
    item_class::add_crit_chance          = 0;
    item_class::sub_crit_chance          = 0;
    item_class::add_walk_speed           = 0;
    item_class::sub_walk_speed           = 0;
    item_class::add_light_radius         = 0;
    item_class::sub_light_radius         = 0;
    item_class::add_health               = 0;
    item_class::add_mana                 = 0;
    item_class::add_spell                = 0;
    item_class::spell_type               = 0;
    item_class::add_fire_damage          = 0;
    item_class::add_frost_damage         = 0;
    item_class::add_lightning_damage     = 0;
    item_class::add_magic_damage         = 0;
    item_class::add_fire_resistance      = 0;
    item_class::add_frost_resistance     = 0;
    item_class::add_lightning_resistance = 0;
    item_class::add_all_resistances      = 0;
};

item_class::~item_class(void)
{
};

void item_class::equip(void)
{
    game.player.armor                   += item_class::armour;
    game.player.physical_damage_minimum += item_class::min_damage;
    game.player.physical_damage_maximum += item_class::max_damage;
    game.player.health.maximum          += item_class::add_max_health;
    game.player.health.maximum          -= item_class::sub_max_health;
    game.player.mana.maximum            += item_class::add_max_mana;
    game.player.mana.maximum            -= item_class::sub_max_mana;
    game.player.health.regeneration     += (float)item_class::add_health_regeneration/100.0f;
    game.player.health.regeneration     -= (float)item_class::sub_health_regeneration/100.0f;
    game.player.mana.regeneration       += (float)item_class::add_mana_regeneration/100.0f;
    game.player.mana.regeneration       -= (float)item_class::sub_mana_regeneration/100.0f;
    game.player.critical_chance         += item_class::add_crit_chance;
    game.player.critical_chance         -= item_class::sub_crit_chance;
    game.player.walk_speed              += item_class::add_walk_speed;
    game.player.walk_speed              -= item_class::sub_walk_speed;
    game.player.light_radius            += item_class::add_light_radius;
    game.player.light_radius            -= item_class::sub_light_radius;
    game.player.resistance_flame        += item_class::add_fire_resistance;
    game.player.resistance_frost        += item_class::add_frost_resistance;
    game.player.resistance_lightning    += item_class::add_lightning_resistance;
    game.player.resistance_flame        += item_class::add_all_resistances;
    game.player.resistance_frost        += item_class::add_all_resistances;
    game.player.resistance_lightning    += item_class::add_all_resistances;
    game.player.damage_flame            += item_class::add_fire_damage;
    game.player.damage_frost            += item_class::add_frost_damage;
    game.player.damage_lightning        += item_class::add_lightning_damage;
    game.player.damage_flame            += item_class::add_magic_damage;
    game.player.damage_frost            += item_class::add_magic_damage;
    game.player.damage_lightning        += item_class::add_magic_damage;
};

void item_class::unequip(void)
{
    game.player.armor                   -= item_class::armour;
    game.player.physical_damage_minimum -= item_class::min_damage;
    game.player.physical_damage_maximum -= item_class::max_damage;
    game.player.health.maximum          -= item_class::add_max_health;
    game.player.health.maximum          += item_class::sub_max_health;
    game.player.mana.maximum            -= item_class::add_max_mana;
    game.player.mana.maximum            += item_class::sub_max_mana;
    game.player.health.regeneration     -= (float)item_class::add_health_regeneration/100.0f;
    game.player.health.regeneration     += (float)item_class::sub_health_regeneration/100.0f;
    game.player.mana.regeneration       -= (float)item_class::add_mana_regeneration/100.0f;
    game.player.mana.regeneration       += (float)item_class::sub_mana_regeneration/100.0f;
    game.player.critical_chance         -= item_class::add_crit_chance;
    game.player.critical_chance         += item_class::sub_crit_chance;
    game.player.walk_speed              -= item_class::add_walk_speed;
    game.player.walk_speed              += item_class::sub_walk_speed;
    game.player.light_radius            -= item_class::add_light_radius;
    game.player.light_radius            += item_class::sub_light_radius;
    game.player.resistance_flame        -= item_class::add_fire_resistance;
    game.player.resistance_frost        -= item_class::add_frost_resistance;
    game.player.resistance_lightning    -= item_class::add_lightning_resistance;
    game.player.resistance_flame        -= item_class::add_all_resistances;
    game.player.resistance_frost        -= item_class::add_all_resistances;
    game.player.resistance_lightning    -= item_class::add_all_resistances;
    game.player.damage_flame            -= item_class::add_fire_damage;
    game.player.damage_frost            -= item_class::add_frost_damage;
    game.player.damage_lightning        -= item_class::add_lightning_damage;
    game.player.damage_flame            -= item_class::add_magic_damage;
    game.player.damage_frost            -= item_class::add_magic_damage;
    game.player.damage_lightning        -= item_class::add_magic_damage;
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
                    if (temp_string_key == "armour")                  item_class::armour                  = temp_int_data;
                    if (temp_string_key == "add_armour")              item_class::add_armour              = temp_int_data;
                    if (temp_string_key == "sub_armour")              item_class::sub_armour              = temp_int_data;
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
                }
            }
        }
        script_file.close();
    }
};

int   generate_range(int level, int quality, int base_value)
{
    return(((level+quality)*1.5f)*base_value);
};

void  generate_random_item(int item_ID, int level, int quality, int type)
{
    int minimum_range   = (MAX_LEVEL - quality);
    int temp_range      = 0;
    int temp_value      = 0;
    int temp_random     = 0;
    int minimum_percent = 15;
    int maximum_percent = 50;
    if (type == WEAPON)
    {
        temp_range = random(5);
        if (temp_range <=  0) type = WAND;
        if (temp_range ==  1) type = SLING;
        if (temp_range ==  2) type = DAGGER;
        if (temp_range ==  3) type = BOW;
        if (temp_range >=  4) type = SWORD;
    }
    switch (type)
    {
        case HELM:
            game.item[item_ID].name              = "Random Helm";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = HELM;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(2);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.helm_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.helm_01.ref_number;
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value/2;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                /*
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                */
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
            }
        break;
        case BOOTS:
            game.item[item_ID].name              = "Random Boots";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = BOOTS;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(12);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.boots_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.boots_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.boots_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.boots_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.boots_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.boots_05.ref_number;
            if (temp_range ==  6) game.item[item_ID].image_ref = game.texture.boots_06.ref_number;
            if (temp_range ==  7) game.item[item_ID].image_ref = game.texture.boots_07.ref_number;
            if (temp_range ==  8) game.item[item_ID].image_ref = game.texture.boots_08.ref_number;
            if (temp_range ==  9) game.item[item_ID].image_ref = game.texture.boots_09.ref_number;
            if (temp_range == 10) game.item[item_ID].image_ref = game.texture.boots_10.ref_number;
            if (temp_range >= 11) game.item[item_ID].image_ref = game.texture.boots_11.ref_number;
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value/3;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                /*
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                */
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
            }
        break;
        case ARMOUR:
            game.item[item_ID].name              = "Random Armour";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = ARMOUR;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(9);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.armour_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.armour_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.armour_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.armour_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.armour_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.armour_05.ref_number;
            if (temp_range ==  6) game.item[item_ID].image_ref = game.texture.armour_06.ref_number;
            if (temp_range ==  7) game.item[item_ID].image_ref = game.texture.armour_07.ref_number;
            if (temp_range >=  8) game.item[item_ID].image_ref = game.texture.armour_08.ref_number;
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                /*
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                */
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
            }
        break;
        case SHIELD:
            game.item[item_ID].name              = "Random Shield";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = SHIELD;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(7);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.shield_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.shield_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.shield_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.shield_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.shield_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.shield_05.ref_number;
            if (temp_range >=  6) game.item[item_ID].image_ref = game.texture.shield_06.ref_number;
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                /*
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                */
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
            }
        break;
        case GLOVES:
            game.item[item_ID].name              = "Random Gloves";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = GLOVES;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value/2;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                /*
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
                */
            }
        break;
        case BELT:
            game.item[item_ID].name              = "Random Belt";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = BELT;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(1);
            if (temp_range >=  0) game.item[item_ID].image_ref = game.texture.belt_00.ref_number;
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value/4;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                /*
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                */
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
            }
        break;
        case RING:
            game.item[item_ID].name              = "Random Ring";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = RING;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(19);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.ring_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.ring_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.ring_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.ring_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.ring_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.ring_05.ref_number;
            if (temp_range ==  6) game.item[item_ID].image_ref = game.texture.ring_06.ref_number;
            if (temp_range ==  7) game.item[item_ID].image_ref = game.texture.ring_07.ref_number;
            if (temp_range ==  8) game.item[item_ID].image_ref = game.texture.ring_08.ref_number;
            if (temp_range ==  9) game.item[item_ID].image_ref = game.texture.ring_09.ref_number;
            if (temp_range == 10) game.item[item_ID].image_ref = game.texture.ring_10.ref_number;
            if (temp_range == 11) game.item[item_ID].image_ref = game.texture.ring_11.ref_number;
            if (temp_range == 12) game.item[item_ID].image_ref = game.texture.ring_12.ref_number;
            if (temp_range == 13) game.item[item_ID].image_ref = game.texture.ring_13.ref_number;
            if (temp_range == 14) game.item[item_ID].image_ref = game.texture.ring_14.ref_number;
            if (temp_range == 15) game.item[item_ID].image_ref = game.texture.ring_15.ref_number;
            if (temp_range == 16) game.item[item_ID].image_ref = game.texture.ring_16.ref_number;
            if (temp_range == 17) game.item[item_ID].image_ref = game.texture.ring_17.ref_number;
            if (temp_range >= 18) game.item[item_ID].image_ref = game.texture.ring_18.ref_number;
            /*
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value/4;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            */
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                /*
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                */
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
            }
        break;
        case AMULET:
            game.item[item_ID].name              = "Random Amulet";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = AMULET;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(14);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.amulet_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.amulet_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.amulet_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.amulet_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.amulet_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.amulet_05.ref_number;
            if (temp_range ==  6) game.item[item_ID].image_ref = game.texture.amulet_06.ref_number;
            if (temp_range ==  7) game.item[item_ID].image_ref = game.texture.amulet_07.ref_number;
            if (temp_range ==  8) game.item[item_ID].image_ref = game.texture.amulet_08.ref_number;
            if (temp_range ==  9) game.item[item_ID].image_ref = game.texture.amulet_09.ref_number;
            if (temp_range == 10) game.item[item_ID].image_ref = game.texture.amulet_10.ref_number;
            if (temp_range == 11) game.item[item_ID].image_ref = game.texture.amulet_11.ref_number;
            if (temp_range == 12) game.item[item_ID].image_ref = game.texture.amulet_12.ref_number;
            if (temp_range >= 13) game.item[item_ID].image_ref = game.texture.amulet_13.ref_number;
            /*
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value/4;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            */
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                /*
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                */
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
            }
        break;
        case WAND:
            game.item[item_ID].name              = "Random Wand";
            game.item[item_ID].active            = true;
            game.item[item_ID].type              = WAND;
            game.item[item_ID].stack_number      = 1;
            game.item[item_ID].max_stack_number  = 1;
            game.item[item_ID].ID                = item_ID;
            temp_range = random(21);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.wand_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.wand_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.wand_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.wand_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.wand_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.wand_05.ref_number;
            if (temp_range ==  6) game.item[item_ID].image_ref = game.texture.wand_06.ref_number;
            if (temp_range ==  7) game.item[item_ID].image_ref = game.texture.wand_07.ref_number;
            if (temp_range ==  8) game.item[item_ID].image_ref = game.texture.wand_08.ref_number;
            if (temp_range ==  9) game.item[item_ID].image_ref = game.texture.wand_09.ref_number;
            if (temp_range == 10) game.item[item_ID].image_ref = game.texture.wand_10.ref_number;
            if (temp_range == 11) game.item[item_ID].image_ref = game.texture.wand_11.ref_number;
            if (temp_range == 12) game.item[item_ID].image_ref = game.texture.wand_12.ref_number;
            if (temp_range == 13) game.item[item_ID].image_ref = game.texture.wand_13.ref_number;
            if (temp_range == 14) game.item[item_ID].image_ref = game.texture.wand_14.ref_number;
            if (temp_range == 15) game.item[item_ID].image_ref = game.texture.wand_15.ref_number;
            if (temp_range == 16) game.item[item_ID].image_ref = game.texture.wand_16.ref_number;
            if (temp_range == 17) game.item[item_ID].image_ref = game.texture.wand_17.ref_number;
            if (temp_range == 18) game.item[item_ID].image_ref = game.texture.wand_18.ref_number;
            if (temp_range == 19) game.item[item_ID].image_ref = game.texture.wand_19.ref_number;
            if (temp_range == 20) game.item[item_ID].image_ref = game.texture.wand_20.ref_number;
            /*
            temp_range = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].armour = temp_value/4;
            if (random(quality*10) <= 10) game.item[item_ID].add_armour = random((quality/10));
            if (random(quality*10) <=  1) game.item[item_ID].sub_armour = random((quality/10));
            game.item[item_ID].armour += game.item[item_ID].add_armour;
            game.item[item_ID].armour -= game.item[item_ID].sub_armour;
            */
            temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].max_damage = temp_value;
            temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
            temp_value = random_int(minimum_range,temp_range);
            game.item[item_ID].min_damage = temp_value/4;
            temp_value = quality*level;
            temp_random = random(100);
            if ((temp_random >=  0) && (temp_random < 25))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int(minimum_range,temp_range);
                game.item[item_ID].add_frost_damage = temp_value;
            }
            if ((temp_random >= 25) && (temp_random < 50))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int(minimum_range,temp_range);
                game.item[item_ID].add_fire_damage = temp_value;
            }
            if ((temp_random >= 50) && (temp_random < 75))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int(minimum_range,temp_range);
                game.item[item_ID].add_lightning_damage = temp_value;
            }
            if ((temp_random >= 75) && (temp_random < 100))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int(minimum_range,temp_range);
                game.item[item_ID].add_magic_damage = temp_value;
            }
            temp_value = quality*level;
            if (random(100) <= 80)
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_health          = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_health          = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_health_regeneration = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_health_regeneration = random((quality/10));
            }
            else
            {
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_max_mana            = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_max_mana            = random((quality/10));
                if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_mana_regeneration   = random((quality/10));
                else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_mana_regeneration   = random((quality/10));
            }
            if (random(100) <= 75)
            {
                temp_range = random(99);
                if (temp_range <= 33)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_crit_chance    = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_crit_chance    = random((quality/10));
                }
                /*
                if ((temp_range >= 33) && (temp_range <= 66))
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_walk_speed     = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_walk_speed     = random((quality/10));
                }
                if (temp_range >= 66)
                {
                    if      (random(temp_value) <= ((temp_value/100)*maximum_percent)) game.item[item_ID].add_light_radius   = random((quality/10));
                    else if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].sub_light_radius   = random((quality/10));
                }
                */
            }
        break;
        case SWORD:
        break;
        case DAGGER:
        break;
        case BOW:
        break;
        case SLING:
        break;
        default:
            game.item[item_ID].active = false;
        break;
    }
    //unique name generation based on randomly generated stats
};

void init_items(void)
{
// First 1000 items are reserved for permanent entities, 1000+ are for randomly generated items.
//-------------------------------- Skills / Spells / scrolls ---------------------------------------------------------
    game.item[101].name              = "Book of Chain Lightning";
    game.item[101].image_ref         = game.texture.book_15.ref_number;
    game.item[101].stack_number      = 1;
    game.item[101].max_stack_number  = 10;
    game.item[101].ID                = 101;
    game.item[101].type              = SPELL_BOOK;
    game.item[101].add_spell         = 1;
    game.item[101].spell_type        = 2;
    game.item[102].name              = "Book of Stalagmite";
    game.item[102].image_ref         = game.texture.book_19.ref_number;
    game.item[102].stack_number      = 1;
    game.item[102].max_stack_number  = 10;
    game.item[102].ID                = 102;
    game.item[102].type              = SPELL_BOOK;
    game.item[102].add_spell         = 1;
    game.item[102].spell_type        = 1;

//-------------------------------- Potions / gems / runes -----------------------------------------------------------
    game.item[201].name              = "Minuscule Health Potion";
    game.item[201].image_ref         = game.texture.potion_01.ref_number;
    game.item[201].stack_number      = 1;
    game.item[201].max_stack_number  = 20;
    game.item[201].ID                = 201;
    game.item[201].type              = HEALTH_POTION;
    game.item[201].add_health        = 5;
    game.item[202].name              = "Tiny Health Potion";
    game.item[202].image_ref         = game.texture.potion_02.ref_number;
    game.item[202].stack_number      = 1;
    game.item[202].max_stack_number  = 20;
    game.item[202].ID                = 202;
    game.item[202].type              = HEALTH_POTION;
    game.item[202].add_health        = 10;
    game.item[203].name              = "Small Health Potion";
    game.item[203].image_ref         = game.texture.potion_03.ref_number;
    game.item[203].stack_number      = 1;
    game.item[203].max_stack_number  = 20;
    game.item[203].ID                = 203;
    game.item[203].type              = HEALTH_POTION;
    game.item[203].add_health        = 20;
    game.item[204].name              = "Medium Health Potion";
    game.item[204].image_ref         = game.texture.potion_04.ref_number;
    game.item[204].stack_number      = 1;
    game.item[204].max_stack_number  = 20;
    game.item[204].ID                = 204;
    game.item[204].type              = HEALTH_POTION;
    game.item[204].add_health        = 40;
    game.item[205].name              = "Large Health Potion";
    game.item[205].image_ref         = game.texture.potion_05.ref_number;
    game.item[205].stack_number      = 1;
    game.item[205].max_stack_number  = 20;
    game.item[205].ID                = 205;
    game.item[205].type              = HEALTH_POTION;
    game.item[205].add_health        = 80;
    game.item[206].name              = "Huge Health Potion";
    game.item[206].image_ref         = game.texture.potion_06.ref_number;
    game.item[206].stack_number      = 1;
    game.item[206].max_stack_number  = 20;
    game.item[206].ID                = 206;
    game.item[206].type              = HEALTH_POTION;
    game.item[206].add_health        = 160;
    game.item[207].name              = "Gigantic Health Potion";
    game.item[207].image_ref         = game.texture.potion_07.ref_number;
    game.item[207].stack_number      = 1;
    game.item[207].max_stack_number  = 20;
    game.item[207].ID                = 207;
    game.item[207].type              = HEALTH_POTION;
    game.item[207].add_health        = 320;

    game.item[208].name              = "Minuscule Mana Potion";
    game.item[208].image_ref         = game.texture.potion_08.ref_number;
    game.item[208].stack_number      = 1;
    game.item[208].max_stack_number  = 20;
    game.item[208].ID                = 208;
    game.item[208].type              = MANA_POTION;
    game.item[208].add_mana          = 5;
    game.item[209].name              = "Tiny Mana Potion";
    game.item[209].image_ref         = game.texture.potion_09.ref_number;
    game.item[209].stack_number      = 1;
    game.item[209].max_stack_number  = 20;
    game.item[209].ID                = 209;
    game.item[209].type              = MANA_POTION;
    game.item[209].add_mana          = 10;
    game.item[210].name              = "Small Mana Potion";
    game.item[210].image_ref         = game.texture.potion_10.ref_number;
    game.item[210].stack_number      = 1;
    game.item[210].max_stack_number  = 20;
    game.item[210].ID                = 210;
    game.item[210].type              = MANA_POTION;
    game.item[210].add_mana          = 20;
    game.item[211].name              = "Medium Mana Potion";
    game.item[211].image_ref         = game.texture.potion_11.ref_number;
    game.item[211].stack_number      = 1;
    game.item[211].max_stack_number  = 20;
    game.item[211].ID                = 211;
    game.item[211].type              = MANA_POTION;
    game.item[211].add_mana          = 40;
    game.item[212].name              = "Large Mana Potion";
    game.item[212].image_ref         = game.texture.potion_12.ref_number;
    game.item[212].stack_number      = 1;
    game.item[212].max_stack_number  = 20;
    game.item[212].ID                = 212;
    game.item[212].type              = MANA_POTION;
    game.item[212].add_mana          = 80;
    game.item[213].name              = "Huge Mana Potion";
    game.item[213].image_ref         = game.texture.potion_13.ref_number;
    game.item[213].stack_number      = 1;
    game.item[213].max_stack_number  = 20;
    game.item[213].ID                = 213;
    game.item[213].type              = MANA_POTION;
    game.item[213].add_mana          = 160;
    game.item[214].name              = "Gigantic Mana Potion";
    game.item[214].image_ref         = game.texture.potion_14.ref_number;
    game.item[214].stack_number      = 1;
    game.item[214].max_stack_number  = 20;
    game.item[214].ID                = 214;
    game.item[214].type              = MANA_POTION;
    game.item[214].add_mana          = 320;

//-------------------------------- Boots / gloves / belts -----------------------------------------------------------
    game.item[301].name              = "Boots of Haste";
    game.item[301].image_ref         = game.texture.boots_09.ref_number;
    game.item[301].stack_number      = 1;
    game.item[301].max_stack_number  = 1;
    game.item[301].ID                = 301;
    game.item[301].type              = BOOTS;
    game.item[301].armour            = 4;
    game.item[302].name              = "Boots of Flame walk";
    game.item[302].image_ref         = game.texture.boots_06.ref_number;
    game.item[302].stack_number      = 1;
    game.item[302].max_stack_number  = 1;
    game.item[302].ID                = 302;
    game.item[302].type              = BOOTS;
    game.item[302].armour            = 2;

    game.item[303].name              = "Belt of Energy";
    game.item[303].image_ref         = game.texture.belt_00.ref_number;
    game.item[303].stack_number      = 1;
    game.item[303].max_stack_number  = 1;
    game.item[303].ID                = 303;
    game.item[303].type              = BELT;
    game.item[303].armour            = 2;
    game.item[303].add_max_mana      = 32;

//-------------------------------- Armour / helms --------------------------------------------------------------------
    game.item[401].name              = "Plate Armour";
    game.item[401].image_ref         = game.texture.armour_00.ref_number;
    game.item[401].stack_number      = 1;
    game.item[401].max_stack_number  = 1;
    game.item[401].ID                = 401;
    game.item[401].type              = ARMOUR;
    game.item[401].armour            = 10;

    game.item[402].name              = "Strong Helm";
    game.item[402].image_ref         = game.texture.helm_00.ref_number;
    game.item[402].stack_number      = 1;
    game.item[402].max_stack_number  = 1;
    game.item[402].ID                = 402;
    game.item[402].type              = HELM;
    game.item[402].armour            = 34;
    game.item[403].name              = "Hard Helm";
    game.item[403].image_ref         = game.texture.helm_01.ref_number;
    game.item[403].stack_number      = 1;
    game.item[403].max_stack_number  = 1;
    game.item[403].ID                = 403;
    game.item[403].type              = HELM;
    game.item[403].armour            = 65;

//-------------------------------- Bows / slings -------------------------------------------------------------------
    game.item[501].name              = "Heroic Bow";
    game.item[501].image_ref         = game.texture.bow_00.ref_number;
    game.item[501].stack_number      = 1;
    game.item[501].max_stack_number  = 1;
    game.item[501].ID                = 501;
    game.item[501].type              = BOW;
    game.item[501].min_damage        = 6;
    game.item[501].max_damage        = 12;

    game.item[502].name              = "Heroic Sling";
    game.item[502].image_ref         = game.texture.sling_00.ref_number;
    game.item[502].stack_number      = 1;
    game.item[502].max_stack_number  = 1;
    game.item[502].ID                = 502;
    game.item[502].type              = SLING;
    game.item[502].min_damage        = 6;
    game.item[502].max_damage        = 12;

//-------------------------------- Daggers / Swords -------------------------------------------------------------------
    game.item[601].name              = "Frost Dagger";
    game.item[601].image_ref         = game.texture.dagger_00.ref_number;
    game.item[601].stack_number      = 1;
    game.item[601].max_stack_number  = 1;
    game.item[601].ID                = 601;
    game.item[601].type              = DAGGER;
    game.item[601].min_damage        = 6;
    game.item[601].max_damage        = 12;
    game.item[602].name              = "Magic Sword";
    game.item[602].image_ref         = game.texture.sword_00.ref_number;
    game.item[602].stack_number      = 1;
    game.item[602].max_stack_number  = 1;
    game.item[602].ID                = 602;
    game.item[602].type              = SWORD;
    game.item[602].min_damage        = 12;
    game.item[602].max_damage        = 24;

//-------------------------------- Rings / Amulets ------------------------------------------------------------------
    game.item[701].name              = "Ice Ring";
    game.item[701].image_ref         = game.texture.ring_00.ref_number;
    game.item[701].stack_number      = 1;
    game.item[701].max_stack_number  = 1;
    game.item[701].ID                = 701;
    game.item[701].type              = RING;
    game.item[701].min_damage        = 6;
    game.item[701].max_damage        = 12;
    game.item[702].name              = "Frost Ring";
    game.item[702].image_ref         = game.texture.ring_14.ref_number;
    game.item[702].stack_number      = 1;
    game.item[702].max_stack_number  = 1;
    game.item[702].ID                = 702;
    game.item[702].type              = RING;
    game.item[702].min_damage        = 6;
    game.item[702].max_damage        = 12;
    game.item[703].name              = "Fire Ring";
    game.item[703].image_ref         = game.texture.ring_12.ref_number;
    game.item[703].stack_number      = 1;
    game.item[703].max_stack_number  = 1;
    game.item[703].ID                = 703;
    game.item[703].type              = RING;
    game.item[703].min_damage        = 6;
    game.item[703].max_damage        = 12;

    game.item[704].name              = "Silver Amulet";
    game.item[704].image_ref         = game.texture.amulet_00.ref_number;
    game.item[704].stack_number      = 1;
    game.item[704].max_stack_number  = 1;
    game.item[704].ID                = 704;
    game.item[704].type              = AMULET;
    game.item[704].min_damage        = 6;
    game.item[704].max_damage        = 12;
    game.item[705].name              = "Ruby Amulet";
    game.item[705].image_ref         = game.texture.amulet_01.ref_number;
    game.item[705].stack_number      = 1;
    game.item[705].max_stack_number  = 1;
    game.item[705].ID                = 705;
    game.item[705].type              = AMULET;
    game.item[705].min_damage        = 6;
    game.item[705].max_damage        = 12;

//-------------------------------- Shields ----------------------------------------------------------------------------
    game.item[801].name              = "Golden Shield";
    game.item[801].image_ref         = game.texture.shield_00.ref_number;
    game.item[801].stack_number      = 1;
    game.item[801].max_stack_number  = 1;
    game.item[801].ID                = 801;
    game.item[801].type              = SHIELD;
    game.item[801].armour            = 16;
    game.item[802].name              = "Silver Shield";
    game.item[802].image_ref         = game.texture.shield_01.ref_number;
    game.item[802].stack_number      = 1;
    game.item[802].max_stack_number  = 1;
    game.item[802].ID                = 802;
    game.item[802].type              = SHIELD;
    game.item[802].armour            = 12;

//-------------------------------- Wands ------------------------------------------------------------------------------
    game.item[901].name              = "Lightning Wand";
    game.item[901].image_ref         = game.texture.wand_05.ref_number;
    game.item[901].stack_number      = 1;
    game.item[901].max_stack_number  = 1;
    game.item[901].ID                = 901;
    game.item[901].type              = WAND;
    game.item[901].min_damage        = 6;
    game.item[901].max_damage        = 12;

//---------------------------------------------------------------------------------------------------------------------
//----------------------------------------- Generate some random items ------------------------------------------------
//this will be done in game on loot drop

    generate_random_item(1000,100,100,BOOTS);
    generate_random_item(1001,100,100,ARMOUR);
    generate_random_item(1002,100,100,SHIELD);
    generate_random_item(1003,100,100,HELM);
    generate_random_item(1004,100,100,BELT);
    generate_random_item(1005,100,100,RING);
    generate_random_item(1006,100,100,AMULET);
    generate_random_item(1007,100,100,WAND);

};






