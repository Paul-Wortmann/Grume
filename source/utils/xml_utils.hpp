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

#ifndef XML_UTILS_HPP
#define XML_UTILS_HPP

#include "../core/includes.hpp"

// A collection of basic functions to extract data from xml encoded strings*
// *This does not cover the full XML specification.

bool        xmlFind           (const std::string &_data, const std::string &_find);
std::string xmlGetDataString  (const std::string &_data);
std::string xmlGetDataValue   (const std::string &_data, const std::string &_key);
float32     xmlGetFloatValue  (const std::string &_data, const std::string &_key);
int32       xmlGetIntegerValue(const std::string &_data, const std::string &_key);
glm::vec2   xmlGetVec2Value   (const std::string &_data);
glm::vec3   xmlGetVec3Value   (const std::string &_data);

#endif // XML_UTILS_HPP
