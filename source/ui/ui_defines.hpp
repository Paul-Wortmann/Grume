


#ifndef UI_DEFINE_HPP
#define UI_DEFINE_HPP

#include "../includes.hpp"
#include "../entity/entity_texture.hpp"
#include "../entity/entity_model.hpp"

struct sUIComponent
{
    // Linked list
    sUIComponent*    next          = nullptr;

    // Infomation
    std::string      name          = "";
    bool             enabled       = true;
    bool             hover         = false;
    bool             activated     = false;

    // Base
    glm::vec3       position       = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3       scale          = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3       rotation       = glm::vec3(0.0f, 0.0f, 0.0f);

    // Graphics
    sEntityModel*    model         = nullptr;
    glm::mat4        modelMatrix   = glm::mat4(1);
    sEntityTexture*  normalTexture = nullptr;
    sEntityTexture*  hoverTexture  = nullptr;
    sEntityTexture*  activeTexture = nullptr;

};

#endif //UI_HPP

