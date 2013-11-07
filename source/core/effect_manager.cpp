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
#include "effect_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

effect_manager_class::effect_manager_class(void)
{
};

effect_manager_class::~effect_manager_class(void)
{
    delete [] effect_manager_class::effect;
};

effect_type* effect_manager_class::add_effect(int effect_UID)
{
    if (effect_manager_class::number_of_effects == 0)
    {
        effect_manager_class::root = new effect_type;
        effect_manager_class::root->next = NULL;
        effect_manager_class::last = new effect_type;
        effect_manager_class::last = root;
        effect_manager_class::last->next = NULL;
    }
    else
    {
        effect_type* temp_pointer;
        temp_pointer = new effect_type;
        temp_pointer = effect_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (temp_pointer->data.UID == effect_UID) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        effect_manager_class::last->next = new effect_type;
        effect_manager_class::last = effect_manager_class::last->next;
        effect_manager_class::last->next = new effect_type;
        effect_manager_class::last->next = NULL;
    }
    effect_manager_class::last->data.active                 = false;
    effect_manager_class::last->data.name                   = "";
    effect_manager_class::last->data.UID                    = effect_UID;
    effect_manager_class::last->data.passive                = false;
    effect_manager_class::last->data.type                   = EFFECT_NONE;
    effect_manager_class::last->data.sub_type               = EFFECT_NONE;
    effect_manager_class::last->data.value                  = 0;
    effect_manager_class::number_of_effects++;
    return(effect_manager_class::last);
};

