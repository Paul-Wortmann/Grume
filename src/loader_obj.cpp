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

#include "loader_obj.hpp"
#include "game.hpp"

extern game_type         game;

loader_obj_class::loader_obj_class(void)
{
    loader_obj_class::reference_ID              = 0;
    loader_obj_class::number_of_vertices        = 0;
    loader_obj_class::number_of_faces           = 0;
    loader_obj_class::number_of_vertex_textures = 0;
    loader_obj_class::number_of_vertex_normals  = 0;
}

loader_obj_class::~loader_obj_class(void)
{

}

void loader_obj_class::load(std::string file_name)
{
    loader_obj_class::reference_ID              = 0;
    loader_obj_class::number_of_vertices        = 0;
    loader_obj_class::number_of_vertex_textures = 0;
    loader_obj_class::number_of_vertex_normals  = 0;
    loader_obj_class::number_of_faces           = 0;
    int          slash_count     = 0;
    bool         count_slashes   = true;
    int          data_count      = 0;
    int          data_count_v    = 0;
    int          data_count_vt   = 0;
    int          data_count_vn   = 0;
    int          position_count  = 0;
    int          position_start  = 0;
    char         temp_char       = ' ';
    float        temp_float_data;
    int          temp_int_data;
    bool         temp_bool_data;
    std::string  temp_string_data;
    std::string  temp_string_key;
    std::string  temp_string_value;
    std::string  data_line;
    std::fstream script_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (script_file.is_open())
    {
        while (script_file.good())
        {
            getline(script_file,data_line);
            {
                switch (data_line[0])
                {
                    case '#': // comment, nothing to load.
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
                                        if (data_count == 0) loader_obj_class::vertex[number_of_vertices+1].x = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::vertex[number_of_vertices+1].y = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                loader_obj_class::vertex[number_of_vertices+1].z = atof(temp_string_data.c_str());
                                loader_obj_class::number_of_vertices++;
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
                                        if (data_count == 0) loader_obj_class::vertex_texture[number_of_vertices+1].x = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::vertex_texture[number_of_vertices+1].y = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                if (data_count == 1) loader_obj_class::vertex_texture[number_of_vertices+1].y = atof(temp_string_data.c_str());
                                if (data_count == 2) loader_obj_class::vertex_texture[number_of_vertices+1].z = atof(temp_string_data.c_str());
                                loader_obj_class::number_of_vertex_textures++;
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
                                        if (data_count == 0) loader_obj_class::vertex_normal[number_of_vertices+1].x = atof(temp_string_data.c_str());
                                        if (data_count == 1) loader_obj_class::vertex_normal[number_of_vertices+1].y = atof(temp_string_data.c_str());
                                        data_count++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                if (data_count == 1) loader_obj_class::vertex_normal[number_of_vertices+1].y = atof(temp_string_data.c_str());
                                if (data_count == 2) loader_obj_class::vertex_normal[number_of_vertices+1].z = atof(temp_string_data.c_str());
                                loader_obj_class::number_of_vertex_normals++;
                            break;
                            default:
                            break;
                        }
                    break;
                    case 'f': // load face data.
                        if (count_slashes)
                        {
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
                                        if (data_count_v == 0) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                        if (data_count_v == 1) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                        if (data_count_v == 2) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                        if (data_count_v == 3) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                        data_count_v++;
                                        temp_string_data = "";
                                    }
                                    position_count++;
                                }
                                if (data_count_v == 2) loader_obj_class::face[number_of_faces+1].vertex[data_count_v]   = atoi(temp_string_data.c_str());
                                if (data_count_v == 2) loader_obj_class::face[number_of_faces+1].vertex[data_count_v+1] = 0;
                                if (data_count_v == 3) loader_obj_class::face[number_of_faces+1].vertex[data_count_v]   = atoi(temp_string_data.c_str());
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
                                            if (data_count_v == 0) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            if (data_count_v == 1) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            if (data_count_v == 2) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            if (data_count_v == 3) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            data_count_v++;
                                            temp_string_data = "";
                                        }
                                        if (data_line[position_count] == ' ')
                                        {
                                            if (data_count_vt == 0) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            if (data_count_vt == 1) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            if (data_count_vt == 2) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            if (data_count_vt == 3) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            data_count_vt++;
                                            temp_string_data = "";
                                        }
                                    }
                                    position_count++;
                                }
                                if (data_count_vt == 2) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt]   = atoi(temp_string_data.c_str());
                                if (data_count_vt == 2) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt+1] = 0;
                                if (data_count_vt == 2) loader_obj_class::face[number_of_faces+1].vertex[data_count_v+1] = 0;
                                if (data_count_vt == 3) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt]   = atoi(temp_string_data.c_str());
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
                                        if ((data_line[position_count] == '/') && (data_count == 0))
                                        {
                                            if (data_count_v == 0) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            if (data_count_v == 1) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            if (data_count_v == 2) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            if (data_count_v == 3) loader_obj_class::face[number_of_faces+1].vertex[data_count_v] = atoi(temp_string_data.c_str());
                                            data_count_v++;
                                            temp_string_data = "";
                                            data_count++;
                                        }
                                        if ((data_line[position_count] == '/') && (data_count == 1))
                                        {
                                            if (data_count_vt == 0) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            if (data_count_vt == 1) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            if (data_count_vt == 2) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            if (data_count_vt == 3) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_vt] = atoi(temp_string_data.c_str());
                                            data_count_vt++;
                                            temp_string_data = "";
                                            data_count = 0;
                                        }
                                        if (data_line[position_count] == ' ')
                                        {
                                            if (data_count_vn == 0) loader_obj_class::face[number_of_faces+1].vertex_normal[data_count_vn] = atoi(temp_string_data.c_str());
                                            if (data_count_vn == 1) loader_obj_class::face[number_of_faces+1].vertex_normal[data_count_vn] = atoi(temp_string_data.c_str());
                                            if (data_count_vn == 2) loader_obj_class::face[number_of_faces+1].vertex_normal[data_count_vn] = atoi(temp_string_data.c_str());
                                            if (data_count_vn == 3) loader_obj_class::face[number_of_faces+1].vertex_normal[data_count_vn] = atoi(temp_string_data.c_str());
                                            data_count_vn++;
                                            temp_string_data = "";
                                        }
                                    }
                                    position_count++;
                                }
                                if (data_count_vn == 2) loader_obj_class::face[number_of_faces+1].vertex_normal[data_count_vt]   = atoi(temp_string_data.c_str());
                                if (data_count_vn == 2) loader_obj_class::face[number_of_faces+1].vertex_normal[data_count_vt+1] = 0;
                                if (data_count_vn == 2) loader_obj_class::face[number_of_faces+1].vertex_texture[data_count_v+1] = 0;
                                if (data_count_vn == 2) loader_obj_class::face[number_of_faces+1].vertex[data_count_v+1] = 0;
                                if (data_count_vn == 3) loader_obj_class::face[number_of_faces+1].vertex_normal[data_count_vt]   = atoi(temp_string_data.c_str());
                            break;
                        }
                        loader_obj_class::number_of_faces++;
                    break;
                    default:
                    break;
                }
            }
        }
        script_file.close();
    }
    game.core.log.File_Write("OBJ file loaded           - ",file_name.c_str());
    game.core.log.File_Write("Number of vertices        - ",loader_obj_class::number_of_vertices);
    game.core.log.File_Write("Number of vertex textures - ",loader_obj_class::number_of_vertex_textures);
    game.core.log.File_Write("Number of vertex normals  - ",loader_obj_class::number_of_vertex_normals);
    game.core.log.File_Write("Number of faces           - ",loader_obj_class::number_of_faces);
};

