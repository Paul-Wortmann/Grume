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

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "particles.hpp"
#include "../game.hpp"

extern  game_type         game;

void  particle_class::init(void)
{
    particle_class::active          = false;
    particle_class::pos_x           = 0.0f;
    particle_class::pos_y           = 0.0f;
    particle_class::pos_z           = 0.0f;
    particle_class::velocity_max    = 0.0f;
    particle_class::velocity_x      = 0.0f;
    particle_class::velocity_y      = 0.0f;
    particle_class::velocity_z      = 0.0f;
    particle_class::acceleration_x  = 0.0f;
    particle_class::acceleration_y  = 0.0f;
    particle_class::acceleration_z  = 0.0f;
    particle_class::direction       = 0.0f;
    particle_class::rotation_rate   = 0.0f;
    particle_class::rotation        = 0.0f;
    particle_class::force_x         = 0.0f;
    particle_class::force_y         = 0.0f;
    particle_class::force_z         = 0.0f;
    particle_class::color_r         = 1.0f;
    particle_class::color_g         = 1.0f;
    particle_class::color_b         = 1.0f;
    particle_class::TTL             = 1.0f;
    particle_class::TTL_rate        = 0.0025f;
};

void  particle_class::kill(void)
{
    particle_class::active          = false;
};

void  particle_class::process(void)
{
    if(particle_class::active)
    {
        particle_class::TTL -= particle_class::TTL_rate;
        if (particle_class::TTL < 0.0f) particle_class::active = false;
        if(particle_class::active)
        {
            if (particle_class::rotation_rate > 0.0f)
            {
                particle_class::rotation += particle_class::rotation_rate;
                if (particle_class::rotation > 360.0f) particle_class::rotation = 0.0f;
            }
            if (particle_class::rotation_rate < 0.0f)
            {
                particle_class::rotation += particle_class::rotation_rate;
                if (particle_class::rotation < 0.0f) particle_class::rotation = 360.0f;
            }
            particle_class::velocity_x += particle_class::acceleration_x;
            particle_class::velocity_y += particle_class::acceleration_y;
            particle_class::velocity_z += particle_class::acceleration_z;
            particle_class::velocity_x += particle_class::force_x;
            particle_class::velocity_y += particle_class::force_y;
            particle_class::velocity_z += particle_class::force_z;
            if (particle_class::velocity_x > particle_class::velocity_max   ) particle_class::velocity_x = particle_class::velocity_max;
            if (particle_class::velocity_x < particle_class::velocity_max*-1) particle_class::velocity_x = particle_class::velocity_max*-1;
            if (particle_class::velocity_y > particle_class::velocity_max   ) particle_class::velocity_y = particle_class::velocity_max;
            if (particle_class::velocity_y < particle_class::velocity_max*-1) particle_class::velocity_y = particle_class::velocity_max*-1;
            if (particle_class::velocity_z > particle_class::velocity_max   ) particle_class::velocity_z = particle_class::velocity_max;
            if (particle_class::velocity_z < particle_class::velocity_max*-1) particle_class::velocity_z = particle_class::velocity_max*-1;
            particle_class::pos_x       = game.core.physics.move_speed_angle_2D_x(particle_class::pos_x,particle_class::velocity_x,game.core.physics.degrees_to_radians(particle_class::direction));
            particle_class::pos_y       = game.core.physics.move_speed_angle_2D_y(particle_class::pos_y,particle_class::velocity_y,game.core.physics.degrees_to_radians(particle_class::direction));
            /*
            // uncomment to have particles move in a circle / blow in a direction.
            // can go the other direction if you change ++ to --
            particle_class::direction++; //  particle_class::direction += particle_class::direction_speed;
            if (particle_class::direction > 360) particle_class::direction = 0;
            */
        }
    }
};

void emitter_class::set_emitter_pos      (float x  , float y  , float z  )
{
    emitter_class::pos_x                 = x;
    emitter_class::pos_y                 = y;
    emitter_class::pos_z                 = z;
};

void emitter_class::set_emitter_state    (bool  active, bool always_on, int ttl)
{
    emitter_class::active                = active;
    emitter_class::always_on             = always_on;
    emitter_class::TTL                   = ttl;
};

