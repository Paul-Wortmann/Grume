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

#include "graphics_engine_debug.hpp"

std::string getOpenGLErrorString(uint32_t _errorCode)
{
    if (_errorCode == GL_INVALID_ENUM)
        return "GL_INVALID_ENUM";
    if (_errorCode == GL_INVALID_VALUE)
        return "GL_INVALID_VALUE";
    if (_errorCode == GL_INVALID_OPERATION)
        return "GL_INVALID_OPERATION";
    if (_errorCode == GL_STACK_OVERFLOW)
        return "GL_STACK_OVERFLOW";
    if (_errorCode == GL_STACK_UNDERFLOW)
        return "GL_STACK_UNDERFLOW";
    if (_errorCode == GL_OUT_OF_MEMORY)
        return "GL_OUT_OF_MEMORY";
    if (_errorCode == GL_INVALID_FRAMEBUFFER_OPERATION)
        return "GL_INVALID_FRAMEBUFFER_OPERATION";
    if (_errorCode == GL_CONTEXT_LOST)
        return "GL_CONTEXT_LOST";
    if (_errorCode == GL_TABLE_TOO_LARGE)
        return "GL_TABLE_TOO_LARGE";
    return "unknown error";
}

void checkOpenGL(void)
{
    GLenum error;
    while((error = glGetError()) != GL_NO_ERROR)
    {
        gLogWrite(LOG_ERROR, std::to_string(error) + ": "+ getOpenGLErrorString(error), __FILE__, __LINE__, __FUNCTION__);
    }
}

