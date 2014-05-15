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

#ifndef LOG_H
#define LOG_H

#include <string>

class log_class
{
    private:
    public:
        std::string file_name;
              log_class(void);
             ~log_class(void);
        bool set_file_name(std::string name_in);
        bool clear_file(void);
        bool delete_file(void);
        bool write(const char  log_data[]);
        bool write(std::string log_data);
        bool write(std::string log_data, int                log_data_int);
        bool write(std::string log_data, float              log_data_float);
        bool write(std::string log_data, bool               log_data_bool);
        bool write(std::string log_data, unsigned long long log_data_ull);
        bool write(int   log_data);
        bool write(float log_data);
        bool write(bool  log_data);
        bool write(std::string log_data_1, std::string log_data_2);
        bool write(std::string log_data_1, std::string log_data_2, std::string log_data_3);
        bool write(std::string log_data_1, const char  log_data_2[], std::string log_data_3);
        bool write(std::string log_data_1, const char log_data_2[]);
        bool write(std::wstring log_data_1, std::wstring log_data_2);
        bool write(std::string log_data,   int log_data_int, float       log_data_float);
        bool write(std::string log_data_1, int   log_data_2, std::string log_data_3);
        bool write(std::string log_data_1, int   log_data_2, std::string log_data_3, int         log_data_4);
        bool write(std::string log_data_1, int   log_data_2, std::string log_data_3, std::string log_data_4);
        bool write(std::string log_data_1, int   log_data_2, std::string log_data_3, int         log_data_4, std::string log_data_5, int         log_data_6);
        bool write(std::string log_data_1, int   log_data_2, std::string log_data_3, int         log_data_4, std::string log_data_5, std::string log_data_6);
        bool write(std::string log_data_1, int   log_data_2, std::string log_data_3, int         log_data_4, std::string log_data_5, int         log_data_6, std::string log_data_7, int   log_data_8);
        bool write(std::string log_data_1, float log_data_2, std::string log_data_3, float       log_data_4);
        bool write_time_stamp(std::string message);
};

#endif //LOG_H


/*

should only have one main file write function that all methods use....







*/




