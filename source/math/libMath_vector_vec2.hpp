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

#ifndef LIB_MATH_VECTOR_VEC2_HPP
#define LIB_MATH_VECTOR_VEC2_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"

template<typename T>
struct vec2_t
{
    // data structures, variables and constants
    static const uint32 SIZE = 2; // vec2_t == 2
    union
    {
        T array[SIZE];
        struct { T x = 0.0; T y = 0.0; };
    };
    
    // construnctors and destructor
    vec2_t(void) { this->x = 0.0; this->y = 0.0; }
    vec2_t(const T &_f) { this->x = _f; this->y = _f; }
    vec2_t(const T &_x, const T &_y) { this->x = _x; this->y = _y; }
    vec2_t(const vec2_t& _v) { this->x = _v.x; this->y = _v.y; }
    ~vec2_t(void) = default;
    
    // opperators
    bool operator==(const vec2_t& _v) const { return (this->x == _v.x && this->y == _v.y); }
    vec2_t& operator=(const vec2_t& _v) { this->x = _v.x; this->y = _v.y; return *this; }
    vec2_t operator- (void) const { vec2_t v(-this->x, -this->y); return v; }
    void operator+=(const vec2_t& _v) { this->x += _v.x; this->y += _v.y; }
    vec2_t operator+(const vec2_t& _v) const { return vec2_t(this->x + _v.x, this->y + _v.y); }
    void operator-=(const vec2_t& _v) { this->x -= _v.x; this->y -= _v.y; }
    vec2_t operator-(const vec2_t& _v) const { return vec2_t(this->x - _v.x, this->y - _v.y); }
    void operator*=(const T _s) { this->x *= _s; this->y *= _s; }
    vec2_t operator*(const T _s) const {    return vec2_t(_s * this->x, _s * this->y); }
    void operator /=(const T _s) { this->x /= _s; this->y /= _s; }
    vec2_t operator/(const T _s) const {return vec2_t(this->x / _s, this->y / _s); }
    T operator*(const vec2_t& _v) const { return this->x * _v.x + this->y * _v.y; }
    void operator %=(const vec2_t& _v) { *this=cross(_v); }
    T operator %(const vec2_t& _v) const { return this->x * _v.y - this->y * _v.x; }
    T& operator[](uint32 _i) { return this->array[_i]; }
    const T& operator[]( uint32 _i ) const { return this->array[_i]; }

    friend vec2_t operator+ (const T &_vl, const vec2_t &_vr) { vec2_t v(_vl + _vr.x, _vl + _vr.y); return v; }
    friend vec2_t operator- (const T &_vl, const vec2_t &_vr) { vec2_t v(_vl - _vr.x, _vl - _vr.y); return v; }
    friend vec2_t operator* (const T &_vl, const vec2_t &_vr) { vec2_t v(_vl * _vr.x, _vl * _vr.y); return v; }
    friend vec2_t operator/ (const T &_vl, const vec2_t &_vr) { vec2_t v(_vl / _vr.x, _vl / _vr.y); return v; }

    // functions
    uint32 size(void) { return SIZE; }
    T length(void){ return std::sqrt((x * x) + (y * y)); }
    T magnitude(void){ return std::sqrt((x * x) + (y * y)); }
    void normalize(void) { T l = length(); if (l > 0.0) { T il = 1.0 / length(); x = x * il; y = y * il; } };
    vec2_t normalized(void) { T l = length(); return (l > 0.0) ? (vec2_t(x, y) * (1.0 / l)) : vec2_t(x, y); }
    T distance(const vec2_t &_v) const { return std::sqrt(((x - _v.x) * (x - _v.x)) + ((y - _v.y) * (y - _v.y))); }
    T dot(const vec2_t& _v) const { return x * _v.x + y * _v.y; }
    T cross(const vec2_t& _v) const { return (x * _v.y) - (y * _v.x); }
    static T dot(const vec2_t &_v1, const vec2_t &_v2) { T s = (_v1.x * _v2.x) + (_v1.y * _v2.y); return s; }
    static T cross(const vec2_t &_v1, const vec2_t &_v2) { T f((_v1.x * _v2.y) - (_v1.y * _v2.x)); return f; }
};

#endif // LIB_MATH_VECTOR_VEC2_HPP

