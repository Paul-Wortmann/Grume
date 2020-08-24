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

#include "model_generator.hpp"

glm::vec3 cModelGenerator::m_generateNormal(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c)
{
    glm::vec3 rNormal;
    glm::vec3 v1 = _b - _a;
    glm::vec3 v2 = _c - _a;
    
    rNormal.x = (v1.y * v2.z) - (v1.z - v2.y);
    rNormal.y = (v1.z * v2.x) - (v1.x - v2.z);
    rNormal.z = (v1.x * v2.y) - (v1.y - v2.x);
    
    return rNormal;
}

void cModelGenerator::generateModel(sEntityModel* _model, const sEntityModelGeneratorInfo &_info)
{
    if (_model == nullptr)
    {
        gLogWrite(LOG_ERROR, "Model generation failed:  " + _info.name, __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    
    float start_x = static_cast<float>(_info.units_x / 2) * _info.size_x;
    float start_y = static_cast<float>(_info.units_y / 2) * _info.size_y;
    float size_x  = _info.size_x / 2.0f;
    float size_y  = _info.size_y / 2.0f;
    
    const uint16_t numVerts = 6;
    const float tVertices[numVerts * 2] =
    {
        -1.0f,  1.0f,
         1.0f,  1.0f,
        -1.0f, -1.0f,

        -1.0f, -1.0f,
         1.0f,  1.0f,
         1.0f, -1.0f,
    };
    
    _model->numInstances = 1;
    _model->modelMatrix  = new glm::mat4(1);
    _model->numMesh = 1;
    _model->mesh    = new sMesh[_model->numMesh];
    _model->mesh[0].numIndex  = _info.units_x * _info.units_y * 2 * 3;
    _model->mesh[0].index     = new uint32_t[_model->mesh[0].numIndex];
    for (std::size_t i = 0; i < _model->mesh[0].numIndex; ++i)
    {
        _model->mesh[0].index[i] = i;
    }
    _model->mesh[0].numVertex = _model->mesh[0].numIndex;
    _model->mesh[0].vertex    = new sVertex[_model->mesh[0].numVertex];
    uint32_t currentVertex = 0;
    for (std::size_t y = 0; y < _info.units_y; ++y)
    {
        for (std::size_t x = 0; x < _info.units_x; ++x)
        {
            for (std::size_t v = 0; v < numVerts; ++v)
            {
                _model->mesh[currentVertex + v].vertex->position.x = start_x + (size_x * 2.0 * x) + (tVertices[(v * 2) + 0] * size_x);
                _model->mesh[currentVertex + v].vertex->position.z = start_y + (size_y * 2.0 * y) + (tVertices[(v * 2) + 1] * size_y);
            
                if ((v > 0) && (((v + 1) % 3) == 0))
                {
                    _model->mesh[currentVertex + v - 0].vertex->normal = m_generateNormal(_model->mesh[currentVertex + v - 0].vertex->position,
                                                                                          _model->mesh[currentVertex + v - 1].vertex->position,
                                                                                          _model->mesh[currentVertex + v - 2].vertex->position);
                    _model->mesh[currentVertex + v - 1].vertex->normal = _model->mesh[currentVertex + v - 0].vertex->normal;
                    _model->mesh[currentVertex + v - 2].vertex->normal = _model->mesh[currentVertex + v - 0].vertex->normal;
                }
            }
            currentVertex += numVerts;
        }
    }
}

