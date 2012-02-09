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

#include "loader_obj.hpp"
#include "../game.hpp"
#include "../misc.hpp"

extern game_type         game;

loader_obj_class::loader_obj_class(void)
{
    loader_obj_class::wrap_texture              =  false;
    loader_obj_class::wrap_texture_ID           =  0;
    loader_obj_class::reference_ID              =  0;
    loader_obj_class::number_of_use_materials   = -1;
    loader_obj_class::number_of_materials       = -1;
    loader_obj_class::number_of_vertices        = -1;
    loader_obj_class::number_of_faces           = -1;
    loader_obj_class::number_of_vertex_textures = -1;
    loader_obj_class::number_of_vertex_normals  = -1;
    loader_obj_class::angle.rotation.x          =  0.0f;
    loader_obj_class::angle.rotation.y          =  0.0f;
    loader_obj_class::angle.rotation.z          =  0.0f;
    loader_obj_class::angle.translation.x       =  0.0f;
    loader_obj_class::angle.translation.y       =  0.0f;
    loader_obj_class::angle.translation.z       =  0.0f;
    loader_obj_class::vertex_texture_w          =  false;
}

loader_obj_class::~loader_obj_class(void)
{

}

void loader_obj_class::set_wrap_texture(int texture_ID)
{
    if (texture_ID > -1)
    {
        loader_obj_class::wrap_texture              =  true;
        loader_obj_class::wrap_texture_ID           =  texture_ID;
    }
    else
    {
        loader_obj_class::wrap_texture              =  false;
        loader_obj_class::wrap_texture_ID           =  0;
    }
};

void loader_obj_class::load_mtl(std::string file_name)
{
    loader_obj_class::number_of_materials       = -1;
    int          number_of_materials_count      = -1;
    int          data_count                     =  0;
    int          position_count                 =  0;
    std::string  temp_string_data;
    std::string  data_line;
    //determine max values first
    std::fstream script_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (script_file.is_open())
    {
        while (script_file.good())
        {
            getline(script_file,data_line);
            {
                switch (data_line[0])
                {
                    case 'n': // material name.
                        loader_obj_class::number_of_materials++;
                    break;
                    default:
                    break;
                }
            }
        }
        script_file.clear();
        script_file.seekg(0, std::ios::beg);
        loader_obj_class::material = new material_type[loader_obj_class::number_of_materials+1];
        // load data
        while (script_file.good())
        {
            getline(script_file,data_line);
            {
                position_count = 0;
                switch (data_line[0])
                {
                    case '#': // comment, nothing to load.
                    break;
                    case 'n': // material name.
                        number_of_materials_count++;
                        position_count = 7;
                        temp_string_data = "";
                        while (position_count <= data_line.length())
                        {
                            temp_string_data += data_line[position_count];
                            position_count++;
                        }
                        loader_obj_class::material[number_of_materials_count].material_name = temp_string_data.c_str();
                    break;
                    case 'N': //
                        switch (data_line[1])
                        {
                            case 's': //
                                position_count = 3;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    temp_string_data += data_line[position_count];
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].Ns = atof(temp_string_data.c_str());
                            break;
                            case 'i': //
                                position_count = 3;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    temp_string_data += data_line[position_count];
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].Ni = atof(temp_string_data.c_str());
                            break;
                            default:
                            break;
                        }
                    break;
                    case 'K': //
                        switch (data_line[1])
                        {
                            case 'a': //
                                position_count = 3;
                                data_count     = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if (data_line[position_count] != ' ')
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_count == 0) loader_obj_class::material[number_of_materials_count].Ka.x = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::material[number_of_materials_count].Ka.y = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].Ka.z = atof(temp_string_data.c_str());
                            break;
                            case 'd': //
                                position_count = 3;
                                data_count     = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if (data_line[position_count] != ' ')
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_count == 0) loader_obj_class::material[number_of_materials_count].Kd.x = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::material[number_of_materials_count].Kd.y = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].Kd.z = atof(temp_string_data.c_str());
                            break;
                            case 's': //
                                position_count = 3;
                                data_count     = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if (data_line[position_count] != ' ')
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_count == 0) loader_obj_class::material[number_of_materials_count].Ks.x = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::material[number_of_materials_count].Ks.y = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].Ks.z = atof(temp_string_data.c_str());
                            break;
                            default:
                            break;
                        }
                    break;
                    case 'd': //
                        position_count = 2;
                        temp_string_data = "";
                        while (position_count <= data_line.length())
                        {
                            temp_string_data += data_line[position_count];
                            position_count++;
                        }
                        loader_obj_class::material[number_of_materials_count].d = atof(temp_string_data.c_str());
                    break;
                    case 'i': //
                        position_count = 6;
                        temp_string_data = "";
                        while (position_count <= data_line.length())
                        {
                            temp_string_data += data_line[position_count];
                            position_count++;
                        }
                        loader_obj_class::material[number_of_materials_count].illum = atof(temp_string_data.c_str());
                    break;
                    case 'm': //
                        switch (data_line[4])
                        {
                            case 'd': //
                                position_count = 6;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    temp_string_data += data_line[position_count];
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].map_d = temp_string_data.c_str();
                            break;
                            case 'K': //
                                position_count = 7;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    temp_string_data += data_line[position_count];
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].map_Kd = temp_string_data.c_str();
                            break;
                            case 'B': //
                                position_count = 9;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    temp_string_data += data_line[position_count];
                                    position_count++;
                                }
                                loader_obj_class::material[number_of_materials_count].map_Bump = temp_string_data.c_str();
                            break;
                            default:
                            break;
                        }
                    break;
                    default:
                    break;
                }
            }
        }
        script_file.close();
    }
};

