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

#ifndef CONFIG_H
#define CONFIG_H

#include <SDL/SDL.h>
#include <string>

class config_class
{
    private:
    public:
        std::string  file_name;
        std::string  file_header;
        const        SDL_VideoInfo* display_info;
        int          display_resolution;
        int          display_resolution_x;
        int          display_resolution_y;
        int          display_bpp;
        bool         display_fullscreen;
        bool         display_touchscreen;
        int          display_flags;
        bool         mouse_autohide;
        int          mouse_autohide_timer;
        int          mouse_autohide_timer_count;
        int          menu_delay;
        int          menu_delay_count;
        int          mouse_resolution_x;
        int          mouse_resolution_y;
        int          joystick_sensitivity;
        bool         joystick_enabled;
        int          joystick_no_buttons;
        int          audio_rate;
        int          audio_channels;
        int          audio_buffers;
        int          audio_volume_music;
        int          audio_volume_sound;
        std::string  language;
                     config_class(void);
                    ~config_class(void);
        void         set_defaults(void);
        bool         file_set(std::string file_name);
        bool         file_write(std::string data_string);
        bool         file_load(void);
        bool         file_save(void);
        bool         file_clear(void);
        bool         file_delete(void);
        void         mouse_autohide_process(bool set_active);
};

#endif //CONFIG_H




