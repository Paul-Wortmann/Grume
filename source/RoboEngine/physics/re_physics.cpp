/**
 * Co_pyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
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
 * You should have received a co_py of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "re_physics.hpp"

namespace RoboEngine
{

    bool cube_collision(float _x1, float _y1, float _z1, float _w1, float _h1, float _d1, float _x2, float _y2, float _z2, float _w2, float _h2, float _d2)
    {
        return (((_x1-(_w1/2) < _x2+(_w2/2)) && (_x2+(_w2/2) > _x1-(_w1/2))) && ((_x2-(_w2/2) < _x1+(_w1/2)) && (_x1+(_w1/2) > _x2-(_w2/2))) && ((_y1-(_h1/2) < _y2+(_h2/2)) && (_y2+(_h2/2) > _y1-(_h1/2))) && ((_y2-(_h2/2) < _y1+(_h1/2)) && (_y1+(_h1/2) > _y2-(_h2/2))) && ((_z1-(_d1/2) < _z2+(_d2/2)) && (_z2+(_d2/2) > _z1-(_d1/2))) && ((_z2-(_d2/2) < _z1+(_d1/2)) && (_z1+(_d1/2) > _z2-(_d2/2))));
    }

    bool quadrangle_collision (float _x1, float _y1, float _w1, float _h1, float _x2, float _y2, float _w2, float _h2)
    {
        return (((_x1-(_w1/2) < _x2+(_w2/2)) && (_x2+(_w2/2) > _x1-(_w1/2))) && ((_x2-(_w2/2) < _x1+(_w1/2)) && (_x1+(_w1/2) > _x2-(_w2/2))) && ((_y1-(_h1/2) < _y2+(_h2/2)) && (_y2+(_h2/2) > _y1-(_h1/2))) && ((_y2-(_h2/2) < _y1+(_h1/2)) && (_y1+(_h1/2) > _y2-(_h2/2))));
    }

    bool circle_collision(float _x1, float _y1, float _r1, float _x2, float _y2, float _r2)
    {
        return (((_x1-_x2)*(_x1-_x2))+((_y1-_y2)*(_y1-_y2)) < ((_r1+_r2)*(_r1+_r2)));
    }

    bool sphere_collision(float _x1, float _y1, float _z1, float _r1, float _x2, float _y2, float _z2, float _r2)
    {
        return ((((_x1-_x2)*(_x1-_x2))+((_y1-_y2)*(_y1-_y2))+((_z1-_z2)*(_z1-_z2))) < ((_r1+_r2)*(_r1+_r2)));
    }

    float distance_2D(float _x1, float _y1, float _x2, float _y2)
    {
        return(sqrt(((_x1-_x2)*(_x1-_x2))+((_y1-_y2)*(_y1-_y2))));
    }

    float distance_3D(float _x1, float _y1, float _z1, float _x2, float _y2, float _z2)
    {
        return(sqrt(((_x1-_x2)*(_x1-_x2))+((_y1-_y2)*(_y1-_y2))+((_z1-_z2)*(_z1-_z2))));
    }

    bool point_in_circle (float _cx, float _cy, float _cr, float _px, float _py)
    {
        return ((((_px-_cx) * (_px-_cx)) + ((_py-_cy) * (_py-_cy))) < (_cr*_cr));
    }

    bool point_in_quadrangle (float _qx, float _qw, float _qy, float _qh, float _px, float _py)
    {
        return ((_px > (_qx-(_qw/2))) && (_px < (_qx+(_qw/2))) && (_py > (_qy-(_qh/2))) && (_py < (_qy+(_qh/2))));
    }

    bool point_in_diamond (float _dx, float _dw, float _dy, float _dh, float _px, float _py)
    {
        return ((_py >= (_dy - (_dh/2.0f))) && (_py <= (_dy + (_dh/2.0f))) && (_px >= (_dx - ((_dw/2.0f) - (_py - _dy)))) && (_px <= (_dx + ((_dw/2.0f) - (_py - _dy)))));
    }

    float rotate_point_2D_x(float _cx,float _cy,float _px,float _py,int32_t _angle)
    {
        return(((_px-_cx) * cos(_angle) - (_py-_cy) * sin(_angle))+_cx);
    }

    float rotate_point_2D_y(float _cx,float _cy,float _px,float _py,int32_t _angle)
    {
        return(((_px-_cx) * sin(_angle) + (_py-_cy) * cos(_angle))+_cy);
    }

}
