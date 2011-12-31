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
    load_maps();
    return(true);
};

bool load_maps(void)
{
    int map_count = 0;
    game.map.town.load      ("data/maps/town.tmx")   ;map_count++;

    game.core.log.File_Write("Map files loaded -> ",map_count);
    return(true);
};

bool load_sounds(void)
{
    int sfx_count = 0;
    game.sound.menu_move_00.load    ("data/sound/menu/menu_move_00.wav",sfx_count)    ;sfx_count++;
    game.sound.menu_select_00.load  ("data/sound/menu/menu_select_00.wav",sfx_count)  ;sfx_count++;

    game.sound.bottle_01.load  ("data/sound/inventory/bottle_01.wav",sfx_count)  ;sfx_count++;
    game.sound.bubble_01.load  ("data/sound/inventory/bubble_01.wav",sfx_count)  ;sfx_count++;
    game.sound.bubble_02.load  ("data/sound/inventory/bubble_02.wav",sfx_count)  ;sfx_count++;
    game.sound.bubble_03.load  ("data/sound/inventory/bubble_03.wav",sfx_count)  ;sfx_count++;

    game.sound.book_00.load  ("data/sound/inventory/book_00.wav",sfx_count)  ;sfx_count++;
    game.sound.book_01.load  ("data/sound/inventory/book_01.wav",sfx_count)  ;sfx_count++;
    game.sound.book_02.load  ("data/sound/inventory/book_02.wav",sfx_count)  ;sfx_count++;

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

    game.texture.cursor.load_image              ("data/textures/UI/cursor.png"                          ,texture_count);texture_count++;
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
    game.texture.spell_book_background.load_image   ("data/textures/UI/spell_book/spell_book_background.png"  ,texture_count);texture_count++;
    game.texture.inventory.load_image               ("data/textures/UI/inventory/inventory.png"               ,texture_count);texture_count++;
    game.texture.inventory_gold.load_image          ("data/textures/UI/inventory/inventory_gold.png"          ,texture_count);texture_count++;
    game.texture.inventory_background.load_image    ("data/textures/UI/inventory/inventory_background.png"    ,texture_count);texture_count++;
    game.texture.item_stat_background.load_image    ("data/textures/UI/inventory/item_stat_background.png"    ,texture_count);texture_count++;
    game.texture.character_portrait_frame.load_image("data/textures/UI/character/character_portrait_frame.png",texture_count);texture_count++;
    game.texture.character_background.load_image    ("data/textures/UI/character/character_background.png"    ,texture_count);texture_count++;
    game.texture.check_box_true.load_image          ("data/textures/UI/character/check_box_true.png"          ,texture_count);texture_count++;
    game.texture.check_box_false.load_image         ("data/textures/UI/character/check_box_false.png"         ,texture_count);texture_count++;
    game.texture.quest_log_background.load_image    ("data/textures/UI/quest_log/quest_log_background.png"    ,texture_count);texture_count++;
    game.texture.equipment_background.load_image    ("data/textures/UI/equipment/equipment_background.png"    ,texture_count);texture_count++;
    game.texture.equipment_slot_32x32.load_image    ("data/textures/UI/equipment/equipment_slot_32x32.png"    ,texture_count);texture_count++;
    game.texture.equipment_slot_64x32.load_image    ("data/textures/UI/equipment/equipment_slot_64x32.png"    ,texture_count);texture_count++;
    game.texture.equipment_slot_64x64.load_image    ("data/textures/UI/equipment/equipment_slot_64x64.png"    ,texture_count);texture_count++;
    game.texture.equipment_slot_64x96.load_image    ("data/textures/UI/equipment/equipment_slot_64x96.png"    ,texture_count);texture_count++;

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

    game.texture.spell_01_level_01.load_image("data/textures/UI/icons/spells/ice-blue-1.png",texture_count);texture_count++;
    game.texture.spell_01_level_02.load_image("data/textures/UI/icons/spells/ice-blue-2.png",texture_count);texture_count++;
    game.texture.spell_01_level_03.load_image("data/textures/UI/icons/spells/ice-blue-3.png",texture_count);texture_count++;
    game.texture.spell_02_level_01.load_image("data/textures/UI/icons/spells/air-burst-sky-1.png",texture_count);texture_count++;
    game.texture.spell_02_level_02.load_image("data/textures/UI/icons/spells/air-burst-sky-2.png",texture_count);texture_count++;
    game.texture.spell_02_level_03.load_image("data/textures/UI/icons/spells/air-burst-sky-3.png",texture_count);texture_count++;
    game.texture.spell_03_level_01.load_image("data/textures/UI/icons/spells/beam-red-1.png",texture_count);texture_count++;
    game.texture.spell_03_level_02.load_image("data/textures/UI/icons/spells/beam-red-2.png",texture_count);texture_count++;
    game.texture.spell_03_level_03.load_image("data/textures/UI/icons/spells/beam-red-3.png",texture_count);texture_count++;
    game.texture.spell_04_level_01.load_image("data/textures/UI/icons/spells/fire-arrows-1.png",texture_count);texture_count++;
    game.texture.spell_04_level_02.load_image("data/textures/UI/icons/spells/fire-arrows-2.png",texture_count);texture_count++;
    game.texture.spell_04_level_03.load_image("data/textures/UI/icons/spells/fire-arrows-3.png",texture_count);texture_count++;
    game.texture.spell_05_level_01.load_image("data/textures/UI/icons/spells/fireball-red-1.png",texture_count);texture_count++;
    game.texture.spell_05_level_02.load_image("data/textures/UI/icons/spells/fireball-red-2.png",texture_count);texture_count++;
    game.texture.spell_05_level_03.load_image("data/textures/UI/icons/spells/fireball-red-3.png",texture_count);texture_count++;
    game.texture.spell_06_level_01.load_image("data/textures/UI/icons/spells/haste-royal-1.png",texture_count);texture_count++;
    game.texture.spell_06_level_02.load_image("data/textures/UI/icons/spells/haste-royal-2.png",texture_count);texture_count++;
    game.texture.spell_06_level_03.load_image("data/textures/UI/icons/spells/haste-royal-3.png",texture_count);texture_count++;
    game.texture.spell_07_level_01.load_image("data/textures/UI/icons/spells/heal-royal-1.png",texture_count);texture_count++;
    game.texture.spell_07_level_02.load_image("data/textures/UI/icons/spells/heal-royal-2.png",texture_count);texture_count++;
    game.texture.spell_07_level_03.load_image("data/textures/UI/icons/spells/heal-royal-3.png",texture_count);texture_count++;
    game.texture.spell_08_level_01.load_image("data/textures/UI/icons/spells/horror-acid-1.png",texture_count);texture_count++;
    game.texture.spell_08_level_02.load_image("data/textures/UI/icons/spells/horror-acid-2.png",texture_count);texture_count++;
    game.texture.spell_08_level_03.load_image("data/textures/UI/icons/spells/horror-acid-3.png",texture_count);texture_count++;
    game.texture.spell_09_level_01.load_image("data/textures/UI/icons/spells/lightning-blue-1.png",texture_count);texture_count++;
    game.texture.spell_09_level_02.load_image("data/textures/UI/icons/spells/lightning-blue-2.png",texture_count);texture_count++;
    game.texture.spell_09_level_03.load_image("data/textures/UI/icons/spells/lightning-blue-3.png",texture_count);texture_count++;
    game.texture.spell_10_level_01.load_image("data/textures/UI/icons/spells/needles-fire-1.png",texture_count);texture_count++;
    game.texture.spell_10_level_02.load_image("data/textures/UI/icons/spells/needles-fire-2.png",texture_count);texture_count++;
    game.texture.spell_10_level_03.load_image("data/textures/UI/icons/spells/needles-fire-3.png",texture_count);texture_count++;
    game.texture.spell_11_level_01.load_image("data/textures/UI/icons/spells/protect-orange-1.png",texture_count);texture_count++;
    game.texture.spell_11_level_02.load_image("data/textures/UI/icons/spells/protect-orange-2.png",texture_count);texture_count++;
    game.texture.spell_11_level_03.load_image("data/textures/UI/icons/spells/protect-orange-3.png",texture_count);texture_count++;
    game.texture.spell_12_level_01.load_image("data/textures/UI/icons/spells/rock-orange-1.png",texture_count);texture_count++;
    game.texture.spell_12_level_02.load_image("data/textures/UI/icons/spells/rock-orange-2.png",texture_count);texture_count++;
    game.texture.spell_12_level_03.load_image("data/textures/UI/icons/spells/rock-orange-3.png",texture_count);texture_count++;
    game.texture.spell_13_level_01.load_image("data/textures/UI/icons/spells/runes-magenta-1.png",texture_count);texture_count++;
    game.texture.spell_13_level_02.load_image("data/textures/UI/icons/spells/runes-magenta-2.png",texture_count);texture_count++;
    game.texture.spell_13_level_03.load_image("data/textures/UI/icons/spells/runes-magenta-3.png",texture_count);texture_count++;
    game.texture.spell_14_level_01.load_image("data/textures/UI/icons/spells/wind-blue-1.png",texture_count);texture_count++;
    game.texture.spell_14_level_02.load_image("data/textures/UI/icons/spells/wind-blue-2.png",texture_count);texture_count++;
    game.texture.spell_14_level_03.load_image("data/textures/UI/icons/spells/wind-blue-3.png",texture_count);texture_count++;
    game.texture.spell_15_level_01.load_image("data/textures/UI/icons/spells/beam-blue-1.png",texture_count);texture_count++;
    game.texture.spell_15_level_02.load_image("data/textures/UI/icons/spells/beam-blue-2.png",texture_count);texture_count++;
    game.texture.spell_15_level_03.load_image("data/textures/UI/icons/spells/beam-blue-3.png",texture_count);texture_count++;

    game.texture.grass_and_water_tileset.load_spritesheet        ("data/tilesets/grass_and_water.png"     ,texture_count, 64, 64);texture_count++;
    game.texture.bridge_tileset.load_spritesheet                 ("data/tilesets/bridge.png"              ,texture_count, 64,148);texture_count++;
    game.texture.grassland_tileset.load_spritesheet              ("data/tilesets/grassland.png"           ,texture_count, 64,128);texture_count++;
    game.texture.grassland_water_tileset.load_spritesheet        ("data/tilesets/grassland_water.png"     ,texture_count, 64, 64);texture_count++;
    game.texture.grassland_trees_tileset.load_spritesheet        ("data/tilesets/grassland_trees.png"     ,texture_count,128,128);texture_count++;
    game.texture.grassland_structures_tileset.load_spritesheet   ("data/tilesets/grassland_structures.png",texture_count, 64,148);texture_count++;
    game.texture.broken_tower_tileset.load_spritesheet           ("data/tilesets/broken_tower.png"        ,texture_count, 64, 64);texture_count++;
    game.texture.fence_tileset.load_spritesheet                  ("data/tilesets/fence.png"               ,texture_count, 64, 64);texture_count++;
    game.texture.medieval_building_tileset.load_spritesheet      ("data/tilesets/medieval_building.png"   ,texture_count, 64,192);texture_count++;
    game.texture.cave_floor_tileset.load_spritesheet             ("data/tilesets/cave_floor.png"          ,texture_count, 64, 32);texture_count++;
    game.texture.cave_wall_tileset.load_spritesheet              ("data/tilesets/cave_wall.png"           ,texture_count, 64,128);texture_count++;
    game.texture.cave_object_tileset.load_spritesheet            ("data/tilesets/cave_object.png"         ,texture_count, 64,128);texture_count++;
    game.texture.dungeon_tileset.load_spritesheet                ("data/tilesets/dungeon.png"             ,texture_count, 64, 64);texture_count++;
    game.texture.gold_tileset.load_spritesheet                   ("data/tilesets/gold_tileset.png"        ,texture_count, 64,128);texture_count++;

    game.texture.book_00.load_image("data/textures/UI/icons/books/book_00.png",texture_count);texture_count++;
    game.texture.book_01.load_image("data/textures/UI/icons/books/book_01.png",texture_count);texture_count++;
    game.texture.book_02.load_image("data/textures/UI/icons/books/book_02.png",texture_count);texture_count++;
    game.texture.book_03.load_image("data/textures/UI/icons/books/book_03.png",texture_count);texture_count++;
    game.texture.book_04.load_image("data/textures/UI/icons/books/book_04.png",texture_count);texture_count++;
    game.texture.book_05.load_image("data/textures/UI/icons/books/book_05.png",texture_count);texture_count++;
    game.texture.book_06.load_image("data/textures/UI/icons/books/book_06.png",texture_count);texture_count++;
    game.texture.book_07.load_image("data/textures/UI/icons/books/book_07.png",texture_count);texture_count++;
    game.texture.book_08.load_image("data/textures/UI/icons/books/book_08.png",texture_count);texture_count++;
    game.texture.book_09.load_image("data/textures/UI/icons/books/book_09.png",texture_count);texture_count++;
    game.texture.book_10.load_image("data/textures/UI/icons/books/book_10.png",texture_count);texture_count++;
    game.texture.book_11.load_image("data/textures/UI/icons/books/book_11.png",texture_count);texture_count++;
    game.texture.book_12.load_image("data/textures/UI/icons/books/book_12.png",texture_count);texture_count++;
    game.texture.book_13.load_image("data/textures/UI/icons/books/book_13.png",texture_count);texture_count++;
    game.texture.book_14.load_image("data/textures/UI/icons/books/book_14.png",texture_count);texture_count++;
    game.texture.book_15.load_image("data/textures/UI/icons/books/book_15.png",texture_count);texture_count++;
    game.texture.book_16.load_image("data/textures/UI/icons/books/book_16.png",texture_count);texture_count++;
    game.texture.book_17.load_image("data/textures/UI/icons/books/book_17.png",texture_count);texture_count++;
    game.texture.book_18.load_image("data/textures/UI/icons/books/book_18.png",texture_count);texture_count++;
    game.texture.book_19.load_image("data/textures/UI/icons/books/book_19.png",texture_count);texture_count++;

    game.texture.armour_00.load_image("data/textures/UI/icons/armour/armour_00.png",texture_count);texture_count++;
    game.texture.armour_01.load_image("data/textures/UI/icons/armour/armour_01.png",texture_count);texture_count++;
    game.texture.armour_02.load_image("data/textures/UI/icons/armour/armour_02.png",texture_count);texture_count++;
    game.texture.armour_03.load_image("data/textures/UI/icons/armour/armour_03.png",texture_count);texture_count++;
    game.texture.armour_04.load_image("data/textures/UI/icons/armour/armour_04.png",texture_count);texture_count++;
    game.texture.armour_05.load_image("data/textures/UI/icons/armour/armour_05.png",texture_count);texture_count++;
    game.texture.armour_06.load_image("data/textures/UI/icons/armour/armour_06.png",texture_count);texture_count++;
    game.texture.armour_07.load_image("data/textures/UI/icons/armour/armour_07.png",texture_count);texture_count++;
    game.texture.armour_08.load_image("data/textures/UI/icons/armour/armour_08.png",texture_count);texture_count++;

    game.texture.boots_00.load_image("data/textures/UI/icons/boots/boots_00.png",texture_count);texture_count++;
    game.texture.boots_01.load_image("data/textures/UI/icons/boots/boots_01.png",texture_count);texture_count++;
    game.texture.boots_02.load_image("data/textures/UI/icons/boots/boots_02.png",texture_count);texture_count++;
    game.texture.boots_03.load_image("data/textures/UI/icons/boots/boots_03.png",texture_count);texture_count++;
    game.texture.boots_04.load_image("data/textures/UI/icons/boots/boots_04.png",texture_count);texture_count++;
    game.texture.boots_05.load_image("data/textures/UI/icons/boots/boots_05.png",texture_count);texture_count++;
    game.texture.boots_06.load_image("data/textures/UI/icons/boots/boots_06.png",texture_count);texture_count++;
    game.texture.boots_07.load_image("data/textures/UI/icons/boots/boots_07.png",texture_count);texture_count++;
    game.texture.boots_08.load_image("data/textures/UI/icons/boots/boots_08.png",texture_count);texture_count++;
    game.texture.boots_09.load_image("data/textures/UI/icons/boots/boots_09.png",texture_count);texture_count++;
    game.texture.boots_10.load_image("data/textures/UI/icons/boots/boots_10.png",texture_count);texture_count++;
    game.texture.boots_11.load_image("data/textures/UI/icons/boots/boots_11.png",texture_count);texture_count++;

    game.texture.bow_00.load_image("data/textures/UI/icons/bows/bow_00.png",texture_count);texture_count++;
    game.texture.bow_01.load_image("data/textures/UI/icons/bows/bow_01.png",texture_count);texture_count++;
    game.texture.bow_02.load_image("data/textures/UI/icons/bows/bow_02.png",texture_count);texture_count++;

    game.texture.dagger_00.load_image("data/textures/UI/icons/daggers/dagger_00.png",texture_count);texture_count++;
    game.texture.dagger_01.load_image("data/textures/UI/icons/daggers/dagger_01.png",texture_count);texture_count++;
    game.texture.dagger_02.load_image("data/textures/UI/icons/daggers/dagger_02.png",texture_count);texture_count++;
    game.texture.dagger_03.load_image("data/textures/UI/icons/daggers/dagger_03.png",texture_count);texture_count++;
    game.texture.dagger_04.load_image("data/textures/UI/icons/daggers/dagger_04.png",texture_count);texture_count++;
    game.texture.dagger_05.load_image("data/textures/UI/icons/daggers/dagger_05.png",texture_count);texture_count++;
    game.texture.dagger_06.load_image("data/textures/UI/icons/daggers/dagger_06.png",texture_count);texture_count++;
    game.texture.dagger_07.load_image("data/textures/UI/icons/daggers/dagger_07.png",texture_count);texture_count++;
    game.texture.dagger_08.load_image("data/textures/UI/icons/daggers/dagger_08.png",texture_count);texture_count++;
    game.texture.dagger_09.load_image("data/textures/UI/icons/daggers/dagger_09.png",texture_count);texture_count++;
    game.texture.dagger_10.load_image("data/textures/UI/icons/daggers/dagger_10.png",texture_count);texture_count++;
    game.texture.dagger_11.load_image("data/textures/UI/icons/daggers/dagger_11.png",texture_count);texture_count++;
    game.texture.dagger_12.load_image("data/textures/UI/icons/daggers/dagger_12.png",texture_count);texture_count++;
    game.texture.dagger_13.load_image("data/textures/UI/icons/daggers/dagger_13.png",texture_count);texture_count++;
    game.texture.dagger_14.load_image("data/textures/UI/icons/daggers/dagger_14.png",texture_count);texture_count++;
    game.texture.dagger_15.load_image("data/textures/UI/icons/daggers/dagger_15.png",texture_count);texture_count++;
    game.texture.dagger_16.load_image("data/textures/UI/icons/daggers/dagger_16.png",texture_count);texture_count++;
    game.texture.dagger_17.load_image("data/textures/UI/icons/daggers/dagger_17.png",texture_count);texture_count++;
    game.texture.dagger_18.load_image("data/textures/UI/icons/daggers/dagger_18.png",texture_count);texture_count++;
    game.texture.dagger_19.load_image("data/textures/UI/icons/daggers/dagger_19.png",texture_count);texture_count++;
    game.texture.dagger_20.load_image("data/textures/UI/icons/daggers/dagger_20.png",texture_count);texture_count++;
    game.texture.dagger_21.load_image("data/textures/UI/icons/daggers/dagger_21.png",texture_count);texture_count++;
    game.texture.dagger_22.load_image("data/textures/UI/icons/daggers/dagger_22.png",texture_count);texture_count++;
    game.texture.dagger_23.load_image("data/textures/UI/icons/daggers/dagger_23.png",texture_count);texture_count++;
    game.texture.dagger_24.load_image("data/textures/UI/icons/daggers/dagger_24.png",texture_count);texture_count++;
    game.texture.dagger_25.load_image("data/textures/UI/icons/daggers/dagger_25.png",texture_count);texture_count++;
    game.texture.dagger_26.load_image("data/textures/UI/icons/daggers/dagger_26.png",texture_count);texture_count++;
    game.texture.dagger_27.load_image("data/textures/UI/icons/daggers/dagger_27.png",texture_count);texture_count++;

    game.texture.ring_00.load_image("data/textures/UI/icons/rings/ring_00.png",texture_count);texture_count++;
    game.texture.ring_01.load_image("data/textures/UI/icons/rings/ring_01.png",texture_count);texture_count++;
    game.texture.ring_02.load_image("data/textures/UI/icons/rings/ring_02.png",texture_count);texture_count++;
    game.texture.ring_03.load_image("data/textures/UI/icons/rings/ring_03.png",texture_count);texture_count++;
    game.texture.ring_04.load_image("data/textures/UI/icons/rings/ring_04.png",texture_count);texture_count++;
    game.texture.ring_05.load_image("data/textures/UI/icons/rings/ring_05.png",texture_count);texture_count++;
    game.texture.ring_06.load_image("data/textures/UI/icons/rings/ring_06.png",texture_count);texture_count++;
    game.texture.ring_07.load_image("data/textures/UI/icons/rings/ring_07.png",texture_count);texture_count++;
    game.texture.ring_08.load_image("data/textures/UI/icons/rings/ring_08.png",texture_count);texture_count++;
    game.texture.ring_09.load_image("data/textures/UI/icons/rings/ring_09.png",texture_count);texture_count++;
    game.texture.ring_10.load_image("data/textures/UI/icons/rings/ring_10.png",texture_count);texture_count++;
    game.texture.ring_11.load_image("data/textures/UI/icons/rings/ring_11.png",texture_count);texture_count++;
    game.texture.ring_12.load_image("data/textures/UI/icons/rings/ring_12.png",texture_count);texture_count++;
    game.texture.ring_13.load_image("data/textures/UI/icons/rings/ring_13.png",texture_count);texture_count++;
    game.texture.ring_14.load_image("data/textures/UI/icons/rings/ring_14.png",texture_count);texture_count++;
    game.texture.ring_15.load_image("data/textures/UI/icons/rings/ring_15.png",texture_count);texture_count++;
    game.texture.ring_16.load_image("data/textures/UI/icons/rings/ring_16.png",texture_count);texture_count++;
    game.texture.ring_17.load_image("data/textures/UI/icons/rings/ring_17.png",texture_count);texture_count++;
    game.texture.ring_18.load_image("data/textures/UI/icons/rings/ring_18.png",texture_count);texture_count++;

    game.texture.shield_00.load_image("data/textures/UI/icons/shields/shield_00.png",texture_count);texture_count++;
    game.texture.shield_01.load_image("data/textures/UI/icons/shields/shield_01.png",texture_count);texture_count++;
    game.texture.shield_02.load_image("data/textures/UI/icons/shields/shield_02.png",texture_count);texture_count++;
    game.texture.shield_03.load_image("data/textures/UI/icons/shields/shield_03.png",texture_count);texture_count++;
    game.texture.shield_04.load_image("data/textures/UI/icons/shields/shield_04.png",texture_count);texture_count++;
    game.texture.shield_05.load_image("data/textures/UI/icons/shields/shield_05.png",texture_count);texture_count++;
    game.texture.shield_06.load_image("data/textures/UI/icons/shields/shield_06.png",texture_count);texture_count++;

    game.texture.sling_00.load_image("data/textures/UI/icons/slings/sling_00.png",texture_count);texture_count++;
    game.texture.sling_01.load_image("data/textures/UI/icons/slings/sling_01.png",texture_count);texture_count++;
    game.texture.sling_02.load_image("data/textures/UI/icons/slings/sling_02.png",texture_count);texture_count++;
    game.texture.sling_03.load_image("data/textures/UI/icons/slings/sling_03.png",texture_count);texture_count++;

    game.texture.sword_00.load_image("data/textures/UI/icons/swords/sword_00.png",texture_count);texture_count++;
    game.texture.sword_01.load_image("data/textures/UI/icons/swords/sword_01.png",texture_count);texture_count++;
    game.texture.sword_02.load_image("data/textures/UI/icons/swords/sword_02.png",texture_count);texture_count++;
    game.texture.sword_03.load_image("data/textures/UI/icons/swords/sword_03.png",texture_count);texture_count++;
    game.texture.sword_04.load_image("data/textures/UI/icons/swords/sword_04.png",texture_count);texture_count++;
    game.texture.sword_05.load_image("data/textures/UI/icons/swords/sword_05.png",texture_count);texture_count++;
    game.texture.sword_06.load_image("data/textures/UI/icons/swords/sword_06.png",texture_count);texture_count++;
    game.texture.sword_07.load_image("data/textures/UI/icons/swords/sword_07.png",texture_count);texture_count++;
    game.texture.sword_08.load_image("data/textures/UI/icons/swords/sword_08.png",texture_count);texture_count++;
    game.texture.sword_09.load_image("data/textures/UI/icons/swords/sword_09.png",texture_count);texture_count++;
    game.texture.sword_10.load_image("data/textures/UI/icons/swords/sword_10.png",texture_count);texture_count++;
    game.texture.sword_11.load_image("data/textures/UI/icons/swords/sword_11.png",texture_count);texture_count++;
    game.texture.sword_12.load_image("data/textures/UI/icons/swords/sword_12.png",texture_count);texture_count++;
    game.texture.sword_13.load_image("data/textures/UI/icons/swords/sword_13.png",texture_count);texture_count++;
    game.texture.sword_14.load_image("data/textures/UI/icons/swords/sword_14.png",texture_count);texture_count++;
    game.texture.sword_15.load_image("data/textures/UI/icons/swords/sword_15.png",texture_count);texture_count++;
    game.texture.sword_16.load_image("data/textures/UI/icons/swords/sword_16.png",texture_count);texture_count++;
    game.texture.sword_17.load_image("data/textures/UI/icons/swords/sword_17.png",texture_count);texture_count++;
    game.texture.sword_18.load_image("data/textures/UI/icons/swords/sword_18.png",texture_count);texture_count++;
    game.texture.sword_19.load_image("data/textures/UI/icons/swords/sword_19.png",texture_count);texture_count++;
    game.texture.sword_20.load_image("data/textures/UI/icons/swords/sword_20.png",texture_count);texture_count++;
    game.texture.sword_21.load_image("data/textures/UI/icons/swords/sword_21.png",texture_count);texture_count++;
    game.texture.sword_22.load_image("data/textures/UI/icons/swords/sword_22.png",texture_count);texture_count++;
    game.texture.sword_23.load_image("data/textures/UI/icons/swords/sword_23.png",texture_count);texture_count++;
    game.texture.sword_24.load_image("data/textures/UI/icons/swords/sword_24.png",texture_count);texture_count++;
    game.texture.sword_25.load_image("data/textures/UI/icons/swords/sword_25.png",texture_count);texture_count++;
    game.texture.sword_26.load_image("data/textures/UI/icons/swords/sword_26.png",texture_count);texture_count++;
    game.texture.sword_27.load_image("data/textures/UI/icons/swords/sword_27.png",texture_count);texture_count++;

    game.texture.wand_00.load_image("data/textures/UI/icons/wands/wand_00.png",texture_count);texture_count++;
    game.texture.wand_01.load_image("data/textures/UI/icons/wands/wand_01.png",texture_count);texture_count++;
    game.texture.wand_02.load_image("data/textures/UI/icons/wands/wand_02.png",texture_count);texture_count++;
    game.texture.wand_03.load_image("data/textures/UI/icons/wands/wand_03.png",texture_count);texture_count++;
    game.texture.wand_04.load_image("data/textures/UI/icons/wands/wand_04.png",texture_count);texture_count++;
    game.texture.wand_05.load_image("data/textures/UI/icons/wands/wand_05.png",texture_count);texture_count++;
    game.texture.wand_06.load_image("data/textures/UI/icons/wands/wand_06.png",texture_count);texture_count++;
    game.texture.wand_07.load_image("data/textures/UI/icons/wands/wand_07.png",texture_count);texture_count++;
    game.texture.wand_08.load_image("data/textures/UI/icons/wands/wand_08.png",texture_count);texture_count++;
    game.texture.wand_09.load_image("data/textures/UI/icons/wands/wand_09.png",texture_count);texture_count++;
    game.texture.wand_10.load_image("data/textures/UI/icons/wands/wand_10.png",texture_count);texture_count++;
    game.texture.wand_11.load_image("data/textures/UI/icons/wands/wand_11.png",texture_count);texture_count++;
    game.texture.wand_12.load_image("data/textures/UI/icons/wands/wand_12.png",texture_count);texture_count++;
    game.texture.wand_13.load_image("data/textures/UI/icons/wands/wand_13.png",texture_count);texture_count++;
    game.texture.wand_14.load_image("data/textures/UI/icons/wands/wand_14.png",texture_count);texture_count++;
    game.texture.wand_15.load_image("data/textures/UI/icons/wands/wand_15.png",texture_count);texture_count++;
    game.texture.wand_16.load_image("data/textures/UI/icons/wands/wand_16.png",texture_count);texture_count++;
    game.texture.wand_17.load_image("data/textures/UI/icons/wands/wand_17.png",texture_count);texture_count++;
    game.texture.wand_18.load_image("data/textures/UI/icons/wands/wand_18.png",texture_count);texture_count++;
    game.texture.wand_19.load_image("data/textures/UI/icons/wands/wand_19.png",texture_count);texture_count++;
    game.texture.wand_20.load_image("data/textures/UI/icons/wands/wand_20.png",texture_count);texture_count++;

    game.texture.potion_01.load_image("data/textures/UI/icons/potions/potion_01.png",texture_count);texture_count++;
    game.texture.potion_02.load_image("data/textures/UI/icons/potions/potion_02.png",texture_count);texture_count++;
    game.texture.potion_03.load_image("data/textures/UI/icons/potions/potion_03.png",texture_count);texture_count++;
    game.texture.potion_04.load_image("data/textures/UI/icons/potions/potion_04.png",texture_count);texture_count++;
    game.texture.potion_05.load_image("data/textures/UI/icons/potions/potion_05.png",texture_count);texture_count++;
    game.texture.potion_06.load_image("data/textures/UI/icons/potions/potion_06.png",texture_count);texture_count++;
    game.texture.potion_07.load_image("data/textures/UI/icons/potions/potion_07.png",texture_count);texture_count++;
    game.texture.potion_08.load_image("data/textures/UI/icons/potions/potion_08.png",texture_count);texture_count++;
    game.texture.potion_09.load_image("data/textures/UI/icons/potions/potion_09.png",texture_count);texture_count++;
    game.texture.potion_10.load_image("data/textures/UI/icons/potions/potion_10.png",texture_count);texture_count++;
    game.texture.potion_11.load_image("data/textures/UI/icons/potions/potion_11.png",texture_count);texture_count++;
    game.texture.potion_12.load_image("data/textures/UI/icons/potions/potion_12.png",texture_count);texture_count++;
    game.texture.potion_13.load_image("data/textures/UI/icons/potions/potion_13.png",texture_count);texture_count++;
    game.texture.potion_14.load_image("data/textures/UI/icons/potions/potion_14.png",texture_count);texture_count++;
    game.texture.potion_15.load_image("data/textures/UI/icons/potions/potion_15.png",texture_count);texture_count++;
    game.texture.potion_16.load_image("data/textures/UI/icons/potions/potion_16.png",texture_count);texture_count++;
    game.texture.potion_17.load_image("data/textures/UI/icons/potions/potion_17.png",texture_count);texture_count++;
    game.texture.potion_18.load_image("data/textures/UI/icons/potions/potion_18.png",texture_count);texture_count++;
    game.texture.potion_19.load_image("data/textures/UI/icons/potions/potion_19.png",texture_count);texture_count++;
    game.texture.potion_20.load_image("data/textures/UI/icons/potions/potion_20.png",texture_count);texture_count++;
    game.texture.potion_21.load_image("data/textures/UI/icons/potions/potion_21.png",texture_count);texture_count++;

    game.texture.amulet_00.load_image("data/textures/UI/icons/amulets/amulet_00.png",texture_count);texture_count++;
    game.texture.amulet_01.load_image("data/textures/UI/icons/amulets/amulet_01.png",texture_count);texture_count++;
    game.texture.amulet_02.load_image("data/textures/UI/icons/amulets/amulet_02.png",texture_count);texture_count++;
    game.texture.amulet_03.load_image("data/textures/UI/icons/amulets/amulet_03.png",texture_count);texture_count++;
    game.texture.amulet_04.load_image("data/textures/UI/icons/amulets/amulet_04.png",texture_count);texture_count++;
    game.texture.amulet_05.load_image("data/textures/UI/icons/amulets/amulet_05.png",texture_count);texture_count++;
    game.texture.amulet_06.load_image("data/textures/UI/icons/amulets/amulet_06.png",texture_count);texture_count++;
    game.texture.amulet_07.load_image("data/textures/UI/icons/amulets/amulet_07.png",texture_count);texture_count++;
    game.texture.amulet_08.load_image("data/textures/UI/icons/amulets/amulet_08.png",texture_count);texture_count++;
    game.texture.amulet_09.load_image("data/textures/UI/icons/amulets/amulet_09.png",texture_count);texture_count++;
    game.texture.amulet_10.load_image("data/textures/UI/icons/amulets/amulet_10.png",texture_count);texture_count++;
    game.texture.amulet_11.load_image("data/textures/UI/icons/amulets/amulet_11.png",texture_count);texture_count++;
    game.texture.amulet_12.load_image("data/textures/UI/icons/amulets/amulet_12.png",texture_count);texture_count++;
    game.texture.amulet_13.load_image("data/textures/UI/icons/amulets/amulet_13.png",texture_count);texture_count++;

    game.texture.belt_00.load_image("data/textures/UI/icons/belts/belt_00.png",texture_count);texture_count++;

    game.texture.helm_00.load_image("data/textures/UI/icons/helms/helm_00.png",texture_count);texture_count++;
    game.texture.helm_01.load_image("data/textures/UI/icons/helms/helm_01.png",texture_count);texture_count++;

    game.texture.portrait_00.load_image("data/textures/UI/portraits/portrait_00.png",texture_count);texture_count++;
    game.texture.portrait_01.load_image("data/textures/UI/portraits/portrait_01.png",texture_count);texture_count++;
    game.texture.portrait_02.load_image("data/textures/UI/portraits/portrait_02.png",texture_count);texture_count++;
    game.texture.portrait_03.load_image("data/textures/UI/portraits/portrait_03.png",texture_count);texture_count++;
    game.texture.portrait_04.load_image("data/textures/UI/portraits/portrait_04.png",texture_count);texture_count++;
    game.texture.portrait_05.load_image("data/textures/UI/portraits/portrait_05.png",texture_count);texture_count++;
    game.texture.portrait_06.load_image("data/textures/UI/portraits/portrait_06.png",texture_count);texture_count++;
    game.texture.portrait_07.load_image("data/textures/UI/portraits/portrait_07.png",texture_count);texture_count++;
    game.texture.portrait_08.load_image("data/textures/UI/portraits/portrait_08.png",texture_count);texture_count++;
    game.texture.portrait_09.load_image("data/textures/UI/portraits/portrait_09.png",texture_count);texture_count++;
    game.texture.portrait_10.load_image("data/textures/UI/portraits/portrait_10.png",texture_count);texture_count++;

    game.core.log.File_Write("Texture files loaded -> ",texture_count);
    return(true);
};

