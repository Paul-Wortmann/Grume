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

#include "re_sdl_graphics.hpp"

namespace RoboEngine
{

    RE_Window* RE_CreateWindow(const std::string &_title, uint16_t _w, uint16_t _h, uint32_t _flags)
    {
        return RE_CreateWindow(_title.c_str(), RE_WINDOWPOS_CENTERED, RE_WINDOWPOS_CENTERED, _w, _h, _flags);
    }

    RE_Window* RE_CreateWindow(const std::string &_title, uint64_t _x, uint64_t _y, uint16_t _w, uint16_t _h, uint32_t _flags)
    {
        return SDL_CreateWindow(_title.c_str(), _x, _y, _w, _h, _flags);
    }

    void RE_DestroyWindow(RE_Window* _window)
    {
        SDL_DestroyWindow(_window);
    }

    RE_GLContext RE_GL_CreateContext(RE_Window *_window)
    {
        return SDL_GL_CreateContext(_window);
    }

    void RE_GL_SwapWindow(RE_Window *_window)
    {
        SDL_GL_SwapWindow(_window);
    }

    void RE_GL_DeleteContext(RE_GLContext _glcontext)
    {
        SDL_GL_DeleteContext(_glcontext);
    }

    uint16_t RE_GL_SetSwapInterval(uint16_t _interval)
    {
        return SDL_GL_SetSwapInterval(_interval);
    }

    uint16_t RE_GetNumVideoDisplays(void)
    {
        return SDL_GetNumVideoDisplays();
    }

    uint16_t RE_GetNumDisplayModes(uint16_t _displayIndex)
    {
        return SDL_GetNumDisplayModes(_displayIndex);
    }

    uint16_t RE_GetDisplayMode(uint16_t _displayIndex, uint16_t _modeIndex, RE_DisplayMode* _mode)
    {
        return SDL_GetDisplayMode(_displayIndex, _modeIndex, _mode);
    }

}