void loader_obj_class::save_mtl(std::string file_name)
{
    std::fstream script_file(file_name.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
    if (script_file.is_open())
    {
        script_file << "# Frost and Flame OBJ File: '";
        script_file << file_name;
        script_file << "'\n";
        script_file << "# www.physhexgames.co.nr\n";
        script_file << "# Material Count: ";
        script_file << loader_obj_class::number_of_materials+1;
        script_file << "\n";
        for (int material_count = 0; material_count < loader_obj_class::number_of_materials+1; material_count++)
        {
            script_file << "newmtl ";
            script_file << loader_obj_class::material[material_count].material_name;
            script_file << "\n";
            script_file << "Ns ";
            script_file << loader_obj_class::material[material_count].Ns;
            script_file << "\n";
            script_file << "Ka ";
            script_file << loader_obj_class::material[material_count].Ka.x;
            script_file << " ";
            script_file << loader_obj_class::material[material_count].Ka.y;
            script_file << " ";
            script_file << loader_obj_class::material[material_count].Ka.z;
            script_file << "\n";
            script_file << "Kd ";
            script_file << loader_obj_class::material[material_count].Kd.x;
            script_file << " ";
            script_file << loader_obj_class::material[material_count].Kd.y;
            script_file << " ";
            script_file << loader_obj_class::material[material_count].Kd.z;
            script_file << "\n";
            script_file << "Ks ";
            script_file << loader_obj_class::material[material_count].Ks.x;
            script_file << " ";
            script_file << loader_obj_class::material[material_count].Ks.y;
            script_file << " ";
            script_file << loader_obj_class::material[material_count].Ks.z;
            script_file << "\n";
            script_file << "Ni ";
            script_file << loader_obj_class::material[material_count].Ni;
            script_file << "\n";
            script_file << "d ";
            script_file << loader_obj_class::material[material_count].d;
            script_file << "\n";
            script_file << "illum ";
            script_file << loader_obj_class::material[material_count].illum;
            script_file << "\n";
            script_file << "map_d ";
            script_file << loader_obj_class::material[material_count].map_d;
            script_file << "\n";
            script_file << "map_Kd ";
            script_file << loader_obj_class::material[material_count].map_Kd;
            script_file << "\n";
            script_file << "map_Bump ";
            script_file << loader_obj_class::material[material_count].map_Bump;
            script_file << "\n";
            script_file << "\n";
            script_file << "\n";
        }
        script_file.close();
    }
};

void loader_obj_class::load(std::string file_name, int obj_ID)
{
    loader_obj_class::reference_ID =  obj_ID;
    loader_obj_class::load(file_name);
};

void loader_obj_class::load(std::string file_name)
{
    loader_obj_class::number_of_vertices         = -1;
    loader_obj_class::number_of_vertex_textures  = -1;
    loader_obj_class::number_of_vertex_normals   = -1;
    loader_obj_class::number_of_use_materials    = -1;
    loader_obj_class::number_of_faces            = -1;
    int          number_of_vertices_count        =  0;
    int          number_of_vertex_textures_count =  0;
    int          number_of_vertex_normals_count  =  0;
    int          number_of_use_materials_count   =  0;
    int          number_of_faces_count           =  0;
    int          slash_count                     =  0;
    bool         count_slashes                   =  true;
    int          data_count                      =  0;
    int          data_count_v                    =  0;
    int          data_count_vt                   =  0;
    int          data_count_vn                   =  0;
    int          position_count                  =  0;
    int          position_start                  =  0;
    char         temp_char                       =  ' ';
    float        temp_float_data;
    int          temp_int_data;
    bool         temp_bool_data;
    std::string  temp_string_data;
    std::string  temp_string_key;
    std::string  temp_string_value;
    std::string  data_line;
    //determine max values first
    std::fstream script_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (script_file.is_open())
    {
        while (script_file.good())
        {
            getline(script_file,data_line);
            {
                switch (data_line[0])
                {
                    case 'v':
                        switch (data_line[1])
                        {
                            case ' ': // vertex data
                                loader_obj_class::number_of_vertices++;
                            break;
                            case 't': // vertex texture data
                                loader_obj_class::number_of_vertex_textures++;
                            break;
                            case 'n': // vertex normal data
                                loader_obj_class::number_of_vertex_normals++;
                            break;
                            default:
                            break;
                        }
                    break;
                    case 'u': // use material data.
                        loader_obj_class::number_of_use_materials++;
                    break;
                    case 'f': // face data.
                        loader_obj_class::number_of_faces++;
                    break;
                    default:
                    break;
                }
            }
        }
        script_file.clear();
        script_file.seekg(0, std::ios::beg);
        loader_obj_class::vertex         = new vertex_type[loader_obj_class::number_of_vertices+1];
        loader_obj_class::vertex_texture = new vertex_texture_type[loader_obj_class::number_of_vertex_textures+1];
        loader_obj_class::vertex_normal  = new vertex_normal_type[loader_obj_class::number_of_vertex_normals+1];
        loader_obj_class::use_material   = new use_material_type[loader_obj_class::number_of_use_materials+1];
        loader_obj_class::face           = new face_type[loader_obj_class::number_of_faces+1];
        // load data
        while (script_file.good())
        {
            getline(script_file,data_line);
            {
                switch (data_line[0])
                {
                    case '#': // comment, nothing to load.
                    break;
                    case 'o': // load object name.
                        position_count = 2;
                        temp_string_data = "";
                        while (position_count <= data_line.length())
                        {
                            temp_string_data += data_line[position_count];
                            position_count++;
                        }
                        loader_obj_class::model_name = temp_string_data.c_str();
                    break;
                    case 'm': // load material file name.
                        position_count = 7;
                        temp_string_data = "";
                        while (position_count <= data_line.length())
                        {
                            temp_string_data += data_line[position_count];
                            position_count++;
                        }
                        loader_obj_class::mtllib = temp_string_data.c_str();
                    break;
                    case 'v': // load vertex data
                        switch (data_line[1])
                        {
                            case ' ': // load vertex data
                                position_count = 2;
                                data_count     = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if (data_line[position_count] != ' ')
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_count == 0) loader_obj_class::vertex[number_of_vertices_count].x = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::vertex[number_of_vertices_count].y = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                loader_obj_class::vertex[number_of_vertices_count].z = atof(temp_string_data.c_str());
                                number_of_vertices_count++;
                            break;
                            case 't': // load vertex texture data
                                position_count = 3;
                                data_count     = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if (data_line[position_count] != ' ')
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_count == 0) loader_obj_class::vertex_texture[number_of_vertex_textures_count].u = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::vertex_texture[number_of_vertex_textures_count].v = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                if (data_count == 1) loader_obj_class::vertex_texture[number_of_vertex_textures_count].v = atof(temp_string_data.c_str());
                                if (data_count == 2) loader_obj_class::vertex_texture[number_of_vertex_textures_count].w = atof(temp_string_data.c_str());
                                if (data_count == 2) loader_obj_class::vertex_texture_w = true;
                                number_of_vertex_textures_count++;
                            break;
                            case 'n': // load vertex normal data
                                position_count = 3;
                                data_count     = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if (data_line[position_count] != ' ')
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_count == 0) loader_obj_class::vertex_normal[number_of_vertex_normals_count].i = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::vertex_normal[number_of_vertex_normals_count].j = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                if (data_count == 1) loader_obj_class::vertex_normal[number_of_vertex_normals_count].j = atof(temp_string_data.c_str());
                                if (data_count == 2) loader_obj_class::vertex_normal[number_of_vertex_normals_count].k = atof(temp_string_data.c_str());
                                number_of_vertex_normals_count++;
                            break;
                            default:
                            break;
                        }
                    break;
                    case 'u': // load material to use after this point.
                        position_count = 7;
                        temp_string_data = "";
                        while (position_count <= data_line.length())
                        {
                            temp_string_data += data_line[position_count];
                            position_count++;
                        }
                        loader_obj_class::use_material[number_of_use_materials_count].material_name = temp_string_data.c_str();
                        loader_obj_class::use_material[number_of_use_materials_count].face_number   = number_of_faces_count;
                        number_of_use_materials_count++;
                    break;
                    case 's': // load smooth shading state.
                        if (data_line[3] == 'n') loader_obj_class::smooth_shading = true;
                        if (data_line[3] == 'f') loader_obj_class::smooth_shading = false;
                        if (data_line[2] == '1') loader_obj_class::smooth_shading = true;
                        if (data_line[2] == '0') loader_obj_class::smooth_shading = false;
                    break;
                    case 'f': // load face data.
                        if (count_slashes)
                        {
                            slash_count    = 0;
                            position_count = 2;
                            while ((position_count < data_line.length()) && (data_line[position_count] != ' '))
                            {
                                if (data_line[position_count] == '/') slash_count++;
                                position_count++;
                            }
                            count_slashes = false;
                        }
                        switch (slash_count)
                        {
                            case 0: // only vertex data
                                position_count   = 2;
                                data_count       = 0;
                                data_count_v     = 0;
                                data_count_vt    = 0;
                                data_count_vn    = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if (data_line[position_count] != ' ')
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        loader_obj_class::face[number_of_faces_count].vertex[data_count_v] = atoi(temp_string_data.c_str())-1;
                                        data_count_v++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                loader_obj_class::face[number_of_faces_count].count_vertices         = data_count_v;
                                loader_obj_class::face[number_of_faces_count].count_vertex_textures  = -1;
                                loader_obj_class::face[number_of_faces_count].count_vertex_normals   = -1;
                                loader_obj_class::face[number_of_faces_count].vertex[data_count_v]   = atoi(temp_string_data.c_str())-1;
                            break;
                            case 1: // vertex data and vertex texture data
                                position_count   = 2;
                                data_count       = 0;
                                data_count_v     = 0;
                                data_count_vt    = 0;
                                data_count_vn    = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if ((data_line[position_count] != ' ') && (data_line[position_count] != '/'))
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_line[position_count] == '/')
                                        {
                                            loader_obj_class::face[number_of_faces_count].vertex[data_count_v] = atoi(temp_string_data.c_str())-1;
                                            data_count_v++;
                                            temp_string_data = "";
                                        }
                                        if (data_line[position_count] == ' ')
                                        {
                                            loader_obj_class::face[number_of_faces_count].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str())-1;
                                            data_count_vt++;
                                            temp_string_data = "";
                                        }
                                    }
                                    position_count++;
                                }
                                loader_obj_class::face[number_of_faces_count].count_vertices         = data_count_v;
                                loader_obj_class::face[number_of_faces_count].count_vertex_textures  = data_count_vt;
                                loader_obj_class::face[number_of_faces_count].count_vertex_normals   = -1;
                                loader_obj_class::face[number_of_faces_count].vertex_texture[data_count_vt]   = atoi(temp_string_data.c_str())-1;
                            break;
                            case 2: // vertex data, vertex texture data and vertex normal data
                                position_count   = 2;
                                data_count       = 0;
                                data_count_v     = 0;
                                data_count_vt    = 0;
                                data_count_vn    = 0;
                                temp_string_data = "";
                                while (position_count <= data_line.length())
                                {
                                    if ((data_line[position_count] != ' ') && (data_line[position_count] != '/'))
                                    {
                                        temp_string_data += data_line[position_count];
                                    }
                                    else
                                    {
                                        if (data_line[position_count] == '/')
                                        {
                                            if (data_count == 0)
                                            {
                                                loader_obj_class::face[number_of_faces_count].vertex[data_count_v] = atoi(temp_string_data.c_str())-1;
                                                data_count_v++;
                                                temp_string_data = "";
                                                data_count = 1;
                                            }
                                            else
                                            {
                                                loader_obj_class::face[number_of_faces_count].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str())-1;
                                                data_count_vt++;
                                                temp_string_data = "";
                                                data_count = 0;
                                            }
                                        }
                                        if (data_line[position_count] == ' ')
                                        {
                                            loader_obj_class::face[number_of_faces_count].vertex_normal[data_count_vn] = atoi(temp_string_data.c_str())-1;
                                            data_count_vn++;
                                            temp_string_data = "";
                                        }
                                    }
                                    position_count++;
                                }
                                loader_obj_class::face[number_of_faces_count].count_vertices         = data_count_v;
                                loader_obj_class::face[number_of_faces_count].count_vertex_textures  = data_count_vt;
                                loader_obj_class::face[number_of_faces_count].count_vertex_normals   = data_count_vn;
                                loader_obj_class::face[number_of_faces_count].vertex_normal[data_count_vn]   = atoi(temp_string_data.c_str())-1;
                            break;
                        }
                        number_of_faces_count++;
                    break;
                    default:
                    break;
                }
            }
        }
        script_file.close();
        loader_obj_class::mtllib = game.core.file.path_get(file_name.c_str()) + loader_obj_class::mtllib;
        loader_obj_class::load_mtl(loader_obj_class::mtllib); // load the material data file for this object
        //create VBO ?? Hmmm
    }
    else game.core.log.File_Write("Failed to load OBJ file - ",file_name.c_str());
};

