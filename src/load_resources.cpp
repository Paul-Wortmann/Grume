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
#include "load_resources.hpp"
#include "core/core.hpp"

extern game_class        game;
       sound_type        sound;
       music_type        music;
       texture_type      texture;
       font_type         font;

bool load_resources(void)
{
    load_sounds();
    load_music();
    load_textures();
    load_fonts();
    return(true);
};

bool load_sounds(void)
{
    int sfx_count = 0;
    //sound.menu_move_00.load  ("data/sounds/menu_move_00.wav",sfx_count)  ;sfx_count++;

    game.log.File_Write("Sound files loaded -> ",sfx_count);
    return(true);
};

bool load_music(void)
{
    int music_count = 0;
    //music.level_00.load("data/music/level_00.s3m",music_count);music_count++;

    game.log.File_Write("Music files loaded -> ",music_count);
    return(true);
};

bool load_textures(void)
{
    int texture_count = 0;
    texture.background_00.load_image("data/textures/menu/background_00.png",texture_count);texture_count++;
    texture.background_01.load_image("data/textures/menu/background_01.png",texture_count);texture_count++;

    texture.particle_000.load_image("data/textures/particles/particle_000.png",texture_count);texture_count++;
    texture.particle_001.load_image("data/textures/particles/particle_001.png",texture_count);texture_count++;
    texture.particle_002.load_image("data/textures/particles/particle_002.png",texture_count);texture_count++;
    texture.particle_003.load_image("data/textures/particles/particle_003.png",texture_count);texture_count++;
    texture.particle_004.load_image("data/textures/particles/particle_004.png",texture_count);texture_count++;
    texture.particle_005.load_image("data/textures/particles/particle_005.png",texture_count);texture_count++;
    texture.particle_006.load_image("data/textures/particles/particle_006.png",texture_count);texture_count++;
    texture.particle_007.load_image("data/textures/particles/particle_007.png",texture_count);texture_count++;
    texture.particle_008.load_image("data/textures/particles/particle_008.png",texture_count);texture_count++;
    texture.particle_009.load_image("data/textures/particles/particle_009.png",texture_count);texture_count++;
    texture.particle_010.load_image("data/textures/particles/particle_010.png",texture_count);texture_count++;
    texture.particle_011.load_image("data/textures/particles/particle_011.png",texture_count);texture_count++;
    texture.particle_012.load_image("data/textures/particles/particle_012.png",texture_count);texture_count++;
    texture.particle_013.load_image("data/textures/particles/particle_013.png",texture_count);texture_count++;
    texture.particle_014.load_image("data/textures/particles/particle_014.png",texture_count);texture_count++;
    texture.particle_015.load_image("data/textures/particles/particle_015.png",texture_count);texture_count++;

    game.log.File_Write("Texture files loaded -> ",texture_count);
    return(true);
};

bool proc_textures(void)
{
    texture.background_00.process();
    texture.background_01.process();

    texture.particle_000.process();
    texture.particle_001.process();
    texture.particle_002.process();
    texture.particle_003.process();
    texture.particle_004.process();
    texture.particle_005.process();
    texture.particle_006.process();
    texture.particle_007.process();
    texture.particle_008.process();
    texture.particle_009.process();
    texture.particle_010.process();
    texture.particle_011.process();
    texture.particle_012.process();
    texture.particle_013.process();
    texture.particle_014.process();
    texture.particle_015.process();

};

bool load_fonts(void)
{
    int font_count = 0;
    font.font_1.Set_File("data/fonts/font_001.ttf");font_count++;
    game.log.File_Write("Font files loaded -> ",font_count);
    return(true);
};

bool loading_screen_display(std::string file_name)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapBuffers();
    texture_class loading_screen;
    loading_screen.load_image(file_name,0);
    loading_screen.draw(false,0.0f,0.0f,0.9f,2.0f,2.0f);
    SDL_GL_SwapBuffers();
    return(true);
};

bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h)
{
    draw_texture(r,texture_number,x,y,z,w,h,0.0f);
};

bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle)
{
    if (texture_number == texture.background_00.ref_number) texture.background_00.draw(r,x,y,z,w,h,angle);
    if (texture_number == texture.background_01.ref_number) texture.background_01.draw(r,x,y,z,w,h,angle);

    return(true);
};