void emitter_class::set_emitter_image    (int i_ref)
{
    emitter_class::image_reference       = i_ref;
};

void emitter_class::set_emitter_image    (int i_ref, float w  , float h  )
{
    emitter_class::image_reference       = i_ref;
    emitter_class::image_width           = w;
    emitter_class::image_height          = h;
};

void emitter_class::set_emitter_movement (float vm , float ax , float ay , float az , float dr , int   sr , float fx , float fy , float fz )
{
    emitter_class::velocity_max          = vm;
    emitter_class::acceleration_x        = ax;
    emitter_class::acceleration_y        = ay;
    emitter_class::acceleration_z        = az;
    emitter_class::direction             = dr;
    emitter_class::spray_radius          = sr;
    emitter_class::force_x               = fx;
    emitter_class::force_y               = fy;
    emitter_class::force_z               = fz;
};

void emitter_class::set_emitter_rotation(float r  , float rr )
{
    emitter_class::rotation              = r;
    emitter_class::rotation_rate         = rr;
};

void emitter_class::set_emitter_rates    (int   sf , int   sfc, float pr , int sq)
{
    emitter_class::spawn_frequency       = sf;
    emitter_class::spawn_frequency_count = sfc;
    emitter_class::particle_TTL_rate     = pr;
    emitter_class::spawn_quantity        = sq;
};

void emitter_class::set_emitter_color    (float csr, float csg, float csb, float cer, float ceg, float ceb)
{
    float pr = emitter_class::particle_TTL_rate;
    emitter_class::color_start_r         = csr;
    emitter_class::color_start_g         = csg;
    emitter_class::color_start_b         = csb;
    emitter_class::color_end_r           = cer;
    emitter_class::color_end_g           = ceg;
    emitter_class::color_end_b           = ceb;
    emitter_class::color_rate_r          = (csr - cer) / (1.0f / pr);
    emitter_class::color_rate_g          = (csg - ceg) / (1.0f / pr);
    emitter_class::color_rate_b          = (csb - ceb) / (1.0f / pr);
};

void emitter_class::set_emitter_velocity (float vx , float vy , float vz )
{
    emitter_class::velocity_x            = vx;
    emitter_class::velocity_y            = vy;
    emitter_class::velocity_z            = vz;
};

void emitter_class::set_emitter_size     (float sx , float sy , float sz )
{
    emitter_class::size_x = sx;
    emitter_class::size_y = sy;
    emitter_class::size_z = sz;
};

void  emitter_class::init(void)
{
    for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
    {
        emitter_class::particle[particle_count].init();
    }
    emitter_class::active                = false;
    emitter_class::always_on             = false;
    emitter_class::image_reference       = 0;
    emitter_class::image_width           = 0.0f;
    emitter_class::image_height          = 0.0f;
    emitter_class::pos_x                 = 0.0f;
    emitter_class::pos_y                 = 0.0f;
    emitter_class::pos_z                 = 0.0f;
    emitter_class::size_x                = 0.0f;
    emitter_class::size_y                = 0.0f;
    emitter_class::size_z                = 0.0f;
    emitter_class::velocity_max          = 0.0f;
    emitter_class::acceleration_x        = 0.0f;
    emitter_class::acceleration_y        = 0.0f;
    emitter_class::acceleration_z        = 0.0f;
    emitter_class::direction             = 0.0f;
    emitter_class::rotation_rate         = 0.0f;
    emitter_class::force_x               = 0.0f;
    emitter_class::force_y               = 0.0f;
    emitter_class::force_z               = 0.0f;
    emitter_class::color_start_r         = 0.0f;
    emitter_class::color_start_g         = 0.0f;
    emitter_class::color_start_b         = 0.0f;
    emitter_class::color_end_r           = 0.0f;
    emitter_class::color_end_g           = 0.0f;
    emitter_class::color_end_b           = 0.0f;
    emitter_class::spawn_frequency       = 0.0f;
    emitter_class::spawn_frequency_count = 0.0f;
    emitter_class::spawn_quantity        = 16;
    emitter_class::particle_TTL_rate     = 0.0f;
    emitter_class::color_rate_r          = 0.0f;
    emitter_class::color_rate_g          = 0.0f;
    emitter_class::color_rate_b          = 0.0f;
};

