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

#ifndef ENTITY_GRAPHICS_HPP
#define ENTITY_GRAPHICS_HPP

#include "entity_model.hpp"
#include "../resource/material_define.hpp"

struct sEntityGraphics
{
    bool             billboard   = false;
    glm::mat4        modelMatrix = glm::mat4(1);
    sEntityModel*    model       = nullptr;
    std::uint32_t    numMaterial = 0;
    sMaterial**      material    = nullptr;
    std::uint32_t    icon        = 0;
};

#endif // ENTITY_GRAPHICS_HPP
