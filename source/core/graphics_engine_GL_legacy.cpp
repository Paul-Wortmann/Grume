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


#include "core.hpp"
#include "graphics_engine.hpp"
#include "graphics_engine_GL_legacy.hpp"
#include "../game/game.hpp"
#include "misc.hpp"

extern game_class game;

bool GL_legacy_init(void)
{
    bool return_value = true;
    if (game.core.graphics.window)
    {
        game.core.log.write("Closing previous window....");
        SDL_GL_DeleteContext(game.core.graphics.context);
        SDL_DestroyWindow(game.core.graphics.window);
    }
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        game.core.log.write("SDL Video initialization failed.");
        return_value = false;
    }
    else
    {
        game.core.log.write("SDL Video initialized correctly.");
        SDL_version compiled;
        SDL_version linked;
        SDL_VERSION(&compiled);
        SDL_GetVersion(&linked);
        game.core.log.write("SDL build version ->  ",compiled.major,".",compiled.minor,".",compiled.patch);
        game.core.log.write("SDL linked version -> ",linked.major,".",linked.minor,".",linked.patch);
        /*
        char SDL_VID_WIN_POS[] = "SDL_VIDEO_WINDOW_POS";
        char SDL_VID_CENTERD[] = "SDL_VIDEO_CENTERED=1";
        #ifndef WIN32
            putenv(SDL_VID_WIN_POS);
            putenv(SDL_VID_CENTERD);
        #endif
        */
        //game.core.config.display_info = SDL_GetVideoInfo( );
        //if(!game.core.config.display_info)
        //{
        //    game.core.log.write("Video query failed.");
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
        game.core.graphics.current_display      = 0;
        game.core.graphics.current_display_mode = 0;
        game.core.graphics.number_displays      = SDL_GetNumVideoDisplays();
        game.core.log.write("Number of attached displays -> ",game.core.graphics.number_displays);
        game.core.graphics.number_display_modes = SDL_GetNumDisplayModes(game.core.graphics.current_display);
        game.core.graphics.display_mode = new SDL_DisplayMode[game.core.graphics.number_display_modes+1];
        game.core.log.write("Number of display modes -> ",game.core.graphics.number_display_modes);
        for (int i = 0; i < game.core.graphics.number_display_modes; i++)
        {
            SDL_GetDisplayMode(game.core.graphics.current_display,i,&game.core.graphics.display_mode[i]);
            //if ((SDL_GetDisplayMode(game.core.graphics.current_display,i,&game.core.graphics.display_mode[i]) == 0)&&(game.core.debug)) game.core.log.write("Display mode - ",i," - x - ",game.core.graphics.display_mode[i].w," - y - ",game.core.graphics.display_mode[i].h," - refresh rate - ",game.core.graphics.display_mode[i].refresh_rate);
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
        game.core.log.write("Setting display mode - ",game.core.graphics.current_display_mode," - x - ",game.core.graphics.display_mode[game.core.graphics.current_display_mode].w," - y - ",game.core.graphics.display_mode[game.core.graphics.current_display_mode].h," - refresh rate - ",game.core.graphics.display_mode[game.core.graphics.current_display_mode].refresh_rate);
        game.core.log.write("Using pixel format - ",pixel_format_from_int(game.core.graphics.display_mode[game.core.graphics.current_display_mode].format));
        game.core.log.write("Creating window...");
        game.core.config.display_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
        if (game.core.config.display_fullscreen) game.core.config.display_flags |= SDL_WINDOW_FULLSCREEN;
        game.core.graphics.window = SDL_CreateWindow(game.core.application_name.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,game.core.config.display_resolution_x, game.core.config.display_resolution_y, game.core.config.display_flags);

        game.core.graphics.context = SDL_GL_CreateContext(game.core.graphics.window);
        if (!game.core.graphics.window)
        {
            game.core.log.write("Video mode set failed.");
            return_value = false;
        }
        else
        {
            game.core.graphics.gl_version_string                  = std::string((const char*)glGetString(GL_VERSION));
            game.core.graphics.gl_vendor_string                   = std::string((const char*)glGetString(GL_VENDOR));
            game.core.graphics.gl_renderer_string                 = std::string((const char*)glGetString(GL_RENDERER));
            game.core.graphics.gl_shading_language_version_string = std::string((const char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
            game.core.log.write("GL Driver Version           -> ",game.core.graphics.gl_version_string);
            game.core.log.write("GL Driver Vendor            -> ",game.core.graphics.gl_vendor_string);
            game.core.log.write("GL Renderer                 -> ",game.core.graphics.gl_renderer_string);
            game.core.log.write("GL Shading Language Version -> ",game.core.graphics.gl_shading_language_version_string);
            glGetIntegerv(GL_NUM_EXTENSIONS,&game.core.graphics.gl_extention_count);
            game.core.log.write("Loaded OpenGL Extension count -> ",game.core.graphics.gl_extention_count);
            /*
            game.core.graphics.gl_extention_names = new std::string[game.core.graphics.gl_extention_count+1];
            for (int j = 0; j < game.core.graphics.gl_extention_count; j++)
            {
                game.core.graphics.gl_extention_names[j] = (const char*)glGetStringi(GL_EXTENSIONS, j);
                if (game.core.debug) game.core.log.write("Loaded OpenGL Extension -> ",game.core.graphics.gl_extention_names[j]);
            }
            */
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
    }
    return(return_value);
}

bool GL_legacy_deinit(void)
{
    bool return_value = true;

    return(return_value);
};

bool GL_legacy_render(void)
{
    bool return_value = true;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    switch (game.state)
    {
        case STATE_MENU:
            game.core.background.draw();
            game.UI_manager.render();
        break;
        case STATE_GAME:
            game.render();
        break;
        default:
        break;
    }
    game.texture_manager.draw(game.UI_manager.data.cursor.normal_arrow,false,game.core.event_manager.mouse_x+0.012f,game.core.event_manager.mouse_y-0.018f,0.001f,0.04f,0.04f,0.0f);
    SDL_GL_SwapWindow(game.core.graphics.window);
    return(return_value);
};

bool GL_legacy_build_mode_list(void)
{
    bool debug_state = game.core.debug;
    game.core.debug = false;
    bool return_value = true;
    if (game.core.graphics.number_display_modes <= 0)
    {
        return_value = false;
    }
    else
    {
        if (game.core.debug) game.core.log.write("-----------------------------------------------------");
        if (game.core.debug)game.core.log.write("- Menu display list:                                -");
        if (game.core.debug)game.core.log.write("-----------------------------------------------------");
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
                    if (game.core.debug)game.core.log.write("Menu res - x - ",game.core.graphics.display_mode[i].w," - y - ",game.core.graphics.display_mode[i].h);
                }
                list_position++;
            }
        }
        if (game.core.debug)game.core.log.write("-----------------------------------------------------");
    }
    game.core.debug = debug_state;
    return(return_value);
};

std::string GL_legacy_get_display_mode(int mode_number)
{
    std::string padding_left  = "";
    std::string padding_right = "";
    if (mode_number > game.core.graphics.menu_mode_length) mode_number = game.core.graphics.menu_mode_length;
    mode_number = game.core.graphics.menu_mode_list[mode_number];
    if (game.core.graphics.display_mode[mode_number].w < 1000) padding_left  = " ";
    if (game.core.graphics.display_mode[mode_number].h < 1000) padding_right = " ";
    return(padding_left+int_to_string(game.core.graphics.display_mode[mode_number].w)+" X "+int_to_string(game.core.graphics.display_mode[mode_number].h)+padding_right);
};

