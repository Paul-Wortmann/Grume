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

#include "game.hpp"
#include "balls.hpp"
balls_class       balls;

game_class        game;

game_class::game_class(void)
{
    game_class::event = 0;
    game_class::state = STATE_MENU;
};

void game_class::init(void)
{
    glDisable(GL_DEPTH_TEST);
    //--- initial state of the background ---
    game.core.background.set_data ( 1, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, game.resource.texture.background_00.ref_number);
    game.core.background.set_data ( 2, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, game.resource.texture.background_00.ref_number);
    game.core.background.set_data ( 3, 1, 0, 0.0f, 0.0f, 0.0010f, 0.00065f, game.resource.texture.background_01.ref_number);
    game.core.background.set_data ( 4, 1, 0, 4.0f, 0.0f, 0.0010f, 0.00065f, game.resource.texture.background_01.ref_number);
    game.core.background.set_movement_type(FRONT_SCROLL);
    //--- other ---
    game.core.music_next_track = true;
    balls.initialize();
};

void game_class::process(void)
{
    game_class::event = 0;
    balls.process();
};

void game_class::render(void)
{
    balls.render();
};

