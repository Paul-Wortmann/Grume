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

#include "re_glsl.hpp"

namespace RoboEngine
{

    void freeShader(uint32_t _shaderID)
    {
        RE_glUseProgram(0);
        RE_glDeleteProgram(_shaderID);
    }

    void loadShader(const std::string &_fileName, uint32_t &_programID, uint32_t &_numAttribs)
    {
        _programID = RE_glCreateProgram();
        uint32_t shaderVS_ID = 0;
        uint32_t shaderFS_ID = 0;
        // compile vertex shader
        shaderVS_ID = RE_glCreateShader(RE_GL_VERTEX_SHADER);
        if (shaderVS_ID == 0)
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> OpenGL, failed to create and get an ID for vertex shader.");
        std::string contentsStringVS = fileToString(_fileName + ".vs").c_str();
        const char *contentsPtrVS = contentsStringVS.c_str();
        RE_glShaderSource(shaderVS_ID, 1, &contentsPtrVS, nullptr);
        RE_glCompileShader(shaderVS_ID);
        int32_t success = 0;
        RE_glGetShaderiv(shaderVS_ID, RE_GL_COMPILE_STATUS, &success);
        if (success == RE_GL_FALSE)
        {
            int32_t maxLength = 0;
            RE_glGetShaderiv(shaderVS_ID, RE_GL_INFO_LOG_LENGTH, &maxLength);
            char* infoLog = new char[maxLength + 1];
            RE_glGetShaderInfoLog(shaderVS_ID, maxLength, &maxLength, infoLog);
            std::string infoLogString = infoLog;
            delete[] infoLog;
            RE_glDeleteShader(shaderVS_ID);
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> " + _fileName + ".vs" + " failed to compile.");
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Compilation error -> " + infoLogString);
        }
        else
        {
            // compile fragment shader
            shaderFS_ID = RE_glCreateShader(RE_GL_FRAGMENT_SHADER);
            if (shaderFS_ID == 0)
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> OpenGL, failed to create and get an ID for fragment shader.");
            std::string contentsStringFS = fileToString(_fileName + ".fs").c_str();
            const char *contentsPtrFS = contentsStringFS.c_str();
            RE_glShaderSource(shaderFS_ID, 1, &contentsPtrFS, nullptr);
            RE_glCompileShader(shaderFS_ID);
            success = 0;
            RE_glGetShaderiv(shaderFS_ID, RE_GL_COMPILE_STATUS, &success);
            if (success == RE_GL_FALSE)
            {
                int32_t maxLength = 0;
                RE_glGetShaderiv(shaderFS_ID, RE_GL_INFO_LOG_LENGTH, &maxLength);
                char* infoLog = new char[maxLength + 1];
                RE_glGetShaderInfoLog(shaderFS_ID, maxLength, &maxLength, infoLog);
                std::string infoLogString = infoLog;
                delete[] infoLog;
                RE_glDeleteShader(shaderVS_ID);
                RE_glDeleteShader(shaderFS_ID);
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> " + _fileName + ".fs" + " failed to compile.");
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Compilation error -> " + infoLogString);
            }
            else
            {
                //add attributes
                std::string fileName = _fileName + ".vs";
                std::ifstream fileStream(fileName);
                if (fileStream.fail())
                {
                    perror(fileName.c_str());
                    RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error - Failed to open file:. " + fileName + ".vs");
                }
                std::string fileData = "";
                std::string lineData = "";
                uint32_t lineDataSize = 0;
                while (std::getline(fileStream, lineData))
                {
                    lineDataSize = lineData.size();
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
                            RE_glBindAttribLocation(_programID, _numAttribs++, attrib.c_str());
                        }
                    }
                }
                fileStream.close();
                //link shaders
                RE_glAttachShader(_programID, shaderVS_ID);
                RE_glAttachShader(_programID, shaderFS_ID);
                RE_glLinkProgram(_programID);
                int32_t isLinked = 0;
                RE_glGetProgramiv(_programID, RE_GL_LINK_STATUS, (int *)&isLinked);
                if(isLinked == RE_GL_FALSE)
                {
                    int32_t maxLength = 0;
                    RE_glGetProgramiv(_programID, RE_GL_INFO_LOG_LENGTH, &maxLength);
                    char* infoLog = new char[maxLength + 1];
                    RE_glGetProgramInfoLog(_programID, maxLength, &maxLength, infoLog);
                    std::string infoLogString = infoLog;
                    delete[] infoLog;
                    RE_glDeleteProgram(_programID);
                    RE_glDeleteShader(shaderVS_ID);
                    RE_glDeleteShader(shaderFS_ID);
                    RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> Shaders failed to link.");
                    RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Linker error -> " + infoLogString);
                }
                RE_glDetachShader(_programID, shaderVS_ID);
                RE_glDetachShader(_programID, shaderFS_ID);
                RE_glDeleteShader(shaderVS_ID);
                RE_glDeleteShader(shaderFS_ID);
            }
        }
    }

/*
    int32_t getUniformLocation(const std::string & _uniformName)
    {
        uint32_t location = RE_glGetUniformLocation(m_program_ID, _uniformName.c_str());
        if (location == RE_GL_INVALID_INDEX)
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Uniform " + _uniformName + "not found in shader.");
        return location;
    }
*/


}
