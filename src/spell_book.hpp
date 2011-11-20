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

#ifndef SPELL_BOOK_H
#define SPELL_BOOK_H

class spell_slot_class
{
    public:
        int   click_delay;
        int   click_delay_count;
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
        float base_pos_x;
        float base_pos_y;
        float width;
        float height;
        spell_slot_class(void);
       ~spell_slot_class(void);
        void process(void);
        void draw(void);
        void draw_tooltip(void);
};

class spell_book_class
{
    public:
        float pos_x;
        float pos_y;
        float pos_z;
        float width;
        float height;
        spell_slot_class spell_slot_01;
        spell_slot_class spell_slot_02;
        spell_slot_class spell_slot_03;
        spell_slot_class spell_slot_04;
        spell_slot_class spell_slot_05;
        spell_slot_class spell_slot_06;
        spell_slot_class spell_slot_07;
        spell_slot_class spell_slot_08;
        spell_slot_class spell_slot_09;
        spell_slot_class spell_slot_10;
        spell_slot_class spell_slot_11;
        spell_slot_class spell_slot_12;
        spell_slot_class spell_slot_13;
        spell_slot_class spell_slot_14;
        spell_slot_class spell_slot_15;
        spell_slot_class spell_slot_16;
        spell_slot_class spell_slot_17;
        spell_slot_class spell_slot_18;
        spell_slot_class spell_slot_19;
        spell_slot_class spell_slot_20;
        spell_book_class(void);
       ~spell_book_class(void);
        void process(void);
        void draw(void);
};

#endif // SPELL_BOOK_H

