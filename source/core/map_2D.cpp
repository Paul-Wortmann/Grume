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

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "map_2D.hpp"
#include "loader_tmx.hpp"
#include "../game.hpp"
#include "textures.hpp"
#include "misc.hpp"

extern game_class         game;


//-----------------------------------------------------------------------------------------------------------------
void map_2D_class::render(tmx_map_type *tmx_map_pointer)
{
    tmx_tileset_type debug_tileset;
    if(game.debug)
    {
        if (!debug_tileset.image_loaded)
        {
            debug_tileset.tile_width  = 64;
            debug_tileset.tile_height = 32;
            debug_tileset.image_source = "data/tilesets/default_tileset.png";
            debug_tileset.image_source = game.core.file.path_remove(debug_tileset.image_source);
            debug_tileset.image_source = game.core.file.path_add(debug_tileset.image_source,"data/tilesets/");
            debug_tileset.tile.load_spritesheet(debug_tileset.image_source,debug_tileset.tile_width,debug_tileset.tile_height);
            debug_tileset.image_loaded = true;
            debug_tileset.number_of_tiles = debug_tileset.tile.frame_max;
        }
    }
    else
    {
        for(int tileset_count = 0; tileset_count <  tmx_map_pointer->data.number_of_tilesets; tileset_count++)
        {
            if (!tmx_map_pointer->tileset[tileset_count].image_loaded)
            {
                tmx_map_pointer->tileset[tileset_count].image_source = game.core.file.path_remove(tmx_map_pointer->tileset[tileset_count].image_source);
                tmx_map_pointer->tileset[tileset_count].image_source = game.core.file.path_add(tmx_map_pointer->tileset[tileset_count].image_source,"data/tilesets/");
                tmx_map_pointer->tileset[tileset_count].tile.load_spritesheet(tmx_map_pointer->tileset[tileset_count].image_source,tmx_map_pointer->tileset[tileset_count].tile_width,tmx_map_pointer->tileset[tileset_count].tile_height);
                tmx_map_pointer->tileset[tileset_count].image_loaded = true;
            }
        }
    }
//-----------------------------
    float tile_offset_w = 0.0f;
    float tile_offset_h = 0.0f;
    float tile_offset_x = 0.0f;
    float tile_offset_y = 0.0f;
    glDisable(GL_DEPTH_TEST);
// ----------------------------- Draw Tile Layers ------------------------------------------------------------------
    for(int layer_count = 0; layer_count <  tmx_map_pointer->data.number_of_layers; layer_count++)
    {
        for(int tile_count = 0; tile_count <  tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            if ((map_2D_class::tile_visible(tmx_map_pointer,layer_count,tile_count)) && (tmx_map_pointer->layer[layer_count].tile[tile_count].tile > 0))
            {
                tile_offset_x = tmx_map_pointer->layer[layer_count].tile[tile_count].position.x;
                tile_offset_y = tmx_map_pointer->layer[layer_count].tile[tile_count].position.y;
                tile_offset_w = tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_width  / (game.zoom.current*2);
                tile_offset_h = tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_height / (game.zoom.current*2);
                if(game.debug) tile_offset_w = debug_tileset.tile_width  / (game.zoom.current*2);
                if(game.debug) tile_offset_h = debug_tileset.tile_height / (game.zoom.current*2);
                // Calculate for irregular sized tiles.
                if (tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_width > DEFAULT_FRAME_WIDTH)
                {
                    tile_offset_x += (tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_width - DEFAULT_FRAME_WIDTH) / (game.zoom.current*4);
                }
                if (tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_height > DEFAULT_FRAME_HEIGHT)
                {
                    tile_offset_y += (tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_height - DEFAULT_FRAME_HEIGHT) / (game.zoom.current*4);
                }
                if (tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_height < DEFAULT_FRAME_HEIGHT)
                {
                    tile_offset_y += (tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile_height - DEFAULT_FRAME_HEIGHT) / (game.zoom.current*4);
                }
                if (game.debug)
                {
                    debug_tileset.tile.draw(true,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,tmx_map_pointer->layer[layer_count].tile[tile_count].tile);
                }
                else tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile.draw(true,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,tmx_map_pointer->layer[layer_count].tile[tile_count].tile-1);
            }
        }
    };
};

void map_2D_class::process(tmx_map_type *tmx_map_pointer)
{
    if (game.core.io.mouse_y >=  0.99000) map_2D_class::scroll_map(tmx_map_pointer, 0, 1);
    if (game.core.io.mouse_y <= -0.99000) map_2D_class::scroll_map(tmx_map_pointer, 0,-1);
    if (game.core.io.mouse_x >=  0.99000) map_2D_class::scroll_map(tmx_map_pointer, 1, 0);
    if (game.core.io.mouse_x <= -0.99000) map_2D_class::scroll_map(tmx_map_pointer,-1, 0);
};

void map_2D_class::scroll_map(tmx_map_type *tmx_map_pointer,int x_dir, int y_dir)
{
    float temp_x = x_dir * MAP_SCROLL_SPEED;
    float temp_y = y_dir * MAP_SCROLL_SPEED;
    for(int layer_count = 0; layer_count <  tmx_map_pointer->data.number_of_layers; layer_count++)
    {
        for(int tile_count = 0; tile_count <  tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.x -= temp_x;
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.y -= temp_y;
        }
    }
};

void map_2D_class::center_on_tile(tmx_map_type *tmx_map_pointer, int tile_ID)
{
    int layer_count = 0;
    float temp_x    = tmx_map_pointer->layer[layer_count].tile[tile_ID].position.x;
    float temp_y    = tmx_map_pointer->layer[layer_count].tile[tile_ID].position.y;
    for(layer_count = 0; layer_count <  tmx_map_pointer->data.number_of_layers; layer_count++)
    {
        for(int tile_count = 0; tile_count <  tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.x -= temp_x;
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.y -= temp_y;
        }
    }
};

