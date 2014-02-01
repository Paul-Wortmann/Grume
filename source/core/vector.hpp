/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 *
 * Please note some of this code is derived form a vector class by Benedikt Bitterli.
 * See link below for Benedikt Bitterli's vector class an awesome physics tutorial.
 * http://www.gamedev.net/page/resources/_/technical/math-and-physics/a-verlet-based-approach-for-2d-game-physics-r2714
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include "types.hpp"

class vector_class
{
    private:
    protected:
    public:
        f2_type *vector_p;

};


class vector_2f_class
{
    private:
    protected:
    public:
        float x;
        float y;
        vector_2f_class( float ix = 0.0f, float iy = 0.0f ) : x( ix ), y( iy ) { };
       ~vector_2f_class() { };
        vector_2f_class operator*( float scalar ) { return vector_2f_class( x*scalar, y*scalar ); }
        vector_2f_class operator/( float scalar ) { return vector_2f_class( x/scalar, y/scalar ); }
        vector_2f_class operator+( vector_2f_class b ) { return vector_2f_class( x + b.x, y + b.y ); }
        vector_2f_class operator-( vector_2f_class b ) { return vector_2f_class( x - b.x, y - b.y ); }
        vector_2f_class operator-() { return vector_2f_class( -x, -y ); }
        float operator*( vector_2f_class b ) { return x*b.x + y*b.y; }
        void  operator=( vector_2f_class b ) { x = b.x; y = b.y; }
        void  operator+=( vector_2f_class b ) { x += b.x; y += b.y; }
        void  operator-=( vector_2f_class b ) { x -= b.x; y -= b.y; }
        void  operator*=( float scalar ) { x *= scalar; y *= scalar; }
        void  operator/=( float scalar ) { x /= scalar; y /= scalar; }
        bool  operator>=( vector_2f_class b ) { return x >= b.x && y >= b.y; }
        bool  operator<=( vector_2f_class b ) { return x <= b.x && y <= b.y; }
        bool  operator==( vector_2f_class b ) { return x == b.x && y == b.y; }
        bool  operator!=( vector_2f_class b ) { return x != b.x || y != b.y; }
        float angle(void); // radians
        int   angle_deg(void); // degrees
        float magnitude(void);
        float magnitude_squared(void);
        void  normalize(void);
};

class vector_2i_class
{
    private:
    protected:
    public:
        int x;
        int y;
        vector_2i_class( int ix = 0.0f, int iy = 0.0f ) : x( ix ), y( iy ) { };
       ~vector_2i_class() { };
        vector_2i_class operator*( int scalar ) { return vector_2i_class( x*scalar, y*scalar ); }
        vector_2i_class operator/( int scalar ) { return vector_2i_class( x/scalar, y/scalar ); }
        vector_2i_class operator+( vector_2i_class b ) { return vector_2i_class( x + b.x, y + b.y ); }
        vector_2i_class operator-( vector_2i_class b ) { return vector_2i_class( x - b.x, y - b.y ); }
        vector_2i_class operator-() { return vector_2i_class( -x, -y ); }
        int   operator*( vector_2i_class b ) { return x*b.x + y*b.y; }
        void  operator=( vector_2i_class b ) { x = b.x; y = b.y; }
        void  operator+=( vector_2i_class b ) { x += b.x; y += b.y; }
        void  operator-=( vector_2i_class b ) { x -= b.x; y -= b.y; }
        void  operator*=( int scalar ) { x *= scalar; y *= scalar; }
        void  operator/=( int scalar ) { x /= scalar; y /= scalar; }
        bool  operator>=( vector_2f_class b ) { return x >= b.x && y >= b.y; }
        bool  operator<=( vector_2f_class b ) { return x <= b.x && y <= b.y; }
        bool  operator==( vector_2i_class b ) { return x == b.x && y == b.y; }
        bool  operator!=( vector_2i_class b ) { return x != b.x || y != b.y; }
        int   magnitude(void);
        int   magnitude_squared(void);
        void  normalize(void);
};

#endif //VECTOR_H
