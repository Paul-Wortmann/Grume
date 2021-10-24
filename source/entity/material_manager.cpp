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

#include "material_manager.hpp"

void cMaterialManager::initialize(void)
{
    textureManager.initialize();
}

void cMaterialManager::terminate(void)
{
    textureManager.terminate();
    m_freeAll();
}

void cMaterialManager::m_freeData(sEntityMaterial*& _pointer)
{
}

void cMaterialManager::m_freeAll(void)
{
    for (sEntityMaterial* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        m_freeData(temp);
    }
}

bool cMaterialManager::isLoaded(const std::string &_diffuse, const std::string &_emissive, const std::string &_normal, const std::string &_specular)
{
    if (getCount() > 0)
    {
        for (sEntityMaterial* temp = getHead(); temp != nullptr; temp = temp->next)
        {
            if ((temp->diffuse->fileName.compare(_diffuse) == 0)
             && (temp->emissive->fileName.compare(_emissive) == 0)
             && (temp->normal->fileName.compare(_normal) == 0)
             && (temp->specular->fileName.compare(_specular) == 0))
            {
                return true;
            }
        }
    }
    return false;
}

sEntityMaterial* cMaterialManager::add(std::string _diffuse, std::string _emissive, std::string _normal, std::string _specular)
{
    // If it is already loaded return that pointer
    if (getCount() > 0)
    {
        for (sEntityMaterial* temp = getHead(); temp != nullptr; temp = temp->next)
        {
            // if any nullptrs are encountered don't compare file names
            if ((temp->diffuse  == nullptr) ||
                (temp->emissive == nullptr) ||
                (temp->normal   == nullptr) ||
                (temp->specular == nullptr));
            else if((temp->diffuse->fileName.compare(_diffuse)  == 0) &&
                    (temp->emissive->fileName.compare(_emissive) == 0) &&
                    (temp->normal->fileName.compare(_normal)     == 0) &&
                    (temp->specular->fileName.compare(_specular) == 0))
            {
                return temp;
            }
        }
    }

    sEntityMaterial* tMaterial = getNew();
    tMaterial->diffuse = textureManager.load(_diffuse);
    tMaterial->emissive = textureManager.load(_emissive);
    tMaterial->normal = textureManager.load(_normal);
    tMaterial->specular = textureManager.load(_specular);
    return tMaterial;
}

sEntityTexture* cMaterialManager::loadTexture(const std::string &_fileName)
{
    return textureManager.load(_fileName);
}

GLFWimage* cMaterialManager::loadIcon(const std::string &_fileName)
{
    return textureManager.loadIcon(_fileName);
}
