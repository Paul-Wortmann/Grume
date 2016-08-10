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

#include "re_parser_xml.hpp"

namespace RoboEngine
{

    void xml_delete(xml_data_s *&xml_data)
    {
        if (xml_data)
        {
            if (xml_data->line)
            {
                for (int16_t i = 0; i < xml_data->line_count;i++)
                    if (xml_data->line[i].data)
                        delete[] xml_data->line[i].data;
                delete[] xml_data->line;
            }
            delete xml_data;
            xml_data = nullptr;
        }
    }

    xml_line_data_s xml_line_parse(const std::string &s_xml_line, uint8_t &indentation)
    {
        bool debug = false;
        uint8_t indent_depth = 3;
        // strip leading and trailing space
        std::string s_temp = "";
        bool b_start = false;
        bool b_end  = false;
        uint16_t line_length = s_xml_line.length();
        for (uint16_t i = 0; i < line_length; i++)
        {
            if (s_xml_line[i] == '<') b_start = true;
            if ((i  > 1) && (s_xml_line[i]-1 == '>') && (s_xml_line[i] == ' ')) b_end = true;
            if (b_start && !b_end)
                    s_temp += s_xml_line[i];
        }
        //  syntax character count
        uint8_t count_a1 = 0;//    &
        uint8_t count_b1 = 0;//    <
        uint8_t count_b2 = 0;//    >
        uint8_t count_d1 = 0;//    -
        uint8_t count_e1 = 0;//    =
        uint8_t count_e2 = 0;//    !
        uint8_t count_s1 = 0;//    /
        uint8_t count_s2 = 0;//
        uint8_t count_q1 = 0;//    ?
        xml_line_data_s xml_return_line_data;
        line_length = s_temp.length();
        for (uint16_t i = 0; i < line_length; i++)
        {
            if (s_temp[i] == '&') count_a1++;
            if (s_temp[i] == '<') count_b1++;
            if (s_temp[i] == '>') count_b2++;
            if (s_temp[i] == '-') count_d1++;
            if (s_temp[i] == '=') count_e1++;
            if (s_temp[i] == '!') count_e2++;
            if (s_temp[i] == '/') count_s1++;
            if (s_temp[i] == ' ') count_s2++;
            if (s_temp[i] == '?') count_q1++;
        }

        // <?declaration?>
        if ((count_b1 >= 1) && (count_b2 >= 1) && (count_q1 >= 2))
            xml_return_line_data.data_type = XML_enum::XML_DECLARATION;
        // <!--comment-->
        else if ((count_b1 >= 1) && (count_b2 >= 1) && (count_d1 >= 4) && (count_e2 >= 1))
            xml_return_line_data.data_type = XML_enum::XML_COMMENT;
        // <tag>
        else if ((count_a1 == 0) && (count_b1 == 1) && (count_b2 == 1) && (count_d1 == 0) && (count_e1 == 0) && (count_e2 == 0) && (count_s1 == 0) && (count_s2 == 0) && (count_q1 == 0))
            xml_return_line_data.data_type = XML_enum::XML_TAG_START;
        // </tag>
        else if ((count_a1 == 0) && (count_b1 == 1) && (count_b2 == 1) && (count_d1 == 0) && (count_e1 == 0) && (count_e2 == 0) && (count_s1 == 1) && (count_s2 == 0) && (count_q1 == 0))
            xml_return_line_data.data_type = XML_enum::XML_TAG_END;
        // <tag>text</tag>
        else if ((count_a1 == 0) && (count_b1 == 2) && (count_b2 == 2) && (count_d1 == 0) && (count_e1 == 0) && (count_e2 == 0) && (count_s1 == 1) && (count_s2 == 0) && (count_q1 == 0))
            xml_return_line_data.data_type = XML_enum::XML_TAG_TEXT;
        // <tag attribute="value">
        else if ((count_a1 == 0) && (count_b1 == 1) && (count_b2 == 1) && (count_e1 > 0) && (count_e2 == 0) && (count_s1 == 0) && (count_s2 > 0) && (count_q1 == 0))
            xml_return_line_data.data_type = XML_enum::XML_TAG_ATTRIBUTE;
        // <tag attribute="value"/>
        else if ((count_a1 == 0) && (count_b1 == 1) && (count_b2 == 1) && (count_e1 > 0) && (count_e2 == 0) && (count_s1 == 1) && (count_s2 > 0) && (count_q1 == 0))
            xml_return_line_data.data_type = XML_enum::XML_TAG_ATTRIBUTE_END;
        else
            xml_return_line_data.data_type = XML_enum::XML_NONE;
        // xml_declaration
        if (xml_return_line_data.data_type == XML_enum::XML_DECLARATION)
        {
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.attribute_count = count_s2+1;
            xml_return_line_data.data = new xml_attribute_data_s[xml_return_line_data.attribute_count];
            bool tag_start = false;
            bool attribute_start = false;
            bool value_start = false;
            uint8_t attribute_no = 0;
            for (uint16_t i = 0; i < line_length; i++)
            {
                if ((tag_start) && (s_temp[i] == ' '))
                {
                    tag_start = false;
                }
                if (s_temp[i] == '=')
                {
                    attribute_start = false;
                }
                if (i > 1)
                {
                    if ((s_temp[i-1] != '=') && (s_temp[i] == '"'))
                        value_start = false;
                }
                if (tag_start)
                    xml_return_line_data.data[attribute_no].attribute += s_temp[i];
                if (attribute_start)
                    xml_return_line_data.data[attribute_no].attribute += s_temp[i];
                if (value_start)
                    xml_return_line_data.data[attribute_no].value += s_temp[i];
                if (s_temp[i] == '<')
                    tag_start = true;
                if (s_temp[i] == ' ')
                {
                    attribute_start = true;
                    attribute_no++;
                }
                if (i > 1)
                {
                    if ((s_temp[i-1] == '=') && (s_temp[i] == '"'))
                        value_start = true;
                }
            }
            if (debug)
            {
                std::cout <<  std::string(indentation * indent_depth, ' ');
                std::cout << "<" + xml_return_line_data.data[0].attribute;
                for (uint16_t i = 1; i < xml_return_line_data.attribute_count; i++)
                {
                    std::cout << " " + xml_return_line_data.data[i].attribute + "=\"" + xml_return_line_data.data[i].value + "\"";
                }
                std::cout << "?>" << std::endl;
            }
        }
        // xml_comment
        else if (xml_return_line_data.data_type == XML_enum::XML_COMMENT)
        {
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.attribute_count = 1;
            xml_return_line_data.data = new xml_attribute_data_s[xml_return_line_data.attribute_count];
            bool data_start = false;
            bool data_end = false;
            for (uint16_t i = 0; i < line_length; i++)
            {
                if (data_start && (s_temp[i] == '-') && (s_temp[i+1] == '-'))
                    data_end = true;
                if (data_start && !data_end)
                    xml_return_line_data.data[0].value += s_temp[i];
                if (!data_end && (s_temp[i] == '-') && (s_temp[i-1] == '-'))
                    data_start = true;
            }
            if (debug)
            {
                std::cout <<  std::string(indentation * indent_depth, ' ');
                std::cout << "<!--" + xml_return_line_data.data[0].value + "-->"<< std::endl;
            }
        }
        // xml_tag_start
        else if (xml_return_line_data.data_type == XML_enum::XML_TAG_START)
        {
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.attribute_count = 1;
            xml_return_line_data.data = new xml_attribute_data_s[xml_return_line_data.attribute_count];
            bool data_start = false;
            bool data_end = false;
            for (uint16_t i = 0; i < line_length; i++)
            {
                if (data_start && (s_temp[i] == '>'))
                    data_end = true;
                if (data_start && !data_end)
                    xml_return_line_data.data[0].value += s_temp[i];
                if (!data_end && (s_temp[i] == '<'))
                    data_start = true;
            }
            if (debug)
            {
                std::cout <<  std::string(indentation * indent_depth, ' ');
                std::cout << "<" + xml_return_line_data.data[0].value + ">"<< std::endl;
            }
            indentation++;
        }
        // xml_tag_end
        else if (xml_return_line_data.data_type == XML_enum::XML_TAG_END)
        {
            indentation--;
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.attribute_count = 1;
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.data = new xml_attribute_data_s[xml_return_line_data.attribute_count];
            bool data_start = false;
            bool data_end = false;
            for (uint16_t i = 0; i < line_length; i++)
            {
                if (data_start && (s_temp[i] == '>'))
                    data_end = true;
                if (data_start && !data_end)
                    xml_return_line_data.data[0].value += s_temp[i];
                if (!data_end && (s_temp[i] == '/') && (s_temp[i-1] == '<'))
                    data_start = true;
            }
            if (debug)
            {
                std::cout <<  std::string(indentation * indent_depth, ' ');
                std::cout << "</" + xml_return_line_data.data[0].value + ">"<< std::endl;
            }
        }
        // xml_tag_text
        else if (xml_return_line_data.data_type == XML_enum::XML_TAG_TEXT)
        {
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.attribute_count = 2;
            xml_return_line_data.data = new xml_attribute_data_s[xml_return_line_data.attribute_count];
            bool tag_start = false;
            bool tag_end = false;
            bool text_start = false;
            for (uint16_t i = 0; i < line_length; i++)
            {
                if (tag_end)
                {
                    if (s_temp[i] == '<')
                        text_start = false;
                    if (text_start)
                        xml_return_line_data.data[1].value += s_temp[i];
                }
                if (!tag_end)
                {
                    if (s_temp[i] == '>')
                    {
                        tag_start = false;
                        tag_end = true;
                        text_start = true;
                    }
                    if (tag_start)
                        xml_return_line_data.data[0].value += s_temp[i];
                    if (s_temp[i] == '<')
                        tag_start = true;
                }
            }
            if (debug)
            {
                std::cout <<  std::string(indentation * indent_depth, ' ');
                std::cout  << "<" + xml_return_line_data.data[0].value + ">" << xml_return_line_data.data[1].value << "</" + xml_return_line_data.data[0].value + ">" << std::endl;
            }
        }
        // xml_tag_attribute
        else if (xml_return_line_data.data_type == XML_enum::XML_TAG_ATTRIBUTE)
        {
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.attribute_count = count_s2+1;
            xml_return_line_data.data = new xml_attribute_data_s[xml_return_line_data.attribute_count];
            bool tag_start = false;
            bool attribute_start = false;
            bool value_start = false;
            uint8_t attribute_no = 0;
            for (uint16_t i = 0; i < line_length; i++)
            {
                if ((tag_start) && (s_temp[i] == ' '))
                {
                    tag_start = false;
                }
                if (s_temp[i] == '=')
                {
                    attribute_start = false;
                }
                if (i > 1)
                {
                    if ((s_temp[i-1] != '=') && (s_temp[i] == '"'))
                        value_start = false;
                }
                if (tag_start)
                    xml_return_line_data.data[attribute_no].attribute += s_temp[i];
                if (attribute_start)
                    xml_return_line_data.data[attribute_no].attribute += s_temp[i];
                if (value_start)
                    xml_return_line_data.data[attribute_no].value += s_temp[i];
                if (s_temp[i] == '<')
                    tag_start = true;
                if (s_temp[i] == ' ')
                {
                    attribute_start = true;
                    attribute_no++;
                }
                if (i > 1)
                {
                    if ((s_temp[i-1] == '=') && (s_temp[i] == '"'))
                        value_start = true;
                }
            }
            if (debug)
            {
                std::cout <<  std::string(indentation * indent_depth, ' ');
                std::cout << "<" + xml_return_line_data.data[0].attribute;
                for (uint16_t i = 1; i < xml_return_line_data.attribute_count; i++)
                {
                    std::cout << " " + xml_return_line_data.data[i].attribute + "=\"" + xml_return_line_data.data[i].value + "\"";
                }
                std::cout << ">" << std::endl;
            }
            indentation++;
        }
        // xml_tag_attribute_end
        else if (xml_return_line_data.data_type == XML_enum::XML_TAG_ATTRIBUTE_END)
        {
            xml_return_line_data.indentation = indentation;
            xml_return_line_data.attribute_count = count_s2+1;
            xml_return_line_data.data = new xml_attribute_data_s[xml_return_line_data.attribute_count];
            bool tag_start = false;
            bool attribute_start = false;
            bool value_start = false;
            uint8_t attribute_no = 0;
            for (uint16_t i = 0; i < line_length; i++)
            {
                if ((tag_start) && (s_temp[i] == ' '))
                {
                    tag_start = false;
                }
                if (s_temp[i] == '=')
                {
                    attribute_start = false;
                }
                if (i > 1)
                {
                    if ((s_temp[i-1] != '=') && (s_temp[i] == '"'))
                        value_start = false;
                }
                if (tag_start)
                    xml_return_line_data.data[attribute_no].attribute += s_temp[i];
                if (attribute_start)
                    xml_return_line_data.data[attribute_no].attribute += s_temp[i];
                if (value_start)
                    xml_return_line_data.data[attribute_no].value += s_temp[i];
                if (s_temp[i] == '<')
                    tag_start = true;
                if (s_temp[i] == ' ')
                {
                    attribute_start = true;
                    attribute_no++;
                }
                if (i > 1)
                {
                    if ((s_temp[i-1] == '=') && (s_temp[i] == '"'))
                        value_start = true;
                }
            }
            if (debug)
            {
                std::cout <<  std::string(indentation * indent_depth, ' ');
                std::cout << "<" + xml_return_line_data.data[0].attribute;
                for (uint16_t i = 1; i < xml_return_line_data.attribute_count; i++)
                {
                    std::cout << " " + xml_return_line_data.data[i].attribute + "=\"" + xml_return_line_data.data[i].value + "\"";
                }
                std::cout << "/>" << std::endl;
            }
        }
        else
        {
            if (debug)
            {
                std::cout << "ERROR-> Unable to parse line: " << s_temp << std::endl;
            }
        }
        return xml_return_line_data;
    }

