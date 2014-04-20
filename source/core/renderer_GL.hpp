/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */



#ifndef RENDERER_GL_H
#define RENDERER_GL_H

#include "core.hpp"

#define PROGRAM_NAME "Frost and Flame -> OpenGL 3.x+ test renderer."
#define RENDERER_CONTEXT_MAJOR 1
#define RENDERER_CONTEXT_MINOR 2


struct GL_object_struct
{
    GLuint   vao_data;
    GLuint  *vbo_data;
    GLuint   vao_id;
    int      number_of_vertex;
    int      number_of_vbo;
    GLfloat *vertex;
    GLfloat *color;
};

struct render_GL_struct
{
    int window_x;
    int window_y;
    int major_version_number;
    int minor_version_number;
    int number_VAO;
    GL_object_struct *object_vao;
    SDL_Window*   window;
    SDL_GLContext context;
    int current_display;
    int current_display_mode;
    int number_displays;
    int number_display_modes;

    int IsCompiled_VS;
    int IsCompiled_FS;
    int IsLinked;
    int maxLength;
    char *vertexInfoLog;
    char *fragmentInfoLog;
    char *shaderProgramInfoLog;
    GLchar *vertexsource;
    GLchar *fragmentsource;
    GLuint  vertexshader;
    GLuint  fragmentshader;
    GLuint  shaderprogram;
};

bool GL_init(void);
bool GL_init_old(void);
bool GL_deinit(void);
bool GL_push_renderer_vbo(GL_object_struct &GL_object, GLuint &vao_id);
bool GL_init_vao(GL_object_struct &GL_object);
bool GL_render(void);

#endif // RENDERER_GL_H

