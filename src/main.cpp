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
#include "misc.hpp"
#include "main.hpp"
#include "menu_system.hpp"
#include "game.hpp"

extern game_type         game;

const char App_Name[] = ("Frost and Flame V0.03 - www.physhexgames.co.nr");
const char App_Icon[] = ("data/textures/icon.bmp");

Uint32                   colorkey;
SDL_Surface             *App_Icon_Surface;


//----------------------------------- Main -------------------------------------
int main(int argc, char *argv[])
{
    std::locale::global( std::locale( "" ) );
    events_init();
    game.core.log.File_Set("Frost_And_Flame.log");
    game.core.log.File_Clear();
    game.core.log.File_Write("----------------------------------------------");
    game.core.log.File_Write(App_Name);
    game.core.log.File_Write("----------------------------------------------\n");
    game.core.log.File_Write("Starting up!");
    game.core.log.File_Write("");
    game.core.log.File_Write("----------------------------------------------\n");
    game.core.config.File_Set("Frost_And_Flame.cfg");
    game.core.config.Set_Defaults();
    game.core.log.File_Write("Loading config...");
    game.core.config.File_Set("Frost_And_Flame.cfg");
    game.core.config.File_Read();
    game.core.log.File_Write("Loading language file -> data/configuration/languages/"+game.core.config.language+".txt");
    game.language.load("data/configuration/languages/"+game.core.config.language+".txt");
//----------------------------------- SDL Video --------------------------------
    game.core.log.File_Write("Starting SDL...");
    putenv("SDL_VIDEO_WINDOW_POS");
    putenv("SDL_VIDEO_CENTERED=1");
    getenv("SDL_VIDEO_WINDOW_POS");
    getenv("SDL_VIDEO_CENTERED");
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
    game.core.log.File_Write("Starting OpenGL...");
    if (game.core.config.Display_Fullscreen) SDL_SetVideoMode(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution,game.core.config.Display_BPS,SDL_OPENGL | SDL_FULLSCREEN);
    else SDL_SetVideoMode(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution,game.core.config.Display_BPS,SDL_OPENGL/* | SDL_NOFRAME/* | SDL_FULLSCREEN */);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    App_Icon_Surface = SDL_LoadBMP(App_Icon);
    colorkey = SDL_MapRGB(App_Icon_Surface->format, 255, 0, 255);
    SDL_SetColorKey(App_Icon_Surface, SDL_SRCCOLORKEY, colorkey);
    SDL_WM_SetIcon(App_Icon_Surface,NULL);
    SDL_WM_SetCaption(App_Name, 0);
    SDL_ShowCursor(SDL_DISABLE);
//----------------------------------- SDL Audio --------------------------------
    game.core.log.File_Write("Starting sound system...");
    SDL_Init(SDL_INIT_AUDIO);
    Mix_AllocateChannels(game.core.config.Audio_Channels);
    Mix_OpenAudio(game.core.config.Audio_Rate, AUDIO_S16, 2, game.core.config.Audio_Buffers);
    Mix_Volume(-1,game.core.config.Audio_Sound_Volume);
    Mix_VolumeMusic(game.core.config.Audio_Music_Volume);
    game.core.log.File_Write("Initializing joystick system...");
    SDL_Init(SDL_INIT_JOYSTICK);
    SDL_Joystick *joystick;
    SDL_JoystickEventState(SDL_ENABLE);
    joystick = SDL_JoystickOpen(0);
    game.core.log.File_Write("Seeding random...");
    seed_rand();
    game.core.log.File_Write("Initializing game system...");
    init_game(false);
    game.core.log.File_Write("Initializing OpenGL...");
    game.core.graphics.init_gl(game.core.config.Display_X_Resolution,game.core.config.Display_Y_Resolution);
    game.core.log.File_Write("Initializing font system...");
    TTF_Init();
    game.core.log.File_Write("Loading resources...");
    loading_screen_display("data/textures/loading_screen.png");
    load_resources();
    game.core.log.File_Write("Initializing menu system...");
    init_menu();
    init_game(false);
    game.core.log.File_Write("Starting game.core...");
    game.core.log.File_Write("----------------------------------------------\n");
//----------------------------------- Main loop --------------------------------
    game.core.timer.start();
    game.core.LastTicks = game.core.timer.getticks();
    for(int quit = 0; !quit;)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        events_process();
        if (game.core.status_quit_active) quit = 1;
        if (!quit)
        {
            game.core.config.process(false);
            proc_textures();
//****************************************** MENU *****************************************
            if ((game.core.menu_active) && (!game.core.game_active))
            {
                if (game.core.music_next_track)
                {
                    game.music.menu_00.play();
                    game.core.music_next_track = false;
                }
                diplay_menu ();
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) process_menu();
            }
//****************************************** GAME *****************************************
            if (game.core.game_active)
            {
                if (game.core.process_ready) process_game();
                display_game();
            }
//*********************************** Game paused *****************************************
            if (game.core.game_paused)
            {
                if (game.core.music_next_track)
                {
                    game.core.music_next_track = false;
                    //game.music.level_pd.play();
                }
                game.core.menu_level = 11;
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) process_menu();
                display_game();
                diplay_menu ();
             }
//*********************************** PLAYER DEATH SCREEN *****************************************
            if (game.core.pdie_active)
            {
                if (game.core.music_next_track)
                {
                    game.core.music_next_track = false;
                    //game.music.level_pd.play();
                }
                diplay_menu ();
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) process_menu();
                if (!game.core.pdie_active)  init_game(true);
            }
//******************************* PLAYER NEXT LEVEL SCREEN *************************************
            if (game.core.nlvl_active)
            {
                if (game.core.music_next_track)
                {
                    game.core.music_next_track = false;
                    //game.music.level_nl.play();
                }
                game.core.menu_level = 9;
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) process_menu();
                diplay_menu ();
            }
//******************************* OUTRO SCREEN *************************************************
         if (game.core.outr_active)
            {
                if (game.core.music_next_track)
                {
                    game.core.music_next_track = false;
                    //game.music.outro_00.play();
                }
                game.core.menu_level = 10;
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) process_menu();
                diplay_menu ();
            }
//---------------------------- code for end of main loop -----------------------
            game.core.FPS = (game.core.timer.getticks() - game.core.LastTicks);
            if ((game.core.timer.getticks() - game.core.LastTicks) >= 1000/90)
            {
                game.core.LastTicks = game.core.timer.getticks();
                game.core.process_ready = true;
            }
            else game.core.process_ready = false;
            game.texture.cursor.draw(false,game.core.io.mouse_x+0.012f,game.core.io.mouse_y-0.018f,0.001f,0.04f,0.04f,345.0f);
            SDL_GL_SwapBuffers();
        }
    }
//----------------------------------- Exit -------------------------------------
    game.core.log.File_Write("----------------------------------------------");
    game.core.log.File_Write("Shutting down...");
    game.core.log.File_Write("Saving configuration...");
    game.core.config.File_Set("Frost_And_Flame.cfg");
    game.core.config.File_Clear();
    game.core.config.File_Write();
    game.core.log.File_Write("SDL shutting down...");
    SDL_Quit();
    game.core.log.File_Write("----------------------------------------------\n");
    return(0);
}
