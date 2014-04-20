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


#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_opengl.h>
#include "core.hpp"
#include "renderer_GL.hpp"
#include "../game/game.hpp"

extern game_class game;

std::string pixel_format_from_int(int pfi)
{
    switch (pfi)
    {
        case SDL_PIXELFORMAT_INDEX1LSB:
            return ("SDL_PIXELFORMAT_INDEX1LSB");
        break;
        case SDL_PIXELFORMAT_INDEX1MSB:
            return ("SDL_PIXELFORMAT_INDEX1MSB");
        break;
        case SDL_PIXELFORMAT_INDEX4LSB:
            return ("SDL_PIXELFORMAT_INDEX4LSB");
        break;
        case SDL_PIXELFORMAT_INDEX4MSB:
            return ("SDL_PIXELFORMAT_INDEX4MSB");
        break;
        case SDL_PIXELFORMAT_INDEX8:
            return ("SDL_PIXELFORMAT_INDEX8");
        break;
        case SDL_PIXELFORMAT_RGB332:
            return ("SDL_PIXELFORMAT_RGB332");
        break;
        case SDL_PIXELFORMAT_RGB444:
            return ("SDL_PIXELFORMAT_RGB444");
        break;
        case SDL_PIXELFORMAT_RGB555:
            return ("SDL_PIXELFORMAT_RGB555");
        break;
        case SDL_PIXELFORMAT_BGR555:
            return ("SDL_PIXELFORMAT_BGR555");
        break;
        case SDL_PIXELFORMAT_ARGB4444:
            return ("SDL_PIXELFORMAT_ARGB4444");
        break;
        case SDL_PIXELFORMAT_RGBA4444:
            return ("SDL_PIXELFORMAT_RGBA4444");
        break;
        case SDL_PIXELFORMAT_ABGR4444:
            return ("SDL_PIXELFORMAT_ABGR4444");
        break;
        case SDL_PIXELFORMAT_BGRA4444:
            return ("SDL_PIXELFORMAT_BGRA4444");
        break;
        case SDL_PIXELFORMAT_ARGB1555:
            return ("SDL_PIXELFORMAT_ARGB1555");
        break;
        case SDL_PIXELFORMAT_RGBA5551:
            return ("SDL_PIXELFORMAT_RGBA5551");
        break;
        case SDL_PIXELFORMAT_ABGR1555:
            return ("SDL_PIXELFORMAT_ABGR1555");
        break;
        case SDL_PIXELFORMAT_BGRA5551:
            return ("SDL_PIXELFORMAT_BGRA5551");
        break;
        case SDL_PIXELFORMAT_RGB565:
            return ("SDL_PIXELFORMAT_RGB565");
        break;
        case SDL_PIXELFORMAT_BGR565:
            return ("SDL_PIXELFORMAT_BGR565");
        break;
        case SDL_PIXELFORMAT_RGB24:
            return ("SDL_PIXELFORMAT_RGB24");
        break;
        case SDL_PIXELFORMAT_BGR24:
            return ("SDL_PIXELFORMAT_BGR24");
        break;
        case SDL_PIXELFORMAT_RGB888:
            return ("SDL_PIXELFORMAT_RGB888");
        break;
        case SDL_PIXELFORMAT_RGBX8888:
            return ("SDL_PIXELFORMAT_RGBX8888");
        break;
        case SDL_PIXELFORMAT_BGR888:
            return ("SDL_PIXELFORMAT_BGR888");
        break;
        case SDL_PIXELFORMAT_BGRX8888:
            return ("SDL_PIXELFORMAT_BGRX8888");
        break;
        case SDL_PIXELFORMAT_ARGB8888:
            return ("SDL_PIXELFORMAT_ARGB8888");
        break;
        case SDL_PIXELFORMAT_RGBA8888:
            return ("SDL_PIXELFORMAT_RGBA8888");
        break;
        case SDL_PIXELFORMAT_ABGR8888:
            return ("SDL_PIXELFORMAT_ABGR8888");
        break;
        case SDL_PIXELFORMAT_BGRA8888:
            return ("SDL_PIXELFORMAT_BGRA8888");
        break;
        case SDL_PIXELFORMAT_ARGB2101010:
            return ("SDL_PIXELFORMAT_ARGB2101010");
        break;
        case SDL_PIXELFORMAT_YV12:
            return ("SDL_PIXELFORMAT_YV12");
        break;
        case SDL_PIXELFORMAT_IYUV:
            return ("SDL_PIXELFORMAT_IYUV");
        break;
        case SDL_PIXELFORMAT_YUY2:
            return ("SDL_PIXELFORMAT_YUY2");
        break;
        case SDL_PIXELFORMAT_UYVY:
            return ("SDL_PIXELFORMAT_UYVY");
        break;
        case SDL_PIXELFORMAT_YVYU:
            return ("SDL_PIXELFORMAT_YVYU");
        break;
        case SDL_PIXELFORMAT_UNKNOWN:
        default:
            return ("SDL_PIXELFORMAT_UNKNOWN");
        break;
    }
    return ("Error in pixel_format_from_int(int pfi)");
}

