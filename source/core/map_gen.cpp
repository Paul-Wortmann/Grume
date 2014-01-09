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
#include "map_gen_BSP.hpp"
#include "map_gen_CA.hpp"
#include "map_gen_M1.hpp"
#include "map_gen_RC.hpp"
#include "misc.hpp"

extern game_class    game;

void map_gen_base(fmx_map_type *fmx_map_pointer, int map_size_x, int map_size_y)
{
    int tile_count_temp                                     = 0;
    int tileset_count                                       = 0;
    fmx_map_pointer->data.map_width                         = map_size_x;
    fmx_map_pointer->data.map_height                        = map_size_y;
    fmx_map_pointer->data.map_tile_width                    = 64;
    fmx_map_pointer->data.map_tile_height                   = 32;
    fmx_map_pointer->data.number_of_tiles                   = map_size_x*map_size_y;
    fmx_map_pointer->data.number_of_layers                  = 3;
    fmx_map_pointer->data.number_of_tilesets                = 1;
    fmx_map_pointer->data.number_of_rooms                   = 0;
    fmx_map_pointer->layer                                  = new fmx_layer_type[fmx_map_pointer->data.number_of_layers];
    fmx_map_pointer->layer[LAYER_FLOOR].name                = "generated_floor";
    fmx_map_pointer->layer[LAYER_FLOOR].width               = map_size_x;
    fmx_map_pointer->layer[LAYER_FLOOR].height              = map_size_y;
    fmx_map_pointer->layer[LAYER_OBJECT].name               = "generated_object";
    fmx_map_pointer->layer[LAYER_OBJECT].width              = map_size_x;
    fmx_map_pointer->layer[LAYER_OBJECT].height             = map_size_y;
    fmx_map_pointer->layer[LAYER_WALL].name                 = "generated_wall";
    fmx_map_pointer->layer[LAYER_WALL].width                = map_size_x;
    fmx_map_pointer->layer[LAYER_WALL].height               = map_size_y;
    fmx_map_pointer->tileset                                = new fmx_tileset_type[fmx_map_pointer->data.number_of_tilesets];
    fmx_map_pointer->tileset[tileset_count].first_gid       = 1;
    fmx_map_pointer->tileset[tileset_count].image_source    = "data/tilesets/default_tileset.png";
    fmx_map_pointer->tileset[tileset_count].image_width     = 256;
    fmx_map_pointer->tileset[tileset_count].image_height    = 32;
    fmx_map_pointer->tileset[tileset_count].tile_width      = 64;
    fmx_map_pointer->tileset[tileset_count].tile_height     = 32;
    fmx_map_pointer->tileset[tileset_count].number_of_tiles = 4;
    fmx_map_pointer->layer[LAYER_FLOOR].tile   = new fmx_tile_type[fmx_map_pointer->data.number_of_tiles];
    fmx_map_pointer->layer[LAYER_OBJECT].tile  = new fmx_tile_type[fmx_map_pointer->data.number_of_tiles];
    fmx_map_pointer->layer[LAYER_WALL].tile    = new fmx_tile_type[fmx_map_pointer->data.number_of_tiles];
    fmx_map_pointer->tile_data                 = new fmx_tile_data_type[fmx_map_pointer->data.number_of_tiles];
    fmx_map_pointer->path_data                 = new fmx_path_data_type[fmx_map_pointer->data.number_of_tiles];
    for (int tile_count_x = 0; tile_count_x < fmx_map_pointer->data.map_width; tile_count_x++)
    {
        for (int tile_count_y = 0; tile_count_y < fmx_map_pointer->data.map_height; tile_count_y++)
        {
            tile_count_temp = (tile_count_y * fmx_map_pointer->data.map_width) + tile_count_x;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count_temp].position.x    = tile_count_x;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count_temp].position.y    = tile_count_y;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count_temp].tile          = TILE_WALL;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count_temp].tile_tileset  = tileset_count;
            fmx_map_pointer->layer[LAYER_OBJECT].tile[tile_count_temp].position.x   = tile_count_x;
            fmx_map_pointer->layer[LAYER_OBJECT].tile[tile_count_temp].position.y   = tile_count_y;
            fmx_map_pointer->layer[LAYER_OBJECT].tile[tile_count_temp].tile         = TILE_NONE;
            fmx_map_pointer->layer[LAYER_OBJECT].tile[tile_count_temp].tile_tileset = tileset_count;
            fmx_map_pointer->layer[LAYER_WALL].tile[tile_count_temp].position.x     = tile_count_x;
            fmx_map_pointer->layer[LAYER_WALL].tile[tile_count_temp].position.y     = tile_count_y;
            fmx_map_pointer->layer[LAYER_WALL].tile[tile_count_temp].tile           = TILE_NONE;
            fmx_map_pointer->layer[LAYER_WALL].tile[tile_count_temp].tile_tileset   = tileset_count;
            fmx_map_pointer->tile_data[tile_count_temp].collision                   = true;
        }
    }
};

