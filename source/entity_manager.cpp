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

cEntityManager::cEntityManager(void)
{
    
};

cEntityManager::~cEntityManager(void)
{
    
};

void cEntityManager::initialize(void)
{
    // Initialize entity component managers
    managerAudio.initialize();
    managerGraphics.initialize();
    managerPhysics.initialize();
    m_audio    = managerAudio.getFirst();
    m_graphics = managerGraphics.getFirst();
    m_physics  = managerPhysics.getFirst();

    // Initialize entity resource managers
    managerModel.initialize();
    managerTexture.initialize();

    // Initialize the entity manager
    m_numEntities = 0;
    if (m_first != nullptr)
    {
        m_freeEntities();
    }
    m_first = new sEntity;
    m_last  = m_first;
};

void cEntityManager::terminate(void)
{
    // Terminate entity resource managers first
    managerTexture.terminate();
    managerModel.terminate();

    // Terminate entity components second
    managerAudio.terminate();
    managerGraphics.terminate();
    managerPhysics.terminate();

    // Terminate entity manager third
    m_freeEntities();
    m_numEntities = 0;
};

void cEntityManager::m_freeEntities(void)
{
    if (m_first != nullptr)
    {
        sEntity *entityDel = m_first;
        for(m_temp = m_first->next; m_temp != nullptr; m_temp = m_temp->next)
        {
            if (entityDel != nullptr)
            {
                m_freeEntityData(entityDel);
                delete entityDel;
                entityDel = nullptr;
            }
            entityDel = m_temp;
        }
        if (entityDel != nullptr)
        {
            m_freeEntityData(entityDel);
            delete entityDel;
            entityDel = nullptr;
        }
    }
    m_first = nullptr;
    m_last  = nullptr;
    m_temp  = nullptr;
    m_numEntities = 0;    
};

void cEntityManager::m_freeEntityData(sEntity *_entity)
{
    // Entity components are freed by their respective managers.
};

void cEntityManager::m_updateModelMatrix(sEntity *_entity, const uint32_t &_instance)
{
    // generate model matrix
    glm::mat4 tMatrix = glm::mat4(1);
    
    tMatrix = glm::scale(tMatrix, _entity->physics->entity_scale);
    tMatrix = glm::rotate(tMatrix, _entity->physics->entity_rotation.x, glm::vec3(1, 0, 0));
    tMatrix = glm::rotate(tMatrix, _entity->physics->entity_rotation.y, glm::vec3(0, 1, 0));
    tMatrix = glm::rotate(tMatrix, _entity->physics->entity_rotation.z, glm::vec3(0, 0, 1));
    tMatrix = glm::translate(tMatrix, _entity->physics->entity_position);
    
    _entity->graphics->model->modelMatrix[_instance] = tMatrix;
}

sEntity *cEntityManager::getNew(void)
{
    if (m_numEntities == 0)
    {
        if (m_first == nullptr)
        {
            m_first = new sEntity;
        }
        m_last = m_first;
    }
    else
    {
        m_last->next = new sEntity;
        m_last = m_last->next;
    }
    m_numEntities++;
    return m_last;
};

sEntity *cEntityManager::getFirstEntity(void)
{
    return m_first;
};

sEntityAudio *cEntityManager::getFirstAudioComponent(void)
{
    return m_audio;
};

sEntityGraphics *cEntityManager::getFirstGraphicsComponent(void)
{
    return m_graphics;
};

sEntityPhysics *cEntityManager::getFirstPhysicsComponent(void)
{
    return m_physics;
};

void cEntityManager::addComponentAudio(sEntity *_entity)
{
    if (_entity->audio != nullptr)
    {
        _entity->audio = managerAudio.getNew();
    }
};

void cEntityManager::addComponentGraphics(sEntity *_entity)
{
    if (_entity->graphics == nullptr)
    {
        _entity->graphics = managerGraphics.getNew();
    }
};

void cEntityManager::addComponentPhysics(sEntity *_entity)
{
    if (_entity->physics != nullptr)
    {
        _entity->physics = managerPhysics.getNew();
    }
};

void cEntityManager::generateModel(sEntity *_entity, const sEntityModelGeneratorInfo &_info, const std::string &_textureFileName)
{
    managerModel.generateModel(_info);
    attachModel(_entity, _info.name, _textureFileName);
}


