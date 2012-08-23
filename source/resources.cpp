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

#include <SDL/SDL.h>
#include "resources.hpp"
#include "game.hpp"

extern game_class         game;

//---------------------------------------- sound_resource_class ----------------------------------------------------------

void sound_resource_class::play(int sound_number)
{
    if (sound_number == game.resource.sound.menu_move_00.ref_number)   game.resource.sound.menu_move_00.play();
    if (sound_number == game.resource.sound.menu_select_00.ref_number) game.resource.sound.menu_select_00.play();

    if (sound_number == game.resource.sound.bottle_01.ref_number)      game.resource.sound.bottle_01.play();
    if (sound_number == game.resource.sound.bubble_01.ref_number)      game.resource.sound.bubble_01.play();
    if (sound_number == game.resource.sound.bubble_02.ref_number)      game.resource.sound.bubble_02.play();
    if (sound_number == game.resource.sound.bubble_03.ref_number)      game.resource.sound.bubble_03.play();

    if (sound_number == game.resource.sound.book_00.ref_number)        game.resource.sound.book_00.play();
    if (sound_number == game.resource.sound.book_01.ref_number)        game.resource.sound.book_01.play();
    if (sound_number == game.resource.sound.book_02.ref_number)        game.resource.sound.book_02.play();
};

//---------------------------------------- texture_resource_class ----------------------------------------------------------

void texture_resource_class::process(void)
{
    //use for sprite sheets / animation
};

void texture_resource_class::render(bool r, int texture_number, float x, float y, float z, float w, float h)
{
    game.resource.texture.render(r,texture_number,x,y,z,w,h,0.0f,0);
};

void texture_resource_class::render(bool r, int texture_number, float x, float y, float z, float w, float h, float angle)
{
    game.resource.texture.render(r,texture_number,x,y,z,w,h,angle,0);
};

void texture_resource_class::render(bool r, int texture_number, float x, float y, float z, float w, float h, float angle, int frame)
{
    if (texture_number == game.resource.texture.default_texture.ref_number) game.resource.texture.default_texture.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.background_00.ref_number) game.resource.texture.background_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.background_01.ref_number) game.resource.texture.background_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.background_02.ref_number) game.resource.texture.background_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.background_03.ref_number) game.resource.texture.background_03.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.logo.ref_number)                      game.resource.texture.logo.draw                     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.button_normal.ref_number)             game.resource.texture.button_normal.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.button_highlighted.ref_number)        game.resource.texture.button_highlighted.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.button_disabled.ref_number)           game.resource.texture.button_disabled.draw          (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.close_button.ref_number)              game.resource.texture.close_button.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.close_button_highlighted.ref_number)  game.resource.texture.close_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.selection_box.ref_number)             game.resource.texture.selection_box.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.arrow_button_normal.ref_number)       game.resource.texture.arrow_button_normal.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.arrow_button_highlighted.ref_number)  game.resource.texture.arrow_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.arrow_button_disabled.ref_number)     game.resource.texture.arrow_button_disabled.draw    (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.slider_button_normal.ref_number)      game.resource.texture.slider_button_normal.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.slider_button_highlighted.ref_number) game.resource.texture.slider_button_highlighted.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.red_button.ref_number)                game.resource.texture.red_button.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.red_button_highlighted.ref_number)    game.resource.texture.red_button_highlighted.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.green_button.ref_number)              game.resource.texture.green_button.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.green_button_highlighted.ref_number)  game.resource.texture.green_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.blue_button.ref_number)               game.resource.texture.blue_button.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.blue_button_highlighted.ref_number)   game.resource.texture.blue_button_highlighted.draw  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.resolution_icon.ref_number)           game.resource.texture.resolution_icon.draw          (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.cursor.ref_number)                    game.resource.texture.cursor.draw                   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.action_bar.ref_number)                game.resource.texture.action_bar.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.action_bar_front.ref_number)          game.resource.texture.action_bar_front.draw         (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.glass_cover_01.ref_number)            game.resource.texture.glass_cover_01.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.glass_cover_02.ref_number)            game.resource.texture.glass_cover_02.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.icon_01.ref_number)                   game.resource.texture.icon_01.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.icon_02.ref_number)                   game.resource.texture.icon_02.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.icon_03.ref_number)                   game.resource.texture.icon_03.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.icon_04.ref_number)                   game.resource.texture.icon_04.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.icon_05.ref_number)                   game.resource.texture.icon_05.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.icon_06.ref_number)                   game.resource.texture.icon_06.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.icon_melee.ref_number)                game.resource.texture.icon_melee.draw               (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.health_bar.ref_number)                game.resource.texture.health_bar.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.mana_bar.ref_number)                  game.resource.texture.mana_bar.draw                 (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.experience_bar.ref_number)            game.resource.texture.experience_bar.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.profile_background.ref_number)        game.resource.texture.profile_background.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.profile_main.ref_number)              game.resource.texture.profile_main.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.profile_main_background.ref_number)   game.resource.texture.profile_main_background.draw  (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.spell_book.ref_number)                  game.resource.texture.spell_book.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_book_spell_cover.ref_number)      game.resource.texture.spell_book_spell_cover.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_book_background.ref_number)       game.resource.texture.spell_book_background.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.inventory.ref_number)                   game.resource.texture.inventory.draw                   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.inventory_gold.ref_number)              game.resource.texture.inventory_gold.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.inventory_background.ref_number)        game.resource.texture.inventory_background.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.item_stat_background.ref_number)        game.resource.texture.item_stat_background.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.character_portrait_frame.ref_number)    game.resource.texture.character_portrait_frame.draw    (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.character_background.ref_number)        game.resource.texture.character_background.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.check_box_true_highlighted.ref_number)  game.resource.texture.check_box_true_highlighted.draw  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.check_box_false_highlighted.ref_number) game.resource.texture.check_box_false_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.check_box_true_normal.ref_number)       game.resource.texture.check_box_true_normal.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.check_box_false_normal.ref_number)      game.resource.texture.check_box_false_normal.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.quest_log_background.ref_number)        game.resource.texture.quest_log_background.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.equipment_background.ref_number)        game.resource.texture.equipment_background.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.equipment_slot_32x32.ref_number)        game.resource.texture.equipment_slot_32x32.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.equipment_slot_64x32.ref_number)        game.resource.texture.equipment_slot_64x32.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.equipment_slot_64x64.ref_number)        game.resource.texture.equipment_slot_64x64.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.equipment_slot_64x96.ref_number)        game.resource.texture.equipment_slot_64x96.draw        (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.enemy_health_bar_000.ref_number)            game.resource.texture.enemy_health_bar_000.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_001.ref_number)            game.resource.texture.enemy_health_bar_001.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_background_000.ref_number) game.resource.texture.enemy_health_bar_background_000.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_background_001.ref_number) game.resource.texture.enemy_health_bar_background_001.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_000.ref_number) game.resource.texture.enemy_health_bar_foreground_000.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_001.ref_number) game.resource.texture.enemy_health_bar_foreground_001.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_002.ref_number) game.resource.texture.enemy_health_bar_foreground_002.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_003.ref_number) game.resource.texture.enemy_health_bar_foreground_003.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_004.ref_number) game.resource.texture.enemy_health_bar_foreground_004.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_005.ref_number) game.resource.texture.enemy_health_bar_foreground_005.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_mana_bar_000.ref_number)              game.resource.texture.enemy_mana_bar_000.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.enemy_mana_bar_001.ref_number)              game.resource.texture.enemy_mana_bar_001.draw        (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.particle_000.ref_number) game.resource.texture.particle_000.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_001.ref_number) game.resource.texture.particle_001.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_002.ref_number) game.resource.texture.particle_002.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_003.ref_number) game.resource.texture.particle_003.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_004.ref_number) game.resource.texture.particle_004.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_005.ref_number) game.resource.texture.particle_005.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_006.ref_number) game.resource.texture.particle_006.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_007.ref_number) game.resource.texture.particle_007.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_008.ref_number) game.resource.texture.particle_008.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_009.ref_number) game.resource.texture.particle_009.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_010.ref_number) game.resource.texture.particle_010.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_011.ref_number) game.resource.texture.particle_011.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_012.ref_number) game.resource.texture.particle_012.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_013.ref_number) game.resource.texture.particle_013.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_014.ref_number) game.resource.texture.particle_014.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.particle_015.ref_number) game.resource.texture.particle_015.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.spell_01_level_01.ref_number) game.resource.texture.spell_01_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_01_level_02.ref_number) game.resource.texture.spell_01_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_01_level_03.ref_number) game.resource.texture.spell_01_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_02_level_01.ref_number) game.resource.texture.spell_02_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_02_level_02.ref_number) game.resource.texture.spell_02_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_02_level_03.ref_number) game.resource.texture.spell_02_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_03_level_01.ref_number) game.resource.texture.spell_03_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_03_level_02.ref_number) game.resource.texture.spell_03_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_03_level_03.ref_number) game.resource.texture.spell_03_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_04_level_01.ref_number) game.resource.texture.spell_04_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_04_level_02.ref_number) game.resource.texture.spell_04_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_04_level_03.ref_number) game.resource.texture.spell_04_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_05_level_01.ref_number) game.resource.texture.spell_05_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_05_level_02.ref_number) game.resource.texture.spell_05_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_05_level_03.ref_number) game.resource.texture.spell_05_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_06_level_01.ref_number) game.resource.texture.spell_06_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_06_level_02.ref_number) game.resource.texture.spell_06_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_06_level_03.ref_number) game.resource.texture.spell_06_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_07_level_01.ref_number) game.resource.texture.spell_07_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_07_level_02.ref_number) game.resource.texture.spell_07_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_07_level_03.ref_number) game.resource.texture.spell_07_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_08_level_01.ref_number) game.resource.texture.spell_08_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_08_level_02.ref_number) game.resource.texture.spell_08_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_08_level_03.ref_number) game.resource.texture.spell_08_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_09_level_01.ref_number) game.resource.texture.spell_09_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_09_level_02.ref_number) game.resource.texture.spell_09_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_09_level_03.ref_number) game.resource.texture.spell_09_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_10_level_01.ref_number) game.resource.texture.spell_10_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_10_level_02.ref_number) game.resource.texture.spell_10_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_10_level_03.ref_number) game.resource.texture.spell_10_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_11_level_01.ref_number) game.resource.texture.spell_11_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_11_level_02.ref_number) game.resource.texture.spell_11_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_11_level_03.ref_number) game.resource.texture.spell_11_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_12_level_01.ref_number) game.resource.texture.spell_12_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_12_level_02.ref_number) game.resource.texture.spell_12_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_12_level_03.ref_number) game.resource.texture.spell_12_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_13_level_01.ref_number) game.resource.texture.spell_13_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_13_level_02.ref_number) game.resource.texture.spell_13_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_13_level_03.ref_number) game.resource.texture.spell_13_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_14_level_01.ref_number) game.resource.texture.spell_14_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_14_level_02.ref_number) game.resource.texture.spell_14_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_14_level_03.ref_number) game.resource.texture.spell_14_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_15_level_01.ref_number) game.resource.texture.spell_15_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_15_level_02.ref_number) game.resource.texture.spell_15_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.spell_15_level_03.ref_number) game.resource.texture.spell_15_level_03.draw(r,x,y,z,w,h,angle,frame);
