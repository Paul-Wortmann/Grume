/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "libMath"
 *
 * "libMath" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "libMath" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "libMath" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2020-04-23
 */

#include "libMath.hpp"

vec3 planeLineIntersection(const vec3 &_planePoint, const vec3 &_planeNormal, const vec3 &_linePoint, const vec3 &_lineDirection)
{
    vec3    ld    = _lineDirection;
    ld.normalize();
    float pnDld = _planeNormal.dot(ld);

    if (pnDld == 0)
    {
        return vec3(0.0f, 0.0f, 0.0f);
    }
    
    float t = (_planeNormal.dot(_planePoint) - _planeNormal.dot(_linePoint)) / pnDld;
    
    vec3 ldSt = ld * t;
    vec3 lpPld = _linePoint + ldSt;
    
    return lpPld;
}