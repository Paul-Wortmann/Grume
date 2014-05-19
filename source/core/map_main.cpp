/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <physfs.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "map_main.hpp"
#include "../game/game.hpp"
#include "misc.hpp"

extern game_class         game;

void map_load(map_type* map_pointer, std::string file_name)
{
    game.core.log.write("Loading map file (new xml 3D) -> ",file_name);

    map_pointer->info.environment_name = "not set";
    map_pointer->info.name             = "not set";
    map_pointer->info.number_of_tiles  = 0;
    map_pointer->info.rotation.x       = -45.0f;
    map_pointer->info.rotation.y       = 0.0f;
    map_pointer->info.rotation.z       = 0.0f;
    map_pointer->info.position.x       = 0.0f;
    map_pointer->info.position.y       = 0.0f;
    map_pointer->info.position.z       = 0.0f;
    map_pointer->info.size.x           = 0;
    map_pointer->info.size.y           = 0;
    map_pointer->info.tile_size        = DEFAULT_TILE_SIZE;
    map_pointer->info.version          = 0.0f;
    map_pointer->info.version_required = 0.0f;

    if (PHYSFS_exists(file_name.c_str()))
    {
        PHYSFS_openRead(file_name.c_str());
        PHYSFS_File *file_pointer = NULL;
        file_pointer = PHYSFS_openRead(file_name.c_str());
        if (file_pointer)
        {
            bool           tile_layer         = false;
            bool           object_layer       = false;
            int            tile_layer_count   = 0;
            int            object_layer_count = 0;
            float          temp_float_data;
            int            temp_int_data;
            std::string    temp_string_data;
            std::string    temp_string_key;
            std::string    temp_string_value;
            std::string    data_line;
            int            position_count  = 0;
            char           temp_char       = ' ';
            bool           eof_found       = false;
            char          *char_buffer     = new char[2];
            eof_found                      = false;
            while (!eof_found)
            {
                data_line = "";
                bool endl_found = false;
                while (!endl_found)
                {
                    PHYSFS_read(file_pointer, char_buffer, 1, 1);
                    if (char_buffer[0] < 32) endl_found = true;
                    eof_found = PHYSFS_eof(file_pointer);
                    if (eof_found) endl_found = true;
                    if ((!endl_found)&&(!eof_found)) data_line += char_buffer[0];
                }
                position_count = 0;
                if((data_line[position_count] != '<') && (data_line.length() > 2))
                {
                    temp_char = ' ';
                    while ((temp_char != '<') && (position_count < (int)data_line.length()))
                    {
                        temp_char = data_line[position_count];
                        position_count++;
                    }
                    position_count--;
                }
                if((data_line[position_count] == '<') && (data_line.length() > 2))
                {
                    position_count++;
                    while(position_count < (int)data_line.length())
                    {
                        temp_char         = ' ';
                        temp_string_key   = "";
                        temp_string_value = "";
                        while ((temp_char != '>') && (position_count < (int)data_line.length()))
                        {
                            temp_char = data_line[position_count];
                            if (temp_char != '>') temp_string_key += temp_char;
                            position_count++;
                        }
                        while ((temp_char != '<') && (position_count < (int)data_line.length()))
                        {
                            temp_char = data_line[position_count];
                            if (temp_char != '<') temp_string_value += temp_char;
                            position_count++;
                        }
                        temp_string_data    = temp_string_value.c_str();
                        temp_float_data     = atof(temp_string_value.c_str());
                        temp_int_data       = atoi(temp_string_value.c_str());
                        if (temp_string_key == "version")      map_pointer->info.version          = temp_float_data;
                        if (temp_string_key == "game_version") map_pointer->info.version_required = temp_float_data;
                        if (temp_string_key == "name")         map_pointer->info.name             = temp_string_data;
                        if (temp_string_key == "environment")  map_pointer->info.environment_name = temp_string_data;
                        if (temp_string_key == "environment")  map_pointer->environment           = game.map_environment_manager.add_map_environment(map_pointer->info.environment_name.c_str());
                        if (temp_string_key == "size_x")       map_pointer->info.size.x           = temp_int_data;
                        if (temp_string_key == "size_y")       map_pointer->info.size.y           = temp_int_data;
                        if (temp_string_key == "size_y")
                        {
                            map_pointer->info.number_of_tiles = map_pointer->info.size.x * map_pointer->info.size.y;
                            map_pointer->tile                 = new map_tile_type[map_pointer->info.number_of_tiles+1];
                        }
                        if (temp_string_key == "tile_layer")
                        {
                            tile_layer   = true;
                            object_layer = false;
                        }
                        if (temp_string_key == "object_layer")
                        {
                            tile_layer   = false;
                            object_layer = true;
                        }
                        if (temp_string_key == "id")
                        {
                            if (tile_layer)
                            {
                                map_pointer->tile[tile_layer_count].texture = temp_int_data;
                                tile_layer_count++;
                            }
                            if (object_layer)
                            {
                                map_pointer->tile[object_layer_count].object = temp_int_data;
                                object_layer_count++;
                            }
                        }
                    }
                }
            }
            map_generate_tile_positions(map_pointer);
            map_center_on_tile(map_pointer,(((map_pointer->info.size.y/2)*map_pointer->info.size.x) + (map_pointer->info.size.x/2)));
            if (map_pointer->environment->number_of_load_screens > 0)
            {
                if (map_pointer->environment->number_of_load_screens > 1)
                {
                    game.texture_manager.draw(map_pointer->environment->texture_load_screen[random(map_pointer->environment->number_of_load_screens)].data,false,0.0f,0.0f,0.0f,2.0f,20.f);
                }
                else
                {
                    game.texture_manager.draw(map_pointer->environment->texture_load_screen[0].data,false,0.0f,0.0f,0.0f,2.0f,20.f);
                }
            }
            if (map_pointer->environment->number_of_musics > 0)
            {
                if (map_pointer->environment->number_of_musics > 1)
                {
                    game.music_manager.play(map_pointer->environment->music[random(map_pointer->environment->number_of_load_screens)].data);
                }
                else
                {
                    game.music_manager.play(map_pointer->environment->music[0].data);
                }
            }
            for (int tile_count = 0; tile_count < map_pointer->info.number_of_tiles; tile_count++)
            {
                if (map_pointer->tile[tile_count].texture > map_pointer->environment->number_of_textures_floor) map_pointer->tile[tile_count].texture = map_pointer->environment->number_of_textures_floor;
                if (map_pointer->tile[tile_count].texture < 0) map_pointer->tile[tile_count].texture = random(map_pointer->environment->number_of_textures_floor);
            }
            if (file_pointer) PHYSFS_close(file_pointer);
        }
        else
        {
            game.core.log.write("Fail -> PhysicsFS unable to open file - ",file_name.c_str());
        }
    }
    else
    {
        game.core.log.write("Fail -> PhysicsFS unable to find file - ",file_name.c_str());
    }
};

