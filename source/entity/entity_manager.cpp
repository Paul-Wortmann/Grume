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
    m_modelManager.initialize();
}

void cEntityManager::terminate(void)
{
    m_modelManager.terminate();
    m_freeAll();
}

void cEntityManager::addModel(sEntityModel*& _model)
{
    m_modelManager.addBack(_model);
}

sEntityModel* cEntityManager::getNewModel(void)
{
    return m_modelManager.getNew();
}

void cEntityManager::m_freeData(sEntity*& _pointer)
{
    _pointer->owner = eEntityOwner::ownerNone;
    _pointer->name = "";

    // These are freed by their respective managers
    //sEntityModel*    model        = nullptr;
    //sEntityMaterial* material     = nullptr;

    // Bone transforms
    if (_pointer->boneTransform != nullptr)
    {
        delete[] _pointer->boneTransform;
        _pointer->boneTransform = nullptr;
        _pointer->numBones = 0;
    }

    // State
    if (_pointer->state != nullptr)
    {
        delete[] _pointer->state;
        _pointer->state = nullptr;
        _pointer->stateCount = 0;
    }

    // AI
    if (_pointer->ai != nullptr)
    {
        delete[] _pointer->ai;
        _pointer->ai = nullptr;
    }

    // Pathing
    if (_pointer->movement != nullptr)
    {
        if (_pointer->movement->mapPath.path != nullptr)
        {
            delete[] _pointer->movement->mapPath.path;
            _pointer->movement->mapPath.path = nullptr;
        }
        delete[] _pointer->movement;
        _pointer->movement = nullptr;
    }
}

void cEntityManager::m_freeAll(void)
{
    for (sEntity* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        m_freeData(temp);
    }
}

sEntityModel* cEntityManager::loadModel(const std::string &_fileName)
{
    return m_modelManager.load(_fileName);
}

void cEntityManager::removeModel(sEntityModel*& _model)
{
    m_modelManager.remove(_model);
}

sEntityMaterial* cEntityManager::loadMaterial(const std::string &_fileName)
{
    return m_modelManager.loadMaterial(_fileName);
}

sEntityTexture* cEntityManager::loadTexture(const std::string &_fileName)
{
    return m_modelManager.loadTexture(_fileName);
}

void cEntityManager::updateModelMatrix(sEntity*& _entity)
{
    // 1. Translation
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1), _entity->position);

    // 2. Rotation
    glm::mat4 rotationMatrix = glm::mat4(1);
    rotationMatrix = glm::rotate(rotationMatrix, _entity->rotation.x, glm::vec3(1, 0, 0));
    rotationMatrix = glm::rotate(rotationMatrix, _entity->rotation.y, glm::vec3(0, 1, 0));
    rotationMatrix = glm::rotate(rotationMatrix, _entity->rotation.z, glm::vec3(0, 0, 1));

    // 3. Scale
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1), _entity->scale);

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
        _entity->name                 = xmlFile.getString("<name>");
        _entity->position             = xmlFile.getVec3("<position>");
        _entity->scale                = xmlFile.getVec3("<scale>");
        _entity->rotation             = xmlFile.getVec3("<rotation>");
        std::string modelFile         = xmlFile.getString("<model>");
        std::string materialFile      = xmlFile.getString("<material>");
        _entity->animationIndependent = (xmlFile.getInteger("<animation_independent>") == 1);

        // Movement data
        if (xmlFile.getInstanceCount("<movement>") != 0)
        {
            _entity->movement = new sEntityMovement;
            _entity->movement->movementSpeed = xmlFile.getFloat("<movement_speed>");
        }
        
        // Load AI data
        if (xmlFile.getInstanceCount("<ai>") != 0)
        {
            _entity->ai                   = new sEntityAI;
            _entity->ai->distanceAttack   = xmlFile.getFloat("<attack_distance>");
            _entity->ai->distanceMove     = xmlFile.getFloat("<move_distance>");
            _entity->ai->attack_frequency = xmlFile.getInteger("<attack_frequency>");
            _entity->ai->attack_counter   = _entity->ai->attack_frequency;
        }

        // Load model from file
        if (modelFile.length() > 3)
        {
            _entity->model = loadModel(modelFile);
            if ((_entity->model) && (_entity->model->animation != nullptr))
            {
                _entity->stopAnimTime = _entity->model->animation[0].animationTime;
            }
        }

        // Update the model matrix
        updateModelMatrix(_entity);

        // Load material from file
        if (materialFile.length() > 3)
        {
            sEntityMaterial* tMaterial = m_modelManager.loadMaterial(materialFile);
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
            _entity->state[i].animation = xmlFile.getVec3("<state_animation>", 1 + i);
            std::string audioData = xmlFile.getString("<state_sound>", 1 + i);
            //_entity->state[i].audioFile = xmlFile.getString("<state_sound>", 1 + i);

            // Process the audio data string
            audioData += "    ";
            std::uint64_t audioDataLength = audioData.length();
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (audioDataLength > 6)
            {
                for (std::uint64_t j = 0; j < audioDataLength; ++j)
                {
                    if (audioData[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            _entity->state[i].audioDBname = tString;
                        }
                        else if (tStringNum == 1)
                        {
                            _entity->state[i].audioDBIndex = std::stoi(tString);
                        }
                        else if (tStringNum == 2)
                        {
                            _entity->state[i].audioRepeat = (std::stoi(tString) == 1);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += audioData[j];
                    }
                }
            }
        }
        
        // Set default state if required
        if ((_entity->animationIndependent) && (_entity->stateCount > 0) && (_entity->stateInitial > 0))
        {
            m_setAnimationState(_entity, _entity->stateInitial);
        }

        // Cleanup and return a pointer to the entity
        xmlFile.free();
        return _entity;
    }
    return nullptr; // Load failed
}

