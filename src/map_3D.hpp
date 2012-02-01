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

#include <string>
#include "core/graphics.hpp"

const int   RAND_SEED      = 20;
const int   X_CELLS        = 100;
const int   Y_CELLS        = 100;
const int   NUM_CELLS      = (X_CELLS * Y_CELLS);
const float CELL_SPACING   = 0.05;
const float MESH_X         = 0.0f;
const float MESH_Y         = 0.0f + (CELL_SPACING * Y_CELLS) - CELL_SPACING;

struct cell_type
{
    float x;
    float y;
    vertex_type vertex[5];
};

class map_3D_class
{
    public:
        float              x_rotate;
        float              y_rotate;
        float              z_rotate;
        float              position_x;
        float              position_y;
        float              position_z;
        bool               render_surfaces;
        bool               render_wireframe;
        cell_type cell[NUM_CELLS];
        map_3D_class(void);
       ~map_3D_class(void);
        void               fix_mesh(void);
        void               load(std::string file_name);
        void               process(void);
        void               set_height_color(float z_height);
        void               draw(void);
};

#endif // MAP_3D_H

