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

#ifndef RE_SDL_GRAPHICS_HPP
#define RE_SDL_GRAPHICS_HPP

#include <cstdint>
#include <cstdlib>
#include <string>
#include <SDL2/SDL.h>
#include "re_sdl.hpp"

namespace RoboEngine
{

    #define RE_WINDOWPOS_CENTERED SDL_WINDOWPOS_CENTERED
    #define RE_WINDOWPOS_UNDEFINED SDL_WINDOWPOS_UNDEFINED

    #define RE_WINDOW_FULLSCREEN SDL_WINDOW_FULLSCREEN
    #define RE_WINDOW_FULLSCREEN_DESKTOP SDL_WINDOW_FULLSCREEN_DESKTOP
    #define RE_WINDOW_OPENGL SDL_WINDOW_OPENGL
    #define RE_WINDOW_HIDDEN SDL_WINDOW_HIDDEN
    #define RE_WINDOW_BORDERLESS SDL_WINDOW_BORDERLESS
    #define RE_WINDOW_RESIZABLE SDL_WINDOW_RESIZABLE
    #define RE_WINDOW_MINIMIZED SDL_WINDOW_MINIMIZED
    #define RE_WINDOW_MAXIMIZED SDL_WINDOW_MAXIMIZED
    #define RE_WINDOW_INPUT_GRABBED SDL_WINDOW_INPUT_GRABBED
    #define RE_WINDOW_ALLOW_HIGHDPI SDL_WINDOW_ALLOW_HIGHDPI

    #define RE_GL_CONTEXT_MAJOR_VERSION SDL_GL_CONTEXT_MAJOR_VERSION
    #define RE_GL_CONTEXT_MINOR_VERSION SDL_GL_CONTEXT_MINOR_VERSION
    #define RE_GL_CONTEXT_PROFILE_MASK SDL_GL_CONTEXT_PROFILE_MASK
    #define RE_GL_CONTEXT_PROFILE_CORE SDL_GL_CONTEXT_PROFILE_CORE
    #define RE_GL_DOUBLEBUFFER SDL_GL_DOUBLEBUFFER
    #define RE_GL_DEPTH_SIZE SDL_GL_DEPTH_SIZE

    typedef SDL_Window RE_Window;
    typedef SDL_GLContext RE_GLContext;
    typedef SDL_DisplayMode RE_DisplayMode;

    inline RE_Window* RE_CreateWindow(const std::string &_title, uint64_t _x, uint64_t _y, uint16_t _w, uint16_t _h, uint32_t _flags) { return SDL_CreateWindow(_title.c_str(), _x, _y, _w, _h, _flags); }
    inline RE_Window* RE_CreateWindow(const std::string &_title, uint16_t _w, uint16_t _h, uint32_t _flags) { return RE_CreateWindow(_title.c_str(), RE_WINDOWPOS_CENTERED, RE_WINDOWPOS_CENTERED, _w, _h, _flags); }
    inline void RE_DestroyWindow(RE_Window* _window) { SDL_DestroyWindow(_window); }

    inline RE_GLContext RE_GL_CreateContext(RE_Window *_window) { return SDL_GL_CreateContext(_window); }
    inline void RE_GL_SwapWindow(RE_Window *_window) { SDL_GL_SwapWindow(_window); }
    inline void RE_GL_DeleteContext(RE_GLContext _glcontext) { SDL_GL_DeleteContext(_glcontext); }
    inline uint16_t RE_GL_SetSwapInterval(uint16_t _interval) { return SDL_GL_SetSwapInterval(_interval); }

    inline uint16_t RE_GetNumVideoDisplays(void) { return SDL_GetNumVideoDisplays(); }
    inline uint16_t RE_GetNumDisplayModes(uint16_t _displayIndex) { return SDL_GetNumDisplayModes(_displayIndex); }
    inline uint16_t RE_GetDisplayMode(uint16_t _displayIndex, uint16_t _modeIndex, RE_DisplayMode* _mode) { return SDL_GetDisplayMode(_displayIndex, _modeIndex, _mode); }

    inline uint16_t RE_GL_SetAttribute(RE_GLattr _attribute, int _value) { return SDL_GL_SetAttribute(_attribute, _value); }
    inline uint16_t RE_GL_GetAttribute(RE_GLattr _attribute, int* _value) { return SDL_GL_GetAttribute(_attribute, _value); }

}

#endif //  RE_SDL_GRAPHICS_HPP
