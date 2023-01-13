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

#include "../audio/audio_defines.hpp"
#include "../audio/audio_engine.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_model.hpp"
#include "../resource/database_manager.hpp"
#include "../resource/resource_manager.hpp"

struct sUIAudioData
{
    std::string   name     = {};
    std::uint32_t number   = {};
    sAudio*       sound    = nullptr;
};

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
    componentFunctionInventorySlot_54   = 79, // Inventory slot 54

    componentFunctionActionBarSlot_1    = 80, // Action Bar slot 1
    componentFunctionActionBarSlot_2    = 81, // Action Bar slot 2
    componentFunctionActionBarSlot_3    = 82, // Action Bar slot 3
    componentFunctionActionBarSlot_4    = 83, // Action Bar slot 4
    componentFunctionActionBarSlot_5    = 84, // Action Bar slot 5
    componentFunctionActionBarSlot_6    = 85, // Action Bar slot 6
    componentFunctionActionBarSlot_7    = 86, // Action Bar slot 7
    componentFunctionActionBarSlot_8    = 87, // Action Bar slot 8
    componentFunctionActionBarSlot_9    = 88, // Action Bar slot 9
    componentFunctionActionBarSlot_10   = 89, // Action Bar slot 10
    componentFunctionActionBarSlot_11   = 90, // Action Bar slot 11
    componentFunctionActionBarSlot_12   = 91, // Action Bar slot 12

    componentFunctionVendorSlot_1       = 92, // Vendor slot 1
    componentFunctionVendorSlot_2       = 93, // Vendor slot 2
    componentFunctionVendorSlot_3       = 94, // Vendor slot 3
    componentFunctionVendorSlot_4       = 95, // Vendor slot 4
    componentFunctionVendorSlot_5       = 96, // Vendor slot 5
    componentFunctionVendorSlot_6       = 97, // Vendor slot 6
    componentFunctionVendorSlot_7       = 98, // Vendor slot 7
    componentFunctionVendorSlot_8       = 99, // Vendor slot 8
    componentFunctionVendorSlot_9       = 100, // Vendor slot 9
    componentFunctionVendorSlot_10      = 101, // Vendor slot 10
    componentFunctionVendorSlot_11      = 102, // Vendor slot 11
    componentFunctionVendorSlot_12      = 103, // Vendor slot 12
    componentFunctionVendorSlot_13      = 104, // Vendor slot 13
    componentFunctionVendorSlot_14      = 105, // Vendor slot 14
    componentFunctionVendorSlot_15      = 106, // Vendor slot 15
    componentFunctionVendorSlot_16      = 107, // Vendor slot 16
    componentFunctionVendorSlot_17      = 108, // Vendor slot 17
    componentFunctionVendorSlot_18      = 109, // Vendor slot 18
    componentFunctionVendorSlot_19      = 110, // Vendor slot 19
    componentFunctionVendorSlot_20      = 111, // Vendor slot 20
    componentFunctionVendorSlot_21      = 112, // Vendor slot 21
    componentFunctionVendorSlot_22      = 113, // Vendor slot 22
    componentFunctionVendorSlot_23      = 114, // Vendor slot 23
    componentFunctionVendorSlot_24      = 115, // Vendor slot 24
    componentFunctionVendorSlot_25      = 116, // Vendor slot 25
    componentFunctionVendorSlot_26      = 117, // Vendor slot 26
    componentFunctionVendorSlot_27      = 118, // Vendor slot 27
    componentFunctionVendorSlot_28      = 119, // Vendor slot 28
    componentFunctionVendorSlot_29      = 120, // Vendor slot 29
    componentFunctionVendorSlot_30      = 121, // Vendor slot 30
    componentFunctionVendorSlot_31      = 122, // Vendor slot 31
    componentFunctionVendorSlot_32      = 123, // Vendor slot 32
    componentFunctionVendorSlot_33      = 124, // Vendor slot 33
    componentFunctionVendorSlot_34      = 125, // Vendor slot 34
    componentFunctionVendorSlot_35      = 126, // Vendor slot 35
    componentFunctionVendorSlot_36      = 127, // Vendor slot 36
    componentFunctionVendorSlot_37      = 128, // Vendor slot 37
    componentFunctionVendorSlot_38      = 129, // Vendor slot 38
    componentFunctionVendorSlot_39      = 130, // Vendor slot 39
    componentFunctionVendorSlot_40      = 131, // Vendor slot 40
    componentFunctionVendorSlot_41      = 132, // Vendor slot 41
    componentFunctionVendorSlot_42      = 133, // Vendor slot 42
    componentFunctionVendorSlot_43      = 134, // Vendor slot 43
    componentFunctionVendorSlot_44      = 135, // Vendor slot 44
    componentFunctionVendorSlot_45      = 136, // Vendor slot 45
    componentFunctionVendorSlot_46      = 137, // Vendor slot 46
    componentFunctionVendorSlot_47      = 138, // Vendor slot 47
    componentFunctionVendorSlot_48      = 139, // Vendor slot 48
    componentFunctionVendorSlot_49      = 140, // Vendor slot 49
    componentFunctionVendorSlot_50      = 141, // Vendor slot 50
    componentFunctionVendorSlot_51      = 142, // Vendor slot 51
    componentFunctionVendorSlot_52      = 143, // Vendor slot 52
    componentFunctionVendorSlot_53      = 144, // Vendor slot 53
    componentFunctionVendorSlot_54      = 145, // Vendor slot 54

    componentFunctionTextGold           = 146  // Gold text

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
    componentTypeItem      = 1, // Item
    componentTypeText      = 2  // Text
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
    glm::vec3         position       = glm::vec3(0.0f, 0.0f, 0.0f); // Position in OpenGL coordinate space (-1 to 1)
    glm::vec2         size           = glm::vec2(1, 1); // Size in OpenGL coordinate space
    glm::vec2         positionMin    = glm::vec2(0, 0); // (In OpenGL coordinate space) calculated on load, min position (top left corner)
    glm::vec2         positionMax    = glm::vec2(0, 0); // (In OpenGL coordinate space) calculated on load, max position (bottom right corner)

    // Graphics
    glm::mat4          modelMatrix   = glm::mat4(1);
    std::uint32_t      textureNormal = 0;
    std::uint32_t      textureHover  = 0;
    std::uint32_t      textureActive = 0;

    // Audio
    sUIAudioData      audio_activate = {};
    sUIAudioData      audio_hover    = {};
};

