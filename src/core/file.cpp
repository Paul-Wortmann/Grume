/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <string>
#include "core.hpp"
#include "file.hpp"

file_class::file_class(void)
{

};

file_class::~file_class(void)
{

};

bool file_class::extension_exist(std::string file_name, std::string file_extension)
{
    bool extention_found = false;
    for (int string_pos = 0; string_pos < file_name.size(); string_pos++)
    {
        if (file_name[string_pos] == '.') extention_found = true;
    }
    return (extention_found);
};

std::string file_class::extension_add(std::string file_name, std::string file_extension)
{
    if (file_extension[0] == '.') return (file_name+file_extension);
    else return (file_name+'.'+file_extension);
};

std::string file_class::extension_remove(std::string file_name)
{
    bool            extention_found = false;
    std::string     temp_string     = "";
    for (int string_pos = 0; string_pos < file_name.size(); string_pos++)
    {
        if (file_name[string_pos] == '.') extention_found = true;
        if (!extention_found) temp_string += file_name[string_pos];
    }
    return (temp_string);
};

