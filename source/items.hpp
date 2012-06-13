/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <fstream>

#define EMPTY         0
#define SPELL         1
#define HEALTH_POTION 2
#define MANA_POTION   3
#define SPELL_BOOK    4
#define SPELL_SCROLL  5
#define HELM          6
#define BOOTS         7
#define ARMOUR        8
#define GLOVES        9
#define RING          10
#define AMULET        11
#define SHIELD        12
#define WAND          13
#define SWORD         14
#define DAGGER        15
#define BELT          16
#define BOW           17
#define SLING         18
#define WEAPON        19

const int   ARMOUR_BASE_MULTIPLIER              = 1;
const int   DAMAGE_BASE_MULTIPLIER              = 1;
const int   HEALTH_BASE_MULTIPLIER              = 1;
const int   MANA_BASE_MULTIPLIER                = 1;
const int   HEALTH_REGENERATION_BASE_MULTIPLIER = 15;
const int   MANA_REGENERATION_BASE_MULTIPLIER   = 25;
const int   CRITICAL_CHANCE_BASE_MULTIPLIER     = 1;
const int   WALK_SPEED_BASE_MULTIPLIER          = 1;
const int   LIGHT_RADIUS_BASE_MULTIPLIER        = 1;

const int   MAX_ITEMS                = 65500;
const int   MAX_ITEM_USE_SOUNDS      = 8;
const int   MAX_ITEM_RELOCATE_SOUNDS = 8;

struct item_sound_type
{
    int             quantity_use;
    int             quantity_relocate;
    int             use     [MAX_ITEM_USE_SOUNDS];
    int             relocate[MAX_ITEM_RELOCATE_SOUNDS];
};

class item_class
{
    public:
        std::string name;
        bool            active;
        int             image_ref;
        item_sound_type sound;
        int             ID;
        int             type;
        int             stack_number;
        int             max_stack_number;
        int             require_defence;
        int             require_strength;
        int             require_intelligence;
        int             armour;
        int             add_armour;
        int             sub_armour;
        int             min_damage;
        int             max_damage;
        int             add_min_damage;
        int             add_max_damage;
        int             sub_min_damage;
        int             sub_max_damage;
        int             add_max_health;
        int             sub_max_health;
        int             add_max_mana;
        int             sub_max_mana;
        int             add_health_regeneration;
        int             sub_health_regeneration;
        int             add_mana_regeneration;
        int             sub_mana_regeneration;
        int             add_crit_chance;
        int             sub_crit_chance;
        int             add_walk_speed;
        int             sub_walk_speed;
        int             add_light_radius;
        int             sub_light_radius;
        int             add_spell;
        int             spell_type;
        int             add_health;
        int             add_mana;
        int             add_flame_damage;
        int             add_frost_damage;
        int             add_lightning_damage;
        int             add_magic_damage;
        int             add_flame_resistance;
        int             add_frost_resistance;
        int             add_lightning_resistance;
        int             add_all_resistances;
        item_class(void);
       ~item_class(void);
        void            load   (std::string file_name);
        void            equip  (void);
        void            unequip(void);
};

int   generate_range(int level, int quality, int base_value);
void  generate_random_item(int item_ID, int level, int quality, int type);
void  init_items(void);
void  init_item_sounds(int item_ID);

#endif // ITEMS_H






