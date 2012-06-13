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

#include "player.hpp"
#include "game.hpp"

extern game_class         game;

level_class::level_class(void)
{
    level_class::current_experience = 0;
    level_class::base               = 2;
    level_class::current            = 0;
    level_class::multiplier         = 2.0f;
    for (int exp_count = 0; exp_count < MAX_LEVELS; exp_count++)
    {
        level_class::experience[exp_count] = 0;
    }
};

level_class::~level_class(void)
{

};

void level_class::init(void)
{
    unsigned long long temp_exp =  level_class::base;
    for (int exp_count = 1; exp_count < MAX_LEVELS; exp_count++)
    {
        temp_exp = temp_exp * level_class::multiplier;
        if (temp_exp > 9223372036854775808u) temp_exp = 9223372036854775808u;
        level_class::experience[exp_count] = temp_exp;
    }
};

void level_class::process(void)
{
    int temp_level = 0;
    if (level_class::current_experience > 9223372036854775808u) level_class::current_experience = 9223372036854775808u;
    for (int exp_count = 1; exp_count < MAX_LEVELS; exp_count++)
    {
        if (level_class::current_experience >= level_class::experience[exp_count]) temp_level = exp_count;
    }
    if (temp_level > level_class::current) // level up!!!
    {
        level_class::current = temp_level;
        if(game.player.auto_allocate)
        {
            game.player.offence   += 1;
            game.player.defense   += 1;
            game.player.intellect += 1;
        }
        else game.player.allocatable_points += 3;

    }

};

//-----------------------------------------------------------------------------------------------------------------

stat_class::stat_class(void)
{
    stat_class::current      = 0.0f;
    stat_class::maximum      = 0.0f;
    stat_class::regeneration = 0.0f;
};

stat_class::~stat_class(void)
{

};

void stat_class::process(void)
{
    stat_class::current += stat_class::regeneration;
    if (stat_class::current < 0.0f)                stat_class::current = 0.0f;
    if (stat_class::current > stat_class::maximum) stat_class::current = stat_class::maximum;
};

void stat_class::draw(void)
{

};

//-----------------------------------------------------------------------------------------------------------------

player_class::player_class(void)
{
    player_class::name                          = "Player_Name";
    player_class::level.current                 = 0;
    player_class::gold                          = 0u;
    player_class::pos_x                         = 0.0f;
    player_class::pos_y                         = 0.0f;
    player_class::pos_z                         = 0.0f;
    player_class::offence                       = 1;
    player_class::defense                       = 1;
    player_class::intellect                     = 1;
    player_class::armor                         = 0.0f;
    player_class::critical_chance               = 0.0f;
    player_class::damage_physical_maximum       = 2.0f;
    player_class::damage_physical_minimum       = 1.0f;
    player_class::damage_frost                  = 0.0f;
    player_class::damage_flame                  = 0.0f;
    player_class::damage_lightning              = 0.0f;
    player_class::resistance_frost              = 0.0f;
    player_class::resistance_flame              = 0.0f;
    player_class::resistance_lightning          = 0.0f;
    player_class::allocatable_points            = 0;
    player_class::auto_allocate                 = true;
};

player_class::~player_class(void)
{

};

void player_class::process(void)
{
    player_class::health.process();
    player_class::mana.process();
    player_class::level.process();
    if (game.core.io.mouse_button_left)
    {
        if (!player_class::destination_set)
        {
            player_class::destination_tile = 0;
            player_class::destination_set  = true;
            if (!player_class::path_set)
            {
                player_class::path_calculate();
                player_class::path_set = true;
            }
            if (player_class::path_set)
            {
                switch (player_class::movement_type)
                {
                    case MOVE_TO_TILE_MOVE:
                        player_class::player_move();
                    break;
                    case MOVE_TO_TILE_ATTACK:
                        player_class::player_attack();
                    break;
                    case MOVE_TO_TILE_PICKUP_ITEM:
                        player_class::player_pickup_item();
                    break;
                    case MOVE_TO_TILE_USE_OBJECT:
                        player_class::player_use_object();
                    break;
                }
            }
        }
    }
};

void player_class::draw(void)
{

};

void player_class::path_calculate(void)
{

};

void player_class::player_move(void)
{

};

void player_class::player_attack(void)
{

};

void player_class::player_pickup_item(void)
{

};

void player_class::player_use_object(void)
{

};

