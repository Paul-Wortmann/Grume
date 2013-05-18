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

#ifndef RS232_H
#define RS232_H

#define NONE   0
#define ODD    1
#define EVEN   2
#define MARK   3
#define SPACE  4

#include <stdio.h>
#include <string.h>

#ifdef __linux__

#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#else

#include <windows.h>

#endif

class rs232_class
{
    public:
    bool  port_open;
    int   port_number;
    int   baud_rate;
    int   stop_bits;
    int   data_bits;
    int   parity;
        rs232_class (void);
       ~rs232_class (void);
    void  set_port       (int port_number_set, int baud_rate_set, int stop_bits_set, int data_bits_set, int parity_set);
    void  set_port_number(int port_number_set);
    void  set_baud_rate  (int baud_rate_set);
    void  set_stop_bits  (int stop_bits_set);
    void  set_data_bits  (int data_bits_set);
    void  set_parity     (int parity_set);
    bool  open_port      (void);
    bool  close_port     (void);
/*
    int   PollComport (int, unsigned char *, int);
    int   SendByte    (int, unsigned char);
    int   SendBuf     (int, unsigned char *, int);
    void  cprintf     (int, const char *);
    int   IsCTSEnabled(int);
*/
};

#endif //RS232_H







