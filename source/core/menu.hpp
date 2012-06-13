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

#ifndef MENU_H
#define MENU_H

#include <string>

#define DISABLED   0
#define CLOSE      1
#define BUTTON     2
#define SLIDER     3
#define IMAGE      4
#define BAR        5
#define TOGGLE     6
#define CHECKBOX   7
#define DROPDOWN   8
#define SELECTION  9
#define ACHIEVE    10

const int MAX_ELEMENTS = 32;

class menu_element_class
{
    private:
    public:
        std::string             title;
        std::string             tooltip;
        int                     event;
        int                     type;
        float                   value;
        float                   possition_x;
        float                   possition_y;
        float                   possition_z;
        float                   size_x;
        float                   size_y;
        float                   size_z;
        bool                    mouse_over;
        bool                    active;
        bool                    clicked;
        bool                    hightlighted;
        menu_element_class(void);
       ~menu_element_class(void);
        void                    render(void);
        int                     process(void);
};

class menu_class
{
    private:
    public:
        int                     event;
        std::string             title;
        float                   possition_x;
        float                   possition_y;
        float                   possition_z;
        float                   size_x;
        float                   size_y;
        float                   size_z;
        int                     color_normal_r;
        int                     color_normal_g;
        int                     color_normal_b;
        int                     color_normal_a;
        int                     color_highlighted_r;
        int                     color_highlighted_g;
        int                     color_highlighted_b;
        int                     color_highlighted_a;
        int                     color_disabled_r;
        int                     color_disabled_g;
        int                     color_disabled_b;
        int                     color_disabled_a;
        int                     texture_ID;
        int                     texture_ID_normal;
        int                     texture_ID_highlighted;
        int                     texture_ID_disabled;
        bool                    mouse_over;
        bool                    active;
        bool                    drag_active;
        menu_element_class      element[MAX_ELEMENTS];
        menu_class(void);
       ~menu_class(void);
        void                    render(void);
        void                    process(void);
};

#endif //MENU_H




