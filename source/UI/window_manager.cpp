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

#include "window_manager.hpp"
#include "../game.hpp"

extern game_class         game;

//--------------------------------------------------------- Window Manager Class -------------------------------------------------------------------

window_manager_class::window_manager_class(void)
{
    window_manager_class::event.id             = 0;
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

void window_manager_class::window_stack_sort(void)
{
    if (window_manager_class::number_of_windows > 1) // only processed if there are actually windows in the list to sort.
    {
        for (int window_count = window_manager_class::number_of_windows-1; window_count >= 1; window_count--)
        {
            if ((window_manager_class::window[window_manager_class::window_stack[window_count]].active) && (!window_manager_class::window[window_manager_class::window_stack[window_count]].set_behind))
            {
                int temp_window_count = window_manager_class::window_stack[window_count-1];
                window_manager_class::window_stack[window_count-1] = window_manager_class::window_stack[window_count];
                window_manager_class::window_stack[window_count]   = temp_window_count;
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
        // create the window stack
        window_manager_class::window_stack = new int[window_manager_class::number_of_windows+1];
        window_manager_class::windows_list_created = true;
        // Clear the window stack
        for (int window_stack_count = 0; window_stack_count < number_of_windows; window_stack_count++)
        {
            window_manager_class::window_stack[window_stack_count] = -1;
        }
    }
 }

int  window_manager_class::window_get_number(int UID)
{
    int return_value = 0;
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID) return_value = window_manager_class::window_stack[window_count];
        }
    }
    return(return_value);
};

void window_manager_class::window_set_active(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID)
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].active = true;
            }
            else
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].active = false;
            }
        }
    }
    window_manager_class::event.id = EVENT_WINDOW_STACK_SORT; // request stack sort
};

void window_manager_class::window_set_inactive(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID)
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].active = false;
            }
        }
    }
    window_manager_class::event.id = EVENT_WINDOW_STACK_SORT; // request stack sort
};

int  window_manager_class::window_get_active(void)
{
    int return_value = 0;
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if(window_manager_class::window[window_manager_class::window_stack[window_count]].active) return_value = window_manager_class::window[window_manager_class::window_stack[window_count]].UID;
        }
    }
    return(return_value);
};

int window_manager_class::window_register(int UID)
{
    bool window_added = false;
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if ((window_manager_class::window[window_count].UID == -1) && (!window_added))
            {
                window_added = true;
                window_manager_class::window[window_count].UID         = UID;
                window_manager_class::window[window_count].active      = false;
                window_manager_class::window[window_count].enabled     = false;
                window_manager_class::window_stack[window_count]       = window_count;
            }
        }
    }
    if(window_added) return(UID);
    else return(-1);
}

int  window_manager_class::window_register(int UID_minimum, int UID_maximum)
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
    if(new_UID > 0) return(window_manager_class::window_register(new_UID));
    else return(-1);
}

void window_manager_class::window_de_register(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID)
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].active  = false;
                window_manager_class::window[window_manager_class::window_stack[window_count]].enabled = false;
                window_manager_class::window[window_manager_class::window_stack[window_count]].UID     = -1;
                window_manager_class::window_stack[window_count] = -1;
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
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID)
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].enabled = true;
                window_manager_class::window_set_active(window_manager_class::window[window_manager_class::window_stack[window_count]].UID);
                game.window_manager.window_stack_sort();
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
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID)
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].enabled = false;
                window_manager_class::window_set_inactive(window_manager_class::window[window_manager_class::window_stack[window_count]].UID);
            }
        }
    }
};

void window_manager_class::window_set_pos(int UID_source, int UID_destination)
{
    int source_window      = window_manager_class::window_get_number(UID_source);
    int destination_window = window_manager_class::window_get_number(UID_destination);
    window_manager_class::window[destination_window].set_position(window_manager_class::window[source_window].position.x,window_manager_class::window[source_window].position.y);
};

