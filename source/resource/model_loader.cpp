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

std::uint32_t cModelManager::m_getNumMesh(const aiNode* _node, std::uint32_t _numMesh)
{
    if (_node != nullptr)
    {
        _numMesh += _node->mNumMeshes;
        for (std::uint32_t i = 0; i < _node->mNumChildren; ++i)
        {
            _numMesh += m_getNumMesh(_node->mChildren[i], _numMesh);
        }
    }
    return _numMesh;
}

void cModelManager::m_processMesh(const aiScene*& _scene, const aiMesh* _mesh, sEntityModel*& _model)
{
    if (_mesh != nullptr)
    {
        std::uint32_t meshNum = 0;
        //Find the next free mesh in _model to populate
        for (std::uint32_t i = 0; i < _model->numMesh; ++i)
        {
            if (_model->mesh[i].numVertex == 0)
            {
                meshNum = i;
                break;
            }
        }
/*
        // process this mesh's materials
        if (_scene->HasMaterials())
        {
            //Diffuse
            aiString aiTextureDiffuse;
            std::string textureDiffuse;
            if (_scene->mMaterials[_mesh->mMaterialIndex]->GetTextureCount(aiTextureType_DIFFUSE) > 0)
            {
                _scene->mMaterials[_mesh->mMaterialIndex]->GetTexture(aiTextureType_DIFFUSE, 0, &aiTextureDiffuse);
                textureDiffuse = aiTextureDiffuse.C_Str();
            }
            else
            {
                textureDiffuse = std::string(FILE_DEFAULT_TEXTURE) + "_d.png";
            }
            // Emissive
            aiString aiTextureEmissive;
            std::string textureEmissive;
            if (_scene->mMaterials[_mesh->mMaterialIndex]->GetTextureCount(aiTextureType_EMISSIVE) > 0)
            {
                _scene->mMaterials[_mesh->mMaterialIndex]->GetTexture(aiTextureType_EMISSIVE, 0, &aiTextureEmissive);
                textureEmissive = aiTextureEmissive.C_Str();
            }
            else
            {
                textureEmissive = std::string(FILE_DEFAULT_TEXTURE) + "_e.png";
            }
            // Normal
            aiString aiTextureNormal;
            std::string textureNormal;
            if (_scene->mMaterials[_mesh->mMaterialIndex]->GetTextureCount(aiTextureType_NORMALS) > 0)
            {
                _scene->mMaterials[_mesh->mMaterialIndex]->GetTexture(aiTextureType_NORMALS, 0, &aiTextureNormal);
                textureNormal = aiTextureNormal.C_Str();
            }
            else
            {
                textureNormal = std::string(FILE_DEFAULT_TEXTURE) + "_n.png";
            }
            // Specular
            aiString aiTextureSpecular;
            std::string textureSpecular;
            if (_scene->mMaterials[_mesh->mMaterialIndex]->GetTextureCount(aiTextureType_SPECULAR) > 0)
            {
                _scene->mMaterials[_mesh->mMaterialIndex]->GetTexture(aiTextureType_SPECULAR, 0, &aiTextureSpecular);
                textureSpecular = aiTextureSpecular.C_Str();
            }
            else
            {
                textureSpecular = std::string(FILE_DEFAULT_TEXTURE) + "_s.png";
            }
            // Get a pointer to the material
            //_model->mesh[meshNum].material = materialManager.add(textureDiffuse, textureEmissive, textureNormal, textureSpecular);
        }
*/
        // fill the model mesh with data from the assimp mesh
        // vertex data
        _model->mesh[meshNum].numVertex = _mesh->mNumVertices;
        _model->mesh[meshNum].vertex = new sEntityModelVertex[_model->mesh[meshNum].numVertex];
        for (std::uint32_t i = 0; i < _model->mesh[meshNum].numVertex; ++i)
        {
            if (_mesh->HasPositions())
            {
                _model->mesh[meshNum].vertex[i].position.x = _mesh->mVertices[i].x;
                _model->mesh[meshNum].vertex[i].position.y = _mesh->mVertices[i].y;
                _model->mesh[meshNum].vertex[i].position.z = _mesh->mVertices[i].z;
            }
            if (_mesh->HasNormals())
            {
                _model->mesh[meshNum].vertex[i].normal.x = _mesh->mNormals[i].x;
                _model->mesh[meshNum].vertex[i].normal.y = _mesh->mNormals[i].y;
                _model->mesh[meshNum].vertex[i].normal.z = _mesh->mNormals[i].z;
            }
            if (_mesh->HasTextureCoords(0))
            {
                _model->mesh[meshNum].vertex[i].texcoord.x = _mesh->mTextureCoords[0][i].x;
                _model->mesh[meshNum].vertex[i].texcoord.y = _mesh->mTextureCoords[0][i].y;
            }
            if (_mesh->HasTangentsAndBitangents())
            {
                // tangents
                _model->mesh[meshNum].vertex[i].tangent.x = _mesh->mTangents[i].x;
                _model->mesh[meshNum].vertex[i].tangent.y = _mesh->mTangents[i].y;
                _model->mesh[meshNum].vertex[i].tangent.z = _mesh->mTangents[i].z;

                // bitangents
                _model->mesh[meshNum].vertex[i].bitangent.x = _mesh->mBitangents[i].x;
                _model->mesh[meshNum].vertex[i].bitangent.y = _mesh->mBitangents[i].y;
                _model->mesh[meshNum].vertex[i].bitangent.z = _mesh->mBitangents[i].z;
            }
        }
        // index data
        if (_mesh->HasFaces())
        {
            //get the face count of the assimp mesh
            std::uint32_t faceCount = 0;
            for (std::uint32_t i = 0; i < _mesh->mNumFaces; ++i)
            {
                faceCount += _mesh->mFaces[i].mNumIndices;
            }
            // load the assimp face data into the model mesh index struct
            _model->mesh[meshNum].numIndex = faceCount;
            _model->mesh[meshNum].index = new std::uint32_t[_model->mesh[meshNum].numIndex];
            std::uint32_t indexNum = 0;
            for (std::uint32_t i = 0; i < _mesh->mNumFaces; ++i)
            {
                for (std::uint32_t j = 0; j < _mesh->mFaces[i].mNumIndices ; ++j)
                {
                    _model->mesh[meshNum].index[indexNum + j] = _mesh->mFaces[i].mIndices[j];
                }
                indexNum += _mesh->mFaces[i].mNumIndices;
            }
        }

        // process bones
        if (_mesh->mNumBones > 0)
        {
            _model->mesh[meshNum].vertexBone = new sEntityModelVertexBone[_model->mesh[meshNum].numVertex];
        }

        for (std::size_t i = 0; i < _mesh->mNumBones; ++i)
        {
            aiBone* bone = _mesh->mBones[i];
            std::int32_t boneID = m_getBoneID(bone->mName.C_Str());
            if (boneID > -1)
            {
                for (std::size_t j = 0; j < bone->mNumWeights; ++j)
                {
                    aiVertexWeight weight = bone->mWeights[j];
                    if (weight.mWeight > _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.w)
                    {
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.w = _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.z;
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneID.w     = _model->mesh[meshNum].vertexBone[weight.mVertexId].boneID.z;
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.z = _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.y;
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneID.z     = _model->mesh[meshNum].vertexBone[weight.mVertexId].boneID.y;
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.y = _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.x;
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneID.y     = _model->mesh[meshNum].vertexBone[weight.mVertexId].boneID.x;
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneWeight.x = weight.mWeight;
                        _model->mesh[meshNum].vertexBone[weight.mVertexId].boneID.x     = boneID;
                    }
                }
            }
        }


    }
}

