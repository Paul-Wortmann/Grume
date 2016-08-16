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

#ifndef RE_SDL_EVENT_HPP
#define RE_SDL_EVENT_HPP

#include <cstdint>
#include <cstdlib>
#include <SDL2/SDL.h>

namespace RoboEngine
{

    #define RE_KEYDOWN SDL_KEYDOWN
    #define RE_KEYUP SDL_KEYUP
    #define RE_MOUSEMOTION SDL_MOUSEMOTION
    #define RE_MOUSEBUTTONDOWN SDL_MOUSEBUTTONDOWN
    #define RE_MOUSEBUTTONUP SDL_MOUSEBUTTONUP
    #define RE_QUIT SDL_QUIT
    #define RE_WINDOWEVENT SDL_WINDOWEVENT
    #define RE_WINDOWEVENT_ENTER SDL_WINDOWEVENT_ENTER
    #define RE_WINDOWEVENT_LEAVE SDL_WINDOWEVENT_LEAVE

    typedef SDL_Event RE_Event;
    inline int RE_PollEvent(RE_Event* _event) { return SDL_PollEvent(_event); }

}

#endif // RE_SDL_EVENT_HPP
