/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
#include <SDL2/SDL.h>
//#include <physfs.h>
#include "core/misc.hpp"

extern game_class    game;

Uint32                   colorkey;
SDL_Surface             *application_icon_surface;

// --------------------------------------------------------------------------------------------------------------------------
// | Main()
// --------------------------------------------------------------------------------------------------------------------------
extern "C" int main(int argc, char** argv)
{
    game.core.application_name = "Frost and Flame V0.24 - www.physhexgames.co.nr";
    game.core.application_icon = "data/icon.bmp";
    game.core.log.file_set("frost_and_flame.log");
    game.core.log.file_clear();
    game.core.log.file_write("# ",game.core.application_name," #");
    game.core.log.file_write("# ---------------------------------------------- #");
    game.core.log.file_write(" ");
    game.core.log.file_write("Initializing PhysicsFS file system....");
    //PHYSFS_init(argv[0]);
    //PHYSFS_addToSearchPath("data.fnf", 1);
    game.core.log.file_write("Loading configuration...");
    game.core.config.set_defaults();
    game.core.config.file_set("frost_and_flame.cfg");
    game.core.config.file_header = game.core.application_name;
    game.core.config.file_load();
    game.core.log.file_write("Processing command line switches...");
    game.command_line.process(argc,argv);
    game.core.log.file_write("Loading language file -> data/configuration/languages/"+game.core.config.language+".txt");
    game.language.load("data/configuration/languages/"+game.core.config.language+".txt");
// --------------------------------------------------------------------------------------------------------------------------
// | Application initialization
// --------------------------------------------------------------------------------------------------------------------------
//  --- graphics ---
    game.core.log.file_write("Starting graphics subsystem...");
    if (!game.core.graphics.init_sdl())
    {
        game.core.log.file_write("Loading default configuration...");
        game.core.config.set_defaults();
                game.core.log.file_write("Starting default graphics configuration...");
            if (!game.core.graphics.init_sdl())
            {
                game.core.log.file_write("terminating game...");
                game.state = STATE_QUIT;
            }
    }
    game.core.log.file_write("Starting OpenGL...");
    game.core.graphics.init_gl(game.core.config.display_resolution_x,game.core.config.display_resolution_y);
    application_icon_surface = SDL_LoadBMP(game.core.application_icon);
    SDL_SetWindowIcon(game.core.window_pointer, application_icon_surface);
    SDL_FreeSurface(application_icon_surface);
    SDL_ShowCursor(SDL_DISABLE);
    SDL_Init(SDL_INIT_EVENTS);
//  --- audio ---
    game.core.log.file_write("Starting sound system...");
    SDL_Init(SDL_INIT_AUDIO);
    Mix_AllocateChannels(game.core.config.audio_channels);
    Mix_OpenAudio(game.core.config.audio_rate, AUDIO_S16, 2, game.core.config.audio_buffers);
    Mix_Volume(-1,game.core.config.audio_volume_sound);
    Mix_VolumeMusic(game.core.config.audio_volume_music);
//  --- joysticks ---
    game.core.log.file_write("Initializing joystick system...");
    SDL_Init(SDL_INIT_JOYSTICK);
    SDL_Init(SDL_INIT_HAPTIC);
    SDL_Init(SDL_INIT_GAMECONTROLLER);
    //SDL_Joystick *joystick;
    //SDL_JoystickEventState(SDL_ENABLE);
    //joystick = SDL_JoystickOpen(0);
//  --- font ---
    game.core.log.file_write("Initializing font system...");
    TTF_Init();
//  --- resources ---
    game.loading_screen.display("data/loading_screen.png");
    game.core.log.file_write("Loading resources....");
    game.UI_manager.cursor.normal_arrow = game.texture_manager.add_texture("data/textures/UI/cursors/default.png");
    game.music_manager.current = game.music_manager.add_music("data/music/menu_00.s3m");
//  --- miscellaneous ---
    game.core.log.file_write("Seeding random...");
    seed_rand();
    game.core.log.file_write("Initializing UI system...");
    game.UI_manager.setup();
    game.core.log.file_write("Initializing game system...");
    game.init();
    game.core.log.file_write("Initializing event handlers...");
    events_init();
    game.core.log.file_write("Starting Game...");
    game.core.log.file_write(" ");
    game.core.log.file_write("# ---------------------------------------------- #");
    game.core.log.file_write(" ");
    SDL_Init(SDL_INIT_TIMER);
    game.core.timer.start();
    game.core.last_ticks = game.core.timer.getticks();
// --------------------------------------------------------------------------------------------------------------------------
// | Main application loop
// --------------------------------------------------------------------------------------------------------------------------
    while (game.state != STATE_QUIT)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        events_process();
        switch (game.state)
        {
            case STATE_MENU:// initial state of the game, only the main menu is active, not the game.
                if (game.music_manager.next_track)
                {
                    game.music_manager.play(game.music_manager.current);
                    game.music_manager.next_track = false;
                }
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) game.UI_manager.process();
                //if (game.menu.event == 65535) game.state = STATE_QUIT;
                if (game.core.io.key_escape)  game.state = STATE_QUIT;
                game.core.background.draw();
                game.UI_manager.render();
            break;
            case STATE_GAME:// game active, menus can be utilized in game, but the game will stay in this state.
                if (game.core.process_ready) game.process();
                if (game.core.process_ready) game.UI_manager.process();
                //if (game.event == 65535) game.state = STATE_QUIT;
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
        game.texture_manager.draw(game.UI_manager.cursor.normal_arrow,false,game.core.io.mouse_x+0.012f,game.core.io.mouse_y-0.018f,0.001f,0.04f,0.04f,345.0f);
        SDL_GL_SwapWindow(game.core.window_pointer);
    }
// --------------------------------------------------------------------------------------------------------------------------
// | Application terminated, cleanup and free resources etc...
// --------------------------------------------------------------------------------------------------------------------------
    game.core.log.file_write(" ");
    game.core.log.file_write("# ---------------------------------------------- #");
    game.core.log.file_write(" ");
    game.core.log.file_write("Font    count -> ", game.font_manager.number_of_fonts);
    game.core.log.file_write("Music   count -> ", game.music_manager.number_of_music);
    game.core.log.file_write("Sound   count -> ", game.sound_manager.number_of_sounds);
    game.core.log.file_write("Texture count -> ", game.texture_manager.number_of_textures);
    game.core.log.file_write(" ");
    game.core.log.file_write("# ---------------------------------------------- #");
    game.core.log.file_write(" ");
    game.core.log.file_write("Saving configuration...");
    game.core.config.file_clear();
    game.core.config.file_save();
    game.core.log.file_write("Shutting down...");
    //PHYSFS_deinit();
    SDL_Quit();
    return(0);
};


