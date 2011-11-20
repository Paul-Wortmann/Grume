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
    game.sound.menu_move_00.load    ("data/sound/menu_move_00.wav",sfx_count)    ;sfx_count++;
    game.sound.menu_select_00.load  ("data/sound/menu_select_00.wav",sfx_count)  ;sfx_count++;

    game.core.log.File_Write("Sound files loaded -> ",sfx_count);
    return(true);
};

bool load_music(void)
{
    int music_count = 0;
    game.music.menu_00.load("data/music/menu_00.s3m",music_count);music_count++;

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

    game.texture.logo.load_image                     ("data/textures/menu/logo.png"                     ,texture_count);texture_count++;
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

    game.texture.action_bar.load_image          ("data/textures/UI/action_bar/action_bar.png"           ,texture_count);texture_count++;
    game.texture.action_bar_front.load_image    ("data/textures/UI/action_bar/action_bar_front.png"     ,texture_count);texture_count++;
    game.texture.glass_cover_01.load_image      ("data/textures/UI/action_bar/glass_cover_01.png"       ,texture_count);texture_count++;
    game.texture.glass_cover_02.load_image      ("data/textures/UI/action_bar/glass_cover_02.png"       ,texture_count);texture_count++;
    game.texture.icon_01.load_image             ("data/textures/UI/action_bar/icon_01.png"              ,texture_count);texture_count++;
    game.texture.icon_02.load_image             ("data/textures/UI/action_bar/icon_02.png"              ,texture_count);texture_count++;
    game.texture.icon_03.load_image             ("data/textures/UI/action_bar/icon_03.png"              ,texture_count);texture_count++;
    game.texture.icon_04.load_image             ("data/textures/UI/action_bar/icon_04.png"              ,texture_count);texture_count++;
    game.texture.icon_05.load_image             ("data/textures/UI/action_bar/icon_05.png"              ,texture_count);texture_count++;
    game.texture.icon_06.load_image             ("data/textures/UI/action_bar/icon_06.png"              ,texture_count);texture_count++;
    game.texture.icon_melee.load_image          ("data/textures/UI/action_bar/icon_melee.png"           ,texture_count);texture_count++;

    game.texture.health_bar.load_image              ("data/textures/UI/portrait/health_bar.png"               ,texture_count);texture_count++;
    game.texture.mana_bar.load_image                ("data/textures/UI/portrait/mana_bar.png"                 ,texture_count);texture_count++;
    game.texture.profile_background.load_image      ("data/textures/UI/portrait/profile_background.png"       ,texture_count);texture_count++;
    game.texture.profile_main.load_image            ("data/textures/UI/portrait/profile_main.png"             ,texture_count);texture_count++;
    game.texture.profile_main_background.load_image ("data/textures/UI/portrait/profile_main_background.png"  ,texture_count);texture_count++;

    game.texture.spell_book.load_image              ("data/textures/UI/spell_book/spell_book.png"             ,texture_count);texture_count++;
    game.texture.spell_book_spell_cover.load_image  ("data/textures/UI/spell_book/spell_book_spell_cover.png" ,texture_count);texture_count++;

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

    if (texture_number == game.texture.logo.ref_number)                      game.texture.logo.draw                     (r,x,y,z,w,h,angle);
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

    if (texture_number == game.texture.action_bar.ref_number)                game.texture.action_bar.draw               (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.action_bar_front.ref_number)          game.texture.action_bar_front.draw         (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.glass_cover_01.ref_number)            game.texture.glass_cover_01.draw           (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.glass_cover_02.ref_number)            game.texture.glass_cover_02.draw           (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.icon_01.ref_number)                   game.texture.icon_01.draw                  (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.icon_02.ref_number)                   game.texture.icon_02.draw                  (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.icon_03.ref_number)                   game.texture.icon_03.draw                  (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.icon_04.ref_number)                   game.texture.icon_04.draw                  (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.icon_05.ref_number)                   game.texture.icon_05.draw                  (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.icon_06.ref_number)                   game.texture.icon_06.draw                  (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.icon_melee.ref_number)                game.texture.icon_melee.draw               (r,x,y,z,w,h,angle);

    if (texture_number == game.texture.health_bar.ref_number)                game.texture.health_bar.draw               (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.mana_bar.ref_number)                  game.texture.mana_bar.draw                 (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.profile_background.ref_number)        game.texture.profile_background.draw       (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.profile_main.ref_number)              game.texture.profile_main.draw             (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.profile_main_background.ref_number)   game.texture.profile_main_background.draw  (r,x,y,z,w,h,angle);

    if (texture_number == game.texture.spell_book.ref_number)                game.texture.spell_book.draw               (r,x,y,z,w,h,angle);
    if (texture_number == game.texture.spell_book_spell_cover.ref_number)    game.texture.spell_book_spell_cover.draw   (r,x,y,z,w,h,angle);

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




