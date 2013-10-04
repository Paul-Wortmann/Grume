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
#include "../game/game.hpp"
#include "texture_manager.hpp"
#include "misc.hpp"

extern game_class         game;

//-----------------------------------------------------------------------------------------------------------------
void map_2D_class::render(tmx_map_type *tmx_map_pointer)
{
    /*
    tmx_tileset_type debug_tileset;
    if(game.debug)
    {
        if (debug_tileset.tile != NULL)
        {
            debug_tileset.tile_width  = 64;
            debug_tileset.tile_height = 32;
            debug_tileset.image_source = "data/tilesets/default_tileset.png";
            debug_tileset.image_source = game.core.file.path_remove(debug_tileset.image_source);
            debug_tileset.image_source = game.core.file.path_add(debug_tileset.image_source,"data/tilesets/");
            game.core.log.file_write("Loading tile-set -> ",debug_tileset.image_source);
            debug_tileset.tile = game.texture_manager.add_texture(debug_tileset.image_source.c_str(),true,debug_tileset.tile_width,debug_tileset.tile_height);
            debug_tileset.number_of_tiles = debug_tileset.tile->frame_max;
        }
    }
    else
    {
        for(int tileset_count = 0; tileset_count < tmx_map_pointer->data.number_of_tilesets; tileset_count++)
        {
            if (tmx_map_pointer->tileset[tileset_count].tile != NULL)
            {
                tmx_map_pointer->tileset[tileset_count].image_source    = game.core.file.path_remove(tmx_map_pointer->tileset[tileset_count].image_source);
                tmx_map_pointer->tileset[tileset_count].image_source    = game.core.file.path_add(tmx_map_pointer->tileset[tileset_count].image_source,"data/tilesets/");
                tmx_map_pointer->tileset[tileset_count].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[tileset_count].image_source.c_str(),true,tmx_map_pointer->tileset[tileset_count].tile_width,tmx_map_pointer->tileset[tileset_count].tile_height);
                tmx_map_pointer->tileset[tileset_count].number_of_tiles = tmx_map_pointer->tileset[tileset_count].tile->frame_max;
            }
        }
    }
    */
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
                //if(game.debug) tile_offset_w = debug_tileset.tile_width  / (game.zoom.current*2);
                //if(game.debug) tile_offset_h = debug_tileset.tile_height / (game.zoom.current*2);
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
                /*
                if (game.debug)
                {
                    game.texture_manager.draw(debug_tileset.tile,true,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,tmx_map_pointer->layer[layer_count].tile[tile_count].tile);
                }
                else
                */
                /*
                if (!game.debug)
                {
                    game.core.log.file_write("Number of layers   -> ",tmx_map_pointer->data.number_of_layers);
                    game.core.log.file_write("Number of tilesets -> ",tmx_map_pointer->data.number_of_tilesets);
                    game.core.log.file_write("Number of tiles    -> ",tmx_map_pointer->data.number_of_tiles);
                    game.core.log.file_write("Layer count        -> ",layer_count);
                    game.core.log.file_write("Tile set           -> ",tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset);
                    game.core.log.file_write("Tile               -> ",tmx_map_pointer->layer[layer_count].tile[tile_count].tile-1);
                    game.debug = true;
                }
                */
                game.texture_manager.draw(tmx_map_pointer->tileset[tmx_map_pointer->layer[layer_count].tile[tile_count].tile_tileset].tile,true,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,tmx_map_pointer->layer[layer_count].tile[tile_count].tile-1);
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
    for(int layer_count = 0; layer_count < tmx_map_pointer->data.number_of_layers; layer_count++)
    {
        for(int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
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


//----------------------------------------------------------------------------------------------------------------
//| Apply Tile-set                                                                                               |
//----------------------------------------------------------------------------------------------------------------
void map_2D_class::apply_tileset(tmx_map_type *tmx_map_pointer, int pre_defined_tileset_value)
{
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
    // ---------------------------------------------- Preset values ---------------------------------------------
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
    int  floor_width    = 64;
    int  floor_height   = 32;
    int  wall_width     = 64;
    int  wall_height    = 128;
    // ----------------------------------------- set tileset based on type ---------------------------------------
    switch (pre_defined_tileset_value)
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
            game.core.log.file_write("Error applying tile-set -> %d",pre_defined_tileset_value);
        break;

    }
    // load tile-sets
    if (tmx_map_pointer->tileset) delete [] tmx_map_pointer->tileset;
    tmx_map_pointer->data.number_of_tilesets                     = 16;
    tmx_map_pointer->tileset                                     = new tmx_tileset_type[tmx_map_pointer->data.number_of_tilesets];
    tmx_map_pointer->data.map_tile_width                         = DEFAULT_FRAME_WIDTH;
    tmx_map_pointer->data.map_tile_height                        = DEFAULT_FRAME_HEIGHT;
    tmx_map_pointer->tileset[TILE_SET_DEFAULT].first_gid         = 1;
    tmx_map_pointer->tileset[TILE_SET_DEFAULT].image_source      = tile_set_name_default;
    tmx_map_pointer->tileset[TILE_SET_DEFAULT].tile_width        = tmx_map_pointer->data.map_tile_width;
    tmx_map_pointer->tileset[TILE_SET_DEFAULT].tile_height       = tmx_map_pointer->data.map_tile_height;
    tmx_map_pointer->tileset[TILE_SET_DEFAULT].tile              = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_DEFAULT].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_DEFAULT].tile_width,tmx_map_pointer->tileset[TILE_SET_DEFAULT].tile_height);
    tmx_map_pointer->tileset[TILE_SET_DEFAULT].number_of_tiles   = tmx_map_pointer->tileset[TILE_SET_DEFAULT].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_FLOOR].first_gid           = tmx_map_pointer->tileset[TILE_SET_DEFAULT].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_DEFAULT].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_FLOOR].image_source        = tile_set_name_floor;
    tmx_map_pointer->tileset[TILE_SET_FLOOR].tile_width          = floor_width;
    tmx_map_pointer->tileset[TILE_SET_FLOOR].tile_height         = floor_height;
    tmx_map_pointer->tileset[TILE_SET_FLOOR].tile                = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_FLOOR].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_FLOOR].tile_width,tmx_map_pointer->tileset[TILE_SET_FLOOR].tile_height);
    tmx_map_pointer->tileset[TILE_SET_FLOOR].number_of_tiles     = tmx_map_pointer->tileset[TILE_SET_FLOOR].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_ROOF].first_gid            = tmx_map_pointer->tileset[TILE_SET_FLOOR].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_FLOOR].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_ROOF].image_source         = tile_set_name_roof;
    tmx_map_pointer->tileset[TILE_SET_ROOF].tile_width           = wall_width;
    tmx_map_pointer->tileset[TILE_SET_ROOF].tile_height          = wall_height;
    tmx_map_pointer->tileset[TILE_SET_ROOF].tile                 = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_ROOF].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_ROOF].tile_width,tmx_map_pointer->tileset[TILE_SET_ROOF].tile_height);
    tmx_map_pointer->tileset[TILE_SET_ROOF].number_of_tiles      = tmx_map_pointer->tileset[TILE_SET_ROOF].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].first_gid      = tmx_map_pointer->tileset[TILE_SET_ROOF].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_ROOF].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].image_source   = tile_set_name_wall_north;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].tile_width     = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].tile_height    = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].number_of_tiles = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].first_gid       = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].image_source    = tile_set_name_wall_south;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].tile_width      = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].tile_height     = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].number_of_tiles = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_EAST].first_gid        = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_EAST].image_source     = tile_set_name_wall_east;
    tmx_map_pointer->tileset[TILE_SET_WALL_EAST].tile_width       = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_EAST].tile_height      = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_EAST].tile             = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_EAST].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_EAST].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_EAST].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_EAST].number_of_tiles  = tmx_map_pointer->tileset[TILE_SET_WALL_EAST].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_WEST].first_gid        = tmx_map_pointer->tileset[TILE_SET_WALL_EAST].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_EAST].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_WEST].image_source     = tile_set_name_wall_west;
    tmx_map_pointer->tileset[TILE_SET_WALL_WEST].tile_width       = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_WEST].tile_height      = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_WEST].tile             = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_WEST].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_WEST].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_WEST].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_WEST].number_of_tiles  = tmx_map_pointer->tileset[TILE_SET_WALL_WEST].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].first_gid        = tmx_map_pointer->tileset[TILE_SET_WALL_WEST].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_WEST].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].image_source     = tile_set_name_wall_north_east_convex;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile_width       = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile_height      = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile             = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].number_of_tiles  = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].first_gid        = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].image_source     = tile_set_name_wall_north_west_convex;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile_width       = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile_height      = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile             = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].number_of_tiles  = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].first_gid        = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].image_source     = tile_set_name_wall_south_east_convex;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile_width       = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile_height      = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile             = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].number_of_tiles  = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].first_gid        = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].image_source     = tile_set_name_wall_south_west_convex;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile_width       = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile_height      = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile             = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].number_of_tiles  = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].first_gid       = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].image_source    = tile_set_name_wall_north_east_concave;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile_width      = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile_height     = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].first_gid       = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].image_source    = tile_set_name_wall_north_west_concave;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile_width      = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile_height     = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].first_gid       = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].image_source    = tile_set_name_wall_south_east_concave;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile_width      = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile_height     = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].first_gid       = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].image_source    = tile_set_name_wall_south_west_concave;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile_width      = wall_width;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile_height     = wall_height;
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile_width,tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile_height);
    tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].tile->frame_max;
    tmx_map_pointer->tileset[TILE_SET_OBJECTS].first_gid       = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles+tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].first_gid +1;
    tmx_map_pointer->tileset[TILE_SET_OBJECTS].image_source    = tile_set_name_objects;
    tmx_map_pointer->tileset[TILE_SET_OBJECTS].tile_width      = wall_width;
    tmx_map_pointer->tileset[TILE_SET_OBJECTS].tile_height     = wall_height;
    tmx_map_pointer->tileset[TILE_SET_OBJECTS].tile            = game.texture_manager.add_texture(tmx_map_pointer->tileset[TILE_SET_OBJECTS].image_source.c_str(),true,tmx_map_pointer->tileset[TILE_SET_OBJECTS].tile_width,tmx_map_pointer->tileset[TILE_SET_OBJECTS].tile_height);
    tmx_map_pointer->tileset[TILE_SET_OBJECTS].number_of_tiles = tmx_map_pointer->tileset[TILE_SET_OBJECTS].tile->frame_max;
    int  layer_floor    = 0;
    int  layer_object   = 1;
    int  layer_wall     = 2;
    int  random_seed    = 0;
    int  random_number  = 0;
    bool wall_placed    = false;
    bool place_floor    = false;
    tmx_tile_type *temp_tile_data = new tmx_tile_type[tmx_map_pointer->data.number_of_tiles];
    for (int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        temp_tile_data[tile_count].tile         = tmx_map_pointer->layer[layer_floor].tile[tile_count].tile;
        temp_tile_data[tile_count].tile_tileset = tmx_map_pointer->layer[layer_floor].tile[tile_count].tile_tileset;
        temp_tile_data[tile_count].collision    = tmx_map_pointer->layer[layer_floor].tile[tile_count].collision;
    }
    for (int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        switch (temp_tile_data[tile_count].tile)
        {
            case TILE_FLOOR:
                tmx_map_pointer->layer[layer_floor].tile[tile_count].tile_tileset = TILE_SET_FLOOR;
                random_seed     = tmx_map_pointer->tileset[TILE_SET_FLOOR].number_of_tiles;
                random_number   = random(random_seed*4);
                if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_floor].tile[tile_count].tile = 1;
                else tmx_map_pointer->layer[layer_floor].tile[tile_count].tile = (random_number - random_seed*3);
                // Randomly add cave objects.
                if (   (temp_tile_data[tile_count+1].tile         == TILE_FLOOR)
                    && (temp_tile_data[tile_count-1].tile         == TILE_FLOOR)
                    && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile   == TILE_FLOOR)
                    && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width+1].tile == TILE_FLOOR)
                    && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width-1].tile == TILE_FLOOR)
                    && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile   == TILE_FLOOR)
                    && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width+1].tile == TILE_FLOOR)
                    && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width-1].tile == TILE_FLOOR))
                    {
                        if(random(1000) < 10)
                        {
                            tmx_map_pointer->layer[layer_object].tile[tile_count].tile_tileset = TILE_SET_OBJECTS;
                            random_seed     = tmx_map_pointer->tileset[TILE_SET_OBJECTS].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_object].tile[tile_count].tile = 1;
                            else tmx_map_pointer->layer[layer_object].tile[tile_count].tile = (random_number - random_seed*3);
                        }
                    }
            break;
            case TILE_WALL:
                wall_placed = false;
                if((tile_count >= 0) && (tile_count+1 <= tmx_map_pointer->data.map_width))
                {//North wall.
                    if ((temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_FLOOR))
                    {
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = true;
                    }
                    if ((temp_tile_data[tile_count-1].tile == TILE_WALL) && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width-1].tile == TILE_FLOOR))
                    {//North east concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH_EAST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = true;
                    }
                    if ((temp_tile_data[tile_count+1].tile == TILE_WALL) && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width+1].tile == TILE_FLOOR))
                    {//North west concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH_WEST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = true;
                    }
                }
                if((tile_count-1) >= (tmx_map_pointer->data.number_of_tiles-tmx_map_pointer->data.map_width))
                {//South wall.
                    if ((temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_FLOOR))
                    {
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                    if ((temp_tile_data[tile_count-1].tile == TILE_WALL) && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width-1].tile == TILE_FLOOR))
                    {//South east concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH_EAST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                    if ((temp_tile_data[tile_count+1].tile == TILE_WALL) && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width+1].tile == TILE_FLOOR))
                    {//South west concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH_WEST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                }
                if((tile_count-1 >= 0) && (tile_count+1 <= tmx_map_pointer->data.number_of_tiles)
                   && (tile_count-tmx_map_pointer->data.map_width >= 0) && (tile_count+tmx_map_pointer->data.map_width <= tmx_map_pointer->data.number_of_tiles))
                {
                    if ((temp_tile_data[tile_count-1].tile == TILE_WALL) && (temp_tile_data[tile_count+1].tile == TILE_WALL))
                    {
                        if(temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_FLOOR)
                        {// North wall
                            tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH;
                            random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                            else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                            wall_placed = true;
                            place_floor = false;
                        }
                        if(temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_FLOOR)
                        {// South wall
                            tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH;
                            random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                            else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                            wall_placed = true;
                            place_floor = true;
                        }
                    }
                    if ((temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_WALL) && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_WALL))
                    {
                        if(temp_tile_data[tile_count+1].tile == TILE_FLOOR)
                        {// East wall
                            tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_EAST;
                            random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_EAST].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                            else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                            wall_placed = true;
                            place_floor = true;
                        }
                        if(temp_tile_data[tile_count-1].tile == TILE_FLOOR)
                        {// West wall
                            tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_WEST;
                            random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_WEST].number_of_tiles;
                            random_number = random(random_seed*4);
                            if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                            else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                            wall_placed = true;
                            place_floor = false;
                        }
                    }
                    if ((temp_tile_data[tile_count-1].tile == TILE_WALL) && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count+1].tile == TILE_FLOOR)
                        && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_FLOOR))
                    {//North east convex wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH_EAST_CONVEX;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = true;
                    }
                    if ((temp_tile_data[tile_count+1].tile == TILE_WALL) && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count-1].tile == TILE_FLOOR)
                        && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_FLOOR))
                    {//North west convex wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH_WEST_CONVEX;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                    if ((temp_tile_data[tile_count-1].tile == TILE_WALL) && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count+1].tile == TILE_FLOOR)
                        && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_FLOOR))
                    {//South east convex wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH_EAST_CONVEX;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = true;
                    }
                    if ((temp_tile_data[tile_count+1].tile == TILE_WALL) && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count-1].tile == TILE_FLOOR)
                        && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_FLOOR))
                    {//South west convex wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH_WEST_CONVEX;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONVEX].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = true;
                    }
                    if ((temp_tile_data[tile_count-1].tile == TILE_WALL) && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width-1].tile == TILE_FLOOR))
                    {//North east concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH_EAST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                    if ((temp_tile_data[tile_count+1].tile == TILE_WALL) && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count+tmx_map_pointer->data.map_width+1].tile == TILE_FLOOR))
                    {//North west concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_NORTH_WEST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_NORTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                    if ((temp_tile_data[tile_count-1].tile == TILE_WALL) && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width-1].tile == TILE_FLOOR))
                    {//South east concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH_EAST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_EAST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                    if ((temp_tile_data[tile_count+1].tile == TILE_WALL) && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width].tile == TILE_WALL)
                        && (temp_tile_data[tile_count-tmx_map_pointer->data.map_width+1].tile == TILE_FLOOR))
                    {//South west concave wall
                        tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset = TILE_SET_WALL_SOUTH_WEST_CONCAVE;
                        random_seed     = tmx_map_pointer->tileset[TILE_SET_WALL_SOUTH_WEST_CONCAVE].number_of_tiles;
                        random_number = random(random_seed*4);
                        if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = 1;
                        else tmx_map_pointer->layer[layer_wall].tile[tile_count].tile = (random_number - random_seed*3);
                        wall_placed = true;
                        place_floor = false;
                    }
                }
                if(place_floor)
                {
                    tmx_map_pointer->layer[layer_floor].tile[tile_count].tile_tileset = TILE_SET_FLOOR;
                    random_seed     = tmx_map_pointer->tileset[TILE_SET_FLOOR].number_of_tiles;
                    random_number   = random(random_seed*4);
                    if (random_number <= (random_seed*3)) tmx_map_pointer->layer[layer_floor].tile[tile_count].tile = 1;
                    else tmx_map_pointer->layer[layer_floor].tile[tile_count].tile = (random_number - random_seed*3);
                }
                else
                {
                    tmx_map_pointer->layer[layer_floor].tile[tile_count].tile_tileset   = TILE_SET_DEFAULT;
                    tmx_map_pointer->layer[layer_floor].tile[tile_count].tile           = 0;
                }
                if (!wall_placed)
                {
                    tmx_map_pointer->layer[layer_floor].tile[tile_count].tile_tileset   = TILE_SET_DEFAULT;
                    tmx_map_pointer->layer[layer_floor].tile[tile_count].tile           = 0;
                    tmx_map_pointer->layer[layer_wall].tile[tile_count].tile_tileset    = TILE_SET_DEFAULT;
                    tmx_map_pointer->layer[layer_wall].tile[tile_count].tile            = 0;
                }
            break;
            default:
                game.core.log.file_write("Unable to apply tile-set to unknown tile type -> %d\n",temp_tile_data[tile_count].tile);
            break;
        }
    }
    for (int tile_count = 0; tile_count < tmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        if (temp_tile_data[tile_count].tile == TILE_FLOOR)
        {
            tmx_map_pointer->layer[layer_floor].tile[tile_count].collision = false;
        }
        else
        {
            tmx_map_pointer->layer[layer_floor].tile[tile_count].collision = true;
        }
    }
    delete [] temp_tile_data;
};

