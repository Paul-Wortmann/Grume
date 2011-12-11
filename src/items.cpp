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

#include "items.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

item_class::item_class(void)
{
    item_class::name                    = "None";
    item_class::image_ref               = 0;
    item_class::ID                      = 100;
    item_class::defence                 = 0;
    item_class::min_dammage             = 0;
    item_class::max_dammage             = 0;
    item_class::add_min_dammage         = 0;
    item_class::add_max_dammage         = 0;
    item_class::sub_min_dammage         = 0;
    item_class::sub_max_dammage         = 0;
    item_class::add_max_health          = 0;
    item_class::sub_max_health          = 0;
    item_class::add_max_mana            = 0;
    item_class::sub_max_mana            = 0;
    item_class::add_health_regeneration = 0;
    item_class::sub_health_regeneration = 0;
    item_class::add_mana_regeneration   = 0;
    item_class::sub_mana_regeneration   = 0;
    item_class::add_crit_chance         = 0;
    item_class::sub_crit_chance         = 0;
    item_class::add_spell               = 0;
    item_class::spell_type              = 0;
    item_class::usable                  = false;
};

item_class::~item_class(void)
{

};

void item_class::load(void)
{

};

void init_items(void)
{
//-------------------------------- Skills / Spells -------------------------------------------------------------------
    game.item[1].name              = "Book of Chain Lightning";
    game.item[1].image_ref         = game.texture.book_15.ref_number;
    game.item[1].stack_number      = 5;
    game.item[1].max_stack_number  = 10;
    game.item[1].ID                = 101;
    game.item[1].type              = SPELL_BOOK;
    game.item[1].add_spell         = 1;
    game.item[1].spell_type        = 2;
    game.item[1].usable            = true;
    game.item[2].name              = "Book of Stalagmite";
    game.item[2].image_ref         = game.texture.book_19.ref_number;
    game.item[2].stack_number      = 5;
    game.item[2].max_stack_number  = 10;
    game.item[2].ID                = 102;
    game.item[2].type              = SPELL_BOOK;
    game.item[2].add_spell         = 1;
    game.item[2].spell_type        = 1;
    game.item[2].usable            = true;

//-------------------------------- Boots ----------------------------------------------------------------------------
    game.item[101].name              = "Boots of Haste";
    game.item[101].image_ref         = game.texture.boots_09.ref_number;
    game.item[101].stack_number      = 1;
    game.item[101].max_stack_number  = 1;
    game.item[101].ID                = 201;
    game.item[101].type              = BOOTS;
    game.item[101].defence           = 10;
    game.item[102].name              = "Boots of Flame walk";
    game.item[102].image_ref         = game.texture.boots_06.ref_number;
    game.item[102].stack_number      = 1;
    game.item[102].max_stack_number  = 1;
    game.item[102].ID                = 202;
    game.item[102].type              = BOOTS;
    game.item[102].defence           = 10;
};