bool  effect_manager_class::use_effect(int  effect_UID, float value)
{
    bool used_item = false;
    switch (effect_UID)
    {
        case EFFECT_NONE:
        break;
        case EFFECT_MOD_STRENGTH:
            used_item = true;
            game.player.stats.strength += value;
        break;
        case EFFECT_MOD_INTELLECT:
            used_item = true;
            game.player.stats.intellect += value;
        break;
        case EFFECT_MOD_DEXTERITY:
            used_item = true;
            game.player.stats.dexterity += value;
        break;
        case EFFECT_MOD_ALL_ATTRIBUTES:
            used_item = true;
            game.player.stats.strength  += value;
            game.player.stats.intellect += value;
            game.player.stats.dexterity += value;
        break;
        case EFFECT_MOD_ARMOR:
            used_item = true;
            game.player.stats.armor += value;
        break;
        case EFFECT_MOD_DAMAGE:
            used_item = true;
            game.player.stats.damage += value;
        break;
        case EFFECT_MOD_DAMAGE_MAX:
            used_item = true;
            game.player.stats.damage_max += value;
        break;
        case EFFECT_MOD_DAMAGE_MIN:
            used_item = true;
            game.player.stats.damage_min += value;
        break;
        case EFFECT_MOD_DAMAGE_ICE:
            used_item = true;
            game.player.stats.damage_ice += value;
        break;
        case EFFECT_MOD_DAMAGE_FIRE:
            used_item = true;
            game.player.stats.damage_fire += value;
        break;
        case EFFECT_MOD_DAMAGE_LIGHTNING:
            used_item = true;
            game.player.stats.damage_lightning += value;
        break;
        case EFFECT_MOD_DAMAGE_ELEMENTAL:
            used_item = true;
            game.player.stats.damage_ice       += value;
            game.player.stats.damage_fire      += value;
            game.player.stats.damage_lightning += value;
        break;
        case EFFECT_MOD_RESIST_PHYSICAL:
            used_item = true;
            game.player.stats.resist_physical += value;
        break;
        case EFFECT_MOD_RESIST_ICE:
            used_item = true;
            game.player.stats.resist_ice += value;
        break;
        case EFFECT_MOD_RESIST_FIRE:
            used_item = true;
            game.player.stats.resist_fire += value;
        break;
        case EFFECT_MOD_RESIST_LIGHTNING:
            used_item = true;
            game.player.stats.resist_lightning += value;
        break;
        case EFFECT_MOD_RESIST_ALL:
            used_item = true;
            game.player.stats.resist_physical  += value;
            game.player.stats.resist_ice       += value;
            game.player.stats.resist_fire      += value;
            game.player.stats.resist_lightning += value;
        break;
        case EFFECT_MOD_HEALTH:
            if (game.player.health.current < game.player.health.maximum)
            {
                used_item = true;
                game.player.health.current += value;
            }
        break;
        case EFFECT_MOD_HEALTH_MAX:
            used_item = true;
            game.player.health.maximum += value;
        break;
        case EFFECT_MOD_HEALTH_REGEN:
            used_item = true;
            if (value >=  1) value = value / 1000.0f;
            if (value <= -1) value = value / 1000.0f;
            game.player.health.regeneration += value;
        break;
        case EFFECT_MOD_HEALTH_HIT:
            used_item = true;
            game.player.stats.health_hit += value;
        break;
        case EFFECT_MOD_HEALTH_KILL:
            used_item = true;
            game.player.stats.health_kill += value;
        break;
        case EFFECT_MOD_MANA:
            if (game.player.mana.current < game.player.mana.maximum)
            {
                used_item = true;
                game.player.mana.current += value;
            }
        break;
        case EFFECT_MOD_MANA_MAX:
            used_item = true;
            game.player.mana.maximum += value;
        break;
        case EFFECT_MOD_MANA_REGEN:
            used_item = true;
            if (value >=  1) value = value / 1000.0f;
            if (value <= -1) value = value / 1000.0f;
            game.player.mana.regeneration += value;
        break;
        case EFFECT_MOD_MANA_HIT:
            used_item = true;
            game.player.stats.mana_hit += value;
        break;
        case EFFECT_MOD_MANA_KILL:
            used_item = true;
            game.player.stats.mana_kill += value;
        break;
        case EFFECT_MOD_CRIT_CHANCE:
            used_item = true;
            game.player.stats.crit_chance += value;
        break;
        case EFFECT_MOD_CRIT_DAMAGE:
            used_item = true;
            game.player.stats.crit_damage += value;
        break;
        case EFFECT_MOD_MOVEMENT_SPEED:
            used_item = true;
            game.player.stats.movement_speed += value;
        break;
        case EFFECT_MOD_LIGHT_RADIUS:
            used_item = true;
            game.player.stats.light_radius += value;
        break;
        case EFFECT_MOD_MAGIC_FIND:
            used_item = true;
            game.player.stats.magic_find += value;
        break;
        case EFFECT_MOD_GOLD_FIND:
            used_item = true;
            game.player.stats.gold_find += value;
        break;
        case EFFECT_MOD_EXP_PER_KILL:
            used_item = true;
            game.player.stats.exp_per_kill += value;
        break;
        case EFFECT_MOD_SPELL:
            {
                int spell_name = value;
                if (value < 0)
                {
                    spell_name *= -1;
                    value = -1;
                }
                else value = 1;
                switch (spell_name)
                {
                    case ITEM_SPELL_ARROW_FIRE:
                        game.player.spells.arrow_fire += value;
                    break;
                    case ITEM_SPELL_ARROW_ICE:
                        game.player.spells.arrow_ice += value;
                    break;
                    case ITEM_SPELL_ARROW_LIGHTNING:
                        game.player.spells.arrow_lightning += value;
                    break;
                    case ITEM_SPELL_ARROW_ELEMENTAL:
                        game.player.spells.arrow_elemental += value;
                    break;
                    case ITEM_SPELL_BALL_FIRE:
                        game.player.spells.ball_fire += value;
                    break;
                    case ITEM_SPELL_BALL_ICE:
                        game.player.spells.ball_ice += value;
                    break;
                    case ITEM_SPELL_BALL_LIGHTNING:
                        game.player.spells.ball_lightning += value;
                    break;
                    case ITEM_SPELL_BALL_ELEMENTAL:
                        game.player.spells.ball_elemental += value;
                    break;
                    default:
                    break;
                }
            }
        break;
        case EFFECT_MOD_SPELL_TYPE:
        break;
        case EFFECT_MOD_SPELL_ALL:
        break;
        case EFFECT_MOD_SPELL_CAST_KILL:
        break;
        case EFFECT_MOD_SPELL_CAST_HIT:
        break;
        case EFFECT_MOD_SPELL_CAST_DMG:
        break;
        default:
            game.core.log.file_write("Unable to use effect -> ",effect_UID);
        break;
    }
    return (used_item);
};

void effect_manager_class::load_effects(std::string file_name)
{
    effect_type*   temp_effect_pointer;
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
                        temp_effect_pointer = game.effect_manager.add_effect(atoi(temp_string_data.c_str()));
                        temp_effect_pointer->data.UID     = atoi(temp_string_data.c_str());
                        temp_effect_pointer->data.active   = true;
                    }
                    if (temp_effect_pointer != NULL)
                    {
                        if  (temp_string_key == "NAME")     temp_effect_pointer->data.name = temp_string_data.c_str();
                        temp_effect_pointer->data.passive = ((temp_string_key == "PASSIVE")&&(temp_string_data == "TRUE")) ? true : false;
                        if  (temp_string_key == "VALUE")    temp_effect_pointer->data.value = atof(temp_string_data.c_str());
                        if  (temp_string_key == "TYPE")     temp_effect_pointer->data.type  = atoi(temp_string_data.c_str());
                        if  (temp_string_key == "SUB_TYPE") temp_effect_pointer->data.type  = atoi(temp_string_data.c_str());
                    }
                }
            }
        }
        script_file.close();
    }
};
