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

#ifndef PHYSICS_H
#define PHYSICS_H

#define SPHERE 0
#define CUBE   1

class body_class
{
    private:
    public:
        int         world_ID;
        int         texture;
        int         body_type;
        float       radius_x;
        float       radius_y;
        float       radius_z;
        float       length_x;
        float       length_y;
        float       length_z;
        float       weight;
        float       restitution;
        float       friction;
        float       acceleration;
        float       velocity_max;
        float       velocity_x;
        float       velocity_y;
        float       velocity_z;
        float       position_x;
        float       position_y;
        float       position_z;
        float       rotational_angle_x;
        float       rotational_angle_y;
        float       rotational_angle_z;
        float       rotational_velocity_max;
        float       rotational_velocity_x;
        float       rotational_velocity_y;
        float       rotational_velocity_z;
        float       rotational_acceleration;
                    body_class            (void);
                   ~body_class            (void);
};

class world_class
{
    private:
    public:
        int         ID;
        float       gravity_x;
        float       gravity_y;
        float       gravity_z;
        float       length_x;
        float       length_y;
        float       length_z;
        float       position_x;
        float       position_y;
        float       position_z;
                    world_class            (void);
                   ~world_class            (void);
};

class physics_class
{
    private:
    public:
        float       sin_table[360];
        float       cos_table[360];
                    physics_class            (void);
                   ~physics_class            (void);
        bool        cube_collision           (float x1, float y1, float z1, float w1, float h1, float d1, float x2, float y2, float z2, float w2, float h2, float d2);
        bool        quadrangle_collision     (float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
        bool        circle_collision         (float x1, float y1, float r1, float x2, float y2, float r2);
        bool        sphere_collision         (float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2);
        float       distance_2D              (float x1, float y1, float x2, float y2);
        float       distance_3D              (float x1, float y1, float z1, float x2, float y2, float z2);
        bool        point_in_circle          (float cx, float cy, float cr, float px, float py);
        bool        point_in_quadrangle      (float qx, float qw, float qy, float qh, float px, float py);
        bool        point_in_diamond         (float dx, float dw, float dy, float dh, float px, float py);
        float       point_side_of_line       (float x1, float y1, float x2, float y2, float px, float py);
        float       line_slope_2D            (float x1, float y1, float x2, float y2);
        float       line_angle               (float x1, float y1, float x2, float y2);
        float       line_point_2D_x          (float x1, float distance, float angle);
        float       line_point_2D_y          (float y1, float distance, float angle);
        float       rotate_point_2D_x        (float cx, float cy, float px, float py, int angle);
        float       rotate_point_2D_y        (float cx, float cy, float px, float py, int angle);
        float       move_speed_angle_2D_x    (float  x, float s,  float dr);
        float       move_speed_angle_2D_y    (float  y, float s,  float dr);
        float       degrees_to_radians       (float degrees);
        float       radians_to_degrees       (float radians);
        void        generate_sin_table       (void);
        void        generate_cos_table       (void);
};

#endif //PHYSICS_H


