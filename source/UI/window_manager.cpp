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

extern game_class game;

//------------------------------------------------------------ Window Class ------------------------------------------------------------------------

window_class::window_class(void)
{
    window_class::UID           = -1;
    window_class::active        = false;
    window_class::mouse_over    = false;
    window_class::size_x        = 0.0f;
    window_class::size_y        = 0.0f;
    window_class::size_z        = 0.0f;
    window_class::position_x    = 0.0f;
    window_class::position_y    = 0.0f;
    window_class::position_z    = 0.0f;
}

window_class::~window_class(void)
{
}

//--------------------------------------------------------- Window Manager Class -------------------------------------------------------------------

window_manager_class::window_manager_class(void)
{
    window_manager_class::number_of_windows = 0;
}

window_manager_class::~window_manager_class(void)
{

}

void window_manager_class::set_active_window(int UID)
{
    for (int window_count = 1; window_count <= window_manager_class::number_of_windows; window_count++)
    {
        if (window_manager_class::window[window_count].UID == UID) window_manager_class::window[window_count].active = true;
        else window_manager_class::window[window_count].active = false;
    }
}

int  window_manager_class::get_active_window(void)
{
    int return_UID = 0;
    for (int window_count = 1; window_count <= window_manager_class::number_of_windows; window_count++)
    {
        if (window_manager_class::window[window_count].active) return_UID = window_count;
    }
    return(return_UID);
}

int  window_manager_class::register_window(int UID)
{
    game.core.log.file_write("registering window -> ",UID);
    if (window_manager_class::number_of_windows > 0) window_manager_class::de_register_window(UID); //first remove UID from list if it is already on the list
    if (window_manager_class::number_of_windows > 0) // only processed if there are actually windows in the list.
    {
        window_class temp_window_data[window_manager_class::number_of_windows+1];
        // save the old window data
        for (int window_count = 1; window_count <= window_manager_class::number_of_windows; window_count++)
        {
            temp_window_data[window_count].UID = window_manager_class::window[window_count].UID;
        }
        window_manager_class::number_of_windows += 1;
        if (window_manager_class::window) delete window_manager_class::window;
        window_manager_class::window = new window_class[window_manager_class::number_of_windows+1];
        //place new UID on top of the list and the old window data after it.
        window_manager_class::window[1].active = true;
        window_manager_class::window[1].UID    = UID;
        for (int window_count = 2; window_count <= window_manager_class::number_of_windows; window_count++)
        {
            window_manager_class::window[window_count].UID = temp_window_data[window_count-1].UID;
        }
    }
    else // list is empty so just add our window to the list
    {
        window_manager_class::number_of_windows = 1;
        if (window_manager_class::window) delete window_manager_class::window;
        window_manager_class::window = new window_class[window_manager_class::number_of_windows+1];
        //place new UID on top of the list and the old window data after it.
        window_manager_class::window[1].active = true;
        window_manager_class::window[1].UID    = UID;
    }
    game.core.log.file_write("registered window -> ",UID, "window_count -> ",window_manager_class::number_of_windows);
}

int  window_manager_class::register_window(int UID_minimum, int UID_maximum)
{
    int   new_UID   = -1;
    int   temp_UID  = UID_minimum;
    bool  UID_found = false;
    while ((new_UID == -1) and (temp_UID < UID_maximum))
    {
        UID_found = false;
        for (int window_count = 1; window_count <= window_manager_class::number_of_windows; window_count++)
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
    game.core.log.file_write("de_registering window -> ",UID);
    int UID_on_list = 0;
    if (window_manager_class::number_of_windows > 0) // only process windows if there are actually windows in the list.
    {
        for (int window_count = 1; window_count <= window_manager_class::number_of_windows; window_count++) // first check if UID is on list
        {
            if (window_manager_class::window[window_count].UID == UID) UID_on_list++;
        }
        if (UID_on_list > 0)
        {
            if (window_manager_class::number_of_windows == UID_on_list)
            {
                window_manager_class::number_of_windows = 0;
                if(window_manager_class::window) delete window_manager_class::window;
            }
            else
            {
                //backup old list
                window_class temp_window_data[window_manager_class::number_of_windows];
                for (int window_count = 1; window_count <= window_manager_class::number_of_windows; window_count++)
                {
                    temp_window_data[window_count].UID = window_manager_class::window[window_count].UID;
                }
                //create new list without UID
                int new_window_count = 1;
                window_manager_class::number_of_windows -= UID_on_list;
                if(window_manager_class::window) delete window_manager_class::window;
                window_manager_class::window = new window_class[window_manager_class::number_of_windows+1];
                for (int window_count = 1; window_count <= window_manager_class::number_of_windows+UID_on_list; window_count++)
                {
                    if (window_manager_class::window[window_count].UID != UID)
                    {
                        window_manager_class::window[new_window_count].UID = temp_window_data[window_count].UID;
                        new_window_count++;
                    }
                }
            }
        }
    }
    game.core.log.file_write("de_registered window -> ",UID, "window_count -> ",window_manager_class::number_of_windows);
}

bool  window_manager_class::mouse_in_quadrangle  (float qx, float qy, float qw, float qh)
{
    float px = window_manager_class::mouse_x;
    float py = window_manager_class::mouse_y;
    if ((px > (qx-(qw/2))) && (px < (qx+(qw/2))) && (py > (qy-(qh/2))) && (py < (qy+(qh/2)))) return(true);
    else return(false);
};

void window_manager_class::process(void)
{
    /*
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
}











