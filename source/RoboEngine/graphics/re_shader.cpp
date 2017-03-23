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

#include "re_shader.hpp"
#include "../roboengine.hpp"

namespace RoboEngine
{

    void freeShader(uint32_t _shaderID)
    {
        glUseProgram(0);
        glDeleteProgram(_shaderID);
    }

    void loadShader(const std::string &_fileName, uint32_t &_programID, uint32_t &_numAttribs)
    {
        _programID = glCreateProgram();
        // compile vertex shader
        uint32_t shaderVS_ID = glCreateShader(GL_VERTEX_SHADER);
        if (shaderVS_ID == 0)
            re_logWrite("Error -> OpenGL, failed to create and get an ID for vertex shader.", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
        std::string contentsStringVS = re_fileToString(_fileName + ".vs").c_str();
        const char *contentsPtrVS = contentsStringVS.c_str();
        glShaderSource(shaderVS_ID, 1, &contentsPtrVS, nullptr);
        glCompileShader(shaderVS_ID);
        int32_t success = 0;
        glGetShaderiv(shaderVS_ID, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            int32_t maxLength = 0;
            glGetShaderiv(shaderVS_ID, GL_INFO_LOG_LENGTH, &maxLength);
            char* infoLog = new char[maxLength + 1];
            glGetShaderInfoLog(shaderVS_ID, maxLength, &maxLength, infoLog);
            std::string infoLogString = infoLog;
            delete[] infoLog;
            glDeleteShader(shaderVS_ID);
            re_logWrite("Error -> " + _fileName + ".vs" + " failed to compile.", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            re_logWrite("Compilation error -> " + infoLogString, RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
        }
        else
        {
            // compile fragment shader
            uint32_t shaderFS_ID = glCreateShader(GL_FRAGMENT_SHADER);
            if (shaderFS_ID == 0)
                re_logWrite("Error -> OpenGL, failed to create and get an ID for fragment shader.", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            std::string contentsStringFS = re_fileToString(_fileName + ".fs").c_str();
            const char *contentsPtrFS = contentsStringFS.c_str();
            glShaderSource(shaderFS_ID, 1, &contentsPtrFS, nullptr);
            glCompileShader(shaderFS_ID);
            success = 0;
            glGetShaderiv(shaderFS_ID, GL_COMPILE_STATUS, &success);
            if (success == GL_FALSE)
            {
                int32_t maxLength = 0;
                glGetShaderiv(shaderFS_ID, GL_INFO_LOG_LENGTH, &maxLength);
                char* infoLog = new char[maxLength + 1];
                glGetShaderInfoLog(shaderFS_ID, maxLength, &maxLength, infoLog);
                std::string infoLogString = infoLog;
                delete[] infoLog;
                glDeleteShader(shaderVS_ID);
                glDeleteShader(shaderFS_ID);
                re_logWrite("Error -> " + _fileName + ".fs" + " failed to compile.", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
                re_logWrite("Compilation error -> " + infoLogString, RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
            }
            else
            {
                //add attributes
                std::string fileName = _fileName + ".vs";
                std::ifstream fileStream(fileName);
                if (fileStream.fail())
                {
                    perror(fileName.c_str());
                    re_logWrite("Error - Failed to open file:. " + fileName + ".vs", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
                }
                std::string lineData = "";
                while (std::getline(fileStream, lineData))
                {
                    uint32_t lineDataSize = lineData.size();
                    if (lineDataSize >= 10)
                    {
                        if ((lineData[0] == 'i') && (lineData[1] == 'n') && (lineData[2] == ' ') && (lineData[3] == 'v') && (lineData[4] == 'e') && (lineData[5] == 'c'))
                        {
                            bool startFound = false;
                            bool endFound = false;
                            std::string attrib = "";
                            for (uint32_t i = 5; i < lineDataSize; i++)
                            {
                                if ((lineData[i] != ' ') && (lineData[i-1] == ' '))
                                    startFound = true;
                                if (lineData[i] == ';')
                                    endFound = true;
                                if (startFound && !endFound)
                                    attrib += lineData[i];
                            }
                            //std::cout << "Found attribute -> -" << attrib << "- " << std::endl;
                            glBindAttribLocation(_programID, _numAttribs++, attrib.c_str());
                        }
                    }
                }
                fileStream.close();
                //link shaders
                glAttachShader(_programID, shaderVS_ID);
                glAttachShader(_programID, shaderFS_ID);
                glLinkProgram(_programID);
                int32_t isLinked = 0;
                glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
                if(isLinked == GL_FALSE)
                {
                    int32_t maxLength = 0;
                    glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);
                    char* infoLog = new char[maxLength + 1];
                    glGetProgramInfoLog(_programID, maxLength, &maxLength, infoLog);
                    std::string infoLogString = infoLog;
                    delete[] infoLog;
                    glDeleteProgram(_programID);
                    glDeleteShader(shaderVS_ID);
                    glDeleteShader(shaderFS_ID);
                    re_logWrite("Error -> Shaders failed to link.", RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
                    re_logWrite("Linker error -> " + infoLogString, RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
                }
                glDetachShader(_programID, shaderVS_ID);
                glDetachShader(_programID, shaderFS_ID);
                glDeleteShader(shaderVS_ID);
                glDeleteShader(shaderFS_ID);
            }
        }
    }

    int32_t getUniformLocation(const re_sShader& _sShader, const std::string & _uniformName)
    {
        uint32_t location = glGetUniformLocation(_sShader.ID, _uniformName.c_str());
        if (location == GL_INVALID_INDEX)
            re_logWrite("Warning - Uniform " + _uniformName + " not found in shader: " + _sShader.fileName, RE_ENGINE_LOG, __FILE__, __LINE__, __FUNCTION__);
        return location;
    }

}
