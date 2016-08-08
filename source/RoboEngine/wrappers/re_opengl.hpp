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
#include <GL/glew.h>
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
    #define RE_GL_TEXTURE_2D GL_TEXTURE_2D
    #define RE_GL_RGBA GL_RGBA
    #define RE_GL_UNSIGNED_BYTE GL_UNSIGNED_BYTE
    #define RE_GL_TEXTURE_WRAP_S GL_TEXTURE_WRAP_S
    #define RE_GL_TEXTURE_WRAP_T GL_TEXTURE_WRAP_T
    #define RE_GL_TEXTURE_MIN_FILTER GL_TEXTURE_MIN_FILTER
    #define RE_GL_TEXTURE_MAG_FILTER GL_TEXTURE_MAG_FILTER
    #define RE_GL_REPEAT GL_REPEAT
    #define RE_GL_LINEAR_MIPMAP_LINEAR GL_LINEAR_MIPMAP_LINEAR
    #define RE_GL_LINEAR GL_LINEAR

    void RE_glClearColor(float _r, float _g, float _b, float _a);
    void RE_glClear(RE_GLbitfield _mask);
    const unsigned char* RE_glGetString(RE_GLenum _name);

    void RE_glGenTextures(uint32_t _n, uint32_t *_textures);
    void RE_glBindTexture(RE_GLenum _target,	uint32_t _texture);
    void RE_glTexImage2D(RE_GLenum _target, int32_t _level, int32_t _internalformat, uint32_t _width, uint32_t _height, int32_t _border, RE_GLenum _format, RE_GLenum _type, const GLvoid *_data);
    void RE_glTexParameteri(RE_GLenum _target, RE_GLenum _pname, int32_t _param);
    void RE_glTexParameterf(RE_GLenum _target, RE_GLenum _pname, float _param);
    void RE_glGenerateMipmap(RE_GLenum _target);
    void RE_glGenerateTextureMipmap(uint32_t _texture);
    void RE_glDeleteTextures(uint32_t _textureCount, uint32_t *_textureID);
}

#endif //  RE_OPENGL_HPP

