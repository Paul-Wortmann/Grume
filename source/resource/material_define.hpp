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

#ifndef MATERIAL_DEFINE_HPP
#define MATERIAL_DEFINE_HPP

#include "../core/includes.hpp"
#include "texture_define.hpp"

struct sMaterial
{
    // Linked list management
    std::uint32_t UID      = 0;
    sMaterial*    next     = nullptr;

    // Data
    std::string   materialName = {};
    sTexture*     diffuse      = 0;
    sTexture*     normal       = 0;
    sTexture*     specular     = 0;
    sTexture*     emissive     = 0;
    float         shininess    = 32.0f;
};

#endif // MATERIAL_DEFINE_HPP
