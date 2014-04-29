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
 * @date 2011-11-11
 */

#include <fstream>
#include <time.h>
#include "config.hpp"
#include "../game/game.hpp"

extern game_class    game;

config_class::config_class(void)
{
    config_class::file_name                  = "default.cfg";
    config_class::display_resolution         = 0;
    config_class::display_resolution_x       = 0;
    config_class::display_resolution_y       = 0;
    config_class::font_base_resolution_x     = 1920;
    config_class::font_base_resolution_y     = 1080;
    config_class::font_scale_x               = (float)config_class::display_resolution_x/(float)config_class::font_base_resolution_x;
    config_class::font_scale_y               = (float)config_class::display_resolution_y/(float)config_class::font_base_resolution_y;
    config_class::display_bpp                = 32;
    config_class::display_fullscreen         = true;
    config_class::display_touchscreen        = false;
    config_class::display_flags              = 0;
    config_class::mouse_autohide             = false;
    config_class::mouse_autohide_timer       = 128;
    config_class::mouse_autohide_timer_count = 0;
    config_class::menu_delay                 = 128;
    config_class::menu_delay_count           = 0;
    config_class::mouse_resolution_x         = config_class::display_resolution_x;
    config_class::mouse_resolution_y         = config_class::display_resolution_y;
    config_class::joystick_sensitivity       = 6400;
    config_class::joystick_enabled           = false;
    config_class::joystick_no_buttons        = 0;
    config_class::audio_rate                 = 44100;
    config_class::audio_channels             = 32;
    config_class::audio_buffers              = 1024;
    config_class::audio_volume_music         = 32;
    config_class::audio_volume_sound         = 64;
    config_class::language                   = "english";
};

config_class::~config_class(void)
{
    //config_class::display_info                 = NULL;
};

void       config_class::set_defaults(void)
{
    config_class::file_name                  = "default.cfg";
    config_class::display_resolution         = 0;
    config_class::display_resolution_x       = 0;
    config_class::display_resolution_y       = 0;
    config_class::font_base_resolution_x     = 1920;
    config_class::font_base_resolution_y     = 1080;
    config_class::font_scale_x               = (float)config_class::display_resolution_x/(float)config_class::font_base_resolution_x;
    config_class::font_scale_y               = (float)config_class::display_resolution_y/(float)config_class::font_base_resolution_y;
    config_class::display_bpp                = 32;
    config_class::display_fullscreen         = true;
    config_class::display_touchscreen        = false;
    config_class::display_flags              = 0;
    config_class::mouse_autohide             = false;
    config_class::mouse_autohide_timer       = 128;
    config_class::mouse_autohide_timer_count = 0;
    config_class::menu_delay                 = 128;
    config_class::menu_delay_count           = 0;
    config_class::mouse_resolution_x         = config_class::display_resolution_x;
    config_class::mouse_resolution_y         = config_class::display_resolution_y;
    config_class::joystick_sensitivity       = 6400;
    config_class::joystick_enabled           = false;
    config_class::joystick_no_buttons        = 0;
    config_class::audio_rate                 = 44100;
    config_class::audio_channels             = 32;
    config_class::audio_buffers              = 1024;
    config_class::audio_volume_music         = 32;
    config_class::audio_volume_sound         = 64;
    config_class::language                   = "english";
};

bool config_class::file_set(std::string file_name_in)
{
    config_class::file_name = file_name_in.c_str();
    return(true);
};

bool config_class::file_write(std::string data_string)
{
    std::fstream configfile(config_class::file_name.c_str(),std::ios::out|std::ios::app);
    if (configfile.is_open())
    {
        configfile << data_string;
        configfile << std::endl;
        configfile.close();
    }
    else return(false);
    return(true);
};

