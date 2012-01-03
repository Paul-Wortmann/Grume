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

#ifndef LOADER_OBJ_H
#define LOADER_OBJ_H

#include <string>

const int MAX_VERTICES = 256;
const int MAX_FACES    = 256;

struct vertex_type
{
    float x;
    float y;
    float z;
};

struct face_type
{
    int vertex[4];
    int vertex_texture[4];
    int vertex_normal[4];
};

class loader_obj_class
{
    public:
        int                reference_ID;
        int                number_of_vertices;
        int                number_of_vertex_textures;
        int                number_of_vertex_normals;
        int                number_of_faces;
        vertex_type        vertex[MAX_VERTICES];
        vertex_type        vertex_texture[MAX_VERTICES];
        vertex_type        vertex_normal[MAX_VERTICES];
        face_type          face[MAX_FACES];
        loader_obj_class(void);
       ~loader_obj_class(void);
        void               load(std::string file_name);
        void               scale(float scale_value);
        void               process(void);
        void               draw(void);
};

#endif // LOADER_OBJ_H

