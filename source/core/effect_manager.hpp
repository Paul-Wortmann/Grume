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

#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include <string>
#include "../core/texture_manager.hpp"
#include "../core/sound_manager.hpp"

#define EFFECT_NONE                 0
#define EFFECT_MOD_STRENGTH         1
#define EFFECT_MOD_INTELLECT        2
#define EFFECT_MOD_DEXTERITY        3
#define EFFECT_MOD_ALL_ATTRIBUTES   4
//---------------------------------------
#define EFFECT_MOD_ARMOR            5
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

struct effect_data_type
{
    bool             active;
    std::string      name;
    bool             passive;
    int              sub_type;
    int              type;
    int              UID;
    int              value;
};

struct effect_type
{
    effect_data_type  data;
    effect_type      *next;
};


class effect_manager_class
{
    public:
        effect_manager_class(void);
       ~effect_manager_class(void);
        int                 number_of_effects;
        effect_type        *root;
        effect_type        *last;
        effect_type        *effect;
        effect_type        *add_effect(int effect_UID);
//        bool                use_effect(int  effect_UID);
        bool                use_effect(int  effect_UID, float value);
        void                load_effects(std::string file_name);
};

#endif // EFFECT_MANAGER_H

