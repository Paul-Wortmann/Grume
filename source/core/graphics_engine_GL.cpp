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
#include "misc.hpp"

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
        #ifndef __MINGW32__
            char SDL_VID_WIN_POS[] = "SDL_VIDEO_WINDOW_POS";
            char SDL_VID_CENTERD[] = "SDL_VIDEO_CENTERED=1";
            putenv(SDL_VID_WIN_POS);
            putenv(SDL_VID_CENTERD);
        #endif
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
        game.core.graphics.display_mode = new SDL_DisplayMode[game.core.graphics.number_display_modes+1];
        game.core.log.file_write("Number of display modes -> ",game.core.graphics.number_display_modes);
        if (game.core.debug) for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            if (SDL_GetDisplayMode(game.core.graphics.current_display,i,&game.core.graphics.display_mode[i]) == 0) game.core.log.file_write("Display mode - ",i," - x - ",game.core.graphics.display_mode[i].w," - y - ",game.core.graphics.display_mode[i].h," - refresh rate - ",game.core.graphics.display_mode[i].refresh_rate);
        }
        SDL_GetDisplayMode(game.core.graphics.current_display,game.core.graphics.current_display_mode,&game.core.graphics.display_mode[game.core.graphics.current_display_mode]);
        if ((game.core.config.display_resolution_x < game.core.graphics.display_mode[game.core.graphics.number_display_modes-1].w) || (game.core.config.display_resolution_y < game.core.graphics.display_mode[game.core.graphics.number_display_modes-1].h))
        {
            game.core.config.display_resolution_x    = game.core.graphics.display_mode[game.core.graphics.number_display_modes-1].w;
            game.core.config.display_resolution_y    = game.core.graphics.display_mode[game.core.graphics.number_display_modes-1].h;
            game.core.graphics.current_display_mode  = game.core.graphics.number_display_modes-1;
        }
        if ((game.core.config.display_resolution_x > game.core.graphics.display_mode[0].w) || (game.core.config.display_resolution_y > game.core.graphics.display_mode[0].h))
        {
            game.core.config.display_resolution_x    = game.core.graphics.display_mode[0].w;
            game.core.config.display_resolution_y    = game.core.graphics.display_mode[0].h;
            game.core.graphics.current_display_mode  = 0;
            game.core.config.display_fullscreen      = true;
        }
        bool display_mode_found = false;
        for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            if ((game.core.config.display_resolution_x == game.core.graphics.display_mode[i].w) && (game.core.config.display_resolution_y == game.core.graphics.display_mode[i].h))
            {
                game.core.graphics.current_display_mode = i;
                display_mode_found                      = true;
            }
        }
        if (!display_mode_found)
        {
            game.core.config.display_resolution_x    = game.core.graphics.display_mode[0].w;
            game.core.config.display_resolution_y    = game.core.graphics.display_mode[0].h;
            game.core.graphics.current_display_mode  = 0;
            game.core.config.display_fullscreen      = true;
        }
        else
        {
            game.core.config.display_resolution_x    = game.core.graphics.display_mode[game.core.graphics.current_display_mode].w;
            game.core.config.display_resolution_y    = game.core.graphics.display_mode[game.core.graphics.current_display_mode].h;
        }
        if (game.core.config.display_fullscreen)
        {
            game.core.config.display_resolution_x    = game.core.graphics.display_mode[0].w;
            game.core.config.display_resolution_y    = game.core.graphics.display_mode[0].h;
        }
        game.core.config.font_base_resolution_x = game.core.graphics.display_mode[0].w;
        game.core.config.font_base_resolution_y = game.core.graphics.display_mode[0].h;
        game.core.config.font_scale_x = (float)game.core.config.display_resolution_x/(float)game.core.config.font_base_resolution_x;
        game.core.config.font_scale_y = (float)game.core.config.display_resolution_y/(float)game.core.config.font_base_resolution_y;
        game.core.config.mouse_resolution_x   = game.core.config.display_resolution_x;
        game.core.config.mouse_resolution_y   = game.core.config.display_resolution_y;
        game.core.log.file_write("Setting display mode - ",game.core.graphics.current_display_mode," - x - ",game.core.graphics.display_mode[game.core.graphics.current_display_mode].w," - y - ",game.core.graphics.display_mode[game.core.graphics.current_display_mode].h," - refresh rate - ",game.core.graphics.display_mode[game.core.graphics.current_display_mode].refresh_rate);
        game.core.log.file_write("Using pixel format - ",pixel_format_from_int(game.core.graphics.display_mode[game.core.graphics.current_display_mode].format));
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
            int  version_status = 0;
            version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &game.core.graphics.GL_major_version_number);
            version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &game.core.graphics.GL_minor_version_number);
            if (version_status == 0)
            {
                game.core.log.file_write("OpenGl Version -> ",game.core.graphics.GL_major_version_number,".",game.core.graphics.GL_minor_version_number);
                if ((game.core.graphics.GL_major_version_number >= 3) && (game.core.graphics.GL_minor_version_number >= 2))
                {
                    glewExperimental = GL_TRUE;
                    int glew_status = glewInit();
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
                        int shader_compile_status = 0;
                        GLchar *vertex_shader_file = game.core.file.load_file_to_buffer("data/shaders/aabb.vert");
                        game.core.graphics.render_GL.vertexshader = glCreateShader(GL_VERTEX_SHADER);
                        glShaderSource(game.core.graphics.render_GL.vertexshader, 1, (const GLchar**)&vertex_shader_file, 0);
                        glCompileShader(game.core.graphics.render_GL.vertexshader);
                        glGetShaderiv(game.core.graphics.render_GL.vertexshader, GL_COMPILE_STATUS, &shader_compile_status);
                        if (shader_compile_status != 1)
                        {
                            int maxLength;
                            glGetShaderiv(game.core.graphics.render_GL.vertexshader, GL_INFO_LOG_LENGTH, &maxLength);
                            char *vertex_info_Log = new char[maxLength];
                            glGetShaderInfoLog(game.core.graphics.render_GL.vertexshader, maxLength, &maxLength, vertex_info_Log);
                            game.core.log.file_write("FAIL -> Error loading Vertex Shader: ",vertex_info_Log);
                            delete [] vertex_info_Log;
                        }
                        // Fragment Shader
                        shader_compile_status = 0;
                        GLchar *fragment_shader_file = game.core.file.load_file_to_buffer("data/shaders/aabb.frag");
                        game.core.graphics.render_GL.fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
                        glShaderSource(game.core.graphics.render_GL.fragmentshader, 1, (const GLchar**)&fragment_shader_file, 0);
                        glCompileShader(game.core.graphics.render_GL.fragmentshader);
                        glGetShaderiv(game.core.graphics.render_GL.fragmentshader, GL_COMPILE_STATUS, &shader_compile_status);
                        if (shader_compile_status != 1)
                        {
                            int maxLength;
                            glGetShaderiv(game.core.graphics.render_GL.fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);
                            char *fragment_info_Log = new char[maxLength];
                            glGetShaderInfoLog(game.core.graphics.render_GL.fragmentshader, maxLength, &maxLength, fragment_info_Log);
                            game.core.log.file_write("FAIL -> Error loading Fragment Shader: ",fragment_info_Log);
                            delete [] fragment_info_Log;
                        }
                        // Shader Program
                        int shader_program_link_status = 0;
                        game.core.graphics.render_GL.shaderprogram = glCreateProgram();
                        glAttachShader(game.core.graphics.render_GL.shaderprogram, game.core.graphics.render_GL.vertexshader);
                        glAttachShader(game.core.graphics.render_GL.shaderprogram, game.core.graphics.render_GL.fragmentshader);
                        glBindAttribLocation(game.core.graphics.render_GL.shaderprogram, 0, "in_Position");
                        glBindAttribLocation(game.core.graphics.render_GL.shaderprogram, 1, "in_Color");
                        glLinkProgram(game.core.graphics.render_GL.shaderprogram);
                        glGetProgramiv(game.core.graphics.render_GL.shaderprogram, GL_LINK_STATUS, (int *)&shader_program_link_status);
                        if (shader_program_link_status != 1)
                        {
                            int maxLength;
                            glGetProgramiv(game.core.graphics.render_GL.shaderprogram, GL_INFO_LOG_LENGTH, &maxLength);
                            char *shader_program_info_Log = new char[maxLength];
                            glGetProgramInfoLog(game.core.graphics.render_GL.shaderprogram, maxLength, &maxLength, shader_program_info_Log);
                            game.core.log.file_write("FAIL -> Shader program error: ",shader_program_info_Log);
                            delete [] shader_program_info_Log;
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
    bool return_value = true;
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
    //delete game.core.graphics.render_GL.vertexsource;
    //delete game.core.graphics.render_GL.fragmentsource;
    return (return_value);
};

/*
bool GL_push_renderer_vbo(GL_object_struct &GL_object, GLuint &vao_id)
{
    bool return_value = true;

    return (return_value);
}
*/

bool GL_init_vao(GL_object_struct &GL_object)
{
    bool return_value = true;
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
    return (return_value);
};

bool GL_render(void)
{
    bool return_value = true;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glBindVertexArray(game.core.graphics.render_GL.object_vao->vao_data);
    glDrawArrays( GL_TRIANGLE_FAN, 0, game.core.graphics.render_GL.object_vao->number_of_vertex);
    SDL_GL_SwapWindow(game.core.graphics.window);
    return (return_value);
};

bool GL_build_mode_list(void)
{
    bool return_value = true;
    if (game.core.graphics.number_display_modes <= 0)
    {
        return_value = false;
    }
    else
    {
        if (game.core.debug) game.core.log.file_write("-----------------------------------------------------");
        if (game.core.debug)game.core.log.file_write("- Menu display list:                                -");
        if (game.core.debug)game.core.log.file_write("-----------------------------------------------------");
        game.core.graphics.menu_mode_length = 1;
        int list_position = 0;
        int last_w = game.core.graphics.display_mode[0].w;
        int last_h = game.core.graphics.display_mode[0].h;
        for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            if ((last_w != game.core.graphics.display_mode[i].w) || (last_h != game.core.graphics.display_mode[i].h))
            {
                last_w = game.core.graphics.display_mode[i].w;
                last_h = game.core.graphics.display_mode[i].h;
                game.core.graphics.menu_mode_length++;
            }
        }
        game.core.graphics.menu_mode_list = new int[game.core.graphics.menu_mode_length+1];
        for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            if ((last_w != game.core.graphics.display_mode[i].w) || (last_h != game.core.graphics.display_mode[i].h))
            {
                last_w = game.core.graphics.display_mode[i].w;
                last_h = game.core.graphics.display_mode[i].h;
                if (list_position < game.core.graphics.menu_mode_length)
                {
                    game.core.graphics.menu_mode_list[list_position] = i;
                    if (game.core.debug)game.core.log.file_write("Menu res - x - ",game.core.graphics.display_mode[i].w," - y - ",game.core.graphics.display_mode[i].h);
                }
                list_position++;
            }
        }
        if (game.core.debug)game.core.log.file_write("-----------------------------------------------------");
    }
    return(return_value);
};

std::string GL_get_display_mode(int mode_number)
{
    std::string padding_left  = "";
    std::string padding_right = "";
    if (mode_number > game.core.graphics.menu_mode_length) mode_number = game.core.graphics.menu_mode_length;
    mode_number = game.core.graphics.menu_mode_list[mode_number];
    if (game.core.graphics.display_mode[mode_number].w < 1000) padding_left  = " ";
    if (game.core.graphics.display_mode[mode_number].h < 1000) padding_right = " ";
    return(padding_left+int_to_string(game.core.graphics.display_mode[mode_number].w)+" X "+int_to_string(game.core.graphics.display_mode[mode_number].h)+padding_right);
};
