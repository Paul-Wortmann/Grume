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
#include "game.hpp"

extern game_type         game;

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
    game.sound.menu_move_00.load    ("data/sounds/menu_move_00.wav",sfx_count)    ;sfx_count++;
    game.sound.menu_select_00.load  ("data/sounds/menu_select_00.wav",sfx_count)  ;sfx_count++;

    game.core.log.File_Write("Sound files loaded -> ",sfx_count);
    return(true);
};

bool load_music(void)
{
    int music_count = 0;
    game.music.menu_00.load("data/music/menu_00.xm",music_count);music_count++;

    game.core.log.File_Write("Music files loaded -> ",music_count);
    return(true);
};

bool load_textures(void)
{
    int texture_count = 0;
    game.texture.background_00.load_image("data/textures/menu/background_00.png",texture_count);texture_count++;
    game.texture.background_01.load_image("data/textures/menu/background_01.png",texture_count);texture_count++;
    game.texture.background_02.load_image("data/textures/menu/background_02.png",texture_count);texture_count++;
    game.texture.background_03.load_image("data/textures/menu/background_03.png",texture_count);texture_count++;

    game.texture.button_normal.load_image            ("data/textures/menu/button_normal.png"            ,texture_count);texture_count++;
    game.texture.button_highlighted.load_image       ("data/textures/menu/button_highlighted.png"       ,texture_count);texture_count++;
    game.texture.button_disabled.load_image          ("data/textures/menu/button_disabled.png"          ,texture_count);texture_count++;
    game.texture.close_button.load_image             ("data/textures/menu/close_button.png"             ,texture_count);texture_count++;
    game.texture.close_button_highlighted.load_image ("data/textures/menu/close_button_highlighted.png" ,texture_count);texture_count++;
    game.texture.selection_box.load_image            ("data/textures/menu/selection_box.png"            ,texture_count);texture_count++;
    game.texture.arrow_button_normal.load_image      ("data/textures/menu/arrow_normal.png"             ,texture_count);texture_count++;
    game.texture.arrow_button_highlighted.load_image ("data/textures/menu/arrow_highlighted.png"        ,texture_count);texture_count++;
    game.texture.arrow_button_disabled.load_image    ("data/textures/menu/arrow_disabled.png"           ,texture_count);texture_count++;
    game.texture.slider_button_normal.load_image     ("data/textures/menu/slider_normal.png"            ,texture_count);texture_count++;
    game.texture.slider_button_highlighted.load_image("data/textures/menu/slider_highlighted.png"       ,texture_count);texture_count++;
    game.texture.red_button.load_image               ("data/textures/menu/red_button.png"               ,texture_count);texture_count++;
    game.texture.red_button_highlighted.load_image   ("data/textures/menu/red_button_highlighted.png"   ,texture_count);texture_count++;
    game.texture.green_button.load_image             ("data/textures/menu/green_button.png"             ,texture_count);texture_count++;
    game.texture.green_button_highlighted.load_image ("data/textures/menu/green_button_highlighted.png" ,texture_count);texture_count++;
    game.texture.blue_button.load_image              ("data/textures/menu/blue_button.png"              ,texture_count);texture_count++;
    game.texture.blue_button_highlighted.load_image  ("data/textures/menu/blue_button_highlighted.png"  ,texture_count);texture_count++;
    game.texture.resolution_icon.load_image          ("data/textures/menu/resolution_icon.png"          ,texture_count);texture_count++;

    game.texture.particle_000.load_image("data/textures/particles/particle_000.png",texture_count);texture_count++;
    game.texture.particle_001.load_image("data/textures/particles/particle_001.png",texture_count);texture_count++;
    game.texture.particle_002.load_image("data/textures/particles/particle_002.png",texture_count);texture_count++;
    game.texture.particle_003.load_image("data/textures/particles/particle_003.png",texture_count);texture_count++;
    game.texture.particle_004.load_image("data/textures/particles/particle_004.png",texture_count);texture_count++;
    game.texture.particle_005.load_image("data/textures/particles/particle_005.png",texture_count);texture_count++;
    game.texture.particle_006.load_image("data/textures/particles/particle_006.png",texture_count);texture_count++;
    game.texture.particle_007.load_image("data/textures/particles/particle_007.png",texture_count);texture_count++;
    game.texture.particle_008.load_image("data/textures/particles/particle_008.png",texture_count);texture_count++;
    game.texture.particle_009.load_image("data/textures/particles/particle_009.png",texture_count);texture_count++;
    game.texture.particle_010.load_image("data/textures/particles/particle_010.png",texture_count);texture_count++;
    game.texture.particle_011.load_image("data/textures/particles/particle_011.png",texture_count);texture_count++;
    game.texture.particle_012.load_image("data/textures/particles/particle_012.png",texture_count);texture_count++;
    game.texture.particle_013.load_image("data/textures/particles/particle_013.png",texture_count);texture_count++;
    game.texture.particle_014.load_image("data/textures/particles/particle_014.png",texture_count);texture_count++;
    game.texture.particle_015.load_image("data/textures/particles/particle_015.png",texture_count);texture_count++;

    game.core.log.File_Write("Texture files loaded -> ",texture_count);
    return(true);
};

