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

#ifndef ENTITY_BONE_HPP
#define ENTITY_BONE_HPP

#include "../core/includes.hpp"

struct sEntityBone
{
    std::int32_t ID               = -1;
    std::int32_t parentID         = -1;
    std::string  name             = "";
    glm::mat4    transformNode    = glm::mat4(1); // node transformation matrix
    glm::mat4    transformPose    = glm::mat4(1); // inverse bind pose matrix
    glm::mat4    transformFinal   = glm::mat4(1); // the final animated transform
    glm::mat4    transformTemp    = glm::mat4(1); // an intermediary transform
};

#endif // ENTITY_BONE_HPP