void map_save(map_type* map_pointer, std::string file_name)
{

};

void map_generate_tile_positions(map_type* map_pointer)
{
    float start_x    = 0.0f;
    float start_y    = 0.0f ;
    int   tile_count = 0;
    for(int x_count = 0; x_count < map_pointer->info.size.x; x_count++)
    {
        for(int y_count = 0; y_count < map_pointer->info.size.y; y_count++)
        {
            map_pointer->tile[tile_count].position.x   = (start_x - (x_count * map_pointer->info.tile_size)) + (y_count * map_pointer->info.tile_size);
            map_pointer->tile[tile_count].position.y   = (start_y - (y_count * map_pointer->info.tile_size)) - (x_count * map_pointer->info.tile_size);
            map_pointer->tile[tile_count].vertex[0].x  = map_pointer->tile[tile_count].position.x;
            map_pointer->tile[tile_count].vertex[0].y  = map_pointer->tile[tile_count].position.y + map_pointer->info.tile_size;
            map_pointer->tile[tile_count].vertex[0].z  = 0.0f;
            map_pointer->tile[tile_count].vertex[1].x  = map_pointer->tile[tile_count].position.x + map_pointer->info.tile_size;
            map_pointer->tile[tile_count].vertex[1].y  = map_pointer->tile[tile_count].position.y;
            map_pointer->tile[tile_count].vertex[1].z  = 0.0f;
            map_pointer->tile[tile_count].vertex[2].x  = map_pointer->tile[tile_count].position.x;
            map_pointer->tile[tile_count].vertex[2].y  = map_pointer->tile[tile_count].position.y - map_pointer->info.tile_size;
            map_pointer->tile[tile_count].vertex[2].z  = 0.0f;
            map_pointer->tile[tile_count].vertex[3].x  = map_pointer->tile[tile_count].position.x - map_pointer->info.tile_size;
            map_pointer->tile[tile_count].vertex[3].y  = map_pointer->tile[tile_count].position.y;
            map_pointer->tile[tile_count].vertex[3].z  = 0.0f;
            tile_count++;
        }
    }
}

