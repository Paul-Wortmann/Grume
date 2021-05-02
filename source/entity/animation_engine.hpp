


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
        void     process(double _deltaTime);
        void     setEntityHead(sEntity* _entity) { m_entityHead = _entity; m_entityTemp = _entity; }
        
    protected:

    private:
        
        sEntity*  m_entityHead = nullptr;
        sEntity*  m_entityTemp = nullptr;
        
        glm::mat4 m_calculateTransformPosition(double _currentAnimTime, uint32_t _channel);
        glm::mat4 m_calculateTransformRotation(double _currentAnimTime, uint32_t _channel);
        glm::mat4 m_calculateTransformScale(double _currentAnimTime, uint32_t _channel);
        glm::mat4 m_calculateTransform(double _currentAnimTime, uint32_t _channel);
        glm::mat4 m_calcRecursiveTransforms(int32_t _ID);
        void      m_calculateAnimation(double _currentAnimTime);
};

#endif //ANIMATION_ENGINE_HPP

