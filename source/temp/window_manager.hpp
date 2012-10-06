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

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "window.hpp"
#include "main_menu.hpp"

#define    ACTIONBAR_UID          1
#define    PCPROFILE_UID          2
#define    EQUIPMENT_UID          3
#define    QUEST_LOG_UID          4
#define    CHARACTER_UID          5
#define    INVENTORY_UID          6
#define    SPELLBOOK_UID          7
#define    NPCVENDOR_UID          8
#define    MENU_DEFAULT_UID       9  //base menu to store default values, and position / size for conjoined windows.
#define    MENU_MAIN_UID          10
#define    MENU_NEW_GAME_UID      11
#define    MENU_SAVE_UID          12
#define    MENU_LOAD_UID          13
#define    MENU_OPTIONS_UID       14
#define    MENU_GAME_OVER_UID     15
#define    MENU_PAUSE_UID         16

class window_manager_class
{
    protected:
    private:
    public:
        float mouse_x;
        float mouse_y;
        int   number_of_windows;
        window_class *window;
        window_manager_class(void);
       ~window_manager_class(void);
        int  get_window_number(int UID);
        void set_active_window(int UID);
        int  get_active_window(void);
        int  register_window(int UID);
        int  register_window(int UID_minimum, int UID_maximum);
        void de_register_window(int UID);
        bool mouse_over_window(float wx, float wy, float ww, float wh);
        void process(void);
        void render(void);
};

void setup_windows(void);

#endif // WINDOW_MANAGER_H
