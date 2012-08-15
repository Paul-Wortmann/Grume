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
#include "misc.hpp"

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
        if ((map_2D_class::tile_visable(tile_count)) && (map_2D_class::tile[tile_count].tile >= 0))
        {
            tile_offset_x = map_2D_class::tile[tile_count].pos_x;
            tile_offset_y = map_2D_class::tile[tile_count].pos_y;
            tile_offset_w = map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tilewidth  / (game.zoom.current*2);
            tile_offset_h = map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tileheight / (game.zoom.current*2);
            // Calculate for irregular sized tiles.
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
            map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].tile.draw(true,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].tile);
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
            map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].tile.draw(true,tile_offset_x,tile_offset_y,0.001f,tile_offset_w,tile_offset_h,0.0f,map_2D_class::tile[tile_count].object);
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
    for(int tile_count = 0; tile_count <  map_2D_class::number_of_tiles; tile_count++)
    {
        map_2D_class::tile[tile_count].pos_x -= temp_x;
        map_2D_class::tile[tile_count].pos_y -= temp_y;
    }
};

void map_2D_class::center_on_tile(int tile_ID)
{
    float temp_x = map_2D_class::tile[tile_ID].pos_x;
    float temp_y = map_2D_class::tile[tile_ID].pos_y;
    for(int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
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
    for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
    {
        map_2D_class::tile[tile_count].pos_x = start_x + (x_count * (TILE_WIDTH_HALF/2));
        map_2D_class::tile[tile_count].pos_y = start_y - (y_count * (TILE_HEIGHT_HALF/(DEFAULT_FRAME_HEIGHT/16)));
        x_count++;
        y_count++;
        if (x_count >= map_2D_class::width)
        {
            x_count = 0;
            start_x -= TILE_WIDTH_HALF/2;
        }
        if (y_count >= map_2D_class::height)
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
    for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
    {
        map_2D_class::tile[tile_count].pos_x = start_x + (x_count * (tile_width_half_specify/2));
        map_2D_class::tile[tile_count].pos_y = start_y - (y_count * (tile_height_half_specify/(DEFAULT_FRAME_HEIGHT/16)));
        x_count++;
        y_count++;
        if (x_count >= map_2D_class::width)
        {
            x_count = 0;
            start_x -= tile_width_half_specify/2;
        }
        if (y_count >= map_2D_class::height)
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
    game.core.log.file_write("Loading 2D map -> ",file_name);
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
    char         temp_char       = ' ';
    float        temp_float_data = 0.0f;
    int          temp_int_data   = 0;
    bool         temp_bool_data  = false;
    std::string  temp_string_data;
    std::string  temp_string_key;
    std::string  temp_string_value;
    std::string  data_line;
    std::fstream script_file(file_name.c_str(),std::ios::in|std::ios::binary);
//----------------------------- get sizes for dynamic arrays --------------------------------------------------------
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
                        tileset_count++;
                    }
                }
            }
        }
    }
    map_2D_class::number_of_tilesets = tileset_count + 1;
    map_2D_class::tileset = new tileset_class[map_2D_class::number_of_tilesets];
    script_file.clear();
    script_file.seekg(0, std::ios::beg);
    //----------------------------- read in data ------------------------------------------------------------------------
    position_count  = 0;
    position_start  = 0;
    map_data        = true;
    tileset_data    = false;
    layer_data      = false;
    collision_data  = false;
    object_data     = false;
    tile_data       = false;
    tileset_count   = 0;
    layer_count     = 0;
    tile_count      = 0;
    temp_char       = ' ';
    temp_float_data = 0.0f;
    temp_int_data   = 0;
    temp_bool_data  = false;
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
                            if (temp_string_key == "tileheight")  map_data                  = false;
                            if(!map_data)
                            {
                                map_2D_class::number_of_tiles = map_2D_class::width * map_2D_class::height;
                                map_2D_class::tile = new tile_class[map_2D_class::number_of_tiles];
                            }
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
        // Load the tile-sets into memory
        for (int tile_set_count = 0; tile_set_count < map_2D_class::number_of_tilesets-1; tile_set_count++)
        {
            int temp_tile_width  = map_2D_class::tileset[tile_set_count].tilewidth;
            int temp_tile_height = map_2D_class::tileset[tile_set_count].tileheight;
            temp_string_data = map_2D_class::tileset[tile_set_count].image_source;
            temp_string_data = game.core.file.path_remove(temp_string_data);
            temp_string_data = game.core.file.path_add(temp_string_data,"data/tilesets/");
            map_2D_class::tileset[tile_set_count].tile.load_spritesheet(temp_string_data,tile_set_count,temp_tile_width,temp_tile_height);
            game.core.log.file_write("Loaded tile-set -> " + temp_string_data + " - frames loaded -> ",map_2D_class::tileset[tile_set_count].number_of_tiles);
        }
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
            script_file << ((map_2D_class::tile[tile_count].tile + map_2D_class::tileset[map_2D_class::tile[tile_count].tile_tileset].firstgid));
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
            script_file << ((map_2D_class::tile[tile_count].object + map_2D_class::tileset[map_2D_class::tile[tile_count].object_tileset].firstgid));
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

