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
{/**
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

#include "model_dae_loader.hpp"

void gImportModelDAE(const std::string &_fileName, sModel *&_model)
{
    // Load using the standalone dae importer
    sDAEModel *dae = nullptr;
    gLoadDAE(dae, _fileName);

    // if load failed, early exit
    if (dae == nullptr)
        return;

    // convert dae data to to game engine specific format
    _model = new sModel;
    _model->fileName = _fileName;
    _model->numMesh = dae->numMesh;
    _model->mesh = new sModelMesh[_model->numMesh];

    // copy the vertex data
    for (std::uint32_t m = 0; m < _model->numMesh; ++m)
    {
        // Name
        _model->mesh[m].name = dae->mesh[m].name;

        // vertex
        _model->mesh[m].numVertex = dae->mesh[m].numIndex;
        _model->mesh[m].vertex = new sModelVertex[_model->mesh[m].numVertex];

        // index
        _model->mesh[m].numIndex = dae->mesh[m].numIndex;
        _model->mesh[m].index = new std::uint32_t[_model->mesh[m].numIndex];

        // skinning data
        if (dae->numBone > 0)
        {
            // vertex bone
            _model->mesh[m].numVertexBone = _model->mesh[m].numVertex;
            _model->mesh[m].vertexBone    = new sModelVertexBone[_model->mesh[m].numVertexBone];
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
            _model->mesh[m].vertex[v].texCoord.x = dae->mesh[m].texCoord[dae->mesh[m].index[v].z].x;
            _model->mesh[m].vertex[v].texCoord.y = dae->mesh[m].texCoord[dae->mesh[m].index[v].z].y;

            // Skinning data
            if (dae->numBone > 0)
            {
                // bone IDs
                _model->mesh[m].vertexBone[v].boneID.w = dae->mesh[m].boneID[dae->mesh[m].index[v].x].w;
                _model->mesh[m].vertexBone[v].boneID.x = dae->mesh[m].boneID[dae->mesh[m].index[v].x].x;
                _model->mesh[m].vertexBone[v].boneID.y = dae->mesh[m].boneID[dae->mesh[m].index[v].x].y;
                _model->mesh[m].vertexBone[v].boneID.z = dae->mesh[m].boneID[dae->mesh[m].index[v].x].z;

                // bone Weights
                _model->mesh[m].vertexBone[v].boneWeight.w = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].w;
                _model->mesh[m].vertexBone[v].boneWeight.x = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].x;
                _model->mesh[m].vertexBone[v].boneWeight.y = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].y;
                _model->mesh[m].vertexBone[v].boneWeight.z = dae->mesh[m].boneWeight[dae->mesh[m].index[v].x].z;
            }
        }

        // Calculate tangent and bi-tangent vectors
        for (std::uint32_t v = 0; v < _model->mesh[m].numVertex; v += 3)
        {
            gCalculateTangentBiTangent(_model->mesh[m].vertex[v + 0],
                                       _model->mesh[m].vertex[v + 1],
                                       _model->mesh[m].vertex[v + 2]);
        }



    }

    // Free the temporary dae data
    gFreeDAE(dae);
}
