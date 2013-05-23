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

#include "item_manager.hpp"
#include "game.hpp"

extern game_class game;

//----------------------------------------------------------------------------------------------------------------

item_manager_class::item_manager_class(void)
{
};

item_manager_class::~item_manager_class(void)
{
    delete [] item_manager_class::item;
};

void item_manager_class::reset_item(int item_number)
{
    item_manager_class::item[item_number].type                   = NULL_ITEM;
    item_manager_class::item[item_number].sub_type               = NULL_ITEM;
    item_manager_class::item[item_number].name                   = "";
    item_manager_class::item[item_number].quantity               = 1;
    item_manager_class::item[item_number].quantity_max           = 1;
    item_manager_class::item[item_number].active                 = false;
    item_manager_class::item[item_number].socketable             = false;
    item_manager_class::item[item_number].number_of_item_effects = 0;
    item_manager_class::item[item_number].number_of_item_sockets = 0;
    for (int item_effect_count = 0; item_effect_count < MAX_ITEM_EFFECTS; item_effect_count++)
    {
        item_manager_class::item[item_number].effect[item_effect_count].type = NULL_ITEM;
    }
    for (int item_socket_count = 0; item_socket_count < MAX_ITEM_SOCKETS; item_socket_count++)
    {
        item_manager_class::item[item_number].socket[item_socket_count].type = NULL_ITEM;
    }
};

int item_manager_class::get_new_ID(void)
{
    for (int item_count = 0; item_count < MAX_ITEMS; item_count++)
    {
        if (!item_manager_class::item[item_count].active) return (item_count);
    }
    return (-1);
};

int item_manager_class::get_item_ID(int temp_item_type)
{
    for (int item_count = 0; item_count < MAX_ITEMS; item_count++)
    {
        if (item_manager_class::item[item_count].ID == temp_item_type) return (item_count);
    }
    return (-1);
};

int item_manager_class::get_item_type(int item_ID)
{
    return(item_manager_class::item[item_ID].type);
};

//----------------------------------------------------------------------------------------------------------------

void  init_items(void) // Initialize hard-coded default items, such as health potions etc...
{
    game.item_manager.number_of_items = 3;
    game.item_manager.item = new item_type[game.item_manager.number_of_items];
    for (int item_count = 0; item_count < game.item_manager.number_of_items;item_count++)
    {
        game.item_manager.item[item_count].active = false;
    }
    //------------------------------------------------------------------------------------------------------------
    int item_number = -1;
    //------------------------- Potions --------------------------------------------------------------------------
    item_number = game.item_manager.get_new_ID();
    if (item_number > -1) // Health potion
    {
        game.item_manager.reset_item(item_number);
        game.item_manager.item[item_number].active                 = true;
        game.item_manager.item[item_number].type                   = HEALTH_POTION;
        game.item_manager.item[item_number].sub_type               = LARGE_POTION;
        game.item_manager.item[item_number].ID                     = item_number;
        game.item_manager.item[item_number].quantity               = 1;
        game.item_manager.item[item_number].quantity_max           = 1;
        game.item_manager.item[item_number].socketable             = false;
        game.item_manager.item[item_number].number_of_item_sockets = 1;
        game.item_manager.item[item_number].number_of_item_effects = 1;
        game.item_manager.item[item_number].effect[0].type         = EFFECT_MOD_HEALTH;
        game.item_manager.item[item_number].effect[0].value        = 50.0f;
        game.item_manager.item[item_number].image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_23.png");
        game.item_manager.item[item_number].sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
        game.item_manager.item[item_number].sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_01.wav");
    }
    item_number = game.item_manager.get_new_ID();
    if (item_number > -1) // Mana potion
    {
        game.item_manager.reset_item(item_number);
        game.item_manager.item[item_number].active                 = true;
        game.item_manager.item[item_number].type                   = MANA_POTION;
        game.item_manager.item[item_number].ID                     = item_number;
        game.item_manager.item[item_number].quantity               = 1;
        game.item_manager.item[item_number].quantity_max           = 1;
        game.item_manager.item[item_number].socketable             = false;
        game.item_manager.item[item_number].number_of_item_sockets = 1;
        game.item_manager.item[item_number].number_of_item_effects = 1;
        game.item_manager.item[item_number].effect[0].type         = EFFECT_MOD_MANA;
        game.item_manager.item[item_number].effect[0].value        = 50.0f;
        game.item_manager.item[item_number].image                  = game.texture_manager.add_texture("data/textures/UI/icons/potions/potion_22.png");
        game.item_manager.item[item_number].sound_move             = game.sound_manager.add_sound("data/sound/inventory/bottle_01.wav");
        game.item_manager.item[item_number].sound_use              = game.sound_manager.add_sound("data/sound/inventory/bubble_03.wav");
    }
    item_number = game.item_manager.get_new_ID();
    if (item_number > -1) // test spell 1
    {
        game.item_manager.reset_item(item_number);
        game.item_manager.item[item_number].active                 = true;
        game.item_manager.item[item_number].type                   = SPELL;
        game.item_manager.item[item_number].ID                     = item_number;
        game.item_manager.item[item_number].quantity               = 1;
        game.item_manager.item[item_number].quantity_max           = 1;
        game.item_manager.item[item_number].socketable             = false;
        game.item_manager.item[item_number].number_of_item_sockets = 1;
        game.item_manager.item[item_number].number_of_item_effects = 2;
        game.item_manager.item[item_number].effect[0].type         = EFFECT_MOD_MANA;
        game.item_manager.item[item_number].effect[0].value        = 50.0f;
        game.item_manager.item[item_number].effect[1].type         = EFFECT_MOD_HEALTH;
        game.item_manager.item[item_number].effect[1].value        = 50.0f;
        game.item_manager.item[item_number].image                  = game.texture_manager.add_texture("data/textures/test_1.png");
        game.item_manager.item[item_number].sound_move             = game.sound_manager.add_sound("data/sound/inventory/book_02.wav");
        game.item_manager.item[item_number].sound_use              = game.sound_manager.add_sound("data/sound/inventory/book_01.wav");
    }
    //------------------------------------------------------------------------------------------------------------
};

void  use_item(int window_from, int element_from)
{
    if (game.window_manager.window[window_from].element[element_from].active)
    {
        int item_number = game.window_manager.window[window_from].element[element_from].value;
        for (int effect_count = 0; effect_count < game.item_manager.item[item_number].number_of_item_effects; effect_count++)
        {
            if (game.item_manager.item[item_number].effect[effect_count].type != NULL_ITEM)
            {
                switch (game.item_manager.item[item_number].effect[effect_count].type)
                {
                    case EFFECT_MOD_HEALTH:
                        game.player.health.current += game.item_manager.item[item_number].effect[effect_count].value;
                    break;
                    case EFFECT_MOD_MANA:
                        game.player.mana.current += game.item_manager.item[item_number].effect[effect_count].value;
                    break;
                    default:
                    break;
                }
            }
        }
        game.window_manager.window[window_from].element[element_from].quantity--;
        if (game.window_manager.window[window_from].element[element_from].quantity <= 0)
        {
            game.window_manager.window[window_from].element[element_from].value    = -1;
            game.window_manager.window[window_from].element[element_from].quantity = 0;
        }
        game.sound_manager.play(game.item_manager.item[item_number].sound_use);
        game.core.log.file_write("Using item -> ", window_from, " - ", element_from);
    }
};

