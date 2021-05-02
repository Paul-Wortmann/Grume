

#include "graphics_engine_utils.hpp"

glm::vec3 generateNormal(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c)
{
    return glm::normalize(glm::cross(_b - _a, _c - _a));
}

glm::vec3 generateTangent(glm::vec3 _normal)
{
    glm::vec3 rTangent;
    glm::vec3 c1 = glm::cross(_normal, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec3 c2 = glm::cross(_normal, glm::vec3(0.0f, 1.0f, 0.0f));
    
    rTangent = (glm::length(c1) > glm::length(c2)) ? c1 : c2;
        
    return glm::normalize(rTangent);
}

glm::vec3 generateBitangent(glm::vec3 _normal, glm::vec3 _tangent)
{
    return glm::normalize(glm::cross(_normal, _tangent));
}