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

#ifndef LOADER_TMX_H
#define LOADER_TMX_H

class tmx_tile_class
{
    public:
        float pos_x;
        float pos_y;
        bool  collision;
        int   object;
        int   object_tileset;
        int   tile;
        int   tile_tileset;
        tmx_tile_class(void);
       ~tmx_tile_class(void);
};

class tmx_layer_class
{
    public:
        std::string        name;
        tmx_tile_class    *tile;
};

class tmx_tileset_class
{
    public:
        int           tilewidth;
        int           tileheight;
        int           firstgid;
        std::string   name;
        std::string   image_source;
        int           width;
        int           height;
        int           number_of_tiles;
        tmx_tileset_class(void);
       ~tmx_tileset_class(void);
};

class tmx_class
{
    public:
        float              version;
        std::string        orientation;
        int                width;
        int                height;
        int                tilewidth;
        int                tileheight;
        tmx_layer_class   *layer;
        int                number_of_layers;
        int                number_of_tiles;
        tmx_tileset_class *tileset;
        int                number_of_tilesets;
        void save(std::string file_name);
        void load(std::string file_name);
        tmx_class(void);
       ~tmx_class(void);
};

#endif //LOADER_TMX_H


