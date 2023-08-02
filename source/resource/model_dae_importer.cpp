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

#include "model_dae.hpp"

void model_dae_import(sEntityModel *&_model, const std::string &_fileName)
{
    // Load using the standalone dae importer
    sDAEModel *dae = nullptr;
    gLoadDAE(dae, _fileName);

    // if load failed, early exit
    if (dae == nullptr)
        return;

    // convert dae data to to game engine specific format
    _model = new sEntityModel;
    _model->fileName = _fileName;
    _model->numMesh = dae->numMesh;
    _model->mesh = new sEntityModelMesh[_model->numMesh];
    _model->numBones = dae->numBone;
    _model->numAnimations = dae->numAnimations;

    // model inverseTransform matrix
    _model->inverseTransform = glm::inverse(dae->inverseTransform);

    // copy the mesh data
    for (std::uint32_t m = 0; m < _model->numMesh; ++m)
    {
        // Name
        _model->mesh[m].name = dae->mesh[m].name;

        // vertex
        _model->mesh[m].numVertex = dae->mesh[m].numIndex;
        _model->mesh[m].vertex = new sEntityModelVertex[_model->mesh[m].numVertex];

        // index
        _model->mesh[m].numIndex = dae->mesh[m].numIndex;
        _model->mesh[m].index = new std::uint32_t[_model->mesh[m].numIndex];

        // skeleton
        if (_model->numBones > 0)
        {
            // vertexBone
            _model->mesh[m].vertexBone = new sEntityModelVertexBone[_model->mesh[m].numVertex];
        }

        for (std::uint32_t v = 0; v < _model->mesh[m].numVertex; ++v)
        {
            // index
            _model->mesh[m].index[v] = v;

            // Vertex positions
            _model->mesh[m].vertex[v].position.x = dae->mesh[m].position[dae->mesh[m].index[v].x].x;
            _model->mesh[m].vertex[v].position.y = dae->mesh[m].position[dae->mesh[m].index[v].x].y;
            _model->mesh[m].vertex[v].position.z = dae->mesh[m].position[dae->mesh[m].index[v].x].z;

            // Apply node transform
            _model->mesh[m].vertex[v].position = glm::vec4(_model->mesh[m].vertex[v].position, 1.0) * dae->mesh[m].transform;

            // Vertex normals
            _model->mesh[m].vertex[v].normal.x = dae->mesh[m].normal[dae->mesh[m].index[v].y].x;
            _model->mesh[m].vertex[v].normal.y = dae->mesh[m].normal[dae->mesh[m].index[v].y].y;
            _model->mesh[m].vertex[v].normal.z = dae->mesh[m].normal[dae->mesh[m].index[v].y].z;

            // Vertex texture coordinates
            _model->mesh[m].vertex[v].texcoord.x = dae->mesh[m].texCoord[dae->mesh[m].index[v].z].x;
            _model->mesh[m].vertex[v].texcoord.y = dae->mesh[m].texCoord[dae->mesh[m].index[v].z].y;

            // Skinning data
            if (_model->numBones > 0)
            {
                // bone IDs
                _model->mesh[m].vertexBone[v].boneID.x = dae->mesh[m].boneID[dae->mesh[m].index[v].x].x;
                _model->mesh[m].vertexBone[v].boneID.y = dae->mesh[m].boneID[dae->mesh[m].index[v].x].y;
                _model->mesh[m].vertexBone[v].boneID.z = dae->mesh[m].boneID[dae->mesh[m].index[v].x].z;
                _model->mesh[m].vertexBone[v].boneID.w = dae->mesh[m].boneID[dae->mesh[m].index[v].x].w;

                // bone Weights
                _model->mesh[m].vertexBone[v].boneWeight.x = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].x;
                _model->mesh[m].vertexBone[v].boneWeight.y = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].y;
                _model->mesh[m].vertexBone[v].boneWeight.z = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].z;
                _model->mesh[m].vertexBone[v].boneWeight.w = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].w;
            }

        }

        // Calculate tangent and bi-tangent vectors
        for (std::uint32_t v = 0; v < _model->mesh[m].numVertex; v += 3)
        {
            gCalculateTangentBiTangent(_model->mesh[m].vertex[v + 0],
                                       _model->mesh[m].vertex[v + 1],
                                       _model->mesh[m].vertex[v + 2]);
        }

        // Bone data
        if (_model->numBones > 0)
        {
            // Allocate memory
            _model->bone = new sEntityBone[_model->numBones];

            // copy bone data for each bone
            for (std::uint32_t b = 0; b < _model->numBones; ++b)
            {
                _model->bone[b].ID = dae->bone[b].ID;
                _model->bone[b].name = dae->bone[b].name;
                _model->bone[b].parentID = dae->bone[b].parentID;
                _model->bone[b].transformNode = dae->bone[b].transformNode;
                _model->bone[b].transformPose = dae->bone[b].transformPose;
                _model->bone[b].transformFinal = glm::mat4(1);
            }
        }

        // Animation data
        if ((_model->numBones > 0) && (_model->numAnimations > 0))
        {
            _model->animated = true;
        }

    }

    // Free the temporary dae data
    gFreeDAE(dae);
}
