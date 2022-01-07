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

#include "physics_resolution.hpp"


//      v1* cos(d1-p) * (m1 - m2) + 2 * m2 * v2 * cos(d2- p)
// vx = ----------------------------------------------------- * cos(p) + v1 * sin(d1-p) * cos(p + PI/2)
//                    m1 + m2
//
//      v1* cos(d1-p) * (m1 - m2) + 2 * m2 * v2 * cos(d2- p)
// vy = ----------------------------------------------------- * sin(p) + v1 * sin(d1-p) * sin(p + PI/2)
//                     m1 + m2
//
// More info can be found at https://en.wikipedia.org/wiki/Elastic_collision#Two-dimensional

// Elastic collision resolution 2D circle - circle
void gPhysicsResolution_circle_circle(float32 &_vx1, float32 &_vy1, float32 &_px1, float32 &_py1, const float32 &_r1, const float32 &_m1, const bool &_static1,
                                      float32 &_vx2, float32 &_vy2, float32 &_px2, float32 &_py2, const float32 &_r2, const float32 &_m2, const bool &_static2)
{
    const float32 opx1 = _px1;
    const float32 opy1 = _py1;
    const float32 opx2 = _px2;
    const float32 opy2 = _py2;
    const float32 ovx1 = _vx1;
    const float32 ovy1 = _vy1;
    const float32 ovx2 = _vx2;
    const float32 ovy2 = _vy2;

    // Distance vector components
    const float32 dx = _px2 - _px1;
    const float32 dy = _py2 - _py1;

    const float32 distance = sqrt(dx*dx + dy*dy);

    // Normalized distance vector components
    const float32 nx = dx / distance;
    const float32 ny = dy / distance;

    // Reposition the circles so they are just touching
    const float32 distanceC1 = (distance * (_r1 / (_r1 + _r2)));
    const float32 contactX = _px1 + nx * distanceC1;
    const float32 contactY = _py1 + ny * distanceC1;

    if (_static1)
    {
        // Circle 2
        _px2 = contactX + nx * (_r1 + _r2);
        _py2 = contactY + ny * (_r1 + _r2);
    }
    if (_static2)
    {
        // Circle 1
        _px1 = contactX - nx * (_r1 + _r2);
        _py1 = contactY - ny * (_r1 + _r2);
    }
    if ((!_static1) && (!_static1))
    {
        // Circle 1
        _px1 = contactX - nx * _r1;
        _py1 = contactY - ny * _r1;

        // Circle 2
        _px2 = contactX + nx * _r2;
        _py2 = contactY + ny * _r2;
    }

    // Get the direction and velocity of each Circle
    const float32 v1 = sqrt(_vx1 * _vx1 + _vy1 * _vy1);
    const float32 v2 = sqrt(_vx2 * _vx2 + _vy2 * _vy2);

    // Get the direction of travel of each circle
    const float32 d1 = atan2(_vy1, _vx1);
    const float32 d2 = atan2(_vy2, _vx2);

    // Get the direction from  circle 1 center to circle 2 center
    float32 directOfContact = atan2(ny, nx);

    // Calculate mass
    //const float32 m1 = pow(_r1, 3);
    //const float32 m2 = pow(_r2, 3);
    float32 m1 = _m1;
    float32 m2 = _m2;

    float32 mm  = m1 - m2;
    float32 mmt = m1 + m2;
    float32 v1s = v1 * sin(d1 - directOfContact);

    float32 cp = cos(directOfContact);
    float32 sp = sin(directOfContact);
    float32 cdp1 = v1 * cos(d1 - directOfContact);
    float32 cdp2 = v2 * cos(d2 - directOfContact);
    float32 cpp = cos((directOfContact + M_PI) / 2);
    float32 spp = sin((directOfContact + M_PI) / 2);

    float t = 0.5f;

    if (_static1)
    {
        _vx2 *= -1;
        _vy2 *= -1;
    }
    else if (_static2)
    {
        _vx1 *= -1;
        _vy1 *= -1;
    }
    else
    {
        t = (cdp1 * mm + 2 * m2 * cdp2) / mmt;
        _vx1 = t * cp + v1s * cpp;
        _vy1 = t * sp + v1s * spp;
        directOfContact += M_PI;
        const float32 v2s = v2 * sin(d2 - directOfContact);
        cdp1 = v1 * cos(d1 - directOfContact);
        cdp2 = v2 * cos(d2 - directOfContact);
        t = (cdp2 * -mm + 2 * m1 * cdp1) / mmt;
        _vx2 = t * -cp + v2s * -cpp;
        _vy2 = t * -sp + v2s * -spp;
    }

    if (_static1)
    {
        _px1 = opx1;
        _py1 = opy1;
        _vx1 = ovx1;
        _vy1 = ovy1;
    }
    if (_static2)
    {
        _px2 = opx2;
        _py2 = opy2;
        _vx2 = ovx2;
        _vy2 = ovy2;
    }
}