/*
    if (texture_number == game.resource.texture.grass_and_water_tileset.ref_number)         game.resource.texture.grass_and_water_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.bridge_tileset.ref_number)                  game.resource.texture.bridge_tileset.draw                 (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.grassland_tileset.ref_number)               game.resource.texture.grassland_tileset.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.grassland_water_tileset.ref_number)         game.resource.texture.grassland_water_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.grassland_trees_tileset.ref_number)         game.resource.texture.grassland_trees_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.grassland_structures_tileset.ref_number)    game.resource.texture.grassland_structures_tileset.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.broken_tower_tileset.ref_number)            game.resource.texture.broken_tower_tileset.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.fence_tileset.ref_number)                   game.resource.texture.fence_tileset.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.medieval_building_tileset.ref_number)       game.resource.texture.medieval_building_tileset.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.cave_floor_tileset.ref_number)              game.resource.texture.cave_floor_tileset.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.cave_wall_tileset.ref_number)               game.resource.texture.cave_wall_tileset.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.cave_object_tileset.ref_number)             game.resource.texture.cave_object_tileset.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dungeon_tileset.ref_number)                 game.resource.texture.dungeon_tileset.draw                (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.gold_tileset.ref_number)                    game.resource.texture.gold_tileset.draw                   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.test_tileset.ref_number)                    game.resource.texture.test_tileset.draw                   (r,x,y,z,w,h,angle,frame);
*/
    if (texture_number == game.resource.texture.book_00.ref_number) game.resource.texture.book_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_01.ref_number) game.resource.texture.book_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_02.ref_number) game.resource.texture.book_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_03.ref_number) game.resource.texture.book_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_04.ref_number) game.resource.texture.book_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_05.ref_number) game.resource.texture.book_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_06.ref_number) game.resource.texture.book_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_07.ref_number) game.resource.texture.book_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_08.ref_number) game.resource.texture.book_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_09.ref_number) game.resource.texture.book_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_10.ref_number) game.resource.texture.book_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_11.ref_number) game.resource.texture.book_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_12.ref_number) game.resource.texture.book_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_13.ref_number) game.resource.texture.book_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_14.ref_number) game.resource.texture.book_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_15.ref_number) game.resource.texture.book_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_16.ref_number) game.resource.texture.book_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_17.ref_number) game.resource.texture.book_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_18.ref_number) game.resource.texture.book_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.book_19.ref_number) game.resource.texture.book_19.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.armour_00.ref_number) game.resource.texture.armour_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_01.ref_number) game.resource.texture.armour_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_02.ref_number) game.resource.texture.armour_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_03.ref_number) game.resource.texture.armour_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_04.ref_number) game.resource.texture.armour_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_05.ref_number) game.resource.texture.armour_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_06.ref_number) game.resource.texture.armour_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_07.ref_number) game.resource.texture.armour_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.armour_08.ref_number) game.resource.texture.armour_08.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.boots_00.ref_number) game.resource.texture.boots_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_01.ref_number) game.resource.texture.boots_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_02.ref_number) game.resource.texture.boots_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_03.ref_number) game.resource.texture.boots_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_04.ref_number) game.resource.texture.boots_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_05.ref_number) game.resource.texture.boots_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_06.ref_number) game.resource.texture.boots_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_07.ref_number) game.resource.texture.boots_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_08.ref_number) game.resource.texture.boots_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_09.ref_number) game.resource.texture.boots_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_10.ref_number) game.resource.texture.boots_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.boots_11.ref_number) game.resource.texture.boots_11.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.bow_00.ref_number) game.resource.texture.bow_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.bow_01.ref_number) game.resource.texture.bow_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.bow_02.ref_number) game.resource.texture.bow_02.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.dagger_00.ref_number) game.resource.texture.dagger_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_01.ref_number) game.resource.texture.dagger_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_02.ref_number) game.resource.texture.dagger_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_03.ref_number) game.resource.texture.dagger_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_04.ref_number) game.resource.texture.dagger_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_05.ref_number) game.resource.texture.dagger_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_06.ref_number) game.resource.texture.dagger_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_07.ref_number) game.resource.texture.dagger_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_08.ref_number) game.resource.texture.dagger_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_09.ref_number) game.resource.texture.dagger_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_10.ref_number) game.resource.texture.dagger_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_11.ref_number) game.resource.texture.dagger_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_12.ref_number) game.resource.texture.dagger_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_13.ref_number) game.resource.texture.dagger_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_14.ref_number) game.resource.texture.dagger_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_15.ref_number) game.resource.texture.dagger_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_16.ref_number) game.resource.texture.dagger_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_17.ref_number) game.resource.texture.dagger_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_18.ref_number) game.resource.texture.dagger_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_19.ref_number) game.resource.texture.dagger_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_20.ref_number) game.resource.texture.dagger_20.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_21.ref_number) game.resource.texture.dagger_21.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_22.ref_number) game.resource.texture.dagger_22.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_23.ref_number) game.resource.texture.dagger_23.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_24.ref_number) game.resource.texture.dagger_24.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_25.ref_number) game.resource.texture.dagger_25.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_26.ref_number) game.resource.texture.dagger_26.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.dagger_27.ref_number) game.resource.texture.dagger_27.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.ring_00.ref_number) game.resource.texture.ring_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_01.ref_number) game.resource.texture.ring_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_02.ref_number) game.resource.texture.ring_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_03.ref_number) game.resource.texture.ring_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_04.ref_number) game.resource.texture.ring_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_05.ref_number) game.resource.texture.ring_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_06.ref_number) game.resource.texture.ring_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_07.ref_number) game.resource.texture.ring_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_08.ref_number) game.resource.texture.ring_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_09.ref_number) game.resource.texture.ring_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_10.ref_number) game.resource.texture.ring_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_11.ref_number) game.resource.texture.ring_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_12.ref_number) game.resource.texture.ring_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_13.ref_number) game.resource.texture.ring_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_14.ref_number) game.resource.texture.ring_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_15.ref_number) game.resource.texture.ring_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_16.ref_number) game.resource.texture.ring_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_17.ref_number) game.resource.texture.ring_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.ring_18.ref_number) game.resource.texture.ring_18.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.shield_00.ref_number) game.resource.texture.shield_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.shield_01.ref_number) game.resource.texture.shield_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.shield_02.ref_number) game.resource.texture.shield_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.shield_03.ref_number) game.resource.texture.shield_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.shield_04.ref_number) game.resource.texture.shield_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.shield_05.ref_number) game.resource.texture.shield_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.shield_06.ref_number) game.resource.texture.shield_06.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.sling_00.ref_number) game.resource.texture.sling_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sling_01.ref_number) game.resource.texture.sling_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sling_02.ref_number) game.resource.texture.sling_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sling_03.ref_number) game.resource.texture.sling_03.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.sword_00.ref_number) game.resource.texture.sword_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_01.ref_number) game.resource.texture.sword_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_02.ref_number) game.resource.texture.sword_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_03.ref_number) game.resource.texture.sword_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_04.ref_number) game.resource.texture.sword_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_05.ref_number) game.resource.texture.sword_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_06.ref_number) game.resource.texture.sword_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_07.ref_number) game.resource.texture.sword_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_08.ref_number) game.resource.texture.sword_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_09.ref_number) game.resource.texture.sword_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_10.ref_number) game.resource.texture.sword_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_11.ref_number) game.resource.texture.sword_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_12.ref_number) game.resource.texture.sword_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_13.ref_number) game.resource.texture.sword_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_14.ref_number) game.resource.texture.sword_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_15.ref_number) game.resource.texture.sword_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_16.ref_number) game.resource.texture.sword_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_17.ref_number) game.resource.texture.sword_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_18.ref_number) game.resource.texture.sword_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_19.ref_number) game.resource.texture.sword_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_20.ref_number) game.resource.texture.sword_20.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_21.ref_number) game.resource.texture.sword_21.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_22.ref_number) game.resource.texture.sword_22.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_23.ref_number) game.resource.texture.sword_23.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_24.ref_number) game.resource.texture.sword_24.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_25.ref_number) game.resource.texture.sword_25.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_26.ref_number) game.resource.texture.sword_26.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.sword_27.ref_number) game.resource.texture.sword_27.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.wand_00.ref_number) game.resource.texture.wand_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_01.ref_number) game.resource.texture.wand_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_02.ref_number) game.resource.texture.wand_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_03.ref_number) game.resource.texture.wand_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_04.ref_number) game.resource.texture.wand_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_05.ref_number) game.resource.texture.wand_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_06.ref_number) game.resource.texture.wand_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_07.ref_number) game.resource.texture.wand_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_08.ref_number) game.resource.texture.wand_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_09.ref_number) game.resource.texture.wand_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_10.ref_number) game.resource.texture.wand_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_11.ref_number) game.resource.texture.wand_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_12.ref_number) game.resource.texture.wand_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_13.ref_number) game.resource.texture.wand_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_14.ref_number) game.resource.texture.wand_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_15.ref_number) game.resource.texture.wand_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_16.ref_number) game.resource.texture.wand_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_17.ref_number) game.resource.texture.wand_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_18.ref_number) game.resource.texture.wand_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_19.ref_number) game.resource.texture.wand_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.wand_20.ref_number) game.resource.texture.wand_20.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.potion_01.ref_number) game.resource.texture.potion_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_02.ref_number) game.resource.texture.potion_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_03.ref_number) game.resource.texture.potion_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_04.ref_number) game.resource.texture.potion_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_05.ref_number) game.resource.texture.potion_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_06.ref_number) game.resource.texture.potion_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_07.ref_number) game.resource.texture.potion_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_08.ref_number) game.resource.texture.potion_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_09.ref_number) game.resource.texture.potion_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_10.ref_number) game.resource.texture.potion_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_11.ref_number) game.resource.texture.potion_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_12.ref_number) game.resource.texture.potion_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_13.ref_number) game.resource.texture.potion_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_14.ref_number) game.resource.texture.potion_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_15.ref_number) game.resource.texture.potion_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_16.ref_number) game.resource.texture.potion_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_17.ref_number) game.resource.texture.potion_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_18.ref_number) game.resource.texture.potion_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_19.ref_number) game.resource.texture.potion_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_20.ref_number) game.resource.texture.potion_20.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.potion_21.ref_number) game.resource.texture.potion_21.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.amulet_00.ref_number) game.resource.texture.amulet_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_01.ref_number) game.resource.texture.amulet_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_02.ref_number) game.resource.texture.amulet_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_03.ref_number) game.resource.texture.amulet_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_04.ref_number) game.resource.texture.amulet_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_05.ref_number) game.resource.texture.amulet_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_06.ref_number) game.resource.texture.amulet_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_07.ref_number) game.resource.texture.amulet_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_08.ref_number) game.resource.texture.amulet_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_09.ref_number) game.resource.texture.amulet_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_10.ref_number) game.resource.texture.amulet_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_11.ref_number) game.resource.texture.amulet_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_12.ref_number) game.resource.texture.amulet_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.amulet_13.ref_number) game.resource.texture.amulet_13.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.belt_00.ref_number) game.resource.texture.belt_00.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.helm_00.ref_number) game.resource.texture.helm_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.helm_01.ref_number) game.resource.texture.helm_01.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.portrait_00.ref_number) game.resource.texture.portrait_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_01.ref_number) game.resource.texture.portrait_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_02.ref_number) game.resource.texture.portrait_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_03.ref_number) game.resource.texture.portrait_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_04.ref_number) game.resource.texture.portrait_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_05.ref_number) game.resource.texture.portrait_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_06.ref_number) game.resource.texture.portrait_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_07.ref_number) game.resource.texture.portrait_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_08.ref_number) game.resource.texture.portrait_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_09.ref_number) game.resource.texture.portrait_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_10.ref_number) game.resource.texture.portrait_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_11.ref_number) game.resource.texture.portrait_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.portrait_12.ref_number) game.resource.texture.portrait_12.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.heightmap_000.ref_number) game.resource.texture.heightmap_000.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.resource.texture.generic_grass.ref_number)       game.resource.texture.generic_grass.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.generic_lava.ref_number)        game.resource.texture.generic_lava.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.generic_leaves_00.ref_number)   game.resource.texture.generic_leaves_00.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.generic_leaves_00.ref_number)   game.resource.texture.generic_leaves_01.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.generic_sand_shrubs.ref_number) game.resource.texture.generic_sand_shrubs.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.generic_water.ref_number)       game.resource.texture.generic_water.draw       (r,x,y,z,w,h,angle,frame);


    // - - - test / delete - - -
    if (texture_number == game.resource.texture.test_background.ref_number)       game.resource.texture.test_background.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.resource.texture.test_ball.ref_number)             game.resource.texture.test_ball.draw       (r,x,y,z,w,h,angle,frame);

};

