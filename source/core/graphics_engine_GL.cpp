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
#include "graphics_engine.hpp"
#include "graphics_engine_GL.hpp"
#include "../game/game.hpp"

extern game_class game;

bool GL_init(void)
{
    bool return_value    = true;
    bool reload_textures = false;
    if (game.core.graphics.window)
    {
        reload_textures = true;
        SDL_DestroyWindow(game.core.graphics.window);
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        game.core.log.file_write("SDL Video initialization failed.");
        return_value = false;
    }
    else
    {
        SDL_version compiled;
        SDL_version linked;
        SDL_VERSION(&compiled);
        SDL_GetVersion(&linked);
        game.core.log.file_write("SDL build version ->  ",compiled.major,".",compiled.minor,".",compiled.patch);
        game.core.log.file_write("SDL linked version -> ",linked.major,".",linked.minor,".",linked.patch);
        char SDL_VID_WIN_POS[] = "SDL_VIDEO_WINDOW_POS";
        char SDL_VID_CENTERD[] = "SDL_VIDEO_CENTERED=1";
        putenv(SDL_VID_WIN_POS);
        putenv(SDL_VID_CENTERD);
        int  glew_status    = 0;
        int  version_status = 0;
        game.core.graphics.render_GL.number_VAO  = 1;
        game.core.graphics.GL_major_version_number = 0;
        game.core.graphics.GL_minor_version_number = 0;
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,  RENDERER_CONTEXT_MAJOR);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,  RENDERER_CONTEXT_MINOR);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetSwapInterval(1);
        game.core.graphics.current_display      = 0;
        game.core.graphics.current_display_mode = 0;
        game.core.graphics.number_displays      = SDL_GetNumVideoDisplays();
        game.core.log.file_write("Number of attached displays -> ",game.core.graphics.number_displays);
        game.core.graphics.number_display_modes = SDL_GetNumDisplayModes(game.core.graphics.current_display);
        SDL_DisplayMode *mode = new SDL_DisplayMode[game.core.graphics.number_display_modes+1];
        game.core.log.file_write("Number of display modes -> ",game.core.graphics.number_display_modes);
        for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            if (SDL_GetDisplayMode(game.core.graphics.current_display,i,&mode[i]) == 0) game.core.log.file_write("Display mode - ",i," - x - ",mode[i].w," - y - ",mode[i].h," - refresh rate - ",mode[i].refresh_rate);
        }
        SDL_GetDisplayMode(game.core.graphics.current_display,game.core.graphics.current_display_mode,&mode[game.core.graphics.current_display_mode]);
        game.core.config.display_resolution_x    = mode[game.core.graphics.current_display_mode].w;
        game.core.config.display_resolution_y    = mode[game.core.graphics.current_display_mode].h;
        game.core.config.display_resolution_x    = 800;
        game.core.config.display_resolution_y    = 600;
        game.core.config.display_fullscreen      = false;
        if ((game.core.config.display_resolution_x < mode[game.core.graphics.number_display_modes-1].w) || (game.core.config.display_resolution_y < mode[game.core.graphics.number_display_modes-1].h))
        {
            game.core.config.display_resolution_x    = mode[game.core.graphics.number_display_modes-1].w;
            game.core.config.display_resolution_y    = mode[game.core.graphics.number_display_modes-1].h;
        }
        if ((game.core.config.display_resolution_x > mode[0].w) || (game.core.config.display_resolution_y > mode[0].h))
        {
            game.core.config.display_resolution_x    = mode[0].w;
            game.core.config.display_resolution_y    = mode[0].h;
            game.core.config.display_fullscreen      = true;
        }
        bool display_mode_found = false;
        if (game.core.debug)  for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            if ((game.core.config.display_resolution_x == mode[i].w) && (game.core.config.display_resolution_y == mode[i].h)) display_mode_found = true;
        }
        if (!display_mode_found)
        {
            game.core.config.display_resolution_x    = mode[0].w;
            game.core.config.display_resolution_y    = mode[0].h;
            game.core.config.display_fullscreen      = true;
        }
        if (game.core.config.display_fullscreen)
        {
            game.core.config.display_resolution_x    = mode[game.core.graphics.current_display_mode].w;
            game.core.config.display_resolution_y    = mode[game.core.graphics.current_display_mode].h;
        }
        game.core.config.font_base_resolution_x = mode[0].w;
        game.core.config.font_base_resolution_y = mode[0].h;
        game.core.config.font_scale_x = (float)game.core.config.display_resolution_x/(float)game.core.config.font_base_resolution_x;
        game.core.config.font_scale_y = (float)game.core.config.display_resolution_y/(float)game.core.config.font_base_resolution_y;
        game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
        game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
        game.core.log.file_write("Setting display mode - ",game.core.graphics.current_display_mode," - x - ",mode[game.core.graphics.current_display_mode].w," - y - ",mode[game.core.graphics.current_display_mode].h," - refresh rate - ",mode[game.core.graphics.current_display_mode].refresh_rate);
        game.core.log.file_write("Using pixel format - ",pixel_format_from_int(mode[game.core.graphics.current_display_mode].format));
        game.core.log.file_write("Creating window...");
        game.core.config.display_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
        if (game.core.config.display_fullscreen) game.core.config.display_flags |= SDL_WINDOW_FULLSCREEN;
        game.core.graphics.window = SDL_CreateWindow(game.core.application_name,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,game.core.config.display_resolution_x, game.core.config.display_resolution_y, game.core.config.display_flags);
        if (!game.core.graphics.window)
        {
            return_value = false;
            game.core.log.file_write("FAIL -> Unable to create window.");
        }
        else
        {
            game.core.log.file_write("Starting OpenGL...");
            game.core.graphics.context = SDL_GL_CreateContext(game.core.graphics.window);
            version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &game.core.graphics.GL_major_version_number);
            version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &game.core.graphics.GL_minor_version_number);
            if (version_status == 0)
            {
                game.core.log.file_write("OpenGl Version -> ",game.core.graphics.GL_major_version_number,".",game.core.graphics.GL_minor_version_number);
                if ((game.core.graphics.GL_major_version_number >= 3) && (game.core.graphics.GL_minor_version_number >= 2))
                {
                    glewExperimental = GL_TRUE;
                    glew_status = glewInit();
                    if(glew_status != GLEW_OK)
                    {
                        return_value = false;
                        game.core.log.file_write("FAIL -> Failed to initialize GLEW -> ",(const char*)glewGetErrorString(glew_status));
                    }
                    else
                    {
                        game.core.log.file_write("Initialized GLEW -> ",(const char*)glewGetErrorString(glew_status));
                        int i;
                        glGetIntegerv(GL_NUM_EXTENSIONS,&i);
                        game.core.log.file_write("Loaded OpenGL Extension count -> ",i);
                        if (game.core.debug) for (int j = 0; j < i; j++) game.core.log.file_write("Loaded OpenGL Extension -> ",(const char*)glGetStringi(GL_EXTENSIONS, j));
                        glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
                        // Vertex Shader
                        game.core.graphics.render_GL.vertexsource = game.core.file.filetobuf("data/shaders/aabb.vert");
                        game.core.graphics.render_GL.vertexshader = glCreateShader(GL_VERTEX_SHADER);
                        glShaderSource(game.core.graphics.render_GL.vertexshader, 1, (const GLchar**)&game.core.graphics.render_GL.vertexsource, 0);
                        glCompileShader(game.core.graphics.render_GL.vertexshader);
                        glGetShaderiv(game.core.graphics.render_GL.vertexshader, GL_COMPILE_STATUS, &game.core.graphics.render_GL.IsCompiled_VS);
                        if(game.core.graphics.render_GL.IsCompiled_VS == false)
                        {
                            int maxLength;
                            glGetShaderiv(game.core.graphics.render_GL.vertexshader, GL_INFO_LOG_LENGTH, &maxLength);
                            game.core.graphics.render_GL.vertexInfoLog = (char *)malloc(maxLength);
                            glGetShaderInfoLog(game.core.graphics.render_GL.vertexshader, maxLength, &maxLength, game.core.graphics.render_GL.vertexInfoLog);
                            game.core.log.file_write("FAIL -> Error loading Vertex Shader.");
                            free(game.core.graphics.render_GL.vertexInfoLog);
                        }
                        // Fragment Shader
                        game.core.graphics.render_GL.fragmentsource = game.core.file.filetobuf("data/shaders/aabb.frag");
                        game.core.graphics.render_GL.fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
                        glShaderSource(game.core.graphics.render_GL.fragmentshader, 1, (const GLchar**)&game.core.graphics.render_GL.fragmentsource, 0);
                        glCompileShader(game.core.graphics.render_GL.fragmentshader);
                        glGetShaderiv(game.core.graphics.render_GL.fragmentshader, GL_COMPILE_STATUS, &game.core.graphics.render_GL.IsCompiled_FS);
                        if(game.core.graphics.render_GL.IsCompiled_FS == false)
                        {
                            int maxLength;
                            glGetShaderiv(game.core.graphics.render_GL.fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);
                            game.core.graphics.render_GL.fragmentInfoLog = (char *)malloc(maxLength);
                            glGetShaderInfoLog(game.core.graphics.render_GL.fragmentshader, maxLength, &maxLength, game.core.graphics.render_GL.fragmentInfoLog);
                            game.core.log.file_write("FAIL -> Error loading Fragment Shader.");
                            free(game.core.graphics.render_GL.fragmentInfoLog);
                        }
                        // Shader Program
                        game.core.graphics.render_GL.shaderprogram = glCreateProgram();
                        glAttachShader(game.core.graphics.render_GL.shaderprogram, game.core.graphics.render_GL.vertexshader);
                        glAttachShader(game.core.graphics.render_GL.shaderprogram, game.core.graphics.render_GL.fragmentshader);
                        glBindAttribLocation(game.core.graphics.render_GL.shaderprogram, 0, "in_Position");
                        glBindAttribLocation(game.core.graphics.render_GL.shaderprogram, 1, "in_Color");
                        glLinkProgram(game.core.graphics.render_GL.shaderprogram);
                        glGetProgramiv(game.core.graphics.render_GL.shaderprogram, GL_LINK_STATUS, (int *)&game.core.graphics.render_GL.IsLinked);
                        if(game.core.graphics.render_GL.IsLinked == false)
                        {
                            int maxLength;
                            glGetProgramiv(game.core.graphics.render_GL.shaderprogram, GL_INFO_LOG_LENGTH, &maxLength);
                            game.core.graphics.render_GL.shaderProgramInfoLog = (char *)malloc(maxLength);
                            glGetProgramInfoLog(game.core.graphics.render_GL.shaderprogram, maxLength, &maxLength, game.core.graphics.render_GL.shaderProgramInfoLog);
                            game.core.log.file_write("FAIL -> Shader program error.");
                            free(game.core.graphics.render_GL.shaderProgramInfoLog);
                        }
                        glUseProgram(game.core.graphics.render_GL.shaderprogram);

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
                        game.core.graphics.render_GL.object_vao = object_1;
                    }
                }
            }
            else
            {
                return_value = false;
                game.core.log.file_write("FAIL -> Unable to set OpenGl Version -> ",game.core.graphics.GL_major_version_number,".",game.core.graphics.GL_minor_version_number);
            }
        }
    }
    if (reload_textures) game.texture_manager.reload_textures();
    return (return_value);
};

