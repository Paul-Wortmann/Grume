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

#include "map_generate_database.hpp"

// Retrive a file name from an already opened database file
std::string gGetFileName(cXML &_xmlFile, const std::string &_name, const std::uint32_t &_index)
{
    // First grab the string from the database
    std::string tDataString = "";
    if (_index > 0)
    {
        tDataString = _xmlFile.getString(_name, _index);
    }
    else
    {
        tDataString = _xmlFile.getString(_name, (rand() % (_xmlFile.getInstanceCount(_name) - 1)) + 1);
    }
    
    return tDataString;
    /*
    // Second parse the string from the database
    tDataString += "    ";
    std::uint64_t tDataStringLength = tDataString.length();
    std::string   tFileName         = "";
    std::uint32_t tStringNum        = 0;
    std::string   tString           = "";
    if (tDataStringLength > 6)
    {
        for (std::uint64_t j = 0; j < tDataStringLength; ++j)
        {
            if (tDataString[j] == ' ')
            {
                if (tStringNum == 0)
                {
                    ; // databse name
                }
                else if (tStringNum == 1)
                {
                    tFileName = tString.c_str();
                }

                tStringNum++;
                tString = "";
            }
            else
            {
                tString += tDataString[j];
            }
        }
    }
    
    std::cout << _name << std::endl;
    std::cout << tDataString << std::endl;

    // Return the file name
    return tFileName;
    */
}
