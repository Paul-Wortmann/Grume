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

#include "vector.hpp"

float vector_2f_class::angle(void) // radians
{
    return(1.0f / tan(vector_2f_class::y / vector_2f_class::x));
}

int  vector_2f_class::angle_deg(void) // degrees
{
    return((1.0f / tan(vector_2f_class::y / vector_2f_class::x)) * (180 / M_PI));
}

float vector_2f_class::magnitude(void)
{
    return sqrtf( vector_2f_class::x*vector_2f_class::x + vector_2f_class::y*vector_2f_class::y );
}

float vector_2f_class::magnitude_squared(void)
{
    return vector_2f_class::x*vector_2f_class::x + vector_2f_class::y*vector_2f_class::y;
}

void vector_2f_class::normalize(void)
{
    float length_temp = 1.0/sqrtf( vector_2f_class::x*vector_2f_class::x + vector_2f_class::y*vector_2f_class::y );
    vector_2f_class::x *= length_temp;
    vector_2f_class::y *= length_temp;
}

//-----------------------------------------------------------------------------------------------------------------

int vector_2i_class::magnitude(void)
{
    return sqrtf( vector_2i_class::x*vector_2i_class::x + vector_2i_class::y*vector_2i_class::y );
}

int vector_2i_class::magnitude_squared(void)
{
    return vector_2i_class::x*vector_2i_class::x + vector_2i_class::y*vector_2i_class::y;
}

void vector_2i_class::normalize(void)
{
    int length_temp = 1.0/sqrtf( vector_2i_class::x*vector_2i_class::x + vector_2i_class::y*vector_2i_class::y );
    vector_2i_class::x *= length_temp;
    vector_2i_class::y *= length_temp;
}

