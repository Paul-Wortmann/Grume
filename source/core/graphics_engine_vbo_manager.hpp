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

struct vbo_data_type
{
    bool             loaded;
    std::string      file;
};

struct vbo_type
{
    vbo_data_type data;
    vbo_type*     next;
};

class vbo_manager_class
{
    public:
        vbo_manager_class(void);
       ~vbo_manager_class(void);
        int           number_of_vbos;
        vbo_type *root;
        vbo_type *last;
        vbo_type *add_vbo(std::string file_name);
        bool      load_vbo(vbo_type *vbo_pointer);
};

#endif // VBO_MANAGER_H

