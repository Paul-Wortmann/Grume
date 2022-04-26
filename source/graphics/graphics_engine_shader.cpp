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

#include "graphics_engine_shader.hpp"

void cGraphicsEngineShader::initialize(void)
{
    m_shaderID = 0;
}

void cGraphicsEngineShader::terminate(void)
{
    glUseProgram(0);
    glDeleteProgram(m_shaderID);
}

void cGraphicsEngineShader::use(void)
{
    glUseProgram(m_shaderID);
}

// Load a shader from file
std::uint32_t cGraphicsEngineShader::load(const std::string &_fileName)
{
    if(m_shaderID != 0)
    {
        glDeleteProgram(m_shaderID);
    }
    m_shaderID = 0;

    // Vertex shader
    GLuint vertShader = 0;

    std::string file_vs = FILE_PATH_SHADER + _fileName + ".vs";
    bool exist_vs = (fileExists(file_vs));
    if (exist_vs)
    {
        // Load the shader
        vertShader = glCreateShader(GL_VERTEX_SHADER);
        std::string shaderStr = "";
        fileToString(file_vs, shaderStr);
        const char *shaderSrc = shaderStr.c_str();

        // Compile the shader
        glShaderSource(vertShader, 1, &shaderSrc, NULL);
        glCompileShader(vertShader);

        // Check the shader
        GLint        compileStatus = GL_FALSE;
        std::int32_t logLength = 0;
        glGetShaderiv(vertShader, GL_COMPILE_STATUS, &compileStatus);
        if (compileStatus == GL_FALSE)
        {
            glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
            GLchar shaderLog[logLength+1];
            glGetShaderInfoLog(vertShader, logLength, NULL, &shaderLog[0]);
            gLogWrite(LOG_ERROR, "Error in shader: " + file_vs, __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
            if (vertShader != 0)
                glDeleteShader(vertShader);
            return m_shaderID;
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "No vertex shader found: " + file_vs, __FILE__, __LINE__, __FUNCTION__);
        return m_shaderID;
    }

    // Geometry shader
    GLuint geomShader = 0;

    std::string file_gs = FILE_PATH_SHADER + _fileName + ".gs";
    bool exist_gs = (fileExists(file_gs));
    if (exist_gs)
    {
        // Load the shader
        geomShader = glCreateShader(GL_GEOMETRY_SHADER);
        std::string shaderStr = "";
        fileToString(file_gs, shaderStr);
        const char *shaderSrc = shaderStr.c_str();

        // Compile the shader
        glShaderSource(geomShader, 1, &shaderSrc, NULL);
        glCompileShader(geomShader);

        // Check the shader
        GLint        compileStatus = GL_FALSE;
        std::int32_t logLength = 0;
        glGetShaderiv(geomShader, GL_COMPILE_STATUS, &compileStatus);
        if (compileStatus == GL_FALSE)
        {
            glGetShaderiv(geomShader, GL_INFO_LOG_LENGTH, &logLength);
            GLchar shaderLog[logLength+1];
            glGetShaderInfoLog(geomShader, logLength, NULL, &shaderLog[0]);
            gLogWrite(LOG_ERROR, "Error in shader: " + file_gs, __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
            if (vertShader != 0)
                glDeleteShader(vertShader);
            if (geomShader != 0)
                glDeleteShader(geomShader);
            return m_shaderID;
        }
    }
    else
    {
        gLogWrite(LOG_INFO, "No geometry shader found: " + file_gs, __FILE__, __LINE__, __FUNCTION__);
    }

    // Fragment shader
    GLuint fragShader = 0;

    std::string file_fs = FILE_PATH_SHADER + _fileName + ".fs";
    bool exist_fs = (fileExists(file_fs));
    if (exist_fs)
    {
        // Load the shader
        fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        std::string shaderStr = "";
        fileToString(file_fs, shaderStr);
        const char *shaderSrc = shaderStr.c_str();

        // Compile the shader
        glShaderSource(fragShader, 1, &shaderSrc, NULL);
        glCompileShader(fragShader);

        // Check the shader
        GLint        compileStatus = GL_FALSE;
        std::int32_t logLength = 0;
        glGetShaderiv(fragShader, GL_COMPILE_STATUS, &compileStatus);
        if (compileStatus == GL_FALSE)
        {
            glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
            GLchar shaderLog[logLength+1];
            glGetShaderInfoLog(fragShader, logLength, NULL, &shaderLog[0]);
            gLogWrite(LOG_ERROR, "Error in shader: " + file_fs, __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
            if (vertShader != 0)
                glDeleteShader(vertShader);
            if (geomShader != 0)
                glDeleteShader(geomShader);
            if (fragShader != 0)
                glDeleteShader(fragShader);
            return m_shaderID;
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "No fragment shader found: " + file_fs, __FILE__, __LINE__, __FUNCTION__);
        if (vertShader != 0)
            glDeleteShader(vertShader);
        if (geomShader != 0)
            glDeleteShader(geomShader);
        return m_shaderID;
    }

    // Shader program
    // Attach the compiled shader components
    GLuint program = glCreateProgram();
    if (vertShader != 0)
        glAttachShader(program, vertShader);
    if (geomShader != 0)
        glAttachShader(program, geomShader);
    if (fragShader != 0)
        glAttachShader(program, fragShader);

    // Compile the shader program
    glLinkProgram(program);

    // Chech for errors
    GLint        compileStatus = GL_FALSE;
    std::int32_t logLength = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &compileStatus);
    if (compileStatus == GL_FALSE)
    {
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        GLchar shaderLog[logLength+1];
        glGetProgramInfoLog(program, logLength, NULL, &shaderLog[0]);
        gLogWrite(LOG_ERROR, "Error in shader: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
        glDeleteProgram(program);
    }

    // Clean up
    if (vertShader != 0)
    {
        glDetachShader(program, vertShader);
        glDeleteShader(vertShader);
    }
    if (geomShader != 0)
    {
        glDetachShader(program, geomShader);
        glDeleteShader(geomShader);
    }
    if (fragShader != 0)
    {
        glDetachShader(program, fragShader);
        glDeleteShader(fragShader);
    }
    
    // Save and return the shader program ID
    m_shaderID = program;
    return program;
}

// Get a uniform location from the shader
std::uint32_t cGraphicsEngineShader::getUniformLocation(const std::string &_name)
{
    return glGetUniformLocation(m_shaderID, _name.c_str());
}

// Get an atribute location from the shader
std::uint32_t cGraphicsEngineShader::getAttribLocation(const std::string &_name)
{
    return glGetAttribLocation(m_shaderID, _name.c_str());
}
