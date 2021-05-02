


#ifndef ENTITY_MODEL_HPP
#define ENTITY_MODEL_HPP

#include "../includes.hpp"
#include "entity_animation.hpp"
#include "entity_bone.hpp"
#include "entity_material.hpp"
#include "entity_mesh.hpp"

struct sEntityModel
{
    // Linked list management
    sEntityModel*     next             = nullptr;

    // Information
    bool              animated         = false;
    std::string       fileName         = {};

    // Mesh
    uint32            numMesh          = 0;
    sEntityMesh*      mesh             = nullptr;

    // Bones
    glm::mat4         inverseTransform = glm::mat4(1); // global inverse transformation matrix
    uint32            numBones         = 0;
    sEntityBone*      bone             = nullptr;

    // Animation
    uint32            numAnimations    = 0;
    sEntityAnimation* animation        = nullptr;
    uint32            currentAnimation = 0;
};

#endif // ENTITY_MODEL_HPP
