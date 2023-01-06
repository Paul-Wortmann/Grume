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
    componentFunctionLoadMapTown_6      = 25, // Load map town 6
    componentFunctionInventorySlot_1    = 26, // Inventory slot 1
    componentFunctionInventorySlot_2    = 27, // Inventory slot 2
    componentFunctionInventorySlot_3    = 28, // Inventory slot 3
    componentFunctionInventorySlot_4    = 29, // Inventory slot 4
    componentFunctionInventorySlot_5    = 30, // Inventory slot 5
    componentFunctionInventorySlot_6    = 31, // Inventory slot 6
    componentFunctionInventorySlot_7    = 32, // Inventory slot 7
    componentFunctionInventorySlot_8    = 33, // Inventory slot 8
    componentFunctionInventorySlot_9    = 34, // Inventory slot 9
    componentFunctionInventorySlot_10   = 35, // Inventory slot 10
    componentFunctionInventorySlot_11   = 36, // Inventory slot 11
    componentFunctionInventorySlot_12   = 37, // Inventory slot 12
    componentFunctionInventorySlot_13   = 38, // Inventory slot 13
    componentFunctionInventorySlot_14   = 39, // Inventory slot 14
    componentFunctionInventorySlot_15   = 40, // Inventory slot 15
    componentFunctionInventorySlot_16   = 41, // Inventory slot 16
    componentFunctionInventorySlot_17   = 42, // Inventory slot 17
    componentFunctionInventorySlot_18   = 43, // Inventory slot 18
    componentFunctionInventorySlot_19   = 44, // Inventory slot 19
    componentFunctionInventorySlot_20   = 45, // Inventory slot 20
    componentFunctionInventorySlot_21   = 46, // Inventory slot 21
    componentFunctionInventorySlot_22   = 47, // Inventory slot 22
    componentFunctionInventorySlot_23   = 48, // Inventory slot 23
    componentFunctionInventorySlot_24   = 49, // Inventory slot 24
    componentFunctionInventorySlot_25   = 50, // Inventory slot 25
    componentFunctionInventorySlot_26   = 51, // Inventory slot 26
    componentFunctionInventorySlot_27   = 52, // Inventory slot 27
    componentFunctionInventorySlot_28   = 53, // Inventory slot 28
    componentFunctionInventorySlot_29   = 54, // Inventory slot 29
    componentFunctionInventorySlot_30   = 55, // Inventory slot 30
    componentFunctionInventorySlot_31   = 56, // Inventory slot 31
    componentFunctionInventorySlot_32   = 57, // Inventory slot 32
    componentFunctionInventorySlot_33   = 58, // Inventory slot 33
    componentFunctionInventorySlot_34   = 59, // Inventory slot 34
    componentFunctionInventorySlot_35   = 60, // Inventory slot 35
    componentFunctionInventorySlot_36   = 61, // Inventory slot 36
    componentFunctionInventorySlot_37   = 62, // Inventory slot 37
    componentFunctionInventorySlot_38   = 63, // Inventory slot 38
    componentFunctionInventorySlot_39   = 64, // Inventory slot 39
    componentFunctionInventorySlot_40   = 65, // Inventory slot 40
    componentFunctionInventorySlot_41   = 66, // Inventory slot 41
    componentFunctionInventorySlot_42   = 67, // Inventory slot 42
    componentFunctionInventorySlot_43   = 68, // Inventory slot 43
    componentFunctionInventorySlot_44   = 69, // Inventory slot 44
    componentFunctionInventorySlot_45   = 70, // Inventory slot 45
    componentFunctionInventorySlot_46   = 71, // Inventory slot 46
    componentFunctionInventorySlot_47   = 72, // Inventory slot 47
    componentFunctionInventorySlot_48   = 73, // Inventory slot 48
    componentFunctionInventorySlot_49   = 74, // Inventory slot 49
    componentFunctionInventorySlot_50   = 75, // Inventory slot 50
    componentFunctionInventorySlot_51   = 76, // Inventory slot 51
    componentFunctionInventorySlot_52   = 77, // Inventory slot 52
    componentFunctionInventorySlot_53   = 78, // Inventory slot 53
    componentFunctionInventorySlot_54   = 79  // Inventory slot 54
};

enum class eComponentState : std::uint16_t
{
    componentStateNormal    = 0, // Normal
    componentStateHover     = 1, // Hover
    componentStateActivated = 2, // Activated
    componentStateDragged   = 3  // Dragged
};

enum class eComponentType : std::uint16_t
{
    componentTypeNormal    = 0, // Normal
    componentTypeItem      = 1  // Item
};

struct sUIComponent
{
    // Linked list
    sUIComponent*      next          = nullptr;
    std::uint32_t      UID           = 0;

    // Information
    std::string        name          = "";
    bool               enabled       = false;
    eComponentFunction function      = eComponentFunction::componentFunctionNone;
    eComponentType     type          = eComponentType::componentTypeNormal;
    eComponentState    state         = eComponentState::componentStateNormal;

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

    // Information
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

