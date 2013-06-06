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

#include "window.hpp"
#include "../game.hpp"

extern game_class        game;

//------------------------------------------------------------ Window Class ------------------------------------------------------------------------

window_class::window_class(void)
{
    window_class::UID                                = -1;
    window_class::enabled                            = false;
    window_class::active                             = false;
    window_class::set_behind                         = false;
    window_class::drag_enabled                       = true;
    window_class::event.id                           = 0;
    window_class::number_of_elements                 = 0;
    window_class::title.text                         = "Not set";
    window_class::title.size.x                       = 0.0f;
    window_class::title.size.y                       = 0.0f;
    window_class::title.size.z                       = 0.0f;
    window_class::title.position.x                   = 0.0f;
    window_class::title.position.y                   = 0.0f;
    window_class::title.position.z                   = 0.0f;
    window_class::title_bar.text                     = "";
    window_class::title_bar.size.x                   = 0.0f;
    window_class::title_bar.size.y                   = 0.0f;
    window_class::title_bar.size.z                   = 0.0f;
    window_class::title_bar.position.x               = 0.0f;
    window_class::title_bar.position.y               = 0.0f;
    window_class::title_bar.position.z               = 0.0f;
    window_class::position.x                         = 0.0f;
    window_class::position.y                         = 0.0f;
    window_class::position.z                         = 0.0f;
    window_class::size.x                             = 0.0f;
    window_class::size.y                             = 0.0f;
    window_class::size.z                             = 0.0f;
    window_class::title_color.r                      = 255;
    window_class::title_color.g                      = 255;
    window_class::title_color.b                      = 255;
    window_class::title_color.a                      = 255;
    window_class::color.normal.r                     = 255;
    window_class::color.normal.g                     = 255;
    window_class::color.normal.b                     = 255;
    window_class::color.normal.a                     = 255;
    window_class::color.highlighted.r                = 255;
    window_class::color.highlighted.g                = 255;
    window_class::color.highlighted.b                = 255;
    window_class::color.highlighted.a                = 255;
    window_class::color.disabled.r                   = 255;
    window_class::color.disabled.g                   = 255;
    window_class::color.disabled.b                   = 255;
    window_class::color.disabled.a                   = 255;
    window_class::mouse_delay.maximum                = 30;
    window_class::mouse_over_menu                    = false;
    window_class::mouse_over_title                   = false;
    window_class::drag_active                        = false;
    window_class::zoom.enabled                       = true;
    window_class::zoom.maximum                       = 0.01f;
    window_class::zoom.value                         = 0.0f;
    window_class::zoom.speed                         = 0.001f;
    for (int pos_number = 0; pos_number < MAX_CHOICE_SELECTIONS_PER_MENU; pos_number++)
    {
        window_class::choice_selection[pos_number].selected     = 0;
        window_class::choice_selection[pos_number].position     = 0;
        window_class::choice_selection[pos_number].position_max = 0;
        for (int data_pos_number = 0; data_pos_number < MAX_CHOICE_SELECTIONS_PER_MENU; data_pos_number++)
        {
            window_class::choice_selection[pos_number].data[data_pos_number].active        = false;
            window_class::choice_selection[pos_number].data[data_pos_number].value_string  = "";
            window_class::choice_selection[pos_number].data[data_pos_number].value_int     = 0;
        }
    }
};

window_class::~window_class(void)
{

};

