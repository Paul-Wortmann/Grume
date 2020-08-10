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

#include "model_exporter.hpp"

std::string quatToString(glm::quat _quat)
{
    std::string rString = "";
    rString += std::to_string(_quat.x);
    rString += ",";
    rString += std::to_string(_quat.y);
    rString += ",";
    rString += std::to_string(_quat.z);
    rString += ",";
    rString += std::to_string(_quat.w);
    return rString;
}

std::string mat4ToString(glm::mat4 _mat4)
{
    const uint16_t dSize = 16;
    std::string rString = "";
    const float *pSource = (const float*)glm::value_ptr(_mat4);
    for (std::size_t i = 0; i < dSize; ++i)
    {
        rString += std::to_string(pSource[i]);
        if (i < (dSize - 1))
        {
            rString += ",";
        }
    }
    return rString;
}

std::string ivec4ToString(glm::ivec4 _ivec4)
{
    std::string rString = "";
    rString += std::to_string(_ivec4[0]);
    rString += ",";
    rString += std::to_string(_ivec4[1]);
    rString += ",";
    rString += std::to_string(_ivec4[2]);
    rString += ",";
    rString += std::to_string(_ivec4[3]);
    return rString;
}

std::string vec4ToString(glm::vec4 _vec4)
{
    std::string rString = "";
    rString += std::to_string(_vec4.x);
    rString += ",";
    rString += std::to_string(_vec4.y);
    rString += ",";
    rString += std::to_string(_vec4.z);
    rString += ",";
    rString += std::to_string(_vec4.w);
    return rString;
}

std::string vec3ToString(glm::vec3 _vec3)
{
    std::string rString = "";
    rString += std::to_string(_vec3.x);
    rString += ",";
    rString += std::to_string(_vec3.y);
    rString += ",";
    rString += std::to_string(_vec3.z);
    return rString;
}

std::string vec2ToString(glm::vec2 _vec2)
{
    std::string rString = "";
    rString += std::to_string(_vec2.x);
    rString += ",";
    rString += std::to_string(_vec2.y);
    return rString;
}