void cEntityManager::attachModel(sEntity *_entity, const std::string &_modelFileName, const std::string &_textureFileName)
{
    // Create a new entity if need be.
    if (_entity == nullptr)
    {
        _entity = this->getNew();
    }

    // Add a physics entity component if one does not yet exist.
    if (_entity->physics == nullptr)
    {
        _entity->physics = managerPhysics.getNew();
    }
    // Add a graphics entity component if one does not yet exist.
    if (_entity->graphics == nullptr)
    {
        _entity->graphics = managerGraphics.getNew();
    }

    // Get a model instance count
    uint32_t instanceCount = managerModel.isLoaded(_modelFileName);

    // generate model matrix
    glm::mat4 tMatrix = glm::mat4(1);
    
    tMatrix = glm::scale(tMatrix, _entity->physics->entity_scale);
    tMatrix = glm::rotate(tMatrix, _entity->physics->entity_rotation.x, glm::vec3(1, 0, 0));
    tMatrix = glm::rotate(tMatrix, _entity->physics->entity_rotation.y, glm::vec3(0, 1, 0));
    tMatrix = glm::rotate(tMatrix, _entity->physics->entity_rotation.z, glm::vec3(0, 0, 1));
    tMatrix = glm::translate(tMatrix, _entity->physics->entity_position);

    if (instanceCount > 0)
    {
        _entity->graphics->modelInstance = instanceCount;
        _entity->graphics->model = managerModel.load(_modelFileName);
        managerModel.addInstance(_entity->graphics->model, tMatrix);
    }
    else
    {
        _entity->graphics->modelInstance = 0;
        _entity->graphics->model = managerModel.load(_modelFileName);
        _entity->graphics->model->modelMatrix[0] = tMatrix;

        // process materials
        if (_entity->graphics->model->material == nullptr)
        {
            _entity->graphics->model->numMaterials = 1;
            _entity->graphics->model->material= new sMaterial[_entity->graphics->model->numMaterials];
            _entity->graphics->model->material[0].diffuse.fileName  = _textureFileName + "_d.png";
            _entity->graphics->model->material[0].normal.fileName   = _textureFileName + "_n.png";
            _entity->graphics->model->material[0].specular.fileName = _textureFileName + "_s.png";
        }
        for (size_t i = 0; i < _entity->graphics->model->numMaterials; ++i)
        {
            // diffuse 
            if (_entity->graphics->model->material[i].diffuse.fileName.size() > 2)
            {
            }
            else if (_textureFileName.size() > 2)
            {
                _entity->graphics->model->material[i].diffuse.fileName = _textureFileName + "_d.png";
            }
            else
            {
                _entity->graphics->model->material[i].diffuse.fileName = TEXTURE_DEFAULT_DIFFUSE;
            }
            _entity->graphics->model->material[i].diffuse.ID = managerTexture.add(_entity->graphics->model->material[i].diffuse.fileName);

            // normal
            if (_entity->graphics->model->material[i].normal.fileName.size() > 2)
            {
            }
            else if (_textureFileName.size() > 2)
            {
                _entity->graphics->model->material[i].normal.fileName = _textureFileName + "_n.png";
            }
            else
            {
                _entity->graphics->model->material[i].normal.fileName = TEXTURE_DEFAULT_NORMAL;
            }
            _entity->graphics->model->material[i].normal.ID = managerTexture.add(_entity->graphics->model->material[i].normal.fileName);
            
            // specular
            if (_entity->graphics->model->material[i].specular.fileName.size() > 2)
            {
            }
            else if (_textureFileName.size() > 2)
            {
                _entity->graphics->model->material[i].specular.fileName = _textureFileName + "_s.png";
            }
            else
            {
                _entity->graphics->model->material[i].specular.fileName = TEXTURE_DEFAULT_SPECULAR;
            }
            _entity->graphics->model->material[i].specular.ID = managerTexture.add(_entity->graphics->model->material[i].specular.fileName);
        }
    }
}

void cEntityManager::setScale(sEntity *_entity, const uint32_t &_instance, const float &_x, const float &_y, const float &_z)
{
    _entity->physics->entity_scale.x = _x;
    _entity->physics->entity_scale.y = _y;
    _entity->physics->entity_scale.z = _z;
    
    m_updateModelMatrix(_entity, _instance);
}

void cEntityManager::setPosition(sEntity *_entity, const uint32_t &_instance, const float &_x, const float &_y, const float &_z)
{
    _entity->physics->entity_position.x = _x;
    _entity->physics->entity_position.y = _y;
    _entity->physics->entity_position.z = _z;
    
    m_updateModelMatrix(_entity, _instance);
}

void cEntityManager::setRotation(sEntity *_entity, const uint32_t &_instance, const float &_x, const float &_y, const float &_z)
{
    _entity->physics->entity_rotation.x = _x;
    _entity->physics->entity_rotation.y = _y;
    _entity->physics->entity_rotation.z = _z;
    
    m_updateModelMatrix(_entity, _instance);
}

void cEntityManager::setScale   (sEntity *_entity, const float &_x, const float &_y, const float &_z)
{
    setScale(_entity, 0, _x, _y, _z);
}

void cEntityManager::setPosition(sEntity *_entity, const float &_x, const float &_y, const float &_z)
{
    setPosition(_entity, 0, _x, _y, _z);
}

void cEntityManager::setRotation(sEntity *_entity, const float &_x, const float &_y, const float &_z)
{
    setRotation(_entity, 0, _x, _y, _z);
}

