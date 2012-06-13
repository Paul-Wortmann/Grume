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

class menu_system_class
{
    private:
public:
        int        event;
        int        possition;
        int        possition_max;
        int        level;
        int        level_no;
        int        recall_position;
        int        recall_view;
        menu_class main;
        menu_class new_game;
        menu_class save;
        menu_class load;
        menu_class options;
        menu_class game_over;
        menu_class pause;
        void       render(void);
        void       process(void);
        void       init(void);
};


#endif //MENU_SYSTEM_H
