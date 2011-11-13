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

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class config_file_class
{
    private:
        const char  *Config_File;
    public:
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
        int          Display_resolution;
        int          Display_X_Resolution;
        int          Display_Y_Resolution;
        int          Display_BPS;
        bool         Display_Fullscreen;
        bool         Display_Touchscreen;
        int          Audio_Rate;
        int          Audio_Channels;
        int          Audio_Buffers;
        int          Audio_Music_Volume;
        int          Audio_Sound_Volume;
        std::string  language;
              config_file_class(void);
             ~config_file_class(void);
        void  process          (bool set_active);
        bool  File_Set         (std::string file_name);
        bool  Set_Defaults     (void);
        bool  File_Clear       (void);
        bool  File_Delete      (void);
        bool  File_Write_Data  (std::string config_comment);
        bool  File_Write_Data  (std::string config_key, int  config_data_int);
        bool  File_Write_Data  (std::string config_key, bool config_data_bool);
        bool  File_Write_Data  (std::string config_key, std::string config_string_bool);
        bool  File_Write       (void);
        bool  Process_Data     (std::string data_line);
        bool  File_Read        (void);
};

#endif //CONFIG_H
