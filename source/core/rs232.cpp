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

#include "rs232.hpp"

    rs232_class::rs232_class(void)
{
    rs232_class::port_open   = false;
    rs232_class::port_number = 1;
    rs232_class::baud_rate   = 9600;
    rs232_class::stop_bits   = 1;
    rs232_class::data_bits   = 8;
    rs232_class::parity      = NONE;
};

    rs232_class::~rs232_class(void)
{
    if (rs232_class::port_open) rs232_class::close_port();
};

void  rs232_class::set_port       (int port_number_set, int baud_rate_set, int stop_bits_set, int data_bits_set, int parity_set)
{
    rs232_class::port_number = port_number_set;
    rs232_class::baud_rate   = baud_rate_set;
    rs232_class::stop_bits   = stop_bits_set;
    rs232_class::data_bits   = data_bits_set;
    rs232_class::parity      = parity_set;
};

void  rs232_class::set_port_number(int port_number_set)
{
    rs232_class::port_number = port_number_set;
};

void  rs232_class::set_baud_rate  (int baud_rate_set)
{
    rs232_class::baud_rate   = baud_rate_set;
};

void  rs232_class::set_stop_bits  (int stop_bits_set)
{
    rs232_class::stop_bits   = stop_bits_set;
};

void  rs232_class::set_data_bits  (int data_bits_set)
{
    rs232_class::data_bits   = data_bits_set;
};

void  rs232_class::set_parity     (int parity_set)
{
    rs232_class::parity      = parity_set;
};

bool  rs232_class::open_port      (void)
{
    return(true);
};

bool  rs232_class::close_port     (void)
{
    return(true);
};