void cModelManager::m_processNode(const aiScene*& _scene, const aiNode* _node, sEntityModel*& _model)
{
    if (_node != nullptr)
    {
        // process this nodes meshes
        for (std::uint32_t i = 0; i < _node->mNumMeshes; ++i)
        {
            m_processMesh(_scene, _scene->mMeshes[_node->mMeshes[i]] , _model);
        }

        // recursivly process child nodes
        for (std::uint32_t i = 0; i < _node->mNumChildren; ++i)
        {
            m_processNode(_scene, _node->mChildren[i] , _model);
        }
    }
}

void cModelManager::m_addBoneMap(const std::string &_name, const glm::mat4 &_mat4)
{
    std::int32_t found = -1;
    for (std::size_t k = 0; k < m_boneMap.size(); ++k)
    {
        if (m_boneMap[k].name.compare(_name) == 0)
        {
            found = k;
        }
    }
    if (found == -1)
    {
        sEntityBone tBone;
        tBone.ID   = m_boneMap.size();
        tBone.name = _name;
        tBone.transformPose = _mat4;
        m_boneMap.push_back(tBone);
    }
}

void cModelManager::m_buildBoneMap(aiNode* _node, const aiScene* _scene)
{
    // process node -> mesh -> bones
    for (std::size_t i = 0; i < _node->mNumMeshes; ++i)
    {
        aiMesh* mesh = _scene->mMeshes[_node->mMeshes[i]];
        for (std::size_t j = 0; j < mesh->mNumBones; ++j)
        {
            aiBone* bone = mesh->mBones[j];
            m_addBoneMap(bone->mName.C_Str(), toMat4(bone->mOffsetMatrix));
            //std::cout << "Found bone: " << m_boneMap[m_boneMap.size()-1].name << std::endl;
        }
    }

    // process children
    for (std::size_t i = 0; i < _node->mNumChildren; ++i)
    {
        m_buildBoneMap(_node->mChildren[i], _scene);
    }
}

