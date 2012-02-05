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
#include "../loader_obj.hpp"
#include "../misc.hpp"
#include "../game.hpp"

extern game_type         game;

map_3D_class::map_3D_class(void)
{
    map_3D_class::version             =  0.0f;
    map_3D_class::cell_spacing        =  0.1f;
    map_3D_class::cell_spacing_half   =  map_3D_class::cell_spacing / 2.0f;
    map_3D_class::number_of_cells_x   =  100;
    map_3D_class::number_of_cells_z   =  100;
    map_3D_class::number_of_cells     =  map_3D_class::number_of_cells_x * map_3D_class::number_of_cells_z;
    map_3D_class::x_rotate            = -45.0f;
    map_3D_class::y_rotate            =  0.0f;
    map_3D_class::z_rotate            =  0.0f;
    map_3D_class::position_x          =  0.0f;
    map_3D_class::position_y          =  0.0f;
    map_3D_class::position_z          =  0.0f;
    map_3D_class::render_textured     =  true;
    map_3D_class::render_surfaces     =  true;
    map_3D_class::render_wireframe    =  true;
};

map_3D_class::~map_3D_class(void)
{
};

void map_3D_class::load(std::string file_name)
{
    map_3D_class::cell = new cell_type[map_3D_class::number_of_cells+1];
    mesh_cell_positions_generate();
    map_3D_class::mesh_height_generate_random();
};

void map_3D_class::process(void)
{
    if (game.core.io.mouse_y >=  0.99000) map_3D_class::scroll_map( 0, 1);
    if (game.core.io.mouse_y <= -0.99000) map_3D_class::scroll_map( 0,-1);
    if (game.core.io.mouse_x >=  0.99000) map_3D_class::scroll_map( 1, 0);
    if (game.core.io.mouse_x <= -0.99000) map_3D_class::scroll_map(-1, 0);

    game.player.gold = map_3D_class::mouse_over_cell();
};

void map_3D_class::draw(void)
{
    glPushMatrix();
    //glDisable(GL_DEPTH_TEST);
    //glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW_MATRIX);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    //glDisable(GL_DEPTH_TEST);
    //glDepthRange(-2.0f,2.0f);
    glRotatef (map_3D_class::x_rotate, 1.0f, 0.0f, 0.0f);
    glRotatef (map_3D_class::y_rotate, 0.0f, 1.0f, 0.0f);
    glRotatef (map_3D_class::z_rotate, 0.0f, 0.0f, 1.0f);
	glTranslatef(map_3D_class::position_x,map_3D_class::position_y,map_3D_class::position_z);
    if (map_3D_class::render_textured)
    {
        glBindTexture( GL_TEXTURE_2D, game.texture.heightmap_001.frame[0].data);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
    }
    if (map_3D_class::render_wireframe)
    {
        glColor3f (1.0f, 1.0f, 1.0f);
    }
    for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
    {
        if (map_3D_class::render_textured)  // and if cell visible
        {
            //draw_texture(false,game.texture.heightmap_001.ref_number,map_3D_class::cell[cell_count].x,map_3D_class::cell[cell_count].y,map_3D_class::cell[cell_count].z,map_3D_class::cell_spacing,map_3D_class::cell_spacing);
/*
            glBegin (GL_QUADS);
                glVertex3f(map_3D_class::cell[cell_count].x - cell_spacing_half,map_3D_class::cell[cell_count].y,map_3D_class::cell[cell_count].z - cell_spacing_half);
                glVertex3f(map_3D_class::cell[cell_count].x + cell_spacing_half,map_3D_class::cell[cell_count].y,map_3D_class::cell[cell_count].z - cell_spacing_half);
                glVertex3f(map_3D_class::cell[cell_count].x + cell_spacing_half,map_3D_class::cell[cell_count].y,map_3D_class::cell[cell_count].z + cell_spacing_half);
                glVertex3f(map_3D_class::cell[cell_count].x - cell_spacing_half,map_3D_class::cell[cell_count].y,map_3D_class::cell[cell_count].z + cell_spacing_half);
            glEnd ();
*/
        }
        if (map_3D_class::render_surfaces)
        {

        }
        if (map_3D_class::render_wireframe)
        {
            glBegin (GL_LINES);
                glVertex3f(map_3D_class::cell[cell_count].vertex[0].x,map_3D_class::cell[cell_count].vertex[0].y,map_3D_class::cell[cell_count].vertex[0].z);
                glVertex3f(map_3D_class::cell[cell_count].vertex[1].x,map_3D_class::cell[cell_count].vertex[1].y,map_3D_class::cell[cell_count].vertex[1].z);
            glEnd ();
            glBegin (GL_LINES);
                glVertex3f(map_3D_class::cell[cell_count].vertex[1].x,map_3D_class::cell[cell_count].vertex[1].y,map_3D_class::cell[cell_count].vertex[1].z);
                glVertex3f(map_3D_class::cell[cell_count].vertex[2].x,map_3D_class::cell[cell_count].vertex[2].y,map_3D_class::cell[cell_count].vertex[2].z);
            glEnd ();
            glBegin (GL_LINES);
                glVertex3f(map_3D_class::cell[cell_count].vertex[2].x,map_3D_class::cell[cell_count].vertex[2].y,map_3D_class::cell[cell_count].vertex[2].z);
                glVertex3f(map_3D_class::cell[cell_count].vertex[3].x,map_3D_class::cell[cell_count].vertex[3].y,map_3D_class::cell[cell_count].vertex[3].z);
            glEnd ();
            glBegin (GL_LINES);
                glVertex3f(map_3D_class::cell[cell_count].vertex[3].x,map_3D_class::cell[cell_count].vertex[3].y,map_3D_class::cell[cell_count].vertex[3].z);
                glVertex3f(map_3D_class::cell[cell_count].vertex[0].x,map_3D_class::cell[cell_count].vertex[0].y,map_3D_class::cell[cell_count].vertex[0].z);
            glEnd ();
        }
    }
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
};

