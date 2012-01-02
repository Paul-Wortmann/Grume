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
    spell_class::name                   = "Spell name not set";
    spell_class::item_type              = SPELL;
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
    game.spell[1].name                   = "Frost shards";
    game.spell[1].level                  = 0;
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
    //Frost shards
    game.spell[2].level                  = 0;
    game.spell[2].image_level_1          = game.texture.spell_02_level_01.ref_number;
    game.spell[2].image_level_2          = game.texture.spell_02_level_02.ref_number;
    game.spell[2].image_level_3          = game.texture.spell_02_level_03.ref_number;
    game.spell[2].experience_level_1     = 0;
    game.spell[2].experience_level_2     = 1024;
    game.spell[2].experience_level_3     = 2048;
    game.spell[2].experience             = 0;
    game.spell[2].cooldown_speed         = 0.0f;
    game.spell[2].cooldown_count         = 0.0f;
    game.spell[2].mana_cost_level_1      = 0.0f;
    game.spell[2].mana_cost_level_2      = 0.0f;
    game.spell[2].mana_cost_level_3      = 0.0f;
    game.spell[2].cooldown_level_1       = 0.0f;
    game.spell[2].cooldown_level_2       = 0.0f;
    game.spell[2].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[3].level                  = 0;
    game.spell[3].image_level_1          = game.texture.spell_03_level_01.ref_number;
    game.spell[3].image_level_2          = game.texture.spell_03_level_02.ref_number;
    game.spell[3].image_level_3          = game.texture.spell_03_level_03.ref_number;
    game.spell[3].experience_level_1     = 0;
    game.spell[3].experience_level_2     = 1024;
    game.spell[3].experience_level_3     = 2048;
    game.spell[3].experience             = 0;
    game.spell[3].cooldown_speed         = 0.0f;
    game.spell[3].cooldown_count         = 0.0f;
    game.spell[3].mana_cost_level_1      = 0.0f;
    game.spell[3].mana_cost_level_2      = 0.0f;
    game.spell[3].mana_cost_level_3      = 0.0f;
    game.spell[3].cooldown_level_1       = 0.0f;
    game.spell[3].cooldown_level_2       = 0.0f;
    game.spell[3].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[4].level                  = 0;
    game.spell[4].image_level_1          = game.texture.spell_04_level_01.ref_number;
    game.spell[4].image_level_2          = game.texture.spell_04_level_02.ref_number;
    game.spell[4].image_level_3          = game.texture.spell_04_level_03.ref_number;
    game.spell[4].experience_level_1     = 0;
    game.spell[4].experience_level_2     = 1024;
    game.spell[4].experience_level_3     = 2048;
    game.spell[4].experience             = 0;
    game.spell[4].cooldown_speed         = 0.0f;
    game.spell[4].cooldown_count         = 0.0f;
    game.spell[4].mana_cost_level_1      = 0.0f;
    game.spell[4].mana_cost_level_2      = 0.0f;
    game.spell[4].mana_cost_level_3      = 0.0f;
    game.spell[4].cooldown_level_1       = 0.0f;
    game.spell[4].cooldown_level_2       = 0.0f;
    game.spell[4].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[5].level                  = 0;
    game.spell[5].image_level_1          = game.texture.spell_05_level_01.ref_number;
    game.spell[5].image_level_2          = game.texture.spell_05_level_02.ref_number;
    game.spell[5].image_level_3          = game.texture.spell_05_level_03.ref_number;
    game.spell[5].experience_level_1     = 0;
    game.spell[5].experience_level_2     = 1024;
    game.spell[5].experience_level_3     = 2048;
    game.spell[5].experience             = 0;
    game.spell[5].cooldown_speed         = 0.0f;
    game.spell[5].cooldown_count         = 0.0f;
    game.spell[5].mana_cost_level_1      = 0.0f;
    game.spell[5].mana_cost_level_2      = 0.0f;
    game.spell[5].mana_cost_level_3      = 0.0f;
    game.spell[5].cooldown_level_1       = 0.0f;
    game.spell[5].cooldown_level_2       = 0.0f;
    game.spell[5].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[6].level                  = 0;
    game.spell[6].image_level_1          = game.texture.spell_06_level_01.ref_number;
    game.spell[6].image_level_2          = game.texture.spell_06_level_02.ref_number;
    game.spell[6].image_level_3          = game.texture.spell_06_level_03.ref_number;
    game.spell[6].experience_level_1     = 0;
    game.spell[6].experience_level_2     = 1024;
    game.spell[6].experience_level_3     = 2048;
    game.spell[6].experience             = 0;
    game.spell[6].cooldown_speed         = 0.0f;
    game.spell[6].cooldown_count         = 0.0f;
    game.spell[6].mana_cost_level_1      = 0.0f;
    game.spell[6].mana_cost_level_2      = 0.0f;
    game.spell[6].mana_cost_level_3      = 0.0f;
    game.spell[6].cooldown_level_1       = 0.0f;
    game.spell[6].cooldown_level_2       = 0.0f;
    game.spell[6].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[7].level                  = 0;
    game.spell[7].image_level_1          = game.texture.spell_07_level_01.ref_number;
    game.spell[7].image_level_2          = game.texture.spell_07_level_02.ref_number;
    game.spell[7].image_level_3          = game.texture.spell_07_level_03.ref_number;
    game.spell[7].experience_level_1     = 0;
    game.spell[7].experience_level_2     = 1024;
    game.spell[7].experience_level_3     = 2048;
    game.spell[7].experience             = 0;
    game.spell[7].cooldown_speed         = 0.0f;
    game.spell[7].cooldown_count         = 0.0f;
    game.spell[7].mana_cost_level_1      = 0.0f;
    game.spell[7].mana_cost_level_2      = 0.0f;
    game.spell[7].mana_cost_level_3      = 0.0f;
    game.spell[7].cooldown_level_1       = 0.0f;
    game.spell[7].cooldown_level_2       = 0.0f;
    game.spell[7].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[8].level                  = 0;
    game.spell[8].image_level_1          = game.texture.spell_08_level_01.ref_number;
    game.spell[8].image_level_2          = game.texture.spell_08_level_02.ref_number;
    game.spell[8].image_level_3          = game.texture.spell_08_level_03.ref_number;
    game.spell[8].experience_level_1     = 0;
    game.spell[8].experience_level_2     = 1024;
    game.spell[8].experience_level_3     = 2048;
    game.spell[8].experience             = 0;
    game.spell[8].cooldown_speed         = 0.0f;
    game.spell[8].cooldown_count         = 0.0f;
    game.spell[8].mana_cost_level_1      = 0.0f;
    game.spell[8].mana_cost_level_2      = 0.0f;
    game.spell[8].mana_cost_level_3      = 0.0f;
    game.spell[8].cooldown_level_1       = 0.0f;
    game.spell[8].cooldown_level_2       = 0.0f;
    game.spell[8].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[9].level                  = 0;
    game.spell[9].image_level_1          = game.texture.spell_09_level_01.ref_number;
    game.spell[9].image_level_2          = game.texture.spell_09_level_02.ref_number;
    game.spell[9].image_level_3          = game.texture.spell_09_level_03.ref_number;
    game.spell[9].experience_level_1     = 0;
    game.spell[9].experience_level_2     = 1024;
    game.spell[9].experience_level_3     = 2048;
    game.spell[9].experience             = 0;
    game.spell[9].cooldown_speed         = 0.0f;
    game.spell[9].cooldown_count         = 0.0f;
    game.spell[9].mana_cost_level_1      = 0.0f;
    game.spell[9].mana_cost_level_2      = 0.0f;
    game.spell[9].mana_cost_level_3      = 0.0f;
    game.spell[9].cooldown_level_1       = 0.0f;
    game.spell[9].cooldown_level_2       = 0.0f;
    game.spell[9].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[10].level                  = 0;
    game.spell[10].image_level_1          = game.texture.spell_10_level_01.ref_number;
    game.spell[10].image_level_2          = game.texture.spell_10_level_02.ref_number;
    game.spell[10].image_level_3          = game.texture.spell_10_level_03.ref_number;
    game.spell[10].experience_level_1     = 0;
    game.spell[10].experience_level_2     = 1024;
    game.spell[10].experience_level_3     = 2048;
    game.spell[10].experience             = 0;
    game.spell[10].cooldown_speed         = 0.0f;
    game.spell[10].cooldown_count         = 0.0f;
    game.spell[10].mana_cost_level_1      = 0.0f;
    game.spell[10].mana_cost_level_2      = 0.0f;
    game.spell[10].mana_cost_level_3      = 0.0f;
    game.spell[10].cooldown_level_1       = 0.0f;
    game.spell[10].cooldown_level_2       = 0.0f;
    game.spell[10].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[11].level                  = 0;
    game.spell[11].image_level_1          = game.texture.spell_11_level_01.ref_number;
    game.spell[11].image_level_2          = game.texture.spell_11_level_02.ref_number;
    game.spell[11].image_level_3          = game.texture.spell_11_level_03.ref_number;
    game.spell[11].experience_level_1     = 0;
    game.spell[11].experience_level_2     = 1024;
    game.spell[11].experience_level_3     = 2048;
    game.spell[11].experience             = 0;
    game.spell[11].cooldown_speed         = 0.0f;
    game.spell[11].cooldown_count         = 0.0f;
    game.spell[11].mana_cost_level_1      = 0.0f;
    game.spell[11].mana_cost_level_2      = 0.0f;
    game.spell[11].mana_cost_level_3      = 0.0f;
    game.spell[11].cooldown_level_1       = 0.0f;
    game.spell[11].cooldown_level_2       = 0.0f;
    game.spell[11].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[12].level                  = 0;
    game.spell[12].image_level_1          = game.texture.spell_12_level_01.ref_number;
    game.spell[12].image_level_2          = game.texture.spell_12_level_02.ref_number;
    game.spell[12].image_level_3          = game.texture.spell_12_level_03.ref_number;
    game.spell[12].experience_level_1     = 0;
    game.spell[12].experience_level_2     = 1024;
    game.spell[12].experience_level_3     = 2048;
    game.spell[12].experience             = 0;
    game.spell[12].cooldown_speed         = 0.0f;
    game.spell[12].cooldown_count         = 0.0f;
    game.spell[12].mana_cost_level_1      = 0.0f;
    game.spell[12].mana_cost_level_2      = 0.0f;
    game.spell[12].mana_cost_level_3      = 0.0f;
    game.spell[12].cooldown_level_1       = 0.0f;
    game.spell[12].cooldown_level_2       = 0.0f;
    game.spell[12].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[13].level                  = 0;
    game.spell[13].image_level_1          = game.texture.spell_13_level_01.ref_number;
    game.spell[13].image_level_2          = game.texture.spell_13_level_02.ref_number;
    game.spell[13].image_level_3          = game.texture.spell_13_level_03.ref_number;
    game.spell[13].experience_level_1     = 0;
    game.spell[13].experience_level_2     = 1024;
    game.spell[13].experience_level_3     = 2048;
    game.spell[13].experience             = 0;
    game.spell[13].cooldown_speed         = 0.0f;
    game.spell[13].cooldown_count         = 0.0f;
    game.spell[13].mana_cost_level_1      = 0.0f;
    game.spell[13].mana_cost_level_2      = 0.0f;
    game.spell[13].mana_cost_level_3      = 0.0f;
    game.spell[13].cooldown_level_1       = 0.0f;
    game.spell[13].cooldown_level_2       = 0.0f;
    game.spell[13].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[14].level                  = 0;
    game.spell[14].image_level_1          = game.texture.spell_14_level_01.ref_number;
    game.spell[14].image_level_2          = game.texture.spell_14_level_02.ref_number;
    game.spell[14].image_level_3          = game.texture.spell_14_level_03.ref_number;
    game.spell[14].experience_level_1     = 0;
    game.spell[14].experience_level_2     = 1024;
    game.spell[14].experience_level_3     = 2048;
    game.spell[14].experience             = 0;
    game.spell[14].cooldown_speed         = 0.0f;
    game.spell[14].cooldown_count         = 0.0f;
    game.spell[14].mana_cost_level_1      = 0.0f;
    game.spell[14].mana_cost_level_2      = 0.0f;
    game.spell[14].mana_cost_level_3      = 0.0f;
    game.spell[14].cooldown_level_1       = 0.0f;
    game.spell[14].cooldown_level_2       = 0.0f;
    game.spell[14].cooldown_level_3       = 0.0f;
    //Frost shards
    game.spell[15].level                  = 0;
    game.spell[15].image_level_1          = game.texture.spell_15_level_01.ref_number;
    game.spell[15].image_level_2          = game.texture.spell_15_level_02.ref_number;
    game.spell[15].image_level_3          = game.texture.spell_15_level_03.ref_number;
    game.spell[15].experience_level_1     = 0;
    game.spell[15].experience_level_2     = 1024;
    game.spell[15].experience_level_3     = 2048;
    game.spell[15].experience             = 0;
    game.spell[15].cooldown_speed         = 0.0f;
    game.spell[15].cooldown_count         = 0.0f;
    game.spell[15].mana_cost_level_1      = 0.0f;
    game.spell[15].mana_cost_level_2      = 0.0f;
    game.spell[15].mana_cost_level_3      = 0.0f;
    game.spell[15].cooldown_level_1       = 0.0f;
    game.spell[15].cooldown_level_2       = 0.0f;
    game.spell[15].cooldown_level_3       = 0.0f;
};






