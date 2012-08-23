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

#ifndef NPC_H
#define NPC_H

#include <string>

class health_bar_class
{
    public:
        health_bar_class(void);
       ~health_bar_class(void);
        float             size_x;
        float             size_y;
        float             size_z;
        float             position_x;
        float             position_y;
        float             position_z;
        int               texture_base;
        int               texture_bar;
        int               texture_front;
        float             maximum;
        float             value;
        bool              mouse_over;
        int               mouse_over_count;
        int               mouse_over_maximum;
        void              draw_tooltip(void);
        void              render(void);
};

class health_class
{
    public:
        health_class(void);
       ~health_class(void);
        float             value;
        float             maximum;
        float             regeneration;
        health_bar_class  bar;
        void              process(void);
};


class npc_class
{
    public:
        npc_class(void);
       ~npc_class(void);
        std::string        name;
        health_class       health;
        void               process(void);
        void               render(void);
};

#endif // NPC_H

