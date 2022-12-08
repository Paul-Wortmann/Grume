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

#include "obj_loader.hpp"

void gFreeOBJ(sOBJ *&_obj)
{
    // OBJ
    if (_obj != nullptr)
    {
        // mesh
        if (_obj->mesh != nullptr)
        {
            // for each mesh
            for (std::uint32_t i = 0; i < _obj->numMesh; ++i)
            {
                // index
                if (_obj->mesh[i].index != nullptr)
                {
                    delete[] _obj->mesh[i].index;
                    _obj->mesh[i].index = nullptr;
                }

                // normal
                if (_obj->mesh[i].normal != nullptr)
                {
                    delete[] _obj->mesh[i].normal;
                    _obj->mesh[i].normal = nullptr;
                }

                // texCoord
                if (_obj->mesh[i].texCoord != nullptr)
                {
                    delete[] _obj->mesh[i].texCoord;
                    _obj->mesh[i].texCoord = nullptr;
                }

                // vertex
                if (_obj->mesh[i].vertex != nullptr)
                {
                    delete[] _obj->mesh[i].vertex;
                    _obj->mesh[i].vertex = nullptr;
                }
            }

            // free mesh memory
            delete[] _obj->mesh;
            _obj->mesh = nullptr;
        }

        // free _obj memory
        delete _obj;
        _obj = nullptr;
    }
}

