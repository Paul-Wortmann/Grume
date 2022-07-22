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

#ifndef GRAPHICS_ENGINE_UTILS_HPP
#define GRAPHICS_ENGINE_UTILS_HPP

#include "../core/includes.hpp"

glm::vec3 generateNormal(glm::vec3 _a, glm::vec3 _b, glm::vec3 _c);
glm::vec3 generateTangent(glm::vec3 _normal);
glm::vec3 generateBitangent(glm::vec3 _normal, glm::vec3 _tangent);

#endif //GRAPHICS_ENGINE_UTILS_HPP