void  emitter_class::kill(void)
{
    for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
    {
        emitter_class::particle[particle_count].kill();
    }
    emitter_class::active          = false;
};


void  emitter_class::process(void)
{
    if (emitter_class::active)
    {
        if (!emitter_class::always_on)
        {
            emitter_class::TTL_count++;
            if (emitter_class::TTL_count > TTL) emitter_class::active = false;
            emitter_class::TTL_count = 0;
        }
        else emitter_class::active = true;
        emitter_class::spawn_frequency_count++;
        if (emitter_class::spawn_frequency_count > emitter_class::spawn_frequency)
        {
            emitter_class::spawn_frequency_count = 0;
            int spawned = emitter_class::spawn_quantity;
            if (emitter_class::active == false) spawned = 0;
            for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
            {
                if (spawned > 0)
                {
                    if (!emitter_class::particle[particle_count].active)
                    {
                        spawned--;
                        emitter_class::particle[particle_count].active         = true;
                        float rx = emitter_class::size_x;
                              rx = (rx*rand()/(RAND_MAX + 1.0)) - (rx/2);
                        float ry = emitter_class::size_y;
                              ry = (ry*rand()/(RAND_MAX + 1.0)) - (ry/2);
                        float rz = emitter_class::size_z;
                              rz = (rz*rand()/(RAND_MAX + 1.0)) - (rz/2);
                        emitter_class::particle[particle_count].rotation       = emitter_class::rotation_rate + ((rand()% 200)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].rotation_rate  = emitter_class::rotation_rate + ((rand()% 200)/10000); // add random!!! 1%?
                        if (rand()%100 > 50) emitter_class::particle[particle_count].rotation_rate *= -1;
                        emitter_class::particle[particle_count].pos_x          = emitter_class::pos_x + rx + ((rand()% 200)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].pos_y          = emitter_class::pos_y + ry + ((rand()% 200)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].pos_z          = emitter_class::pos_z + rz + ((rand()% 200)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].velocity_max   = emitter_class::velocity_max + ((rand()% 100)/10000); // add random!!! 1%?
                        emitter_class::particle[particle_count].velocity_x     = emitter_class::velocity_x + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].velocity_y     = emitter_class::velocity_y + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].velocity_z     = emitter_class::velocity_z + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_x = emitter_class::acceleration_x + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_y = emitter_class::acceleration_y + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].acceleration_z = emitter_class::acceleration_z + ((rand()% 500)/10000); // add random!!! 5%?
                        emitter_class::particle[particle_count].force_x        = emitter_class::force_x;
                        emitter_class::particle[particle_count].force_y        = emitter_class::force_y;
                        emitter_class::particle[particle_count].force_z        = emitter_class::force_z;
                        emitter_class::particle[particle_count].color_r        = emitter_class::color_start_r;
                        emitter_class::particle[particle_count].color_g        = emitter_class::color_start_g;
                        emitter_class::particle[particle_count].color_b        = emitter_class::color_start_b;
                        int sr = emitter_class::spray_radius;
                        emitter_class::particle[particle_count].direction      = emitter_class::direction - (sr/2) + (int)(sr*rand()/(RAND_MAX + 1.0)); // add random!!! 5%?
                        if (emitter_class::particle[particle_count].direction <   0) emitter_class::particle[particle_count].direction += 360;
                        if (emitter_class::particle[particle_count].direction > 360) emitter_class::particle[particle_count].direction -= 360;
                        emitter_class::particle[particle_count].TTL_rate       = emitter_class::particle_TTL_rate + ((rand()% 100)/10000); // add random 5%?
                        emitter_class::particle[particle_count].TTL            = 1.0f;
                    }
                }
            }
        }
    }
    for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
    {
        if (emitter_class::particle[particle_count].active)
        {
            emitter_class::particle[particle_count].process();
            emitter_class::particle[particle_count].color_r -= emitter_class::color_rate_r;
            emitter_class::particle[particle_count].color_g -= emitter_class::color_rate_g;
            emitter_class::particle[particle_count].color_b -= emitter_class::color_rate_b;
        }
    }
};

