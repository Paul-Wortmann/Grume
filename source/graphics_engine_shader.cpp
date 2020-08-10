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

#include "utilities_file.hpp"
#include "graphics_engine_shader.hpp"

uint32_t cShader::load(const std::string &_fileName)
{
    // if a shader is already loaded, free it.
    if (m_programID != 0)
    {
        glDeleteShader(m_programID);
        m_programID = 0;
    }

    // check to see if the file exists
    if (fileExists(_fileName + ".vs") && fileExists(_fileName + ".fs"))
    {
        gLogWrite(LOG_INFO, "cShader - Loading file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        gLogWrite(LOG_ERROR, "cShader - Error loading file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return 0;
    }
    
    // Read shaders
    uint32_t shaderVert = glCreateShader(GL_VERTEX_SHADER);
    uint32_t shaderFrag = glCreateShader(GL_FRAGMENT_SHADER);    

    std::string shaderVertString = fileToString(_fileName + ".vs");
    std::string shaderFragString = fileToString(_fileName + ".fs");
    
    const char* shaderVertSource = shaderVertString.c_str();
    const char* shaderFragSource = shaderFragString.c_str();    
    
    GLint result = GL_FALSE;
  
    // Vertex shader
    glShaderSource(shaderVert, 1, &shaderVertSource, NULL);
    glCompileShader(shaderVert);
    glGetShaderiv(shaderVert, GL_COMPILE_STATUS, &result);
    if (result != GL_TRUE)
    {
        int logLength = 0;
        glGetShaderiv(shaderVert, GL_INFO_LOG_LENGTH, &logLength);
        char* vertShaderError = new char[logLength];
        glGetShaderInfoLog(shaderVert, logLength, NULL, &vertShaderError[0]);
        std::cout << &vertShaderError[0] << std::endl;
        delete[] vertShaderError;
    }

    // Fragment shader
    glShaderSource(shaderFrag, 1, &shaderFragSource, NULL);
    glCompileShader(shaderFrag);
    glGetShaderiv(shaderFrag, GL_COMPILE_STATUS, &result);
    if (result != GL_TRUE)
    {
        int logLength = 0;
        glGetShaderiv(shaderFrag, GL_INFO_LOG_LENGTH, &logLength);
        char* fragShaderError = new char[logLength];
        glGetShaderInfoLog(shaderFrag, logLength, NULL, &fragShaderError[0]);
        std::cout << &fragShaderError[0] << std::endl;
        delete[] fragShaderError;
    }
    
    // Shader Program
    m_programID = glCreateProgram();
    glAttachShader(m_programID, shaderVert);
    glAttachShader(m_programID, shaderFrag);
    glLinkProgram(m_programID);
    glGetProgramiv(m_programID, GL_LINK_STATUS, &result);
    if (result != GL_TRUE)
    {
        int logLength = 0;
        glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &logLength);
        char* programShaderError = new char[logLength];
        glGetProgramInfoLog(m_programID, logLength, NULL, &programShaderError[0]);
        std::cout << &programShaderError[0] << std::endl;
        delete[] programShaderError;
        
        glDeleteShader(m_programID);
        m_programID = 0;
    }

    glDeleteShader(shaderVert);
    glDeleteShader(shaderFrag);

    m_setupIDs();

    return m_programID;
}

void cShader::m_setupIDs(void)
{
    m_animationEnabledID = glGetUniformLocation(m_programID, "animationEnabled");
    
    m_modelMatrixID      = glGetUniformLocation(m_programID, "modelMatrix");
    m_viewMatrixID       = glGetUniformLocation(m_programID, "viewMatrix");
    m_projectionMatrixID = glGetUniformLocation(m_programID, "projectionMatrix");

    m_textureDiffuseID   = glGetUniformLocation(m_programID, "textureDiffuse");
    m_textureNormalID    = glGetUniformLocation(m_programID, "textureNormal");
    m_textureSpecularID  = glGetUniformLocation(m_programID, "textureSpecular");

    for (size_t i = 0; i < MAX_BONES; i++)
    {
        m_boneID[i] = glGetUniformLocation(m_programID, std::string("boneMatrix[" + std::to_string(i) + "]").c_str());
    }
}

void cShader::use(void)
{
    glUseProgram(m_programID);
}