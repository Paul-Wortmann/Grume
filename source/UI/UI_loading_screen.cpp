/**
 * Copyright (C) 2011-2013 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "UI_loading_screen.hpp"
#include "../core/texture_manager.hpp"
#include "../game.hpp"

extern game_class game;

void UI_loading_screen_class::display(std::string file_name)
{
    texture_type* loading_screen_texture;
    loading_screen_texture = game.texture_manager.add_texture(file_name.c_str(),false);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(game.core.window_pointer);
    game.texture_manager.draw(loading_screen_texture,false,0.0f,0.0f,0.9f,2.0f,2.0f);
    SDL_GL_SwapWindow(game.core.window_pointer);
};
