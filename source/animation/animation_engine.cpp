/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "animation_engine.hpp"

/** \brief Initializes the animation engine.
 *
 * \param   void, does not take any parameters.
 * \return  EXIT_SUCCESS / EXIT_FAILURE.
 *
 * Initializes the animation engine and returns EXIT_SUCCESS if successful,
 * or EXIT_FAILURE is unsuccessful.
 */

std::uint32_t cAnimationEngine::initialize(void)
{
    return EXIT_SUCCESS;
}

void cAnimationEngine::terminate(void)
{

}

glm::mat4 cAnimationEngine::m_calculateTransformPosition(float _currentAnimTime, std::uint32_t _currentAnimation, std::uint32_t _channel)
{
    sAnimationChannel* channel = &m_entityTemp->graphics->model->animation[_currentAnimation].channel[_channel];

    // No position keys on this channel: nothing to animate, return identity
    if (channel->numPositionKeys == 0)
    {
        return glm::mat4(1.0f);
    }

    glm::vec3 newVector = channel->positionKey[0].vector;

    if (channel->numPositionKeys > 1)
    {
        // Default to the final segment. If the loop below never breaks
        // (time is past the last key), we interpolate the final pair.
        std::uint32_t i1 = channel->numPositionKeys - 2;
        std::uint32_t i2 = channel->numPositionKeys - 1;

        for (std::uint32_t i = 0; i < channel->numPositionKeys - 1; ++i)
        {
            if (_currentAnimTime < channel->positionKey[i + 1].time)
            {
                i1 = i;
                break;
            }
        }
        i2 = i1 + 1;

        float deltaTime = static_cast<float>(channel->positionKey[i2].time - channel->positionKey[i1].time);
        float factor = (deltaTime > 0.0f)
                     ? ((_currentAnimTime - static_cast<float>(channel->positionKey[i1].time)) / deltaTime)
                     : 0.0f;
        if (factor < 0.0f) factor = 0.0f;
        if (factor > 1.0f) factor = 1.0f;

        const glm::vec3& startKey = channel->positionKey[i1].vector;
        const glm::vec3& endKey   = channel->positionKey[i2].vector;
        glm::vec3 deltaKey = endKey - startKey;
        newVector = startKey + factor * deltaKey;
    }
    return glm::translate(glm::mat4(1.0f), newVector);
}

glm::mat4 cAnimationEngine::m_calculateTransformRotation(float _currentAnimTime, std::uint32_t _currentAnimation, std::uint32_t _channel)
{
    sAnimationChannel* channel = &m_entityTemp->graphics->model->animation[_currentAnimation].channel[_channel];

    // No rotation keys on this channel: nothing to animate, return identity
    if (channel->numRotationKeys == 0)
    {
        return glm::mat4(1.0f);
    }

    glm::quat newQuat = channel->rotationKey[0].quat;
    if (channel->numRotationKeys > 1)
    {
        // Default to the final segment (see position version above)
        std::uint32_t i1 = channel->numRotationKeys - 2;
        std::uint32_t i2 = channel->numRotationKeys - 1;

        for (uint32_t i = 0; i < channel->numRotationKeys - 1; ++i)
        {
            if (_currentAnimTime < channel->rotationKey[i + 1].time)
            {
                i1 = i;
                break;
            }
        }
        i2 = i1 + 1;

        float deltaTime = static_cast<float>(channel->rotationKey[i2].time - channel->rotationKey[i1].time);
        float factor = (deltaTime > 0.0f)
                     ? ((_currentAnimTime - static_cast<float>(channel->rotationKey[i1].time)) / deltaTime)
                     : 0.0f;
        if (factor < 0.0f) factor = 0.0f;
        if (factor > 1.0f) factor = 1.0f;

        const glm::quat& startKey = channel->rotationKey[i1].quat;
        const glm::quat& endKey   = channel->rotationKey[i2].quat;

        newQuat = glm::slerp(startKey, endKey, factor);
    }
    return glm::toMat4(newQuat);
}

