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

#include <string>
#include "command_line_parser.hpp"
#include "../game/game.hpp"

extern game_class game;

command_line_parser_class::command_line_parser_class (void)
{
    command_line_parser_class::number_of_args = 0;
};

command_line_parser_class::~command_line_parser_class(void)
{
};

void command_line_parser_class::process (int arg_count, char** arg_data)
{
    std::string temp_string;
    command_line_parser_class::number_of_args = arg_count;
    for (int arg_number = 0; arg_number < arg_count; arg_number++)
    {
        temp_string = arg_data[arg_number];
        if ((temp_string.compare("-window") == 0) ||
            (temp_string.compare("-w") == 0))
        {
            game.core.config.display_fullscreen   = false;
            game.core.config.display_resolution_x = 0;
            game.core.config.display_resolution_y = 0;
            std::cout << "Windowed mode enabled." << std::endl;
        }
        if ((temp_string.compare("-debug") == 0) ||
            (temp_string.compare("-d") == 0))
        {
            game.core.debug = true;
            std::cout << "Developer mode enabled." << std::endl;
        }
        if ((temp_string.compare("--help") == 0) ||
            (temp_string.compare("-help") == 0) ||
            (temp_string.compare("-h") == 0))
        {
            std::cout << "-w   Enable a windowed mode." << std::endl;
            std::cout << "-d   Enable developer mode." << std::endl;
            std::cout << "-h   This help screen." << std::endl;
        }
    }
};

