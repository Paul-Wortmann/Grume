


#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../includes.hpp"
#include "entity_material.hpp"
#include "entity_model.hpp"
#include "entity_physics.hpp"

enum eEntityOwner: uint16
{
    ownerNone = 0,
    ownerUI   = 1,
    ownerMap  = 2
};

struct sEntity
{
    // Linked list
    sEntity*         next        = nullptr;

    // Infomation
    std::string      name        = "";
    bool             enabled     = true;
    eEntityOwner     owner       = eEntityOwner::ownerNone;

    // Base
    glm::vec3        position    = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3        scale       = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3        rotation    = glm::vec3(0.0f, 0.0f, 0.0f);

    // Graphics
    sEntityModel*    model       = nullptr;
    glm::mat4        modelMatrix = glm::mat4(1);
    sEntityMaterial* material    = nullptr;

    // Physics
    //sEntityPhysics* physics  = nullptr;
};

#endif //ENTITY_HPP

