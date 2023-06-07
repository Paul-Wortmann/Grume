/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef TYPE_UTILS_HPP
#define TYPE_UTILS_HPP

#include "../core/includes.hpp"

// A collection of basic functions for working with data types

void gStringToInt32Array(const std::string &_string, const std::uint32_t &_dataCount, std::uint32_t *&_array);
void gStringToFloatArray(const std::string &_string, const std::uint32_t &_dataCount, float *&_array);
void gStringToMat4Array(const std::string &_string, const std::uint32_t &_dataCount, glm::mat4 *&_array);

#endif // TYPE_UTILS_HPP

