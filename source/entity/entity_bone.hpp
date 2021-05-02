


#ifndef ENTITY_BONE_HPP
#define ENTITY_BONE_HPP

#include "../includes.hpp"

struct sEntityBone
{
    int32       ID               = -1;
    int32       parentID         = -1;
    std::string name             = "";
    glm::mat4   transformNode    = glm::mat4(1); // node transformation matrix
    glm::mat4   transformPose    = glm::mat4(1); // inverse bind pose matrix
    glm::mat4   transformFinal   = glm::mat4(1); // the final animated transform
    glm::mat4   transformTemp    = glm::mat4(1); // an intermediary transform
};

#endif // ENTITY_BONE_HPP
