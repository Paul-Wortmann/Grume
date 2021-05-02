



#ifndef ASSIMP_TO_GLM_HPP
#define ASSIMP_TO_GLM_HPP

#include "../includes.hpp"

static inline glm::vec3 toVec3(const aiVector3D &v) { return glm::vec3(v.x, v.y, v.z); }
static inline glm::vec2 toVec2(const aiVector3D &v) { return glm::vec2(v.x, v.y); }
static inline glm::quat toQuat(const aiQuaternion &q) { return glm::quat(q.w, q.x, q.y, q.z); }
static inline glm::mat4 toMat4(const aiMatrix4x4 &m) { return glm::transpose(glm::make_mat4(&m.a1)); }
static inline glm::mat3 toMat3(const aiMatrix3x3 &m) { return glm::transpose(glm::make_mat3(&m.a1)); }

static inline void printMat4(const glm::mat4 &_mat4)
{
    double tArray[16] = {0.0};
    const float *tData = (const float*)glm::value_ptr(_mat4);
    for (int i = 0; i < 16; ++i)
    {
        tArray[i] = tData[i];
    }
    std::cout << "----- GLM-Mat4 ----" << std::endl;
    for (int i = 0; i < 16; ++i)
    {
        std::cout << "[" << tArray[i] << "] ";
        if ((i % 4) == 3)
        {
            std::cout << std::endl;
        }
    }
    std::cout << "-------------------" << std::endl;
}

#endif // ASSIMP_TO_GLM_HPP