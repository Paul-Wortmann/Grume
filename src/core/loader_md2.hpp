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

#ifndef LOADER_MD2_H
#define LOADER_MD2_H

#include <string>
#include "graphics.hpp"

struct md2_face_type
{
    int vertex[4];
    int vertex_texture[4];
    int vertex_normal[4];
    int count_vertices;
    int count_vertex_textures;
    int count_vertex_normals;
};


struct md2_angle_type
{
    vertex_type translation;
    vertex_type rotation;
};

struct md2_material_type
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

struct md2_use_material_type
{
    std::string       material_name;
    int               face_number;
};

class loader_md2_class
{
    public:
        bool                      wrap_texture;
        int                       wrap_texture_ID;
        md2_angle_type            angle;
        std::string               model_name;
        std::string               mtllib;
        md2_use_material_type*    use_material;
        md2_material_type*        material;
        int                       number_of_use_materials;
        int                       number_of_materials;
        bool                      smooth_shading;
        int                       reference_ID;
        int                       number_of_vertices;
        int                       number_of_vertex_textures;
        int                       number_of_vertex_normals;
        int                       number_of_faces;
        bool                      vertex_texture_w;
        vertex_type*              vertex;
        vertex_texture_type*      vertex_texture;
        vertex_normal_type*       vertex_normal;
        md2_face_type*            face;
        loader_md2_class(void);
       ~loader_md2_class(void);
        void                  set_wrap_texture(int texture_ID);
        void                  load(std::string file_name);
        void                  load(std::string file_name, int md2_ID);
        void                  save(std::string file_name);
        void                  scale(float scale_value);
        void                  scale(float scale_x, float scale_y, float scale_z);
        void                  set_angle(float x, float y, float z);
        void                  set_position(float x, float y, float z);
        void                  relocate(float x, float y, float z);
        void                  process(void);
        void                  draw(void);
        void                  draw(float x, float y, float z);
};

#endif // LOADER_MD2_H

