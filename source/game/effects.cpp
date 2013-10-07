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

#include "effects.hpp"
#include "game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------------------------------------------------
void  effect_class::init_effects(void) // Initialize hard-coded default effects, such as mod health etc...
{
    effect_type* temp_effect_pointer;
    //------------------------- Mod Health Effect --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_HEALTH);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mod Player Health";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 10.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_HEALTH;
    temp_effect_pointer->data.sub_type = ITEM_POTION_SMALL;
    //------------------------- Mod Mana Effect --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MANA);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mod Player Mana";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 10.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MANA;
    temp_effect_pointer->data.sub_type = ITEM_POTION_SMALL;
    //------------------------- Mod Mana Effect --------------------------------------------------------------------------
    temp_effect_pointer                = game.effect_manager.add_effect(EFFECT_MOD_MANA_HEALTH);
    temp_effect_pointer->data.active   = true;
    temp_effect_pointer->data.name     = "Mod Player Mana + health";
    temp_effect_pointer->data.passive  = false;
    temp_effect_pointer->data.value    = 10.0f;
    temp_effect_pointer->data.type     = EFFECT_MOD_MANA_HEALTH;
    temp_effect_pointer->data.sub_type = ITEM_POTION_SMALL;
}

void  effect_class::use_effect(int effect_UID, float value)
{
    // redundant function? O_o
    switch (effect_UID)
    {
        case EFFECT_NONE:
        break;
        case EFFECT_MOD_HEALTH:
            game.player.health.current += value;
        break;
        case EFFECT_MOD_MANA:
            game.player.mana.current   += value;
        break;
        default:
        break;
    }
};
