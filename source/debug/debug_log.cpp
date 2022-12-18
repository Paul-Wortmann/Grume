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

#include "debug_log.hpp"

std::string _UDATE_(void)
{
    std::string tMonth = "";
    tMonth += __DATE__[0];
    tMonth += __DATE__[1];
    tMonth += __DATE__[2];

    std::string returnString = "";
    returnString += __DATE__[ 7];
    returnString += __DATE__[ 8];
    returnString += __DATE__[ 9];
    returnString += __DATE__[10];
    returnString += "-";

    if (tMonth.compare("Jan") == 0)
        returnString += "01";
    if (tMonth.compare("Feb") == 0)
        returnString += "02";
    if (tMonth.compare("Mar") == 0)
        returnString += "03";
    if (tMonth.compare("Apr") == 0)
        returnString += "04";
    if (tMonth.compare("May") == 0)
        returnString += "05";
    if (tMonth.compare("Jun") == 0)
        returnString += "06";
    if (tMonth.compare("Jul") == 0)
        returnString += "07";
    if (tMonth.compare("Aug") == 0)
        returnString += "08";
    if (tMonth.compare("Sep") == 0)
        returnString += "09";
    if (tMonth.compare("Oct") == 0)
        returnString += "10";
    if (tMonth.compare("Nov") == 0)
        returnString += "11";
    if (tMonth.compare("Dec") == 0)
        returnString += "12";

    returnString += "-";
    if (__DATE__[ 4] == ' ')
        returnString += "0";
    else
        returnString += __DATE__[ 4];
    returnString += __DATE__[ 5];

    return returnString;
}

void gLogClear(void)
{
    gLogClear(DEBUG_FILE);
}

void gLogClear(const std::string &_fileName)
{
    std::ofstream outFile(_fileName, std::fstream::trunc | std::fstream::out);
    outFile.close();
}

void gLogWrite(const std::uint32_t &_type, const std::string &_string, const std::string &_file, const std::uint32_t &_line, const std::string &_function)
{
    gLogWrite(DEBUG_FILE, _type, _string, _file, _line, _function);
}

void gLogWrite(const std::string &_fileName, const std::uint32_t &_type, const std::string &_string, const std::string &_file, const std::uint32_t &_line, const std::string &_function)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);

    // Year
    std::string timeString;
    timeString  = std::to_string(now_tm.tm_year + 1900) + "-";

    // Month
    timeString += (now_tm.tm_mon < 9) ? "0" : "";
    timeString += std::to_string(now_tm.tm_mon + 1) + "-";

    // Day
    timeString += (now_tm.tm_mday < 10) ? "0" : "";
    timeString += std::to_string(now_tm.tm_mday) + " ";

    // Hour
    timeString += (now_tm.tm_hour < 10) ? "0" : "";
    timeString += std::to_string(now_tm.tm_hour) + ":";

    // Minute
    timeString += (now_tm.tm_min < 10) ? "0" : "";
    timeString += std::to_string(now_tm.tm_min) + ":";

    // Second
    timeString += (now_tm.tm_sec < 10) ? "0" : "";
    timeString += std::to_string(now_tm.tm_sec);

    #ifdef DEBUG_LC
        #ifdef __linux__
            switch (_type)
            {
                case LOG_INFO:
                    std::cout << FG_LIGHT_GREEN("[Info]") << "    ";
                break;
                case LOG_WARNING:
                    std::cout << FG_YELLOW("[Warning]") << " ";
                break;
                case LOG_ERROR:
                    std::cout << FG_RED("[Error]") << "   ";
                break;
                default:
                    std::cout << FG_RED("[UNKNOWN_TYPE]") << "   ";
                break;
            }
        #elif _WIN32
            switch (_type)
            {
                case LOG_INFO:
                    std::cout << "[Info]    ";
                break;
                case LOG_WARNING:
                    std::cout << "[Warning] ";
                break;
                case LOG_ERROR:
                    std::cout << "[Error]   ";
                break;
                default:
                    std::cout << "[UNKNOWN_TYPE]" << "   ";
                break;
            }
        #else
            #error Platform not supported
        #endif
            //std::cout << timeString;
            //std::cout << " " << stripPath(_file) << " " << _function << "() " << std::to_string(_line) << " ";
            std::cout << _string << std::endl;
    #endif // DEBUG_LC
    #ifdef DEBUG_LF
        #if (defined(__linux__) || defined(_WIN32))
            std::ofstream outFile(_fileName, std::fstream::out | std::fstream::app);
            if (outFile.is_open())
            {
                switch (_type)
                {
                    case LOG_INFO:
                        outFile << "[Info]    ";
                    break;
                    case LOG_WARNING:
                        outFile << "[Warning] ";
                    break;
                    case LOG_ERROR:
                        outFile << "[Error]   ";
                    break;
                    default:
                        outFile << "[UNKNOWN_TYPE] ";
                    break;
                }
                outFile << timeString;
                outFile << " - " << gStripPath(_file) << " - " << _function << "() - " << std::to_string(_line) << " -> ";
                outFile << _string << std::endl;
                outFile.close();
            }
            else
            {
                std::cout << "Failed to write to file: " << std::string(_fileName) << std::endl;
            }
        #else
            #error Platform not supported
        #endif

    #endif // DEBUG_LF
    /*
    if (_type == LOG_ERROR)
    {
        std::string tString = "";
        tString  = stripPath(_file);
        tString += " ";
        tString += _function;
        tString += "() ";
        tString += std::to_string(_line);
        throw std::runtime_error(tString.c_str());
    }
    */
}
