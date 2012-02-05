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
    map_3D_class::x_rotate         = -45.0f;
    map_3D_class::y_rotate         =   0.0f;
    map_3D_class::z_rotate         =   0.0f;
    map_3D_class::position_x       =   0.0f;
    map_3D_class::position_y       =   0.0f;
    map_3D_class::position_z       =   0.0f;
    map_3D_class::render_textured  = true;
    map_3D_class::render_surfaces  = true;
    map_3D_class::render_wireframe = true;
    int cell_num = 0;
    for(int cell_x = 0; cell_x < X_CELLS; cell_x++)
    {
        for(int cell_z = 0; cell_z < Z_CELLS; cell_z++)
        {
            map_3D_class::cell[cell_num].x = (MESH_X - (cell_x * CELL_SPACING)) + (cell_z * CELL_SPACING);
            map_3D_class::cell[cell_num].z = (MESH_Z - (cell_z * CELL_SPACING)) - (cell_x * CELL_SPACING);
            cell_num++;
        }
    }
    for(cell_num = 0; cell_num < MAX_CELLS; cell_num++)
    {
        map_3D_class::cell[cell_num].vertex[0].x = map_3D_class::cell[cell_num].x;
        map_3D_class::cell[cell_num].vertex[0].z = map_3D_class::cell[cell_num].z - CELL_SPACING;
        map_3D_class::cell[cell_num].vertex[1].x = map_3D_class::cell[cell_num].x - CELL_SPACING;
        map_3D_class::cell[cell_num].vertex[1].z = map_3D_class::cell[cell_num].z;
        map_3D_class::cell[cell_num].vertex[2].x = map_3D_class::cell[cell_num].x;
        map_3D_class::cell[cell_num].vertex[2].z = map_3D_class::cell[cell_num].z;
        map_3D_class::cell[cell_num].vertex[3].x = map_3D_class::cell[cell_num].x + CELL_SPACING;
        map_3D_class::cell[cell_num].vertex[3].z = map_3D_class::cell[cell_num].z;
        map_3D_class::cell[cell_num].vertex[4].x = map_3D_class::cell[cell_num].x;
        map_3D_class::cell[cell_num].vertex[4].z = map_3D_class::cell[cell_num].z + CELL_SPACING;
    }
    map_3D_class::mesh_height_generate_random();
}

map_3D_class::~map_3D_class(void)
{

}
void map_3D_class::mesh_height_generate_random(void)
{
    for(int cell_num = 0; cell_num < MAX_CELLS; cell_num++)
    {
        map_3D_class::cell[cell_num].vertex[0].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[1].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[2].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[3].y = (random_double() / 20.0f) + 0.01f;
        map_3D_class::cell[cell_num].vertex[4].y = (random_double() / 20.0f) + 0.01f;
    }
    map_3D_class::mesh_height_smooth();
}

void map_3D_class::mesh_height_generate_heightmap(int heightmap_reference_number)
{

}

