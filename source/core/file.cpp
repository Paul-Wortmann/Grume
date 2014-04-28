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

#include <string>
#include "core.hpp"
#include "file.hpp"
#include "../game/game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <physfs.h>

extern game_class game;

file_class::file_class (void)
{

};

file_class::~file_class (void)
{

};

bool file_class::extension_exist (std::string file_name, std::string file_extension)
{
    int file_size = (int)file_name.size();
    if ((file_extension[0] == file_name[file_size-3]) &&
        (file_extension[1] == file_name[file_size-2]) &&
        (file_extension[2] == file_name[file_size-1])) return (true);
    else return (false);
};

bool file_class::extension_exist (std::string file_name)
{
    bool extention_found = false;
    for (int string_pos = 0; string_pos < (int)file_name.size(); string_pos++)
    {
        if (file_name[string_pos] == '.') extention_found = true;
    }
    return (extention_found);
};

std::string file_class::extension_add (std::string file_name, std::string file_extension)
{
    if (file_extension[0] == '.') return (file_name+file_extension);
    else return (file_name+'.'+file_extension);
};

std::string file_class::extension_remove (std::string file_name)
{
    bool            extention_found = false;
    std::string     temp_string     = "";
    for (int string_pos = 0; string_pos < (int)file_name.size(); string_pos++)
    {
        if (file_name[string_pos] == '.') extention_found = true;
        if (!extention_found) temp_string += file_name[string_pos];
    }
    return (temp_string);
};

std::string file_class::path_get (std::string file_name)
{
    int         slash_count = 0;
    int         slash_pos   = 0;
    std::string temp_string = "";
    for (int string_pos = 0; string_pos < (int)file_name.size(); string_pos++)
    {
        if (file_name[string_pos] == '/') slash_count++;
    }
    for (int string_pos = 0; string_pos < (int)file_name.size(); string_pos++)
    {
        if (slash_pos < slash_count)
        {
            temp_string += file_name[string_pos];
        }
        if (file_name[string_pos] == '/') slash_pos++;
    }
    return (temp_string);
};

std::string file_class::path_remove (std::string file_name)
{
    int             slash_position  = -1;
    std::string     temp_string     = "";
    for (int string_pos = 0; string_pos < (int)file_name.size(); string_pos++)
    {
        if (file_name[string_pos] == '\\') slash_position = string_pos;
        if (file_name[string_pos] == '/') slash_position = string_pos;
    }
    for (int string_pos = slash_position+1; string_pos < (int)file_name.size(); string_pos++)
    {
        temp_string += file_name[string_pos];
    }
    return (temp_string);
};

std::string file_class::path_add (std::string file_name, std::string path_name)
{
    return (path_name+file_name);
};

char* file_class::filetobuf (std::string file_name)
{
    FILE *file_pointer;
    long length;
    char *buf;
    file_pointer = fopen(file_name.c_str(), "rb");
    if (!file_pointer)
    {
        game.core.log.file_write("Failed to load file into buffer -> ",file_name);
        return NULL;
    }
    fseek(file_pointer, 0, SEEK_END);
    length = ftell(file_pointer);
    buf = (char*)malloc(length+1);
    fseek(file_pointer, 0, SEEK_SET);
    fread(buf, length, 1, file_pointer);
    fclose(file_pointer);
    buf[length] = 0;
    return buf;
}

void file_class::file_system_init(char** arg_data)
{
    game.core.log.file_write("Initializing Physics File System.");
    PHYSFS_init(arg_data[0]);
    PHYSFS_Version version_info;
    PHYSFS_getLinkedVersion(&version_info);
    game.core.log.file_write("PhysFS Version -> ",version_info.major,".",version_info.minor,".",version_info.patch);
    PHYSFS_addToSearchPath("frost_and_flame.dat", 1);
}

void file_class::file_system_deinit(void)
{
    game.core.log.file_write("Shutting down Physics File System.");
    PHYSFS_deinit();
}

SDL_Surface * file_class::load_image(std::string file_name)
{
    SDL_Surface *temp_serface = NULL;
    if (PHYSFS_exists(file_name.c_str()))
    {
        PHYSFS_openRead(file_name.c_str());
        PHYSFS_File *file_pointer = NULL;
        file_pointer = PHYSFS_openRead(file_name.c_str());
        if (file_pointer)
        {
            PHYSFS_sint64 file_size = PHYSFS_fileLength(file_pointer);
            char *file_data = new char[file_size];
            PHYSFS_read(file_pointer, file_data, 1, file_size);
            SDL_RWops *rwops_pointer = NULL;
            rwops_pointer = SDL_RWFromMem(file_data, file_size);
            if (rwops_pointer != NULL)
            {
                temp_serface  = IMG_Load_RW(rwops_pointer, false);
                if (rwops_pointer) SDL_FreeRW(rwops_pointer);
            }
            else
            {
                game.core.log.file_write("Fail -> PhysicsFS unable to allocate rwops pointer for file - ",file_name.c_str());
            }
            if (file_data) delete [] file_data;
            if (file_pointer) PHYSFS_close(file_pointer);
        }
        else
        {
            game.core.log.file_write("Fail -> PhysicsFS unable to open file - ",file_name.c_str());
        }
    }
    else
    {
        game.core.log.file_write("Fail -> PhysicsFS unable to find file - ",file_name.c_str());
    }
    if (!temp_serface) game.state = STATE_QUIT;
    return(temp_serface);
}

