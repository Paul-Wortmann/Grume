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

void model_obj_export(sEntityModel* &_model, const std::string &_fileName)
{
/*
    // Early exit if no data
    if (_model == nullptr)
    {
        return;
    }

    std::ofstream objFile (_fileName, std::ofstream::out | std::ios::trunc);
    if(objFile.is_open())
    {
        // Because the obj standard is stupid...
        // Vertex, normal and texture coord data are specified separately per object,
        // however face indices can reference any objects data??
        std::uint32_t vertexOffset = 0;

        objFile << "# Engine exported OBJ" << std::endl;
        for (std::uint32_t i = 0; i < _model->numMesh; ++i)
        {
            // Object name
            objFile << "o " << _model->mesh[i].name << std::endl;

            // Vertex data
            for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
            {
                objFile << "v " << _model->mesh[i].vertex[j].vertex[0] << " "
                                << _model->mesh[i].vertex[j].vertex[1] << " "
                                << _model->mesh[i].vertex[j].vertex[2] << std::endl;
            }

            // Texture coord data
            for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
            {
                objFile << "vt " << _model->mesh[i].vertex[j].texcrd[0] << " "
                                 << _model->mesh[i].vertex[j].texcrd[1] << std::endl;
            }

            // Normal data
            for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
            {
                objFile << "vn " << _model->mesh[i].vertex[j].normal[0] << " "
                                 << _model->mesh[i].vertex[j].normal[1] << " "
                                 << _model->mesh[i].vertex[j].normal[2] << std::endl;
            }

            // Material name
            objFile << "usemtl None" << std::endl;

            // Smooth shading
            objFile << "s off" << std::endl;

            // Face data
            for (std::uint32_t j = 0; j < _model->mesh[i].numIndex; j += 3)
            {
                objFile << "f " << j + 1 + vertexOffset << "/" << j + 1 + vertexOffset << "/" << j + 1 + vertexOffset << " "
                                << j + 2 + vertexOffset << "/" << j + 2 + vertexOffset << "/" << j + 2 + vertexOffset << " "
                                << j + 3 + vertexOffset << "/" << j + 3 + vertexOffset << "/" << j + 3 + vertexOffset << std::endl;
            }
            vertexOffset += _model->mesh[i].numVertex;
        }
        objFile.close();
    }
*/
}