void window_class::render(void)
{
    if(window_class::enabled)
    {
        // ------------------------- Render menu background and title -------------------------
        game.texture_manager.draw(window_class::texture.base,false,window_class::position.x,window_class::position.y,window_class::position.z,window_class::size.x,window_class::size.y);
        game.font_manager.write(window_class::font,window_class::title_color.r,window_class::title_color.g,window_class::title_color.b,window_class::title_color.a,window_class::title.position.x,window_class::title.position.y,window_class::title.size.x,window_class::title.size.y,window_class::title.text);
        // ------------------------- Render elements -------------------------
        if (window_class::number_of_elements > 0)
        {
            for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
            {
                if (window_class::element[element_number].active)
                {
                    float zoom_value = (window_class::element[element_number].zoom.enabled) ? window_class::element[element_number].zoom.value : 0.0f;
                    float temp_float = 0.0f;
                    if (window_class::element[element_number].active)
                    {
                        switch (window_class::element[element_number].type)
                        {
                            case IMAGE:
                                if (window_class::element[element_number].selected) game.texture_manager.draw(window_class::element[element_number].texture.highlighted,false,window_class::element[element_number].position.x,window_class::element[element_number].position.y,window_class::element[element_number].position.z,window_class::element[element_number].size.x+zoom_value,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                game.texture_manager.draw(window_class::element[element_number].texture.normal,false,window_class::element[element_number].position.x,window_class::element[element_number].position.y,window_class::element[element_number].position.z,window_class::element[element_number].size.x+zoom_value,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                if ((window_class::element[element_number].title.enabled) && (window_class::element[element_number].mouse_over))
                                {
                                    game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.highlighted.r,window_class::element[element_number].color.highlighted.g,window_class::element[element_number].color.highlighted.b,window_class::element[element_number].color.highlighted.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                }
                            break;
                            case BUTTON:
                                switch (window_class::element[element_number].state)
                                {
                                    case NORMAL:
                                        game.texture_manager.draw(window_class::element[element_number].texture.normal,false,window_class::element[element_number].position.x,window_class::element[element_number].position.y,window_class::element[element_number].position.z,window_class::element[element_number].size.x+zoom_value,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.normal.r,window_class::element[element_number].color.normal.g,window_class::element[element_number].color.normal.b,window_class::element[element_number].color.normal.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    case HIGHLIGHTED:
                                        game.texture_manager.draw(window_class::element[element_number].texture.highlighted,false,window_class::element[element_number].position.x,window_class::element[element_number].position.y,window_class::element[element_number].position.z,window_class::element[element_number].size.x+zoom_value,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.highlighted.r,window_class::element[element_number].color.highlighted.g,window_class::element[element_number].color.highlighted.b,window_class::element[element_number].color.highlighted.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    case DISABLED:
                                        game.texture_manager.draw(window_class::element[element_number].texture.disabled,false,window_class::element[element_number].position.x,window_class::element[element_number].position.y,window_class::element[element_number].position.z,window_class::element[element_number].size.x+zoom_value,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.disabled.r,window_class::element[element_number].color.disabled.g,window_class::element[element_number].color.disabled.b,window_class::element[element_number].color.disabled.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    default:
                                    break;
                                }
                            break;
                            case TEXTLABEL:
                                switch (window_class::element[element_number].state)
                                {
                                    case NORMAL:
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.normal.r,window_class::element[element_number].color.normal.g,window_class::element[element_number].color.normal.b,window_class::element[element_number].color.normal.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    case HIGHLIGHTED:
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.highlighted.r,window_class::element[element_number].color.highlighted.g,window_class::element[element_number].color.highlighted.b,window_class::element[element_number].color.highlighted.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    case DISABLED:
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.disabled.r,window_class::element[element_number].color.disabled.g,window_class::element[element_number].color.disabled.b,window_class::element[element_number].color.disabled.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    default:
                                    break;
                                }
                            break;
                            case SLIDER:
                            break;
                            case BAR:
                                switch (window_class::element[element_number].state)
                                {
                                    case NORMAL:
                                        temp_float = (window_class::element[element_number].value / window_class::element[element_number].value_max) * (window_class::element[element_number].size.x+zoom_value);
                                        game.texture_manager.draw(window_class::element[element_number].texture.normal,false,window_class::element[element_number].position.x-((window_class::element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),window_class::element[element_number].position.y,window_class::element[element_number].position.z,temp_float,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.normal.r,window_class::element[element_number].color.normal.g,window_class::element[element_number].color.normal.b,window_class::element[element_number].color.normal.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    case HIGHLIGHTED:
                                        temp_float = (window_class::element[element_number].value / window_class::element[element_number].value_max) * (window_class::element[element_number].size.x+zoom_value);
                                        game.texture_manager.draw(window_class::element[element_number].texture.highlighted,false,window_class::element[element_number].position.x-((window_class::element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),window_class::element[element_number].position.y,window_class::element[element_number].position.z,temp_float,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.highlighted.r,window_class::element[element_number].color.highlighted.g,window_class::element[element_number].color.highlighted.b,window_class::element[element_number].color.highlighted.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
                                    break;
                                    case DISABLED:
                                        temp_float = (window_class::element[element_number].value / window_class::element[element_number].value_max) * (window_class::element[element_number].size.x+zoom_value);
                                        game.texture_manager.draw(window_class::element[element_number].texture.disabled,false,window_class::element[element_number].position.x-((window_class::element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),window_class::element[element_number].position.y,window_class::element[element_number].position.z,temp_float,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                        if (window_class::element[element_number].title.enabled) game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.disabled.r,window_class::element[element_number].color.disabled.g,window_class::element[element_number].color.disabled.b,window_class::element[element_number].color.disabled.a,window_class::element[element_number].title.position.x,window_class::element[element_number].title.position.y,window_class::element[element_number].title.size.x,window_class::element[element_number].title.size.y,window_class::element[element_number].title.text);
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
                            case ITEM:
                                if (window_class::element[element_number].value > -1)
                                {
                                    game.texture_manager.draw(window_class::element[element_number].texture.normal,false,window_class::element[element_number].position.x,window_class::element[element_number].position.y,window_class::element[element_number].position.z,window_class::element[element_number].size.x+zoom_value,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                                }
                                // Font write -> Item quantity
                            break;
                            default:
                            break;
                        }
                    }
                }
            }
        }
        // ------------------------- Render element tool tips -------------------------
        if (window_class::number_of_elements > 0)
        {
            for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
            {
                if (window_class::element[element_number].active)
                {
                    if ((window_class::element[element_number].active) && (window_class::element[element_number].tooltip.enabled))
                    {
                        if (window_class::element[element_number].mouse_over)
                        {
                            if ((window_class::element[element_number].tooltip.enabled) && (window_class::element[element_number].tooltip.image_enabled))
                            {
                                float temp_size_x = window_class::element[element_number].tooltip.image_size.x;
                                float temp_size_y = window_class::element[element_number].tooltip.image_size.y;
                                game.texture_manager.draw(window_class::element[element_number].tooltip.image,false,game.core.io.mouse_x+(temp_size_x*0.25f),game.core.io.mouse_y+(temp_size_y*0.25f),window_class::element[element_number].tooltip.position.z,temp_size_x,temp_size_y,window_class::element[element_number].texture.angle);
                            }
                            game.font_manager.write(window_class::element[element_number].font,window_class::element[element_number].color.highlighted.r,window_class::element[element_number].color.highlighted.g,window_class::element[element_number].color.highlighted.b,window_class::element[element_number].color.highlighted.a,game.core.io.mouse_x,game.core.io.mouse_y,window_class::element[element_number].tooltip.size.x,window_class::element[element_number].tooltip.size.y,window_class::element[element_number].tooltip.text);
                        }
                    }
                }
            }
        }
    }
};

void window_class::render_draged_elements(void)
{
    if(window_class::enabled)
    {
        if (window_class::number_of_elements > 0)
        {
            for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
            {
                if (window_class::element[element_number].active)
                {
                    float zoom_value = (window_class::element[element_number].zoom.enabled) ? window_class::element[element_number].zoom.value : 0.0f;
                    if ((window_class::element[element_number].drag_active) && (window_class::element[element_number].value > -1))
                    {
                        game.texture_manager.draw(window_class::element[element_number].texture.normal,false,window_class::element[element_number].position.x,window_class::element[element_number].position.y,window_class::element[element_number].position.z,window_class::element[element_number].size.x+zoom_value,window_class::element[element_number].size.y+zoom_value,window_class::element[element_number].texture.angle);
                    }
                }
            }
        }
    }
}

bool  window_class::get_mouse_over_menu(void)
{
    return(game.core.physics.point_in_quadrangle(window_class::position.x,window_class::size.x,window_class::position.y,window_class::size.y,game.core.io.mouse_x,game.core.io.mouse_y));
};

bool  window_class::get_mouse_over_title(void)
{
    return(game.core.physics.point_in_quadrangle(window_class::title_bar.position.x,window_class::title_bar.size.x,window_class::title_bar.position.y,window_class::title_bar.size.y,game.core.io.mouse_x,game.core.io.mouse_y));
};

bool  window_class::mouse_click_title(void)
{
    if (game.core.io.mouse_button_left) return(window_class::get_mouse_over_title());
    else return(false);
};

void window_class::set_position(float x_pos, float y_pos)
{
    float move_delta_x                  = window_class::position.x;
    float move_delta_y                  = window_class::position.y;
    window_class::position.x            = x_pos;
    window_class::position.y            = y_pos;
    move_delta_x                        = move_delta_x - window_class::position.x;
    move_delta_y                        = move_delta_y - window_class::position.y;
    window_class::title.position.x     -= move_delta_x;
    window_class::title.position.y     -= move_delta_y;
    window_class::title_bar.position.x -= move_delta_x;
    window_class::title_bar.position.y -= move_delta_y;
    if(window_class::number_of_elements > 0)
    {
        for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
        {
            if (window_class::element[element_number].active)
            {
                window_class::element[element_number].position.x       -= move_delta_x;
                window_class::element[element_number].position.y       -= move_delta_y;
                window_class::element[element_number].title.position.x -= move_delta_x;
                window_class::element[element_number].title.position.y -= move_delta_y;
            }
        }
    }
};

event_type window_class::process(bool window_in_focus)
{
    float      drag_delta_x = 0.0f;
    float      drag_delta_y = 0.0f;
    event_type return_value;
    bool       return_mouse_over = false;
    bool       allow_drag        = true;
    return_value.id = EVENT_NONE;
    if (window_class::enabled)
    {
        // ------------------------- Process mouse delay -------------------------
        if (window_class::mouse_delay.enabled)
        {
            window_class::mouse_delay.value++;
            if (window_class::mouse_delay.value >= window_class::mouse_delay.maximum)
            {
                window_class::mouse_delay.ready = true;
                window_class::mouse_delay.value = window_class::mouse_delay.maximum;
            }
        }
        // ------------------------- Process elements -------------------------
        if ((window_class::number_of_elements > 0) && (!window_class::drag_active))
        {
            for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
            {
                if ((window_class::element[element_number].active) && ((return_value.id == EVENT_NONE) || (return_value.id == EVENT_ELEMENT_DRAG)))
                {
                    // ---------------------------------------------------------------------------------------
                    if (game.core.physics.point_in_quadrangle(window_class::element[element_number].position.x,window_class::element[element_number].size.x,window_class::element[element_number].position.y,window_class::element[element_number].size.y,game.core.io.mouse_x,game.core.io.mouse_y)) window_class::element[element_number].mouse_over = true;
                    else window_class::element[element_number].mouse_over = false;
                    float drag_delta_x = 0.0f;
                    float drag_delta_y = 0.0f;
                    bool  allow_drag   = window_class::element[element_number].dragable;
                    bool  allow_process = true;
                    window_class::element[element_number].clicked = false;
                    // ------------------------- Process mouse delay -------------------------
                    if (window_class::element[element_number].mouse_delay.enabled)
                    {
                        window_class::element[element_number].mouse_delay.value++;
                        if (window_class::element[element_number].mouse_delay.value >= window_class::element[element_number].mouse_delay.maximum)
                        {
                            window_class::element[element_number].mouse_delay.ready = true;
                            window_class::element[element_number].mouse_delay.value = window_class::element[element_number].mouse_delay.maximum;
                        }
                    }
                    // ------------------------- -------------------------
                    if ((window_class::element[element_number].event.id == EVENT_ELEMENT_MOUSE_RIGHT) || (window_class::element[element_number].event.id == EVENT_ELEMENT_MOUSE_LEFT)) window_class::element[element_number].event.id = EVENT_NONE;
                    if (!window_class::element[element_number].active) allow_process = false;
                    if ((window_class::element[element_number].type == ITEM) && (window_class::element[element_number].value < 0)) allow_process = false;
                    if (allow_process)
                    {
                        if (window_class::element[element_number].state != DISABLED)
                        {
                            // ------------------------- Drag n drop -------------------------
                            if (window_class::element[element_number].drag_active)
                            {
                                if (game.core.io.mouse_button_left)
                                {
                                    drag_delta_x = window_class::element[element_number].position.x;
                                    drag_delta_y = window_class::element[element_number].position.y;
                                    window_class::element[element_number].position.x = game.core.io.mouse_x + window_class::element[element_number].drag_offset_x;
                                    window_class::element[element_number].position.y = game.core.io.mouse_y + window_class::element[element_number].drag_offset_y;
                                    drag_delta_x = drag_delta_x - window_class::element[element_number].position.x;
                                    drag_delta_y = drag_delta_y - window_class::element[element_number].position.y;
                                    window_class::element[element_number].title.position.x     -= drag_delta_x;
                                    window_class::element[element_number].title.position.y     -= drag_delta_y;
                                }
                                else
                                {
                                    int window_over  = game.window_manager.mouse_over_window();
                                    int window_from  = window_class::element[element_number].window_UID;
                                    int element_from = window_class::element[element_number].element_UID;
                                    int element_over = 0;
                                    window_class::element[element_number].position.x = window_class::element[element_number].position_origional.x;
                                    window_class::element[element_number].position.y = window_class::element[element_number].position_origional.y;
                                    if (window_over != MOUSE_OVER_MAP)
                                    {
                                        element_over = game.window_manager.mouse_over_element(window_over);
                                        if (element_over != MOUSE_OVER_MAP)
                                        {
                                            //swap
                                            swap_elements(window_from,element_from,window_over,element_over);
                                        }
                                    }
                                    game.window_manager.element_drag_in_progress       = false;
                                    game.window_manager.drag_in_progress               = false;
                                    window_class::element[element_number].drag_active  = false;
                                    window_class::element[element_number].event.id     = EVENT_NONE;
                                }
                            }
                            else
                            {
                                if ((window_class::element[element_number].dragable) && (window_in_focus) && (window_class::element[element_number].mouse_over) && (!game.window_manager.drag_in_progress))
                                {
                                    if ((game.core.io.mouse_button_left) && (allow_drag))// start drag
                                    {
                                        window_class::element[element_number].position_origional.x   = window_class::element[element_number].position.x;
                                        window_class::element[element_number].position_origional.y   = window_class::element[element_number].position.y;
                                        window_class::element[element_number].drag_offset_x          = window_class::element[element_number].position.x - game.core.io.mouse_x;
                                        window_class::element[element_number].drag_offset_y          = window_class::element[element_number].position.y - game.core.io.mouse_y;
                                        window_class::element[element_number].drag_active            = true;
                                        game.window_manager.drag_in_progress         = true;
                                        game.window_manager.element_drag_in_progress = true;
                                    }
                                }
                            }
                            if (window_class::element[element_number].mouse_over)
                            {
                                // ----------------- highlighting element ------------------------------
                                if (window_in_focus)
                                {
                                    if ((window_class::element[element_number].state  != HIGHLIGHTED) && (window_class::element[element_number].sound.on_mouse_over.enabled)) game.sound_manager.play(window_class::element[element_number].sound.on_mouse_over.sound);
                                    window_class::element[element_number].state        = HIGHLIGHTED;
                                }
                                else
                                {
                                    window_class::element[element_number].state        = NORMAL;
                                }
                                // ------------------------- clicked element -------------------------
                                float dragged_by_x = 0.0f;
                                float dragged_by_y = 0.0f;
                                if (window_class::element[element_number].position_origional.x > window_class::element[element_number].position.x) dragged_by_x = window_class::element[element_number].position_origional.x - window_class::element[element_number].position.x;
                                else dragged_by_x = window_class::element[element_number].position.x - window_class::element[element_number].position_origional.x;
                                if (window_class::element[element_number].position_origional.y > window_class::element[element_number].position.y) dragged_by_y = window_class::element[element_number].position_origional.y - window_class::element[element_number].position.y;
                                else dragged_by_y = window_class::element[element_number].position.y - window_class::element[element_number].position_origional.y;
                                if (((dragged_by_x < 0.01f) && (dragged_by_y < 0.01f) && (window_in_focus)) || ((!game.window_manager.drag_in_progress) && (window_in_focus)))
                                {
                                    if (window_class::element[element_number].click_enabled)
                                    {
                                        if (((game.core.io.mouse_button_left) || (game.core.io.mouse_button_right)) && (window_class::element[element_number].mouse_over))
                                        {
                                            if((window_class::element[element_number].mouse_delay.ready) || (!window_class::element[element_number].mouse_delay.enabled))
                                            {
                                                if (game.core.io.mouse_button_right) window_class::element[element_number].event.id = EVENT_ELEMENT_MOUSE_RIGHT;
                                                if (game.core.io.mouse_button_left)  window_class::element[element_number].event.id = EVENT_ELEMENT_MOUSE_LEFT;
                                                if (window_class::element[element_number].sound.on_click.enabled) game.sound_manager.play(window_class::element[element_number].sound.on_click.sound);
                                                window_class::element[element_number].clicked = true;
                                                if (window_class::element[element_number].mouse_delay.enabled)
                                                {
                                                    window_class::element[element_number].mouse_delay.ready = false;
                                                    window_class::element[element_number].mouse_delay.value = 0;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                window_class::element[element_number].state = NORMAL;
                            }
                        }
                        if (window_class::element[element_number].state == HIGHLIGHTED)
                        {
                            window_class::element[element_number].zoom.value += window_class::element[element_number].zoom.speed;
                            if (window_class::element[element_number].zoom.value > window_class::element[element_number].zoom.maximum) window_class::element[element_number].zoom.value = window_class::element[element_number].zoom.maximum;
                        }
                        if ((window_class::element[element_number].state != HIGHLIGHTED) && (window_class::element[element_number].zoom.value > 0.0f))
                        {
                            window_class::element[element_number].zoom.value -= window_class::element[element_number].zoom.speed;
                            if (window_class::element[element_number].zoom.value < 0.0f) window_class::element[element_number].zoom.value = 0.0f;
                        }
                    }
                    else window_class::element[element_number].event.id = EVENT_NONE;
                    return_value.id = window_class::element[element_number].event.id;
                    // ------------------------------------------------------------------------------------------
                    if (return_value.id != EVENT_NONE)
                    {
                        switch (return_value.id)
                        {
                            case EVENT_ELEMENT_DRAG:
                                //game.window_manager.source.element = element_number;
                            break;
                            default:
                                return_value.id += (element_number * EVENT_BUTTON_MULTIPLIER);
                            break;
                        }
                        allow_drag       = false;
                    }
                    if (window_class::element[element_number].mouse_over)
                    {
                        allow_drag        = false;
                        return_mouse_over = true;
                    }
                }
            }
        }
        //if (window_in_focus)
        {
            // ------------------------- Drag -------------------------
            if (!game.window_manager.drag_in_progress) window_class::mouse_over_menu = window_class::get_mouse_over_menu();
            if ((!game.window_manager.drag_in_progress) && (window_class::get_mouse_over_title())) window_class::mouse_over_title = true;
            else window_class::mouse_over_title = false;
            if (window_class::drag_active)
            {
                if (game.core.io.mouse_button_left)
                {
                    drag_delta_x = window_class::position.x;
                    drag_delta_y = window_class::position.y;
                    window_class::position.x = game.core.io.mouse_x + window_class::drag_offset_x;
                    window_class::position.y = game.core.io.mouse_y + window_class::drag_offset_y;
                    drag_delta_x = drag_delta_x - window_class::position.x;
                    drag_delta_y = drag_delta_y - window_class::position.y;
                    window_class::title.position.x     -= drag_delta_x;
                    window_class::title.position.y     -= drag_delta_y;
                    window_class::title_bar.position.x -= drag_delta_x;
                    window_class::title_bar.position.y -= drag_delta_y;
                    if(window_class::number_of_elements > 0)
                    {
                        for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
                        {
                            if (window_class::element[element_number].active)
                            {
                                window_class::element[element_number].position.x       -= drag_delta_x;
                                window_class::element[element_number].position.y       -= drag_delta_y;
                                window_class::element[element_number].title.position.x -= drag_delta_x;
                                window_class::element[element_number].title.position.y -= drag_delta_y;
                            }
                        }
                    }
                }
                else
                {
                    window_class::drag_active             = false;
                    game.window_manager.drag_in_progress  = false;
                }
            }
            else
            {
                if ((window_class::drag_enabled) && (window_in_focus))
                {
                    if ((!game.window_manager.drag_in_progress) && (window_class::mouse_over_title) && (game.core.io.mouse_button_left) && (allow_drag))// start drag
                    {
                        window_class::drag_offset_x                = window_class::position.x - game.core.io.mouse_x;
                        window_class::drag_offset_y                = window_class::position.y - game.core.io.mouse_y;
                        window_class::drag_active                  = true;
                        game.window_manager.drag_in_progress       = true;
                        return_value.id                            = EVENT_WINDOW_STACK_SORT;
                    }
                }
                // user clicked on window, that is not title or an element.
                if ((game.core.io.mouse_button_left) && (return_value.id == EVENT_NONE) && (!window_class::active))
                {
                    return_value.id = EVENT_WINDOW_STACK_SORT;
                }
            }
            // ------------------------- X -------------------------
            if (!window_class::mouse_over_title) window_class::mouse_over_title = return_mouse_over;
        }
    }
    //if (return_value > 0) game.core.log.file_write("returning event -> ",return_value, " - from UID - ", window_class::UID);
    //if (return_value == EVENT_WINDOW_STACK_SORT) game.core.log.file_write("returning event -> ",return_value, " - from UID - ", window_class::UID);
    window_class::event = return_value;
    return (window_class::event);
};

