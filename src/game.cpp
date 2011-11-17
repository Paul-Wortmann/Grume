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

    game.UI.action_bar.pos_x                      =  0.0f;
    game.UI.action_bar.pos_y                      = -0.9f;
    game.UI.action_bar.pos_z                      =  0.001f;
    game.UI.action_bar.width                      =  1.8f;
    game.UI.action_bar.height                     =  0.18f;
    game.UI.action_bar.menu_slot_01.button_type   =  1;
    game.UI.action_bar.menu_slot_01.pos_x         = -0.79f;
    game.UI.action_bar.menu_slot_01.pos_y         = -0.916f;
    game.UI.action_bar.menu_slot_01.pos_z         =  0.001f;
    game.UI.action_bar.menu_slot_01.width         =  0.078f;
    game.UI.action_bar.menu_slot_01.height        =  0.078f;
    game.UI.action_bar.menu_slot_02.button_type  =  2;
    game.UI.action_bar.menu_slot_02.pos_x         = -0.69f;
    game.UI.action_bar.menu_slot_02.pos_y         = -0.916f;
    game.UI.action_bar.menu_slot_02.pos_z         =  0.001f;
    game.UI.action_bar.menu_slot_02.width         =  0.078f;
    game.UI.action_bar.menu_slot_02.height        =  0.078f;
    game.UI.action_bar.menu_slot_03.button_type   =  3;
    game.UI.action_bar.menu_slot_03.pos_x         = -0.59f;
    game.UI.action_bar.menu_slot_03.pos_y         = -0.916f;
    game.UI.action_bar.menu_slot_03.pos_z         =  0.001f;
    game.UI.action_bar.menu_slot_03.width         =  0.078f;
    game.UI.action_bar.menu_slot_03.height        =  0.078f;
    game.UI.action_bar.menu_slot_04.button_type   =  4;
    game.UI.action_bar.menu_slot_04.pos_x         =  0.60f;
    game.UI.action_bar.menu_slot_04.pos_y         = -0.916f;
    game.UI.action_bar.menu_slot_04.pos_z         =  0.001f;
    game.UI.action_bar.menu_slot_04.width         =  0.078f;
    game.UI.action_bar.menu_slot_04.height        =  0.078f;
    game.UI.action_bar.menu_slot_05.button_type   =  5;
    game.UI.action_bar.menu_slot_05.pos_x         =  0.70f;
    game.UI.action_bar.menu_slot_05.pos_y         = -0.916f;
    game.UI.action_bar.menu_slot_05.pos_z         =  0.001f;
    game.UI.action_bar.menu_slot_05.width         =  0.078f;
    game.UI.action_bar.menu_slot_05.height        =  0.078f;
    game.UI.action_bar.menu_slot_06.button_type   =  6;
    game.UI.action_bar.menu_slot_06.pos_x         =  0.80f;
    game.UI.action_bar.menu_slot_06.pos_y         = -0.916f;
    game.UI.action_bar.menu_slot_06.pos_z         =  0.001f;
    game.UI.action_bar.menu_slot_06.width         =  0.078f;
    game.UI.action_bar.menu_slot_06.height        =  0.078f;
    game.UI.action_bar.action_slot_01.button_type =  0;
    game.UI.action_bar.action_slot_01.pos_x       = -0.4532f;
    game.UI.action_bar.action_slot_01.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_01.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_01.width       =  0.088f;
    game.UI.action_bar.action_slot_01.height      =  0.146f;
    game.UI.action_bar.action_slot_02.button_type =  0;
    game.UI.action_bar.action_slot_02.pos_x       = -0.3521f;
    game.UI.action_bar.action_slot_02.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_02.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_02.width       =  0.088f;
    game.UI.action_bar.action_slot_02.height      =  0.146f;
    game.UI.action_bar.action_slot_03.button_type =  0;
    game.UI.action_bar.action_slot_03.pos_x       = -0.2500f;
    game.UI.action_bar.action_slot_03.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_03.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_03.width       =  0.088f;
    game.UI.action_bar.action_slot_03.height      =  0.146f;
    game.UI.action_bar.action_slot_04.button_type =  0;
    game.UI.action_bar.action_slot_04.pos_x       = -0.1487f;
    game.UI.action_bar.action_slot_04.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_04.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_04.width       =  0.088f;
    game.UI.action_bar.action_slot_04.height      =  0.146f;
    game.UI.action_bar.action_slot_05.button_type =  0;
    game.UI.action_bar.action_slot_05.pos_x       = -0.0476f;
    game.UI.action_bar.action_slot_05.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_05.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_05.width       =  0.088f;
    game.UI.action_bar.action_slot_05.height      =  0.146f;
    game.UI.action_bar.action_slot_06.button_type =  0;
    game.UI.action_bar.action_slot_06.pos_x       =  0.0534f;
    game.UI.action_bar.action_slot_06.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_06.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_06.width       =  0.088f;
    game.UI.action_bar.action_slot_06.height      =  0.146f;
    game.UI.action_bar.action_slot_07.button_type =  0;
    game.UI.action_bar.action_slot_07.pos_x       =  0.1544f;
    game.UI.action_bar.action_slot_07.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_07.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_07.width       =  0.088f;
    game.UI.action_bar.action_slot_07.height      =  0.146f;
    game.UI.action_bar.action_slot_08.button_type =  0;
    game.UI.action_bar.action_slot_08.pos_x       =  0.2552;
    game.UI.action_bar.action_slot_08.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_08.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_08.width       =  0.088f;
    game.UI.action_bar.action_slot_08.height      =  0.146f;
    game.UI.action_bar.action_slot_09.button_type =  0;
    game.UI.action_bar.action_slot_09.pos_x       =  0.3578f;
    game.UI.action_bar.action_slot_09.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_09.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_09.width       =  0.088f;
    game.UI.action_bar.action_slot_09.height      =  0.146f;
    game.UI.action_bar.action_slot_10.button_type =  1;
    game.UI.action_bar.action_slot_10.pos_x       =  0.4589f;
    game.UI.action_bar.action_slot_10.pos_y       = -0.9f;
    game.UI.action_bar.action_slot_10.pos_z       =  0.001f;
    game.UI.action_bar.action_slot_10.width       =  0.088f;
    game.UI.action_bar.action_slot_10.height      =  0.146f;
    game.UI.player_stats.portrait                 = 0;
    game.UI.player_stats.pos_x                    =-0.8f;
    game.UI.player_stats.pos_y                    = 0.88f;
    game.UI.player_stats.pos_z                    = 0.001f;
    game.UI.player_stats.width                    = 0.4f;
    game.UI.player_stats.height                   = 0.24f;

    game.player.health.maximum                    =  100.0f;
    game.player.health.regeneration               =  0.05f;
    game.player.mana.maximum                      =  100.0f;
    game.player.mana.regeneration                 =  0.05f;
    return(0);
};


/*----------------------------------------------------------------------------*/
int process_game(void)
{
    game.UI.action_bar.process();
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

