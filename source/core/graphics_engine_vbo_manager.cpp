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


#include "graphics_engine_vbo_manager.hpp"
#include "core.hpp"

extern core_struct core;

vbo_manager_class::vbo_manager_class(void)
{
    vbo_manager_class::last               = NULL;
    vbo_manager_class::root               = NULL;
    vbo_manager_class::number_of_vbos     = 0;
};

vbo_manager_class::~vbo_manager_class(void)
{
    vbo_type* temp_pointer;
    temp_pointer = vbo_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            //delete [] temp_pointer->data.;
            temp_pointer = temp_pointer->next;
        }
    }
    //delete [] root;
    //delete [] last;
};

vbo_type* vbo_manager_class::add_vbo(std::string file_name)
{
    if (vbo_manager_class::number_of_vbos == 0)
    {
        vbo_manager_class::root = new vbo_type;
        vbo_manager_class::root->next = NULL;
        vbo_manager_class::last = new vbo_type;
        vbo_manager_class::last = root;
        vbo_manager_class::last->next = NULL;
    }
    else
    {
        vbo_type* temp_pointer = vbo_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (strcmp(file_name.c_str(),temp_pointer->data.file.c_str()) == 0) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        vbo_manager_class::last->next = new vbo_type;
        vbo_manager_class::last = vbo_manager_class::last->next;
        vbo_manager_class::last->next = new vbo_type;
        vbo_manager_class::last->next = NULL;
    }
    vbo_manager_class::last->data.file   = file_name.c_str();
    vbo_manager_class::last->data.loaded = vbo_manager_class::load_vbo(last);
    if (vbo_manager_class::last->data.loaded) vbo_manager_class::number_of_vbos++;
    return(vbo_manager_class::last);
}

bool vbo_manager_class::load_vbo(vbo_type *vbo_pointer)
{
    bool return_value = false;


    return (return_value);
}
