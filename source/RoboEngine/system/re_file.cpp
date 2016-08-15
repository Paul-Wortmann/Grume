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
#include <fstream>
#include <iostream>

namespace RoboEngine
{

    std::string fileExtention(const std::string &s_fileName)
    {
        const char16_t marker = '.';
        std::string r_returnString = "";
        bool markerFound = false;
        uint16_t fileLength = s_fileName.length();
        for (int16_t i = fileLength-1; i >= 0; i--)
        {
            if (!markerFound)
            {
                if (s_fileName[i] != marker)
                    r_returnString += s_fileName[i];
                else
                    markerFound = true;
            }
        }
        uint16_t r_fileLength = r_returnString.length();
        std::string returnString = "";
        for (int16_t i = r_fileLength-1; i >= 0; i--)
                returnString += r_returnString[i];
        return returnString;
    }

    std::string stripPath(const std::string &s_fileName)
    {
        const char16_t marker = '/';
        std::string r_returnString = "";
        bool markerFound = false;
        uint16_t fileLength = s_fileName.length();
        for (int16_t i = fileLength-1; i >= 0; i--)
        {
            if (!markerFound)
            {
                if (s_fileName[i] != marker)
                    r_returnString += s_fileName[i];
                else
                    markerFound = true;
            }
        }
        uint16_t r_fileLength = r_returnString.length();
        std::string returnString = "";
        for (int16_t i = r_fileLength-1; i >= 0; i--)
                returnString += r_returnString[i];
        return returnString;
    }

}
