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

#include "re_generate_mesh.hpp"
#include "../roboengine.hpp"

namespace RoboEngine
{

    void re_GenerateMesh(uint32_t _size, re_sGenMesh &_mesh)
    {
/*
        struct v_uint32_t
        {
            float x;
            float y;
        };
        // generate point matrix
        uint32_t pointCount = _size * _size;
        v_uint32_t *pMatrix = new v_uint32_t[pointCount];
        for (uint32_t i = 0; i < _size; i++)
        {
            for (uint32_t j = 0; j < _size; j++)
            {
                pMatrix[(i*_size)+j].x = j;
                pMatrix[(i*_size)+j].y = i;
            }
        }
        // center point matrix at origin
        float poisitionDelta = _size / 2.0f;
        for (uint32_t i = 0; i < pointCount; i++)
        {
            pMatrix[i].x -= poisitionDelta;
            pMatrix[i].y -= poisitionDelta;
        }
        // normalize points
        float normalDelta = 1.0f / _size;
        for (uint32_t i = 0; i < pointCount; i++)
        {
            pMatrix[i].x *= normalDelta;
            pMatrix[i].y *= normalDelta;
        }
        delete[] pMatrix;
*/
        _mesh.indexCount = _size * _size * 6;
        _mesh.index = new v8_f[_mesh.indexCount];
        uint64_t _indexOffset = 0;
        float _cellSize = 1.0f;
        float poisitionDelta = (_size * _cellSize) / 2.0f;
        for (uint32_t i = 0; i < _size; i++)
        {
            for (uint32_t j = 0; j < _size; j++)
            {
                // generate vertices
                _mesh.index[_indexOffset+0].x = ((j*_cellSize*2) - _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+0].y = ((i*_cellSize*2) + _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+0].z = 0;
                _mesh.index[_indexOffset+1].x = ((j*_cellSize*2) + _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+1].y = ((i*_cellSize*2) - _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+1].z = 0;
                _mesh.index[_indexOffset+2].x = ((j*_cellSize*2) - _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+2].y = ((i*_cellSize*2) - _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+2].z = 0;
                _mesh.index[_indexOffset+3].x = ((j*_cellSize*2) - _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+3].y = ((i*_cellSize*2) + _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+3].z = 0;
                _mesh.index[_indexOffset+4].x = ((j*_cellSize*2) + _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+4].y = ((i*_cellSize*2) + _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+4].z = 0;
                _mesh.index[_indexOffset+5].x = ((j*_cellSize*2) + _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+5].y = ((i*_cellSize*2) - _cellSize) - poisitionDelta;
                _mesh.index[_indexOffset+5].z = 0;
                // generate uvs
                _mesh.index[_indexOffset+0].s = 0;
                _mesh.index[_indexOffset+0].t = 0;
                _mesh.index[_indexOffset+1].s = 1;
                _mesh.index[_indexOffset+1].t = 1;
                _mesh.index[_indexOffset+2].s = 0;
                _mesh.index[_indexOffset+2].t = 1;
                _mesh.index[_indexOffset+3].s = 0;
                _mesh.index[_indexOffset+3].t = 0;
                _mesh.index[_indexOffset+4].s = 1;
                _mesh.index[_indexOffset+4].t = 0;
                _mesh.index[_indexOffset+5].s = 1;
                _mesh.index[_indexOffset+5].t = 1;
                // generate normals
                for (uint32_t k = 0; k < 6; k++)
                {
                    _mesh.index[_indexOffset+k].nx = 0;
                    _mesh.index[_indexOffset+k].ny = 0;
                    _mesh.index[_indexOffset+k].nz = -1;
                }
                _indexOffset += 6;
            }
        }
    }

}
