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

#ifndef RE_OGL_HEADERS_HPP
#define RE_OGL_HEADERS_HPP

#define RE_GL_CONTEXT_MAJOR 3
#define RE_GL_CONTEXT_MINOR 3

#ifdef __gnu_linux__
    #define GLEW_STATIC
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
    #define GLM_FORCE_RADIANS
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtx/projection.hpp>
    #include <glm/gtx/transform2.hpp>
#else
    #define GLEW_STATIC
    #include <gl/glew.h>
    #include <GLFW/glfw3.h>
    #define GLM_FORCE_RADIANS
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtx/projection.hpp>
    #include <glm/gtx/transform2.hpp>
#endif

#endif // RE_OGL_HEADERS_HPP
