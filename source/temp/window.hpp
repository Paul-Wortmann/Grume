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

#ifndef WINDOW_H
#define WINDOW_H

#include "window_element.hpp"

class color_class
{
    private:
    public:
        int r;
        int g;
        int b;
        int a;
};

class color_state_class
{
    private:
    public:
        color_class normal;
        color_class highlighted;
        color_class disabled;
};

class window_class
{
    protected:
    private:
    public:
        int                     UID;
        int                     event;
        bool                    active;
        int                     number_of_elements;
        bool                    mouse_over;
        bool                    drag_active;
        float                   drag_offset_x;
        float                   drag_offset_y;
        delay_class             mouse_delay;
        color_state_class       color;
        window_element_class    form;
        window_element_class   *element;
        window_class(void);
       ~window_class(void);
        void process(void);
        void render(void);
};

#endif // WINDOW_H

/*
        location_class          title;
        color_class             title_color;
        location_class          title_bar;
        element_zoom_class      zoom;
*/
