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
    game.zoom.speed                               = 2.5f;

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

    game.UI.spell_book.close_button.image_normal              =  game.resource.texture.close_button.ref_number;
    game.UI.spell_book.close_button.image_highlighted         =  game.resource.texture.close_button_highlighted.ref_number;
    game.UI.inventory.close_button.image_normal               =  game.resource.texture.close_button.ref_number;
    game.UI.inventory.close_button.image_highlighted          =  game.resource.texture.close_button_highlighted.ref_number;
    game.UI.character.auto_points_box.image_true_highlighted  =  game.resource.texture.check_box_true_highlighted.ref_number;
    game.UI.character.auto_points_box.image_false_highlighted =  game.resource.texture.check_box_false_highlighted.ref_number;
    game.UI.character.auto_points_box.image_true_normal       =  game.resource.texture.check_box_true_normal.ref_number;
    game.UI.character.auto_points_box.image_false_normal      =  game.resource.texture.check_box_false_normal.ref_number;
    game.UI.character.auto_points_box.state                   =  game.player.auto_allocate;
    game.UI.character.close_button.image_normal               =  game.resource.texture.close_button.ref_number;
    game.UI.character.close_button.image_highlighted          =  game.resource.texture.close_button_highlighted.ref_number;
    game.UI.quest_log.close_button.image_normal               =  game.resource.texture.close_button.ref_number;
    game.UI.quest_log.close_button.image_highlighted          =  game.resource.texture.close_button_highlighted.ref_number;
    game.UI.equipment.close_button.image_normal               =  game.resource.texture.close_button.ref_number;
    game.UI.equipment.close_button.image_highlighted          =  game.resource.texture.close_button_highlighted.ref_number;
    game.UI.npcvendor.close_button.image_normal               =  game.resource.texture.close_button.ref_number;
    game.UI.npcvendor.close_button.image_highlighted          =  game.resource.texture.close_button_highlighted.ref_number;
    game.npc.health.bar.texture_base  = game.resource.texture.enemy_health_bar_background_000.ref_number;
    game.npc.health.bar.texture_bar   = game.resource.texture.enemy_health_bar_000.ref_number;
    game.npc.health.bar.texture_front = game.resource.texture.enemy_health_bar_foreground_000.ref_number;

    //--- other ---
    game.menu.init();
    game.core.music_next_track = true;
    init_spells();
    init_items();
    init_inventory();
    game.resource.map_2D.load("data/maps/town.tmx");
    //game.resource.map_2D.random_map(100,100,CAVE);
};

void game_class::process(void)
{
    game.UI.process();
    game.player.process();
    game.npc.process();
    game.resource.map_2D.process();
    //game.resource.map_3D.town.process();
    game.core.game_resume = true;
    if (game.core.music_next_track)
    {
        game.core.music_next_track = false;
        if (game.core.music_track ==  0) game.resource.music.menu_00.play();
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
                game.resource.map_2D.tile[0].pos_y -= (DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
                game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
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
                game.resource.map_2D.calculate_tile_positions(DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
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
        if (game.core.io.key_escape) // Main menu
        {
            if (!game.core.game_menu_active)
            {
                game.UI.active_window_list.add_to_list(MAIN_MENU_WINDOW);
                game.menu.active_menu                        = MENU_MAIN;
                game.resource.sound.menu_select_00.play();
                game.core.game_menu_active                   = true;
            }
            else
            {
                game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
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
                game.UI.active_window_list.add_to_list(EQUIPMENT_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.equipment_active         = true;
            }
            else
            {
                game.UI.active_window_list.remove_from_list(EQUIPMENT_WINDOW);
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
                game.UI.active_window_list.add_to_list(QUEST_LOG_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.quest_log_active         = true;
            }
            else
            {
                game.UI.active_window_list.remove_from_list(QUEST_LOG_WINDOW);
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
                game.UI.active_window_list.add_to_list(CHARACTER_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.character_active         = true;
            }
            else
            {
                game.UI.active_window_list.remove_from_list(CHARACTER_WINDOW);
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
                game.UI.active_window_list.add_to_list(INVENTORY_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.inventory_active         = true;
            }
            else
            {
                game.UI.active_window_list.remove_from_list(INVENTORY_WINDOW);
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
                game.UI.active_window_list.add_to_list(SPELLBOOK_WINDOW);
                game.resource.sound.menu_select_00.play();
                game.core.spellbook_active         = true;
            }
            else
            {
                game.UI.active_window_list.remove_from_list(SPELLBOOK_WINDOW);
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
                game.UI.active_window_list.remove_from_list(MAIN_MENU_WINDOW);
                game.core.game_menu_active         = false;
            }
            if (game.core.equipment_active)
            {
                game.UI.active_window_list.remove_from_list(EQUIPMENT_WINDOW);
                game.core.equipment_active         = false;
            }
            if (game.core.quest_log_active)
            {
                game.UI.active_window_list.remove_from_list(QUEST_LOG_WINDOW);
                game.core.quest_log_active         = false;
            }
            if (game.core.character_active)
            {
                game.UI.active_window_list.remove_from_list(CHARACTER_WINDOW);
                game.core.character_active         = false;
            }
            if (game.core.inventory_active)
            {
                game.UI.active_window_list.remove_from_list(INVENTORY_WINDOW);
                game.core.inventory_active         = false;
            }
            if (game.core.spellbook_active)
            {
                game.UI.active_window_list.remove_from_list(SPELLBOOK_WINDOW);
                game.core.spellbook_active         = false;
            }
            if (game.core.npcvendor_active)
            {
                game.UI.active_window_list.remove_from_list(NPCVENDOR_WINDOW);
                game.core.npcvendor_active         = false;
            }
            game.resource.sound.menu_select_00.play();
            game.core.io.key_space                 = false;
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
    float  global_ambient_light[] = {game.global_ambient.intensity_R,game.global_ambient.intensity_G,game.global_ambient.intensity_B,game.global_ambient.intensity_A};
    float  world_ambient_light[]  = {game.world_ambient.intensity_R,game.world_ambient.intensity_G,game.world_ambient.intensity_B,game.world_ambient.intensity_A};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,world_ambient_light);


    game.resource.map_2D.draw();
    //game.resource.map_3D.town.draw();
    game.player.draw();
    game.npc.render();

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient_light);
    game.UI.draw();
};