bool proc_textures(void)
{
    //use for sprite sheets / animation
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
    draw_texture(r,texture_number,x,y,z,w,h,0.0f,0);
};

bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle)
{
    draw_texture(r,texture_number,x,y,z,w,h,angle,0);
};

bool draw_texture(bool r, int texture_number, float x, float y, float z, float w, float h, float angle, int frame)
{
    if (texture_number == game.texture.background_00.ref_number) game.texture.background_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.background_01.ref_number) game.texture.background_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.background_02.ref_number) game.texture.background_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.background_03.ref_number) game.texture.background_03.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.logo.ref_number)                      game.texture.logo.draw                     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.button_normal.ref_number)             game.texture.button_normal.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.button_highlighted.ref_number)        game.texture.button_highlighted.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.button_disabled.ref_number)           game.texture.button_disabled.draw          (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.close_button.ref_number)              game.texture.close_button.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.close_button_highlighted.ref_number)  game.texture.close_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.selection_box.ref_number)             game.texture.selection_box.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.arrow_button_normal.ref_number)       game.texture.arrow_button_normal.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.arrow_button_highlighted.ref_number)  game.texture.arrow_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.arrow_button_disabled.ref_number)     game.texture.arrow_button_disabled.draw    (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.slider_button_normal.ref_number)      game.texture.slider_button_normal.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.slider_button_highlighted.ref_number) game.texture.slider_button_highlighted.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.red_button.ref_number)                game.texture.red_button.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.red_button_highlighted.ref_number)    game.texture.red_button_highlighted.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.green_button.ref_number)              game.texture.green_button.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.green_button_highlighted.ref_number)  game.texture.green_button_highlighted.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.blue_button.ref_number)               game.texture.blue_button.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.blue_button_highlighted.ref_number)   game.texture.blue_button_highlighted.draw  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.resolution_icon.ref_number)           game.texture.resolution_icon.draw          (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.cursor.ref_number)                    game.texture.cursor.draw                   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.action_bar.ref_number)                game.texture.action_bar.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.action_bar_front.ref_number)          game.texture.action_bar_front.draw         (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.glass_cover_01.ref_number)            game.texture.glass_cover_01.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.glass_cover_02.ref_number)            game.texture.glass_cover_02.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_01.ref_number)                   game.texture.icon_01.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_02.ref_number)                   game.texture.icon_02.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_03.ref_number)                   game.texture.icon_03.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_04.ref_number)                   game.texture.icon_04.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_05.ref_number)                   game.texture.icon_05.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_06.ref_number)                   game.texture.icon_06.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.icon_melee.ref_number)                game.texture.icon_melee.draw               (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.health_bar.ref_number)                game.texture.health_bar.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.mana_bar.ref_number)                  game.texture.mana_bar.draw                 (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.profile_background.ref_number)        game.texture.profile_background.draw       (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.profile_main.ref_number)              game.texture.profile_main.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.profile_main_background.ref_number)   game.texture.profile_main_background.draw  (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.spell_book.ref_number)                game.texture.spell_book.draw               (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_spell_cover.ref_number)    game.texture.spell_book_spell_cover.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_book_background.ref_number)     game.texture.spell_book_background.draw    (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.inventory.ref_number)                 game.texture.inventory.draw                (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.inventory_gold.ref_number)            game.texture.inventory_gold.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.inventory_background.ref_number)      game.texture.inventory_background.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.item_stat_background.ref_number)      game.texture.item_stat_background.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.character_portrait_frame.ref_number)  game.texture.character_portrait_frame.draw (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.character_background.ref_number)      game.texture.character_background.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.check_box_true.ref_number)            game.texture.check_box_true.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.check_box_false.ref_number)           game.texture.check_box_false.draw          (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.quest_log_background.ref_number)      game.texture.quest_log_background.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.equipment_background.ref_number)      game.texture.equipment_background.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.equipment_slot_32x32.ref_number)      game.texture.equipment_slot_32x32.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.equipment_slot_64x32.ref_number)      game.texture.equipment_slot_64x32.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.equipment_slot_64x64.ref_number)      game.texture.equipment_slot_64x64.draw     (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.equipment_slot_64x96.ref_number)      game.texture.equipment_slot_64x96.draw     (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.particle_000.ref_number) game.texture.particle_000.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_001.ref_number) game.texture.particle_001.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_002.ref_number) game.texture.particle_002.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_003.ref_number) game.texture.particle_003.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_004.ref_number) game.texture.particle_004.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_005.ref_number) game.texture.particle_005.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_006.ref_number) game.texture.particle_006.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_007.ref_number) game.texture.particle_007.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_008.ref_number) game.texture.particle_008.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_009.ref_number) game.texture.particle_009.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_010.ref_number) game.texture.particle_010.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_011.ref_number) game.texture.particle_011.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_012.ref_number) game.texture.particle_012.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_013.ref_number) game.texture.particle_013.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_014.ref_number) game.texture.particle_014.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.particle_015.ref_number) game.texture.particle_015.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.spell_01_level_01.ref_number) game.texture.spell_01_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_01_level_02.ref_number) game.texture.spell_01_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_01_level_03.ref_number) game.texture.spell_01_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_02_level_01.ref_number) game.texture.spell_02_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_02_level_02.ref_number) game.texture.spell_02_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_02_level_03.ref_number) game.texture.spell_02_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_03_level_01.ref_number) game.texture.spell_03_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_03_level_02.ref_number) game.texture.spell_03_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_03_level_03.ref_number) game.texture.spell_03_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_04_level_01.ref_number) game.texture.spell_04_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_04_level_02.ref_number) game.texture.spell_04_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_04_level_03.ref_number) game.texture.spell_04_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_05_level_01.ref_number) game.texture.spell_05_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_05_level_02.ref_number) game.texture.spell_05_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_05_level_03.ref_number) game.texture.spell_05_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_06_level_01.ref_number) game.texture.spell_06_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_06_level_02.ref_number) game.texture.spell_06_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_06_level_03.ref_number) game.texture.spell_06_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_07_level_01.ref_number) game.texture.spell_07_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_07_level_02.ref_number) game.texture.spell_07_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_07_level_03.ref_number) game.texture.spell_07_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_08_level_01.ref_number) game.texture.spell_08_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_08_level_02.ref_number) game.texture.spell_08_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_08_level_03.ref_number) game.texture.spell_08_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_09_level_01.ref_number) game.texture.spell_09_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_09_level_02.ref_number) game.texture.spell_09_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_09_level_03.ref_number) game.texture.spell_09_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_10_level_01.ref_number) game.texture.spell_10_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_10_level_02.ref_number) game.texture.spell_10_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_10_level_03.ref_number) game.texture.spell_10_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_11_level_01.ref_number) game.texture.spell_11_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_11_level_02.ref_number) game.texture.spell_11_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_11_level_03.ref_number) game.texture.spell_11_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_12_level_01.ref_number) game.texture.spell_12_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_12_level_02.ref_number) game.texture.spell_12_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_12_level_03.ref_number) game.texture.spell_12_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_13_level_01.ref_number) game.texture.spell_13_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_13_level_02.ref_number) game.texture.spell_13_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_13_level_03.ref_number) game.texture.spell_13_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_14_level_01.ref_number) game.texture.spell_14_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_14_level_02.ref_number) game.texture.spell_14_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_14_level_03.ref_number) game.texture.spell_14_level_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_15_level_01.ref_number) game.texture.spell_15_level_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_15_level_02.ref_number) game.texture.spell_15_level_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.spell_15_level_03.ref_number) game.texture.spell_15_level_03.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.grass_and_water_tileset.ref_number)         game.texture.grass_and_water_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.bridge_tileset.ref_number)                  game.texture.bridge_tileset.draw                 (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_tileset.ref_number)               game.texture.grassland_tileset.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_water_tileset.ref_number)         game.texture.grassland_water_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_trees_tileset.ref_number)         game.texture.grassland_trees_tileset.draw        (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.grassland_structures_tileset.ref_number)    game.texture.grassland_structures_tileset.draw   (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.broken_tower_tileset.ref_number)            game.texture.broken_tower_tileset.draw           (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.fence_tileset.ref_number)                   game.texture.fence_tileset.draw                  (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.medieval_building_tileset.ref_number)       game.texture.medieval_building_tileset.draw      (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.cave_floor_tileset.ref_number)              game.texture.cave_floor_tileset.draw             (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.cave_wall_tileset.ref_number)               game.texture.cave_wall_tileset.draw              (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.cave_object_tileset.ref_number)             game.texture.cave_object_tileset.draw            (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dungeon_tileset.ref_number)                 game.texture.dungeon_tileset.draw                (r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.gold_tileset.ref_number)                    game.texture.gold_tileset.draw                   (r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.book_00.ref_number) game.texture.book_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_01.ref_number) game.texture.book_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_02.ref_number) game.texture.book_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_03.ref_number) game.texture.book_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_04.ref_number) game.texture.book_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_05.ref_number) game.texture.book_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_06.ref_number) game.texture.book_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_07.ref_number) game.texture.book_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_08.ref_number) game.texture.book_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_09.ref_number) game.texture.book_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_10.ref_number) game.texture.book_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_11.ref_number) game.texture.book_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_12.ref_number) game.texture.book_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_13.ref_number) game.texture.book_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_14.ref_number) game.texture.book_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_15.ref_number) game.texture.book_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_16.ref_number) game.texture.book_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_17.ref_number) game.texture.book_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_18.ref_number) game.texture.book_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.book_19.ref_number) game.texture.book_19.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.armour_00.ref_number) game.texture.armour_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_01.ref_number) game.texture.armour_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_02.ref_number) game.texture.armour_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_03.ref_number) game.texture.armour_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_04.ref_number) game.texture.armour_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_05.ref_number) game.texture.armour_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_06.ref_number) game.texture.armour_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_07.ref_number) game.texture.armour_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.armour_08.ref_number) game.texture.armour_08.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.boots_00.ref_number) game.texture.boots_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_01.ref_number) game.texture.boots_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_02.ref_number) game.texture.boots_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_03.ref_number) game.texture.boots_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_04.ref_number) game.texture.boots_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_05.ref_number) game.texture.boots_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_06.ref_number) game.texture.boots_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_07.ref_number) game.texture.boots_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_08.ref_number) game.texture.boots_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_09.ref_number) game.texture.boots_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_10.ref_number) game.texture.boots_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.boots_11.ref_number) game.texture.boots_11.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.bow_00.ref_number) game.texture.bow_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.bow_01.ref_number) game.texture.bow_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.bow_02.ref_number) game.texture.bow_02.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.dagger_00.ref_number) game.texture.dagger_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_01.ref_number) game.texture.dagger_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_02.ref_number) game.texture.dagger_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_03.ref_number) game.texture.dagger_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_04.ref_number) game.texture.dagger_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_05.ref_number) game.texture.dagger_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_06.ref_number) game.texture.dagger_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_07.ref_number) game.texture.dagger_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_08.ref_number) game.texture.dagger_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_09.ref_number) game.texture.dagger_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_10.ref_number) game.texture.dagger_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_11.ref_number) game.texture.dagger_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_12.ref_number) game.texture.dagger_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_13.ref_number) game.texture.dagger_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_14.ref_number) game.texture.dagger_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_15.ref_number) game.texture.dagger_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_16.ref_number) game.texture.dagger_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_17.ref_number) game.texture.dagger_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_18.ref_number) game.texture.dagger_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_19.ref_number) game.texture.dagger_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_20.ref_number) game.texture.dagger_20.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_21.ref_number) game.texture.dagger_21.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_22.ref_number) game.texture.dagger_22.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_23.ref_number) game.texture.dagger_23.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_24.ref_number) game.texture.dagger_24.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_25.ref_number) game.texture.dagger_25.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_26.ref_number) game.texture.dagger_26.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.dagger_27.ref_number) game.texture.dagger_27.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.ring_00.ref_number) game.texture.ring_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_01.ref_number) game.texture.ring_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_02.ref_number) game.texture.ring_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_03.ref_number) game.texture.ring_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_04.ref_number) game.texture.ring_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_05.ref_number) game.texture.ring_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_06.ref_number) game.texture.ring_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_07.ref_number) game.texture.ring_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_08.ref_number) game.texture.ring_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_09.ref_number) game.texture.ring_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_10.ref_number) game.texture.ring_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_11.ref_number) game.texture.ring_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_12.ref_number) game.texture.ring_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_13.ref_number) game.texture.ring_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_14.ref_number) game.texture.ring_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_15.ref_number) game.texture.ring_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_16.ref_number) game.texture.ring_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_17.ref_number) game.texture.ring_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.ring_18.ref_number) game.texture.ring_18.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.shield_00.ref_number) game.texture.shield_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.shield_01.ref_number) game.texture.shield_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.shield_02.ref_number) game.texture.shield_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.shield_03.ref_number) game.texture.shield_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.shield_04.ref_number) game.texture.shield_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.shield_05.ref_number) game.texture.shield_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.shield_06.ref_number) game.texture.shield_06.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.sling_00.ref_number) game.texture.sling_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sling_01.ref_number) game.texture.sling_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sling_02.ref_number) game.texture.sling_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sling_03.ref_number) game.texture.sling_03.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.sword_00.ref_number) game.texture.sword_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_01.ref_number) game.texture.sword_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_02.ref_number) game.texture.sword_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_03.ref_number) game.texture.sword_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_04.ref_number) game.texture.sword_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_05.ref_number) game.texture.sword_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_06.ref_number) game.texture.sword_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_07.ref_number) game.texture.sword_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_08.ref_number) game.texture.sword_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_09.ref_number) game.texture.sword_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_10.ref_number) game.texture.sword_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_11.ref_number) game.texture.sword_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_12.ref_number) game.texture.sword_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_13.ref_number) game.texture.sword_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_14.ref_number) game.texture.sword_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_15.ref_number) game.texture.sword_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_16.ref_number) game.texture.sword_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_17.ref_number) game.texture.sword_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_18.ref_number) game.texture.sword_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_19.ref_number) game.texture.sword_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_20.ref_number) game.texture.sword_20.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_21.ref_number) game.texture.sword_21.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_22.ref_number) game.texture.sword_22.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_23.ref_number) game.texture.sword_23.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_24.ref_number) game.texture.sword_24.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_25.ref_number) game.texture.sword_25.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_26.ref_number) game.texture.sword_26.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.sword_27.ref_number) game.texture.sword_27.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.wand_00.ref_number) game.texture.wand_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_01.ref_number) game.texture.wand_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_02.ref_number) game.texture.wand_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_03.ref_number) game.texture.wand_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_04.ref_number) game.texture.wand_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_05.ref_number) game.texture.wand_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_06.ref_number) game.texture.wand_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_07.ref_number) game.texture.wand_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_08.ref_number) game.texture.wand_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_09.ref_number) game.texture.wand_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_10.ref_number) game.texture.wand_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_11.ref_number) game.texture.wand_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_12.ref_number) game.texture.wand_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_13.ref_number) game.texture.wand_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_14.ref_number) game.texture.wand_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_15.ref_number) game.texture.wand_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_16.ref_number) game.texture.wand_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_17.ref_number) game.texture.wand_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_18.ref_number) game.texture.wand_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_19.ref_number) game.texture.wand_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.wand_20.ref_number) game.texture.wand_20.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.potion_01.ref_number) game.texture.potion_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_02.ref_number) game.texture.potion_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_03.ref_number) game.texture.potion_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_04.ref_number) game.texture.potion_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_05.ref_number) game.texture.potion_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_06.ref_number) game.texture.potion_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_07.ref_number) game.texture.potion_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_08.ref_number) game.texture.potion_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_09.ref_number) game.texture.potion_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_10.ref_number) game.texture.potion_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_11.ref_number) game.texture.potion_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_12.ref_number) game.texture.potion_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_13.ref_number) game.texture.potion_13.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_14.ref_number) game.texture.potion_14.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_15.ref_number) game.texture.potion_15.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_16.ref_number) game.texture.potion_16.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_17.ref_number) game.texture.potion_17.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_18.ref_number) game.texture.potion_18.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_19.ref_number) game.texture.potion_19.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_20.ref_number) game.texture.potion_20.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.potion_21.ref_number) game.texture.potion_21.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.amulet_00.ref_number) game.texture.amulet_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_01.ref_number) game.texture.amulet_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_02.ref_number) game.texture.amulet_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_03.ref_number) game.texture.amulet_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_04.ref_number) game.texture.amulet_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_05.ref_number) game.texture.amulet_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_06.ref_number) game.texture.amulet_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_07.ref_number) game.texture.amulet_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_08.ref_number) game.texture.amulet_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_09.ref_number) game.texture.amulet_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_10.ref_number) game.texture.amulet_10.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_11.ref_number) game.texture.amulet_11.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_12.ref_number) game.texture.amulet_12.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.amulet_13.ref_number) game.texture.amulet_13.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.belt_00.ref_number) game.texture.belt_00.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.helm_00.ref_number) game.texture.helm_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.helm_01.ref_number) game.texture.helm_01.draw(r,x,y,z,w,h,angle,frame);

    if (texture_number == game.texture.portrait_00.ref_number) game.texture.portrait_00.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_01.ref_number) game.texture.portrait_01.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_02.ref_number) game.texture.portrait_02.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_03.ref_number) game.texture.portrait_03.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_04.ref_number) game.texture.portrait_04.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_05.ref_number) game.texture.portrait_05.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_06.ref_number) game.texture.portrait_06.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_07.ref_number) game.texture.portrait_07.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_08.ref_number) game.texture.portrait_08.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_09.ref_number) game.texture.portrait_09.draw(r,x,y,z,w,h,angle,frame);
    if (texture_number == game.texture.portrait_10.ref_number) game.texture.portrait_10.draw(r,x,y,z,w,h,angle,frame);

    return(true);
};




