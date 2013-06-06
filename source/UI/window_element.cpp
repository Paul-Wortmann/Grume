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

#include "window_element.hpp"
#include "../game.hpp"

extern game_class        game;

//------------------------------------------------------------ Window element Class ------------------------------------------------------------------------
/*
window_element_class::window_element_class(void)
{
    window_element_class::window_UID                     = 0;
    window_element_class::element_UID                    = 0;
    window_element_class::mouse_over                     = false;
    window_element_class::mouse_delay.ready              = false;
    window_element_class::mouse_delay.value              = 0;
    window_element_class::mouse_delay.maximum            = 0;
    window_element_class::mouse_delay.enabled            = true;
    window_element_class::size.x                         = 0.0f;
    window_element_class::size.y                         = 0.0f;
    window_element_class::size.z                         = 0.0f;
    window_element_class::position.x                     = 0.0f;
    window_element_class::position.y                     = 0.0f;
    window_element_class::position.z                     = 0.0f;
    window_element_class::title.enabled                  = false;
    window_element_class::title.text                     = "";
    window_element_class::title.position.x               = 0.0f;
    window_element_class::title.position.y               = 0.0f;
    window_element_class::title.position.z               = 0.0f;
    window_element_class::title.size.x                   = 0.0f;
    window_element_class::title.size.y                   = 0.0f;
    window_element_class::title.size.z                   = 0.0f;
    window_element_class::tooltip.enabled                = false;
    window_element_class::tooltip.text                   = "";
    window_element_class::tooltip.position.x             = 0.0f;
    window_element_class::tooltip.position.y             = 0.0f;
    window_element_class::tooltip.position.z             = 0.0f;
    window_element_class::tooltip.size.x                 = 0.0f;
    window_element_class::tooltip.size.y                 = 0.0f;
    window_element_class::tooltip.size.z                 = 0.0f;
    window_element_class::tooltip.image_enabled          = false;
    window_element_class::tooltip.image_size.x           = 0.0f;
    window_element_class::tooltip.image_size.y           = 0.0f;
    window_element_class::tooltip.image_size.z           = 0.0f;
    window_element_class::color.normal.r                 = 0;
    window_element_class::color.normal.g                 = 0;
    window_element_class::color.normal.b                 = 0;
    window_element_class::color.normal.a                 = 0;
    window_element_class::color.highlighted.r            = 0;
    window_element_class::color.highlighted.g            = 0;
    window_element_class::color.highlighted.b            = 0;
    window_element_class::color.highlighted.a            = 0;
    window_element_class::color.disabled.r               = 0;
    window_element_class::color.disabled.g               = 0;
    window_element_class::color.disabled.b               = 0;
    window_element_class::color.disabled.a               = 0;
    window_element_class::event.id                       = 0;
    window_element_class::state                          = NORMAL;
    window_element_class::selected                       = false;
    window_element_class::type                           = BUTTON;
    window_element_class::sub_type                       = ITEM_NONE;
    window_element_class::quantity                       = 1;
    window_element_class::value                          = 0.0f;
    window_element_class::value_max                      = 0.0f;
    window_element_class::active                         = false;
    window_element_class::clicked                        = false;
    window_element_class::click_enabled                  = true;
    window_element_class::dragable                       = false;
    window_element_class::drag_active                    = false;
    window_element_class::texture.angle                  = 0.0f;
    window_element_class::zoom.enabled                   = true;
    window_element_class::zoom.maximum                   = 0.0f;
    window_element_class::zoom.value                     = 0.0f;
    window_element_class::zoom.speed                     = 0.0f;
};

window_element_class::~window_element_class(void)
{

};




bool window_element_class::mouse_over_element(void)
{
    return(game.core.physics.point_in_quadrangle(window_element_class::position.x,window_element_class::size.x,window_element_class::position.y,window_element_class::size.y,game.core.io.mouse_x,game.core.io.mouse_y));
};

bool window_element_class::mouse_clicked_element(void)
{
    if ((game.core.io.mouse_button_left) || (game.core.io.mouse_button_right)) return(window_element_class::mouse_over_element());
    else return(false);
};


*/
