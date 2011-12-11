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

#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define HEALTH_POTION 1
#define MANA_POTION   2
#define SPELL_BOOK    3
#define SPELL_SCROLL  4
#define HELM          5
#define BOOTS         6
#define ARMOUR        7
#define GLOVES        8
#define RING          9
#define AMULET        10
#define SHIELD        11
#define WAND          12
#define SWORD         13
#define DAGGER        14
#define BELT          15
#define BOW           16
#define WEAPON        17

const int MAX_ITEMS = 65500;

class item_class
{
    public:
        std::string name;
        int         image_ref;
        int         sound_ref;
        int         ID;
        int         type;
        int         stack_number;
        int         max_stack_number;
        int         defence;
        int         min_dammage;
        int         max_dammage;
        int         add_min_dammage;
        int         add_max_dammage;
        int         sub_min_dammage;
        int         sub_max_dammage;
        int         add_max_health;
        int         sub_max_health;
        int         add_max_mana;
        int         sub_max_mana;
        int         add_health_regeneration;
        int         sub_health_regeneration;
        int         add_mana_regeneration;
        int         sub_mana_regeneration;
        int         add_crit_chance;
        int         sub_crit_chance;
        int         add_spell;
        int         spell_type;
        bool        usable;
        void load(void);
        item_class(void);
       ~item_class(void);
};

void    init_items(void);

#endif // ITEMS_H

