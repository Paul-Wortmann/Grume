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

enum eEntityInteractionType: std::uint16_t
{
    InteractionTypeToggle     = 0,
    InteractionTypeSet        = 1,
    InteractionTypeActivate   = 2
};

struct sEntityInteraction
{
    // 0 = toggle states; 1 = set state
    eEntityInteractionType type     = eEntityInteractionType::InteractionTypeToggle;
    std::uint32_t          data_1   = 0;
    std::uint32_t          data_2   = 0;
    float                  distance = 4; // Maximum interaction radius
};

#endif // ENTITY_INTERACTION_HPP

