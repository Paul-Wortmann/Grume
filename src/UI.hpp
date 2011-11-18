/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of Star.P.G.
 *
 * Star.P.G. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Star.P.G. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Star.P.G. If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.co.nr
 * @license GPL
 * @date 2011-10-01
 */

#ifndef UI_H
#define UI_H

class player_stats_class
{
    public:
        bool  highlighted;
        bool  drag;
        int   portrait;
        int   mouse_over_count;
        int   tooltip_time;
        bool  tooltip_active;
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        float mana;
        float health;
        player_stats_class(void);
       ~player_stats_class(void);
        void process(void);
        void draw(void);
};

class action_slot_class
{
    public:
        bool  highlighted;
        bool  drag;
        int   button_type;
        bool  mouse_over;
        int   mouse_over_count;
        int   tooltip_time;
        bool  tooltip_active;
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        action_slot_class(void);
       ~action_slot_class(void);
        void process(void);
        void draw(void);
        void draw_tooltip(void);
};

class menu_slot_class
{
    public:
        bool  highlighted;
        bool  drag;
        int   button_type;
        bool  mouse_over;
        int   mouse_over_count;
        int   tooltip_time;
        bool  tooltip_active;
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        menu_slot_class(void);
       ~menu_slot_class(void);
        void process(void);
        void draw(void);
        void draw_tooltip(void);
};

class action_bar_class
{
    public:
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        menu_slot_class menu_slot_01;
        menu_slot_class menu_slot_02;
        menu_slot_class menu_slot_03;
        menu_slot_class menu_slot_04;
        menu_slot_class menu_slot_05;
        menu_slot_class menu_slot_06;
        action_slot_class action_slot_01;
        action_slot_class action_slot_02;
        action_slot_class action_slot_03;
        action_slot_class action_slot_04;
        action_slot_class action_slot_05;
        action_slot_class action_slot_06;
        action_slot_class action_slot_07;
        action_slot_class action_slot_08;
        action_slot_class action_slot_09;
        action_slot_class action_slot_10;
        void process(void);
        void draw(void);
        action_bar_class(void);
       ~action_bar_class(void);
};

class UI_class
{
    public:
        player_stats_class player_stats;
        action_bar_class   action_bar;
        void process(void);
        void draw(void);
        UI_class(void);
       ~UI_class(void);
};

#endif // UI_H