bool GL_deinit(void)
{
    glUseProgram(0);
    glDetachShader(game.core.graphics.render_GL.shaderprogram, game.core.graphics.render_GL.vertexshader);
    glDetachShader(game.core.graphics.render_GL.shaderprogram, game.core.graphics.render_GL.fragmentshader);
    glDeleteProgram(game.core.graphics.render_GL.shaderprogram);
    glDeleteShader(game.core.graphics.render_GL.vertexshader);
    glDeleteShader(game.core.graphics.render_GL.fragmentshader);
    if (game.core.graphics.render_GL.number_VAO > 0)
    {
        for (int i = 0; i < game.core.graphics.render_GL.number_VAO; i++)
        {
            glDisableVertexAttribArray(i);
        }
        if (game.core.graphics.render_GL.object_vao->number_of_vbo > 0) glDeleteBuffers(game.core.graphics.render_GL.object_vao->number_of_vbo, game.core.graphics.render_GL.object_vao->vbo_data);
        if (game.core.graphics.render_GL.number_VAO > 0) glDeleteVertexArrays(game.core.graphics.render_GL.number_VAO, &game.core.graphics.render_GL.object_vao->vao_data);
    }
    free(game.core.graphics.render_GL.vertexsource);
    free(game.core.graphics.render_GL.fragmentsource);
    return(true);
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
    glBindVertexArray(game.core.graphics.render_GL.object_vao->vao_data);
    glDrawArrays( GL_TRIANGLE_FAN, 0, game.core.graphics.render_GL.object_vao->number_of_vertex);
    SDL_GL_SwapWindow(game.core.graphics.window);
};