bool GL_init(void)
{
    bool return_value   = true;
    int  glew_status    = 0;
    int  version_status = 0;
    game.core.gfx.number_VAO  = 1;
    game.core.gfx.major_version_number = 0;
    game.core.gfx.minor_version_number = 0;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,  RENDERER_CONTEXT_MAJOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,  RENDERER_CONTEXT_MINOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetSwapInterval(1);
    game.core.gfx.current_display      = 0;
    game.core.gfx.current_display_mode = 0;
    game.core.gfx.number_displays      = SDL_GetNumVideoDisplays();
    std::cout << "Number of attached displays -> " << game.core.gfx.number_displays << std::endl;
    game.core.gfx.number_display_modes = SDL_GetNumDisplayModes(game.core.gfx.current_display);
    SDL_DisplayMode *mode = new SDL_DisplayMode[game.core.gfx.number_display_modes+1];
    std::cout << "Number of display modes -> " << game.core.gfx.number_display_modes << std::endl;
    for (int i = 0; i < game.core.gfx.number_display_modes; i++)
    {
        if (SDL_GetDisplayMode(game.core.gfx.current_display,i,&mode[i]) == 0) std::cout << "Display mode - " << i << " - x - " << mode[i].w << " - y - " << mode[i].h << " - refresh rate - " << mode[i].refresh_rate << std::endl;
    }
    SDL_GetDisplayMode(game.core.gfx.current_display,game.core.gfx.current_display_mode,&mode[game.core.gfx.current_display_mode]);
    game.core.gfx.window_x    = mode[game.core.gfx.current_display_mode].w;
    game.core.gfx.window_y    = mode[game.core.gfx.current_display_mode].h;
    game.core.gfx.window_x    = 800;
    game.core.gfx.window_y    = 600;
    std::cout << "Setting display mode - " << game.core.gfx.current_display_mode << " - x - " << mode[game.core.gfx.current_display_mode].w << " - y - " << mode[game.core.gfx.current_display_mode].h << " - refresh rate - " << mode[game.core.gfx.current_display_mode].refresh_rate << std::endl;
    std::cout << "Using pixel format - " << pixel_format_from_int(mode[game.core.gfx.current_display_mode].format) << std::endl;
    std::cout << "Creating window..." << std::endl;
    game.core.gfx.window = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, game.core.gfx.window_x, game.core.gfx.window_y, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
    if (!game.core.gfx.window)
    {
        return_value = false;
        std::cout << "FAIL -> Unable to create window." << std::endl;
    }
    else
    {
        std::cout << "Starting OpenGL..." << std::endl;
        game.core.gfx.context = SDL_GL_CreateContext(game.core.gfx.window);
        version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &game.core.gfx.major_version_number);
        version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &game.core.gfx.minor_version_number);
        if (version_status == 0)
        {
            std::cout << "OpenGl Version -> " << game.core.gfx.major_version_number << "." << game.core.gfx.minor_version_number << std::endl;
            glewExperimental = GL_TRUE;
            glew_status = glewInit();
            if(glew_status != GLEW_OK)
            {
                return_value = false;
                std::cout << "FAIL -> Failed to initialize GLEW -> " << glewGetErrorString(glew_status) << std::endl;
            }
            else
            {
                std::cout << "Initialized GLEW -> " << glewGetErrorString(glew_status) << std::endl;
                int i;
                glGetIntegerv(GL_NUM_EXTENSIONS,&i);
                std::cout << "Loaded OpenGL Extension count -> " << i << std::endl;
                if (game.core.debug) for (int j = 0; j < i; j++) std::cout << "Loaded OpenGL Extension -> " << glGetStringi(GL_EXTENSIONS, j) << std::endl;
                glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
                // Vertex Shader
                game.core.gfx.vertexsource = game.core.file.filetobuf("data/shaders/aabb.vert");
                game.core.gfx.vertexshader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(game.core.gfx.vertexshader, 1, (const GLchar**)&game.core.gfx.vertexsource, 0);
                glCompileShader(game.core.gfx.vertexshader);
                glGetShaderiv(game.core.gfx.vertexshader, GL_COMPILE_STATUS, &game.core.gfx.IsCompiled_VS);
                if(game.core.gfx.IsCompiled_VS == false)
                {
                    int maxLength;
                    glGetShaderiv(game.core.gfx.vertexshader, GL_INFO_LOG_LENGTH, &maxLength);
                    game.core.gfx.vertexInfoLog = (char *)malloc(maxLength);
                    glGetShaderInfoLog(game.core.gfx.vertexshader, maxLength, &maxLength, game.core.gfx.vertexInfoLog);
                    std::cout << "FAIL -> Error loading Vertex Shader." << std::endl;
                    free(game.core.gfx.vertexInfoLog);
                }
                // Fragment Shader
                game.core.gfx.fragmentsource = game.core.file.filetobuf("data/shaders/aabb.frag");
                game.core.gfx.fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(game.core.gfx.fragmentshader, 1, (const GLchar**)&game.core.gfx.fragmentsource, 0);
                glCompileShader(game.core.gfx.fragmentshader);
                glGetShaderiv(game.core.gfx.fragmentshader, GL_COMPILE_STATUS, &game.core.gfx.IsCompiled_FS);
                if(game.core.gfx.IsCompiled_FS == false)
                {
                    int maxLength;
                    glGetShaderiv(game.core.gfx.fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);
                    game.core.gfx.fragmentInfoLog = (char *)malloc(maxLength);
                    glGetShaderInfoLog(game.core.gfx.fragmentshader, maxLength, &maxLength, game.core.gfx.fragmentInfoLog);
                    std::cout << "FAIL -> Error loading Fragment Shader." << std::endl;
                    free(game.core.gfx.fragmentInfoLog);
                }
                // Shader Program
                game.core.gfx.shaderprogram = glCreateProgram();
                glAttachShader(game.core.gfx.shaderprogram, game.core.gfx.vertexshader);
                glAttachShader(game.core.gfx.shaderprogram, game.core.gfx.fragmentshader);
                glBindAttribLocation(game.core.gfx.shaderprogram, 0, "in_Position");
                glBindAttribLocation(game.core.gfx.shaderprogram, 1, "in_Color");
                glLinkProgram(game.core.gfx.shaderprogram);
                glGetProgramiv(game.core.gfx.shaderprogram, GL_LINK_STATUS, (int *)&game.core.gfx.IsLinked);
                if(game.core.gfx.IsLinked == false)
                {
                    int maxLength;
                    glGetProgramiv(game.core.gfx.shaderprogram, GL_INFO_LOG_LENGTH, &maxLength);
                    game.core.gfx.shaderProgramInfoLog = (char *)malloc(maxLength);
                    glGetProgramInfoLog(game.core.gfx.shaderprogram, maxLength, &maxLength, game.core.gfx.shaderProgramInfoLog);
                    std::cout << "FAIL -> Shader program error." << std::endl;
                    free(game.core.gfx.shaderProgramInfoLog);
                }
                glUseProgram(game.core.gfx.shaderprogram);

                /*--------------------------------------*/
                GL_object_struct *object_1 = new GL_object_struct;
                object_1->vao_id           = 1;
                object_1->number_of_vbo    = 2;
                object_1->number_of_vertex = 4;
                object_1->vbo_data = new GLuint[object_1->number_of_vbo];
                object_1->vertex = new GLfloat[object_1->number_of_vertex*3];
                object_1->color  = new GLfloat[object_1->number_of_vertex*3];
                object_1->vertex[ 0] =  0.0f; object_1->vertex[ 1] =  1.0f; object_1->vertex[ 2] =  0.0f;
                object_1->vertex[ 3] =  1.0f; object_1->vertex[ 4] =  0.0f; object_1->vertex[ 5] =  0.0f;
                object_1->vertex[ 6] =  0.0f; object_1->vertex[ 7] = -1.0f; object_1->vertex[ 8] =  0.0f;
                object_1->vertex[ 9] = -1.0f; object_1->vertex[10] =  0.0f; object_1->vertex[11] =  0.0f;
                object_1->color[ 0] =  1.0f; object_1->color[ 1] =  0.0f; object_1->color[ 2] =  0.0f;
                object_1->color[ 3] =  0.0f; object_1->color[ 4] =  1.0f; object_1->color[ 5] =  0.0f;
                object_1->color[ 6] =  0.0f; object_1->color[ 7] =  0.0f; object_1->color[ 8] =  1.0f;
                object_1->color[ 9] =  1.0f; object_1->color[10] =  1.0f; object_1->color[11] =  1.0f;
                GL_init_vao(*object_1);
                /*--------------------------------------*/
                game.core.gfx.object_vao = object_1;
            }
        }
        else
        {
            return_value = false;
            std::cout << "FAIL -> Unable to set OpenGl Version -> " << game.core.gfx.major_version_number << "." << game.core.gfx.minor_version_number << std::endl;
        }
    }
    return (return_value);
};