glm::mat4 cAnimationEngine::m_calculateTransformScale(float _currentAnimTime, std::uint32_t _currentAnimation, std::uint32_t _channel)
{
    sAnimationChannel* channel = &m_entityTemp->graphics->model->animation[_currentAnimation].channel[_channel];

    // No scaling keys on this channel: nothing to animate, return identity
    if (channel->numScalingKeys == 0)
    {
        return glm::mat4(1.0f);
    }

    glm::vec3 newVector = channel->scalingKey[0].vector;

    if (channel->numScalingKeys > 1)
    {
        // Default to the final segment (see position version above)
        std::uint32_t i1 = channel->numScalingKeys - 2;
        std::uint32_t i2 = channel->numScalingKeys - 1;

        for (std::uint32_t i = 0; i < channel->numScalingKeys - 1; ++i)
        {
            if (_currentAnimTime < channel->scalingKey[i + 1].time)
            {
                i1 = i;
                break;
            }
        }
        i2 = i1 + 1;

        float deltaTime = static_cast<float>(channel->scalingKey[i2].time - channel->scalingKey[i1].time);
        float factor = (deltaTime > 0.0f)
                     ? ((_currentAnimTime - static_cast<float>(channel->scalingKey[i1].time)) / deltaTime)
                     : 0.0f;
        if (factor < 0.0f) factor = 0.0f;
        if (factor > 1.0f) factor = 1.0f;

        const glm::vec3& startKey = channel->scalingKey[i1].vector;
        const glm::vec3& endKey   = channel->scalingKey[i2].vector;
        glm::vec3 deltaKey = endKey - startKey;
        newVector = startKey + factor * deltaKey;
    }
    return glm::scale(glm::mat4(1.0f), newVector);
}

glm::mat4 cAnimationEngine::m_calculateTransform(float _currentAnimTime, std::uint32_t _currentAnimation, std::uint32_t _channel)
{
    // position
    glm::mat4 matrixPosition = m_calculateTransformPosition(_currentAnimTime, _currentAnimation, _channel);
    // rotation
    glm::mat4 matrixRotation = m_calculateTransformRotation(_currentAnimTime, _currentAnimation, _channel);
    // scale
    glm::mat4 matrixScale    = m_calculateTransformScale(_currentAnimTime, _currentAnimation, _channel);

    return matrixPosition * matrixRotation * matrixScale;
}

glm::mat4 cAnimationEngine::m_calcRecursiveTransforms(int32_t _ID)
{
    glm::mat4 rMat = m_entityTemp->graphics->model->bone[_ID].transformTemp;
    if (m_entityTemp->graphics->model->bone[_ID].parentID > -1)
    {
        rMat = m_calcRecursiveTransforms(m_entityTemp->graphics->model->bone[_ID].parentID) * rMat;
    }
    return rMat;
};

void cAnimationEngine::m_calculateAnimation(float _currentAnimTime, std::uint32_t _currentAnimation)
{
    // Early exit if animation data is missing
    if ((m_entityTemp == nullptr) ||
        (m_entityTemp->graphics == nullptr) ||
        (m_entityTemp->graphics->model == nullptr) ||
        (m_entityTemp->graphics->model->animation == nullptr) ||
        (_currentAnimation >= m_entityTemp->graphics->model->numAnimations))
    {
        return;
    }

    sEntityModelAnimation* animation = &m_entityTemp->graphics->model->animation[_currentAnimation];

    // for each channel (bone) set the animation transformation matrix based on the time in the animation
    for (std::uint32_t i = 0; i < animation->numChannels; ++i)
    {
        if (animation->channel[i].boneID > -1)
        {
            m_entityTemp->graphics->model->bone[animation->channel[i].boneID].transformTemp = m_calculateTransform(_currentAnimTime, _currentAnimation, i);
        }
    }
    // calculate the recursive transforms
    for (std::uint32_t i = 0; i < m_entityTemp->graphics->model->numBones; ++i)
    {
        m_entityTemp->graphics->model->bone[i].transformFinal = m_entityTemp->graphics->model->inverseTransform * m_calcRecursiveTransforms(i) * m_entityTemp->graphics->model->bone[i].transformPose;
    }
}

void cAnimationEngine::initializeEntities(void)
{
    // Initialize any entities that have independent animation
    for (m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp->animation != nullptr) &&
            (m_entityTemp->animation->animationIndependent) &&
            (m_entityTemp->graphics != nullptr) &&
            (m_entityTemp->graphics->model != nullptr) &&
            (m_entityTemp->graphics->model->animation != nullptr) &&
            (m_entityTemp->graphics->model->numAnimations > 0))
        {
            // Initialize the bone transforms if need be
            if (m_entityTemp->animation->boneTransform == nullptr)
            {
                m_entityTemp->animation->numBones = m_entityTemp->graphics->model->numBones;
                m_entityTemp->animation->boneTransform = new glm::mat4[m_entityTemp->animation->numBones];
            }

            // Calculate the bone transforms at their initial state
            m_calculateAnimation(0.0f, 0);

            // Copy the bone transforms from the model to the entity
            for (std::uint32_t i = 0; i < m_entityTemp->animation->numBones; ++i)
            {
                m_entityTemp->animation->boneTransform[i] = m_entityTemp->graphics->model->bone[i].transformFinal;
            }
        }
    }
}

