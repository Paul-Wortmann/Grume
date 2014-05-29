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


#include "texture_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

texture_manager_class::texture_manager_class(void)
{
    texture_manager_class::last               = NULL;
    texture_manager_class::root               = NULL;
    texture_manager_class::number_of_textures = 0;
};

texture_manager_class::~texture_manager_class(void)
{
    texture_type* temp_pointer;
    temp_pointer = texture_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            delete [] temp_pointer->data.frame;
            temp_pointer = temp_pointer->next;
        }
    }
    //delete [] root;
    //delete [] last;
};

texture_type* texture_manager_class::add_texture(std::string file_name)
{
    return (texture_manager_class::add_texture(file_name,DEFAULT_FRAME_WIDTH,DEFAULT_FRAME_HEIGHT,TEXTURE_IMAGE));
};

texture_type* texture_manager_class::add_texture(std::string file_name, bool is_sprite_sheet)
{
    if (is_sprite_sheet) return (texture_manager_class::add_texture(file_name,DEFAULT_FRAME_WIDTH,DEFAULT_FRAME_HEIGHT,TEXTURE_SPRITESHEET));
    else return (texture_manager_class::add_texture(file_name,DEFAULT_FRAME_WIDTH,DEFAULT_FRAME_HEIGHT,TEXTURE_IMAGE));
};

texture_type* texture_manager_class::add_texture(std::string file_name, bool is_sprite_sheet, int width_set, int height_set)
{
    if (is_sprite_sheet) return (texture_manager_class::add_texture(file_name,width_set,height_set,TEXTURE_SPRITESHEET));
    else return (texture_manager_class::add_texture(file_name,width_set,height_set,TEXTURE_IMAGE));
};

texture_type* texture_manager_class::add_texture(std::string file_name, int width_set, int height_set, int texture_flag)
{
    return (texture_manager_class::add_texture(NULL,file_name,height_set,width_set,height_set,texture_flag));
};

texture_type* texture_manager_class::add_texture(font_type* font, std::string text_string, float text_size, int width_set, int height_set, int texture_flag)
{
    return (texture_manager_class::add_texture(font,text_string,text_size,width_set,height_set,255,255,255,255,texture_flag));
};

texture_type* texture_manager_class::add_texture(font_type* font, std::string text_string, float text_size, int width_set, int height_set, int r, int g, int b, int a, int texture_flag)
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
        texture_type* temp_pointer = texture_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (strcmp(text_string.c_str(),temp_pointer->data.path.c_str()) == 0) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        texture_manager_class::last->next = new texture_type;
        texture_manager_class::last = texture_manager_class::last->next;
        texture_manager_class::last->next = new texture_type;
        texture_manager_class::last->next = NULL;
    }
    texture_manager_class::last->data.render_positioning = TEXTURE_RENDER_CENTERED;
    texture_manager_class::last->data.text.font          = font;
    texture_manager_class::last->data.text.color.r       = r;
    texture_manager_class::last->data.text.color.g       = g;
    texture_manager_class::last->data.text.color.b       = b;
    texture_manager_class::last->data.text.color.a       = a;
    texture_manager_class::last->data.text.text_size     = text_size;
    texture_manager_class::last->data.text.text_string   = text_string.c_str();
    texture_manager_class::last->data.path               = text_string.c_str();
    texture_manager_class::last->data.width              = width_set;
    texture_manager_class::last->data.height             = height_set;
    texture_manager_class::last->data.rotate_able        = false;
    texture_manager_class::last->data.rotate_speed       = 0.0f;
    texture_manager_class::last->data.rotate_direction   = 0;
    texture_manager_class::last->data.angle              = 0.0f;
    texture_manager_class::last->data.frame_delay        = 0.0f;
    texture_manager_class::last->data.frame_delay_count  = 0.0f;
    texture_manager_class::last->data.frame_delay_max    = 0.0f;
    texture_manager_class::last->data.frame_number       = 0;
    texture_manager_class::last->data.frame_max          = 0;
    texture_manager_class::last->data.texture_flag       = texture_flag;
    switch (texture_flag)
    {
        case TEXTURE_IMAGE:
            texture_manager_class::last->data.loaded = texture_manager_class::load_texture(last);
        break;
        case TEXTURE_SPRITESHEET:
            texture_manager_class::last->data.loaded = texture_manager_class::load_sprite_sheet(last,texture_manager_class::last->data.width,texture_manager_class::last->data.height);
        break;
        case TEXTURE_STRING:
            texture_manager_class::last->data.loaded = texture_manager_class::load_string(last);
        break;
        default:
            game.core.log.write("Fail -> Texture manager, unknown texture flag. - ",texture_flag);
            texture_manager_class::last->data.loaded = false;
        break;
    }
    if (texture_manager_class::last->data.loaded) texture_manager_class::number_of_textures++;
    return(texture_manager_class::last);
};

