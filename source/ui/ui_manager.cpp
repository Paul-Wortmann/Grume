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
    // Load the ui database file
    cXML xmlUiFile;
    xmlUiFile.load(FILE_PATH_UI + _fileName);
    
    // If ui database file contains data:
    if (xmlUiFile.lineCount() > 0)
    {
        // get a count of ui components
        std::uint32_t uicCount = xmlUiFile.getInstanceCount("<component>");
        
        // load each ui component
        for (std::uint32_t i = 0; i < uicCount; ++i)
        {
            sUIComponent* temp = getNew();
            temp->name = xmlUiFile.getString("<name>", i + 1);
            temp->position = xmlUiFile.getVec3("<position>", i + 1);
            temp->textureNormal = m_entityManager->loadTexture(xmlUiFile.getString("<texture_normal>", i + 1));
            temp->textureHover  = m_entityManager->loadTexture(xmlUiFile.getString("<texture_hover>", i + 1));
            temp->textureActive = m_entityManager->loadTexture(xmlUiFile.getString("<texture_activated>", i + 1));
        }
    }
    
    // Cleanup
    xmlUiFile.free();

}

