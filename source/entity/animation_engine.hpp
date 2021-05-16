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

#ifndef ANIMATION_ENGINE_HPP
#define ANIMATION_ENGINE_HPP

#include "../includes.hpp"
#include "entity_define.hpp"

class cAnimationEngine
{
    private:

    public:
        cAnimationEngine(void) {}
        ~cAnimationEngine(void) {}
        uint32_t initialize(void);
        void     terminate(void);
        void     initializeEntities(void);
        void     process(double _deltaTime);
        void     setEntityHead(sEntity* _entity) { m_entityHead = _entity; m_entityTemp = _entity; }

    protected:

    private:

        sEntity*  m_entityHead = nullptr;
        sEntity*  m_entityTemp = nullptr;

        // animation_engine.cpp
        glm::mat4 m_calculateTransformPosition(double _currentAnimTime, uint32_t _currentAnimation, uint32_t _channel);
        glm::mat4 m_calculateTransformRotation(double _currentAnimTime, uint32_t _currentAnimation, uint32_t _channel);
        glm::mat4 m_calculateTransformScale(double _currentAnimTime, uint32_t _currentAnimation, uint32_t _channel);
        glm::mat4 m_calculateTransform(double _currentAnimTime, uint32_t _currentAnimation, uint32_t _channel);
        glm::mat4 m_calcRecursiveTransforms(int32_t _ID);
        void      m_calculateAnimation(double _currentAnimTime, uint32_t _currentAnimation);
        void      m_processEntity(sEntity* _entity, double _deltaTime);
};

#endif //ANIMATION_ENGINE_HPP

