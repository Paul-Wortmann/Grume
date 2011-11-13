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

struct sound_type
{
};

struct music_type
{
};

struct texture_type
{
    texture_class background_00;
    texture_class background_01;

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

};

struct font_type
{
    font_class font_1;
};

bool load_resources(void);
bool load_sounds(void);
bool load_music(void);
bool load_textures(void);
bool proc_textures(void);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h);
bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle);
bool load_fonts(void);

bool loading_screen_display(std::string file_name);

#endif // LOAD_RESOURCES_H
















