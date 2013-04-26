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

#include "textures.hpp"

#define ISOMETRIC  1
#define ORTHOGONAL 2
#define UTF_8      8
#define UTF_16     16

struct i2_type
{
    int x;
    int y;
};

struct f2_type
{
    float x;
    float y;
};

struct tmx_tile_type
{
    int           tile;
    int           tile_tileset;
    f2_type       position;
};

struct tmx_tileset_type
{
    int           tile_width;
    int           tile_height;
    int           first_gid;
    std::string   image_name;
    std::string   image_source;
    bool          image_loaded;
    int           image_width;
    int           image_height;
    int           number_of_tiles;
    texture_class tile;
};

struct tmx_layer_type
{
    std::string        name;
    int                width;
    int                height;
    tmx_tile_type     *tile;
};

struct tmx_data_type
{
    float              xml_version;
    std::string        xml_encoding;
    float              map_version;
    std::string        map_orientation;
    int                map_width;
    int                map_height;
    int                map_tile_width;
    int                map_tile_height;
    int                number_of_layers;
    int                number_of_tiles;
    int                number_of_tilesets;
};

struct tmx_map_type
{
    tmx_data_type     data;
    tmx_layer_type   *layer;
    tmx_tileset_type *tileset;
};

void tmx_load(tmx_map_type *tmx_map_pointer, std::string file_name);
void tmx_save(tmx_map_type *tmx_map_pointer, std::string file_name);

#endif //LOADER_TMX_H


