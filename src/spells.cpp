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

#include "spells.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

spell_class::spell_class(void)
{
    spell_class::level                  = 0;
    spell_class::image_level_1          = 0;
    spell_class::image_level_2          = 0;
    spell_class::image_level_3          = 0;
    spell_class::experience_level_1     = 0;
    spell_class::experience_level_2     = 0;
    spell_class::experience_level_3     = 0;
    spell_class::experience             = 0;
    spell_class::cooldown_speed         = 0.0f;
    spell_class::cooldown_count         = 0.0f;
    spell_class::mana_cost_level_1      = 0.0f;
    spell_class::mana_cost_level_2      = 0.0f;
    spell_class::mana_cost_level_3      = 0.0f;
    spell_class::cooldown_level_1       = 0.0f;
    spell_class::cooldown_level_2       = 0.0f;
    spell_class::cooldown_level_3       = 0.0f;
};

spell_class::~spell_class(void)
{

};

void init_spells(void)
{
    //Frost shards
    game.spell[1].level                  = 1;
    game.spell[1].image_level_1          = game.texture.spell_01_level_01.ref_number;
    game.spell[1].image_level_2          = game.texture.spell_01_level_02.ref_number;
    game.spell[1].image_level_3          = game.texture.spell_01_level_03.ref_number;
    game.spell[1].experience_level_1     = 0;
    game.spell[1].experience_level_2     = 1024;
    game.spell[1].experience_level_3     = 2048;
    game.spell[1].experience             = 0;
    game.spell[1].cooldown_speed         = 0.0f;
    game.spell[1].cooldown_count         = 0.0f;
    game.spell[1].mana_cost_level_1      = 0.0f;
    game.spell[1].mana_cost_level_2      = 0.0f;
    game.spell[1].mana_cost_level_3      = 0.0f;
    game.spell[1].cooldown_level_1       = 0.0f;
    game.spell[1].cooldown_level_2       = 0.0f;
    game.spell[1].cooldown_level_3       = 0.0f;
};






