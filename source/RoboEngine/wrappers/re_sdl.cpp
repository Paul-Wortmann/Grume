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

#include "re_sdl.hpp"

namespace RoboEngine
{

    int RE_Init(uint32_t _flags)
    {
        SDL_Init(_flags);
        return 0;
    }

    void RE_SetMainReady(void)
    {
        SDL_SetMainReady();
    }

    void RE_Quit(void)
    {
        SDL_Quit();
    }

    int RE_InitSubSystem(uint32_t _flags)
    {
        return SDL_InitSubSystem(_flags);
    }

    void RE_QuitSubSystem(uint32_t _flags)
    {
        SDL_QuitSubSystem(_flags);
    }

    uint32_t RE_WasInit(uint32_t _flags)
    {
        return SDL_WasInit(_flags);
    }

    uint16_t RE_GL_SetAttribute(RE_GLattr _attribute, int _value)
    {
        return SDL_GL_SetAttribute(_attribute, _value);
    }

}
