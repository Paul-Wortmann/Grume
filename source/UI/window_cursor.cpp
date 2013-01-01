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

#include "window_cursor.hpp"
#include "../game.hpp"

extern game_class game;

void window_cursor_class::reload_textures(void)
{
    if (window_cursor_class::normal_arrow.image_path.length() > 3)      window_cursor_class::normal_arrow.image.load_image     (window_cursor_class::normal_arrow.image_path);
};

void window_cursor_class::draw(void)
{
    window_cursor_class::pointer[window_cursor_class::active_cursor].image.draw(false,game.core.io.mouse_x+0.012f,game.core.io.mouse_y-0.018f,0.001f,0.04f,0.04f,345.0f);
};



