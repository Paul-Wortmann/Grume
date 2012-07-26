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

#define DISABLED       0
#define NORMAL         1
#define HIGHLIGHTED    2

#define BUTTON         3
#define TEXTLABEL      4
#define IMAGE          5
#define SLIDER         6
#define BAR            7
#define TOGGLE         8
#define CHECKBOX       9
#define DROPDOWN       10
#define SELECTION      11

#define MAX_CHOICE_SELECTIONS_PER_MENU 8
#define MAX_CHOICE_SELECTION           16

const int MAX_ELEMENTS = 16;

class location_class
{
    private:
    public:
        std::string             text;
        float                   position_x;
        float                   position_y;
        float                   position_z;
        float                   size_x;
        float                   size_y;
        float                   size_z;
        location_class(void);
       ~location_class(void);
};

class element_zoom_class
{
    private:
    public:
        bool  enabled;
        float maximum;
        float value;
        float speed;
};

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

class texture_state_class
{
    private:
    public:
        float angle;
        int   base;
        int   normal;
        int   highlighted;
        int   disabled;
};

class delay_class
{
    private:
    public:
        bool                    ready;
        int                     value;
        int                     maximum;
        delay_class(void);
        void                    process(void);
        void                    reset(void);
};

class menu_element_class
{
    private:
    public:
        location_class          title;
        location_class          tooltip;
        int                     event;
        int                     state;
        bool                    selected;
        int                     type;
        float                   value;
        float                   value_max;
        float                   position_x;
        float                   position_y;
        float                   position_z;
        float                   size_x;
        float                   size_y;
        float                   size_z;
        bool                    mouse_over;
        bool                    active;
        bool                    clicked;
        int                     mouse_delay;
        element_zoom_class      zoom;
        color_state_class       color;
        texture_state_class     texture_ID;
        menu_element_class(void);
       ~menu_element_class(void);
        void                    render(void);
        bool                    mouse_over_element(void);
        bool                    mouse_clicked_element(void);
        int                     process(void);
};

struct selection_data_type
{
    bool    active;
    int     value;
};


struct choice_selection_type
{
    int                         selected;
    int                         position;
    int                         position_max;
    selection_data_type         data[MAX_CHOICE_SELECTION];
};

class menu_class
{
    private:
    public:
        choice_selection_type   choice_selection[MAX_CHOICE_SELECTIONS_PER_MENU];
        delay_class             mouse_delay;
        int                     event;
        location_class          title;
        color_class             title_color;
        location_class          title_bar;
        float                   position_x;
        float                   position_y;
        float                   position_z;
        float                   size_x;
        float                   size_y;
        float                   size_z;
        bool                    mouse_over;
        bool                    drag_active;
        float                   drag_offset_x;
        float                   drag_offset_y;
        element_zoom_class      zoom;
        color_state_class       color;
        texture_state_class     texture_ID;
        bool                    active;
        menu_element_class      element[MAX_ELEMENTS];
        menu_class(void);
       ~menu_class(void);
        void                    render(void);
        bool                    mouse_over_title(void);
        bool                    mouse_click_title(void);
        void                    set_position(float x_pos, float y_pos);
        int                     process(void);
};

#endif //MENU_H




