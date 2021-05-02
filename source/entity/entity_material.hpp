


#ifndef ENTITY_MATERIAL_HPP
#define ENTITY_MATERIAL_HPP

#include "../includes.hpp"
#include "entity_texture.hpp"

struct sEntityMaterial
{
    sEntityMaterial* next = nullptr;
    sEntityTexture*  diffuse;
    sEntityTexture*  normal;
    sEntityTexture*  specular;
    sEntityTexture*  emissive;
    float32          shininess = 32.0f;
};

#endif // ENTITY_MATERIAL_HPP
