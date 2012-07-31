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
#include "../game.hpp"

extern game_class        game;

/*----------------------------------------*/
/*| delay_class                          |*/
/*----------------------------------------*/

delay_class::delay_class(void)
{
    ready   = false;
    value   = 0;
    maximum = 30;
};

void delay_class::process(void)
{
    delay_class::value++;
    if (delay_class::value >= delay_class::maximum)
    {
        delay_class::ready = true;
        delay_class::value = delay_class::maximum;
    }
};

void delay_class::reset(void)
{
    ready   = false;
    value   = 0;
};

/*----------------------------------------*/
/*| location_class                       |*/
/*----------------------------------------*/

location_class::location_class(void)
{
    location_class::text        = "Not set";
    location_class::position_x  = 0.0f;
    location_class::position_y  = 0.0f;
    location_class::position_z  = 0.0f;
    location_class::size_x      = 0.0f;
    location_class::size_y      = 0.0f;
    location_class::size_z      = 0.0f;
}

location_class::~location_class(void)
{

}

/*----------------------------------------*/
/*| menu_class                           |*/
/*----------------------------------------*/

menu_class::menu_class(void)
{
    menu_class::event                      = 0;
    menu_class::title.text                 = "Not set";
    menu_class::title.size_x               = 0.0f;
    menu_class::title.size_y               = 0.0f;
    menu_class::title.size_z               = 0.0f;
    menu_class::title.position_x           = 0.0f;
    menu_class::title.position_y           = 0.0f;
    menu_class::title.position_z           = 0.0f;
    menu_class::title_bar.text             = "";
    menu_class::title_bar.size_x           = 0.0f;
    menu_class::title_bar.size_y           = 0.0f;
    menu_class::title_bar.size_z           = 0.0f;
    menu_class::title_bar.position_x       = 0.0f;
    menu_class::title_bar.position_y       = 0.0f;
    menu_class::title_bar.position_z       = 0.0f;
    menu_class::position_x                 = 0.0f;
    menu_class::position_y                 = 0.0f;
    menu_class::position_z                 = 0.0f;
    menu_class::size_x                     = 0.0f;
    menu_class::size_y                     = 0.0f;
    menu_class::size_z                     = 0.0f;
    menu_class::title_color.r              = 255;
    menu_class::title_color.g              = 255;
    menu_class::title_color.b              = 255;
    menu_class::title_color.a              = 255;
    menu_class::color.normal.r             = 255;
    menu_class::color.normal.g             = 255;
    menu_class::color.normal.b             = 255;
    menu_class::color.normal.a             = 255;
    menu_class::color.highlighted.r        = 255;
    menu_class::color.highlighted.g        = 255;
    menu_class::color.highlighted.b        = 255;
    menu_class::color.highlighted.a        = 255;
    menu_class::color.disabled.r           = 255;
    menu_class::color.disabled.g           = 255;
    menu_class::color.disabled.b           = 255;
    menu_class::color.disabled.a           = 255;
    menu_class::texture_ID.base            = 0;
    menu_class::texture_ID.normal          = 0;
    menu_class::texture_ID.highlighted     = 0;
    menu_class::texture_ID.disabled        = 0;
    menu_class::mouse_over                 = false;
    menu_class::active                     = false;
    menu_class::drag_active                = false;
    menu_class::zoom.enabled               = true;
    menu_class::zoom.maximum               = 0.01f;
    menu_class::zoom.value                 = 0.0f;
    menu_class::zoom.speed                 = 0.001f;
    for (int pos_number = 0; pos_number < MAX_CHOICE_SELECTIONS_PER_MENU; pos_number++)
    {
        menu_class::choice_selection[pos_number].selected     = 0;
        menu_class::choice_selection[pos_number].position     = 0;
        menu_class::choice_selection[pos_number].position_max = 0;
        for (int data_pos_number = 0; data_pos_number < MAX_CHOICE_SELECTIONS_PER_MENU; data_pos_number++)
        {
            menu_class::choice_selection[pos_number].data[data_pos_number].active        = false;
            menu_class::choice_selection[pos_number].data[data_pos_number].value         = 0;
            menu_class::choice_selection[pos_number].data[data_pos_number].value_string  = "";
        }
    }
};