bool GL_deinit(void)
{
    glUseProgram(0);
    glDetachShader(game.core.gfx.shaderprogram, game.core.gfx.vertexshader);
    glDetachShader(game.core.gfx.shaderprogram, game.core.gfx.fragmentshader);
    glDeleteProgram(game.core.gfx.shaderprogram);
    glDeleteShader(game.core.gfx.vertexshader);
    glDeleteShader(game.core.gfx.fragmentshader);
    if (game.core.gfx.number_VAO > 0)
    {
        for (int i = 0; i < game.core.gfx.number_VAO; i++)
        {
            glDisableVertexAttribArray(i);
        }
        if (game.core.gfx.object_vao->number_of_vbo > 0) glDeleteBuffers(game.core.gfx.object_vao->number_of_vbo, game.core.gfx.object_vao->vbo_data);
        if (game.core.gfx.number_VAO > 0) glDeleteVertexArrays(game.core.gfx.number_VAO, &game.core.gfx.object_vao->vao_data);
    }
    free(game.core.gfx.vertexsource);
    free(game.core.gfx.fragmentsource);
};

bool GL_push_renderer_vbo(GL_object_struct &GL_object, GLuint &vao_id)
{
    bool return_value = true;

    return (return_value);
}

bool GL_init_vao(GL_object_struct &GL_object)
{
    glGenVertexArrays(GL_object.vao_id, &GL_object.vao_data);
    glBindVertexArray(GL_object.vao_data);
    glGenBuffers(GL_object.number_of_vbo, GL_object.vbo_data);
    glBindBuffer(GL_ARRAY_BUFFER, GL_object.vbo_data[0]);
    glBufferData(GL_ARRAY_BUFFER, 3*GL_object.number_of_vertex*sizeof(GLfloat), GL_object.vertex, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, GL_object.vbo_data[1]);
    glBufferData(GL_ARRAY_BUFFER, 3*GL_object.number_of_vertex*sizeof(GLfloat), GL_object.color, GL_STATIC_DRAW);
    glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);
};

bool GL_render(void)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glBindVertexArray(game.core.gfx.object_vao->vao_data);
    glDrawArrays( GL_TRIANGLE_FAN, 0, game.core.gfx.object_vao->number_of_vertex);
    SDL_GL_SwapWindow(game.core.gfx.window);
};



