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

#include "xml_parser.hpp"

// Remove anomalies such as extra spaces.
// This leads to easier parsing and less memory usage.
std::string cXML::m_lineFormat(const std::string &_string)
{
    // Return an empty string if _string has no data
    if (_string.length() < 1)
    {
        return "";
    }
    
    // Process _string
    std::string   tString = "";
    std::uint32_t tStringLength = _string.length();
    std::uint32_t tStringPosition = 0;
    std::uint32_t abCount = 0; // angle bracket count
    
    // if the first character is a space or a tab, proceed
    if ((_string[0] == ' ') || (_string[0] == '\t'))
    {
        // First strip preceding spaces by finding 
        // the start of the data within the string.
        for(tStringPosition = 0; tStringPosition < tStringLength; ++tStringPosition)
        {
            if ((_string[tStringPosition] != ' ') && (_string[tStringPosition] != '\t'))
            {
                //tStringPosition--;
                break;
            }
        }
    }

    if (_string[tStringPosition] != '<')
    {
        // There is no valid data, return an empty string
        // Probably a comment line
        return "";
    }

    // Save the string without any aditional spaces
    for(; tStringPosition < tStringLength; ++tStringPosition)
    {
        // Look for the end of the data
        if (_string[tStringPosition] == '>')
        {
            abCount++;
            if (abCount == 2)
            {
                tString += _string[tStringPosition];
                break;
            }
        }

        // Save data if it is not a space or a tab
        if ((_string[tStringPosition] != ' ') && (_string[tStringPosition] != '\t'))
        {
            tString += _string[tStringPosition];
        }
        else //if ((_string[tStringPosition] == ' ') || (_string[tStringPosition] == '\t'))
        {
            // (tStringPosition - 1) shouldn't == 0 as we 
            // removed all preceding spaces and tabs in the previous step
            // tString[0] should be "<"
            if ((_string[tStringPosition - 1] != ' ') && (_string[tStringPosition - 1] != '\t'))
            {
                tString += " ";
            }
        }
    }
    
    // Return the processed string
    return tString;
}

void cXML::load(const std::string &_fileName)
{
    m_lineCount = 0;
    std::ifstream fileIn(_fileName.c_str());
    if(fileIn.is_open())
    {
        std::string lineData;
        while (std::getline(fileIn, lineData))
        {
            m_lineCount++;
        }
        fileIn.clear();
        fileIn.seekg (0, std::ios::beg);
        m_line = new std::string[m_lineCount];
        uint32 lineNum = 0;
        while (std::getline(fileIn, lineData))
        {
            m_line[lineNum] = m_lineFormat(lineData.c_str());
            lineNum++;
        }
        fileIn.close();
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}

uint32 cXML::getInstanceCount(const std::string &_key)
{
    uint32 instanceCount = 0;
    for (uint32 i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
        }
    }
    return instanceCount;
}

std::string cXML::getString(const std::string &_key, const uint32 _instance)
{
    uint32 instanceCount = 0;
    std::string rString = "";
    for (std::size_t i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
            if (instanceCount == _instance)
            {
                std::size_t start = m_line[i].find(_key) + _key.length();
                for(std::size_t j = start; j < m_line[i].length(); ++j)
                {
                    if (m_line[i][j] == '<')
                    {
                        j = m_line[i].length();
                    }
                    else
                    {
                        if (m_line[i][j] != '>')
                        {
                            rString += m_line[i][j];
                        }
                    }
                }
                return rString;
            }
        }
    }
    return rString;
}

uint32 cXML::getInteger(const std::string &_key, const uint32 _instance)
{
    std::string value = getString(_key, _instance);
    if (value.length() < 1)
    {
        return 0;
    }
    return std::stoi(value);
}

float cXML::getFloat(const std::string &_key, const uint32 _instance)
{
    std::string value = getString(_key, _instance);
    if (value.length() < 1)
    {
        return 0;
    }
    return std::stof(value);
}

glm::vec3 cXML::getVec3(const std::string &_key, const uint32 _instance)
{
    uint32 instanceCount = 0;
    glm::vec3 rVec;
    for (std::size_t i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
            if (instanceCount == _instance)
            {
                std::string v[3];
                uint16 pos = 0;
                std::size_t start = m_line[i].find(_key) + _key.length();
                for(std::size_t j = start; j < m_line[i].length(); ++j)
                {
                    if (m_line[i][j] == '<')
                    {
                        j = m_line[i].length();
                    }
                    else
                    {
                        if (m_line[i][j] != '>')
                        {
                            if (m_line[i][j] == ' ')
                            {
                                pos++;
                            }
                            else
                            {
                                v[pos] += m_line[i][j];
                            }
                        }
                    }
                }
                rVec = glm::vec3(std::stof(v[0]), std::stof(v[1]), std::stof(v[2]));
                return rVec;
            }
        }
    }
    return rVec;
}

glm::vec2 cXML::getVec2(const std::string &_key, const uint32 _instance)
{
    uint32 instanceCount = 0;
    glm::vec2 rVec;
    for (std::size_t i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
            if (instanceCount == _instance)
            {
                std::string v[2];
                uint16 pos = 0;
                std::size_t start = m_line[i].find(_key) + _key.length();
                for(std::size_t j = start; j < m_line[i].length(); ++j)
                {
                    if (m_line[i][j] == '<')
                    {
                        j = m_line[i].length();
                    }
                    else
                    {
                        if (m_line[i][j] != '>')
                        {
                            if (m_line[i][j] == ' ')
                            {
                                pos++;
                            }
                            else
                            {
                                v[pos] += m_line[i][j];
                            }
                        }
                    }
                }
                rVec = glm::vec2(std::stof(v[0]), std::stof(v[1]));
                return rVec;
            }
        }
    }
    return rVec;
}

glm::ivec3  cXML::getIvec3(const std::string &_key, const uint32 _instance)
{
    uint32 instanceCount = 0;
    glm::ivec3 rVec;
    for (std::size_t i = 0; i < m_lineCount; ++i)
    {
        if (m_line[i].find(_key) != std::string::npos)
        {
            instanceCount++;
            if (instanceCount == _instance)
            {
                std::string v[3];
                uint16 pos = 0;
                std::size_t start = m_line[i].find(_key) + _key.length();
                for(std::size_t j = start; j < m_line[i].length(); ++j)
                {
                    if (m_line[i][j] == '<')
                    {
                        j = m_line[i].length();
                    }
                    else
                    {
                        if (m_line[i][j] != '>')
                        {
                            if (m_line[i][j] == ' ')
                            {
                                pos++;
                            }
                            else
                            {
                                v[pos] += m_line[i][j];
                            }
                        }
                    }
                }
                rVec = glm::ivec3(std::stoi(v[0]), std::stoi(v[1]), std::stoi(v[2]));
                return rVec;
            }
        }
    }
    return rVec;
}
