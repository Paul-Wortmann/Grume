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
#include "map_gen_CA.hpp"

extern game_class    game;

void map_gen_CA (fmx_map_type *fmx_map_pointer)
{
    map_gen_base(fmx_map_pointer);
    flood_fill_type fill_data[fmx_map_pointer->data.number_of_tiles];
    bool ca_map_good               = false;
    int  ca_minimum_cave_size      = 60;
    int  ca_wall_stay              = 4;
    int  ca_wall_new               = 5;
    int  ca_iterations             = 4;
    int  ca_random_tile_number     = ((fmx_map_pointer->data.map_width * fmx_map_pointer->data.map_height) * ca_minimum_cave_size) / 100;
    fmx_tile_type temp_map[fmx_map_pointer->data.number_of_tiles];
    //------------------------------------------------------------
    while (!ca_map_good)
    {
        for (int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile  = TILE_FLOOR;
        }
        for (int tile_count = 0; tile_count < ca_random_tile_number; tile_count++)
        {
            fmx_map_pointer->layer[LAYER_FLOOR].tile[rand()%fmx_map_pointer->data.number_of_tiles].tile = TILE_WALL;
        }
        //add a 3x3 floored room to the middle of the map
        //this is for use later when checking for disjointed parts.
        {
            int middle_tile_number = ((fmx_map_pointer->data.number_of_tiles/2)+(fmx_map_pointer->data.map_width/2));
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number].tile                       = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number+1].tile                     = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number-1].tile                     = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number+fmx_map_pointer->data.map_width].tile   = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number+fmx_map_pointer->data.map_width+1].tile = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number+fmx_map_pointer->data.map_width-1].tile = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number-fmx_map_pointer->data.map_width].tile   = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number-fmx_map_pointer->data.map_width+1].tile = TILE_FLOOR;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[middle_tile_number-fmx_map_pointer->data.map_width-1].tile = TILE_FLOOR;
        }
        //fill perimeter with wall tiles
        for (int tile_count = 0; tile_count < fmx_map_pointer->data.map_width; tile_count++)
        {
            fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile                                = TILE_WALL;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[fmx_map_pointer->data.number_of_tiles-tile_count].tile  = TILE_WALL;
        }
        for (int tile_count = 0; tile_count < fmx_map_pointer->data.map_height; tile_count++)
        {
            fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count*fmx_map_pointer->data.map_width].tile                         = TILE_WALL;
            fmx_map_pointer->layer[LAYER_FLOOR].tile[(tile_count*fmx_map_pointer->data.map_width)+fmx_map_pointer->data.map_width-1].tile = TILE_WALL;
        }
        //smooth map, depending on neighboring tiles.
        for (int refine_count = 0; refine_count < ca_iterations; refine_count++)
        {
            int number_of_neighbors = 0;
            int temp_tile_number    = 0;
            for(int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
            {
                number_of_neighbors = 0;
                temp_tile_number    = 0;
                temp_map[tile_count].tile = TILE_FLOOR; // new tile is initially a floor tile
                temp_tile_number = tile_count+1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                temp_tile_number = tile_count-1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                temp_tile_number = tile_count+fmx_map_pointer->data.map_width;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                temp_tile_number = tile_count+fmx_map_pointer->data.map_width+1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                temp_tile_number = tile_count+fmx_map_pointer->data.map_width-1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                temp_tile_number = tile_count-fmx_map_pointer->data.map_width;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                temp_tile_number = tile_count-fmx_map_pointer->data.map_width+1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                temp_tile_number = tile_count-fmx_map_pointer->data.map_width-1;
                if ((temp_tile_number >= 0) && (temp_tile_number <= fmx_map_pointer->data.number_of_tiles) && (fmx_map_pointer->layer[LAYER_FLOOR].tile[temp_tile_number].tile == TILE_WALL)) number_of_neighbors++;
                if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile  == TILE_WALL)  && (number_of_neighbors >= ca_wall_stay)) temp_map[tile_count].tile = TILE_WALL; //Tile on temp map is a wall
                if ((fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile  == TILE_FLOOR) && (number_of_neighbors >= ca_wall_new )) temp_map[tile_count].tile = TILE_WALL; //Tile on temp map is a wall
            }
            //copy tiles from temp map to the main map.
            for(int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
            {
                fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile  = temp_map[tile_count].tile;
            }
            //fill perimeter with wall tiles
            for (int tile_count = 0; tile_count < fmx_map_pointer->data.map_width; tile_count++)
            {
                fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile                                        = TILE_WALL;
                fmx_map_pointer->layer[LAYER_FLOOR].tile[fmx_map_pointer->data.number_of_tiles-tile_count].tile  = TILE_WALL;
            }
            for (int tile_count = 0; tile_count < fmx_map_pointer->data.map_height; tile_count++)
            {
                fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count*fmx_map_pointer->data.map_width].tile                                     = TILE_WALL;
                fmx_map_pointer->layer[LAYER_FLOOR].tile[(tile_count*fmx_map_pointer->data.map_width)+fmx_map_pointer->data.map_width-1].tile = TILE_WALL;
            }
        }
        // find out if cave from the center is the largest part, and discard disjointed parts
        // if main cave is of adequate size, keep and return good, else regenerate.
        for(int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
        {
            fill_data[tile_count].tile_data      = fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile ;
            fill_data[tile_count].processed      = false;
            fill_data[tile_count].adjoining_tile = false;
        }
        // we already know these are floor tiles, so mark as part of the fill.
        int middle_tile_number = ((fmx_map_pointer->data.number_of_tiles/2)+(fmx_map_pointer->data.map_width/2));
        fill_data[middle_tile_number].processed                                        = true;
        fill_data[middle_tile_number+1].processed                                      = true;
        fill_data[middle_tile_number-1].processed                                      = true;
        fill_data[middle_tile_number+fmx_map_pointer->data.map_width].processed        = true;
        fill_data[middle_tile_number+fmx_map_pointer->data.map_width+1].processed      = true;
        fill_data[middle_tile_number+fmx_map_pointer->data.map_width-1].processed      = true;
        fill_data[middle_tile_number-fmx_map_pointer->data.map_width].processed        = true;
        fill_data[middle_tile_number-fmx_map_pointer->data.map_width+1].processed      = true;
        fill_data[middle_tile_number-fmx_map_pointer->data.map_width-1].processed      = true;
        fill_data[middle_tile_number].adjoining_tile                                   = true;
        fill_data[middle_tile_number+1].adjoining_tile                                 = true;
        fill_data[middle_tile_number-1].adjoining_tile                                 = true;
        fill_data[middle_tile_number+fmx_map_pointer->data.map_width].adjoining_tile   = true;
        fill_data[middle_tile_number+fmx_map_pointer->data.map_width+1].adjoining_tile = true;
        fill_data[middle_tile_number+fmx_map_pointer->data.map_width-1].adjoining_tile = true;
        fill_data[middle_tile_number-fmx_map_pointer->data.map_width].adjoining_tile   = true;
        fill_data[middle_tile_number-fmx_map_pointer->data.map_width+1].adjoining_tile = true;
        fill_data[middle_tile_number-fmx_map_pointer->data.map_width-1].adjoining_tile = true;
        int   number_found         = 0;
        int   temp_tile            = 0;
        bool  is_an_adjoining_tile = false;
        //while((!fill_data[0].processed) && (!fill_data[fmx_map_pointer->data.number_of_tiles-1].processed))
        for(int repeat_count = 0; repeat_count < ((fmx_map_pointer->data.map_width+fmx_map_pointer->data.map_height)/2); repeat_count++)
        {
            for(int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
            {
                // we don't need to check if temp_tile is going passed the borders as the borders are always walls
                is_an_adjoining_tile  = false;
                temp_tile = tile_count+1;
                if((temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                temp_tile = tile_count-1;
                if((temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                temp_tile = tile_count+fmx_map_pointer->data.map_width;
                if((temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                temp_tile = tile_count-fmx_map_pointer->data.map_width;
                if((temp_tile >= 0) && (temp_tile <= fmx_map_pointer->data.number_of_tiles))
                {
                    if (fill_data[temp_tile].adjoining_tile)
                    {
                        is_an_adjoining_tile = true;
                        number_found++;
                    }
                }
                fill_data[tile_count].processed = true;
                if ((is_an_adjoining_tile) and (fill_data[tile_count].tile_data == TILE_FLOOR)) fill_data[tile_count].adjoining_tile = true;
            }
        }
        ca_map_good = (number_found >= ((fmx_map_pointer->data.number_of_tiles*ca_minimum_cave_size)/100.0f)) ? true : false;
    }
    // write new values to array discarding disjointed tiles
    for (int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        if (fill_data[tile_count].adjoining_tile) fill_data[tile_count].tile_data = TILE_FLOOR;
        else fill_data[tile_count].tile_data = TILE_WALL;
    }
    // Push data from fill struct back to map.
    for(int tile_count = 0; tile_count < fmx_map_pointer->data.number_of_tiles; tile_count++)
    {
        fmx_map_pointer->layer[LAYER_FLOOR].tile[tile_count].tile  = fill_data[tile_count].tile_data;
    }
    map_gen_check_tiles(fmx_map_pointer);
};

void map_gen_CA (fmx_map_type *fmx_map_pointer, int seed)
{
    srand(seed);
    map_gen_CA(fmx_map_pointer);
};