void window_manager_class::window_transition(int UID_source, int UID_destination)
{
    window_manager_class::window_disable(UID_source);
    window_manager_class::window_set_pos(UID_source,UID_destination);
    window_manager_class::mouse_reset(UID_destination);
    window_manager_class::mouse_reset(UID_source);
    window_manager_class::window_reset_event(UID_destination);
    window_manager_class::window_reset_event(UID_source);
    window_manager_class::window_enable(UID_destination);
    window_manager_class::window_set_active(UID_destination);
    window_manager_class::event.id = EVENT_WINDOW_STACK_SORT; // Request stack sort
    game.core.io.mouse_button_left = false;
};

void window_manager_class::window_reset_event(int UID)
{
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID)
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].event.id = EVENT_NONE;
            }
        }
    }
};

void window_manager_class::mouse_reset(int UID)
{
    int window_number;
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID)
            {
                window_number = window_manager_class::window_stack[window_count];
                window_manager_class::window[window_number].mouse_delay.reset();
                for (int element_count = 0; element_count < window_manager_class::window[window_number].number_of_elements; element_count++)
                {
                    window_manager_class::window[window_number].element[element_count].mouse_delay.reset();
                }
            }
        }
    }
};

event_type  window_manager_class::window_get_event(int UID)
{
    event_type return_value;
    return_value.id = 0;
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
        {
            if ((window_manager_class::window[window_manager_class::window_stack[window_count]].UID == UID) && (window_manager_class::window[window_manager_class::window_stack[window_count]].enabled))
            {
                return_value = window_manager_class::window[window_manager_class::window_stack[window_count]].event;
            }
        }
    }
    return(return_value);
};

void window_manager_class::process(void)
{
    //Determine mouse over for overlapping windows.
    bool front_window_found = false;
    event_type temp_event;
    for (int window_count = 0; window_count < window_manager_class::number_of_windows; window_count++)
    {
        if (window_manager_class::window[window_manager_class::window_stack[window_count]].enabled)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].get_mouse_over_menu())
            {
                if (!front_window_found)
                {
                    window_manager_class::window[window_manager_class::window_stack[window_count]].mouse_over_menu  = true;
                    temp_event = window_manager_class::window[window_manager_class::window_stack[window_count]].process(true);
                    if (temp_event.id == EVENT_WINDOW_STACK_SORT) window_manager_class::window_set_active(window_manager_class::window[window_manager_class::window_stack[window_count]].UID);
                    front_window_found = true;
                }
                else
                {
                    window_manager_class::window[window_manager_class::window_stack[window_count]].mouse_over_menu  = true;
                    window_manager_class::window[window_manager_class::window_stack[window_count]].process(false);
                }
            }
            else
            {
                window_manager_class::window[window_manager_class::window_stack[window_count]].process(false);
            }
        }
    }
}

void window_manager_class::render(void)
{
    // Render windows
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        for (int window_count = window_manager_class::number_of_windows-1; window_count >= 0; window_count--)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID != -1)
            {
                if (window_manager_class::window[window_manager_class::window_stack[window_count]].enabled)
                {
                    window_manager_class::window[window_manager_class::window_stack[window_count]].render();
                }
            }
        }
        // Render dragged items
        for (int window_count = window_manager_class::number_of_windows-1; window_count >= 0; window_count--)
        {
            if (window_manager_class::window[window_manager_class::window_stack[window_count]].UID != -1)
            {
                if (window_manager_class::window[window_manager_class::window_stack[window_count]].enabled)
                {
                    window_manager_class::window[window_manager_class::window_stack[window_count]].render_draged_elements();
                }
            }
        }
    }
}

void window_manager_class::swap_elements(window_element_class *src_element, window_element_class *dst_element)
{
    window_element_class *tmp_element;
    tmp_element = dst_element;
    dst_element = src_element;
    src_element = tmp_element;

};
