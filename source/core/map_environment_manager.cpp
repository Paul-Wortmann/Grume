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

#include "map_environment_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

map_environment_manager_class::map_environment_manager_class(void)
{
    map_environment_manager_class::root            = NULL;
    map_environment_manager_class::last            = NULL;
    map_environment_manager_class::current         = NULL;
    map_environment_manager_class::number_of_map_environment = 0;
};

map_environment_manager_class::~map_environment_manager_class(void)
{
};

map_environment_type *map_environment_manager_class::add_map_environment(std::string file_name)
{
    if (map_environment_manager_class::number_of_map_environment == 0)
    {
        map_environment_manager_class::root = new map_environment_type;
        map_environment_manager_class::root->next = NULL;
        map_environment_manager_class::last = new map_environment_type;
        map_environment_manager_class::last = root;
        map_environment_manager_class::last->next = NULL;
    }
    else
    {
        map_environment_type* temp_pointer;
        temp_pointer = map_environment_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (strcmp(file_name.c_str(),temp_pointer->path.c_str()) == 0) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        map_environment_manager_class::last->next = new map_environment_type;
        map_environment_manager_class::last = map_environment_manager_class::last->next;
        map_environment_manager_class::last->next = new map_environment_type;
        map_environment_manager_class::last->next = NULL;
    }
    map_environment_manager_class::last->path = file_name.c_str();
//    map_environment_manager_class::last->loaded = map_environment_manager_class::load_map_environment(last);
    if (map_environment_manager_class::last->loaded) map_environment_manager_class::number_of_map_environment++;
    return(map_environment_manager_class::last);
};

bool map_environment_manager_class::load_map_environment(map_environment_type *map_environment)
{
    bool return_value = false;

    return (return_value);
};

