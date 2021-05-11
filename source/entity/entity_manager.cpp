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

#include "entity_manager.hpp"

void cEntityManager::initialize(void)
{
    modelManager.initialize();
}

void cEntityManager::terminate(void)
{
    modelManager.terminate();
    m_freeAll();
}

void cEntityManager::addModel(sEntityModel*& _model)
{
    modelManager.addBack(_model);
}

sEntityModel* cEntityManager::getNewModel(void)
{
    return modelManager.getNew();
}

void cEntityManager::m_freeData(sEntity*& _pointer)
{
    _pointer->owner = eEntityOwner::ownerNone;
    _pointer->name = "";
    
    // State
    if (_pointer->state != nullptr)
    {
        delete[] _pointer->state;
        _pointer->state = nullptr;
        _pointer->stateCount = 0;
    }
}

void cEntityManager::m_freeAll(void)
{
    for (sEntity* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

sEntityModel* cEntityManager::loadModel(const std::string &_fileName)
{
    return modelManager.load(_fileName);
}

void cEntityManager::removeModel(sEntityModel*& _model)
{
    modelManager.remove(_model);
}

sEntityMaterial* cEntityManager::loadMaterial(const std::string &_fileName)
{
    return modelManager.loadMaterial(_fileName);
}

sEntityTexture* cEntityManager::loadTexture(const std::string &_fileName)
{
    return modelManager.loadTexture(_fileName);
}

void cEntityManager::updateModelMatrix(sEntity*& _entity)
{
    // 1. Translation
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1), _entity->position);

    // 2. Scale
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1), _entity->scale);

    // 3. Rotation
    glm::mat4 rotationMatrix = glm::mat4(1);
    rotationMatrix = glm::rotate(rotationMatrix, _entity->rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, _entity->rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    rotationMatrix = glm::rotate(rotationMatrix, _entity->rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    // 4. Fianlly calculate the model matrix
    _entity->modelMatrix = translationMatrix * rotationMatrix * scaleMatrix;
}

sEntity* cEntityManager::load(const std::string& _fileName, sEntity* _entity)
{
    cXML xmlFile;
    xmlFile.load(FILE_PATH_ENTITY + _fileName);
    if (xmlFile.lineCount() > 0)
    {
        // If management
        if (_entity == nullptr)
        {
            _entity = getNew();
        }
        
        //gLogWrite(LOG_INFO, "Loading entity: " + xmlFile.getString("<name>"), __FILE__, __LINE__, __FUNCTION__);

        // Get the data from the XML file
        _entity->name            = xmlFile.getString("<name>");
        _entity->position        = xmlFile.getVec3("<position>");
        _entity->scale           = xmlFile.getVec3("<scale>");
        _entity->rotation        = xmlFile.getVec3("<rotation>");
        std::string modelFile    = xmlFile.getString("<model>");
        std::string materialFile = xmlFile.getString("<material>");

        // Load model from file
        if (modelFile.length() > 3)
        {
            _entity->model = loadModel(modelFile);
        }

        // Update the model matrix
        updateModelMatrix(_entity);

        // Load material from file
        if (materialFile.length() > 3)
        {
            sEntityMaterial* tMaterial = modelManager.loadMaterial(materialFile);
            if (tMaterial != nullptr)
            {
                _entity->material = tMaterial;
            }
        }

        // Load entity states from file
        _entity->stateInitial = xmlFile.getInteger("<state_initial>");
        _entity->stateCount = xmlFile.getInstanceCount("<state_name>");
        _entity->state = new sEntityState[_entity->stateCount];
        for (std::uint32_t i = 0; i < _entity->stateCount; ++i)
        {
            _entity->state[i].name = xmlFile.getString("<state_name>", 1 + i);
            std::cout << "State: " << _entity->state[i].name << std::endl;
            _entity->state[i].musicFile = xmlFile.getString("<state_sound>", 1 + i);
            _entity->state[i].animation = xmlFile.getIvec3("<state_animation>", 1 + i);
        }

        // Cleanup and return a pointer to the entity
        xmlFile.free();
        return _entity;
    }
    return nullptr; // Load failed
}

void cEntityManager::setState(const std::string& _name)
{
    /*
    for (std::uint32_t i = 0; i < _entity->stateCount; ++i)
    {
        _entity->state[i].name = xmlFile.getString("<state_name>", 1 + i);
        std::cout << "State: " << _entity->state[i].name << std::endl;
        _entity->state[i].musicFile = xmlFile.getString("<state_sound>", 1 + i);
        _entity->state[i].animation = xmlFile.getIvec3("<state_animation>", 1 + i);
    }
    */
}

void cEntityManager::setState(const std::uint32_t& _state)
{
    
}
