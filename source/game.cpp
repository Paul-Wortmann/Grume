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

#include "core/map_2D.hpp"
#include "game.hpp"

game_class        game;

game_class::game_class(void)
{
    game_class::event = 0;
    game_class::state = STATE_MENU;
};

void game_class::init(void)
{
    game_class::debug = false;
    glDisable(GL_DEPTH_TEST);
    //--- initial state of the background ---
    game.core.background.set_data ( 1, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, "data/textures/UI/menu/background_00.png");
    game.core.background.set_data ( 2, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, "data/textures/UI/menu/background_00.png");
    game.core.background.set_data ( 3, 1, 0, 0.0f, 0.0f, 0.0010f, 0.00065f, "data/textures/UI/menu/background_01.png");
    game.core.background.set_data ( 4, 1, 0, 4.0f, 0.0f, 0.0010f, 0.00065f, "data/textures/UI/menu/background_01.png");
    game.core.background.set_movement_type(FRONT_SCROLL);
    //--- other ---

    //game.model_3D.tree_palm.save("test_palm.obj");
    game.global_ambient.intensity_R = 8.0f;
    game.global_ambient.intensity_G = 8.0f;
    game.global_ambient.intensity_B = 8.0f;
    game.global_ambient.intensity_A = 8.0f;
    game.world_ambient.intensity_R  = 2.0f;
    game.world_ambient.intensity_G  = 2.0f;
    game.world_ambient.intensity_B  = 2.0f;
    game.world_ambient.intensity_A  = 2.0f;
    game.world_ambient.increase     = true;
    game.world_ambient.speed        = 0.0125f;
    game.zoom.current                             = TILE_SCALE_DEFAULT;
    game.zoom.min                                 = 80.0f;
    game.zoom.max                                 = 400.0f;
    game.zoom.speed                               = 200.5f;

    game.core.game_paused                         = false;
    game.core.game_active                         = false;
    game.core.game_resume                         = false;
    game.core.quest_log_active                    = false;
    game.core.character_active                    = false;
    game.core.spellbook_active                    = false;
    game.core.inventory_active                    = false;
    game.core.npcvendor_active                    = false;

    //game.player.portrait_number                   =  0;
    //game.player.portrait_image_ref                =  game.resource.texture.portrait_00.ref_number;
    game.player.name                              =  "Kanchi";
    game.player.level.current                     =  0;
    game.player.level.base                        =  2;
    game.player.level.multiplier                  =  1.52f;
    game.player.level.init();
    game.player.health.current                    =  000.0f;
    game.player.health.maximum                    =  100.0f;
    game.player.health.regeneration               =  000.015f;
    game.player.mana.current                      =  000.0f;
    game.player.mana.maximum                      =  100.0f;
    game.player.mana.regeneration                 =  000.025f;
    game.player.destination_tile                  =  0;
    game.player.destination_set                   =  false;
    game.player.path_set                          =  false;
    game.player.movement_type                     =  MOVE_TO_TILE_NONE;
/*
    game.npc.health.bar.texture_base  = game.resource.texture.enemy_health_bar_background_000.ref_number;
    game.npc.health.bar.texture_bar   = game.resource.texture.enemy_health_bar_000.ref_number;
    game.npc.health.bar.texture_front = game.resource.texture.enemy_health_bar_foreground_000.ref_number;
*/
    //--- other ---
    game.core.music_next_track = true;
    init_spells();
    init_items();

    //game.resource.map_2D.load("data/maps/cave.tmx");
    //game.resource.map_2D.random_map(100,100,CAVE,CAVE);

    //zoom out for testing
    game.zoom.current = game.zoom.max;
    //game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
};

