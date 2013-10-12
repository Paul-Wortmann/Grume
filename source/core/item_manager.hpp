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
#include "../core/texture_manager.hpp"
#include "../core/sound_manager.hpp"
#include "../UI/UI_types.hpp"
#include "effect_manager.hpp"

#define ITEM_NONE            0
#define ITEM_RING            1
#define ITEM_NECK            2
#define ITEM_HEAD            3
#define ITEM_HAND            4
#define ITEM_FEET            5
#define ITEM_BODY            6
#define ITEM_BELT            7
#define ITEM_OFFHAND         8
#define ITEM_WEAPON          9

#define ITEM_POTION          10
#define ITEM_POTION_SMALL    11
#define ITEM_POTION_MEDIUM   12
#define ITEM_POTION_LARGE    13
#define ITEM_SPELL           14
#define ITEM_SPELL_BOOK      15


//temp---------------
#define ITEM_HEALTH_POTION          20
#define ITEM_MANA_POTION            21
#define ITEM_REJUVENATION_POTION    22

/*
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
*/

#define MAX_ITEM_EFFECTS 4
#define MAX_ITEM_SOCKETS 4

#define SOCKET_NONE   0
#define SOCKET_GEM    1
#define SOCKET_RUNE   2

struct item_socket_type
{
    bool enabled;
    int  type;
    int  value;
};

struct item_data_type
{
    sound_type*      sound_move;
    sound_type*      sound_use;
    texture_type*    image;
    bool             active;
    bool             consumable;
    bool             equipable;
    bool             quest;
    std::string      name;
    int              UID;
    int              type;
    int              sub_type;
    int              quantity;
    int              quantity_max;
    int              number_of_item_effects;
    int              number_of_item_sockets;
    bool             socketable;  // has sockets, or can gain sockets via NPC etc...
    int              socket_max;  // max_number of allowed sockets for item, ie. ring == 1 etc...
    int              socket_type; // Only accept certain items
    effect_type*     effect[MAX_ITEM_EFFECTS];
    item_socket_type socket[MAX_ITEM_SOCKETS];
};

struct item_type
{
    item_data_type   data;
    item_type*       next;
};

class item_manager_class
{
    public:
        item_manager_class(void);
       ~item_manager_class(void);
        int             number_of_items;
        item_type*      root;
        item_type*      last;
        item_type*      item;
        item_type*      add_item(std::string file_name);
        item_type*      add_item(int item_UID);
        void            use_item(item_type *item_pointer);
        int             get_new_item_UID(void);
        void            load_items(std::string file_name);
        void            use_item(UI_form_struct *UI_form_pointer, int element_number);
        void            equip_item(item_type* item_pointer);
        void            unequip_item(item_type* item_pointer);
};

#endif // ITEM_MANAGER_H

