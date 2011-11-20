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

#include "spell_book.hpp"
#include "game.hpp"

extern game_type game;

//----------------------------------------------------------------------------------------------------------------

spell_slot_class::spell_slot_class(void)
{

};

spell_slot_class::~spell_slot_class(void)
{

};

void spell_slot_class::process(void)
{

};

void spell_slot_class::draw(void)
{

};

//----------------------------------------------------------------------------------------------------------------

spell_book_class::spell_book_class(void)
{
    spell_book_class::pos_x  = 0.5f;
    spell_book_class::pos_y  = 0.3f;
    spell_book_class::pos_z  = 0.001;
    spell_book_class::width  = 0.5f;
    spell_book_class::height = 1.0f;
};

spell_book_class::~spell_book_class(void)
{

};

void spell_book_class::process(void)
{
    spell_book_class::spell_slot_01.process();
    spell_book_class::spell_slot_02.process();
    spell_book_class::spell_slot_03.process();
    spell_book_class::spell_slot_04.process();
    spell_book_class::spell_slot_05.process();
    spell_book_class::spell_slot_06.process();
    spell_book_class::spell_slot_07.process();
    spell_book_class::spell_slot_08.process();
    spell_book_class::spell_slot_09.process();
    spell_book_class::spell_slot_10.process();
    spell_book_class::spell_slot_11.process();
    spell_book_class::spell_slot_12.process();
    spell_book_class::spell_slot_13.process();
    spell_book_class::spell_slot_14.process();
    spell_book_class::spell_slot_15.process();
    spell_book_class::spell_slot_16.process();
    spell_book_class::spell_slot_17.process();
    spell_book_class::spell_slot_18.process();
    spell_book_class::spell_slot_19.process();
    spell_book_class::spell_slot_20.process();
};

void spell_book_class::draw(void)
{
    game.texture.spell_book.draw(false,spell_book_class::pos_x,spell_book_class::pos_y,spell_book_class::pos_z,spell_book_class::width,spell_book_class::height);
    spell_book_class::spell_slot_01.draw();
    spell_book_class::spell_slot_02.draw();
    spell_book_class::spell_slot_03.draw();
    spell_book_class::spell_slot_04.draw();
    spell_book_class::spell_slot_05.draw();
    spell_book_class::spell_slot_06.draw();
    spell_book_class::spell_slot_07.draw();
    spell_book_class::spell_slot_08.draw();
    spell_book_class::spell_slot_09.draw();
    spell_book_class::spell_slot_10.draw();
    spell_book_class::spell_slot_11.draw();
    spell_book_class::spell_slot_12.draw();
    spell_book_class::spell_slot_13.draw();
    spell_book_class::spell_slot_14.draw();
    spell_book_class::spell_slot_15.draw();
    spell_book_class::spell_slot_16.draw();
    spell_book_class::spell_slot_17.draw();
    spell_book_class::spell_slot_18.draw();
    spell_book_class::spell_slot_19.draw();
    spell_book_class::spell_slot_20.draw();
};
