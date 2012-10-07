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

#include "window_manager.hpp"
#include "../game.hpp"

extern game_class         game;

//--------------------------------------------------------- Window Manager Stack Class -------------------------------------------------------------------
window_manager_stack_class::window_manager_stack_class(void)
{
    window_manager_stack_class::active        = false;
    window_manager_stack_class::enabled       = false;
    window_manager_stack_class::UID           = -1;
    window_manager_stack_class::window_number = -1;
}

//--------------------------------------------------------- Window Manager Class -------------------------------------------------------------------

window_manager_class::window_manager_class(void)
{
    window_manager_class::number_of_windows    = 0;
    window_manager_class::windows_list_created = false;
}

window_manager_class::~window_manager_class(void)
{

}

bool  window_manager_class::mouse_over_window(float wx, float wy, float ww, float wh)
{
    float mx = window_manager_class::mouse_x;
    float my = window_manager_class::mouse_y;
    if ((mx > (wx-(ww/2))) && (mx < (wx+(ww/2))) && (my > (wy-(wh/2))) && (my < (wy+(wh/2)))) return(true);
    else return(false);
};

void window_manager_class::sort_window_stack(void)
{
    bool temp_stack_item_active;
    bool temp_stack_item_enabled;
    int  temp_stack_item_UID;
    int  temp_stack_item_window_number;
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        // place the active window on the top of the list
        for (int window_count = window_manager_class::number_of_windows; window_count > 0; window_count--)
        {
            if(window_count > 0)
            {
                if(window_manager_class::window_stack[window_count].active)
                {
                    //if active window found below top of stack move it up...
                    temp_stack_item_active        = window_manager_class::window_stack[window_count-1].active;
                    temp_stack_item_enabled       = window_manager_class::window_stack[window_count-1].enabled;
                    temp_stack_item_UID           = window_manager_class::window_stack[window_count-1].UID;
                    temp_stack_item_window_number = window_manager_class::window_stack[window_count-1].window_number;
                    window_manager_class::window_stack[window_count-1].active        = window_manager_class::window_stack[window_count].active;
                    window_manager_class::window_stack[window_count-1].enabled       = window_manager_class::window_stack[window_count].enabled;
                    window_manager_class::window_stack[window_count-1].UID           = window_manager_class::window_stack[window_count].UID;
                    window_manager_class::window_stack[window_count-1].window_number = window_manager_class::window_stack[window_count].window_number;
                    window_manager_class::window_stack[window_count].active          = temp_stack_item_active;
                    window_manager_class::window_stack[window_count].enabled         = temp_stack_item_enabled;
                    window_manager_class::window_stack[window_count].UID             = temp_stack_item_UID;
                    window_manager_class::window_stack[window_count].window_number   = temp_stack_item_window_number;
                }
            }
        }
    }
};

void window_manager_class::create_windows(int number_windows)
{
    if (!window_manager_class::windows_list_created)
    {
        // create the windows
        window_manager_class::number_of_windows = number_windows;
        window_manager_class::window = new window_class[window_manager_class::number_of_windows+1];
        // create the UID stack
        window_manager_class::window_stack = new window_manager_stack_class[window_manager_class::number_of_windows+1];
        window_manager_class::windows_list_created = true;
    }
 }

int  window_manager_class::get_window_number(int UID)
{
    int return_value = 0;
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID) return_value = window_manager_class::window_stack[window_count].window_number;
        }
    }
    return(return_value);
};

void window_manager_class::set_active_window(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID)
            {
                window_manager_class::window_stack[window_count].active = true;
                window_manager_class::window[window_count].active       = true;
            }
            else
            {
                window_manager_class::window_stack[window_count].active = false;
                window_manager_class::window[window_count].active       = false;
            }
        }
    }
    window_manager_class::sort_window_stack();
};

int  window_manager_class::get_active_window(void)
{
    int return_value = 0;
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if(window_manager_class::window_stack[window_count].active) return_value = window_manager_class::window_stack[window_count].UID;
        }
    }
    return(return_value);
};