void map_scroll(map_type* map_pointer,int x_dir, int y_dir)
{
    if (game.core.io.mouse_in_window)
    {
        float x_scroll_delta = MAP_SCROLL_SPEED;
        float y_scroll_delta = MAP_SCROLL_SPEED + (MAP_SCROLL_SPEED * (game.core.config.display_resolution_x/game.core.config.display_resolution_y));

        if (((map_pointer->info.position.x + x_dir) > (-2.0f+x_scroll_delta)) && ((map_pointer->info.position.x + x_dir) < 2.0f-x_scroll_delta)) map_pointer->info.position.x += x_dir * x_scroll_delta;
        if (((map_pointer->info.position.y + y_dir) > (-2.0f+y_scroll_delta)) && ((map_pointer->info.position.y + y_dir) < 2.0f-y_scroll_delta)) map_pointer->info.position.y += y_dir * y_scroll_delta;
    }
}

bool map_tile_visable(map_type* map_pointer,int tile_count)
{
    if ((map_pointer->tile[tile_count].position.x < ( 2.0f+DEFAULT_TILE_SIZE-map_pointer->info.position.x))
    &&  (map_pointer->tile[tile_count].position.x > (-2.0f-DEFAULT_TILE_SIZE-map_pointer->info.position.x))
    &&  (map_pointer->tile[tile_count].position.y < ( 2.0f+DEFAULT_TILE_SIZE-map_pointer->info.position.y))
    &&  (map_pointer->tile[tile_count].position.y > (-2.0f-DEFAULT_TILE_SIZE-map_pointer->info.position.y))) return(true);
    else return(false);
}

int  map_mouse_over_tile(map_type* map_pointer)
{
    int return_value = -1;
    for (int tile_count = 0; tile_count < map_pointer->info.number_of_tiles; tile_count++)
    {
        if (map_tile_visable(map_pointer,tile_count))
        {
            if (game.core.physics.point_in_diamond(map_pointer->tile[tile_count].position.x,DEFAULT_TILE_SIZE_HALF,map_pointer->tile[tile_count].position.y,DEFAULT_TILE_SIZE_HALF,game.core.io.mouse_x,game.core.io.mouse_y)) return_value = tile_count;
        }
    }
    return(return_value);
}

void map_process(map_type* map_pointer)
{
    if ((game.core.io.mouse_y >=  0.99000) || (game.core.io.up))    map_scroll(map_pointer, 0,-1);
    if ((game.core.io.mouse_y <= -0.99000) || (game.core.io.down))  map_scroll(map_pointer, 0, 1);
    if ((game.core.io.mouse_x <= -0.99000) || (game.core.io.left))  map_scroll(map_pointer, 1, 0);
    if ((game.core.io.mouse_x >=  0.99000) || (game.core.io.right)) map_scroll(map_pointer,-1, 0);
};