void texture_resource_class::bind(int texture_number)
{
    if (texture_number == game.resource.texture.default_texture.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.default_texture.frame[0].data);

    if (texture_number == game.resource.texture.background_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.background_00.frame[0].data);
    if (texture_number == game.resource.texture.background_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.background_01.frame[0].data);
    if (texture_number == game.resource.texture.background_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.background_02.frame[0].data);
    if (texture_number == game.resource.texture.background_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.background_03.frame[0].data);

    if (texture_number == game.resource.texture.logo.ref_number)                      glBindTexture(GL_TEXTURE_2D, game.resource.texture.logo.frame[0].data)                     ;
    if (texture_number == game.resource.texture.button_normal.ref_number)             glBindTexture(GL_TEXTURE_2D, game.resource.texture.button_normal.frame[0].data)            ;
    if (texture_number == game.resource.texture.button_highlighted.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.button_highlighted.frame[0].data)       ;
    if (texture_number == game.resource.texture.button_disabled.ref_number)           glBindTexture(GL_TEXTURE_2D, game.resource.texture.button_disabled.frame[0].data)          ;
    if (texture_number == game.resource.texture.close_button.ref_number)              glBindTexture(GL_TEXTURE_2D, game.resource.texture.close_button.frame[0].data)             ;
    if (texture_number == game.resource.texture.close_button_highlighted.ref_number)  glBindTexture(GL_TEXTURE_2D, game.resource.texture.close_button_highlighted.frame[0].data) ;
    if (texture_number == game.resource.texture.selection_box.ref_number)             glBindTexture(GL_TEXTURE_2D, game.resource.texture.selection_box.frame[0].data)            ;
    if (texture_number == game.resource.texture.arrow_button_normal.ref_number)       glBindTexture(GL_TEXTURE_2D, game.resource.texture.arrow_button_normal.frame[0].data)      ;
    if (texture_number == game.resource.texture.arrow_button_highlighted.ref_number)  glBindTexture(GL_TEXTURE_2D, game.resource.texture.arrow_button_highlighted.frame[0].data) ;
    if (texture_number == game.resource.texture.arrow_button_disabled.ref_number)     glBindTexture(GL_TEXTURE_2D, game.resource.texture.arrow_button_disabled.frame[0].data)    ;
    if (texture_number == game.resource.texture.slider_button_normal.ref_number)      glBindTexture(GL_TEXTURE_2D, game.resource.texture.slider_button_normal.frame[0].data)     ;
    if (texture_number == game.resource.texture.slider_button_highlighted.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.slider_button_highlighted.frame[0].data);
    if (texture_number == game.resource.texture.red_button.ref_number)                glBindTexture(GL_TEXTURE_2D, game.resource.texture.red_button.frame[0].data)               ;
    if (texture_number == game.resource.texture.red_button_highlighted.ref_number)    glBindTexture(GL_TEXTURE_2D, game.resource.texture.red_button_highlighted.frame[0].data)   ;
    if (texture_number == game.resource.texture.green_button.ref_number)              glBindTexture(GL_TEXTURE_2D, game.resource.texture.green_button.frame[0].data)             ;
    if (texture_number == game.resource.texture.green_button_highlighted.ref_number)  glBindTexture(GL_TEXTURE_2D, game.resource.texture.green_button_highlighted.frame[0].data) ;
    if (texture_number == game.resource.texture.blue_button.ref_number)               glBindTexture(GL_TEXTURE_2D, game.resource.texture.blue_button.frame[0].data)              ;
    if (texture_number == game.resource.texture.blue_button_highlighted.ref_number)   glBindTexture(GL_TEXTURE_2D, game.resource.texture.blue_button_highlighted.frame[0].data)  ;
    if (texture_number == game.resource.texture.resolution_icon.ref_number)           glBindTexture(GL_TEXTURE_2D, game.resource.texture.resolution_icon.frame[0].data)          ;

    if (texture_number == game.resource.texture.cursor.ref_number)                    glBindTexture(GL_TEXTURE_2D, game.resource.texture.cursor.frame[0].data)                   ;
    if (texture_number == game.resource.texture.action_bar.ref_number)                glBindTexture(GL_TEXTURE_2D, game.resource.texture.action_bar.frame[0].data)               ;
    if (texture_number == game.resource.texture.action_bar_front.ref_number)          glBindTexture(GL_TEXTURE_2D, game.resource.texture.action_bar_front.frame[0].data)         ;
    if (texture_number == game.resource.texture.glass_cover_01.ref_number)            glBindTexture(GL_TEXTURE_2D, game.resource.texture.glass_cover_01.frame[0].data)           ;
    if (texture_number == game.resource.texture.glass_cover_02.ref_number)            glBindTexture(GL_TEXTURE_2D, game.resource.texture.glass_cover_02.frame[0].data)           ;
    if (texture_number == game.resource.texture.icon_01.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.icon_01.frame[0].data)                  ;
    if (texture_number == game.resource.texture.icon_02.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.icon_02.frame[0].data)                  ;
    if (texture_number == game.resource.texture.icon_03.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.icon_03.frame[0].data)                  ;
    if (texture_number == game.resource.texture.icon_04.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.icon_04.frame[0].data)                  ;
    if (texture_number == game.resource.texture.icon_05.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.icon_05.frame[0].data)                  ;
    if (texture_number == game.resource.texture.icon_06.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.icon_06.frame[0].data)                  ;
    if (texture_number == game.resource.texture.icon_melee.ref_number)                glBindTexture(GL_TEXTURE_2D, game.resource.texture.icon_melee.frame[0].data)               ;

    if (texture_number == game.resource.texture.health_bar.ref_number)                glBindTexture(GL_TEXTURE_2D, game.resource.texture.health_bar.frame[0].data)               ;
    if (texture_number == game.resource.texture.mana_bar.ref_number)                  glBindTexture(GL_TEXTURE_2D, game.resource.texture.mana_bar.frame[0].data)                 ;
    if (texture_number == game.resource.texture.experience_bar.ref_number)            glBindTexture(GL_TEXTURE_2D, game.resource.texture.experience_bar.frame[0].data)           ;
    if (texture_number == game.resource.texture.profile_background.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.profile_background.frame[0].data)       ;
    if (texture_number == game.resource.texture.profile_main.ref_number)              glBindTexture(GL_TEXTURE_2D, game.resource.texture.profile_main.frame[0].data)             ;
    if (texture_number == game.resource.texture.profile_main_background.ref_number)   glBindTexture(GL_TEXTURE_2D, game.resource.texture.profile_main_background.frame[0].data)  ;

    if (texture_number == game.resource.texture.spell_book.ref_number)                  glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_book.frame[0].data)                  ;
    if (texture_number == game.resource.texture.spell_book_spell_cover.ref_number)      glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_book_spell_cover.frame[0].data)      ;
    if (texture_number == game.resource.texture.spell_book_background.ref_number)       glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_book_background.frame[0].data)       ;
    if (texture_number == game.resource.texture.inventory.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.inventory.frame[0].data)                   ;
    if (texture_number == game.resource.texture.inventory_gold.ref_number)              glBindTexture(GL_TEXTURE_2D, game.resource.texture.inventory_gold.frame[0].data)              ;
    if (texture_number == game.resource.texture.inventory_background.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.inventory_background.frame[0].data)        ;
    if (texture_number == game.resource.texture.item_stat_background.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.item_stat_background.frame[0].data)        ;
    if (texture_number == game.resource.texture.character_portrait_frame.ref_number)    glBindTexture(GL_TEXTURE_2D, game.resource.texture.character_portrait_frame.frame[0].data)    ;
    if (texture_number == game.resource.texture.character_background.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.character_background.frame[0].data)        ;
    if (texture_number == game.resource.texture.check_box_true_highlighted.ref_number)  glBindTexture(GL_TEXTURE_2D, game.resource.texture.check_box_true_highlighted.frame[0].data)  ;
    if (texture_number == game.resource.texture.check_box_false_highlighted.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.check_box_false_highlighted.frame[0].data) ;
    if (texture_number == game.resource.texture.check_box_true_normal.ref_number)       glBindTexture(GL_TEXTURE_2D, game.resource.texture.check_box_true_normal.frame[0].data)       ;
    if (texture_number == game.resource.texture.check_box_false_normal.ref_number)      glBindTexture(GL_TEXTURE_2D, game.resource.texture.check_box_false_normal.frame[0].data)      ;
    if (texture_number == game.resource.texture.quest_log_background.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.quest_log_background.frame[0].data)        ;
    if (texture_number == game.resource.texture.equipment_background.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.equipment_background.frame[0].data)        ;
    if (texture_number == game.resource.texture.equipment_slot_32x32.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.equipment_slot_32x32.frame[0].data)        ;
    if (texture_number == game.resource.texture.equipment_slot_64x32.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.equipment_slot_64x32.frame[0].data)        ;
    if (texture_number == game.resource.texture.equipment_slot_64x64.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.equipment_slot_64x64.frame[0].data)        ;
    if (texture_number == game.resource.texture.equipment_slot_64x96.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.equipment_slot_64x96.frame[0].data)        ;

    if (texture_number == game.resource.texture.enemy_health_bar_000.ref_number)            glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_000.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_001.ref_number)            glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_001.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_background_000.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_background_000.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_background_001.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_background_001.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_000.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_foreground_000.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_001.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_foreground_001.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_002.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_foreground_002.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_003.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_foreground_003.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_004.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_foreground_004.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_health_bar_foreground_005.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_health_bar_foreground_005.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_mana_bar_000.ref_number)              glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_mana_bar_000.frame[0].data)        ;
    if (texture_number == game.resource.texture.enemy_mana_bar_001.ref_number)              glBindTexture(GL_TEXTURE_2D, game.resource.texture.enemy_mana_bar_001.frame[0].data)        ;

    if (texture_number == game.resource.texture.particle_000.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_000.frame[0].data);
    if (texture_number == game.resource.texture.particle_001.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_001.frame[0].data);
    if (texture_number == game.resource.texture.particle_002.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_002.frame[0].data);
    if (texture_number == game.resource.texture.particle_003.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_003.frame[0].data);
    if (texture_number == game.resource.texture.particle_004.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_004.frame[0].data);
    if (texture_number == game.resource.texture.particle_005.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_005.frame[0].data);
    if (texture_number == game.resource.texture.particle_006.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_006.frame[0].data);
    if (texture_number == game.resource.texture.particle_007.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_007.frame[0].data);
    if (texture_number == game.resource.texture.particle_008.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_008.frame[0].data);
    if (texture_number == game.resource.texture.particle_009.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_009.frame[0].data);
    if (texture_number == game.resource.texture.particle_010.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_010.frame[0].data);
    if (texture_number == game.resource.texture.particle_011.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_011.frame[0].data);
    if (texture_number == game.resource.texture.particle_012.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_012.frame[0].data);
    if (texture_number == game.resource.texture.particle_013.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_013.frame[0].data);
    if (texture_number == game.resource.texture.particle_014.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_014.frame[0].data);
    if (texture_number == game.resource.texture.particle_015.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.particle_015.frame[0].data);

    if (texture_number == game.resource.texture.spell_01_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_01_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_01_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_01_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_01_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_01_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_02_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_02_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_02_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_02_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_02_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_02_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_03_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_03_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_03_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_03_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_03_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_03_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_04_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_04_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_04_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_04_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_04_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_04_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_05_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_05_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_05_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_05_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_05_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_05_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_06_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_06_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_06_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_06_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_06_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_06_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_07_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_07_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_07_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_07_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_07_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_07_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_08_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_08_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_08_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_08_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_08_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_08_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_09_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_09_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_09_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_09_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_09_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_09_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_10_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_10_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_10_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_10_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_10_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_10_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_11_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_11_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_11_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_11_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_11_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_11_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_12_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_12_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_12_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_12_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_12_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_12_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_13_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_13_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_13_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_13_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_13_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_13_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_14_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_14_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_14_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_14_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_14_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_14_level_03.frame[0].data);
    if (texture_number == game.resource.texture.spell_15_level_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_15_level_01.frame[0].data);
    if (texture_number == game.resource.texture.spell_15_level_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_15_level_02.frame[0].data);
    if (texture_number == game.resource.texture.spell_15_level_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.spell_15_level_03.frame[0].data);
