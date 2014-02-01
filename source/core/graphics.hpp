/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef GRAPHICS_H
#define GRAPHICS_H

struct light_type
{
    float            intensity_R;
    float            intensity_G;
    float            intensity_B;
    float            intensity_A;
    bool             increase;
    float            speed;
};

struct vertex_type
{
    float x;
    float y;
    float z;
};

struct vertex_texture_type
{
    float u;
    float v;
    float w;
};

struct vertex_normal_type
{
    float i;
    float j;
    float k;
};

class graphics_class
{
    private:
        int resolution_x;
        int resolution_y;
    public:
              graphics_class(void);
        void  set_resolution(int x_res, int y_res);
        int   get_resolution_x(void);
        int   get_resolution_y(void);
        int   gl_to_res(float gl_coord, int max_res);
        float res_to_gl(int  res_coord, int max_res);
        void  init_gl(int x_res, int y_res);
        void  init_gl(void);
        bool  init_sdl(void);
};

#endif //GRAPHICS_H
