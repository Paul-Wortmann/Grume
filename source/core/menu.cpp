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

#include "menu.hpp"

/*----------------------------------------*/
/*| menu_class                           |*/
/*----------------------------------------*/

menu_class::menu_class(void)
{
    menu_class::event                  = 0;
    menu_class::title                  = " Not set";
    menu_class::possition_x            = 0.0f;
    menu_class::possition_y            = 0.0f;
    menu_class::possition_z            = 0.0f;
    menu_class::size_x                 = 0.0f;
    menu_class::size_y                 = 0.0f;
    menu_class::size_z                 = 0.0f;
    menu_class::color_normal_r         = 255;
    menu_class::color_normal_g         = 255;
    menu_class::color_normal_b         = 255;
    menu_class::color_normal_a         = 255;
    menu_class::color_highlighted_r    = 255;
    menu_class::color_highlighted_g    = 255;
    menu_class::color_highlighted_b    = 255;
    menu_class::color_highlighted_a    = 255;
    menu_class::color_disabled_r       = 255;
    menu_class::color_disabled_g       = 255;
    menu_class::color_disabled_b       = 255;
    menu_class::color_disabled_a       = 255;
    menu_class::texture_ID             = 0;
    menu_class::texture_ID_normal      = 0;
    menu_class::texture_ID_highlighted = 0;
    menu_class::texture_ID_disabled    = 0;
    menu_class::mouse_over             = false;
    menu_class::active                 = false;
    menu_class::drag_active            = false;
};

menu_class::~menu_class(void)
{

};

void menu_class::render(void)
{

};

void menu_class::process(void)
{
    for (int element_number = 0; element_number < MAX_ELEMENTS; element_number++)
    {
        if (menu_class::element[element_number].active)
        {
            menu_class::element[element_number].process();
            if (menu_class::element[element_number].event == 65535) menu_class::event = menu_class::element[element_number].event;
        }
    }
};

/*----------------------------------------*/
/*| Element_class                        |*/
/*----------------------------------------*/

menu_element_class::menu_element_class(void)
{

};

menu_element_class::~menu_element_class(void)
{

};

void menu_element_class::render(void)
{

};

int  menu_element_class::process(void)
{
    if (menu_element_class::clicked)
    {
        if (menu_element_class::type == CLOSE) menu_element_class::event = 65535;
    }
    return(menu_element_class::event);
};