/*
    if (texture_number == game.resource.texture.grass_and_water_tileset.ref_number)         glBindTexture(GL_TEXTURE_2D, game.resource.texture.grass_and_water_tileset.frame[0].data)        ;
    if (texture_number == game.resource.texture.bridge_tileset.ref_number)                  glBindTexture(GL_TEXTURE_2D, game.resource.texture.bridge_tileset.frame[0].data)                 ;
    if (texture_number == game.resource.texture.grassland_tileset.ref_number)               glBindTexture(GL_TEXTURE_2D, game.resource.texture.grassland_tileset.frame[0].data)              ;
    if (texture_number == game.resource.texture.grassland_water_tileset.ref_number)         glBindTexture(GL_TEXTURE_2D, game.resource.texture.grassland_water_tileset.frame[0].data)        ;
    if (texture_number == game.resource.texture.grassland_trees_tileset.ref_number)         glBindTexture(GL_TEXTURE_2D, game.resource.texture.grassland_trees_tileset.frame[0].data)        ;
    if (texture_number == game.resource.texture.grassland_structures_tileset.ref_number)    glBindTexture(GL_TEXTURE_2D, game.resource.texture.grassland_structures_tileset.frame[0].data)   ;
    if (texture_number == game.resource.texture.broken_tower_tileset.ref_number)            glBindTexture(GL_TEXTURE_2D, game.resource.texture.broken_tower_tileset.frame[0].data)           ;
    if (texture_number == game.resource.texture.fence_tileset.ref_number)                   glBindTexture(GL_TEXTURE_2D, game.resource.texture.fence_tileset.frame[0].data)                  ;
    if (texture_number == game.resource.texture.medieval_building_tileset.ref_number)       glBindTexture(GL_TEXTURE_2D, game.resource.texture.medieval_building_tileset.frame[0].data)      ;
    if (texture_number == game.resource.texture.cave_floor_tileset.ref_number)              glBindTexture(GL_TEXTURE_2D, game.resource.texture.cave_floor_tileset.frame[0].data)             ;
    if (texture_number == game.resource.texture.cave_wall_tileset.ref_number)               glBindTexture(GL_TEXTURE_2D, game.resource.texture.cave_wall_tileset.frame[0].data)              ;
    if (texture_number == game.resource.texture.cave_object_tileset.ref_number)             glBindTexture(GL_TEXTURE_2D, game.resource.texture.cave_object_tileset.frame[0].data)            ;
    if (texture_number == game.resource.texture.dungeon_tileset.ref_number)                 glBindTexture(GL_TEXTURE_2D, game.resource.texture.dungeon_tileset.frame[0].data)                ;
    if (texture_number == game.resource.texture.gold_tileset.ref_number)                    glBindTexture(GL_TEXTURE_2D, game.resource.texture.gold_tileset.frame[0].data)                   ;
    if (texture_number == game.resource.texture.test_tileset.ref_number)                    glBindTexture(GL_TEXTURE_2D, game.resource.texture.test_tileset.frame[0].data)                   ;
*/
    if (texture_number == game.resource.texture.book_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_00.frame[0].data);
    if (texture_number == game.resource.texture.book_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_01.frame[0].data);
    if (texture_number == game.resource.texture.book_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_02.frame[0].data);
    if (texture_number == game.resource.texture.book_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_03.frame[0].data);
    if (texture_number == game.resource.texture.book_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_04.frame[0].data);
    if (texture_number == game.resource.texture.book_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_05.frame[0].data);
    if (texture_number == game.resource.texture.book_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_06.frame[0].data);
    if (texture_number == game.resource.texture.book_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_07.frame[0].data);
    if (texture_number == game.resource.texture.book_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_08.frame[0].data);
    if (texture_number == game.resource.texture.book_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_09.frame[0].data);
    if (texture_number == game.resource.texture.book_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_10.frame[0].data);
    if (texture_number == game.resource.texture.book_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_11.frame[0].data);
    if (texture_number == game.resource.texture.book_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_12.frame[0].data);
    if (texture_number == game.resource.texture.book_13.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_13.frame[0].data);
    if (texture_number == game.resource.texture.book_14.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_14.frame[0].data);
    if (texture_number == game.resource.texture.book_15.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_15.frame[0].data);
    if (texture_number == game.resource.texture.book_16.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_16.frame[0].data);
    if (texture_number == game.resource.texture.book_17.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_17.frame[0].data);
    if (texture_number == game.resource.texture.book_18.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_18.frame[0].data);
    if (texture_number == game.resource.texture.book_19.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.book_19.frame[0].data);

    if (texture_number == game.resource.texture.armour_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_00.frame[0].data);
    if (texture_number == game.resource.texture.armour_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_01.frame[0].data);
    if (texture_number == game.resource.texture.armour_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_02.frame[0].data);
    if (texture_number == game.resource.texture.armour_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_03.frame[0].data);
    if (texture_number == game.resource.texture.armour_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_04.frame[0].data);
    if (texture_number == game.resource.texture.armour_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_05.frame[0].data);
    if (texture_number == game.resource.texture.armour_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_06.frame[0].data);
    if (texture_number == game.resource.texture.armour_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_07.frame[0].data);
    if (texture_number == game.resource.texture.armour_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.armour_08.frame[0].data);

    if (texture_number == game.resource.texture.boots_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_00.frame[0].data);
    if (texture_number == game.resource.texture.boots_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_01.frame[0].data);
    if (texture_number == game.resource.texture.boots_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_02.frame[0].data);
    if (texture_number == game.resource.texture.boots_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_03.frame[0].data);
    if (texture_number == game.resource.texture.boots_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_04.frame[0].data);
    if (texture_number == game.resource.texture.boots_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_05.frame[0].data);
    if (texture_number == game.resource.texture.boots_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_06.frame[0].data);
    if (texture_number == game.resource.texture.boots_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_07.frame[0].data);
    if (texture_number == game.resource.texture.boots_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_08.frame[0].data);
    if (texture_number == game.resource.texture.boots_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_09.frame[0].data);
    if (texture_number == game.resource.texture.boots_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_10.frame[0].data);
    if (texture_number == game.resource.texture.boots_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.boots_11.frame[0].data);

    if (texture_number == game.resource.texture.bow_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.bow_00.frame[0].data);
    if (texture_number == game.resource.texture.bow_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.bow_01.frame[0].data);
    if (texture_number == game.resource.texture.bow_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.bow_02.frame[0].data);

    if (texture_number == game.resource.texture.dagger_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_00.frame[0].data);
    if (texture_number == game.resource.texture.dagger_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_01.frame[0].data);
    if (texture_number == game.resource.texture.dagger_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_02.frame[0].data);
    if (texture_number == game.resource.texture.dagger_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_03.frame[0].data);
    if (texture_number == game.resource.texture.dagger_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_04.frame[0].data);
    if (texture_number == game.resource.texture.dagger_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_05.frame[0].data);
    if (texture_number == game.resource.texture.dagger_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_06.frame[0].data);
    if (texture_number == game.resource.texture.dagger_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_07.frame[0].data);
    if (texture_number == game.resource.texture.dagger_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_08.frame[0].data);
    if (texture_number == game.resource.texture.dagger_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_09.frame[0].data);
    if (texture_number == game.resource.texture.dagger_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_10.frame[0].data);
    if (texture_number == game.resource.texture.dagger_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_11.frame[0].data);
    if (texture_number == game.resource.texture.dagger_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_12.frame[0].data);
    if (texture_number == game.resource.texture.dagger_13.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_13.frame[0].data);
    if (texture_number == game.resource.texture.dagger_14.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_14.frame[0].data);
    if (texture_number == game.resource.texture.dagger_15.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_15.frame[0].data);
    if (texture_number == game.resource.texture.dagger_16.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_16.frame[0].data);
    if (texture_number == game.resource.texture.dagger_17.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_17.frame[0].data);
    if (texture_number == game.resource.texture.dagger_18.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_18.frame[0].data);
    if (texture_number == game.resource.texture.dagger_19.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_19.frame[0].data);
    if (texture_number == game.resource.texture.dagger_20.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_20.frame[0].data);
    if (texture_number == game.resource.texture.dagger_21.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_21.frame[0].data);
    if (texture_number == game.resource.texture.dagger_22.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_22.frame[0].data);
    if (texture_number == game.resource.texture.dagger_23.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_23.frame[0].data);
    if (texture_number == game.resource.texture.dagger_24.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_24.frame[0].data);
    if (texture_number == game.resource.texture.dagger_25.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_25.frame[0].data);
    if (texture_number == game.resource.texture.dagger_26.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_26.frame[0].data);
    if (texture_number == game.resource.texture.dagger_27.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.dagger_27.frame[0].data);

    if (texture_number == game.resource.texture.ring_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_00.frame[0].data);
    if (texture_number == game.resource.texture.ring_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_01.frame[0].data);
    if (texture_number == game.resource.texture.ring_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_02.frame[0].data);
    if (texture_number == game.resource.texture.ring_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_03.frame[0].data);
    if (texture_number == game.resource.texture.ring_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_04.frame[0].data);
    if (texture_number == game.resource.texture.ring_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_05.frame[0].data);
    if (texture_number == game.resource.texture.ring_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_06.frame[0].data);
    if (texture_number == game.resource.texture.ring_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_07.frame[0].data);
    if (texture_number == game.resource.texture.ring_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_08.frame[0].data);
    if (texture_number == game.resource.texture.ring_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_09.frame[0].data);
    if (texture_number == game.resource.texture.ring_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_10.frame[0].data);
    if (texture_number == game.resource.texture.ring_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_11.frame[0].data);
    if (texture_number == game.resource.texture.ring_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_12.frame[0].data);
    if (texture_number == game.resource.texture.ring_13.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_13.frame[0].data);
    if (texture_number == game.resource.texture.ring_14.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_14.frame[0].data);
    if (texture_number == game.resource.texture.ring_15.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_15.frame[0].data);
    if (texture_number == game.resource.texture.ring_16.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_16.frame[0].data);
    if (texture_number == game.resource.texture.ring_17.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_17.frame[0].data);
    if (texture_number == game.resource.texture.ring_18.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.ring_18.frame[0].data);

    if (texture_number == game.resource.texture.shield_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.shield_00.frame[0].data);
    if (texture_number == game.resource.texture.shield_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.shield_01.frame[0].data);
    if (texture_number == game.resource.texture.shield_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.shield_02.frame[0].data);
    if (texture_number == game.resource.texture.shield_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.shield_03.frame[0].data);
    if (texture_number == game.resource.texture.shield_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.shield_04.frame[0].data);
    if (texture_number == game.resource.texture.shield_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.shield_05.frame[0].data);
    if (texture_number == game.resource.texture.shield_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.shield_06.frame[0].data);

    if (texture_number == game.resource.texture.sling_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sling_00.frame[0].data);
    if (texture_number == game.resource.texture.sling_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sling_01.frame[0].data);
    if (texture_number == game.resource.texture.sling_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sling_02.frame[0].data);
    if (texture_number == game.resource.texture.sling_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sling_03.frame[0].data);

    if (texture_number == game.resource.texture.sword_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_00.frame[0].data);
    if (texture_number == game.resource.texture.sword_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_01.frame[0].data);
    if (texture_number == game.resource.texture.sword_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_02.frame[0].data);
    if (texture_number == game.resource.texture.sword_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_03.frame[0].data);
    if (texture_number == game.resource.texture.sword_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_04.frame[0].data);
    if (texture_number == game.resource.texture.sword_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_05.frame[0].data);
    if (texture_number == game.resource.texture.sword_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_06.frame[0].data);
    if (texture_number == game.resource.texture.sword_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_07.frame[0].data);
    if (texture_number == game.resource.texture.sword_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_08.frame[0].data);
    if (texture_number == game.resource.texture.sword_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_09.frame[0].data);
    if (texture_number == game.resource.texture.sword_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_10.frame[0].data);
    if (texture_number == game.resource.texture.sword_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_11.frame[0].data);
    if (texture_number == game.resource.texture.sword_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_12.frame[0].data);
    if (texture_number == game.resource.texture.sword_13.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_13.frame[0].data);
    if (texture_number == game.resource.texture.sword_14.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_14.frame[0].data);
    if (texture_number == game.resource.texture.sword_15.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_15.frame[0].data);
    if (texture_number == game.resource.texture.sword_16.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_16.frame[0].data);
    if (texture_number == game.resource.texture.sword_17.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_17.frame[0].data);
    if (texture_number == game.resource.texture.sword_18.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_18.frame[0].data);
    if (texture_number == game.resource.texture.sword_19.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_19.frame[0].data);
    if (texture_number == game.resource.texture.sword_20.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_20.frame[0].data);
    if (texture_number == game.resource.texture.sword_21.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_21.frame[0].data);
    if (texture_number == game.resource.texture.sword_22.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_22.frame[0].data);
    if (texture_number == game.resource.texture.sword_23.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_23.frame[0].data);
    if (texture_number == game.resource.texture.sword_24.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_24.frame[0].data);
    if (texture_number == game.resource.texture.sword_25.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_25.frame[0].data);
    if (texture_number == game.resource.texture.sword_26.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_26.frame[0].data);
    if (texture_number == game.resource.texture.sword_27.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.sword_27.frame[0].data);

    if (texture_number == game.resource.texture.wand_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_00.frame[0].data);
    if (texture_number == game.resource.texture.wand_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_01.frame[0].data);
    if (texture_number == game.resource.texture.wand_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_02.frame[0].data);
    if (texture_number == game.resource.texture.wand_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_03.frame[0].data);
    if (texture_number == game.resource.texture.wand_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_04.frame[0].data);
    if (texture_number == game.resource.texture.wand_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_05.frame[0].data);
    if (texture_number == game.resource.texture.wand_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_06.frame[0].data);
    if (texture_number == game.resource.texture.wand_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_07.frame[0].data);
    if (texture_number == game.resource.texture.wand_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_08.frame[0].data);
    if (texture_number == game.resource.texture.wand_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_09.frame[0].data);
    if (texture_number == game.resource.texture.wand_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_10.frame[0].data);
    if (texture_number == game.resource.texture.wand_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_11.frame[0].data);
    if (texture_number == game.resource.texture.wand_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_12.frame[0].data);
    if (texture_number == game.resource.texture.wand_13.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_13.frame[0].data);
    if (texture_number == game.resource.texture.wand_14.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_14.frame[0].data);
    if (texture_number == game.resource.texture.wand_15.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_15.frame[0].data);
    if (texture_number == game.resource.texture.wand_16.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_16.frame[0].data);
    if (texture_number == game.resource.texture.wand_17.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_17.frame[0].data);
    if (texture_number == game.resource.texture.wand_18.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_18.frame[0].data);
    if (texture_number == game.resource.texture.wand_19.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_19.frame[0].data);
    if (texture_number == game.resource.texture.wand_20.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.wand_20.frame[0].data);

    if (texture_number == game.resource.texture.potion_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_01.frame[0].data);
    if (texture_number == game.resource.texture.potion_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_02.frame[0].data);
    if (texture_number == game.resource.texture.potion_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_03.frame[0].data);
    if (texture_number == game.resource.texture.potion_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_04.frame[0].data);
    if (texture_number == game.resource.texture.potion_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_05.frame[0].data);
    if (texture_number == game.resource.texture.potion_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_06.frame[0].data);
    if (texture_number == game.resource.texture.potion_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_07.frame[0].data);
    if (texture_number == game.resource.texture.potion_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_08.frame[0].data);
    if (texture_number == game.resource.texture.potion_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_09.frame[0].data);
    if (texture_number == game.resource.texture.potion_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_10.frame[0].data);
    if (texture_number == game.resource.texture.potion_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_11.frame[0].data);
    if (texture_number == game.resource.texture.potion_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_12.frame[0].data);
    if (texture_number == game.resource.texture.potion_13.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_13.frame[0].data);
    if (texture_number == game.resource.texture.potion_14.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_14.frame[0].data);
    if (texture_number == game.resource.texture.potion_15.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_15.frame[0].data);
    if (texture_number == game.resource.texture.potion_16.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_16.frame[0].data);
    if (texture_number == game.resource.texture.potion_17.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_17.frame[0].data);
    if (texture_number == game.resource.texture.potion_18.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_18.frame[0].data);
    if (texture_number == game.resource.texture.potion_19.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_19.frame[0].data);
    if (texture_number == game.resource.texture.potion_20.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_20.frame[0].data);
    if (texture_number == game.resource.texture.potion_21.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.potion_21.frame[0].data);

    if (texture_number == game.resource.texture.amulet_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_00.frame[0].data);
    if (texture_number == game.resource.texture.amulet_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_01.frame[0].data);
    if (texture_number == game.resource.texture.amulet_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_02.frame[0].data);
    if (texture_number == game.resource.texture.amulet_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_03.frame[0].data);
    if (texture_number == game.resource.texture.amulet_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_04.frame[0].data);
    if (texture_number == game.resource.texture.amulet_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_05.frame[0].data);
    if (texture_number == game.resource.texture.amulet_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_06.frame[0].data);
    if (texture_number == game.resource.texture.amulet_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_07.frame[0].data);
    if (texture_number == game.resource.texture.amulet_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_08.frame[0].data);
    if (texture_number == game.resource.texture.amulet_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_09.frame[0].data);
    if (texture_number == game.resource.texture.amulet_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_10.frame[0].data);
    if (texture_number == game.resource.texture.amulet_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_11.frame[0].data);
    if (texture_number == game.resource.texture.amulet_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_12.frame[0].data);
    if (texture_number == game.resource.texture.amulet_13.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.amulet_13.frame[0].data);

    if (texture_number == game.resource.texture.belt_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.belt_00.frame[0].data);

    if (texture_number == game.resource.texture.helm_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.helm_00.frame[0].data);
    if (texture_number == game.resource.texture.helm_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.helm_01.frame[0].data);

    if (texture_number == game.resource.texture.portrait_00.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_00.frame[0].data);
    if (texture_number == game.resource.texture.portrait_01.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_01.frame[0].data);
    if (texture_number == game.resource.texture.portrait_02.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_02.frame[0].data);
    if (texture_number == game.resource.texture.portrait_03.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_03.frame[0].data);
    if (texture_number == game.resource.texture.portrait_04.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_04.frame[0].data);
    if (texture_number == game.resource.texture.portrait_05.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_05.frame[0].data);
    if (texture_number == game.resource.texture.portrait_06.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_06.frame[0].data);
    if (texture_number == game.resource.texture.portrait_07.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_07.frame[0].data);
    if (texture_number == game.resource.texture.portrait_08.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_08.frame[0].data);
    if (texture_number == game.resource.texture.portrait_09.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_09.frame[0].data);
    if (texture_number == game.resource.texture.portrait_10.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_10.frame[0].data);
    if (texture_number == game.resource.texture.portrait_11.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_11.frame[0].data);
    if (texture_number == game.resource.texture.portrait_12.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.portrait_12.frame[0].data);

    if (texture_number == game.resource.texture.heightmap_000.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.heightmap_000.frame[0].data);

    if (texture_number == game.resource.texture.generic_grass.ref_number)       glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_grass.frame[0].data);
    if (texture_number == game.resource.texture.generic_lava.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_lava.frame[0].data);
    if (texture_number == game.resource.texture.generic_lava_layer.ref_number)  glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_lava_layer.frame[0].data);
    if (texture_number == game.resource.texture.generic_leaves_00.ref_number)   glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_leaves_00.frame[0].data);
    if (texture_number == game.resource.texture.generic_leaves_01.ref_number)   glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_leaves_01.frame[0].data);
    if (texture_number == game.resource.texture.generic_sand.ref_number)        glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_sand.frame[0].data);
    if (texture_number == game.resource.texture.generic_sand_shrubs.ref_number) glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_sand_shrubs.frame[0].data);
    if (texture_number == game.resource.texture.generic_water.ref_number)       glBindTexture(GL_TEXTURE_2D, game.resource.texture.generic_water.frame[0].data);

    // - - - test / delete - - -
    if (texture_number == game.resource.texture.test_background.ref_number)       glBindTexture(GL_TEXTURE_2D, game.resource.texture.test_background.frame[0].data);
    if (texture_number == game.resource.texture.test_ball.ref_number)             glBindTexture(GL_TEXTURE_2D, game.resource.texture.test_ball.frame[0].data);

};

