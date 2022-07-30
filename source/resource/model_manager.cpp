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

#include "model_manager.hpp"

std::uint32_t cModelManager::initialize(void)
{
    return EXIT_SUCCESS;
}

void cModelManager::terminate(void)
{
    freeAll();
}

void cModelManager::freeData(sEntityModel*& _pointer)
{
    // It is assumed that other managers freed their data by this point
    if (_pointer != nullptr)
    {
        // free mesh data
        if (_pointer->mesh != nullptr)
        {
            for(std::uint32_t i = 0; i < _pointer->numMesh; ++i)
            {
                // opengl objects
                if (_pointer->mesh[i].VAO != 0)
                {
                    glDeleteVertexArrays(1, &_pointer->mesh[i].VAO);
                    _pointer->mesh[i].VAO = 0;
                }
                if (_pointer->mesh[i].VBO_vertices != 0)
                {
                    glDeleteBuffers(1, &_pointer->mesh[i].VBO_vertices);
                    _pointer->mesh[i].VBO_vertices = 0;
                }
                if (_pointer->mesh[i].VBO_bones != 0)
                {
                    glDeleteBuffers(1, &_pointer->mesh[i].VBO_bones);
                    _pointer->mesh[i].VBO_bones = 0;
                }
                if (_pointer->mesh[i].IBO != 0)
                {
                    glDeleteBuffers(1, &_pointer->mesh[i].IBO);
                    _pointer->mesh[i].IBO = 0;
                }

                 // vertex
                if (_pointer->mesh[i].vertex != nullptr)
                {
                    delete [] _pointer->mesh[i].vertex;
                    _pointer->mesh[i].vertex = nullptr;
                }
                 // vertex bone
                if (_pointer->mesh[i].vertexBone != nullptr)
                {
                    delete [] _pointer->mesh[i].vertexBone;
                    _pointer->mesh[i].vertexBone = nullptr;
                }
                // Index
                if (_pointer->mesh[i].index != nullptr)
                {
                    delete [] _pointer->mesh[i].index;
                    _pointer->mesh[i].index = nullptr;
                }
            }
            //free mesh array
            delete [] _pointer->mesh;
            _pointer->mesh = nullptr;
        }

        // free bone data
        if (_pointer->bone != nullptr)
        {
            //free bone array
            delete [] _pointer->bone;
            _pointer->bone = nullptr;
        }

        // animations
        if (_pointer->animation != nullptr)
        {
            for (size_t i = 0; i < _pointer->numAnimations; i++)
            {
                // channels
                if (_pointer->animation[i].channel != nullptr)
                {
                    for (size_t j = 0; j < _pointer->animation[i].numChannels; j++)
                    {
                        // position keys
                        if (_pointer->animation[i].channel[j].positionKey != nullptr)
                        {
                            delete[] _pointer->animation[i].channel[j].positionKey;
                            _pointer->animation[i].channel[j].positionKey = nullptr;
                        }
                        // rotation keys
                        if (_pointer->animation[i].channel[j].rotationKey != nullptr)
                        {
                            delete[] _pointer->animation[i].channel[j].rotationKey;
                            _pointer->animation[i].channel[j].rotationKey = nullptr;
                        }
                        // scaling keys
                        if (_pointer->animation[i].channel[j].scalingKey != nullptr)
                        {
                            delete[] _pointer->animation[i].channel[j].scalingKey;
                            _pointer->animation[i].channel[j].scalingKey = nullptr;
                        }
                    }
                    delete[] _pointer->animation[i].channel;
                    _pointer->animation[i].channel = nullptr;
                }
                // mesh channels
                if (_pointer->animation[i].meshChannel != nullptr)
                {
                    for (size_t j = 0; j < _pointer->animation[i].numMeshChannels; j++)
                    {
                        // mesh keys
                        if (_pointer->animation[i].meshChannel[j].meshKey != nullptr)
                        {
                            delete[] _pointer->animation[i].meshChannel[j].meshKey;
                            _pointer->animation[i].meshChannel[j].meshKey = nullptr;
                        }
                    }
                    delete[] _pointer->animation[i].meshChannel;
                    _pointer->animation[i].meshChannel = nullptr;
                }
            }
            delete[] _pointer->animation;
            _pointer->animation = nullptr;
        }
    }
}

