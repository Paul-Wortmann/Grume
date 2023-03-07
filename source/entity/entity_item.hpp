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

#ifndef ENTITY_ITEM_HPP
#define ENTITY_ITEM_HPP

#include "../core/includes.hpp"

enum eEntityItemType : std::uint32_t
{
    entityItemType_none      =  0,   // none
    entityItemType_potionHP  =  1,   // health potion
    entityItemType_potionMP  =  2,   // mana potion
    entityItemType_coin      =  3,   // coin
    entityItemType_rune_1    =  4,   // rune 1
    entityItemType_rune_2    =  5,   // rune 2
    entityItemType_rune_3    =  6,   // rune 3
    entityItemType_rune_4    =  7,   // rune 4
    entityItemType_rune_5    =  8,   // rune 5
    entityItemType_rune_6    =  9,   // rune 6

    entityItemType_armor     = 10,   // armor
    entityItemType_boots     = 11,   // boots
    entityItemType_gloves    = 12,   // gloves
    entityItemType_helmet    = 13,   // helmet
    entityItemType_belt      = 14,   // belt

    entityItemType_bow       = 15,   // bow
    entityItemType_crossbow  = 16,   // crossbow
    entityItemType_dagger    = 17,   // dagger
    entityItemType_grimoire  = 18,   // grimoire
    entityItemType_quiver    = 19,   // quiver
    entityItemType_shield    = 20,   // shield
    entityItemType_staff     = 21,   // staff
    entityItemType_wand      = 22,   // wand

    entityItemType_axe_one   = 23,   // one handed axe
    entityItemType_axe_two   = 24,   // two handed axe
    entityItemType_mace_one  = 25,   // one handed mace
    entityItemType_mace_two  = 26,   // two handed mace
    entityItemType_sword_one = 27,   // one handed sword
    entityItemType_sword_two = 28,   // two handed sword

    entityItemType_ring      = 29,   // ring
    entityItemType_amulet    = 30    // amulet
};

struct sEntityItemAttributes
{
    std::uint32_t         strength  = 0;
    std::uint32_t         dexterity = 0;
    std::uint32_t         vitality  = 0;
    std::uint32_t         energy    = 0;
};

struct sEntityItem
{
    eEntityItemType       type      = eEntityItemType::entityItemType_none;
    std::uint32_t         stackSize = 1;
    std::uint32_t         stackMax  = 1;

    std::uint32_t         goldValue = 0;
    sEntityItemAttributes attribute = {};
};

#endif // ENTITY_ITEM_HPP
