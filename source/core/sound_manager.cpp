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

#include "sound_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

sound_manager_class::sound_manager_class(void)
{
    sound_manager_class::last             = NULL;
    sound_manager_class::root             = NULL;
    sound_manager_class::number_of_sounds = 0;
};

sound_manager_class::~sound_manager_class(void)
{
    Mix_HaltChannel(-1);
    sound_type* temp_pointer;
    temp_pointer = sound_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            Mix_FreeChunk(temp_pointer->sound_data);
            //delete [] temp_pointer->sound_data;
            temp_pointer = temp_pointer->next;
        }
    }
};

sound_type *sound_manager_class::add_sound(std::string file_name)
{
    if (sound_manager_class::number_of_sounds == 0)
    {
        sound_manager_class::root = new sound_type;
        sound_manager_class::root->next = NULL;
        sound_manager_class::last = new sound_type;
        sound_manager_class::last = root;
        sound_manager_class::last->next = NULL;
    }
    else
    {
        sound_type* temp_pointer;
        temp_pointer = sound_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (strcmp(file_name.c_str(),temp_pointer->path.c_str()) == 0) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        sound_manager_class::last->next = new sound_type;
        sound_manager_class::last = sound_manager_class::last->next;
        sound_manager_class::last->next = new sound_type;
        sound_manager_class::last->next = NULL;
    }
    sound_manager_class::last->path = file_name.c_str();
    sound_manager_class::last->sound_channel = -1;
    sound_manager_class::last->loaded = sound_manager_class::load_sound(last);
    if (sound_manager_class::last->loaded) sound_manager_class::number_of_sounds++;
    return(sound_manager_class::last);
};

bool sound_manager_class::load_sound(sound_type *sound)
{
    bool return_value = false;
    sound->sound_data = Mix_LoadWAV(sound->path.c_str());
    if (sound->sound_data != NULL) return_value = true;
    else game.core.log.file_write("Failed to load sound ->",sound->path.c_str());
    return (return_value);
};

void sound_manager_class::play(sound_type *sound)
{
    sound->sound_channel = Mix_PlayChannel(-1, sound->sound_data, 0);
};
