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

#ifndef ENTITY_MESH_HPP
#define ENTITY_MESH_HPP

#include "../core/includes.hpp"
#include "entity_vertex.hpp"
#include "entity_material.hpp"

struct sEntityMesh
{
    // Linked list
    sEntityMesh*       next         = nullptr;
    std::uint32_t      UID          = 0;

    // OpenGL
    std::uint32_t      VAO          = 0;
    std::uint32_t      VBO_vertices = 0;
    std::uint32_t      VBO_bones    = 0;
    std::uint32_t      IBO          = 0;
    
    // Data
    std::string        name         = {};
    std::uint32_t      numVertex    = 0;
    sEntityVertex*     vertex       = nullptr;
    sEntityVertexBone* vertexBone   = nullptr;
    std::uint32_t      numIndex     = 0;
    std::uint32_t*     index        = nullptr;
    sEntityMaterial*   material     = nullptr;
};

#endif //ENTITY_MESH_HPP
