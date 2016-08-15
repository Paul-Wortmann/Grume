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

#include "re_file.hpp"
#include "re_log.hpp"
#include <fstream>
#include <iostream>

namespace RoboEngine
{

    void log_clear(const std::string &s_fileName)
    {
        std::fstream filePointer;
        filePointer.open (s_fileName, std::fstream::trunc | std::fstream::out);
        filePointer.close();
        if (!filePointer.good())
            std::cout << "ERROR -> log_clear()  :  " << s_fileName << std::endl;
    }

    void log_write(const std::string &s_fileName, const std::string &s_data, const bool &_consoleLogging)
    {
        std::fstream filePointer;
        filePointer.open (s_fileName, std::fstream::out | std::fstream::app);
        filePointer << s_data << std::endl;
        filePointer.close();
        if (!filePointer.good())
            std::cout  << std::endl << "ERROR -> log_write()  :  " << s_fileName << std::endl << std::endl;
        if (_consoleLogging || LOGTOCONSOLE)
            std::cout << s_data << std::endl;
    }

    void log_write(const std::string &s_fileName, const std::string &s_dataFile, const std::string &s_dataFunction, const uint32_t &s_dataLine, const std::string &s_message)
    {
        log_write(s_fileName, s_dataFile, s_dataFunction, s_dataLine, s_message, false);
    }

    void log_write(const std::string &s_fileName, const std::string &s_dataFile, const std::string &s_dataFunction, const uint32_t &s_dataLine, const std::string &s_message, const bool &_consoleLogging)
    {
        std::string s_data = stripPath(s_dataFile);
        s_data += " - ";
        s_data += s_dataFunction;
        s_data += "() - ";
        s_data += std::to_string(s_dataLine);
        s_data += " - ";
        s_data += s_message;
        log_write(s_fileName, s_data, _consoleLogging);
    }

    void log_write(const std::string &s_fileName, const std::string &s_data)
    {
        log_write(s_fileName, s_data, false);
    }

}
