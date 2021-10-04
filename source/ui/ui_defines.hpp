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

#ifndef UI_DEFINE_HPP
#define UI_DEFINE_HPP

#include "../core/includes.hpp"
#include "../entity/entity_texture.hpp"
#include "../entity/entity_model.hpp"

enum class eComponentState : std::uint16_t 
{
    componentNormal    = 0, // Normal
    componentHover     = 1, // Hover
    componentActivated = 2, // Activated
};

struct sUIComponent
{
    // Linked list
    sUIComponent*    next          = nullptr;
    std::uint32_t    UID           = 0;

    // Infomation
    std::string      name          = "";
    bool             enabled       = true;
    eComponentState  state         = eComponentState::componentNormal;

    // Base
    glm::vec3       position       = glm::vec3(0.0f, 0.0f, 0.0f); // relative to owner
    glm::vec2       scale          = glm::vec2(1.0f, 1.0f);
    glm::vec3       rotation       = glm::vec3(0.0f, 0.0f, 0.0f);

    // Graphics
    sEntityModel*    model         = nullptr;
    glm::mat4        modelMatrix   = glm::mat4(1);
    sEntityTexture*  textureNormal = nullptr;
    sEntityTexture*  textureHover  = nullptr;
    sEntityTexture*  textureActive = nullptr;
};

struct sUIMenu
{
    // Components
    std::uint32_t    numComponent  = 0;
    sUIComponent*    component     = nullptr;

    // Infomation
    std::string      name          = "";
    bool             enabled       = true;

    // Base
    glm::vec3       position       = glm::vec3(0.0f, 0.0f, 0.0f); // relative to window
    glm::vec2       scale          = glm::vec2(1.0f, 1.0f);
    glm::vec3       rotation       = glm::vec3(0.0f, 0.0f, 0.0f);

    // Graphics
    sEntityModel*    model         = nullptr;
    glm::mat4        modelMatrix   = glm::mat4(1);
    sEntityTexture*  textureNormal = nullptr;
};

#endif //UI_HPP