void cModelExporter::save(sEntityModel* _model, const std::string &_fileName)
{
    std::ofstream clearFile(_fileName, std::fstream::trunc | std::fstream::out);
    clearFile.close();
    
    std::ofstream outFile(_fileName, std::fstream::out | std::fstream::app);
    if (outFile.is_open())
    {
        // xml header
        outFile << std::string(0, ' ') << "<?xml version = \"1.0\" encoding = \"UTF-8\" ?>" << std::endl;

        outFile << std::string(0, ' ') << "<model>" << std::endl;
        
        // Model data
        outFile << std::string(3, ' ') << "<detail_section>" << std::endl;
        outFile << std::string(6, ' ') << "<bone_count value=\"" << _model->numBones << "\"/>" << std::endl;
        outFile << std::string(6, ' ') << "<animation_count value=\"" << _model->numAnimations << "\"/>" << std::endl;
        outFile << std::string(6, ' ') << "<material_count value=\"" << _model->numMaterials << "\"/>" << std::endl;
        outFile << std::string(6, ' ') << "<mesh_count value=\"" << _model->numMesh << "\"/>" << std::endl;
        outFile << std::string(3, ' ') << "</detail_section>" << std::endl;
        
        // Bones
        outFile << std::endl;
        outFile << std::string(3, ' ') << "<bone_section>" << std::endl;
        for (std::size_t i = 0; i < _model->numBones; i++)
        {
            outFile << std::string(6, ' ') << "<bone ID=\"" << _model->bone[i].ID 
                                           << "\" name=\"" << _model->bone[i].name
                                           << "\" parent=\"" << _model->bone[i].parentID
                                           << "\" transform_pose=\"" << mat4ToString(_model->bone[i].transformPose)
                                           << "\" transform_node=\"" << mat4ToString(_model->bone[i].transformNode)
                                           << "\"/>" << std::endl;
        }
        outFile << std::string(3, ' ') << "</bone_section>" << std::endl;
        
        // Animations
        outFile << std::endl;
        outFile << std::string(3, ' ') << "<animation_section>" << std::endl;
        for (std::size_t i = 0; i < _model->numAnimations; i++)
        {
            outFile << std::string(6, ' ') << "<animation ID=\"" << std::to_string(i) << "\">" << std::endl;
            outFile << std::string(6, ' ') << "<channel_count value=\"" << std::to_string(_model->animation[i].numChannels) << "\"/>" << std::endl;
            for (std::size_t j = 0; j < _model->animation[i].numChannels; j++)
            {
                outFile << std::string(9, ' ') << "<channel ID=\"" << std::to_string(j) << "\">" << std::endl;
                outFile << std::string(12, ' ') << "<position_key_count value=\"" << std::to_string(_model->animation[i].channel[j].numPositionKeys) << "\">" << std::endl;
                for (std::size_t k = 0; k < _model->animation[i].channel[j].numPositionKeys; k++)
                {
                    outFile << std::string(12, ' ') << "<position_key ID=\"" << std::to_string(k)
                                                    << "\" time=\"" << std::to_string(_model->animation[i].channel[j].positionKey[k].time)
                                                    << "\" vector=\"" << vec3ToString(_model->animation[i].channel[j].positionKey[k].vector)
                                                    << "\"/>" << std::endl;
                }
                outFile << std::string(12, ' ') << "<rotation_key_count value=\"" << std::to_string(_model->animation[i].channel[j].numRotationKeys) << "\">" << std::endl;
                for (std::size_t k = 0; k < _model->animation[i].channel[j].numRotationKeys; k++)
                {
                    outFile << std::string(12, ' ') << "<rotation_key ID=\"" << std::to_string(k)
                                                    << "\" time=\"" << std::to_string(_model->animation[i].channel[j].rotationKey[k].time)
                                                    << "\" quat=\"" << quatToString(_model->animation[i].channel[j].rotationKey[k].quat)
                                                    << "\"/>" << std::endl;
                }
                outFile << std::string(12, ' ') << "<scaling_key_count value=\"" << std::to_string(_model->animation[i].channel[j].numScalingKeys) << "\">" << std::endl;
                for (std::size_t k = 0; k < _model->animation[i].channel[j].numScalingKeys; k++)
                {
                    outFile << std::string(12, ' ') << "<scaling_key ID=\"" << std::to_string(k)
                                                    << "\" time=\"" << std::to_string(_model->animation[i].channel[j].scalingKey[k].time)
                                                    << "\" vector=\"" << vec3ToString(_model->animation[i].channel[j].scalingKey[k].vector)
                                                    << "\"/>" << std::endl;
                }
                outFile << std::string(9, ' ') << "</channel>" << std::endl;
            }
            outFile << std::string(6, ' ') << "</animation>" << std::endl;
        }
        
        outFile << std::string(3, ' ') << "</animation_section>" << std::endl;
        
        // Materials
        outFile << std::endl;
        outFile << std::string(3, ' ') << "<material_section>" << std::endl;
        for (std::size_t i = 0; i < _model->numMaterials; i++)
        {
            outFile << std::string(6, ' ') << "<material ID=\"" << _model->material[i].ID
                                           << "\" diffuse_file=\"" << _model->material[i].diffuse.fileName
                                           << "\" normal_file=\"" << _model->material[i].normal.fileName
                                           << "\" specular_file=\"" << _model->material[i].specular.fileName
                                           << "\"/>" << std::endl;
        }
        outFile << std::string(3, ' ') << "</material_section>" << std::endl;
        
        // Meshes
        outFile << std::endl;
        outFile << std::string(3, ' ') << "<mesh_section>" << std::endl;
        for (std::size_t i = 0; i < _model->numMesh; i++)
        {
            outFile << std::string(6, ' ') << "<mesh ID=\"" << std::to_string(i) << "\">" << std::endl;
            outFile << std::string(9, ' ') << "<material_ID value=\"" << _model->mesh[i].materialID << "\"/>" << std::endl;
            outFile << std::string(9, ' ') << "<vertex_count value=\"" << _model->mesh[i].numVertex << "\"/>" << std::endl;
            outFile << std::string(9, ' ') << "<index_count value=\"" << _model->mesh[i].numIndex << "\"/>" << std::endl;
            outFile << std::string(9, ' ') << "<!-- Vertex: position(3f), normal(3f), tangent(3f), bitangent(3f), texCoords(2f)-->" << std::endl;
            for (std::size_t j = 0; j < _model->mesh[i].numVertex; j++)
            {
                outFile << std::string(9, ' ') << "<vertex ID=\"" << std::to_string(j)
                                               << "\" data=\""    << vec3ToString(_model->mesh[i].vertex[j].position)
                                               << ","             << vec3ToString(_model->mesh[i].vertex[j].normal)
                                               << ","             << vec3ToString(_model->mesh[i].vertex[j].tangent)
                                               << ","             << vec3ToString(_model->mesh[i].vertex[j].bitangent)
                                               << ","             << vec2ToString(_model->mesh[i].vertex[j].texcoord)
                                               << "\"/>" << std::endl;
            }
            outFile << std::string(9, ' ') << "<!-- Skinning: boneID(4i), boneWeight(4f)-->" << std::endl;
            if (_model->numBones > 0)
            {
                for (std::size_t j = 0; j < _model->mesh[i].numVertex; j++)
                {
                    outFile << std::string(9, ' ') << "<skinning ID=\"" << std::to_string(j)
                                                   << "\" data=\""    << ivec4ToString(_model->mesh[i].vertexBone[j].boneID)
                                                   << ","             << vec4ToString(_model->mesh[i].vertexBone[j].boneWeight)
                                                   << "\"/>" << std::endl;
                }
            }
            outFile << std::string(6, ' ') << "</mesh>" << std::endl;
        }
        outFile << std::string(3, ' ') << "</mesh_section>" << std::endl;

        outFile << std::string(0, ' ') << "</model>" << std::endl;
        outFile.close();
    }
}


