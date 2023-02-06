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
#include "../io/io_define.hpp"
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

    componentFunctionInventoryStack_1   = 146, // Inventory slot 1 stack size text label
    componentFunctionInventoryStack_2   = 147, // Inventory slot 2 stack size text label
    componentFunctionInventoryStack_3   = 148, // Inventory slot 3 stack size text label
    componentFunctionInventoryStack_4   = 149, // Inventory slot 4 stack size text label
    componentFunctionInventoryStack_5   = 150, // Inventory slot 5 stack size text label
    componentFunctionInventoryStack_6   = 151, // Inventory slot 6 stack size text label
    componentFunctionInventoryStack_7   = 152, // Inventory slot 7 stack size text label
    componentFunctionInventoryStack_8   = 153, // Inventory slot 8 stack size text label
    componentFunctionInventoryStack_9   = 154, // Inventory slot 9 stack size text label
    componentFunctionInventoryStack_10  = 155, // Inventory slot 10 stack size text label
    componentFunctionInventoryStack_11  = 156, // Inventory slot 11 stack size text label
    componentFunctionInventoryStack_12  = 157, // Inventory slot 12 stack size text label
    componentFunctionInventoryStack_13  = 158, // Inventory slot 13 stack size text label
    componentFunctionInventoryStack_14  = 159, // Inventory slot 14 stack size text label
    componentFunctionInventoryStack_15  = 160, // Inventory slot 15 stack size text label
    componentFunctionInventoryStack_16  = 161, // Inventory slot 16 stack size text label
    componentFunctionInventoryStack_17  = 162, // Inventory slot 17 stack size text label
    componentFunctionInventoryStack_18  = 163, // Inventory slot 18 stack size text label
    componentFunctionInventoryStack_19  = 164, // Inventory slot 19 stack size text label
    componentFunctionInventoryStack_20  = 165, // Inventory slot 20 stack size text label
    componentFunctionInventoryStack_21  = 166, // Inventory slot 21 stack size text label
    componentFunctionInventoryStack_22  = 167, // Inventory slot 22 stack size text label
    componentFunctionInventoryStack_23  = 168, // Inventory slot 23 stack size text label
    componentFunctionInventoryStack_24  = 169, // Inventory slot 24 stack size text label
    componentFunctionInventoryStack_25  = 170, // Inventory slot 25 stack size text label
    componentFunctionInventoryStack_26  = 171, // Inventory slot 26 stack size text label
    componentFunctionInventoryStack_27  = 172, // Inventory slot 27 stack size text label
    componentFunctionInventoryStack_28  = 173, // Inventory slot 28 stack size text label
    componentFunctionInventoryStack_29  = 174, // Inventory slot 29 stack size text label
    componentFunctionInventoryStack_30  = 175, // Inventory slot 30 stack size text label
    componentFunctionInventoryStack_31  = 176, // Inventory slot 31 stack size text label
    componentFunctionInventoryStack_32  = 177, // Inventory slot 32 stack size text label
    componentFunctionInventoryStack_33  = 178, // Inventory slot 33 stack size text label
    componentFunctionInventoryStack_34  = 179, // Inventory slot 34 stack size text label
    componentFunctionInventoryStack_35  = 180, // Inventory slot 35 stack size text label
    componentFunctionInventoryStack_36  = 181, // Inventory slot 36 stack size text label
    componentFunctionInventoryStack_37  = 182, // Inventory slot 37 stack size text label
    componentFunctionInventoryStack_38  = 183, // Inventory slot 38 stack size text label
    componentFunctionInventoryStack_39  = 184, // Inventory slot 39 stack size text label
    componentFunctionInventoryStack_40  = 185, // Inventory slot 40 stack size text label
    componentFunctionInventoryStack_41  = 186, // Inventory slot 41 stack size text label
    componentFunctionInventoryStack_42  = 187, // Inventory slot 42 stack size text label
    componentFunctionInventoryStack_43  = 188, // Inventory slot 43 stack size text label
    componentFunctionInventoryStack_44  = 189, // Inventory slot 44 stack size text label
    componentFunctionInventoryStack_45  = 190, // Inventory slot 45 stack size text label
    componentFunctionInventoryStack_46  = 191, // Inventory slot 46 stack size text label
    componentFunctionInventoryStack_47  = 192, // Inventory slot 47 stack size text label
    componentFunctionInventoryStack_48  = 193, // Inventory slot 48 stack size text label
    componentFunctionInventoryStack_49  = 194, // Inventory slot 49 stack size text label
    componentFunctionInventoryStack_50  = 195, // Inventory slot 50 stack size text label
    componentFunctionInventoryStack_51  = 196, // Inventory slot 51 stack size text label
    componentFunctionInventoryStack_52  = 197, // Inventory slot 52 stack size text label
    componentFunctionInventoryStack_53  = 198, // Inventory slot 53 stack size text label
    componentFunctionInventoryStack_54  = 199, // Inventory slot 54 stack size text label

    componentFunctionActionBarStack_1   = 200, // Action Bar slot 1 stack size text label
    componentFunctionActionBarStack_2   = 201, // Action Bar slot 2 stack size text label
    componentFunctionActionBarStack_3   = 202, // Action Bar slot 3 stack size text label
    componentFunctionActionBarStack_4   = 203, // Action Bar slot 4 stack size text label
    componentFunctionActionBarStack_5   = 204, // Action Bar slot 5 stack size text label
    componentFunctionActionBarStack_6   = 205, // Action Bar slot 6 stack size text label
    componentFunctionActionBarStack_7   = 206, // Action Bar slot 7 stack size text label
    componentFunctionActionBarStack_8   = 207, // Action Bar slot 8 stack size text label
    componentFunctionActionBarStack_9   = 208, // Action Bar slot 9 stack size text label
    componentFunctionActionBarStack_10  = 209, // Action Bar slot 10 stack size text label
    componentFunctionActionBarStack_11  = 210, // Action Bar slot 11 stack size text label
    componentFunctionActionBarStack_12  = 211, // Action Bar slot 12 stack size text label

    componentFunctionVendorStack_1      = 212, // Vendor slot 1 stack size text label
    componentFunctionVendorStack_2      = 213, // Vendor slot 2 stack size text label
    componentFunctionVendorStack_3      = 214, // Vendor slot 3 stack size text label
    componentFunctionVendorStack_4      = 215, // Vendor slot 4 stack size text label
    componentFunctionVendorStack_5      = 216, // Vendor slot 5 stack size text label
    componentFunctionVendorStack_6      = 217, // Vendor slot 6 stack size text label
    componentFunctionVendorStack_7      = 218, // Vendor slot 7 stack size text label
    componentFunctionVendorStack_8      = 219, // Vendor slot 8 stack size text label
    componentFunctionVendorStack_9      = 220, // Vendor slot 9 stack size text label
    componentFunctionVendorStack_10     = 221, // Vendor slot 10 stack size text label
    componentFunctionVendorStack_11     = 222, // Vendor slot 11 stack size text label
    componentFunctionVendorStack_12     = 223, // Vendor slot 12 stack size text label
    componentFunctionVendorStack_13     = 224, // Vendor slot 13 stack size text label
    componentFunctionVendorStack_14     = 225, // Vendor slot 14 stack size text label
    componentFunctionVendorStack_15     = 226, // Vendor slot 15 stack size text label
    componentFunctionVendorStack_16     = 227, // Vendor slot 16 stack size text label
    componentFunctionVendorStack_17     = 228, // Vendor slot 17 stack size text label
    componentFunctionVendorStack_18     = 229, // Vendor slot 18 stack size text label
    componentFunctionVendorStack_19     = 230, // Vendor slot 19 stack size text label
    componentFunctionVendorStack_20     = 231, // Vendor slot 20 stack size text label
    componentFunctionVendorStack_21     = 232, // Vendor slot 21 stack size text label
    componentFunctionVendorStack_22     = 233, // Vendor slot 22 stack size text label
    componentFunctionVendorStack_23     = 234, // Vendor slot 23 stack size text label
    componentFunctionVendorStack_24     = 235, // Vendor slot 24 stack size text label
    componentFunctionVendorStack_25     = 236, // Vendor slot 25 stack size text label
    componentFunctionVendorStack_26     = 237, // Vendor slot 26 stack size text label
    componentFunctionVendorStack_27     = 238, // Vendor slot 27 stack size text label
    componentFunctionVendorStack_28     = 239, // Vendor slot 28 stack size text label
    componentFunctionVendorStack_29     = 240, // Vendor slot 29 stack size text label
    componentFunctionVendorStack_30     = 241, // Vendor slot 30 stack size text label
    componentFunctionVendorStack_31     = 242, // Vendor slot 31 stack size text label
    componentFunctionVendorStack_32     = 243, // Vendor slot 32 stack size text label
    componentFunctionVendorStack_33     = 244, // Vendor slot 33 stack size text label
    componentFunctionVendorStack_34     = 245, // Vendor slot 34 stack size text label
    componentFunctionVendorStack_35     = 246, // Vendor slot 35 stack size text label
    componentFunctionVendorStack_36     = 247, // Vendor slot 36 stack size text label
    componentFunctionVendorStack_37     = 248, // Vendor slot 37 stack size text label
    componentFunctionVendorStack_38     = 249, // Vendor slot 38 stack size text label
    componentFunctionVendorStack_39     = 250, // Vendor slot 39 stack size text label
    componentFunctionVendorStack_40     = 251, // Vendor slot 40 stack size text label
    componentFunctionVendorStack_41     = 252, // Vendor slot 41 stack size text label
    componentFunctionVendorStack_42     = 253, // Vendor slot 42 stack size text label
    componentFunctionVendorStack_43     = 254, // Vendor slot 43 stack size text label
    componentFunctionVendorStack_44     = 255, // Vendor slot 44 stack size text label
    componentFunctionVendorStack_45     = 256, // Vendor slot 45 stack size text label
    componentFunctionVendorStack_46     = 257, // Vendor slot 46 stack size text label
    componentFunctionVendorStack_47     = 258, // Vendor slot 47 stack size text label
    componentFunctionVendorStack_48     = 259, // Vendor slot 48 stack size text label
    componentFunctionVendorStack_49     = 260, // Vendor slot 49 stack size text label
    componentFunctionVendorStack_50     = 261, // Vendor slot 50 stack size text label
    componentFunctionVendorStack_51     = 262, // Vendor slot 51 stack size text label
    componentFunctionVendorStack_52     = 263, // Vendor slot 52 stack size text label
    componentFunctionVendorStack_53     = 264, // Vendor slot 53 stack size text label
    componentFunctionVendorStack_54     = 265, // Vendor slot 54 stack size text label

    componentFunctionEquipmentSlot_1    = 266, // Equipment slot 1
    componentFunctionEquipmentSlot_2    = 267, // Equipment slot 2
    componentFunctionEquipmentSlot_3    = 268, // Equipment slot 3
    componentFunctionEquipmentSlot_4    = 269, // Equipment slot 4
    componentFunctionEquipmentSlot_5    = 270, // Equipment slot 5
    componentFunctionEquipmentSlot_6    = 271, // Equipment slot 6
    componentFunctionEquipmentSlot_7    = 272, // Equipment slot 7
    componentFunctionEquipmentSlot_8    = 273, // Equipment slot 8
    componentFunctionEquipmentSlot_9    = 274, // Equipment slot 9
    componentFunctionEquipmentSlot_10   = 275, // Equipment slot 10
    componentFunctionEquipmentSlot_11   = 276, // Equipment slot 11
    componentFunctionEquipmentSlot_12   = 277, // Equipment slot 12
    componentFunctionEquipmentSlot_13   = 278, // Equipment slot 13
    componentFunctionEquipmentSlot_14   = 279, // Equipment slot 14

    componentFunctionEquipmentStack_1   = 280, // Equipment slot 1 stack size text label
    componentFunctionEquipmentStack_2   = 281, // Equipment slot 2 stack size text label
    componentFunctionEquipmentStack_3   = 282, // Equipment slot 3 stack size text label
    componentFunctionEquipmentStack_4   = 283, // Equipment slot 4 stack size text label
    componentFunctionEquipmentStack_5   = 284, // Equipment slot 5 stack size text label
    componentFunctionEquipmentStack_6   = 285, // Equipment slot 6 stack size text label
    componentFunctionEquipmentStack_7   = 286, // Equipment slot 7 stack size text label
    componentFunctionEquipmentStack_8   = 287, // Equipment slot 8 stack size text label
    componentFunctionEquipmentStack_9   = 288, // Equipment slot 9 stack size text label
    componentFunctionEquipmentStack_10  = 289, // Equipment slot 10 stack size text label
    componentFunctionEquipmentStack_11  = 290, // Equipment slot 11 stack size text label
    componentFunctionEquipmentStack_12  = 291, // Equipment slot 12 stack size text label
    componentFunctionEquipmentStack_13  = 292, // Equipment slot 13 stack size text label
    componentFunctionEquipmentStack_14  = 293, // Equipment slot 14 stack size text label

    componentFunctionWaypointsSlot_1    = 294, // Waypoints slot 1
    componentFunctionWaypointsSlot_2    = 295, // Waypoints slot 2
    componentFunctionWaypointsSlot_3    = 296, // Waypoints slot 3
    componentFunctionWaypointsSlot_4    = 297, // Waypoints slot 4
    componentFunctionWaypointsSlot_5    = 298, // Waypoints slot 5
    componentFunctionWaypointsSlot_6    = 299, // Waypoints slot 6

    componentFunctionWaypointsStack_1   = 300, // Waypoints slot 1 stack size text label
    componentFunctionWaypointsStack_2   = 301, // Waypoints slot 1 stack size text label
    componentFunctionWaypointsStack_3   = 302, // Waypoints slot 1 stack size text label
    componentFunctionWaypointsStack_4   = 303, // Waypoints slot 1 stack size text label
    componentFunctionWaypointsStack_5   = 304, // Waypoints slot 1 stack size text label
    componentFunctionWaypointsStack_6   = 305, // Waypoints slot 1 stack size text label

    componentFunctionTextGold           = 306  // Gold text

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
    sUIComponent*      next           = nullptr;
    std::uint32_t      UID            = 0;

    // Information
    std::string        name           = "";
    bool               enabled        = false;
    eComponentFunction function       = eComponentFunction::componentFunctionNone;
    eComponentType     type           = eComponentType::componentTypeNormal;
    eComponentState    state          = eComponentState::componentStateNormal;

    // Base
    glm::vec3          position       = glm::vec3(0.0f, 0.0f, 0.0f); // Position in OpenGL coordinate space (-1 to 1)
    glm::vec2          size           = glm::vec2(1, 1); // Size in OpenGL coordinate space
    glm::vec2          positionMin    = glm::vec2(0, 0); // (In OpenGL coordinate space) calculated on load, min position (top left corner)
    glm::vec2          positionMax    = glm::vec2(0, 0); // (In OpenGL coordinate space) calculated on load, max position (bottom right corner)

    // Graphics
    glm::mat4          modelMatrix    = glm::mat4(1);
    std::uint32_t      textureNormal  = 0;
    std::uint32_t      textureHover   = 0;
    std::uint32_t      textureActive  = 0;

    // Audio
    sUIAudioData       audio_activate = {};
    sUIAudioData       audio_hover    = {};
};