void  emitter_class::draw(void)
{
    if (emitter_class::active)
    {
        for (int particle_count = 0; particle_count < MAX_PARTICLES; particle_count++)
        {
            if (emitter_class::particle[particle_count].active)
            {
                if (emitter_class::image_reference == game.texture.particle_000.ref_number) game.texture.particle_000.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_001.ref_number) game.texture.particle_001.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_002.ref_number) game.texture.particle_002.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_003.ref_number) game.texture.particle_003.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_004.ref_number) game.texture.particle_004.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_005.ref_number) game.texture.particle_005.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_006.ref_number) game.texture.particle_006.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_007.ref_number) game.texture.particle_007.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_008.ref_number) game.texture.particle_008.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_009.ref_number) game.texture.particle_009.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_010.ref_number) game.texture.particle_010.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_011.ref_number) game.texture.particle_011.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_012.ref_number) game.texture.particle_012.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_013.ref_number) game.texture.particle_013.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_014.ref_number) game.texture.particle_014.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
                if (emitter_class::image_reference == game.texture.particle_015.ref_number) game.texture.particle_015.draw(true,emitter_class::particle[particle_count].pos_x,emitter_class::particle[particle_count].pos_y,emitter_class::particle[particle_count].pos_z,emitter_class::image_width,emitter_class::image_height,emitter_class::particle[particle_count].rotation,emitter_class::particle[particle_count].color_r,emitter_class::particle[particle_count].color_g,emitter_class::particle[particle_count].color_b,emitter_class::particle[particle_count].TTL);
            }
        };
    };
};

