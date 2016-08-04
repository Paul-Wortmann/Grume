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

#ifndef RE_OPENGL_HPP
#define RE_OPENGL_HPP

#include <cstdint>
#include <cstdlib>
#include <GL/gl.h>

namespace RoboEngine
{

    #define RE_GL_COLOR_BUFFER_BIT GL_COLOR_BUFFER_BIT
    #define RE_GLbitfield GLbitfield
    #define RE_GLenum GLenum
    #define RE_GL_VERSION GL_VERSION
    #define RE_GL_VENDOR GL_VENDOR
    #define RE_GL_RENDERER GL_RENDERER
    #define RE_GL_SHADING_LANGUAGE_VERSION GL_SHADING_LANGUAGE_VERSION
    #define RE_GL_EXTENSIONS GL_EXTENSIONS

    void RE_glClearColor(float _r, float _g, float _b, float _a);
    void RE_glClear(RE_GLbitfield _mask);
    const unsigned char* RE_glGetString(RE_GLenum _name);

}

#endif //  RE_OPENGL_HPP
