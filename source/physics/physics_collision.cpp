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
float gPhysicsAngleTwoPoints(const float &_px1, const float &_py1,
                             const float &_px2, const float &_py2)
{
    return atan2(_py1 - _py2, _px1 - _px2);
}

// Circle - Circle
bool gPhysicsCollision_circle_circle(const float &_px1, const float &_py1, const float &_r1,
                                     const float &_px2, const float &_py2, const float &_r2)
{
    return (((_px1 - _px2) * (_px1 - _px2)) + ((_py1 - _py2) * (_py1 - _py2))) < ((_r1 + _r2) * (_r1 + _r2));
}

// Circle - Circle distance
float gPhysicsDistance_circle_circle(const float &_px1, const float &_py1, const float &_r1,
                                     const float &_px2, const float &_py2, const float &_r2)
{
    return sqrt(((_px1 - _px2) * (_px1 - _px2)) + ((_py1 - _py2) * (_py1 - _py2))) - _r1 - _r2;
}

// Sphere - Sphere
bool gPhysicsCollision_sphere_sphere(const float &_px1, const float &_py1, const float &_pz1, const float &_r1,
                                     const float &_px2, const float &_py2, const float &_pz2, const float &_r2)
{
    return (((_px1 - _px2) * (_px1 - _px2)) + ((_py1 - _py2) * (_py1 - _py2)) + ((_pz1 - _pz2) * (_pz1 - _pz2))) < ((_r1 + _r2) * (_r1 + _r2));
}

// Axis aligned bounding square - Axis aligned bounding square
bool gPhysicsCollision_aabs_aabs(const float &_px1, const float &_py1, const float &_hw1, const float &_hh1,
                                 const float &_px2, const float &_py2, const float &_hw2, const float &_hh2)
{
    return (((_px1 - _hw1) < (_px2 + _hw2)) &&
            ((_px1 + _hw1) > (_px2 - _hw2)) &&
            ((_py1 - _hh1) < (_py2 + _hh2)) &&
            ((_py1 + _hh1) > (_py2 - _hh2)));
}

// Axis aligned bounding box - Axis aligned bounding box
bool gPhysicsCollision_aabb_aabb(const float &_px1, const float &_py1, const float &_pz1, const float &_hw1, const float &_hh1, const float &_hd1,
                                 const float &_px2, const float &_py2, const float &_pz2, const float &_hw2, const float &_hh2, const float &_hd2)
{
    return (((_px1 - _hw1) < (_px2 + _hw2)) &&
            ((_px1 + _hw1) > (_px2 - _hw2)) &&
            ((_py1 - _hh1) < (_py2 + _hh2)) &&
            ((_py1 + _hh1) > (_py2 - _hh2)) &&
            ((_pz1 - _hd1) < (_pz2 + _hd2)) &&
            ((_pz1 + _hd1) > (_pz2 - _hd2)));
}

// AABS - Circle collision
bool gPhysicsCollision_aabs_circle(const float &_px1, const float &_py1, const float &_hw1, const float &_hh1,
                                   const float &_px2, const float &_py2, const float &_r2)
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

// ray - aabb collision
bool gPhysicsCollision_ray_aabb(const float &_px1, const float &_py1, const float &_pz1, const float &_dx1, const float &_dy1, const float &_dz1,
                                const float &_px2, const float &_py2, const float &_pz2, const float &_hsx2, const float &_hsy2, const float &_hsz2,
                                float &_tmin)
{
    float tmin  = 0.0f;
    float tmax  = 0.0f;
    float tymin = 0.0f;
    float tymax = 0.0f;
    float tzmin = 0.0f;
    float tzmax = 0.0f;

    _tmin = std::numeric_limits<float>::max();

    glm::vec3 bounds[2];
    bounds[0].x =_px2 - _hsx2;
    bounds[0].y =_py2 - _hsy2;
    bounds[0].z =_pz2 - _hsz2;
    bounds[1].x =_px2 + _hsx2;
    bounds[1].y =_py2 + _hsy2;
    bounds[1].z =_pz2 + _hsz2;

    glm::vec3 invdir = 1.f / glm::vec3(_dx1, _dy1, _dz1);
    glm::i8vec3 sign;

    sign.x = (invdir.x < 0);
    sign.y = (invdir.y < 0);
    sign.z = (invdir.z < 0);

    tmin = (bounds[sign.x].x - _px1) * invdir.x;
    tmax = (bounds[1 - sign.x].x - _px1) * invdir.x;
    tymin = (bounds[sign.y].y - _py1) * invdir.y;
    tymax = (bounds[1 - sign.y].y - _py1) * invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (bounds[sign.z].z - _pz1) * invdir.z;
    tzmax = (bounds[1 - sign.z].z - _pz1) * invdir.z;

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    _tmin = tmin;
    return true;
}

glm::vec3 gPhysicsCollision_ray_plane(const glm::vec3 &_ray, const glm::vec3 &_position)
{
    glm::vec3 n = glm::vec3(0.0, -1.0, 0.0);
    float   t = -glm::dot(_position, n) / glm::dot(_ray, n);

    return _position + _ray * t;
}
