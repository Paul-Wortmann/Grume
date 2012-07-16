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

#include "physics.hpp"
#include <math.h>

body_2D_class::body_2D_class         (void)
{
    body_2D_class::world_ID                 =  0;
    body_2D_class::body_type                =  1;
    body_2D_class::texture                  =  0;
    body_2D_class::mass                     =  0.0f;
    body_2D_class::restitution              =  0.0f;
    body_2D_class::friction                 =  0.0f;
    body_2D_class::acceleration.x           =  0.0f;
    body_2D_class::acceleration.y           =  0.0f;
    body_2D_class::velocity_max             =  0.0f;
    body_2D_class::radius                   =  0.0f;
    body_2D_class::position.x               =  0.0f;
    body_2D_class::position.y               =  0.0f;
    body_2D_class::velocity.x               =  0.0f;
    body_2D_class::velocity.y               =  0.0f;
}

body_2D_class::~body_2D_class          (void)
{

};

///-----------------------------------------------------------------------------------------------------------------------
world_class::world_class         (void)
{
    world_class::ID                       =  0;
    world_class::gravity_x                =  0.0f;
    world_class::gravity_y                = -9.8f;
    world_class::gravity_z                =  0.0f;
    world_class::position_x               =  0.0f;
    world_class::position_y               =  0.0f;
    world_class::position_z               =  0.0f;
    world_class::ID                       =  0;
    world_class::gravity_x                =  0.0f;
    world_class::gravity_y                = -9.8f;
    world_class::gravity_z                =  0.0f;
    world_class::position_x               =  0.0f;
    world_class::position_y               =  0.0f;
    world_class::position_z               =  0.0f;
    world_class::length_x                 =  0.0f; // redundant, included for backwards compatibility.
    world_class::length_y                 =  0.0f; // redundant, included for backwards compatibility.
    world_class::length_z                 =  0.0f; // redundant, included for backwards compatibility.
    for (int vertex_count = 0; vertex_count < (int)(sizeof(world_class::vertex) / sizeof(world_class::vertex[0])); vertex_count++)
    {
        world_class::vertex[vertex_count].x = 0.0f;
        world_class::vertex[vertex_count].y = 0.0f;
    }
    world_class::vertex[0].x =  0.50f;
    world_class::vertex[0].y =  0.50f;
    world_class::vertex[1].x =  0.50f;
    world_class::vertex[1].y = -0.50f;
    world_class::vertex[2].x = -0.50f;
    world_class::vertex[2].y = -0.50f;
    world_class::vertex[3].x = -0.50f;
    world_class::vertex[3].y =  0.50f;
}

world_class::~world_class         (void)
{

};

///-----------------------------------------------------------------------------------------------------------------------

physics_class::physics_class         (void)
{
    physics_class::generate_sin_table();
    physics_class::generate_cos_table();
};

physics_class::~physics_class         (void)
{

};

bool physics_class::collision_detection (body_2D_class body_1, body_2D_class body_2)
{
    switch (body_1.body_type)
    {
        case CIRCLE:
            switch (body_1.body_type)
            {
                case CIRCLE:
                    if (physics_class::circle_collision(body_1.position.x,body_1.position.y,body_1.radius,body_2.position.x,body_2.position.y,body_2.radius)) return(true);
                    else return(false);
                break;
                case POLYGON:

                break;
                default:
                    return(false);
                break;
            }
        break;
        case POLYGON:
            switch (body_1.body_type)
            {
                case CIRCLE:

                break;
                case POLYGON:

                break;
                default:
                    return(false);
                break;
            }
        break;
        default:
            return(false);
        break;
    }
};

void physics_class::collision_responce    (body_2D_class body_1, body_2D_class body_2)
{
    switch (body_1.body_type)
    {
        case CIRCLE:
            switch (body_1.body_type)
            {
                case CIRCLE:




                break;
                case POLYGON:

                break;
                default:
                break;
            }
        break;
        case POLYGON:
            switch (body_1.body_type)
            {
                case CIRCLE:

                break;
                case POLYGON:

                break;
                default:
                break;
            }
        break;
        default:
        break;
    }
};

