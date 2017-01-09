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
#include "../roboengine.hpp"

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
        uint64_t count_a = re_xml_get_count(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array");
        for (uint64_t i = 0; i < count_a; i++)
        {
            std::string t_value = re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "id");
            // vertices
            if (t_value.find("mesh-positions-array") != std::string::npos)
            {
                _daeData->vertex_count = std::stof(re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "count")) / 3;
                uint64_t line_no = re_xml_get_line_attribute(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1);
                const std::string data_v = xml_data->line[line_no].data[xml_data->line[line_no].attribute_count-1].value;
                _daeData->vertex = new v3_f[_daeData->vertex_count];
                uint64_t data_v_l = data_v.length();
                uint64_t current_p = 0;
                uint64_t current_v = 0;
                std::string temp_v = "";
                for (uint64_t j = 0; j < data_v_l; j++)
                {
                    if (data_v[j] != ' ')
                        temp_v += data_v[j];
                    else
                    {
                        if (current_p == 0)
                            _daeData->vertex[current_v].x = std::stof(temp_v);
                        else if (current_p == 1)
                            _daeData->vertex[current_v].y = std::stof(temp_v);
                        else if (current_p == 2)
                            _daeData->vertex[current_v].z = std::stof(temp_v);
                        temp_v = "";
                        current_p++;
                        if (current_p > 2)
                        {
                            current_p = 0;
                            current_v++;
                        }
                    }
                }
                _daeData->vertex[current_v].z = std::stof(temp_v);
            }
            // normals
            if (t_value.find("mesh-normals-array") != std::string::npos)
            {
                _daeData->vertex_normal_count = std::stof(re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "count")) / 3;
                uint64_t line_no = re_xml_get_line_attribute(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1);
                const std::string data_n = xml_data->line[line_no].data[xml_data->line[line_no].attribute_count-1].value;
                _daeData->vertex_normal = new v3_f[_daeData->vertex_normal_count];
                uint64_t data_n_l = data_n.length();
                uint64_t current_p = 0;
                uint64_t current_n = 0;
                std::string temp_n = "";
                for (uint64_t j = 0; j < data_n_l; j++)
                {
                    if (data_n[j] != ' ')
                        temp_n += data_n[j];
                    else
                    {
                        if (current_p == 0)
                            _daeData->vertex_normal[current_n].x = std::stof(temp_n);
                        else if (current_p == 1)
                            _daeData->vertex_normal[current_n].y = std::stof(temp_n);
                        else if (current_p == 2)
                            _daeData->vertex_normal[current_n].z = std::stof(temp_n);
                        temp_n = "";
                        current_p++;
                        if (current_p > 2)
                        {
                            current_p = 0;
                            current_n++;
                        }
                    }
                }
                _daeData->vertex_normal[current_n].z = std::stof(temp_n);
            }
            // texture coords
            if (t_value.find("mesh-map-0-array") != std::string::npos)
            {
                _daeData->vertex_texture_count = std::stof(re_xml_get_sub_value(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1, "count")) / 2;
                uint64_t line_no = re_xml_get_line_attribute(*xml_data, XML_enum::XML_TAG_ATTRIBUTE_TEXT, "float_array", i+1);
                const std::string data_t = xml_data->line[line_no].data[xml_data->line[line_no].attribute_count-1].value;
                _daeData->vertex_texture = new v2_f[_daeData->vertex_texture_count];
                uint64_t data_t_l = data_t.length();
                uint64_t current_p = 0;
                uint64_t current_t = 0;
                std::string temp_t = "";
                for (uint64_t j = 0; j < data_t_l; j++)
                {
                    if (data_t[j] != ' ')
                        temp_t += data_t[j];
                    else
                    {
                        if (current_p == 0)
                            _daeData->vertex_texture[current_t].x = std::stof(temp_t);
                        else if (current_p == 1)
                            _daeData->vertex_texture[current_t].y = std::stof(temp_t);
                        temp_t = "";
                        current_p++;
                        if (current_p > 1)
                        {
                            current_p = 0;
                            current_t++;
                        }
                    }
                }
                _daeData->vertex_texture[current_t].y = std::stof(temp_t);
            }
        }
        // faces
        uint64_t line_v = re_xml_get_line_value(*xml_data, XML_enum::XML_TAG_TEXT, "p", 1);
        const std::string data_f = xml_data->line[line_v].data[xml_data->line[line_v].attribute_count-1].value;
        _daeData->face_count = (std::count( data_f.begin(), data_f.end(), ' ' ) + 1) / 3;
        _daeData->face = new v8_f[_daeData->face_count];
        uint64_t data_f_l = data_f.length();
        uint64_t current_p = 0;
        uint64_t current_f = 0;
        std::string temp_f = "";
        for (uint64_t j = 0; j < data_f_l; j++)
        {
            if (data_f[j] != ' ')
                temp_f += data_f[j];
            else
            {
                if (current_p == 0)
                {
                    _daeData->face[current_f].x = _daeData->vertex[std::stoi(temp_f)].x;
                    _daeData->face[current_f].y = _daeData->vertex[std::stoi(temp_f)].y;
                    _daeData->face[current_f].z = _daeData->vertex[std::stoi(temp_f)].z;
                }
                else if (current_p == 1)
                {
                    _daeData->face[current_f].nx = _daeData->vertex_normal[std::stoi(temp_f)].x;
                    _daeData->face[current_f].ny = _daeData->vertex_normal[std::stoi(temp_f)].y;
                    _daeData->face[current_f].nz = _daeData->vertex_normal[std::stoi(temp_f)].z;
                }
                else if (current_p == 2)
                {
                    _daeData->face[current_f].s = _daeData->vertex_texture[std::stoi(temp_f)].x;
                    _daeData->face[current_f].t = _daeData->vertex_texture[std::stoi(temp_f)].y;
                }
                temp_f = "";
                current_p++;
                if (current_p > 2)
                {
                    current_p = 0;
                    current_f++;
                }
            }
        }
        _daeData->face[current_f].s = _daeData->vertex_texture[std::stoi(temp_f)].x;
        _daeData->face[current_f].t = _daeData->vertex_texture[std::stoi(temp_f)].y;
        re_xml_delete(xml_data);
    }

    void daeExport(const std::string &_daeFile, const re_sdaeData &_daeData)
    {
        // Not yet a requirement for the engine, but may be implemented in the future on request.
        re_logWrite("ERROR -> not yet implemented. " + _daeFile + " - " + _daeData.name, RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
    }

}
