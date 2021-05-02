


#include "basic_log.hpp"

void logClear(const std::string &_fileName)
{
    std::ofstream logFile;
    logFile.open(_fileName, std::ofstream::out | std::ofstream::trunc);
    logFile.close();
}

void logWrite(const std::string &_string, const std::string &_fileName)
{
    std::ofstream logFile;
    logFile.open(_fileName, std::ofstream::out | std::ios_base::app);
    logFile << _string << std::endl;
    logFile.close();
}

