/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef MAP_H
#define MAP_H

const int MAX_MAP_X        = 100;
const int MAX_MAP_Y        = 100;
const int MAX_MAP_TILESETS = 8;
const int MAX_MAP_LAYERS   = 8;

class layer_class
{
    public:
        std::string   name;
        int           width;
        int           height;
        layer_class(void);
       ~layer_class(void);
};

class tileset_class
{
    public:
        int           tilewidth;
        int           tileheight;
        int           firstgid;
        std::string   name;
        tileset_class(void);
       ~tileset_class(void);
};

class map_class
{
    public:
        int           reference_id;
        int           width;
        int           height;
        int           tilewidth;
        int           tileheight;
        tileset_class tileset[MAX_MAP_TILESETS];
        layer_class   layer[MAX_MAP_LAYERS];
        void draw(void);
        void process(void);
        void load(std::string file_name, int reference_id);
        map_class(void);
       ~map_class(void);
};

#endif //MAP_H


