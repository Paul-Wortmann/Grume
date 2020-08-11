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

#include "model_manager.hpp"

void cModelManager::initialize(void)
{
    
}

void cModelManager::terminate(void)
{
    freeModels();
}

void cModelManager::freeModels(void)
{
    if (m_modelHead != nullptr)
    {
        sEntityModel* modelDel = m_modelHead;
        for(m_modelTemp = m_modelHead->next; m_modelTemp != nullptr; m_modelTemp = m_modelTemp->next)
        {
            if (modelDel != nullptr)
            {
                m_freeModelData(modelDel);
                delete modelDel;
                modelDel = nullptr;
            }
            modelDel = m_modelTemp;
        }
        if (modelDel != nullptr)
        {
            m_freeModelData(modelDel);
            delete modelDel;
            modelDel = nullptr;
        }
    }
    m_modelHead = nullptr;
    m_modelTail = nullptr;
    m_modelTemp = nullptr;
    m_count = 0;
}

void cModelManager::m_freeModelData(sEntityModel *_model)
{
    // model compnent 
    if (_model != nullptr)
    {
        // model matrix
        if (_model->modelMatrix != nullptr)
        {
            delete[] _model->modelMatrix;
            _model->modelMatrix = nullptr;
        }
        
        // mesh data
        if ((_model->numMesh != 0) && (_model->mesh != nullptr))
        {
            for (size_t i = 0; i < _model->numMesh; i++)
            {
                // opengl objects
                if (_model->mesh[i].VAO != 0)
                {
                    glDeleteVertexArrays(1, &_model->mesh[i].VAO);
                    _model->mesh[i].VAO = 0;
                }
                if (_model->mesh[i].VBO_vertices != 0)
                {
                    glDeleteBuffers(1, &_model->mesh[i].VBO_vertices);
                    _model->mesh[i].VBO_vertices = 0;
                }
                if (_model->mesh[i].VBO_bones != 0)
                {
                    glDeleteBuffers(1, &_model->mesh[i].VBO_bones);
                    _model->mesh[i].VBO_bones = 0;
                }
                if (_model->mesh[i].IBO != 0)
                {
                    glDeleteBuffers(1, &_model->mesh[i].IBO);
                    _model->mesh[i].IBO = 0;
                }
                
                // vertex data
                if (_model->mesh[i].vertex != nullptr)
                {
                    delete[] _model->mesh[i].vertex;
                    _model->mesh[i].vertex = nullptr;
                }
                
                // vertex bone data
                if (_model->mesh[i].vertexBone != nullptr)
                {
                    delete[] _model->mesh[i].vertexBone;
                    _model->mesh[i].vertexBone = nullptr;
                }
                
                // indices
                if (_model->mesh[i].index != nullptr)
                {
                    delete[] _model->mesh[i].index;
                    _model->mesh[i].index = nullptr;
                }
            }
            delete[] _model->mesh;
            _model->mesh = nullptr;
        }
        
        //bones
        if (_model->bone != nullptr)
        {
            delete[] _model->bone;
            _model->bone = nullptr;
        }
        
        // animations
        if (_model->animation != nullptr)
        {
            for (size_t i = 0; i < _model->numAnimations; i++)
            {
                // channels
                if (_model->animation[i].channel != nullptr)
                {
                    for (size_t j = 0; j < _model->animation[i].numChannels; j++)
                    {
                        // position keys
                        if (_model->animation[i].channel[j].positionKey != nullptr)
                        {
                            delete[] _model->animation[i].channel[j].positionKey;
                            _model->animation[i].channel[j].positionKey = nullptr;
                        }
                        // rotation keys
                        if (_model->animation[i].channel[j].rotationKey != nullptr)
                        {
                            delete[] _model->animation[i].channel[j].rotationKey;
                            _model->animation[i].channel[j].rotationKey = nullptr;
                        }
                        // scaling keys
                        if (_model->animation[i].channel[j].scalingKey != nullptr)
                        {
                            delete[] _model->animation[i].channel[j].scalingKey;
                            _model->animation[i].channel[j].scalingKey = nullptr;
                        }
                    }
                    delete[] _model->animation[i].channel;
                    _model->animation[i].channel = nullptr;
                }
                // mesh channels
                if (_model->animation[i].meshChannel != nullptr)
                {
                    for (size_t j = 0; j < _model->animation[i].numMeshChannels; j++)
                    {
                        // mesh keys
                        if (_model->animation[i].meshChannel[j].meshKey != nullptr)
                        {
                            delete[] _model->animation[i].meshChannel[j].meshKey;
                            _model->animation[i].meshChannel[j].meshKey = nullptr;
                        }
                    }
                    delete[] _model->animation[i].meshChannel;
                    _model->animation[i].meshChannel = nullptr;
                }
            }
            delete[] _model->animation;
            _model->animation = nullptr;
        }

        // materials
        if (_model->material != nullptr)
        {
            delete[] _model->material;
            _model->material = nullptr;
        }
    }
}

