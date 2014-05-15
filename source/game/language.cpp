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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <physfs.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../core/misc.hpp"
#include "game.hpp"
#include "language.hpp"

extern  game_class                game;

language_class::language_class(void)
{
    language_class::text.main_menu             = "Main menu           ";
    language_class::text.new_game              = "New Game            ";
    language_class::text.load_game             = "Load Game           ";
    language_class::text.save_game             = "Save Game           ";
    language_class::text.resume_game           = "Resume Game         ";
    language_class::text.options               = "Options             ";
    language_class::text.quit_game             = "Quit Game           ";
    language_class::text.none                  = "None                ";
    language_class::text.save_menu             = "Save Menu           ";
    language_class::text.save_slot_1           = "Save Slot 1         ";
    language_class::text.save_slot_2           = "Save Slot 2         ";
    language_class::text.save_slot_3           = "Save Slot 3         ";
    language_class::text.save_slot_4           = "Save Slot 4         ";
    language_class::text.save_slot_5           = "Save Slot 5         ";
    language_class::text.save_slot_6           = "Save Slot 6         ";
    language_class::text.save_slot_7           = "Save Slot 7         ";
    language_class::text.load_menu             = "Load Menu           ";
    language_class::text.sound_volume          = "Sound Volume        ";
    language_class::text.music_volume          = "Music Volume        ";
    language_class::text.screen_resolution     = "Screen Resolution   ";
    language_class::text.res_640_x_480         = "640 X 480           ";
    language_class::text.res_800_x_600         = "800 X 600           ";
    language_class::text.res_1024_x_768        = "1024 X 768          ";
    language_class::text.res_1280_x_1024       = "1280 X 1024         ";
    language_class::text.res_1366_x_768        = "1366 X 768          ";
    language_class::text.res_1440_x_900        = "1440 X 900          ";
    language_class::text.res_1680_x_1050       = "1680 X 1050         ";
    language_class::text.res_1920_x_1080       = "1920 X 1080         ";
    language_class::text.full_screen           = "Full Screen         ";
    language_class::text.game_over             = "Game Over           ";
    language_class::text.game_completed        = "Game Completed      ";
    language_class::text.game_paused           = "Game Paused         ";
    language_class::text.menu_item_unavailable = "Unavailable         ";
    language_class::text.quest_log             = "Quest Log           ";
    language_class::text.character_menu        = "Character Menu      ";
    language_class::text.inventory             = "Inventory           ";
    language_class::text.spell_book            = "Spell Book          ";
    language_class::text.equipment             = "Equipment           ";
    language_class::text.npcvendor             = "Vendor              ";
};

