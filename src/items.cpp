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
    for (int item_sound_use_count = 0; item_sound_use_count < item_class::sound.quantity_use; item_sound_use_count++)
    {
        item_class::sound.use[item_sound_use_count] = 0;
    }
    for (int item_sound_relocate_count = 0; item_sound_relocate_count < item_class::sound.quantity_relocate; item_sound_relocate_count++)
    {
        item_class::sound.relocate[item_sound_relocate_count] = 0;
    }
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
    item_class::add_flame_damage         = 0;
    item_class::add_frost_damage         = 0;
    item_class::add_lightning_damage     = 0;
    item_class::add_magic_damage         = 0;
    item_class::add_flame_resistance     = 0;
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
    game.player.damage_physical_minimum += item_class::min_damage;
    game.player.damage_physical_maximum += item_class::max_damage;
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
    game.player.resistance_flame        += item_class::add_flame_resistance;
    game.player.resistance_frost        += item_class::add_frost_resistance;
    game.player.resistance_lightning    += item_class::add_lightning_resistance;
    game.player.resistance_flame        += item_class::add_all_resistances;
    game.player.resistance_frost        += item_class::add_all_resistances;
    game.player.resistance_lightning    += item_class::add_all_resistances;
    game.player.damage_flame            += item_class::add_flame_damage;
    game.player.damage_frost            += item_class::add_frost_damage;
    game.player.damage_lightning        += item_class::add_lightning_damage;
    game.player.damage_flame            += item_class::add_magic_damage;
    game.player.damage_frost            += item_class::add_magic_damage;
    game.player.damage_lightning        += item_class::add_magic_damage;
};

