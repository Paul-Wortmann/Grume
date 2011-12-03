/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

class equipment_button_class
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
        equipment_button_class(void);
       ~equipment_button_class(void);
        void        process(void);
        void        draw(void);
};

class equipment_slot_class
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
        equipment_slot_class(void);
       ~equipment_slot_class(void);
        void        process(void);
        void        draw(void);
        void        draw_drag(void);
        void        draw_tooltip(void);
};

class equipment_class
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
        equipment_button_class close_button;
        equipment_class(void);
       ~equipment_class(void);
        void             process(void);
        void             draw(void);
};

#endif // EQUIPMENT_H

