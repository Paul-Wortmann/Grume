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

#ifndef LIB_MATH_MATRIX_MAT2_HPP
#define LIB_MATH_MATRIX_MAT2_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"
#include "libMath_vector.hpp"

template<typename T>
struct mat2_t
{
    //--- Column major! ---
    static const uint32_t COLUMNS = 2;
    static const uint32_t ROWS    = 2;
    mat2_t(void) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = (i == j) ? 1.0f : 0.0f;}
    mat2_t(int _s) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = (_s == 1) ? (i == j) ? 1.0f : 0.0f : _s; }
    mat2_t(T _f) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = _f; }
    mat2_t(T _f00, T _f10,
         T _f01, T _f11)
         {
             data[0][0] = _f00; data[0][1] = _f01;
             data[1][0] = _f10; data[1][1] = _f11;
         }
    ~mat2_t(void) { }
    mat2_t& operator=(const mat2_t& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] = _m.array[i]; return *this; }
    mat2_t operator+(const mat2_t& _m) const { mat2_t _tMat2; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat2.array[i] = _m.array[i] + array[i]; return _tMat2; }
    void operator+=(const mat2_t& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] += _m.array[i]; }
    mat2_t operator-(const mat2_t& _m) const { mat2_t _tMat2; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat2.array[i] = _m.array[i] - array[i]; return _tMat2; }
    void operator-=(const mat2_t& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] -= _m.array[i]; }
    mat2_t operator*(const T _s) const { mat2_t _tMat2; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat2.array[i] = array[i] * _s; return _tMat2; }
    void operator*=(const T _s) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] *= _s; }
    mat2_t operator*(const mat2_t& _m) const { mat2_t _tMat2(0.0f); for(size_t i = 0; i < ROWS; i++) { for(size_t j = 0; j < COLUMNS; j++) { for(size_t k = 0; k < COLUMNS; k++) { _tMat2.data[i][j] += data[i][k] * _m.data[k][j]; } } } return _tMat2; }
    void operator*=(const mat2_t& _m) { mat2_t _tMat2(0.0f); for(size_t i = 0; i < ROWS; i++) { for(size_t j = 0; j < COLUMNS; j++) { for(size_t k = 0; k < COLUMNS; k++) { _tMat2.data[i][j] += data[i][k] * _m.data[k][j]; } } } for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] = _tMat2.array[i]; }

    vec2_t<T> operator*(const vec2_t<T>& _v) const 
    { 
        vec2_t<T> _tVec2(0.0f); 
        for(size_t i = 0; i < ROWS; i++) 
        { 
            for(size_t j = 0; j < COLUMNS; j++)
            {
                _tVec2.array[i] += data[i][j] * _v.array[j];
            }
        }
        return _tVec2;
    }

    T determinant(void)
    {
        return((data[0][0] * data[1][1]) - (data[1][0] * data[0][1]));
    }

    void transpose(void)
    {
        for(size_t i = 0; i < ROWS; i++)
        {
            for(size_t j = i; j < COLUMNS; j++)
            {
                if (i != j)
                {
                    T temp = data[j][i];
                    data[j][i] = data[i][j];
                    data[i][j] = temp;
                }
            }
        }
    }

    void setCR(T _f00, T _f10,
               T _f01, T _f11)
               {
                   data[0][0] = _f00; data[0][1] = _f01;
                   data[1][0] = _f10; data[1][1] = _f11;
               }
    
    void setRC(T _f00, T _f01,
               T _f10, T _f11)
               {
                   data[0][0] = _f00; data[0][1] = _f01;
                   data[1][0] = _f10; data[1][1] = _f11;
               }

    union
    {
        struct { T array[COLUMNS * ROWS] = {0.0f}; };
        struct { T data[COLUMNS][ROWS]; };
    };
    
/*  -- internal test code ---
    void draw(void)
    {
        std::cout << "--- mat2_t ---" << std::endl;
        for (size_t i = 0; i < COLUMNS * ROWS; i++)
        {
            std::cout << "[" << array[i] << "]";
            if ((i % ROWS) == (COLUMNS-1))
            std::cout << std::endl;
        }
        std::cout << "--------" << std::endl;
    }
*/

};

#endif // LIB_MATH_MATRIX_MAT2_HPP