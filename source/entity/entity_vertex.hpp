


#ifndef ENTITY_VERTEX_HPP
#define ENTITY_VERTEX_HPP

#include "../includes.hpp"

struct sEntityVertex
{
    glm::vec3  position    = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3  normal      = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec2  texcoord    = glm::vec2(0.0f, 0.0f);
    glm::vec3  tangent     = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3  bitangent   = glm::vec3(0.0f, 0.0f, 0.0f);
};

struct sEntityVertexBone
{
    glm::vec4  boneWeight  = glm::vec4(0.0);
    glm::ivec4 boneID      = glm::ivec4(0);
};

#endif // ENTITY_VERTEX_HPP
