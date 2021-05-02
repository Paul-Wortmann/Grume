


#ifndef ENTITY_MESH_HPP
#define ENTITY_MESH_HPP

#include "../includes.hpp"
#include "entity_vertex.hpp"
#include "entity_material.hpp"

struct sEntityMesh
{
    sEntityMesh*       next         = nullptr;
    
    uint32             VAO          = 0;
    uint32             VBO_vertices = 0;
    uint32             VBO_bones    = 0;
    uint32             IBO          = 0;
    
    uint32             numVertex    = 0;
    sEntityVertex*     vertex       = nullptr;
    sEntityVertexBone* vertexBone   = nullptr;
    uint32             numIndex     = 0;
    uint32*            index        = nullptr;
    sEntityMaterial*   material     = nullptr;
};

#endif //ENTITY_MESH_HPP