//---------------------------------------- resource_class ----------------------------------------------------------------

resource_class::resource_class(void)
{
    resource_class::font.number_loaded     = 0;
    //resource_class::map_2D.number_loaded   = 0;
    resource_class::map_3D.number_loaded   = 0;
    resource_class::model_3D.number_loaded = 0;
    resource_class::music.number_loaded    = 0;
    resource_class::sound.number_loaded    = 0;
    resource_class::texture.number_loaded  = 0;
};

resource_class::~resource_class(void)
{

};

void resource_class::loading_screen_display(std::string file_name)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapBuffers();
    texture_class loading_screen;
    loading_screen.load_image(file_name,0);
    loading_screen.draw(false,0.0f,0.0f,0.9f,2.0f,2.0f);
    SDL_GL_SwapBuffers();
};

void resource_class::write_log_file_count(void)
{
//--- log loaded file count ---
    game.core.log.file_write("font     files loaded -> ",resource_class::font.number_loaded);
    //game.core.log.file_write("2D map   files loaded -> ",resource_class::map_2D.number_loaded);
    game.core.log.file_write("3D map   files loaded -> ",resource_class::map_3D.number_loaded);
    game.core.log.file_write("3D model files loaded -> ",resource_class::model_3D.number_loaded);
    game.core.log.file_write("music    files loaded -> ",resource_class::music.number_loaded);
    game.core.log.file_write("sound    files loaded -> ",resource_class::sound.number_loaded);
    game.core.log.file_write("texture  files loaded -> ",resource_class::texture.number_loaded);
};

