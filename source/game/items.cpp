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
    //------------------------- Fire Arrow --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_ARROW_FIRE);
    temp_item_pointer->data.name                   = "Fire Arrow";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/fire-arrows-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_ARROW_FIRE;
    //------------------------- Ice Arrow --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_ARROW_ICE);
    temp_item_pointer->data.name                   = "Ice Arrow";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/ice-blue-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_ARROW_ICE;
    //------------------------- Lightning Arrow --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_ARROW_LIGHTNING);
    temp_item_pointer->data.name                   = "Lightning Arrow";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/lightning-blue-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_ARROW_LIGHTNING;
    //------------------------- Elemental Arrow --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_ARROW_ELEMENTAL);
    temp_item_pointer->data.name                   = "Elemental Arrow";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/beam-royal-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_ARROW_ELEMENTAL;
    //------------------------- Fire Ball --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_BALL_FIRE);
    temp_item_pointer->data.name                   = "Fire Ball";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/fireball-red-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_BALL_FIRE;
    //------------------------- Ice Ball --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_BALL_ICE);
    temp_item_pointer->data.name                   = "Ice Ball";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/fireball-sky-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_BALL_ICE;
    //------------------------- Lightning Ball --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_BALL_LIGHTNING);
    temp_item_pointer->data.name                   = "Lightning Ball";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/light-blue-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_BALL_LIGHTNING;
    //------------------------- Elemental Ball --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_BALL_ELEMENTAL);
    temp_item_pointer->data.name                   = "Elemental Ball";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/explosion-royal-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_BALL_ELEMENTAL;

    //------------------------- Fire Shield --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_SHIELD_FIRE);
    temp_item_pointer->data.name                   = "Fire Shield";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-red-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_SHIELD_FIRE;
    //------------------------- Ice Shield --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_SHIELD_ICE);
    temp_item_pointer->data.name                   = "Ice Shield";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-blue-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_SHIELD_ICE;
    //------------------------- Lightning Shield --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_SHIELD_LIGHTNING);
    temp_item_pointer->data.name                   = "Lightning Shield";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-sky-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_SHIELD_LIGHTNING;
    //------------------------- Elemental Shield --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_SHIELD_ELEMENTAL);
    temp_item_pointer->data.name                   = "Elemental Shield";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/protect-acid-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_SHIELD_ELEMENTAL;
    //------------------------- Heal --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_SPELL_HEAL);
    temp_item_pointer->data.name                   = "Heal";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.spell                  = true;
    temp_item_pointer->data.quantity_max           = 1;
    temp_item_pointer->data.number_of_item_effects = 0;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/spells/heal-royal-1.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_SPELL;
    temp_item_pointer->data.sub_type               = ITEM_SPELL_HEAL;

    //------------------------- Health Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_S_HEALTH);
    temp_item_pointer->data.name                   = "Small Health Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_01.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_SMALL;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.effect[0].value        = 5;
    //------------------------- Health Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_M_HEALTH);
    temp_item_pointer->data.name                   = "Medium Health Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_02.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_MEDIUM;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.effect[0].value        = 15;
    //------------------------- Health Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_L_HEALTH);
    temp_item_pointer->data.name                   = "Large Health Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_23.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.effect[0].value        = 45;
    //------------------------- Mana Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_S_MANA);
    temp_item_pointer->data.name                   = "Small Mana Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_08.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_SMALL;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_MANA;
    temp_item_pointer->data.effect[0].value        = 5;
    //------------------------- Mana Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_M_MANA);
    temp_item_pointer->data.name                   = "Medium Mana Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_09.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_MEDIUM;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_MANA;
    temp_item_pointer->data.effect[0].value        = 15;
    //------------------------- Mana Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_L_MANA);
    temp_item_pointer->data.name                   = "Large Mana Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 1;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_22.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_MANA;
    temp_item_pointer->data.effect[0].value        = 45;
    //------------------------- Rejuvination Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_S_REJUVENATION);
    temp_item_pointer->data.name                   = "Small Rejuvenation Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 2;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_SMALL;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.effect[0].value        = 5;
    temp_item_pointer->data.effect[1].enabled      = true;
    temp_item_pointer->data.effect[1].type         = EFFECT_MOD_MANA;
    temp_item_pointer->data.effect[1].value        = 5;
    //------------------------- Rejuvination Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_M_REJUVENATION);
    temp_item_pointer->data.name                   = "Medium Rejuvenation Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 2;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_MEDIUM;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.effect[0].value        = 15;
    temp_item_pointer->data.effect[1].enabled      = true;
    temp_item_pointer->data.effect[1].type         = EFFECT_MOD_MANA;
    temp_item_pointer->data.effect[1].value        = 15;
    //------------------------- Rejuvination Potion --------------------------------------------------------------------------
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_L_REJUVENATION);
    temp_item_pointer->data.name                   = "Large Rejuvenation Potion";
    temp_item_pointer->data.active                 = true;
    temp_item_pointer->data.consumable             = true;
    temp_item_pointer->data.stackable              = true;
    temp_item_pointer->data.quantity_max           = 100;
    temp_item_pointer->data.number_of_item_effects = 2;
    temp_item_pointer->data.image.level_0          = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_24.png");
    temp_item_pointer->data.sound.on_move          = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
    temp_item_pointer->data.sound.on_use           = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    temp_item_pointer->data.type                   = ITEM_POTION;
    temp_item_pointer->data.sub_type               = ITEM_POTION_LARGE;
    temp_item_pointer->data.effect[0].enabled      = true;
    temp_item_pointer->data.effect[0].type         = EFFECT_MOD_HEALTH;
    temp_item_pointer->data.effect[0].value        = 45;
    temp_item_pointer->data.effect[1].enabled      = true;
    temp_item_pointer->data.effect[1].type         = EFFECT_MOD_MANA;
    temp_item_pointer->data.effect[1].value        = 45;
    //------------------------------------------------------------------------------------------------------------
    game.item_manager.load_items("data/scripts/items.txt");
};

