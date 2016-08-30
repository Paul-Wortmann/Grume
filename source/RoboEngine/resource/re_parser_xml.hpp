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

#ifndef RE_PARSER_XML_HPP
#define RE_PARSER_XML_HPP

#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include "../system/re_log.hpp"

namespace RoboEngine
{

    enum class XML_enum : uint32_t { XML_NONE, XML_TAG_START, XML_TAG_END, XML_TAG_SLASH, XML_COMMENT, XML_DECLARATION, XML_TAG_TEXT, XML_TAG_ATTRIBUTE, XML_TAG_ATTRIBUTE_END, XML_TAG_ATTRIBUTE_TEXT };

    struct re_sxmlAttributeData
    {
        std::string attribute = "";
        std::string value = "";
    };

    struct re_sxmlLineData
    {
        XML_enum data_type = XML_enum::XML_NONE;
        uint64_t attribute_count = 0;
        uint64_t indentation = 0;
        re_sxmlAttributeData* data = nullptr;
    };

    struct re_sxmlData
    {
        uint64_t line_count = 0;
        re_sxmlLineData* line = nullptr;
    };

    void re_xml_delete(re_sxmlData *&xml_data);
    re_sxmlLineData re_xml_line_parse(const std::string &_xml_line, uint64_t &_indentation);
    void re_xml_parse(const std::string &_xml_file, re_sxmlData *&_xml_data);
    void re_xml_export(const std::string &_xml_file, const re_sxmlData &_xml_data);
    std::string re_xml_get_value(const re_sxmlData &_xml_data, XML_enum _data_type, const std::string &_attribute, uint64_t _attribute_no);
    std::string re_xml_get_sub_value(const re_sxmlData &_xml_data, XML_enum _data_type, const std::string &_attribute, uint64_t _attribute_no, const std::string &_sub_attribute);
    uint64_t re_xml_get_count(const re_sxmlData &_xml_data, XML_enum _data_type, const std::string &_attribute);
    uint64_t re_xml_get_count_value(const re_sxmlData &_xml_data, XML_enum _data_type, const std::string &_value);
    uint64_t re_xml_get_line_attribute(const re_sxmlData &_xml_data, XML_enum _data_type, const std::string &_attribute, uint64_t _attribute_no);
    uint64_t re_xml_get_line_value(const re_sxmlData &_xml_data, XML_enum _data_type, const std::string &_value, uint64_t _value_no);
    re_sxmlLineData* re_xml_get_line(const re_sxmlData &_xml_data, XML_enum _data_type, const std::string &_attribute, uint64_t _attribute_count);

}

#endif // RE_PARSER_XML_HPP