// Elastic collision resolution 2D aabs - aabs
void gPhysicsResolution_aabs_aabs(float32 &_vx1, float32 &_vy1, float32 &_px1, float32 &_py1, const float32 &_hw1, const float32 &_hh1, const float32 &_m1, const bool &_static1,
                                  float32 &_vx2, float32 &_vy2, float32 &_px2, float32 &_py2, const float32 &_hw2, const float32 &_hh2, const float32 &_m2, const bool &_static2)
{
    // Distance vector components
    const float32 dx = _px2 - _px1;
    const float32 dy = _py2 - _py1;

    // penetration distance x
    float pdx1 = fabs((_px1 + _hw1) - (_px2 - _hw2));
    float pdx2 = fabs((_px1 - _hw1) - (_px2 + _hw2));
    float pdx = (pdx1 < pdx2) ? pdx1 : pdx2;
    float xd = _hw1 + _hw2;
    pdx = (pdx < xd) ? pdx : xd;

    // penetration distance y
    float pdy1 = fabs((_py1 + _hh1) - (_py2 - _hh2));
    float pdy2 = fabs((_py1 - _hh1) - (_py2 + _hh2));
    float pdy = (pdy1 < pdy2) ? pdy1 : pdy2;
    float yd = _hh1 + _hh2;
    pdy = (pdy < yd) ? pdy : yd;

    pdx *= 2.0f;
    pdy *= 2.0f;

    if (_static1)
    {
        if (pdx < pdy)
        {
            if (_px2 > _px1)
            {
                _px2 = _px2 + pdx;
                _vx2 *= -1;
            }
            else
            {
                _px2 = _px2 - pdx;
                _vx2 *= -1;
            }
        }
        else
        {
            if (_py2 > _py1)
            {
                _py2 = _py2 + pdy;
                _vy2 *= -1;
            }
            else
            {
                _py2 = _py2 - pdy;
                _vy2 *= -1;
            }
        }
    }

    if (_static2)
    {
        if (pdx < pdy)
        {
            if (_px1 > _px2)
            {
                _px1 = _px1 + pdx;
                _vx1 *= -1;
            }
            else
            {
                _px1 = _px1 - pdx;
                _vx1 *= -1;
            }
        }
        else
        {
            if (_py1 > _py2)
            {
                _py1 = _py1 + pdy;
                _vy1 *= -1;
            }
            else
            {
                _py1 = _py1 - pdy;
                _vy1 *= -1;
            }
        }
    }
    else
    {
        pdx /= 2.0f;
        pdy /= 2.0f;

        if (pdx < pdy)
            _px1 = (_px1 > _px2) ? (_px1 + pdx) : (_px1 - pdx);
        else
            _py1 = (_py1 > _py2) ? (_py1 + pdy) : (_py1 - pdy);

        if (pdx < pdy)
            _px2 = (_px2 > _px1) ? (_px2 + pdx) : (_px2 - pdx);
        else
            _py2 = (_py2 > _py1) ? (_py2 + pdy) : (_py2 - pdy);

        // Velocity, both dynamic
        const float32 distance = sqrt(dx*dx + dy*dy);

        // Normalized distance vector components
        const float32 nx = dx / distance;
        const float32 ny = dy / distance;

        // Get the direction and velocity of each object
        const float32 v1 = sqrt(_vx1 * _vx1 + _vy1 * _vy1);
        const float32 v2 = sqrt(_vx2 * _vx2 + _vy2 * _vy2);

        // Get the direction of travel of each object
        const float32 d1 = atan2(_vy1, _vx1);
        const float32 d2 = atan2(_vy2, _vx2);

        // Get the direction from object 1 center to object 2 center
        float32 directOfContact = atan2(ny, nx);

        // Calculate mass
        //const float32 m1 = pow(_r1, 3);
        //const float32 m2 = pow(_r2, 3);
        float32 m1 = _m1;
        float32 m2 = _m2;

        float32 mm  = m1 - m2;
        float32 mmt = m1 + m2;
        float32 v1s = v1 * sin(d1 - directOfContact);

        float32 cp = cos(directOfContact);
        float32 sp = sin(directOfContact);
        float32 cdp1 = v1 * cos(d1 - directOfContact);
        float32 cdp2 = v2 * cos(d2 - directOfContact);
        float32 cpp = cos((directOfContact + M_PI) / 2);
        float32 spp = sin((directOfContact + M_PI) / 2);

        float t1 = (cdp1 * mm + 2 * m2 * cdp2) / mmt;
        directOfContact += M_PI;
        const float32 v2s = v2 * sin(d2 - directOfContact);
        cdp1 = v1 * cos(d1 - directOfContact);
        cdp2 = v2 * cos(d2 - directOfContact);
        float t2 = (cdp2 * -mm + 2 * m1 * cdp1) / mmt;

        _vx1 = t1 * cp + v1s * cpp;
        _vy1 = t1 * sp + v1s * spp;
        _vx2 = t2 * -cp + v2s * -cpp;
        _vy2 = t2 * -sp + v2s * -spp;
    }
}

