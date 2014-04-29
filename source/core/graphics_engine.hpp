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

#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <string>

#define PROGRAM_NAME "Frost and Flame -> OpenGL 3.x+ test renderer."
#define RENDERER_CONTEXT_MAJOR 3
#define RENDERER_CONTEXT_MINOR 2

#define RENDERER_GL1 1
#define RENDERER_GL3 3

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
    int number_VAO;
    GL_object_struct *object_vao;

    GLuint  vertexshader;
    GLuint  fragmentshader;
    GLuint  shaderprogram;
};

struct light_type
{
    float intensity_R;
    float intensity_G;
    float intensity_B;
    float intensity_A;
    bool  increase;
    float speed;
};

struct vertex_type
{
    float x;
    float y;
    float z;
};

struct vertex_texture_type
{
    float u;
    float v;
    float w;
};

struct vertex_normal_type
{
    float i;
    float j;
    float k;
};

class graphics_engine_class
{
    public:
        SDL_Window*      window;
        SDL_GLContext    context;
        SDL_DisplayMode *display_mode;
        render_GL_struct render_GL; // temp
        int             *menu_mode_list;
        int              menu_mode_length;
        int              renderer;
        int              GL_major_version_number;
        int              GL_minor_version_number;
        int              current_display;
        int              current_display_mode;
        int              number_displays;
        int              number_display_modes;
        graphics_engine_class(void);
       ~graphics_engine_class(void);
        bool             init(void);
        bool             deinit(void);
        bool             render(void);
        bool             build_mode_list(void);
        std::string      get_display_mode(int mode_number);
};

int   gl_to_res(float gl_coord, int max_res);
float res_to_gl(int  res_coord, int max_res);
std::string pixel_format_from_int(int pfi);
#endif //GRAPHICS_ENGINE_H
