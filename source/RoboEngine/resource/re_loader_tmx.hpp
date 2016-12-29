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

#ifndef LOADER_TMX_H
#define LOADER_TMX_H

#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "../core/re_types.hpp"
#include "../system/re_log.hpp"
#include "re_parser_xml.hpp"

namespace RoboEngine
{

    struct tmx_tile_type
    {
        uint32_t      tile;
        uint32_t      tile_tileset;
    };

    struct tmx_tileset_type
    {
        uint32_t      tile_width;
        uint32_t      tile_height;
        uint32_t      first_gid;
        std::string   image_name;
        std::string   image_source;
        uint32_t      image_width;
        uint32_t      image_height;
        uint32_t      number_of_tiles;
    };

    struct tmx_layer_type
    {
        std::string        name;
        uint32_t           width;
        uint32_t           height;
        tmx_tile_type*     tile;
    };

    struct tmx_data_type
    {
        float              xml_version;
        std::string        xml_encoding;
        float              map_version;
        std::string        map_orientation;
        uint32_t           map_width;
        uint32_t           map_height;
        uint32_t           map_tile_width;
        uint32_t           map_tile_height;
        uint32_t           number_of_layers;
        uint32_t           number_of_tiles;
        uint32_t           number_of_tilesets;
    };

    struct re_stmxData
    {
        tmx_data_type       data;
        tmx_layer_type*     layer;
        tmx_tileset_type*   tileset;
    };

    void re_tmxDelete(re_stmxData *&_tmxData);
    void re_tmxLoad(const std::string &_fileName, re_stmxData *&_tmxData);
    void re_tmxSave(const std::string &_fileName, re_stmxData *&_tmxData);

}

#endif //LOADER_TMX_H