void loader_obj_class::save(std::string file_name)
{
    if (game.core.file.extension_exist(file_name,"obj")) file_name = game.core.file.extension_remove(file_name);
    if (loader_obj_class::number_of_materials >= 0) loader_obj_class::save_mtl(game.core.file.extension_add(file_name,".mtl"));
    file_name = game.core.file.extension_add(file_name,".obj");
    std::fstream script_file(file_name.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
    if (script_file.is_open())
    {
        script_file << "# Frost and Flame OBJ File: '";
        script_file << file_name;
        script_file << "'\n";
        script_file << "# www.physhexgames.co.nr\n";
        script_file << "mtllib ";
        script_file << loader_obj_class::mtllib;
        script_file << "\n";
        script_file << "o ";
        script_file << loader_obj_class::model_name;
        script_file << "\n";
        for (int vertex_count = 0; vertex_count <= loader_obj_class::number_of_vertices; vertex_count++)
        {
            script_file << "v ";
            script_file << loader_obj_class::vertex[vertex_count].x;
            script_file << " ";
            script_file << loader_obj_class::vertex[vertex_count].y;
            script_file << " ";
            script_file << loader_obj_class::vertex[vertex_count].z;
            script_file << "\n";
        }
        if (loader_obj_class::number_of_vertex_textures > 0)
        {
            for (int vertex_count = 0; vertex_count <= loader_obj_class::number_of_vertex_textures; vertex_count++)
            {
                script_file << "vt ";
                script_file << loader_obj_class::vertex_texture[vertex_count].u;
                script_file << " ";
                script_file << loader_obj_class::vertex_texture[vertex_count].v;
                if (loader_obj_class::vertex_texture_w)
                {
                    script_file << " ";
                    script_file << loader_obj_class::vertex_texture[vertex_count].w;
                }
                script_file << "\n";
            }
        }
        if (loader_obj_class::number_of_vertex_normals > 0)
        {
            for (int vertex_count = 0; vertex_count <= loader_obj_class::number_of_vertex_normals; vertex_count++)
            {
                script_file << "vn ";
                script_file << loader_obj_class::vertex_normal[vertex_count].i;
                script_file << " ";
                script_file << loader_obj_class::vertex_normal[vertex_count].j;
                script_file << " ";
                script_file << loader_obj_class::vertex_normal[vertex_count].k;
                script_file << "\n";
            }
        }
        for (int face_count = 0; face_count <= loader_obj_class::number_of_faces; face_count++)
        {
            if (loader_obj_class::number_of_use_materials >= 0)
            {
                for(int material_count = 0; material_count < loader_obj_class::number_of_use_materials; material_count++)
                {
                    if (loader_obj_class::use_material[material_count].face_number == face_count)
                    {
                        script_file << "usemtl ";
                        script_file << loader_obj_class::use_material[material_count].material_name;
                        script_file << "\n";
                        script_file << "s ";
                        if (loader_obj_class::smooth_shading) script_file << "on";
                        else  script_file << "off";
                        script_file << "\n";
                    }
                }
            }
            script_file << "f ";
            if (loader_obj_class::face[face_count].count_vertices >= 0)
            {
                script_file << loader_obj_class::face[face_count].vertex[0]+1;
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals == -1))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[0]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[0]+1;
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[0]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures == -1) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[0]+1;
                }
                script_file << " ";
            }
            if (loader_obj_class::face[face_count].count_vertices >= 1)
            {
                script_file << loader_obj_class::face[face_count].vertex[1]+1;
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals == -1))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[1]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[1]+1;
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[1]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures == -1) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[1]+1;
                }
                script_file << " ";
            }
            if (loader_obj_class::face[face_count].count_vertices >= 2)
            {
                script_file << loader_obj_class::face[face_count].vertex[2]+1;
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals == -1))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[2]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[2]+1;
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[2]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures == -1) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[2]+1;
                }
                script_file << " ";
            }
            if (loader_obj_class::face[face_count].count_vertices >= 3)
            {
                script_file << loader_obj_class::face[face_count].vertex[3]+1;
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals == -1))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[3]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures > 0) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_texture[3]+1;
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[3]+1;
                }
                if ((loader_obj_class::number_of_vertex_textures == -1) && (loader_obj_class::number_of_vertex_normals > 0))
                {
                    script_file << "/";
                    script_file << "/";
                    script_file << loader_obj_class::face[face_count].vertex_normal[3]+1;
                }
            }
            script_file << "\n";
        }
        script_file.close();
    }
}

