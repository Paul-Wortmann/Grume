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

#include <SDL/SDL.h>
#include "menu_system.hpp"
#include "game.hpp"
#include "misc.hpp"

        game_type        game;

int init_game(bool re_init)
{
    game.core.game_paused                         = false;
    game.core.game_active                         = false;
    game.core.game_resume                         = false;
    game.core.outr_active                         = false;
    game.core.menu_active                         = true;
    game.core.pdie_active                         = false;
    game.core.nlvl_active                         = false;

    return(0);
};


/*----------------------------------------------------------------------------*/
int process_game(void)
{
    bool return_data        = false;
    return(0);
};
/*----------------------------------------------------------------------------*/
int display_game(void)
{
    float z_pos = 0;
    glPushMatrix();
    glDisable(GL_DEPTH_TEST);
    glPopMatrix();
    return(1);
};

