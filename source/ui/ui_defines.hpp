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

#ifndef UI_DEFINE_HPP
#define UI_DEFINE_HPP

#include "../includes.hpp"
#include "../entity/entity_texture.hpp"
#include "../entity/entity_model.hpp"

struct sUIComponent
{
    // Linked list
    sUIComponent*    next          = nullptr;
    std::uint32_t    UID           = 0;

    // Infomation
    std::string      name          = "";
    bool             enabled       = true;
    bool             hover         = false;
    bool             activated     = false;

    // Base
    glm::vec3       position       = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3       scale          = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3       rotation       = glm::vec3(0.0f, 0.0f, 0.0f);

    // Graphics
    sEntityModel*    model         = nullptr;
    glm::mat4        modelMatrix   = glm::mat4(1);
    sEntityTexture*  normalTexture = nullptr;
    sEntityTexture*  hoverTexture  = nullptr;
    sEntityTexture*  activeTexture = nullptr;

};

#endif //UI_HPP
