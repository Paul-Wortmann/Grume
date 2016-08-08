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

#ifndef RE_XML_PARSER_HPP
#define RE_XML_PARSER_HPP

#include <string>
#include <cstdint>

namespace RoboEngine
{

    enum class XML_enum : uint16_t { XML_NONE, XML_TAG_START, XML_TAG_END, XML_COMMENT, XML_DECLARATION, XML_TAG_TEXT, XML_TAG_ATTRIBUTE, XML_TAG_ATTRIBUTE_END };

    struct xml_attribute_data_s
    {
        std::string attribute = "";
        std::string value = "";
    };

    struct xml_line_data_s
    {
        XML_enum data_type = XML_enum::XML_NONE;
        uint8_t attribute_count = 0;
        uint8_t indentation = 0;
        xml_attribute_data_s* data = nullptr;
    };

    struct xml_data_s
    {
        uint16_t line_count = 0;
        xml_line_data_s* line = nullptr;
    };

    void xml_delete(xml_data_s *&xml_data);
    xml_line_data_s xml_line_parse(const std::string &s_xml_line, uint8_t &indentation);
    void xml_parse(const std::string &s_xml_file, xml_data_s *&xml_data);
    void xml_export(const std::string &s_xml_file, const xml_data_s &xml_data);
    std::string xml_get_value(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute, uint16_t attribute_no);
    std::string xml_get_sub_value(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute, uint16_t attribute_no, const std::string &sub_attribute);
    uint16_t  xml_get_count(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute);
    xml_line_data_s* xml_get_line(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute, uint16_t attribute_count);

}

#endif // RE_XML_PARSER_HPP



