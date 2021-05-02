

#include "file_utils.hpp"


void fileToString(const std::string &_fileName, std::string &_buffer)
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

std::string fileToString(const std::string &_fileName)
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

bool fileExists(const std::string &_fileName)
{
    std::ifstream fileIn(_fileName.c_str());
    if(fileIn.is_open())
    {
        fileIn.close();
        return true;
    }
    return false;
}

const char *fileToBuffer(const std::string &_fileName)
{
    return (fileToString(_fileName)).c_str();
}

bool re_fileToBufferV(const std::string &_fileName, std::vector<unsigned char> &_buffer)
{
    std::fstream fileStream(_fileName.c_str(), std::ios::in | std::ios::binary);
    if (fileStream.fail())
    {
        perror(_fileName.c_str());
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + _fileName + " error : " + std::strerror(errno), __FILE__, __LINE__, __FUNCTION__);
        return false;
    }
    fileStream.seekg(0, std::ios::end);
    uint16 file_size = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    file_size -= fileStream.tellg();
    _buffer.resize(file_size);
    fileStream.read((char*)&(_buffer[0]), file_size);
    fileStream.close();
    return true;
}

std::string fileExtention(const std::string &_fileName)
{
    const char16_t marker = '.';
    std::string r_returnString = "";
    bool markerFound = false;
    uint16 fileLength = _fileName.length();
    for (int16 i = fileLength-1; i >= 0; i--)
    {
        if (!markerFound)
        {
            if (_fileName[i] != marker)
                r_returnString += _fileName[i];
            else
                markerFound = true;
        }
    }
    uint16 r_fileLength = r_returnString.length();
    std::string returnString = "";
    for (int16 i = r_fileLength-1; i >= 0; i--)
            returnString += r_returnString[i];
    return returnString;
}

std::string stripPath(const std::string &_fileName)
{
    const char16_t marker = '/';
    std::string r_returnString = "";
    bool markerFound = false;
    uint16 fileLength = _fileName.length();
    for (int16 i = fileLength-1; i >= 0; i--)
    {
        if (!markerFound)
        {
            if (_fileName[i] != marker)
                r_returnString += _fileName[i];
            else
                markerFound = true;
        }
    }
    uint16 r_fileLength = r_returnString.length();
    std::string returnString = "";
    for (int16 i = r_fileLength-1; i >= 0; i--)
            returnString += r_returnString[i];
    return returnString;
}

