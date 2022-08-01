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

#ifndef UI_DEFINES_HPP
#define UI_DEFINES_HPP

#include "../core/includes.hpp"
#include "../entity/entity_model.hpp"
#include "../resource/resource_manager.hpp"

enum class eComponentFunction : std::uint16_t
{
    componentFunctionNone               =  0, // No function when clicked
    componentFunctionGameQuit           =  1, // Game quit
    componentFunctionCloseMenu          =  2, // Close menu
    componentFunctionGameNew            =  3, // Game new
    componentFunctionGameSave           =  4, // Game save
    componentFunctionGameLoad           =  5, // Game load
    componentFunctionMenuOptions        =  6, // Menu Options
    componentFunctionBarHealth          =  7, // Bar - health
    componentFunctionBarMana            =  8, // Bar - mana
    componentFunctionBarExp             =  9, // Bar - exp
    componentFunctionFullscreenModified = 10, // Fullscreen modified
    componentFunctionVolumeMusicUp      = 11, // Music volume up
    componentFunctionVolumeMusicDown    = 12, // Music volume down
    componentFunctionVolumeMusicBar     = 13, // Music volume bar
    componentFunctionVolumeSoundUp      = 14, // Sound volume up
    componentFunctionVolumeSoundDown    = 15, // Sound volume down
    componentFunctionVolumeSoundBar     = 16, // Sound volume bar
    componentFunctionVolumeMasterUp     = 17, // Master volume up
    componentFunctionVolumeMasterDown   = 18, // Master volume down
    componentFunctionVolumeMasterBar    = 19, // Master volume bar
    componentFunctionLoadMapTown_1      = 20, // Load map town 1
    componentFunctionLoadMapTown_2      = 21, // Load map town 2
    componentFunctionLoadMapTown_3      = 22, // Load map town 3
    componentFunctionLoadMapTown_4      = 23, // Load map town 4
    componentFunctionLoadMapTown_5      = 24, // Load map town 5
    componentFunctionLoadMapTown_6      = 25  // Load map town 6
};

enum class eComponentState : std::uint16_t
{
    componentNormal    = 0, // Normal
    componentHover     = 1, // Hover
    componentActivated = 2  // Activated
};

struct sUIComponent
{
    // Linked list
    sUIComponent*      next          = nullptr;
    std::uint32_t      UID           = 0;

    // Infomation
    std::string        name          = "";
    bool               enabled       = false;
    eComponentFunction function      = eComponentFunction::componentFunctionNone;
    eComponentState    state         = eComponentState::componentNormal;

    // Base
    glm::vec3          position      = glm::vec3(0.0f, 0.0f, 0.0f); // Position in OpenGL coordinate space (-1 to 1)
    glm::vec2          scale         = glm::vec2(1.0f, 1.0f); // Scale relative to OpenGL window coordinates (-1 to 1)
    glm::vec2          size          = glm::vec2(1, 1); // Size in pixels
    glm::vec2          positionMin   = glm::vec2(0, 0); // (In pixels) calculated on load, min position (top left corner)
    glm::vec2          positionMax   = glm::vec2(0, 0); // (In pixels) calculated on load, max position (bottom right corner)

    // Graphics
    glm::mat4          modelMatrix   = glm::mat4(1);
    std::uint32_t      textureNormal = 0;
    std::uint32_t      textureHover  = 0;
    std::uint32_t      textureActive = 0;
};

struct sUIMenu
{
    // Components
    std::uint32_t     numComponent  = 0;
    sUIComponent*     component     = nullptr;

    // Infomation
    std::string       name          = "";
    bool              enabled       = false;

    // Base
    glm::vec3         position      = glm::vec3(0.0f, 0.0f, 0.0f); // Position in OpenGL coordinate space (-1 to 1)
    glm::vec2         scale         = glm::vec2(1.0f, 1.0f); // Scale relative to OpenGL window coordinates (-1 to 1)
    glm::vec2         size          = glm::vec2(1, 1); // Size in pixels
    glm::vec2         positionMin   = glm::vec2(0, 0); // (In pixels) calculated on load, min position (top left corner)
    glm::vec2         positionMax   = glm::vec2(0, 0); // (In pixels) calculated on load, max position (bottom right corner)

    // Graphics
    glm::mat4         modelMatrix   = glm::mat4(1);
    std::uint32_t     textureNormal = 0;
};

#endif //UI_DEFINES_HPP