void cModelManager::m_buildBoneMapParents(aiNode* _node, aiNode* _nodeParent, const aiScene* _scene)
{
    std::int32_t nodeID = m_getBoneID(_node->mName.C_Str());
    if ((_nodeParent != nullptr) && (nodeID > -1))
    {
        m_boneMap[nodeID].parentID = m_getBoneID(_nodeParent->mName.C_Str());
    }

    // process children
    for (std::size_t i = 0; i < _node->mNumChildren; ++i)
    {
        m_buildBoneMapParents(_node->mChildren[i], _node, _scene);
    }
}

std::int32_t cModelManager::m_getBoneID(const std::string &_name)
{
    for (std::size_t i = 0; i < m_boneMap.size(); ++i)
    {
        if(_name.compare(m_boneMap[i].name) == 0)
        {
            return m_boneMap[i].ID;
        }
    }
    return -1; // bone not found
}

void cModelManager::m_buildBoneMapNodes(aiNode* _node)
{
    //std::cout << "Checking node: " << _node->mName.C_Str() << std::endl;
    std::int32_t boneID = m_getBoneID(_node->mName.C_Str());
    if (boneID > -1)
    {
        //std::cout << "Loading node transform: " << _node->mName.C_Str() << std::endl;
        m_boneMap[boneID].transformNode = toMat4(_node->mTransformation);
    }
    for (std::size_t i = 0; i < _node->mNumChildren; ++i)
    {
        m_buildBoneMapNodes(_node->mChildren[i]);
    }
}

glm::mat4 cModelManager::m_getRecursiveTransforms(std::int32_t _ID)
{
    glm::mat4 rMat = m_boneMap[_ID].transformNode;
    if (m_boneMap[_ID].parentID > -1)
    {
        rMat = m_getRecursiveTransforms(m_boneMap[_ID].parentID) * rMat;
    }
    return rMat;
};

bool cModelManager::m_getNodeTransform(const aiNode* _node, const std::string &_name, glm::mat4 &_matrix)
{
    std::string name = _node->mName.C_Str();
    if (name.compare(_name) == 0)
    {
        _matrix = toMat4(_node->mTransformation);
        return true;
    }
    bool done = false;
    for (std::size_t i = 0; i < _node->mNumChildren; ++i)
    {
        if (!done)
        {
            done = m_getNodeTransform(_node->mChildren[i], _name, _matrix);
        }
    }
    return done;
}

void cModelManager::m_addMissingBoneMap(const aiScene* _scene)
{
    if (_scene->mNumAnimations > 0)
    {
        for (std::size_t i = 0; i < _scene->mNumAnimations; ++i)
        {
            for (std::size_t j = 0; j < _scene->mAnimations[i]->mNumChannels; ++j)
            {
                std::string boneName = _scene->mAnimations[i]->mChannels[j]->mNodeName.C_Str();
                glm::mat4   boneTransform;
                m_getNodeTransform(_scene->mRootNode, boneName, boneTransform);
                m_addBoneMap(boneName, boneTransform);
            }
        }
    }
}

