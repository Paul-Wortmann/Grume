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

#ifndef VBO_MANAGER_H
#define VBO_MANAGER_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>

struct vao_data_type
{
    bool             loaded;
};

struct vao_type
{
    vao_data_type data;
    vao_type*     next;
};

class vao_manager_class
{
    public:
        vao_manager_class(void);
       ~vao_manager_class(void);
        int           number_of_vaos;
        vao_type *root;
        vao_type *last;
        vao_type *add_vao(vao_data_type *vao_data_pointer);
        bool      load_vao(vao_type *vao_pointer);
};

#endif // VBO_MANAGER_H

