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

#ifndef OBJ_LOADER_HPP
#define OBJ_LOADER_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

#include "../math/libMath.hpp"

/*
#ifndef vec3
struct vec3
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};
#endif // vec3

#ifndef vec2
struct vec2
{
    float x = 0.0f;
    float y = 0.0f;
};
#endif // vec2

#ifndef ivec3
struct ivec3
{
    std::uint32_t x = 0;
    std::uint32_t y = 0;
    std::uint32_t z = 0;
};
#endif // ivec3
*/

struct sOBJMesh
{
    std::string    name        = {};
    std::uint32_t  numVertex   = 0;
    vec3          *vertex      = nullptr;
    std::uint32_t  numNormal   = 0;
    vec3          *normal      = nullptr;
    std::uint32_t  numTexCoord = 0;
    vec2          *texCoord    = nullptr;
    std::uint32_t  numIndex    = 0;
    ivec3         *index       = nullptr;
};

struct sOBJ
{
    std::string    name    = {};
    std::uint32_t  numMesh = 0;
    sOBJMesh      *mesh    = nullptr;
};

void gFreeOBJ(sOBJ *&_obj);
void gLoadOBJ(sOBJ *&_obj, const std::string &_fileName);
void gSaveOBJ(sOBJ *&_obj, const std::string &_fileName);

#endif // OBJ_LOADER_HPP
