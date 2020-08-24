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


#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <cstdint>

#define PATH_DATA      "data/"
#define PATH_LOGS         "data/logs/"
#define PATH_MAPS         "data/maps/"
#define PATH_ENTITIES        "data/maps/entities/"
#define PATH_OBJECTS         "data/maps/objects/"
#define PATH_PLAYLISTS       "data/maps/playlists/"
#define PATH_TILESETS        "data/maps/tilesets/"
#define PATH_WALLS           "data/maps/walls/"
#define PATH_MODELS       "data/models/"
#define PATH_MUSIC        "data/music/"
#define PATH_PREFABS      "data/prefabs/"
#define PATH_SHADERS      "data/shaders/"
#define PATH_SOUNDS       "data/sounds/"
#define PATH_TEXTURES     "data/textures/"

#define TEXTURE_DEFAULT          "default"
#define TEXTURE_DEFAULT_DIFFUSE  "default_d.png"
#define TEXTURE_DEFAULT_EMISSIVE "default_e.png"
#define TEXTURE_DEFAULT_NORMAL   "default_n.png"
#define TEXTURE_DEFAULT_METAL    "default_m.png"
#define TEXTURE_DEFAULT_ROUGH    "default_r.png"
#define TEXTURE_DEFAULT_SPECULAR "default_s.png"

#define MAX_BONES 64 // !!! THIS HAS TO MATCH THE SHADER !!!!
#define MAX_BONE_WEIGHTS 4

#ifdef __linux__
#define PLATFORM_LINUX
#endif
#ifdef __ANDROID__
#define PLATFORM_ANDROID
#endif
#ifdef _WIN32
#define PLATFORM_WINDOWS
#endif
#ifdef _WIN64
#define PLATFORM_WINDOWS
#endif
#ifdef __APPLE__
#error "Platform not supported, upgrade to Linux!"
#endif

enum eGameState:uint16_t    { inactive = 0, active = 1 };

#endif // DEFINES_HPP