void resource_class::load_default(void)
{
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.default_texture.load_image("data/textures/default.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
}
void resource_class::load_UI(void)
{
    game.core.log.file_write("Loading resources -> UI");
//--- font ---
    game.resource.font.font_1.Set_File("data/fonts/font_001.ttf");resource_class::font.number_loaded++;
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
    game.resource.music.menu_00.load("data/music/menu_00.s3m",resource_class::music.number_loaded);resource_class::music.number_loaded++;
//--- sound ---
    game.resource.sound.menu_move_00.load    ("data/sound/menu/menu_move_00.wav",resource_class::sound.number_loaded)    ;resource_class::sound.number_loaded++;
    game.resource.sound.menu_select_00.load  ("data/sound/menu/menu_select_00.wav",resource_class::sound.number_loaded)  ;resource_class::sound.number_loaded++;
//--- texture ---

    game.resource.texture.background_00.load_image("data/textures/UI/menu/background_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.background_01.load_image("data/textures/UI/menu/background_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.background_02.load_image("data/textures/UI/menu/background_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.background_03.load_image("data/textures/UI/menu/background_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.logo.load_image                     ("data/textures/UI/menu/logo.png"                     ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.button_normal.load_image            ("data/textures/UI/menu/button_normal.png"            ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.button_highlighted.load_image       ("data/textures/UI/menu/button_highlighted.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.button_disabled.load_image          ("data/textures/UI/menu/button_disabled.png"          ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.close_button.load_image             ("data/textures/UI/menu/close_button.png"             ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.close_button_highlighted.load_image ("data/textures/UI/menu/close_button_highlighted.png" ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.selection_box.load_image            ("data/textures/UI/menu/selection_box.png"            ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.arrow_button_normal.load_image      ("data/textures/UI/menu/arrow_normal.png"             ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.arrow_button_highlighted.load_image ("data/textures/UI/menu/arrow_highlighted.png"        ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.arrow_button_disabled.load_image    ("data/textures/UI/menu/arrow_disabled.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.slider_button_normal.load_image     ("data/textures/UI/menu/slider_normal.png"            ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.slider_button_highlighted.load_image("data/textures/UI/menu/slider_highlighted.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.red_button.load_image               ("data/textures/UI/menu/red_button.png"               ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.red_button_highlighted.load_image   ("data/textures/UI/menu/red_button_highlighted.png"   ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.green_button.load_image             ("data/textures/UI/menu/green_button.png"             ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.green_button_highlighted.load_image ("data/textures/UI/menu/green_button_highlighted.png" ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.blue_button.load_image              ("data/textures/UI/menu/blue_button.png"              ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.blue_button_highlighted.load_image  ("data/textures/UI/menu/blue_button_highlighted.png"  ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.resolution_icon.load_image          ("data/textures/UI/menu/resolution_icon.png"          ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.cursor.load_image              ("data/textures/UI/cursor.png"                          ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.action_bar.load_image          ("data/textures/UI/action_bar/action_bar.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.action_bar_front.load_image    ("data/textures/UI/action_bar/action_bar_front.png"     ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.glass_cover_01.load_image      ("data/textures/UI/action_bar/glass_cover_01.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.glass_cover_02.load_image      ("data/textures/UI/action_bar/glass_cover_02.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.icon_01.load_image             ("data/textures/UI/action_bar/icon_01.png"              ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.icon_02.load_image             ("data/textures/UI/action_bar/icon_02.png"              ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.icon_03.load_image             ("data/textures/UI/action_bar/icon_03.png"              ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.icon_04.load_image             ("data/textures/UI/action_bar/icon_04.png"              ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.icon_05.load_image             ("data/textures/UI/action_bar/icon_05.png"              ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.icon_06.load_image             ("data/textures/UI/action_bar/icon_06.png"              ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.icon_melee.load_image          ("data/textures/UI/action_bar/icon_melee.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.health_bar.load_image              ("data/textures/UI/portrait/health_bar.png"               ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.mana_bar.load_image                ("data/textures/UI/portrait/mana_bar.png"                 ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.experience_bar.load_image          ("data/textures/UI/action_bar/experience_bar.png"         ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.profile_background.load_image      ("data/textures/UI/portrait/profile_background.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.profile_main.load_image            ("data/textures/UI/portrait/profile_main.png"             ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.profile_main_background.load_image ("data/textures/UI/portrait/profile_main_background.png"  ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.spell_book.load_image                  ("data/textures/UI/spell_book/spell_book.png"                    ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_book_spell_cover.load_image      ("data/textures/UI/spell_book/spell_book_spell_cover.png"        ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_book_background.load_image       ("data/textures/UI/spell_book/spell_book_background.png"         ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.inventory.load_image                   ("data/textures/UI/inventory/inventory.png"                      ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.inventory_gold.load_image              ("data/textures/UI/inventory/inventory_gold.png"                 ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.inventory_background.load_image        ("data/textures/UI/inventory/inventory_background.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.item_stat_background.load_image        ("data/textures/UI/inventory/item_stat_background.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.character_portrait_frame.load_image    ("data/textures/UI/character/character_portrait_frame.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.character_background.load_image        ("data/textures/UI/character/character_background.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.check_box_true_highlighted.load_image  ("data/textures/UI/character/check_box_true_highlighted.png"     ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.check_box_false_highlighted.load_image ("data/textures/UI/character/check_box_false_highlighted.png"    ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.check_box_true_normal.load_image       ("data/textures/UI/character/check_box_true_normal.png"          ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.check_box_false_normal.load_image      ("data/textures/UI/character/check_box_false_normal.png"         ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.quest_log_background.load_image        ("data/textures/UI/quest_log/quest_log_background.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.equipment_background.load_image        ("data/textures/UI/equipment/equipment_background.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.equipment_slot_32x32.load_image        ("data/textures/UI/equipment/equipment_slot_32x32.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.equipment_slot_64x32.load_image        ("data/textures/UI/equipment/equipment_slot_64x32.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.equipment_slot_64x64.load_image        ("data/textures/UI/equipment/equipment_slot_64x64.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.equipment_slot_64x96.load_image        ("data/textures/UI/equipment/equipment_slot_64x96.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.enemy_health_bar_000.load_image             ("data/textures/UI/enemy_health_bars/enemy_health_bar_000.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_001.load_image             ("data/textures/UI/enemy_health_bars/enemy_health_bar_001.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_background_000.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_background_000.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_background_001.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_background_001.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_foreground_000.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_foreground_000.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_foreground_001.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_foreground_001.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_foreground_002.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_foreground_002.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_foreground_003.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_foreground_003.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_foreground_004.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_foreground_004.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_health_bar_foreground_005.load_image  ("data/textures/UI/enemy_health_bars/enemy_health_bar_foreground_005.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_mana_bar_000.load_image               ("data/textures/UI/enemy_health_bars/enemy_mana_bar_000.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.enemy_mana_bar_001.load_image               ("data/textures/UI/enemy_health_bars/enemy_mana_bar_001.png"           ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};

void resource_class::load_items(void)
{
    game.core.log.file_write("Loading resources -> Items");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
    game.resource.sound.bottle_01.load  ("data/sound/inventory/bottle_01.wav",resource_class::sound.number_loaded);resource_class::sound.number_loaded++;
    game.resource.sound.bubble_01.load  ("data/sound/inventory/bubble_01.wav",resource_class::sound.number_loaded);resource_class::sound.number_loaded++;
    game.resource.sound.bubble_02.load  ("data/sound/inventory/bubble_02.wav",resource_class::sound.number_loaded);resource_class::sound.number_loaded++;
    game.resource.sound.bubble_03.load  ("data/sound/inventory/bubble_03.wav",resource_class::sound.number_loaded);resource_class::sound.number_loaded++;

    game.resource.sound.book_00.load  ("data/sound/inventory/book_00.wav",resource_class::sound.number_loaded);resource_class::sound.number_loaded++;
    game.resource.sound.book_01.load  ("data/sound/inventory/book_01.wav",resource_class::sound.number_loaded);resource_class::sound.number_loaded++;
    game.resource.sound.book_02.load  ("data/sound/inventory/book_02.wav",resource_class::sound.number_loaded);resource_class::sound.number_loaded++;
//--- texture ---
    game.resource.texture.book_00.load_image("data/textures/UI/icons/books/book_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_01.load_image("data/textures/UI/icons/books/book_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_02.load_image("data/textures/UI/icons/books/book_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_03.load_image("data/textures/UI/icons/books/book_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_04.load_image("data/textures/UI/icons/books/book_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_05.load_image("data/textures/UI/icons/books/book_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_06.load_image("data/textures/UI/icons/books/book_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_07.load_image("data/textures/UI/icons/books/book_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_08.load_image("data/textures/UI/icons/books/book_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_09.load_image("data/textures/UI/icons/books/book_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_10.load_image("data/textures/UI/icons/books/book_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_11.load_image("data/textures/UI/icons/books/book_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_12.load_image("data/textures/UI/icons/books/book_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_13.load_image("data/textures/UI/icons/books/book_13.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_14.load_image("data/textures/UI/icons/books/book_14.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_15.load_image("data/textures/UI/icons/books/book_15.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_16.load_image("data/textures/UI/icons/books/book_16.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_17.load_image("data/textures/UI/icons/books/book_17.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_18.load_image("data/textures/UI/icons/books/book_18.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.book_19.load_image("data/textures/UI/icons/books/book_19.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.armour_00.load_image("data/textures/UI/icons/armour/armour_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_01.load_image("data/textures/UI/icons/armour/armour_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_02.load_image("data/textures/UI/icons/armour/armour_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_03.load_image("data/textures/UI/icons/armour/armour_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_04.load_image("data/textures/UI/icons/armour/armour_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_05.load_image("data/textures/UI/icons/armour/armour_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_06.load_image("data/textures/UI/icons/armour/armour_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_07.load_image("data/textures/UI/icons/armour/armour_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.armour_08.load_image("data/textures/UI/icons/armour/armour_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.boots_00.load_image("data/textures/UI/icons/boots/boots_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_01.load_image("data/textures/UI/icons/boots/boots_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_02.load_image("data/textures/UI/icons/boots/boots_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_03.load_image("data/textures/UI/icons/boots/boots_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_04.load_image("data/textures/UI/icons/boots/boots_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_05.load_image("data/textures/UI/icons/boots/boots_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_06.load_image("data/textures/UI/icons/boots/boots_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_07.load_image("data/textures/UI/icons/boots/boots_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_08.load_image("data/textures/UI/icons/boots/boots_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_09.load_image("data/textures/UI/icons/boots/boots_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_10.load_image("data/textures/UI/icons/boots/boots_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.boots_11.load_image("data/textures/UI/icons/boots/boots_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.bow_00.load_image("data/textures/UI/icons/bows/bow_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.bow_01.load_image("data/textures/UI/icons/bows/bow_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.bow_02.load_image("data/textures/UI/icons/bows/bow_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.dagger_00.load_image("data/textures/UI/icons/daggers/dagger_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_01.load_image("data/textures/UI/icons/daggers/dagger_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_02.load_image("data/textures/UI/icons/daggers/dagger_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_03.load_image("data/textures/UI/icons/daggers/dagger_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_04.load_image("data/textures/UI/icons/daggers/dagger_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_05.load_image("data/textures/UI/icons/daggers/dagger_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_06.load_image("data/textures/UI/icons/daggers/dagger_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_07.load_image("data/textures/UI/icons/daggers/dagger_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_08.load_image("data/textures/UI/icons/daggers/dagger_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_09.load_image("data/textures/UI/icons/daggers/dagger_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_10.load_image("data/textures/UI/icons/daggers/dagger_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_11.load_image("data/textures/UI/icons/daggers/dagger_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_12.load_image("data/textures/UI/icons/daggers/dagger_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_13.load_image("data/textures/UI/icons/daggers/dagger_13.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_14.load_image("data/textures/UI/icons/daggers/dagger_14.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_15.load_image("data/textures/UI/icons/daggers/dagger_15.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_16.load_image("data/textures/UI/icons/daggers/dagger_16.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_17.load_image("data/textures/UI/icons/daggers/dagger_17.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_18.load_image("data/textures/UI/icons/daggers/dagger_18.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_19.load_image("data/textures/UI/icons/daggers/dagger_19.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_20.load_image("data/textures/UI/icons/daggers/dagger_20.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_21.load_image("data/textures/UI/icons/daggers/dagger_21.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_22.load_image("data/textures/UI/icons/daggers/dagger_22.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_23.load_image("data/textures/UI/icons/daggers/dagger_23.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_24.load_image("data/textures/UI/icons/daggers/dagger_24.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_25.load_image("data/textures/UI/icons/daggers/dagger_25.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_26.load_image("data/textures/UI/icons/daggers/dagger_26.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.dagger_27.load_image("data/textures/UI/icons/daggers/dagger_27.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.ring_00.load_image("data/textures/UI/icons/rings/ring_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_01.load_image("data/textures/UI/icons/rings/ring_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_02.load_image("data/textures/UI/icons/rings/ring_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_03.load_image("data/textures/UI/icons/rings/ring_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_04.load_image("data/textures/UI/icons/rings/ring_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_05.load_image("data/textures/UI/icons/rings/ring_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_06.load_image("data/textures/UI/icons/rings/ring_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_07.load_image("data/textures/UI/icons/rings/ring_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_08.load_image("data/textures/UI/icons/rings/ring_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_09.load_image("data/textures/UI/icons/rings/ring_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_10.load_image("data/textures/UI/icons/rings/ring_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_11.load_image("data/textures/UI/icons/rings/ring_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_12.load_image("data/textures/UI/icons/rings/ring_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_13.load_image("data/textures/UI/icons/rings/ring_13.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_14.load_image("data/textures/UI/icons/rings/ring_14.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_15.load_image("data/textures/UI/icons/rings/ring_15.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_16.load_image("data/textures/UI/icons/rings/ring_16.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_17.load_image("data/textures/UI/icons/rings/ring_17.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.ring_18.load_image("data/textures/UI/icons/rings/ring_18.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.shield_00.load_image("data/textures/UI/icons/shields/shield_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.shield_01.load_image("data/textures/UI/icons/shields/shield_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.shield_02.load_image("data/textures/UI/icons/shields/shield_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.shield_03.load_image("data/textures/UI/icons/shields/shield_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.shield_04.load_image("data/textures/UI/icons/shields/shield_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.shield_05.load_image("data/textures/UI/icons/shields/shield_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.shield_06.load_image("data/textures/UI/icons/shields/shield_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.sling_00.load_image("data/textures/UI/icons/slings/sling_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sling_01.load_image("data/textures/UI/icons/slings/sling_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sling_02.load_image("data/textures/UI/icons/slings/sling_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sling_03.load_image("data/textures/UI/icons/slings/sling_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.sword_00.load_image("data/textures/UI/icons/swords/sword_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_01.load_image("data/textures/UI/icons/swords/sword_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_02.load_image("data/textures/UI/icons/swords/sword_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_03.load_image("data/textures/UI/icons/swords/sword_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_04.load_image("data/textures/UI/icons/swords/sword_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_05.load_image("data/textures/UI/icons/swords/sword_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_06.load_image("data/textures/UI/icons/swords/sword_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_07.load_image("data/textures/UI/icons/swords/sword_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_08.load_image("data/textures/UI/icons/swords/sword_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_09.load_image("data/textures/UI/icons/swords/sword_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_10.load_image("data/textures/UI/icons/swords/sword_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_11.load_image("data/textures/UI/icons/swords/sword_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_12.load_image("data/textures/UI/icons/swords/sword_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_13.load_image("data/textures/UI/icons/swords/sword_13.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_14.load_image("data/textures/UI/icons/swords/sword_14.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_15.load_image("data/textures/UI/icons/swords/sword_15.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_16.load_image("data/textures/UI/icons/swords/sword_16.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_17.load_image("data/textures/UI/icons/swords/sword_17.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_18.load_image("data/textures/UI/icons/swords/sword_18.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_19.load_image("data/textures/UI/icons/swords/sword_19.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_20.load_image("data/textures/UI/icons/swords/sword_20.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_21.load_image("data/textures/UI/icons/swords/sword_21.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_22.load_image("data/textures/UI/icons/swords/sword_22.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_23.load_image("data/textures/UI/icons/swords/sword_23.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_24.load_image("data/textures/UI/icons/swords/sword_24.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_25.load_image("data/textures/UI/icons/swords/sword_25.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_26.load_image("data/textures/UI/icons/swords/sword_26.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.sword_27.load_image("data/textures/UI/icons/swords/sword_27.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.wand_00.load_image("data/textures/UI/icons/wands/wand_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_01.load_image("data/textures/UI/icons/wands/wand_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_02.load_image("data/textures/UI/icons/wands/wand_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_03.load_image("data/textures/UI/icons/wands/wand_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_04.load_image("data/textures/UI/icons/wands/wand_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_05.load_image("data/textures/UI/icons/wands/wand_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_06.load_image("data/textures/UI/icons/wands/wand_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_07.load_image("data/textures/UI/icons/wands/wand_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_08.load_image("data/textures/UI/icons/wands/wand_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_09.load_image("data/textures/UI/icons/wands/wand_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_10.load_image("data/textures/UI/icons/wands/wand_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_11.load_image("data/textures/UI/icons/wands/wand_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_12.load_image("data/textures/UI/icons/wands/wand_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_13.load_image("data/textures/UI/icons/wands/wand_13.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_14.load_image("data/textures/UI/icons/wands/wand_14.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_15.load_image("data/textures/UI/icons/wands/wand_15.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_16.load_image("data/textures/UI/icons/wands/wand_16.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_17.load_image("data/textures/UI/icons/wands/wand_17.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_18.load_image("data/textures/UI/icons/wands/wand_18.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_19.load_image("data/textures/UI/icons/wands/wand_19.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.wand_20.load_image("data/textures/UI/icons/wands/wand_20.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.potion_01.load_image("data/textures/UI/icons/potions/potion_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_02.load_image("data/textures/UI/icons/potions/potion_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_03.load_image("data/textures/UI/icons/potions/potion_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_04.load_image("data/textures/UI/icons/potions/potion_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_05.load_image("data/textures/UI/icons/potions/potion_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_06.load_image("data/textures/UI/icons/potions/potion_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_07.load_image("data/textures/UI/icons/potions/potion_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_08.load_image("data/textures/UI/icons/potions/potion_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_09.load_image("data/textures/UI/icons/potions/potion_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_10.load_image("data/textures/UI/icons/potions/potion_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_11.load_image("data/textures/UI/icons/potions/potion_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_12.load_image("data/textures/UI/icons/potions/potion_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_13.load_image("data/textures/UI/icons/potions/potion_13.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_14.load_image("data/textures/UI/icons/potions/potion_14.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_15.load_image("data/textures/UI/icons/potions/potion_15.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_16.load_image("data/textures/UI/icons/potions/potion_16.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_17.load_image("data/textures/UI/icons/potions/potion_17.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_18.load_image("data/textures/UI/icons/potions/potion_18.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_19.load_image("data/textures/UI/icons/potions/potion_19.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_20.load_image("data/textures/UI/icons/potions/potion_20.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.potion_21.load_image("data/textures/UI/icons/potions/potion_21.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.amulet_00.load_image("data/textures/UI/icons/amulets/amulet_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_01.load_image("data/textures/UI/icons/amulets/amulet_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_02.load_image("data/textures/UI/icons/amulets/amulet_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_03.load_image("data/textures/UI/icons/amulets/amulet_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_04.load_image("data/textures/UI/icons/amulets/amulet_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_05.load_image("data/textures/UI/icons/amulets/amulet_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_06.load_image("data/textures/UI/icons/amulets/amulet_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_07.load_image("data/textures/UI/icons/amulets/amulet_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_08.load_image("data/textures/UI/icons/amulets/amulet_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_09.load_image("data/textures/UI/icons/amulets/amulet_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_10.load_image("data/textures/UI/icons/amulets/amulet_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_11.load_image("data/textures/UI/icons/amulets/amulet_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_12.load_image("data/textures/UI/icons/amulets/amulet_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.amulet_13.load_image("data/textures/UI/icons/amulets/amulet_13.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.belt_00.load_image("data/textures/UI/icons/belts/belt_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;

    game.resource.texture.helm_00.load_image("data/textures/UI/icons/helms/helm_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.helm_01.load_image("data/textures/UI/icons/helms/helm_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};

void resource_class::load_particles(void)
{
    game.core.log.file_write("Loading resources -> particles");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.particle_000.load_image("data/textures/particles/particle_000.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_001.load_image("data/textures/particles/particle_001.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_002.load_image("data/textures/particles/particle_002.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_003.load_image("data/textures/particles/particle_003.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_004.load_image("data/textures/particles/particle_004.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_005.load_image("data/textures/particles/particle_005.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_006.load_image("data/textures/particles/particle_006.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_007.load_image("data/textures/particles/particle_007.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_008.load_image("data/textures/particles/particle_008.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_009.load_image("data/textures/particles/particle_009.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_010.load_image("data/textures/particles/particle_010.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_011.load_image("data/textures/particles/particle_011.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_012.load_image("data/textures/particles/particle_012.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_013.load_image("data/textures/particles/particle_013.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_014.load_image("data/textures/particles/particle_014.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.particle_015.load_image("data/textures/particles/particle_015.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};

void resource_class::load_portraits(void)
{
    game.core.log.file_write("Loading resources -> portraits");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.portrait_00.load_image("data/textures/UI/portraits/portrait_00.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_01.load_image("data/textures/UI/portraits/portrait_01.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_02.load_image("data/textures/UI/portraits/portrait_02.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_03.load_image("data/textures/UI/portraits/portrait_03.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_04.load_image("data/textures/UI/portraits/portrait_04.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_05.load_image("data/textures/UI/portraits/portrait_05.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_06.load_image("data/textures/UI/portraits/portrait_06.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_07.load_image("data/textures/UI/portraits/portrait_07.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_08.load_image("data/textures/UI/portraits/portrait_08.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_09.load_image("data/textures/UI/portraits/portrait_09.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_10.load_image("data/textures/UI/portraits/portrait_10.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_11.load_image("data/textures/UI/portraits/portrait_11.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.portrait_12.load_image("data/textures/UI/portraits/portrait_12.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};

void resource_class::load_spells(void)
{
    game.core.log.file_write("Loading resources -> spells");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.spell_01_level_01.load_image("data/textures/UI/icons/spells/ice-blue-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_01_level_02.load_image("data/textures/UI/icons/spells/ice-blue-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_01_level_03.load_image("data/textures/UI/icons/spells/ice-blue-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_02_level_01.load_image("data/textures/UI/icons/spells/air-burst-sky-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_02_level_02.load_image("data/textures/UI/icons/spells/air-burst-sky-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_02_level_03.load_image("data/textures/UI/icons/spells/air-burst-sky-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_03_level_01.load_image("data/textures/UI/icons/spells/beam-red-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_03_level_02.load_image("data/textures/UI/icons/spells/beam-red-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_03_level_03.load_image("data/textures/UI/icons/spells/beam-red-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_04_level_01.load_image("data/textures/UI/icons/spells/fire-arrows-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_04_level_02.load_image("data/textures/UI/icons/spells/fire-arrows-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_04_level_03.load_image("data/textures/UI/icons/spells/fire-arrows-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_05_level_01.load_image("data/textures/UI/icons/spells/fireball-red-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_05_level_02.load_image("data/textures/UI/icons/spells/fireball-red-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_05_level_03.load_image("data/textures/UI/icons/spells/fireball-red-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_06_level_01.load_image("data/textures/UI/icons/spells/haste-royal-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_06_level_02.load_image("data/textures/UI/icons/spells/haste-royal-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_06_level_03.load_image("data/textures/UI/icons/spells/haste-royal-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_07_level_01.load_image("data/textures/UI/icons/spells/heal-royal-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_07_level_02.load_image("data/textures/UI/icons/spells/heal-royal-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_07_level_03.load_image("data/textures/UI/icons/spells/heal-royal-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_08_level_01.load_image("data/textures/UI/icons/spells/horror-acid-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_08_level_02.load_image("data/textures/UI/icons/spells/horror-acid-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_08_level_03.load_image("data/textures/UI/icons/spells/horror-acid-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_09_level_01.load_image("data/textures/UI/icons/spells/lightning-blue-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_09_level_02.load_image("data/textures/UI/icons/spells/lightning-blue-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_09_level_03.load_image("data/textures/UI/icons/spells/lightning-blue-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_10_level_01.load_image("data/textures/UI/icons/spells/needles-fire-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_10_level_02.load_image("data/textures/UI/icons/spells/needles-fire-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_10_level_03.load_image("data/textures/UI/icons/spells/needles-fire-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_11_level_01.load_image("data/textures/UI/icons/spells/protect-orange-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_11_level_02.load_image("data/textures/UI/icons/spells/protect-orange-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_11_level_03.load_image("data/textures/UI/icons/spells/protect-orange-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_12_level_01.load_image("data/textures/UI/icons/spells/rock-orange-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_12_level_02.load_image("data/textures/UI/icons/spells/rock-orange-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_12_level_03.load_image("data/textures/UI/icons/spells/rock-orange-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_13_level_01.load_image("data/textures/UI/icons/spells/runes-magenta-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_13_level_02.load_image("data/textures/UI/icons/spells/runes-magenta-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_13_level_03.load_image("data/textures/UI/icons/spells/runes-magenta-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_14_level_01.load_image("data/textures/UI/icons/spells/wind-blue-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_14_level_02.load_image("data/textures/UI/icons/spells/wind-blue-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_14_level_03.load_image("data/textures/UI/icons/spells/wind-blue-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_15_level_01.load_image("data/textures/UI/icons/spells/beam-blue-1.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_15_level_02.load_image("data/textures/UI/icons/spells/beam-blue-2.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.spell_15_level_03.load_image("data/textures/UI/icons/spells/beam-blue-3.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};
/*
void resource_class::load_tilesets(void)
{
    game.core.log.file_write("Loading resources -> Tilesets");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.grass_and_water_tileset.load_spritesheet        ("data/tilesets/grass_and_water.png"     ,resource_class::texture.number_loaded, 64, 64);resource_class::texture.number_loaded++;
    game.resource.texture.bridge_tileset.load_spritesheet                 ("data/tilesets/bridge.png"              ,resource_class::texture.number_loaded, 64,148);resource_class::texture.number_loaded++;
    game.resource.texture.grassland_tileset.load_spritesheet              ("data/tilesets/grassland.png"           ,resource_class::texture.number_loaded, 64,128);resource_class::texture.number_loaded++;
    game.resource.texture.grassland_water_tileset.load_spritesheet        ("data/tilesets/grassland_water.png"     ,resource_class::texture.number_loaded, 64, 64);resource_class::texture.number_loaded++;
    game.resource.texture.grassland_trees_tileset.load_spritesheet        ("data/tilesets/grassland_trees.png"     ,resource_class::texture.number_loaded,128,128);resource_class::texture.number_loaded++;
    game.resource.texture.grassland_structures_tileset.load_spritesheet   ("data/tilesets/grassland_structures.png",resource_class::texture.number_loaded, 64,148);resource_class::texture.number_loaded++;
    game.resource.texture.broken_tower_tileset.load_spritesheet           ("data/tilesets/broken_tower.png"        ,resource_class::texture.number_loaded, 64, 64);resource_class::texture.number_loaded++;
    game.resource.texture.fence_tileset.load_spritesheet                  ("data/tilesets/fence.png"               ,resource_class::texture.number_loaded, 64, 64);resource_class::texture.number_loaded++;
    game.resource.texture.medieval_building_tileset.load_spritesheet      ("data/tilesets/medieval_building.png"   ,resource_class::texture.number_loaded, 64,192);resource_class::texture.number_loaded++;
    game.resource.texture.cave_floor_tileset.load_spritesheet             ("data/tilesets/cave_floor.png"          ,resource_class::texture.number_loaded, 64, 32);resource_class::texture.number_loaded++;
    game.resource.texture.cave_wall_tileset.load_spritesheet              ("data/tilesets/cave_wall.png"           ,resource_class::texture.number_loaded, 64,128);resource_class::texture.number_loaded++;
    game.resource.texture.cave_object_tileset.load_spritesheet            ("data/tilesets/cave_object.png"         ,resource_class::texture.number_loaded, 64,128);resource_class::texture.number_loaded++;
    game.resource.texture.dungeon_tileset.load_spritesheet                ("data/tilesets/dungeon.png"             ,resource_class::texture.number_loaded, 64, 64);resource_class::texture.number_loaded++;
    game.resource.texture.gold_tileset.load_spritesheet                   ("data/tilesets/gold_tileset.png"        ,resource_class::texture.number_loaded, 64,128);resource_class::texture.number_loaded++;
    game.resource.texture.test_tileset.load_spritesheet                   ("data/tilesets/test_tileset.png"        ,resource_class::texture.number_loaded, 64,128);resource_class::texture.number_loaded++;
};
*/
void resource_class::load_generic_textures(void)
{
    game.core.log.file_write("Loading resources -> Generic Textures");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.generic_grass.load_image       ("data/textures/generic/grass.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.generic_lava.load_image        ("data/textures/generic/lava.png"        ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.generic_lava_layer.load_image  ("data/textures/generic/lava_layer.png"  ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.generic_leaves_00.load_image   ("data/textures/generic/leaves_00.png"   ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.generic_leaves_01.load_image   ("data/textures/generic/leaves_01.png"   ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.generic_sand.load_image        ("data/textures/generic/sand.png"        ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.generic_sand_shrubs.load_image ("data/textures/generic/sand_shrubs.png" ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.generic_water.load_image       ("data/textures/generic/water.png"       ,resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};

void resource_class::load_heightmaps(void)
{
    game.core.log.file_write("Loading resources -> Heightmaps");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.heightmap_000.load_image("data/textures/heightmaps/heightmap_000.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};

/*
void resource_class::load_maps_2D(void)
{
    game.core.log.file_write("Loading resources -> 2D Maps");
//--- font ---
//--- 2D map ---
    game.resource.map_2D.town.load           ("data/maps/town.tmx");resource_class::map_2D.number_loaded++;
    game.resource.map_2D.generated.load      ("data/maps/auto.tmx");resource_class::map_2D.number_loaded++;
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
};
*/

void resource_class::load_maps_3D(void)
{
    game.core.log.file_write("Loading resources -> 3D Maps");
//--- font ---
//--- 2D map ---
//--- 3D map ---
    game.resource.map_3D.town.load      ("data/maps/town_3D.tmx");resource_class::map_3D.number_loaded++;
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
};

void resource_class::load_3D_models(void)
{
    game.core.log.file_write("Loading resources -> 3D Models");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
    game.resource.model_3D.tree_fern.load("data/models/forest/tree_fern.obj",resource_class::model_3D.number_loaded);resource_class::model_3D.number_loaded++;
    game.resource.model_3D.tree_fern.set_wrap_texture(game.resource.texture.generic_leaves_01.ref_number);
    game.resource.model_3D.tree_palm.load("data/models/forest/tree_palm.obj",resource_class::model_3D.number_loaded);resource_class::model_3D.number_loaded++;
    game.resource.model_3D.tree_palm.set_wrap_texture(game.resource.texture.generic_leaves_01.ref_number);
    game.resource.model_3D.well.load("data/models/objects/well.obj",resource_class::model_3D.number_loaded);resource_class::model_3D.number_loaded++;
    game.resource.model_3D.well.set_wrap_texture(game.resource.texture.generic_sand_shrubs.ref_number);
    game.resource.model_3D.cemetery_gate.load("data/models/objects/cemetery_gate.obj",resource_class::model_3D.number_loaded);resource_class::model_3D.number_loaded++;
    game.resource.model_3D.cemetery_gate.set_wrap_texture(game.resource.texture.generic_sand_shrubs.ref_number);
    game.resource.model_3D.tomb.load("data/models/objects/tomb.obj",resource_class::model_3D.number_loaded);resource_class::model_3D.number_loaded++;
    game.resource.model_3D.tomb.set_wrap_texture(game.resource.texture.generic_sand_shrubs.ref_number);
    game.resource.model_3D.tombwoof.load("data/models/objects/tombwoof.obj",resource_class::model_3D.number_loaded);resource_class::model_3D.number_loaded++;
    game.resource.model_3D.tombwoof.set_wrap_texture(game.resource.texture.generic_sand_shrubs.ref_number);
//--- music ---
//--- sound ---
//--- texture ---
};

void resource_class::load_test_data(void)
{
    game.core.log.file_write("Loading resources -> test data");
//--- font ---
//--- 2D map ---
//--- 3D map ---
//--- 3D model ---
//--- music ---
//--- sound ---
//--- texture ---
    game.resource.texture.test_background.load_image("data/test/background.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
    game.resource.texture.test_ball.load_image("data/test/ball.png",resource_class::texture.number_loaded);resource_class::texture.number_loaded++;
};

void resource_class::load_all(void)
{
    resource_class::initialize();
    resource_class::load_default();
    resource_class::load_UI();
    resource_class::load_items();
    resource_class::load_portraits();
    resource_class::load_particles();
    resource_class::load_spells();
    //resource_class::load_tilesets();
    resource_class::load_generic_textures();
    resource_class::load_heightmaps();
    //resource_class::load_maps_2D();
    resource_class::load_maps_3D();
    resource_class::load_3D_models();
    resource_class::load_test_data();
    resource_class::write_log_file_count();
    for(int tile_set_count = 0; tile_set_count < game.resource.map_2D.number_of_tilesets; tile_set_count++)
    {
        game.resource.map_2D.tileset[tile_set_count].tile.load_spritesheet(game.resource.map_2D.tileset[tile_set_count].image_source,0,game.resource.map_2D.tileset[tile_set_count].tilewidth,game.resource.map_2D.tileset[tile_set_count].tileheight);
    }
};

void resource_class::initialize(void)
{
    resource_class::font.number_loaded     = 0;
    //resource_class::map_2D.number_loaded   = 0;
    resource_class::map_3D.number_loaded   = 0;
    resource_class::model_3D.number_loaded = 0;
    resource_class::music.number_loaded    = 0;
    resource_class::sound.number_loaded    = 0;
    resource_class::texture.number_loaded  = 0;
};

//------------------------------------------------------------------------------------------------------------------------

