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

#include "music.hpp"

music_class::music_class()
{
    music_class::music_data = NULL;
};

music_class::~music_class()
{
    Mix_HaltMusic();
    Mix_FreeMusic(music_class::music_data);
};

void music_class::play(void)
{
    Mix_PlayMusic(music_class::music_data,-1);
};

void music_class::load(std::string file_name)
{
    music_class::music_data = Mix_LoadMUS(file_name.c_str());
};

void music_class::load(std::string file_name, int reference_number)
{
    music_class::ref_number = reference_number;
    music_class::music_data = Mix_LoadMUS(file_name.c_str());
};


