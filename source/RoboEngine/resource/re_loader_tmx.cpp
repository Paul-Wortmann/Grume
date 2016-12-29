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

#include <fstream>
#include <string>
#include "re_loader_tmx.hpp"

namespace RoboEngine
{

    void re_tmxDelete(re_stmxData *&_tmxData)
    {
        if (_tmxData)
        {
            if (_tmxData->layer->tile)
                delete[] _tmxData->layer->tile;
            if (_tmxData->layer)
                delete[] _tmxData->layer;
            if (_tmxData->tileset)
                delete[] _tmxData->tileset;
            delete _tmxData;
            _tmxData = nullptr;
        }
    }

    void re_tmxLoad(const std::string &_fileName, re_stmxData *&_tmxData)
    {
        re_sxmlData* xml_data = nullptr;
        re_xml_parse(_fileName, xml_data);
        if (!_tmxData)
            _tmxData = new re_stmxData;
        if (xml_data != nullptr)
        {
            // map data
            _tmxData->data.map_version = std::stof(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "version"));
            _tmxData->data.map_orientation = RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "orientation");
            _tmxData->data.map_renderorder = RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "renderorder");
            _tmxData->data.map_width = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "width"));
            _tmxData->data.map_height = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "height"));
            _tmxData->data.map_tile_width = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "tilewidth"));
            _tmxData->data.map_tile_height = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "tileheight"));
            _tmxData->data.map_nextobjectid = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "map", 1, "nextobjectid"));

            // tileset data
            uint64_t count_ts = RoboEngine::re_xml_get_count(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "tileset");
            for (uint64_t i = 0; i < count_ts; i++)
            {
                _tmxData->data.number_of_tilesets = count_ts;
                _tmxData->tileset = new re_stmxTilesetType[_tmxData->data.number_of_tilesets];
                _tmxData->tileset[i].first_gid = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "tileset", i, "firstgid"));
                _tmxData->tileset[i].name = RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "tileset", i, "name");
                _tmxData->tileset[i].tile_width = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "tileset", i, "tilewidth"));
                _tmxData->tileset[i].tile_height = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "tileset", i, "tileheight"));
                _tmxData->tileset[i].tile_count = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "tileset", i, "tilecount"));
                _tmxData->tileset[i].tile_columns = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE, "tileset", i, "columns"));

                _tmxData->tileset[i].image_source = RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "image", i, "source");
                _tmxData->tileset[i].image_width = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "image", i, "width"));
                _tmxData->tileset[i].image_height = std::stoi(RoboEngine::re_xml_get_sub_value(*xml_data, RoboEngine::XML_enum::XML_TAG_ATTRIBUTE_END, "image", i, "height"));
            }

        }
        re_xml_delete(xml_data);
    }

    void re_tmxSave(const std::string &_fileName, re_stmxData *&_tmxData)
    {
        std::fstream script_file(_fileName.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
        if (script_file.is_open())
        {
            script_file << "<?xml version=";
            script_file << '"';
            script_file << "1.0";
            //script_file << std::to_string(_tmxData->data.xml_version) << ".0";
            script_file << '"';
            script_file << " encoding=";
            script_file << '"';
            script_file << "UTF-8";
            //script_file << _tmxData->data.xml_encoding.c_str();
            script_file << '"';
            script_file << "?>";
            script_file << "\n";

            script_file << "<map version=";
            script_file << '"';
            script_file << std::to_string(_tmxData->data.map_version) << ".0";
            script_file << '"';
            script_file << " orientation=";
            script_file << '"';
            script_file << _tmxData->data.map_orientation.c_str();
            script_file << '"';
            script_file << " renderorder=";
            script_file << '"';
            script_file << _tmxData->data.map_renderorder.c_str();
            script_file << '"';
            script_file << " width=";
            script_file << '"';
            script_file << _tmxData->data.map_width;
            script_file << '"';
            script_file << " height=";
            script_file << '"';
            script_file << _tmxData->data.map_height;
            script_file << '"';
            script_file << " tilewidth=";
            script_file << '"';
            script_file << _tmxData->data.map_tile_width;
            script_file << '"';
            script_file << " tileheight=";
            script_file << '"';
            script_file << _tmxData->data.map_tile_height;
            script_file << '"';
            script_file << " nextobjectid=";
            script_file << '"';
            script_file << _tmxData->data.map_nextobjectid;
            script_file << '"';
            script_file << ">";
            script_file << "\n";

            script_file << " <properties>";
            script_file << "\n";
            script_file << "  <property name=";
            script_file << '"';
            script_file << "MAP_ID";
            script_file << '"';
            script_file << " value=";
            script_file << '"';
            script_file << "0";
            script_file << '"';
            script_file << "/>";
            script_file << "\n";
            script_file << " </properties>";
            script_file << "\n";

            for (uint32_t i = 0; i < _tmxData->data.number_of_tilesets; i++)
            {
                script_file << " <tileset firstgid=";
                script_file << '"';
                script_file << _tmxData->tileset[i].first_gid;
                script_file << '"';
                script_file << " name=";
                script_file << '"';
                script_file << _tmxData->tileset[i].name;
                script_file << '"';
                script_file << " tilewidth=";
                script_file << '"';
                script_file << _tmxData->tileset[i].tile_width;
                script_file << '"';
                script_file << " tileheight=";
                script_file << '"';
                script_file << _tmxData->tileset[i].tile_height;
                script_file << '"';
                script_file << " tilecount=";
                script_file << '"';
                script_file << _tmxData->tileset[i].tile_count;
                script_file << '"';
                script_file << " columns=";
                script_file << '"';
                script_file << _tmxData->tileset[i].tile_columns;
                script_file << '"';
                script_file << ">";
                script_file << "\n";
                script_file << "  <image source=";
                script_file << '"';
                script_file << _tmxData->tileset[i].image_source;
                script_file << '"';
                script_file << " width=";
                script_file << '"';
                script_file << _tmxData->tileset[i].image_width;
                script_file << '"';
                script_file << " height=";
                script_file << '"';
                script_file << _tmxData->tileset[i].image_height;
                script_file << '"';
                script_file << "/>";
                script_file << "\n";
                script_file << " </tileset>";
                script_file << "\n";
            }
            for (uint32_t i = 0; i < _tmxData->data.number_of_layers; i++)
            {
                script_file << " <layer name=";
                script_file << '"';
                script_file << "tile";
                script_file << '"';
                script_file << " width=";
                script_file << '"';
                script_file << _tmxData->layer[i].width;
                script_file << '"';
                script_file << " height=";
                script_file << '"';
                script_file << _tmxData->layer[i].height;
                script_file << '"';
                script_file << ">";
                script_file << "\n";
                script_file << "  <data>";
                script_file << "\n";
                for (uint32_t j = 0; j < _tmxData->data.number_of_tiles; j++)
                {
                    script_file << "   <tile gid=";
                    script_file << '"';
                    script_file << ((_tmxData->layer[i].tile[j].tile + _tmxData->tileset[_tmxData->layer[i].tile[j].tile_tileset].first_gid) - 1);
                    script_file << '"';
                    script_file << "/>";
                    script_file << "\n";
                }
                script_file << "  </data>";
                script_file << "\n";
                script_file << " </layer>";
                script_file << "\n";
            }
            script_file << "</map>";
            script_file << "\n";
            script_file.close();
        }
    }

}