enum class eMenuType : std::uint16_t
{
    menuTypeNone      = 0, // None
    menuTypeActionBar = 1, // Action Bar
    menuTypeMain      = 2, // Main
    menuTypeOptions   = 3, // Options
    menuTypeCharacter = 4, // Character
    menuTypeEquipment = 5, // Equipment
    menuTypeInventory = 6, // Inventory
    menuTypeSkills    = 7, // Skills
    menuTypeVendor    = 8, // Vendor
    menuTypeWayPoints = 9  // Way points
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

// Event type enum
enum eUIEventType : std::uint32_t
{
    UIEventType_none        = 0, // null event
    UIEventType_click       = 1, // click event
    UIEventType_drag        = 2, // drag event
    UIEventType_dropGround  = 3, // drop ground event
    UIEventType_dropMenu    = 4, // drop menu event
    UIEventType_setSlotType = 5  // component slot type
};

// Event function enum
enum eUIEventFunction : std::uint32_t
{
    UIEventFunction_none               =  0,  // null event
    UIEventFunction_closeMenu          =  1,  // Close menu
    UIEventFunction_gameQuit           =  2,  // Game quit
    UIEventFunction_gameNew            =  3,  // Game new
    UIEventFunction_gameSave           =  4,  // Game save
    UIEventFunction_gameLoad           =  5,  // Game load
    UIEventFunction_menuOptions        =  6,  // Menu Options
    UIEventFunction_fullscreenModified =  7,  // Fullscreen modified
    UIEventFunction_volumeMusicUp      =  8,  // Music volume up
    UIEventFunction_volumeMusicDown    =  9,  // Music volume down
    UIEventFunction_volumeSoundUp      = 10,  // Sound volume up
    UIEventFunction_volumeSoundDown    = 11,  // Sound volume down
    UIEventFunction_volumeMasterUp     = 12,  // Master volume up
    UIEventFunction_volumeMasterDown   = 13,  // Master volume down
    UIEventFunction_loadMapTown        = 14,  // Load map town
    UIEventFunction_actionBar          = 15,  // actionBar storage
    UIEventFunction_equipment          = 16,  // equipment storage
    UIEventFunction_inventory          = 17,  // inventory storage
    UIEventFunction_vendor             = 18,  // vendor storage
    UIEventFunction_waypoints          = 19,  // waypoints storage
    UIEventFunction_componentSlotType  = 20   // component slot type
};

// Event struct
struct sUIEvent
{
    sUIEvent*        next       = nullptr;
    eUIEventType     type       = eUIEventType::UIEventType_none;
    eUIEventFunction function_1 = eUIEventFunction::UIEventFunction_none;
    std::uint32_t    data_1     = 0;
    eUIEventFunction function_2 = eUIEventFunction::UIEventFunction_none;
    std::uint32_t    data_2     = 0;
};

#endif //UI_DEFINES_HPP

