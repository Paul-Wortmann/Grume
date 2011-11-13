/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "log.hpp"

log_file_class::log_file_class(void)
{

};

log_file_class::~log_file_class(void)
{

};

bool log_file_class::File_Set(const char *Log_File)
{
    log_file_class::Log_File = Log_File;
    return(true);
};

bool log_file_class::File_Clear(void)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::binary|std::ios::trunc);
    if (logfile.is_open()) logfile.close();
    else return(false);
    return(true);
};

bool log_file_class::File_Delete(void)
{
  if( remove(log_file_class::Log_File) != 0 ) return(false);
  else return(true);
};

bool log_file_class::File_Write(const char  log_data[])
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data, int   log_data_int)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << log_data_int;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data, float log_data_float)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << log_data_float;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data, bool  log_data_bool)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        if(log_data_bool) logfile << "TRUE";
        else logfile << "FALSE";
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(int   log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(float log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(bool  log_data)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        if(log_data) logfile << "TRUE";
        else logfile << "FALSE";
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data_1, std::string log_data_2)
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::string log_data_1, const char log_data_2[])
{
    std::fstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_file_class::File_Write(std::wstring log_data_1, std::wstring log_data_2)
{
    std::wfstream logfile(log_file_class::Log_File,std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile.write(log_data_1.c_str(), log_data_1.size());
        logfile.write(log_data_2.c_str(), log_data_2.size());
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

