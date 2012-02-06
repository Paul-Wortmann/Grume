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

#ifndef MAP_3D_H
#define MAP_3D_H

#include "textures.hpp"
#include "graphics.hpp"
#include "map_2D.hpp"

struct cell_type
{
    float        x;
    float        y;
    float        z;
    vertex_type  vertex[4];
    int          tile_number;
    int          tileset_number;
};


class map_3D_class
{
    public:
        float              version;
        float              cell_spacing;
        float              cell_spacing_half;
        int                number_of_cells;
        int                number_of_cells_x;
        int                number_of_cells_z;
        float              x_rotate;
        float              y_rotate;
        float              z_rotate;
        float              position_x;
        float              position_y;
        float              position_z;
        bool               render_textured;
        bool               render_surfaces;
        bool               render_wireframe;
        cell_type*         cell;
        map_3D_class(void);
       ~map_3D_class(void);
        void               load(std::string file_name);
        void               process(void);
        void               draw(void);
        void               mesh_cell_positions_generate(void);
        void               mesh_height_generate_random(void);
        void               mesh_height_randomize(void);
        void               mesh_height_generate_heightmap(int heightmap_reference_number);
        void               mesh_height_smooth(void);
        void               mesh_height_set_color(float y_height);
        void               scroll_map(int x_dir, int z_dir);
        int                mouse_over_cell(void);
        bool               cell_visable(int cell_number);
};

#endif //MAP_H_3D


