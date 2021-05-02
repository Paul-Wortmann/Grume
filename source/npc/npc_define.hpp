


#ifndef NPC_DEFINE_HPP
#define NPC_DEFINE_HPP

#include "../includes.hpp"

struct sNPC
{
    // Linked list management
    sNPC*     next     = nullptr;
    
    // Data
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale    = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
};

#endif //NPC_DEFINE_HPP
