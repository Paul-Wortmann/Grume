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
// *This does not cover the full XML specification.
// Returns: a bool result of a std::string find;
bool xmlFind(const std::string &_data, const std::string &_find)
{
    return (_data.find(_find) != std::string::npos);
}

// A basic function to extract data from xml encoded string*
// *This does not cover the full XML specification.
// String encoded as: <tag>data</tag>
// Returns: data
std::string xmlGetDataString(const std::string &_data)
{
    std::string returnString = "";
    std::size_t stringLength = _data.length();
    uint16_t    gtCount      = 0;
    uint16_t    ltCount      = 0;
    
    for (std::size_t i = 0; i < stringLength; ++i)
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
// *This does not cover the full XML specification.
// String encoded as: <tag>key1="data1" key2="data2" key3="data3"</tag>
// String encoded as: <tag key1="data1" key2="data2" key3="data3"/>
// Depending on key specified returns associated, key1 returns: data1
std::string xmlGetDataValue(const std::string &_data, const std::string &_key)
{
    std::string returnString = "";
    std::size_t stringLength = _data.length();
    uint16_t    smCount      = 0;
    std::size_t keyStart     = _data.find(_key + "=");

    if (keyStart == std::string::npos)
    {
        // key not found
        return returnString;
    }

    for (std::size_t i = keyStart; i < stringLength; ++i)
    {
        if (_data[i] == '"')
        {
            smCount++;
        }
        else
        {
            if (smCount == 1)
            {
                returnString += _data[i];
            }
        }
    }
    return returnString;
}

// A basic function to extract data from xml encoded string*
// *This does not cover the full XML specification.
// Converts a returned string into a float
float xmlGetFloatValue(const std::string &_data, const std::string &_key)
{
    std::string tString = xmlGetDataValue(_data, _key);
    std::size_t vLength = tString.length();
    return (vLength == 0) ? 0 : stof(tString);
}

// A basic function to extract data from xml encoded string*
// *This does not cover the full XML specification.
// Converts a returned string into an int32
int32_t xmlGetIntegerValue(const std::string &_data, const std::string &_key)
{
    std::string tString = xmlGetDataValue(_data, _key);
    std::size_t vLength = tString.length();
    return (vLength == 0) ? 0 : stoi(tString);
}

// A basic function to extract data from xml encoded string*
// *This does not cover the full XML specification.
// String encoded as: <tag x="1.0" y="1.0"/>
// Returns: glm::vec2(1.0, 2.0);
glm::vec2 xmlGetVec2Value(const std::string &_data, const std::string &_key)
{
    std::string tStringX = xmlGetDataValue(_data, "x");
    std::string tStringY = xmlGetDataValue(_data, "y");
    std::size_t vLengthX = tStringX.length();
    std::size_t vLengthY = tStringY.length();
    if ((vLengthX == 0) || (vLengthY == 0))
    {
        return glm::vec2(0.0f, 0.0f);
    }
    return glm::vec2(stof(tStringX), stof(tStringY));
}

// A basic function to extract data from xml encoded string*
// *This does not cover the full XML specification.
// String encoded as: <tag x="1.0" y="2.0" z="3.0"/>
// Returns: glm::vec3(1.0, 2.0, 3.0);
glm::vec3 xmlGetVec3Value(const std::string &_data, const std::string &_key)
{
    std::string tStringX = xmlGetDataValue(_data, "x");
    std::string tStringY = xmlGetDataValue(_data, "y");
    std::string tStringZ = xmlGetDataValue(_data, "z");
    std::size_t vLengthX = tStringX.length();
    std::size_t vLengthY = tStringY.length();
    std::size_t vLengthZ = tStringZ.length();
    if ((vLengthX == 0) || (vLengthY == 0) || (vLengthZ == 0))
    {
        return glm::vec3(0.0f, 0.0f, 0.0f);
    }
    return glm::vec3(stof(tStringX), stof(tStringY), stof(tStringZ));
}
