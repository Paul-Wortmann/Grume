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

#ifndef MAP_2D_H
#define MAP_2D_H

#include "texture_manager.hpp"
#include "map_gen.hpp"

const float  MAP_SCROLL_SPEED    = 0.02f;
const float  TILE_SCALE_DEFAULT  = 200.0f;
const float  TILE_WIDTH          = (float)DEFAULT_FRAME_WIDTH  / TILE_SCALE_DEFAULT;
const float  TILE_HEIGHT         = (float)DEFAULT_FRAME_HEIGHT / TILE_SCALE_DEFAULT;
const float  TILE_WIDTH_HALF     = TILE_WIDTH/2.0f;
const float  TILE_HEIGHT_HALF    = TILE_HEIGHT/2.0f;

class map_2D_class
{
    public:
        void render(fmx_map_type *fmx_map_pointer);
        void process(fmx_map_type *fmx_map_pointer);
        void scroll_map(fmx_map_type *fmx_map_pointer, int x_dir, int y_dir);
        bool tile_visible(fmx_map_type *fmx_map_pointer, int layer_number, int tile_number);
        void center_on_tile(fmx_map_type *fmx_map_pointer, int tile_ID);
        void calculate_tile_positions(fmx_map_type *fmx_map_pointer);
        void calculate_tile_positions(fmx_map_type *fmx_map_pointer, float tile_width_half_specify,float tile_height_half_specify);
        int  mouse_over_tile(fmx_map_type *fmx_map_pointer);
        void apply_tileset(fmx_map_type *fmx_map_pointer, int pre_defined_tileset_value);
};

#endif //MAP_H_2D


