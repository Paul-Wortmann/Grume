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
    for (sUIComponent* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        m_freeData(temp);
    }
}

void cUIManager::load(const std::string &_fileName)
{
    sUIComponent* temp = getNew();
    temp->normalTexture = m_entityManager->loadTexture("ui/hud_001.png");
}