// Elastic collision resolution 2D aabs - circle
void gPhysicsResolution_aabs_circle(float32 &_vx1, float32 &_vy1, float32 &_px1, float32 &_py1, const float32 &_hw1, const float32 &_hh1, const float32 &_m1, const bool &_static1,
                                    float32 &_vx2, float32 &_vy2, float32 &_px2, float32 &_py2, const float32 &_r2, const float32 &_m2, const bool &_static2)
{
    // Distance vector components
    const float32 dx = _px2 - _px1;
    const float32 dy = _py2 - _py1;

    // penetration distance x
    float pdx1 = fabs((_px1 + _hw1) - (_px2 - _r2));
    float pdx2 = fabs((_px1 - _hw1) - (_px2 + _r2));
    float pdx = (pdx1 < pdx2) ? pdx1 : pdx2;
    float xd = _hw1 + _r2;
    pdx = (pdx < xd) ? pdx : xd;

    // penetration distance y
    float pdy1 = fabs((_py1 + _hh1) - (_py2 - _r2));
    float pdy2 = fabs((_py1 - _hh1) - (_py2 + _r2));
    float pdy = (pdy1 < pdy2) ? pdy1 : pdy2;
    float yd = _hh1 + _r2;
    pdy = (pdy < yd) ? pdy : yd;

    pdx *= 2.0f;
    pdy *= 2.0f;

    if (_static1)
    {
        if (pdx < pdy)
        {
            if (_px2 > _px1)
            {
                _px2 = _px2 + pdx;
                _vx2 *= -1;
            }
            else
            {
                _px2 = _px2 - pdx;
                _vx2 *= -1;
            }
        }
        else
        {
            if (_py2 > _py1)
            {
                _py2 = _py2 + pdy;
                _vy2 *= -1;
            }
            else
            {
                _py2 = _py2 - pdy;
                _vy2 *= -1;
            }
        }
    }

    if (_static2)
    {
        if (pdx < pdy)
        {
            if (_px1 > _px2)
            {
                _px1 = _px1 + pdx;
                _vx1 *= -1;
            }
            else
            {
                _px1 = _px1 - pdx;
                _vx1 *= -1;
            }
        }
        else
        {
            if (_py1 > _py2)
            {
                _py1 = _py1 + pdy;
                _vy1 *= -1;
            }
            else
            {
                _py1 = _py1 - pdy;
                _vy1 *= -1;
            }
        }
    }
    else
    {
        pdx /= 2.0f;
        pdy /= 2.0f;

        if (pdx < pdy)
            _px1 = (_px1 > _px2) ? (_px1 + pdx) : (_px1 - pdx);
        else
            _py1 = (_py1 > _py2) ? (_py1 + pdy) : (_py1 - pdy);

        if (pdx < pdy)
            _px2 = (_px2 > _px1) ? (_px2 + pdx) : (_px2 - pdx);
        else
            _py2 = (_py2 > _py1) ? (_py2 + pdy) : (_py2 - pdy);

        // Velocity, both dynamic
        const float32 distance = sqrt(dx*dx + dy*dy);

        // Normalized distance vector components
        const float32 nx = dx / distance;
        const float32 ny = dy / distance;

        // Get the direction and velocity of each object
        const float32 v1 = sqrt(_vx1 * _vx1 + _vy1 * _vy1);
        const float32 v2 = sqrt(_vx2 * _vx2 + _vy2 * _vy2);

        // Get the direction of travel of each object
        const float32 d1 = atan2(_vy1, _vx1);
        const float32 d2 = atan2(_vy2, _vx2);

        // Get the direction from object 1 center to object 2 center
        float32 directOfContact = atan2(ny, nx);

        // Calculate mass
        //const float32 m1 = pow(_r1, 3);
        //const float32 m2 = pow(_r2, 3);
        float32 m1 = _m1;
        float32 m2 = _m2;

        float32 mm  = m1 - m2;
        float32 mmt = m1 + m2;
        float32 v1s = v1 * sin(d1 - directOfContact);

        float32 cp = cos(directOfContact);
        float32 sp = sin(directOfContact);
        float32 cdp1 = v1 * cos(d1 - directOfContact);
        float32 cdp2 = v2 * cos(d2 - directOfContact);
        float32 cpp = cos((directOfContact + M_PI) / 2);
        float32 spp = sin((directOfContact + M_PI) / 2);

        float t1 = (cdp1 * mm + 2 * m2 * cdp2) / mmt;
        directOfContact += M_PI;
        const float32 v2s = v2 * sin(d2 - directOfContact);
        cdp1 = v1 * cos(d1 - directOfContact);
        cdp2 = v2 * cos(d2 - directOfContact);
        float t2 = (cdp2 * -mm + 2 * m1 * cdp1) / mmt;

        _vx1 = t1 * cp + v1s * cpp;
        _vy1 = t1 * sp + v1s * spp;
        _vx2 = t2 * -cp + v2s * -cpp;
        _vy2 = t2 * -sp + v2s * -spp;
    }
}