void cAnimationEngine::process(std::int64_t _deltaTime)
{
    // Process animations
    for (m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if (m_entityTemp->base.inRnge)
        {
            // Set the animation processed flag
            if ((m_entityTemp->base.enabled) &&
                (m_entityTemp->graphics != nullptr) &&
                (m_entityTemp->graphics->model != nullptr))
            {
                m_entityTemp->graphics->model->animProcessed = false;
            }

            // Independent animations
            if ((m_entityTemp->base.enabled) && (m_entityTemp->animation != nullptr) && (m_entityTemp->animation->animationIndependent))
            {
                m_processEntity(m_entityTemp, _deltaTime);
            }

            // Non independent animations
            if ((m_entityTemp->base.enabled) && (m_entityTemp->graphics != nullptr) && (m_entityTemp->graphics->model != nullptr) && (m_entityTemp->graphics->model->animation != nullptr) && (!m_entityTemp->graphics->model->animProcessed))
            {
                // Set the animation processed flag, only process once per frame
                m_entityTemp->graphics->model->animProcessed = true;

                // Get the pointer to the current animation
                sEntityModelAnimation* animation = &m_entityTemp->graphics->model->animation[m_entityTemp->graphics->model->currentAnimation];

                // Guard against an invalid/empty animation
                if (animation->animationTime > 0.0f)
                {
                    // determine the new animation time
                    animation->previousAnimTime = animation->currentAnimTime;
                    animation->currentAnimTime += static_cast<float>(_deltaTime) / 1000.0f; // convert milliseconds to seconds
                    while (animation->currentAnimTime > animation->animationTime)
                    {
                        animation->currentAnimTime -= animation->animationTime;
                    }

                    m_calculateAnimation(animation->currentAnimTime, m_entityTemp->graphics->model->currentAnimation);
                }
            }
        }
    }
}

void cAnimationEngine::m_processEntity(sEntity* _entity, std::int64_t _deltaTime)
{
    if ((_entity == nullptr) || (!_entity->base.enabled))
        return;

    // Set the internal temp entity, this is used when processing animations
    m_entityTemp = _entity;

    // Processed animations
    if ((m_entityTemp->animation->finishedAnimation == false) &&
        (m_entityTemp->graphics != nullptr) &&
        (m_entityTemp->graphics->model != nullptr) &&
        (m_entityTemp->graphics->model->animation != nullptr) &&
        (m_entityTemp->animation->currentAnimation < m_entityTemp->graphics->model->numAnimations))
    {
        // Initialize the bone transforms if need be
        if (m_entityTemp->animation->boneTransform == nullptr)
        {
            m_entityTemp->animation->numBones = m_entityTemp->graphics->model->numBones;
            m_entityTemp->animation->boneTransform = new glm::mat4[m_entityTemp->animation->numBones];
        }

        // determine the new animation time
        m_entityTemp->animation->previousAnimTime = m_entityTemp->animation->currentAnimTime;
        m_entityTemp->animation->currentAnimTime += static_cast<float>(_deltaTime) / 1000.0f; // convert milliseconds to seconds
        if (m_entityTemp->animation->currentAnimTime > m_entityTemp->animation->stopAnimTime)
        {
            if (m_entityTemp->animation->repeatAnimation == true)
            {
                m_entityTemp->animation->currentAnimTime = m_entityTemp->animation->startAnimTime;
            }
            else
            {
                m_entityTemp->animation->currentAnimTime = m_entityTemp->animation->stopAnimTime;
                m_entityTemp->animation->finishedAnimation = true;
            }
        }

        // Calculate the bone transforms
        m_calculateAnimation(m_entityTemp->animation->currentAnimTime, m_entityTemp->animation->currentAnimation);

        // Copy the bone transforms from the model to the entity
        for (std::uint32_t i = 0; i < m_entityTemp->animation->numBones; ++i)
        {
            m_entityTemp->animation->boneTransform[i] = m_entityTemp->graphics->model->bone[i].transformFinal;
        }
    }
}