void map_gen_base(fmx_map_type *fmx_map_pointer)
{
    map_gen_base(fmx_map_pointer,MAP_GEN_TILES_X,MAP_GEN_TILES_Y);
};

void map_gen (fmx_map_type *fmx_map_pointer, int generator_algorithm)
{
    switch (generator_algorithm)
    {
        case MAP_GEN_BSP:
            map_gen_BSP(fmx_map_pointer);
        break;
        case MAP_GEN_CA:
            map_gen_CA(fmx_map_pointer);
        break;
        case MAP_GEN_M1:
            map_gen_M1(fmx_map_pointer);
        break;
        case MAP_GEN_RC:
        default:
            map_gen_RC(fmx_map_pointer);
        break;
    }
};

void map_gen (fmx_map_type *fmx_map_pointer, int generator_algorithm, int tileset_type)
{
    map_gen(fmx_map_pointer,generator_algorithm);
    game.map_2D.apply_tileset(fmx_map_pointer,tileset_type);
    game.map_2D.calculate_tile_positions(fmx_map_pointer,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
    game.map_2D.center_on_tile(fmx_map_pointer,(fmx_map_pointer->data.number_of_tiles/2)+(fmx_map_pointer->data.map_width/2));
};

bool map_gen_room (fmx_map_type *fmx_map_pointer, room_data_type room, int number_of_exits)
{
    bool return_value = true;
    if (room.position.x <= 0) room.position.x = random(fmx_map_pointer->data.map_width -((ROOM_MAX_X+2)*2)+(ROOM_MAX_X+2));
    if (room.position.y <= 0) room.position.y = random(fmx_map_pointer->data.map_height-((ROOM_MAX_Y+2)*2)+(ROOM_MAX_Y+2));
    if (room.size.x <= 0) room.size.x = random_int(ROOM_MIN_X,ROOM_MAX_X);
    if (room.size.y <= 0) room.size.y = random_int(ROOM_MIN_Y,ROOM_MAX_Y);
    //int temp_pos_x = room.position.x - (room.size.x/2)-1;
    //int temp_pos_y = room.position.y - (room.size.y/2)-1;
    int temp_tile = 0;
    for (int count_x = 0; count_x < room.size.x+2; count_x++)
    {
        for (int count_y = 0; count_y < room.size.y+2; count_y++)
        {
            temp_tile = (fmx_map_pointer->data.map_width*(room.position.y+count_y))+(room.position.x+count_x);
            if (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile].tile != TILE_WALL) return_value = false;
        }
    }
    if (return_value)
    {
        for (int count_x = 1; count_x < room.size.x; count_x++)
        {
            for (int count_y = 1; count_y < room.size.y; count_y++)
            {
                temp_tile = (fmx_map_pointer->data.map_width*(room.position.y+count_y))+(room.position.x+count_x);
                fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile].tile = TILE_FLOOR;
            }
        }
        int room_number = map_gen_room_add(fmx_map_pointer);
        fmx_map_pointer->room[room_number].active   = true;
        fmx_map_pointer->room[room_number].position = room.position;
        fmx_map_pointer->room[room_number].size     = room.size;
    }
    return (return_value);
};

