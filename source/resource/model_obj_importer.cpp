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

#include "model_obj.hpp"

void model_obj_import(sEntityModel *&_model, const std::string &_fileName)
{
    // Load using the standalone obj importer
    sOBJ *obj = nullptr;
    gLoadOBJ(obj, _fileName);

    // if load failed, early exit
    if (obj == nullptr)
        return;

    // convert obj data to to game engine specific format
    _model = new sEntityModel;
    _model->fileName = _fileName;
    _model->numMesh = obj->numMesh;
    _model->mesh = new sEntityModelMesh[_model->numMesh];

    // copy the vertex data
    for (std::uint32_t m = 0; m < _model->numMesh; ++m)
    {
        // vertex
        _model->mesh[m].numVertex = obj->mesh[m].numIndex;
        _model->mesh[m].vertex = new sEntityModelVertex[_model->mesh[m].numVertex];

        // index
        _model->mesh[m].numIndex = obj->mesh[m].numIndex;
        _model->mesh[m].index = new std::uint32_t[_model->mesh[m].numIndex];

        for (std::uint32_t v = 0; v < _model->mesh[m].numVertex; ++v)
        {
            // index
            _model->mesh[m].index[v] = v;

            // Vertex positions
            _model->mesh[m].vertex[v].position.x = obj->mesh[m].vertex[obj->mesh[m].index[v].v - 1].x;
            _model->mesh[m].vertex[v].position.y = obj->mesh[m].vertex[obj->mesh[m].index[v].v - 1].y;
            _model->mesh[m].vertex[v].position.z = obj->mesh[m].vertex[obj->mesh[m].index[v].v - 1].z;

            // Vertex normals
            _model->mesh[m].vertex[v].normal.x = obj->mesh[m].normal[obj->mesh[m].index[v].n - 1].x;
            _model->mesh[m].vertex[v].normal.y = obj->mesh[m].normal[obj->mesh[m].index[v].n - 1].y;
            _model->mesh[m].vertex[v].normal.z = obj->mesh[m].normal[obj->mesh[m].index[v].n - 1].z;

            // Vertex texture coordinates
            _model->mesh[m].vertex[v].texcoord.x = obj->mesh[m].texCoord[obj->mesh[m].index[v].t - 1].x;
            _model->mesh[m].vertex[v].texcoord.y = obj->mesh[m].texCoord[obj->mesh[m].index[v].t - 1].y;
        }

        // Calculate tangent and bi-tangent vectors
        for (std::uint32_t v = 0; v < _model->mesh[m].numVertex; v += 3)
        {
            gCalculateTangentBiTangent(_model->mesh[m].vertex[v + 0],
                                       _model->mesh[m].vertex[v + 1],
                                       _model->mesh[m].vertex[v + 2]);
        }
    }

    // Free the temporary obj data
    gFreeOBJ(obj);
}
