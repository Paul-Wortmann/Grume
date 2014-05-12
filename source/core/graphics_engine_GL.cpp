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
    if (game.core.graphics.window)
    {
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
        for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            if ((SDL_GetDisplayMode(game.core.graphics.current_display,i,&game.core.graphics.display_mode[i]) == 0)&&(game.core.debug)) game.core.log.file_write("Display mode - ",i," - x - ",game.core.graphics.display_mode[i].w," - y - ",game.core.graphics.display_mode[i].h," - refresh rate - ",game.core.graphics.display_mode[i].refresh_rate);
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
        game.core.graphics.window = SDL_CreateWindow(game.core.application_name.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,game.core.config.display_resolution_x, game.core.config.display_resolution_y, game.core.config.display_flags);
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
    SDL_GL_DeleteContext(game.core.graphics.context);
    SDL_DestroyWindow(game.core.graphics.window);
    return (return_value);
};

bool GL_render(void)
{
    bool return_value = true;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    if (game.core.graphics.vao_manager.number_of_vaos > 0)
    {
        vao_type* temp_pointer = game.core.graphics.vao_manager.root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                glBindVertexArray(temp_pointer->data.vao_data);
                glDrawArrays( GL_TRIANGLE_FAN, 0, temp_pointer->data.number_of_vertex);
                temp_pointer = temp_pointer->next;
            }
        }
    }
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
                if ((last_w == game.core.config.display_resolution_x) && (last_h == game.core.config.display_resolution_y)) game.core.config.display_resolution = i;
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
