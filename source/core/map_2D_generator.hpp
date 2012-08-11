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

#ifndef MAP_2D_GENERATOR_H
#define MAP_2D_GENERATOR_H

#include "map_2D.hpp"

#define DUNGEON    1
#define CAVE       2
#define FOREST     3

struct tile_grid_location_type
{
    int    start_x;
    int    end_x;
    int    start_y;
    int    end_y;
};


class tile_grid_class
{
    private:
    public:
        int*                    tile_data;
        int                     number_of_tiles;
        int                     number_of_tiles_x;
        int                     number_of_tiles_y;
        tile_grid_location_type origin;
};

struct tile_type
{
    int          data;
    int          x;
    int          y;
};

struct map_type
{
    int          number_tiles;
    int          number_tiles_x;
    int          number_tiles_y;
    tile_type*   tile;
};

class map_2D_generator_class
{
    private:
    public:
        map_type map_populate_loot(map_type map_in, int loot_amount ,int loot_average);
        map_type map_populate_monsters(map_type map_in, int monster_max, int monster_difficulty);
        map_type map_populate(map_type map_in, int loot_amount ,int loot_average, int monster_max, int monster_difficulty);
        map_type map_generate(int size_x ,int size_y ,int type ,bool town);
        void     draw(map_type generated_map);
};

#endif //MAP_2D_GENERATOR_H






