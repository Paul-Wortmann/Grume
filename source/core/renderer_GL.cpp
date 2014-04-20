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
    /*
    bool reload_textures = false;
    if (game.core.window_pointer)
    {
        reload_textures = true;
        SDL_DestroyWindow(game.core.window_pointer);
    }
    char SDL_VID_WIN_POS[] = "SDL_VIDEO_WINDOW_POS";
    char SDL_VID_CENTERD[] = "SDL_VIDEO_CENTERED=1";
    game.core.log.file_write("Initializing graphics subsystem...");
    putenv(SDL_VID_WIN_POS);
    putenv(SDL_VID_CENTERD);
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        game.core.log.file_write("Video initialization failed.");
        return_value = false;
    }
*/








    bool return_value   = true;
    int  glew_status    = 0;
    int  version_status = 0;
    game.core.graphics.number_VAO  = 1;
    game.core.graphics.major_version_number = 0;
    game.core.graphics.minor_version_number = 0;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,  RENDERER_CONTEXT_MAJOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,  RENDERER_CONTEXT_MINOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetSwapInterval(1);
    game.core.graphics.current_display      = 0;
    game.core.graphics.current_display_mode = 0;
    game.core.graphics.number_displays      = SDL_GetNumVideoDisplays();
    std::cout << "Number of attached displays -> " << game.core.graphics.number_displays << std::endl;
    game.core.graphics.number_display_modes = SDL_GetNumDisplayModes(game.core.graphics.current_display);
    SDL_DisplayMode *mode = new SDL_DisplayMode[game.core.graphics.number_display_modes+1];
    std::cout << "Number of display modes -> " << game.core.graphics.number_display_modes << std::endl;
    for (int i = 0; i < game.core.graphics.number_display_modes; i++)
    {
        if (SDL_GetDisplayMode(game.core.graphics.current_display,i,&mode[i]) == 0) std::cout << "Display mode - " << i << " - x - " << mode[i].w << " - y - " << mode[i].h << " - refresh rate - " << mode[i].refresh_rate << std::endl;
    }
    SDL_GetDisplayMode(game.core.graphics.current_display,game.core.graphics.current_display_mode,&mode[game.core.graphics.current_display_mode]);
    game.core.graphics.window_x    = mode[game.core.graphics.current_display_mode].w;
    game.core.graphics.window_y    = mode[game.core.graphics.current_display_mode].h;
    game.core.graphics.window_x    = 800;
    game.core.graphics.window_y    = 600;
    std::cout << "Setting display mode - " << game.core.graphics.current_display_mode << " - x - " << mode[game.core.graphics.current_display_mode].w << " - y - " << mode[game.core.graphics.current_display_mode].h << " - refresh rate - " << mode[game.core.graphics.current_display_mode].refresh_rate << std::endl;
    std::cout << "Using pixel format - " << pixel_format_from_int(mode[game.core.graphics.current_display_mode].format) << std::endl;
    std::cout << "Creating window..." << std::endl;
    game.core.graphics.window = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, game.core.graphics.window_x, game.core.graphics.window_y, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
    if (!game.core.graphics.window)
    {
        return_value = false;
        std::cout << "FAIL -> Unable to create window." << std::endl;
    }
    else
    {
        std::cout << "Starting OpenGL..." << std::endl;
        game.core.graphics.context = SDL_GL_CreateContext(game.core.graphics.window);
        version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &game.core.graphics.major_version_number);
        version_status += SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &game.core.graphics.minor_version_number);
        if (version_status == 0)
        {
            std::cout << "OpenGl Version -> " << game.core.graphics.major_version_number << "." << game.core.graphics.minor_version_number << std::endl;
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
                game.core.graphics.vertexsource = game.core.file.filetobuf("data/shaders/aabb.vert");
                game.core.graphics.vertexshader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(game.core.graphics.vertexshader, 1, (const GLchar**)&game.core.graphics.vertexsource, 0);
                glCompileShader(game.core.graphics.vertexshader);
                glGetShaderiv(game.core.graphics.vertexshader, GL_COMPILE_STATUS, &game.core.graphics.IsCompiled_VS);
                if(game.core.graphics.IsCompiled_VS == false)
                {
                    int maxLength;
                    glGetShaderiv(game.core.graphics.vertexshader, GL_INFO_LOG_LENGTH, &maxLength);
                    game.core.graphics.vertexInfoLog = (char *)malloc(maxLength);
                    glGetShaderInfoLog(game.core.graphics.vertexshader, maxLength, &maxLength, game.core.graphics.vertexInfoLog);
                    std::cout << "FAIL -> Error loading Vertex Shader." << std::endl;
                    free(game.core.graphics.vertexInfoLog);
                }
                // Fragment Shader
                game.core.graphics.fragmentsource = game.core.file.filetobuf("data/shaders/aabb.frag");
                game.core.graphics.fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(game.core.graphics.fragmentshader, 1, (const GLchar**)&game.core.graphics.fragmentsource, 0);
                glCompileShader(game.core.graphics.fragmentshader);
                glGetShaderiv(game.core.graphics.fragmentshader, GL_COMPILE_STATUS, &game.core.graphics.IsCompiled_FS);
                if(game.core.graphics.IsCompiled_FS == false)
                {
                    int maxLength;
                    glGetShaderiv(game.core.graphics.fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);
                    game.core.graphics.fragmentInfoLog = (char *)malloc(maxLength);
                    glGetShaderInfoLog(game.core.graphics.fragmentshader, maxLength, &maxLength, game.core.graphics.fragmentInfoLog);
                    std::cout << "FAIL -> Error loading Fragment Shader." << std::endl;
                    free(game.core.graphics.fragmentInfoLog);
                }
                // Shader Program
                game.core.graphics.shaderprogram = glCreateProgram();
                glAttachShader(game.core.graphics.shaderprogram, game.core.graphics.vertexshader);
                glAttachShader(game.core.graphics.shaderprogram, game.core.graphics.fragmentshader);
                glBindAttribLocation(game.core.graphics.shaderprogram, 0, "in_Position");
                glBindAttribLocation(game.core.graphics.shaderprogram, 1, "in_Color");
                glLinkProgram(game.core.graphics.shaderprogram);
                glGetProgramiv(game.core.graphics.shaderprogram, GL_LINK_STATUS, (int *)&game.core.graphics.IsLinked);
                if(game.core.graphics.IsLinked == false)
                {
                    int maxLength;
                    glGetProgramiv(game.core.graphics.shaderprogram, GL_INFO_LOG_LENGTH, &maxLength);
                    game.core.graphics.shaderProgramInfoLog = (char *)malloc(maxLength);
                    glGetProgramInfoLog(game.core.graphics.shaderprogram, maxLength, &maxLength, game.core.graphics.shaderProgramInfoLog);
                    std::cout << "FAIL -> Shader program error." << std::endl;
                    free(game.core.graphics.shaderProgramInfoLog);
                }
                glUseProgram(game.core.graphics.shaderprogram);

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
                game.core.graphics.object_vao = object_1;
            }
        }
        else
        {
            return_value = false;
            std::cout << "FAIL -> Unable to set OpenGl Version -> " << game.core.graphics.major_version_number << "." << game.core.graphics.minor_version_number << std::endl;
        }
    }
    bool reload_textures = false;
    if (reload_textures) game.texture_manager.reload_textures();
    return (return_value);
};

