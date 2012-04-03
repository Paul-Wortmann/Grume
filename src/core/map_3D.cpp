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

#include <GL/gl.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "map_2D.hpp"
#include "map_3D.hpp"
#include "../game.hpp"
#include "textures.hpp"
#include "loader_obj.hpp"
#include "../misc.hpp"
#include "../game.hpp"

extern game_type         game;

map_3D_class::map_3D_class(void)
{
    map_3D_class::version             =  0.0f;
    map_3D_class::cell_spacing        =  0.05f;
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
    map_3D_class::render_textured     =  false;
    map_3D_class::render_surfaces     =  true;
    map_3D_class::render_wireframe    =  true;
    map_3D_class::render_water        =  true;
};

map_3D_class::~map_3D_class(void)
{
    delete map_3D_class::cell;
};

void map_3D_class::load(std::string file_name)
{
    map_3D_class::cell = new cell_type[map_3D_class::number_of_cells+1];
    map_3D_class::mesh_cell_positions_generate();
    map_3D_class::mesh_height_generate_heightmap("data/textures/heightmaps/heightmap_000.png");
    //map_3D_class::mesh_height_generate_random();
    //map_3D_class::mesh_height_randomize();
};

void map_3D_class::process(void)
{
    if (game.core.io.mouse_y >=  0.99000) map_3D_class::scroll_map( 0,-1);
    if (game.core.io.mouse_y <= -0.99000) map_3D_class::scroll_map( 0, 1);
    if (game.core.io.mouse_x >=  0.99000) map_3D_class::scroll_map(-1, 0);
    if (game.core.io.mouse_x <= -0.99000) map_3D_class::scroll_map( 1, 0);

    game.player.gold = map_3D_class::mouse_over_cell();
};

