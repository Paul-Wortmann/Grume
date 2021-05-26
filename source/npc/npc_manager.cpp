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
 
#include "npc_manager.hpp"

void cNPCManager::initialize(cEntityManager* _entityManager)
{
    m_entityManager = _entityManager;
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

sEntity* cNPCManager::load(const std::string &_fileName)
{
    
}

void cNPCManager::process(const float32 &_dt)
{
    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityPlayer != nullptr) && (m_entityTemp->type == eEntityType::entityTypeNPCmob))
        {
            //glm::vec3 rotation = m_entityTemp->rotation;
            double angle = atan2(m_entityTemp->position.z - m_entityPlayer->position.z, m_entityTemp->position.x - m_entityPlayer->position.x);
            m_entityTemp->rotation.y = angle - DTOR_90;
            m_entityManager->updateModelMatrix(m_entityTemp);
        }
    }
}