bool GL_deinit(void)
{
    glUseProgram(0);
    glDetachShader(game.core.graphics.shaderprogram, game.core.graphics.vertexshader);
    glDetachShader(game.core.graphics.shaderprogram, game.core.graphics.fragmentshader);
    glDeleteProgram(game.core.graphics.shaderprogram);
    glDeleteShader(game.core.graphics.vertexshader);
    glDeleteShader(game.core.graphics.fragmentshader);
    if (game.core.graphics.number_VAO > 0)
    {
        for (int i = 0; i < game.core.graphics.number_VAO; i++)
        {
            glDisableVertexAttribArray(i);
        }
        if (game.core.graphics.object_vao->number_of_vbo > 0) glDeleteBuffers(game.core.graphics.object_vao->number_of_vbo, game.core.graphics.object_vao->vbo_data);
        if (game.core.graphics.number_VAO > 0) glDeleteVertexArrays(game.core.graphics.number_VAO, &game.core.graphics.object_vao->vao_data);
    }
    free(game.core.graphics.vertexsource);
    free(game.core.graphics.fragmentsource);
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
    glBindVertexArray(game.core.graphics.object_vao->vao_data);
    glDrawArrays( GL_TRIANGLE_FAN, 0, game.core.graphics.object_vao->number_of_vertex);
    SDL_GL_SwapWindow(game.core.graphics.window);
};



