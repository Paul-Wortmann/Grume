/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <fstream>
#include <ctime>
#include <iostream>
#include "log.hpp"

log_class::log_class(void)
{

};

log_class::~log_class(void)
{

};

bool log_class::file_set(std::string file_name_in)
{
    log_class::file_name = file_name_in;
    return(true);
};

bool log_class::file_clear(void)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
    if (logfile.is_open()) logfile.close();
    else return(false);
    return(true);
};

bool log_class::file_delete(void)
{
  if( remove(log_class::file_name.c_str()) != 0 ) return(false);
  else return(true);
};

bool log_class::file_write(const char  log_data[])
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data, int   log_data_int)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
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

bool log_class::file_write(std::string log_data, float log_data_float)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
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

bool log_class::file_write(std::string log_data, bool  log_data_bool)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
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

bool log_class::file_write(std::string log_data, unsigned long long log_data_ull)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << log_data_ull;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(int   log_data)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(float log_data)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(bool  log_data)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
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

bool log_class::file_write(std::string log_data_1, std::string log_data_2)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
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

bool log_class::file_write(std::string log_data_1, std::string log_data_2, std::string log_data_3)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << log_data_3;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data_1, const char  log_data_2[], std::string log_data_3)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << log_data_3;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data_1, const char log_data_2[])
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
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

bool log_class::file_write(std::wstring log_data_1, std::wstring log_data_2)
{
    std::wfstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
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

bool log_class::file_write(std::string log_data, int log_data_int ,float log_data_float)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data;
        logfile << log_data_int;
        logfile << " - ";
        logfile << log_data_float;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data_1, int log_data_2 ,std::string log_data_3, int log_data_4)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << log_data_3;
        logfile << log_data_4;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data_1, int   log_data_2, std::string log_data_3, int   log_data_4, std::string log_data_5, int   log_data_6)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << log_data_3;
        logfile << log_data_4;
        logfile << log_data_5;
        logfile << log_data_6;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data_1, int   log_data_2 ,std::string log_data_3, int   log_data_4,std::string log_data_5, int   log_data_6 ,std::string log_data_7, int   log_data_8)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << log_data_3;
        logfile << log_data_4;
        logfile << log_data_5;
        logfile << log_data_6;
        logfile << log_data_7;
        logfile << log_data_8;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write(std::string log_data_1, float log_data_2 ,std::string log_data_3, float log_data_4)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        logfile << log_data_1;
        logfile << log_data_2;
        logfile << log_data_3;
        logfile << log_data_4;
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

bool log_class::file_write_time_stamp(void)
{
    std::fstream logfile(log_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (logfile.is_open())
    {
        std::time_t result = std::time(NULL);
        logfile << "Logfile created: " << std::asctime(std::localtime(&result));
        logfile << "\n";
        logfile.close();
    }
    else return(false);
    return(true);
};

