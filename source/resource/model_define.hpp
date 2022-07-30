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

#ifndef MODEL_DEFINE_HPP
#define MODEL_DEFINE_HPP

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
/*
struct sModelMaterial
{
    std::string name  = {};
    float       Ns    = 0.0f;
    float       Ka[3] = {};
    float       Kd[3] = {};
    float       Ks[3] = {};
    float       d     = 0.0f;
    float       illum = 0.0f;
};

struct sModelVertex
{
    // x, y, z
    float vertex[3] = {};
    // x, y, z
    float normal[3] = {};
    // u, v
    float texcrd[2] = {};
};

struct sModelMesh
{
    std::string     name           = {};
    std::uint32_t   UID            = 0;

    //
    std::uint32_t   numIndex       = 0;
    std::uint32_t*  index          = nullptr;
    std::uint32_t   numVertex      = 0;
    sModelVertex*   vertex         = nullptr;

    // Material
    std::uint32_t   materialID     = 0;

    // Render Data
    std::uint32_t   VAO            = 0;
    std::uint32_t   VBO_vertices   = 0;
    std::uint32_t   IBO            = 0;
};

struct sModel
{
    // Linked list management
    sModel*         next           = nullptr;
    std::uint32_t   UID            = 0;

    // Data
    std::string     modelName      = {};
    std::string     materialFile   = {};
    std::uint32_t   numMesh        = 0;
    sModelMesh*     mesh           = nullptr;
    std::uint32_t   numMaterial    = 0;
    sModelMaterial* material       = nullptr;

    glm::mat4*      matrixInstance = {};
    std::uint32_t   numInstance    = 0;
};
*/
#endif // MODEL_DEFINE_HPP
