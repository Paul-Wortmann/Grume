/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "physics_collision.hpp"

// Circle - Circle
bool gPhysicsCollision_Circle_Circle(const float32 &_x1, const float32 &_y1, const float32 &_r1,
                                     const float32 &_x2, const float32 &_y2, const float32 &_r2)
{
    return (((_x1 - _x2) * (_x1 - _x2)) + ((_y1 - _y2) * (_y1 - _y2))) < ((_r1 + _r2) * (_r1 + _r2));
}

// Sphere - Sphere
bool gPhysicsCollision_Sphere_Sphere(const float32 &_x1, const float32 &_y1, const float32 &_z1, const float32 &_r1,
                                     const float32 &_x2, const float32 &_y2, const float32 &_z2, const float32 &_r2)
{
    return (((_x1 - _x2) * (_x1 - _x2)) + ((_y1 - _y2) * (_y1 - _y2)) + ((_z1 - _z2) * (_z1 - _z2))) < ((_r1 + _r2) * (_r1 + _r2));
}

// Axis aligned bounding square - Axis aligned bounding square
bool gPhysicsCollision_aabs_aabs(const float32 &_x1, const float32 &_y1, const float32 &_hw1, const float32 &_hh1,
                                 const float32 &_x2, const float32 &_y2, const float32 &_hw2, const float32 &_hh2)
{
    return (((_x1 - _hw1) < (_x2 + _hw2)) &&
            ((_x1 + _hw1) > (_x2 - _hw2)) &&
            ((_y1 - _hh1) < (_y2 + _hh2)) &&
            ((_y1 + _hh1) > (_y2 - _hh2)));
}

// Axis aligned bounding box - Axis aligned bounding box
bool gPhysicsCollision_aabb_aabb(const float32 &_x1, const float32 &_y1, const float32 &_z1, const float32 &_hw1, const float32 &_hh1, const float32 &_hd1,
                                 const float32 &_x2, const float32 &_y2, const float32 &_z2, const float32 &_hw2, const float32 &_hh2, const float32 &_hd2)
{
    return (((_x1 - _hw1) < (_x2 + _hw2)) &&
            ((_x1 + _hw1) > (_x2 - _hw2)) &&
            ((_y1 - _hh1) < (_y2 + _hh2)) &&
            ((_y1 + _hh1) > (_y2 - _hh2)) &&
            ((_z1 - _hd1) < (_z2 + _hd2)) &&
            ((_z1 + _hd1) > (_z2 - _hd2)));
}
