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

#ifndef RE_GLX_HPP
#define RE_GXW_HPP

#include <GL/gl.h>
#include <GL/glx.h>

namespace RoboEngine
{
    namespace glExt
    {
        extern PFNGLACTIVETEXTUREARBPROC         glActiveTextureARB;
        extern PFNGLMULTITEXCOORD2FARBPROC       glMultiTexCoord2fARB;
        extern PFNGLGENVERTEXARRAYSPROC          glGenVertexArrays;
        extern PFNGLBINDVERTEXARRAYPROC          glBindVertexArray;
        extern PFNGLGENBUFFERSPROC               glGenBuffers;
        extern PFNGLBINDBUFFERPROC               glBindBuffer;
        extern PFNGLBUFFERDATAPROC               glBufferData;
        extern PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer;
        extern PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray;
        extern PFNGLCREATESHADERPROC             glCreateShader;
        extern PFNGLSHADERSOURCEPROC             glShaderSource;
        extern PFNGLCOMPILESHADERPROC            glCompileShader;
        extern PFNGLGETSHADERIVPROC              glGetShaderiv;
        extern PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog;
        extern PFNGLCREATEPROGRAMPROC            glCreateProgram;
        extern PFNGLATTACHSHADERPROC             glAttachShader;
        extern PFNGLBINDATTRIBLOCATIONPROC       glBindAttribLocation;
        extern PFNGLLINKPROGRAMPROC              glLinkProgram;
        extern PFNGLGETPROGRAMIVPROC             glGetProgramiv;
        extern PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog;
        extern PFNGLUSEPROGRAMPROC               glUseProgram;
        extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
        extern PFNGLDETACHSHADERPROC             glDetachShader;
        extern PFNGLDELETEPROGRAMPROC            glDeleteProgram;
        extern PFNGLDELETESHADERPROC             glDeleteShader;
        extern PFNGLDELETEBUFFERSPROC            glDeleteBuffers;
        extern PFNGLDELETEVERTEXARRAYSPROC       glDeleteVertexArrays;
        extern PFNGLGETSTRINGIPROC               glGetStringi;
        extern PFNGLGETATTRIBLOCATIONPROC        glGetAttribLocation;
        extern PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation;
        extern void init(void **context);
    }
}

#endif //RE_GLX_HPP
