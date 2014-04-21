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

#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <string>

struct object_data_type
{
    bool remove_me;
};

struct object_type
{
    bool              loaded;
    std::string       path;
    object_data_type* object_data;
    object_type*      next;
};

class object_manager_class
{
    public:
        object_manager_class(void);
       ~object_manager_class(void);
        int           number_of_objects;
        object_type*  root;
        object_type*  last;
        object_type*  current;
        object_type*  add_object(std::string file_name);
        bool          load_object(object_type *object);
        //void          play(object_type *object);
};

#endif // OBJECT_MANAGER_H
