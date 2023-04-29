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

#ifndef LIB_MATH_MATRIX_MAT4_HPP
#define LIB_MATH_MATRIX_MAT4_HPP

#include "libMath_defines.hpp"
#include "libMath_includes.hpp"
#include "libMath_matrix_mat3.hpp"
#include "libMath_vector.hpp"

    #include <iostream> // Used for test draw function

template<typename T>
struct mat4_t
{
    //--- Column major! ---
    static const uint32_t COLUMNS = 4;
    static const uint32_t ROWS    = 4;
    static const uint32_t SIZE    = COLUMNS * ROWS;
    
    // constructors and destructor
    mat4_t(void) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = (i == j) ? 1.0f : 0.0f;}
    mat4_t(int _s) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = (_s == 1) ? (i == j) ? 1.0f : 0.0f : _s; }
    mat4_t(T _f) { for (size_t i = 0; i < ROWS; i++) for (size_t j = 0; j < COLUMNS; j++) data[j][i] = _f; }
    mat4_t(T _f00, T _f10, T _f20, T _f30,
         T _f01, T _f11, T _f21, T _f31,
         T _f02, T _f12, T _f22, T _f32,
         T _f03, T _f13, T _f23, T _f33)
         {
             data[0][0] = _f00; data[0][1] = _f01; data[0][2] = _f02; data[0][3] = _f03;
             data[1][0] = _f10; data[1][1] = _f11; data[1][2] = _f12; data[1][3] = _f13;
             data[2][0] = _f20; data[2][1] = _f21; data[2][2] = _f22; data[2][3] = _f23;
             data[3][0] = _f30; data[3][1] = _f31; data[3][2] = _f32; data[3][3] = _f33;
         }
    ~mat4_t(void) { }
    
    // operators
    mat4_t& operator=(const mat4_t& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] = _m.array[i]; return *this; }
    mat4_t operator+(const mat4_t& _m) const { mat4_t _tMat4; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat4.array[i] = _m.array[i] + array[i]; return _tMat4; }
    void operator+=(const mat4_t& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] += _m.array[i]; }
    mat4_t operator-(const mat4_t& _m) const { mat4_t _tMat4; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat4.array[i] = _m.array[i] - array[i]; return _tMat4; }
    void operator-=(const mat4_t& _m) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] -= _m.array[i]; }
    mat4_t operator*(const T _s) const { mat4_t _tMat4; for (size_t i = 0; i < COLUMNS * ROWS; i++) _tMat4.array[i] = array[i] * _s; return _tMat4; }
    void operator*=(const T _s) { for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] *= _s; }
    mat4_t operator*(const mat4_t& _m) const { mat4_t _tMat4(0.0f); for(size_t i = 0; i < ROWS; i++) { for(size_t j = 0; j < COLUMNS; j++) { for(size_t k = 0; k < COLUMNS; k++) { _tMat4.data[i][j] += (data[i][k] * _m.data[k][j]); } } } return _tMat4; }
    void operator*=(const mat4_t& _m) { mat4_t _tMat4(0.0f); for(size_t i = 0; i < ROWS; i++) { for(size_t j = 0; j < COLUMNS; j++) { for(size_t k = 0; k < COLUMNS; k++) { _tMat4.data[i][j] += data[i][k] * _m.data[k][j]; } } } for (size_t i = 0; i < COLUMNS * ROWS; i++) array[i] = _tMat4.array[i]; }
    vec4_t<T> operator*(const vec4_t<T>& _v) const { vec4_t<T> _tVec4(0.0f); for(size_t i = 0; i < ROWS; i++) { for(size_t j = 0; j < COLUMNS; j++) { _tVec4.array[i] += data[i][j] * _v.array[j]; } } return _tVec4; }

    // functions
    uint32 size(void) { return SIZE; }
    T determinant(void)
    {
        mat3_t<T>  aMat3(0.0f);
        aMat3.setRC(data[1][1], data[1][2], data[1][3],
                    data[2][1], data[2][2], data[2][3],
                    data[3][1], data[3][2], data[3][3]);
        mat3_t<T>  bMat3(0.0f);
        bMat3.setRC(data[1][0], data[1][2], data[1][3],
                    data[2][0], data[2][2], data[2][3],
                    data[3][0], data[3][2], data[3][3]);
        mat3_t<T>  cMat3(0.0f);
        cMat3.setRC(data[1][0], data[1][1], data[1][3],
                    data[2][0], data[2][1], data[2][3],
                    data[3][0], data[3][1], data[3][3]);
        mat3_t<T>  dMat3(0.0f);
        dMat3.setRC(data[1][0], data[1][1], data[1][2],
                    data[2][0], data[2][1], data[2][2],
                    data[3][0], data[3][1], data[3][2]);
        
        T det = 0;
        det += data[0][0] * aMat3.determinant();
        det += data[0][1] * bMat3.determinant() * -1;
        det += data[0][2] * cMat3.determinant();
        det += data[0][3] * dMat3.determinant() * -1;
        return det;
    }
    
    mat4_t inverse(void)
    {
        // Determinant
        mat4_t tMat4(0.0f);
        T det = determinant();
        if (det == 0)
        {
            return tMat4;
        }
        //std::cout << "Det: " << det << std::endl;
        float32 detInv = 1.0f / det; // Has to be a float32 and not a T because floating point math is evil!
        
        // Adjunct
        transpose();

        for (size_t i = 0; i < ROWS; i++)
        {
            for (size_t j = 0; j < COLUMNS; j++)
            {
                uint32_t count = 0;
                mat3_t<T>     tMat3(0.0f);
                for (size_t k = 0; k < ROWS; k++)
                {
                    for (size_t l = 0; l < COLUMNS; l++)
                    {
                        if ((i != k) && (j != l))
                        {
                            tMat3.array[count] = data[k][l];
                            count++;
                        }
                    }
                }            
                tMat4.data[i][j] = tMat3.determinant();
                if ((i+j) % 2 != 0)
                {
                    tMat4.data[i][j] *= -1;
                }
            }
        }
        transpose();
        
        // Inverse
        for (size_t i = 0; i < (COLUMNS * ROWS); i++)
        {
            tMat4.array[i] *= detInv;
        }
        return(tMat4);
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

    void setCR(T _f00, T _f10, T _f20, T _f30,
               T _f01, T _f11, T _f21, T _f31,
               T _f02, T _f12, T _f22, T _f32,
               T _f03, T _f13, T _f23, T _f33)
               {
                   data[0][0] = _f00; data[0][1] = _f01; data[0][2] = _f02; data[0][3] = _f03;
                   data[1][0] = _f10; data[1][1] = _f11; data[1][2] = _f12; data[1][3] = _f13;
                   data[2][0] = _f20; data[2][1] = _f21; data[2][2] = _f22; data[2][3] = _f23;
                   data[3][0] = _f30; data[3][1] = _f31; data[3][2] = _f32; data[3][3] = _f33;
               }
    
    void setRC(T _f00, T _f01, T _f02, T _f03,
               T _f10, T _f11, T _f12, T _f13,
               T _f20, T _f21, T _f22, T _f23,
               T _f30, T _f31, T _f32, T _f33)
               {
                   data[0][0] = _f00; data[0][1] = _f01; data[0][2] = _f02; data[0][3] = _f03;
                   data[1][0] = _f10; data[1][1] = _f11; data[1][2] = _f12; data[1][3] = _f13;
                   data[2][0] = _f20; data[2][1] = _f21; data[2][2] = _f22; data[2][3] = _f23;
                   data[3][0] = _f30; data[3][1] = _f31; data[3][2] = _f32; data[3][3] = _f33;
               }

    union
    {
        struct { T array[COLUMNS * ROWS] = {0.0f}; };
        struct { T data[COLUMNS][ROWS]; };
    };
    
//  -- internal test code ---
    void draw(void)
    {
        std::cout << "--- mat4_t ---" << std::endl;
        for (size_t i = 0; i < COLUMNS * ROWS; i++)
        {
            std::cout << "[" << array[i] << "]";
            if ((i % ROWS) == (COLUMNS-1))
            std::cout << std::endl;
        }
        std::cout << "--------" << std::endl;
    }
//

};

#endif // LIB_MATH_MATRIX_MAT4_HPP