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

#include "re_loader_dae.hpp"

namespace RoboEngine
{

    void daeDelete(re_sdaeData *&_daeData)
    {
        if (_daeData)
        {
            if (_daeData->vertex)
                delete[] _daeData->vertex;
            if (_daeData->vertex_texture)
                delete[] _daeData->vertex_texture;
            if (_daeData->vertex_normal)
                delete[] _daeData->vertex_normal;
            if (_daeData->face)
                delete[] _daeData->face;
            delete _daeData;
            _daeData = nullptr;
        }
    }

    void daeImport(const std::string &_daeFile, re_sdaeData *&_daeData)
    {
        re_sxmlData* xml_data = nullptr;
        re_xml_parse(_daeFile, xml_data);
        if (!_daeData)
            _daeData = new re_sdaeData;
    }

    void daeExport(const std::string &_daeFile, const re_sdaeData &_daeData)
    {
        /*
        if (&_daeData != nullptr)
        {
            std::ofstream file_pointer;
            file_pointer.open (_daeFile, std::ofstream::trunc | std::ofstream::out);
            file_pointer.close();
            file_pointer.open (_daeFile, std::ofstream::out | std::ofstream::app);
            if (!file_pointer.good())
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> exporting COLLADA  :  " + _daeFile);
            file_pointer << "# RoboEngine exported COLLADA File" << std::endl;
            file_pointer << "o " << _daeData.name << std::endl;
            for (uint16_t i = 0; i < _daeData.vertex_count; i++)
                file_pointer << "v " << _daeData.vertex[i].x << " " << _daeData.vertex[i].y << " " << _daeData.vertex[i].z << std::endl;
            for (uint16_t i = 0; i < _daeData.vertex_texture_count; i++)
                file_pointer << "vt " << _daeData.vertex_texture[i].x << " " << _daeData.vertex_texture[i].y << std::endl;
            for (uint16_t i = 0; i < _daeData.vertex_normal_count; i++)
                file_pointer << "vn " << _daeData.vertex_normal[i].x << " " << _daeData.vertex_normal[i].y << " " << _daeData.vertex_normal[i].z << std::endl;
            file_pointer << "s off" << _daeData.name << std::endl;
            for (uint16_t i = 0; i < _daeData.face_count; i++)
            {
                file_pointer << "f ";
                for (uint16_t j = 0; j < 3; j++)
                {
                    file_pointer << _daeData.face[i].p[j].x << "/" << _daeData.face[i].p[j].y << "/" << _daeData.face[i].p[j].z;
                    if (j < 2)
                        file_pointer << " ";
                }
                file_pointer << std::endl;
            }
            file_pointer.close();
        }
        else
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> _daeData == nullptr");
        */
    }

}
