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

#ifndef LIB_MATH_VECTOR_VEC3_HPP
#define LIB_MATH_VECTOR_VEC3_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"

template<typename T>
struct vec3_t
{
    // data structures, variables and constants
    static const uint32 SIZE = 3; // vec3_t<T> == 3
    union
    {
        T array[SIZE];
        struct { T x = 0.0; T y = 0.0; T z = 0.0; };
    };
    
    // construnctors and destructor
    vec3_t<T>(void) { this->x = 0.0; this->y = 0.0; this->z = 0.0; }
    vec3_t<T>(const T &_f) { this->x = _f; this->y = _f; this->z = _f; }
    vec3_t<T>(const T &_x, const T &_y, const T &_z) { this->x = _x; this->y = _y; this->z = _z; }
    vec3_t<T>(const vec3_t<T>& _v) { this->x = _v.x; this->y = _v.y; this->z = _v.z; }
    ~vec3_t<T>(void) = default;
    
    // opperators
    bool operator==(const vec3_t<T>& _v) const { return (this->x == _v.x && this->y == _v.y && this->z == _v.z); }
    vec3_t<T>& operator=(const vec3_t<T>& _v) { this->x = _v.x; this->y = _v.y; this->z = _v.z; return *this; }
    vec3_t<T> operator- (void) const { vec3_t<T> v(-this->x, -this->y, -this->z); return v; }
    void operator+=(const vec3_t<T>& _v) { this->x += _v.x; this->y += _v.y; this->z += _v.z; }
    vec3_t<T> operator+(const vec3_t<T>& _v) const { return vec3_t<T>(this->x + _v.x, this->y + _v.y, this->z + _v.z); }
    void operator-=(const vec3_t<T>& _v) { this->x -= _v.x; this->y -= _v.y; this->z -= _v.z; }
    vec3_t<T> operator-(const vec3_t<T>& _v) const { return vec3_t<T>(this->x - _v.x, this->y - _v.y, this->z - _v.z); }
    void operator*=(const T _s) { this->x *= _s; this->y *= _s; this->z *= _s; }
    vec3_t<T> operator*(const T _s) const {    return vec3_t<T>(_s * this->x, _s * this->y, _s * this->z); }
    void operator /=(const T _s) { this->x /= _s; this->y /= _s; this->z /= _s; }
    vec3_t<T> operator/(const T _s) const {return vec3_t<T>(this->x / _s, this->y / _s, this->z / _s); }
    T operator*(const vec3_t<T>& _v) const { return this->x * _v.x + this->y * _v.y + this->z * _v.z; }
    void operator %=(const vec3_t<T>& _v) { *this=cross(_v); }
    vec3_t<T> operator %(const vec3_t<T>& _v) const { return vec3_t<T>(this->y * _v.z - this->z * _v.y, this->z * _v.x - this->x * _v.z, this->x * _v.y - this->y * _v.x); }
    T& operator[](uint32 _i) { return this->array[_i]; }
    const T& operator[]( uint32 _i ) const { return this->array[_i]; }

    friend vec3_t<T> operator+ (const T &_vl, const vec3_t<T> &_vr) { vec3_t<T> v(_vl + _vr.x, _vl + _vr.y, _vl + _vr.z); return v; }
    friend vec3_t<T> operator- (const T &_vl, const vec3_t<T> &_vr) { vec3_t<T> v(_vl - _vr.x, _vl - _vr.y, _vl - _vr.z); return v; }
    friend vec3_t<T> operator* (const T &_vl, const vec3_t<T> &_vr) { vec3_t<T> v(_vl * _vr.x, _vl * _vr.y, _vl * _vr.z); return v; }
    friend vec3_t<T> operator/ (const T &_vl, const vec3_t<T> &_vr) { vec3_t<T> v(_vl / _vr.x, _vl / _vr.y, _vl / _vr.z); return v; }

    // functions
    uint32 size(void) { return SIZE; }
    T length(void){ return std::sqrt((x * x) + (y * y) + (z * z)); }
    T magnitude(void){ return std::sqrt((x * x) + (y * y) + (z * z)); }
    void normalize(void) { T l = length(); if (l > 0.0) { T il = 1.0 / length(); x = x * il; y = y * il; z = z * il; } };
    vec3_t<T> normalized(void) { T l = length(); return (l > 0.0) ? (vec3_t<T>(x, y, z) * (1.0 / l)) : vec3_t<T>(x, y, z); }
    T distance(const vec3_t<T> &_v) const { return std::sqrt(((x - _v.x) * (x - _v.x)) + ((y - _v.y) * (y - _v.y)) + ((z - _v.z) * (z - _v.z))); }
    T dot(const vec3_t<T>& _v) const { return x * _v.x + y * _v.y + z * _v.z; }
    vec3_t<T> cross(const vec3_t<T>& _v) const { return vec3_t<T>( y * _v.z - z * _v.y, z * _v.x - x * _v.z, x * _v.y - y * _v.x); }

    static T dot(const vec3_t<T> &_v1, const vec3_t<T> &_v2) { T s = (_v1.x * _v2.x) + (_v1.y * _v2.y) + (_v1.z * _v2.z); return s; }
    static vec3_t<T> cross(const vec3_t<T> &_v1, const vec3_t<T> &_v2) { vec3_t<T> v((_v1.y * _v2.z) - (_v1.z * _v2.y), (_v1.z * _v2.x) - (_v1.x * _v2.z), (_v1.x * _v2.y) - (_v1.y * _v2.x)); return v; }
};

#endif // LIB_MATH_VECTOR_VEC3_HPP