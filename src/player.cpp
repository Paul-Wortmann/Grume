/**
 * Copyright (C) 2011 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "player.hpp"

stat_class::stat_class(void)
{
    stat_class::current      = 0.0f;
    stat_class::maximum      = 0.0f;
    stat_class::regeneration = 0.0f;
}

stat_class::~stat_class(void)
{

}

void stat_class::process(void)
{
    if (stat_class::current < stat_class::maximum) stat_class::current += stat_class::regeneration;
    if (stat_class::current > stat_class::maximum) stat_class::current  = stat_class::maximum;
}

void stat_class::draw(void)
{

}

//-----------------------------------------------------------------------------------------------------------------

player_class::player_class(void)
{
    player_class::name         = "Player_Name";
    player_class::level        = 0;
    player_class::next_level   = 0u;
    player_class::exprience    = 0u;
    player_class::gold         = 0u;
    player_class::pos_x        = 0.0f;
    player_class::pos_y        = 0.0f;
    player_class::pos_z        = 0.0f;
}

player_class::~player_class(void)
{

}

void player_class::process(void)
{
    player_class::health.process();
    player_class::mana.process();
}

void player_class::draw(void)
{

}