void map_2D_class::calculate_tile_positions(tmx_map_type *tmx_map_pointer)
{
    for(int layer_count   = 0; layer_count <  tmx_map_pointer->data.number_of_layers; layer_count++)
    {
        float start_x     = 0.0f;
        float start_y     = 0.0f;
        int   x_count     = 0;
        int   y_count     = 0;
        for(int tile_count = 0; tile_count <  tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.x = start_x + (x_count * (TILE_WIDTH_HALF/2));
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.y = start_y - (y_count * (TILE_HEIGHT_HALF/(DEFAULT_FRAME_HEIGHT/16)));
            x_count++;
            y_count++;
            if (x_count >= tmx_map_pointer->data.map_width)
            {
                x_count = 0;
                start_x -= TILE_WIDTH_HALF/2;
            }
            if (y_count >= tmx_map_pointer->data.map_height)
            {
                y_count = 0;
                start_y -= TILE_HEIGHT_HALF/(DEFAULT_FRAME_HEIGHT/16);
            }
        }
    }
};

void map_2D_class::calculate_tile_positions(tmx_map_type *tmx_map_pointer, float tile_width_half_specify,float tile_height_half_specify)
{
    for(int layer_count   = 0; layer_count <  tmx_map_pointer->data.number_of_layers; layer_count++)
    {
        float start_x     = 0.0f;
        float start_y     = 0.0f;
        int   x_count     = 0;
        int   y_count     = 0;
        for(int tile_count = 0; tile_count <  tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.x = start_x + (x_count * (tile_width_half_specify/2));
            tmx_map_pointer->layer[layer_count].tile[tile_count].position.y = start_y - (y_count * (tile_height_half_specify/(DEFAULT_FRAME_HEIGHT/16)));
            x_count++;
            y_count++;
            if (x_count >= tmx_map_pointer->data.map_width)
            {
                x_count = 0;
                start_x -= tile_width_half_specify/2;
            }
            if (y_count >= tmx_map_pointer->data.map_height)
            {
                y_count = 0;
                start_y -= tile_height_half_specify/(DEFAULT_FRAME_HEIGHT/16);
            }
        }
    }
};

bool map_2D_class::tile_visible(tmx_map_type *tmx_map_pointer, int layer_number, int tile_number)
{
    float x_max =  1.0f;
    float x_min = -1.0f;
    float y_max =  1.0f;
    float y_min = -1.0f;
    if((tmx_map_pointer->layer[layer_number].tile[tile_number].position.x <= ( x_max+(TILE_WIDTH*4))) && (tmx_map_pointer->layer[layer_number].tile[tile_number].position.x >= (x_min-(TILE_WIDTH*4))) && (tmx_map_pointer->layer[layer_number].tile[tile_number].position.y <= ( y_max+(TILE_HEIGHT*4))) && (tmx_map_pointer->layer[layer_number].tile[tile_number].position.y >= (y_min-(TILE_HEIGHT*4)))) return(true);
    else return(false);
};

int  map_2D_class::mouse_over_tile(tmx_map_type *tmx_map_pointer)
{
    int layer_count  = 0;
    int return_value = -1;
    //for(layer_count = 0; layer_count <  tmx_map_pointer->data.number_of_layers; layer_count++)
    {
        for(int tile_count = 0; tile_count <  tmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            if (map_2D_class::tile_visible(tmx_map_pointer,layer_count,tile_count))
            {
                if (game.core.physics.point_in_diamond(tmx_map_pointer->layer[layer_count].tile[tile_count].position.x,TILE_WIDTH_HALF,tmx_map_pointer->layer[layer_count].tile[tile_count].position.y,TILE_HEIGHT_HALF,game.core.io.mouse_x,game.core.io.mouse_y)) return_value = tile_count;
            }
        }
    }
    return(return_value);
};

