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

void window_manager_class::set_window_active(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID)
            {
                window_manager_class::window_stack[window_count].active = true;
                window_manager_class::window[window_manager_class::window_stack[window_count].window_number].active = true;
            }
            else
            {
                window_manager_class::window_stack[window_count].active = false;
                window_manager_class::window[window_manager_class::window_stack[window_count].window_number].active = false;
            }
        }
    }
    window_manager_class::sort_window_stack();
};

void window_manager_class::set_window_inactive(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID)
            {
                window_manager_class::window_stack[window_count].active = false;
                window_manager_class::window[window_manager_class::window_stack[window_count].window_number].active = false;
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

int  window_manager_class::register_window(int UID)
{
    bool window_added = false;
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if ((window_manager_class::window_stack[window_count].UID == -1) && (!window_added))
            {
                window_added = true;
                window_manager_class::window_stack[window_count].active        = false;
                window_manager_class::window_stack[window_count].enabled       = false;
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

void window_manager_class::window_enable(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID)
            {
                window_manager_class::window_stack[window_count].enabled       = true;
            }
        }
    }
};

void window_manager_class::window_disable(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID)
            {
                window_manager_class::window_stack[window_count].enabled       = false;
            }
        }
    }
};

void window_manager_class::window_set_pos(int UID_destination, int UID_source)
{
    int source_window      = window_manager_class::get_window_number(UID_source);
    int destination_window = window_manager_class::get_window_number(UID_destination);
    window_manager_class::window[destination_window].set_position(window_manager_class::window[source_window].position.x,window_manager_class::window[source_window].position.y);
};

void window_manager_class::mouse_reset(int UID)
{
    int window_number;
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window_stack[window_count].UID == UID)
            {
                window_number = window_manager_class::window_stack[window_count].window_number;
                window_manager_class::window[window_number].mouse_delay.reset();
                for (int element_count = 0; element_count < window_manager_class::window[window_number].number_of_elements; element_count++)
                {
                    window_manager_class::window[window_number].element[element_count].mouse_delay.reset();
                }
            }
        }
    }
};

int  window_manager_class::get_window_event(int UID)
{
    int return_value = 0;
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if ((window_manager_class::window_stack[window_count].UID == UID) && (window_manager_class::window_stack[window_count].enabled))
            {
                return_value = window_manager_class::window[window_manager_class::window_stack[window_count].window_number].event;
            }
        }
    }
};

void window_manager_class::process(void)
{
    //Determine mouse over for overlapping windows.
    bool front_window_found = false;
    for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
    {
        if((!front_window_found) && (window_manager_class::window_stack[window_count].enabled))
        {
            if(window_manager_class::window[window_manager_class::window_stack[window_count].window_number].get_mouse_over_menu())
            {
                //if active window found, process it.
                window_manager_class::window[window_manager_class::window_stack[window_count].window_number].mouse_over_menu = true;
                window_manager_class::window[window_manager_class::window_stack[window_count].window_number].process();
                front_window_found = true;
            }
        }
    }
}

void window_manager_class::render(void)
{
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = window_manager_class::number_of_windows; window_count >= 0; window_count--)
        {
            if (window_manager_class::window_stack[window_count].enabled)
            {
                window_manager_class::window[window_manager_class::window_stack[window_count].window_number].render();
            }
        }
    }
}