void item_class::unequip(void)
{
    game.player.armor                   -= item_class::armour;
    game.player.damage_physical_minimum -= item_class::min_damage;
    game.player.damage_physical_maximum -= item_class::max_damage;
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
    game.player.resistance_flame        -= item_class::add_flame_resistance;
    game.player.resistance_frost        -= item_class::add_frost_resistance;
    game.player.resistance_lightning    -= item_class::add_lightning_resistance;
    game.player.resistance_flame        -= item_class::add_all_resistances;
    game.player.resistance_frost        -= item_class::add_all_resistances;
    game.player.resistance_lightning    -= item_class::add_all_resistances;
    game.player.damage_flame            -= item_class::add_flame_damage;
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
    int minimum_range   = (MAX_LEVELS - quality);
    int temp_range      = 0;
    int temp_value      = 0;
    int temp_random     = 0;
    int minimum_percent = 15;
    int maximum_percent = 50;
    int chance_for_stat = 80;
    if (type == WEAPON)
    {
        temp_range = random(5);
        if (temp_range <=  0) type = WAND;
        if (temp_range ==  1) type = SLING;
        if (temp_range ==  2) type = DAGGER;
        if (temp_range ==  3) type = BOW;
        if (temp_range >=  4) type = SWORD;
    }
    game.item[item_ID].active            = true;
    game.item[item_ID].type              = type;
    game.item[item_ID].stack_number      = 1;
    game.item[item_ID].max_stack_number  = 1;
    game.item[item_ID].ID                = item_ID;
//---------------------------------------------------- Random image usage ------------------------------------------------
    switch (type)
    {
        case HELM:
            temp_range = random(2);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.helm_00.ref_number;
            if (temp_range >=  1) game.item[item_ID].image_ref = game.texture.helm_01.ref_number;
        break;
        case BOOTS:
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
        break;
        case ARMOUR:
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
        break;
        case SHIELD:
            temp_range = random(7);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.shield_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.shield_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.shield_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.shield_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.shield_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.shield_05.ref_number;
            if (temp_range >=  6) game.item[item_ID].image_ref = game.texture.shield_06.ref_number;
        break;
        case GLOVES:
        break;
        case BELT:
            temp_range = random(1);
            if (temp_range >=  0) game.item[item_ID].image_ref = game.texture.belt_00.ref_number;
        break;
        case RING:
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
        break;
        case AMULET:
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
        break;
        case WAND:
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
            if (temp_range >= 20) game.item[item_ID].image_ref = game.texture.wand_20.ref_number;
        break;
        case SWORD:
            temp_range = random(28);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.sword_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.sword_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.sword_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.sword_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.sword_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.sword_05.ref_number;
            if (temp_range ==  6) game.item[item_ID].image_ref = game.texture.sword_06.ref_number;
            if (temp_range ==  7) game.item[item_ID].image_ref = game.texture.sword_07.ref_number;
            if (temp_range ==  8) game.item[item_ID].image_ref = game.texture.sword_08.ref_number;
            if (temp_range ==  9) game.item[item_ID].image_ref = game.texture.sword_09.ref_number;
            if (temp_range == 10) game.item[item_ID].image_ref = game.texture.sword_10.ref_number;
            if (temp_range == 11) game.item[item_ID].image_ref = game.texture.sword_11.ref_number;
            if (temp_range == 12) game.item[item_ID].image_ref = game.texture.sword_12.ref_number;
            if (temp_range == 13) game.item[item_ID].image_ref = game.texture.sword_13.ref_number;
            if (temp_range == 14) game.item[item_ID].image_ref = game.texture.sword_14.ref_number;
            if (temp_range == 15) game.item[item_ID].image_ref = game.texture.sword_15.ref_number;
            if (temp_range == 16) game.item[item_ID].image_ref = game.texture.sword_16.ref_number;
            if (temp_range == 17) game.item[item_ID].image_ref = game.texture.sword_17.ref_number;
            if (temp_range == 18) game.item[item_ID].image_ref = game.texture.sword_18.ref_number;
            if (temp_range == 19) game.item[item_ID].image_ref = game.texture.sword_19.ref_number;
            if (temp_range == 20) game.item[item_ID].image_ref = game.texture.sword_20.ref_number;
            if (temp_range == 21) game.item[item_ID].image_ref = game.texture.sword_21.ref_number;
            if (temp_range == 22) game.item[item_ID].image_ref = game.texture.sword_22.ref_number;
            if (temp_range == 23) game.item[item_ID].image_ref = game.texture.sword_23.ref_number;
            if (temp_range == 24) game.item[item_ID].image_ref = game.texture.sword_24.ref_number;
            if (temp_range == 25) game.item[item_ID].image_ref = game.texture.sword_25.ref_number;
            if (temp_range == 26) game.item[item_ID].image_ref = game.texture.sword_26.ref_number;
            if (temp_range >= 27) game.item[item_ID].image_ref = game.texture.sword_27.ref_number;
        break;
        case DAGGER:
            temp_range = random(28);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.dagger_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.dagger_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.dagger_02.ref_number;
            if (temp_range ==  3) game.item[item_ID].image_ref = game.texture.dagger_03.ref_number;
            if (temp_range ==  4) game.item[item_ID].image_ref = game.texture.dagger_04.ref_number;
            if (temp_range ==  5) game.item[item_ID].image_ref = game.texture.dagger_05.ref_number;
            if (temp_range ==  6) game.item[item_ID].image_ref = game.texture.dagger_06.ref_number;
            if (temp_range ==  7) game.item[item_ID].image_ref = game.texture.dagger_07.ref_number;
            if (temp_range ==  8) game.item[item_ID].image_ref = game.texture.dagger_08.ref_number;
            if (temp_range ==  9) game.item[item_ID].image_ref = game.texture.dagger_09.ref_number;
            if (temp_range == 10) game.item[item_ID].image_ref = game.texture.dagger_10.ref_number;
            if (temp_range == 11) game.item[item_ID].image_ref = game.texture.dagger_11.ref_number;
            if (temp_range == 12) game.item[item_ID].image_ref = game.texture.dagger_12.ref_number;
            if (temp_range == 13) game.item[item_ID].image_ref = game.texture.dagger_13.ref_number;
            if (temp_range == 14) game.item[item_ID].image_ref = game.texture.dagger_14.ref_number;
            if (temp_range == 15) game.item[item_ID].image_ref = game.texture.dagger_15.ref_number;
            if (temp_range == 16) game.item[item_ID].image_ref = game.texture.dagger_16.ref_number;
            if (temp_range == 17) game.item[item_ID].image_ref = game.texture.dagger_17.ref_number;
            if (temp_range == 18) game.item[item_ID].image_ref = game.texture.dagger_18.ref_number;
            if (temp_range == 19) game.item[item_ID].image_ref = game.texture.dagger_19.ref_number;
            if (temp_range == 20) game.item[item_ID].image_ref = game.texture.dagger_20.ref_number;
            if (temp_range == 21) game.item[item_ID].image_ref = game.texture.dagger_21.ref_number;
            if (temp_range == 22) game.item[item_ID].image_ref = game.texture.dagger_22.ref_number;
            if (temp_range == 23) game.item[item_ID].image_ref = game.texture.dagger_23.ref_number;
            if (temp_range == 24) game.item[item_ID].image_ref = game.texture.dagger_24.ref_number;
            if (temp_range == 25) game.item[item_ID].image_ref = game.texture.dagger_25.ref_number;
            if (temp_range == 26) game.item[item_ID].image_ref = game.texture.dagger_26.ref_number;
            if (temp_range >= 27) game.item[item_ID].image_ref = game.texture.dagger_27.ref_number;
        break;
        case BOW:
            temp_range = random(3);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.bow_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.bow_01.ref_number;
            if (temp_range >=  2) game.item[item_ID].image_ref = game.texture.bow_02.ref_number;
        break;
        case SLING:
            temp_range = random(4);
            if (temp_range ==  0) game.item[item_ID].image_ref = game.texture.sling_00.ref_number;
            if (temp_range ==  1) game.item[item_ID].image_ref = game.texture.sling_01.ref_number;
            if (temp_range ==  2) game.item[item_ID].image_ref = game.texture.sling_02.ref_number;
            if (temp_range >=  3) game.item[item_ID].image_ref = game.texture.sling_03.ref_number;
        break;
        default:
        break;
    }
//---------------------------------------------------- Randomly generate all stats ---------------------------------------
    float temp_armour                   = 0;
    float temp_add_armour               = 0;
    float temp_sub_armour               = 0;
    float temp_add_max_health           = 0;
    float temp_add_health_regeneration  = 0;
    float temp_sub_max_health           = 0;
    float temp_sub_health_regeneration  = 0;
    float temp_add_max_mana             = 0;
    float temp_add_mana_regeneration    = 0;
    float temp_sub_max_mana             = 0;
    float temp_sub_mana_regeneration    = 0;
    float temp_add_crit_chance          = 0;
    float temp_sub_crit_chance          = 0;
    float temp_add_walk_speed           = 0;
    float temp_sub_walk_speed           = 0;
    float temp_add_light_radius         = 0;
    float temp_sub_light_radius         = 0;
    float temp_max_damage               = 0;
    float temp_min_damage               = 0;
    float temp_add_frost_damage         = 0;
    float temp_add_flame_damage         = 0;
    float temp_add_lightning_damage     = 0;
    float temp_add_magic_damage         = 0;
    float temp_add_frost_resistance     = 0;
    float temp_add_flame_resistance     = 0;
    float temp_add_lightning_resistance = 0;
    float temp_add_all_resistances      = 0;

    //------ Armour ------
    temp_range  = generate_range(level,quality,ARMOUR_BASE_MULTIPLIER);
    temp_value  = random_int((int)minimum_range,(int)temp_range);
    temp_armour = temp_value;
    if (random(quality*10) <= 10) temp_add_armour = random((quality/10));
    if (random(quality*10) <=  1) temp_sub_armour = random((quality/10));
    if (temp_add_armour < 0) temp_add_armour = 0;
    if (temp_sub_armour < 0) temp_sub_armour = 0;
    if (temp_add_armour > temp_sub_armour)
    {
        temp_add_armour -= temp_sub_armour;
        temp_sub_armour = 0;
    }
    if (temp_sub_armour > temp_add_armour)
    {
        temp_sub_armour -= temp_add_armour;
        temp_add_armour = 0;
    }
    temp_armour += temp_add_armour;
    temp_armour -= temp_sub_armour;
    //------ Health ------
    temp_value = quality*level;
    if (random(100) <= chance_for_stat)
    {
        if (random(100) <= chance_for_stat/2)
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent)) temp_sub_max_health          = random((quality/10));
            if (random(temp_value) <= ((temp_value/100)*minimum_percent)) temp_sub_health_regeneration = random((quality/10));
        }
        else
        {
            if (random(temp_value) <= ((temp_value/100)*maximum_percent)) temp_add_max_health          = random((quality/10));
            if (random(temp_value) <= ((temp_value/100)*maximum_percent)) temp_add_health_regeneration = random((quality/10));
        }
    }
    //------ Mana ------
    temp_value = quality*level;
    if (random(100) <= chance_for_stat)
    {
        if (random(100) <= chance_for_stat/2)
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent)) temp_sub_max_mana          = random((quality/10));
            if (random(temp_value) <= ((temp_value/100)*minimum_percent)) temp_sub_mana_regeneration = random((quality/10));
        }
        else
        {
            if (random(temp_value) <= ((temp_value/100)*maximum_percent)) temp_add_max_mana          = random((quality/10));
            if (random(temp_value) <= ((temp_value/100)*maximum_percent)) temp_add_mana_regeneration = random((quality/10));
        }
    }
    //------ Critical chance ------
    temp_value = quality*level;
    if (random(100) <= chance_for_stat)
    {
        if (random(100) <= chance_for_stat/2)
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent)) temp_sub_crit_chance    = random((quality/10));
        }
        else
        {
            if (random(temp_value) <= ((temp_value/100)*maximum_percent)) temp_add_crit_chance    = random((quality/10));
        }
    }
    //------ Walk Speed ------
    temp_value = quality*level;
    if (random(100) <= chance_for_stat)
    {
        if (random(100) <= chance_for_stat/2)
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent)) temp_sub_walk_speed    = random((quality/10));
        }
        else
        {
            if (random(temp_value) <= ((temp_value/100)*maximum_percent)) temp_add_walk_speed    = random((quality/10));
        }
    }
    //------ Light radius ------
    temp_value = quality*level;
    if (random(100) <= chance_for_stat)
    {
        if (random(100) <= chance_for_stat/2)
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent)) temp_sub_light_radius    = random((quality/10));
        }
        else
        {
            if (random(temp_value) <= ((temp_value/100)*maximum_percent)) temp_add_light_radius    = random((quality/10));
        }
    }
    //------ Physical Damage ------

    temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
    temp_value = random_int((int)minimum_range,(int)temp_range);
    temp_max_damage = temp_value;

    temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
    temp_value = random_int((int)minimum_range,(int)temp_max_damage);
    temp_min_damage = temp_value;

    //------ Magic Damage ------

    temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
    temp_value = random_int((int)minimum_range,(int)temp_range);
    temp_add_frost_damage = temp_value;

    temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
    temp_value = random_int((int)minimum_range,(int)temp_range);
    temp_add_flame_damage = temp_value;

    temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
    temp_value = random_int((int)minimum_range,(int)temp_range);
    temp_add_lightning_damage = temp_value;

    temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
    temp_value = random_int((int)minimum_range,(int)temp_range);
    temp_add_magic_damage = temp_value;

    //------ Magic Resistance ------
    temp_value = quality*level;
    if (random(100) <= chance_for_stat)
    {
        if (random(100) <= chance_for_stat/2)
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int((int)minimum_range,(int)temp_range);
                temp_add_frost_resistance = temp_value;
            }
        }
        else
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int((int)minimum_range,(int)temp_range);
                temp_add_flame_resistance = temp_value;
            }
        }
        if (random(100) <= chance_for_stat/2)
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int((int)minimum_range,(int)temp_range);
                temp_add_all_resistances = temp_value;
            }
        }
        else
        {
            if (random(temp_value) <= ((temp_value/100)*minimum_percent))
            {
                temp_range = generate_range(level,quality,DAMAGE_BASE_MULTIPLIER);
                temp_value = random_int((int)minimum_range,(int)temp_range);
                temp_add_lightning_resistance = temp_value;
            }
        }
    }

