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

#ifndef IO_H
#define IO_H

#include "rs232.hpp"

struct io_type
{
    rs232_class    rs232;
    bool           joystick_button_0;
    bool           joystick_button_1;
    bool           joystick_button_2;
    bool           joystick_button_3;
    bool           joystick_button_4;
    bool           joystick_button_5;
    bool           joystick_button_6;
    bool           joystick_button_7;
    bool           joystick_button_8;
    bool           joystick_button_9;
    bool           joystick_button_10;
    bool           joystick_button_11;
    bool           joystick_up;
    bool           joystick_down;
    bool           joystick_left;
    bool           joystick_right;
    bool           mouse_wheel_down;
    bool           mouse_wheel_up;
    bool           mouse_button_left;
    bool           mouse_button_middle;
    bool           mouse_button_right;
    bool           mouse_button_ready;
    int            mouse_button_delay;
    int            mouse_button_delay_count;
    float          mouse_x;
    float          mouse_y;
    float          mouse_xrel;
    float          mouse_yrel;
    int            joystick_sensitivity;
    bool           keyboard_ready;
    int            keyboard_delay;
    int            keyboard_delay_count;
    bool           joystick_ready;
    int            joystick_delay;
    int            joystick_delay_count;
    bool           key_0;
    bool           key_1;
    bool           key_2;
    bool           key_3;
    bool           key_4;
    bool           key_5;
    bool           key_6;
    bool           key_7;
    bool           key_8;
    bool           key_9;
    bool           key_a;
    bool           key_b;
    bool           key_c;
    bool           key_d;
    bool           key_e;
    bool           key_f;
    bool           key_g;
    bool           key_h;
    bool           key_i;
    bool           key_j;
    bool           key_k;
    bool           key_l;
    bool           key_m;
    bool           key_n;
    bool           key_o;
    bool           key_p;
    bool           key_q;
    bool           key_r;
    bool           key_s;
    bool           key_t;
    bool           key_u;
    bool           key_v;
    bool           key_w;
    bool           key_x;
    bool           key_y;
    bool           key_z;
    bool           key_up;
    bool           key_down;
    bool           key_left;
    bool           key_right;
    bool           key_space;
    bool           key_enter;
    bool           key_plus;
    bool           key_minus;
    bool           key_escape;
    bool           key_lalt;
    bool           key_lctrl;
    bool           key_lshift;
    bool           key_ralt;
    bool           key_rctrl;
    bool           key_rshift;
    bool           key_alt;
    bool           key_ctrl;
    bool           key_shift;
    bool           shoot;
    bool           select;
    bool           pause;
    bool           up;
    bool           down;
    bool           left;
    bool           right;
};

bool events_init(void);
bool events_process(void);


#endif //IO_H

