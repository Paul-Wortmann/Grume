/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#ifndef SAVE_DATA_H
#define SAVE_DATA_H

#include "core/core.hpp"
#include "core/savegame.hpp"
#include "game.hpp"

struct save_data_type
{
    float                save_version;
    int                  AB_MS_01;
    int                  AB_MS_02;
    int                  AB_MS_03;
    int                  AB_MS_04;
    int                  AB_MS_05;
    int                  AB_MS_06;
    int                  AB_AS_01;
    int                  AB_AS_02;
    int                  AB_AS_03;
    int                  AB_AS_04;
    int                  AB_AS_05;
    int                  AB_AS_06;
    int                  AB_AS_07;
    int                  AB_AS_08;
    int                  AB_AS_09;
    int                  AB_AS_10;
};

void update_save_data(void);
void update_game_data(void);

#endif // SAVE_DATA_H


