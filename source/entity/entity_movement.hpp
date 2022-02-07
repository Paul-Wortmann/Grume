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

#ifndef ENTITY_MOVEMENT_HPP
#define ENTITY_MOVEMENT_HPP

#include "../core/includes.hpp"
#include "../map/map_path_define.hpp"

struct sEntityMovement
{
    sMapPath        mapPath;
        
    // Movement
    float           movementSpeed   = 0.125f;
    float           movementBias    = 0.00125f;
    bool            pathing         = false; // currently following a path?
    bool            moved           = false; // Did we move this frame?
    glm::vec3       moveDelta       = glm::vec3(0.0f, 0.0f, 0.0f); // How much did we move last frame?
};

#endif //ENTITY_MOVEMENT_HPP
