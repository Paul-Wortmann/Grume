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

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "textures.hpp"
#include "../game.hpp"

#define GL_BGR  0x80E0
#define GL_BGRA 0x80E1

extern  game_class    game;

texture_class::texture_class()
{
    texture_class::width             = DEFAULT_FRAME_WIDTH;
    texture_class::height            = DEFAULT_FRAME_HEIGHT;
    texture_class::rotate_able       = false;
    texture_class::rotate_speed      = 0.0f;
    texture_class::rotate_direction  = 0;
    texture_class::angle             = 0.0f;
    texture_class::frame_number      = 0;
    texture_class::frame_max         = 0;
    texture_class::frame_delay       = 0.0f;
    texture_class::frame_delay_count = 0.0f;
    texture_class::frame_delay_max   = 0.0f;
};

texture_class::~texture_class()
{
    for (int frame_count = 0; frame_count < frame_max; frame_count++)
    {
        if (texture_class::frame[frame_count].active) glDeleteTextures(1, &texture_class::frame[frame_count].data);
    }
};

bool texture_class::load_image(void)
{
    if (texture_class::path.length() > 4)
    {
        texture_class::load_image(texture_class::path);
        return(true);
    }
    else return(false);
};

bool texture_class::load_image(std::string file_name)
{
    SDL_Surface    *image_surface = NULL;
    GLenum          texture_format = 0;
    GLint           number_of_colors;
    bool            return_value = false;
    texture_class::frame_max     = 0;
    texture_class::frame = new frame_type[texture_class::frame_max+1];
    texture_class::path  = file_name;
    if ((image_surface = IMG_Load(file_name.c_str())))
    {
        return_value = true;
        if ((image_surface->w & (image_surface->w - 1)) != 0 );
        if ((image_surface->h & (image_surface->h - 1)) != 0 );
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

        glGenTextures( 1, &texture_class::frame[texture_class::frame_number].data);
        glBindTexture( GL_TEXTURE_2D, texture_class::frame[texture_class::frame_number].data);
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
        game.core.log.file_write("Failed to load image ->",file_name.c_str());
    }
    if ( image_surface ) SDL_FreeSurface( image_surface );
    return(return_value);
};

bool texture_class::load_spritesheet(std::string file_name)
{
    texture_class::load_spritesheet(file_name,DEFAULT_FRAME_WIDTH,DEFAULT_FRAME_HEIGHT);
    return(true);
};

