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

const int    MAX_MAP_TILESETS    = 8;
const int    MAX_TILE_X          = 100;
const int    MAX_TILE_Y          = 100;
const int    MAX_TILES           = MAX_TILE_X*MAX_TILE_Y;
const float  TILE_SIZE           = 0.16f;
const float  TILE_WIDTH_SCALE    = 1;
const float  TILE_HEIGHT_SCALE   = 2;
const float  TILE_WIDTH          = TILE_SIZE*TILE_WIDTH_SCALE;
const float  TILE_HEIGHT         = TILE_SIZE*TILE_HEIGHT_SCALE;
const float  TILE_WIDTH_HALF     = TILE_WIDTH/2;
const float  TILE_HEIGHT_HALF    = TILE_HEIGHT/2;

class tile_class
{
    public:
        float pos_x;
        float pos_y;
        bool  collision;
        int   object;
        int   object_tileset;
        int   tile;
        int   tile_tileset;
        tile_class(void);
       ~tile_class(void);
};

class tileset_class
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
        tileset_class(void);
       ~tileset_class(void);
};

class map_class
{
    public:
        float         version;
        std::string   orientation;
        int           width;
        int           height;
        int           tilewidth;
        int           tileheight;
        tile_class    tile[MAX_TILES];
        int           number_of_tiles;
        tileset_class tileset[MAX_MAP_TILESETS];
        int           number_of_tilesets;
        void draw(void);
        void process(void);
        void reorder_tiles(void);
        void center_on_tile(int tile_ID);
        void calculate_tile_positions(void);
        bool tile_visable(int tile_no);
        void save(std::string file_name);
        void load(std::string file_name);
        map_class(void);
       ~map_class(void);
};

#endif //MAP_H


