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

#include <string>
#include <cstdint>

namespace RoboEngine
{

    struct v2_f
    {
        v2_f() = default;
        virtual ~v2_f() = default;
        v2_f(float _x, float _y) {x = _x; y = _y;}
        float x = 0.0f;
        float y = 0.0f;
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

}

#endif // RE_TYPES_HPP



