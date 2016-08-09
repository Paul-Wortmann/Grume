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

namespace RoboEngine
{

    void objDelete(re_sobjData *&_objData)
    {
        if (_objData)
        {
            if (_objData->vertex)
                delete[] _objData->vertex;
            if (_objData->vertex_texture)
                delete[] _objData->vertex_texture;
            if (_objData->vertex_normal)
                delete[] _objData->vertex_normal;
            if (_objData->face)
                delete[] _objData->face;
            delete _objData;
            _objData = nullptr;
        }
    }

    void objImport(const std::string &_objFile, re_sobjData *&_objData)
    {
        if (!_objData)
            _objData = new re_sobjData;
        std::ifstream file_pointer;
        file_pointer.open (_objFile, std::ifstream::in);
        if (!file_pointer.good())
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> importing OBJ  :  " + _objFile);
        std::string s_temp = "";
        while (std::getline(file_pointer, s_temp))
        {
            if (s_temp.length() >= 6)
            {
                if ((s_temp[0] == 'v') && (s_temp[1] == ' '))
                    _objData->vertex_count++;
                if ((s_temp[0] == 'v') && (s_temp[1] == 't'))
                    _objData->vertex_texture_count++;
                if ((s_temp[0] == 'v') && (s_temp[1] == 'n'))
                    _objData->vertex_normal_count++;
                if ((s_temp[0] == 'f') && (s_temp[1] == ' '))
                    _objData->face_count++;
            }
        }
        file_pointer.clear();
        file_pointer.seekg(0, std::ios::beg);
        _objData->vertex = new v3_f[_objData->vertex_count];
        _objData->vertex_texture = new v2_f[_objData->vertex_texture_count];
        _objData->vertex_normal = new v3_f[_objData->vertex_normal_count];
        _objData->face = new re_sobjFace[_objData->face_count];
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
                                _objData->vertex[v_count].x = stof(temp);
                            if (s_count == 2)
                                _objData->vertex[v_count].y = stof(temp);
                            if (s_count == 3)
                                _objData->vertex[v_count].z = stof(temp);
                            temp = "";
                        }
                        else
                            temp += s_temp[i];
                    }
                    _objData->vertex[v_count].z = stof(temp);
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
                                _objData->vertex_texture[vt_count].x = stof(temp);
                            if (s_count == 2)
                                _objData->vertex_texture[vt_count].y = stof(temp);
                            temp = "";
                        }
                        else
                            temp += s_temp[i];
                    }
                    _objData->vertex_texture[vt_count].y = stof(temp);
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
                                _objData->vertex_normal[vn_count].x = stof(temp);
                            if (s_count == 2)
                                _objData->vertex_normal[vn_count].y = stof(temp);
                            if (s_count == 3)
                                _objData->vertex_normal[vn_count].z = stof(temp);
                            temp = "";
                        }
                        else
                            temp += s_temp[i];
                    }
                    _objData->vertex_normal[vn_count].z = stof(temp);
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
                                _objData->face[f_count].p[s_count].x = stoi(temp);
                            if (fs_count == 2)
                                _objData->face[f_count].p[s_count].y = stoi(temp);
                            if (fs_count == 3)
                                _objData->face[f_count].p[s_count].z = stoi(temp);
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
                    _objData->face[f_count].p[s_count].z = stoi(temp);
                    f_count++;
                }
                if ((s_temp[0] == 'o') && (s_temp[1] == ' '))
                {
                    for (uint16_t i = 2; i < s_temp.length(); i++)
                    {
                        _objData->name += s_temp[i];
                    }
                }
            }
        }
        file_pointer.close();
    }

    void objExport(const std::string &_objFile, const re_sobjData &_objData)
    {
        if (&_objData != nullptr)
        {
            std::ofstream file_pointer;
            file_pointer.open (_objFile, std::ofstream::trunc | std::ofstream::out);
            file_pointer.close();
            file_pointer.open (_objFile, std::ofstream::out | std::ofstream::app);
            if (!file_pointer.good())
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> exporting OBJ  :  " + _objFile);
            file_pointer << "# RoboEngine exported OBJ File" << std::endl;
            file_pointer << "o " << _objData.name << std::endl;
            for (uint16_t i = 0; i < _objData.vertex_count; i++)
                file_pointer << "v " << _objData.vertex[i].x << " " << _objData.vertex[i].y << " " << _objData.vertex[i].z << std::endl;
            for (uint16_t i = 0; i < _objData.vertex_texture_count; i++)
                file_pointer << "vt " << _objData.vertex_texture[i].x << " " << _objData.vertex_texture[i].y << std::endl;
            for (uint16_t i = 0; i < _objData.vertex_normal_count; i++)
                file_pointer << "vn " << _objData.vertex_normal[i].x << " " << _objData.vertex_normal[i].y << " " << _objData.vertex_normal[i].z << std::endl;
            file_pointer << "s off" << _objData.name << std::endl;
            for (uint16_t i = 0; i < _objData.face_count; i++)
            {
                file_pointer << "f ";
                for (uint16_t j = 0; j < 3; j++)
                {
                    file_pointer << _objData.face[i].p[j].x << "/" << _objData.face[i].p[j].y << "/" << _objData.face[i].p[j].z;
                    if (j < 2)
                        file_pointer << " ";
                }
                file_pointer << std::endl;
            }
            file_pointer.close();
        }
        else
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> _objData == nullptr");
    }

}