void map_2D_class::smooth_map(tmx_map_type *tmx_map_pointer)
{
    int iterations  = 2;
    int layer_count = 0;
    int mw          = tmx_map_pointer->data.map_width;
    for (int iteration_count = 0; iteration_count < iterations; iteration_count++)
    {
        for (int tile_count = mw; tile_count < (tmx_map_pointer->data.number_of_tiles-tmx_map_pointer->data.map_width-1); tile_count++)
        {
            if(tmx_map_pointer->layer[layer_count].tile[tile_count].tile == TILE_WALL)
            {
                // Remove single tiles
                // OOO
                // OXO
                // OOO
                //--------------------
                if(  (tmx_map_pointer->layer[layer_count].tile[tile_count+1].tile    == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-1].tile    == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw].tile   == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw].tile   == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile == TILE_FLOOR))
                {
                    tmx_map_pointer->layer[layer_count].tile[tile_count].tile = TILE_FLOOR;
                }
                // Remove single horizontal tiles
                // ???
                // OXO
                // ???
                //--------------------
                if(  (tmx_map_pointer->layer[layer_count].tile[tile_count+1].tile    == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-1].tile    == TILE_FLOOR))
                {
                    tmx_map_pointer->layer[layer_count].tile[tile_count].tile = TILE_FLOOR;
                }
                // Remove single vertical tiles
                // ?O?
                // ?X?
                // ?O?
                //--------------------
                if(  (tmx_map_pointer->layer[layer_count].tile[tile_count+mw].tile   == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw].tile   == TILE_FLOOR))
                {
                    tmx_map_pointer->layer[layer_count].tile[tile_count].tile = TILE_FLOOR;
                }
                // Remove cross right tiles
                // O?X
                // ?X?
                // X?O
                //--------------------
                if(  (tmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile == TILE_WALL))
                {
                    tmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile = TILE_WALL;
                    tmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile = TILE_WALL;
                }
                // Remove cross left tiles
                // X?O
                // ?X?
                // O?X
                //--------------------
                if(  (tmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile == TILE_FLOOR))
                {
                    tmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile = TILE_WALL;
                    tmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile = TILE_WALL;
                }
            }
        }
    }
};

/*

                // Remove cross left+1 tiles
                // OXX
                // XXX
                // XOO
                //--------------------
                if(  (tmx_map_pointer->layer[layer_count].tile[tile_count+1].tile    == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-1].tile    == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw].tile   == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile == TILE_FLOOR)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count+mw-1].tile == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw].tile   == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw+1].tile == TILE_WALL)
                   &&(tmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile == TILE_FLOOR))
                {
                    tmx_map_pointer->layer[layer_count].tile[tile_count+mw+1].tile = TILE_WALL;
                    tmx_map_pointer->layer[layer_count].tile[tile_count-mw-1].tile = TILE_WALL;
                }
*/
