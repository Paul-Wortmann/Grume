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

#include "../core/map_2D.hpp"
#include "../core/misc.hpp"
#include "game.hpp"

game_class        game;
fmx_map_type      fmx_map;

game_class::game_class(void)
{
    game_class::event = 0;
    game_class::state = STATE_MENU;
};

void game_class::init(void)
{
    game.loading_screen.display("data/loading_screen.png");
    game_class::debug = false;
    glDisable(GL_DEPTH_TEST);
    //--- initial state of the background ---
    game.core.background.set_data ( 1, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, "data/textures/UI/backgrounds/background_01.png");
    game.core.background.set_data ( 2, 1, 0, 0.0f, 0.0f, 0.0000f, 0.00000f, "data/textures/UI/backgrounds/background_01.png");
    game.core.background.set_data ( 3, 1, 0, 0.0f, 0.0f, 0.0010f, 0.00065f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.set_data ( 4, 1, 0, 4.0f, 0.0f, 0.0010f, 0.00065f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.set_data ( 5, 1, 0, 0.0f, 0.0f, 0.0040f, 0.00075f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.set_data ( 6, 1, 0, 4.0f, 0.0f, 0.0040f, 0.00075f, "data/textures/UI/backgrounds/background_03.png");
    game.core.background.movemennt_type = FRONT_SCROLL;
    //--- other ---

    //game.model_3D.tree_palm.save("test_palm.obj");
    game.global_ambient.intensity_R               = 8.0f;
    game.global_ambient.intensity_G               = 8.0f;
    game.global_ambient.intensity_B               = 8.0f;
    game.global_ambient.intensity_A               = 8.0f;
    game.world_ambient.intensity_R                = 2.0f;
    game.world_ambient.intensity_G                = 2.0f;
    game.world_ambient.intensity_B                = 2.0f;
    game.world_ambient.intensity_A                = 2.0f;
    game.world_ambient.increase                   = true;
    game.world_ambient.speed                      = 0.0125f;
    game.zoom.current                             = TILE_SCALE_DEFAULT;
    game.zoom.min                                 = 80.0f;
    game.zoom.max                                 = 400.0f;
    game.zoom.speed                               = 200.5f;

    game.core.game_paused                         = false;
    game.core.game_active                         = false;
    game.core.game_resume                         = false;
    game.core.quest_log_active                    = false;
    game.core.character_active                    = false;
    game.core.skillbook_active                    = false;
    game.core.inventory_active                    = false;
    game.core.npcvendor_active                    = false;

    game.player.name                              =  "Kanchi";
    game.player.level.current                     =  0;
    game.player.level.base                        =  2;
    game.player.level.multiplier                  =  1.52f;
    game.player.level.init();
    game.player.level.current_experience          =  2; // 0 for norm
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

    //--- other ---
    game.music_manager.next_track = true;
    game.effect.init_effects();
    game.item.init_items();
    game.spell.init_spells();


    //zoom out for testing
    game.zoom.current = game.zoom.max;
    fmx_load(&fmx_map,"data/maps/town.tmx");
    game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
    game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));

    // Add default items to the inventory
    UI_form_struct* UI_form_pointer;
    item_type*      temp_item_pointer;// = new item_type;
    int             element_number    = 1;
    UI_form_pointer   = game.UI_manager.UI_form_get(UID_INVENTORY);
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_L_HEALTH);
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = random(100);
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 2;
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_L_MANA);
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = random(100);
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 3;
    temp_item_pointer = game.item_manager.add_item(ITEM_POTION_L_REJUVENATION);
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = random(100);
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 4;
    temp_item_pointer = game.item_manager.add_item(101);
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_RING,ITEM_RING,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 5;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_RING,ITEM_RING,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 6;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_BELT,ITEM_BELT,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 7;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_BODY,ITEM_BODY,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 8;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_FEET,ITEM_FEET,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 9;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_HAND,ITEM_HAND,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 10;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_HEAD,ITEM_HEAD,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 11;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_NECK,ITEM_NECK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 12;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_OFFHAND,ITEM_OFFHAND,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 13;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_WEAPON,ITEM_WEAPON,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 14;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_RING,ITEM_RING,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 15;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 16;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 17;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 18;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 19;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 20;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_OFFHAND,ITEM_OFFHAND,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 21;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_WEAPON,ITEM_WEAPON,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 22;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_RING,ITEM_RING,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 23;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_RING,ITEM_RING,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 24;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 25;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 26;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 27;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_GEM,ITEM_GEM,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;

    element_number    = 41;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 42;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 43;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 44;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 45;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 46;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 47;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number    = 48;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_SPELL_BOOK,ITEM_SPELL_BOOK,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;


    // Add default items to the action bar
    UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
    element_number = 8;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_POTION,ITEM_POTION,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = random(100);
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number = 9;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_POTION,ITEM_POTION,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = random(100);
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number = 10;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_POTION,ITEM_POTION,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = random(100);
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
    element_number = 11;
    temp_item_pointer = game.item_manager.add_item(game.item_manager.gen_item(ITEM_POTION,ITEM_POTION,random(MAX_ITEM_QUALITY)));
    UI_form_pointer->data.element[element_number].value          = temp_item_pointer->data.UID;
    UI_form_pointer->data.element[element_number].quantity       = random(100);
    UI_form_pointer->data.element[element_number].texture.normal = temp_item_pointer->data.image.level_0;
};

