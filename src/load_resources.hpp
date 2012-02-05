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

#ifndef LOAD_RESOURCES_H
#define LOAD_RESOURCES_H

#include "core/core.hpp"
#include "core/sound.hpp"
#include "core/music.hpp"
#include "core/textures.hpp"
#include "core/font.hpp"
#include "core/map_2D.hpp"
#include "map_3D.hpp"

struct sound_type
{
    sound_class   menu_move_00;
    sound_class   menu_select_00;

    sound_class   bottle_01;
    sound_class   bubble_01;
    sound_class   bubble_02;
    sound_class   bubble_03;

    sound_class   book_00;
    sound_class   book_01;
    sound_class   book_02;
};

struct map_2D_type
{
    map_2D_class   town;
};

struct map_3D_type
{
    map_3D_class   cave;
};

struct music_type
{
    music_class   menu_00;
};

struct texture_type
{
    texture_class background_00;
    texture_class background_01;
    texture_class background_02;
    texture_class background_03;

    texture_class logo;
    texture_class button_normal;
    texture_class button_highlighted;
    texture_class button_disabled;
    texture_class close_button;
    texture_class close_button_highlighted;
    texture_class selection_box;
    texture_class arrow_button_normal;
    texture_class arrow_button_highlighted;
    texture_class arrow_button_disabled;
    texture_class slider_button_normal;
    texture_class slider_button_highlighted;
    texture_class red_button;
    texture_class red_button_highlighted;
    texture_class green_button;
    texture_class green_button_highlighted;
    texture_class blue_button;
    texture_class blue_button_highlighted;
    texture_class resolution_icon;

    texture_class cursor;
    texture_class action_bar;
    texture_class action_bar_front;
    texture_class glass_cover_01;
    texture_class glass_cover_02;
    texture_class icon_01;
    texture_class icon_02;
    texture_class icon_03;
    texture_class icon_04;
    texture_class icon_05;
    texture_class icon_06;
    texture_class icon_melee;

    texture_class health_bar;
    texture_class mana_bar;
    texture_class experience_bar;
    texture_class profile_background;
    texture_class profile_main;
    texture_class profile_main_background;

    texture_class spell_book;
    texture_class spell_book_spell_cover;
    texture_class spell_book_background;
    texture_class inventory;
    texture_class inventory_gold;
    texture_class inventory_background;
    texture_class item_stat_background;
    texture_class character_portrait_frame;
    texture_class character_background;
    texture_class check_box_true_highlighted;
    texture_class check_box_false_highlighted;
    texture_class check_box_true_normal;
    texture_class check_box_false_normal;
    texture_class quest_log_background;
    texture_class equipment_background;
    texture_class equipment_slot_32x32;
    texture_class equipment_slot_64x32;
    texture_class equipment_slot_64x64;
    texture_class equipment_slot_64x96;

    texture_class particle_000;
    texture_class particle_001;
    texture_class particle_002;
    texture_class particle_003;
    texture_class particle_004;
    texture_class particle_005;
    texture_class particle_006;
    texture_class particle_007;
    texture_class particle_008;
    texture_class particle_009;
    texture_class particle_010;
    texture_class particle_011;
    texture_class particle_012;
    texture_class particle_013;
    texture_class particle_014;
    texture_class particle_015;

