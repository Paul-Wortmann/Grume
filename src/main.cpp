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
 * @license GPL
 * @date 2011-11-11
 */

#include <locale>
#include <SDL/SDL.h>
#include <SDL/SDL_main.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_net.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include "main.hpp"

const char App_Name[] = ("Frost And Flame V0.0 - www.physhexgames.co.nr");
//----------------------------------- Main -------------------------------------
int main(int argc, char *argv[])
{
    std::locale::global( std::locale( "" ) );
//----------------------------------- SDL Video --------------------------------
    putenv("SDL_VIDEO_WINDOW_POS");
    putenv("SDL_VIDEO_CENTERED=1");
    getenv("SDL_VIDEO_WINDOW_POS");
    getenv("SDL_VIDEO_CENTERED");
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
    SDL_SetVideoMode(800,600,32,SDL_OPENGL/* | SDL_NOFRAME/* | SDL_FULLSCREEN */);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
//----------------------------------- Main loop --------------------------------
    {
        ;
    }
//----------------------------------- Exit -------------------------------------
    SDL_Quit();
    return(0);
}

