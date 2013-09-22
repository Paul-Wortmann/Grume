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

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#include "action_bar.hpp"
#include "character_window.hpp"
#include "equipment_window.hpp"
#include "inventory_window.hpp"
#include "menu_game_load.hpp"
#include "menu_game_new.hpp"
#include "menu_game_save.hpp"
#include "menu_main.hpp"
#include "menu_options.hpp"
#include "player_profile.hpp"
#include "quest_log_window.hpp"
#include "skillbook_window.hpp"
#include "UI_cursor.hpp"
#include "UI_types.hpp"
#include "../player.hpp"

#define    UID_ACTIONBAR          1
#define    UID_PCPROFILE          2
#define    UID_EQUIPMENT          3
#define    UID_QUEST_LOG          4
#define    UID_CHARACTER          5
#define    UID_INVENTORY          6
#define    UID_SKILLBOOK          7
#define    UID_NPCVENDOR          8
#define    UID_MENU_MAIN          9
#define    UID_MENU_GAME_NEW      10
#define    UID_MENU_GAME_SAVE     11
#define    UID_MENU_GAME_LOAD     12
#define    UID_MENU_OPTIONS       13
#define    UID_MENU_GAME_OVER     14
#define    UID_MENU_PAUSE         15

class UI_manager_class
{
    public:
        UI_manager_class(void);
        UI_cursor_class       cursor;
        bool                  drag_in_progress;
        bool                  element_drag_in_progress;
        event_struct          event;
        int                   number_of_UI_forms;
        UI_form_struct       *root;
        UI_form_struct       *last;
        UI_form_struct       *UI_form_add(int UI_form_UID);
        UI_form_struct       *UI_form_get(int UI_form_UID);
        void                  UI_form_enable(int UI_form_UID);
        void                  UI_form_disable(int UI_form_UID);
        void                  UI_form_set_active(int UI_form_UID);
        bool                  UI_form_get_active(int UI_form_UID);
        void                  UI_form_set_position(int UI_form_UID_src, int UI_form_UID_dst);
        void                  UI_form_mouse_reset(int UI_form_UID);
        void                  UI_form_set_event(int UI_form_UID, int EVENT_ID);
        int                   UI_form_get_list_position(int UI_form_UID);
        void                  UI_form_list_sort(void);
        void                  UI_form_transition(int UI_form_UID_src, int UI_form_UID_dst);
        void                  setup(void);
        void                  render(void);
        void                  process(void);
        event_struct          process_form_elements(UI_form_struct *UI_form_pointer,bool window_in_focus);
        event_struct          process_form(UI_form_struct *UI_form_pointer);
};


#endif // UI_MANAGER_H

