


#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include "../includes.hpp"

void        fileToString(const std::string &_fileName, std::string &_buffer);
std::string fileToString(const std::string &_fileName);
bool        fileExists(const std::string &_fileName);
const char* fileToBuffer(const std::string &_fileName);
bool        fileToBufferV(const std::string &_fileName, std::vector<unsigned char> &_buffer);
std::string fileExtention(const std::string &_fileName);
std::string stripPath(const std::string &_fileName);

#endif // FILE_UTILS_HPP

