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

# include "map_2D_generator.hpp"

map_type map_2D_generator_class::map_populate_loot(map_type map_in, int loot_amount ,int loot_average)
{
    map_type map_out;
    map_out = map_in;
    return(map_out);
};

map_type map_2D_generator_class::map_populate_monsters(map_type map_in, int monster_max, int monster_difficulty)
{
    map_type map_out;
    map_out = map_in;
    return(map_out);
};

map_type map_2D_generator_class::map_populate(map_type map_in, int loot_amount ,int loot_average, int monster_max, int monster_difficulty)
{
    map_type map_out;
    map_out = map_in;
    map_out = map_2D_generator_class::map_populate_monsters(map_out,100,1);
    map_out = map_2D_generator_class::map_populate_loot(map_out,100,1);
    return(map_out);
};

map_type map_2D_generator_class::map_generate(int size_x ,int size_y ,int type ,bool town)
{
    map_type temp_map;
    int number_tiles        = size_x*size_y;
    temp_map.number_tiles   = number_tiles;
    temp_map.number_tiles_x = size_x;
    temp_map.number_tiles_y = size_y;
    temp_map.tile           = new tile_type[number_tiles];
    switch (type)
    {
        case DUNGEON:
            for (int tile_count = 0; tile_count < number_tiles; tile_count++)
            {
                temp_map.tile[tile_count].data = 1;  //Fill map with wall tiles
            }
        break;
        case CAVE:
            for (int tile_count = 0; tile_count < number_tiles; tile_count++)
            {
                temp_map.tile[tile_count].data = 2;  //Fill map with floor tiles
            }
            //fill perimeter with wall tiles
            for (int tile_count = 0; tile_count < size_x; tile_count++)
            {
                temp_map.tile[tile_count].data              = 1;  //Fill with wall tiles
                temp_map.tile[number_tiles-tile_count].data = 1;  //Fill with wall tiles
            }
            for (int tile_count = 0; tile_count < size_y; tile_count++)
            {
                temp_map.tile[tile_count*size_x].data              = 1;  //Fill with wall tiles
                temp_map.tile[(tile_count*size_x)+size_x].data     = 1;  //Fill with wall tiles
            }
        break;
        case FOREST:
            for (int tile_count = 0; tile_count < number_tiles; tile_count++)
            {
                temp_map.tile[tile_count].data = 2;  //Fill map with floor tiles
            }
        break;
    }
    return(temp_map);
};

void map_2D_generator_class::draw(map_type generated_map)
{

};



/*
//-------------------------------------------------------------//
//| Random dungeon generation ideas                           |//
//-------------------------------------------------------------//
//possibly add a lava flow / river through map...add bridges where necessary.. (add first so rooms/towns are created around this feature)
//if (town) add town rooms to middle of the map.
//generate rooms and corridors()
//possibly (if not previously added) add a lava flow / river through map...add bridges where necessary..(added after rooms so the lava seams to have cut through the rooms etc...)
//use random floor tiles
//transform walls to correctly,use pattern matching for corners etc...
//alternatively also use pattern matching for adding other features, ie. randomly decide to add flame torches down long corridors...etc...
//if a room is isolated, possibly make it a secret room with loot (1% chance etc...)
//possibly have a key dropped before a locked door...

for (number_of_rooms)
{
    for (number_of_rooms)
    {
        //find rooms furtherest apart()
        //add stairs, portal, exit/ cave entrance etc...
    }
}
//add loot, mostly to rooms not on the shortest path from A-B
//add monsters mostly to rooms
//possibly add an elite / boss monster near the exit, just before the locked door...
*/

