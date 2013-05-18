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

#include "texture_manager.hpp"
#include "../game.hpp"

extern game_class game;

texture_manager_class::texture_manager_class(void)
{
    texture_manager_class::number_of_textures = 0;
};

texture_manager_class::~texture_manager_class(void)
{
    delete [] root;
    delete [] last;
};

texture_type *texture_manager_class::add_texture(std::string file_name)
{
    if (texture_manager_class::number_of_textures == 0)
    {
        texture_manager_class::root = new texture_type;
        texture_manager_class::root->next = NULL;
        texture_manager_class::last = new texture_type;
        texture_manager_class::last = root;
        texture_manager_class::last->next = NULL;
    }
    else
    {
        texture_type* temp_pointer;
        temp_pointer = new texture_type;
        temp_pointer = texture_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer->next != NULL)
            {
                if (strcmp(file_name.c_str(),temp_pointer->path.c_str()) == 0)
                {
                    return(temp_pointer);
                }
                temp_pointer = temp_pointer->next;
            }
        }
        texture_manager_class::number_of_textures++;
        texture_manager_class::last->next = new texture_type;
        texture_manager_class::last = texture_manager_class::last->next;
        texture_manager_class::last->next = new texture_type;
        texture_manager_class::last->next = NULL;
    }
    texture_manager_class::last->loaded             = false;
    texture_manager_class::last->path               = file_name.c_str();
    texture_manager_class::last->width              = DEFAULT_FRAME_WIDTH;
    texture_manager_class::last->height             = DEFAULT_FRAME_HEIGHT;
    texture_manager_class::last->rotate_able        = false;
    texture_manager_class::last->rotate_speed       = 0.0f;
    texture_manager_class::last->rotate_direction   = 0;
    texture_manager_class::last->angle              = 0.0f;
    texture_manager_class::last->frame_delay        = 0.0f;
    texture_manager_class::last->frame_delay_count  = 0.0f;
    texture_manager_class::last->frame_delay_max    = 0.0f;
    texture_manager_class::last->frame_number       = 0;
    texture_manager_class::last->frame_max          = 0;
    return(texture_manager_class::last);
};

void texture_manager_class::load_textures(void)
{
    texture_type* temp_pointer;
    temp_pointer = new texture_type;
    temp_pointer = texture_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            if (!temp_pointer->loaded)
            {
                if (temp_pointer->path.length() > 4) load_texture(temp_pointer);
            }
            temp_pointer = temp_pointer->next;
        }
    }
};

void texture_manager_class::reload_textures(void)
{
    texture_type* temp_pointer;
    temp_pointer = new texture_type;
    temp_pointer = texture_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            if (temp_pointer->path.length() > 4) load_texture(temp_pointer);
        }
    }
};

bool texture_manager_class::load_texture(texture_type *texure)
{
    SDL_Surface    *image_surface = NULL;
    GLenum          texture_format = 0;
    GLint           number_of_colors;
    bool            return_value = false;
    texure->frame_max     = 0;
    texure->frame = new frame_type[texure->frame_max+1];
    if ((image_surface = IMG_Load(texure->path.c_str())))
    {
        return_value = true;
        number_of_colors = image_surface->format->BytesPerPixel;
        if (number_of_colors == 4)
        {
            if (image_surface->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
            else texture_format = GL_BGRA;
        }
        else if (number_of_colors == 3)
        {
            if (image_surface->format->Rmask == 0x000000ff) texture_format = GL_RGB;
            else texture_format = GL_BGR;
        }

        glGenTextures( 1, &texure->frame[texure->frame_number].data);
        glBindTexture( GL_TEXTURE_2D, texure->frame[texure->frame_number].data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexImage2D( GL_TEXTURE_2D, 0, number_of_colors, image_surface->w, image_surface->h, 0, texture_format, GL_UNSIGNED_BYTE, image_surface->pixels );
    }
    else
    {
        return_value = false;
        if ( image_surface ) SDL_FreeSurface( image_surface );
        game.core.log.file_write("Failed to load image ->",texure->path.c_str());
    }
    if ( image_surface ) SDL_FreeSurface( image_surface );
    return(return_value);
};

