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

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>

struct text_type
{
    std::string    main_menu;
    std::string    new_game;
    std::string    load_game;
    std::string    save_game;
    std::string    resume_game;
    std::string    options;
    std::string    quit_game;
    std::string    none;
    std::string    save_menu;
    std::string    save_slot_1;
    std::string    save_slot_2;
    std::string    save_slot_3;
    std::string    save_slot_4;
    std::string    save_slot_5;
    std::string    save_slot_6;
    std::string    save_slot_7;
    std::string    load_menu;
    std::string    sound_volume;
    std::string    music_volume;
    std::string    screen_resolution;
    std::string    res_640_x_480;
    std::string    res_800_x_600;
    std::string    res_1024_x_768;
    std::string    res_1280_x_1024;
    std::string    res_1366_x_768;
    std::string    res_1440_x_900;
    std::string    res_1680_x_1050;
    std::string    res_1920_x_1080;
    std::string    full_screen;
    std::string    game_over;
    std::string    game_completed;
    std::string    game_paused;
    std::string    menu_item_unavailable;
    std::string    quest_log;
    std::string    character_menu;
    std::string    inventory;
    std::string    spell_book;
    std::string    equipment;
    std::string    npcvendor;
};

class language_class
{
    public:
        void load(std::string file_name);
        text_type text;
        language_class(void);
};

#endif //LANGUAGE_H