bool texture_class::load_spritesheet(std::string file_name, int width, int height)
{
    texture_class::width      = width;
    texture_class::height     = height;
    int             frames_x;
    int             frames_y;
    int             frame_number   = 0;
    int             num_sprites    = 0;
    SDL_Surface    *sprite_sheet   = NULL;
    SDL_Surface    *temp_surface   = NULL;
    int             flags          = 0;
    GLenum          texture_format = 0;
    GLint           number_of_colors;
    bool            return_value   = false;
    texture_class::path  = file_name;
   if ((sprite_sheet = IMG_Load(file_name.c_str())))
    {
        return_value = true;
        if ((sprite_sheet->w & (sprite_sheet->w - 1)) != 0 );
        if ((sprite_sheet->h & (sprite_sheet->h - 1)) != 0 );
        frames_x = sprite_sheet->w / texture_class::width;
        frames_y = sprite_sheet->h / texture_class::height;
        num_sprites = frames_x * frames_y;
        texture_class::frame_max = num_sprites-1;
        texture_class::frame = new frame_type[texture_class::frame_max+1];
        number_of_colors = sprite_sheet->format->BytesPerPixel;
        if (number_of_colors == 4)
        {
            if (sprite_sheet->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
            else texture_format = GL_BGRA;
        }
        else if (number_of_colors == 3)
        {
            if (sprite_sheet->format->Rmask == 0x000000ff) texture_format = GL_RGB;
            else texture_format = GL_BGR;
        }
        temp_surface = SDL_CreateRGBSurface(flags,texture_class::width-1,texture_class::height-1,sprite_sheet->format->BitsPerPixel,sprite_sheet->format->Rmask,sprite_sheet->format->Gmask,sprite_sheet->format->Bmask,sprite_sheet->format->Amask);
        int32_t     *in_pixels       = (int32_t*)sprite_sheet->pixels;
        int32_t     *out_pixels      = (int32_t*)temp_surface->pixels;

        for (int current_sprite_y = 0; current_sprite_y < frames_y; current_sprite_y++)
        {
            for (int current_sprite_x = 0; current_sprite_x < frames_x; current_sprite_x++)
            {
                int out_pixel_count = 0;
                if(SDL_MUSTLOCK(sprite_sheet)) SDL_LockSurface(sprite_sheet);
                for(int y_count = 0; y_count < texture_class::height-1; y_count++)
                {
                    for(int x_count = 0; x_count < texture_class::width-1; x_count++)
                    {
                        out_pixels[out_pixel_count] = in_pixels[((sprite_sheet->w*y_count)+(((frame_number)*(texture_class::width))+x_count))];
                        out_pixel_count++;
                    }
                }
                if(SDL_MUSTLOCK(sprite_sheet)) SDL_UnlockSurface(sprite_sheet);
                texture_class::frame[frame_number].active = true;
                glGenTextures( 1, &texture_class::frame[frame_number].data);
                glBindTexture( GL_TEXTURE_2D, texture_class::frame[frame_number].data);
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
                glTexImage2D( GL_TEXTURE_2D, 0, number_of_colors, temp_surface->w, temp_surface->h, 0, texture_format, GL_UNSIGNED_BYTE, temp_surface->pixels );
                frame_number++;
            }
        }
    }
    else
    {
        return_value = false;
        if ( sprite_sheet ) SDL_FreeSurface( sprite_sheet );
        if ( temp_surface ) SDL_FreeSurface( temp_surface );
        game.core.log.file_write("Failed to load image ->",file_name.c_str());
    }
    if ( sprite_sheet ) SDL_FreeSurface( sprite_sheet );
    if ( temp_surface ) SDL_FreeSurface( temp_surface );
    return(return_value);
};

void texture_class::bind_image(void)
{
    glBindTexture(GL_TEXTURE_2D, texture_class::frame[0].data);
};

void texture_class::process(void)
{
    //process rotation
    if(texture_class::rotate_able)
    {
        if(texture_class::rotate_direction == 0)
        {
            texture_class::angle += texture_class::rotate_speed;
            if (texture_class::angle > 6.2832f) texture_class::angle = 0.0f;
        }
        if(texture_class::rotate_direction == 1)
        {
            texture_class::angle -= texture_class::rotate_speed;
            if (texture_class::angle < 0.0f) texture_class::angle = 6.2832f;
        }
    }
    // process frames
    texture_class::frame_delay_count += texture_class::frame_delay;
    if (texture_class::frame_delay_count > texture_class::frame_delay_max)
    {
        texture_class::frame_delay_count = 0.0f;
        texture_class::frame_number++;
        if (texture_class::frame_number > texture_class::frame_max) texture_class::frame_number = 0;
    }
};

void texture_class::draw(bool rumble, float pos_x, float pos_y, float pos_z, float width, float height)
{
/*
    if (rumble)
    {
        pos_x += game_o.rumble.counter_x;
        pos_y += game_o.rumble.counter_y;
    }
*/
    if (texture_class::frame[texture_class::frame_number].data) // Only render if data is available.
    {
        int temp_angle;
        if (texture_class::angle != 0) temp_angle = 360 - texture_class::angle;
        else temp_angle = 0;
        glPushMatrix();
        glBindTexture( GL_TEXTURE_2D, texture_class::frame[texture_class::frame_number].data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x-(width/2),pos_y-(height/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x-(width/2),pos_y-(height/2), temp_angle), pos_z);
        glTexCoord2i( 0, 0 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x-(width/2),pos_y+(height/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x-(width/2),pos_y+(height/2), temp_angle), pos_z);
        glTexCoord2i( 1, 0 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+(width/2),pos_y+(height/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+(width/2),pos_y+(height/2), temp_angle), pos_z);
        glTexCoord2i( 1, 1 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+(width/2),pos_y-(height/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+(width/2),pos_y-(height/2), temp_angle), pos_z);
        glEnd();
        glPopMatrix();
    }
};

void texture_class::draw(bool rumble, float pos_x, float pos_y, float pos_z, float width, float height, int angle)
{
    texture_class::angle = angle;//game.core.physics.degrees_to_radians(angle);
    texture_class::draw(rumble,pos_x,pos_y,pos_z,width,height);
};

void texture_class::draw(bool rumble, float pos_x, float pos_y, float pos_z, float width, float height, float angle)
{
    texture_class::angle = angle;
    texture_class::draw(rumble,pos_x,pos_y,pos_z,width,height);
};

void texture_class::draw(bool rumble, float pos_x, float pos_y, float pos_z, float width, float height, float angle, float alpha)
{
    texture_class::angle = angle;
    glColor4f (1.0f, 1.0f, 1.0f, alpha);
    texture_class::draw(rumble,pos_x,pos_y,pos_z,width,height);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_class::draw(bool rumble, float pos_x, float pos_y, float pos_z, float width, float height, float angle, float red, float green, float blue, float alpha)
{
    texture_class::angle = angle;
    glColor4f (red, green, blue, alpha);
    texture_class::draw(rumble,pos_x,pos_y,pos_z,width,height);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_class::draw(bool rumble, float pos_x, float pos_y, float pos_z, float width, float height, float angle, float red, float green, float blue, float alpha, int frame)
{
    texture_class::frame_number = frame;
    texture_class::angle        = angle;
    glColor4f (red, green, blue, alpha);
    texture_class::draw(rumble,pos_x,pos_y,pos_z,width,height);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_class::draw(bool rumble, float pos_x, float pos_y, float pos_z, float width, float height, float angle, int frame)
{
    texture_class::frame_number = frame;
    texture_class::angle        = angle;
    texture_class::draw(rumble,pos_x,pos_y,pos_z,width,height);
};