enum class eMenuType : std::uint16_t
{
    menuTypeNone      = 0, // None
    menuTypeActionBar = 1, // Action Bar
    menuTypeMain      = 2, // Main
    menuTypeOptions   = 3, // Options
    menuTypeCharacter = 4, // Character
    menuTypeInventory = 5, // Inventory
    menuTypeSkills    = 6, // Skills
    menuTypeVendor    = 7, // Vendor
    menuTypeWayPoints = 8  // Way points
};

struct sUIMenu
{
    // Components
    std::uint32_t     numComponent   = 0;
    sUIComponent*     component      = nullptr;

    // Information
    std::string       name           = "";
    bool              enabled        = false;
    eMenuType         type           = eMenuType::menuTypeNone;

    // Base
    glm::vec3         position       = glm::vec3(0.0f, 0.0f, 0.0f); // Position in OpenGL coordinate space (-1 to 1)
    glm::vec2         size           = glm::vec2(1, 1); // Size in OpenGL coordinate space
    glm::vec2         positionMin    = glm::vec2(0, 0); // (In OpenGL coordinate space) calculated on load, min position (top left corner)
    glm::vec2         positionMax    = glm::vec2(0, 0); // (In OpenGL coordinate space) calculated on load, max position (bottom right corner)

    // Graphics
    glm::mat4         modelMatrix    = glm::mat4(1);
    std::uint32_t     textureNormal  = 0;

    // Audio
    sUIAudioData      audio_open     = {};
    sUIAudioData      audio_close    = {};
};

#endif //UI_DEFINES_HPP

