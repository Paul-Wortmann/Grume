


#ifndef GRAPHICS_ENGINE_UTILS_HPP
#define GRAPHICS_ENGINE_UTILS_HPP

#include "../includes.hpp"

glm::vec3 generateNormal(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c);
glm::vec3 generateTangent(glm::vec3 _normal);
glm::vec3 generateBitangent(glm::vec3 _normal, glm::vec3 _tangent);

#endif //GRAPHICS_ENGINE_UTILS_HPP
