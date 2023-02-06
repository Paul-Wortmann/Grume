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

#ifndef PLAYER_STORAGE_DEFINE_HPP
#define PLAYER_STORAGE_DEFINE_HPP

#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"

enum class ePlayerStorageSlotType : std::uint16_t
{
    playerStorageSlotTypeNone      =  0, // None
    playerStorageSlotTypePotion    =  1, // Potion
    playerStorageSlotTypeSkill     =  2, // Skill

    playerStorageSlotTypeWeapon    =  3, // Weapon
    playerStorageSlotTypeShield    =  4, // Shield
    playerStorageSlotTypeHelm      =  5, // Helm
    playerStorageSlotTypeArmor     =  6, // Armor
    playerStorageSlotTypeGloves    =  7, // Gloves
    playerStorageSlotTypeBoots     =  8, // Boots
    playerStorageSlotTypeBelt      =  9, // Belt
    playerStorageSlotTypeAmulet    = 10, // Amulet
    playerStorageSlotTypeRing      = 11, // Ring

    playerStorageSlotTypeRune_1    = 12, // Rune 1
    playerStorageSlotTypeRune_2    = 13, // Rune 2
    playerStorageSlotTypeRune_3    = 14, // Rune 3
    playerStorageSlotTypeRune_4    = 15, // Rune 4
    playerStorageSlotTypeRune_5    = 16, // Rune 5
    playerStorageSlotTypeRune_6    = 17  // Rune 6
};

enum class ePlayerStorageType : std::uint16_t
{
    playerStorageTypeNone      = 0, // None
    playerStorageTypeActionBar = 1, // Action-bar
    playerStorageTypeEquipment = 2, // Equipment
    playerStorageTypeInventory = 3, // Inventory
    playerStorageTypeSkills    = 4, // Skills
    playerStorageTypeVendor    = 5, // Vendor
    playerStorageTypeWaypoints = 6  // Way-points
};

// Player storage slot struct
struct sPlayerStorageSlot
{
    ePlayerStorageSlotType type       =  ePlayerStorageSlotType::playerStorageSlotTypeNone;
    bool                   dragged    = false;
    bool                   occupied   = false;
    sEntity*               entity     = nullptr;
    std::uint32_t          data       = 0;
    sTexture*              stackLabel = nullptr;
};

// Player storage struct
struct sPlayerStorage
{
    ePlayerStorageType  type        = ePlayerStorageType::playerStorageTypeNone;
    std::uint32_t       numSlot     = 0;
    std::uint32_t       numFreeSlot = 0;
    sPlayerStorageSlot* slot        = nullptr;
};

#endif // PLAYER_STORAGE_DEFINE_HPP