/*
sEntityMaterial* cModelManager::loadMaterial(const std::string &_fileName)
{
    cXML xmlFile;
    xmlFile.load(FILE_PATH_MATERIAL + _fileName);
    if (xmlFile.lineCount() > 0)
    {
        sEntityMaterial* tMaterial = nullptr;

        // Get the data from the XML file
        std::string diffuseFile = xmlFile.getString("<diffuse>");
        std::string emissiveFile = xmlFile.getString("<emissive>");
        std::string normalFile = xmlFile.getString("<normal>");
        std::string specularFile = xmlFile.getString("<specular>");

        // Load defaults if is data missing, and log error
        if (diffuseFile.length() < 5)
        {
            gLogWrite(LOG_ERROR, "Diffuse file data missing in material file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
            diffuseFile = DEFAULT_TEXTURE_D;
        }
        if (emissiveFile.length() < 5)
        {
            gLogWrite(LOG_ERROR, "Emissive file data missing in material file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
            emissiveFile = DEFAULT_TEXTURE_E;
        }
        if (normalFile.length() < 5)
        {
            gLogWrite(LOG_ERROR, "Normal file data missing in material file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
            normalFile = DEFAULT_TEXTURE_N;
        }
        if (specularFile.length() < 5)
        {
            gLogWrite(LOG_ERROR, "Specular file data missing in material file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
            specularFile = DEFAULT_TEXTURE_S;
        }

        // Load defaults if files don't exist, and log error
        if (!fileExists(std::string(FILE_PATH_TEXTURE)+diffuseFile))
        {
            gLogWrite(LOG_ERROR, "Unable to locate file: " + diffuseFile, __FILE__, __LINE__, __FUNCTION__);
            diffuseFile = DEFAULT_TEXTURE_D;
        }
        if (!fileExists(std::string(FILE_PATH_TEXTURE)+emissiveFile))
        {
            gLogWrite(LOG_ERROR, "Unable to locate file: " + emissiveFile, __FILE__, __LINE__, __FUNCTION__);
            emissiveFile = DEFAULT_TEXTURE_E;
        }
        if (!fileExists(std::string(FILE_PATH_TEXTURE)+normalFile))
        {
            gLogWrite(LOG_ERROR, "Unable to locate file: " + normalFile, __FILE__, __LINE__, __FUNCTION__);
            normalFile = DEFAULT_TEXTURE_N;
        }
        if (!fileExists(std::string(FILE_PATH_TEXTURE)+specularFile))
        {
            gLogWrite(LOG_ERROR, "Unable to locate file: " + specularFile, __FILE__, __LINE__, __FUNCTION__);
            specularFile = DEFAULT_TEXTURE_S;
        }

        // Material manager load and return pointer
        tMaterial = materialManager.add(diffuseFile, emissiveFile, normalFile, specularFile);

        // Cleanup and return a pointer to the entity
        xmlFile.free();
        return tMaterial;
    }
    return nullptr; // Load failed
}
*/

sEntityModel* cModelManager::load(const std::string &_fileName)
{
//    model_obj_import(model, std::string(FILE_PATH_MODEL) + _fileName);


    // If the model has already been loaded, return a pointer to it
    // Also create a new instance
    for (sEntityModel* temp = getHead(); temp != nullptr; temp = temp->next)
    {
        if (temp->fileName.compare(_fileName) == 0)
        {
            return temp;
        }
    }

    // Add a short delay to prevent CPU saturation;
    gThreadSleep(1);

    // Else try to load the model
    sEntityModel* tModel = m_loadModel(_fileName);
    if (tModel != nullptr)
    {
        //gLogWrite(LOG_INFO, "Loading model: " + _fileName, __FILE__, __LINE__, __FUNCTION__);

        // Pass it to the model manager
        addBack(tModel);
    }
    return tModel; // if loadModel() failed, tModel == nullptr
}
