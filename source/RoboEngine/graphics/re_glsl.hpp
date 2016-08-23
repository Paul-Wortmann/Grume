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

#ifndef C_GLSL_HPP
#define C_GLSL_HPP

#include <string>
#include <fstream>
#include <iostream>
#include "../system/re_log.hpp"
#include "../system/re_file.hpp"

namespace RoboEngine
{

    void freeShader(uint32_t _shaderID);
    void loadShader(const std::string &_fileName, uint32_t &_shaderID, uint32_t &_numAttribs);

}

#endif // C_GLSL_HPP