/*
void graphics_class::init_gl (int x_res, int y_res)
{
    glViewport(0, 0,x_res,y_res);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    //--------------------------------------------------------------------------------------------------------------------
	// OpenGL Lighting Setup
	glEnable(GL_LIGHTING);
    float global_ambient[] = { 4.0f, 4.0f, 4.0f, 4.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	glEnable(GL_LIGHT0);
	float ambientLight0[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	float diffuseLight0[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specularLight0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float position0[]      = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT,  ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glLightfv(GL_LIGHT0, GL_POSITION, position0);
    // Position and direction (spotlight)
	//glEnable(GL_LIGHT1);
    //float posLight1[]     = {  0.0f,  0.0f, -1.0f,  1.0f };
    //float spotDirection[] = {  0.0f,  0.0f, 1.0f };
	//float ambientLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float diffuseLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float specularLight1[] = { 1.0f, 0.5f, 0.5f, 1.0f };
    //glLightfv( GL_LIGHT1, GL_POSITION, posLight1 );
    //glLightf ( GL_LIGHT1, GL_SPOT_CUTOFF, 60.0F );
    //glLightfv( GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection );
	//glLightfv( GL_LIGHT1, GL_AMBIENT,  ambientLight1);
	//glLightfv( GL_LIGHT1, GL_DIFFUSE,  diffuseLight1);
	//glLightfv( GL_LIGHT1, GL_SPECULAR, specularLight1);
    //glLightf ( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f );
	//glEnable(GL_LIGHT1);
	//float ambientLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float diffuseLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float specularLight1[] = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float position1[]      = { 1.5f, 1.0f, 2.0f, 1.0f };
	//glLightfv(GL_LIGHT1, GL_AMBIENT,  ambientLight1);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE,  diffuseLight1);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	//glLightfv(GL_LIGHT1, GL_POSITION, position1);



    glDisable(GL_DEPTH_TEST);
}


bool graphics_class::init_sdl (void)
{
    bool reload_textures = false;
    if (game.core.window_pointer)
    {
        reload_textures = true;
        SDL_DestroyWindow(game.core.window_pointer);
    }
    char SDL_VID_WIN_POS[] = "SDL_VIDEO_WINDOW_POS";
    char SDL_VID_CENTERD[] = "SDL_VIDEO_CENTERED=1";
    bool return_value = true;
    game.core.log.file_write("Initializing graphics subsystem...");
    putenv(SDL_VID_WIN_POS);
    putenv(SDL_VID_CENTERD);
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        game.core.log.file_write("Video initialization failed.");
        return_value = false;
    }
    //game.core.config.display_info = SDL_GetVideoInfo( );
    //if(!game.core.config.display_info)
    //{
    //    game.core.log.file_write("Video query failed.");
    //    return_value = false;
    //}
    //game.core.config.display_bpp    = game.core.config.display_info->vfmt->BitsPerPixel;
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,  RENDERER_CONTEXT_MAJOR);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,  RENDERER_CONTEXT_MINOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetSwapInterval(1);
    game.core.config.display_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
    if (game.core.config.display_fullscreen) game.core.config.display_flags |= SDL_WINDOW_FULLSCREEN;
    game.core.window_pointer = SDL_CreateWindow(game.core.application_name,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,game.core.config.display_resolution_x, game.core.config.display_resolution_y, game.core.config.display_flags);

    game.core.glcontext = SDL_GL_CreateContext(game.core.window_pointer);
    if (!game.core.window_pointer)
    {
        game.core.log.file_write("Video mode set failed.");
        return_value = false;
    }
    if (reload_textures) game.texture_manager.reload_textures();
    return (return_value);
};

*/