    void xml_parse(const std::string &s_xml_file, xml_data_s *&xml_data)
    {
        xml_data = new xml_data_s;
        std::ifstream file_pointer;
        file_pointer.open (s_xml_file, std::ifstream::in);
        if (!file_pointer.good())
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> parsing XML file  :  " + s_xml_file);
        uint16_t line_count = 0;
        uint8_t indentation = 0;
        std::string s_temp = "";
        while (std::getline(file_pointer, s_temp))
            line_count++;
        file_pointer.clear();
        file_pointer.seekg(0, std::ios::beg);
        xml_data->line_count = line_count;
        xml_data->line = new xml_line_data_s[line_count];
        uint16_t i = 0;
        while (std::getline(file_pointer, s_temp))
        {
            xml_data->line[i] = xml_line_parse(s_temp, indentation);
            i++;
        }
        file_pointer.clear();
        file_pointer.close();
        if (!file_pointer.good())
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> parsing XML file  :  " + s_xml_file);
    }

    void xml_export(const std::string &s_xml_file, const xml_data_s &xml_data)
    {
        uint8_t indent_depth = 3;
        uint8_t indent_char = ' ';
        std::ofstream file_pointer;
        file_pointer.open (s_xml_file, std::ofstream::trunc | std::ofstream::out);
        file_pointer.close();
        file_pointer.open (s_xml_file, std::ofstream::out | std::ofstream::app);
        if (!file_pointer.good())
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "ERROR -> parsing XML file  :  " + s_xml_file);
        for (uint16_t j = 0; j < xml_data.line_count; j++)
        {
            // xml_declaration
            if (xml_data.line[j].data_type == XML_enum::XML_DECLARATION)
            {
                file_pointer <<  std::string(xml_data.line[j].indentation * indent_depth, indent_char);
                file_pointer << "<" + xml_data.line[j].data[0].attribute;
                for (uint16_t i = 1; i < xml_data.line[j].attribute_count; i++)
                {
                    file_pointer << " " + xml_data.line[j].data[i].attribute + "=\"" + xml_data.line[j].data[i].value + "\"";
                }
                file_pointer << "?>" << std::endl;
            }
            // xml_comment
            if (xml_data.line[j].data_type == XML_enum::XML_COMMENT)
            {
                file_pointer <<  std::string(xml_data.line[j].indentation * indent_depth, indent_char);
                file_pointer << "<!--" + xml_data.line[j].data[0].value + "-->"<< std::endl;
            }
            // xml_tag_start
            if (xml_data.line[j].data_type == XML_enum::XML_TAG_START)
            {
                file_pointer <<  std::string(xml_data.line[j].indentation * indent_depth, indent_char);
                file_pointer << "<" + xml_data.line[j].data[0].value + ">"<< std::endl;
            }
            // xml_tag_end
            if (xml_data.line[j].data_type == XML_enum::XML_TAG_END)
            {
                file_pointer <<  std::string(xml_data.line[j].indentation * indent_depth, indent_char);
                file_pointer << "</" + xml_data.line[j].data[0].value + ">"<< std::endl;
            }
            // xml_tag_text
            if (xml_data.line[j].data_type == XML_enum::XML_TAG_TEXT)
            {
                file_pointer <<  std::string(xml_data.line[j].indentation * indent_depth, indent_char);
                file_pointer  << "<" + xml_data.line[j].data[0].value + ">" << xml_data.line[j].data[1].value << "</" + xml_data.line[j].data[0].value + ">" << std::endl;
            }
            // xml_tag_attribute
            if (xml_data.line[j].data_type == XML_enum::XML_TAG_ATTRIBUTE)
            {
                file_pointer <<  std::string(xml_data.line[j].indentation * indent_depth, indent_char);
                file_pointer << "<" + xml_data.line[j].data[0].attribute;
                for (uint16_t i = 1; i < xml_data.line[j].attribute_count; i++)
                {
                    file_pointer << " " + xml_data.line[j].data[i].attribute + "=\"" + xml_data.line[j].data[i].value + "\"";
                }
                file_pointer << ">" << std::endl;
            }
            // xml_tag_attribute_end
            if (xml_data.line[j].data_type == XML_enum::XML_TAG_ATTRIBUTE_END)
            {
                file_pointer <<  std::string(xml_data.line[j].indentation * indent_depth, indent_char);
                file_pointer << "<" + xml_data.line[j].data[0].attribute;
                for (uint16_t i = 1; i < xml_data.line[j].attribute_count; i++)
                {
                    file_pointer << " " + xml_data.line[j].data[i].attribute + "=\"" + xml_data.line[j].data[i].value + "\"";
                }
                file_pointer << "/>" << std::endl;
            }
        }
        file_pointer.close();
    }

    std::string xml_get_value(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute, uint16_t attribute_no)
    {
        uint16_t attribute_count = 0;
        for (uint16_t i = 0; i < xml_data.line_count; i++)
            if (xml_data.line[i].data_type == data_type)
                for (uint16_t j = 0; j < xml_data.line[i].attribute_count; j++)
                {
                    if (xml_data.line[i].data[j].attribute == attribute)
                        attribute_count++;
                    if (attribute_no == attribute_count)
                        return xml_data.line[i].data[j].value;
                }
        return "XML Parser could not find requested attribute at number";
    }

    std::string xml_get_sub_value(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute, uint16_t attribute_no, const std::string &sub_attribute)
    {
        uint16_t attribute_count = 0;
        for (uint16_t i = 0; i < xml_data.line_count; i++)
            if (xml_data.line[i].data_type == data_type)
                for (uint16_t j = 0; j < xml_data.line[i].attribute_count; j++)
                {
                    if (xml_data.line[i].data[j].attribute == attribute)
                        attribute_count++;
                    if (attribute_no == attribute_count)
                        for (uint16_t k = j; k < xml_data.line[i].attribute_count; k++)
                            if (xml_data.line[i].data[k].attribute == sub_attribute)
                                return xml_data.line[i].data[k].value;
                }
        return "XML Parser could not find requested attribute at number";
    }

    uint16_t  xml_get_count(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute)
    {
        uint16_t return_count = 0;
        for (uint16_t i = 0; i < xml_data.line_count; i++)
            if (xml_data.line[i].data_type == data_type)
                for (uint16_t j = 0; j < xml_data.line[i].attribute_count; j++)
                    if (xml_data.line[i].data[j].attribute == attribute)
                        return_count++;
        return return_count;
    }

    xml_line_data_s* xml_get_line(const xml_data_s &xml_data, XML_enum data_type, const std::string &attribute, uint16_t attribute_count)
    {
        xml_line_data_s* return_data = nullptr;
        for (uint16_t i = 0; i < xml_data.line_count; i++)
            if (xml_data.line[i].data_type == data_type)
                for (uint16_t j = 0; j < xml_data.line[i].attribute_count; j++)
                    if ((xml_data.line[i].data[j].attribute == attribute) && (j == attribute_count))
                        return_data = xml_data.line;
        return return_data;
    }

}
