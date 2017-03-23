
#ifndef RE_LIGHT_TYPES_HPP
#define RE_LIGHT_TYPES_HPP

#include "../core/re_common_headers.hpp"
#include "../core/re_types.hpp"

namespace RoboEngine
{

    enum class e_lightType : uint32_t {NONE = 0, POINT = 1, DIRECTIONAL = 2};

    #define MAX_LIGHTS 10

    struct s_light
    {
        e_lightType type = e_lightType::NONE;
        glm::vec3   position = {};
        glm::vec3   direction = {};
        float       coneAngle = {};
        glm::vec3   attenuation = {};
        glm::vec3   color = {};
        float       ambientIntensity = {};
        float       diffuseIntensity = {};
    };

    struct s_lightModelDebug
    {
        uint32_t shader = 0;
        uint32_t vbo = 0;
        glm::mat4 mvp = {};
        glm::mat4 modelMatrix = glm::mat4(1.0f);
        glm::vec3 color = {};
        uint32_t n_vertices = 36;
        v3_f vertex[36] =
                            {{ -0.1, 0.1, 0.1 },
                            { -0.1, -0.1, -0.1 },
                            { -0.1, -0.1, 0.1 },
                            { -0.1, 0.1, -0.1 },
                            { 0.1, -0.1, -0.1 },
                            { -0.1, -0.1, -0.1 },
                            { 0.1, 0.1, -0.1 },
                            { 0.1, -0.1, 0.1 },
                            { 0.1, -0.1, -0.1 },
                            { 0.1, 0.1, 0.1 },
                            { -0.1, -0.1, 0.1 },
                            { 0.1, -0.1, 0.1 },
                            { 0.1, -0.1, -0.1 },
                            { -0.1, -0.1, 0.1 },
                            { -0.1, -0.1, -0.1 },
                            { -0.1, 0.1, -0.1 },
                            { 0.1, 0.1, 0.1 },
                            { 0.1, 0.1, -0.1 },
                            { -0.1, 0.1, 0.1 },
                            { -0.1, 0.1, -0.1 },
                            { -0.1, -0.1, -0.1 },
                            { -0.1, 0.1, -0.1 },
                            { 0.1, 0.1, -0.1 },
                            { 0.1, -0.1, -0.1 },
                            { 0.1, 0.1, -0.1 },
                            { 0.1, 0.1, 0.1 },
                            { 0.1, -0.1, 0.1 },
                            { 0.1, 0.1, 0.1 },
                            { -0.1, 0.1, 0.1 },
                            { -0.1, -0.1, 0.1 },
                            { 0.1, -0.1, -0.1 },
                            { 0.1, -0.1, 0.1 },
                            { -0.1, -0.1, 0.1 },
                            { -0.1, 0.1, -0.1 },
                            { -0.1, 0.1, 0.1 },
                            { 0.1, 0.1, 0.1 }};
    };

    // #endif // LIGHT_TYPES_HPP

    struct s_light_ogl
    {
        bool      isEnabled;
        bool      isLocal;
        bool      isSpot;
        glm::vec3 ambient;
        glm::vec3 color;
        glm::vec3 position;
        glm::vec3 halfVector;
        glm::vec3 coneDirection;
        float     spotCosCutoff;
        float     spotExponent;
        float     constantAttenuation;
        float     linearAttenuation;
        float     quadraticAttenuation;
    };

}

#endif // RE_LIGHT_TYPES_HPP
