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

#ifndef ENTITY_PATH_HPP
#define ENTITY_PATH_HPP

#include "../core/includes.hpp"
#include "../map/map_path_define.hpp"

struct sEntityPath
{
        sMapPath        mapPath;
        float32         movementSpeed   = 0.125f;
        float32         movementBias    = 0.00125f;
        
        bool            pathing         = false; // currently following a path?
        bool            moved           = false; // Did we move this frame?
        glm::vec3       moveDelta       = glm::vec3(0.0f, 0.0f, 0.0f); // How much did we move last frame?
};

#endif //ENTITY_PATH_HPP
