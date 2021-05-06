/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
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
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef BIOME_DEFINE_HPP
#define BIOME_DEFINE_HPP

#include "../includes.hpp"

struct sMapFloorSpritesheet
{
    std::string name     = "";
    std::string fileName = "";
};

struct sMapMusicSet
{
    std::string   name     = "";
    std::string   fileName = "";
    std::uint32_t count    = 0;
};

struct sMapMusicTag
{
    std::string   name     = "";
};

struct sMusicTrack
{
    std::uint32_t no       = 0; // Default == 0 (random)
};

struct sMapNPCSet
{
    std::string name     = "";
    std::string fileName = "";
};

struct sMapObjectSet
{
    std::string name     = "";
    std::string fileName = "";
};

struct sMapWallSet
{
    std::string name     = "";
    std::string fileName = "";

    // Wide walls
    //sEntity**     wall_wp       = nullptr; // Pillar
    std::uint32_t wall_wp_count = 0; // Pillar
    //sEntity**     wall_we       = nullptr; // End
    std::uint32_t wall_we_count = 0; // End
    //sEntity**     wall_ws       = nullptr; // Single side
    std::uint32_t wall_ws_count = 0; // Single side
    //sEntity**     wall_wd       = nullptr; // Double side
    std::uint32_t wall_wd_count = 0; // Double side
    //sEntity**     wall_wc       = nullptr; // Corner
    std::uint32_t wall_wc_count = 0; // Corner
    //sEntity**     wall_wt       = nullptr; // Top
    std::uint32_t wall_wt_count = 0; // Top

    // Thin walls
    //sEntity**     wall_tp       = nullptr; // Pillar
    std::uint32_t wall_tp_count = 0; // Pillar
    //sEntity**     wall_te       = nullptr; // End
    std::uint32_t wall_te_count = 0; // End
    //sEntity**     wall_ts       = nullptr; // Straight
    std::uint32_t wall_ts_count = 0; // Straight
    //sEntity**     wall_tc       = nullptr; // Corner
    std::uint32_t wall_tc_count = 0; // Corner
    //sEntity**     wall_tt       = nullptr; // T Junction
    std::uint32_t wall_tt_count = 0; // T Junction
    //sEntity**     wall_tx       = nullptr; // X Junction
    std::uint32_t wall_tx_count = 0; // X Junction
    //sEntity**     wall_td       = nullptr; // Doorway single
    std::uint32_t wall_td_count = 0; // Doorway single
    //sEntity**     wall_tl       = nullptr; // Doorway large
    std::uint32_t wall_tl_count = 0; // Doorway large
};

struct sMapBiome
{
    // Linked list management
    sMapBiome* next          = nullptr;

    // General information
    std::string name         = "";
    std::string fileName     = "";

    // Data sets
    sMapMusicSet  MusicSet   = {};
    sMapMusicTag  MusicTag   = {};
    sMusicTrack   MusicTrack = {};
    sMapNPCSet    NPCSet     = {};
    sMapObjectSet ObjectSet  = {};
    sMapWallSet   WallSet    = {};
    
    // Map floor spritesheet
    sMapFloorSpritesheet floorSpritesheet = {};
};

#endif //BIOME_DEFINE_HPP

