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

#include "re_opengl.hpp"

namespace RoboEngine
{

    void RE_glClearColor(float _r, float _g, float _b, float _a)
    {
        glClearColor(_r, _g, _b, _a);
    }

    void RE_glClear(RE_GLbitfield _mask)
    {
        glClear(_mask);
    }

    const unsigned char* RE_glGetString(RE_GLenum _name)
    {
        return glGetString(_name);
    }

    void RE_glGenTextures(uint32_t _n, uint32_t *_textures)
    {
        glGenTextures(_n, _textures);
    }

    void RE_glBindTexture(RE_GLenum _target, uint32_t _texture)
    {
        glBindTexture(_target, _texture);
    }

    void RE_glTexImage2D(RE_GLenum _target, int32_t _level, int32_t _internalformat, uint32_t _width, uint32_t _height, int32_t _border, RE_GLenum _format, RE_GLenum _type, const GLvoid *_data)
    {
        glTexImage2D(_target, _level, _internalformat, _width, _height, _border, _format, _type, _data);
    }

    void RE_glTexParameteri(RE_GLenum _target, RE_GLenum _pname, int32_t _param)
    {
        glTexParameteri(_target, _pname, _param);
    }

    void RE_glTexParameterf(RE_GLenum _target, RE_GLenum _pname, float _param)
    {
        glTexParameterf(_target, _pname, _param);
    }

    void RE_glGenerateMipmap(RE_GLenum _target)
    {
        glGenerateMipmap(_target);
    }

    void RE_glGenerateTextureMipmap(uint32_t _texture)
    {
        glGenerateTextureMipmap(_texture);
    }

}
