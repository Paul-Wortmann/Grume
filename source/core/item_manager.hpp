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

#define MAX_ITEM_EFFECTS     6
#define MAX_ITEM_SOCKETS     4
#define MAX_ITEM_QUALITY     100

#define ITEM_QUALITY_NORMAL  0
#define ITEM_QUALITY_MAGIC   1
#define ITEM_QUALITY_EPIC    2
#define ITEM_QUALITY_SET     3

#define SOCKET_NONE          0
#define SOCKET_GEM           1
#define SOCKET_RUNE          2

#define ITEM_NONE            0
#define ITEM_POTION          1
#define ITEM_POTION_SMALL    2
#define ITEM_POTION_MEDIUM   3
#define ITEM_POTION_LARGE    4
#define ITEM_SPELL           5
#define ITEM_SPELL_BOOK      6
#define ITEM_SPELL_SCROLL    7
#define ITEM_GEM_NONE        8
#define ITEM_GEM             9
#define ITEM_GEM_EMERALD     10
#define ITEM_GEM_OPAL        11
#define ITEM_GEM_RUBY        12
#define ITEM_GEM_SAPPHIRE    13
#define ITEM_GEM_TOPAZ       14
#define ITEM_RING            15
#define ITEM_NECK            16
#define ITEM_HEAD            17
#define ITEM_HAND            18
#define ITEM_FEET            19
#define ITEM_BODY            20
#define ITEM_BELT            21
#define ITEM_OFFHAND         22
#define ITEM_WEAPON          23
#define ITEM_HELM            24
#define ITEM_BOOTS           25
#define ITEM_ARMOUR          26
#define ITEM_GLOVES          27
#define ITEM_AMULET          28
#define ITEM_SHIELD          29
#define ITEM_SOURCE          30
#define ITEM_WAND            31
#define ITEM_SWORD           32
#define ITEM_DAGGER          33
#define ITEM_BOW             34

//--- Predefined items ---------------
#define ITEM_POTION_S_HEALTH          120
#define ITEM_POTION_M_HEALTH          121
#define ITEM_POTION_L_HEALTH          122
#define ITEM_POTION_S_MANA            123
#define ITEM_POTION_M_MANA            124
#define ITEM_POTION_L_MANA            125
#define ITEM_POTION_S_REJUVENATION    126
#define ITEM_POTION_M_REJUVENATION    127
#define ITEM_POTION_L_REJUVENATION    128

struct item_socket_type
{
    bool enabled;
    int  type;
    int  value;
};

struct item_effect_type
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
    int              qaulity_type;
    bool             active;
    bool             stackable;
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
    //effect_type*     effect[MAX_ITEM_EFFECTS];
    item_effect_type effect[MAX_ITEM_EFFECTS];
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
        int             gen_item(int item_type_UID, int item_sub_type_UID, int quality_level);
        void            gen_item_name(item_type* temp_item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level);
        void            gen_item_texture(item_type* temp_item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level);
        void            gen_item_sounds(item_type* temp_item_pointer,int item_type_UID, int item_sub_type_UID, int quality_level);
};

#endif // ITEM_MANAGER_H