void game_class::process(void)
{
    game.window_manager.process();
    game.player.process();
    game.npc.process();
    //game.resource.map_2D.process();
    //game.resource.map_3D.town.process();
    game.core.game_resume = true;
    if (game.core.music_next_track)
    {
        game.core.music_next_track = false;
        //if (game.core.music_track ==  0) game.resource.music.menu_00.play();
    }
    if (game.core.io.mouse_wheel != 0)
    {
        if (game.core.io.mouse_wheel < 0)
        {
            while (game.core.io.mouse_wheel < 0)
            {
                game.core.io.mouse_wheel++;
                game.zoom.current += game.zoom.speed;
            }
            if (game.zoom.current > game.zoom.max) game.zoom.current = game.zoom.max;
            else
            {
                //game.resource.map_2D.tile[0].pos_y -= (DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
                //game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            }
        }
        if (game.core.io.mouse_wheel > 0)
        {
            while (game.core.io.mouse_wheel > 0)
            {
                game.core.io.mouse_wheel--;
                game.zoom.current -= game.zoom.speed;
            }
            if (game.zoom.current < game.zoom.min) game.zoom.current = game.zoom.min;
            else
            {
                //game.resource.map_2D.tile[0].pos_y += (DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
                //game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            }
        }
    }
    if (game.core.io.keyboard_ready)
    {
        /*
        if (game.core.io.pause)
        {
            if (!game.core.game_paused)
            {
                game.core.game_paused = true;
                game.core.menu_active = true;
                game.core.game_active = false;
                game.core.io.pause    = false;
                game.core.menu_level  = 11;
                SDL_WarpMouse(game.core.graphics.gl_to_res(game.pause_menu.get_button_x_pos(1),game.core.config.mouse_resolution_x),game.core.config.mouse_resolution_y-game.core.graphics.gl_to_res(game.pause_menu.get_button_y_pos(1),game.core.config.mouse_resolution_y));
            }
            else
            {
                game.core.game_paused = false;
                game.core.menu_active = false;
                game.core.game_active = true;
            }
        };
        */
/*
        if (game.core.io.key_escape) // Main menu
        {
            if (!game.core.game_menu_active)
            {
                game.window_manager.register_window(MAIN_MENU_WINDOW);
                game.menu.active_menu                        = MENU_MAIN;
                game.resource.sound.menu_select_00.play();
                game.core.game_menu_active                   = true;
            }
            else
            {
                game.window_manager.de_register_window(MAIN_MENU_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.game_menu_active = false;
            }
            game.core.io.key_escape                = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_e) // Equipment menu
        {
            if (!game.core.equipment_active)
            {
                game.window_manager.register_window(EQUIPMENT_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.equipment_active         = true;
            }
            else
            {
                game.window_manager.de_register_window(EQUIPMENT_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.equipment_active         = false;
            }
            game.core.io.key_e                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_q) // Quest log menu
        {
            if (!game.core.quest_log_active)
            {
                game.window_manager.register_window(QUEST_LOG_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.quest_log_active         = true;
            }
            else
            {
                game.window_manager.de_register_window(QUEST_LOG_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.quest_log_active         = false;
            }
            game.core.io.key_q                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_c) // Character menu
        {
            if (!game.core.character_active)
            {
                game.window_manager.register_window(CHARACTER_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.character_active         = true;
            }
            else
            {
                game.window_manager.de_register_window(CHARACTER_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.character_active         = false;
            }
            game.core.io.key_c                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_i) // Inventory menu
        {
            if (!game.core.inventory_active)
            {
                game.window_manager.register_window(INVENTORY_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.inventory_active         = true;
            }
            else
            {
                game.window_manager.de_register_window(INVENTORY_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.inventory_active         = false;
            }
            game.core.io.key_i                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_b) // Skill book menu
        {
            if (!game.core.spellbook_active)
            {
                game.window_manager.register_window(SPELLBOOK_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.spellbook_active         = true;
            }
            else
            {
                game.window_manager.de_register_window(SPELLBOOK_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.spellbook_active         = false;
            }
            game.core.io.key_b                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_space) // close all open windows
        {
            if (game.core.game_menu_active)
            {
                game.window_manager.de_register_window(MAIN_MENU_WINDOW);
                game.core.game_menu_active         = false;
            }
            if (game.core.equipment_active)
            {
                game.window_manager.de_register_window(EQUIPMENT_WINDOW);
                game.core.equipment_active         = false;
            }
            if (game.core.quest_log_active)
            {
                game.window_manager.de_register_window(QUEST_LOG_WINDOW);
                game.core.quest_log_active         = false;
            }
            if (game.core.character_active)
            {
                game.window_manager.de_register_window(CHARACTER_WINDOW);
                game.core.character_active         = false;
            }
            if (game.core.inventory_active)
            {
                game.window_manager.de_register_window(INVENTORY_WINDOW);
                game.core.inventory_active         = false;
            }
            if (game.core.spellbook_active)
            {
                game.window_manager.de_register_window(SPELLBOOK_WINDOW);
                game.core.spellbook_active         = false;
            }
            if (game.core.npcvendor_active)
            {
                game.window_manager.de_register_window(NPCVENDOR_WINDOW);
                game.core.npcvendor_active         = false;
            }
            game.resource.sound.menu_select_00.play();
            game.core.io.key_space                 = false;
            game.core.io.keyboard_delay_count      = 0;
        }
*/

///------------------------------------------------------------------------------------------
        if (game.core.io.key_r) // regenerate random map.
        {
            //game.resource.map_2D.random_map(100,100,CAVE,DUNGEON);
            //zoom out for testing
            game.zoom.current = game.zoom.max;
            //game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
           //game.resource.sound.menu_select_00.play();
            game.core.io.key_r                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_d) // toggle debug.
        {
            game.debug = !game.debug;
            game.core.io.key_d                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
///------------------------------------------------------------------------------------------

        if (game.core.io.key_alt) // display item names on map (loot / clickable items)
        {
            ;
        }
    }
};

void game_class::render(void)
{
    /*
    if (game.world_ambient.increase) // day / night lighting
    {
        game.world_ambient.intensity_R += game.world_ambient.speed;
        game.world_ambient.intensity_G += game.world_ambient.speed;
        game.world_ambient.intensity_B += game.world_ambient.speed;
        if (game.world_ambient.intensity_R > game.global_ambient.intensity_R) game.world_ambient.increase = false;
    }
    if (!game.world_ambient.increase)
    {
        game.world_ambient.intensity_R -= game.world_ambient.speed;
        game.world_ambient.intensity_G -= game.world_ambient.speed;
        game.world_ambient.intensity_B -= game.world_ambient.speed;
        if (game.world_ambient.intensity_R < -0.5f) game.world_ambient.increase = true;
    }
    */
    float  global_ambient_light[] = {game.global_ambient.intensity_R,game.global_ambient.intensity_G,game.global_ambient.intensity_B,game.global_ambient.intensity_A};
    float  world_ambient_light[]  = {game.world_ambient.intensity_R,game.world_ambient.intensity_G,game.world_ambient.intensity_B,game.world_ambient.intensity_A};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,world_ambient_light);

    //game.resource.map_2D.draw();
    //game.resource.map_3D.town.draw();
    game.player.draw();
    game.npc.render();

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient_light);
    game.window_manager.render();
};

