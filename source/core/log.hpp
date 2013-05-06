/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
        bool file_set(std::string file_name_in);
        bool file_clear(void);
        bool file_delete(void);
        bool file_write(const char  log_data[]);
        bool file_write(std::string log_data);
        bool file_write(std::string log_data, int                log_data_int);
        bool file_write(std::string log_data, float              log_data_float);
        bool file_write(std::string log_data, bool               log_data_bool);
        bool file_write(std::string log_data, unsigned long long log_data_ull);
        bool file_write(int   log_data);
        bool file_write(float log_data);
        bool file_write(bool  log_data);
        bool file_write(std::string log_data_1, std::string log_data_2);
        bool file_write(std::string log_data_1, std::string log_data_2, std::string log_data_3);
        bool file_write(std::string log_data_1, const char  log_data_2[], std::string log_data_3);
        bool file_write(std::string log_data_1, const char log_data_2[]);
        bool file_write(std::wstring log_data_1, std::wstring log_data_2);
        bool file_write(std::string log_data, int log_data_int ,float log_data_float);
        bool file_write(std::string log_data_1, int   log_data_2 ,std::string log_data_3, int   log_data_4);
        bool file_write(std::string log_data_1, int   log_data_2 ,std::string log_data_3, int   log_data_4,std::string log_data_5, int   log_data_6 ,std::string log_data_7, int   log_data_8);
        bool file_write(std::string log_data_1, float log_data_2 ,std::string log_data_3, float log_data_4);
};

#endif //LOG_H
