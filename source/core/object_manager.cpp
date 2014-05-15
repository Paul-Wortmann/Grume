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

#include "object_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

object_manager_class::object_manager_class(void)
{
    object_manager_class::current           = NULL;
    object_manager_class::last              = NULL;
    object_manager_class::root              = NULL;
    object_manager_class::number_of_objects = 0;
};

object_manager_class::~object_manager_class(void)
{
    Mix_HaltMusic();
    object_type* temp_pointer;
    temp_pointer = object_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            //Mix_FreeMusic(temp_pointer->object_data);
            temp_pointer = temp_pointer->next;
        }
    }
};

object_type *object_manager_class::add_object(std::string file_name)
{
    if (object_manager_class::number_of_objects == 0)
    {
        object_manager_class::root = new object_type;
        object_manager_class::root->next = NULL;
        object_manager_class::last = new object_type;
        object_manager_class::last = root;
        object_manager_class::last->next = NULL;
    }
    else
    {
        object_type* temp_pointer;
        temp_pointer = object_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (strcmp(file_name.c_str(),temp_pointer->path.c_str()) == 0) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        object_manager_class::last->next = new object_type;
        object_manager_class::last = object_manager_class::last->next;
        object_manager_class::last->next = new object_type;
        object_manager_class::last->next = NULL;
    }
    object_manager_class::last->path = file_name.c_str();
    object_manager_class::last->loaded = object_manager_class::load_object(last);
    if (object_manager_class::last->loaded) object_manager_class::number_of_objects++;
    return(object_manager_class::last);
};

bool object_manager_class::load_object(object_type *object)
{
    bool return_value = false;
    //object->object_data = Mix_LoadMUS(object->path.c_str());
    if (object->object_data != NULL) return_value = true;
    else game.core.log.write("Failed to load object ->",object->path.c_str());
    return (return_value);
};

/*
void object_manager_class::play(object_type *object)
{
//    Mix_PlayMusic(object->object_data,-1);
};
*/
