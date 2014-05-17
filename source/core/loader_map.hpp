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

#ifndef LOADER_MAP_H
#define LOADER_MAP_H

#include "types.hpp"

#define DEFAULT_TILE_SIZE 0.05f

struct map_tile_type
{
    int           texture;
    int           object;
    f3_type       position;
    f3_type       vertex[4];
};

struct map_info_type
{
    float              version;
    float              version_required;
    std::string        name;
    std::string        environment_name;
    int                environment_ID;
    i2_type            size;
    int                number_of_tiles;
    float              tile_size;
    f3_type            position;
    f3_type            rotation;
};

struct map_type
{
    map_info_type     info;
    map_tile_type*    tile;
};

void map_load(map_type* map_pointer, std::string file_name);
void map_save(map_type* map_pointer, std::string file_name);
void map_generate_tile_positions(map_type* map_pointer);
void map_render(map_type* map_pointer);

#endif //LOADER_MAP_H

