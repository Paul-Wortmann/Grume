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

// px, py, pz    - position
// dx, dy, dz    - direction
// rx, ry, rz    - rotation
// vx, vy, vz    - velocity
// r             - radius
// sx, sy, sz    - size
// hsx, hsy, hsz - half size

// Angle between two points
float gPhysicsAngleTwoPoints(const float &_px1, const float &_py1,
                             const float &_px2, const float &_py2);
// Circle - Circle collision
bool gPhysicsCollision_circle_circle(const float &_px1, const float &_py1, const float &_r1,
                                     const float &_px2, const float &_py2, const float &_r2);
// Circle - Circle distance
float gPhysicsDistance_circle_circle(const float &_px1, const float &_py1, const float &_r1,
                                     const float &_px2, const float &_py2, const float &_r2);
// Sphere - Sphere collision
bool gPhysicsCollision_sphere_sphere(const float &_px1, const float &_py1, const float &_pz1, const float &_r1,
                                     const float &_px2, const float &_py2, const float &_pz2, const float &_r2);
// Axis aligned bounding square - Axis aligned bounding square collision
bool gPhysicsCollision_aabs_aabs(const float &_px1, const float &_py1, const float &_hsx1, const float &_hsy1,
                                 const float &_px2, const float &_py2, const float &_hsx2, const float &_hsy2);
// Axis aligned bounding box - Axis aligned bounding box collision
bool gPhysicsCollision_aabb_aabb(const float &_px1, const float &_py1, const float &_pz1, const float &_hsx1, const float &_hsy1, const float &_hsz1,
                                 const float &_px2, const float &_py2, const float &_pz2, const float &_hsx2, const float &_hsy2, const float &_hsz2);
// AABS - Circle collision
bool gPhysicsCollision_aabs_circle(const float &_px1, const float &_py1, const float &_hw1, const float &_hh1,
                                   const float &_px2, const float &_py2, const float &_r2);
// ray - aabb collision
bool gPhysicsCollision_ray_aabb(const float &_px1, const float &_py1, const float &_pz1, const float &_dx1, const float &_dy1, const float &_dz1,
                                const float &_px2, const float &_py2, const float &_pz2, const float &_hsx2, const float &_hsy2, const float &_hsz2,
                                float &_tmin);
// ray - plane collision
glm::vec3 gPhysicsCollision_ray_plane(const glm::vec3 &_ray, const glm::vec3 &_position);

/*
sat
obb

cylinder
ray
*/

#endif // PHYSICS_COLLISION_HPP

