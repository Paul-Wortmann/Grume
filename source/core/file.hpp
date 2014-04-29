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

#ifndef FILE_H
#define FILE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class file_class
{
    public:
         file_class(void);
        ~file_class(void);
        bool         extension_exist    (std::string file_name);
        bool         extension_exist    (std::string file_name, std::string file_extension);
        std::string  extension_add      (std::string file_name, std::string file_extension);
        std::string  extension_remove   (std::string file_name);
        std::string  path_get           (std::string file_name);
        std::string  path_remove        (std::string file_name);
        std::string  path_add           (std::string file_name, std::string path_name);
        char        *filetobuf          (std::string file_name);
        void         file_system_init   (char** arg_data);
        void         file_system_deinit (void);
        SDL_Surface *load_image         (std::string file_name);
        void         load_font          (font_type *font, int pt_size);
        Mix_Music   *load_music         (std::string file_name);
        Mix_Chunk   *load_sound         (std::string file_name);
        char        *load_file_to_buffer(std::string file_name);
};


#endif //FILE_H

