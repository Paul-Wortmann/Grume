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

#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

class window_class
{
    protected:
    private:
    public:
        int   UID;
        bool  active;
        bool  mouse_over;
        float size_x;
        float size_y;
        float size_z;
        float position_x;
        float position_y;
        float position_z;
        window_class(void);
       ~window_class(void);
};

class window_manager_class
{
    protected:
    private:
    public:
        int   number_of_windows;
        float mouse_x;
        float mouse_y;
        window_class *window;
        window_manager_class(void);
       ~window_manager_class(void);
        void set_active_window(int UID);
        int  get_active_window(void);
        int  register_window(int UID);
        int  register_window(int UID_minimum, int UID_maximum);
        void de_register_window(int UID);
        bool mouse_in_quadrangle  (float qx, float qy, float qw, float qh);
        void process(void);
};

#endif // WINDOW_MANAGER_H
