


#ifndef BASIC_LOG_HPP
#define BASIC_LOG_HPP

#define BASIC_LOG_FILE "engine.log"

#include <fstream>
#include <iostream>
#include <string>

void logClear(const std::string &_fileName = BASIC_LOG_FILE);
void logWrite(const std::string &_string, const std::string &_fileName = BASIC_LOG_FILE);

#endif // BASIC_LOG_HPP
