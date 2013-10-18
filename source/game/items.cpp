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
    item_type*      temp_item_pointer;
    //------------------------- Health Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_HEALTH_POTION);
    temp_item_pointer->data.name                   = "Health Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_23.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    //------------------------- Mana Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_MANA_POTION);
    temp_item_pointer->data.name                   = "Mana Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_22.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
    //------------------------- Rejuvination Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_REJUVENATION_POTION);
    temp_item_pointer->data.name                   = "Rejuvenation Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 2;
    temp_item_pointer->data.image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
    temp_item_pointer->data.sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0]              = new effect_type;
    temp_item_pointer->data.effect[0]              = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    temp_item_pointer->data.effect[1]              = new effect_type;
    temp_item_pointer->data.effect[1]              = game.effect_manager.add_effect(EFFECT_MOD_MANA);
    //------------------------------------------------------------------------------------------------------------
    game.item_manager.load_items("data/scripts/items.txt");
};