//---------------
int  window_manager_class::register_window(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == -1)
            {
                window_manager_class::window_stack[window_count].active        = false;
                window_manager_class::window_stack[window_count].enabled       = true;
                window_manager_class::window_stack[window_count].UID           = UID;
                window_manager_class::window_stack[window_count].window_number = window_count;
                window_manager_class::window[window_count].UID                 = UID;
            }
        }
    }
}

int  window_manager_class::register_window(int UID_minimum, int UID_maximum)
{
    int   new_UID   = -1;
    int   temp_UID  = UID_minimum;
    bool  UID_found = false;
    while ((new_UID == -1) and (temp_UID < UID_maximum))
    {
        UID_found = false;
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window[window_count].UID == temp_UID) UID_found = true;
        }
        if (!UID_found) new_UID = temp_UID;
        else temp_UID++;
    }
    if(new_UID > 0) return(window_manager_class::register_window(new_UID));
    else return(-1);
}

void window_manager_class::de_register_window(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID)
            {
                window_manager_class::window_stack[window_count].active        = false;
                window_manager_class::window_stack[window_count].enabled       = false;
                window_manager_class::window_stack[window_count].UID           = -1;
                window_manager_class::window_stack[window_count].window_number = -1;
            }
        }
    }
}

void window_manager_class::process(void)
{
    /*
    // add code to handle window overlap processing protection etc...
    //possibly drag between windows code?

    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        bool mouse_over_current_window = false;
        for (int window_count = 1; window_count <= window_manager_class::number_of_windows; window_count++)
        {
            //determine if the mouse is over a menu, taking into consideration positional ordering.
            //first check if mouse is over a window
            mouse_over_current_window = window_manager_class::mouse_in_quadrangle(window_manager_class::window[window_count].position_x,
                                                                                  window_manager_class::window[window_count].position_y,
                                                                                  window_manager_class::window[window_count].size_x,
                                                                                  window_manager_class::window[window_count].size_y);
            //check that mouse is not over any windows higher up on the list
            if (window_count == 1) //This window is already on the top of the list
            {
                window_manager_class::window[window_count].mouse_over = true;
            }
            else
            {
                window_manager_class::window[window_count].mouse_over = true;
                for (int window_count_temp = 1; window_count_temp <= window_count; window_count_temp++) // only check windows higher up on the list
                {
                    //only set mouse over if mouse over and not mouse over higher windows on the list.
                    if(window_manager_class::window[window_count_temp].mouse_over) window_manager_class::window[window_count].mouse_over = false;
                }
            }
        }

    }
    */
    for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++) // first check if UID is on list
    {
        if (window_manager_class::window[window_count].active) window_manager_class::window[window_count].process();
    }
}

void window_manager_class::render(void)
{
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = window_manager_class::number_of_windows; window_count > 0; window_count--)
        {
            //error here somewhere....
            if (window_manager_class::window_stack[window_count].enabled)
            {
                game.core.log.file_write("Attempting to render window -> ",window_count);
                window_manager_class::window[window_count].render();
            }
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------

void setup_windows(void)
{
    //--- create the desired number of windows and setup the UID stack---
    game.window_manager.create_windows(5);
    //--- register the windows in the windows manager stack ---
    game.window_manager.register_window(MENU_MAIN_UID);
    game.window_manager.register_window(MENU_GAME_NEW_UID);
    game.window_manager.register_window(MENU_GAME_LOAD_UID);
    game.window_manager.register_window(MENU_GAME_SAVE_UID);
    //--- populate windows with data. ---
    setup_menu_main(MENU_MAIN_UID);
    setup_menu_game_new(MENU_GAME_NEW_UID);
    setup_menu_game_load(MENU_GAME_LOAD_UID);
    setup_menu_game_save(MENU_GAME_SAVE_UID);
    //--- Set the main menu as the default active window. ---
    game.window_manager.set_active_window(MENU_MAIN_UID);
};

void process_windows(void) // Process events generated buy the window in the list
{
}

















