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

#ifndef LOADER_OBJ_H
#define LOADER_OBJ_H

#include <string>
#include "core/graphics.hpp"

struct face_type
{
    int vertex[4];
    int vertex_texture[4];
    int vertex_normal[4];
    int count_vertices;
    int count_vertex_textures;
    int count_vertex_normals;
};


struct angle_type
{
    vertex_type translation;
    vertex_type rotation;
};

struct material_type
{
    std::string       material_name;
    float             Ns;
    vertex_type       Ka;
    vertex_type       Kd;
    vertex_type       Ks;
    float             Ni;
    float             d;
    float             illum;
    std::string       map_d;
    std::string       map_Kd;
    std::string       map_Bump;
};

struct use_material_type
{
    std::string       material_name;
    int               face_number;
};

class loader_obj_class
{
    public:
        angle_type            angle;
        std::string           model_name;
        std::string           mtllib;
        use_material_type*    use_material;
        material_type*        material;
        int                   number_of_use_materials;
        int                   number_of_materials;
        bool                  smooth_shading;
        int                   reference_ID;
        int                   number_of_vertices;
        int                   number_of_vertex_textures;
        int                   number_of_vertex_normals;
        int                   number_of_faces;
        bool                  vertex_texture_w;
        vertex_type*          vertex;
        vertex_texture_type*  vertex_texture;
        vertex_normal_type*   vertex_normal;
        face_type*            face;
        loader_obj_class(void);
       ~loader_obj_class(void);
        void                  load_mtl(std::string file_name);
        void                  save_mtl(std::string file_name);
        void                  load(std::string file_name);
        void                  save(std::string file_name);
        void                  scale(float scale_value);
        void                  scale(float scale_x, float scale_y, float scale_z);
        void                  set_angle(float x, float y, float z);
        void                  set_position(float x, float y, float z);
        void                  relocate(float x, float y, float z);
        void                  process(void);
        void                  draw(void);
};

#endif // LOADER_OBJ_H

