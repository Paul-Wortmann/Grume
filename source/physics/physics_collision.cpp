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

// Angle between two points
float gPhysicsAngleTwoPoints(const float32 &_px1, const float32 &_py1,
                             const float32 &_px2, const float32 &_py2)
{
    return atan2(_py1 - _py2, _px1 - _px2);
}

// Circle - Circle
bool gPhysicsCollision_Circle_Circle(const float32 &_px1, const float32 &_py1, const float32 &_r1,
                                     const float32 &_px2, const float32 &_py2, const float32 &_r2)
{
    return (((_px1 - _px2) * (_px1 - _px2)) + ((_py1 - _py2) * (_py1 - _py2))) < ((_r1 + _r2) * (_r1 + _r2));
}

// Circle - Circle distance
float gPhysicsDistance_Circle_Circle(const float32 &_px1, const float32 &_py1, const float32 &_r1,
                                     const float32 &_px2, const float32 &_py2, const float32 &_r2)
{
    return sqrt(((_px1 - _px2) * (_px1 - _px2)) + ((_py1 - _py2) * (_py1 - _py2)));
}

// Sphere - Sphere
bool gPhysicsCollision_Sphere_Sphere(const float32 &_px1, const float32 &_py1, const float32 &_pz1, const float32 &_r1,
                                     const float32 &_px2, const float32 &_py2, const float32 &_pz2, const float32 &_r2)
{
    return (((_px1 - _px2) * (_px1 - _px2)) + ((_py1 - _py2) * (_py1 - _py2)) + ((_pz1 - _pz2) * (_pz1 - _pz2))) < ((_r1 + _r2) * (_r1 + _r2));
}

// Axis aligned bounding square - Axis aligned bounding square
bool gPhysicsCollision_aabs_aabs(const float32 &_px1, const float32 &_py1, const float32 &_hw1, const float32 &_hh1,
                                 const float32 &_px2, const float32 &_py2, const float32 &_hw2, const float32 &_hh2)
{
    return (((_px1 - _hw1) < (_px2 + _hw2)) &&
            ((_px1 + _hw1) > (_px2 - _hw2)) &&
            ((_py1 - _hh1) < (_py2 + _hh2)) &&
            ((_py1 + _hh1) > (_py2 - _hh2)));
}

// Axis aligned bounding box - Axis aligned bounding box
bool gPhysicsCollision_aabb_aabb(const float32 &_px1, const float32 &_py1, const float32 &_pz1, const float32 &_hw1, const float32 &_hh1, const float32 &_hd1,
                                 const float32 &_px2, const float32 &_py2, const float32 &_pz2, const float32 &_hw2, const float32 &_hh2, const float32 &_hd2)
{
    return (((_px1 - _hw1) < (_px2 + _hw2)) &&
            ((_px1 + _hw1) > (_px2 - _hw2)) &&
            ((_py1 - _hh1) < (_py2 + _hh2)) &&
            ((_py1 + _hh1) > (_py2 - _hh2)) &&
            ((_pz1 - _hd1) < (_pz2 + _hd2)) &&
            ((_pz1 + _hd1) > (_pz2 - _hd2)));
}

// AABS - Circle collision
bool gPhysicsCollision_aabs_circle(const float32 &_px1, const float32 &_py1, const float32 &_hw1, const float32 &_hh1,
                                   const float32 &_px2, const float32 &_py2, const float32 &_r2)
{
    // get center point circle first
    glm::vec2 circle_center = glm::vec2(_px2, _py2) + _r2;
    // calculate AABB info (center, half-extents)
    glm::vec2 aabb_half_extents = glm::vec2(_hw1, _hh1);
    glm::vec2 aabb_center = glm::vec2(_px1 + aabb_half_extents.x, _py1 + aabb_half_extents.y);
    // get difference vector between both centers
    glm::vec2 difference = circle_center - aabb_center;
    glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
    // add clamped value to AABB_center and we get the value of box closest to circle
    glm::vec2 closest = aabb_center + clamped;
    // retrieve vector between center circle and closest point AABB and check if length <= radius
    difference = closest - circle_center;
    return glm::length(difference) < _r2;
}
