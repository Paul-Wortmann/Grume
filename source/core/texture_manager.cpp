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
    texture_type* temp_pointer;
    temp_pointer = new texture_type;
    temp_pointer = texture_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            delete [] temp_pointer->frame;
            temp_pointer = temp_pointer->next;
        }
    }
    //delete [] root;
    //delete [] last;
};

texture_type *texture_manager_class::add_texture(std::string file_name)
{
    return(texture_manager_class::add_texture(file_name,false));
};

texture_type *texture_manager_class::add_texture(std::string file_name, bool is_sprite_sheet)
{
    return(texture_manager_class::add_texture(file_name,is_sprite_sheet,DEFAULT_FRAME_WIDTH,DEFAULT_FRAME_HEIGHT));
};

texture_type *texture_manager_class::add_texture(std::string file_name, bool is_sprite_sheet, int width_set, int height_set)
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
        texture_manager_class::last->next = new texture_type;
        texture_manager_class::last = texture_manager_class::last->next;
        texture_manager_class::last->next = new texture_type;
        texture_manager_class::last->next = NULL;
    }
    texture_manager_class::last->sprite_sheet       = is_sprite_sheet;
    texture_manager_class::last->path               = file_name.c_str();
    texture_manager_class::last->width              = width_set;
    texture_manager_class::last->height             = height_set;
    texture_manager_class::last->rotate_able        = false;
    texture_manager_class::last->rotate_speed       = 0.0f;
    texture_manager_class::last->rotate_direction   = 0;
    texture_manager_class::last->angle              = 0.0f;
    texture_manager_class::last->frame_delay        = 0.0f;
    texture_manager_class::last->frame_delay_count  = 0.0f;
    texture_manager_class::last->frame_delay_max    = 0.0f;
    texture_manager_class::last->frame_number       = 0;
    texture_manager_class::last->frame_max          = 0;
    if (is_sprite_sheet) texture_manager_class::last->loaded = texture_manager_class::load_sprite_sheet(last,texture_manager_class::last->width,texture_manager_class::last->height);
    else  texture_manager_class::last->loaded = texture_manager_class::load_texture(last);
    if (texture_manager_class::last->loaded) texture_manager_class::number_of_textures++;
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
                if (temp_pointer->path.length() > 4)
                {
                    if (temp_pointer->sprite_sheet) load_sprite_sheet(temp_pointer);
                    else load_texture(temp_pointer);
                }
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
            if (temp_pointer->sprite_sheet) load_sprite_sheet(temp_pointer);
            else load_texture(temp_pointer);
            temp_pointer = temp_pointer->next;
        }
    }
};

