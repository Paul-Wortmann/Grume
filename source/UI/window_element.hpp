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

#ifndef WINDOW_ELEMENT_H
#define WINDOW_ELEMENT_H

#include <string>
#include "../core/texture_manager.hpp"
#include "../core/font.hpp"
#include "../core/sound.hpp"
#include "../core/types.hpp"

#define MAX_CHOICE_SELECTIONS_PER_MENU 8
#define MAX_CHOICE_SELECTION           16

#define EVENT_NONE                0
#define EVENT_ELEMENT_MOUSE_LEFT  1
#define EVENT_ELEMENT_MOUSE_RIGHT 2
#define EVENT_ELEMENT_DRAG        3
#define EVENT_ELEMENT_DROP        4
#define EVENT_ELEMENT_SWAP        5
#define EVENT_BUTTON_MULTIPLIER   100
#define EVENT_WINDOW_STACK_SORT   10000

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

#define ITEM_NONE       30
#define ITEM_RING       31
#define ITEM_NECK       32
#define ITEM_HEAD       33
#define ITEM_HAND       34
#define ITEM_FEET       35
#define ITEM_BODY       36
#define ITEM_BELT       37
#define ITEM_SHIELD     38
#define ITEM_WEAPON     39

#define ITEM_POTION     40
#define ITEM_SPELL      41
#define ITEM_SPELL_BOOK 42

#define MOUSE_OVER_MAP 65535

struct event_type
{
    int             id;
};

class location_class
{
    private:
    public:
        bool                    enabled;
        std::string             text;
        f3_type                 size;
        f3_type                 position;
        bool                    image_enabled;
        std::string             image_path;
        texture_type           *image;
        f3_type                 image_size;
        location_class(void);
       ~location_class(void);
};

struct element_zoom_struct
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

struct texture_struct
{
    std::string             image_path;
    texture_type           *image;
};

struct texture_state_struct
{
    float angle;
    texture_struct   base;
    texture_struct   normal;
    texture_struct   highlighted;
    texture_struct   disabled;
};

struct sound_struct
{
    bool                    enabled;
    std::string             sound_path;
    sound_class             sound;
};

struct sound_state_struct
{
    sound_struct            on_click;
    sound_struct            on_mouse_over;
};

class delay_class
{
    private:
    public:
        bool                    enabled;
        bool                    ready;
        int                     value;
        int                     maximum;
        delay_class(void);
        void                    process(void);
        void                    reset(void);
};

struct selection_data_type
{
    int           value_int;
    bool          active;
    texture_type *image;
    std::string   image_path;
    std::string   value_string;
};


struct choice_selection_type
{
    int                         selected;
    int                         position;
    int                         position_max;
    selection_data_type         data[MAX_CHOICE_SELECTION];
};

class window_element_class
{
    private:
    public:
        int                     window_UID;
        int                     element_UID;
        location_class          title;
        location_class          tooltip;
        event_type              event;
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
        bool                    drop_active;
        float                   drag_offset_x;
        float                   drag_offset_y;
        delay_class             mouse_delay;
        f3_type                 size;
        f3_type                 position;
        f3_type                 position_origional;
        element_zoom_struct     zoom;
        color_state_struct      color;
        sound_state_struct      sound;
        texture_state_struct    texture;
        font_class              font;
        window_element_class(void);
       ~window_element_class(void);
        void                    reload_textures(void);
        void                    render(void);
        void                    render_tooltips(void);
        void                    render_item_if_dragged(void);
        bool                    mouse_over_element(void);
        bool                    mouse_clicked_element(void);
        event_type              process(bool element_in_focus);
};

#endif // WINDOW_ELEMENT_H
