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

#include "model_loader_obj.hpp"

sEntityModel* loadModelOBJ(const std::string &_fileName)
{
    // Check if the file exists
    if (fileExists(FILE_PATH_MODEL+_fileName))
    {
        // Open file
        std::ifstream objFile (FILE_PATH_MODEL+_fileName, std::ios::binary);
        if(objFile.is_open())
        {
            // Hold a line of data read from the file
            std::string   lineData       = "";
            std::uint32_t lineDataLength = 0;

            // Get an object count from the file
            std::uint32_t objectCount = 0;
            while (getline (objFile, lineData))
            {
                lineDataLength = lineData.length();
                if (lineDataLength > 4)
                {
                    if ((lineData[0] == 'o') && (lineData[1] == ' '))
                    {
                        objectCount++;
                    }
                }
            }

            // Reset the obj file
            objFile.clear();
            objFile.seekg(std::ios::beg);

            // Create temporary data storage
            struct sObject
            {
                std::string   name        = {};
                float*        vertex      = nullptr;
                std::uint32_t numVertex   = 0;
                float*        normal      = nullptr;
                std::uint32_t numNormal   = 0;
                float*        texcrd      = nullptr;
                std::uint32_t numTexcrd   = 0;
                std::uint32_t numFaceVert = 0;
            };
            sObject object[objectCount];

            // Temporary data indices
            bool          objectFirst = true;
            std::uint32_t objectIndex = 0;

            // Get vertex, normal and texture coord counts for each object
            while (getline (objFile, lineData))
            {
                lineData += " ";
                lineDataLength = lineData.length();
                if (lineDataLength > 4)
                {
                    if ((lineData[0] == 'o') && (lineData[1] == ' '))
                    {
                        // Insure objectIndex is only incremented after the first object
                        if (objectFirst == true)
                        {
                            objectFirst = false;
                        }
                        else
                        {
                            objectIndex++;
                        }
                        // Save object name
                        std::uint32_t spaceCount = 0;
                        std::string tempData = "";
                        for(std::uint32_t i = 0; i < lineDataLength; ++i)
                        {
                            if (lineData[i] == ' ')
                            {
                                spaceCount++;
                                if (spaceCount == 2)
                                {
                                    object[objectIndex].name = tempData;
                                }
                                tempData = "";
                            }
                            else
                            {
                                tempData += lineData[i];
                            }
                        }

                    }
                    else if ((lineData[0] == 'v') && (lineData[1] == ' '))
                    {
                        object[objectIndex].numVertex++;
                    }
                    else if ((lineData[0] == 'v') && (lineData[1] == 'n') && (lineData[2] == ' '))
                    {
                        object[objectIndex].numNormal++;
                    }
                    else if ((lineData[0] == 'v') && (lineData[1] == 't') && (lineData[2] == ' '))
                    {
                        object[objectIndex].numTexcrd++;
                    }
                    else if ((lineData[0] == 'f') && (lineData[1] == ' '))
                    {
                        std::uint32_t spaceCount = 0;
                        for(std::uint32_t i = 0; i < lineDataLength; ++i)
                        {
                            if (lineData[i] == ' ')
                            {
                                spaceCount++;
                            }
                        }
                        // We are assuming the data is formatted correctly...
                        object[objectIndex].numFaceVert += (((spaceCount - 1) - 3) * 3) + 3;
                    }
                }
            }

            // Reset the obj file
            objFile.clear();
            objFile.seekg(std::ios::beg);

            // Allocate memory for the temporary data
            for (std::uint32_t i = 0; i < objectCount; ++i)
            {
                object[i].vertex = new float[object[i].numVertex * 3];
                object[i].normal = new float[object[i].numNormal * 3];
                object[i].texcrd = new float[object[i].numTexcrd * 2];
            }

            // Temporary data indices
            std::uint32_t vertexIndex = 0;
            std::uint32_t normalIndex = 0;
            std::uint32_t texcrdIndex = 0;

            // Reset temporary data indices
            objectFirst = true;
            objectIndex = 0;

            // Get vertex, normal and texture coord data for each object
            while (getline (objFile, lineData))
            {
                lineData += " ";
                lineDataLength = lineData.length();
                if (lineDataLength > 4)
                {
                    if ((lineData[0] == 'o') && (lineData[1] == ' '))
                    {
                        // Insure objectIndex is only incremented after the first object
                        if (objectFirst == true)
                        {
                            objectFirst = false;
                        }
                        else
                        {
                            objectIndex++;
                        }

                        // Reset temporary data indices
                        vertexIndex = 0;
                        normalIndex = 0;
                        texcrdIndex = 0;
                    }
                    else if ((lineData[0] == 'v') && (lineData[1] == ' '))
                    {
                        std::string   tempData = "";
                        std::uint32_t spaceCount = 0;
                        for(std::uint32_t i = 0; i < lineDataLength; ++i)
                        {
                            if (lineData[i] == ' ')
                            {
                                spaceCount++;
                                if ((spaceCount > 1) && (spaceCount < 5))
                                {
                                    object[objectIndex].vertex[vertexIndex] = std::stof(tempData);
                                    vertexIndex++;
                                }
                                tempData = "";
                            }
                            else
                            {
                                tempData += lineData[i];
                            }
                        }
                    }
                    else if ((lineData[0] == 'v') && (lineData[1] == 'n') && (lineData[2] == ' '))
                    {
                        std::string   tempData = "";
                        std::uint32_t spaceCount = 0;
                        for(std::uint32_t i = 0; i < lineDataLength; ++i)
                        {
                            if (lineData[i] == ' ')
                            {
                                spaceCount++;
                                if ((spaceCount > 1) && (spaceCount < 5))
                                {
                                    object[objectIndex].normal[normalIndex] = std::stof(tempData);
                                    normalIndex++;
                                }
                                tempData = "";
                            }
                            else
                            {
                                tempData += lineData[i];
                            }
                        }
                    }
                    else if ((lineData[0] == 'v') && (lineData[1] == 't') && (lineData[2] == ' '))
                    {
                        std::string   tempData = "";
                        std::uint32_t spaceCount = 0;
                        for(std::uint32_t i = 0; i < lineDataLength; ++i)
                        {
                            if (lineData[i] == ' ')
                            {
                                spaceCount++;
                                if ((spaceCount > 1) && (spaceCount < 4))
                                {
                                    object[objectIndex].texcrd[texcrdIndex] = std::stof(tempData);
                                    texcrdIndex++;
                                }
                                tempData = "";
                            }
                            else
                            {
                                tempData += lineData[i];
                            }
                        }
                    }
                }
            }

            // Reset the obj file
            objFile.clear();
            objFile.seekg(std::ios::beg);

            // Allocate memory for model
            sEntityModel* tModel = new sEntityModel;
            tModel->fileName = _fileName;

            tModel->numMesh = objectCount;
            tModel->mesh = new sEntityMesh[tModel->numMesh];
            for (std::uint32_t i = 0; i < tModel->numMesh; ++i)
            {
                tModel->mesh[i].name      = object[i].name;
                tModel->mesh[i].numVertex = object[i].numFaceVert;
                tModel->mesh[i].vertex    = new sEntityVertex[tModel->mesh[i].numVertex];
                tModel->mesh[i].numIndex  = object[i].numFaceVert;
                tModel->mesh[i].index     = new std::uint32_t[tModel->mesh[i].numIndex];
                for (std::uint32_t j = 0; j < tModel->mesh[i].numIndex; ++j)
                {
                    tModel->mesh[i].index[j] = j;
                }
            }

            // Reset temporary data indices
            vertexIndex = 0;
            objectFirst = true;
            objectIndex = 0;

            // Because the obj standard is stupid...
            // Vertex, normal and texture coord data are specified separately per object,
            // however face indices can reference any objects data??
            std::uint32_t vertexOffset = 0;
            std::uint32_t normalOffset = 0;
            std::uint32_t texcrdOffset = 0;

            // Get vertex, normal and texture coord data for each object
            while (getline (objFile, lineData))
            {
                lineData += " ";
                lineDataLength = lineData.length();
                if (lineDataLength > 4)
                {
                    if ((lineData[0] == 'o') && (lineData[1] == ' '))
                    {
                        // Insure objectIndex is only incremented after the first object
                        if (objectFirst == true)
                        {
                            objectFirst = false;
                        }
                        else
                        {
                            vertexOffset += object[objectIndex].numVertex;
                            normalOffset += object[objectIndex].numNormal;
                            texcrdOffset += object[objectIndex].numTexcrd;

                            objectIndex++;
                            vertexIndex = 0;
                        }
                    }
                    else if ((lineData[0] == 'f') && (lineData[1] == ' '))
                    {
                        std::string   tempData = "";
                        std::uint32_t faceVertCount = 0;
                        for(std::uint32_t i = 0; i < lineDataLength; ++i)
                        {
                            if (lineData[i] == ' ')
                            {
                                faceVertCount++;
                            }
                        }
                        faceVertCount--;

                        // Triangles :)
                        // f v/t/n v/t/n v/t/n
                        if (faceVertCount == 3)
                        {
                            tempData   = "";
                            std::uint32_t spaceCount = 0;
                            std::uint32_t slashCount = 0;
                            for(std::uint32_t i = 0; i < lineDataLength; ++i)
                            {
                                if (lineData[i] == ' ')
                                {
                                    spaceCount++;
                                    if (spaceCount > 1)
                                    {
                                        tModel->mesh[objectIndex].vertex[vertexIndex].normal[0] = object[objectIndex].normal[((std::stoi(tempData) - 1 - normalOffset) * 3) + 0];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].normal[1] = object[objectIndex].normal[((std::stoi(tempData) - 1 - normalOffset) * 3) + 1];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].normal[2] = object[objectIndex].normal[((std::stoi(tempData) - 1 - normalOffset) * 3) + 2];
                                        vertexIndex++;
                                    }
                                    tempData   = "";
                                }
                                else if (lineData[i] == '/')
                                {
                                    if (slashCount == 0)
                                    {
                                        tModel->mesh[objectIndex].vertex[vertexIndex].position[0] = object[objectIndex].vertex[((std::stoi(tempData) - 1 - vertexOffset) * 3) + 0];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].position[1] = object[objectIndex].vertex[((std::stoi(tempData) - 1 - vertexOffset) * 3) + 1];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].position[2] = object[objectIndex].vertex[((std::stoi(tempData) - 1 - vertexOffset) * 3) + 2];
                                        slashCount++;
                                    }
                                    else
                                    {
                                        tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[0] = object[objectIndex].texcrd[((std::stoi(tempData) - 1 - texcrdOffset) * 2) + 0];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[1] = object[objectIndex].texcrd[((std::stoi(tempData) - 1 - texcrdOffset) * 2) + 1];
                                        slashCount = 0;
                                    }
                                    tempData   = "";
                                }
                                else
                                {
                                    tempData += lineData[i];
                                }
                            }
                        }

                        // Triangulate
                        // f v/t/n v/t/n v/t/n v/t/n
                        else if (faceVertCount == 4)
                        {
                            tempData   = "";
                            std::uint32_t spaceCount = 0;
                            std::uint32_t slashCount = 0;
                            for(std::uint32_t i = 0; i < lineDataLength; ++i)
                            {
                                if (lineData[i] == ' ')
                                {
                                    if (spaceCount > 0)
                                    {
                                        tModel->mesh[objectIndex].vertex[vertexIndex].normal[0] = object[objectIndex].normal[((std::stoi(tempData) - 1 - normalOffset) * 3) + 0];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].normal[1] = object[objectIndex].normal[((std::stoi(tempData) - 1 - normalOffset) * 3) + 1];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].normal[2] = object[objectIndex].normal[((std::stoi(tempData) - 1 - normalOffset) * 3) + 2];
                                        vertexIndex++;

                                        if (spaceCount == 3)
                                        {
                                            // First triangle
                                            tModel->mesh[objectIndex].vertex[vertexIndex].position[0] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].position[0];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].position[1] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].position[1];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].position[2] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].position[2];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].normal[0] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].normal[0];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].normal[1] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].normal[1];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].normal[2] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].normal[2];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[0] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].texcoord[0];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[1] = tModel->mesh[objectIndex].vertex[vertexIndex - 3].texcoord[1];
                                            vertexIndex++;

                                            // Second triangle
                                            tModel->mesh[objectIndex].vertex[vertexIndex].position[0] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].position[0];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].position[1] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].position[1];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].position[2] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].position[2];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].normal[0] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].normal[0];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].normal[1] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].normal[1];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].normal[2] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].normal[2];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[0] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].texcoord[0];
                                            tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[1] = tModel->mesh[objectIndex].vertex[vertexIndex - 2].texcoord[1];
                                            vertexIndex++;
                                        }

                                    }
                                    spaceCount++;
                                    tempData   = "";
                                }
                                else if (lineData[i] == '/')
                                {
                                    if (slashCount == 0)
                                    {
                                        tModel->mesh[objectIndex].vertex[vertexIndex].position[0] = object[objectIndex].vertex[((std::stoi(tempData) - 1 - vertexOffset) * 3) + 0];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].position[1] = object[objectIndex].vertex[((std::stoi(tempData) - 1 - vertexOffset) * 3) + 1];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].position[2] = object[objectIndex].vertex[((std::stoi(tempData) - 1 - vertexOffset) * 3) + 2];
                                        slashCount++;
                                    }
                                    else
                                    {
                                        tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[0] = object[objectIndex].texcrd[((std::stoi(tempData) - 1 - texcrdOffset) * 2) + 0];
                                        tModel->mesh[objectIndex].vertex[vertexIndex].texcoord[1] = object[objectIndex].texcrd[((std::stoi(tempData) - 1 - texcrdOffset) * 2) + 1];
                                        slashCount = 0;
                                    }
                                    tempData   = "";
                                }
                                else
                                {
                                    tempData += lineData[i];
                                }
                            }
                        }
                        else
                        {
                            gLogWrite(LOG_ERROR, "Mesh has a surface with more than 4 vertices: " + std::string(FILE_PATH_MODEL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
                        }
                    }
                }
            }

            //Clean up
            for (std::uint32_t i = 0; i < objectCount; ++i)
            {
                if (object[i].vertex != nullptr)
                {
                    delete[] object[i].vertex;
                    object[i].vertex = nullptr;
                }
                if (object[i].normal != nullptr)
                {
                    delete[] object[i].normal;
                    object[i].normal = nullptr;
                }
                if (object[i].texcrd != nullptr)
                {
                    delete[] object[i].texcrd;
                    object[i].texcrd = nullptr;
                }
            }

            // Close the file
            objFile.close();
        }
        else
        {
            gLogWrite(LOG_ERROR, "Failed to open file: " + std::string(FILE_PATH_MODEL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        }
        // return data
        
    }
    else
    {
        // File not found
        gLogWrite(LOG_ERROR, "Failed to locate file: " + std::string(FILE_PATH_MODEL) + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return nullptr;
    }
    return nullptr;
}