    texture_class spell_01_level_01;
    texture_class spell_01_level_02;
    texture_class spell_01_level_03;
    texture_class spell_02_level_01;
    texture_class spell_02_level_02;
    texture_class spell_02_level_03;
    texture_class spell_03_level_01;
    texture_class spell_03_level_02;
    texture_class spell_03_level_03;
    texture_class spell_04_level_01;
    texture_class spell_04_level_02;
    texture_class spell_04_level_03;
    texture_class spell_05_level_01;
    texture_class spell_05_level_02;
    texture_class spell_05_level_03;
    texture_class spell_06_level_01;
    texture_class spell_06_level_02;
    texture_class spell_06_level_03;
    texture_class spell_07_level_01;
    texture_class spell_07_level_02;
    texture_class spell_07_level_03;
    texture_class spell_08_level_01;
    texture_class spell_08_level_02;
    texture_class spell_08_level_03;
    texture_class spell_09_level_01;
    texture_class spell_09_level_02;
    texture_class spell_09_level_03;
    texture_class spell_10_level_01;
    texture_class spell_10_level_02;
    texture_class spell_10_level_03;
    texture_class spell_11_level_01;
    texture_class spell_11_level_02;
    texture_class spell_11_level_03;
    texture_class spell_12_level_01;
    texture_class spell_12_level_02;
    texture_class spell_12_level_03;
    texture_class spell_13_level_01;
    texture_class spell_13_level_02;
    texture_class spell_13_level_03;
    texture_class spell_14_level_01;
    texture_class spell_14_level_02;
    texture_class spell_14_level_03;
    texture_class spell_15_level_01;
    texture_class spell_15_level_02;
    texture_class spell_15_level_03;
    texture_class spell_16_level_01;
    texture_class spell_16_level_02;
    texture_class spell_16_level_03;
    texture_class spell_17_level_01;
    texture_class spell_17_level_02;
    texture_class spell_17_level_03;
    texture_class spell_18_level_01;
    texture_class spell_18_level_02;
    texture_class spell_18_level_03;
    texture_class spell_19_level_01;
    texture_class spell_19_level_02;
    texture_class spell_19_level_03;
    texture_class spell_20_level_01;
    texture_class spell_20_level_02;
    texture_class spell_20_level_03;

    texture_class grass_and_water_tileset;
    texture_class bridge_tileset;
    texture_class grassland_tileset;
    texture_class grassland_water_tileset;
    texture_class grassland_trees_tileset;
    texture_class grassland_structures_tileset;
    texture_class broken_tower_tileset;
    texture_class fence_tileset;
    texture_class medieval_building_tileset;
    texture_class cave_floor_tileset;
    texture_class cave_wall_tileset;
    texture_class cave_object_tileset;
    texture_class dungeon_tileset;
    texture_class gold_tileset;

    texture_class book_00;
    texture_class book_01;
    texture_class book_02;
    texture_class book_03;
    texture_class book_04;
    texture_class book_05;
    texture_class book_06;
    texture_class book_07;
    texture_class book_08;
    texture_class book_09;
    texture_class book_10;
    texture_class book_11;
    texture_class book_12;
    texture_class book_13;
    texture_class book_14;
    texture_class book_15;
    texture_class book_16;
    texture_class book_17;
    texture_class book_18;
    texture_class book_19;

    texture_class armour_00;
    texture_class armour_01;
    texture_class armour_02;
    texture_class armour_03;
    texture_class armour_04;
    texture_class armour_05;
    texture_class armour_06;
    texture_class armour_07;
    texture_class armour_08;

    texture_class boots_00;
    texture_class boots_01;
    texture_class boots_02;
    texture_class boots_03;
    texture_class boots_04;
    texture_class boots_05;
    texture_class boots_06;
    texture_class boots_07;
    texture_class boots_08;
    texture_class boots_09;
    texture_class boots_10;
    texture_class boots_11;

    texture_class bow_00;
    texture_class bow_01;
    texture_class bow_02;

    texture_class dagger_00;
    texture_class dagger_01;
    texture_class dagger_02;
    texture_class dagger_03;
    texture_class dagger_04;
    texture_class dagger_05;
    texture_class dagger_06;
    texture_class dagger_07;
    texture_class dagger_08;
    texture_class dagger_09;
    texture_class dagger_10;
    texture_class dagger_11;
    texture_class dagger_12;
    texture_class dagger_13;
    texture_class dagger_14;
    texture_class dagger_15;
    texture_class dagger_16;
    texture_class dagger_17;
    texture_class dagger_18;
    texture_class dagger_19;
    texture_class dagger_20;
    texture_class dagger_21;
    texture_class dagger_22;
    texture_class dagger_23;
    texture_class dagger_24;
    texture_class dagger_25;
    texture_class dagger_26;
    texture_class dagger_27;