// load obj data and automatically triangulate quad faces
void gLoadOBJ(sOBJ *&_obj, const std::string &_fileName)
{
    // index count lambda
    auto _getIndexCount = [](const std::string &_line)
    {
        std::uint32_t sCount = 0;
        std::uint32_t lLength = _line.length();

        for (std::uint32_t i = 0; i < lLength; ++i)
        {
            if (_line[i] == ' ')
                sCount++;
        }
        return sCount;
    };

    // get object name lambda
    auto _getObjectName = [](const std::string &_line)
    {
        std::string returnData;
        std::uint32_t lLength = _line.length();

        for (std::uint32_t i = 2; i < lLength; ++i)
        {
            returnData += _line[i];
        }
        return returnData;
    };

    // vec2 lambda
    auto _getVec2 = [](const std::string &_line)
    {
        vec2 returnData;
        std::uint32_t sCount = 0;
        std::string   tData  = {};
        std::uint32_t lLength = _line.length();

        for (std::uint32_t i = 0; i < lLength; ++i)
        {
            if (_line[i] == ' ')
            {
                if (sCount == 1)
                    returnData.x = std::stof(tData);

                sCount++;
                tData = "";
            }
            else
            {
                tData += _line[i];
            }
        }
        returnData.y = std::stof(tData);
        return returnData;
    };

    // vec3 lambda
    auto _getVec3 = [](const std::string &_line)
    {
        vec3 returnData;
        std::uint32_t sCount = 0;
        std::string   tData  = {};
        std::uint32_t lLength = _line.length();

        for (std::uint32_t i = 0; i < lLength; ++i)
        {
            if (_line[i] == ' ')
            {
                if (sCount == 1)
                    returnData.x = std::stof(tData);
                else if (sCount == 2)
                    returnData.y = std::stof(tData);

                sCount++;
                tData = "";
            }
            else
            {
                tData += _line[i];
            }
        }
        returnData.z = std::stof(tData);
        return returnData;
    };

    // getIndex lambda, return ivec3
    auto _getIndex = [](const std::string &_line, const std::uint32_t &_number)
    {
        ivec3 returnData;
        std::uint32_t sCount = 0;
        std::uint32_t dCount = 0;
        std::string   tData  = {};
        std::uint32_t lLength = _line.length();

        for (std::uint32_t i = 0; i < lLength; ++i)
        {
            if (_line[i] == ' ')
            {
                if (sCount == _number)
                    returnData.n = std::stoi(tData);
                sCount++;
                tData = "";
            }
            else if ((_line[i] == '/') && (sCount == _number))
            {
                if (dCount == 0)
                    returnData.v = std::stoi(tData);
                else if (dCount == 1)
                    returnData.t = std::stoi(tData);
                dCount++;
                tData = "";
            }
            else
            {
                tData += _line[i];
            }
        }
        return returnData;
    };

    // free object if necessary
    if (_obj != nullptr)
    {
        gFreeOBJ(_obj);
    }

    // open obj file
    std::ifstream objFile(_fileName);
    if (objFile.is_open())
    {
        // allocate memory for obj data
        _obj = new sOBJ;

        // Read the file line by line to determine mesh count
        std::string line;
        while (std::getline(objFile, line))
        {
            if ((line[0] == 'o') && (line[1] == ' '))
                _obj->numMesh++;
        }

        // allocate mesh memory
        _obj->mesh = new sOBJMesh[_obj->numMesh];

        // Reset obj file
        objFile.clear();                 // clear fail and eof bits
        objFile.seekg(0, std::ios::beg); // back to the start!

        // mesh counter
        std::uint32_t meshNum = 0;

        // Read the file line by line to determine data count for each mesh
        while (std::getline(objFile, line))
        {
            if ((line[0] == 'o') && (line[1] == ' '))
            {
                meshNum++;
            }
            else if ((line[0] == 'v') && (line[1] == ' '))
            {
                _obj->mesh[meshNum - 1].numVertex++;
            }
            else if ((line[0] == 'v') && (line[1] == 't') && (line[2] == ' '))
            {
                _obj->mesh[meshNum - 1].numTexCoord++;
            }
            else if ((line[0] == 'v') && (line[1] == 'n') && (line[2] == ' '))
            {
                _obj->mesh[meshNum - 1].numNormal++;
            }
            else if ((line[0] == 'f') && (line[1] == ' '))
            {
                std::uint32_t indexCount = _getIndexCount(line);
                if (indexCount == 3) // Triangle
                {
                    _obj->mesh[meshNum - 1].numIndex += 3;
                }
                else // n-gon
                {
                    _obj->mesh[meshNum - 1].numIndex += ((indexCount - 2) * 3);
                }
            }
        }

        // allocate memory
        for (std::uint32_t i = 0; i < _obj->numMesh; ++i)
        {
            _obj->mesh[i].vertex   = new  vec3[_obj->mesh[i].numVertex];
            _obj->mesh[i].normal   = new  vec3[_obj->mesh[i].numNormal];
            _obj->mesh[i].texCoord = new  vec2[_obj->mesh[i].numTexCoord];
            _obj->mesh[i].index    = new ivec3[_obj->mesh[i].numIndex];
        }

        // Reset obj file
        objFile.clear();                 // clear fail and eof bits
        objFile.seekg(0, std::ios::beg); // back to the start!

        // reset mesh counter
        meshNum = 0;

        // temporary counters
        std::uint32_t vertexNum   = 0;
        std::uint32_t normalNum   = 0;
        std::uint32_t texCoordNum = 0;
        std::uint32_t indexNum    = 0;

        // Read the file line by line and parse the data
        while (std::getline(objFile, line))
        {
            if ((line[0] == 'o') && (line[1] == ' '))
            {
                meshNum++;
                vertexNum   = 0;
                normalNum   = 0;
                texCoordNum = 0;
                indexNum    = 0;

                _obj->mesh[meshNum - 1].name = _getObjectName(line);
            }
            else if ((line[0] == 'v') && (line[1] == ' '))
            {
                // parse
                _obj->mesh[meshNum - 1].vertex[vertexNum] = _getVec3(line);

                //increment counter
                vertexNum++;
            }
            else if ((line[0] == 'v') && (line[1] == 't') && (line[2] == ' '))
            {
                // parse
                _obj->mesh[meshNum - 1].texCoord[texCoordNum] = _getVec2(line);

                //increment counter
                texCoordNum++;
            }
            else if ((line[0] == 'v') && (line[1] == 'n') && (line[2] == ' '))
            {
                // parse
                _obj->mesh[meshNum - 1].normal[normalNum] = _getVec3(line);

                //increment counter
                normalNum++;
            }
            else if ((line[0] == 'f') && (line[1] == ' '))
            {
                // parse
                std::uint32_t indexCount = _getIndexCount(line);
                if (indexCount == 3) // Triangle
                {
                    _obj->mesh[meshNum - 1].index[indexNum + 0] = _getIndex(line + " ", 1);
                    _obj->mesh[meshNum - 1].index[indexNum + 1] = _getIndex(line + " ", 2);
                    _obj->mesh[meshNum - 1].index[indexNum + 2] = _getIndex(line + " ", 3);

                    indexNum += 3;
                }
                else if (indexCount == 4) // Quad
                {
                    _obj->mesh[meshNum - 1].index[indexNum + 0] = _getIndex(line + " ", 1);
                    _obj->mesh[meshNum - 1].index[indexNum + 1] = _getIndex(line + " ", 2);
                    _obj->mesh[meshNum - 1].index[indexNum + 2] = _getIndex(line + " ", 3);

                    _obj->mesh[meshNum - 1].index[indexNum + 3] = _getIndex(line + " ", 3);
                    _obj->mesh[meshNum - 1].index[indexNum + 4] = _getIndex(line + " ", 4);
                    _obj->mesh[meshNum - 1].index[indexNum + 5] = _getIndex(line + " ", 1);

                    indexNum += 6;
                }
                else // n-gon
                {
                    _obj->mesh[meshNum - 1].index[indexNum + 0] = _getIndex(line + " ", 1);
                    _obj->mesh[meshNum - 1].index[indexNum + 1] = _getIndex(line + " ", 2);
                    _obj->mesh[meshNum - 1].index[indexNum + 2] = _getIndex(line + " ", 3);

                    std::uint32_t ic = 3; // triangle index count
                    for (std::uint32_t i = 3; i < indexCount; ++i)
                    {
                        _obj->mesh[meshNum - 1].index[indexNum + ic + 0] = _getIndex(line + " ", i + 0);
                        _obj->mesh[meshNum - 1].index[indexNum + ic + 1] = _getIndex(line + " ", i + 1);
                        _obj->mesh[meshNum - 1].index[indexNum + ic + 2] = _getIndex(line + " ", 1);
                        ic += 3;
                    }
                    indexNum += ((indexCount - 2) * 3);
                }
            }
        }

        // Close the obj file
        objFile.close();
    }
    else
    {
        std::cout << "Failed to open file: " << _fileName << std::endl;
    }
}

