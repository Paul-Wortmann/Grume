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
    game.core.questbook_active                    = false;
    game.core.character_active                    = false;
    game.core.spellbook_active                    = false;
    game.core.inventory_active                    = false;

    game.player.health.current                    =  100.0f;
    game.player.health.maximum                    =  100.0f;
    game.player.health.regeneration               =  000.05f;
    game.player.mana.current                      =  000.0f;
    game.player.mana.maximum                      =  100.0f;
    game.player.mana.regeneration                 =  000.05f;
    return(0);
};


/*----------------------------------------------------------------------------*/
int process_game(void)
{
    game.UI.process();
    game.player.process();
    game.core.game_resume = true;
    if (game.core.music_next_track)
    {
        game.core.music_next_track = false;
        if (game.core.music_track ==  0) game.music.menu_00.play();
    }
    if (game.core.io.escape)
    {
        game.sound.menu_select_00.play();
        game.core.music_next_track        = true;
        game.core.game_active             = false;
        game.core.menu_level              = 1;
        game.core.menu_active             = true;
        game.core.io.escape               = false;
        game.core.io.keyboard_delay_count = 0;
        game.core.config.menu_delay_count = 0;
        while (game.core.config.menu_delay_count < (game.core.config.menu_delay/2))
        {
            game.core.config.menu_delay_count++;
        }
    }
    if (game.core.io.pause)
    {
        //game.paused.spawn();
        game.core.game_paused = true;
        game.core.game_active = false;
        game.core.io.pause    = false;
        game.core.menu_level  = 11;
        SDL_WarpMouse(game.core.graphics.gl_to_res(game.pause_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.pause_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
    };
    bool return_data        = false;
    return(0);
};
/*----------------------------------------------------------------------------*/
int display_game(void)
{
    float z_pos = 0;
    glPushMatrix();
    game.player.draw();




    game.UI.draw();
    glDisable(GL_DEPTH_TEST);
    glPopMatrix();
    return(1);
};