    texture_class ring_00;
    texture_class ring_01;
    texture_class ring_02;
    texture_class ring_03;
    texture_class ring_04;
    texture_class ring_05;
    texture_class ring_06;
    texture_class ring_07;
    texture_class ring_08;
    texture_class ring_09;
    texture_class ring_10;
    texture_class ring_11;
    texture_class ring_12;
    texture_class ring_13;
    texture_class ring_14;
    texture_class ring_15;
    texture_class ring_16;
    texture_class ring_17;
    texture_class ring_18;

    texture_class shield_00;
    texture_class shield_01;
    texture_class shield_02;
    texture_class shield_03;
    texture_class shield_04;
    texture_class shield_05;
    texture_class shield_06;

    texture_class sling_00;
    texture_class sling_01;
    texture_class sling_02;
    texture_class sling_03;

    texture_class sword_00;
    texture_class sword_01;
    texture_class sword_02;
    texture_class sword_03;
    texture_class sword_04;
    texture_class sword_05;
    texture_class sword_06;
    texture_class sword_07;
    texture_class sword_08;
    texture_class sword_09;
    texture_class sword_10;
    texture_class sword_11;
    texture_class sword_12;
    texture_class sword_13;
    texture_class sword_14;
    texture_class sword_15;
    texture_class sword_16;
    texture_class sword_17;
    texture_class sword_18;
    texture_class sword_19;
    texture_class sword_20;
    texture_class sword_21;
    texture_class sword_22;
    texture_class sword_23;
    texture_class sword_24;
    texture_class sword_25;
    texture_class sword_26;
    texture_class sword_27;

    texture_class wand_00;
    texture_class wand_01;
    texture_class wand_02;
    texture_class wand_03;
    texture_class wand_04;
    texture_class wand_05;
    texture_class wand_06;
    texture_class wand_07;
    texture_class wand_08;
    texture_class wand_09;
    texture_class wand_10;
    texture_class wand_11;
    texture_class wand_12;
    texture_class wand_13;
    texture_class wand_14;
    texture_class wand_15;
    texture_class wand_16;
    texture_class wand_17;
    texture_class wand_18;
    texture_class wand_19;
    texture_class wand_20;

    texture_class potion_01;
    texture_class potion_02;
    texture_class potion_03;
    texture_class potion_04;
    texture_class potion_05;
    texture_class potion_06;
    texture_class potion_07;
    texture_class potion_08;
    texture_class potion_09;
    texture_class potion_10;
    texture_class potion_11;
    texture_class potion_12;
    texture_class potion_13;
    texture_class potion_14;
    texture_class potion_15;
    texture_class potion_16;
    texture_class potion_17;
    texture_class potion_18;
    texture_class potion_19;
    texture_class potion_20;
    texture_class potion_21;

    texture_class amulet_00;
    texture_class amulet_01;
    texture_class amulet_02;
    texture_class amulet_03;
    texture_class amulet_04;
    texture_class amulet_05;
    texture_class amulet_06;
    texture_class amulet_07;
    texture_class amulet_08;
    texture_class amulet_09;
    texture_class amulet_10;
    texture_class amulet_11;
    texture_class amulet_12;
    texture_class amulet_13;

    texture_class belt_00;

    texture_class helm_00;
    texture_class helm_01;

    texture_class portrait_00;
    texture_class portrait_01;
    texture_class portrait_02;
    texture_class portrait_03;
    texture_class portrait_04;
    texture_class portrait_05;
    texture_class portrait_06;
    texture_class portrait_07;
    texture_class portrait_08;
    texture_class portrait_09;
    texture_class portrait_10;

    texture_class heightmap_001;

    texture_class generic_lava;
};

struct font_type
{
    font_class font_1;
};

bool load_resources(void);
bool load_maps_2D(void);
bool load_maps_3D(void);
bool load_sounds(void);
bool play_sound(int sound_number);
bool load_music(void);
bool load_textures(void);
bool proc_textures(void);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle, int frame);
bool load_fonts(void);

bool loading_screen_display(std::string file_name);

#endif // LOAD_RESOURCES_H
















