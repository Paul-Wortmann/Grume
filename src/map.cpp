/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include "map.hpp"
#include "game.hpp"

extern game_type         game;

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

void draw(void)
{

};

void process(void)
{

};

void map_class::load(std::string file_name, int reference_id)
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
    map_class::reference_id = reference_id;
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
                        if(position_count > data_line.length()) temp_char = '>';
                    }
                    if (temp_string_key == "tileset")
                    {
                        map_class::tileset[tileset_count].number_of_tiles = ((map_class::tileset[tileset_count].width / map_class::tileset[tileset_count].tilewidth) * (map_class::tileset[tileset_count].height / map_class::tileset[tileset_count].tileheight));
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
                    while(position_count < data_line.length())
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
                            if(position_count > data_line.length()) temp_char = '"';
                        }
                        temp_char        = ' ';
                        while(temp_char != '"')
                        {
                            temp_char = data_line[position_count];
                            if(temp_char != '"') temp_string_value += temp_char;
                            position_count++;
                            if(position_count > data_line.length()) (temp_char = '"');
                        }
                        temp_string_data = temp_string_value.c_str();
                        temp_float_data  = atof(temp_string_value.c_str());
                        temp_int_data    = atoi(temp_string_value.c_str());
                        if (temp_int_data == 1) temp_bool_data = true;
                        else temp_bool_data = false;
                        if (temp_string_key == "map version")      map_data     = true;
                        if (temp_string_key == "tileset firstgid") tileset_data = true;
                        if (temp_string_key == "layer name")       layer_data   = true;
                        if (map_data)
                        {
                            if (temp_string_key == "map version") map_class::version     = temp_float_data;
                            if (temp_string_key == "orientation") map_class::orientation = temp_string_data;
                            if (temp_string_key == "width")       map_class::width       = temp_int_data;
                            if (temp_string_key == "height")      map_class::height      = temp_int_data;
                            if (temp_string_key == "tilewidth")   map_class::tileheight  = temp_int_data;
                            if (temp_string_key == "tileheight")  map_class::tileheight  = temp_int_data;
                            if (temp_string_key == "tileheight")  map_data               = false;
                        }
                        if (tileset_data)
                        {
                            if (temp_string_key == "tileset firstgid") map_class::tileset[tileset_count].firstgid     = temp_int_data;
                            if (temp_string_key == "name")             map_class::tileset[tileset_count].name         = temp_string_data;
                            if (temp_string_key == "tilewidth")        map_class::tileset[tileset_count].tilewidth    = temp_int_data;
                            if (temp_string_key == "tileheight")       map_class::tileset[tileset_count].tileheight   = temp_int_data;
                            if (temp_string_key == "image source")     map_class::tileset[tileset_count].image_source = temp_string_data;
                            if (temp_string_key == "width")            map_class::tileset[tileset_count].width        = temp_int_data;
                            if (temp_string_key == "height")           map_class::tileset[tileset_count].height       = temp_int_data;
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
                                if (collision_data) map_class::tile[tile_count].collision = temp_int_data;
                                if (object_data) map_class::tile[tile_count].object       = temp_int_data;
                                if (tile_data) map_class::tile[tile_count].tile           = temp_int_data;
                                tile_count++;
                            }
                        }
                    }
                }
            }
        }
        script_file.close();
    }
};

map_class::map_class(void)
{
    map_class::version     = 0.0f;
    map_class::orientation = "Unknown";
    map_class::width       = 0;
    map_class::height      = 0;
    map_class::tilewidth   = 0;
    map_class::tileheight  = 0;
};

map_class::~map_class(void)
{
};

//-----------------------------------------------------------------------------------------------------------------