menu_class::~menu_class(void)
{

};

void menu_class::render(void)
{
    // ------------------------- Render menu background and title -------------------------
    game.resource.texture.render(false,menu_class::texture_ID.base,menu_class::position_x,menu_class::position_y,menu_class::position_z,menu_class::size_x,menu_class::size_y);
    game.resource.font.font_1.Write(menu_class::title_color.r,menu_class::title_color.g,menu_class::title_color.b,menu_class::title_color.a,menu_class::title.position_x,menu_class::title.position_y,menu_class::title.size_x,menu_class::title.size_y,menu_class::title.text);
    // ------------------------- Render elements -------------------------
    for (int element_number = 0; element_number < MAX_ELEMENTS; element_number++)
    {
        if (menu_class::element[element_number].active)
        {
            menu_class::element[element_number].render();
        }
    }
};

bool  menu_class::mouse_over_title(void)
{
    return(game.core.physics.point_in_quadrangle(menu_class::title_bar.position_x,menu_class::title_bar.size_x,menu_class::title_bar.position_y,menu_class::title_bar.size_y,game.core.io.mouse_x,game.core.io.mouse_y));
};

bool  menu_class::mouse_click_title(void)
{
    if (game.core.io.mouse_button_left) return(menu_class::mouse_over_title());
    else return(false);
};

void menu_class::set_position(float x_pos, float y_pos)
{
    float move_delta_x                = menu_class::position_x;
    float move_delta_y                = menu_class::position_y;
    menu_class::position_x            = x_pos;
    menu_class::position_y            = y_pos;
    move_delta_x                      = move_delta_x - menu_class::position_x;
    move_delta_y                      = move_delta_y - menu_class::position_y;
    menu_class::title.position_x     -= move_delta_x;
    menu_class::title.position_y     -= move_delta_y;
    menu_class::title_bar.position_x -= move_delta_x;
    menu_class::title_bar.position_y -= move_delta_y;
    for (int element_number = 0; element_number < MAX_ELEMENTS; element_number++)
    {
        if (menu_class::element[element_number].active)
        {
            menu_class::element[element_number].position_x       -= move_delta_x;
            menu_class::element[element_number].position_y       -= move_delta_y;
            menu_class::element[element_number].title.position_x -= move_delta_x;
            menu_class::element[element_number].title.position_y -= move_delta_y;
        }
    }
};

