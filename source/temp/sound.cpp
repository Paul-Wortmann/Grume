/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "sound.hpp"

sound_class::sound_class()
{
    sound_class::sound_channel = -1;
};

sound_class::~sound_class()
{
    Mix_HaltChannel(-1);
    if (sound_class::sound_data != NULL) Mix_FreeChunk(sound_class::sound_data);
};

void sound_class::load(std::string file_name)
{
    sound_class::sound_data = Mix_LoadWAV(file_name.c_str());
};

void sound_class::play(void)
{
    sound_class::sound_channel = Mix_PlayChannel(-1, sound_data, 0);
};