bool proc_textures(void)
{
    //used for sprite sheets
};

bool load_fonts(void)
{
    int font_count = 0;
    game.font.font_1.Set_File("data/fonts/font_001.ttf");font_count++;
    game.core.log.File_Write("Font files loaded -> ",font_count);
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
    if (texture_number == game.texture.background_00.ref_number) game.texture.background_00.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.background_01.ref_number) game.texture.background_01.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.background_02.ref_number) game.texture.background_02.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.background_03.ref_number) game.texture.background_03.draw(r,x,y,z,w,h,angle);

    if (texture_number == game.texture.button_normal.ref_number)             game.texture.button_normal.draw            (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.button_highlighted.ref_number)        game.texture.button_highlighted.draw       (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.button_disabled.ref_number)           game.texture.button_disabled.draw          (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.close_button.ref_number)              game.texture.close_button.draw             (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.close_button_highlighted.ref_number)  game.texture.close_button_highlighted.draw (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.selection_box.ref_number)             game.texture.selection_box.draw            (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.arrow_button_normal.ref_number)       game.texture.arrow_button_normal.draw      (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.arrow_button_highlighted.ref_number)  game.texture.arrow_button_highlighted.draw (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.arrow_button_disabled.ref_number)     game.texture.arrow_button_disabled.draw    (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.slider_button_normal.ref_number)      game.texture.slider_button_normal.draw     (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.slider_button_highlighted.ref_number) game.texture.slider_button_highlighted.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.red_button.ref_number)                game.texture.red_button.draw               (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.red_button_highlighted.ref_number)    game.texture.red_button_highlighted.draw   (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.green_button.ref_number)              game.texture.green_button.draw             (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.green_button_highlighted.ref_number)  game.texture.green_button_highlighted.draw (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.blue_button.ref_number)               game.texture.blue_button.draw              (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.blue_button_highlighted.ref_number)   game.texture.blue_button_highlighted.draw  (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.resolution_icon.ref_number)           game.texture.resolution_icon.draw          (r,x,y,z,w,h,angle);

    if (texture_number == game.texture.particle_000.ref_number) game.texture.particle_000.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_001.ref_number) game.texture.particle_001.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_002.ref_number) game.texture.particle_002.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_003.ref_number) game.texture.particle_003.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_004.ref_number) game.texture.particle_004.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_005.ref_number) game.texture.particle_005.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_006.ref_number) game.texture.particle_006.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_007.ref_number) game.texture.particle_007.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_008.ref_number) game.texture.particle_008.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_009.ref_number) game.texture.particle_009.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_010.ref_number) game.texture.particle_010.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_011.ref_number) game.texture.particle_011.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_012.ref_number) game.texture.particle_012.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_013.ref_number) game.texture.particle_013.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_014.ref_number) game.texture.particle_014.draw(r,x,y,z,w,h,angle);
    if (texture_number == game.texture.particle_015.ref_number) game.texture.particle_015.draw(r,x,y,z,w,h,angle);

    return(true);
};




