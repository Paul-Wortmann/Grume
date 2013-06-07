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

#ifndef UI_TYPES_H
#define UI_TYPES_H

#include <string>
#include "../core/font_manager.hpp"
#include "../core/sound_manager.hpp"
#include "../core/texture_manager.hpp"
#include "../core/types.hpp"

#define EVENT_NONE                0
#define EVENT_ELEMENT_MOUSE_LEFT  1
#define EVENT_ELEMENT_MOUSE_RIGHT 2
#define EVENT_ELEMENT_DRAG        3
#define EVENT_BUTTON_MULTIPLIER   100
#define EVENT_UI_STACK_SORT       10000

#define DISABLED        0
#define NORMAL          1
#define HIGHLIGHTED     2

#define BUTTON          3
#define TEXTLABEL       4
#define IMAGE           5
#define SLIDER          6
#define BAR             7
#define TOGGLE          8
#define CHECKBOX        9
#define DROPDOWN        10
#define SELECTION       11
#define ITEM            12

struct event_struct
{
    int             id;
};

struct location_struct
{
    bool                    enabled;
    std::string             text;
    f3_type                 size;
    f3_type                 position;
    bool                    image_enabled;
    texture_type           *image;
    f3_type                 image_size;
};

struct zoom_struct
{
    bool  enabled;
    float maximum;
    float value;
    float speed;
};

struct color_struct
{
    int r;
    int g;
    int b;
    int a;
};

struct color_state_struct
{
    color_struct normal;
    color_struct highlighted;
    color_struct disabled;
};

struct texture_state_struct
{
    float angle;
    texture_type   *base;
    texture_type   *normal;
    texture_type   *highlighted;
    texture_type   *disabled;
};

struct sound_struct
{
    bool                    enabled;
    sound_type             *sound;
};

struct sound_state_struct
{
    sound_struct            on_click;
    sound_struct            on_mouse_over;
    sound_struct            on_move;
    sound_struct            on_use;
};

struct delay_struct
{
    bool                    enabled;
    bool                    ready;
    int                     value;
    int                     maximum;
};

struct UI_element_struct
{
    int                     window_UID;
    int                     element_UID;
    location_struct         title;
    location_struct         tooltip;
    event_struct            event;
    int                     state;
    bool                    selected;
    int                     type;
    int                     sub_type;
    int                     quantity;
    float                   value;
    float                   value_max;
    bool                    mouse_over;
    bool                    active;
    bool                    clicked;
    bool                    click_enabled;
    bool                    dragable;
    bool                    drag_active;
    float                   drag_offset_x;
    float                   drag_offset_y;
    delay_struct            mouse_delay;
    f3_type                 size;
    f3_type                 position;
    f3_type                 position_origional;
    zoom_struct             zoom;
    color_state_struct      color;
    sound_state_struct      sound;
    texture_state_struct    texture;
    font_type              *font;
};

struct UI_form_struct
{
    UI_form_struct         *next;
    UI_form_struct         *previous;
    bool                    active;
    color_state_struct      color;
    bool                    drag_active;
    bool                    drag_enabled;
    float                   drag_offset_x;
    float                   drag_offset_y;
    bool                    enabled;
    event_struct            event;
    font_type              *font;
    delay_struct            mouse_delay;
    bool                    mouse_over_menu;
    bool                    mouse_over_title;
    int                     number_of_elements;
    f3_type                 position;
    bool                    set_behind;
    f3_type                 size;
    sound_state_struct      sound;
    texture_state_struct    texture;
    location_struct         title;
    location_struct         title_bar;
    color_struct            title_color;
    int                     UID;
    zoom_struct             zoom;
    UI_element_struct      *element;
    //choice_selection_type   choice_selection[MAX_CHOICE_SELECTIONS_PER_MENU];
};

#endif // UI_TYPES_H
