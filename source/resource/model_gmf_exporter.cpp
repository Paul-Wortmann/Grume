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

#include "model_gmf.hpp"

void model_gmf_export(sEntityModel *&_model, const std::string &_fileName)
{
    // Early exit if no data
    if (_model == nullptr)
    {
        return;
    }

    std::ofstream gmfFile (_fileName, std::ofstream::out | std::ios::trunc);
    if(gmfFile.is_open())
    {
        std::cout << "Exporting model: " << _fileName << std::endl;

        // info
        gmfFile << "# Engine exported DAE" << std::endl;
        gmfFile << "# Name: " << _model->modelName << std::endl;
        gmfFile << "# FileName: " << _model->fileName << std::endl;
        gmfFile << std::endl;

        // mesh
        for (std::uint32_t i = 0; ((i < _model->numMesh) && (_model->mesh[i].numVertex > 0)); ++i)
        {
            gmfFile << "Model: " << i << std::endl << std::endl;
            // Vertex position data
            gmfFile << "Positions: " << std::endl;
            for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
            {
                gmfFile << "v " << _model->mesh[i].vertex[j].position.x << " "
                                << _model->mesh[i].vertex[j].position.y << " "
                                << _model->mesh[i].vertex[j].position.z << std::endl;
            }

            // Texture coord data
            gmfFile << "Texcoords: " << std::endl;
            for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
            {
                gmfFile << "vt " << _model->mesh[i].vertex[j].texcoord.x << " "
                                 << _model->mesh[i].vertex[j].texcoord.y << std::endl;
            }

            // Normal data
            gmfFile << "Positions: " << std::endl;
            for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
            {
                gmfFile << "vn " << _model->mesh[i].vertex[j].normal.x << " "
                                 << _model->mesh[i].vertex[j].normal.y << " "
                                 << _model->mesh[i].vertex[j].normal.z << std::endl;
            }

            if(_model->mesh[i].vertexBone != nullptr)
            {

                // Vertex bone ID data
                gmfFile << "Bone ID: " << std::endl;
                for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
                {
                    gmfFile << "vb " << _model->mesh[i].vertexBone[j].boneID.w << " "
                                     << _model->mesh[i].vertexBone[j].boneID.x << " "
                                     << _model->mesh[i].vertexBone[j].boneID.y << " "
                                     << _model->mesh[i].vertexBone[j].boneID.z << std::endl;
                }

                // Vertex bone weight data
                gmfFile << "Bone Weight: " << std::endl;
                for (std::uint32_t j = 0; j < _model->mesh[i].numVertex; ++j)
                {
                    gmfFile << "vw " << _model->mesh[i].vertexBone[j].boneWeight.w << " "
                                     << _model->mesh[i].vertexBone[j].boneWeight.x << " "
                                     << _model->mesh[i].vertexBone[j].boneWeight.y << " "
                                     << _model->mesh[i].vertexBone[j].boneWeight.z << std::endl;
                }
            }

            // Face data
            gmfFile << "Triangles: " << std::endl;
            for (std::uint32_t j = 0; j < _model->mesh[i].numIndex; ++j)
            {
                gmfFile << _model->mesh[i].index[j] << " ";
            }
            gmfFile << std::endl << std::endl;
        }

        gmfFile << "Num Bones: " << _model->numBones << std::endl;

        // skeleton data
        if (_model->numBones > 0)
        {
            // Bone data
            gmfFile << "Bones: " << std::endl;
            for (std::uint32_t b = 0; b < _model->numBones; ++b)
            {
                gmfFile << "Bone name: " << _model->bone[b].name << std::endl;
                gmfFile << "Bone ID: " << _model->bone[b].ID << std::endl;
                gmfFile << "Bone parent ID: " << _model->bone[b].parentID << std::endl;
                gmfFile << "Bone transform node: " << std::endl;
                gmfFile << _model->bone[b].transformNode[0][0] << " " << _model->bone[b].transformNode[0][1] << " " << _model->bone[b].transformNode[0][2] << " " << _model->bone[b].transformNode[0][3] << " ";
                gmfFile << _model->bone[b].transformNode[1][0] << " " << _model->bone[b].transformNode[1][1] << " " << _model->bone[b].transformNode[1][2] << " " << _model->bone[b].transformNode[1][3] << " ";
                gmfFile << _model->bone[b].transformNode[2][0] << " " << _model->bone[b].transformNode[2][1] << " " << _model->bone[b].transformNode[2][2] << " " << _model->bone[b].transformNode[2][3] << " ";
                gmfFile << _model->bone[b].transformNode[3][0] << " " << _model->bone[b].transformNode[3][1] << " " << _model->bone[b].transformNode[3][2] << " " << _model->bone[b].transformNode[3][3] << " ";
                gmfFile << std::endl;
                gmfFile << "Bone transform pose: " << std::endl;
                gmfFile << _model->bone[b].transformPose[0][0] << " " << _model->bone[b].transformPose[0][1] << " " << _model->bone[b].transformPose[0][2] << " " << _model->bone[b].transformPose[0][3] << " ";
                gmfFile << _model->bone[b].transformPose[1][0] << " " << _model->bone[b].transformPose[1][1] << " " << _model->bone[b].transformPose[1][2] << " " << _model->bone[b].transformPose[1][3] << " ";
                gmfFile << _model->bone[b].transformPose[2][0] << " " << _model->bone[b].transformPose[2][1] << " " << _model->bone[b].transformPose[2][2] << " " << _model->bone[b].transformPose[2][3] << " ";
                gmfFile << _model->bone[b].transformPose[3][0] << " " << _model->bone[b].transformPose[3][1] << " " << _model->bone[b].transformPose[3][2] << " " << _model->bone[b].transformPose[3][3] << " ";
                gmfFile << std::endl;
            }
        }

        gmfFile.close();
    }

}