void game_class::process(void)
{
    UI_form_struct* UI_form_pointer;
    int             element_number    = 1;
    path_type* path;
    game.player.process();
    game.npc.process();
    game.map_2D.process(&fmx_map);
    game.core.game_resume = true;
    if (game.music_manager.next_track)
    {
        game.music_manager.next_track = false;
        //if (game.core.music_track ==  0) game.resource.music.menu_00.play();
    }
    if (game.core.io.keyboard_ready)
    {
        if (game.core.io.key_escape) // Main menu
        {
            game.UI_manager.UI_form_disable(UID_MENU_GAME_LOAD);
            game.UI_manager.UI_form_disable(UID_MENU_GAME_NEW);
            game.UI_manager.UI_form_disable(UID_MENU_GAME_SAVE);
            game.UI_manager.UI_form_disable(UID_MENU_OPTIONS);
            if (!game.core.game_menu_active)
            {
                game.UI_manager.UI_form_enable(UID_MENU_MAIN);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_MENU_MAIN;
                game.core.game_menu_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.core.game_menu_active                   = false;
            }
            game.core.io.key_escape                = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_c) // Character menu
        {
            if (!game.core.character_active)
            {
                game.UI_manager.UI_form_enable(UID_CHARACTER);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_CHARACTER;
                game.core.character_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_CHARACTER);
                game.core.character_active                   = false;
            }
            game.core.io.key_c                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_e) // Equipment menu
        {
            if (!game.core.equipment_active)
            {
                game.UI_manager.UI_form_enable(UID_EQUIPMENT);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_EQUIPMENT;
                game.core.equipment_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_EQUIPMENT);
                game.core.equipment_active                   = false;
            }
            game.core.io.key_e                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_q) // Quest log menu
        {
            if (!game.core.quest_log_active)
            {
                game.UI_manager.UI_form_enable(UID_QUEST_LOG);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_QUEST_LOG;
                game.core.quest_log_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_QUEST_LOG);
                game.core.quest_log_active                   = false;
            }
            game.core.io.key_q                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_i) // Inventory menu
        {
            if (!game.core.inventory_active)
            {
                game.UI_manager.UI_form_enable(UID_INVENTORY);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_INVENTORY;
                game.core.inventory_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_INVENTORY);
                game.core.inventory_active                   = false;
            }
            game.core.io.key_i                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_b) // Skill book menu
        {
            if (!game.core.skillbook_active)
            {
                game.UI_manager.UI_form_enable(UID_SKILLBOOK);
                game.UI_manager.data.event.id    = EVENT_UI_LIST_SORT;
                game.UI_manager.data.event.value = UID_SKILLBOOK;
                game.core.skillbook_active                   = true;
            }
            else
            {
                game.UI_manager.UI_form_disable(UID_SKILLBOOK);
                game.core.skillbook_active                   = false;
            }
            game.core.io.key_b                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_space) // close all open windows
        {
            if (game.core.game_menu_active)
            {
                game.UI_manager.UI_form_disable(UID_MENU_MAIN);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_LOAD);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_NEW);
                game.UI_manager.UI_form_disable(UID_MENU_GAME_SAVE);
                game.UI_manager.UI_form_disable(UID_MENU_OPTIONS);
                game.core.game_menu_active                   = false;
            }
            if (game.core.equipment_active)
            {
                game.UI_manager.UI_form_disable(UID_EQUIPMENT);
                game.core.equipment_active                   = false;
            }
            if (game.core.quest_log_active)
            {
                game.UI_manager.UI_form_disable(UID_QUEST_LOG);
                game.core.quest_log_active                   = false;
            }
            if (game.core.character_active)
            {
                game.UI_manager.UI_form_disable(UID_CHARACTER);
                game.core.character_active                   = false;
            }
            if (game.core.inventory_active)
            {
                game.UI_manager.UI_form_disable(UID_INVENTORY);
                game.core.inventory_active                   = false;
            }
            if (game.core.skillbook_active)
            {
                game.UI_manager.UI_form_disable(UID_SKILLBOOK);
                game.core.skillbook_active                   = false;
            }
            if (game.core.npcvendor_active)
            {
                game.UI_manager.UI_form_disable(UID_NPCVENDOR);
                game.core.npcvendor_active                   = false;
            }
            game.core.io.key_space                 = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_alt) // display item names on map (loot / click-able items)
        {
            game.core.io.key_alt                   = false;
            game.core.io.keyboard_delay_count      = 0;
        }