void map_3D_class::mesh_cell_positions_generate(void)
{
    float start_x  = 0.0f;
    float start_z  = 0.0f ;
    int cell_count = 0;
    for(int x_count = 0; x_count < map_3D_class::number_of_cells_x; x_count++)
    {
        for(int z_count = 0; z_count < map_3D_class::number_of_cells_z; z_count++)
        {
            map_3D_class::cell[cell_count].x = (start_x - (x_count * map_3D_class::cell_spacing)) + (z_count * map_3D_class::cell_spacing);
            map_3D_class::cell[cell_count].z = (start_z - (z_count * map_3D_class::cell_spacing)) - (x_count * map_3D_class::cell_spacing);
            map_3D_class::cell[cell_count].vertex[0].x = map_3D_class::cell[cell_count].x;
            map_3D_class::cell[cell_count].vertex[0].y = 0.0f;
            map_3D_class::cell[cell_count].vertex[0].z = map_3D_class::cell[cell_count].z + map_3D_class::cell_spacing;
            map_3D_class::cell[cell_count].vertex[1].x = map_3D_class::cell[cell_count].x + map_3D_class::cell_spacing;
            map_3D_class::cell[cell_count].vertex[1].y = 0.0f;
            map_3D_class::cell[cell_count].vertex[1].z = map_3D_class::cell[cell_count].z;
            map_3D_class::cell[cell_count].vertex[2].x = map_3D_class::cell[cell_count].x;
            map_3D_class::cell[cell_count].vertex[2].y = 0.0f;
            map_3D_class::cell[cell_count].vertex[2].z = map_3D_class::cell[cell_count].z - map_3D_class::cell_spacing;
            map_3D_class::cell[cell_count].vertex[3].x = map_3D_class::cell[cell_count].x - map_3D_class::cell_spacing;
            map_3D_class::cell[cell_count].vertex[3].y = 0.0f;
            map_3D_class::cell[cell_count].vertex[3].z = map_3D_class::cell[cell_count].z;
            cell_count++;
        }
    }
};

void map_3D_class::mesh_height_generate_random(void)
{
    for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
    {
        map_3D_class::cell[cell_count].vertex[0].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_count].vertex[1].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_count].vertex[2].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_count].vertex[3].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_count].vertex[4].y = (random_double() / 20.0f) + 0.01f;
    }
    map_3D_class::mesh_height_smooth();
};

void map_3D_class::mesh_height_generate_heightmap(int heightmap_reference_number)
{
};

void map_3D_class::mesh_height_smooth(void)
{
    for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
    {
        if(cell_count < map_3D_class::number_of_cells_x) // top right edge
        {
            if((cell_count == 0) && (cell_count == map_3D_class::number_of_cells_x))
            {
                if(cell_count == 0)
                {

                }
                if(cell_count == map_3D_class::number_of_cells_x)
                {

                }

            }
            else
            {

            }

        }
        if(cell_count < map_3D_class::number_of_cells_x) // top right edge
        {

        }
    }
/*
    int cell_num = 0;
    int cell_2   = 0;
    for(int cell_x = 0; cell_x < map_3D_class::number_of_cells_x; cell_x++)
    {
        for(int cell_z = 0; cell_z < map_3D_class::number_of_cells_z; cell_z++)
        {
            if (cell_num < map_3D_class::number_of_cells-1)
            {
                map_3D_class::cell[cell_num].vertex[0].y = (map_3D_class::cell[cell_num + 1].vertex[1].y + map_3D_class::cell[cell_num].vertex[0].y) /2;
                map_3D_class::cell[cell_num].vertex[3].y = (map_3D_class::cell[cell_num + 1].vertex[4].y + map_3D_class::cell[cell_num].vertex[3].y) /2;
                map_3D_class::cell[cell_num + 1].vertex[1].y = map_3D_class::cell[cell_num].vertex[0].y ;
                map_3D_class::cell[cell_num + 1].vertex[4].y = map_3D_class::cell[cell_num].vertex[3].y;

                cell_2 = cell_num + map_3D_class::number_of_cells_x;
                if (cell_2 < map_3D_class::number_of_cells)
                {
                    //map_3D_class::cell[cell_num].vertex[1].y = (map_3D_class::cell[cell_2].vertex[4].y + map_3D_class::cell[cell_num].vertex[1].y) /2;
                    //map_3D_class::cell[cell_num].vertex[0].y = (map_3D_class::cell[cell_2].vertex[3].y + map_3D_class::cell[cell_num].vertex[0].y) /2;
                    map_3D_class::cell[cell_2].vertex[4].y = map_3D_class::cell[cell_num].vertex[1].y;
                    map_3D_class::cell[cell_2].vertex[3].y = map_3D_class::cell[cell_num].vertex[0].y;
                }
            }
            cell_num++;
        }
    }
    map_3D_class::cell[0].vertex[1].y = map_3D_class::cell[Z_CELLS+0].vertex[4].y; // fix first cell vertex 1
*/
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