void map_center_on_tile(map_type* map_pointer, int tile_ID)
{
    float temp_x    = map_pointer->tile[tile_ID].position.x;
    float temp_y    = map_pointer->tile[tile_ID].position.y;
    for(int tile_count = 0; tile_count <  map_pointer->info.number_of_tiles; tile_count++)
    {
        map_pointer->tile[tile_count].position.y -= temp_y;
        map_pointer->tile[tile_count].vertex[0].x  = map_pointer->tile[tile_count].position.x;
        map_pointer->tile[tile_count].vertex[0].y  = map_pointer->tile[tile_count].position.y + map_pointer->info.tile_size;
        map_pointer->tile[tile_count].vertex[0].z  = 0.0f;
        map_pointer->tile[tile_count].vertex[1].x  = map_pointer->tile[tile_count].position.x + map_pointer->info.tile_size;
        map_pointer->tile[tile_count].vertex[1].y  = map_pointer->tile[tile_count].position.y;
        map_pointer->tile[tile_count].vertex[1].z  = 0.0f;
        map_pointer->tile[tile_count].vertex[2].x  = map_pointer->tile[tile_count].position.x;
        map_pointer->tile[tile_count].vertex[2].y  = map_pointer->tile[tile_count].position.y - map_pointer->info.tile_size;
        map_pointer->tile[tile_count].vertex[2].z  = 0.0f;
        map_pointer->tile[tile_count].vertex[3].x  = map_pointer->tile[tile_count].position.x - map_pointer->info.tile_size;
        map_pointer->tile[tile_count].vertex[3].y  = map_pointer->tile[tile_count].position.y;
        map_pointer->tile[tile_count].vertex[3].z  = 0.0f;
    }
};

void map_render(map_type* map_pointer)
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthRange(-2.0f,2.0f);
    glRotatef (map_pointer->info.rotation.x, 1.0f, 0.0f, 0.0f);
    glRotatef (map_pointer->info.rotation.y, 0.0f, 1.0f, 0.0f);
    glRotatef (map_pointer->info.rotation.z, 0.0f, 0.0f, 1.0f);
	glTranslatef(map_pointer->info.position.x,map_pointer->info.position.y,map_pointer->info.position.z);
    //if (map_pointer->info.tile_visable(tile_count))
    {
        glMatrixMode(GL_MODELVIEW_MATRIX);
        //ARB_multitexture_supported = true; need for bump mapping specular etc...
        glBindTexture(GL_TEXTURE_2D, map_pointer->environment->texture_floor[1].data->data.frame[0].data);
        for (int tile_count = 0; tile_count < map_pointer->info.number_of_tiles; tile_count++)
        {
            glBegin (GL_QUADS);
                glTexCoord2i( 0, 1);glVertex3f(map_pointer->tile[tile_count].vertex[0].x,map_pointer->tile[tile_count].vertex[0].y,map_pointer->tile[tile_count].vertex[0].z);
                glTexCoord2i( 0, 0);glVertex3f(map_pointer->tile[tile_count].vertex[1].x,map_pointer->tile[tile_count].vertex[1].y,map_pointer->tile[tile_count].vertex[1].z);
                glTexCoord2i( 1, 0);glVertex3f(map_pointer->tile[tile_count].vertex[2].x,map_pointer->tile[tile_count].vertex[2].y,map_pointer->tile[tile_count].vertex[2].z);
                glTexCoord2i( 1, 1);glVertex3f(map_pointer->tile[tile_count].vertex[3].x,map_pointer->tile[tile_count].vertex[3].y,map_pointer->tile[tile_count].vertex[3].z);
            glEnd ();
        }
    }
    glDisable(GL_DEPTH_TEST);
    glPopMatrix();
}