void map_3D_class::mesh_height_smooth(void)
{
    int cell_num = 0;
    int cell_2   = 0;
    for(int cell_x = 0; cell_x < X_CELLS; cell_x++)
    {
        for(int cell_z = 0; cell_z < Z_CELLS; cell_z++)
        {
            if (cell_num < MAX_CELLS-1)
            {
                map_3D_class::cell[cell_num].vertex[0].y = (map_3D_class::cell[cell_num + 1].vertex[1].y + map_3D_class::cell[cell_num].vertex[0].y) /2;
                map_3D_class::cell[cell_num].vertex[3].y = (map_3D_class::cell[cell_num + 1].vertex[4].y + map_3D_class::cell[cell_num].vertex[3].y) /2;
                map_3D_class::cell[cell_num + 1].vertex[1].y = map_3D_class::cell[cell_num].vertex[0].y ;
                map_3D_class::cell[cell_num + 1].vertex[4].y = map_3D_class::cell[cell_num].vertex[3].y;

                cell_2 = cell_num + X_CELLS;
                if (cell_2 < MAX_CELLS)
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
}

void map_3D_class::load(std::string file_name)
{

};


void map_3D_class::process(void)
{
    if (game.core.io.mouse_y >=  0.99000) map_3D_class::scroll_map( 0, 1);
    if (game.core.io.mouse_y <= -0.99000) map_3D_class::scroll_map( 0,-1);
    if (game.core.io.mouse_x >=  0.99000) map_3D_class::scroll_map( 1, 0);
    if (game.core.io.mouse_x <= -0.99000) map_3D_class::scroll_map(-1, 0);

    game.player.gold = map_3D_class::mouse_over_cell();

};

void map_3D_class::scroll_map(int x_dir, int z_dir)
{
    float temp_x = x_dir * MAP_SCROLL_SPEED;
    float temp_z = z_dir * MAP_SCROLL_SPEED;
    for(int cell_count = 0; cell_count < MAX_CELLS; cell_count++)
    {
        map_3D_class::cell[cell_count].x -= temp_x;
        map_3D_class::cell[cell_count].z -= temp_z;
        map_3D_class::cell[cell_count].vertex[0].x = map_3D_class::cell[cell_count].x;
        map_3D_class::cell[cell_count].vertex[0].z = map_3D_class::cell[cell_count].z - CELL_SPACING;
        map_3D_class::cell[cell_count].vertex[1].x = map_3D_class::cell[cell_count].x - CELL_SPACING;
        map_3D_class::cell[cell_count].vertex[1].z = map_3D_class::cell[cell_count].z;
        map_3D_class::cell[cell_count].vertex[2].x = map_3D_class::cell[cell_count].x;
        map_3D_class::cell[cell_count].vertex[2].z = map_3D_class::cell[cell_count].z;
        map_3D_class::cell[cell_count].vertex[3].x = map_3D_class::cell[cell_count].x + CELL_SPACING;
        map_3D_class::cell[cell_count].vertex[3].z = map_3D_class::cell[cell_count].z;
        map_3D_class::cell[cell_count].vertex[4].x = map_3D_class::cell[cell_count].x;
        map_3D_class::cell[cell_count].vertex[4].z = map_3D_class::cell[cell_count].z + CELL_SPACING;
    }
};

int  map_3D_class::mouse_over_cell(void)
{
    int return_value = -1;
    for (int cell_count = 0; cell_count < MAX_CELLS; cell_count++)
    {
        if (map_3D_class::cell_visable(cell_count))
        {
            if (game.core.physics.point_in_diamond(map_3D_class::cell[cell_count].x,CELL_SPACING_HALF,map_3D_class::cell[cell_count].z,CELL_SPACING_HALF,game.core.io.mouse_x,game.core.io.mouse_y)) return_value = cell_count;
        }
    }
    return(return_value);
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
}

bool map_3D_class::cell_visable(int cell_number)
{
    if ((map_3D_class::cell[cell_number].x < ( 1.0f+CELL_SPACING))
    &&  (map_3D_class::cell[cell_number].x > (-1.0f-CELL_SPACING))
    /*
    &&  (map_3D_class::cell[cell_number].z < ( 1.0f+CELL_SPACING))
    &&  (map_3D_class::cell[cell_number].z > (-1.0f-CELL_SPACING))
        */
        ) return(true);
    else return(false);
}

void map_3D_class::draw(void)
{
    glPushMatrix();
    //glDisable(GL_DEPTH_TEST);
    //glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW_MATRIX);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
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
    for(int cell_num = 0; cell_num < MAX_CELLS; cell_num++)
    {
        // A 4 B
        // 1 2 3
        // C 0 D
        if ((map_3D_class::render_textured) && (map_3D_class::cell_visable(cell_num)))
        {
            glBegin (GL_TRIANGLES);
    //----- A   ---
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
    //----- B   ---
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
    //----- C   ---
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
    //----- D   ---
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
    //----- END ---
            glEnd ();
        }
        if ((map_3D_class::render_surfaces) && (map_3D_class::cell_visable(cell_num)))
        {
    //----- A  ---
            glBegin (GL_TRIANGLES);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[1].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[2].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[4].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
    //----- B  ---
            glBegin (GL_TRIANGLES);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[2].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[3].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[4].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
    //----- C  ---
            glBegin (GL_TRIANGLES);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[0].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[1].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[2].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
    //----- D  ---
            glBegin (GL_TRIANGLES);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[0].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[2].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            mesh_height_set_color(map_3D_class::cell[cell_num].vertex[3].y);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glEnd ();
        }
        if ((map_3D_class::render_wireframe) && (map_3D_class::cell_visable(cell_num)))
        {
    //----- A  ---
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glEnd ();
    //----- B  ---
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[4].x,map_3D_class::cell[cell_num].vertex[4].y,map_3D_class::cell[cell_num].vertex[4].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
    //----- C  ---
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[1].x,map_3D_class::cell[cell_num].vertex[1].y,map_3D_class::cell[cell_num].vertex[1].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glEnd ();
    //----- D  ---
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[2].x,map_3D_class::cell[cell_num].vertex[2].y,map_3D_class::cell[cell_num].vertex[2].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glEnd ();
            glBegin (GL_LINES);
            glVertex3f(map_3D_class::cell[cell_num].vertex[3].x,map_3D_class::cell[cell_num].vertex[3].y,map_3D_class::cell[cell_num].vertex[3].z);
            glVertex3f(map_3D_class::cell[cell_num].vertex[0].x,map_3D_class::cell[cell_num].vertex[0].y,map_3D_class::cell[cell_num].vertex[0].z);
            glEnd ();
        }
    }
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
}

