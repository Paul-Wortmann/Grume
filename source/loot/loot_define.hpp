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

#ifndef LOOT_DEFINE_HPP
#define LOOT_DEFINE_HPP

#include "../core/includes.hpp"

enum class eLootTableEntryType : std::uint32_t
{
    lootTableEntryTypeNone   = 0, // None
    lootTableEntryTypeQuest  = 1, // Quest
    lootTableEntryTypeSet    = 2, // Set
    lootTableEntryTypeUnique = 3, // Unique
    lootTableEntryTypeNormal = 4, // Normal
    lootTableEntryTypeCoin   = 5, // Coin
    lootTableEntryTypePotion = 6  // Potion
};

struct sLootTableEntry
{
    std::uint32_t       itemID       = 0;  // position in the loot table
    std::string         entityName   = {}; // item database name
    std::uint32_t       entityNumber = 1;  // item database number

    std::uint32_t       value        = 0;  // random number generator value
    bool                dropOnce     = false;
    bool                dropUp       = false;
    std::uint32_t       dropCount    = 0;

    eLootTableEntryType itemType     = eLootTableEntryType::lootTableEntryTypeNone;
};

struct sLootTable
{
    std::uint32_t    tableValue = 0;
    std::uint32_t    numEntry   = 0;
    sLootTableEntry* entry      = nullptr;
};

struct sLootReturn
{
    std::uint32_t       itemID       = 0;  // position in the loot table
    std::string         entityName   = {}; // item database name

    eLootTableEntryType itemType     = eLootTableEntryType::lootTableEntryTypeNone;
};

#endif //LOOT_DEFINE_HPP
