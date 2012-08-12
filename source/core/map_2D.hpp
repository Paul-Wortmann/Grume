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

#ifndef MAP_2D_H
#define MAP_2D_H

#include "textures.hpp"

#define DUNGEON    1
#define CAVE       2
#define FOREST     3

const float  TILE_SCALE_DEFAULT  = 200.0f;
const float  TILE_WIDTH          = (float)DEFAULT_FRAME_WIDTH  / TILE_SCALE_DEFAULT;
const float  TILE_HEIGHT         = (float)DEFAULT_FRAME_HEIGHT / TILE_SCALE_DEFAULT;
const float  TILE_WIDTH_HALF     = TILE_WIDTH/2.0f;
const float  TILE_HEIGHT_HALF    = TILE_HEIGHT/2.0f;
const float  MAP_SCROLL_SPEED    = 0.02f;
const int    MAX_ITEMS_PER_TILE  = 4;

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
        int   tile_item[MAX_ITEMS_PER_TILE];
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
        texture_class tile;
        tileset_class(void);
       ~tileset_class(void);
};

class map_2D_class
{
    public:
        float          version;
        std::string    orientation;
        int            width;
        int            height;
        int            tilewidth;
        int            tileheight;
        tile_class*    tile;
        int            number_of_tiles;
        tileset_class* tileset;
        int            number_of_tilesets;
        void draw(void);
        void process(void);
        void scroll_map(int x_dir, int y_dir);
        void center_on_tile(int tile_ID);
        void calculate_tile_positions(void);
        void calculate_tile_positions(float tile_width_half_specify,float tile_height_half_specify);
        int  mouse_over_tile(void);
        bool tile_visable(int tile_no);
        void save(std::string file_name);
        void load(std::string file_name);
        map_2D_class(void);
       ~map_2D_class(void);
        void random_map(int tiles_x, int tiles_y, int type_of_map_to_generate);
};

#endif //MAP_H_2D


