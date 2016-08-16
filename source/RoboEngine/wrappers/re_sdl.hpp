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

#ifndef RE_SDL_HPP
#define RE_SDL_HPP

#include <cstdint>
#include <cstdlib>
#include <SDL2/SDL.h>

namespace RoboEngine
{

    #define RE_QUIT SDL_QUIT
    #define RE_INIT_TIMER SDL_INIT_TIMER
    #define RE_INIT_AUDIO SDL_INIT_AUDIO
    #define RE_INIT_VIDEO SDL_INIT_VIDEO
    #define RE_INIT_EVENTS SDL_INIT_EVENTS
    #define RE_INIT_JOYSTICK SDL_INIT_JOYSTICK
    #define RE_INIT_HAPTIC SDL_INIT_HAPTIC
    #define RE_INIT_GAMECONTROLLER SDL_INIT_GAMECONTROLLER
    #define RE_INIT_JOYSTICK SDL_INIT_JOYSTICK
    #define RE_INIT_EVENTS SDL_INIT_EVENTS
    #define RE_INIT_EVERYTHING SDL_INIT_EVERYTHING

    typedef SDL_GLattr RE_GLattr;

    inline int RE_Init(uint32_t _flags) { return SDL_Init(_flags); }
    inline void RE_SetMainReady(void) { SDL_SetMainReady(); }
    inline void RE_Quit(void) { SDL_Quit(); }
    inline int RE_InitSubSystem(uint32_t _flags) { return SDL_InitSubSystem(_flags); }
    inline void RE_QuitSubSystem(uint32_t _flags) { SDL_QuitSubSystem(_flags); }
    inline uint32_t RE_WasInit(uint32_t _flags) { return SDL_WasInit(_flags); }

}

#endif //  RE_SDL_HPP
