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

#include "map_environment_manager.hpp"
#include "types.hpp"

#define DEFAULT_TILE_SIZE            (0.4f)
#define DEFAULT_TILE_SIZE_HALF       (DEFAULT_TILE_SIZE/2.0f)
#define DEFAULT_TILE_DIAGONAL_LENGTH (sqrt(2*(DEFAULT_TILE_SIZE*DEFAULT_TILE_SIZE)))
#define DEFAULT_MAP_SCROLL_SPEED     (DEFAULT_TILE_SIZE/20.0f)

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
    i2_type            size;
    int                number_of_tiles;
    float              tile_size;
    f3_type            position;
    f3_type            rotation;
};

struct map_type
{
    map_environment_type *environment;
    map_info_type         info;
    map_tile_type        *tile;
};

void map_load(map_type *map_pointer, std::string file_name);
//void map_save(map_type *map_pointer, std::string file_name);
void map_generate_tile_positions(map_type *map_pointer);
void map_scroll(map_type* map_pointer,int x_dir, int y_dir);
bool map_tile_visable(map_type* map_pointer,int tile_count);
int  map_mouse_over_tile(map_type* map_pointer);
void map_center_on_tile(map_type* map_pointer, int tile_ID);
void map_process(map_type *map_pointer);
void map_render(map_type *map_pointer);

#endif //LOADER_MAP_H

