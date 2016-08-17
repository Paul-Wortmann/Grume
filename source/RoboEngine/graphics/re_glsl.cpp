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

    void freeShader(uint32_t _shaderID, uint32_t _numAttributes)
    {

    }

    uint32_t loadShader(const std::string &_fileName)
    {

    }

    uint32_t loadShaderAttribs(const std::string &_fileName)
    {

    }




    void re_cglsl::compileShader(const std::string &_file_name, e_shader_type _type)
    {
        uint32_t shader_ID = 0;
        std::string fileName = "";
        if (_type == e_shader_type::VERTEX)
        {
            m_shaderVS_ID = RE_glCreateShader(RE_GL_VERTEX_SHADER);
            if (m_shaderVS_ID == 0)
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> OpenGL, failed to create and get an ID for vertex shader.");
            shader_ID = m_shaderVS_ID;
            fileName = _file_name + ".vs";
        }
        else if (_type == e_shader_type::FRAGMENT)
        {
            m_shaderFS_ID = RE_glCreateShader(RE_GL_FRAGMENT_SHADER);
            if (m_shaderFS_ID == 0)
                RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> OpenGL, failed to create and get an ID for fragment shader.");
            shader_ID = m_shaderFS_ID;
            fileName = _file_name + ".fs";
        }
        const char* contentsPtr = fileToBuffer(fileName);
        RE_glShaderSource(shader_ID, 1, &contentsPtr, nullptr);
        RE_glCompileShader(shader_ID);
        int32_t success = 0;
        RE_glGetShaderiv(shader_ID, RE_GL_COMPILE_STATUS, &success);
        if (success == RE_GL_FALSE)
        {
            int32_t maxLength = 0;
            RE_glGetShaderiv(shader_ID, RE_GL_INFO_LOG_LENGTH, &maxLength);
            std::vector<char> infoLog(maxLength);
            RE_glGetShaderInfoLog(shader_ID, maxLength, &maxLength, &infoLog[0]);
            RE_glDeleteShader(shader_ID);
            shader_ID = 0;
            std::printf("%s\n", &(infoLog[0]));
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> " + fileName + " failed to compile.");
        }
    }

    void re_cglsl::compileShaders(const std::string &_file_name)
    {
        m_program_ID = RE_glCreateProgram();
        compileShader(_file_name, e_shader_type::VERTEX);
        compileShader(_file_name, e_shader_type::FRAGMENT);
    }

    void re_cglsl::linkShaders(void)
    {
        RE_glAttachShader(m_program_ID, m_shaderVS_ID);
        RE_glAttachShader(m_program_ID, m_shaderFS_ID);
        RE_glLinkProgram(m_program_ID);
        int32_t isLinked = 0;
        RE_glGetProgramiv(m_program_ID, RE_GL_LINK_STATUS, (int *)&isLinked);
        if(isLinked == RE_GL_FALSE)
        {
            int32_t maxLength = 0;
            RE_glGetProgramiv(m_program_ID, RE_GL_INFO_LOG_LENGTH, &maxLength);
            std::vector<char> infoLog(maxLength);
            RE_glGetProgramInfoLog(m_program_ID, maxLength, &maxLength, &infoLog[0]);
            RE_glDeleteProgram(m_program_ID);
            RE_glDeleteShader(m_shaderVS_ID);
            RE_glDeleteShader(m_shaderFS_ID);
            std::printf("%s\n", &(infoLog[0]));
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Error -> Shaders failed to link.");
        }
        RE_glDetachShader(m_program_ID, m_shaderVS_ID);
        RE_glDetachShader(m_program_ID, m_shaderFS_ID);
        RE_glDeleteShader(m_shaderVS_ID);
        RE_glDeleteShader(m_shaderFS_ID);
    }

    void re_cglsl::addAttribute(const std::string & _attributeName)
    {
        RE_glBindAttribLocation(m_program_ID, m_numAttributes++, _attributeName.c_str());
    }

    int32_t re_cglsl::getUniformLocation(const std::string & _uniformName)
    {
        uint32_t location = RE_glGetUniformLocation(m_program_ID, _uniformName.c_str());
        if (location == RE_GL_INVALID_INDEX)
            RoboEngine::log_write(ROBOENGINELOG, __FILE__, __FUNCTION__, __LINE__, "Uniform " + _uniformName + "not found in shader.");
        return location;
    }

    void re_cglsl::use(void)
    {
        RE_glUseProgram(m_program_ID);
        for (uint16_t i = 0; i < m_numAttributes; i++)
            RE_glEnableVertexAttribArray(i);
    }

    void re_cglsl::unuse(void)
    {
        RE_glUseProgram(0);
        for (uint16_t i = 0; i < m_numAttributes; i++)
            RE_glDisableVertexAttribArray(i);
    }

}
