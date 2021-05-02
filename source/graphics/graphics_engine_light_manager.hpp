


#ifndef GRAPHICS_ENGINE_LIGHT_MANAGER_HPP
#define GRAPHICS_ENGINE_LIGHT_MANAGER_HPP

#include "../includes.hpp"
#include "../linked_list.hpp"
#include "graphics_engine_light_define.hpp"

class cGraphicsEngineLightManager : public tcLinkedList<sGraphicsEnginePointLight>
{
    public:
        sGraphicsEngineDirectionalLight directionalLight;
        sGraphicsEngineDirectionalLightLocation uniformLocationDirectional;
        sGraphicsEnginePointLightLocation uniformLocationPoint[MAX_POINT_LIGHTS];
        bool limitReached   = false;
        bool updateRequired = true;

        void initialize(void);
        void terminate(void);

    protected:

    private:
        void m_freeAll(void);
        void m_freeData(sGraphicsEnginePointLight*& _light);
};

#endif // GRAPHICS_ENGINE_LIGHT_MANAGER_HPP
