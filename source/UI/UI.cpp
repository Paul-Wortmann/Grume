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

#include "UI.hpp"
#include "menu_main.hpp"
#include "../game.hpp"

extern game_class         game;

//------------------------------------------------------------------------------------------------------------------------

void UI_class::UI_setup(void)
{
    //--- create the desired number of windows and setup the UID stack---
    game.window_manager.create_windows(6);
    //--- register the windows in the windows manager stack ---
    game.window_manager.register_window(MENU_MAIN_UID);
    game.window_manager.register_window(MENU_GAME_NEW_UID);
    game.window_manager.register_window(MENU_GAME_LOAD_UID);
    game.window_manager.register_window(MENU_GAME_SAVE_UID);
    game.window_manager.register_window(MENU_OPTIONS_UID);
    //--- populate windows with data. ---
    setup_menu_main(MENU_MAIN_UID);
    setup_menu_game_new(MENU_GAME_NEW_UID);
    setup_menu_game_load(MENU_GAME_LOAD_UID);
    setup_menu_game_save(MENU_GAME_SAVE_UID);
    setup_menu_options(MENU_OPTIONS_UID);
    //--- Enable windows. ---
    game.window_manager.window_enable(MENU_MAIN_UID);
    //--- Set the main menu as the default active window. ---
    game.window_manager.set_window_active(MENU_MAIN_UID);
};

void UI_class::UI_process(void) // Process events generated buy the windows in the list
{
    if (game.window_manager.number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < game.window_manager.number_of_windows; window_count++)
        {
            if(game.window_manager.window_stack[window_count].enabled)
            {
                switch(game.window_manager.window_stack[window_count].UID)
                {
                    case MENU_MAIN_UID:
                        process_menu_main();
                    break;
                    case MENU_GAME_NEW_UID:
                        process_menu_game_new();
                    break;
                    case MENU_GAME_LOAD_UID:
                        process_menu_game_load();
                    break;
                    case MENU_GAME_SAVE_UID:
                        process_menu_game_save();
                    break;
                    case MENU_OPTIONS_UID:
                        process_menu_options();
                    break;
                }
            }
        }
    }
}
