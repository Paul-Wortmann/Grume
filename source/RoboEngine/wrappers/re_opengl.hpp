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
    #define RE_GL_FALSE GL_FALSE
    #define RE_GL_TRUE GL_TRUE
    #define RE_GL_COMPUTE_SHADER GL_COMPUTE_SHADER
    #define RE_GL_VERTEX_SHADER GL_VERTEX_SHADER
    #define RE_GL_TESS_CONTROL_SHADER GL_TESS_CONTROL_SHADER
    #define RE_GL_TESS_EVALUATION_SHADER GL_TESS_EVALUATION_SHADER
    #define RE_GL_GEOMETRY_SHADER GL_GEOMETRY_SHADER
    #define RE_GL_FRAGMENT_SHADER GL_FRAGMENT_SHADER
    #define RE_GL_COMPILE_STATUS GL_COMPILE_STATUS
    #define RE_GL_INFO_LOG_LENGTH GL_INFO_LOG_LENGTH
    #define RE_GL_LINK_STATUS GL_LINK_STATUS
    #define RE_GL_INVALID_INDEX GL_INVALID_INDEX

    inline void RE_glClearColor(float _r, float _g, float _b, float _a) { glClearColor(_r, _g, _b, _a); }
    inline void RE_glClear(RE_GLbitfield _mask) { glClear(_mask); }
    inline const unsigned char* RE_glGetString(RE_GLenum _name) { return glGetString(_name); }

    inline void RE_glGenTextures(uint32_t _n, uint32_t *_textures) { glGenTextures(_n, _textures); }
    inline void RE_glBindTexture(RE_GLenum _target,	uint32_t _texture) { glBindTexture(_target, _texture); }
    inline void RE_glTexImage2D(RE_GLenum _target, int32_t _level, int32_t _internalformat, uint32_t _width, uint32_t _height, int32_t _border, RE_GLenum _format, RE_GLenum _type, const GLvoid *_data) { glTexImage2D(_target, _level, _internalformat, _width, _height, _border, _format, _type, _data); }
    inline void RE_glTexParameteri(RE_GLenum _target, RE_GLenum _pname, int32_t _param) { glTexParameteri(_target, _pname, _param); }
    inline void RE_glTexParameterf(RE_GLenum _target, RE_GLenum _pname, float _param) { glTexParameterf(_target, _pname, _param); }
    inline void RE_glGenerateMipmap(RE_GLenum _target) { glGenerateMipmap(_target); }
    inline void RE_glGenerateTextureMipmap(uint32_t _texture) { glGenerateTextureMipmap(_texture); }
    inline void RE_glDeleteTextures(uint32_t _textureCount, uint32_t *_textureID) { glDeleteTextures(_textureCount, _textureID); }

    inline uint32_t RE_glCreateShader(RE_GLenum _shaderType) { return glCreateShader(_shaderType); }
    inline void RE_glShaderSource(uint32_t _shader, int32_t _count, const char **_string, const int32_t *_length) { glShaderSource(_shader, _count, _string, _length); }
    inline void RE_glCompileShader(uint32_t _shader) { glCompileShader(_shader); }
    inline void RE_glGetShaderiv(uint32_t _shader, RE_GLenum _pname, int32_t *_params) { RE_glGetShaderiv(_shader, _pname, _params); }
    inline void RE_glGetShaderInfoLog(uint32_t _shader, int32_t _maxLength, int32_t *_length, char *_infoLog) { glGetShaderInfoLog(_shader, _maxLength, _length, _infoLog); }
    inline void RE_glDeleteShader(uint32_t _shader) { glDeleteShader(_shader); }
    inline uint32_t RE_glCreateProgram(void) { return glCreateProgram(); }
    inline void RE_glAttachShader(uint32_t _program, uint32_t _shader) { glAttachShader(_program, _shader); }
    inline void RE_glLinkProgram(uint32_t _program) { glLinkProgram(_program); }
    inline void RE_glGetProgramiv(uint32_t _program, RE_GLenum _pname, int32_t *_params) { glGetProgramiv(_program, _pname, _params); }
    inline void RE_glGetProgramInfoLog(uint32_t _program, int32_t _maxLength, int32_t *_length, char *_infoLog) {glGetProgramInfoLog(_program, _maxLength, _length, _infoLog);}
    inline void RE_glDeleteProgram(uint32_t _program) { glDeleteProgram(_program); }
    inline void RE_glDetachShader(uint32_t _program, uint32_t _shader) { glDetachShader(_program, _shader); }
    inline void RE_glBindAttribLocation(uint32_t _program, uint32_t _index, const char *_name) { glBindAttribLocation(_program, _index, _name); }
    inline int32_t RE_glGetUniformLocation(uint32_t _program, const char *_name) { return glGetUniformLocation(_program, _name); }
    inline void RE_glUseProgram(uint32_t _program) { glUseProgram(_program); }
    inline void RE_glEnableVertexAttribArray(uint32_t _index) { glEnableVertexAttribArray(_index); }
    inline void RE_glDisableVertexAttribArray(uint32_t _index) { glDisableVertexAttribArray(_index); }

}

#endif //  RE_OPENGL_HPP