uint32_t cModelManager::isLoaded(const std::string &_fileName)
{
    if (m_modelHead == nullptr)
    {
        m_modelHead = new sEntityModel;
        m_modelTail = m_modelHead;
    }
    else
    {
        for(m_modelTemp = m_modelHead; m_modelTemp != nullptr; m_modelTemp = m_modelTemp->next)
        {
            if (std::strcmp(_fileName.c_str(), m_modelTemp->fileName.c_str()) == 0)
            {
                return m_modelTemp->numInstances;
            }
        }
    }
    return 0;
}

void cModelManager::addInstance(sEntityModel* _model, const glm::mat4 &_transform)
{
    if (_model != nullptr)
    {
        if (_model->modelMatrix != nullptr)
        {
            glm::mat4* tInstances = new glm::mat4[_model->numInstances];
            for (std::size_t i = 0; i < _model->numInstances; i++)
            {
                tInstances[i] = _model->modelMatrix[i];
            }
            delete[] _model->modelMatrix;
            _model->numInstances++;
            _model->modelMatrix = new glm::mat4[_model->numInstances];
            for (std::size_t i = 0; i < _model->numInstances - 1; i++)
            {
                _model->modelMatrix[i] = tInstances[i];
            }
            _model->modelMatrix[_model->numInstances - 1] = _transform;
            delete[] tInstances;
        }
        else
        {
            _model->numInstances++;
            _model->modelMatrix = new glm::mat4[_model->numInstances];
            _model->modelMatrix[_model->numInstances - 1] = _transform;
        }
    }
}

sEntityModel* cModelManager::load(const std::string &_fileName)
{
    if (m_modelHead == nullptr)
    {
        m_modelHead = new sEntityModel;
        m_modelTail = m_modelHead;
    }
    else
    {
        for(m_modelTemp = m_modelHead; m_modelTemp != nullptr; m_modelTemp = m_modelTemp->next)
        {
            if (std::strcmp(_fileName.c_str(), m_modelTemp->fileName.c_str()) == 0)
            {
                return m_modelTemp;
            }
        }
    }
    m_count++;
    m_modelTail->next = new sEntityModel;
    m_modelTail = m_modelTail->next;
    m_modelTail->fileName = _fileName;
    m_load(m_modelTail, std::string(PATH_MODEL + _fileName).c_str());
    return m_modelTail;
}

void cModelManager::m_load(sEntityModel* _model, const std::string &_fileName)
{
    m_modelLoader.load(_model, _fileName);
}

void cModelManager::save(sEntityModel* _model, const std::string &_fileName)
{
    m_modelExporter.save(_model, _fileName);
}

uint32_t cModelManager::getAnimationCount(sEntityModel* _model)
{
    return (_model != nullptr) ? _model->numAnimations : 0;
}

void     cModelManager::setAnimation(sEntityModel* _model, uint32_t _anim)
{
    if ((_model != nullptr) && (_anim <= _model->numAnimations))
    {
        _model->currentAnimation = _anim;
    }
}

void cModelManager::generateMesh(sEntityModel* _model, const sEntityModeleGeneratorInfo &_info)
{
    m_modelGenerator.generateMesh(_model, _info);
}
