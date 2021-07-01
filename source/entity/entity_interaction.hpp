/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
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
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */
 
#ifndef ENTITY_INTERACTION_HPP
#define ENTITY_INTERACTION_HPP

#include "../core/includes.hpp"

enum eEntityInteractionType: uint16
{
    InteractionTypeToggle     = 0,
    InteractionTypeSet        = 1
};

struct sEntityInteraction
{
    // 0 = toggle states; 1 = set state
    eEntityInteractionType  type   = eEntityInteractionType::InteractionTypeToggle;
    std::uint32_t           data_1 = 0;
    std::uint32_t           data_2 = 0;
};

#endif // ENTITY_INTERACTION_HPP