void cModelManager::m_loadBones(sEntityModel* _model, const aiScene* _scene)
{
    m_buildBoneMap(_scene->mRootNode, _scene);
    m_addMissingBoneMap(_scene);
    if (m_boneMap.size() > 0)
    {
        m_buildBoneMapNodes(_scene->mRootNode);
        m_buildBoneMapParents(_scene->mRootNode, nullptr, _scene);
        _model->numBones     = m_boneMap.size();
        _model->bone         = new sEntityBone[_model->numBones];
        //std::cout << "Bone count: " << _model->numBones << std::endl;
        for (std::size_t i = 0; i < _model->numBones; ++i)
        {
            _model->bone[i].ID            = m_boneMap[i].ID;
            _model->bone[i].parentID      = m_boneMap[i].parentID;
            _model->bone[i].name          = m_boneMap[i].name.c_str();
            _model->bone[i].transformNode = m_boneMap[i].transformNode;
            _model->bone[i].transformPose = m_boneMap[i].transformPose;
        }
        for (std::size_t i = 0; i < _model->numBones; ++i)
        {
            _model->bone[i].transformFinal = _model->inverseTransform * m_getRecursiveTransforms(i) * _model->bone[i].transformPose;
        }
    }
}

void cModelManager::m_loadAnimations(sEntityModel* _model, const aiScene* _scene)
{
    _model->numAnimations = _scene->mNumAnimations;
    if (_scene->mNumAnimations > 0)
    {
        _model->animation     = new sEntityModelAnimation[_model->numAnimations];
        _model->animated     = (_model->numAnimations > 0);
        for (std::size_t i = 0; i < _model->numAnimations; ++i)
        {
            _model->animation[i].name            = _scene->mAnimations[i]->mName.C_Str();
            _model->animation[i].duration        = _scene->mAnimations[i]->mDuration;
            _model->animation[i].ticksPerSecond  = _scene->mAnimations[i]->mTicksPerSecond;
            _model->animation[i].ticksPerSecond += (_model->animation[i].ticksPerSecond == 0) ? 24 : 0;
            _model->animation[i].animationTime   = _model->animation[i].duration / _model->animation[i].ticksPerSecond;

            _model->animation[i].numChannels     = _scene->mAnimations[i]->mNumChannels;
            _model->animation[i].channel         = new sAnimationChannel[_model->animation[i].numChannels];
            for (std::size_t j = 0; j < _model->animation[i].numChannels; ++j)
            {
                _model->animation[i].channel[j].name   = _scene->mAnimations[i]->mChannels[j]->mNodeName.C_Str();
                _model->animation[i].channel[j].boneID = m_getBoneID(_model->animation[i].channel[j].name);

                // position vectors
                _model->animation[i].channel[j].numPositionKeys = _scene->mAnimations[i]->mChannels[j]->mNumPositionKeys;
                _model->animation[i].channel[j].positionKey = new sAnimationVecKey[_model->animation[i].channel[j].numPositionKeys];
                for (std::size_t k = 0; k < _model->animation[i].channel[j].numPositionKeys; ++k)
                {
                    _model->animation[i].channel[j].positionKey[k].time = _scene->mAnimations[i]->mChannels[j]->mPositionKeys[k].mTime;
                    _model->animation[i].channel[j].positionKey[k].vector = toVec3(_scene->mAnimations[i]->mChannels[j]->mPositionKeys[k].mValue);
                }

                // rotation quaternions
                _model->animation[i].channel[j].numRotationKeys = _scene->mAnimations[i]->mChannels[j]->mNumRotationKeys;
                _model->animation[i].channel[j].rotationKey = new sAnimationQuatKey[_model->animation[i].channel[j].numRotationKeys];
                for (std::size_t k = 0; k < _model->animation[i].channel[j].numRotationKeys; ++k)
                {
                    _model->animation[i].channel[j].rotationKey[k].time = _scene->mAnimations[i]->mChannels[j]->mRotationKeys[k].mTime;
                    _model->animation[i].channel[j].rotationKey[k].quat = toQuat(_scene->mAnimations[i]->mChannels[j]->mRotationKeys[k].mValue);
                }

                _model->animation[i].channel[j].numScalingKeys = _scene->mAnimations[i]->mChannels[j]->mNumScalingKeys;
                _model->animation[i].channel[j].scalingKey = new sAnimationVecKey[_model->animation[i].channel[j].numScalingKeys];
                for (std::size_t k = 0; k < _model->animation[i].channel[j].numScalingKeys; ++k)
                {
                    _model->animation[i].channel[j].scalingKey[k].time = _scene->mAnimations[i]->mChannels[j]->mScalingKeys[k].mTime;
                    _model->animation[i].channel[j].scalingKey[k].vector = toVec3(_scene->mAnimations[i]->mChannels[j]->mScalingKeys[k].mValue);
                }
            }

            _model->animation[i].numMeshChannels = _scene->mAnimations[i]->mNumMeshChannels;
            _model->animation[i].meshChannel    = new sAnimationMeshChannel[_model->animation[i].numMeshChannels];
            for (std::size_t j = 0; j < _model->animation[i].numMeshChannels; ++j)
            {
                _model->animation[i].meshChannel[j].name = _scene->mAnimations[i]->mMeshChannels[j]->mName.C_Str();

                _model->animation[i].meshChannel[j].numKeys = _scene->mAnimations[i]->mMeshChannels[j]->mNumKeys;
                _model->animation[i].meshChannel[j].meshKey = new sAnimationMeshKey[_model->animation[i].meshChannel[j].numKeys];
                for (std::size_t k = 0; k < _model->animation[i].meshChannel[j].numKeys; ++k)
                {
                    _model->animation[i].meshChannel[j].meshKey[k].time = _scene->mAnimations[i]->mMeshChannels[j]->mKeys[k].mTime;
                    _model->animation[i].meshChannel[j].meshKey[k].value = _scene->mAnimations[i]->mMeshChannels[j]->mKeys[k].mValue;
                }
            }
        }
    }
}

