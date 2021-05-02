



#include "animation_engine.hpp"

uint32_t cAnimationEngine::initialize(void)
{
    return EXIT_SUCCESS;
}

void cAnimationEngine::terminate(void)
{
    
}

glm::mat4 cAnimationEngine::m_calculateTransformPosition(double _currentAnimTime, uint32_t _channel)
{
    sAnimationChannel* channel = &m_entityTemp->model->animation[m_entityTemp->model->currentAnimation].channel[_channel];

    glm::vec3 newVector = channel->positionKey[0].vector;
    
    if (channel->numPositionKeys > 1)
    {
        uint32_t i1 = 0;
        uint32_t i2 = 0;

        for (size_t i = 0; i < channel->numPositionKeys - 1; ++i)
        {
            if (_currentAnimTime < channel->positionKey[i + 1].time)
            {
                i1 = i;
                break;
            }
        }
        i2 = (i1 + 1) % channel->numPositionKeys;
        
        float deltaTime = (float)(channel->positionKey[i2].time - channel->positionKey[i1].time);
        float factor = (_currentAnimTime - (float)channel->positionKey[i1].time) / deltaTime;

        const glm::vec3& startKey = channel->positionKey[i1].vector;
        const glm::vec3& endKey = channel->positionKey[i2].vector;
        glm::vec3 deltaKey = endKey - startKey;
        newVector = startKey + factor * deltaKey;        
    }
    return glm::translate(glm::mat4(1.0f), newVector);
}

glm::mat4 cAnimationEngine::m_calculateTransformRotation(double _currentAnimTime, uint32_t _channel)
{
    sAnimationChannel* channel = &m_entityTemp->model->animation[m_entityTemp->model->currentAnimation].channel[_channel];

    glm::quat newQuat = channel->rotationKey[0].quat;
    if (channel->numRotationKeys > 1)
    {
        uint32_t i1 = 0;
        uint32_t i2 = 0;

        for (size_t i = 0; i < channel->numRotationKeys - 1; ++i)
        {
            if (_currentAnimTime < channel->rotationKey[i + 1].time)
            {
                i1 = i;
                break;
            }
        }
        i2 = (i1 + 1) % channel->numRotationKeys;
        
        float deltaTime = (float)(channel->rotationKey[i2].time - channel->rotationKey[i1].time);
        float factor = (_currentAnimTime - (float)channel->rotationKey[i1].time) / deltaTime;

        const glm::quat& startKey = channel->rotationKey[i1].quat;
        const glm::quat& endKey = channel->rotationKey[i2].quat;

        newQuat = glm::slerp(startKey, endKey, factor);
    }
    return glm::toMat4(newQuat);
}

glm::mat4 cAnimationEngine::m_calculateTransformScale(double _currentAnimTime, uint32_t _channel)
{
    sAnimationChannel* channel = &m_entityTemp->model->animation[m_entityTemp->model->currentAnimation].channel[_channel];

    glm::vec3 newVector = channel->scalingKey[0].vector;
    
    if (channel->numScalingKeys > 1)
    {
        uint32_t i1 = 0;
        uint32_t i2 = 0;

        for (std::size_t i = 0; i < channel->numScalingKeys - 1; ++i)
        {
            if (_currentAnimTime < channel->scalingKey[i + 1].time)
            {
                i1 = i;
                break;
            }
        }
        i2 = (i1 + 1) % channel->numScalingKeys;
        
        float deltaTime = (float)(channel->scalingKey[i2].time - channel->scalingKey[i1].time);
        float factor = (_currentAnimTime - (float)channel->scalingKey[i1].time) / deltaTime;

        const glm::vec3& startKey = channel->scalingKey[i1].vector;
        const glm::vec3& endKey = channel->scalingKey[i2].vector;
        glm::vec3 deltaKey = endKey - startKey;
        newVector = startKey + factor * deltaKey;        
    }
    return glm::scale(glm::mat4(1.0f), newVector);
}

glm::mat4 cAnimationEngine::m_calculateTransform(double _currentAnimTime, uint32_t _channel)
{
    // position
    glm::mat4 matrixPosition = m_calculateTransformPosition(_currentAnimTime, _channel);
    // rotation
    glm::mat4 matrixRotation = m_calculateTransformRotation(_currentAnimTime, _channel);
    // scale
    glm::mat4 matrixScale    = m_calculateTransformScale(_currentAnimTime, _channel);

    return matrixPosition * matrixRotation * matrixScale;
}

glm::mat4 cAnimationEngine::m_calcRecursiveTransforms(int32_t _ID)
{
    glm::mat4 rMat = m_entityTemp->model->bone[_ID].transformTemp;
    if (m_entityTemp->model->bone[_ID].parentID > -1)
    {
        rMat = m_calcRecursiveTransforms(m_entityTemp->model->bone[_ID].parentID) * rMat;
    }
    return rMat;
};

void cAnimationEngine::m_calculateAnimation(double _currentAnimTime)
{
    sEntityAnimation* animation = &m_entityTemp->model->animation[m_entityTemp->model->currentAnimation];
    // for each channel (bone) set the animation transformation matrix based on the time in the animation
    for (std::size_t i = 0; i < animation->numChannels; ++i)
    {
        if (animation->channel[i].boneID > -1)
        {
            m_entityTemp->model->bone[animation->channel[i].boneID].transformTemp = m_calculateTransform(_currentAnimTime, i);
        }
    }
    // calculate the recursive transforms
    for (std::size_t i = 0; i < m_entityTemp->model->numBones; ++i)
    {
        m_entityTemp->model->bone[i].transformFinal = m_entityTemp->model->inverseTransform * m_calcRecursiveTransforms(i) * m_entityTemp->model->bone[i].transformPose;
    }
}

void cAnimationEngine::process(double _deltaTime)
{
    _deltaTime /= 1000.0f; // convert milliseconds to seconds
    for (m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp->model != nullptr) && (m_entityTemp->model->animation != nullptr))
        {
            sEntityAnimation* animation = &m_entityTemp->model->animation[m_entityTemp->model->currentAnimation];

            // determine the new animation time
            animation->previousAnimTime = animation->currentAnimTime;
            animation->currentAnimTime += _deltaTime;
            while (animation->currentAnimTime > animation->animationTime)
            {
                animation->currentAnimTime -= animation->animationTime;
            }
            
            m_calculateAnimation(animation->currentAnimTime);
        }
    }
}
