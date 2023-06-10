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

#include "model_dae_loader.hpp"

void gFreeDAE(sDAEModel *&_dae)
{
    // DAE
    if (_dae != nullptr)
    {
        // mesh
        if (_dae->mesh != nullptr)
        {
            // for each mesh
            for (std::uint32_t i = 0; i < _dae->numMesh; ++i)
            {
                // index
                if (_dae->mesh[i].index != nullptr)
                {
                    delete[] _dae->mesh[i].index;
                    _dae->mesh[i].index = nullptr;
                }

                // normal
                if (_dae->mesh[i].normal != nullptr)
                {
                    delete[] _dae->mesh[i].normal;
                    _dae->mesh[i].normal = nullptr;
                }

                // texCoord
                if (_dae->mesh[i].texCoord != nullptr)
                {
                    delete[] _dae->mesh[i].texCoord;
                    _dae->mesh[i].texCoord = nullptr;
                }

                // position
                if (_dae->mesh[i].position != nullptr)
                {
                    delete[] _dae->mesh[i].position;
                    _dae->mesh[i].position = nullptr;
                }

                // color
                if (_dae->mesh[i].color != nullptr)
                {
                    delete[] _dae->mesh[i].color;
                    _dae->mesh[i].color = nullptr;
                }

                // bone ID
                if (_dae->mesh[i].boneID != nullptr)
                {
                    delete[] _dae->mesh[i].boneID;
                    _dae->mesh[i].boneID = nullptr;
                }

                // bone weight
                if (_dae->mesh[i].boneWeight != nullptr)
                {
                    delete[] _dae->mesh[i].boneWeight;
                    _dae->mesh[i].boneWeight = nullptr;
                }
            }

            // free mesh memory
            delete[] _dae->mesh;
            _dae->mesh = nullptr;
        }

        // bone
        if (_dae->bone != nullptr)
        {
            delete[] _dae->bone;
            _dae->bone = nullptr;
        }

        // Animation
        if (_dae->animation != nullptr)
        {
            // animation nodes
            if (_dae->animation->node != nullptr)
            {
                for (std::uint32_t i = 0; i < _dae->animation->numNodes; ++i)
                {
                    // keyframes
                    if (_dae->animation->node->keyFrame != nullptr)
                    {
                        delete[] _dae->animation->node->keyFrame;
                        _dae->animation->node->keyFrame = nullptr;
                    }

                    // transforms
                    if (_dae->animation->node->transform != nullptr)
                    {
                        delete[] _dae->animation->node->transform;
                        _dae->animation->node->transform = nullptr;
                    }
                }

                delete[] _dae->animation->node;
                _dae->animation->node = nullptr;
            }

            delete[] _dae->animation;
            _dae->animation = nullptr;
        }

        // free _dae memory
        delete _dae;
        _dae = nullptr;
    }
}

