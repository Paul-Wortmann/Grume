/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "vector.hpp"

#define NONE       0
#define CIRCLE     1
#define SPHERE     2
#define SQUARE     3
#define CUBE       4
#define TRIANGLE   5
#define POLYGON    6

class vertex_3f_class
{
    private:
    protected:
    public:
        float x;
        float y;
        float z;
};

class vertex_2f_class
{
    private:
    protected:
    public:
        float x;
        float y;
        vertex_2f_class( float ix = 0.0f, float iy = 0.0f ) : x( ix ), y( iy ) { };
       ~vertex_2f_class() { };
        vertex_2f_class operator*( float scalar ) { return vertex_2f_class( x*scalar, y*scalar ); }
        vertex_2f_class operator/( float scalar ) { return vertex_2f_class( x/scalar, y/scalar ); }
        vertex_2f_class operator+( vertex_2f_class b ) { return vertex_2f_class( x + b.x, y + b.y ); }
        vertex_2f_class operator-( vertex_2f_class b ) { return vertex_2f_class( x - b.x, y - b.y ); }
        vertex_2f_class operator-() { return vertex_2f_class( -x, -y ); }
        float operator*( vertex_2f_class b ) { return x*b.x + y*b.y; }
        void  operator=( vertex_2f_class b ) { x = b.x; y = b.y; }
        void  operator+=( vertex_2f_class b ) { x += b.x; y += b.y; }
        void  operator-=( vertex_2f_class b ) { x -= b.x; y -= b.y; }
        void  operator*=( float scalar ) { x *= scalar; y *= scalar; }
        void  operator/=( float scalar ) { x /= scalar; y /= scalar; }
        bool  operator>=( vertex_2f_class b ) { return x >= b.x && y >= b.y; }
        bool  operator<=( vertex_2f_class b ) { return x <= b.x && y <= b.y; }
        bool  operator==( vertex_2f_class b ) { return x == b.x && y == b.y; }
        bool  operator!=( vertex_2f_class b ) { return x != b.x || y != b.y; }
};
/*
class body_2D_class
{
    private:
    public:
        int             world_ID;
        int             texture;
        int             body_type;
        float           mass;
        float           restitution;
        float           friction;
        bool            solid;
        bool            liquid;
        bool            gas;
        float           elasticity;
        float           viscosity;
        float           density;
        vector_2f_class acceleration;
        float           velocity_max;
        float           radius;
        vector_2f_class position;
        vector_2f_class velocity;
        body_2D_class(void);
       ~body_2D_class(void);
        void            process(void);
};
*/
/*
class world_class
{
    private:
    public:
        int                       ID;
        vertex_2f_class           vertex[4];
        vector_2f_class           gravity;
        float                     gravity_x;
        float                     gravity_y;
        float                     gravity_z;
        float                     position_x;
        float                     position_y;
        float                     position_z;
        float                     length_x; // redundant, included for backwards compatibility.
        float                     length_y; // redundant, included for backwards compatibility.
        float                     length_z; // redundant, included for backwards compatibility.
                                  world_class            (void);
                                 ~world_class            (void);
};
*/
class physics_class
{
    private:
    public:
        float               sin_table[360];
        float               cos_table[360];

                            physics_class            (void);
                           ~physics_class            (void);
        //bool                collision_detection      (body_2D_class body_1, body_2D_class  body_2);
        //bool                collision_detection      (body_2D_class body_1, world_class    world_1);
        //void                collision_responce       (body_2D_class body_1, body_2D_class  body_2);
        //body_2D_class       collision_responce       (body_2D_class body_1, world_class    world_1);
        //body_2D_class       process_body             (body_2D_class body_1);

        bool                cube_collision           (float x1, float y1, float z1, float w1, float h1, float d1, float x2, float y2, float z2, float w2, float h2, float d2);
        bool                quadrangle_collision     (float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
        bool                circle_collision         (float x1, float y1, float r1, float x2, float y2, float r2);
        bool                sphere_collision         (float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2);
        float               distance_2D              (float x1, float y1, float x2, float y2);
        float               distance_3D              (float x1, float y1, float z1, float x2, float y2, float z2);
        bool                point_in_circle          (float cx, float cy, float cr, float px, float py);
        bool                point_in_quadrangle      (float qx, float qw, float qy, float qh, float px, float py);
        bool                point_in_diamond         (float dx, float dw, float dy, float dh, float px, float py);
        float               point_side_of_line       (float x1, float y1, float x2, float y2, float px, float py);
        float               line_slope_2D            (float x1, float y1, float x2, float y2);
        float               line_angle               (float x1, float y1, float x2, float y2);
        float               line_point_2D_x          (float x1, float distance, float angle);
        float               line_point_2D_y          (float y1, float distance, float angle);
        float               rotate_point_2D_x        (float cx, float cy, float px, float py, int angle);
        float               rotate_point_2D_y        (float cx, float cy, float px, float py, int angle);
        float               move_velocity_angle_2D_x (float  x, float v,  float radians);
        float               move_velocity_angle_2D_y (float  y, float v,  float radians);
        float               move_velocity_angle_2D_x (float  x, float v,  int degrees);
        float               move_velocity_angle_2D_y (float  y, float v,  int degrees);
        float               degrees_to_radians       (float degrees);
        float               radians_to_degrees       (float radians);
        void                generate_sin_table       (void);
        void                generate_cos_table       (void);
        bool                point_in_polygon         (int number_of_vertecies, vertex_3f_class vertex[], float px, float py);
        int                 sigma                    (int n);
};

#endif //PHYSICS_H