void loader_obj_class::scale(float scale_value)
{
    for (int vertex_count = 0; vertex_count <=  loader_obj_class::number_of_vertices; vertex_count++)
    {
        loader_obj_class::vertex[vertex_count].x *= scale_value;
        loader_obj_class::vertex[vertex_count].y *= scale_value;
        loader_obj_class::vertex[vertex_count].z *= scale_value;
    }
};

void loader_obj_class::scale(float scale_x, float scale_y, float scale_z)
{
    for (int vertex_count = 0; vertex_count <= loader_obj_class::number_of_vertices; vertex_count++)
    {
        loader_obj_class::vertex[vertex_count].x *= scale_x;
        loader_obj_class::vertex[vertex_count].y *= scale_y;
        loader_obj_class::vertex[vertex_count].z *= scale_z;
    }
};


void loader_obj_class::set_angle(float x, float y, float z)
{
    loader_obj_class::angle.rotation.x = x;
    loader_obj_class::angle.rotation.y = y;
    loader_obj_class::angle.rotation.z = z;
}

void loader_obj_class::set_position(float x, float y, float z)
{
    loader_obj_class::angle.translation.x = x;
    loader_obj_class::angle.translation.y = y;
    loader_obj_class::angle.translation.z = z;
}

void loader_obj_class::relocate(float x, float y, float z) // relocate vertex 0
{
    float temp_x = loader_obj_class::vertex[0].x - x;
    float temp_y = loader_obj_class::vertex[0].y - y;
    float temp_z = loader_obj_class::vertex[0].z - z;
    loader_obj_class::vertex[0].x = x;
    loader_obj_class::vertex[0].y = y;
    loader_obj_class::vertex[0].z = z;
    for (int vertex_count = 1; vertex_count <=  loader_obj_class::number_of_vertices; vertex_count++)
    {
        loader_obj_class::vertex[vertex_count].x -= temp_x;
        loader_obj_class::vertex[vertex_count].y -= temp_y;
        loader_obj_class::vertex[vertex_count].z -= temp_z;
    }
};

