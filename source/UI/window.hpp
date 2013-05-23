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

#ifndef WINDOW_H
#define WINDOW_H

#include "window_element.hpp"
#include "../core/font_manager.hpp"
#include "../core/types.hpp"
#include <string>

class window_class
{
    private:
    public:
        bool                    enabled;
        bool                    active;
        bool                    set_behind;
        int                     UID;
        choice_selection_type   choice_selection[MAX_CHOICE_SELECTIONS_PER_MENU];
        delay_class             mouse_delay;
        event_type              event;
        location_class          title;
        color_struct            title_color;
        location_class          title_bar;
        f3_type                 size;
        f3_type                 position;
        bool                    mouse_over_menu;
        bool                    mouse_over_title;
        bool                    drag_enabled;
        bool                    drag_active;
        float                   drag_offset_x;
        float                   drag_offset_y;
        element_zoom_struct     zoom;
        color_state_struct      color;
        sound_state_struct      sound;
        texture_state_struct    texture;
        font_type              *font;
        int                     number_of_elements;
        window_element_class   *element;
        window_class(void);
       ~window_class(void);
        void                    render(void);
        void                    render_draged_elements(void);
        bool                    get_mouse_over_menu(void);
        bool                    get_mouse_over_title(void);
        bool                    mouse_click_title(void);
        void                    set_position(float x_pos, float y_pos);
        event_type              process(bool window_in_focus);
};

#endif // WINDOW_H

