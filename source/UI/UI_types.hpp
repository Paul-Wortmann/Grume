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

#define MOUSE_OVER_MAP             65535

#define EVENT_VALUE_NONE          -1
#define EVENT_NONE                 0
#define EVENT_ELEMENT_MOUSE_LEFT   1
#define EVENT_ELEMENT_MOUSE_RIGHT  2
#define EVENT_BUTTON_MULTIPLIER    100
#define EVENT_UI_LIST_SORT         10000
#define EVENT_UI_FORM_DRAG         10001
#define EVENT_UI_ELEMENT_DRAG      10002

#define UI_DISABLED                0
#define UI_NORMAL                  1
#define UI_HIGHLIGHTED             2

#define UI_ELEMENT_BUTTON          3
#define UI_ELEMENT_TEXTLABEL       4
#define UI_ELEMENT_IMAGE           5
#define UI_ELEMENT_SLIDER          6
#define UI_ELEMENT_BAR             7
#define UI_ELEMENT_TOGGLE          8
#define UI_ELEMENT_CHECKBOX        9
#define UI_ELEMENT_DROPDOWN        10
#define UI_ELEMENT_SELECTION       11
#define UI_ELEMENT_ITEM            12

struct event_struct
{
    int                     value;
    int                     id;
};

struct location_struct
{
    bool                    enabled;
    texture_type*           image;
    bool                    image_enabled;
    f3_type                 image_size;
    f3_type                 position;
    f3_type                 size;
    texture_type*           text;
};

struct zoom_struct
{
    bool                    enabled;
    float                   maximum;
    float                   speed;
    float                   value;
};

struct color_struct
{
    int                     r;
    int                     g;
    int                     b;
    int                     a;
};

struct color_state_struct
{
    color_struct            disabled;
    color_struct            highlighted;
    color_struct            normal;
};

struct texture_state_struct
{
    float angle;
    texture_type*           base;
    texture_type*           overlay;
    texture_type*           disabled;
    texture_type*           highlighted;
    texture_type*           normal;
};

struct tooltip_textures_type
{
    texture_type*           background;
    texture_type*           divider;
    texture_type*           header;
    texture_type*           socket;
};

struct tooltip_texture_data_type
{
    tooltip_textures_type   normal;
    tooltip_textures_type   magic;
    tooltip_textures_type   epic;
    tooltip_textures_type   setitem;
    texture_type*           bar;
    texture_type*           bar_background;
};

struct sound_struct
{
    bool                    enabled;
    sound_type*             sound;
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
    int                     maximum;
    bool                    ready;
    int                     value;
};

struct selection_data_type
{
    bool          active;
    texture_type* image;
    int           value_int;
    texture_type* value_string;
};


struct choice_selection_type
{
    selection_data_type*    data;
    int                     number_of_data;
    int                     position;
    int                     position_max;
    int                     selected;
};

struct UI_element_struct
{
    bool                    active;
    bool                    clicked;
    bool                    click_enabled;
    color_state_struct      color;
    bool                    dragable;
    bool                    drag_active;
    float                   drag_offset_x;
    float                   drag_offset_y;
    int                     element_UID;
    event_struct            event;
    font_type*              font;
    delay_struct            mouse_delay;
    bool                    overlay_enabled;
    bool                    mouse_over;
    f3_type                 position;
    f3_type                 position_origional;
    int                     quantity;
    bool                    selected;
    f3_type                 size;
    int                     state;
    sound_state_struct      sound;
    int                     sub_type;
    texture_state_struct    texture;
    location_struct         title;
    location_struct         tooltip;
    int                     type;
    float                   value;
    float                   value_max;
    int                     window_UID;
    zoom_struct             zoom;
};

struct UI_form_data_struct
{
    choice_selection_type*  choice_selection;
    color_state_struct      color;
    bool                    drag_active;
    bool                    drag_enabled;
    float                   drag_offset_x;
    float                   drag_offset_y;
    bool                    enabled;
    UI_element_struct*      element;
    event_struct            event;
    font_type*              font;
    delay_struct            mouse_delay;
    bool                    mouse_over_menu;
    bool                    mouse_over_title;
    int                     number_of_choice_selections;
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
};

struct UI_form_struct
{
    UI_form_data_struct     data;
    UI_form_struct*         next;
    UI_form_struct*         previous;
};

#endif // UI_TYPES_H
