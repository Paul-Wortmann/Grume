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

#ifndef LIB_MATH_VECTOR_VEC4_HPP
#define LIB_MATH_VECTOR_VEC4_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"

template<typename T>
struct vec4_t
{
    static const uint32_t SIZE = 4;
    vec4_t(float64 _f) { x = _f; y = _f; z = _f; w = _f; }
    vec4_t(float64 _x, float64 _y, float64 _z, float64 _w) { x = _x; y = _y; z = _z; w = _w; }
    ~vec4_t(void) { }
    vec4_t(const vec4_t& _v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; }
    bool operator==(const vec4_t& _v) { return (x == _v.x && y == _v.y && z == _v.z && w == _v.w); }
    vec4_t& operator=(const vec4_t& _v) { x = _v.x; y = _v.y; z = _v.z; w = _v.w; return *this; }
    void operator+=(const vec4_t& _v) { x += _v.x; y += _v.y; z += _v.z; w += _v.w; }
    vec4_t operator+(const vec4_t& _v) const { return vec4_t(x + _v.x, y + _v.y, z + _v.z, w + _v.w); }
    void operator-=(const vec4_t& _v) { x -= _v.x; y -= _v.y; z -= _v.z; w -= _v.w; }
    vec4_t operator-(const vec4_t& _v) const { return vec4_t(x - _v.x, y - _v.y, z - _v.z, w - _v.w); }
    void operator*=(const float64 _s) { x *= _s; y *= _s; z *= _s; w *= _s; }
    vec4_t operator*(const float64 _s) const {    return vec4_t(_s * x, _s * y, _s * z, _s * w); }
    void operator /=(const float64 _s) { x /= _s; y /= _s; z /= _s; w /= _s; }
    vec4_t operator/(const float64 _s) const {return vec4_t(x / _s, y / _s, z / _s, w / _s); }
    float64 operator*(const vec4_t& _v) const { return x * _v.x + y * _v.y + z * _v.z + w * _v.w; }
    float64 dot(const vec4_t& _v) const { return x * _v.x + y * _v.y + z * _v.z + w * _v.w; }
    float64 magnitude(void){ return std::sqrt(x * x + y * y + z * z + w * w); }
    void normalize(void) { float64 magnitude = std::sqrt(x * x + y * y + z * z + w * w);  if (magnitude > 0.0f) { float64 oneOverMagnitude = 1.0f / magnitude; x = x * oneOverMagnitude; y = y * oneOverMagnitude; z = z * oneOverMagnitude; w = w * oneOverMagnitude; } }

/*  -- internal test code ---
    void draw(void)
    {
        std::cout << "--- vec4_t ---" << std::endl;
        for (size_t i = 0; i < SIZE; i++)
        {
            std::cout << "[" << array[i] << "]";
        }
        std::cout << std::endl << "--------" << std::endl;
    }
*/

    union
    {
        struct { float64 x = 0.0f; float64 y = 0.0f; float64 z = 0.0f; float64 w = 0.0f; };
        struct { float64 array[SIZE]; };
    };
};

#endif // _VEC4