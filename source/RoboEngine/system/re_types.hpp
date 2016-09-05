/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef RE_TYPES_HPP
#define RE_TYPES_HPP

#include <cstdint>
#include <cfloat>
#include <climits>
#include <tuple>
#include "re_math.hpp"

namespace RoboEngine
{

    template <typename T>
    struct v2_T
    {
        T x = 0;
        T y = 0;
        inline v2_T(): x(T(0)), y(T(0)) {}
        inline v2_T(const T& _vx, const T& _vy): x(_vx), x(_vy) {}
        inline virtual ~v2_T() = default;
        inline v2_T operator+(const v2_T& _v) { return v2_T(x + _v.x, y + _v.y); }
        inline v2_T operator-(const v2_T& _v) { return v2_T(x - _v.x, y - _v.y); }
        inline v2_T operator*(const v2_T& _v) { return v2_T(x * _v.x, y * _v.y); }
        inline v2_T operator/(const v2_T& _v) { return v2_T(x / _v.x, y / _v.y); }
        inline v2_T& operator+=(const v2_T& _v) { x += _v.x; y += _v.y; return *this; }
        inline v2_T& operator-=(const v2_T& _v) { x -= _v.x; y -= _v.y; return *this; }
        inline v2_T& operator*=(const v2_T& _v) { x *= _v.x; y *= _v.y; return *this; }
        inline v2_T& operator/=(const v2_T& _v) { x /= _v.x; y /= _v.y; return *this; }
        inline friend bool operator==(const v2_T& _L, const v2_T& _R) { return std::tie(_L.x, _L.y) == std::tie(_R.x, _R.y); }
        inline friend bool operator!=(const v2_T& _L, const v2_T& _R) { return !(_L == _R); }
        inline friend bool operator< (const v2_T& _L, const v2_T& _R) { return std::tie(_L.x, _L.y) < std::tie(_R.x, _R.y); }
        inline friend bool operator>=(const v2_T& _L, const v2_T& _R) { return !(_L < _R); }
        inline friend bool operator> (const v2_T& _L, const v2_T& _R) { return   _R < _L ; }
        inline friend bool operator<=(const v2_T& _L, const v2_T& _R) { return !(_R < _L); }
        inline v2_T operator-() const { return v2_T(-x, -y); }
        inline v2_T& operator*=(const T& _s) { x *= _s; y *= _s; return *this; }
        inline v2_T& operator/=(const T& _s) { x /= _s; y /= _s; return *this; }
    };

    struct v2_f
    {
        inline v2_f() = default;
        inline virtual ~v2_f() = default;
        inline v2_f(float _x, float _y) {x = _x; y = _y;}
        float x = 0.0f;
        float y = 0.0f;
        inline v2_f operator*(const float &_scalar) {return v2_f(x*_scalar, y*_scalar);}
        inline v2_f operator/(const float &_scalar) {return v2_f(x/_scalar, y/_scalar);}
        inline v2_f operator+(const v2_f &_b) {return v2_f(x + _b.x, y + _b.y);}
        inline v2_f operator-(const v2_f &_b) {return v2_f(x - _b.x, y - _b.y);}
        inline v2_f operator*(const v2_f &_b) {return v2_f(x * _b.x, y * _b.y);}
        inline v2_f operator/(const v2_f &_b) {return v2_f(x / _b.x, y / _b.y);}
        inline void operator+=(const v2_f &_b) {x += _b.x; y += _b.y;}
        inline void operator-=(const v2_f &_b) {x -= _b.x; y -= _b.y;}
        inline void operator*=(const v2_f &_b) {x *= _b.x; y *= _b.y;}
        inline void operator/=(const v2_f &_b) {x /= _b.x; y /= _b.y;}
        inline void operator*=(const float &_scalar) {x *= _scalar; y *= _scalar;}
        inline void operator/=(const float &_scalar) {x /= _scalar; y /= _scalar;}
        inline bool operator>(const v2_f &_b) {return ((x > _b.x)) && ((y > _b.y));}
        inline bool operator<(const v2_f &_b) {return ((x < _b.x)) && ((y < _b.y));}
        inline bool operator>=(const v2_f &_b) {return ((x >= _b.x)) && ((y >= _b.y));}
        inline bool operator<=(const v2_f &_b) {return ((x <= _b.x)) && ((y <= _b.y));}
        inline bool operator==(const v2_f &_b) {return floatsEqual(x, _b.x) && floatsEqual(y, _b.y);}
        inline bool operator!=(const v2_f &_b) {return !floatsEqual(x, _b.x) || !floatsEqual(y, _b.y);}
        inline v2_f operator-() {return v2_f(-x, -y);}
        inline v2_f& operator=(const v2_f &_b) {x = _b.x; y = _b.y; return *this;}
        inline float sqrt(const v2_f &_b) {return(std::sqrt(((x - _b.x) * (x - _b.x)) + ((y - _b.y) * (y - _b.y))));}
    };


    struct v3_f
    {
        v3_f() = default;
        virtual ~v3_f() = default;
        inline v3_f(float _x, float _y, float _z) {x = _x; y = _y; z = _z;}
        inline void set(float _x, float _y, float _z) {x = _x; y = _y; z = _z;}
        inline v3_f get(void) { return v3_f(x, y, z);}
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
    };

    struct v8_f
    {
        //v8_f() = default;
        //virtual ~v8_f() = default;
        //inline v8_f(float _x, float _y, float _z, float _nx, float _ny, float _nz, float _s, float _t) {x = _x; y = _y; z = _z; nx = _nx; ny = _ny; nz = _nz; s = _s; t = _t;}
        inline void set(float _x, float _y, float _z, float _nx, float _ny, float _nz, float _s, float _t) {x = _x; y = _y; z = _z; nx = _nx; ny = _ny; nz = _nz; s = _s; t = _t;}
        //inline v8_f get(void) { return v8_f(x, y, z, nx, ny, nz, s, t);}
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        float nx = 0.0f;
        float ny = 0.0f;
        float nz = 0.0f;
        float s = 0.0f;
        float t = 0.0f;
    };

    struct v3_uint16
    {
        v3_uint16() = default;
        virtual ~v3_uint16() = default;
        v3_uint16(uint16_t _x, uint16_t _y, uint16_t _z) {x = _x; y = _y; z = _z;}
        uint16_t x = 0;
        uint16_t y = 0;
        uint16_t z = 0;
    };

    struct v3_uint32
    {
        v3_uint32() = default;
        virtual ~v3_uint32() = default;
        v3_uint32(uint32_t _x, uint32_t _y, uint32_t _z) {x = _x; y = _y; z = _z;}
        uint32_t x = 0;
        uint32_t y = 0;
        uint32_t z = 0;
    };

    struct v3_uint64
    {
        v3_uint64() = default;
        virtual ~v3_uint64() = default;
        v3_uint64(uint64_t _x, uint64_t _y, uint64_t _z) {x = _x; y = _y; z = _z;}
        uint64_t x = 0;
        uint64_t y = 0;
        uint64_t z = 0;
    };

}

#endif // RE_TYPES_HPP



