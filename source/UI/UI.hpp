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

#ifndef UI_H
#define UI_H

#include "spell_book.hpp"
#include "equipment.hpp"
#include "inventory.hpp"
#include "character.hpp"
#include "quest_log.hpp"
#include "../npcvendor.hpp"

#define    MAIN_MENU_WINDOW  1
#define    EQUIPMENT_WINDOW  2
#define    QUEST_LOG_WINDOW  3
#define    CHARACTER_WINDOW  4
#define    INVENTORY_WINDOW  5
#define    SPELLBOOK_WINDOW  6
#define    PCPROFILE_WINDOW  7
#define    NPCVENDOR_WINDOW  8

const int  MAX_ACTIVE_WINDOWS      = 9;
const int  MAX_ACTION_SLOTS        = 16;
const int  MAX_ACTION_MENU_SLOTS   = 8;

/*
class active_window_list_class
{
    public:
        int  window_ID[MAX_ACTIVE_WINDOWS];
        active_window_list_class(void);
       ~active_window_list_class(void);
        void remove_from_list(int window_UID);
        void add_to_list(int window_UID);
};
*/

class player_stats_class
{
    public:
        bool  highlighted;
        bool  drag;
        int   portrait;
        bool  mouse_over;
        int   mouse_over_count;
        int   mouse_over_health_count;
        int   mouse_over_mana_count;
        int   mouse_over_portrait_count;
        int   tooltip_time;
        bool  tooltip_active;
        float drag_delta_x;
        float drag_delta_y;
        float drag_offset_x;
        float drag_offset_y;
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        float mana;
        float health;
        player_stats_class(void);
       ~player_stats_class(void);
        void process(void);
        void draw(void);
        void draw_tooltip(void);
};

class action_slot_class
{
    public:
        int   current_item;
        bool  highlighted;
        bool  drag;
        int   button_type;
        bool  mouse_over;
        int   mouse_over_count;
        int   tooltip_time;
        bool  tooltip_active;
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        float drag_offset_x;
        float drag_offset_y;
        float base_pos_x;
        float base_pos_y;
        action_slot_class(void);
       ~action_slot_class(void);
        void process(void);
        void draw(void);
        void draw_drag(void);
        void draw_tooltip(void);
};

class menu_slot_class
{
    public:
        int   click_delay;
        int   click_delay_count;
        bool  highlighted;
        bool  drag;
        int   button_type;
        bool  mouse_over;
        int   mouse_over_count;
        int   tooltip_time;
        bool  tooltip_active;
        float pos_x;
        float pos_y;
        float pos_z;
        float base_pos_x;
        float base_pos_y;
        float width;
        float height;
        menu_slot_class(void);
       ~menu_slot_class(void);
        void process(void);
        void draw(void);
        void draw_tooltip(void);
};

class action_bar_class
{
    public:
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        menu_slot_class   menu_slot  [MAX_ACTION_MENU_SLOTS];
        action_slot_class action_slot[MAX_ACTION_SLOTS];
        void process(void);
        void draw(void);
        action_bar_class(void);
       ~action_bar_class(void);
};

class UI_class
{
    public:
        bool                     drag_in_progress;
        //active_window_list_class active_window_list;
        player_stats_class       player_stats;
        action_bar_class         action_bar;
        spell_book_class         spell_book;
        inventory_class          inventory;
        character_class          character;
        equipment_class          equipment;
        npcvendor_class          npcvendor;
        quest_log_class          quest_log;
        void process(void);
        void draw(void);
        UI_class(void);
       ~UI_class(void);
};

#endif // UI_H