void gSaveOBJ(sOBJ *&_obj, const std::string &_fileName)
{
    // if no data, early exit
    if (_obj == nullptr)
        return;

    // Open the file
    std::ofstream objFile;
    objFile.open (_fileName);
    objFile << "# Grume obj loader" << std::endl;

    // For each mesh
    for (std::uint32_t m = 0; m < _obj->numMesh; ++m)
    {
        objFile << "o " << _obj->mesh[m].name << std::endl;

        // For each vertex position
        for (std::uint32_t v = 0; v < _obj->mesh[m].numVertex; ++v)
        {
            objFile << "v " << _obj->mesh[m].vertex[v].x << " "
                            << _obj->mesh[m].vertex[v].y << " "
                            << _obj->mesh[m].vertex[v].z << std::endl;
        }

        // For each vertex texture coord
        for (std::uint32_t vt = 0; vt < _obj->mesh[m].numTexCoord; ++vt)
        {
            objFile << "vt " << _obj->mesh[m].texCoord[vt].x << " "
                             << _obj->mesh[m].texCoord[vt].y << std::endl;
        }

        // For each vertex normal
        for (std::uint32_t vn = 0; vn < _obj->mesh[m].numNormal; ++vn)
        {
            objFile << "vn " << _obj->mesh[m].normal[vn].x << " "
                             << _obj->mesh[m].normal[vn].y << " "
                             << _obj->mesh[m].normal[vn].z << std::endl;
        }

        // For each triangle face
        for (std::uint32_t f = 0; f < _obj->mesh[m].numIndex; f += 3)
        {
            objFile << "f " << _obj->mesh[m].index[f + 0].v << "/"
                            << _obj->mesh[m].index[f + 0].t << "/"
                            << _obj->mesh[m].index[f + 0].n << " "

                            << _obj->mesh[m].index[f + 1].v << "/"
                            << _obj->mesh[m].index[f + 1].t << "/"
                            << _obj->mesh[m].index[f + 1].n << " "

                            << _obj->mesh[m].index[f + 2].v << "/"
                            << _obj->mesh[m].index[f + 2].t << "/"
                            << _obj->mesh[m].index[f + 2].n << std::endl;
        }

    }

    // Close the file
    objFile.close();
}
