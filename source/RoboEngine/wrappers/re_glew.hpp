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

#ifndef RE_GLEW_HPP
#define RE_GLEW_HPP

#include <GL/glew.h>
#include <GL/gl.h>
#include "re_opengl.hpp"

namespace RoboEngine
{

    #define RE_GLEW_OK GLEW_OK

    inline void RE_glewExperimental(bool _bool) { glewExperimental = _bool; }
    inline RE_GLenum RE_glewInit(void) { return glewInit(); }
}

#endif //RE_GLEW_HPP
