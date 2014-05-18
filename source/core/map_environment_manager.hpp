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

#ifndef MAP_ENVIRONMENT_H
#define MAP_ENVIRONMENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include "texture_manager.hpp"
#include "music_manager.hpp"

struct mem_music_data_type
{
    std::string   file_name;
    music_type*   data;
};

struct mem_texture_data_type
{
    std::string   file_name;
    texture_type* data;
};

struct mem_model_data_type
{
    std::string file_name;
};

struct map_environment_type
{
    bool                   loaded;
    std::string            path;
    float                  version;
    int                    number_of_musics;
    int                    number_of_load_screens;
    int                    number_of_textures_floor;
    int                    number_of_textures_wall;
    int                    number_of_models_wall;
    int                    number_of_models_debris;
    mem_music_data_type   *music;
    mem_texture_data_type *texture_load_screen;
    mem_texture_data_type *texture_floor;
    mem_texture_data_type *texture_wall;
    mem_model_data_type   *model_wall;
    mem_model_data_type   *model_debris;
    map_environment_type  *next;
};

class map_environment_manager_class
{
    public:
        map_environment_manager_class(void);
       ~map_environment_manager_class(void);
        int                     number_of_map_environments;
        map_environment_type   *root;
        map_environment_type   *last;
        map_environment_type   *current;
        map_environment_type   *add_map_environment(std::string file_name);
        bool                    load_map_environment(map_environment_type *map_environment);
};

#endif // MAP_ENVIRONMENT_H

