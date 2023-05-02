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

template<typename T>
mat4_t<T> translate(const mat4_t<T> &_mat4_t, const vec4_t<T> &_transVec)
{
    mat4_t<T> tMat4(0.0f);
    for (size_t i = 0; i < (_mat4_t.COLUMNS * _mat4_t.ROWS); i++)
    {
        tMat4.array[i] = _mat4_t.array[i];
    }
    for (size_t i = 0; i < (_transVec.SIZE - 1); i++)
    {
        tMat4.data[i][tMat4.COLUMNS - 1] = tMat4.data[i][tMat4.COLUMNS - 1] + _transVec.array[i];
    }
    return tMat4;
}

template<typename T>
mat4_t<T> translate(const vec4_t<T> &_transVec)
{
    return translate(mat4_t<T>(1), _transVec);
}

template<typename T>
mat4_t<T> scale(const mat4_t<T> &_mat4_t, const vec4_t<T> &_scaleVec)
{
    mat4_t<T> tMat4(0.0f);
    for (size_t i = 0; i < (_mat4_t.COLUMNS * _mat4_t.ROWS); i++)
    {
        tMat4.array[i] = _mat4_t.array[i];
    }
    for (size_t i = 0; i < (_scaleVec.SIZE - 1); i++)
    {
        tMat4.data[i][i] = tMat4.data[i][i] * _scaleVec.array[i];
    }
    return tMat4;
}

template<typename T>
mat4_t<T> scale(const vec4_t<T> &_scaleVec)
{
    return scale(mat4_t<T>(1), _scaleVec);
}

template<typename T>
mat4_t<T> rotate(const mat4_t<T> &_mat4_t, const vec4_t<T> &_rotateVec)
{
    mat4_t<T> xMat4(1);
    if (_rotateVec.x != 0)
    {
        T xs = sin(_rotateVec.x);
        T xc = cos(_rotateVec.x);
        xMat4.data[1][1] = xc;
        xMat4.data[1][2] = xs * -1;
        xMat4.data[2][1] = xs;
        xMat4.data[2][2] = xc;
    }
    
    mat4_t<T> yMat4(1);
    if (_rotateVec.y != 0)
    {
        T ys = sin(_rotateVec.y);
        T yc = cos(_rotateVec.y);
        xMat4.data[0][0] = yc;
        xMat4.data[0][2] = ys;
        xMat4.data[2][0] = ys * -1;
        xMat4.data[2][2] = yc;
    }

    mat4_t<T> zMat4(1);
    if (_rotateVec.z != 0)
    {
        T zs = sin(_rotateVec.z);
        T zc = cos(_rotateVec.z);
        xMat4.data[0][0] = zc;
        xMat4.data[0][1] = zs * -1;
        xMat4.data[1][0] = zs;
        xMat4.data[1][1] = zc;
    }
    
    return _mat4_t * xMat4 * yMat4 * zMat4;
}

template<typename T>
mat4_t<T> rotate(const vec4_t<T> &_rotateVec)
{
    return rotate(mat4_t<T>(1), _rotateVec);
}

template<typename T>
mat4_t<T> orthographic(T _left, T _right, T _bottom, T _top, T _near, T _far)
{
    return mat4_t<T>();
}

template<typename T>
mat4_t<T> perspective(T _fov, T _aspect, T _near, T _far)
{
    mat4_t<T> tMat4(0.0f);
    tMat4.data[0][0] = 1.0f / (tanf( _fov / 2.0f) * _aspect);
    tMat4.data[1][1] = 1.0f / tanf( _fov / 2.0f);
    tMat4.data[2][2] = ((-1.0 * _near) - _far) / (_near - _far);
    tMat4.data[2][3] = 2.0f * _far * _near / (_near - _far);
    tMat4.data[3][2] = 1.0f;
    return tMat4;
}

template<typename T>
mat4_t<T> perspective(T _fov, T _near, T _far)
{
    mat4_t<T> tMat4(0.0f);
    tMat4.data[0][0] = 1.0f / tanf( _fov / 2.0f);
    tMat4.data[1][1] = 1.0f / tanf( _fov / 2.0f);
    tMat4.data[2][3] = -1.0f;
    tMat4.data[3][2] = -1.0f * ((_far * _near) / (_far - _near));
    return tMat4;
}

template<typename T>
mat4_t<T> lookAt(vec3_t<T> _position, vec3_t<T> _target, vec3_t<T> _upVector)
{
    return mat4_t<T>();
}
