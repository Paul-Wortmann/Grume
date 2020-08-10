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

#include "model_loader.hpp"

void cModelLoader::m_processMesh(sEntityModel* _model, aiMesh* _mesh, const aiScene* _scene)
{
    // find the next free mesh node in the sEntityModel
    int32_t meshNum = -1;
    for (std::size_t i = 0; i < _model->numMesh; ++i)
    {
        if ((meshNum == -1) && (_model->mesh[i].vertex == nullptr))
        {
            meshNum = i;
        }
    }
    
    // process vertices
    _model->mesh[meshNum].numVertex = _mesh->mNumVertices;
    _model->mesh[meshNum].vertex = new sVertex[_mesh->mNumVertices];
    
    for (std::size_t i = 0; i < _mesh->mNumVertices; ++i)
    {
        // positions
        _model->mesh[meshNum].vertex[i].position.x = _mesh->mVertices[i].x;
        _model->mesh[meshNum].vertex[i].position.y = _mesh->mVertices[i].y;
        _model->mesh[meshNum].vertex[i].position.z = _mesh->mVertices[i].z;

        // normals
        _model->mesh[meshNum].vertex[i].normal.x = _mesh->mNormals[i].x;
        _model->mesh[meshNum].vertex[i].normal.y = _mesh->mNormals[i].y;
        _model->mesh[meshNum].vertex[i].normal.z = _mesh->mNormals[i].z;
        
        // tangents
        if (_mesh->mTangents)
        {
            _model->mesh[meshNum].vertex[i].tangent.x = _mesh->mTangents[i].x;
            _model->mesh[meshNum].vertex[i].tangent.y = _mesh->mTangents[i].y;
            _model->mesh[meshNum].vertex[i].tangent.z = _mesh->mTangents[i].z;
        }
        
        // bitangents
        if (_mesh->mBitangents)
        {
            _model->mesh[meshNum].vertex[i].bitangent.x = _mesh->mBitangents[i].x;
            _model->mesh[meshNum].vertex[i].bitangent.y = _mesh->mBitangents[i].y;
            _model->mesh[meshNum].vertex[i].bitangent.z = _mesh->mBitangents[i].z;
        }
        
        // texcoords
        if (_mesh->mTextureCoords[0])
        {
            _model->mesh[meshNum].vertex[i].texcoord.x = _mesh->mTextureCoords[0][i].x;
            _model->mesh[meshNum].vertex[i].texcoord.y = _mesh->mTextureCoords[0][i].y;
        }
    }
    
    // process vertices
    _model->mesh[meshNum].numIndex = m_getIndexCount(_mesh, _scene);
    _model->mesh[meshNum].index = new uint32_t[_model->mesh[meshNum].numIndex];
    uint64_t indexNum = 0;
    for (std::size_t i = 0; i < _mesh->mNumFaces; ++i)
    {
        for (std::size_t j = 0; j < _mesh->mFaces[i].mNumIndices; ++j)
        {
            _model->mesh[meshNum].index[indexNum] = _mesh->mFaces[i].mIndices[j];
            indexNum++;
        }
    }
    
    // process materials / textures
    if (_scene->mNumMaterials > 0)
    {
        std::string diffuseFile  = "0";
        std::string normalFile   = "0";
        std::string specularFile = "0";

        aiMaterial* material = _scene->mMaterials[_mesh->mMaterialIndex];
        aiString fileName;
        if (material->GetTextureCount(aiTextureType_DIFFUSE) > 0)
        {
            material->GetTexture(aiTextureType_DIFFUSE, 0, &fileName);
            diffuseFile = fileName.C_Str();
        }
        if (material->GetTextureCount(aiTextureType_NORMALS) > 0)
        {
            material->GetTexture(aiTextureType_NORMALS, 0, &fileName);
            normalFile = fileName.C_Str();
        }
        if (material->GetTextureCount(aiTextureType_SPECULAR) > 0)
        {
            material->GetTexture(aiTextureType_SPECULAR, 0, &fileName);
            specularFile = fileName.C_Str();
        }
        _model->mesh[meshNum].materialID = m_getMaterialID(diffuseFile, normalFile, specularFile);
    }
    
    // process bones
    if (_mesh->mNumBones > 0)
    {
        _model->mesh[meshNum].vertexBone = new sVertexBone[_mesh->mNumVertices];
    }

    for (std::size_t i = 0; i < _mesh->mNumBones; ++i)
    {
        aiBone* bone = _mesh->mBones[i];
        int32_t boneID = m_getBoneID(bone->mName.C_Str());
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


/*
    std::ofstream outFile("mesh_data.txt", std::fstream::out | std::fstream::app);
    if (outFile.is_open())
    {
        outFile << "Mesh name: " << _mesh->mName.C_Str() << std::endl;
        outFile << "-----------------------------------------" << std::endl << std::endl;
        for (std::size_t i = 0; i < _mesh->mNumVertices; ++i)
        {
            outFile << "Vertex bone weights-> x: " << _model->mesh[meshNum].vertexBone[i].boneWeight.x;
            outFile << " y: " << _model->mesh[meshNum].vertexBone[i].boneWeight.y;
            outFile << " z: " << _model->mesh[meshNum].vertexBone[i].boneWeight.z;
            outFile << " w: " << _model->mesh[meshNum].vertexBone[i].boneWeight.w << std::endl;

            outFile << "Vertex bone IDs-> x: " << _model->mesh[meshNum].vertexBone[i].boneID.x;
            outFile << " y: " << _model->mesh[meshNum].vertexBone[i].boneID.y;
            outFile << " z: " << _model->mesh[meshNum].vertexBone[i].boneID.z;
            outFile << " w: " << _model->mesh[meshNum].vertexBone[i].boneID.w << std::endl;
        }
    }
    outFile.close();
*/
}

void cModelLoader::m_loadMeshes(sEntityModel* _model, aiNode* _node, const aiScene* _scene)
{
    // process node
    for (std::size_t i = 0; i < _node->mNumMeshes; ++i)
    {
        m_processMesh(_model, _scene->mMeshes[_node->mMeshes[i]], _scene);
    }
    
    // process children
    for (std::size_t i = 0; i < _node->mNumChildren; ++i)
    {
        m_loadMeshes(_model, _node->mChildren[i], _scene);
    }
}

uint32_t cModelLoader::m_getMeshCount(aiNode* _node, const aiScene* _scene)
{
    uint32_t count = _node->mNumMeshes;
    
    // process children
    for (std::size_t i = 0; i < _node->mNumChildren; ++i)
    {
        count += m_getMeshCount(_node->mChildren[i], _scene);
    }
    return count;
}

uint64_t cModelLoader::m_getIndexCount(aiMesh* _mesh, const aiScene* _scene)
{
    uint64_t count = 0;
    
    for (std::size_t i = 0; i < _mesh->mNumFaces; ++i)
    {
        count += _mesh->mFaces[i].mNumIndices;
    }
    return count;
}

void cModelLoader::m_buildBoneMap(aiNode* _node, const aiScene* _scene)
{
    // process node -> mesh -> bones
    for (std::size_t i = 0; i < _node->mNumMeshes; ++i)
    {
        aiMesh* mesh = _scene->mMeshes[_node->mMeshes[i]];
        for (std::size_t j = 0; j < mesh->mNumBones; ++j)
        {
            aiBone* bone = mesh->mBones[j];
            int32_t found = -1;
            std::string name = bone->mName.C_Str();
            for (std::size_t k = 0; k < m_boneMap.size(); ++k)
            {
                if (m_boneMap[k].name.compare(name) == 0)
                {
                    found = k;
                }
            }
            if (found == -1)
            {
                sBone tBone;
                tBone.ID   = m_boneMap.size();
                tBone.name = name;
                tBone.transformPose = toMat4(bone->mOffsetMatrix);
                m_boneMap.push_back(tBone);
                //std::cout << "Found bone: " << m_boneMap[m_boneMap.size()-1].name << std::endl;
            }
        }
    }
    
    // process children
    for (std::size_t i = 0; i < _node->mNumChildren; ++i)
    {
        m_buildBoneMap(_node->mChildren[i], _scene);
    }
}

void cModelLoader::m_buildBoneMapParents(aiNode* _node, aiNode* _nodeParent, const aiScene* _scene)
{
    int32_t nodeID = m_getBoneID(_node->mName.C_Str());
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

int32_t cModelLoader::m_getBoneID(const std::string &_name)
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

void cModelLoader::m_buildBoneMapNodes(aiNode* _node)
{
    //std::cout << "Checking node: " << _node->mName.C_Str() << std::endl;
    int32_t boneID = m_getBoneID(_node->mName.C_Str());
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

glm::mat4 cModelLoader::m_getRecursiveTransforms(int32_t _ID)
{
    glm::mat4 rMat = m_boneMap[_ID].transformNode;
    if (m_boneMap[_ID].parentID > -1)
    {
        rMat = m_getRecursiveTransforms(m_boneMap[_ID].parentID) * rMat;
    }
    return rMat;
};

void cModelLoader::m_loadBones(sEntityModel* _model, const aiScene* scene)
{
    m_buildBoneMap(scene->mRootNode, scene);
    if (m_boneMap.size() > 0)
    {
        m_buildBoneMapNodes(scene->mRootNode);
        m_buildBoneMapParents(scene->mRootNode, nullptr, scene);
        _model->numBones     = m_boneMap.size();
        _model->bone         = new sBone[_model->numBones];
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

void cModelLoader::m_loadAnimations(sEntityModel* _model, const aiScene* _scene)
{
    _model->numAnimations = _scene->mNumAnimations;
    if (_scene->mNumAnimations > 0)
    {
        _model->animation     = new sAnimation[_model->numAnimations];
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

void export_bones(sEntityModel* _model)
{
    std::ofstream clearFile("DEBUG_FILE.txt", std::fstream::trunc | std::fstream::out);
    clearFile.close();
    
    std::ofstream outFile("DEBUG_FILE.txt", std::fstream::out | std::fstream::app);
    if (outFile.is_open())
    
    for (std::size_t i = 0; i < _model->numMesh; ++i)
    {
        outFile << "Model name: " << _model->fileName << std::endl;
        outFile << "-----------------------------------" << std::endl << std::endl;
        for (std::size_t j = 0; j < _model->mesh[i].numVertex ; ++j)
        {
            outFile << "ID: " << _model->mesh[i].vertexBone[j].boneID.x << " - ";
            outFile << "ID: " << _model->mesh[i].vertexBone[j].boneID.y << " - ";
            outFile << "ID: " << _model->mesh[i].vertexBone[j].boneID.z << " - ";
            outFile << "ID: " << _model->mesh[i].vertexBone[j].boneID.w << std::endl;

            outFile << "Bw: " << _model->mesh[i].vertexBone[j].boneWeight.x << " - ";
            outFile << "Bw: " << _model->mesh[i].vertexBone[j].boneWeight.y << " - ";
            outFile << "Bw: " << _model->mesh[i].vertexBone[j].boneWeight.z << " - ";
            outFile << "Bw: " << _model->mesh[i].vertexBone[j].boneWeight.w << std::endl << std::endl;
        }
    }
    outFile.close();
}

void cModelLoader::m_saveMaterials(sEntityModel* _model)
{
    if (m_materialMap.size() > 0)
    {
        _model->numMaterials = m_materialMap.size();
        _model->material     = new sMaterial[_model->numMaterials];
        for (std::size_t i = 0; i < _model->numMaterials; ++i)
        {
            _model->material[i].ID                = m_materialMap[i].ID;
            _model->material[i].diffuse.fileName  = m_materialMap[i].diffuse.fileName;
            _model->material[i].normal.fileName   = m_materialMap[i].normal.fileName;
            _model->material[i].specular.fileName = m_materialMap[i].specular.fileName;
        }
    }
}

uint32_t cModelLoader::m_getMaterialID(const std::string &_diffuse, const std::string &_normal, const std::string &_specular)
{
    uint32_t index = -1;
    for (std::size_t i = 0; i < m_materialMap.size(); ++i)
    {
        if ((m_materialMap[i].diffuse.fileName.compare(_diffuse.c_str()) == 0)
         && (m_materialMap[i].normal.fileName.compare(_normal.c_str()) == 0)
         && (m_materialMap[i].specular.fileName.compare(_specular.c_str()) == 0))
        {
            index = i;
        }
    }
    
    if (index == -1)
    {
        sMaterial tMaterial;
        tMaterial.diffuse.fileName  = _diffuse.c_str();
        tMaterial.normal.fileName   = _normal.c_str();
        tMaterial.specular.fileName = _specular.c_str();
        tMaterial.ID                = m_materialMap.size();
        index = tMaterial.ID;
        m_materialMap.push_back(tMaterial);
    }
    return index;
}

void cModelLoader::load(sEntityModel* _model, const std::string &_fileName)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(_fileName,
        aiProcess_GenSmoothNormals |
        aiProcess_LimitBoneWeights |
        aiProcess_Triangulate |
        aiProcess_CalcTangentSpace);
    if ((scene == nullptr) || (scene->mFlags != 0) || (scene->mRootNode == nullptr))
    {
        gLogWrite(LOG_ERROR, "cModelLoader - Error loading file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    gLogWrite(LOG_INFO, "cModelLoader - Loading file: " + _fileName + " : " + importer.GetErrorString(), __FILE__, __LINE__, __FUNCTION__);

    _model->numMesh      = m_getMeshCount(scene->mRootNode, scene);
    _model->mesh         = new sMesh[_model->numMesh];
    _model->numInstances = 1;
    _model->modelMatrix  = new glm::mat4[_model->numInstances];
    _model->modelMatrix[0] = glm::mat4(1);
    //glm::mat4 rotMat = glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(1, 0, 0));
    //_model->modelMatrix[0] = rotMat * _model->modelMatrix[0];

    _model->inverseTransform = toMat4(scene->mRootNode->mTransformation);
    _model->inverseTransform = glm::inverse(_model->inverseTransform);
    
    // Make sure to build the bone map before calling m_loadMeshes!
    m_loadBones(_model, scene);
    if (m_boneMap.size() > 0)
    {
        m_loadAnimations(_model, scene);
    }
    m_loadMeshes(_model, scene->mRootNode, scene);
    m_saveMaterials(_model);

    //export_bones(_model);
}
