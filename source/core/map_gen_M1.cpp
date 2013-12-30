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

#include "../game/game.hpp"
#include "map_gen.hpp"
#include "map_gen_M1.hpp"

extern game_class    game;

void           map_gen_M1              (fmx_map_type *fmx_map_pointer, int seed)
{
    srand(seed);
    map_gen_M1(fmx_map_pointer);
};

bool map_gen_maze_check_tile(fmx_map_type *fmx_map_pointer, int tile_count, int direction_bias)
{
    bool return_value = true;
    if (tile_count < fmx_map_pointer->data.map_width) return_value = false;
    if (tile_count > (fmx_map_pointer->data.number_of_tiles - fmx_map_pointer->data.map_width-1)) return_value = false;
    if (!(tile_count % fmx_map_pointer->data.map_width)) return_value = false;
    if (!((tile_count+1) % fmx_map_pointer->data.map_width)) return_value = false;
    if (fmx_map_pointer->tile_data[tile_count].attribute == TILE_ATTRIBUTE_PROCESSED) return_value = false;
    if (return_value)
    {
        switch (direction_bias)
        {
            case DIRECTION_BIAS_NORTH:
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-fmx_map_pointer->data.map_width].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-fmx_map_pointer->data.map_width-1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-fmx_map_pointer->data.map_width+1].tile != TILE_WALL) return_value = false;
            break;
            case DIRECTION_BIAS_SOUTH:
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+fmx_map_pointer->data.map_width].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+fmx_map_pointer->data.map_width-1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+fmx_map_pointer->data.map_width+1].tile != TILE_WALL) return_value = false;
            break;
            case DIRECTION_BIAS_EAST:
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-fmx_map_pointer->data.map_width].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-fmx_map_pointer->data.map_width-1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+fmx_map_pointer->data.map_width].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+fmx_map_pointer->data.map_width-1].tile != TILE_WALL) return_value = false;
            break;
            case DIRECTION_BIAS_WEST:
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-fmx_map_pointer->data.map_width].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count-fmx_map_pointer->data.map_width+1].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+fmx_map_pointer->data.map_width].tile != TILE_WALL) return_value = false;
                if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count+fmx_map_pointer->data.map_width+1].tile != TILE_WALL) return_value = false;
            break;
            case DIRECTION_BIAS_NONE:
            default:
                game.core.log.file_write("error, map_gen_maze_check_tile() passed invalid direction bias.");
                return_value = true;
            break;
        }
    }
    return (return_value);
};

void map_gen_maze(fmx_map_type *fmx_map_pointer, int tile_count, int direction_bias)
{
    fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile      = TILE_FLOOR;
    fmx_map_pointer->tile_data[tile_count].attribute = TILE_ATTRIBUTE_PROCESSED;
    int  tiles_available    = 1;
    bool new_direction_bias = false;
    int tile_direction      = 0;
    while (tiles_available > 0)
    {
        tiles_available = 0;
        int  tile_north      = tile_count-fmx_map_pointer->data.map_width;
        bool tile_north_ok   = map_gen_maze_check_tile(fmx_map_pointer,tile_north,DIRECTION_BIAS_NORTH);
        if (tile_north_ok) tiles_available++;
        int  tile_south      = tile_count+fmx_map_pointer->data.map_width;
        bool tile_south_ok   = map_gen_maze_check_tile(fmx_map_pointer,tile_south,DIRECTION_BIAS_SOUTH);
        if (tile_south_ok) tiles_available++;
        int  tile_east       = tile_count-1;
        bool tile_east_ok    = map_gen_maze_check_tile(fmx_map_pointer,tile_east,DIRECTION_BIAS_EAST);
        if (tile_east_ok) tiles_available++;
        int  tile_west       = tile_count+1;
        bool tile_west_ok    = map_gen_maze_check_tile(fmx_map_pointer,tile_west,DIRECTION_BIAS_WEST);
        if (tile_west_ok) tiles_available++;
        if ((new_direction_bias) || (direction_bias == DIRECTION_BIAS_NONE)) tile_direction = (rand() % 4) + 1;
        else
        {
            tile_direction = (rand()%(4+DIRECTION_BIAS_THRESHOLD))+1;
            if (tile_direction > 4) tile_direction = direction_bias;
            else
            {
                direction_bias     = tile_direction;
                new_direction_bias = true;
            }
        }
        switch (tile_direction)
        {
            case DIRECTION_BIAS_NORTH:
                if (tile_north_ok)
                {
                    tiles_available--;
                    tile_north_ok = false;
                    map_gen_maze(fmx_map_pointer,tile_north,direction_bias);
                }
            break;
            case DIRECTION_BIAS_SOUTH:
                if (tile_south_ok)
                {
                    tiles_available--;
                    tile_south_ok = false;
                    map_gen_maze(fmx_map_pointer,tile_south,direction_bias);
                }
            break;
            case DIRECTION_BIAS_EAST:
                if (tile_east_ok)
                {
                    tiles_available--;
                    tile_east_ok = false;
                    map_gen_maze(fmx_map_pointer,tile_east,direction_bias);
                }
            break;
            case DIRECTION_BIAS_WEST:
                if (tile_west_ok)
                {
                    tiles_available--;
                    tile_west_ok = false;
                    map_gen_maze(fmx_map_pointer,tile_west,direction_bias);
                }
            break;
            default:
                game.core.log.file_write("error in rand tile choice -> map_gen_maze()");
                tiles_available--;
            break;
        }
    }
};

void map_gen_maze(fmx_map_type *fmx_map_pointer, int tile_x, int tile_y, int direction_bias)
{
    map_gen_maze(fmx_map_pointer, ((tile_y * fmx_map_pointer->data.map_width) + tile_x),direction_bias);
};

void           map_gen_M1              (fmx_map_type *fmx_map_pointer)
{
    room_data_type room_data;
    room_data.position.x = 0;
    room_data.position.y = 0;
    room_data.size.x     = 0;
    room_data.size.y     = 0;
    map_gen_base(fmx_map_pointer);
    map_gen_room(fmx_map_pointer,room_data,1);
    map_gen_room(fmx_map_pointer,room_data,1);
    map_gen_room(fmx_map_pointer,room_data,2);
    map_gen_room(fmx_map_pointer,room_data,2);
    map_gen_maze(fmx_map_pointer,fmx_map_pointer->data.map_width/2,fmx_map_pointer->data.map_width * (fmx_map_pointer->data.map_height-1),DIRECTION_BIAS_NONE);
    map_gen_check_tiles(fmx_map_pointer);
};