//------------------------------ Random map generation below -----------------------------------------------------------------------------------

void map_2D_class::random_map(int tiles_x, int tiles_y, int type_of_map_to_generate)
{
    #define WALL  2
    #define FLOOR 1

    bool map_is_good               = false;
    int  minimum_cave_size         = 50; //%
    int  ca_wall_stay              = 4;
    int  ca_wall_new               = 5;
    int  ca_iterations             = 4;
    map_2D_class::number_of_tiles  = tiles_x*tiles_y;
    map_2D_class::width            = tiles_x;
    map_2D_class::height           = tiles_y;
    int  percent_random_tiles      = 40; // NB. randomly generated tiles can be generated on the same tile, thus reducing the percentage, adding a check is possible although slower.
    int  number_random_tiles       = (map_2D_class::number_of_tiles / 200) * percent_random_tiles * 3;
    map_2D_class::tile             = new tile_class[map_2D_class::number_of_tiles];
    tile_class* temp_map           = new tile_class[map_2D_class::number_of_tiles];
    // load test tile-set
    {
        map_2D_class::number_of_tilesets        = 1;
        map_2D_class::tileset                   = new tileset_class [map_2D_class::number_of_tilesets];
        map_2D_class::tilewidth                 = DEFAULT_FRAME_WIDTH;
        map_2D_class::tileheight                = DEFAULT_FRAME_HEIGHT;
        map_2D_class::tileset[0].firstgid       = 0;
        map_2D_class::tileset[0].image_source   = "data/tilesets/test_tileset.png";
        map_2D_class::tileset[0].tilewidth      = map_2D_class::tilewidth;
        map_2D_class::tileset[0].tileheight     = map_2D_class::tileheight;
        map_2D_class::tileset[0].tile.load_spritesheet(map_2D_class::tileset[0].image_source,0);
        map_2D_class::tileset[0].number_of_tiles = map_2D_class::tileset[0].tile.frame_max;
    }
    switch (type_of_map_to_generate)
    {
        case DUNGEON:
            for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
            {
                map_2D_class::tile[tile_count].tile = WALL;  //Fill map with wall tiles
            }
        break;
        case CAVE:
            map_is_good = false;
            while (!map_is_good)
            {
                for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
                {
                    map_2D_class::tile[tile_count].tile = FLOOR;  //Fill map with floor tiles
                }
                //add wall tiles randomly on map.
                for (int tile_count = 0; tile_count < number_random_tiles; tile_count++)
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
                struct flood_fill_type
                {
                    int  tile_data;
                    bool processed;
                    bool adjoining_tile;
                };
                flood_fill_type* fill_data;
                fill_data = new flood_fill_type[map_2D_class::number_of_tiles];
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
                for(int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
                {
                    if(fill_data[tile_count].adjoining_tile) map_2D_class::tile[tile_count].tile = FLOOR;
                    else map_2D_class::tile[tile_count].tile = WALL;
                }
                delete fill_data;

                if (number_found >= ((map_2D_class::number_of_tiles/100.0f)*minimum_cave_size)) map_is_good = true;
                else map_is_good = false;
            }
        break;
        case FOREST:
            for (int tile_count = 0; tile_count < map_2D_class::number_of_tiles; tile_count++)
            {
                map_2D_class::tile[tile_count].tile = FLOOR;  //Fill map with floor tiles
            }
        break;
    }
    map_2D_class::calculate_tile_positions();
    map_2D_class::center_on_tile((map_2D_class::number_of_tiles/2)+(map_2D_class::width/2));
};


//-----------------------------------------------------------------------------------------------------------------