sEntityModel* cModelManager::m_loadModel(const std::string &_fileName)
{
    if (gFileExists(FILE_PATH_MODEL+_fileName))
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(FILE_PATH_MODEL+_fileName, aiProcess_CalcTangentSpace |
                                                                            aiProcess_GenSmoothNormals |
                                                                            aiProcess_Triangulate |
                                                                            aiProcess_LimitBoneWeights |
                                                                            aiProcess_FixInfacingNormals |
                                                                            aiProcess_FindInvalidData |
                                                                            aiProcess_ValidateDataStructure);
        if (scene != nullptr)
        {
            if ((scene->mFlags == 0) || (scene->mRootNode != nullptr))
            {
                sEntityModel* tModel = new sEntityModel;
                tModel->fileName = _fileName;
                tModel->numMesh = m_getNumMesh(scene->mRootNode);
                //std::cout << "Num mesh: " << tModel->numMesh << std::endl;
                tModel->mesh = new sEntityModelMesh[tModel->numMesh];
                tModel->inverseTransform = toMat4(scene->mRootNode->mTransformation);
                tModel->inverseTransform = glm::inverse(tModel->inverseTransform);

                // Make sure to build the bone map before calling m_processNode()!
                m_loadBones(tModel, scene);
                if (tModel->numBones > MAX_BONES)
                {
                    gLogWrite(LOG_WARNING, "3D model: " + _fileName + ", has too many bones: " + std::to_string(tModel->numBones), __FILE__, __LINE__, __FUNCTION__);
                }
                if (m_boneMap.size() > 0)
                {
                    m_loadAnimations(tModel, scene);
                }
                m_processNode(scene, scene->mRootNode, tModel);

                // Clean up
                m_boneMap.clear();
                return tModel;
            }
            else
            {
                gLogWrite(LOG_ERROR, "Assimp: " + std::string(importer.GetErrorString()), __FILE__, __LINE__, __FUNCTION__);
                return nullptr;
            }
        }
        else
        {
            gLogWrite(LOG_ERROR, "Assimp: " + std::string(importer.GetErrorString()), __FILE__, __LINE__, __FUNCTION__);
            return nullptr;
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to open file: " + std::string(FILE_PATH_MODEL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return nullptr;
    }
    return nullptr;
}