void  emitter_class::load(std::string file_name)
{
    char         temp_char = ' ';
    float        temp_float;
    std::string  temp_string_key;
    std::string  temp_string_value;
    int          count;
    std::string  data_line;
    std::fstream particle_file(file_name.c_str(),std::ios::in|std::ios::binary);
    if (particle_file.is_open())
    {
        while ( particle_file.good() )
        {
            getline(particle_file,data_line);
            {
                temp_char = data_line[0];
                if((temp_char != '#') && (data_line.length() > 2))
                {
                    temp_char         = '#';
                    temp_string_key   = "";
                    temp_string_value = "";
                    count = 0;
                    while(temp_char != ' ')
                    {
                        temp_char = data_line[count];
                        if(temp_char != ' ') temp_string_key += temp_char;
                        count++;
                        if(count > data_line.length()) (temp_char = ' ');
                    }
                    while((temp_char == ' ') || (temp_char == '='))
                    {
                        temp_char = data_line[count];
                        count++;
                        if(count > data_line.length()) (temp_char = '#');
                    }
                    count--;
                    while(temp_char != ' ')
                    {
                        temp_char = data_line[count];
                        if(temp_char != ' ') temp_string_value += temp_char;
                        count++;
                        if(count > data_line.length()) (temp_char = ' ');
                    }
                    temp_float = atof(temp_string_value.c_str());
                    if (temp_string_key == "Start_Active")
                    {
                        if ((int)temp_float == 1) emitter_class::active = true;
                        else emitter_class::active = false;
                    }
                    if (temp_string_key == "Always_On")
                    {
                        if ((int)temp_float == 1) emitter_class::always_on = true;
                        else emitter_class::always_on = false;
                    }
                    if (temp_string_key == "Image_Reference")
                    {
                        if ((int)temp_float != 0)
                        {
                            emitter_class::image_reference = (int)temp_float;
                        }
                    }
                    if (temp_string_key == "Image_Width")
                    {
                        emitter_class::image_width = temp_float;
                    }
                    if (temp_string_key == "Image_Height")
                    {
                        emitter_class::image_height = temp_float;
                    }
                    if (temp_string_key == "Position_X")
                    {
                        emitter_class::pos_x = temp_float;
                    }
                    if (temp_string_key == "Position_Y")
                    {
                        emitter_class::pos_y = temp_float;
                    }
                    if (temp_string_key == "Position_Z")
                    {
                        emitter_class::pos_z = temp_float;
                    }
                    if (temp_string_key == "Size_X")
                    {
                        emitter_class::size_x = temp_float;
                    }
                    if (temp_string_key == "Size_Y")
                    {
                        emitter_class::size_y = temp_float;
                    }
                    if (temp_string_key == "Size_Z")
                    {
                        emitter_class::size_z = temp_float;
                    }
                    if (temp_string_key == "Velocity_MAX")
                    {
                        emitter_class::velocity_max = temp_float;
                    }
                    if (temp_string_key == "Velocity_X")
                    {
                        emitter_class::velocity_x = temp_float;
                    }
                    if (temp_string_key == "Velocity_Y")
                    {
                        emitter_class::velocity_y = temp_float;
                    }
                    if (temp_string_key == "Velocity_Z")
                    {
                        emitter_class::velocity_z = temp_float;
                    }
                    if (temp_string_key == "Acceleration_X")
                    {
                        emitter_class::acceleration_x = temp_float;
                    }
                    if (temp_string_key == "Acceleration_Y")
                    {
                        emitter_class::acceleration_y = temp_float;
                    }
                    if (temp_string_key == "Acceleration_Z")
                    {
                        emitter_class::acceleration_z = temp_float;
                    }
                    if (temp_string_key == "Direction")
                    {
                        emitter_class::direction = temp_float;
                    }
                    if (temp_string_key == "Rotation")
                    {
                        emitter_class::rotation = temp_float;
                    }
                    if (temp_string_key == "Rotation_Rate")
                    {
                        emitter_class::rotation_rate = temp_float;
                    }
                    if (temp_string_key == "Spray_Radius")
                    {
                        emitter_class::spray_radius = (int)temp_float;
                    }
                    if (temp_string_key == "Force_X")
                    {
                        emitter_class::force_x = temp_float;
                    }
                    if (temp_string_key == "Force_Y")
                    {
                        emitter_class::force_y = temp_float;
                    }
                    if (temp_string_key == "Force_Z")
                    {
                        emitter_class::force_z = temp_float;
                    }
                    if (temp_string_key == "Color_Start_R")
                    {
                        emitter_class::color_start_r = temp_float;
                    }
                    if (temp_string_key == "Color_Start_G")
                    {
                        emitter_class::color_start_g = temp_float;
                    }
                    if (temp_string_key == "Color_Start_B")
                    {
                        emitter_class::color_start_b = temp_float;
                    }
                    if (temp_string_key == "Color_End_R")
                    {
                        emitter_class::color_end_r = temp_float;
                    }
                    if (temp_string_key == "Color_End_G")
                    {
                        emitter_class::color_end_g = temp_float;
                    }
                    if (temp_string_key == "Color_End_B")
                    {
                        emitter_class::color_end_b = temp_float;
                    }
                    if (temp_string_key == "Color_Rate_R")
                    {
                        emitter_class::color_rate_r = temp_float;
                    }
                    if (temp_string_key == "Color_Rate_G")
                    {
                        emitter_class::color_rate_g = temp_float;
                    }
                    if (temp_string_key == "Color_Rate_B")
                    {
                        emitter_class::color_rate_b = temp_float;
                    }
                    if (temp_string_key == "Spawn_Frequency")
                    {
                        emitter_class::spawn_frequency = (int)temp_float;
                    }
                    if (temp_string_key == "Spawn_Frequency_Count")
                    {
                        emitter_class::spawn_frequency_count = (int)temp_float;
                    }
                    if (temp_string_key == "Spawn_Quantity")
                    {
                        emitter_class::spawn_quantity = (int)temp_float;
                    }
                    if (temp_string_key == "Time_To_Live")
                    {
                        emitter_class::TTL = (int)temp_float;
                    }
                    if (temp_string_key == "Time_To_Live_Count")
                    {
                        emitter_class::TTL_count = (int)temp_float;
                    }
                    if (temp_string_key == "Particle_TTL_Rate")
                    {
                        emitter_class::particle_TTL_rate = temp_float;
                    }
                }
            }
        }
        particle_file.close();
    }
    emitter_class::color_rate_r = (emitter_class::color_start_r - emitter_class::color_end_r) / (1.0f / emitter_class::particle_TTL_rate);
    emitter_class::color_rate_g = (emitter_class::color_start_g - emitter_class::color_end_g) / (1.0f / emitter_class::particle_TTL_rate);
    emitter_class::color_rate_b = (emitter_class::color_start_b - emitter_class::color_end_b) / (1.0f / emitter_class::particle_TTL_rate);
};




