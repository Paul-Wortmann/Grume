/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

class log_file_class
{
    private:
        const char *Log_File;
    public:
              log_file_class(void);
             ~log_file_class(void);
        bool File_Set(const char *Log_File);
        bool File_Clear(void);
        bool File_Delete(void);
        bool File_Write(const char  log_data[]);
        bool File_Write(std::string log_data);
        bool File_Write(std::string log_data, int                log_data_int);
        bool File_Write(std::string log_data, float              log_data_float);
        bool File_Write(std::string log_data, bool               log_data_bool);
        bool File_Write(std::string log_data, unsigned long long log_data_ull);
        bool File_Write(int   log_data);
        bool File_Write(float log_data);
        bool File_Write(bool  log_data);
        bool File_Write(std::string log_data_1, std::string log_data_2);
        bool File_Write(std::string log_data_1, const char log_data_2[]);
        bool File_Write(std::wstring log_data_1, std::wstring log_data_2);
        bool File_Write(std::string log_data, int log_data_int ,float log_data_float);
};

#endif //LOG_H