bool config_class::file_load(void)
{
    if (config_class::file_name.length() < 5)
    {
        game.core.log.file_write("Fail -> Configuration file name invalid - ",config_class::file_name.c_str());
        return(false);
    }
    else
    {
        std::fstream configfile(config_class::file_name.c_str(),std::ios::in|std::ios::binary);
        if (configfile.is_open())
        {
            int         temp_int;
            std::string temp_string_key;
            std::string temp_string_value;
            int         position_count;
            std::string data_line;
            while (configfile.good())
            {
                getline(configfile,data_line);
                char temp_char = data_line[0];
                if((temp_char == '#') || ((int)data_line.length() <= 1))
                {
                    //comment or insufficient data due to line length, therefore do nothing.
                }
                else
                {
                    temp_string_key   = "";
                    temp_string_value = "";
                    temp_char = '#';
                    position_count = 0;
                    while(temp_char != ' ')
                    {
                        temp_char = data_line[position_count];
                        if(temp_char != ' ') temp_string_key += temp_char;
                        position_count++;
                        if(position_count > (int)data_line.length()) (temp_char = ' ');
                    }
                    while((temp_char == ' ') || (temp_char == '='))
                    {
                        temp_char = data_line[position_count];
                        position_count++;
                        if(position_count > (int)data_line.length()) (temp_char = ' ');
                    }
                    position_count--;
                    while(position_count < (int)data_line.length())
                    {
                        temp_char = data_line[position_count];
                        if ((temp_char != ' ') && (temp_char != '\r')) temp_string_value += temp_char;
                        position_count++;
                    }
                    temp_int = atoi(temp_string_value.c_str());
                    if (temp_string_key == "Joystick_Sensitivity")
                    {
                        config_class::joystick_sensitivity = temp_int;
                    }
                    if (temp_string_key == "Display_Touchscreen")
                    {
                        if (temp_int == 1) config_class::display_touchscreen = true;
                        else config_class::display_touchscreen = false;
                    }
                    if (temp_string_key == "Display_Fullscreen")
                    {
                        if (temp_int == 1) config_class::display_fullscreen = true;
                        else config_class::display_fullscreen = false;
                    }
                    if (temp_string_key == "Audio_Rate")
                    {
                        if (temp_int == 11) temp_int = 11025;
                        if (temp_int == 22) temp_int = 22050;
                        if (temp_int == 44) temp_int = 44100;
                        if ((temp_int == 11025) || (temp_int == 22050) || (temp_int == 44100)) config_class::audio_rate = temp_int;
                    }
                    if (temp_string_key == "Audio_Channels")
                    {
                        if ((temp_int >= 1) && (temp_int <= 128)) config_class::audio_channels = temp_int;
                    }
                    if (temp_string_key == "Audio_Buffers")
                    {
                        if ((temp_int >= 512) && (temp_int <= 2048)) config_class::audio_buffers = temp_int;
                    }
                    if (temp_string_key == "Audio_Volume_Music")
                    {
                        if ((temp_int >= 0) && (temp_int <= 100)) config_class::audio_volume_music = temp_int;
                    }
                    if (temp_string_key == "Audio_Volume_Sound")
                    {
                        if ((temp_int >= 0) && (temp_int <= 100)) config_class::audio_volume_sound = temp_int;
                    }
                    if (temp_string_key == "Display_BPP")
                    {
                        config_class::display_bpp = temp_int;
                    }
                    if (temp_string_key == "Display_Resolution_X")
                    {
                        config_class::display_resolution_x = temp_int;
                    }
                    if (temp_string_key == "Display_Resolution_Y")
                    {
                        config_class::display_resolution_y = temp_int;
                    }
                    if (temp_string_key == "Language")
                    {
                        config_class::language = temp_string_value.c_str();
                    }
                }
            }
            configfile.close();
        }
        else
        {
            game.core.log.file_write("Fail -> Configuration file unable to open - ",config_class::file_name.c_str());
            return(false);
        }
    }
    config_class::font_scale_x         = (float)config_class::display_resolution_x/(float)config_class::font_base_resolution_x;
    config_class::font_scale_y         = (float)config_class::display_resolution_y/(float)config_class::font_base_resolution_y;
    config_class::mouse_resolution_x   = config_class::display_resolution_x;
    config_class::mouse_resolution_y   = config_class::display_resolution_y;
    return(true);
};