bool texture_manager_class::load_texture(texture_type *texture)
{
    GLint           number_of_colors;
    SDL_Surface    *image_surface  = NULL;
    GLenum          texture_format = 0;
    bool            return_value   = false;
    texture->frame_max              = 0;
    texture->frame                  = new frame_type[texture->frame_max+1];
    texture->sprite_sheet          = false;
    if ((image_surface = IMG_Load(texture->path.c_str())))
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
        glGenTextures  (1, &texture->frame[texture->frame_number].data);
        glBindTexture  (GL_TEXTURE_2D, texture->frame[texture->frame_number].data);
        glEnable       (GL_BLEND);
        glBlendFunc    (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glPixelStorei  (GL_UNPACK_ALIGNMENT, 1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvf      (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexImage2D   (GL_TEXTURE_2D, 0, number_of_colors, image_surface->w, image_surface->h, 0, texture_format, GL_UNSIGNED_BYTE, image_surface->pixels);
    }
    else
    {
        return_value = false;
        if (image_surface) SDL_FreeSurface(image_surface);
        game.core.log.file_write("Failed to load image ->",texture->path.c_str());
    }
    if (image_surface) SDL_FreeSurface(image_surface);
    texture->loaded = return_value;
    return(return_value);
};

bool texture_manager_class::load_sprite_sheet(texture_type *texture)
{
    return(texture_manager_class::load_sprite_sheet(texture,DEFAULT_FRAME_WIDTH,DEFAULT_FRAME_HEIGHT));
};

bool texture_manager_class::load_sprite_sheet(texture_type *texture, int width_set, int height_set)
{
    texture->sprite_sheet          = true;
    texture->width                  = width_set;
    texture->height                 = height_set;
    int             frames_x;
    int             frames_y;
    int             frame_count    = 0;
    int             num_sprites    = 0;
    SDL_Surface    *sprite_sheet   = NULL;
    SDL_Surface    *temp_surface   = NULL;
    int             flags          = 0;
    GLenum          texture_format = 0;
    GLint           number_of_colors;
    bool            return_value   = false;
    if ((sprite_sheet = IMG_Load(texture->path.c_str())))
    {
        return_value = true;
        frames_x = sprite_sheet->w / texture->width;
        frames_y = sprite_sheet->h / texture->height;
        num_sprites = frames_x * frames_y;
        texture->frame_max = num_sprites-1;
        texture->frame = new frame_type[texture->frame_max+1];
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
        temp_surface = SDL_CreateRGBSurface(flags,texture->width-1,texture->height-1,sprite_sheet->format->BitsPerPixel,sprite_sheet->format->Rmask,sprite_sheet->format->Gmask,sprite_sheet->format->Bmask,sprite_sheet->format->Amask);
        int32_t     *in_pixels       = (int32_t*)sprite_sheet->pixels;
        int32_t     *out_pixels      = (int32_t*)temp_surface->pixels;

        for (int current_sprite_y = 0; current_sprite_y < frames_y; current_sprite_y++)
        {
            for (int current_sprite_x = 0; current_sprite_x < frames_x; current_sprite_x++)
            {
                int out_pixel_count = 0;
                if (SDL_MUSTLOCK(sprite_sheet)) SDL_LockSurface(sprite_sheet);
                for (int y_count = 0; y_count < texture->height-1; y_count++)
                {
                    for (int x_count = 0; x_count < texture->width-1; x_count++)
                    {
                        out_pixels[out_pixel_count] = in_pixels[((sprite_sheet->w*y_count)+(((frame_count)*(texture->width))+x_count))];
                        out_pixel_count++;
                    }
                }
                if (SDL_MUSTLOCK(sprite_sheet)) SDL_UnlockSurface(sprite_sheet);
                texture->frame[frame_count].active = true;
                glGenTextures  (1, &texture->frame[texture->frame_number].data);
                glBindTexture  (GL_TEXTURE_2D, texture->frame[texture->frame_number].data);
                glEnable       (GL_BLEND);
                glBlendFunc    (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glPixelStorei  (GL_UNPACK_ALIGNMENT, 1);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexEnvf      (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
                glTexImage2D   (GL_TEXTURE_2D, 0, number_of_colors, temp_surface->w, temp_surface->h, 0, texture_format, GL_UNSIGNED_BYTE, temp_surface->pixels);
                frame_count++;
            }
        }
    }
    else
    {
        return_value = false;
        game.core.log.file_write("Failed to load image ->",texture->path.c_str());
    }
    if (sprite_sheet) SDL_FreeSurface(sprite_sheet);
    if (temp_surface) SDL_FreeSurface(temp_surface);
    texture->loaded = return_value;
    return(return_value);
};

void texture_manager_class::bind_image(texture_type *texture)
{
    glBindTexture(GL_TEXTURE_2D, texture->frame[0].data);
};

void texture_manager_class::process(texture_type *texture)
{
    //process rotation
    if(texture->rotate_able)
    {
        if(texture->rotate_direction == 0)
        {
            texture->angle += texture->rotate_speed;
            if (texture->angle > 6.2832f) texture->angle = 0.0f;
        }
        if(texture->rotate_direction == 1)
        {
            texture->angle -= texture->rotate_speed;
            if (texture->angle < 0.0f) texture->angle = 6.2832f;
        }
    }
    // process frames
    texture->frame_delay_count += texture->frame_delay;
    if (texture->frame_delay_count > texture->frame_delay_max)
    {
        texture->frame_delay_count = 0.0f;
        texture->frame_number++;
        if (texture->frame_number > texture->frame_max) texture->frame_number = 0;
    }
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set)
{
    if ((!game.debug) && (texture->sprite_sheet))
    {
        game.core.log.file_write("Frame number -> ",texture->frame_number);
        game.core.log.file_write("Frame max    -> ",texture->frame_max);
        game.debug = true;
    }

    if (rumble_set)
    {
        game.rumble.counter.x = 0.0f;
        game.rumble.counter.y = 0.0f;
        pos_x += game.rumble.counter.x;
        pos_y += game.rumble.counter.y;
    }
    if (sizeof(texture->frame[texture->frame_number].data) > 0) // Only render if data is available.
    {
        int temp_angle;
        if (texture->angle != 0) temp_angle = 360 - texture->angle;
        else temp_angle = 0;
        glPushMatrix();
        glBindTexture( GL_TEXTURE_2D, texture->frame[texture->frame_number].data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 0, 1 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x-(width_set/2),pos_y-(height_set/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x-(width_set/2),pos_y-(height_set/2), temp_angle), pos_z);
        glTexCoord2i( 0, 0 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x-(width_set/2),pos_y+(height_set/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x-(width_set/2),pos_y+(height_set/2), temp_angle), pos_z);
        glTexCoord2i( 1, 0 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+(width_set/2),pos_y+(height_set/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+(width_set/2),pos_y+(height_set/2), temp_angle), pos_z);
        glTexCoord2i( 1, 1 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+(width_set/2),pos_y-(height_set/2),temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+(width_set/2),pos_y-(height_set/2), temp_angle), pos_z);
        glEnd();
        glPopMatrix();
    }
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, int angle_set)
{
    texture->angle = angle_set;//game.core.physics.degrees_to_radians(angle);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set)
{
    texture->angle = angle_set;
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, float alpha)
{
    texture->angle = angle_set;
    glColor4f (1.0f, 1.0f, 1.0f, alpha);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, float red, float green, float blue, float alpha)
{
    texture->angle = angle_set;
    glColor4f (red, green, blue, alpha);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, float red, float green, float blue, float alpha, int frame_set)
{
    texture->frame_number = frame_set;
    texture->angle        = angle_set;
    glColor4f (red, green, blue, alpha);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, int frame_set)
{
    texture->frame_number = frame_set;
    texture->angle        = angle_set;
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
};
