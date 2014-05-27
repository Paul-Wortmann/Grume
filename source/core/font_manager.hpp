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

#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

struct font_type
{
    bool            loaded;
    std::string     path;
    TTF_Font       *font_data;
    SDL_RWops      *rwops_pointer;
    char           *file_data;
    font_type      *next;
};

class font_manager_class
{
    public:
        font_manager_class(void);
       ~font_manager_class(void);
        int           number_of_fonts;
        font_type    *root;
        font_type    *last;
        font_type    *add_font(std::string file_name);
        void          init(void);
        void          deinit(void);
        bool          load_font(font_type *font);
        bool          load_font(font_type *font, int pt_size);
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,std::string text,int   int_data);
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,std::string text,float float_data);
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text       ,float              float_data  );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text       ,int                int_data    );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text       ,int                int_data    ,std::string        text_2      );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text       ,float              float_data  ,std::string        text_2      );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,float              float_data ,std::string        text        );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,unsigned long long ullint_data,std::string        text        );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,int                int_data   ,std::string        text        );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text_data  ,std::string        text        );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text       ,unsigned long long ullint_data );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text       ,unsigned long long ullint_data ,std::string        text_2      );
        bool          write(font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string        text       ,int                int_data    ,std::string        text_2      ,int                int_data_2 ,std::string        text_3      );

        bool          write (font_type *font, Uint8 r,Uint8 g,Uint8 b,Uint8 a,float x,float y,float ws,float hs,std::string text);
};

#endif // FONT_MANAGER_H