bool physics_class::collision_detection      (body_2D_class body_1, world_class world_1)
{
    float qx = 0.0f;
    float qy = 0.0f;
    float qw = 1.0f;
    float qh = 1.0f;
    float px = body_1.position.x;
    float py = body_1.position.y;
    float pr = body_1.radius;
    if ((px+pr > (qx-(qw/2))) &&
        (px-pr < (qx+(qw/2))) &&
        (py+pr > (qy-(qh/2))) &&
        (py-pr < (qy+(qh/2)))) return(true);
    else return(false);
/*
    bool            return_value        = false;
    int             number_of_vertecies = (int)(sizeof(world_1.vertex) / sizeof(world_1.vertex[0]));
    float           px                  = body_1.position.x;
    float           py                  = body_1.position.y;
    float           pr                  = body_1.radius+body_1.velocity.magnitude();
    float           vx1                 = 0.0f;
    float           vy1                 = 0.0f;
    float           vx2                 = 0.0f;
    float           vy2                 = 0.0f;
    for (int i = 0, j = number_of_vertecies-1; i < number_of_vertecies; j = i++)
    {
        vx1 = world_1.vertex[i].x;
        vy1 = world_1.vertex[i].y;
        vx2 = world_1.vertex[j].x;
        vy2 = world_1.vertex[j].y;
        if (((vy1>py-pr) != (vy2>py-pr)) && (px-pr < (vx2-vx1) * (py+pr-vy1) / (vy2-vy1) + vx1)) return_value = !return_value;
    }
    return(return_value);
*/
};

body_2D_class physics_class::collision_responce       (body_2D_class body_1, world_class world_1)
{
    int   temp_angle     = body_1.velocity.angle_deg();
    float temp_magnitude = body_1.velocity.magnitude();
    temp_angle -= 180;
    if (temp_angle < 0) temp_angle += 360;
    body_1.velocity.x = temp_magnitude * physics_class::cos_table[temp_angle];
    body_1.velocity.y = temp_magnitude * physics_class::sin_table[temp_angle];
    //body_1.position.x = physics_class::move_velocity_angle_2D_x(body_1.position.x,body_1.velocity.magnitude(),body_1.velocity.angle_deg());
    //body_1.position.y = physics_class::move_velocity_angle_2D_y(body_1.position.y,body_1.velocity.magnitude(),body_1.velocity.angle_deg());

    return(body_1);
};

body_2D_class physics_class::process_body             (body_2D_class body_1)
{
    if (body_1.velocity.magnitude() < body_1.velocity_max) body_1.velocity += body_1.acceleration;
    body_1.position.x = physics_class::move_velocity_angle_2D_x(body_1.position.x,body_1.velocity.magnitude(),body_1.velocity.angle_deg());
    body_1.position.y = physics_class::move_velocity_angle_2D_y(body_1.position.y,body_1.velocity.magnitude(),body_1.velocity.angle_deg());

    switch (body_1.body_type)
    {
        case CIRCLE:

        break;
        case POLYGON:
        break;
        default:
        break;
    }
    return (body_1);
};

//----------------------------------------------------------------------------------------------------------------

bool  physics_class::cube_collision        (float x1, float y1, float z1, float w1, float h1, float d1, float x2, float y2, float z2, float w2, float h2, float d2)
{
    if (((x1-(w1/2) < x2+(w2/2)) && (x2+(w2/2) > x1-(w1/2))) && ((x2-(w2/2) < x1+(w1/2)) && (x1+(w1/2) > x2-(w2/2)))
     && ((y1-(h1/2) < y2+(h2/2)) && (y2+(h2/2) > y1-(h1/2))) && ((y2-(h2/2) < y1+(h1/2)) && (y1+(h1/2) > y2-(h2/2)))
     && ((z1-(d1/2) < z2+(d2/2)) && (z2+(d2/2) > z1-(d1/2))) && ((z2-(d2/2) < z1+(d1/2)) && (z1+(d1/2) > z2-(d2/2)))) return(true);
    else return(false);
}

bool  physics_class::quadrangle_collision   (float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
    if (((x1-(w1/2) < x2+(w2/2)) && (x2+(w2/2) > x1-(w1/2))) && ((x2-(w2/2) < x1+(w1/2)) && (x1+(w1/2) > x2-(w2/2)))
     && ((y1-(h1/2) < y2+(h2/2)) && (y2+(h2/2) > y1-(h1/2))) && ((y2-(h2/2) < y1+(h1/2)) && (y1+(h1/2) > y2-(h2/2)))) return(true);
    else return(false);
}

bool  physics_class::circle_collision(float x1, float y1, float r1, float x2, float y2, float r2)
{
    if (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) < ((r1+r2)*(r1+r2))) return(true);
    else return(false);
}

