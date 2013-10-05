/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
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
 * @website www.physhexgames.co.nr
 * @license GPL V3
 * @date 2011-11-11
 */

#include "items.hpp"
#include "game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

void  item_class::init_items(void) // Initialize hard-coded default items, such as health potions etc...
{
    //------------------------- Potions --------------------------------------------------------------------------
    item_type* item_health_potion = new item_type;
    item_health_potion = game.item_manager.add_item(HEALTH_POTION);
    item_health_potion->data.active                 = true;
    item_health_potion->data.name                   = "Health Potion";
    item_health_potion->data.number_of_item_effects = 1;
    item_health_potion->data.type                   = ITEM_POTION;
    item_health_potion->data.sub_type               = ITEM_POTION_LARGE;
    item_health_potion->data.effect[0]              = new effect_type;
    item_health_potion->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
};

void  item_class::use_item(int window_from, int element_from)
{
};
