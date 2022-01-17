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
    uint32             UID          = 0;

    // OpenGL
    uint32             VAO          = 0;
    uint32             VBO_vertices = 0;
    uint32             VBO_bones    = 0;
    uint32             IBO          = 0;
    
    // Data
    uint32             numVertex    = 0;
    sEntityVertex*     vertex       = nullptr;
    sEntityVertexBone* vertexBone   = nullptr;
    uint32             numIndex     = 0;
    uint32*            index        = nullptr;
    sEntityMaterial*   material     = nullptr;
};

#endif //ENTITY_MESH_HPP
