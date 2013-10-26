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

#include "spell_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

spell_manager_class::spell_manager_class(void)
{
};

spell_manager_class::~spell_manager_class(void)
{
    delete [] spell_manager_class::spell;
};

spell_type* spell_manager_class::add_spell(int spell_UID)
{
    if (spell_manager_class::number_of_spells == 0)
    {
        spell_manager_class::root = new spell_type;
        spell_manager_class::root->next = NULL;
        spell_manager_class::last = new spell_type;
        spell_manager_class::last = root;
        spell_manager_class::last->next = NULL;
    }
    else
    {
        spell_type* temp_pointer;
        temp_pointer = new spell_type;
        temp_pointer = spell_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer != NULL)
            {
                if (temp_pointer->data.UID == spell_UID) return(temp_pointer);
                temp_pointer = temp_pointer->next;
            }
        }
        spell_manager_class::last->next = new spell_type;
        spell_manager_class::last = spell_manager_class::last->next;
        spell_manager_class::last->next = new spell_type;
        spell_manager_class::last->next = NULL;
    }
    spell_manager_class::last->data.active                 = false;
    spell_manager_class::last->data.name                   = "";
    spell_manager_class::last->data.UID                    = spell_UID;
    spell_manager_class::last->data.passive                = false;
    spell_manager_class::last->data.type                   = EFFECT_NONE;
    spell_manager_class::last->data.sub_type               = EFFECT_NONE;
    spell_manager_class::last->data.value                  = 0;
    spell_manager_class::number_of_spells++;
    return(spell_manager_class::last);
};

bool  spell_manager_class::use_spell(int  spell_UID, float value)
{
    bool used_item = false;
    switch (spell_UID)
    {
        case EFFECT_NONE:
        break;
        case EFFECT_MOD_HEALTH:
            if (game.player.health.current < game.player.health.maximum)
            {
                used_item = true;
                game.player.health.current += value;
            }
        break;
        case EFFECT_MOD_HEALTH_MAX:
            used_item = true;
            game.player.health.maximum += value;
        break;
        case EFFECT_MOD_HEALTH_REGEN:
            used_item = true;
            game.player.health.regeneration += value;
        break;
        case EFFECT_MOD_MANA:
            if (game.player.mana.current < game.player.mana.maximum)
            {
                used_item = true;
                game.player.mana.current += value;
            }
        break;
        case EFFECT_MOD_MANA_MAX:
            used_item = true;
            game.player.mana.maximum += value;
        break;
        case EFFECT_MOD_MANA_REGEN:
            used_item = true;
            game.player.mana.regeneration += value;
        break;
        default:
        break;
    }
    return (used_item);
};

