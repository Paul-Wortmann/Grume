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

#ifndef LOAD_RESOURCES_H
#define LOAD_RESOURCES_H

#include "core/core.hpp"
#include "core/sound.hpp"
#include "core/music.hpp"
#include "core/textures.hpp"
#include "core/font.hpp"
#include "map.hpp"

struct sound_type
{
    sound_class   menu_move_00;
    sound_class   menu_select_00;
};

struct map_type
{
    map_class   town;
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
    texture_class profile_background;
    texture_class profile_main;
    texture_class profile_main_background;

    texture_class spell_book;
    texture_class spell_book_spell_cover;
    texture_class spell_book_background;
    texture_class inventory;
    texture_class character_background;
    texture_class quest_log_background;

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

    texture_class grass_and_water_tileset;
    texture_class bridge_tileset;
};

struct font_type
{
    font_class font_1;
};

bool load_resources(void);
bool load_maps(void);
bool load_sounds(void);
bool load_music(void);
bool load_textures(void);
bool proc_textures(void);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle, int frame);
bool load_fonts(void);

bool loading_screen_display(std::string file_name);

#endif // LOAD_RESOURCES_H
