int map_gen_flood_fill_tile (fmx_map_type *fmx_map_pointer, flood_fill_type *fill_data, int tile_number)
{
    int return_value = 0;
    if ((fill_data[tile_number].tile_data == TILE_FLOOR) && (!fill_data[tile_number].processed))
    {
        fill_data[tile_number].processed = true;
        fill_data[tile_number].adjoining_tile = true;
        return_value++;
        if ((tile_number+1) <= fmx_map_pointer->data.number_of_tiles) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number+1);
        if ((tile_number-1) >= 0) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number-1);
        if ((tile_number+fmx_map_pointer->data.map_width) <= fmx_map_pointer->data.number_of_tiles) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number+fmx_map_pointer->data.map_width);
        if ((tile_number+fmx_map_pointer->data.map_width+1) <= fmx_map_pointer->data.number_of_tiles) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number+fmx_map_pointer->data.map_width+1);
        if ((tile_number+fmx_map_pointer->data.map_width-1) <= fmx_map_pointer->data.number_of_tiles) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number+fmx_map_pointer->data.map_width-1);
        if ((tile_number-fmx_map_pointer->data.map_width) >= 0) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number-fmx_map_pointer->data.map_width);
        if ((tile_number-fmx_map_pointer->data.map_width+1) >= 0) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number-fmx_map_pointer->data.map_width+1);
        if ((tile_number-fmx_map_pointer->data.map_width-1) >= 0) return_value += map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number-fmx_map_pointer->data.map_width-1);
    }
    return (return_value);
}

bool map_gen_room_flood_fill (fmx_map_type *fmx_map_pointer)
{
    int  floor_count  = 0;
    int  first_floor  = -1;
    bool return_value = true;
    flood_fill_type fill_data[fmx_map_pointer->data.number_of_tiles];
    for(int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) floor_count++;
        if ((floor_count == 1) && (first_floor < 0)) first_floor = tile_count;
        fill_data[tile_count].tile_data       = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile ;
        fill_data[tile_count].processed       = false;
        fill_data[tile_count].adjoining_tile  = false;
    }
    int   number_found = map_gen_flood_fill_tile(fmx_map_pointer,fill_data,first_floor);
    if (number_found < floor_count) return_value = false;
    return (return_value);
};