void language_class::load(std::string language_name)
{
    std::string file_name = "data/configuration/languages/"+language_name+".txt";
    game.core.log.write("Loading language '"+language_name+"' from file -> "+file_name);
    if (PHYSFS_exists(file_name.c_str()))
    {
        PHYSFS_openRead(file_name.c_str());
        PHYSFS_File *file_pointer = NULL;
        file_pointer = PHYSFS_openRead(file_name.c_str());
        if (file_pointer)
        {
            int            temp_char_UTF32  = ' ';
            //int            temp_int_data;
            //float          temp_float_data;
            //bool           temp_bool_data;
            std::string    temp_string_data;
            std::string    temp_string_key;
            std::string    temp_string_value;
            int            position_count;
            std::string    data_line;
            bool           eof_found = false;
            char          *char_buffer = new char[2];
            while (!eof_found)
            {
                //getline(script_file,data_line);
                data_line = "";
                bool endl_found = false;
                while (!endl_found)
                {
                    PHYSFS_read(file_pointer, char_buffer, 1, 1);
                    if (char_buffer[0] < 32) endl_found = true;
                    eof_found = PHYSFS_eof(file_pointer);
                    if (eof_found) endl_found = true;
                    if ((!endl_found)&&(!eof_found)) data_line += char_buffer[0];
                }
                //game.core.log.file_write("Reading line -> "+data_line);
                if (data_line.length() > 0)
                {
                    if ('\r' == data_line.at(data_line.length()-1))
                    {
                        data_line = data_line.substr(0, data_line.length()-1);
                    }
                }
                {
                    temp_char_UTF32 = data_line[0];
                    if((temp_char_UTF32 != '#') && (data_line.length() > 2))
                    {
                        temp_char_UTF32   = '#';
                        temp_string_key   = "";
                        temp_string_value = "";
                        position_count = 0;
                        while(temp_char_UTF32 != ' ')
                        {
                            temp_char_UTF32 = data_line[position_count];
                            if(temp_char_UTF32 != ' ') temp_string_key += temp_char_UTF32;
                            position_count++;
                            if(position_count > (int)data_line.length()) (temp_char_UTF32 = ' ');
                        }
                        while((temp_char_UTF32 == ' ') || (temp_char_UTF32 == '='))
                        {
                            temp_char_UTF32 = data_line[position_count];
                            position_count++;
                            if(position_count > (int)data_line.length()) (temp_char_UTF32 = '#');
                        }
                        position_count--;
                        while(position_count < ((int)data_line.length()-1))
                        {
                            temp_char_UTF32  = data_line[position_count];
                            if (temp_char_UTF32 != '"') temp_string_value += temp_char_UTF32;
                            position_count++;
                        }
                        temp_string_data = temp_string_value.c_str();
                        /*
                        temp_float_data  = (float) atof(temp_string_value.c_str());
                        temp_int_data    = (int)   atoi(temp_string_value.c_str());
                        if (temp_int_data == 1) temp_bool_data = true;
                        else temp_bool_data = false;
                        */
                        if (temp_string_key == "Main_Menu")             language_class::text.main_menu             = temp_string_data;
                        if (temp_string_key == "New_Game")              language_class::text.new_game              = temp_string_data;
                        if (temp_string_key == "Load_Game")             language_class::text.load_game             = temp_string_data;
                        if (temp_string_key == "Save_Game")             language_class::text.save_game             = temp_string_data;
                        if (temp_string_key == "Resume_Game")           language_class::text.resume_game           = temp_string_data;
                        if (temp_string_key == "Options")               language_class::text.options               = temp_string_data;
                        if (temp_string_key == "Quit_Game")             language_class::text.quit_game             = temp_string_data;
                        if (temp_string_key == "None")                  language_class::text.none                  = temp_string_data;
                        if (temp_string_key == "Save_Menu")             language_class::text.save_menu             = temp_string_data;
                        if (temp_string_key == "Save_Slot_1")           language_class::text.save_slot_1           = temp_string_data;
                        if (temp_string_key == "Save_Slot_2")           language_class::text.save_slot_2           = temp_string_data;
                        if (temp_string_key == "Save_Slot_3")           language_class::text.save_slot_3           = temp_string_data;
                        if (temp_string_key == "Save_Slot_4")           language_class::text.save_slot_4           = temp_string_data;
                        if (temp_string_key == "Save_Slot_5")           language_class::text.save_slot_5           = temp_string_data;
                        if (temp_string_key == "Save_Slot_6")           language_class::text.save_slot_6           = temp_string_data;
                        if (temp_string_key == "Save_Slot_7")           language_class::text.save_slot_7           = temp_string_data;
                        if (temp_string_key == "Load_Menu")             language_class::text.load_menu             = temp_string_data;
                        if (temp_string_key == "Sound_Volume")          language_class::text.sound_volume          = temp_string_data;
                        if (temp_string_key == "Music_Volume")          language_class::text.music_volume          = temp_string_data;
                        if (temp_string_key == "Screen_Resolution")     language_class::text.screen_resolution     = temp_string_data;
                        if (temp_string_key == "Res_640_X_480")         language_class::text.res_640_x_480         = temp_string_data;
                        if (temp_string_key == "Res_800_X_600")         language_class::text.res_800_x_600         = temp_string_data;
                        if (temp_string_key == "Res_1024_X_768")        language_class::text.res_1024_x_768        = temp_string_data;
                        if (temp_string_key == "Res_1280_X_1024")       language_class::text.res_1280_x_1024       = temp_string_data;
                        if (temp_string_key == "Res_1366_X_768")        language_class::text.res_1366_x_768        = temp_string_data;
                        if (temp_string_key == "Res_1440_X_900")        language_class::text.res_1440_x_900        = temp_string_data;
                        if (temp_string_key == "Res_1680_X_1050")       language_class::text.res_1680_x_1050       = temp_string_data;
                        if (temp_string_key == "Res_1920_X_1080")       language_class::text.res_1920_x_1080       = temp_string_data;
                        if (temp_string_key == "Full_Screen")           language_class::text.full_screen           = temp_string_data;
                        if (temp_string_key == "Game_Over")             language_class::text.game_over             = temp_string_data;
                        if (temp_string_key == "Game_Completed")        language_class::text.game_completed        = temp_string_data;
                        if (temp_string_key == "Game_Paused")           language_class::text.game_paused           = temp_string_data;
                        if (temp_string_key == "Menu_Item_Unavailable") language_class::text.menu_item_unavailable = temp_string_data;
                        if (temp_string_key == "Quest_Log")             language_class::text.quest_log             = temp_string_data;
                        if (temp_string_key == "Character_Menu")        language_class::text.character_menu        = temp_string_data;
                        if (temp_string_key == "Inventory")             language_class::text.inventory             = temp_string_data;
                        if (temp_string_key == "Spell_Book")            language_class::text.spell_book            = temp_string_data;
                        if (temp_string_key == "Equipment")             language_class::text.equipment             = temp_string_data;
                        if (temp_string_key == "NPC_Vendor")            language_class::text.npcvendor             = temp_string_data;
                    }
                }
            }
            if (file_pointer) PHYSFS_close(file_pointer);
        }
        else
        {
            game.core.log.write("Fail -> PhysicsFS unable to open file - ",file_name.c_str());
        }
    }
    else
    {
        game.core.log.write("Fail -> PhysicsFS unable to find file - ",file_name.c_str());
    }
}
