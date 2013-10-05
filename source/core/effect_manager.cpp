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

#include "effect_manager.hpp"
#include "../game/game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

effect_manager_class::effect_manager_class(void)
{
};

effect_manager_class::~effect_manager_class(void)
{
    delete [] effect_manager_class::effect;
};

effect_type* effect_manager_class::add_effect(int effect_UID)
{
    if (effect_manager_class::number_of_effects == 0)
    {
        effect_manager_class::root = new effect_type;
        effect_manager_class::root->next = NULL;
        effect_manager_class::last = new effect_type;
        effect_manager_class::last = root;
        effect_manager_class::last->next = NULL;
    }
    else
    {
        effect_type* temp_pointer;
        temp_pointer = new effect_type;
        temp_pointer = effect_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer->next != NULL)
            {
                if (temp_pointer->data.UID == effect_UID)
                {
                    return(temp_pointer);
                }
                temp_pointer = temp_pointer->next;
            }
        }
        effect_manager_class::last->next = new effect_type;
        effect_manager_class::last = effect_manager_class::last->next;
        effect_manager_class::last->next = new effect_type;
        effect_manager_class::last->next = NULL;
    }
    effect_manager_class::last->data.active                 = false;
    effect_manager_class::last->data.name                   = "";
    effect_manager_class::last->data.UID                    = effect_UID;
    effect_manager_class::last->data.passive                = false;
    effect_manager_class::last->data.type                   = EFFECT_NONE;
    effect_manager_class::last->data.sub_type               = EFFECT_NONE;
    effect_manager_class::last->data.value                  = 0;
    effect_manager_class::number_of_effects++;
    return(effect_manager_class::last);
};