void texture_manager_class::load_textures(void)
{
    texture_type* temp_pointer;
    temp_pointer = texture_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            if (!temp_pointer->data.loaded)
            {
                if (temp_pointer->data.path.length() > 4)
                {
                    switch (temp_pointer->data.texture_flag)
                    {
                        case TEXTURE_IMAGE:
                            temp_pointer->data.loaded = texture_manager_class::load_texture(temp_pointer);
                        break;
                        case TEXTURE_SPRITESHEET:
                            temp_pointer->data.loaded = texture_manager_class::load_sprite_sheet(temp_pointer);
                        break;
                        case TEXTURE_STRING:
                            temp_pointer->data.loaded = texture_manager_class::load_string(temp_pointer);
                        break;
                        default:
                            game.core.log.write("Fail -> Loading texture, unknown texture flag. - ",temp_pointer->data.texture_flag);
                            temp_pointer->data.loaded = false;
                        break;
                    }
                }
            }
            temp_pointer = temp_pointer->next;
        }
    }
};

void texture_manager_class::reload_textures(void)
{
    game.core.log.write("Reloading resources....");
    texture_type* temp_pointer;
    temp_pointer = texture_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            temp_pointer->data.loaded = false;
            temp_pointer = temp_pointer->next;
        }
    }
    temp_pointer = texture_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            switch (temp_pointer->data.texture_flag)
            {
                case TEXTURE_IMAGE:
                    temp_pointer->data.loaded = texture_manager_class::load_texture(temp_pointer);
                break;
                case TEXTURE_SPRITESHEET:
                    temp_pointer->data.loaded = texture_manager_class::load_sprite_sheet(temp_pointer,temp_pointer->data.width,temp_pointer->data.height);
                break;
                case TEXTURE_STRING:
                    temp_pointer->data.loaded = texture_manager_class::load_string(temp_pointer,temp_pointer->data.text.font,temp_pointer->data.text.text_string,temp_pointer->data.text.text_size,temp_pointer->data.text.color.r,temp_pointer->data.text.color.g,temp_pointer->data.text.color.b,temp_pointer->data.text.color.a,temp_pointer->data.render_positioning);
                break;
                default:
                    game.core.log.write("Fail -> Reloading texture, unknown texture flag. - ",temp_pointer->data.texture_flag);
                    temp_pointer->data.loaded = false;
                break;
            }
            temp_pointer = temp_pointer->next;
        }
    }
};

void texture_manager_class::reload_texture(texture_type *texture)
{
    if (texture != NULL)
    {
        //game.core.log.write("Reloading texture - ",texture->data.path.c_str());
        switch (texture->data.texture_flag)
        {
            case TEXTURE_IMAGE:
                texture->data.loaded = texture_manager_class::load_texture(texture);
            break;
            case TEXTURE_SPRITESHEET:
                texture->data.loaded = texture_manager_class::load_sprite_sheet(texture,texture->data.width,texture->data.height);
            break;
            case TEXTURE_STRING:
                texture->data.loaded = texture_manager_class::load_string(texture,texture->data.text.font,texture->data.text.text_string,texture->data.text.text_size,texture->data.text.color.r,texture->data.text.color.g,texture->data.text.color.b,texture->data.text.color.a,texture->data.render_positioning);
            break;
            default:
                game.core.log.write("Fail -> Reloading texture, unknown texture flag. - ",texture->data.texture_flag);
                texture->data.loaded = false;
            break;
        }
    }
    else
    {
        game.core.log.write("Fail -> Reloading texture - NULL pointer passed to function.");
    }
};

bool texture_manager_class::load_texture(texture_type *texture)
{
    bool            return_value   = false;
    SDL_Surface    *image_surface  = NULL;
    if ((image_surface = game.core.file.load_image(texture->data.path.c_str())))
    {
        GLint           number_of_colors;
        GLenum          texture_format = 0;
        texture->data.frame_max        = 0;
        texture->data.frame            = new frame_type[texture->data.frame_max+1];
        return_value                   = true;
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
        glGenTextures  (1, &texture->data.frame[texture->data.frame_number].data);
        glBindTexture  (GL_TEXTURE_2D, texture->data.frame[texture->data.frame_number].data);
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
        game.core.log.write("Failed to load image ->",texture->data.path.c_str());
    }
    if (image_surface) SDL_FreeSurface(image_surface);
    texture->data.loaded = return_value;
    return(return_value);
};

