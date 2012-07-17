/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "npc.hpp"
#include "game.hpp"

extern game_class game;

health_bar_class::health_bar_class(void)
{
    health_bar_class::texture_base  = 0;
    health_bar_class::texture_bar   = 0;
    health_bar_class::texture_front = 0;
    health_bar_class::size_x        = 0.8f;
    health_bar_class::size_y        = health_bar_class::size_x/4.0f;
    health_bar_class::size_z        = 0.0f;
    health_bar_class::position_x    = 0.0f;
    health_bar_class::position_y    = 1.0f-(health_bar_class::size_y/2.0f);
    health_bar_class::position_z    = 0.0f;
    health_bar_class::maximum       = 0.0f;
    health_bar_class::value         = 0.0f;
};

health_bar_class::~health_bar_class(void)
{

};

void health_bar_class::render(void)
{
    float temp_float = 0.0f;
    temp_float = ((health_bar_class::size_x/2.6f)*(health_bar_class::value/health_bar_class::maximum));
    game.resource.texture.render(false,health_bar_class::texture_base,health_bar_class::position_x,health_bar_class::position_y,health_bar_class::position_z,health_bar_class::size_x/2.0f,health_bar_class::size_y/2.0f);
    game.resource.texture.render(false,health_bar_class::texture_bar,health_bar_class::position_x-(health_bar_class::size_x/5.2f)+(temp_float/2.0f),health_bar_class::position_y,health_bar_class::position_z,temp_float,health_bar_class::size_y/4.0f);
    game.resource.texture.render(false,health_bar_class::texture_front,health_bar_class::position_x,health_bar_class::position_y,health_bar_class::position_z,health_bar_class::size_x/2.0f,health_bar_class::size_y/2.0f);
};

//------------------------------------------------------------------------------------------------------------------------

health_class::health_class(void)
{
    health_class::value        = 0.0f;
    health_class::maximum      = 100.0f;
    health_class::regeneration = 0.25f;
    health_class::bar.maximum  = health_class::maximum;
    health_class::bar.value    = health_class::value;
};

health_class::~health_class(void)
{

};

void health_class::process(void)
{
    health_class::value += health_class::regeneration;
    if (health_class::value > health_class::maximum) health_class::value = health_class::maximum;
    if (health_class::value < 0.0f) health_class::value = 0.0f;
    health_class::bar.value    = health_class::value;
};

//------------------------------------------------------------------------------------------------------------------------

npc_class::npc_class(void)
{
    npc_class::name = "Unnamed NPC";
};

npc_class::~npc_class(void)
{

};

void npc_class::process(void)
{
    npc_class::health.process();
};

void npc_class::render(void)
{
    npc_class::health.bar.render();
};