///------------------------------------------------------------------------------------------
        /*
        if (game.core.io.key_d) // toggle debug.
        {
            game.debug = !game.debug;
            game.core.io.key_d                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        */
        if (game.core.io.key_t) // test exp++
        {
            game.player.level.current_experience++;
            game.core.io.key_t                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
///------------------------------------------------------------------------------------------
///                 Action Bar Keys
///------------------------------------------------------------------------------------------
        if (game.core.io.key_1) // Action Bar Key 1
        {
            element_number = 8;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,8);
            }
            game.core.io.key_1                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_2) // Action Bar Key 2
        {
            element_number = 9;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,9);
            }
            game.core.io.key_2                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_3) // Action Bar Key 3
        {
            element_number = 10;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,10);
            }
            game.core.io.key_3                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_4) // Action Bar Key 4
        {
            element_number = 11;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,11);
            }
            game.core.io.key_4                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_5) // Action Bar Key 5
        {
            element_number = 12;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,12);
            }
            game.core.io.key_5                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_6) // Action Bar Key 6
        {
            element_number = 13;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,13);
            }
            game.core.io.key_6                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_7) // Action Bar Key 7
        {
            element_number = 14;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,14);
            }
            game.core.io.key_7                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_8) // Action Bar Key 8
        {
            element_number = 15;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,15);
            }
            game.core.io.key_8                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_9) // Action Bar Key 9
        {
            element_number = 16;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,16);
            }
            game.core.io.key_9                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_0) // Action Bar Key 0
        {
            element_number = 17;
            UI_form_pointer = game.UI_manager.UI_form_get(UID_ACTIONBAR);
            if (UI_form_pointer->data.element[element_number].value >= 0)
            {
                game.item_manager.use_item(UI_form_pointer,17);
            }
            game.core.io.key_0                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
///------------------------------------------------------------------------------------------
        if (game.core.io.key_a) // generate a random BSP dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_BSP(&fmx_map);
            game.map_2D.smooth_map(&fmx_map);
            game.map_2D.apply_tileset(&fmx_map,MAP_DUNGEON);
            game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));
            game.core.io.key_a                     = false;
            game.core.io.keyboard_delay_count      = 0;
            path = map_path_find(&fmx_map,2,2,10,10);
        }
        if (game.core.io.key_s) // generate a random BSP dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_BSP(&fmx_map);
            game.map_2D.smooth_map(&fmx_map);
            game.map_2D.apply_tileset(&fmx_map,MAP_CAVE);
            game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));
            game.core.io.key_s                     = false;
            game.core.io.keyboard_delay_count      = 0;
            path = map_path_find(&fmx_map,2,2,10,10);
        }
        if (game.core.io.key_d) // generate a random CA cave
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_CA(&fmx_map);
            game.map_2D.smooth_map(&fmx_map);
            game.map_2D.apply_tileset(&fmx_map,MAP_CAVE);
            game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));
            game.core.io.key_d                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_f) // generate a random CA grassland
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_CA(&fmx_map);
            game.map_2D.smooth_map(&fmx_map);
            game.map_2D.apply_tileset(&fmx_map,MAP_GRASSLAND);
            game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));
            game.core.io.key_f                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_g) // generate a random CA dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_CA(&fmx_map);
            game.map_2D.smooth_map(&fmx_map);
            game.map_2D.apply_tileset(&fmx_map,MAP_DUNGEON);
            game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));
            game.core.io.key_g                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_h) // generate a random RC dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_RC(&fmx_map);
            game.map_2D.smooth_map(&fmx_map);
            game.map_2D.apply_tileset(&fmx_map,MAP_CAVE);
            game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));
            game.core.io.key_h                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
        if (game.core.io.key_j) // generate a random M1 dungeon
        {
            game.loading_screen.display("data/loading_screen.png");
            map_gen_M1(&fmx_map);
            game.map_2D.smooth_map(&fmx_map);
            game.map_2D.apply_tileset(&fmx_map,MAP_CAVE);
            game.map_2D.calculate_tile_positions(&fmx_map,DEFAULT_FRAME_WIDTH/game.zoom.current/2.0f,DEFAULT_FRAME_HEIGHT/game.zoom.current/2.0f);
            game.map_2D.center_on_tile(&fmx_map,(fmx_map.data.number_of_tiles/2)+(fmx_map.data.map_width/2));
            game.core.io.key_h                     = false;
            game.core.io.keyboard_delay_count      = 0;
        }
    }
///------------------------------------------------------------------------------------------
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

    game.map_2D.render(&fmx_map);
    game.player.render();
    game.npc.render();

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,global_ambient_light);
    game.UI_manager.render();
};

