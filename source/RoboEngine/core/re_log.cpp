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

namespace RoboEngine
{

    uint32_t re_logClear(const std::string &_fileName)
    {
        uint32_t return_value = EXIT_SUCCESS;
        std::ofstream fileStream;
        fileStream.open(_fileName, std::ofstream::out | std::ofstream::trunc);
        if (fileStream.is_open())
            fileStream.close();
        else
            return EXIT_FAILURE;
        return return_value;
    }

    void re_logToConsole(const std::string &_message, const std::string &_mFile, const uint32_t &_mLine, const std::string &_mFunction)
    {
        std::string cTime = __TIME__;
        std::string cDate = __DATE__;
        std::cout << cDate << " - " << cTime;
        std::cout << " - " << re_stripPath(_mFile) << " - " << _mFunction << "() - " << std::to_string(_mLine) << " -> ";
        std::cout << _message << std::endl;
    }

    void re_logToConsole(const std::string &_message)
    {
        std::cout << _message << std::endl;
    }

    uint32_t re_logWrite(const std::string &_message, const std::string &_fileName, const std::string &_mFile, const uint32_t &_mLine, const std::string &_mFunction)
    {
        std::string cTime = __TIME__;
        std::string cDate = __DATE__;
        uint32_t return_value = EXIT_SUCCESS;
        std::ofstream fileStream;
        fileStream.open(_fileName, std::ofstream::out | std::ofstream::app);
        if (fileStream.is_open())
        {
            fileStream << cDate << " - " << cTime;
            fileStream << " - " << re_stripPath(_mFile) << " - " << _mFunction << "() - " << std::to_string(_mLine) << " -> ";
            fileStream << _message << std::endl;
            fileStream.close();
        }
        else
            return EXIT_FAILURE;
        return return_value;
    }

    uint32_t re_logWrite(const std::string &_message, const std::string &_fileName)
    {
        uint32_t return_value = EXIT_SUCCESS;
        std::ofstream fileStream;
        fileStream.open(_fileName, std::ofstream::out | std::ofstream::app);
        if (fileStream.is_open())
        {
            fileStream << _message << std::endl;
            fileStream.close();
        }
        else
            return EXIT_FAILURE;
        return return_value;
    }

}
