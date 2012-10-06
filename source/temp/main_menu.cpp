/**
 * Copyright (C) 2011-2012 Paul Wortmann, PhysHex Games, www.physhexgames.co.nr
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

#include "main_menu.hpp"
#include "../game.hpp"

extern game_class         game;

//----------------------------------------------------------Main menu Class ------------------------------------------------------------------------

void setup_main_menu(int UID)
{
    int window_number = game.window_manager.get_window_number(UID);
    game.window_manager.window[window_number].active          = false;
    game.window_manager.window[window_number].form.mouse_over = false;
    game.window_manager.window[window_number].form.position.x = 0.0f;
    game.window_manager.window[window_number].form.position.y = 0.0f;
    game.window_manager.window[window_number].form.position.z = 0.0f;
    game.window_manager.window[window_number].form.size.x     = 0.6f;
    game.window_manager.window[window_number].form.size.y     = 1.0f;
    game.window_manager.window[window_number].form.image_path = "data/textures/UI/menu/background_02.png";
    game.resource.texture.number_loaded++;
    game.window_manager.window[window_number].form.image.load_image(game.window_manager.window[window_number].form.image_path,game.resource.texture.number_loaded);
};