void file_class::load_font(font_type *font, int pt_size)
{
    if (PHYSFS_exists(font->path.c_str()))
    {
        PHYSFS_openRead(font->path.c_str());
        PHYSFS_File *file_pointer = NULL;
        file_pointer = PHYSFS_openRead(font->path.c_str());
        if (file_pointer)
        {
            PHYSFS_sint64 file_size = PHYSFS_fileLength(file_pointer);
            font->file_data = new char[file_size];
            PHYSFS_read(file_pointer, font->file_data, 1, file_size);
            font->rwops_pointer = SDL_RWFromMem(font->file_data, file_size);
            if (font->rwops_pointer != NULL)
            {
                font->font_data = TTF_OpenFontRW(font->rwops_pointer, false,pt_size);
                if (!font->font_data) game.core.log.file_write("Fail -> TTF_OpenFontRW: ",TTF_GetError());
            }
            else
            {
                game.core.log.file_write("Fail -> PhysicsFS unable to allocate rwops pointer for file - ",font->path.c_str());
            }
            if (file_pointer) PHYSFS_close(file_pointer);
        }
        else
        {
            game.core.log.file_write("Fail -> PhysicsFS unable to open file - ",font->path.c_str());
        }
    }
    else
    {
        game.core.log.file_write("Fail -> PhysicsFS unable to find file - ",font->path.c_str());
    }
    if (!font->font_data) game.state = STATE_QUIT;
}

Mix_Music *file_class::load_music(std::string file_name)
{
    Mix_Music *temp_music = NULL;
    if (PHYSFS_exists(file_name.c_str()))
    {
        PHYSFS_openRead(file_name.c_str());
        PHYSFS_File *file_pointer = NULL;
        file_pointer = PHYSFS_openRead(file_name.c_str());
        if (file_pointer)
        {
            PHYSFS_sint64 file_size = PHYSFS_fileLength(file_pointer);
            char *file_data = new char[file_size];
            PHYSFS_read(file_pointer, file_data, 1, file_size);
            SDL_RWops *rwops_pointer = NULL;
            rwops_pointer = SDL_RWFromMem(file_data, file_size);
            if (rwops_pointer != NULL)
            {
                temp_music  = Mix_LoadMUS_RW(rwops_pointer, false);
                if (rwops_pointer) SDL_FreeRW(rwops_pointer);
            }
            else
            {
                game.core.log.file_write("Fail -> PhysicsFS unable to allocate rwops pointer for file - ",file_name.c_str());
            }
            if (file_data) delete [] file_data;
            if (file_pointer) PHYSFS_close(file_pointer);
        }
        else
        {
            game.core.log.file_write("Fail -> PhysicsFS unable to open file - ",file_name.c_str());
        }
    }
    else
    {
        game.core.log.file_write("Fail -> PhysicsFS unable to find file - ",file_name.c_str());
    }
    if (!temp_music) game.state = STATE_QUIT;
    return(temp_music);
}

Mix_Chunk *file_class::load_sound(std::string file_name)
{
    Mix_Chunk *temp_sound = NULL;
    if (PHYSFS_exists(file_name.c_str()))
    {
        PHYSFS_openRead(file_name.c_str());
        PHYSFS_File *file_pointer = NULL;
        file_pointer = PHYSFS_openRead(file_name.c_str());
        if (file_pointer)
        {
            PHYSFS_sint64 file_size = PHYSFS_fileLength(file_pointer);
            char *file_data = new char[file_size];
            PHYSFS_read(file_pointer, file_data, 1, file_size);
            SDL_RWops *rwops_pointer = NULL;
            rwops_pointer = SDL_RWFromMem(file_data, file_size);
            if (rwops_pointer != NULL)
            {
                temp_sound  = Mix_LoadWAV_RW(rwops_pointer, false);
                if (rwops_pointer) SDL_FreeRW(rwops_pointer);
            }
            else
            {
                game.core.log.file_write("Fail -> PhysicsFS unable to allocate rwops pointer for file - ",file_name.c_str());
            }
            if (file_data) delete [] file_data;
            if (file_pointer) PHYSFS_close(file_pointer);
        }
        else
        {
            game.core.log.file_write("Fail -> PhysicsFS unable to open file - ",file_name.c_str());
        }
    }
    else
    {
        game.core.log.file_write("Fail -> PhysicsFS unable to find file - ",file_name.c_str());
    }
    if (!temp_sound) game.state = STATE_QUIT;
    return(temp_sound);
}
