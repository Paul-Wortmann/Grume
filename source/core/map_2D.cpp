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

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "map_2D.hpp"
#include "../game.hpp"
#include "textures.hpp"
#include "random_map.hpp"

extern game_class         game;

//-----------------------------------------------------------------------------------------------------------------

tile_class::tile_class(void)
{
    tile_class::collision       = false;
    tile_class::object          = 0;
    tile_class::object_tileset  = 0;
    tile_class::tile            = 0;
    tile_class::tile_tileset    = 0;
};

tile_class::~tile_class(void)
{
};

//-----------------------------------------------------------------------------------------------------------------

tileset_class::tileset_class(void)
{
    tileset_class::tilewidth  = 0;
    tileset_class::tileheight = 0;
    tileset_class::firstgid   = 0;
    tileset_class::name       = "";
};

tileset_class::~tileset_class(void)
{
};

//-----------------------------------------------------------------------------------------------------------------

void map_2D_class::draw(void)
{
    float tile_offset_w = 0.0f;
    float tile_offset_h = 0.0f;
    float tile_offset_x = 0.0f;
    float tile_offset_y = 0.0f;
    glDisable(GL_DEPTH_TEST);
// ----------------------------- Draw Tile Layer ------------------------------------------------------------------
    for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
    {
        if ((map_2D_class::tile_visable(tile_count)) && (map_2D_class::tile[tile_count].tile > 0))
        {
                tile_offset_x = map_2D_class::tile[tile_count].pos_x;
                tile_offset_y = map_2D_class::tile[tile_count].pos_y;
                tile_offset_w = map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tilewidth  / (game.zoom.current*2);
                tile_offset_h = map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tileheight / (game.zoom.current*2);
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tilewidth > DEFAULT_FRAME_WIDTH)
            {
                tile_offset_x += (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tilewidth - DEFAULT_FRAME_WIDTH) / (game.zoom.current*4);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tileheight > DEFAULT_FRAME_HEIGHT)
            {
                tile_offset_y += (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tileheight - DEFAULT_FRAME_HEIGHT) / (game.zoom.current*4);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tileheight < DEFAULT_FRAME_HEIGHT)
            {
                tile_offset_y += (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tileheight - DEFAULT_FRAME_HEIGHT) / (game.zoom.current*4);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/grass_and_water.png")
            {
                game.resource.texture.render(true,game.resource.texture.grass_and_water_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/bridge.png")
            {
                game.resource.texture.render(true,game.resource.texture.bridge_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/grassland.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/grassland_water.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_water_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/grassland_trees.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_trees_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/grassland_structures.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_structures_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/broken_tower.png")
            {
                game.resource.texture.render(true,game.resource.texture.broken_tower_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/fence.png")
            {
                game.resource.texture.render(true,game.resource.texture.fence_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/medieval_building.png")
            {
                game.resource.texture.render(true,game.resource.texture.medieval_building_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/cave_floor.png")
            {
                game.resource.texture.render(true,game.resource.texture.cave_floor_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/cave_wall.png")
            {
                game.resource.texture.render(true,game.resource.texture.cave_wall_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/cave_object.png")
            {
                game.resource.texture.render(true,game.resource.texture.cave_object_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/dungeon.png")
            {
                game.resource.texture.render(true,game.resource.texture.dungeon_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].image_source == "../tilesets/gold_tileset.png")
            {
                game.resource.texture.render(true,game.resource.texture.gold_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile-1);
            }
        }
    };
// ----------------------------- Draw Object Layer ----------------------------------------------------------------
    for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
    {
        if ((map_2D_class::tile_visable(tile_count)) && (map_2D_class::tile[tile_count].object > 0))
        {
                tile_offset_x = map_2D_class::tile[tile_count].pos_x;
                tile_offset_y = map_2D_class::tile[tile_count].pos_y;
                tile_offset_w = map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tilewidth  / (game.zoom.current*2);
                tile_offset_h = map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tileheight / (game.zoom.current*2);
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tilewidth > DEFAULT_FRAME_WIDTH)
            {
                tile_offset_x += (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tilewidth - DEFAULT_FRAME_WIDTH) / (game.zoom.current*4);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tileheight > DEFAULT_FRAME_HEIGHT)
            {
                tile_offset_y += (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tileheight - DEFAULT_FRAME_HEIGHT) / (game.zoom.current*4);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tileheight < DEFAULT_FRAME_HEIGHT)
            {
                tile_offset_y += (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tileheight - DEFAULT_FRAME_HEIGHT) / (game.zoom.current*4);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/grass_and_water.png")
            {
                game.resource.texture.render(true,game.resource.texture.grass_and_water_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/bridge.png")
            {
                game.resource.texture.render(true,game.resource.texture.bridge_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/grassland.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/grassland_water.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_water_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/grassland_trees.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_trees_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/grassland_structures.png")
            {
                game.resource.texture.render(true,game.resource.texture.grassland_structures_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/broken_tower.png")
            {
                game.resource.texture.render(true,game.resource.texture.broken_tower_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/fence.png")
            {
                game.resource.texture.render(true,game.resource.texture.fence_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/medieval_building.png")
            {
                game.resource.texture.render(true,game.resource.texture.medieval_building_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/cave_floor.png")
            {
                game.resource.texture.render(true,game.resource.texture.cave_floor_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/cave_wall.png")
            {
                game.resource.texture.render(true,game.resource.texture.cave_wall_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/cave_object.png")
            {
                game.resource.texture.render(true,game.resource.texture.cave_object_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/dungeon.png")
            {
                game.resource.texture.render(true,game.resource.texture.dungeon_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
            if (map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].image_source == "../tilesets/gold_tileset.png")
            {
                game.resource.texture.render(true,game.resource.texture.gold_tileset.ref_number,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object-1);
            }
        }
    };
};

void map_2D_class::process(void)
{
    if (game.core.io.mouse_y >=  0.99000) map_2D_class::scroll_map( 0, 1);
    if (game.core.io.mouse_y <= -0.99000) map_2D_class::scroll_map( 0,-1);
    if (game.core.io.mouse_x >=  0.99000) map_2D_class::scroll_map( 1, 0);
    if (game.core.io.mouse_x <= -0.99000) map_2D_class::scroll_map(-1, 0);
};

void map_2D_class::scroll_map(int x_dir, int y_dir)
{
    float temp_x = x_dir * MAP_SCROLL_SPEED;
    float temp_y = y_dir * MAP_SCROLL_SPEED;
    for(int tile_count = 0; tile_count < MAX_TILES; tile_count++)
    {
        map_2D_class::tile[tile_count].pos_x -= temp_x;
        map_2D_class::tile[tile_count].pos_y -= temp_y;
    }
};

void map_2D_class::center_on_tile(int tile_ID)
{
    float temp_x = map_2D_class::tile[tile_ID].pos_x;
    float temp_y = map_2D_class::tile[tile_ID].pos_y;
    for(int tile_count = 0; tile_count < MAX_TILES; tile_count++)
    {
        map_2D_class::tile[tile_count].pos_x -= temp_x;
        map_2D_class::tile[tile_count].pos_y -= temp_y;
    }
};

void map_2D_class::calculate_tile_positions(void)
{
    float start_x  = 0.0f;
    float start_y  = 0.0f;
    int   x_count  = 0;
    int   y_count  = 0;
    for (int tile_count = 0; tile_count < MAX_TILES; tile_count++)
    {
        map_2D_class::tile[tile_count].pos_x = start_x + (x_count * (TILE_WIDTH_HALF/2));
        map_2D_class::tile[tile_count].pos_y = start_y - (y_count * (TILE_HEIGHT_HALF/(DEFAULT_FRAME_HEIGHT/16)));
        x_count++;
        y_count++;
        if (x_count >= MAX_TILE_X)
        {
            x_count = 0;
            start_x -= TILE_WIDTH_HALF/2;
        }
        if (y_count >= MAX_TILE_Y)
        {
            y_count = 0;
            start_y -= TILE_HEIGHT_HALF/(DEFAULT_FRAME_HEIGHT/16);
        }
    }
};

void map_2D_class::calculate_tile_positions(float tile_width_half_specify,float tile_height_half_specify)
{
    float start_x  = map_2D_class::tile[0].pos_x;
    float start_y  = map_2D_class::tile[0].pos_y + (tile_height_half_specify/(DEFAULT_FRAME_HEIGHT/16));
    int   x_count  = 0;
    int   y_count  = 0;
    for (int tile_count = 0; tile_count < MAX_TILES; tile_count++)
    {
        map_2D_class::tile[tile_count].pos_x = start_x + (x_count * (tile_width_half_specify/2));
        map_2D_class::tile[tile_count].pos_y = start_y - (y_count * (tile_height_half_specify/(DEFAULT_FRAME_HEIGHT/16)));
        x_count++;
        y_count++;
        if (x_count >= MAX_TILE_X)
        {
            x_count = 0;
            start_x -= tile_width_half_specify/2;
        }
        if (y_count >= MAX_TILE_Y)
        {
            y_count = 0;
            start_y -= tile_height_half_specify/(DEFAULT_FRAME_HEIGHT/16);
        }
    }
};

bool map_2D_class::tile_visable(int tile_no)
{
    float x_max =  1.0f;
    float x_min = -1.0f;
    float y_max =  1.0f;
    float y_min = -1.0f;
    if((map_2D_class::tile[tile_no].pos_x <= ( x_max+(TILE_WIDTH*4))) && (map_2D_class::tile[tile_no].pos_x >= (x_min-(TILE_WIDTH*4))) && (map_2D_class::tile[tile_no].pos_y <= ( y_max+(TILE_HEIGHT*4))) && (map_2D_class::tile[tile_no].pos_y >= (y_min-(TILE_HEIGHT*4)))) return(true);
    else return(false);
};

int  map_2D_class::mouse_over_tile(void)
{
    int return_value = -1;
    for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
    {
        if ((map_2D_class::tile_visable(tile_count)) && (map_2D_class::tile[tile_count].tile > 0))
        {
            if (game.core.physics.point_in_diamond(map_2D_class::tile[tile_count].pos_x,TILE_WIDTH_HALF,map_2D_class::tile[tile_count].pos_y,TILE_HEIGHT_HALF,game.core.io.mouse_x,game.core.io.mouse_y)) return_value = tile_count;
        }
    }
    return(return_value);
};

void map_2D_class::load(std::string file_name)
{
    int          position_count  = 0;
    int          position_start  = 0;
    bool         map_data        = true;
    bool         tileset_data    = false;
    bool         layer_data      = false;
    bool         collision_data  = false;
    bool         object_data     = false;
    bool         tile_data       = false;
    int          tileset_count   = 0;
    int          layer_count     = 0;
    int          tile_count      = 0;
    char         temp_char = ' ';
    float        temp_float_data;
    int          temp_int_data;
    bool         temp_bool_data;
    std::string  temp_string_data;
    std::string  temp_string_key;
    std::string  temp_string_value;
    std::string  data_line;
    std::fstream script_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (script_file.is_open())
    {
        while (script_file.good())
        {
            getline(script_file,data_line);
            {
                position_count = 0;
                if ((data_line[position_count] == ' ') && (data_line.length() > 2))
                {
                    temp_char = ' ';
                    while (temp_char == ' ')
                    {
                        temp_char = data_line[position_count];
                        position_count++;
                    }
                    position_count--;
                }
                position_start = position_count;
                if((data_line[position_count] == '<') && (data_line[position_count+1] == '/') && (data_line.length() > 2))
                {
                    temp_char         = ' ';
                    temp_string_key   = "";
                    temp_string_value = "";
                    while(temp_char != '>')
                    {
                        temp_char = data_line[position_count];
                        if((temp_char != '<') && (temp_char != '/') && (temp_char != '>'))
                        {
                            temp_string_key += temp_char;
                        }
                        position_count++;
                        if(position_count > (int)data_line.length()) temp_char = '>';
                    }
                    if (temp_string_key == "tileset")
                    {
                        map_2D_class::tileset[tileset_count].number_of_tiles = ((map_2D_class::tileset[tileset_count].width / map_2D_class::tileset[tileset_count].tilewidth) * (map_2D_class::tileset[tileset_count].height / map_2D_class::tileset[tileset_count].tileheight));
                        tileset_data = false;
                        tileset_count++;
                    }
                    if (temp_string_key == "layer")
                    {
                        collision_data  = false;
                        object_data     = false;
                        tile_data       = false;
                        tile_count      = 0;
                        layer_data      = false;
                        layer_count++;
                    }
                }
                position_count = position_start;
                if((data_line[position_count] == '<') && (data_line[position_count+1] != '/') && (data_line.length() > 2))
                {
                    position_count++;
                    while(position_count < (int)data_line.length())
                    {
                        temp_char         = ' ';
                        temp_string_key   = "";
                        temp_string_value = "";
                        while(temp_char != '"')
                        {
                            temp_char = data_line[position_count];
                            if((temp_char != '"') && (temp_char != '='))
                            {
                                if((data_line[position_count-1] != '"') && (temp_char == ' ')) temp_string_key += temp_char;
                                else if (temp_char != ' ') temp_string_key += temp_char;
                            }
                            position_count++;
                            if(position_count > (int)data_line.length()) temp_char = '"';
                        }
                        temp_char        = ' ';
                        while(temp_char != '"')
                        {
                            temp_char = data_line[position_count];
                            if(temp_char != '"') temp_string_value += temp_char;
                            position_count++;
                            if(position_count > (int)data_line.length()) (temp_char = '"');
                        }
                        temp_string_data    = temp_string_value.c_str();
                        temp_float_data     = atof(temp_string_value.c_str());
                        temp_int_data       = atoi(temp_string_value.c_str());
                        if (temp_int_data   == 1) temp_bool_data = true;
                        else temp_bool_data = false;
                        if (temp_string_key == "map version")      map_data     = true;
                        if (temp_string_key == "tileset firstgid") tileset_data = true;
                        if (temp_string_key == "layer name")       layer_data   = true;
                        if (map_data)
                        {
                            if (temp_string_key == "map version") map_2D_class::version     = temp_float_data;
                            if (temp_string_key == "orientation") map_2D_class::orientation = temp_string_data;
                            if (temp_string_key == "width")       map_2D_class::width       = temp_int_data;
                            if (temp_string_key == "height")      map_2D_class::height      = temp_int_data;
                            if (temp_string_key == "tilewidth")   map_2D_class::tilewidth   = temp_int_data;
                            if (temp_string_key == "tileheight")  map_2D_class::tileheight  = temp_int_data;
                            if (temp_string_key == "tileheight")  map_data               = false;
                        }
                        if (tileset_data)
                        {
                            if (temp_string_key == "tileset firstgid") map_2D_class::tileset[tileset_count].firstgid     = temp_int_data;
                            if (temp_string_key == "name")             map_2D_class::tileset[tileset_count].name         = temp_string_data;
                            if (temp_string_key == "tilewidth")        map_2D_class::tileset[tileset_count].tilewidth    = temp_int_data;
                            if (temp_string_key == "tileheight")       map_2D_class::tileset[tileset_count].tileheight   = temp_int_data;
                            if (temp_string_key == "image source")     map_2D_class::tileset[tileset_count].image_source = temp_string_data;
                            if (temp_string_key == "width")            map_2D_class::tileset[tileset_count].width        = temp_int_data;
                            if (temp_string_key == "height")           map_2D_class::tileset[tileset_count].height       = temp_int_data;
                        }
                        if (layer_data)
                        {
                            if (temp_string_key == "layer name")
                            {
                                if (temp_string_data == "collision") collision_data  = true;
                                    else collision_data  = false;
                                if (temp_string_data == "object") object_data  = true;
                                    else object_data  = false;
                                if (temp_string_data == "tile") tile_data  = true;
                                    else tile_data  = false;
                                tile_count      = 0;
                            };
                            if (temp_string_key == "tile gid")
                            {
                                if (collision_data)
                                {
                                    map_2D_class::tile[tile_count].collision = temp_bool_data;
                                }
                                if (object_data)
                                {
                                    map_2D_class::tile[tile_count].object_tileset = 0;
                                    for (int temp_tileset_count = 0; temp_tileset_count < tileset_count; temp_tileset_count++)
                                    {
                                        if (temp_int_data >= map_2D_class::tileset[temp_tileset_count].firstgid)
                                        {
                                            map_2D_class::tile[tile_count].object_tileset = temp_tileset_count;
                                        }
                                    }
                                    temp_int_data -= map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].firstgid;
                                    temp_int_data += 1;
                                    map_2D_class::tile[tile_count].object       = temp_int_data;
                                }
                                if (tile_data)
                                {
                                    map_2D_class::tile[tile_count].tile_tileset = 0;
                                    for (int temp_tileset_count = 0; temp_tileset_count < tileset_count; temp_tileset_count++)
                                    {
                                        if (temp_int_data >= map_2D_class::tileset[temp_tileset_count].firstgid)
                                        {
                                            map_2D_class::tile[tile_count].tile_tileset = temp_tileset_count;
                                        }
                                    }
                                    temp_int_data -= map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].firstgid;
                                    temp_int_data += 1;
                                    map_2D_class::tile[tile_count].tile         = temp_int_data;
                                }
                                tile_count++;
                            }
                        }
                    }
                }
            }
        }
        script_file.close();
        map_2D_class::number_of_tiles    = map_2D_class::width * map_2D_class::height;
        map_2D_class::number_of_tilesets = tileset_count + 1;
        map_2D_class::calculate_tile_positions();
        map_2D_class::center_on_tile(0);
    }
};

void map_2D_class::save(std::string file_name)
{
    std::fstream script_file(file_name.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
    if (script_file.is_open())
    {
        script_file << "<?xml version=";
        script_file << '"';
        script_file << "1.0";
        script_file << '"';
        script_file << " encoding=";
        script_file << '"';
        script_file << " UTF-8";
        script_file << '"';
        script_file << "?>";
        script_file << "\n";

        script_file << "<map version=";
        script_file << '"';
        script_file << (float)map_2D_class::version;
        if ((float)map_2D_class::version == (int)map_2D_class::version) script_file << ".0";
        script_file << '"';
        script_file << " orientation=";
        script_file << '"';
        script_file << map_2D_class::orientation.c_str();
        script_file << '"';
        script_file << " width=";
        script_file << '"';
        script_file << map_2D_class::width;
        script_file << '"';
        script_file << " height=";
        script_file << '"';
        script_file << map_2D_class::height;
        script_file << '"';
        script_file << " tilewidth=";
        script_file << '"';
        script_file << map_2D_class::tilewidth;
        script_file << '"';
        script_file << " tileheight=";
        script_file << '"';
        script_file << map_2D_class::tileheight;
        script_file << '"';
        script_file << ">";
        script_file << "\n";

        script_file << " <properties>";
        script_file << "\n";

        script_file << "  <property name=";
        script_file << '"';
        script_file << "MAP_ID";
        script_file << '"';
        script_file << " value=";
        script_file << '"';
        script_file << "0";
        script_file << '"';
        script_file << "/>";
        script_file << "\n";

        script_file << " </properties>";
        script_file << "\n";

        for (int tileset_count = 0; tileset_count < (map_2D_class::number_of_tilesets - 1); tileset_count++)
        {
            script_file << " <tileset firstgid=";
            script_file << '"';
            script_file << map_2D_class::tileset[tileset_count].firstgid;
            script_file << '"';
            script_file << " name=";
            script_file << '"';
            script_file << map_2D_class::tileset[tileset_count].name;
            script_file << '"';
            script_file << " tilewidth=";
            script_file << '"';
            script_file << map_2D_class::tileset[tileset_count].tilewidth;
            script_file << '"';
            script_file << " tileheight=";
            script_file << '"';
            script_file << map_2D_class::tileset[tileset_count].tileheight;
            script_file << '"';
            script_file << "/>";
            script_file << "\n";
            script_file << "  <image source=";
            script_file << '"';
            script_file << map_2D_class::tileset[tileset_count].image_source;
            script_file << '"';
            script_file << " width=";
            script_file << '"';
            script_file << map_2D_class::tileset[tileset_count].width;
            script_file << '"';
            script_file << " height=";
            script_file << '"';
            script_file << map_2D_class::tileset[tileset_count].height;
            script_file << '"';
            script_file << "/>";
            script_file << "\n";
            script_file << " </tileset>";
            script_file << "\n";
        }
        script_file << " <layer name=";
        script_file << '"';
        script_file << "tile";
        script_file << '"';
        script_file << " width=";
        script_file << '"';
        script_file << map_2D_class::width;
        script_file << '"';
        script_file << " height=";
        script_file << '"';
        script_file << map_2D_class::height;
        script_file << '"';
        script_file << ">";
        script_file << "\n";
        script_file << "  <data>";
        script_file << "\n";
        for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
        {
            script_file << "   <tile gid=";
            script_file << '"';
            script_file << ((map_2D_class::tile[tile_count].tile + map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].firstgid) - 1);
            script_file << '"';
            script_file << "/>";
            script_file << "\n";
        }
        script_file << "  </data>";
        script_file << "\n";
        script_file << " </layer>";
        script_file << "\n";
        script_file << " <layer name=";
        script_file << '"';
        script_file << "object";
        script_file << '"';
        script_file << " width=";
        script_file << '"';
        script_file << map_2D_class::width;
        script_file << '"';
        script_file << " height=";
        script_file << '"';
        script_file << map_2D_class::height;
        script_file << '"';
        script_file << ">";
        script_file << "\n";
        script_file << "  <data>";
        script_file << "\n";
        for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
        {
            script_file << "   <tile gid=";
            script_file << '"';
            script_file << ((map_2D_class::tile[tile_count].object + map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].firstgid) - 1);
            script_file << '"';
            script_file << "/>";
            script_file << "\n";
        }
        script_file << "  </data>";
        script_file << "\n";
        script_file << " </layer>";
        script_file << "\n";
        script_file << "</map>";
        script_file << "\n";
        script_file.close();
    }
};

map_2D_class::map_2D_class(void)
{
    map_2D_class::version                = 0.0f;
    map_2D_class::orientation            = "Unknown";
    map_2D_class::width                  = 0;
    map_2D_class::height                 = 0;
    map_2D_class::tilewidth              = 0;
    map_2D_class::tileheight             = 0;
    map_2D_class::number_of_tiles        = 0;
    map_2D_class::number_of_tilesets     = 0;
};

map_2D_class::~map_2D_class(void)
{
};

//-----------------------------------------------------------------------------------------------------------------

