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

#ifndef PHYSICS_COLLISION_HPP
#define PHYSICS_COLLISION_HPP

#include "../core/includes.hpp"

// x, y, z       - position
// r             - radius
// sx, sy, sz    - scale
// hsx, hsy, hsz - half scale


// Circle - Circle
bool gPhysicsCollision_Circle_Circle(const float32 &_x1, const float32 &_y1, const float32 &_r1,
                                     const float32 &_x2, const float32 &_y2, const float32 &_r2);
// Sphere - Sphere
bool gPhysicsCollision_Sphere_Sphere(const float32 &_x1, const float32 &_y1, const float32 &_z1, const float32 &_r1,
                                     const float32 &_x2, const float32 &_y2, const float32 &_z2, const float32 &_r2);
// Axis aligned bounding square - Axis aligned bounding square
bool gPhysicsCollision_aabs_aabs(const float32 &_x1, const float32 &_y1, const float32 &_hsx1, const float32 &_hsy1,
                                 const float32 &_x2, const float32 &_y2, const float32 &_hsx2, const float32 &_hsy2);
// Axis aligned bounding box - Axis aligned bounding box
bool gPhysicsCollision_aabb_aabb(const float32 &_x1, const float32 &_y1, const float32 &_z1, const float32 &_hsx1, const float32 &_hsy1, const float32 &_hsz1,
                                 const float32 &_x2, const float32 &_y2, const float32 &_z2, const float32 &_hsx2, const float32 &_hsy2, const float32 &_hsz2);

/*

sat

aabc
bb
cylinder
ray
*/

#endif // PHYSICS_COLLISION_HPP

