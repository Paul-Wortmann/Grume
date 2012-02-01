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

#include "loader_obj.hpp"
#include "map_3D.hpp"
#include "game.hpp"
#include "misc.hpp"

extern game_type         game;

map_3D_class::map_3D_class(void)
{
    map_3D_class::x_rotate         = -40.0f;
    map_3D_class::y_rotate         =  0.0f;
    map_3D_class::z_rotate         =  0.0f;
    map_3D_class::position_x       =  0.0f;
    map_3D_class::position_y       =  0.0f;
    map_3D_class::position_z       =  0.0f;
    map_3D_class::render_surfaces  = true;
    map_3D_class::render_wireframe = true;
    int cell_num = 0;
    for(int cell_x = 0; cell_x < X_CELLS; cell_x++)
    {
        for(int cell_y = 0; cell_y < Y_CELLS; cell_y++)
        {
            map_3D_class::cell[cell_num].x = (MESH_X - (cell_x * CELL_SPACING)) + (cell_y * CELL_SPACING);
            map_3D_class::cell[cell_num].y = (MESH_Y - (cell_y * CELL_SPACING)) - (cell_x * CELL_SPACING);
            cell_num++;
        }
    }
    for(cell_num = 0; cell_num < NUM_CELLS; cell_num++)
    {
        map_3D_class::cell[cell_num].vertex[0].x = map_3D_class::cell[cell_num].x;
        map_3D_class::cell[cell_num].vertex[0].y = map_3D_class::cell[cell_num].y - CELL_SPACING;
        map_3D_class::cell[cell_num].vertex[0].z = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[1].x = map_3D_class::cell[cell_num].x - CELL_SPACING;
        map_3D_class::cell[cell_num].vertex[1].y = map_3D_class::cell[cell_num].y;
        map_3D_class::cell[cell_num].vertex[1].z = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[2].x = map_3D_class::cell[cell_num].x;
        map_3D_class::cell[cell_num].vertex[2].y = map_3D_class::cell[cell_num].y;
        map_3D_class::cell[cell_num].vertex[2].z = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[3].x = map_3D_class::cell[cell_num].x + CELL_SPACING;
        map_3D_class::cell[cell_num].vertex[3].y = map_3D_class::cell[cell_num].y;
        map_3D_class::cell[cell_num].vertex[3].z = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[4].x = map_3D_class::cell[cell_num].x;
        map_3D_class::cell[cell_num].vertex[4].y = map_3D_class::cell[cell_num].y + CELL_SPACING;
        map_3D_class::cell[cell_num].vertex[4].z = (random_double() / 20.0f) + 0.01f;
    }
    map_3D_class::fix_mesh();
}

map_3D_class::~map_3D_class(void)
{

}

void map_3D_class::fix_mesh(void)
{
    int cell_num = 0;
    int cell_2   = 0;
    for(int cell_x = 0; cell_x < X_CELLS; cell_x++)
    {
        for(int cell_y = 0; cell_y < Y_CELLS; cell_y++)
        {
            if (cell_num < NUM_CELLS-1)
            {
                map_3D_class::cell[cell_num].vertex[0].z = (map_3D_class::cell[cell_num + 1].vertex[1].z + map_3D_class::cell[cell_num].vertex[0].z) /2;
                map_3D_class::cell[cell_num].vertex[3].z = (map_3D_class::cell[cell_num + 1].vertex[4].z + map_3D_class::cell[cell_num].vertex[3].z) /2;
                map_3D_class::cell[cell_num + 1].vertex[1].z = map_3D_class::cell[cell_num].vertex[0].z ;
                map_3D_class::cell[cell_num + 1].vertex[4].z = map_3D_class::cell[cell_num].vertex[3].z;

                cell_2 = cell_num + X_CELLS;
                if (cell_2 < NUM_CELLS)
                {
                    //map_3D_class::cell[cell_num].vertex[1].z = (map_3D_class::cell[cell_2].vertex[4].z + map_3D_class::cell[cell_num].vertex[1].z) /2;
                    //map_3D_class::cell[cell_num].vertex[0].z = (map_3D_class::cell[cell_2].vertex[3].z + map_3D_class::cell[cell_num].vertex[0].z) /2;
                    map_3D_class::cell[cell_2].vertex[4].z = map_3D_class::cell[cell_num].vertex[1].z;
                    map_3D_class::cell[cell_2].vertex[3].z = map_3D_class::cell[cell_num].vertex[0].z;
                }
            }
            cell_num++;
        }
    }
    map_3D_class::cell[0].vertex[1].z = map_3D_class::cell[Y_CELLS+0].vertex[4].z; // fix first cell vertex 1
}

void map_3D_class::load(std::string file_name)
{

};


void map_3D_class::process(void)
{

}

void map_3D_class::set_height_color(float z_height)
{
    float height_color_r = 0.0f;
    float height_color_g = 0.0f;
    float height_color_b = 0.0f;
    z_height += 0.02f;
    height_color_r = z_height;
    z_height += 0.01f;
    z_height *= 30;
    if (z_height > 0.5f) height_color_g = z_height;
    if (z_height < 0.5f)
    {
        z_height  = 1.0f - z_height;
        height_color_b = (z_height * 2)/3;
    }
    else height_color_b = height_color_r;
    glColor3f (height_color_r,height_color_g,height_color_b);
}

void map_3D_class::draw(void)
{
    glPushMatrix();
    //glDisable(GL_DEPTH_TEST);
    //glDisable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, game.texture.mana_bar.frame[0].data);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

    glMatrixMode(GL_MODELVIEW_MATRIX);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glRotatef (map_3D_class::x_rotate, 1.0f, 0.0f, 0.0f);
    glRotatef (map_3D_class::y_rotate, 0.0f, 1.0f, 0.0f);
    glRotatef (map_3D_class::z_rotate, 0.0f, 0.0f, 1.0f);
	glTranslatef(map_3D_class::position_x,map_3D_class::position_y,map_3D_class::position_z);
    // A 4 B
    // 1 2 3
    // C 0 D
    for(int cell_num = 0; cell_num < NUM_CELLS; cell_num++)
    {
        if (map_3D_class::render_surfaces)
        {
    //----- A  ---
            glBegin (GL_TRIANGLES);
            set_height_color(map_3D_class::cell[cell_num].vertex[1].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[4].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
    //----- B  ---
            glBegin (GL_TRIANGLES);
            set_height_color(map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[3].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[4].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
    //----- C  ---
            glBegin (GL_TRIANGLES);
            set_height_color(map_3D_class::cell[cell_num].vertex[0].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[1].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
    //----- D  ---
            glBegin (GL_TRIANGLES);
            set_height_color(map_3D_class::cell[cell_num].vertex[0].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            set_height_color(map_3D_class::cell[cell_num].vertex[3].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glEnd ();
        }
        if (map_3D_class::render_wireframe)
        {
    //----- A  ---
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glEnd ();
    //----- B  ---
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
    //----- C  ---
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glEnd ();
    //----- D  ---
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glEnd ();
            glBegin (GL_LINES);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glColor3f (1.0f, 1.0f, 1.0f); glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glEnd ();
        }
    }
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
}