//---------------------------------------------------- Apply stats to items if correct type ------------------------------
    switch (type)
    {
        case HELM://-------------------------------- Helm ----------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            game.item[item_ID].armour                   = temp_armour/2;
            game.item[item_ID].add_armour               = temp_add_armour/2;
            game.item[item_ID].sub_armour               = temp_sub_armour/2;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            game.item[item_ID].add_light_radius         = temp_add_light_radius;
            game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance/2;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance/2;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance/2;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances/2;
        break;
        case BOOTS://-------------------------------- Boots --------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            game.item[item_ID].armour                   = temp_armour/4;
            game.item[item_ID].add_armour               = temp_add_armour/4;
            game.item[item_ID].sub_armour               = temp_sub_armour/4;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance/4;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance/4;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance/4;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances/4;
        break;
        case ARMOUR://-------------------------------- Armour ------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            game.item[item_ID].armour                   = temp_armour;
            game.item[item_ID].add_armour               = temp_add_armour;
            game.item[item_ID].sub_armour               = temp_sub_armour;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            game.item[item_ID].add_light_radius         = temp_add_light_radius;
            game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
        break;
        case SHIELD://-------------------------------- Shield ------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            game.item[item_ID].armour                   = temp_armour;
            game.item[item_ID].add_armour               = temp_add_armour;
            game.item[item_ID].sub_armour               = temp_sub_armour;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
        break;
        case GLOVES://-------------------------------- Gloves ------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            game.item[item_ID].armour                   = temp_armour/4;
            game.item[item_ID].add_armour               = temp_add_armour/4;
            game.item[item_ID].sub_armour               = temp_sub_armour/4;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance/4;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance/4;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance/4;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances/4;
        break;
        case BELT://-------------------------------- Belt ----------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            game.item[item_ID].armour                   = temp_armour/8;
            game.item[item_ID].add_armour               = temp_add_armour/8;
            game.item[item_ID].sub_armour               = temp_sub_armour/8;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            //game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            //game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            //game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            //game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
        break;
        case RING://-------------------------------- Ring ----------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            //game.item[item_ID].armour                   = temp_armour;
            //game.item[item_ID].add_armour               = temp_add_armour;
            //game.item[item_ID].sub_armour               = temp_sub_armour;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
        break;
        case AMULET://-------------------------------- Amulet ------------------------------------------------------------
            //game.item[item_ID].max_damage               = temp_max_damage;
            //game.item[item_ID].min_damage               = temp_min_damage;
            //game.item[item_ID].armour                   = temp_armour;
            //game.item[item_ID].add_armour               = temp_add_armour;
            //game.item[item_ID].sub_armour               = temp_sub_armour;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
        break;
        case WAND://-------------------------------- Wand ----------------------------------------------------------------
            game.item[item_ID].max_damage               = temp_max_damage/4;
            game.item[item_ID].min_damage               = temp_min_damage/4;
            //game.item[item_ID].armour                   = temp_armour;
            //game.item[item_ID].add_armour               = temp_add_armour;
            //game.item[item_ID].sub_armour               = temp_sub_armour;
            game.item[item_ID].add_max_health           = temp_add_max_health;
            game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            game.item[item_ID].sub_max_health           = temp_sub_max_health;
            game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            game.item[item_ID].add_max_mana             = temp_add_max_mana;
            game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            game.item[item_ID].add_light_radius         = temp_add_light_radius;
            game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
            temp_random = random(100);
            if  (temp_random <  25)                        game.item[item_ID].add_frost_damage     = temp_add_frost_damage;
            if ((temp_random >= 25) && (temp_random < 50)) game.item[item_ID].add_flame_damage     = temp_add_flame_damage;
            if ((temp_random >= 50) && (temp_random < 75)) game.item[item_ID].add_lightning_damage = temp_add_lightning_damage;
            if  (temp_random >=  75)                       game.item[item_ID].add_magic_damage     = temp_add_magic_damage;
        break;
        case SWORD://-------------------------------- Sword --------------------------------------------------------------
            game.item[item_ID].max_damage               = temp_max_damage;
            game.item[item_ID].min_damage               = temp_min_damage;
            //game.item[item_ID].armour                   = temp_armour;
            //game.item[item_ID].add_armour               = temp_add_armour;
            //game.item[item_ID].sub_armour               = temp_sub_armour;
            //game.item[item_ID].add_max_health           = temp_add_max_health;
            //game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            //game.item[item_ID].sub_max_health           = temp_sub_max_health;
            //game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            //game.item[item_ID].add_max_mana             = temp_add_max_mana;
            //game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            //game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            //game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            game.item[item_ID].add_light_radius         = temp_add_light_radius;
            game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            //game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            //game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            //game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            //game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
            temp_value = quality*level;
            if (random(100) <= chance_for_stat)
            {
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_frost_damage     = temp_add_frost_damage;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_flame_damage     = temp_add_flame_damage;
                }
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_lightning_damage = temp_add_lightning_damage;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_magic_damage     = temp_add_magic_damage;
                }
            }
        break;
        case DAGGER://-------------------------------- Dagger ------------------------------------------------------------
            game.item[item_ID].max_damage               = temp_max_damage;
            game.item[item_ID].min_damage               = temp_min_damage;
            //game.item[item_ID].armour                   = temp_armour;
            //game.item[item_ID].add_armour               = temp_add_armour;
            //game.item[item_ID].sub_armour               = temp_sub_armour;
            //game.item[item_ID].add_max_health           = temp_add_max_health;
            //game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            //game.item[item_ID].sub_max_health           = temp_sub_max_health;
            //game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            //game.item[item_ID].add_max_mana             = temp_add_max_mana;
            //game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            //game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            //game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            //game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            //game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            //game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            //game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
            temp_value = quality*level;
            if (random(100) <= chance_for_stat)
            {
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_frost_damage     = temp_add_frost_damage;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_flame_damage     = temp_add_flame_damage;
                }
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_lightning_damage = temp_add_lightning_damage;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_magic_damage     = temp_add_magic_damage;
                }
            }
        break;
        case BOW://-------------------------------- Bow ------------------------------------------------------------------
            game.item[item_ID].max_damage               = temp_max_damage;
            game.item[item_ID].min_damage               = temp_min_damage;
            //game.item[item_ID].armour                   = temp_armour;
            //game.item[item_ID].add_armour               = temp_add_armour;
            //game.item[item_ID].sub_armour               = temp_sub_armour;
            //game.item[item_ID].add_max_health           = temp_add_max_health;
            //game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            //game.item[item_ID].sub_max_health           = temp_sub_max_health;
            //game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            //game.item[item_ID].add_max_mana             = temp_add_max_mana;
            //game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            //game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            //game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            //game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            //game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            //game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            //game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
            temp_value = quality*level;
            if (random(100) <= chance_for_stat)
            {
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_frost_damage     = temp_add_frost_damage;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_flame_damage     = temp_add_flame_damage;
                }
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_lightning_damage = temp_add_lightning_damage;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_magic_damage     = temp_add_magic_damage;
                }
            }
        break;
        case SLING://-------------------------------- Sling --------------------------------------------------------------
            game.item[item_ID].max_damage               = temp_max_damage/2;
            game.item[item_ID].min_damage               = temp_min_damage/2;
            //game.item[item_ID].armour                   = temp_armour;
            //game.item[item_ID].add_armour               = temp_add_armour;
            //game.item[item_ID].sub_armour               = temp_sub_armour;
            //game.item[item_ID].add_max_health           = temp_add_max_health;
            //game.item[item_ID].add_health_regeneration  = temp_add_health_regeneration;
            //game.item[item_ID].sub_max_health           = temp_sub_max_health;
            //game.item[item_ID].sub_health_regeneration  = temp_sub_health_regeneration;
            //game.item[item_ID].add_max_mana             = temp_add_max_mana;
            //game.item[item_ID].add_mana_regeneration    = temp_add_mana_regeneration;
            //game.item[item_ID].sub_max_mana             = temp_sub_max_mana;
            //game.item[item_ID].sub_mana_regeneration    = temp_sub_mana_regeneration;
            //game.item[item_ID].add_crit_chance          = temp_add_crit_chance;
            //game.item[item_ID].sub_crit_chance          = temp_sub_crit_chance;
            //game.item[item_ID].add_walk_speed           = temp_add_walk_speed;
            //game.item[item_ID].sub_walk_speed           = temp_sub_walk_speed;
            //game.item[item_ID].add_light_radius         = temp_add_light_radius;
            //game.item[item_ID].sub_light_radius         = temp_sub_light_radius;
            //game.item[item_ID].add_frost_damage         = temp_add_frost_damage;
            //game.item[item_ID].add_flame_damage         = temp_add_flame_damage;
            //game.item[item_ID].add_lightning_damage     = temp_add_lightning_damage;
            //game.item[item_ID].add_magic_damage         = temp_add_magic_damage;
            //game.item[item_ID].add_frost_resistance     = temp_add_frost_resistance;
            //game.item[item_ID].add_flame_resistance     = temp_add_flame_resistance;
            //game.item[item_ID].add_lightning_resistance = temp_add_lightning_resistance;
            //game.item[item_ID].add_all_resistances      = temp_add_all_resistances;
            temp_value = quality*level;
            if (random(100) <= chance_for_stat)
            {
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_frost_damage     = temp_add_frost_damage/2;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_flame_damage     = temp_add_flame_damage/2;
                }
                if (random(100) <= chance_for_stat/2)
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_lightning_damage = temp_add_lightning_damage/2;
                }
                else
                {
                    if (random(temp_value) <= ((temp_value/100)*minimum_percent)) game.item[item_ID].add_magic_damage     = temp_add_magic_damage/2;
                }
            }
        break;
        default://-------------------------------- Default ---------------------------------------------------------------
            game.item[item_ID].active = false;
        break;
    }
