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

#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <string>
#include "core/textures.hpp"

#define NULL_ITEM     -1
#define HEALTH_POTION  0
#define MANA_POTION    1

#define SPELL          2
#define SPELL_BOOK     4
#define SPELL_SCROLL   5
#define HELM           6
#define BOOTS          7
#define ARMOUR         8
#define GLOVES         9
#define RING           10
#define AMULET         11
#define SHIELD         12
#define WAND           13
#define SWORD          14
#define DAGGER         15
#define BELT           16
#define BOW            17
#define SLING          18
#define WEAPON         19

#define SMALL_POTION   32
#define MEDIUM_POTION  33
#define LARGE_POTION   34

#define EFFECT_MOD_HEALTH 100
#define EFFECT_MOD_MANA   101

#define MAX_ITEMS        100 /*   65500     */
#define MAX_ITEM_EFFECTS 4
#define MAX_ITEM_SOCKETS 4

struct item_effect_type
{
    bool enabled;
    int  type;
    int  value;
};

struct item_socket_type
{
    bool enabled;
    int  type;
    int  value;
};

struct item_type
{
    // sound move
    // sound use
    // texture
    bool             active;
    std::string      name;
    texture_class    image;
    int              ID;
    int              type;
    int              sub_type;
    int              quantity;
    int              quantity_max;
    int              number_of_item_effects;
    int              number_of_item_sockets;
    bool             socketable;
    item_effect_type effect[MAX_ITEM_EFFECTS];
    item_socket_type socket[MAX_ITEM_SOCKETS];
};

class item_manager_class
{
    public:
        item_manager_class(void);
       ~item_manager_class(void);
        int             number_of_items;
        item_type      *item;
        void            reset_item(int item_number);
        int             get_new_ID(void);
        int             get_item_ID(int temp_item_type);
        int             get_item_type(int item_ID);
};

void  init_items(void); // Initialize hard-coded default items, such as health potions etc...
void  use_item(int window_from, int element_from);

#endif // ITEM_MANAGER_H





/*

sound / texture manager that is separate from the item class, so these are not repeatedly loaded.

item_sound_manager_class
item_texture_manager_class
item_effect_class
item_class

*/
