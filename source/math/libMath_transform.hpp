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

#include "libMath_defines.hpp"
#include "libMath_matrix.hpp"
#include "libMath_vector.hpp"

// templated versions
template<typename T> mat4_t<T> translate(const mat4_t<T> &_mat4, const vec4_t<T> &_transVec);
template<typename T> mat4_t<T> translate(const vec4_t<T> &_transVec);
template<typename T> mat4_t<T> scale(const mat4_t<T> &_mat4, const vec4_t<T> &_scaleVec);
template<typename T> mat4_t<T> scale(const vec4_t<T> &_scaleVec);
template<typename T> mat4_t<T> rotate(const mat4_t<T> &_mat4, const vec4_t<T> &_rotateVec);
template<typename T> mat4_t<T> rotate(const vec4_t<T> &_rotateVec);
template<typename T> mat4_t<T> orthographic(T _left, T _right, T _bottom, T _top, T _near, T _far);
template<typename T> mat4_t<T> perspective(T _fov, T _aspect, T _near, T _far);
template<typename T> mat4_t<T> perspective(T _fov, T _near, T _far);
template<typename T> mat4_t<T> lookAt(vec3_t<T> _position, vec3_t<T> _target, vec3_t<T> _upVector);

// commonly used float32 versions
mat4 translate(const mat4 &_mat4, const vec4 &_transVec);
mat4 translate(const vec4 &_transVec);
mat4 scale(const mat4 &_mat4, const vec4 &_scaleVec);
mat4 scale(const vec4 &_scaleVec);
mat4 rotate(const mat4 &_mat4, const vec4 &_rotateVec);
mat4 rotate(const vec4 &_rotateVec);
mat4 orthographic(float32 _left, float32 _right, float32 _bottom, float32 _top, float32 _near, float32 _far);
mat4 perspective(float32 _fov, float32 _aspect, float32 _near, float32 _far);
mat4 perspective(float32 _fov, float32 _near, float32 _far);
mat4 lookAt(vec3 _position, vec3 _target, vec3 _upVector);
