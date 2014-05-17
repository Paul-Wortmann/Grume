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

#include <physfs.h>
#include "map_environment_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

map_environment_manager_class::map_environment_manager_class(void)
{
    map_environment_manager_class::root                       = NULL;
    map_environment_manager_class::last                       = NULL;
    map_environment_manager_class::current                    = NULL;
    map_environment_manager_class::number_of_map_environments = 0;
};

map_environment_manager_class::~map_environment_manager_class(void)
{
};

map_environment_type *map_environment_manager_class::add_map_environment(std::string file_name)
{
    if (map_environment_manager_class::number_of_map_environments == 0)
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
    map_environment_manager_class::last->loaded = map_environment_manager_class::load_map_environment(last);
    if (map_environment_manager_class::last->loaded) map_environment_manager_class::number_of_map_environments++;
    return(map_environment_manager_class::last);
};

bool map_environment_manager_class::load_map_environment(map_environment_type *map_environment)
{
    bool return_value = false;
    game.core.log.write("Loading environment file -> ",map_environment->path);

    if (PHYSFS_exists(map_environment->path.c_str()))
    {
        PHYSFS_openRead(map_environment->path.c_str());
        PHYSFS_File *file_pointer = NULL;
        file_pointer = PHYSFS_openRead(map_environment->path.c_str());
        if (file_pointer)
        {
            bool           tile_layer         = false;
            bool           object_layer       = false;
            int            tile_layer_count   = 0;
            int            object_layer_count = 0;
            float          temp_float_data;
            int            temp_int_data;
            std::string    temp_string_data;
            std::string    temp_string_key;
            std::string    temp_string_value;
            std::string    data_line;
            int            position_count  = 0;
            char           temp_char       = ' ';
            bool           eof_found       = false;
            char          *char_buffer     = new char[2];
            eof_found                      = false;
            while (!eof_found)
            {
                data_line = "";
                bool endl_found = false;
                while (!endl_found)
                {
                    PHYSFS_read(file_pointer, char_buffer, 1, 1);
                    if (char_buffer[0] < 32) endl_found = true;
                    eof_found = PHYSFS_eof(file_pointer);
                    if (eof_found) endl_found = true;
                    if ((!endl_found)&&(!eof_found)) data_line += char_buffer[0];
                }
                position_count = 0;
                if((data_line[position_count] != '<') && (data_line.length() > 2))
                {
                    temp_char = ' ';
                    while ((temp_char != '<') && (position_count < (int)data_line.length()))
                    {
                        temp_char = data_line[position_count];
                        position_count++;
                    }
                    position_count--;
                }
                if((data_line[position_count] == '<') && (data_line.length() > 2))
                {
                    position_count++;
                    while(position_count < (int)data_line.length())
                    {
                        temp_char         = ' ';
                        temp_string_key   = "";
                        temp_string_value = "";
                        while ((temp_char != '>') && (position_count < (int)data_line.length()))
                        {
                            temp_char = data_line[position_count];
                            if (temp_char != '>') temp_string_key += temp_char;
                            position_count++;
                        }
                        while ((temp_char != '<') && (position_count < (int)data_line.length()))
                        {
                            temp_char = data_line[position_count];
                            if (temp_char != '<') temp_string_value += temp_char;
                            position_count++;
                        }
                        temp_string_data    = temp_string_value.c_str();
                        temp_float_data     = atof(temp_string_value.c_str());
                        temp_int_data       = atoi(temp_string_value.c_str());
//                        if (temp_string_key == "version")      map_pointer->info.version          = temp_float_data;
                    }
                }
            }
            return_value = true;
            if (file_pointer) PHYSFS_close(file_pointer);
        }
        else
        {
            game.core.log.write("Fail -> PhysicsFS unable to open file - ",map_environment->path.c_str());
        }
    }
    else
    {
        game.core.log.write("Fail -> PhysicsFS unable to find file - ",map_environment->path.c_str());
    }
    return (return_value);
};

