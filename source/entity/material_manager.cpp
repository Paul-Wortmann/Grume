
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
    for (sEntityMaterial* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

bool cMaterialManager::isLoaded(const std::string &_diffuse, const std::string &_emissive, const std::string &_normal, const std::string &_specular)
{
    if (getCount() > 0)
    {
        for (sEntityMaterial* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
        {
            if ((m_temp->diffuse->fileName.compare(_diffuse) == 0)
             && (m_temp->emissive->fileName.compare(_emissive) == 0)
             && (m_temp->normal->fileName.compare(_normal) == 0)
             && (m_temp->specular->fileName.compare(_specular) == 0))
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
        for (sEntityMaterial* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
        {
            // if any nullptrs are encountered don't compare file names
            if ((m_temp->diffuse  == nullptr) ||
                (m_temp->emissive == nullptr) ||
                (m_temp->normal   == nullptr) ||
                (m_temp->specular == nullptr));
            else if((m_temp->diffuse->fileName.compare(_diffuse)  == 0) &&
                    (m_temp->emissive->fileName.compare(_emissive) == 0) &&
                    (m_temp->normal->fileName.compare(_normal)     == 0) &&
                    (m_temp->specular->fileName.compare(_specular) == 0))
            {
                return m_temp;
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