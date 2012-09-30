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

#include "window.hpp"

//------------------------------------------------------------ Window Class ------------------------------------------------------------------------

window_class::window_class(void)
{
    window_class::UID           = -1;
    window_class::active        = false;
    window_class::mouse_over    = false;
    window_class::size.x        = 0.0f;
    window_class::size.y        = 0.0f;
    window_class::size.z        = 0.0f;
    window_class::position.x    = 0.0f;
    window_class::position.y    = 0.0f;
    window_class::position.z    = 0.0f;
}

window_class::~window_class(void)
{
}

void window_class::process(void)
{
    ;
}
