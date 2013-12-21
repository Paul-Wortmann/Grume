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

#ifndef LOADER_FMX_H
#define LOADER_FMX_H

#include "texture_manager.hpp"
#include "types.hpp"

struct fmx_tile_data_type
{
    bool          collision;
    int           attribute;
};

struct fmx_tile_type
{
    int           tile;
    int           tile_tileset;
    f2_type       position;
};

struct fmx_tileset_type
{
    int           tile_width;
    int           tile_height;
    int           first_gid;
    std::string   image_name;
    std::string   image_source;
    int           image_width;
    int           image_height;
    int           number_of_tiles;
    texture_type* tile;
};

struct fmx_layer_type
{
    std::string        name;
    int                width;
    int                height;
    fmx_tile_type*     tile;
};

struct fmx_data_type
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
    int                number_of_rooms;
    int                path_length;
    bool               path_end_found;
};

struct fmx_path_data_type
{
    int  tile_data;
    int  parent_tile;
    bool open_list;
    bool closed_list;
    int  F;
    int  G;
    int  H;
};

struct fmx_room_data_type
{
    bool       active;
    i2_type    size;
    i2_type    position;
    int        number_of_connected_rooms;
    int       *connected_rooms;
};

struct fmx_map_type
{
    fmx_path_data_type* path_data;
    fmx_data_type       data;
    fmx_layer_type*     layer;
    fmx_tile_data_type* tile_data;
    fmx_tileset_type*   tileset;
    fmx_room_data_type* room;
};

void fmx_load(fmx_map_type* fmx_map_pointer, std::string file_name);
void fmx_save(fmx_map_type* fmx_map_pointer, std::string file_name);

#endif //LOADER_FMX_H


