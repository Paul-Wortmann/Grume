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

#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "misc.hpp"

int seed_rand(void)
{
   srand(time(0));
   return(1);
};

double random_double(void)
{
  double temp_d = 0;

       do
       {
           temp_d = rand()%100;
           temp_d = 0.95 - (temp_d /50.9);
       }
       while ((temp_d > 2) and (temp_d < -2));
       return temp_d;
}

int random_int(int minimum, int maximum)
{
    return((rand()%(maximum - minimum)) + minimum);
}

int random_int(void)
{
   return(rand()%65535);
}

int    random(int range)
{
    return(rand()%range);
}

int random_dec(void)
{
   return(rand()%10);
}

int random_cen(void)
{
   return(rand()%100);
}

float   random_GLcoord(void)
{
  double temp_f = 0;

       do
       {
       temp_f = rand()%100;
       temp_f = (0.95 - (temp_f /50.9))/2;
       }
       while ((temp_f > 1) and (temp_f < -1));
       return temp_f;
}

std::string int_to_string(int int_in)
{
    std::stringstream string_out;
    string_out << int_in;
    return(string_out.str());
}

std::string const_char_to_string(const char *const_char_in)
{
    std::stringstream string_out;
    string_out << const_char_in;
    return(string_out.str());
}

bool file_exists(const char* file_name)
{
    std::fstream testfile(file_name,std::ios::in|std::ios::binary);
    if (testfile.is_open())
    {
        testfile.close();
    }
    else return(false);
    return(true);
};

int round_double(double x)
{
	return (int)(x + 0.5);
};

int nextpoweroftwo(int x)
{
	double logbase2 = log(x) / log(2);
	return round(pow(2,ceil(logbase2)));
};

std::wstring StringToWString(const std::string& s)
{
    std::wstring temp(s.length(),L' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp;
}


std::string WStringToString(const std::wstring& s)
{
    std::string temp(s.length(), ' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp;
}
