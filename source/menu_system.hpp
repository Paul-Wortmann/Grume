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

#ifndef MENU_SYSTEM_H
#define MENU_SYSTEM_H

#include "core/menu.hpp"

#define MENU_MAIN          0
#define MENU_NEW_GAME      1
#define MENU_SAVE          2
#define MENU_LOAD          3
#define MENU_OPTIONS       4
#define MENU_GAME_OVER     5
#define MENU_PAUSE         6

class menu_system_class
{
    private:
    public:
        delay_class             mouse_delay;
        int                     event;
        int                     position;
        int                     position_max;
        int                     active_menu;
        float                   position_x;
        float                   position_y;
        float                   position_z;
        float                   size_x;
        float                   size_y;
        float                   size_z;
        element_zoom_class      zoom;
        color_state_class       color;
        texture_state_class     texture_ID;
        menu_class menu_main;
        menu_class menu_new_game;
        menu_class menu_save;
        menu_class menu_load;
        menu_class menu_options;
        menu_class menu_game_over;
        menu_class menu_pause;
        void                    render(void);
        int                     process(void);
        void                    init(void);
};


#endif //MENU_SYSTEM_H
