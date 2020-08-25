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

// A basic function to extract data from xml encoded string*
// This relates to a specific DOM, and does not cover the full XML specification.
// String encoded as: <tag>data</tag>
// Returns: data
std::string xmlGetDataString(const std::string &_data)
{
    std::string returnString = "";
    uint32_t    stringLength = _data.length();
    uint16_t    gtCount      = 0;
    uint16_t    ltCount      = 0;
    
    for (uint32_t i = 0; i < stringLength; ++i)
    {
        if (_data[i] == '>')
        {
            gtCount++;
        }
        else if (_data[i] == '<')
        {
            ltCount++;
        }
        else
        {
            if ((ltCount == 1) && (gtCount == 1))
            {
                returnString += _data[i];
            }
        }
    }
    return returnString;
}

// A basic function to extract data from xml encoded string*
// This relates to a specific DOM, and does not cover the full XML specification.
// String encoded as: <tag>key1=data2 key2=data2 key3=data3</tag>
// Depending on key specified returns associated, "key1" returns: data1
std::string xmlGetDataValue(const std::string &_data, const std::string &_key)
{
    std::string returnString = "";
    uint32_t    stringLength = _data.length();
    uint16_t    gtCount      = 0;
    uint16_t    ltCount      = 0;
    uint16_t    esCount      = 0;
    uint16_t    scCount      = 0;
    uint32_t    keyStart     = _data.find(_key);
    
    for (uint32_t i = keyStart; i < stringLength; ++i)
    {
        if (_data[i] == '>')
        {
            gtCount++;
        }
        else if (_data[i] == '<')
        {
            ltCount++;
        }
        else if (_data[i] == '=')
        {
            esCount++;
        }        
        else if (_data[i] == ' ')
        {
            scCount++;
        }        
        else
        {
            if ((esCount == 1) && (ltCount != 1) && (scCount != 1))
            {
                returnString += _data[i];
            }
        }
    }
    return returnString;
}

// A basic function to extract data from xml encoded string*
// This relates to a specific DOM, and does not cover the full XML specification.
// String encoded as: <tag>1.0 2.0</tag>
// String encoded as: <tag>1.0,2.0</tag>
// Returns: glm::vec2(1.0, 2.0);
glm::vec2 xmlGetVec2Value(const std::string &_data, const std::string &_key)
{
    glm::vec2 returnVec;
    uint32_t stringSize = _data.size();
    std::string tempString = "";
    uint32_t start = _data.find(_key);
    uint32_t countC = 0;
    uint32_t countD = 0;
    for (uint32_t i = start; i < stringSize; i++)
    {
        countC += (_data[i] == ',') ? 1 : 0;
        countD += (_data[i] == '"') ? 1 : 0;
        if ((_data[i] != '"') && (countD == 1))
        {
            if ((_data[i] != ' ') && (_data[i] != ','))
            {
                tempString += _data[i];
            }
            else
            {
                if ((_data[i+1] != ' ') && (_data[i+1] != ','))
                {
                    returnVec.x = stof(tempString);
                    tempString = "";
                }
            }
        }
        if ((_data[i] == '"') && (countC == 1))
        {
            returnVec.y = stof(tempString);
            countC++;
        }
    }
    return returnVec;
}

// A basic function to extract data from xml encoded string*
// This relates to a specific DOM, and does not cover the full XML specification.
// String encoded as: <tag>1.0 2.0 3.0</tag>
// String encoded as: <tag>1.0,2.0,3.0</tag>
// Returns: glm::vec3(1.0, 2.0, 3.0);
glm::vec3 xmlGetVec3Value(const std::string &_data, const std::string &_key)
{
    glm::vec3 returnVec;
    uint32_t stringSize = _data.size();
    std::string tempString = "";
    uint32_t start = _data.find(_key);
    uint32_t countC = 0;
    uint32_t countD = 0;
    for (uint32_t i = start; i < stringSize; i++)
    {
        countC += (_data[i] == ',') ? 1 : 0;
        countD += (_data[i] == '"') ? 1 : 0;
        if ((_data[i] != '"') && (countD == 1))
        {
            if ((_data[i] != ' ') && (_data[i] != ','))
            {
                tempString += _data[i];
            }
            else
            {
                if ((_data[i+1] != ' ') && (_data[i+1] != ','))
                {
                    if (countC == 1)
                    {
                        returnVec.x = stof(tempString);
                    }
                    else if (countC == 2)
                    {
                        returnVec.y = stof(tempString);
                    }
                    tempString = "";
                }
            }
        }
        if ((_data[i] == '"') && (countC == 2))
        {
            returnVec.z = stof(tempString);
            countC++;
        }
    }
    return returnVec;
}

// Converts a returned string into a float
float xmlGetFloatValue(const std::string &_data, const std::string &_key)
{
    return stof(xmlGetDataValue(_data, _key));
}

// Converts a returned string into an int32
int32_t xmlGetIntegerValue(const std::string &_data, const std::string &_key)
{
    return stoi(xmlGetDataValue(_data, _key));
}
