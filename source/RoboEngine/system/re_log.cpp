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

#include "re_log.hpp"
#include <fstream>
#include <iostream>

namespace RoboEngine
{

    void log_write(const std::string &s_file_name, const std::string &s_data)
    {
        std::fstream file_pointer;
        file_pointer.open (s_file_name, std::fstream::out | std::fstream::app);
        file_pointer << s_data << std::endl;
        file_pointer.close();
        if (!file_pointer.good())
            std::cout << "ERROR -> log_write()  :  " << s_file_name << std::endl;
    }

    void log_clear(const std::string &s_file_name)
    {
        std::fstream file_pointer;
        file_pointer.open (s_file_name, std::fstream::trunc | std::fstream::out);
        file_pointer.close();
        if (!file_pointer.good())
            std::cout << "ERROR -> log_clear()  :  " << s_file_name << std::endl;
    }

}
