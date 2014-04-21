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

#ifndef LOADER_OBJ_H
#define LOADER_OBJ_H

#include <string>
#include "graphics_engine.hpp"
#include "texture_manager.hpp"

struct obj_face_type
{
    int vertex[4];
    int vertex_texture[4];
    int vertex_normal[4];
    int count_vertices;
    int count_vertex_textures;
    int count_vertex_normals;
    int material;
};

struct obj_angle_type
{
    vertex_type translation;
    vertex_type rotation;
};

struct data_material_type
{
    bool               active;
    std::string        file_name;
    texture_type      *texture;
};

struct obj_material_type
{
    std::string        material_name;
    float              Ns;    // shininess
    vertex_type        Ka;    // ambient
    vertex_type        Kd;    // diffuse
    vertex_type        Ks;    // specular
    float              Ni;    //
    float              d;     // opacity
    float              illum; // illumination
    data_material_type data_d;
    data_material_type data_Kd;
    data_material_type data_Bump;
};

class loader_obj_class
{
    public:
        bool                      wrap_texture_enabled;
        texture_type             *wrap_texture;
        obj_angle_type            angle;
        std::string               model_name;
        std::string               mtllib;
        obj_material_type*        material;
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
        obj_face_type*            face;
        loader_obj_class(void);
       ~loader_obj_class(void);
        void                  set_wrap_texture(std::string file_name);
        bool                  load_texture(std::string file_name, GLuint *texture_data);
        void                  load_mtl(std::string file_name);
        void                  save_mtl(std::string file_name);
        void                  load(std::string file_name);
        void                  load(std::string file_name, int obj_ID);
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

#endif // LOADER_OBJ_H

