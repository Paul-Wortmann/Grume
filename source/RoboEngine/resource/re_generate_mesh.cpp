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
        _mesh.indexCount = _size * _size * 4;
        _mesh.index = new v8_f[_mesh.indexCount];
        float _cellSize = 1.0f;// / _size;
        uint64_t _index = 0;
        for (uint32_t i = 0; i < _size; i++)
        {
            for (uint32_t j = 0; j < _size; j++)
            {
                // generate vertices
                _mesh.index[(i*_size)+j+0].x = (j+0) * _cellSize;
                _mesh.index[(i*_size)+j+0].y = (i+0) * _cellSize;
                _mesh.index[(i*_size)+j+0].z = 0;
                _mesh.index[(i*_size)+j+1].x = (j+0) * _cellSize;
                _mesh.index[(i*_size)+j+1].y = (i+1) * _cellSize;
                _mesh.index[(i*_size)+j+1].z = 0;
                _mesh.index[(i*_size)+j+2].x = (j+1) * _cellSize;
                _mesh.index[(i*_size)+j+2].y = (i+0) * _cellSize;
                _mesh.index[(i*_size)+j+2].z = 0;
                _mesh.index[(i*_size)+j+3].x = (j+1) * _cellSize;
                _mesh.index[(i*_size)+j+3].y = (i+1) * _cellSize;
                _mesh.index[(i*_size)+j+3].z = 0;
                // generate uvs
                _mesh.index[(i*_size)+j+0].s = 0;
                _mesh.index[(i*_size)+j+0].t = 0;
                _mesh.index[(i*_size)+j+1].s = 1;
                _mesh.index[(i*_size)+j+1].t = 1;
                _mesh.index[(i*_size)+j+2].s = 0;
                _mesh.index[(i*_size)+j+2].t = 1;
                _mesh.index[(i*_size)+j+3].s = 1;
                _mesh.index[(i*_size)+j+3].t = 0;
                // generate normals
                _mesh.index[(i*_size)+j+0].nx = 0;
                _mesh.index[(i*_size)+j+0].ny = 0;
                _mesh.index[(i*_size)+j+0].nz = -1;
                _mesh.index[(i*_size)+j+1].nx = 0;
                _mesh.index[(i*_size)+j+1].ny = 0;
                _mesh.index[(i*_size)+j+1].nz = -1;
                _mesh.index[(i*_size)+j+2].nx = 0;
                _mesh.index[(i*_size)+j+2].ny = 0;
                _mesh.index[(i*_size)+j+2].nz = -1;
                _mesh.index[(i*_size)+j+3].nx = 0;
                _mesh.index[(i*_size)+j+3].ny = 0;
                _mesh.index[(i*_size)+j+3].nz = -1;
            }
            _index += 4;
        }

    }

}
