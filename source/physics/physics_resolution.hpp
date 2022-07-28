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

#ifndef PHYSICS_RESOLUTION_HPP
#define PHYSICS_RESOLUTION_HPP

#include "../core/includes.hpp"

// Elastic collision resolution 2D circle - circle
void gPhysicsResolution_circle_circle(float &_vx1, float &_vy1, float &_px1, float &_py1, const float &_r1, const float &_m1, const bool &_static1,
                                      float &_vx2, float &_vy2, float &_px2, float &_py2, const float &_r2, const float &_m2, const bool &_static2);

// Elastic collision resolution 2D aabs - aabs
void gPhysicsResolution_aabs_aabs(float &_vx1, float &_vy1, float &_px1, float &_py1, const float &_hw1, const float &_hh1, const float &_m1, const bool &_static1,
                                  float &_vx2, float &_vy2, float &_px2, float &_py2, const float &_hw2, const float &_hh2, const float &_m2, const bool &_static2);

// Elastic collision resolution 2D aabs - circle
void gPhysicsResolution_aabs_circle(float &_vx1, float &_vy1, float &_px1, float &_py1, const float &_hw1, const float &_hh1, const float &_m1, const bool &_static1,
                                    float &_vx2, float &_vy2, float &_px2, float &_py2, const float &_r2, const float &_m2, const bool &_static2);

#endif // PHYSICS_RESOLUTION_HPP

