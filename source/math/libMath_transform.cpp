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

#include "libMath_transform.hpp"

mat4 translate(const mat4 &_mat4, const vec4 &_transVec)
{
    mat4 tMat4(0.0f);
    for (size_t i = 0; i < (_mat4.COLUMNS * _mat4.ROWS); i++)
    {
        tMat4.array[i] = _mat4.array[i];
    }
    for (size_t i = 0; i < (_transVec.SIZE - 1); i++)
    {
        tMat4.data[i][tMat4.COLUMNS - 1] = tMat4.data[i][tMat4.COLUMNS - 1] + _transVec.array[i];
    }
    return tMat4;
}

mat4 translate(const vec4 &_transVec)
{
    return translate(mat4(1), _transVec);
}

mat4 scale(const mat4 &_mat4, const vec4 &_scaleVec)
{
    mat4 tMat4(0.0f);
    for (size_t i = 0; i < (_mat4.COLUMNS * _mat4.ROWS); i++)
    {
        tMat4.array[i] = _mat4.array[i];
    }
    for (size_t i = 0; i < (_scaleVec.SIZE - 1); i++)
    {
        tMat4.data[i][i] = tMat4.data[i][i] * _scaleVec.array[i];
    }
    return tMat4;
}

mat4 scale(const vec4 &_scaleVec)
{
    return scale(mat4(1), _scaleVec);
}

mat4 rotate(const mat4 &_mat4, const vec4 &_rotateVec)
{
    mat4 xMat4(1);
    if (_rotateVec.x != 0)
    {
        float64 xs = sin(_rotateVec.x);
        float64 xc = cos(_rotateVec.x);
        xMat4.data[1][1] = xc;
        xMat4.data[1][2] = xs * -1;
        xMat4.data[2][1] = xs;
        xMat4.data[2][2] = xc;
    }
    
    mat4 yMat4(1);
    if (_rotateVec.y != 0)
    {
        float64 ys = sin(_rotateVec.y);
        float64 yc = cos(_rotateVec.y);
        xMat4.data[0][0] = yc;
        xMat4.data[0][2] = ys;
        xMat4.data[2][0] = ys * -1;
        xMat4.data[2][2] = yc;
    }

    mat4 zMat4(1);
    if (_rotateVec.z != 0)
    {
        float64 zs = sin(_rotateVec.z);
        float64 zc = cos(_rotateVec.z);
        xMat4.data[0][0] = zc;
        xMat4.data[0][1] = zs * -1;
        xMat4.data[1][0] = zs;
        xMat4.data[1][1] = zc;
    }
    
    return _mat4 * xMat4 * yMat4 * zMat4;
}

mat4 rotate(const vec4 &_rotateVec)
{
    return rotate(mat4(1), _rotateVec);
}

mat4 orthographic(float64 _left, float64 _right, float64 _bottom, float64 _top, float64 _near, float64 _far)
{
    return mat4();
}

mat4 perspective(float64 _fov, float64 _aspect, float64 _near, float64 _far)
{
    mat4 tMat4(0.0f);
    tMat4.data[0][0] = 1.0f / (tanf( _fov / 2.0f) * _aspect);
    tMat4.data[1][1] = 1.0f / tanf( _fov / 2.0f);
    tMat4.data[2][2] = ((-1.0 * _near) - _far) / (_near - _far);
    tMat4.data[2][3] = 2.0f * _far * _near / (_near - _far);
    tMat4.data[3][2] = 1.0f;
    return tMat4;
}

mat4 perspective(float64 _fov, float64 _near, float64 _far)
{
    mat4 tMat4(0.0f);
    tMat4.data[0][0] = 1.0f / tanf( _fov / 2.0f);
    tMat4.data[1][1] = 1.0f / tanf( _fov / 2.0f);
    tMat4.data[2][3] = -1.0f;
    tMat4.data[3][2] = -1.0f * ((_far * _near) / (_far - _near));
    return tMat4;
}

mat4 lookAt(vec3 _position, vec3 _target, vec3 _upVector)
{
    return mat4();
}
