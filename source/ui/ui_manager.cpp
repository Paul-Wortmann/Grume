
#include "ui_manager.hpp"

void cUIManager::initialize(cEntityManager* _entityManager)
{
    m_entityManager = _entityManager;
}

void cUIManager::terminate(void)
{
    m_freeAll();
}

void cUIManager::m_freeData(sUIComponent*& _pointer)
{

}

void cUIManager::m_freeAll(void)
{
    for (sUIComponent* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

void cUIManager::load(const std::string &_fileName)
{
    sUIComponent* m_temp = getNew();
    m_temp->normalTexture = m_entityManager->loadTexture("ui/hud_001.png");
}