//------------------------------ unique name generation based on randomly generated stats -------------------------------
    std::string temp_name_prefix = "Random";
    std::string temp_name_type   = "item";
    std::string temp_name_suffix = "of randomness";

    temp_random = (quality+level)/2;
    if  (temp_random <   5)                         temp_name_prefix = "Discarded";
    if ((temp_random >=  5) && (temp_random <= 10)) temp_name_prefix = "Damaged";
    if ((temp_random >= 10) && (temp_random <= 25)) temp_name_prefix = "Average";
    if ((temp_random >= 25) && (temp_random <= 40)) temp_name_prefix = "Awesome";
    if ((temp_random >= 40) && (temp_random <= 50)) temp_name_prefix = "Superb";
    if ((temp_random >= 50) && (temp_random <= 60)) temp_name_prefix = "Excellent";
    if ((temp_random >= 60) && (temp_random <= 70)) temp_name_prefix = "Superior";
    if ((temp_random >= 70) && (temp_random <= 80)) temp_name_prefix = "Exceptional";
    if ((temp_random >= 80) && (temp_random <= 95)) temp_name_prefix = "Wondrous";
    if  (temp_random >= 95)                         temp_name_prefix = "Heroic";

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
        case SLING:
            temp_range = random(2);
            if (temp_range <=  0) temp_name_type = "slingshot";
            if (temp_range >=  1) temp_name_type = "sling";
        break;
        default:
        break;
    }
    switch (type)
    {
        case HELM:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "protection";
            if (temp_range ==  1) temp_name_suffix = "stone";
            if (temp_range ==  2) temp_name_suffix = "wrath";
            if (temp_range ==  3) temp_name_suffix = "doom";
            if (temp_range ==  4) temp_name_suffix = "cover";
            if (temp_range >=  5) temp_name_suffix = "glory";
        break;
        case BOOTS:
            temp_range = random(7);
            if (temp_range <=  0) temp_name_suffix = "walking";
            if (temp_range ==  1) temp_name_suffix = "stomping";
            if (temp_range ==  2) temp_name_suffix = "running";
            if (temp_range ==  3) temp_name_suffix = "striding";
            if (temp_range ==  4) temp_name_suffix = "treading";
            if (temp_range ==  5) temp_name_suffix = "kicking";
            if (temp_range >=  6) temp_name_suffix = "agility";
        break;
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
        case BELT:
            temp_range = random(6);
            if (temp_range <=  0) temp_name_suffix = "security";
            if (temp_range ==  1) temp_name_suffix = "holding";
            if (temp_range ==  2) temp_name_suffix = "pride";
            if (temp_range ==  3) temp_name_suffix = "perseverance";
            if (temp_range ==  4) temp_name_suffix = "deliverance";
            if (temp_range >=  5) temp_name_suffix = "justice";
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
    init_item_sounds(101);
    game.item[102].name              = "Book of Stalagmite";
    game.item[102].image_ref         = game.texture.book_19.ref_number;
    game.item[102].stack_number      = 1;
    game.item[102].max_stack_number  = 10;
    game.item[102].ID                = 102;
    game.item[102].type              = SPELL_BOOK;
    game.item[102].add_spell         = 1;
    game.item[102].spell_type        = 1;
    init_item_sounds(102);

//-------------------------------- Potions / gems / runes -----------------------------------------------------------
    game.item[201].name              = "Minuscule Health Potion";
    game.item[201].image_ref         = game.texture.potion_01.ref_number;
    game.item[201].stack_number      = 1;
    game.item[201].max_stack_number  = 20;
    game.item[201].ID                = 201;
    game.item[201].type              = HEALTH_POTION;
    game.item[201].add_health        = 5;
    init_item_sounds(201);
    game.item[202].name              = "Tiny Health Potion";
    game.item[202].image_ref         = game.texture.potion_02.ref_number;
    game.item[202].stack_number      = 1;
    game.item[202].max_stack_number  = 20;
    game.item[202].ID                = 202;
    game.item[202].type              = HEALTH_POTION;
    game.item[202].add_health        = 10;
    init_item_sounds(202);
    game.item[203].name              = "Small Health Potion";
    game.item[203].image_ref         = game.texture.potion_03.ref_number;
    game.item[203].stack_number      = 1;
    game.item[203].max_stack_number  = 20;
    game.item[203].ID                = 203;
    game.item[203].type              = HEALTH_POTION;
    game.item[203].add_health        = 20;
    init_item_sounds(203);
    game.item[204].name              = "Medium Health Potion";
    game.item[204].image_ref         = game.texture.potion_04.ref_number;
    game.item[204].stack_number      = 1;
    game.item[204].max_stack_number  = 20;
    game.item[204].ID                = 204;
    game.item[204].type              = HEALTH_POTION;
    game.item[204].add_health        = 40;
    init_item_sounds(204);
    game.item[205].name              = "Large Health Potion";
    game.item[205].image_ref         = game.texture.potion_05.ref_number;
    game.item[205].stack_number      = 1;
    game.item[205].max_stack_number  = 20;
    game.item[205].ID                = 205;
    game.item[205].type              = HEALTH_POTION;
    game.item[205].add_health        = 80;
    init_item_sounds(205);
    game.item[206].name              = "Huge Health Potion";
    game.item[206].image_ref         = game.texture.potion_06.ref_number;
    game.item[206].stack_number      = 1;
    game.item[206].max_stack_number  = 20;
    game.item[206].ID                = 206;
    game.item[206].type              = HEALTH_POTION;
    game.item[206].add_health        = 160;
    init_item_sounds(206);
    game.item[207].name              = "Gigantic Health Potion";
    game.item[207].image_ref         = game.texture.potion_07.ref_number;
    game.item[207].stack_number      = 1;
    game.item[207].max_stack_number  = 20;
    game.item[207].ID                = 207;
    game.item[207].type              = HEALTH_POTION;
    game.item[207].add_health        = 320;
    init_item_sounds(207);

    game.item[208].name              = "Minuscule Mana Potion";
    game.item[208].image_ref         = game.texture.potion_08.ref_number;
    game.item[208].stack_number      = 1;
    game.item[208].max_stack_number  = 20;
    game.item[208].ID                = 208;
    game.item[208].type              = MANA_POTION;
    game.item[208].add_mana          = 5;
    init_item_sounds(208);
    game.item[209].name              = "Tiny Mana Potion";
    game.item[209].image_ref         = game.texture.potion_09.ref_number;
    game.item[209].stack_number      = 1;
    game.item[209].max_stack_number  = 20;
    game.item[209].ID                = 209;
    game.item[209].type              = MANA_POTION;
    game.item[209].add_mana          = 10;
    init_item_sounds(209);
    game.item[210].name              = "Small Mana Potion";
    game.item[210].image_ref         = game.texture.potion_10.ref_number;
    game.item[210].stack_number      = 1;
    game.item[210].max_stack_number  = 20;
    game.item[210].ID                = 210;
    game.item[210].type              = MANA_POTION;
    game.item[210].add_mana          = 20;
    init_item_sounds(210);
    game.item[211].name              = "Medium Mana Potion";
    game.item[211].image_ref         = game.texture.potion_11.ref_number;
    game.item[211].stack_number      = 1;
    game.item[211].max_stack_number  = 20;
    game.item[211].ID                = 211;
    game.item[211].type              = MANA_POTION;
    game.item[211].add_mana          = 40;
    init_item_sounds(211);
    game.item[212].name              = "Large Mana Potion";
    game.item[212].image_ref         = game.texture.potion_12.ref_number;
    game.item[212].stack_number      = 1;
    game.item[212].max_stack_number  = 20;
    game.item[212].ID                = 212;
    game.item[212].type              = MANA_POTION;
    game.item[212].add_mana          = 80;
    init_item_sounds(212);
    game.item[213].name              = "Huge Mana Potion";
    game.item[213].image_ref         = game.texture.potion_13.ref_number;
    game.item[213].stack_number      = 1;
    game.item[213].max_stack_number  = 20;
    game.item[213].ID                = 213;
    game.item[213].type              = MANA_POTION;
    game.item[213].add_mana          = 160;
    init_item_sounds(213);
    game.item[214].name              = "Gigantic Mana Potion";
    game.item[214].image_ref         = game.texture.potion_14.ref_number;
    game.item[214].stack_number      = 1;
    game.item[214].max_stack_number  = 20;
    game.item[214].ID                = 214;
    game.item[214].type              = MANA_POTION;
    game.item[214].add_mana          = 320;
    init_item_sounds(214);

//-------------------------------- Boots / gloves / belts -----------------------------------------------------------
    game.item[301].name              = "Boots of Haste";
    game.item[301].image_ref         = game.texture.boots_09.ref_number;
    game.item[301].stack_number      = 1;
    game.item[301].max_stack_number  = 1;
    game.item[301].ID                = 301;
    game.item[301].type              = BOOTS;
    game.item[301].armour            = 4;
    init_item_sounds(301);
    game.item[302].name              = "Boots of Flame walk";
    game.item[302].image_ref         = game.texture.boots_06.ref_number;
    game.item[302].stack_number      = 1;
    game.item[302].max_stack_number  = 1;
    game.item[302].ID                = 302;
    game.item[302].type              = BOOTS;
    game.item[302].armour            = 2;
    init_item_sounds(302);

    game.item[303].name              = "Belt of Energy";
    game.item[303].image_ref         = game.texture.belt_00.ref_number;
    game.item[303].stack_number      = 1;
    game.item[303].max_stack_number  = 1;
    game.item[303].ID                = 303;
    game.item[303].type              = BELT;
    game.item[303].armour            = 2;
    game.item[303].add_max_mana      = 32;
    init_item_sounds(303);

//-------------------------------- Armour / helms --------------------------------------------------------------------
    game.item[401].name              = "Plate Armour";
    game.item[401].image_ref         = game.texture.armour_00.ref_number;
    game.item[401].stack_number      = 1;
    game.item[401].max_stack_number  = 1;
    game.item[401].ID                = 401;
    game.item[401].type              = ARMOUR;
    game.item[401].armour            = 10;
    init_item_sounds(401);

    game.item[402].name              = "Strong Helm";
    game.item[402].image_ref         = game.texture.helm_00.ref_number;
    game.item[402].stack_number      = 1;
    game.item[402].max_stack_number  = 1;
    game.item[402].ID                = 402;
    game.item[402].type              = HELM;
    game.item[402].armour            = 34;
    init_item_sounds(402);
    game.item[403].name              = "Hard Helm";
    game.item[403].image_ref         = game.texture.helm_01.ref_number;
    game.item[403].stack_number      = 1;
    game.item[403].max_stack_number  = 1;
    game.item[403].ID                = 403;
    game.item[403].type              = HELM;
    game.item[403].armour            = 65;
    init_item_sounds(403);

//-------------------------------- Bows / slings -------------------------------------------------------------------
    game.item[501].name              = "Heroic Bow";
    game.item[501].image_ref         = game.texture.bow_00.ref_number;
    game.item[501].stack_number      = 1;
    game.item[501].max_stack_number  = 1;
    game.item[501].ID                = 501;
    game.item[501].type              = BOW;
    game.item[501].min_damage        = 6;
    game.item[501].max_damage        = 12;
    init_item_sounds(501);

    game.item[502].name              = "Heroic Sling";
    game.item[502].image_ref         = game.texture.sling_00.ref_number;
    game.item[502].stack_number      = 1;
    game.item[502].max_stack_number  = 1;
    game.item[502].ID                = 502;
    game.item[502].type              = SLING;
    game.item[502].min_damage        = 6;
    game.item[502].max_damage        = 12;
    init_item_sounds(502);

//-------------------------------- Daggers / Swords -------------------------------------------------------------------
    game.item[601].name              = "Frost Dagger";
    game.item[601].image_ref         = game.texture.dagger_00.ref_number;
    game.item[601].stack_number      = 1;
    game.item[601].max_stack_number  = 1;
    game.item[601].ID                = 601;
    game.item[601].type              = DAGGER;
    game.item[601].min_damage        = 6;
    game.item[601].max_damage        = 12;
    init_item_sounds(601);
    game.item[602].name              = "Magic Sword";
    game.item[602].image_ref         = game.texture.sword_00.ref_number;
    game.item[602].stack_number      = 1;
    game.item[602].max_stack_number  = 1;
    game.item[602].ID                = 602;
    game.item[602].type              = SWORD;
    game.item[602].min_damage        = 12;
    game.item[602].max_damage        = 24;
    init_item_sounds(602);

//-------------------------------- Rings / Amulets ------------------------------------------------------------------
    game.item[701].name              = "Ice Ring";
    game.item[701].image_ref         = game.texture.ring_00.ref_number;
    game.item[701].stack_number      = 1;
    game.item[701].max_stack_number  = 1;
    game.item[701].ID                = 701;
    game.item[701].type              = RING;
    game.item[701].min_damage        = 6;
    game.item[701].max_damage        = 12;
    init_item_sounds(701);
    game.item[702].name              = "Frost Ring";
    game.item[702].image_ref         = game.texture.ring_14.ref_number;
    game.item[702].stack_number      = 1;
    game.item[702].max_stack_number  = 1;
    game.item[702].ID                = 702;
    game.item[702].type              = RING;
    game.item[702].min_damage        = 6;
    game.item[702].max_damage        = 12;
    init_item_sounds(702);
    game.item[703].name              = "Fire Ring";
    game.item[703].image_ref         = game.texture.ring_12.ref_number;
    game.item[703].stack_number      = 1;
    game.item[703].max_stack_number  = 1;
    game.item[703].ID                = 703;
    game.item[703].type              = RING;
    game.item[703].min_damage        = 6;
    game.item[703].max_damage        = 12;
    init_item_sounds(703);

    game.item[704].name              = "Silver Amulet";
    game.item[704].image_ref         = game.texture.amulet_00.ref_number;
    game.item[704].stack_number      = 1;
    game.item[704].max_stack_number  = 1;
    game.item[704].ID                = 704;
    game.item[704].type              = AMULET;
    game.item[704].min_damage        = 6;
    game.item[704].max_damage        = 12;
    init_item_sounds(704);
    game.item[705].name              = "Ruby Amulet";
    game.item[705].image_ref         = game.texture.amulet_01.ref_number;
    game.item[705].stack_number      = 1;
    game.item[705].max_stack_number  = 1;
    game.item[705].ID                = 705;
    game.item[705].type              = AMULET;
    game.item[705].min_damage        = 6;
    game.item[705].max_damage        = 12;
    init_item_sounds(705);

//-------------------------------- Shields ----------------------------------------------------------------------------
    game.item[801].name              = "Golden Shield";
    game.item[801].image_ref         = game.texture.shield_00.ref_number;
    game.item[801].stack_number      = 1;
    game.item[801].max_stack_number  = 1;
    game.item[801].ID                = 801;
    game.item[801].type              = SHIELD;
    game.item[801].armour            = 16;
    init_item_sounds(801);
    game.item[802].name              = "Silver Shield";
    game.item[802].image_ref         = game.texture.shield_01.ref_number;
    game.item[802].stack_number      = 1;
    game.item[802].max_stack_number  = 1;
    game.item[802].ID                = 802;
    game.item[802].type              = SHIELD;
    game.item[802].armour            = 12;
    init_item_sounds(802);

//-------------------------------- Wands ------------------------------------------------------------------------------
    game.item[901].name              = "Lightning Wand";
    game.item[901].image_ref         = game.texture.wand_05.ref_number;
    game.item[901].stack_number      = 1;
    game.item[901].max_stack_number  = 1;
    game.item[901].ID                = 901;
    game.item[901].type              = WAND;
    game.item[901].min_damage        = 6;
    game.item[901].max_damage        = 12;
    init_item_sounds(901);

    game.item[902].name              = "Vamperic Wand";
    game.item[902].image_ref         = game.texture.wand_14.ref_number;
    game.item[902].stack_number      = 1;
    game.item[902].max_stack_number  = 1;
    game.item[902].ID                = 902;
    game.item[902].type              = WAND;
    game.item[902].min_damage        = 6;
    game.item[902].max_damage        = 12;
    game.item[902].sub_health_regeneration = 12;
    game.item[902].sub_mana_regeneration   = 12;
    init_item_sounds(902);

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
    generate_random_item(1008,100,100,SWORD);
    generate_random_item(1009,100,100,DAGGER);
    generate_random_item(1010,100,100,BOW);
    generate_random_item(1011,100,100,SLING);

};

