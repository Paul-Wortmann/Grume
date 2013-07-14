/**
 * Copyright (C) 2011-2014 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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
    health_bar_class::mouse_over         = false;
    health_bar_class::mouse_over_count   = 0;
    health_bar_class::mouse_over_maximum = 10;
};

health_bar_class::~health_bar_class(void)
{

};

void health_bar_class::draw_tooltip(void)
{
    //game.resource.font.font_1.Write(255,255,255,255,game.core.io.mouse_x,game.core.io.mouse_y,4.8f,32.0f,(int)((health_bar_class::value/health_bar_class::maximum)*100),"%             ");
};

void health_bar_class::render(void)
{
    //float temp_float = 0.0f;
    //temp_float = ((health_bar_class::size_x/2.6f)*(health_bar_class::value/health_bar_class::maximum));
    //game.resource.texture.render(false,health_bar_class::texture_base,health_bar_class::position_x,health_bar_class::position_y,health_bar_class::position_z,health_bar_class::size_x/2.0f,health_bar_class::size_y/2.0f);
    //game.resource.texture.render(false,health_bar_class::texture_bar,health_bar_class::position_x-(health_bar_class::size_x/5.2f)+(temp_float/2.0f),health_bar_class::position_y,health_bar_class::position_z,temp_float,health_bar_class::size_y/4.0f);
    //game.resource.texture.render(false,health_bar_class::texture_front,health_bar_class::position_x,health_bar_class::position_y,health_bar_class::position_z,health_bar_class::size_x/2.0f,health_bar_class::size_y/2.0f);
    if (health_bar_class::mouse_over_count >= health_bar_class::mouse_over_maximum) health_bar_class::draw_tooltip();
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
    if (game.core.physics.point_in_quadrangle(health_class::bar.position_x,health_class::bar.size_x/2,health_class::bar.position_y,health_class::bar.size_y/2,game.core.io.mouse_x,game.core.io.mouse_y)) health_class::bar.mouse_over = true;
    else health_class::bar.mouse_over = false;
    if (health_class::bar.mouse_over) health_class::bar.mouse_over_count++;
    else health_class::bar.mouse_over_count = 0;
    if (health_class::bar.mouse_over_count >= health_class::bar.mouse_over_maximum) health_class::bar.mouse_over_count = health_class::bar.mouse_over_maximum;
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

