/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <locale>
#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_net.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include "core/core.hpp"
#include "load_resources.hpp"
#include "misc.hpp"
#include "main.hpp"
#include "menu_system.hpp"
#include "game.hpp"

extern sound_type        sound;
extern music_type        music;
extern texture_type      texture;
extern menu_type         menu;
extern game_type         game_o;
extern game_class        game;
extern TTF_Font         *font;
extern menu_class        pause_menu;
extern menu_class        game_over_menu;
extern menu_class        next_level_menu;
extern menu_class        outro_menu;

const char App_Name[] = ("Frost and Flame V0.00 - www.physhexgames.co.nr");
const char App_Icon[] = "data/icon.bmp"; fix this icon!!!

Uint32                   colorkey;
SDL_Surface             *App_Icon_Surface;


//----------------------------------- Main -------------------------------------
int main(int argc, char *argv[])
{
    std::locale::global( std::locale( "" ) );
    events_init();
    game.log.File_Set("Frost_And_Flame.log");
    game.log.File_Clear();

    game.log.File_Write("------------------------");
    game.log.File_Write("| Frost_And_Flame V1.0 |");
    game.log.File_Write("------------------------\n");
    game.log.File_Write("Starting up!");
    game.log.File_Write("");
    game.log.File_Write("------------------\n");
    game.config.File_Set("Frost_And_Flame.cfg");
    game.config.Set_Defaults();
    game.log.File_Write("Loading config...");
    game.config.File_Set("Frost_And_Flame.cfg");
    game.config.File_Read();
    game.log.File_Write("Loading language file -> data/configuration/languages/"+game.config.language+".txt");
    game_o.language.load("data/configuration/languages/"+game.config.language+".txt");
//----------------------------------- SDL Video --------------------------------
    game.log.File_Write("Starting SDL...");
    putenv("SDL_VIDEO_WINDOW_POS");
    putenv("SDL_VIDEO_CENTERED=1");
    getenv("SDL_VIDEO_WINDOW_POS");
    getenv("SDL_VIDEO_CENTERED");
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
    game.log.File_Write("Starting OpenGL...");
    if (game.config.Display_Fullscreen) SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
    else SDL_SetVideoMode(game.config.Display_X_Resolution,game.config.Display_Y_Resolution,game.config.Display_BPS,SDL_OPENGL/* | SDL_NOFRAME/* | SDL_FULLSCREEN */);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    App_Icon_Surface = SDL_LoadBMP(App_Icon);
    colorkey = SDL_MapRGB(App_Icon_Surface->format, 255, 0, 255);
    SDL_SetColorKey(App_Icon_Surface, SDL_SRCCOLORKEY, colorkey);
    SDL_WM_SetIcon(App_Icon_Surface,NULL);
    SDL_WM_SetCaption(App_Name, 0);
    SDL_ShowCursor(SDL_ENABLE);
//----------------------------------- SDL Audio --------------------------------
    game.log.File_Write("Starting sound system...");
    SDL_Init(SDL_INIT_AUDIO);
    Mix_AllocateChannels(game.config.Audio_Channels);
    Mix_OpenAudio(game.config.Audio_Rate, AUDIO_S16, 2, game.config.Audio_Buffers);
    Mix_Volume(-1,game.config.Audio_Sound_Volume);
    Mix_VolumeMusic(game.config.Audio_Music_Volume);
    game.log.File_Write("Initializing joystick / gamepad...");
    SDL_Init(SDL_INIT_JOYSTICK);
    SDL_Joystick *joystick;
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
    game.log.File_Write("Initializing game system...");
    init_game(false);
    game.log.File_Write("Initializing OpenGL...");
    game.graphics.init_gl(game.config.Display_X_Resolution,game.config.Display_Y_Resolution);
    game.log.File_Write("Seeding random...");
    seed_rand();
    game.log.File_Write("Initializing font...");
    TTF_Init();
    game.log.File_Write("Loading resources...");
    loading_screen_display("data/textures/loading_screen.png");
    load_resources();
    game.log.File_Write("Initializing menu system...");
    init_menu();
    init_game(false);
    game.log.File_Write("Starting game...");
    game.log.File_Write("---------------\n");
//----------------------------------- Main loop --------------------------------
    game.timer.start();
    game.LastTicks = game.timer.getticks();
    for(int quit = 0; !quit;)
    {
        game.config.process(false);
        proc_textures();
        events_process();
        if (game.status_quit_active) quit = 1;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//****************************************** MENU *****************************************
        if (game.menu_active)
        {
            if (game.music_next_track)
            {
                music.menu_00.play();
                game.music_next_track = false;
            }
            diplay_menu ();
            if (game.process_ready) game.background.process();
            if (game.process_ready) process_menu();
        }
//****************************************** GAME *****************************************
        if (game.game_active)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                if (game.music_track ==  0) music.menu_00.play();
            }
            game.game_resume = true;
            if (game.process_ready) process_game();
            display_game();
        if ((game.io.escape) && (game.process_ready))
        {
            sound.menu_select_00.play();
            game.music_next_track        = true;
            game.game_active             = false;
            game.menu_level              = 1;
            game.menu_active             = true;
            game.io.escape               = false;
            game.io.keyboard_delay_count = 0;
            game.config.menu_delay_count = 0;
            while (game.config.menu_delay_count < (game.config.menu_delay/2))
            {
                game.config.menu_delay_count++;
            }
        }

        if (game.io.pause)
        {
            //game_o.paused.spawn();
            game.game_paused = true;
            game.game_active = false;
            game.io.pause    = false;
            game.menu_level  = 11;
            SDL_WarpMouse(game.graphics.gl_to_res(pause_menu.get_button_x_pos(1),game.config.mouse_resolution_x),game.config.mouse_resolution_y-game.graphics.gl_to_res(pause_menu.get_button_y_pos(1),game.config.mouse_resolution_y));
        };
     }
