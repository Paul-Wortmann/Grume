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

#include "file_utils.hpp"

// A function to read data from a file and copy it to a string
// Function is called with _filename
// Returns the string in _buffer
void gFileToString(const std::string &_fileName, std::string &_buffer)
{
    std::ifstream file;
    file.open(_fileName.c_str());
    if (file.is_open())
    {
        std::stringstream strStream;
        strStream << file.rdbuf();
        _buffer = strStream.str();
        file.close();
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}

// A function to read data from a file and return it as a string
// Function is called with _filename
// Returns a string
std::string gFileToString(const std::string &_fileName)
{
    std::ifstream fileStream(_fileName, std::ios::in);
    if (fileStream.fail())
    {
        perror(_fileName.c_str());
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        std::string fileData = "";
        while(!fileStream.eof())
        {
            std::string lineData = "";
            std::getline(fileStream, lineData);
            fileData.append(lineData + "\n");
        }
        fileStream.close();
        return fileData;
    }
    return nullptr;
}

// A function to check weather a file exists
// Function is called with _filename
// Returns a bool
bool gFileExists(const std::string &_fileName)
{
    std::ifstream fileIn(_fileName.c_str());
    if(fileIn.is_open())
    {
        fileIn.close();
        return true;
    }
    return false;
}

// A function to read data from a file and copy it to a unsigned char vector
// Function is called with _filename
// Returns the data in _buffer
// Returns a bool to indicate success or failure
bool gFileToBufferV(const std::string &_fileName, std::vector<unsigned char> &_buffer)
{
    std::fstream fileStream(_fileName.c_str(), std::ios::in | std::ios::binary);
    if (fileStream.fail())
    {
        perror(_fileName.c_str());
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + _fileName + " error : " + std::strerror(errno), __FILE__, __LINE__, __FUNCTION__);
        return false;
    }
    fileStream.seekg(0, std::ios::end);
    std::uint64_t file_size = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    file_size -= fileStream.tellg();
    _buffer.resize(file_size);
    fileStream.read((char*)&(_buffer[0]), file_size);
    fileStream.close();
    return true;
}

// A function to return a file's extension
// Function is called with _filename
// Returns the data as a string
std::string gFileExtension(const std::string &_fileName)
{
    const char16_t marker = '.';
    std::string r_returnString = "";
    bool markerFound = false;
    std::uint64_t fileLength = _fileName.length();
    for (std::int64_t i = fileLength-1; i >= 0; i--)
    {
        if (!markerFound)
        {
            if (_fileName[i] != marker)
                r_returnString += _fileName[i];
            else
                markerFound = true;
        }
    }
    std::uint64_t r_fileLength = r_returnString.length();
    std::string returnString = "";
    for (std::int64_t i = r_fileLength-1; i >= 0; i--)
    {
            returnString += r_returnString[i];
    }
    return returnString;
}

// A function to remove a files path and return only the file's name and extension
// Function is called with _filename
// Returns the data as a string
std::string gStripPath(const std::string &_fileName)
{
    const char16_t marker = '/';
    std::string r_returnString = "";
    bool markerFound = false;
    std::uint64_t fileLength = _fileName.length();
    for (std::int64_t i = fileLength-1; i >= 0; i--)
    {
        if (!markerFound)
        {
            if (_fileName[i] != marker)
                r_returnString += _fileName[i];
            else
                markerFound = true;
        }
    }
    std::uint64_t r_fileLength = r_returnString.length();
    std::string returnString = "";
    for (std::int64_t i = r_fileLength-1; i >= 0; i--)
    {
            returnString += r_returnString[i];
    }
    return returnString;
}

