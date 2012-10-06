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

#ifndef WINDOW_ELEMENT_H
#define WINDOW_ELEMENT_H

#include <string>
#include "../core/textures.hpp"

struct struct_3f
{
    float x;
    float y;
    float z;
};

class window_element_class
{
    protected:
    private:
    public:
        bool            mouse_over;
        std::string     image_path;
        texture_class   image;
        struct_3f       size;
        struct_3f       position;
        window_element_class(void);
       ~window_element_class(void);
        void process(void);
};

#endif // WINDOW_ELEMENT_H