bool         config_class::file_save(void)
{
    if (config_class::file_name.length() < 5)
    {
        game.core.log.file_write("Fail -> Configuration file name invalid - ",config_class::file_name.c_str());
        return(false);
    }
    else
    {
        std::fstream configfile(config_class::file_name.c_str(),std::ios::out|std::ios::app);
        if (configfile.is_open())
        {
            time_t rawtime;
            rawtime = time(&rawtime);
            char buffer [80];
            #ifdef __MINGW32__
                strftime (buffer,80,"%Y-%m-%d - %H:%M:%S - %Z",localtime(&rawtime));
            #else
                struct tm newtime;
                strftime (buffer,80,"%Y-%m-%d - %H:%M:%S - %Z",localtime_r(&rawtime, &newtime));
            #endif
            configfile << "# " << game.core.application_name << " #" << std::endl;
            configfile << "# ---------------------------------------------- #" << std::endl;
            configfile << std::endl;
            configfile << "# Configuration file created: " << buffer << std::endl;
            configfile << std::endl;
            configfile << "Display_Fullscreen   = ";
            if (config_class::display_fullscreen) configfile << "1";
            else configfile << "0";
            configfile << std::endl;
            configfile << "Display_Resolution_X = ";
            configfile << config_class::display_resolution_x;
            configfile << std::endl;
            configfile << "Display_Resolution_Y = ";
            configfile << config_class::display_resolution_y;
            configfile << std::endl;
            configfile << "Display_BPP          = ";
            configfile << config_class::display_bpp;
            configfile << std::endl;
            configfile << "Display_Touchscreen  = ";
            if (config_class::display_touchscreen) configfile << "1";
            else configfile << "0";
            configfile << std::endl;
            configfile << "Audio_Rate           = ";
            configfile << config_class::audio_rate;
            configfile << std::endl;
            configfile << "Audio_Channels       = ";
            configfile << config_class::audio_channels;
            configfile << std::endl;
            configfile << "Audio_Buffers        = ";
            configfile << config_class::audio_buffers;
            configfile << std::endl;
            configfile << "Audio_Volume_Music   = ";
            configfile << config_class::audio_volume_music;
            configfile << std::endl;
            configfile << "Audio_Volume_Sound   = ";
            configfile << config_class::audio_volume_sound;
            configfile << std::endl;
            configfile << "Joystick_Sensitivity = ";
            configfile << config_class::joystick_sensitivity;
            configfile << std::endl;
            configfile << "Language             = ";
            configfile << config_class::language;
            configfile << std::endl;
            configfile << std::endl;
            configfile.close();
        }
        else
        {
            game.core.log.file_write("Fail -> Configuration file unable to open - ",config_class::file_name.c_str());
            return(false);
        }
    }
    return(true);
};

bool         config_class::file_clear(void)
{
    std::fstream configfile(config_class::file_name.c_str(),std::ios::out|std::ios::binary|std::ios::trunc);
    if (configfile.is_open())
    {
        configfile.close();
    }
    else return(false);
    return(true);
};

bool         config_class::file_delete(void)
{
  if( remove(config_class::file_name.c_str()) != 0 ) return(false);
  else return(true);
};

void config_class::mouse_autohide_process(bool set_active)
{
    if (set_active)
    {
        config_class::mouse_autohide = false;
        config_class::mouse_autohide_timer_count = 0;
    }
    if(!config_class::mouse_autohide)
    {
        config_class::mouse_autohide_timer_count++;
        if (config_class::mouse_autohide_timer_count > config_class::mouse_autohide_timer)
        {
            config_class::mouse_autohide = true;
            config_class::mouse_autohide_timer_count = config_class::mouse_autohide_timer;
        }
    }
};

void config_class::log_system_configuration(void)
{
    game.core.log.file_write("# ------------ System Information -------------- #");
    game.core.log.file_write("Detected - ",SDL_GetPlatform(), " Operating System");
    if (strcmp(SDL_GetPlatform(),"Linux") != 0) game.core.log.file_write("For better performance, upgrade to Linux!");
    game.core.log.file_write("Detected - ",SDL_GetCPUCount()," logical CPU cores");
    game.core.log.file_write("Detected - ",SDL_GetCPUCacheLineSize()," CPU cache line size");
    game.core.log.file_write("Detected - ",SDL_GetSystemRAM(),"MB system RAM");
    if (SDL_Has3DNow())   game.core.log.file_write("Detected - 3D Now");
    if (SDL_HasAVX())     game.core.log.file_write("Detected - AVX");
    if (SDL_HasAltiVec()) game.core.log.file_write("Detected - AltiVec");
    if (SDL_HasMMX())     game.core.log.file_write("Detected - MMX");
    if (SDL_HasRDTSC())   game.core.log.file_write("Detected - RDTSC");
    if (SDL_HasSSE())     game.core.log.file_write("Detected - SSE");
    if (SDL_HasSSE2())    game.core.log.file_write("Detected - SSE2");
    if (SDL_HasSSE3())    game.core.log.file_write("Detected - SSE3");
    if (SDL_HasSSE41())   game.core.log.file_write("Detected - SSE41");
    if (SDL_HasSSE42())   game.core.log.file_write("Detected - SSE42");



    game.core.log.file_write("# ---------------------------------------------- #");
}

