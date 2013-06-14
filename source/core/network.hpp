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

#ifndef NETWORK_H
#define NETWORK_H

#include "SDL/SDL_net.h"

struct ip_struct
{
    int block_0;
    int block_1;
    int block_2;
    int block_3;
};

class network_manager_class
{
    private:
    public:
        int       enabled;
        int       port;
        bool      server;
        ip_struct ip_address_source;
        ip_struct ip_address_destination;
        bool      initialize(void);
        bool      set_ip_destination(ip_struct ip_address);
};


#endif //NETWORK_H