int menu_class::process(void)
{
    float drag_delta_x = 0.0f;
    float drag_delta_y = 0.0f;
    int   return_value = 0;
    bool  return_mouse_over = false;
    bool  allow_drag        = true;
    bool  allow_click       = true;
    menu_class::mouse_delay.process();
    // ------------------------- Process elements -------------------------
    for (int element_number = 0; element_number < MAX_ELEMENTS; element_number++)
    {
        if ((menu_class::element[element_number].type == BUTTON) && (!menu_class::mouse_delay.ready)) allow_click = false;
        else allow_click = true;
        if (menu_class::element[element_number].mouse_delay > 0)
        {
            if (menu_class::mouse_delay.value > menu_class::element[element_number].mouse_delay) allow_click = true;
            else  allow_click = false;
        }
        if ((menu_class::element[element_number].active) && (return_value == 0) && (allow_click))
        {
            return_value = menu_class::element[element_number].process();
            if (return_value != 0)
            {
                allow_drag   = false;
                return_value = element_number + 1;
            }
            if (menu_class::element[element_number].mouse_over)
            {
                allow_drag        = false;
                return_mouse_over = true;
            }
        }
    }
    // ------------------------- Drag -------------------------
    if ((!game.UI.drag_in_progress) && (menu_class::mouse_over_title())) menu_class::mouse_over = true;
    else menu_class::mouse_over = false;
    if (menu_class::drag_active)
    {
        if (game.core.io.mouse_button_left)
        {
            drag_delta_x = menu_class::position_x;
            drag_delta_y = menu_class::position_y;
            menu_class::position_x = game.core.io.mouse_x + menu_class::drag_offset_x;
            menu_class::position_y = game.core.io.mouse_y + menu_class::drag_offset_y;
            drag_delta_x = drag_delta_x - menu_class::position_x;
            drag_delta_y = drag_delta_y - menu_class::position_y;
            menu_class::title.position_x     -= drag_delta_x;
            menu_class::title.position_y     -= drag_delta_y;
            menu_class::title_bar.position_x -= drag_delta_x;
            menu_class::title_bar.position_y -= drag_delta_y;
            for (int element_number = 0; element_number < MAX_ELEMENTS; element_number++)
            {
                if (menu_class::element[element_number].active)
                {
                    menu_class::element[element_number].position_x       -= drag_delta_x;
                    menu_class::element[element_number].position_y       -= drag_delta_y;
                    menu_class::element[element_number].title.position_x -= drag_delta_x;
                    menu_class::element[element_number].title.position_y -= drag_delta_y;
                }
            }
        }
        else
        {
            menu_class::drag_active        = false;
            game.UI.drag_in_progress       = false;
        }
    }
    else
    {
        if ((!game.UI.drag_in_progress) && (menu_class::mouse_over) && (game.core.io.mouse_button_left) && (allow_drag))// start drag
        {
            game.UI.active_window_list.add_to_list(MAIN_MENU_WINDOW);
            menu_class::drag_active        = true;
            game.UI.drag_in_progress       = true;
            menu_class::drag_offset_x      = menu_class::position_x - game.core.io.mouse_x;
            menu_class::drag_offset_y      = menu_class::position_y - game.core.io.mouse_y;
        }
    }
    // ------------------------- X -------------------------
    if (!menu_class::mouse_over) menu_class::mouse_over = return_mouse_over;
    return(return_value);
};

/*----------------------------------------*/
/*| Element_class                        |*/
/*----------------------------------------*/

menu_element_class::menu_element_class(void)
{
    menu_element_class::mouse_delay            = -1;
    menu_element_class::title.text             = "not set";
    menu_element_class::title.position_x       = 0.0f;
    menu_element_class::title.position_y       = 0.0f;
    menu_element_class::title.position_z       = 0.0f;
    menu_element_class::title.size_x           = 0.0f;
    menu_element_class::title.size_y           = 0.0f;
    menu_element_class::title.size_z           = 0.0f;
    menu_element_class::tooltip.text           = "not set";
    menu_element_class::tooltip.position_x     = 0.0f;
    menu_element_class::tooltip.position_y     = 0.0f;
    menu_element_class::tooltip.position_z     = 0.0f;
    menu_element_class::tooltip.size_x         = 0.0f;
    menu_element_class::tooltip.size_y         = 0.0f;
    menu_element_class::tooltip.size_z         = 0.0f;
    menu_element_class::color.normal.r         = 0;
    menu_element_class::color.normal.g         = 0;
    menu_element_class::color.normal.b         = 0;
    menu_element_class::color.normal.a         = 0;
    menu_element_class::color.highlighted.r    = 0;
    menu_element_class::color.highlighted.g    = 0;
    menu_element_class::color.highlighted.b    = 0;
    menu_element_class::color.highlighted.a    = 0;
    menu_element_class::color.disabled.r       = 0;
    menu_element_class::color.disabled.g       = 0;
    menu_element_class::color.disabled.b       = 0;
    menu_element_class::color.disabled.a       = 0;
    menu_element_class::event                  = 0;
    menu_element_class::state                  = NORMAL;
    menu_element_class::selected               = false;
    menu_element_class::type                   = BUTTON;
    menu_element_class::value                  = 0.0f;
    menu_element_class::value_max              = 0.0f;
    menu_element_class::position_x             = 0.0f;
    menu_element_class::position_y             = 0.0f;
    menu_element_class::position_z             = 0.0f;
    menu_element_class::size_x                 = 0.0f;
    menu_element_class::size_y                 = 0.0f;
    menu_element_class::size_z                 = 0.0f;
    menu_element_class::mouse_over             = false;
    menu_element_class::active                 = false;
    menu_element_class::clicked                = false;
    menu_element_class::texture_ID.base        = 0;
    menu_element_class::texture_ID.normal      = 0;
    menu_element_class::texture_ID.highlighted = 0;
    menu_element_class::texture_ID.disabled    = 0;
    menu_element_class::zoom.enabled           = true;
    menu_element_class::zoom.maximum           = 0.0f;
    menu_element_class::zoom.value             = 0.0f;
    menu_element_class::zoom.speed             = 0.0f;
};