bool texture_manager_class::load_sprite_sheet(texture_type *texture)
{
    return(texture_manager_class::load_sprite_sheet(texture,DEFAULT_FRAME_WIDTH,DEFAULT_FRAME_HEIGHT));
};

bool texture_manager_class::load_sprite_sheet(texture_type *texture, int width_set, int height_set)
{
    SDL_Surface    *sprite_sheet   = NULL;
    SDL_Surface    *temp_surface   = NULL;
    bool            return_value   = false;
    if ((sprite_sheet = game.core.file.load_image(texture->data.path.c_str())))
    {
        texture->data.width            = width_set;
        texture->data.height           = height_set;
        int             frame_count    = 0;
        int             num_sprites    = 0;
        int             flags          = 0;
        GLenum          texture_format = 0;
        GLint           number_of_colors;
        int             frames_x;
        int             frames_y;
        return_value = true;
        frames_x = sprite_sheet->w / texture->data.width;
        frames_y = sprite_sheet->h / texture->data.height;
        num_sprites = frames_x * frames_y;
        texture->data.frame_max = num_sprites-1;
        texture->data.frame = new frame_type[texture->data.frame_max+1];
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
        temp_surface = SDL_CreateRGBSurface(flags,texture->data.width-1,texture->data.height-1,sprite_sheet->format->BitsPerPixel,sprite_sheet->format->Rmask,sprite_sheet->format->Gmask,sprite_sheet->format->Bmask,sprite_sheet->format->Amask);
        int32_t     *in_pixels       = (int32_t*)sprite_sheet->pixels;
        int32_t     *out_pixels      = (int32_t*)temp_surface->pixels;

        for (int current_sprite_y = 0; current_sprite_y < frames_y; current_sprite_y++)
        {
            for (int current_sprite_x = 0; current_sprite_x < frames_x; current_sprite_x++)
            {
                int out_pixel_count = 0;
                if (SDL_MUSTLOCK(sprite_sheet)) SDL_LockSurface(sprite_sheet);
                for (int y_count = 0; y_count < texture->data.height-1; y_count++)
                {
                    for (int x_count = 0; x_count < texture->data.width-1; x_count++)
                    {
                        out_pixels[out_pixel_count] = in_pixels[((sprite_sheet->w*y_count)+(((frame_count)*((int)texture->data.width))+x_count))];
                        out_pixel_count++;
                    }
                }
                if (SDL_MUSTLOCK(sprite_sheet)) SDL_UnlockSurface(sprite_sheet);
                texture->data.frame[frame_count].active = true;
                glGenTextures  (1, &texture->data.frame[frame_count].data);
                glBindTexture  (GL_TEXTURE_2D, texture->data.frame[frame_count].data);
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
        game.core.log.write("Failed to load sprite sheet ->",texture->data.path.c_str());
    }
    if (sprite_sheet) SDL_FreeSurface(sprite_sheet);
    if (temp_surface) SDL_FreeSurface(temp_surface);
    texture->data.loaded = return_value;
    return(return_value);
};

bool texture_manager_class::load_string(texture_type *texture_pointer, font_type* font_pointer, std::string text_string, float text_size, int r, int g, int b, int a)
{
    return (texture_manager_class::load_string(texture_pointer,font_pointer,text_string,text_size,r,g,b,a,TEXTURE_RENDER_CENTERED));
}

bool texture_manager_class::load_string(texture_type *texture_pointer, font_type* font_pointer, std::string text_string, float text_size, int r, int g, int b, int a, int render_position)
{
    texture_pointer->data.texture_flag       = TEXTURE_STRING;
    texture_pointer->data.render_positioning = render_position;
    texture_pointer->data.text.font          = font_pointer;
    texture_pointer->data.text.color.r       = r;
    texture_pointer->data.text.color.g       = g;
    texture_pointer->data.text.color.b       = b;
    texture_pointer->data.text.color.a       = a;
    texture_pointer->data.text.text_size     = text_size;
    texture_pointer->data.text.text_string   = text_string.c_str();
    texture_pointer->data.path               = text_string.c_str();
    texture_pointer->data.width              = 0;
    texture_pointer->data.height             = 0;
    texture_pointer->data.rotate_able        = false;
    texture_pointer->data.rotate_speed       = 0.0f;
    texture_pointer->data.rotate_direction   = 0;
    texture_pointer->data.angle              = 0.0f;
    texture_pointer->data.frame_delay        = 0.0f;
    texture_pointer->data.frame_delay_count  = 0.0f;
    texture_pointer->data.frame_delay_max    = 0.0f;
    texture_pointer->data.frame_number       = 0;
    texture_pointer->data.frame_max          = 0;
    return (texture_manager_class::load_string(texture_pointer));
}

bool texture_manager_class::load_string(texture_type *texture)
{
    if (texture->data.text.font == NULL) texture->data.text.font = game.font_manager.root;
    bool return_value   = false;
    if ((texture->data.text.text_string.length() > 0) && (texture->data.text.font->font_data != NULL))
    {
        SDL_Surface    *image_surface  = NULL;
        const char*         write_data = texture->data.text.text_string.c_str();
        SDL_Color font_color = {texture->data.text.color.r,texture->data.text.color.g,texture->data.text.color.b,texture->data.text.color.a};
        image_surface = TTF_RenderUTF8_Blended(texture->data.text.font->font_data,write_data,font_color);
        if (image_surface)
        {
            GLint           number_of_colors;
            GLenum          texture_format = 0;
            texture->data.frame_max        = 0;
            texture->data.frame            = new frame_type[texture->data.frame_max+1];
            texture->data.width  = ((float)image_surface->w / (float)game.core.config.display_resolution_x) * texture->data.text.text_size * game.core.config.font_scale_x;
            texture->data.height = ((float)image_surface->h / (float)game.core.config.display_resolution_y) * texture->data.text.text_size * game.core.config.font_scale_y;
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
            glGenTextures  (1, &texture->data.frame[texture->data.frame_number].data);
            glBindTexture  (GL_TEXTURE_2D, texture->data.frame[texture->data.frame_number].data);
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
            game.core.log.write("Failed to load string ->",texture->data.text.text_string.c_str());
        }
        if (image_surface) SDL_FreeSurface(image_surface);
        texture->data.loaded = return_value;
    }
    return(return_value);
};

void texture_manager_class::bind_image(texture_type *texture)
{
    glBindTexture(GL_TEXTURE_2D, texture->data.frame[0].data);
};

void texture_manager_class::process(texture_type *texture)
{
    //process rotation
    if (texture->data.rotate_able)
    {
        if (texture->data.rotate_direction == 0)
        {
            texture->data.angle += texture->data.rotate_speed;
            if (texture->data.angle > 6.2832f) texture->data.angle = 0.0f;
        }
        if (texture->data.rotate_direction == 1)
        {
            texture->data.angle -= texture->data.rotate_speed;
            if (texture->data.angle < 0.0f) texture->data.angle = 6.2832f;
        }
    }
    // process frames
    texture->data.frame_delay_count += texture->data.frame_delay;
    if (texture->data.frame_delay_count > texture->data.frame_delay_max)
    {
        texture->data.frame_delay_count = 0.0f;
        texture->data.frame_number++;
        if (texture->data.frame_number > texture->data.frame_max) texture->data.frame_number = 0;
    }
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set)
{
    if (texture->data.loaded)
    {
        if (rumble_set)
        {
            game.rumble.counter.x = 0.0f;
            game.rumble.counter.y = 0.0f;
            pos_x += game.rumble.counter.x;
            pos_y += game.rumble.counter.y;
        }
        if (texture->data.frame[texture->data.frame_number].data) // Only render if data is available.
        {
            int   temp_angle;
            float temp_width_p  = (width_set/2);
            float temp_width_n  = (width_set/2)*-1;
            float temp_height_p = (height_set/2);
            float temp_height_n = (height_set/2)*-1;
            if (texture->data.angle != 0) temp_angle = 360 - texture->data.angle;
            else temp_angle = 0;
            glPushMatrix();
            glBindTexture( GL_TEXTURE_2D, texture->data.frame[texture->data.frame_number].data);
            glLoadIdentity();
            glBegin( GL_QUADS );
            switch (texture->data.render_positioning)
            {
                case TEXTURE_RENDER_CENTERED:
                break;
                case TEXTURE_RENDER_UP:
                    temp_height_p = temp_height_p*2.0f;
                    temp_height_n = 0.0f;
                break;
                case TEXTURE_RENDER_DOWN:
                    temp_height_p = 0.0f;
                    temp_height_n = temp_height_n*2.0f;
                break;
                case TEXTURE_RENDER_LEFT:
                    temp_width_p = temp_width_p*2.0f;
                    temp_width_n = 0.0f;
                break;
                case TEXTURE_RENDER_LEFT+TEXTURE_RENDER_UP:
                    temp_width_p = temp_width_p*2.0f;
                    temp_width_n = 0.0f;
                    temp_height_p = temp_height_p*2.0f;
                    temp_height_n = 0.0f;
                break;
                case TEXTURE_RENDER_LEFT+TEXTURE_RENDER_DOWN:
                    temp_width_p = temp_width_p*2.0f;
                    temp_width_n = 0.0f;
                    temp_height_p = 0.0f;
                    temp_height_n = temp_height_n*2.0f;
                break;
                case TEXTURE_RENDER_RIGHT:
                    temp_width_p = 0.0f;
                    temp_width_n = temp_width_n*2.0f;
                break;
                case TEXTURE_RENDER_RIGHT+TEXTURE_RENDER_UP:
                    temp_width_p = 0.0f;
                    temp_width_n = temp_width_n*2.0f;
                    temp_height_p = temp_height_p*2.0f;
                    temp_height_n = 0.0f;
                break;
                case TEXTURE_RENDER_RIGHT+TEXTURE_RENDER_DOWN:
                    temp_width_p = 0.0f;
                    temp_width_n = temp_width_n*2.0f;
                    temp_height_p = 0.0f;
                    temp_height_n = temp_height_n*2.0f;
                break;
                default:
                    game.core.log.write("Texture render error with render positioning -> ",texture->data.render_positioning);
                break;
            }
            if (texture->data.rotate_able)
            {
                glTexCoord2i( 0, 1 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+temp_width_n,pos_y+temp_height_n,temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+temp_width_n,pos_y+temp_height_n, temp_angle), pos_z);
                glTexCoord2i( 0, 0 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+temp_width_n,pos_y+temp_height_p,temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+temp_width_n,pos_y+temp_height_p, temp_angle), pos_z);
                glTexCoord2i( 1, 0 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+temp_width_p,pos_y+temp_height_p,temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+temp_width_p,pos_y+temp_height_p, temp_angle), pos_z);
                glTexCoord2i( 1, 1 );glVertex3f(game.core.physics.rotate_point_2D_x(pos_x, pos_y, pos_x+temp_width_p,pos_y+temp_height_n,temp_angle), game.core.physics.rotate_point_2D_y(pos_x,pos_y,pos_x+temp_width_p,pos_y+temp_height_n, temp_angle), pos_z);        }
            else
            {
                glTexCoord2i( 0, 1 );glVertex3f(pos_x+temp_width_n,pos_y+temp_height_n, pos_z);
                glTexCoord2i( 0, 0 );glVertex3f(pos_x+temp_width_n,pos_y+temp_height_p, pos_z);
                glTexCoord2i( 1, 0 );glVertex3f(pos_x+temp_width_p,pos_y+temp_height_p, pos_z);
                glTexCoord2i( 1, 1 );glVertex3f(pos_x+temp_width_p,pos_y+temp_height_n, pos_z);
            }
            glEnd();
            glPopMatrix();
        }
    }
    else
    {
        game.core.log.write("Fail - Texture manager draw image function called without image data.");
        game.core.log.write("Fail - You are most likely missing data files, please re-install.");
        game.state = STATE_QUIT;
    }
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, int angle_set)
{
    texture->data.angle = angle_set;//game.core.physics.degrees_to_radians(angle);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set)
{
    texture->data.angle = angle_set;
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, float alpha)
{
    texture->data.angle = angle_set;
    glColor4f (1.0f, 1.0f, 1.0f, alpha);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, float red, float green, float blue, float alpha)
{
    texture->data.angle = angle_set;
    glColor4f (red, green, blue, alpha);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, float red, float green, float blue, float alpha, int frame_set)
{
    texture->data.frame_number = frame_set;
    texture->data.angle        = angle_set;
    glColor4f (red, green, blue, alpha);
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
    glColor4f (1.0f, 1.0f, 1.0f,1.0f);
};

void texture_manager_class::draw(texture_type *texture, bool rumble_set, float pos_x, float pos_y, float pos_z, float width_set, float height_set, float angle_set, int frame_set)
{
    texture->data.frame_number = frame_set;
    texture->data.angle        = angle_set;
    texture_manager_class::draw(texture,rumble_set,pos_x,pos_y,pos_z,width_set,height_set);
};