bool GL_init_old(void)
{
    bool reload_textures = false;
    if (game.core.graphics.window)
    {
        reload_textures = true;
        SDL_DestroyWindow(game.core.graphics.window);
    }
    char SDL_VID_WIN_POS[] = "SDL_VIDEO_WINDOW_POS";
    char SDL_VID_CENTERD[] = "SDL_VIDEO_CENTERED=1";
    bool return_value = true;
    game.core.log.file_write("Initializing graphics subsystem...");
    putenv(SDL_VID_WIN_POS);
    putenv(SDL_VID_CENTERD);
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        game.core.log.file_write("Video initialization failed.");
        return_value = false;
    }
    //game.core.config.display_info = SDL_GetVideoInfo( );
    //if(!game.core.config.display_info)
    //{
    //    game.core.log.file_write("Video query failed.");
    //    return_value = false;
    //}
    //game.core.config.display_bpp    = game.core.config.display_info->vfmt->BitsPerPixel;
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,  RENDERER_CONTEXT_MAJOR);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,  RENDERER_CONTEXT_MINOR);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetSwapInterval(1);
    game.core.config.display_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
    if (game.core.config.display_fullscreen) game.core.config.display_flags |= SDL_WINDOW_FULLSCREEN;
    game.core.graphics.window = SDL_CreateWindow(game.core.application_name,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,game.core.config.display_resolution_x, game.core.config.display_resolution_y, game.core.config.display_flags);

    game.core.graphics.context = SDL_GL_CreateContext(game.core.graphics.window);
    if (!game.core.graphics.window)
    {
        game.core.log.file_write("Video mode set failed.");
        return_value = false;
    }
    if (reload_textures) game.texture_manager.reload_textures();
    glViewport(0, 0,game.core.config.display_resolution_x,game.core.config.display_resolution_y);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    //--------------------------------------------------------------------------------------------------------------------
	// OpenGL Lighting Setup
	glEnable(GL_LIGHTING);
    float global_ambient[] = { 4.0f, 4.0f, 4.0f, 4.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	glEnable(GL_LIGHT0);
	float ambientLight0[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	float diffuseLight0[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specularLight0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float position0[]      = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT,  ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glLightfv(GL_LIGHT0, GL_POSITION, position0);
    // Position and direction (spotlight)
	//glEnable(GL_LIGHT1);
    //float posLight1[]     = {  0.0f,  0.0f, -1.0f,  1.0f };
    //float spotDirection[] = {  0.0f,  0.0f, 1.0f };
	//float ambientLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float diffuseLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float specularLight1[] = { 1.0f, 0.5f, 0.5f, 1.0f };
    //glLightfv( GL_LIGHT1, GL_POSITION, posLight1 );
    //glLightf ( GL_LIGHT1, GL_SPOT_CUTOFF, 60.0F );
    //glLightfv( GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection );
	//glLightfv( GL_LIGHT1, GL_AMBIENT,  ambientLight1);
	//glLightfv( GL_LIGHT1, GL_DIFFUSE,  diffuseLight1);
	//glLightfv( GL_LIGHT1, GL_SPECULAR, specularLight1);
    //glLightf ( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f );
	//glEnable(GL_LIGHT1);
	//float ambientLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float diffuseLight1[]  = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float specularLight1[] = { 1.0f, 0.5f, 0.5f, 1.0f };
	//float position1[]      = { 1.5f, 1.0f, 2.0f, 1.0f };
	//glLightfv(GL_LIGHT1, GL_AMBIENT,  ambientLight1);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE,  diffuseLight1);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	//glLightfv(GL_LIGHT1, GL_POSITION, position1);



    glDisable(GL_DEPTH_TEST);
}