menu_element_class::~menu_element_class(void)
{

};

void menu_element_class::render(void)
{
    float zoom_value = 0.0f;
    if (menu_element_class::zoom.enabled) zoom_value = menu_element_class::zoom.value;
    else zoom_value = 0.0f;
    float temp_float = 0.0f;
    if (menu_element_class::active)
    {
        switch (menu_element_class::type)
        {
            case BUTTON:
                switch (menu_element_class::state)
                {
                    case NORMAL:
                        game.resource.texture.render(false,menu_element_class::texture_ID.normal,menu_element_class::position_x,menu_element_class::position_y,menu_element_class::position_z,menu_element_class::size_x+zoom_value,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.normal.r,menu_element_class::color.normal.g,menu_element_class::color.normal.b,menu_element_class::color.normal.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    case HIGHLIGHTED:
                        game.resource.texture.render(false,menu_element_class::texture_ID.highlighted,menu_element_class::position_x,menu_element_class::position_y,menu_element_class::position_z,menu_element_class::size_x+zoom_value,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.highlighted.r,menu_element_class::color.highlighted.g,menu_element_class::color.highlighted.b,menu_element_class::color.highlighted.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    case DISABLED:
                        game.resource.texture.render(false,menu_element_class::texture_ID.disabled,menu_element_class::position_x,menu_element_class::position_y,menu_element_class::position_z,menu_element_class::size_x+zoom_value,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.disabled.r,menu_element_class::color.disabled.g,menu_element_class::color.disabled.b,menu_element_class::color.disabled.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    default:
                    break;
                }
            break;
            case TEXTLABEL:
                switch (menu_element_class::state)
                {
                    case NORMAL:
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.normal.r,menu_element_class::color.normal.g,menu_element_class::color.normal.b,menu_element_class::color.normal.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    case HIGHLIGHTED:
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.highlighted.r,menu_element_class::color.highlighted.g,menu_element_class::color.highlighted.b,menu_element_class::color.highlighted.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    case DISABLED:
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.disabled.r,menu_element_class::color.disabled.g,menu_element_class::color.disabled.b,menu_element_class::color.disabled.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    default:
                    break;
                }
            break;
            case IMAGE:
                if (menu_element_class::selected) game.resource.texture.render(false,menu_element_class::texture_ID.highlighted,menu_element_class::position_x,menu_element_class::position_y,menu_element_class::position_z,menu_element_class::size_x+zoom_value,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                game.resource.texture.render(false,menu_element_class::texture_ID.normal,menu_element_class::position_x,menu_element_class::position_y,menu_element_class::position_z,menu_element_class::size_x+zoom_value,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                if (menu_element_class::mouse_over)
                {
                    if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.highlighted.r,menu_element_class::color.highlighted.g,menu_element_class::color.highlighted.b,menu_element_class::color.highlighted.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                }
            break;
            case SLIDER:
            break;
            case BAR:
                switch (menu_element_class::state)
                {
                    case NORMAL:
                        temp_float = (menu_element_class::value / menu_element_class::value_max) * (menu_element_class::size_x+zoom_value);
                        game.resource.texture.render(false,menu_element_class::texture_ID.normal,menu_element_class::position_x-((menu_element_class::size_x/2)+zoom_value)+(temp_float/2.0f),menu_element_class::position_y,menu_element_class::position_z,temp_float,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.normal.r,menu_element_class::color.normal.g,menu_element_class::color.normal.b,menu_element_class::color.normal.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    case HIGHLIGHTED:
                        temp_float = (menu_element_class::value / menu_element_class::value_max) * (menu_element_class::size_x+zoom_value);
                        game.resource.texture.render(false,menu_element_class::texture_ID.highlighted,menu_element_class::position_x-((menu_element_class::size_x/2)+zoom_value)+(temp_float/2.0f),menu_element_class::position_y,menu_element_class::position_z,temp_float,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.highlighted.r,menu_element_class::color.highlighted.g,menu_element_class::color.highlighted.b,menu_element_class::color.highlighted.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    case DISABLED:
                        temp_float = (menu_element_class::value / menu_element_class::value_max) * (menu_element_class::size_x+zoom_value);
                        game.resource.texture.render(false,menu_element_class::texture_ID.disabled,menu_element_class::position_x-((menu_element_class::size_x/2)+zoom_value)+(temp_float/2.0f),menu_element_class::position_y,menu_element_class::position_z,temp_float,menu_element_class::size_y+zoom_value,menu_element_class::texture_ID.angle);
                        if (menu_element_class::title.text.length() > 0) game.resource.font.font_1.Write(menu_element_class::color.disabled.r,menu_element_class::color.disabled.g,menu_element_class::color.disabled.b,menu_element_class::color.disabled.a,menu_element_class::title.position_x,menu_element_class::title.position_y,menu_element_class::title.size_x,menu_element_class::title.size_y,menu_element_class::title.text);
                    break;
                    default:
                    break;
                }
            break;
            case TOGGLE:
            break;
            case CHECKBOX:
            break;
            case DROPDOWN:
            break;
            case SELECTION:
            break;
            default:
            break;
        }
    }
};

bool menu_element_class::mouse_over_element(void)
{
    return(game.core.physics.point_in_quadrangle(menu_element_class::position_x,menu_element_class::size_x,menu_element_class::position_y,menu_element_class::size_y,game.core.io.mouse_x,game.core.io.mouse_y));
};

bool menu_element_class::mouse_clicked_element(void)
{
    if (game.core.io.mouse_button_left) return(menu_element_class::mouse_over_element());
    else return(false);
};

int  menu_element_class::process(void)
{
    if ((!game.UI.drag_in_progress) && (menu_element_class::active))
    {
        if (menu_element_class::state != DISABLED)
        {
            if (menu_element_class::mouse_over_element())
            {
                menu_element_class::mouse_over   = true;
                menu_element_class::state        = HIGHLIGHTED;
                if (menu_element_class::mouse_clicked_element()) menu_element_class::clicked = true;
                else menu_element_class::clicked = false;
            }
            else
            {
                menu_element_class::mouse_over = false;
                menu_element_class::state      = NORMAL;
                menu_element_class::clicked    = false;
            }
        }
        if (menu_element_class::state == HIGHLIGHTED)
        {
            menu_element_class::zoom.value += menu_element_class::zoom.speed;
            if (menu_element_class::zoom.value > menu_element_class::zoom.maximum) menu_element_class::zoom.value = menu_element_class::zoom.maximum;
        }
        if ((menu_element_class::state != HIGHLIGHTED) && (menu_element_class::zoom.value > 0.0f))
        {
            menu_element_class::zoom.value -= menu_element_class::zoom.speed;
            if (menu_element_class::zoom.value < 0.0f) menu_element_class::zoom.value = 0.0f;
        }
        if (menu_element_class::clicked)
        {
            menu_element_class::event   = 1;
            menu_element_class::clicked = false;
        }
        else
        {
            menu_element_class::event   = 0;
        }
    }
    return(menu_element_class::event);
};

