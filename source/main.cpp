/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "game.hpp"
#include <SDL/SDL.h>
#include "core/misc.hpp"
#include "menu_system.hpp"

extern game_class game;

const char application_name[] = ("Frost and Flame V0.09 - www.physhexgames.co.nr");
const char application_icon[] = ("data/icon.bmp");

Uint32                   colorkey;
SDL_Surface             *application_icon_surface;

// --------------------------------------------------------------------------------------------------------------------------
// | Main()
// --------------------------------------------------------------------------------------------------------------------------
extern "C" int main(int argc, char** argv)
{
    game.core.log.file_set("frost_and_flame.log");
    game.core.log.file_clear();
    game.core.log.file_write("# ",application_name," #");
    game.core.log.file_write("# ---------------------------------------------- #");
    game.core.log.file_write(" ");
    game.core.log.file_write("Loading configuration...");
    game.core.config.set_defaults();
    game.core.config.file_set("frost_and_flame.cfg");
    game.core.config.file_header = application_name;
    game.core.config.file_load();
    game.core.log.file_write("Loading language file -> data/configuration/languages/"+game.core.config.language+".txt");
    game.language.load("data/configuration/languages/"+game.core.config.language+".txt");
// --------------------------------------------------------------------------------------------------------------------------
// | Application initialization
// --------------------------------------------------------------------------------------------------------------------------
//  --- graphics ---
    game.core.log.file_write("Starting graphics subsystem...");
    putenv("SDL_VIDEO_WINDOW_POS");
    putenv("SDL_VIDEO_CENTERED=1");
    getenv("SDL_VIDEO_WINDOW_POS");
    getenv("SDL_VIDEO_CENTERED");
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        game.core.log.file_write("Video initialization failed");
        game.state = STATE_QUIT;
    }
    game.core.config.display_info = SDL_GetVideoInfo( );
    if(!game.core.config.display_info)
    {
        game.core.log.file_write("Video query failed, terminating game...");
        game.state = STATE_QUIT;
    }
    game.core.config.display_bpp    = game.core.config.display_info->vfmt->BitsPerPixel;
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    if (game.core.config.display_fullscreen) game.core.config.display_flags = SDL_OPENGL | SDL_FULLSCREEN;
    else game.core.config.display_flags = SDL_OPENGL;
    if(SDL_SetVideoMode( game.core.config.display_resolution_x, game.core.config.display_resolution_y, game.core.config.display_bpp, game.core.config.display_flags ) == 0 )
    {
        game.core.log.file_write("Video mode set failed, terminating game...");
        game.state = STATE_QUIT;
    }
    application_icon_surface = SDL_LoadBMP(application_icon);
    colorkey = SDL_MapRGB(application_icon_surface->format, 255, 0, 255);
    SDL_SetColorKey(application_icon_surface, SDL_SRCCOLORKEY, colorkey);
    SDL_WM_SetIcon(application_icon_surface,NULL);
    SDL_WM_SetCaption(application_name, 0);
    SDL_ShowCursor(SDL_DISABLE);
    SDL_Init(SDL_INIT_EVENTTHREAD);
//  --- audio ---
    game.core.log.file_write("Starting sound system...");
    SDL_Init(SDL_INIT_AUDIO);
    Mix_AllocateChannels(game.core.config.audio_channels);
    Mix_OpenAudio(game.core.config.audio_rate, AUDIO_S16, 2, game.core.config.audio_buffers);
    Mix_Volume(-1,game.core.config.audio_volume_sound);
    Mix_VolumeMusic(game.core.config.audio_volume_music);
    game.core.log.file_write("Initializing joystick system...");
    SDL_Init(SDL_INIT_JOYSTICK);
    SDL_Joystick *joystick;
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
    game.core.log.file_write("Seeding random...");
    seed_rand();
    game.core.log.file_write("Initializing font system...");
    TTF_Init();
    game.core.log.file_write("Starting OpenGL...");
    game.core.graphics.init_gl(game.core.config.display_resolution_x,game.core.config.display_resolution_y);
    game.resource.load_default();
    game.resource.loading_screen_display("data/loading_screen.png");
    game.core.log.file_write("Loading resources....");
    game.resource.load_UI();
    game.resource.load_items();
    game.resource.load_portraits();
    game.resource.load_particles();
    game.resource.load_spells();
    game.resource.load_tilesets();
    game.resource.load_generic_textures();
    game.resource.load_heightmaps();
    game.resource.load_maps_2D();
    game.resource.load_maps_3D();
    game.resource.load_3D_models();
    game.resource.load_test_data();
    game.resource.write_log_file_count();
    game.core.log.file_write("Initializing game system...");
    game.init();
    game.core.log.file_write("Initializing menu system...");
    game.core.log.file_write("Initializing event handlers...");
    events_init();
    game.core.log.file_write("Starting Game...");
    game.core.log.file_write(" ");
    game.core.log.file_write("# ---------------------------------------------- #");
    game.core.log.file_write(" ");

// --------------------------------------------------------------------------------------------------------------------------
// | Main application loop
// --------------------------------------------------------------------------------------------------------------------------
    game.core.timer.start();
    game.core.last_ticks = game.core.timer.getticks();
    while (game.state != STATE_QUIT)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        events_process();
        switch (game.state)
        {
            case STATE_MENU:// initial state of the game, only the main menu is active, not the game.
                if (game.core.music_next_track)
                {
                    game.resource.music.menu_00.play();
                    game.core.music_next_track = false;
                }
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) game.menu.process();
                if (game.menu.event == 65535) game.state = STATE_QUIT;
                game.core.background.draw();
                game.menu.render();
            break;
            case STATE_GAME:// game active, menus can be utilized in game, but the game will stay in this state.
                if (game.core.process_ready) game.process();
                if (game.event == 65535) game.state = STATE_QUIT;
                game.render();
            break;
            case STATE_QUIT:// game has received a quit event, do nothing...
                game.state = STATE_QUIT;
            break;
            default:
                game.core.log.file_write("Game out of state - terminating");
                game.state = STATE_QUIT;
            break;
        }
        game.core.FPS = (game.core.timer.getticks() - game.core.last_ticks);
        if ((game.core.timer.getticks() - game.core.last_ticks) >= 1000/90)
        {
            game.core.last_ticks = game.core.timer.getticks();
            game.core.process_ready = true;
        }
        else game.core.process_ready = false;
        game.resource.texture.cursor.draw(false,game.core.io.mouse_x+0.012f,game.core.io.mouse_y-0.018f,0.001f,0.04f,0.04f,345.0f);
        SDL_GL_SwapBuffers();
    }
// --------------------------------------------------------------------------------------------------------------------------
// | Application terminated, cleanup and free resources etc...
// --------------------------------------------------------------------------------------------------------------------------
    game.core.log.file_write(" ");
    game.core.log.file_write("# ---------------------------------------------- #");
    game.core.log.file_write(" ");
    game.core.log.file_write("Saving configuration...");
    game.core.config.file_clear();
    game.core.config.file_save();
    game.core.log.file_write("Shutting down...");
    SDL_Quit();
    return(true);
};

