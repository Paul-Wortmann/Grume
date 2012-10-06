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
}

window_class::~window_class(void)
{
}

void window_class::process(void)
{
    ;
}

void window_class::render(void)
{
    if (window_class::form.image.frame != NULL) window_class::form.image.draw(false,window_class::form.position.x,window_class::form.position.y,window_class::form.position.z,window_class::form.size.x,window_class::form.size.y);
    //render elements here....
}