void cEntityManager::m_playSound(sEntity*& _entity, const std::uint32_t& _state)
{
    // Convert to zero indexed array
    std::uint32_t state = _state - 1;
    
    // Play sound associated with state, load first if need be
    if ((_entity->state[state].audioFile.length() > 3) && (_entity->state[state].audioSourceID == 0))
    {
        _entity->state[state].audioSourceID = m_audioManager->newAudioSource();
        m_audioManager->setAudioSourcePosition(_entity->state[state].audioSourceID, 0.0f, 0.0f, 0.0f);
        _entity->state[state].auidoBufferID = m_audioManager->newAudioBuffer();
        m_audioManager->loadBufferOgg(_entity->state[state].auidoBufferID, FILE_PATH_SOUND + _entity->state[state].audioFile);
        m_audioManager->setAudioBufferName(_entity->state[state].auidoBufferID, _entity->state[state].audioFile);
        m_audioManager->attachSourceBuffer(_entity->state[state].audioSourceID, _entity->state[state].auidoBufferID);
        m_audioManager->setAudioSourceLooping(_entity->state[state].audioSourceID, false);
    }
    
    // If the sound has been loaded, play it
    if (_entity->state[state].audioSourceID != 0)
    {
        m_audioManager->playSource(_entity->state[state].audioSourceID);
    }
}

void cEntityManager::m_setAnimationState(sEntity*& _entity, const std::uint32_t& _state)
{
    // Convert to zero indexed array
    std::uint32_t state = _state - 1;
    
    // Set animation data
    _entity->currentAnimTime   = _entity->state[state].animation.x;
    _entity->startAnimTime     = _entity->state[state].animation.x;
    _entity->stopAnimTime      = _entity->state[state].animation.y;
    _entity->repeatAnimation   = (_entity->state[state].animation.z > 0.001);
    _entity->finishedAnimation = false;
}

sEntity* cEntityManager::m_UIDtoEntity(const std::uint32_t& _UID)
{
    for(sEntity* entityTemp = getHead(); entityTemp != nullptr; entityTemp = entityTemp->next)
    {
        if (entityTemp->UID == _UID)
        {
            return entityTemp;
        }
    }
    return nullptr;
}

void cEntityManager::setState(const std::uint32_t& _UID, const std::string& _name)
{
    sEntity* entityTemp = m_UIDtoEntity(_UID);
    for (std::uint32_t i = 0; i < entityTemp->stateCount; ++i)
    {
        if (entityTemp->state[i].name.compare(_name) == 0)
        {
            setState(_UID, i + 1);
        }
    }
}

void cEntityManager::setState(const std::uint32_t& _UID, const std::uint32_t& _state)
{
    // Get the entity pointer first
    sEntity* entityTemp = m_UIDtoEntity(_UID);

    // Only change the state if it is different, and the previous animation has completed
    if (((entityTemp->repeatAnimation == false) && (entityTemp->stateCurrent != _state) && (entityTemp->finishedAnimation)) ||
        ((entityTemp->repeatAnimation == true) && (entityTemp->stateCurrent != _state)))
    {
        // Set the new state
        entityTemp->stateCurrent = _state; // Index from 1, not 0
        
        // Set animation data associated with state
        m_setAnimationState(entityTemp, entityTemp->stateCurrent);

        // Play sound associated with state
        m_playSound(entityTemp, entityTemp->stateCurrent);
    }
}

void cEntityManager::toggleState(const std::uint32_t& _UID, const std::uint32_t& _state1, const std::uint32_t& _state2)
{
    // Get the entity pointer first
    sEntity* entityTemp = m_UIDtoEntity(_UID);

    // Only toggle the state if the previous animation has completed
    if (entityTemp->finishedAnimation)
    {
        // Toggle the current state
        entityTemp->stateCurrent = (entityTemp->stateCurrent == _state1) ? _state2 : _state1;

        // Set animation data associated with state
        m_setAnimationState(entityTemp, entityTemp->stateCurrent);

        // Play sound associated with state
        m_playSound(entityTemp, entityTemp->stateCurrent);
    }
}
