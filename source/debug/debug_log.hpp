/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
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
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef DEBUG_LOG_HPP
#define DEBUG_LOG_HPP

#define LOG_INFO    0
#define LOG_WARNING 1
#define LOG_ERROR   2

#include "basic_log.hpp"

#include "debug_defines.hpp"
#include "debug_string_color.hpp"

#include "../utils/file_utils.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void gLogClear(void);
void gLogWrite( /* DEBUG_FILE will be used */ const uint32 &_type, const std::string &_string, const std::string &_file, const uint32 &_line, const std::string &_function);
void gLogWrite(const std::string &_fileName, const uint32 &_type, const std::string &_string, const std::string &_file, const uint32 &_line, const std::string &_function);

#endif // DEBUG_LOG_HPP
