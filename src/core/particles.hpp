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

#ifndef PARTICLES_H
#define PARTICLES_H

#include <string>

const int   MAX_PARTICLES        = 2048;
const int   MAX_EMITTERS         = 16;

class particle_class
{
    public:
        bool  active;
        float pos_x;
        float pos_y;
        float pos_z;
        float velocity_x;
        float velocity_y;
        float velocity_z;
        float velocity_max;
        float acceleration_x;
        float acceleration_y;
        float acceleration_z;
        float direction; //2D
        float rotation_rate;
        float rotation;
        float force_x;
        float force_y;
        float force_z;
        float color_r;
        float color_g;
        float color_b;
        float TTL;
        float TTL_rate;
        void  init(void);
        void  kill(void);
        void  process(void);
};

class emitter_class
{
    public:
        particle_class  particle[MAX_PARTICLES];
        bool            active;
        bool            always_on;
        int             image_reference;
        float           image_width;
        float           image_height;
        float           pos_x;
        float           pos_y;
        float           pos_z;
        float           size_x;
        float           size_y;
        float           size_z;
        float           velocity_max;
        float           acceleration_x;
        float           acceleration_y;
        float           acceleration_z;
        float           velocity_x;
        float           velocity_y;
        float           velocity_z;
        float           direction;
        float           rotation_rate;
        float           rotation;
        int             spray_radius;
        float           force_x;
        float           force_y;
        float           force_z;
        float           color_start_r;
        float           color_start_g;
        float           color_start_b;
        float           color_end_r;
        float           color_end_g;
        float           color_end_b;
        float           color_rate_r;
        float           color_rate_g;
        float           color_rate_b;
        int             spawn_frequency;
        int             spawn_frequency_count;
        int             spawn_quantity;
        int             TTL;
        int             TTL_count;
        float           particle_TTL_rate;
        void            set_emitter_pos      (float x  , float y  , float z  );
        void            set_emitter_state    (bool  active, bool always_on, int ttl);
        void            set_emitter_image    (int i_ref);
        void            set_emitter_image    (int i_ref, float w  , float h  );
        void            set_emitter_rotation (float r  , float rr );
        void            set_emitter_movement (float vm , float ax , float ay , float az , float dr , int   sr , float fx , float fy , float fz );
        void            set_emitter_rates    (int   sf , int   sfc, float pr , int sq);
        void            set_emitter_color    (float csr, float csg, float csb, float cer, float ceg, float ceb);
        void            set_emitter_velocity (float vx , float vy , float vz );
        void            set_emitter_size     (float sx , float sy , float sz );
        void            init(void);
        void            kill(void);
        void            process(void);
        void            draw(void);
        void            load(std::string file_name);
};

#endif //PARTICLES_H









