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

#ifndef XML_UTILS_HPP
#define XML_UTILS_HPP

#include "includes.hpp"
#include "defines.hpp"

// A collection of basic functions to extract data from xml encoded strings*
// *This does not cover the full XML specification.

bool        xmlFind           (const std::string &_data, const std::string &_find);
std::string xmlGetDataString  (const std::string &_data);
std::string xmlGetDataValue   (const std::string &_data, const std::string &_key);
float       xmlGetFloatValue  (const std::string &_data, const std::string &_key);
int32_t     xmlGetIntegerValue(const std::string &_data, const std::string &_key);
glm::vec2   xmlGetVec2Value   (const std::string &_data, const std::string &_key);
glm::vec3   xmlGetVec3Value   (const std::string &_data, const std::string &_key);

#endif // XML_UTILS_HPP