void map_3D_class::draw(void)
{
    bool set_texture = true;
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW_MATRIX);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthRange(-2.0f,2.0f);
    glRotatef (map_3D_class::x_rotate, 1.0f, 0.0f, 0.0f);
    glRotatef (map_3D_class::y_rotate, 0.0f, 1.0f, 0.0f);
    glRotatef (map_3D_class::z_rotate, 0.0f, 0.0f, 1.0f);
	glTranslatef(map_3D_class::position_x,map_3D_class::position_y,map_3D_class::position_z);
    set_texture = true;
    if (map_3D_class::render_textured)
    {
        glMatrixMode(GL_MODELVIEW_MATRIX);
        for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
        {
            if (set_texture)
            {
                glBindTexture( GL_TEXTURE_2D, game.texture.generic_grass.frame[0].data);
                glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
                glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
                glEnable(GL_TEXTURE_GEN_S);
                glEnable(GL_TEXTURE_GEN_T);
                set_texture = false;
            }
            if (map_3D_class::cell_visable(cell_count))
            {
                glBegin (GL_QUADS);
                    glTexCoord2i( 0, 1);glVertex3f(map_3D_class::cell[cell_count].vertex[0].x,map_3D_class::cell[cell_count].vertex[0].y,map_3D_class::cell[cell_count].vertex[0].z);
                    glTexCoord2i( 0, 0);glVertex3f(map_3D_class::cell[cell_count].vertex[1].x,map_3D_class::cell[cell_count].vertex[1].y,map_3D_class::cell[cell_count].vertex[1].z);
                    glTexCoord2i( 1, 0);glVertex3f(map_3D_class::cell[cell_count].vertex[2].x,map_3D_class::cell[cell_count].vertex[2].y,map_3D_class::cell[cell_count].vertex[2].z);
                    glTexCoord2i( 1, 1);glVertex3f(map_3D_class::cell[cell_count].vertex[3].x,map_3D_class::cell[cell_count].vertex[3].y,map_3D_class::cell[cell_count].vertex[3].z);
                glEnd ();
            }
            if (cell_count == 0) //(map_3D_class::cell[cell_count].object > 0)
            {
                game.model_3D.tree_fern.draw(map_3D_class::cell[0].x,map_3D_class::cell[0].y,map_3D_class::cell[0].z);
                set_texture = true;
            }
        }
    }
    set_texture = true;
    if (map_3D_class::render_surfaces)
    {
        for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
        {
            if (map_3D_class::cell_visable(cell_count))
            {
                if (set_texture)
                {
                    glBindTexture( GL_TEXTURE_2D, game.texture.generic_grass.frame[0].data);
                    set_texture = false;
                }
                glBegin (GL_QUADS);
                    mesh_height_set_color(map_3D_class::cell[cell_count].vertex[0].y);
                    glVertex3f(map_3D_class::cell[cell_count].vertex[0].x,map_3D_class::cell[cell_count].vertex[0].y,map_3D_class::cell[cell_count].vertex[0].z);
                    mesh_height_set_color(map_3D_class::cell[cell_count].vertex[1].y);
                    glVertex3f(map_3D_class::cell[cell_count].vertex[1].x,map_3D_class::cell[cell_count].vertex[1].y,map_3D_class::cell[cell_count].vertex[1].z);
                    mesh_height_set_color(map_3D_class::cell[cell_count].vertex[2].y);
                    glVertex3f(map_3D_class::cell[cell_count].vertex[2].x,map_3D_class::cell[cell_count].vertex[2].y,map_3D_class::cell[cell_count].vertex[2].z);
                    mesh_height_set_color(map_3D_class::cell[cell_count].vertex[3].y);
                    glVertex3f(map_3D_class::cell[cell_count].vertex[3].x,map_3D_class::cell[cell_count].vertex[3].y,map_3D_class::cell[cell_count].vertex[3].z);
                glEnd ();
                if (cell_count == 0) //(map_3D_class::cell[cell_count].object > 0)
                {
                    game.model_3D.tree_fern.draw    (map_3D_class::cell[0].vertex[0].x,map_3D_class::cell[0].vertex[0].y,map_3D_class::cell[0].z);
                    game.model_3D.tree_palm.draw    (map_3D_class::cell[2].vertex[0].x,map_3D_class::cell[2].vertex[0].y,map_3D_class::cell[2].z);
                    //game.model_3D.well.draw         (map_3D_class::cell[103].vertex[0].x,map_3D_class::cell[103].vertex[0].y,map_3D_class::cell[103].z);
                    game.model_3D.tombwoof.draw     (map_3D_class::cell[205].vertex[0].x,map_3D_class::cell[205].vertex[0].y,map_3D_class::cell[205].z);
                    game.model_3D.tomb.draw         (map_3D_class::cell[207].vertex[0].x,map_3D_class::cell[207].vertex[0].y,map_3D_class::cell[207].z);
                    //game.model_3D.cemetery_gate.draw(map_3D_class::cell[409].vertex[0].x,map_3D_class::cell[409].vertex[0].y,map_3D_class::cell[409].z);
                    set_texture = true;
                }
            }
        }
    }
    if (map_3D_class::render_wireframe)
    {
        glColor3f (1.0f, 1.0f, 1.0f);
        for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
        {
            if (map_3D_class::cell_visable(cell_count))
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
    }
    if (map_3D_class::render_water)
    {
        glBindTexture( GL_TEXTURE_2D, game.texture.generic_water.frame[0].data);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        glMatrixMode(GL_MODELVIEW_MATRIX);
        glBegin (GL_QUADS);
            glVertex3f(map_3D_class::cell[0].vertex[0].x,-0.1f,map_3D_class::cell[0].vertex[0].z);
            glVertex3f(map_3D_class::cell[map_3D_class::number_of_cells_x-1].vertex[1].x,-0.1f,map_3D_class::cell[map_3D_class::number_of_cells_x-1].vertex[1].z);
            glVertex3f(map_3D_class::cell[map_3D_class::number_of_cells-1].vertex[2].x,-0.1f,map_3D_class::cell[map_3D_class::number_of_cells-1].vertex[2].z);
            glVertex3f(map_3D_class::cell[map_3D_class::number_of_cells-map_3D_class::number_of_cells_x].vertex[3].x,-0.1f,map_3D_class::cell[map_3D_class::number_of_cells-map_3D_class::number_of_cells_x].vertex[3].z);
        glEnd ();
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
    }
    map_3D_class::mesh_height_smooth();
};

void map_3D_class::mesh_height_randomize(void)
{
    for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
    {
        map_3D_class::cell[cell_count].vertex[0].y += (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_count].vertex[1].y += (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_count].vertex[2].y += (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_count].vertex[3].y += (random_double() / 20.0f) + 0.01f;
    }
    map_3D_class::mesh_height_smooth();
};

