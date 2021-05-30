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
    std::ofstream outFile(DEBUG_FILE, std::fstream::trunc | std::fstream::out);
    outFile.close();
}

void gLogWrite(const uint32 &_type, const std::string &_string, const std::string &_file, const uint32 &_line, const std::string &_function)
{
    gLogWrite(DEBUG_FILE, _type, _string, _file, _line, _function);
}

void gLogWrite(const std::string &_fileName, const uint32 &_type, const std::string &_string, const std::string &_file, const uint32 &_line, const std::string &_function)
{
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
            //std::cout << std::string(_UDATE_()) << " " << std::string(__TIME__);
            //std::cout << " " << stripPath(_file) << " " << _function << "() " << std::to_string(_line) << " ";
            std::cout << _string << std::endl;
    #endif // DEBUG_LC
    #ifdef DEBUG_LF
        #if (defined(__linux__) || defined(_WIN32))
            std::ofstream outFile(DEBUG_FILE, std::fstream::out | std::fstream::app);
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
                outFile << std::string(__TIME__) << " - " << std::string(__DATE__);
                outFile << " - " << stripPath(_file) << " - " << _function << "() - " << std::to_string(_line) << " -> ";
                outFile << _string << std::endl;
                outFile.close();
            }
            else
            {
                std::cout << "Failed to write to file: " << std::string(DEBUG_FILE) << std::endl;
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
