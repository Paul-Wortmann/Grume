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

#include <sstream>
#include "font_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

font_manager_class::font_manager_class(void)
{
    font_manager_class::number_of_fonts = 0;
};

font_manager_class::~font_manager_class(void)
{
    font_type* temp_pointer;
    temp_pointer = new font_type;
    temp_pointer = font_manager_class::root;
    if (temp_pointer != NULL)
    {
        while (temp_pointer->next != NULL)
        {
            TTF_CloseFont(temp_pointer->font_data);
            temp_pointer = temp_pointer->next;
        }
    }
};

font_type *font_manager_class::add_font(std::string file_name)
{
    if (font_manager_class::number_of_fonts == 0)
    {
        font_manager_class::root = new font_type;
        font_manager_class::root->next = NULL;
        font_manager_class::last = new font_type;
        font_manager_class::last = root;
        font_manager_class::last->next = NULL;
    }
    else
    {
        font_type* temp_pointer;
        temp_pointer = new font_type;
        temp_pointer = font_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (strcmp(file_name.c_str(),temp_pointer->path.c_str()) == 0) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        font_manager_class::last->next = new font_type;
        font_manager_class::last = font_manager_class::last->next;
        font_manager_class::last->next = new font_type;
        font_manager_class::last->next = NULL;
    }
    font_manager_class::last->path = file_name.c_str();
    font_manager_class::last->loaded = font_manager_class::load_font(last);
    if (font_manager_class::last->loaded) font_manager_class::number_of_fonts++;
    return(font_manager_class::last);
};

bool font_manager_class::load_font(font_type *font)
{
    bool return_value = false;
    font->font_data = TTF_OpenFont(font->path.c_str(), 12);
    if (font->font_data != NULL) return_value = true;
    else game.core.log.file_write("Failed to load font ->",font->path.c_str());
    return (return_value);
};

bool font_manager_class::load_font(font_type *font, int pt_size)
{
    bool return_value = false;
    font->font_data = TTF_OpenFont(font->path.c_str(),pt_size);
    if (font->font_data != NULL) return_value = true;
    else game.core.log.file_write("Failed to load font ->",font->path.c_str());
    return (return_value);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,std::string text,int int_data)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint texture_data;
        GLenum texture_format;
        GLint  nOfColors;
        float  width;
        float  height;
        const char *write_data;
        std::stringstream temp_string;
        temp_string << int_data;
        text = text + temp_string.str();
        write_data = text.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x ) -1);
        height = ((font_string->h / game.core.config.display_resolution_y ) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        width  = width  / 8.0f;
        height = height / 16.0f;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,std::string text,float float_data)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint texture_data;
        GLenum texture_format;
        GLint  nOfColors;
        float  width;
        float  height;
        const char *write_data;
        std::stringstream temp_string;
        temp_string << float_data;
        text = text + temp_string.str();
        write_data = text.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x ) -1);
        height = ((font_string->h / game.core.config.display_resolution_y ) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        width  = width  / 8.0f;
        height = height / 16.0f;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,std::string text)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint texture_data;
        GLenum texture_format;
        GLint  nOfColors;
        float  width;
        float  height;
        const char *write_data = text.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        width  = width  / 8.0f;
        height = height / 16.0f;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint texture_data;
        GLenum texture_format;
        GLint  nOfColors;
        float  width;
        float  height;
        const  char* write_data = text.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};



bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text,int int_data)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text.begin(), text.end() );
        std::stringstream temp_string;
        temp_string << int_data;
        string_data += temp_string.str();
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text,float float_data)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text.begin(), text.end() );
        std::stringstream temp_string;
        temp_string << float_data;
        string_data += temp_string.str();
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text,int int_data,std::string text_2)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text.begin(), text.end() );
        std::stringstream temp_string;
        temp_string << int_data;
        string_data += temp_string.str();
        string_data += text_2;
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text,float float_data,std::string text_2)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text.begin(), text.end() );
        std::stringstream temp_string;
        temp_string << float_data;
        string_data += temp_string.str();
        string_data += text_2;
        write_data  = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,float float_data,std::string text)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data_2( text.begin(), text.end() );
        std::string string_data;
        std::stringstream temp_string;
        temp_string << float_data;
        string_data += temp_string.str();
        string_data += string_data_2;
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,unsigned long long ullint_data,std::string text)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data_2( text.begin(), text.end() );
        std::string string_data;
        std::stringstream temp_string;
        temp_string << ullint_data;
        string_data += temp_string.str();
        string_data += string_data_2;
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,int int_data,std::string text)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data_2( text.begin(), text.end() );
        std::string string_data;
        std::stringstream temp_string;
        temp_string << int_data;
        string_data += temp_string.str();
        string_data += string_data_2;
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text_data,std::string text)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text_data.begin(), text_data.end() );
        string_data += text;
        write_data  = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text,unsigned long long ullint_data)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text.begin(), text.end() );
        std::stringstream temp_string;
        temp_string << ullint_data;
        string_data += temp_string.str();
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text,unsigned long long ullint_data,std::string text_2)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text.begin(), text.end() );
        std::stringstream temp_string;
        temp_string << ullint_data;
        string_data += temp_string.str();
        string_data += text_2;
        write_data = string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};

bool font_manager_class::write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text,int int_data,std::string text_2,int int_data_2,std::string text_3)
{
    if ((text.length() > 0) && (font->font_data != NULL))
    {
        GLuint             texture_data;
        GLenum             texture_format;
        GLint              nOfColors;
        float              width;
        float              height;
        const char *write_data;
        std::string string_data( text.begin(), text.end() );
        std::stringstream temp_string;
        std::stringstream temp_string_2;
        temp_string   << int_data;
        string_data   += temp_string.str();
        string_data   += text_2;
        temp_string_2 << int_data_2;
        string_data   += temp_string_2.str();
        string_data   += text_3;
        write_data    =  string_data.c_str();
        SDL_Color font_color = {b,g,r,a};
        SDL_Surface *font_string = TTF_RenderUTF8_Blended(font->font_data,write_data,font_color);
        width  = ((font_string->w / game.core.config.display_resolution_x) -1);
        height = ((font_string->h / game.core.config.display_resolution_y) -1);
        if(width  < 0)  width  *= -1;
        if(height < 0)  height *= -1;
        if (ws == 0) ws = width;
        if (hs == 0) hs = height;
        width  = width  / ws;
        height = height / hs;
        nOfColors = font_string->format->BytesPerPixel;
        texture_format = GL_RGBA;
        glPushMatrix();
        glGenTextures( 1, &texture_data);
        glBindTexture( GL_TEXTURE_2D, texture_data);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, font_string->w, font_string->h, 0, texture_format, GL_UNSIGNED_BYTE, font_string->pixels );
        glBindTexture(GL_TEXTURE_2D, texture_data);
        glLoadIdentity();
        glBegin( GL_QUADS );
        glTexCoord2i( 1, 0 );glVertex3f(x+width,y+height, 0.1f );
        glTexCoord2i( 1, 1 );glVertex3f(x+width,y       , 0.1f );
        glTexCoord2i( 0, 1 );glVertex3f(x      ,y       , 0.1f );
        glTexCoord2i( 0, 0 );glVertex3f(x      ,y+height, 0.1f );
        glEnd();
        glPopMatrix();
        glDeleteTextures(1, &texture_data);
        SDL_FreeSurface(font_string);
        return(true);
    }
    else return(false);
};
