/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
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
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "re_obj_loader.hpp"
#include "re_xml_parser.hpp"
#include "../system/re_log.hpp"
#include <fstream>
#include <iostream>

namespace RoboEngine
{

    void obj_delete(obj_data_s *&obj_data)
    {
        if (obj_data)
        {
            if (obj_data->vertex)
                delete[] obj_data->vertex;
            if (obj_data->vertex_texture)
                delete[] obj_data->vertex_texture;
            if (obj_data->vertex_normal)
                delete[] obj_data->vertex_normal;
            if (obj_data->face)
                delete[] obj_data->face;
            delete obj_data;
            obj_data = nullptr;
        }
    }

    void obj_import(const std::string &s_obj_file, obj_data_s *&obj_data)
    {
        if (!obj_data)
            obj_data = new obj_data_s;
        std::ifstream file_pointer;
        file_pointer.open (s_obj_file, std::ifstream::in);
        if (!file_pointer.good())
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> importing OBJ  :  " + s_obj_file);
        std::string s_temp = "";
        while (std::getline(file_pointer, s_temp))
        {
            if (s_temp.length() >= 6)
            {
                if ((s_temp[0] == 'v') && (s_temp[1] == ' '))
                    obj_data->vertex_count++;
                if ((s_temp[0] == 'v') && (s_temp[1] == 't'))
                    obj_data->vertex_texture_count++;
                if ((s_temp[0] == 'v') && (s_temp[1] == 'n'))
                    obj_data->vertex_normal_count++;
                if ((s_temp[0] == 'f') && (s_temp[1] == ' '))
                    obj_data->face_count++;
            }
        }
        file_pointer.clear();
        file_pointer.seekg(0, std::ios::beg);
        obj_data->vertex = new v3_f[obj_data->vertex_count];
        obj_data->vertex_texture = new v2_f[obj_data->vertex_texture_count];
        obj_data->vertex_normal = new v3_f[obj_data->vertex_normal_count];
        obj_data->face = new obj_face_s[obj_data->face_count];
        uint16_t v_count = 0;
        uint16_t vt_count = 0;
        uint16_t vn_count = 0;
        uint16_t f_count = 0;
        while (std::getline(file_pointer, s_temp))
        {
            if (s_temp.length() >= 6)
            {
                if ((s_temp[0] == 'v') && (s_temp[1] == ' '))
                {
                    uint8_t s_count = 0;
                    std::string temp = "";
                    for (uint16_t i = 2; i < s_temp.length(); i++)
                    {
                        if (s_temp[i] == ' ')
                        {
                            s_count++;
                            if (s_count == 1)
                                obj_data->vertex[v_count].x = stof(temp);
                            if (s_count == 2)
                                obj_data->vertex[v_count].y = stof(temp);
                            if (s_count == 3)
                                obj_data->vertex[v_count].z = stof(temp);
                            temp = "";
                        }
                        else
                            temp += s_temp[i];
                    }
                    obj_data->vertex[v_count].z = stof(temp);
                    v_count++;
                }
                if ((s_temp[0] == 'v') && (s_temp[1] == 't'))
                {
                    uint8_t s_count = 0;
                    std::string temp = "";
                    for (uint16_t i = 3; i < s_temp.length(); i++)
                    {
                        if (s_temp[i] == ' ')
                        {
                            s_count++;
                            if (s_count == 1)
                                obj_data->vertex_texture[vt_count].x = stof(temp);
                            if (s_count == 2)
                                obj_data->vertex_texture[vt_count].y = stof(temp);
                            temp = "";
                        }
                        else
                            temp += s_temp[i];
                    }
                    obj_data->vertex_texture[vt_count].y = stof(temp);
                    vt_count++;
                }
                if ((s_temp[0] == 'v') && (s_temp[1] == 'n'))
                {
                    uint8_t s_count = 0;
                    std::string temp = "";
                    for (uint16_t i = 3; i < s_temp.length(); i++)
                    {
                        if (s_temp[i] == ' ')
                        {
                            s_count++;
                            if (s_count == 1)
                                obj_data->vertex_normal[vn_count].x = stof(temp);
                            if (s_count == 2)
                                obj_data->vertex_normal[vn_count].y = stof(temp);
                            if (s_count == 3)
                                obj_data->vertex_normal[vn_count].z = stof(temp);
                            temp = "";
                        }
                        else
                            temp += s_temp[i];
                    }
                    obj_data->vertex_normal[vn_count].z = stof(temp);
                    vn_count++;
                }
                if ((s_temp[0] == 'f') && (s_temp[1] == ' '))
                {
                    uint8_t s_count = 0;
                    uint8_t fs_count = 0;
                    std::string temp = "";
                    for (uint16_t i = 2; i < s_temp.length(); i++)
                    {
                        if ((s_temp[i] == '/') || (s_temp[i] == ' '))
                        {
                            fs_count++;
                            if (fs_count == 1)
                                obj_data->face[f_count].p[s_count].x = stoi(temp);
                            if (fs_count == 2)
                                obj_data->face[f_count].p[s_count].y = stoi(temp);
                            if (fs_count == 3)
                                obj_data->face[f_count].p[s_count].z = stoi(temp);
                            temp = "";
                            if (s_temp[i] == ' ')
                            {
                                fs_count = 0;
                                s_count++;
                            }
                        }
                        else
                            temp += s_temp[i];
                    }
                    obj_data->face[f_count].p[s_count].z = stoi(temp);
                    f_count++;
                }
                if ((s_temp[0] == 'o') && (s_temp[1] == ' '))
                {
                    for (uint16_t i = 2; i < s_temp.length(); i++)
                    {
                        obj_data->name += s_temp[i];
                    }
                }
            }
        }
        file_pointer.close();
    }

    void obj_export(const std::string &s_obj_file, const obj_data_s &obj_data)
    {
        if (&obj_data != nullptr)
        {
            std::ofstream file_pointer;
            file_pointer.open (s_obj_file, std::ofstream::trunc | std::ofstream::out);
            file_pointer.close();
            file_pointer.open (s_obj_file, std::ofstream::out | std::ofstream::app);
            if (!file_pointer.good())
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> exporting OBJ  :  " + s_obj_file);
            file_pointer << "# RoboEngine exported OBJ File" << std::endl;
            file_pointer << "o " << obj_data.name << std::endl;
            for (uint16_t i = 0; i < obj_data.vertex_count; i++)
                file_pointer << "v " << obj_data.vertex[i].x << " " << obj_data.vertex[i].y << " " << obj_data.vertex[i].z << std::endl;
            for (uint16_t i = 0; i < obj_data.vertex_texture_count; i++)
                file_pointer << "vt " << obj_data.vertex_texture[i].x << " " << obj_data.vertex_texture[i].y << std::endl;
            for (uint16_t i = 0; i < obj_data.vertex_normal_count; i++)
                file_pointer << "vn " << obj_data.vertex_normal[i].x << " " << obj_data.vertex_normal[i].y << " " << obj_data.vertex_normal[i].z << std::endl;
            file_pointer << "s off" << obj_data.name << std::endl;
            for (uint16_t i = 0; i < obj_data.face_count; i++)
            {
                file_pointer << "f ";
                for (uint16_t j = 0; j < 3; j++)
                {
                    file_pointer << obj_data.face[i].p[j].x << "/" << obj_data.face[i].p[j].y << "/" << obj_data.face[i].p[j].z;
                    if (j < 2)
                        file_pointer << " ";
                }
                file_pointer << std::endl;
            }
            file_pointer.close();
        }
        else
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> obj_data == nullptr");
    }

}