void map_3D_class::mesh_height_generate_heightmap(std::string file_name)
{
    SDL_PixelFormat *pixel_format;
    Uint8            red          = 0;
    Uint8            green        = 0;
    Uint8            blue         = 0;
    Uint8            alpha        = 0;
    Uint32           temp_data    = 0;
    float            temp_value   = 0.0f;
    SDL_Surface     *temp_surface = NULL;
    if (temp_surface = IMG_Load(file_name.c_str()))
    {
        pixel_format = temp_surface->format;
        if(SDL_MUSTLOCK(temp_surface)) SDL_LockSurface(temp_surface);
        Uint32 *pixel = (Uint32*)temp_surface->pixels;
        if(SDL_MUSTLOCK(temp_surface)) SDL_UnlockSurface(temp_surface);
        for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
        {
            temp_data = pixel[cell_count] & pixel_format->Rmask;
            temp_data = temp_data >> pixel_format->Rshift;
            temp_data = temp_data << pixel_format->Rloss;
            red = (Uint8)temp_data;
            temp_data = pixel[cell_count] & pixel_format->Gmask;
            temp_data = temp_data >> pixel_format->Gshift;
            temp_data = temp_data << pixel_format->Gloss;
            green = (Uint8)temp_data;
            temp_data = pixel[cell_count] & pixel_format->Bmask;
            temp_data = temp_data >> pixel_format->Bshift;
            temp_data = temp_data << pixel_format->Bloss;
            blue = (Uint8)temp_data;
            temp_data = pixel[cell_count] & pixel_format->Amask;
            temp_data = temp_data >> pixel_format->Ashift;
            temp_data = temp_data << pixel_format->Aloss;
            alpha = (Uint8)temp_data;
            temp_value = float((((red+green+blue) / 768.0f) - 1.0f) / 4.0f);
            map_3D_class::cell[cell_count].vertex[0].y = temp_value;
            map_3D_class::cell[cell_count].vertex[1].y = temp_value;
            map_3D_class::cell[cell_count].vertex[2].y = temp_value;
            map_3D_class::cell[cell_count].vertex[3].y = temp_value;
        }
        if ( temp_surface ) SDL_FreeSurface( temp_surface );
    }
    else game.core.log.File_Write("Failed to load height map file -> ",file_name.c_str());
    map_3D_class::mesh_height_smooth();
};

void map_3D_class::mesh_height_smooth(void)
{
    for(int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
    {
        map_3D_class::cell[cell_count].vertex[1].y = map_3D_class::cell[cell_count+1].vertex[0].y;
        map_3D_class::cell[cell_count].vertex[2].y = map_3D_class::cell[cell_count+1].vertex[3].y;
        if(cell_count > map_3D_class::number_of_cells_x-1) // top right edge
        {
            map_3D_class::cell[cell_count].vertex[0].y = map_3D_class::cell[cell_count-map_3D_class::number_of_cells_x].vertex[3].y;
            map_3D_class::cell[cell_count].vertex[1].y = map_3D_class::cell[cell_count-map_3D_class::number_of_cells_x].vertex[2].y;
        }
    }
};

void map_3D_class::mesh_height_set_color(float y_height)
{
    float height_color_r = 0.0f;
    float height_color_g = 0.0f;
    float height_color_b = 0.0f;
    y_height += 0.02f;
    height_color_r = y_height;
    y_height += 0.01f;
    y_height *= 30;
    if (y_height > 0.5f) height_color_g = y_height;
    if (y_height < 0.5f)
    {
        y_height  = 1.0f - y_height;
        height_color_b = (y_height * 2)/3;
    }
    else height_color_b = height_color_r;
    glColor3f (height_color_r,height_color_g,height_color_b);
};

void map_3D_class::scroll_map(int x_dir, int z_dir)
{
    map_3D_class::position_x += x_dir * MAP_SCROLL_SPEED;
    map_3D_class::position_z += z_dir * MAP_SCROLL_SPEED;
};

int  map_3D_class::mouse_over_cell(void)
{
    int return_value = -1;
    for (int cell_count = 0; cell_count < map_3D_class::number_of_cells; cell_count++)
    {
        if (map_3D_class::cell_visable(cell_count))
        {
            if (game.core.physics.point_in_diamond(map_3D_class::cell[cell_count].x,map_3D_class::cell_spacing_half,map_3D_class::cell[cell_count].z,map_3D_class::cell_spacing_half,game.core.io.mouse_x,game.core.io.mouse_y)) return_value = cell_count;
        }
    }
    return(return_value);
};

bool map_3D_class::cell_visable(int cell_number)
{
    if ((map_3D_class::cell[cell_number].x < ( 2.0f+map_3D_class::cell_spacing-map_3D_class::position_x))
    &&  (map_3D_class::cell[cell_number].x > (-2.0f-map_3D_class::cell_spacing-map_3D_class::position_x))
    &&  (map_3D_class::cell[cell_number].z < ( 2.0f+map_3D_class::cell_spacing-map_3D_class::position_z))
    &&  (map_3D_class::cell[cell_number].z > (-2.0f-map_3D_class::cell_spacing-map_3D_class::position_z))) return(true);
    else return(false);

};


//-----------------------------------------------------------------------------------------------------------------

