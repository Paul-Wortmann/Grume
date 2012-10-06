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

#include <SDL/SDL_ttf.h>

#ifndef FONT_H
#define FONT_H

class font_class
{
    private:
        TTF_Font   *font_data;
    public:
        font_class(void);
       ~font_class(void);
        bool load(std::string file_name);
        bool load(std::string file_name, int pt_size);
        bool write(int r,int g,int b,int a,float x,float y,std::string text,int int_data);
        bool write(int r,int g,int b,int a,float x,float y,std::string text,float float_data);
        bool write(int r,int g,int b,int a,float x,float y,std::string text);
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string text);
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text       ,float              float_data  );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text       ,int                int_data    );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text       ,int                int_data    ,std::string        text_2      );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text       ,float              float_data  ,std::string        text_2      );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,float              float_data ,std::string        text        );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,unsigned long long ullint_data,std::string        text        );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,int                int_data   ,std::string        text        );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text_data  ,std::string        text        );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text       ,unsigned long long ullint_data );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text       ,unsigned long long ullint_data ,std::string        text_2      );
        bool write(int r,int g,int b,int a,float x,float y,float ws,float hs,std::string        text       ,int                int_data    ,std::string        text_2      ,int                int_data_2 ,std::string        text_3      );
};

#endif //FONT_H




