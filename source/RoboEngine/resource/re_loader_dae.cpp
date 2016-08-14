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
        if (xml_data != nullptr)
        {
            uint32_t count_a = re_xml_get_count(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array");
            for (uint32_t i = 0; i < count_a; i++)
            {
                std::string t_value = re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "id");
                if (t_value.find("mesh-positions-array") != std::string::npos)
                {
                    uint32_t count_v = std::stof(re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "count"));
                    std:: cout << "found : mesh-positions-array - count : " << std::to_string(count_v) << std::endl;
                }
                if (t_value.find("mesh-normals-array") != std::string::npos)
                {
                    uint32_t count_n = std::stof(re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "count"));
                    std:: cout << "found : mesh-normals-array - count : " << std::to_string(count_n) << std::endl;
                }
                if (t_value.find("mesh-map-0-array") != std::string::npos)
                {
                    uint32_t count_t = std::stof(re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "count"));
                    std:: cout << "found : mesh-map-0-array - count : " << std::to_string(count_t) << std::endl;
                }
            }
        }



//        RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "float_array count  :  " + std::to_string(count_a));

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
