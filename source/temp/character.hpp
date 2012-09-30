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

#ifndef CHARACTER_H
#define CHARACTER_H

class character_check_box_class
{
    public:
        int         image_true_normal;
        int         image_true_highlighted;
        int         image_false_normal;
        int         image_false_highlighted;
        bool        state;
        bool        mouse_over;
        bool        activated;
        float       pos_x;
        float       pos_y;
        float       pos_z;
        float       width;
        float       height;
        character_check_box_class(void);
       ~character_check_box_class(void);
        void        process(void);
        void        draw(void);
};

class character_button_class
{
    public:
        //std::string caption;
        int         image_normal;
        int         image_highlighted;
        bool        mouse_over;
        bool        activated;
        float       pos_x;
        float       pos_y;
        float       pos_z;
        float       width;
        float       height;
        character_button_class(void);
       ~character_button_class(void);
        void        process(void);
        void        draw(void);
};

class character_slot_class
{
    public:
        int         click_delay;
        int         click_delay_count;
        bool        highlighted;
        bool        drag;
        int         button_type;
        bool        mouse_over;
        int         mouse_over_count;
        int         tooltip_time;
        bool        tooltip_active;
        float       pos_x;
        float       pos_y;
        float       pos_z;
        float       base_pos_x;
        float       base_pos_y;
        float       width;
        float       height;
        float       drag_offset_x;
        float       drag_offset_y;
        character_slot_class(void);
       ~character_slot_class(void);
        void        process(void);
        void        draw(void);
        void        draw_drag(void);
        void        draw_tooltip(void);
};

class character_class
{
    public:
        bool             mouse_over;
        bool             drag;
        float            pos_x;
        float            pos_y;
        float            pos_z;
        float            width;
        float            height;
        float            drag_offset_x;
        float            drag_offset_y;
        character_button_class    close_button;
        character_check_box_class auto_points_box;
        character_class(void);
       ~character_class(void);
        void             process(void);
        void             draw(void);
};

#endif // CHARACTER_H