// load dae data
void gLoadDAE(sDAEModel *&_dae, const std::string &_fileName)
{
    // space count lambda
    auto _stringSpaceCount = [](const std::string &_string)
    {
        std::uint32_t sCount = 0;
        std::uint64_t sLength = _string.length();

        for (std::uint64_t i = 0; i < sLength; ++i)
        {
            if (_string[i] == ' ')
                sCount++;
        }
        return sCount;
    };

    // open dae file
    cXML daeFile;
    daeFile.load(_fileName);
    if (daeFile.isValid())
    {
        std::cout << "Loading model: " << _fileName << std::endl;

        // free object if necessary
        if (_dae != nullptr)
        {
            gFreeDAE(_dae);
        }

        // Create a new model
        _dae = new sDAEModel;

        // Up axis
        std::string upAxis = daeFile.getString("<up_axis>");
        if (upAxis.compare("X_UP") == 0)
            _dae->upAxis = eUpAxis::xUp;
        else if (upAxis.compare("X_DOWN") == 0)
            _dae->upAxis = eUpAxis::xDown;
        else if (upAxis.compare("Y_UP") == 0)
            _dae->upAxis = eUpAxis::yUp;
        else if (upAxis.compare("Y_DOWN") == 0)
            _dae->upAxis = eUpAxis::yDown;
        else if (upAxis.compare("Z_UP") == 0)
            _dae->upAxis = eUpAxis::zUp;
        else if (upAxis.compare("Z_DOWN") == 0)
            _dae->upAxis = eUpAxis::zDown;

        // Parse <library_geometries>
        _dae->numMesh = daeFile.getInstanceCount("geometry id");
        _dae->mesh = new sDAEMesh[_dae->numMesh];
        for(std::uint32_t m = 0; m < _dae->numMesh; ++m)
        {
            // Mesh name
            std::string meshID = daeFile.getStringKeyValue("geometry id", "id", m + 1);
            _dae->mesh[m].name = daeFile.getStringKeyValue("geometry id", "name", m + 1);
            std::string controlerID = _dae->mesh[m].name + "-skin";

            //std::cout << "Mesh name: " << _dae->mesh[m].name << std::endl;
            //std::cout << "Mesh ID: " << meshID << std::endl;

            // vertex positions data
            std::string sData = daeFile.getStringKeyValue("#" + meshID + "-positions-array", "count");
            if (sData.length() > 0)
            {
                _dae->mesh[m].numPosition = stoi(sData);
                _dae->mesh[m].position = new glm::vec3[_dae->mesh[m].numPosition];

                // Parse positions data
                std::string   posiionsFloatArray = daeFile.getString(meshID + "-positions-array" + '"' + " count=" + '"' + std::to_string(_dae->mesh[m].numPosition * 3) + '"');
                posiionsFloatArray += " ";
                std::uint32_t posiionsFloatArrayLength = posiionsFloatArray.length();
                std::uint32_t sCount = 0;
                std::uint32_t iCount = 0;
                std::string   tData  = {};

                for (std::uint64_t i = 0; i < posiionsFloatArrayLength; ++i)
                {
                    if (posiionsFloatArray[i] == ' ')
                    {
                      // add data to array
                        if (sCount % 3 == 0)
                        {
                            _dae->mesh[m].position[iCount].x = stof(tData);
                        }
                        if (sCount % 3 == 1)
                        {
                            _dae->mesh[m].position[iCount].y = stof(tData);
                        }
                        if (sCount % 3 == 2)
                        {
                            _dae->mesh[m].position[iCount].z = stof(tData);
                            iCount++;
                        }
                        sCount++;
                        tData = "";
                    }
                    else
                    {
                        tData += posiionsFloatArray[i];
                    }
                }
            }
            //std::cout << "Number positions: " << _dae->mesh[m].numPosition << std::endl;

            // vertex normals data
            sData = daeFile.getStringKeyValue("#" + meshID + "-normals-array", "count");
            if (sData.length() > 0)
            {
                _dae->mesh[m].numNormal = stoi(sData);
                _dae->mesh[m].normal = new glm::vec3[_dae->mesh[m].numNormal];

                // Parse normals data
                std::string   normalsFloatArray = daeFile.getString(meshID + "-normals-array" + '"' + " count=" + '"' + std::to_string(_dae->mesh[m].numNormal * 3) + '"');
                normalsFloatArray += " ";
                std::uint32_t normalsFloatArrayLength = normalsFloatArray.length();
                std::uint32_t sCount = 0;
                std::uint32_t iCount = 0;
                std::string   tData  = {};

                for (std::uint64_t i = 0; i < normalsFloatArrayLength; ++i)
                {
                    if (normalsFloatArray[i] == ' ')
                    {
                      // add data to array
                        if (sCount % 3 == 0)
                        {
                            _dae->mesh[m].normal[iCount].x = stof(tData);
                        }
                        if (sCount % 3 == 1)
                        {
                            _dae->mesh[m].normal[iCount].y = stof(tData);
                        }
                        if (sCount % 3 == 2)
                        {
                            _dae->mesh[m].normal[iCount].z = stof(tData);
                            iCount++;
                        }
                        sCount++;
                        tData = "";
                    }
                    else
                    {
                        tData += normalsFloatArray[i];
                    }
                }
            }
            //std::cout << "Number normals: " << _dae->mesh[m].numNormal << std::endl;

            // vertex texcoords data
            sData = daeFile.getStringKeyValue("#" + meshID + "-map-0-array", "count");
            if (sData.length() > 0)
            {
                _dae->mesh[m].numTexCoord = stoi(sData);
                _dae->mesh[m].texCoord = new glm::vec2[_dae->mesh[m].numTexCoord];

                // Parse texcoords data
                std::string   texcoordsFloatArray = daeFile.getString(meshID + "-map-0-array" + '"' + " count=" + '"' + std::to_string(_dae->mesh[m].numTexCoord * 2) + '"');
                texcoordsFloatArray += " ";
                std::uint32_t texcoordsFloatArrayLength = texcoordsFloatArray.length();
                std::uint32_t sCount = 0;
                std::uint32_t iCount = 0;
                std::string   tData  = {};

                for (std::uint64_t i = 0; i < texcoordsFloatArrayLength; ++i)
                {
                    if (texcoordsFloatArray[i] == ' ')
                    {
                      // add data to array
                        if (sCount % 2 == 0)
                        {
                            _dae->mesh[m].texCoord[iCount].x = stof(tData);
                        }
                        if (sCount % 2 == 1)
                        {
                            _dae->mesh[m].texCoord[iCount].y = stof(tData);
                            iCount++;
                        }
                        sCount++;
                        tData = "";
                    }
                    else
                    {
                        tData += texcoordsFloatArray[i];
                    }
                }
            }
            //std::cout << "Number texcoords: " << _dae->mesh[m].numTexCoord << std::endl;

            // vertex color data
            sData = daeFile.getStringKeyValue("#" + meshID + "-colors-Col-array", "count");
            if (sData.length() > 0)
            {
                // setup the array
                _dae->mesh[m].numColor = stoi(sData);
                _dae->mesh[m].color = new glm::ivec4[_dae->mesh[m].numColor];

                // get the data stride
                std::uint32_t dStride = stoi(daeFile.getStringKeyValue("#" + meshID + "-colors-Col-array", "stride"));

                // Parse colors data
                std::string   colorsFloatArray = daeFile.getString(meshID + "-colors-Col-array" + '"' + " count=" + '"' + std::to_string(_dae->mesh[m].numColor * dStride) + '"');
                colorsFloatArray += " ";
                std::uint32_t colorsFloatArrayLength = colorsFloatArray.length();
                std::uint32_t sCount = 0;
                std::uint32_t iCount = 0;
                std::string   tData  = {};

                // Stride of of 4-> RGBA
                if (dStride == 4)
                {
                    for (std::uint64_t i = 0; i < colorsFloatArrayLength; ++i)
                    {
                        if (colorsFloatArray[i] == ' ')
                        {
                          // add data to array
                            if (sCount % dStride == 0)
                            {
                                _dae->mesh[m].color[iCount].x = stoi(tData);
                            }
                            if (sCount % dStride == 1)
                            {
                                _dae->mesh[m].color[iCount].y = stoi(tData);
                            }
                            if (sCount % dStride == 2)
                            {
                                _dae->mesh[m].color[iCount].z = stoi(tData);
                            }
                            if (sCount % dStride == 3)
                            {
                                _dae->mesh[m].color[iCount].w = stoi(tData);
                                iCount++;
                            }
                            sCount++;
                            tData = "";
                        }
                        else
                        {
                            tData += colorsFloatArray[i];
                        }
                    }
                }
                // Stride of of 3-> RGB
                else
                {
                    for (std::uint64_t i = 0; i < colorsFloatArrayLength; ++i)
                    {
                        if (colorsFloatArray[i] == ' ')
                        {
                          // add data to array
                            if (sCount % dStride == 0)
                            {
                                _dae->mesh[m].color[iCount].x = stoi(tData);
                            }
                            if (sCount % dStride == 1)
                            {
                                _dae->mesh[m].color[iCount].y = stoi(tData);
                            }
                            if (sCount % dStride == 2)
                            {
                                _dae->mesh[m].color[iCount].z = stoi(tData);
                                iCount++;
                            }
                            sCount++;
                            tData = "";
                        }
                        else
                        {
                            tData += colorsFloatArray[i];
                        }
                    }
                }
            }
            //std::cout << "Number colors: " << _dae->mesh[m].numColor << std::endl;

            // Parse index data
            std::string indexArray = daeFile.getString("<p>", m + 1);
            if (indexArray.length() > 0)
            {
                indexArray += " ";
                std::uint32_t indexArrayLength = indexArray.length();

                // get data count
                std::uint32_t sCount = 0;
                std::string   tData  = {};

                for (std::uint64_t i = 0; i < indexArrayLength; ++i)
                {
                    if (indexArray[i] == ' ')
                    {
                        sCount++;
                    }
                }

                // Number of Data
                std::uint32_t numData = 0;
                if (_dae->mesh[m].numPosition > 0)
                    numData++;
                if (_dae->mesh[m].numNormal > 0)
                    numData++;
                if (_dae->mesh[m].numTexCoord > 0)
                    numData++;
                if (_dae->mesh[m].numColor > 0)
                    numData++;

                // Index data
                _dae->mesh[m].numIndex = sCount / numData;

                std::cout << "sCount: " << sCount << std::endl;
                std::cout << "numData: " << numData << std::endl;
                std::cout << "_dae->mesh[m].numIndex: " << _dae->mesh[m].numIndex << std::endl;

                if (_dae->mesh[m].numIndex > 0)
                {
                    _dae->mesh[m].index = new glm::ivec4[_dae->mesh[m].numIndex];

                    // parse the data into the index array
                    sCount = 0;
                    tData  = {};

                    for (std::uint64_t i = 0; i < indexArrayLength; ++i)
                    {
                        if (indexArray[i] == ' ')
                        {
                            // position
                            if ((sCount % numData) == 0)
                                _dae->mesh[m].index[sCount / numData].x = stoi(tData);
                            // normal
                            else if ((numData > 1) && ((sCount % numData) == 1))
                                _dae->mesh[m].index[sCount / numData].y = stoi(tData);
                            // texcoord
                            else if ((numData > 2) && ((sCount % numData) == 2))
                                _dae->mesh[m].index[sCount / numData].z = stoi(tData);
                            // color
                            else if ((numData > 3) && ((sCount % numData) == 3))
                                _dae->mesh[m].index[sCount / numData].w = stoi(tData);
                            sCount++;
                            tData = "";
                        }
                        else
                        {
                            tData += indexArray[i];
                        }
                    }
                    //std::cout << "Number index: " << _dae->mesh[m].numIndex << std::endl;
                }
            }

            // Node transform
            std::uint32_t lineNum = daeFile.getLine("<node id=\"" + meshID + "\" name=\"" + meshID + "\" type=\"NODE\">");
            std::uint32_t instanceNum = daeFile.getInstanceAfterLine("<matrix sid=\"transform\">", lineNum);
            if (instanceNum > 0)
            {
                _dae->mesh[m].transform = daeFile.getMat4("<matrix sid=\"transform\">", instanceNum);
            }
        }

        // Parse <library_controllers>
        std::uint32_t controllerCount = daeFile.getInstanceCount("<controller id=");
        if (controllerCount > 0)
        {
            for(std::uint32_t m = 0; m < _dae->numMesh; ++m)
            {
                // get the controler ID for this mesh
                std::string controlerID = "";
                for(std::uint32_t c = 0; c < controllerCount; ++c)
                {
                    std::string tData = daeFile.getString("<controller id=", c + 1);
                    if (tData.find(_dae->mesh[m].name))
                        controlerID = daeFile.getStringKeyValue("<controller id=", "id");
                }

                if (_dae->numBone == 0)
                {
                    // Controller bone names
                    std::uint32_t boneCount = std::stoi(daeFile.getStringKeyValue("<Name_array id=\"" + controlerID + "-joints-array\" count=", "count"));
                    std::string boneNamesArray = daeFile.getString("<Name_array id=\"" + controlerID + "-joints-array\" count=\"" + std::to_string(boneCount) + "\">");

                    // max bone check
                    if (boneCount > MAX_BONES)
                    {
                        gLogWrite(LOG_WARNING, "3D model: " + _fileName + ", has too many bones: " + std::to_string(boneCount), __FILE__, __LINE__, __FUNCTION__);
                    }

                    // allocate memory
                    _dae->numBone = boneCount;
                    _dae->bone = new sDAEBone[_dae->numBone];

                    // Parse the bone names array into the bone struct
                    boneNamesArray += " ";
                    std::uint64_t boneNamesArrayLength = boneNamesArray.length();
                    if (boneNamesArrayLength > 1)
                    {
                        std::uint32_t sCount = 0;
                        std::string   tData  = {};
                        for (std::uint64_t i = 0; i < boneNamesArrayLength; ++i)
                        {
                            if (boneNamesArray[i] == ' ')
                            {
                                // add data to array
                                _dae->bone[sCount].ID = sCount;
                                _dae->bone[sCount].name = tData;
                                sCount++;
                                tData = "";
                            }
                            else
                            {
                                tData += boneNamesArray[i];
                            }
                        }
                    }

                    // Get the scene id
                    std::string sceneID = daeFile.getStringKeyValue("visual_scene id", "id");

                    // Get the bone transforms
                    for (std::uint32_t i = 0; i < _dae->numBone; ++i)
                    {
                        // bone id
                        std::string baneID = _dae->bone[i].name;
                        std::string boneSceneID = sceneID + "_" + baneID;

                        // Node transform
                        std::uint32_t lineNum = daeFile.getLine("<node id=\"" + boneSceneID + "\" name=\"" + baneID + "\" sid=\"" + baneID + "\" type=\"JOINT\">");
                        std::uint32_t instanceNum = daeFile.getInstanceAfterLine("<matrix sid=\"transform\">", lineNum);
                        if (instanceNum > 0)
                        {
                            _dae->bone[i].transformNode = daeFile.getMat4("<matrix sid=\"transform\">", instanceNum);
                        }
                    }

                    // Get the bone hierarchical order of parent nodes
                    std::int32_t  boneList[_dae->numBone];
                    std::uint32_t boneListPos = 0;
                    std::uint32_t nodeDepth = -1;
                    std::uint32_t visualSceneslineNum = daeFile.getLine("<library_visual_scenes>");
                    for (std::uint32_t i = visualSceneslineNum; i < daeFile.lineCount(); ++i)
                    {
                        std::string tString = daeFile.line(i);
                        if ((tString.find("<node id=") != std::string::npos) && (tString.find("type=\"JOINT\">") != std::string::npos))
                        {
                            // Node depth
                            nodeDepth++;

                            // bone name
                            std::string boneName = daeFile.getValueFromString(tString, "sid");

                            // bone ID
                            std::int32_t boneID = -1;
                            for (std::uint32_t b = 0; b < _dae->numBone; ++b)
                            {
                                if (boneName.find(_dae->bone[b].name) != std::string::npos)
                                {
                                    boneID = b;
                                }
                            }

                            // add to bone list
                            boneList[boneListPos] = boneID;
                            boneListPos++;

                            // if not root bone, add parent
                            if (boneID > 0)
                            {
                                _dae->bone[boneID].parentID = boneList[nodeDepth];
                            }

                        }
                        if (tString.find("</node>") != std::string::npos)
                        {
                            // Node depth
                            nodeDepth--;
                        }
                    }

                    // Joint bind pose arrays
                    std::string bindPosessArray = daeFile.getString("<float_array id=\"" + controlerID + "-bind_poses-array\" count=\"" + std::to_string(boneCount * 16) + "\"");

                    // Parse the bind poses array into the bone struct
                    bindPosessArray += " ";
                    std::uint64_t bindPosessArrayLength = bindPosessArray.length();
                    if (bindPosessArrayLength > 1)
                    {
                        std::uint32_t sCount = 0;
                        std::string   tData  = {};
                        for (std::uint64_t i = 0; i < bindPosessArrayLength; ++i)
                        {
                            if (bindPosessArray[i] == ' ')
                            {
                                // add data to array
                                std::uint32_t matNum = sCount / 16;
                                std::uint32_t matPos = sCount % 16;
                                _dae->bone[matNum].transformPose[matPos / 4][matPos % 4] = std::stof(tData);
                                sCount++;
                                tData = "";
                            }
                            else
                            {
                                tData += bindPosessArray[i];
                            }
                        }
                    }
                }

                // Skinning data weights
                std::uint32_t skinWeightsArrayCount = std::stoi(daeFile.getStringKeyValue("<float_array id=\"" + controlerID + "-weights-array\" count=", "count"));
                std::uint32_t dataLineStart = daeFile.getLine("<float_array id=\"" + controlerID + "-weights-array\" count=\"" + std::to_string(skinWeightsArrayCount) + "\">");
                std::string floatData = daeFile.getString("<float_array id=\"" + controlerID + "-weights-array\" count=\"" + std::to_string(skinWeightsArrayCount) + "\">");
                if (floatData[floatData.length() - 1] != ' ')
                    floatData = floatData + ' ';
                float *skinWeightsArray = new float[skinWeightsArrayCount];
                gStringToFloatArray(floatData, skinWeightsArrayCount, skinWeightsArray);

                // weights per vertex
                std::uint32_t instanceNum = daeFile.getInstanceAfterLine("<vcount>", dataLineStart);
                std::string integerData = daeFile.getString("<vcount>", instanceNum);
                if (integerData[integerData.length() - 1] != ' ')
                    integerData = integerData + ' ';
                std::uint32_t skinJointsCount = _stringSpaceCount(integerData);
                std::uint32_t *skinJointsArray = new std::uint32_t[skinJointsCount];
                gStringToInt32Array(integerData, skinJointsCount, skinJointsArray);

                // vertex joint weight pairs
                floatData = daeFile.getString("<v>", m + 1);
                if (floatData[floatData.length() - 1] != ' ')
                    floatData = floatData + ' ';
                std::uint32_t skinWeightJointCount = _stringSpaceCount(floatData);
                float *skinWeightJointArray = new float[skinWeightJointCount];
                gStringToFloatArray(floatData, skinWeightJointCount, skinWeightJointArray);

                // Allocate memory
                _dae->mesh[m].boneWeight = new glm::vec4[_dae->mesh[m].numPosition];
                _dae->mesh[m].boneID     = new glm::ivec4[_dae->mesh[m].numPosition];

                // set zero data
                for(std::uint32_t p = 0; p < _dae->mesh[m].numPosition; ++p)
                {
                    _dae->mesh[m].boneWeight[p] = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
                    _dae->mesh[m].boneID[p]     = glm::ivec4(0, 0, 0, 0);
                }

                // parse the skinning data for each vertex
                std::uint32_t skinWeightJointPosition = 0;
                for (std::uint32_t i = 0; i < skinJointsCount; ++i)
                {
                    for (std::uint32_t j = 0; j < skinJointsArray[i]; ++j)
                    {
                        if (skinWeightJointArray[skinWeightJointPosition + 1] > _dae->mesh[m].boneWeight[i].x)
                        {
                            // weight
                            _dae->mesh[m].boneWeight[i].w = _dae->mesh[m].boneWeight[i].z;
                            _dae->mesh[m].boneWeight[i].z = _dae->mesh[m].boneWeight[i].y;
                            _dae->mesh[m].boneWeight[i].y = _dae->mesh[m].boneWeight[i].x;
                            _dae->mesh[m].boneWeight[i].x = skinWeightJointArray[skinWeightJointPosition + 1];

                            //boneID
                            _dae->mesh[m].boneID[i].w = _dae->mesh[m].boneID[i].z;
                            _dae->mesh[m].boneID[i].z = _dae->mesh[m].boneID[i].y;
                            _dae->mesh[m].boneID[i].y = _dae->mesh[m].boneID[i].x;
                            _dae->mesh[m].boneID[i].x = skinWeightJointArray[skinWeightJointPosition];
                        }
                        else if (skinWeightJointArray[skinWeightJointPosition + 1] > _dae->mesh[m].boneWeight[i].y)
                        {
                            // weight
                            _dae->mesh[m].boneWeight[i].w = _dae->mesh[m].boneWeight[i].z;
                            _dae->mesh[m].boneWeight[i].z = _dae->mesh[m].boneWeight[i].y;
                            _dae->mesh[m].boneWeight[i].y = skinWeightJointArray[skinWeightJointPosition + 1];

                            //boneID
                            _dae->mesh[m].boneID[i].w = _dae->mesh[m].boneID[i].z;
                            _dae->mesh[m].boneID[i].z = _dae->mesh[m].boneID[i].y;
                            _dae->mesh[m].boneID[i].y = skinWeightJointArray[skinWeightJointPosition];
                        }
                        else if (skinWeightJointArray[skinWeightJointPosition + 1] > _dae->mesh[m].boneWeight[i].z)
                        {
                            // weight
                            _dae->mesh[m].boneWeight[i].w = _dae->mesh[m].boneWeight[i].z;
                            _dae->mesh[m].boneWeight[i].z = skinWeightJointArray[skinWeightJointPosition + 1];

                            //boneID
                            _dae->mesh[m].boneID[i].w = _dae->mesh[m].boneID[i].z;
                            _dae->mesh[m].boneID[i].z = skinWeightJointArray[skinWeightJointPosition];
                        }
                        else if (skinWeightJointArray[skinWeightJointPosition + 1] > _dae->mesh[m].boneWeight[i].w)
                        {
                            // weight
                            _dae->mesh[m].boneWeight[i].w = skinWeightJointArray[skinWeightJointPosition + 1];

                            //boneID
                            _dae->mesh[m].boneID[i].w = skinWeightJointArray[skinWeightJointPosition];
                        }
                        skinWeightJointPosition += 2;
                    }
                    _dae->mesh[m].boneWeight[i] = glm::normalize(_dae->mesh[m].boneWeight[i]);
                }

                // cleanup
                delete[] skinWeightsArray;
                delete[] skinJointsArray;
                delete[] skinWeightJointArray;
            }
        }

        // Parse <library_animations>
        std::uint32_t animationCount = daeFile.getInstanceCount("<animation id=");
        if (animationCount > 0)
        {
            // Load animations
            if (_dae->numBone > 0)
            {
                // get animation ID count
                std::uint32_t animationIDCount = daeFile.getInstanceCount("<animation id=\"");

                // get animated bone count
                std::uint32_t animatedBoneCount = 0;
                for (std::uint32_t i = 0; i < animationIDCount - 1; ++i)
                {
                    std::string tAString = daeFile.line(daeFile.getLine("<animation id=\"", i + 1));
                    if (tAString.find("/>") == std::string::npos)
                    {
                        std::string animationIDName = daeFile.getValueFromString(tAString, "id");
                        for (std::uint32_t b = 0; b < _dae->numBone; ++b)
                        {
                            if (tAString.find(_dae->bone[b].name) != std::string::npos)
                            {
                                animatedBoneCount++;
                            }
                        }
                    }
                }

                // parse animation data if available
                if (animatedBoneCount > 0)
                {
                    // allocate memory
                    _dae->numAnimations = 1;
                    _dae->animation = new sDAEAnimation;
                    _dae->animation->numNodes = _dae->numBone;
                    _dae->animation->node = new sDAEAnimationNode[_dae->animation->numNodes];

                    //find and parse the animation data
                    for (std::uint32_t i = 0; i < animationIDCount - 1; ++i)
                    {
                        std::string tAString = daeFile.line(daeFile.getLine("<animation id=\"", i + 1));
                        if (tAString.find("/>") == std::string::npos)
                        {
                            std::string animationIDName = daeFile.getValueFromString(tAString, "id");
                            for (std::uint32_t b = 0; b < _dae->numBone; ++b)
                            {
                                if (animationIDName.find(_dae->bone[b].name) != std::string::npos)
                                {
                                    // Get animation data
                                    std::string   tIString   = daeFile.line(daeFile.getLine("<float_array id=\"" + animationIDName + "-input-array\" count=\""));
                                    std::uint32_t floatCount = std::stoi(daeFile.getValueFromString(tIString, "count"));
                                    std::string   floatData  = daeFile.getString("<float_array id=\"" + animationIDName + "-input-array\" count=\"" + std::to_string(floatCount) + "\">");
                                    if (floatData[floatData.length() - 1] != ' ')
                                        floatData = floatData + ' ';

                                    std::string   tOString  = daeFile.line(daeFile.getLine("<float_array id=\"" + animationIDName + "-output-array\" count=\""));
                                    std::uint32_t mat4Count = std::stoi(daeFile.getValueFromString(tOString, "count")) / 16; // 4 x 4 matrix
                                    std::string   mat4Data  = daeFile.getString("<float_array id=\"" + animationIDName + "-output-array\" count=\"" + std::to_string(mat4Count * 16) + "\">");
                                    if (mat4Data[mat4Data.length() - 1] != ' ')
                                        mat4Data = mat4Data + ' ';

                                    // Allocate memory
                                    if ((_dae->animation->node->keyFrame == nullptr) && (_dae->animation->node->transform == nullptr))
                                    {
                                        _dae->animation->node->keyFrame  = new float[floatCount];
                                        _dae->animation->node->transform = new glm::mat4[mat4Count];
                                    }

                                    // Parse the keyframe float data
                                    gStringToFloatArray(floatData, floatCount, _dae->animation->node->keyFrame);

                                    // Parse the transform mat4 data
                                    gStringToMat4Array(mat4Data, mat4Count, _dae->animation->node->transform);
                                }
                            }
                        }
                    }
                }
            }
        }

        // Free dae file from memory
        daeFile.free();
    }
    else
    {
        std::cout << "Failed to open file: " << _fileName << std::endl;
    }
}

void gSaveDAE(sDAEModel *&_dae, const std::string &_fileName)
{
}