bool  physics_class::sphere_collision(float x1, float y1, float z1, float r1, float x2, float y2, float z2, float r2)
{
    if ((((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))+((z1-z2)*(z1-z2))) < ((r1+r2)*(r1+r2))) return(true);
    else return(false);
}

float  physics_class::distance_2D(float x1, float y1, float x2, float y2)
{
    return(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}

float  physics_class::distance_3D(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return(sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))+((z1-z2)*(z1-z2))));
}

bool   physics_class::point_in_circle          (float cx, float cy, float cr, float px, float py)
{
    if ((((px-cx) * (px-cx)) + ((py-cy) * (py-cy))) < (cr*cr)) return(true);
    else return(false);
};

bool  physics_class::point_in_quadrangle  (float qx, float qw, float qy, float qh, float px, float py) //rectangle!
{
    if ((px > (qx-(qw/2))) && (px < (qx+(qw/2))) && (py > (qy-(qh/2))) && (py < (qy+(qh/2)))) return(true);
    else return(false);
};

bool   physics_class::point_in_diamond         (float dx, float dw, float dy, float dh, float px, float py)
{
    if ((py >= (dy - (dh/2.0f))) && (py <= (dy + (dh/2.0f))) && (px >= (dx - ((dw/2.0f) - (py - dy)))) && (px <= (dx + ((dw/2.0f) - (py - dy))))) return(true);
    else return(false);
};

float  physics_class::point_side_of_line       (float x1, float y1, float x2, float y2, float px, float py)
{
    return((py-y1)-((y2-y1)/(x2-x1))*(px-x1));
};

float  physics_class::line_slope_2D(float x1, float y1, float x2, float y2)
{
    return((y2-y1)/(x2-x1));
};

float  physics_class::line_angle(float x1, float y1, float x2, float y2)
{
    return(atan2(y2 - y1, x2 - x1));
};

float  physics_class::line_point_2D_x(float x1, float distance, float angle)
{
    return(x1 + distance*physics_class::cos_table[(int)angle]);
};

float physics_class::line_point_2D_y(float y1, float distance, float angle)
{
    return(y1 + distance*physics_class::sin_table[(int)angle]);
};

float  physics_class::rotate_point_2D_x(float cx,float cy,float px,float py,int angle)
{
    return(((px-cx) * physics_class::cos_table[angle] - (py-cy) * physics_class::sin_table[angle])+cx);
}

float  physics_class::rotate_point_2D_y(float cx,float cy,float px,float py,int angle)
{
    return(((px-cx) * physics_class::sin_table[angle] + (py-cy) * physics_class::cos_table[angle])+cy);
}

float  physics_class::move_velocity_angle_2D_x    (float  x, float v,  float radians)
{
    return(x + (v*physics_class::sin_table[(int)physics_class::radians_to_degrees(radians)]));
};

float  physics_class::move_velocity_angle_2D_y    (float  y, float v,  float radians)
{
    return(y + (v*physics_class::cos_table[(int)physics_class::radians_to_degrees(radians)]));
};

float  physics_class::move_velocity_angle_2D_x    (float  x, float v,  int degrees)
{
    return(x + (v*physics_class::sin_table[degrees]));
};

float  physics_class::move_velocity_angle_2D_y    (float  y, float v,  int degrees)
{
    return(y + (v*physics_class::cos_table[degrees]));
};

float  physics_class::degrees_to_radians   (float degrees)
{
    return(degrees * (M_PI/180));
};

float  physics_class::radians_to_degrees   (float radians)
{
    return(radians * (180/M_PI));
};

void   physics_class::generate_sin_table   (void)
{
    for(int sin_count = 0; sin_count < 360; sin_count++)
        physics_class::sin_table[sin_count] = sin(sin_count* (M_PI/180));
};

void   physics_class::generate_cos_table   (void)
{
    for(int cos_count = 0; cos_count < 360; cos_count++)
        physics_class::cos_table[cos_count] = cos(cos_count* (M_PI/180));
};

bool   physics_class::point_in_polygon(int number_of_vertecies, vertex_3f_class vertex[], float px, float py)
{
    bool return_value = false;
    for (int i = 0, j = number_of_vertecies-1; i < number_of_vertecies; j = i++)
    {
        if (((vertex[i].y>py) != (vertex[j].y>py)) && (px < (vertex[j].x-vertex[i].x) * (py-vertex[i].y) / (vertex[j].y-vertex[i].y) + vertex[i].x)) return_value = !return_value;
    }
    return(return_value);
};
