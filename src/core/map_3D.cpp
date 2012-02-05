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
#include "map_3D.hpp"
#include "../game.hpp"
#include "textures.hpp"

extern game_type         game;

map_3D_class::map_3D_class(void)
{
    map_3D_class::number_of_cells  = 0;
    version             = 0.0f;
    cell_spacing        = 0.05f;
    number_of_cells     = 0;
    number_of_cells_x   = 0;
    number_of_cells_y   = 0;
    x_rotate            = 0.0f;
    y_rotate            = 0.0f;
    z_rotate            = 0.0f;
    position_x          = 0.0f;
    position_y          = 0.0f;
    position_z          = 0.0f;
    render_textured     = false;
    render_surfaces     = false;
    render_wireframe    = true;

};

map_3D_class::~map_3D_class(void)
{
};

void map_3D_class::load(std::string file_name)
{
};

void map_3D_class::process(void)
{
};

void map_3D_class::draw(void)
{
};

void map_3D_class::mesh_height_generate_random(void)
{
};

void map_3D_class::mesh_height_generate_heightmap(int heightmap_reference_number)
{
};

void map_3D_class::mesh_height_smooth(void)
{
};

void map_3D_class::mesh_height_set_color(float y_height)
{
};

void map_3D_class::scroll_map(int x_dir, int z_dir)
{
};

int  map_3D_class::mouse_over_cell(void)
{
};

bool map_3D_class::cell_visable(int cell_number)
{
};


//-----------------------------------------------------------------------------------------------------------------