void loader_obj_class::process(void)
{

}

void loader_obj_class::draw(void)
{
    glPushMatrix();
    loader_obj_class::draw(0.0f,0.0f,0.0f);
    glPopMatrix();
}

void loader_obj_class::draw(float x, float y, float z)
{
    glEnable(GL_DEPTH_TEST);
    if (loader_obj_class::wrap_texture)
    {
        bind_texture(loader_obj_class::wrap_texture_ID);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }
    /*
    else
    {
    // add support here to load texture from material file....
    }
    */
    glRotatef(loader_obj_class::angle.rotation.x,1,0,0);
    glRotatef(loader_obj_class::angle.rotation.y,0,1,0);
    glRotatef(loader_obj_class::angle.rotation.z,0,0,1);
    glTranslatef(loader_obj_class::angle.translation.x,loader_obj_class::angle.translation.y,loader_obj_class::angle.translation.z);
    for (int face_count = 0; face_count <= loader_obj_class::number_of_faces; face_count++)
    {
        if (loader_obj_class::face[face_count].count_vertices == 4) // face is a quadrangle
        {
            glBegin(GL_QUADS);
                // Vertex 1
                if (loader_obj_class::number_of_vertex_normals > 0) glNormal3f(loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[0]].i,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[0]].j,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[0]].k);
                else glNormal3f( 0.0f, 0.0f, 1.0f);
                if (loader_obj_class::number_of_vertex_textures > 0) glTexCoord2i(loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[0]].u,loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[0]].v);
                else glTexCoord2i( 0, 1);
                glVertex3f(loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[0]].x+x,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[0]].y+y,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[0]].z+z);
                // Vertex 2
                if (loader_obj_class::number_of_vertex_normals > 0) glNormal3f(loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[1]].i,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[1]].j,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[1]].k);
                else glNormal3f( 0.0f, 0.0f, 1.0f);
                if (loader_obj_class::number_of_vertex_textures > 0) glTexCoord2i(loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[1]].u,loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[1]].v);
                else glTexCoord2i( 0, 0 );
                glVertex3f(loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[1]].x+x,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[1]].y+y,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[1]].z+z);
                // Vertex 3
                if (loader_obj_class::number_of_vertex_normals > 0) glNormal3f(loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[2]].i,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[2]].j,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[2]].k);
                else glNormal3f( 0.0f, 0.0f, 1.0f);
                if (loader_obj_class::number_of_vertex_textures > 0) glTexCoord2i(loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[2]].u,loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[2]].v);
                else glTexCoord2i( 1, 0 );
                glVertex3f(loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[2]].x+x,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[2]].y+y,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[2]].z+z);
                // Vertex 4
                if (loader_obj_class::number_of_vertex_normals > 0) glNormal3f(loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[3]].i,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[3]].j,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[3]].k);
                else glNormal3f( 0.0f, 0.0f, 1.0f);
                if (loader_obj_class::number_of_vertex_textures > 0) glTexCoord2i(loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[3]].u,loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[3]].v);
                else glTexCoord2i( 1, 1 );
                glVertex3f(loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[3]].x+x,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[3]].y+y,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[3]].z+z);
            glEnd();
        }
        if (loader_obj_class::face[face_count].count_vertices == 3) // face is a triangle
        {
            glBegin(GL_TRIANGLES);
                // Vertex 1
                if (loader_obj_class::number_of_vertex_normals > 0) glNormal3f(loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[0]].i,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[0]].j,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[0]].k);
                else glNormal3f( 0.0f, 0.0f, 1.0f);
                if (loader_obj_class::number_of_vertex_textures > 0) glTexCoord2i(loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[0]].u,loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[0]].v);
                else glTexCoord2i( 0, 1);
                glVertex3f(loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[0]].x+x,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[0]].y+y,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[0]].z+z);
                // Vertex 2
                if (loader_obj_class::number_of_vertex_normals > 0) glNormal3f(loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[1]].i,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[1]].j,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[1]].k);
                else glNormal3f( 0.0f, 0.0f, 1.0f);
                if (loader_obj_class::number_of_vertex_textures > 0) glTexCoord2i(loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[1]].u,loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[1]].v);
                else glTexCoord2i( 0, 0 );
                glVertex3f(loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[1]].x+x,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[1]].y+y,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[1]].z+z);
                // Vertex 3
                if (loader_obj_class::number_of_vertex_normals > 0) glNormal3f(loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[2]].i,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[2]].j,loader_obj_class::vertex_normal[loader_obj_class::face[face_count].vertex_normal[2]].k);
                else glNormal3f( 0.0f, 0.0f, 1.0f);
                if (loader_obj_class::number_of_vertex_textures > 0) glTexCoord2i(loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[2]].u,loader_obj_class::vertex_texture[loader_obj_class::face[face_count].vertex_texture[2]].v);
                else glTexCoord2i( 1, 0 );
                glVertex3f(loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[2]].x+x,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[2]].y+y,loader_obj_class::vertex[loader_obj_class::face[face_count].vertex[2]].z+z);
            glEnd();
        }
    }
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
}


