/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef ENTITY_COMPONENT_MODEL_HPP
#define ENTITY_COMPONENT_MODEL_HPP

#include "defines.hpp"
#include "includes.hpp"

struct sBone
{
    int32_t                ID                = -1;
    int32_t                parentID          = -1;
    std::string            name              = "";
    glm::mat4              transformNode     = glm::mat4(1); // node transformation matrix
    glm::mat4              transformPose     = glm::mat4(1); // inverse bind pose matrix
    glm::mat4              transformFinal    = glm::mat4(1); // the final animated transform
    glm::mat4              transformTemp     = glm::mat4(1); // an intermediary transform
};

struct sVertex
{
    glm::vec3              position          = {};
    glm::vec3              normal            = glm::vec3(0.0, 0.0, 1.0);
    glm::vec3              tangent           = glm::vec3(1.0, 0.0, 0.0);
    glm::vec3              bitangent         = glm::vec3(0.0, 1.0, 0.0);
    glm::vec2              texcoord          = {};
};

struct sVertexBone
{
    glm::vec4              boneWeight        = glm::vec4(0.0);
    glm::ivec4             boneID            = glm::ivec4(0);
};

struct sTexture
{
    std::string            fileName          = "";
    uint32_t               ID                = 0;
};

struct sMaterial
{
    int32_t                ID                = -1;
    sTexture               diffuse           = {};
    sTexture               normal            = {};
    sTexture               specular          = {};
};

struct sMesh
{
    uint32_t               VAO               = 0;
    uint32_t               VBO_vertices      = 0;
    uint32_t               VBO_bones         = 0;
    uint32_t               IBO               = 0;

    uint64_t               numVertex         = 0;
    sVertex*               vertex            = nullptr;
    sVertexBone*           vertexBone        = nullptr;
    uint64_t               numIndex          = 0;
    uint32_t*              index             = nullptr;
    int32_t                materialID        = -1;
};

struct sAnimationVecKey
{
    double                 time              = 0;
    glm::vec3              vector            = {};
};

struct sAnimationQuatKey
{
    double                 time              = 0;
    glm::quat              quat              = {};
};

struct sAnimationMeshKey
{
    double                 time              = 0;
    uint32_t               value             = {};
};

struct sAnimationChannel
{
    std::string            name              = "";
    int32_t                boneID            = -1;
    uint32_t               numPositionKeys   = 0;
    sAnimationVecKey*      positionKey       = nullptr;
    uint32_t               numRotationKeys   = 0;
    sAnimationQuatKey*     rotationKey       = nullptr;
    uint32_t               numScalingKeys    = 0;
    sAnimationVecKey*      scalingKey        = nullptr;
};

struct sAnimationMeshChannel
{
    std::string            name              = "";
    uint32_t               numKeys           = 0;
    sAnimationMeshKey*     meshKey           = nullptr;
};

struct sAnimation
{
    std::string            name              = "";
    uint32_t               numChannels       = 0;
    sAnimationChannel*     channel           = nullptr;
    uint32_t               numMeshChannels   = 0;
    sAnimationMeshChannel* meshChannel       = nullptr;
    double                 duration          = 0.0; // duration in ticks
    double                 ticksPerSecond    = 0.0;
    double                 timeInSeconds     = 0.0;
    double                 animationTime     = 16.0; // never set this to 0.0 or lower

    double                 previousAnimTime  = 0.0;
    double                 currentAnimTime   = 0.0;
};

struct sEntityModel
{
    sEntityModel*          next              = nullptr;
    std::string            fileName          = "";
    bool                   animated          = false;
    uint32_t               numMesh           = 0;
    sMesh*                 mesh              = nullptr;
    uint32_t               numInstances      = 0;
    glm::mat4*             modelMatrix       = nullptr;

    glm::mat4              inverseTransform  = glm::mat4(1); // global inverse transformation matrix
    uint32_t               numBones          = 0;
    sBone*                 bone              = nullptr;
    uint32_t               numAnimations     = 0;
    sAnimation*            animation         = nullptr;
    uint32_t               currentAnimation  = 0;
    uint32_t               numMaterials      = 0;
    sMaterial*             material          = nullptr;
};

#endif //ENTITY_COMPONENT_MODEL_HPP

