/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "network_engine.hpp"

std::uint32_t cNetworkEngine::initialize(void)
{
    std::uint32_t return_value = EXIT_SUCCESS;

    // Initialize SDL ------------------------------------------
    if (SDL_Init(0) == 0)
    {
        // SDL version
        SDL_version compiled;
        SDL_version linked;

        SDL_VERSION(&compiled);
        SDL_GetVersion(&linked);

        gLogWrite(LOG_INFO, "SDL Compiled version: " + std::to_string(compiled.major) + "." + std::to_string(compiled.minor) + "." + std::to_string(compiled.patch), __FILE__, __LINE__, __FUNCTION__);
        gLogWrite(LOG_INFO, "SDL linked version: " + std::to_string(linked.major) + "." + std::to_string(linked.minor) + "." + std::to_string(linked.patch), __FILE__, __LINE__, __FUNCTION__);

        // Initialize SDL NET------------------------------------------
        if (SDLNet_Init() == 0)
        {
            // SDL Net version
            gLogWrite(LOG_INFO, "SDL Net linked version: " + std::to_string(SDL_NET_MAJOR_VERSION) + "." + std::to_string(SDL_NET_MINOR_VERSION) + "." + std::to_string(SDL_NET_PATCHLEVEL), __FILE__, __LINE__, __FUNCTION__);

            // setup

        }
        else
        {
            gLogWrite(LOG_ERROR, "SDL NET Initialization failed! " + std::string(SDLNet_GetError()), __FILE__, __LINE__, __FUNCTION__);
            SDLNet_Quit();
            SDL_Quit();
            return_value = EXIT_FAILURE;
        }
    }
    else
    {
        gLogWrite(LOG_ERROR, "SDL Initialization failed! " + std::string(SDL_GetError()), __FILE__, __LINE__, __FUNCTION__);
        SDL_Quit();
        return_value = EXIT_FAILURE;
    }

    // return
    return return_value;
}

void cNetworkEngine::terminate(void)
{
    SDLNet_Quit();
    SDL_Quit();
}

void cNetworkEngine::process(const std::int64_t &_dt)
{

}
