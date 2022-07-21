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

#ifndef ENTITY_INTERACTION_HPP
#define ENTITY_INTERACTION_HPP

#include "../core/includes.hpp"
#include "entity_state.hpp"

enum eEntityInteraction : std::uint32_t { entityInteraction_none     = 0,    // none
                                          entityInteraction_set      = 1,    // set
                                          entityInteraction_toggle   = 2,    // toggle
                                          entityInteraction_activate = 3 };  // activate

struct sEntityInteraction
{
    bool                   triggered    = false;
    bool                   repeat       = true;

    eEntityInteraction     type         = eEntityInteraction::entityInteraction_none;
    eEntityState           state_1      = eEntityState::entityState_none;
    eEntityState           state_2      = eEntityState::entityState_none;

    bool                   affectTile   = false;
    std::uint32_t          triggerTile  = 0;
    std::uint32_t          triggerEvent = 0;

    bool                   mouse        = true; // Allow user interaction
    float                  distance     = 4; // Maximum interaction radius
};

#endif // ENTITY_INTERACTION_HPP

