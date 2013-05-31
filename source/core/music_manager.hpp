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

#ifndef MUSIC_MANAGER_H
#define MUSIC_MANAGER_H

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <string>

struct music_type
{
    bool             loaded;
    std::string      path;
    Mix_Music       *music_data;
    music_type      *next;
};

class music_manager_class
{
    public:
        music_manager_class(void);
       ~music_manager_class(void);
        int           number_of_music;
        int           track;
        bool          next_track;
        music_type   *root;
        music_type   *last;
        music_type   *current;
        music_type   *add_music(std::string file_name);
        bool          load_music(music_type *music);
        void          play(music_type *music);
};

#endif // MUSIC_MANAGER_H
