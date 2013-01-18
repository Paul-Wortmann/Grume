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
#include "../core/textures.hpp"
#include "../core/font.hpp"
#include "../core/sound.hpp"

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
#define ITEM           12

#define MAX_CHOICE_SELECTIONS_PER_MENU 8
#define MAX_CHOICE_SELECTION           16

struct struct_3f
{
    float x;
    float y;
    float z;
};

class location_class
{
    private:
    public:
        bool                    enabled;
        std::string             text;
        struct_3f               size;
        struct_3f               position;
        bool                    image_enabled;
        std::string             image_path;
        texture_class           image;
        struct_3f               image_size;
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
    texture_class           image;
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
    texture_class image;
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
        location_class          title;
        location_class          tooltip;
        int                     event;
        int                     state;
        bool                    selected;
        int                     type;
        float                   value;
        float                   value_max;
        bool                    mouse_over;
        bool                    active;
        bool                    clicked;
        bool                    click_enabled;
        bool                    dragable;
        delay_class             mouse_delay;
        struct_3f               size;
        struct_3f               position;
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
        bool                    mouse_over_element(void);
        bool                    mouse_clicked_element(void);
        int                     process(void);
};

#endif // WINDOW_ELEMENT_H
