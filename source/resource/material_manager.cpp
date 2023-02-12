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

std::uint32_t cMaterialManager::initialize(void)
{
    return m_textureManager.initialize();
}

void cMaterialManager::freeData(sMaterial*& _pointer)
{
    if (_pointer->diffuse != nullptr)
    {
        glDeleteTextures(1, &_pointer->diffuse->ID);
    }
    if (_pointer->normal != nullptr)
    {
        glDeleteTextures(1, &_pointer->normal->ID);
    }
    if (_pointer->specular != nullptr)
    {
        glDeleteTextures(1, &_pointer->specular->ID);
    }
    if (_pointer->emissive != nullptr)
    {
        glDeleteTextures(1, &_pointer->emissive->ID);
    }
}

void cMaterialManager::terminate(void)
{
    m_textureManager.terminate();
    freeAll();
}

sMaterial* cMaterialManager::load(const std::string &_fileName)
{
    sMaterial*  tMaterial        = nullptr;
    std::string materialName     = {};
    std::string diffuseFileName  = {};
    std::string normalFileName   = {};
    std::string specularFileName = {};

    // Get each texture file name
    cXML materialFile;
    materialFile.load(std::string(FILE_PATH_MATERIAL) + _fileName);
    if (materialFile.isValid())
    {
        materialName     = materialFile.getString("<material_name>");
        diffuseFileName  = materialFile.getString("<diffuse_texture>");
        normalFileName   = materialFile.getString("<normal_texture>");
        specularFileName = materialFile.getString("<specular_texture>");
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to load file: " + std::string(FILE_PATH_MATERIAL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        //return tMaterial;
    }
    materialFile.free();

    for (sMaterial* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if (temp->materialName.compare(materialName) == 0)
        {
            return temp;
        }
    }

    // Create a new material node
    tMaterial = getNew();
    tMaterial->materialName = materialName;

    // Try to load the textures
    tMaterial->diffuse  = m_textureManager.load(diffuseFileName);
    tMaterial->normal   = m_textureManager.load(normalFileName);
    tMaterial->specular = m_textureManager.load(specularFileName);

    // Load the default textures if the previous step failed
    if (tMaterial->diffuse == nullptr)
        tMaterial->diffuse = m_textureManager.load(std::string(FILE_DEFAULT_TEXTURE) + "_d.png");
    if (tMaterial->normal == nullptr)
        tMaterial->normal = m_textureManager.load(std::string(FILE_DEFAULT_TEXTURE) + "_n.png");
    if (tMaterial->specular == nullptr)
        tMaterial->specular = m_textureManager.load(std::string(FILE_DEFAULT_TEXTURE) + "_s.png");

    return tMaterial;
}

sTexture* cMaterialManager::loadTexture(const std::string &_fileName)
{
    return m_textureManager.load(_fileName);
}
