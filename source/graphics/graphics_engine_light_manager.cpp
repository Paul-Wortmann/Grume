
#include "graphics_engine_light_manager.hpp"

void cGraphicsEngineLightManager::initialize(void)
{

}

void cGraphicsEngineLightManager::terminate(void)
{
    m_freeAll();
}

void cGraphicsEngineLightManager::m_freeData(sGraphicsEnginePointLight*& _light)
{

}

void cGraphicsEngineLightManager::m_freeAll(void)
{
    for (sGraphicsEnginePointLight* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}
