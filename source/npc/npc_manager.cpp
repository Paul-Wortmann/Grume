
#include "npc_manager.hpp"

void cNPCManager::initialize(void)
{
}

void cNPCManager::terminate(void)
{
    m_freeAll();
}

void cNPCManager::m_freeData(sNPC*& _pointer)
{
}

void cNPCManager::m_freeAll(void)
{
    for (sNPC* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}