/*
//------------------------------ Random map generation below -----------------------------------------------------------------------------------

void map_2D_class::random_map(int tiles_x, int tiles_y, int type_of_map_to_generate, int type_of_tile_set_to_use)
{
    #define FLOOR 1
    #define WALL  2

    #define TILE_SET_DEFAULT                     0
    #define TILE_SET_FLOOR                       1
    #define TILE_SET_ROOF                        2
    #define TILE_SET_WALL_NORTH                  3
    #define TILE_SET_WALL_SOUTH                  4
    #define TILE_SET_WALL_EAST                   5
    #define TILE_SET_WALL_WEST                   6
    #define TILE_SET_WALL_NORTH_EAST_CONVEX      7
    #define TILE_SET_WALL_NORTH_WEST_CONVEX      8
    #define TILE_SET_WALL_SOUTH_EAST_CONVEX      9
    #define TILE_SET_WALL_SOUTH_WEST_CONVEX      10
    #define TILE_SET_WALL_NORTH_EAST_CONCAVE     11
    #define TILE_SET_WALL_NORTH_WEST_CONCAVE     12
    #define TILE_SET_WALL_SOUTH_EAST_CONCAVE     13
    #define TILE_SET_WALL_SOUTH_WEST_CONCAVE     14
    #define TILE_SET_OBJECTS                     15

    //----------------------------------------------------------------------------------------------------------------
    //| Generate random room structure                                                                               |
    //----------------------------------------------------------------------------------------------------------------
    bool ca_map_is_good            = false;
    int  ca_minimum_cave_size      = 50; //percentage of map
    int  ca_wall_stay              = 4;
    int  ca_wall_new               = 5;
    int  ca_iterations             = 4;
    map_2D_class::number_of_tiles  = tiles_x*tiles_y;
    map_2D_class::width            = tiles_x;
    map_2D_class::height           = tiles_y;
    int  ca_percent_random_tiles   = 40; // NB. randomly generated tiles can be generated on the same tile, thus reducing the percentage, adding a check is possible although slower.
    int  ca_number_random_tiles    = (map_2D_class::number_of_tiles / 200) * ca_percent_random_tiles * 3;
    map_2D_class::tile             = new tile_class[map_2D_class::number_of_tiles+1];
    tile_class* temp_map           = new tile_class[map_2D_class::number_of_tiles+1];
    struct flood_fill_type
    {
        int  tile_data;
        bool processed;
        bool adjoining_tile;
    };
    flood_fill_type* fill_data;
    fill_data = new flood_fill_type[map_2D_class::number_of_tiles+1];
    // load test tile-set
    {
        map_2D_class::number_of_tilesets        = 1;
        map_2D_class::tileset                   = new tileset_class [map_2D_class::number_of_tilesets+1];
        map_2D_class::tilewidth                 = DEFAULT_FRAME_WIDTH;
        map_2D_class::tileheight                = DEFAULT_FRAME_HEIGHT;
        map_2D_class::tileset[0].firstgid       = 0;
        map_2D_class::tileset[0].image_source   = "data/tilesets/default_tileset.png";
        map_2D_class::tileset[0].tilewidth      = map_2D_class::tilewidth;
        map_2D_class::tileset[0].tileheight     = map_2D_class::tileheight;
        map_2D_class::tileset[0].tile.load_spritesheet(map_2D_class::tileset[0].image_source);
        map_2D_class::tileset[0].number_of_tiles = map_2D_class::tileset[0].tile.frame_max;
    }
    switch (type_of_map_to_generate)
    {
        case DUNGEON:
            for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
            {
                map_2D_class::tile[tile_count].tile = WALL;  //Fill map with wall tiles
            }
            struct BSP_room_type
            {
                int   bounds_size_x;
                int   bounds_size_y;
                int   bounds_pos_x;
                int   bounds_pos_y;
                int   pos_x;
                int   pos_y;
                int   size_x;
                int   size_y;
                int   leaf_p_ID; // this rooms parent ID
                int   leaf_o_ID; // this rooms own ID
                int   leaf_1_ID; // this rooms child_1 ID
                int   leaf_2_ID; // this rooms child_1 ID
            };

        break;
        case CAVE:
            ca_map_is_good = false;
            while (!ca_map_is_good)
            {
                for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
                {
                    map_2D_class::tile[tile_count].tile = FLOOR;  //Fill map with floor tiles
                }
                //add wall tiles randomly on map.
                for (int tile_count = 0; tile_count < ca_number_random_tiles; tile_count++)
                {
                    map_2D_class::tile[random(map_2D_class::number_of_tiles)].tile = WALL;  //Fill with wall tiles
                }
                //add a 3x3 floored room to the middle of the map
                //this is for use later when checking for disjointed parts.
                {
                    int middle_tile_number = ((map_2D_class::number_of_tiles/2)+(map_2D_class::width/2));
                    map_2D_class::tile[middle_tile_number].tile           = FLOOR;
                    map_2D_class::tile[middle_tile_number+1].tile         = FLOOR;
                    map_2D_class::tile[middle_tile_number-1].tile         = FLOOR;
                    map_2D_class::tile[middle_tile_number+tiles_x].tile   = FLOOR;
                    map_2D_class::tile[middle_tile_number+tiles_x+1].tile = FLOOR;
                    map_2D_class::tile[middle_tile_number+tiles_x-1].tile = FLOOR;
                    map_2D_class::tile[middle_tile_number-tiles_x].tile   = FLOOR;
                    map_2D_class::tile[middle_tile_number-tiles_x+1].tile = FLOOR;
                    map_2D_class::tile[middle_tile_number-tiles_x-1].tile = FLOOR;
                }
                //fill perimeter with wall tiles
                for (int tile_count = 0; tile_count < tiles_x; tile_count++)
                {
                    map_2D_class::tile[tile_count].tile                               = WALL;  //Fill with wall tiles
                    map_2D_class::tile[map_2D_class::number_of_tiles-tile_count].tile = WALL;  //Fill with wall tiles
                }
                for (int tile_count = 0; tile_count < tiles_y; tile_count++)
                {
                    map_2D_class::tile[tile_count*tiles_x].tile                = WALL;  //Fill with wall tiles
                    map_2D_class::tile[(tile_count*tiles_x)+tiles_y-1].tile    = WALL;  //Fill with wall tiles
                }
                //smooth map, depending on neighboring tiles.
                for (int refine_count = 0; refine_count < ca_iterations; refine_count++)
                {
                    int number_of_neighbors = 0;
                    int temp_tile_number    = 0;
                    for(int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
                    {
                        number_of_neighbors = 0;
                        temp_tile_number    = 0;
                        temp_map[tile_count].tile = FLOOR; // new tile is initially a floor tile
                        temp_tile_number = tile_count+1;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        temp_tile_number = tile_count-1;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        temp_tile_number = tile_count+tiles_x;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        temp_tile_number = tile_count+tiles_x+1;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        temp_tile_number = tile_count+tiles_x-1;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        temp_tile_number = tile_count-tiles_x;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        temp_tile_number = tile_count-tiles_x+1;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        temp_tile_number = tile_count-tiles_x-1;
                        if ((temp_tile_number >= 0) && (temp_tile_number <= map_2D_class::number_of_tiles) && (map_2D_class::tile[temp_tile_number].tile == WALL)) number_of_neighbors++;
                        if ((map_2D_class::tile[tile_count].tile == WALL)  && (number_of_neighbors >= ca_wall_stay)) temp_map[tile_count].tile = WALL; //Tile on temp map is a wall
                        if ((map_2D_class::tile[tile_count].tile == FLOOR) && (number_of_neighbors >= ca_wall_new )) temp_map[tile_count].tile = WALL; //Tile on temp map is a wall
                    }
                    //fill perimeter with wall tiles
                    for (int tile_count = 0; tile_count < tiles_x; tile_count++)
                    {
                        temp_map[tile_count].tile                               = WALL;  //Fill with wall tiles
                        temp_map[map_2D_class::number_of_tiles-tile_count].tile = WALL;  //Fill with wall tiles
                    }
                    for (int tile_count = 0; tile_count < tiles_y; tile_count++)
                    {
                        temp_map[tile_count*tiles_x].tile                = WALL;  //Fill with wall tiles
                        temp_map[(tile_count*tiles_x)+tiles_y-1].tile    = WALL;  //Fill with wall tiles
                    }
                    //copy tiles from temp map to the main map.
                    for(int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
                    {
                        map_2D_class::tile[tile_count].tile = temp_map[tile_count].tile;
                    }
                }
                // find out if cave from the center is the largest part, and discard disjointed parts
                // if main cave is of adequate size, keep and return good, else regenerate.
                for(int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
                {
                    fill_data[tile_count].tile_data      = map_2D_class::tile[tile_count].tile;
                    fill_data[tile_count].processed      = false;
                    fill_data[tile_count].adjoining_tile = false;
                }
                {// we already know these are floor tiles, so mark as part of the fill.
                    int middle_tile_number = ((map_2D_class::number_of_tiles/2)+(map_2D_class::width/2));
                    fill_data[middle_tile_number].processed           = true;
                    fill_data[middle_tile_number+1].processed         = true;
                    fill_data[middle_tile_number-1].processed         = true;
                    fill_data[middle_tile_number+tiles_x].processed   = true;
                    fill_data[middle_tile_number+tiles_x+1].processed = true;
                    fill_data[middle_tile_number+tiles_x-1].processed = true;
                    fill_data[middle_tile_number-tiles_x].processed   = true;
                    fill_data[middle_tile_number-tiles_x+1].processed = true;
                    fill_data[middle_tile_number-tiles_x-1].processed = true;
                    fill_data[middle_tile_number].adjoining_tile           = true;
                    fill_data[middle_tile_number+1].adjoining_tile         = true;
                    fill_data[middle_tile_number-1].adjoining_tile         = true;
                    fill_data[middle_tile_number+tiles_x].adjoining_tile   = true;
                    fill_data[middle_tile_number+tiles_x+1].adjoining_tile = true;
                    fill_data[middle_tile_number+tiles_x-1].adjoining_tile = true;
                    fill_data[middle_tile_number-tiles_x].adjoining_tile   = true;
                    fill_data[middle_tile_number-tiles_x+1].adjoining_tile = true;
                    fill_data[middle_tile_number-tiles_x-1].adjoining_tile = true;
                }
                int   number_found         = 0;
                int   temp_tile            = 0;
                bool  is_an_adjoining_tile = false;
                //while((!fill_data[0].processed) && (!fill_data[map_2D_class::number_of_tiles-1].processed))
                for(int repeat_count = 0; repeat_count < ((tiles_x+tiles_y)/2); repeat_count++)
                {
                    for(int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
                    {
                        // we don't need to check if temp_tile is going passed the borders as the borders are always walls
                        is_an_adjoining_tile  = false;
                        temp_tile = tile_count+1;
                        if((temp_tile >= 0) && (temp_tile <= map_2D_class::number_of_tiles))
                        {
                            if (fill_data[temp_tile].adjoining_tile)
                            {
                                is_an_adjoining_tile = true;
                                number_found++;
                            }
                        }
                        temp_tile = tile_count-1;
                        if((temp_tile >= 0) && (temp_tile <= map_2D_class::number_of_tiles))
                        {
                            if (fill_data[temp_tile].adjoining_tile)
                            {
                                is_an_adjoining_tile = true;
                                number_found++;
                            }
                        }
                        temp_tile = tile_count+tiles_x;
                        if((temp_tile >= 0) && (temp_tile <= map_2D_class::number_of_tiles))
                        {
                            if (fill_data[temp_tile].adjoining_tile)
                            {
                                is_an_adjoining_tile = true;
                                number_found++;
                            }
                        }
                        temp_tile = tile_count-tiles_x;
                        if((temp_tile >= 0) && (temp_tile <= map_2D_class::number_of_tiles))
                        {
                            if (fill_data[temp_tile].adjoining_tile)
                            {
                                is_an_adjoining_tile = true;
                                number_found++;
                            }
                        }
                        fill_data[tile_count].processed = true;
                        if ((is_an_adjoining_tile) and (fill_data[tile_count].tile_data == FLOOR)) fill_data[tile_count].adjoining_tile = true;
                    }
                }
                ca_map_is_good = (number_found >= ((map_2D_class::number_of_tiles/100.0f)*ca_minimum_cave_size)) ? true : false;
            }
        break;
        case GRASSLAND:
            for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
            {
                map_2D_class::tile[tile_count].tile = FLOOR;  //Fill map with floor tiles
            }
        break;
    }
    // write new values to array discarding disjointed tiles
    for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
    {
        if(fill_data[tile_count].adjoining_tile) fill_data[tile_count].tile_data = FLOOR;
        else fill_data[tile_count].tile_data = WALL;
    }
    for (int iteration_count = 0; iteration_count < 5; iteration_count++)
    {
        //remove single tiles / tile formations that are not supported
        for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
        {
            if(fill_data[tile_count].tile_data == WALL)
            {
//-------------------- Loose single tiles on a joining wall "T" shape.
                if ((fill_data[tile_count+tiles_x].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data == WALL)
                    && (fill_data[tile_count+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR))
                {
                    fill_data[tile_count+tiles_x+1].tile_data = WALL;
                    fill_data[tile_count-tiles_x+1].tile_data = WALL;
                }
                if ((fill_data[tile_count+tiles_x].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data == WALL)
                    && (fill_data[tile_count-1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                {
                    fill_data[tile_count+tiles_x-1].tile_data = WALL;
                    fill_data[tile_count-tiles_x-1].tile_data = WALL;
                }
                if ((fill_data[tile_count+1].tile_data == WALL)
                    && (fill_data[tile_count-1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR))
                {
                    fill_data[tile_count-tiles_x-1].tile_data = WALL;
                    fill_data[tile_count-tiles_x+1].tile_data = WALL;
                }
                if ((fill_data[tile_count+1].tile_data == WALL)
                    && (fill_data[tile_count-1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR))
                {
                    fill_data[tile_count+tiles_x-1].tile_data = WALL;
                    fill_data[tile_count+tiles_x+1].tile_data = WALL;
                }
//-------------------- Loose single tiles on a joining wall other shape.
                if ((fill_data[tile_count+tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data == FLOOR)
                    && (fill_data[tile_count-1].tile_data == FLOOR))
                {
                    fill_data[tile_count+tiles_x].tile_data = WALL;
                    fill_data[tile_count-1].tile_data = WALL;
                }
                if ((fill_data[tile_count-tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data == FLOOR)
                    && (fill_data[tile_count+1].tile_data == FLOOR))
                {
                    fill_data[tile_count-tiles_x].tile_data = WALL;
                    fill_data[tile_count+1].tile_data = WALL;
                }
//-------------------- Vertical sparse line segment.
                if ((fill_data[tile_count-tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data == FLOOR)
                    && (fill_data[tile_count-1].tile_data == FLOOR))
                {
                    fill_data[tile_count-tiles_x].tile_data = WALL;
                    fill_data[tile_count-1].tile_data = WALL;
                }
                if ((fill_data[tile_count+tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data == FLOOR)
                    && (fill_data[tile_count+1].tile_data == FLOOR))
                {
                    fill_data[tile_count+tiles_x].tile_data = WALL;
                    fill_data[tile_count+1].tile_data = WALL;
                }
//-------------------- Horizontal sparse line segment.
                if ((fill_data[tile_count+tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data == FLOOR)
                    && (fill_data[tile_count-1].tile_data == FLOOR))
                {
                    fill_data[tile_count+tiles_x].tile_data = WALL;
                    fill_data[tile_count-1].tile_data = WALL;
                }
                if ((fill_data[tile_count-tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data == FLOOR)
                    && (fill_data[tile_count+1].tile_data == FLOOR))
                {
                    fill_data[tile_count-tiles_x].tile_data = WALL;
                    fill_data[tile_count+1].tile_data = WALL;
                }
//-------------------- Single tile
                if (   (fill_data[tile_count+1].tile_data         == FLOOR)
                    && (fill_data[tile_count-1].tile_data         == FLOOR)
                    && (fill_data[tile_count+tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                        fill_data[tile_count].tile_data = FLOOR;
                if ((fill_data[tile_count+1].tile_data == FLOOR)
                    && (fill_data[tile_count-1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data == FLOOR))
                    fill_data[tile_count].tile_data = FLOOR;
//-------------------- Diagonally opposite tiles.
                if (   (fill_data[tile_count+1].tile_data         == FLOOR)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {
                        fill_data[tile_count+1].tile_data = WALL;
                        fill_data[tile_count-tiles_x-1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == FLOOR)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {
                        fill_data[tile_count-1].tile_data = WALL;
                        fill_data[tile_count+tiles_x+1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {
                        fill_data[tile_count+tiles_x].tile_data = WALL;
                        fill_data[tile_count-tiles_x-1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count-tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {
                        fill_data[tile_count-tiles_x].tile_data = WALL;
                        fill_data[tile_count+tiles_x+1].tile_data = WALL;
                    }
                //----
                if (   (fill_data[tile_count+1].tile_data         == FLOOR)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == WALL))
                    {
                        fill_data[tile_count+1].tile_data = WALL;
                        fill_data[tile_count+tiles_x-1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == FLOOR)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == WALL))
                    {
                        fill_data[tile_count-1].tile_data = WALL;
                        fill_data[tile_count-tiles_x+1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count+tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == WALL))
                    {
                        fill_data[tile_count+tiles_x].tile_data = WALL;
                        fill_data[tile_count-tiles_x+1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == WALL))
                    {
                        fill_data[tile_count-tiles_x].tile_data = WALL;
                        fill_data[tile_count+tiles_x-1].tile_data = WALL;
                    }
//--------------------------- Corner with diagonal floors
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x-1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {
                        fill_data[tile_count+tiles_x+1].tile_data = WALL;
                        fill_data[tile_count-tiles_x-1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == WALL))
                    {
                        fill_data[tile_count+tiles_x-1].tile_data = WALL;
                        fill_data[tile_count-tiles_x+1].tile_data = WALL;
                    }
                if (   (fill_data[tile_count+1].tile_data         == WALL)
                    && (fill_data[tile_count-1].tile_data         == WALL)
                    && (fill_data[tile_count+tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count+tiles_x+1].tile_data == WALL)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == WALL)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == WALL))
                    {
                        fill_data[tile_count+tiles_x-1].tile_data = WALL;
                        fill_data[tile_count-tiles_x+1].tile_data = WALL;
                    }
            }
        }
    }
    //----------------------------------------------------------------------------------------------------------------
    //| Apply Tile-set                                                                                               |
    //----------------------------------------------------------------------------------------------------------------
    std::string tile_set_name_default                 = "data/tilesets/default_tileset.png";
    std::string tile_set_name_floor                   = "data/tilesets/default_tileset.png";
    std::string tile_set_name_roof                    = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_north              = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_south              = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_east               = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_west               = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_north_east_convex  = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_north_west_convex  = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_south_east_convex  = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_south_west_convex  = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_north_east_concave = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_north_west_concave = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_south_east_concave = "data/tilesets/default_tileset.png";
    std::string tile_set_name_wall_south_west_concave = "data/tilesets/default_tileset.png";
    std::string tile_set_name_objects                 = "data/tilesets/default_tileset.png";
    int  floor_width  = 64;
    int  floor_height = 32;
    int  wall_width   = 64;
    int  wall_height  = 128;
    switch (type_of_tile_set_to_use)
    {
        case DUNGEON:
            floor_width  = 64;
            floor_height = 32;
            wall_width   = 64;
            wall_height  = 128;
            tile_set_name_floor                   = "data/tilesets/dungeon_floor.png";
            tile_set_name_roof                    = "data/tilesets/dungeon_roof.png";
            tile_set_name_wall_north              = "data/tilesets/dungeon_wall_north.png";
            tile_set_name_wall_south              = "data/tilesets/dungeon_wall_south.png";
            tile_set_name_wall_east               = "data/tilesets/dungeon_wall_east.png";
            tile_set_name_wall_west               = "data/tilesets/dungeon_wall_west.png";
            tile_set_name_wall_north_east_convex  = "data/tilesets/dungeon_wall_north_east_convex.png";
            tile_set_name_wall_north_west_convex  = "data/tilesets/dungeon_wall_north_west_convex.png";
            tile_set_name_wall_south_east_convex  = "data/tilesets/dungeon_wall_south_east_convex.png";
            tile_set_name_wall_south_west_convex  = "data/tilesets/dungeon_wall_south_west_convex.png";
            tile_set_name_wall_north_east_concave = "data/tilesets/dungeon_wall_north_east_concave.png";
            tile_set_name_wall_north_west_concave = "data/tilesets/dungeon_wall_north_west_concave.png";
            tile_set_name_wall_south_east_concave = "data/tilesets/dungeon_wall_south_east_concave.png";
            tile_set_name_wall_south_west_concave = "data/tilesets/dungeon_wall_south_west_concave.png";
            tile_set_name_objects                 = "data/tilesets/dungeon_objects.png";
        break;
        case CAVE:
            floor_width  = 64;
            floor_height = 32;
            wall_width   = 64;
            wall_height  = 128;
            tile_set_name_floor                   = "data/tilesets/cave_floor.png";
            tile_set_name_roof                    = "data/tilesets/cave_roof.png";
            tile_set_name_wall_north              = "data/tilesets/cave_wall_north.png";
            tile_set_name_wall_south              = "data/tilesets/cave_wall_south.png";
            tile_set_name_wall_east               = "data/tilesets/cave_wall_east.png";
            tile_set_name_wall_west               = "data/tilesets/cave_wall_west.png";
            tile_set_name_wall_north_east_convex  = "data/tilesets/cave_wall_north_east_convex.png";
            tile_set_name_wall_north_west_convex  = "data/tilesets/cave_wall_north_west_convex.png";
            tile_set_name_wall_south_east_convex  = "data/tilesets/cave_wall_south_east_convex.png";
            tile_set_name_wall_south_west_convex  = "data/tilesets/cave_wall_south_west_convex.png";
            tile_set_name_wall_north_east_concave = "data/tilesets/cave_wall_north_east_concave.png";
            tile_set_name_wall_north_west_concave = "data/tilesets/cave_wall_north_west_concave.png";
            tile_set_name_wall_south_east_concave = "data/tilesets/cave_wall_south_east_concave.png";
            tile_set_name_wall_south_west_concave = "data/tilesets/cave_wall_south_west_concave.png";
            tile_set_name_objects                 = "data/tilesets/cave_objects.png";
        break;
        case GRASSLAND:
            floor_width  = 64;
            floor_height = 128;
            wall_width   = 64;
            wall_height  = 128;
            tile_set_name_floor                   = "data/tilesets/grassland_floor.png";
            tile_set_name_roof                    = "data/tilesets/grassland_roof.png";
            tile_set_name_wall_north              = "data/tilesets/grassland_wall_north.png";
            tile_set_name_wall_south              = "data/tilesets/grassland_wall_south.png";
            tile_set_name_wall_east               = "data/tilesets/grassland_wall_east.png";
            tile_set_name_wall_west               = "data/tilesets/grassland_wall_west.png";
            tile_set_name_wall_north_east_convex  = "data/tilesets/grassland_wall_north_east_convex.png";
            tile_set_name_wall_north_west_convex  = "data/tilesets/grassland_wall_north_west_convex.png";
            tile_set_name_wall_south_east_convex  = "data/tilesets/grassland_wall_south_east_convex.png";
            tile_set_name_wall_south_west_convex  = "data/tilesets/grassland_wall_south_west_convex.png";
            tile_set_name_wall_north_east_concave = "data/tilesets/grassland_wall_north_east_concave.png";
            tile_set_name_wall_north_west_concave = "data/tilesets/grassland_wall_north_west_concave.png";
            tile_set_name_wall_south_east_concave = "data/tilesets/grassland_wall_south_east_concave.png";
            tile_set_name_wall_south_west_concave = "data/tilesets/grassland_wall_south_west_concave.png";
            tile_set_name_objects                 = "data/tilesets/grassland_objects.png";
        break;
        default:
        break;
    }
    // load tile-sets
    {
        if (map_2D_class::tileset) delete map_2D_class::tileset;
        map_2D_class::number_of_tilesets         = 16;
        map_2D_class::tileset                    = new tileset_class [map_2D_class::number_of_tilesets];
        map_2D_class::tilewidth                  = DEFAULT_FRAME_WIDTH;
        map_2D_class::tileheight                 = DEFAULT_FRAME_HEIGHT;
        map_2D_class::tileset[TILE_SET_DEFAULT].firstgid        = 1;
        map_2D_class::tileset[TILE_SET_DEFAULT].image_source    = tile_set_name_default;
        map_2D_class::tileset[TILE_SET_DEFAULT].tilewidth       = map_2D_class::tilewidth;
        map_2D_class::tileset[TILE_SET_DEFAULT].tileheight      = map_2D_class::tileheight;
        map_2D_class::tileset[TILE_SET_DEFAULT].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_DEFAULT].image_source,map_2D_class::tileset[TILE_SET_DEFAULT].tilewidth,map_2D_class::tileset[TILE_SET_DEFAULT].tileheight);
        map_2D_class::tileset[TILE_SET_DEFAULT].number_of_tiles = map_2D_class::tileset[TILE_SET_DEFAULT].tile.frame_max;
        map_2D_class::tileset[TILE_SET_FLOOR].firstgid          = map_2D_class::tileset[TILE_SET_DEFAULT].number_of_tiles+map_2D_class::tileset[TILE_SET_DEFAULT].firstgid +1;
        map_2D_class::tileset[TILE_SET_FLOOR].image_source    = tile_set_name_floor;
        map_2D_class::tileset[TILE_SET_FLOOR].tilewidth       = floor_width;
        map_2D_class::tileset[TILE_SET_FLOOR].tileheight      = floor_height;
        map_2D_class::tileset[TILE_SET_FLOOR].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_FLOOR].image_source,map_2D_class::tileset[TILE_SET_FLOOR].tilewidth,map_2D_class::tileset[TILE_SET_FLOOR].tileheight);
        map_2D_class::tileset[TILE_SET_FLOOR].number_of_tiles = map_2D_class::tileset[TILE_SET_FLOOR].tile.frame_max;
        map_2D_class::tileset[TILE_SET_ROOF].firstgid          = map_2D_class::tileset[TILE_SET_FLOOR].number_of_tiles+map_2D_class::tileset[TILE_SET_FLOOR].firstgid +1;
        map_2D_class::tileset[TILE_SET_ROOF].image_source    = tile_set_name_roof;
        map_2D_class::tileset[TILE_SET_ROOF].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_ROOF].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_ROOF].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_ROOF].image_source,map_2D_class::tileset[TILE_SET_ROOF].tilewidth,map_2D_class::tileset[TILE_SET_ROOF].tileheight);
        map_2D_class::tileset[TILE_SET_ROOF].number_of_tiles = map_2D_class::tileset[TILE_SET_ROOF].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_NORTH].firstgid        = map_2D_class::tileset[TILE_SET_ROOF].number_of_tiles+map_2D_class::tileset[TILE_SET_ROOF].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_NORTH].image_source    = tile_set_name_wall_north;
        map_2D_class::tileset[TILE_SET_WALL_NORTH].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_NORTH].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_NORTH].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_NORTH].image_source,map_2D_class::tileset[TILE_SET_WALL_NORTH].tilewidth,map_2D_class::tileset[TILE_SET_WALL_NORTH].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_NORTH].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_NORTH].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH].firstgid        = map_2D_class::tileset[TILE_SET_WALL_NORTH].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_NORTH].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH].image_source    = tile_set_name_wall_south;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_SOUTH].image_source,map_2D_class::tileset[TILE_SET_WALL_SOUTH].tilewidth,map_2D_class::tileset[TILE_SET_WALL_SOUTH].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_SOUTH].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_SOUTH].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_EAST].firstgid        = map_2D_class::tileset[TILE_SET_WALL_SOUTH].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_SOUTH].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_EAST].image_source    = tile_set_name_wall_east;
        map_2D_class::tileset[TILE_SET_WALL_EAST].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_EAST].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_EAST].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_EAST].image_source,map_2D_class::tileset[TILE_SET_WALL_EAST].tilewidth,map_2D_class::tileset[TILE_SET_WALL_EAST].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_EAST].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_EAST].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_WEST].firstgid        = map_2D_class::tileset[TILE_SET_WALL_EAST].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_EAST].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_WEST].image_source    = tile_set_name_wall_west;
        map_2D_class::tileset[TILE_SET_WALL_WEST].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_WEST].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_WEST].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_WEST].image_source,map_2D_class::tileset[TILE_SET_WALL_WEST].tilewidth,map_2D_class::tileset[TILE_SET_WALL_WEST].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_WEST].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_WEST].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].firstgid        = map_2D_class::tileset[TILE_SET_WALL_WEST].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_WEST].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].image_source    = tile_set_name_wall_north_east_convex;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].image_source,map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tilewidth,map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].firstgid        = map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].image_source    = tile_set_name_wall_north_west_convex;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].image_source,map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tilewidth,map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].firstgid        = map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].image_source    = tile_set_name_wall_south_east_convex;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].image_source,map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tilewidth,map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].firstgid        = map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].image_source    = tile_set_name_wall_south_west_convex;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].image_source,map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tilewidth,map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].firstgid        = map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].image_source    = tile_set_name_wall_north_east_concave;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].image_source,map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tilewidth,map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].firstgid        = map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].image_source    = tile_set_name_wall_north_west_concave;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].image_source,map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tilewidth,map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].firstgid        = map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].image_source    = tile_set_name_wall_south_east_concave;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].image_source,map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tilewidth,map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile.frame_max;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].firstgid        = map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].firstgid +1;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].image_source    = tile_set_name_wall_south_west_concave;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].image_source,map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tilewidth,map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tileheight);
        map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles = map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile.frame_max;
        map_2D_class::tileset[TILE_SET_OBJECTS].firstgid        = map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles+map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].firstgid +1;
        map_2D_class::tileset[TILE_SET_OBJECTS].image_source    = tile_set_name_objects;
        map_2D_class::tileset[TILE_SET_OBJECTS].tilewidth       = wall_width;
        map_2D_class::tileset[TILE_SET_OBJECTS].tileheight      = wall_height;
        map_2D_class::tileset[TILE_SET_OBJECTS].tile.load_spritesheet(map_2D_class::tileset[TILE_SET_OBJECTS].image_source,map_2D_class::tileset[TILE_SET_OBJECTS].tilewidth,map_2D_class::tileset[TILE_SET_OBJECTS].tileheight);
        map_2D_class::tileset[TILE_SET_OBJECTS].number_of_tiles = map_2D_class::tileset[TILE_SET_OBJECTS].tile.frame_max;
    }
    int  random_seed     = 0;
    int  random_number   = 0;
    bool wall_placed     = false;
    for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
    {
        switch (fill_data[tile_count].tile_data)
        {
            case FLOOR:
                map_2D_class::tile[tile_count].tile_tileset = TILE_SET_FLOOR;
                random_seed     = map_2D_class::tileset[TILE_SET_FLOOR].number_of_tiles;
                random_number = random(random_seed*4);
                if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].tile = 1;
                else map_2D_class::tile[tile_count].tile = (random_number - random_seed*3);
                // Randomly add cave objects.
                if (   (fill_data[tile_count+1].tile_data         == FLOOR)
                    && (fill_data[tile_count-1].tile_data         == FLOOR)
                    && (fill_data[tile_count+tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x].tile_data   == FLOOR)
                    && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR)
                    && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {
                        if(random(1000) < 10)
                        {
                            map_2D_class::tile[tile_count].object_tileset = TILE_SET_OBJECTS;
                            random_seed     = map_2D_class::tileset[TILE_SET_OBJECTS].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                            else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        }
                    }

            break;
            case WALL:
                map_2D_class::tile[tile_count].tile_tileset = TILE_SET_FLOOR;
                map_2D_class::tile[tile_count].collision = true;
                wall_placed = false;
                if((tile_count-1 >= 0) && (tile_count+1 <= tiles_x))
                {//North wall.
                    if ((fill_data[tile_count+tiles_x].tile_data == FLOOR))
                    {
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count-1].tile_data == WALL) && (fill_data[tile_count+tiles_x].tile_data == WALL)
                        && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR))
                    {//North east concave wall
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH_EAST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count+1].tile_data == WALL) && (fill_data[tile_count+tiles_x].tile_data == WALL)
                        && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR))
                    {//North west concave wall
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH_WEST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                }
                if((tile_count-1) >= (map_2D_class::number_of_tiles-tiles_x))
                {//South wall.
                    if ((fill_data[tile_count-tiles_x].tile_data == FLOOR))
                    {
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count-1].tile_data == WALL) && (fill_data[tile_count-tiles_x].tile_data == WALL)
                        && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {//South east concave wall
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH_EAST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count+1].tile_data == WALL) && (fill_data[tile_count-tiles_x].tile_data == WALL)
                        && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR))
                    {//South west concave wall
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH_WEST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                }
                if((tile_count-1 >= 0) && (tile_count+1 <= map_2D_class::number_of_tiles)
                   && (tile_count-tiles_x >= 0) && (tile_count+tiles_x <= map_2D_class::number_of_tiles))
                {
                    if ((fill_data[tile_count-1].tile_data == WALL) && (fill_data[tile_count+1].tile_data == WALL))
                    {
                        if(fill_data[tile_count-tiles_x].tile_data == FLOOR)
                        {// North wall
                            map_2D_class::tile[tile_count].tile = 0;
                            map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH;
                            random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                            else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                            wall_placed = true;
                        }
                        if(fill_data[tile_count+tiles_x].tile_data == FLOOR)
                        {// South wall
                            map_2D_class::tile[tile_count].tile = 1;
                            map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH;
                            random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                            else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                            wall_placed = true;
                        }
                    }
                    if ((fill_data[tile_count-tiles_x].tile_data == WALL) && (fill_data[tile_count+tiles_x].tile_data == WALL))
                    {
                        if(fill_data[tile_count+1].tile_data == FLOOR)
                        {// East wall
                            map_2D_class::tile[tile_count].tile = 1;
                            map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_EAST;
                            random_seed     = map_2D_class::tileset[TILE_SET_WALL_EAST].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                            else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                            wall_placed = true;
                        }
                        if(fill_data[tile_count-1].tile_data == FLOOR)
                        {// West wall
                            map_2D_class::tile[tile_count].tile = 0;
                            map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_WEST;
                            random_seed     = map_2D_class::tileset[TILE_SET_WALL_WEST].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                            else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                            wall_placed = true;
                        }
                    }
                    if ((fill_data[tile_count-1].tile_data == WALL) && (fill_data[tile_count+tiles_x].tile_data == WALL)
                        && (fill_data[tile_count+1].tile_data == FLOOR)
                        && (fill_data[tile_count-tiles_x].tile_data == FLOOR))
                    {//North east convex wall
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH_EAST_CONVEX;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count+1].tile_data == WALL) && (fill_data[tile_count+tiles_x].tile_data == WALL)
                        && (fill_data[tile_count-1].tile_data == FLOOR)
                        && (fill_data[tile_count-tiles_x].tile_data == FLOOR))
                    {//North west convex wall
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH_WEST_CONVEX;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count-1].tile_data == WALL) && (fill_data[tile_count-tiles_x].tile_data == WALL)
                        && (fill_data[tile_count+1].tile_data == FLOOR)
                        && (fill_data[tile_count+tiles_x].tile_data == FLOOR))
                    {//South east convex wall
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH_EAST_CONVEX;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count+1].tile_data == WALL) && (fill_data[tile_count-tiles_x].tile_data == WALL)
                        && (fill_data[tile_count-1].tile_data == FLOOR)
                        && (fill_data[tile_count+tiles_x].tile_data == FLOOR))
                    {//South west convex wall
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH_WEST_CONVEX;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count-1].tile_data == WALL) && (fill_data[tile_count+tiles_x].tile_data == WALL)
                        && (fill_data[tile_count+tiles_x-1].tile_data == FLOOR))
                    {//North east concave wall
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH_EAST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count+1].tile_data == WALL) && (fill_data[tile_count+tiles_x].tile_data == WALL)
                        && (fill_data[tile_count+tiles_x+1].tile_data == FLOOR))
                    {//North west concave wall
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_NORTH_WEST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count-1].tile_data == WALL) && (fill_data[tile_count-tiles_x].tile_data == WALL)
                        && (fill_data[tile_count-tiles_x-1].tile_data == FLOOR))
                    {//South east concave wall
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH_EAST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                    if ((fill_data[tile_count+1].tile_data == WALL) && (fill_data[tile_count-tiles_x].tile_data == WALL)
                        && (fill_data[tile_count-tiles_x+1].tile_data == FLOOR))
                    {//South west concave wall
                        map_2D_class::tile[tile_count].tile = 0;
                        map_2D_class::tile[tile_count].object_tileset = TILE_SET_WALL_SOUTH_WEST_CONCAVE;
                        random_seed     = map_2D_class::tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) map_2D_class::tile[tile_count].object = 1;
                        else map_2D_class::tile[tile_count].object = (random_number - random_seed*3);
                        wall_placed = true;
                    }
                }
                if (!wall_placed)
                {
                    map_2D_class::tile[tile_count].tile_tileset   = TILE_SET_DEFAULT;
                    map_2D_class::tile[tile_count].tile           = 0;
                    map_2D_class::tile[tile_count].object_tileset = TILE_SET_ROOF;
                    map_2D_class::tile[tile_count].object         = 1;
                }
            break;
            default:
            break;
        }
    }
    //----------------------------------------------------------------------------------------------------------------
    //| Add content to map                                                                                           |
    //----------------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------------
    //| Miscellaneous                                                                                                |
    //----------------------------------------------------------------------------------------------------------------
    delete fill_data;
    map_2D_class::calculate_tile_positions();
    map_2D_class::center_on_tile((map_2D_class::number_of_tiles/2)+(map_2D_class::width/2));
};


//-----------------------------------------------------------------------------------------------------------------
*/
