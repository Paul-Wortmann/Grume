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

#include "xml_utils.hpp"

std::string xmlGetDataString(const std::string &_string)
{
    std::string returnString = "";
    uint32_t    stringLength = _string.length();
    uint16_t    gtCount      = 0;
    uint16_t    ltCount      = 0;
    
    for (uint32_t i = 0; i < stringLength; ++i)
    {
        if (_string[i] == '>')
        {
            gtCount++;
        }
        else if (_string[i] == '<')
        {
            ltCount++;
        }
        else
        {
            if ((ltCount == 1) && (gtCount == 1))
            {
                returnString += _string[i];
            }
        }
    }
    return returnString;
}

std::string xmlGetDataValue(const std::string &_string, const std::string &_key)
{
    std::string returnString = "";
    uint32_t    stringLength = _string.length();
    uint16_t    gtCount      = 0;
    uint16_t    ltCount      = 0;
    uint16_t    esCount      = 0;
    uint16_t    scCount      = 0;
    uint32_t    keyStart     = _string.find(_key);
    
    for (uint32_t i = keyStart; i < stringLength; ++i)
    {
        if (_string[i] == '>')
        {
            gtCount++;
        }
        else if (_string[i] == '<')
        {
            ltCount++;
        }
        else if (_string[i] == '=')
        {
            esCount++;
        }        
        else if (_string[i] == ' ')
        {
            scCount++;
        }        
        else
        {
            if ((esCount == 1) && (ltCount != 1) && (scCount != 1))
            {
                returnString += _string[i];
            }
        }
    }
    return returnString;
}