void  init_item_sounds(int item_ID)
{
    int  sound_count = 0;
    for (int item_sound_use_count = 0; item_sound_use_count < game.item[item_ID].sound.quantity_use; item_sound_use_count++)
    {
        game.item[item_ID].sound.use[item_sound_use_count] = 0;
    }
    for (int item_sound_relocate_count = 0; item_sound_relocate_count < game.item[item_ID].sound.quantity_relocate; item_sound_relocate_count++)
    {
        game.item[item_ID].sound.relocate[item_sound_relocate_count] = 0;
    }
    switch (game.item[item_ID].type)
    {
        case EMPTY:
        break;
        case SPELL:
        break;
        case HEALTH_POTION:
            sound_count = 0;
            game.item[item_ID].sound.relocate[sound_count] = game.sound.bottle_01.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_relocate = sound_count;
            sound_count = 0;
            game.item[item_ID].sound.use[sound_count] = game.sound.bubble_01.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.bubble_02.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.bubble_03.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_use = sound_count;
        break;
        case MANA_POTION:
            sound_count = 0;
            game.item[item_ID].sound.relocate[sound_count] = game.sound.bottle_01.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_relocate = sound_count;
            sound_count = 0;
            game.item[item_ID].sound.use[sound_count] = game.sound.bubble_01.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.bubble_02.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.bubble_03.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_use = sound_count;
        break;
        case SPELL_BOOK:
            sound_count = 0;
            game.item[item_ID].sound.relocate[sound_count] = game.sound.book_00.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_relocate = sound_count;
            sound_count = 0;
            game.item[item_ID].sound.use[sound_count] = game.sound.book_00.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.book_01.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.book_02.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_use = sound_count;
        break;
        case SPELL_SCROLL:
            sound_count = 0;
            game.item[item_ID].sound.relocate[sound_count] = game.sound.book_01.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_relocate = sound_count;
            sound_count = 0;
            game.item[item_ID].sound.use[sound_count] = game.sound.book_00.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.book_01.ref_number;sound_count++;
            game.item[item_ID].sound.use[sound_count] = game.sound.book_02.ref_number;sound_count++;
            game.item[item_ID].sound.quantity_use = sound_count;
        break;
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
        case WEAPON:
        break;
        default:
        break;
    }
};





