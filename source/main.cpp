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
 * @date    2011-11-11
 */

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_opengl.h>
#include <physfs.h>
#include "core/core.hpp"
#include "core/misc.hpp"
#include "game/game.hpp"

#define APP_NAME_STRING   "Frost and Flame"
#define URL_NAME_STRING   "www.physhexgames.co.nr"
#define FNF_MAJOR_VERSION 0
#define FNF_MINOR_VERSION 31
#define FNF_PATCH_VERSION 1

extern game_class    game;

Uint32                   colorkey;
SDL_Surface*             application_icon_surface;

// --------------------------------------------------------------------------------------------------------------------------
// | Main()
// --------------------------------------------------------------------------------------------------------------------------
extern "C" int main(int argc, char** argv)
{
//  --- Application initialization ---
    game.core.debug = true;
    game.state = STATE_INIT;
    std::string temp_string  = APP_NAME_STRING;
                temp_string += " V"  + int_to_string(FNF_MAJOR_VERSION);
                temp_string += "."   + int_to_string(FNF_MINOR_VERSION);
                temp_string += "."   + int_to_string(FNF_PATCH_VERSION);
                temp_string += " - ";
                temp_string += URL_NAME_STRING;
    game.core.application_name = temp_string.c_str();
    game.core.application_icon = "data/icon.ico";
    game.core.log.set_file_name("frost_and_flame.log");
    game.core.log.clear_file();
    game.core.log.write("# ",game.core.application_name," #");
    game.core.log.write("# ---------------------------------------------- #");
    game.core.log.write(" ");
    game.core.log.write_time_stamp("Log file created: ");
    game.core.log.write("Initializing SDL...");
    int SDL_error = SDL_Init(SDL_INIT_EVERYTHING);
    if (SDL_error != 0) game.core.log.write("SDL initialization error: ",SDL_error);
    game.core.config.get_system_information();
    game.core.config.log_system_information();
    game.core.file.file_system_path("frost_and_flame.dat");
    game.core.file.file_system_init(argv);
    if (game.state == STATE_INIT)
    {
        game.core.log.write("Loading configuration...");
        game.core.config.set_defaults();
        game.core.config.file_set("frost_and_flame.cfg");
        game.core.config.file_load();
        game.core.log.write("Processing command line switches...");
        game.command_line.process(argc,argv);
        if (game.core.debug) game.core.log.write("Developer mode enabled.");
        game.language.load(game.core.config.language);
    }
//  --- graphics ---
    if (game.state == STATE_INIT)
    {
        game.core.log.write("Starting graphics subsystem...");
        game.core.graphics.renderer = RENDERER_GL1;
        game.core.graphics.init();
        game.core.graphics.build_mode_list();
        application_icon_surface = game.core.file.load_image(game.core.application_icon);
        SDL_SetWindowIcon(game.core.graphics.window, application_icon_surface);
        SDL_FreeSurface(application_icon_surface);
        SDL_ShowCursor(SDL_DISABLE);
        SDL_Init(SDL_INIT_EVENTS);
    }
//  --- audio ---
    if (game.state == STATE_INIT)
    {
        game.core.log.write("Starting sound system...");
        SDL_Init(SDL_INIT_AUDIO);
        game.music_manager.init();
        Mix_AllocateChannels(game.core.config.audio_channels);
        Mix_OpenAudio(game.core.config.audio_rate, MIX_DEFAULT_FORMAT, 2, game.core.config.audio_buffers);
        Mix_Volume(-1,game.core.config.audio_volume_sound);
        Mix_VolumeMusic(game.core.config.audio_volume_music);
    }
//  --- joysticks ---
    if (game.state == STATE_INIT)
    {
        game.core.log.write("Initializing joystick system...");
        SDL_Init(SDL_INIT_JOYSTICK);
        SDL_Init(SDL_INIT_HAPTIC);
        SDL_Init(SDL_INIT_GAMECONTROLLER);
        //SDL_Joystick *joystick;
        //SDL_JoystickEventState(SDL_ENABLE);
        //joystick = SDL_JoystickOpen(0);
    }
//  --- font ---
    if (game.state == STATE_INIT) game.font_manager.init();
//  --- resources ---
    if (game.state == STATE_INIT)
    {
        game.loading_screen.display("data/textures/loading_screens/loading_screen_main.png");
        game.core.log.write("Loading resources....");
    }
//  --- miscellaneous ---
    if (game.state == STATE_INIT)
    {
        game.core.log.write("Seeding random...");
        seed_rand();
        game.core.log.write("Initializing UI system...");
        game.UI_manager.setup();
        game.UI_manager.data.cursor.normal_arrow = game.texture_manager.add_texture("data/textures/UI/cursors/default.png");
    }
    if (game.state == STATE_INIT)
    {
        game.music_manager.current = game.music_manager.add_music("data/music/menu_00.s3m");
        game.core.log.write("Initializing game system...");
        game.init();
        game.core.log.write("Initializing event handlers...");
        events_init();
        game.core.log.write("Starting Game...");
        game.core.log.write("# ---------------------------------------------- #");
        game.core.log.write(" ");
        SDL_Init(SDL_INIT_TIMER);
        game.core.timer.start();
        game.core.last_ticks = game.core.timer.getticks();
    }
// --------------------------------------------------------------------------------------------------------------------------
// | Main application loop
// --------------------------------------------------------------------------------------------------------------------------

    // --- TEST ---
    if ((game.core.debug) && (game.state != STATE_QUIT))
    {
        if (game.music_manager.next_track)
        {
            //game.music_manager.play(game.music_manager.current);
            game.music_manager.next_track = false;
        }
        update_player_profile  (game.UI_manager.UI_form_get(UID_PCPROFILE));
        update_character_window(game.UI_manager.UI_form_get(UID_CHARACTER));
        game.music_manager.next_track = true;
        game.UI_manager.UI_form_transition(UID_MENU_GAME_NEW,UID_MENU_MAIN);
        game.UI_manager.UI_form_disable(UID_MENU_MAIN);
        game.core.game_menu_active = false;
        game.UI_manager.UI_form_disable(UID_EQUIPMENT);
        game.core.equipment_active = false;
        game.UI_manager.UI_form_disable(UID_QUEST_LOG);
        game.core.quest_log_active = false;
        game.UI_manager.UI_form_disable(UID_CHARACTER);
        game.core.character_active = false;
        game.UI_manager.UI_form_disable(UID_INVENTORY);
        game.core.inventory_active = false;
        game.UI_manager.UI_form_disable(UID_SKILLBOOK);
        game.core.skillbook_active = false;
        game.UI_manager.UI_form_disable(UID_NPCVENDOR);
        game.core.npcvendor_active = false;
        game.UI_manager.UI_form_enable(UID_PCPROFILE);
        game.UI_manager.UI_form_enable(UID_ACTIONBAR);
    }
// --------------------------------------------------------------------------------------------------------------------------
    if (game.state == STATE_INIT)
    {
      if (game.core.debug) game.state = STATE_GAME;
      else game.state = STATE_MENU;
    }
    while (game.state != STATE_QUIT)
    {
        events_process();
        switch (game.state)
        {
            case STATE_MENU:
                if (game.music_manager.next_track)
                {
                    game.music_manager.play(game.music_manager.current);
                    game.music_manager.next_track = false;
                }
                if (game.core.process_ready) game.core.background.process();
                if (game.core.process_ready) game.UI_manager.process();
                if (game.core.event_manager.key_escape) game.state = STATE_QUIT;
            break;
            case STATE_GAME:
                if (game.core.process_ready) game.UI_manager.process();
                if (game.core.process_ready) game.process();
            break;
            case STATE_QUIT:
                game.state = STATE_QUIT;
            break;
            case STATE_INIT:
                game.core.log.write("Game out of state - STATE_INIT, setting to STATE_MENU");
                game.state = STATE_MENU;
            break;
            default:
                game.core.log.write("Game out of state - terminating");
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
        game.core.graphics.render();
    }
// --------------------------------------------------------------------------------------------------------------------------
// | Application terminated, cleanup and free resources etc...
// --------------------------------------------------------------------------------------------------------------------------
    game.core.log.write(" ");
    if (game.core.debug) game.core.log.write("# ---------------------------------------------- #");
    if (game.core.debug) game.core.log.write("Font    count -> ", game.font_manager.number_of_fonts);
    if (game.core.debug) game.core.log.write("Music   count -> ", game.music_manager.number_of_music);
    if (game.core.debug) game.core.log.write("Sound   count -> ", game.sound_manager.number_of_sounds);
    if (game.core.debug) game.core.log.write("Texture count -> ", game.texture_manager.number_of_textures);
    if (game.core.debug) game.core.log.write("Item    count -> ", game.item_manager.number_of_items);
    if (game.core.debug) game.core.log.write("Effect  count -> ", game.effect_manager.number_of_effects);
    game.core.log.write("# ---------------------------------------------- #");
    //if (game.core.debug) game.UI_manager.UI_form_position_log();
    //game.core.log.write("# ---------------------------------------------- #");
    game.core.log.write("Saving configuration...");
    game.core.config.file_clear();
    game.core.config.file_save();
    game.core.log.write("Shutting down...");
    game.core.graphics.deinit();
    game.font_manager.deinit();
    game.core.file.file_system_deinit();
    SDL_Quit();
    game.core.log.write_time_stamp("Game exited at: ");
    return(0);
};


