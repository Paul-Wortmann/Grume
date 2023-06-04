/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "type_utils.hpp"

// A function to convert a string of space separated floats into a float array
// Function is called with _string and pre-allocated array matching the float count in the string
// Returns the float data in _array
void gStringToFloatArray(const std::string &_string, const std::uint32_t &_dataCount, float *&_array)
{
    std::uint32_t arrayPos = 0;
    std::string   tData = "";
    std::uint32_t stringLength = _string.length();
    for (std::uint32_t i = 0; i < stringLength; ++i)
    {
        if (_string[i] == ' ')
        {
            _array[arrayPos] = std::stof(tData);
            tData = "";
            arrayPos++;
        }
        else
        {
            tData += _string[i];
        }
    }
}

// A function to convert a string of space separated floats into a glm::mat4 array
// Function is called with _string and pre-allocated array matching the glm::mat4 count in the string
// Returns the glm::mat4 data in _array
void gStringToMat4Array(const std::string &_string, const std::uint32_t &_dataCount, glm::mat4 *&_array)
{
    std::uint32_t arrayPos = 0;
    std::uint32_t mat4Num = 0;
    std::uint32_t mat4Col = 0;
    std::uint32_t mat4Row = 0;
    std::string   tData = "";
    std::uint32_t stringLength = _string.length();
    for (std::uint32_t i = 0; i < stringLength; ++i)
    {
        if (_string[i] == ' ')
        {
            mat4Num = arrayPos / 16;
            mat4Col = (arrayPos - (mat4Num * 16)) / 4;
            mat4Row = (arrayPos - (mat4Num * 16)) % 4;
            _array[mat4Num][mat4Col][mat4Row] = std::stof(tData);
            tData = "";
            arrayPos++;
        }
        else
        {
            tData += _string[i];
        }
    }
}