int map_gen_room_check_path (fmx_map_type *fmx_map_pointer, int room_1, int room_2, bool x_then_y)
{
    int return_value         = 0;
    int previous_tile        = TILE_NONE;
    int to_floor_transitions = 0;
    int r1_x = fmx_map_pointer->room[room_1].position.x;
    int r1_y = fmx_map_pointer->room[room_1].position.y;
    int r2_x = fmx_map_pointer->room[room_2].position.x;
    int r2_y = fmx_map_pointer->room[room_2].position.y;
    if ((r1_x >= 0) && (r1_x <= fmx_map_pointer->data.map_width) &&
        (r1_y >= 0) && (r1_y <= fmx_map_pointer->data.map_height) &&
        (r2_x >= 0) && (r2_x <= fmx_map_pointer->data.map_width) &&
        (r2_y >= 0) && (r2_y <= fmx_map_pointer->data.map_height))
    {
        if (x_then_y)
        {
            previous_tile = TILE_NONE;
            to_floor_transitions = 0;
            int x_count = r1_x;
            int y_count = r1_y;
            if (r1_x > r2_x)
            {
                for (x_count = r1_x; x_count > r2_x; x_count--)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
            else
            {
                for (x_count = r1_x; x_count < r2_x; x_count++)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
            if (r1_y > r2_y)
            {
                for (y_count = r1_y; y_count > r2_y; y_count--)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
            else
            {
                for (y_count = r1_y; y_count < r2_y; y_count++)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
        }
        else
        {
            previous_tile = TILE_NONE;
            to_floor_transitions = 0;
            int x_count = r1_x;
            int y_count = r1_y;
            if (r1_y > r2_y)
            {
                for (y_count = r1_y; y_count > r2_y; y_count--)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
            else
            {
                for (y_count = r1_y; y_count < r2_y; y_count++)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
            if (r1_x > r2_x)
            {
                for (x_count = r1_x; x_count > r2_x; x_count--)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
            else
            {
                for (x_count = r1_x; x_count < r2_x; x_count++)
                {
                    int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                    if (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_WALL) return_value++;
                    if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) && (previous_tile == TILE_WALL)) to_floor_transitions++;
                    previous_tile = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile;
                }
            }
        }
    }
    if (to_floor_transitions > 1) return_value = 0;
    return (return_value);
}

void map_gen_room_path (fmx_map_type *fmx_map_pointer, int room_1, int room_2, bool x_then_y)
{
    if (room_1 != room_2)
    {
        //if (map_gen_is_path(fmx_map_pointer,room_1,room_2))
        bool connect_rooms = true;
        {
            bool add_room = true;
            if (fmx_map_pointer->room[room_1].number_of_connected_rooms > 0)
            {
                for (int room_count = 0; room_count < fmx_map_pointer->room[room_1].number_of_connected_rooms; room_count++)
                {
                    if (fmx_map_pointer->room[room_1].connected_rooms[room_count] == room_2) add_room = false;
                }
                connect_rooms = add_room;
            }
            if (add_room)
            {
                int *temp_room_list;
                if (fmx_map_pointer->room[room_1].number_of_connected_rooms > 0)
                {
                    temp_room_list = new int[fmx_map_pointer->room[room_1].number_of_connected_rooms];
                    temp_room_list = fmx_map_pointer->room[room_1].connected_rooms;
                    delete fmx_map_pointer->room[room_1].connected_rooms;
                }
                fmx_map_pointer->room[room_1].number_of_connected_rooms++;
                fmx_map_pointer->room[room_1].connected_rooms = new int[fmx_map_pointer->room[room_1].number_of_connected_rooms];
                if (fmx_map_pointer->room[room_1].number_of_connected_rooms > 1)
                {
                    for (int room_count = 0; room_count < fmx_map_pointer->room[room_1].number_of_connected_rooms-1; room_count++)
                    {
                        fmx_map_pointer->room[room_1].connected_rooms[room_count] = temp_room_list[room_count];
                    }
                    //if (temp_room_list) delete temp_room_list;
                }
                fmx_map_pointer->room[room_1].connected_rooms[fmx_map_pointer->room[room_1].number_of_connected_rooms-1] = room_2;
           }
            add_room = true;
            if (fmx_map_pointer->room[room_2].number_of_connected_rooms > 0)
            {
                for (int room_count = 0; room_count < fmx_map_pointer->room[room_2].number_of_connected_rooms; room_count++)
                {
                    if (fmx_map_pointer->room[room_2].connected_rooms[room_count] == room_1) add_room = false;
                }
                if (connect_rooms) connect_rooms = add_room;
            }
            if (add_room)
            {
                int *temp_room_list;
                if (fmx_map_pointer->room[room_2].number_of_connected_rooms > 0)
                {
                    temp_room_list = new int[fmx_map_pointer->room[room_2].number_of_connected_rooms];
                    temp_room_list = fmx_map_pointer->room[room_2].connected_rooms;
                    delete fmx_map_pointer->room[room_2].connected_rooms;
                }
                fmx_map_pointer->room[room_2].number_of_connected_rooms++;
                fmx_map_pointer->room[room_2].connected_rooms = new int[fmx_map_pointer->room[room_2].number_of_connected_rooms];
                if (fmx_map_pointer->room[room_2].number_of_connected_rooms > 1)
                {
                    for (int room_count = 0; room_count < fmx_map_pointer->room[room_2].number_of_connected_rooms-1; room_count++)
                    {
                        fmx_map_pointer->room[room_2].connected_rooms[room_count] = temp_room_list[room_count];
                    }
                    //if (temp_room_list) delete temp_room_list;
                }
                fmx_map_pointer->room[room_2].connected_rooms[fmx_map_pointer->room[room_2].number_of_connected_rooms-1] = room_1;
            }
        }
        if (connect_rooms)
        {
            fmx_map_pointer->room[room_1].number_of_connected_rooms++;
            fmx_map_pointer->room[room_2].number_of_connected_rooms++;
            int r1_x = fmx_map_pointer->room[room_1].position.x;
            int r1_y = fmx_map_pointer->room[room_1].position.y;
            int r2_x = fmx_map_pointer->room[room_2].position.x;
            int r2_y = fmx_map_pointer->room[room_2].position.y;
            if (x_then_y)
            {
                int x_count = r1_x;
                int y_count = r1_y;
                if (r1_x > r2_x)
                {
                    for (x_count = r1_x; x_count > r2_x; x_count--)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
                else
                {
                    for (x_count = r1_x; x_count < r2_x; x_count++)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
                if (r1_y > r2_y)
                {
                    for (y_count = r1_y; y_count > r2_y; y_count--)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
                else
                {
                    for (y_count = r1_y; y_count < r2_y; y_count++)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
            }
            else
            {
                int x_count = r1_x;
                int y_count = r1_y;
                if (r1_y > r2_y)
                {
                    for (y_count = r1_y; y_count > r2_y; y_count--)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
                else
                {
                    for (y_count = r1_y; y_count < r2_y; y_count++)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
                if (r1_x > r2_x)
                {
                    for (x_count = r1_x; x_count > r2_x; x_count--)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
                else
                {
                    for (x_count = r1_x; x_count < r2_x; x_count++)
                    {
                        int tile_count = x_count + (fmx_map_pointer->data.map_width * (y_count));
                        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile = TILE_FLOOR;
                    }
                }
            }
        }
    }
}

void map_gen_room_connect (fmx_map_type *fmx_map_pointer)
{
    if (fmx_map_pointer->data.number_of_rooms > 0)
    {
        for (int room_count_1 = 0; room_count_1 < fmx_map_pointer->data.number_of_rooms; room_count_1++)
        {
            int closest_room_1 = room_count_1;
            int closest_room_2 = room_count_1;
            int distance_closest_room_2 = fmx_map_pointer->data.number_of_tiles;
            for (int room_count_2 = 0; room_count_2 < fmx_map_pointer->data.number_of_rooms; room_count_2++)
            {
                if (room_count_1 != room_count_2)
                {
                    int distance_temp_1 = map_gen_room_check_path(fmx_map_pointer, room_count_1, room_count_2, true );
                    int distance_temp_2 = map_gen_room_check_path(fmx_map_pointer, room_count_1, room_count_2, false);
                    int distance_temp = (distance_temp_1 < distance_temp_2) ? distance_temp_1 : distance_temp_2;
                    if  ((distance_temp > 0) && (distance_temp < distance_closest_room_2))
                    {
                        closest_room_1          = closest_room_2;
                        distance_closest_room_2 = distance_temp;
                        closest_room_2          = room_count_2;
                    }
                }
            }
            if (map_gen_room_check_path(fmx_map_pointer, room_count_1, closest_room_2, true) > (map_gen_room_check_path(fmx_map_pointer, room_count_1, closest_room_2, false))) map_gen_room_path(fmx_map_pointer, room_count_1, closest_room_2, true);
            else map_gen_room_path(fmx_map_pointer, room_count_1, closest_room_2, false);
            if (fmx_map_pointer->room[closest_room_1].number_of_connected_rooms < 1)
            {
                if (map_gen_room_check_path(fmx_map_pointer, room_count_1, closest_room_1, true) > (map_gen_room_check_path(fmx_map_pointer, room_count_1, closest_room_1, false))) map_gen_room_path(fmx_map_pointer, room_count_1, closest_room_1, true);
                else map_gen_room_path(fmx_map_pointer, room_count_1, closest_room_1, false);
            }
        }
    }
};

int map_gen_room_add (fmx_map_type *fmx_map_pointer)
{
    if (fmx_map_pointer->data.number_of_rooms > 0)
    {
        fmx_room_data_type *temp_room_data =  new fmx_room_data_type[fmx_map_pointer->data.number_of_rooms];
        temp_room_data = fmx_map_pointer->room;
        fmx_map_pointer->room = new fmx_room_data_type[fmx_map_pointer->data.number_of_rooms+1];
        for (int room_count = 0; room_count < fmx_map_pointer->data.number_of_rooms; room_count++)
        {
            fmx_map_pointer->room[room_count] = temp_room_data[room_count];
        }
        fmx_map_pointer->data.number_of_rooms++;
    }
    else
    {
        fmx_map_pointer->data.number_of_rooms = 1;
        fmx_map_pointer->room = new fmx_room_data_type[fmx_map_pointer->data.number_of_rooms];
    }
    return (fmx_map_pointer->data.number_of_rooms-1);
};

room_data_type map_gen_room_find_stats (fmx_map_type *fmx_map_pointer, flood_fill_type *fill_data, int tile_number)
{
    room_data_type return_data;
    return_data.size.x     = 0;
    return_data.size.y     = 0;
    int tile_count         = tile_number;
    int tile_x             = tile_number % fmx_map_pointer->data.map_width;
    int tile_y             = tile_number / fmx_map_pointer->data.map_width;
    while (fill_data[tile_count].tile_data == TILE_FLOOR)
    {
        return_data.size.x++;
        tile_count++;
    }
    tile_count = tile_number;
    while (fill_data[tile_count].tile_data == TILE_FLOOR)
    {
        return_data.size.y++;
        tile_count += fmx_map_pointer->data.map_width;
    }

    return_data.position.x = tile_x + (return_data.size.x / 2);
    return_data.position.y = tile_y + (return_data.size.y / 2);
    map_gen_flood_fill_tile(fmx_map_pointer,fill_data,tile_number);
    return (return_data);
};

void map_gen_room_find (fmx_map_type *fmx_map_pointer)
{
    int            room_number = -1;
    room_data_type room_data;
    flood_fill_type fill_data[fmx_map_pointer->data.number_of_tiles];
    fmx_map_pointer->data.number_of_rooms = 0;
    for (int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        fill_data[tile_count].tile_data       = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile ;
        fill_data[tile_count].processed       = false;
        fill_data[tile_count].adjoining_tile  = false;
    }
    for (int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        if ((fill_data[tile_count].tile_data == TILE_FLOOR) && (!fill_data[tile_count].processed))
        {
            room_data   = map_gen_room_find_stats (fmx_map_pointer,fill_data,tile_count);
            room_number = map_gen_room_add        (fmx_map_pointer);
            fmx_map_pointer->room[room_number].active                    = true;
            fmx_map_pointer->room[room_number].size.x                    = room_data.size.x;
            fmx_map_pointer->room[room_number].size.y                    = room_data.size.y;
            fmx_map_pointer->room[room_number].position.x                = room_data.position.x;
            fmx_map_pointer->room[room_number].position.y                = room_data.position.y;
            fmx_map_pointer->room[room_number].number_of_connected_rooms = 0;
        }
    }
};

void map_gen_room_collision (fmx_map_type *fmx_map_pointer)
{
    for (int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        fmx_map_pointer->tile_data[tile_count].collision = (fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile == TILE_FLOOR) ? false : true;
    }
};

void map_gen_check_tiles (fmx_map_type *fmx_map_pointer)
{
    int iterations  = 2;
    int layer_count = 0;
    int mw          = fmx_map_pointer->data.map_width;
    for (int iteration_count = 0; iteration_count < iterations; iteration_count++)
    {
        for (int tile_count = mw; tile_count < (fmx_map_pointer->data.number_of_tiles-fmx_map_pointer->data.map_width-1); tile_count++)
        {
            if(fmx_map_pointer->layer[layer_count].tile[tile_count].tile == TILE_WALL)
            {
                // Remove single tiles
                // OOO
                // OXO
                // OOO
                //--------------------
                if(  (fmx_map_pointer->layer[layer_count].tile[tile_count+1].tile    == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-1].tile    == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count+mw].tile   == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw].tile   == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile == TILE_FLOOR))
                {
                    fmx_map_pointer->layer[layer_count].tile[tile_count].tile = TILE_FLOOR;
                }
                // Remove single horizontal tiles
                // ???
                // OXO
                // ???
                //--------------------
                if(  (fmx_map_pointer->layer[layer_count].tile[tile_count+1].tile    == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-1].tile    == TILE_FLOOR))
                {
                    fmx_map_pointer->layer[layer_count].tile[tile_count].tile = TILE_FLOOR;
                }
                // Remove single vertical tiles
                // ?O?
                // ?X?
                // ?O?
                //--------------------
                if(  (fmx_map_pointer->layer[layer_count].tile[tile_count+mw].tile   == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw].tile   == TILE_FLOOR))
                {
                    fmx_map_pointer->layer[layer_count].tile[tile_count].tile = TILE_FLOOR;
                }
                // Remove cross right tiles
                // O?X
                // ?X?
                // X?O
                //--------------------
                if(  (fmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile == TILE_WALL)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile == TILE_WALL))
                {
                    fmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile = TILE_WALL;
                    fmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile = TILE_WALL;
                }
                // Remove cross left tiles
                // X?O
                // ?X?
                // O?X
                //--------------------
                if(  (fmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile == TILE_FLOOR)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile == TILE_WALL)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile == TILE_WALL)
                   &&(fmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile == TILE_FLOOR))
                {
                    fmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile = TILE_WALL;
                    fmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile = TILE_WALL;
                }
            }
        }
    }
    map_gen_room_collision(fmx_map_pointer);
};

void map_gen_room_add_exits (fmx_map_type *fmx_map_pointer)
{
game.core.log.file_write("-> map_gen_room_add_exits() called ");

    int room_e        = 0;
    int room_s        = 1;
    /*
    int distance_temp = 0;
    path_type* path_data;
    for (int room_1 = 0; room_1 < fmx_map_pointer->data.number_of_rooms; room_1++)
    {
        for (int room_2 = 0; room_2 < fmx_map_pointer->data.number_of_rooms; room_2++)
        {
            if ((room_1 != room_2)&&(fmx_map_pointer->room[room_1].active)&&(fmx_map_pointer->room[room_2].active))
            {
                path_data = map_path_find(fmx_map_pointer,fmx_map_pointer->room[room_1].position.x,fmx_map_pointer->room[room_1].position.y,fmx_map_pointer->room[room_2].position.x,fmx_map_pointer->room[room_2].position.y);
                if (path_data->path_length > distance_temp)
                {
                    distance_temp = path_data->path_length;
                    room_e = room_1;
                    room_s = room_2;
                    game.core.log.file_write("-> distance found - ",distance_temp);
                }
            }
        }
    }
    if (room_e != room_s)
    {
        fmx_map_pointer->layer[LAYER_FLOOR].tile[(fmx_map_pointer->room[room_e].position.x + (fmx_map_pointer->room[room_e].position.y * fmx_map_pointer->data.map_width))].tile = TILE_EXIT;
        fmx_map_pointer->layer[LAYER_FLOOR].tile[(fmx_map_pointer->room[room_s].position.x + (fmx_map_pointer->room[room_s].position.y * fmx_map_pointer->data.map_width))].tile = TILE_EXIT;

path_data = map_path_find(fmx_map_pointer,fmx_map_pointer->room[room_e].position.x,fmx_map_pointer->room[room_e].position.y,fmx_map_pointer->room[room_s].position.x,fmx_map_pointer->room[room_s].position.y);
distance_temp = path_data->path_length;
game.core.log.file_write("-> distance found - ",distance_temp);

    }

    */
    for (int tile_count_x = 0; tile_count_x < fmx_map_pointer->data.map_width; tile_count_x++)
    {
        for (int tile_count_y = 0; tile_count_y < fmx_map_pointer->data.map_height; tile_count_y++)
        {
            //int tile_count_temp = (tile_count_y * fmx_map_pointer->data.map_width) + tile_count_x;
            //fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count_temp].tile          = TILE_FLOOR;
            //fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count_temp].collision     = false;
        }
    }
        fmx_map_pointer->layer[LAYER_FLOOR].tile[(fmx_map_pointer->room[room_e].position.x + (fmx_map_pointer->room[room_e].position.y * fmx_map_pointer->data.map_width))].tile = TILE_EXIT;
        fmx_map_pointer->layer[LAYER_FLOOR].tile[(fmx_map_pointer->room[room_s].position.x + (fmx_map_pointer->room[room_s].position.y * fmx_map_pointer->data.map_width))].tile = TILE_EXIT;
//path_data = map_path_find(fmx_map_pointer,fmx_map_pointer->room[room_e].position.x,fmx_map_pointer->room[room_e].position.y,fmx_map_pointer->room[room_s].position.x,fmx_map_pointer->room[room_s].position.y);
map_path_find(fmx_map_pointer,fmx_map_pointer->room[room_e].position.x,fmx_map_pointer->room[room_e].position.y,fmx_map_pointer->room[room_s].position.x,fmx_map_pointer->room[room_s].position.y);

};