//*********************************** Game paused *****************************************
        if (game.game_paused)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                //music.level_pd.play();
            }
            game.menu_level = 11;
            if (game.process_ready) game.background.process();
            if (game.process_ready) process_menu();
            display_game();
            diplay_menu ();
         }
//*********************************** PLAYER DEATH SCREEN *****************************************
        if (game.pdie_active)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                //music.level_pd.play();
            }
            diplay_menu ();
            if (game.process_ready) game.background.process();
            if (game.process_ready) process_menu();
            if (!game.pdie_active)  init_game(true);
        }
//******************************* PLAYER NEXT LEVEL SCREEN *************************************
        if (game.nlvl_active)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                //music.level_nl.play();
            }
            game.menu_level = 9;
            if (game.process_ready) game.background.process();
            if (game.process_ready) process_menu();
            diplay_menu ();
        }
//******************************* OUTRO SCREEN *************************************************
     if (game.outr_active)
        {
            if (game.music_next_track)
            {
                game.music_next_track = false;
                //music.outro_00.play();
            }
            game.menu_level = 10;
            if (game.process_ready) game.background.process();
            if (game.process_ready) process_menu();
            diplay_menu ();
        }
//---------------------------- code for end of main loop -----------------------
        game.FPS = (game.timer.getticks() - game.LastTicks);
        if ((game.timer.getticks() - game.LastTicks) >= 1000/90)
        {
            game.LastTicks = game.timer.getticks();
            game.process_ready = true;
        }
        else game.process_ready = false;
        SDL_GL_SwapBuffers();
    }
//----------------------------------- Exit -------------------------------------
    game.log.File_Write("Saving configuration...");
    game.config.File_Set("Frost_And_Flame.cfg");
    game.config.File_Clear();
    game.config.File_Write();
    game.log.File_Write("\n");
    game.log.File_Write("Shutting down...");
    game.log.File_Write("---------------\n");
    game.log.File_Write("Unloading fonts...");
    TTF_Quit();
    game.log.File_Write("Shutting down audio system...");
    Mix_CloseAudio();
    game.log.File_Write("SDL deinit...");
    SDL_Quit();
    return(0);
}

