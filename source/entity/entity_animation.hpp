


#ifndef ENTITY_ANIMATION_HPP
#define ENTITY_ANIMATION_HPP

#include "../includes.hpp"

struct sAnimationVecKey
{
    float64                time              = 0;
    glm::vec3              vector            = {};
};

struct sAnimationQuatKey
{
    float64                time              = 0;
    glm::quat              quat              = {};
};

struct sAnimationMeshKey
{
    float64                time              = 0;
    uint32                 value             = {};
};

struct sAnimationChannel
{
    std::string            name              = "";
    int32                  boneID            = -1;
    uint32                 numPositionKeys   = 0;
    sAnimationVecKey*      positionKey       = nullptr;
    uint32                 numRotationKeys   = 0;
    sAnimationQuatKey*     rotationKey       = nullptr;
    uint32                 numScalingKeys    = 0;
    sAnimationVecKey*      scalingKey        = nullptr;
};

struct sAnimationMeshChannel
{
    std::string            name              = "";
    uint32                 numKeys           = 0;
    sAnimationMeshKey*     meshKey           = nullptr;
};

struct sEntityAnimation
{
    std::string            name              = "";
    uint32                 numChannels       = 0;
    sAnimationChannel*     channel           = nullptr;
    uint32                 numMeshChannels   = 0;
    sAnimationMeshChannel* meshChannel       = nullptr;
    float64                duration          = 0.0; // duration in ticks
    float64                ticksPerSecond    = 0.0;
    float64                timeInSeconds     = 0.0;
    float64                animationTime     = 16.0; // never set this to 0.0 or lower

    float64                previousAnimTime  = 0.0;
    float64                currentAnimTime   = 0.0;
};

#endif // ENTITY_ANIMATION_HPP