void loader_obj_class::scale(float scale_value)
{
    for (int vertex_count = 0; vertex_count <=  loader_obj_class::number_of_vertices; vertex_count++)
    {
        loader_obj_class::vertex[vertex_count].x *= scale_value;
        loader_obj_class::vertex[vertex_count].y *= scale_value;
        loader_obj_class::vertex[vertex_count].z *= scale_value;
    }
    for (int vertex_count = 0; vertex_count <=  loader_obj_class::number_of_vertex_textures; vertex_count++)
    {
        loader_obj_class::vertex_texture[vertex_count].x *= scale_value;
        loader_obj_class::vertex_texture[vertex_count].y *= scale_value;
        loader_obj_class::vertex_texture[vertex_count].z *= scale_value;
    }
    for (int vertex_count = 0; vertex_count <=  loader_obj_class::number_of_vertex_normals; vertex_count++)
    {
        loader_obj_class::vertex_normal[vertex_count].x *= scale_value;
        loader_obj_class::vertex_normal[vertex_count].y *= scale_value;
        loader_obj_class::vertex_normal[vertex_count].z *= scale_value;
    }
};

void loader_obj_class::process(void)
{

}

void loader_obj_class::draw(void)
{
    for (int face_count = 0; face_count <=  loader_obj_class::number_of_vertex_normals; face_count++)
    {

    }
}

















