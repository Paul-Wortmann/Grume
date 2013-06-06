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

#include "UI.hpp"
#include "menu_main.hpp"
#include "../game.hpp"

extern game_class         game;

//------------------------------------------------------------------------------------------------------------------------

void UI_class::UI_setup(void)
{
    //--- create the desired number of windows and setup the UID stack---
    game.window_manager.create_windows(12);
    //--- register the windows in the windows manager stack ---
    game.window_manager.window_register(MENU_MAIN_UID);
    game.window_manager.window_register(MENU_GAME_NEW_UID);
    game.window_manager.window_register(MENU_GAME_LOAD_UID);
    game.window_manager.window_register(MENU_GAME_SAVE_UID);
    game.window_manager.window_register(MENU_OPTIONS_UID);
    game.window_manager.window_register(PCPROFILE_UID);
    game.window_manager.window_register(ACTIONBAR_UID);
    game.window_manager.window_register(CHARACTER_UID);
    game.window_manager.window_register(EQUIPMENT_UID);
    game.window_manager.window_register(INVENTORY_UID);
    game.window_manager.window_register(QUEST_LOG_UID);
    game.window_manager.window_register(SKILLBOOK_UID);
    //--- populate windows with data. ---
    setup_menu_main(MENU_MAIN_UID);
    setup_menu_game_new(MENU_GAME_NEW_UID);
    setup_menu_game_load(MENU_GAME_LOAD_UID);
    setup_menu_game_save(MENU_GAME_SAVE_UID);
    setup_menu_options(MENU_OPTIONS_UID);
    setup_player_profile(PCPROFILE_UID);
    setup_action_bar(ACTIONBAR_UID);
    setup_character_window(CHARACTER_UID);
    setup_equipment_window(EQUIPMENT_UID);
    setup_inventory_window(INVENTORY_UID);
    setup_quest_log_window(QUEST_LOG_UID);
    setup_skillbook_window(SKILLBOOK_UID);
    //--- Enable windows. ---
    game.window_manager.window_enable(MENU_MAIN_UID);
    //--- Set the main menu as the default active window. ---
    game.window_manager.window_set_active(MENU_MAIN_UID);
    // --- Allow specific textures to be rotated ----
    texture_type *temp_pointer;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    temp_pointer->rotate_able = true;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    temp_pointer->rotate_able = true;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    temp_pointer->rotate_able = true;
};

void UI_class::UI_process(void) // Process events generated buy the windows in the list
{
    game.window_manager.process();
    if (game.window_manager.number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < game.window_manager.number_of_windows; window_count++)
        {
            if(game.window_manager.window[game.window_manager.window_stack[window_count]].enabled)
            {
                if(game.window_manager.event.id == EVENT_NONE)
                {
                    switch(game.window_manager.window[game.window_manager.window_stack[window_count]].UID)
                    {
                        case MENU_MAIN_UID:
                            process_menu_main(game.window_manager.window_stack[window_count]);
                        break;
                        case MENU_GAME_NEW_UID:
                            process_menu_game_new(game.window_manager.window_stack[window_count]);
                        break;
                        case MENU_GAME_LOAD_UID:
                            process_menu_game_load(game.window_manager.window_stack[window_count]);
                        break;
                        case MENU_GAME_SAVE_UID:
                            process_menu_game_save(game.window_manager.window_stack[window_count]);
                        break;
                        case MENU_OPTIONS_UID:
                            process_menu_options(game.window_manager.window_stack[window_count]);
                        break;
                        case PCPROFILE_UID:
                            process_player_profile(game.window_manager.window_stack[window_count]);
                        break;
                        case ACTIONBAR_UID:
                            process_action_bar(game.window_manager.window_stack[window_count]);
                        break;
                        case CHARACTER_UID:
                            process_character_window(game.window_manager.window_stack[window_count]);
                        break;
                        case EQUIPMENT_UID:
                            process_equipment_window(game.window_manager.window_stack[window_count]);
                        break;
                        case INVENTORY_UID:
                            process_inventory_window(game.window_manager.window_stack[window_count]);
                        break;
                        case QUEST_LOG_UID:
                            process_quest_log_window(game.window_manager.window_stack[window_count]);
                        break;
                        case SKILLBOOK_UID:
                            process_skillbook_window(game.window_manager.window_stack[window_count]);
                        break;
                        default:
                            game.core.log.file_write("Unable to process UID - ",game.window_manager.window[game.window_manager.window_stack[window_count]].UID);
                        break;
                    }
                }
            }
        }
    }
    switch (game.window_manager.event.id)
    {
        case EVENT_WINDOW_STACK_SORT: //window has requested a window stack sort;
            game.window_manager.window_stack_sort();
            game.window_manager.event.id = EVENT_NONE;
        break;
        default:
            game.window_manager.event.id = EVENT_NONE;
        break;
    }
};

