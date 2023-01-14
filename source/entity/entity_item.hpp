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

enum eEntityItemType : std::uint32_t { entityItemType_none      = 0,    // none
                                       entityItemType_potionHP  = 1,    // health potion
                                       entityItemType_potionMP  = 2,    // mana potion
                                       entityItemType_coin      = 3,    // coin
                                       entityItemType_rune      = 4,    // rune

                                       entityItemType_armor     = 5,    // armor
                                       entityItemType_boots     = 6,    // boots
                                       entityItemType_gloves    = 7,    // gloves
                                       entityItemType_helmet    = 8,    // helmet

                                       entityItemType_bow       = 9,    // bow
                                       entityItemType_crossbow  = 10,   // crossbow
                                       entityItemType_dagger    = 11,   // dagger
                                       entityItemType_grimoire  = 12,   // grimoire
                                       entityItemType_quiver    = 13,   // quiver
                                       entityItemType_shield    = 14,   // shield
                                       entityItemType_staff     = 15,   // staff
                                       entityItemType_wand      = 16,   // wand

                                       entityItemType_axe_one   = 17,   // one handed axe
                                       entityItemType_axe_two   = 18,   // two handed axe
                                       entityItemType_mace_one  = 19,   // one handed mace
                                       entityItemType_mace_two  = 20,   // two handed mace
                                       entityItemType_sword_one = 21,   // one handed sword
                                       entityItemType_sword_two = 22 }; // two handed sword

struct sEntityItem
{
    eEntityItemType type      = eEntityItemType::entityItemType_none;
    std::uint32_t   stackSize = 1;
    std::uint32_t   stackMax  = 1;
    std::uint32_t   goldValue = 0;
};

#endif // ENTITY_ITEM_HPP
