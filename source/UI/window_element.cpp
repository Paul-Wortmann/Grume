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

//------------------------------------------------------------ Delay Class ------------------------------------------------------------------------

delay_class::delay_class(void)
{
    delay_class::enabled = true;
    delay_class::ready   = false;
    delay_class::value   = 0;
    delay_class::maximum = 30;
};

void delay_class::process(void)
{
    if(delay_class::enabled)
    {
        delay_class::value++;
        if (delay_class::value >= delay_class::maximum)
        {
            delay_class::ready = true;
            delay_class::value = delay_class::maximum;
        }
    }
};

void delay_class::reset(void)
{
    delay_class::ready   = false;
    delay_class::value   = 0;
};

//------------------------------------------------------------ Location Class ------------------------------------------------------------------------

location_class::location_class(void)
{
    location_class::text        = "Not set";
    location_class::position.x  = 0.0f;
    location_class::position.y  = 0.0f;
    location_class::position.z  = 0.0f;
    location_class::size.x      = 0.0f;
    location_class::size.y      = 0.0f;
    location_class::size.z      = 0.0f;
}

location_class::~location_class(void)
{

}

//------------------------------------------------------------ Window element Class ------------------------------------------------------------------------

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
    window_element_class::tooltip.image_path             = "";
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
    window_element_class::quantity                       = 1;
    window_element_class::value                          = 0.0f;
    window_element_class::value_max                      = 0.0f;
    window_element_class::active                         = false;
    window_element_class::clicked                        = false;
    window_element_class::click_enabled                  = true;
    window_element_class::dragable                       = false;
    window_element_class::drag_active                    = false;
    window_element_class::drop_active                    = false;
    window_element_class::texture.angle                  = 0.0f;
    window_element_class::texture.base.image_path        = "";
    window_element_class::texture.normal.image_path      = "";
    window_element_class::texture.highlighted.image_path = "";
    window_element_class::texture.disabled.image_path    = "";
    window_element_class::zoom.enabled                   = true;
    window_element_class::zoom.maximum                   = 0.0f;
    window_element_class::zoom.value                     = 0.0f;
    window_element_class::zoom.speed                     = 0.0f;
};

window_element_class::~window_element_class(void)
{

};

void window_element_class::render(void)
{
    float zoom_value = (window_element_class::zoom.enabled) ? window_element_class::zoom.value : 0.0f;
    float temp_float = 0.0f;
    if (window_element_class::active)
    {
        switch (window_element_class::type)
        {
            case IMAGE:
                if (window_element_class::selected) window_element_class::texture.highlighted.image.draw(false,window_element_class::position.x,window_element_class::position.y,window_element_class::position.z,window_element_class::size.x+zoom_value,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                window_element_class::texture.normal.image.draw(false,window_element_class::position.x,window_element_class::position.y,window_element_class::position.z,window_element_class::size.x+zoom_value,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                if ((window_element_class::title.enabled) && (window_element_class::mouse_over))
                {
                    window_element_class::font.write(window_element_class::color.highlighted.r,window_element_class::color.highlighted.g,window_element_class::color.highlighted.b,window_element_class::color.highlighted.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                }
            break;
            case BUTTON:
                switch (window_element_class::state)
                {
                    case NORMAL:
                        window_element_class::texture.normal.image.draw(false,window_element_class::position.x,window_element_class::position.y,window_element_class::position.z,window_element_class::size.x+zoom_value,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.normal.r,window_element_class::color.normal.g,window_element_class::color.normal.b,window_element_class::color.normal.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    case HIGHLIGHTED:
                        window_element_class::texture.highlighted.image.draw(false,window_element_class::position.x,window_element_class::position.y,window_element_class::position.z,window_element_class::size.x+zoom_value,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.highlighted.r,window_element_class::color.highlighted.g,window_element_class::color.highlighted.b,window_element_class::color.highlighted.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    case DISABLED:
                        window_element_class::texture.disabled.image.draw(false,window_element_class::position.x,window_element_class::position.y,window_element_class::position.z,window_element_class::size.x+zoom_value,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.disabled.r,window_element_class::color.disabled.g,window_element_class::color.disabled.b,window_element_class::color.disabled.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    default:
                    break;
                }
            break;
            case TEXTLABEL:
                switch (window_element_class::state)
                {
                    case NORMAL:
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.normal.r,window_element_class::color.normal.g,window_element_class::color.normal.b,window_element_class::color.normal.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    case HIGHLIGHTED:
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.highlighted.r,window_element_class::color.highlighted.g,window_element_class::color.highlighted.b,window_element_class::color.highlighted.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    case DISABLED:
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.disabled.r,window_element_class::color.disabled.g,window_element_class::color.disabled.b,window_element_class::color.disabled.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    default:
                    break;
                }
            break;
            case SLIDER:
            break;
            case BAR:
                switch (window_element_class::state)
                {
                    case NORMAL:
                        temp_float = (window_element_class::value / window_element_class::value_max) * (window_element_class::size.x+zoom_value);
                        window_element_class::texture.normal.image.draw(false,window_element_class::position.x-((window_element_class::size.x/2)+zoom_value)+(temp_float/2.0f),window_element_class::position.y,window_element_class::position.z,temp_float,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.normal.r,window_element_class::color.normal.g,window_element_class::color.normal.b,window_element_class::color.normal.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    case HIGHLIGHTED:
                        temp_float = (window_element_class::value / window_element_class::value_max) * (window_element_class::size.x+zoom_value);
                        window_element_class::texture.highlighted.image.draw(false,window_element_class::position.x-((window_element_class::size.x/2)+zoom_value)+(temp_float/2.0f),window_element_class::position.y,window_element_class::position.z,temp_float,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.highlighted.r,window_element_class::color.highlighted.g,window_element_class::color.highlighted.b,window_element_class::color.highlighted.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
                    break;
                    case DISABLED:
                        temp_float = (window_element_class::value / window_element_class::value_max) * (window_element_class::size.x+zoom_value);
                        window_element_class::texture.disabled.image.draw(false,window_element_class::position.x-((window_element_class::size.x/2)+zoom_value)+(temp_float/2.0f),window_element_class::position.y,window_element_class::position.z,temp_float,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                        if (window_element_class::title.enabled) window_element_class::font.write(window_element_class::color.disabled.r,window_element_class::color.disabled.g,window_element_class::color.disabled.b,window_element_class::color.disabled.a,window_element_class::title.position.x,window_element_class::title.position.y,window_element_class::title.size.x,window_element_class::title.size.y,window_element_class::title.text);
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
                if (window_element_class::value > -1)
                {
                    window_element_class::texture.normal.image.draw(false,window_element_class::position.x,window_element_class::position.y,window_element_class::position.z,window_element_class::size.x+zoom_value,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
                }
                // Font write -> Item quantity
            break;
            default:
            break;
        }
    }
};

void window_element_class::render_item_if_dragged(void)
{
    float zoom_value = (window_element_class::zoom.enabled) ? window_element_class::zoom.value : 0.0f;
    if ((window_element_class::drag_active) && (window_element_class::value > -1))
    {
        window_element_class::texture.normal.image.draw(false,window_element_class::position.x,window_element_class::position.y,window_element_class::position.z,window_element_class::size.x+zoom_value,window_element_class::size.y+zoom_value,window_element_class::texture.angle);
    }
};

void window_element_class::render_tooltips(void)
{
    if ((window_element_class::active) && (window_element_class::tooltip.enabled))
    {
        if (window_element_class::mouse_over_element())
        {
            if (window_element_class::tooltip.image_enabled)
            {
                float temp_size_x = window_element_class::tooltip.image_size.x;
                float temp_size_y = window_element_class::tooltip.image_size.y;
                window_element_class::tooltip.image.draw(false,game.core.io.mouse_x+(temp_size_x*0.25f),game.core.io.mouse_y+(temp_size_y*0.25f),window_element_class::tooltip.position.z,temp_size_x,temp_size_y,window_element_class::texture.angle);
            }
            window_element_class::font.write(window_element_class::color.highlighted.r,window_element_class::color.highlighted.g,window_element_class::color.highlighted.b,window_element_class::color.highlighted.a,game.core.io.mouse_x,game.core.io.mouse_y,window_element_class::tooltip.size.x,window_element_class::tooltip.size.y,window_element_class::tooltip.text);
        }
    }
};

bool window_element_class::mouse_over_element(void)
{
    return(game.core.physics.point_in_quadrangle(window_element_class::position.x,window_element_class::size.x,window_element_class::position.y,window_element_class::size.y,game.core.io.mouse_x,game.core.io.mouse_y));
};

bool window_element_class::mouse_clicked_element(void)
{
    if ((game.core.io.mouse_button_left) || (game.core.io.mouse_button_left)) return(window_element_class::mouse_over_element());
    else return(false);
};

event_type  window_element_class::process(bool element_in_focus)
{
    float drag_delta_x = 0.0f;
    float drag_delta_y = 0.0f;
    bool  allow_drag   = window_element_class::dragable;
    window_element_class::clicked = false;
    window_element_class::mouse_delay.process();
    if ((window_element_class::event.id == EVENT_ELEMENT_MOUSE_RIGHT) || (window_element_class::event.id == EVENT_ELEMENT_MOUSE_LEFT)) window_element_class::event.id = EVENT_NONE;
    if (window_element_class::active)
    {
        if (window_element_class::state != DISABLED)
        {
            window_element_class::mouse_over = window_element_class::mouse_over_element();
            // ------------------------- Drop -------------------------
            if ((game.window_manager.element_drop_in_progress) || (window_element_class::drop_active))
            {
                window_element_class::event.id               = EVENT_NONE;
                window_element_class::drop_active            = false;
                game.window_manager.element_drop_in_progress = false;
            }
            // ------------------------- Drag -------------------------
            if (window_element_class::drag_active)
            {
                if (game.core.io.mouse_button_left)
                {
                    drag_delta_x = window_element_class::position.x;
                    drag_delta_y = window_element_class::position.y;
                    window_element_class::position.x = game.core.io.mouse_x + window_element_class::drag_offset_x;
                    window_element_class::position.y = game.core.io.mouse_y + window_element_class::drag_offset_y;
                    drag_delta_x = drag_delta_x - window_element_class::position.x;
                    drag_delta_y = drag_delta_y - window_element_class::position.y;
                    window_element_class::title.position.x     -= drag_delta_x;
                    window_element_class::title.position.y     -= drag_delta_y;
                }
                else
                {
                    bool allow_swap_elements = false;
                    int window_over  = game.window_manager.mouse_over_window();
                    int window_from  = window_element_class::window_UID;
                    int element_from = window_element_class::element_UID;
                    int element_over = 0;
                    if (window_over != MOUSE_OVER_MAP)
                    {
                        element_over = game.window_manager.mouse_over_element(window_over);
                        if (element_over != MOUSE_OVER_MAP)
                        {
                            game.core.log.file_write("Drag from - W - ",window_from," - E - ",element_from," Drag to - W - ",window_over," - E - ",element_over);
                            //swap
                            //if (swap()) element_swaped = true;
                            if ((window_from == INVENTORY_UID) && (window_over == INVENTORY_UID))
                            {
                                allow_swap_elements = true;
                            }
                        }
                    }
                    window_element_class::position.x = window_element_class::position_origional.x;
                    window_element_class::position.y = window_element_class::position_origional.y;
                    if (allow_swap_elements) swap_elements(window_from,element_from,window_over,element_over);
                    game.window_manager.element_drag_in_progress = false;
                    game.window_manager.drag_in_progress         = false;
                    window_element_class::drag_active            = false;
                    window_element_class::drop_active            = true;
                    game.window_manager.element_drop_in_progress = true;
                    window_element_class::event.id               = EVENT_ELEMENT_DRAG;

                window_element_class::event.id               = EVENT_NONE;
                window_element_class::drop_active            = false;
                game.window_manager.element_drop_in_progress = false;

                }
            }
            else
            {
                if ((window_element_class::dragable) && (element_in_focus) && (window_element_class::mouse_over) && (!game.window_manager.drag_in_progress))
                {
                    if ((game.core.io.mouse_button_left) && (allow_drag))// start drag
                    {
                        window_element_class::position_origional.x   = window_element_class::position.x;
                        window_element_class::position_origional.y   = window_element_class::position.y;
                        window_element_class::drag_offset_x          = window_element_class::position.x - game.core.io.mouse_x;
                        window_element_class::drag_offset_y          = window_element_class::position.y - game.core.io.mouse_y;
                        window_element_class::drag_active            = true;
                        game.window_manager.drag_in_progress         = true;
                        game.window_manager.element_drag_in_progress = true;
                    }
                }
            }
            if (window_element_class::mouse_over)
            {
                // ----------------- highlighting element ------------------------------
                if (element_in_focus)
                {
                    if ((window_element_class::state  != HIGHLIGHTED) && (window_element_class::sound.on_mouse_over.enabled)) window_element_class::sound.on_mouse_over.sound.play();
                    window_element_class::state        = HIGHLIGHTED;
                }
                else
                {
                    window_element_class::state        = NORMAL;
                }
                // ------------------------- clicked element -------------------------
                if ((!game.window_manager.drag_in_progress) && (element_in_focus))
                {
                    if (window_element_class::click_enabled)
                    {
                        if (window_element_class::mouse_clicked_element())
                        {
                            if((window_element_class::mouse_delay.ready) || (!window_element_class::mouse_delay.enabled))
                            {
                                if (game.core.io.mouse_button_right) window_element_class::event.id = EVENT_ELEMENT_MOUSE_RIGHT;
                                if (game.core.io.mouse_button_left)  window_element_class::event.id = EVENT_ELEMENT_MOUSE_LEFT;
                                if (window_element_class::sound.on_click.enabled) window_element_class::sound.on_click.sound.play();
                                window_element_class::clicked = true;
                                if(window_element_class::mouse_delay.enabled) window_element_class::mouse_delay.reset();
                            }
                        }
                    }
                }
            }
            else
            {
                window_element_class::state = NORMAL;
            }
        }
        if (window_element_class::state == HIGHLIGHTED)
        {
            window_element_class::zoom.value += window_element_class::zoom.speed;
            if (window_element_class::zoom.value > window_element_class::zoom.maximum) window_element_class::zoom.value = window_element_class::zoom.maximum;
        }
        if ((window_element_class::state != HIGHLIGHTED) && (window_element_class::zoom.value > 0.0f))
        {
            window_element_class::zoom.value -= window_element_class::zoom.speed;
            if (window_element_class::zoom.value < 0.0f) window_element_class::zoom.value = 0.0f;
        }
    }
    return(window_element_class::event);
};

void window_element_class::reload_textures(void)
{
    if (window_element_class::active)
    {
        if (window_element_class::texture.normal.image_path.length() > 3)      window_element_class::texture.normal.image.load_image     (window_element_class::texture.normal.image_path);
        if (window_element_class::texture.highlighted.image_path.length() > 3) window_element_class::texture.highlighted.image.load_image(window_element_class::texture.highlighted.image_path);
        if (window_element_class::texture.disabled.image_path.length() > 3)    window_element_class::texture.disabled.image.load_image   (window_element_class::texture.disabled.image_path);
        if (window_element_class::texture.base.image_path.length() > 3)        window_element_class::texture.base.image.load_image       (window_element_class::texture.base.image_path);
        if (window_element_class::tooltip.image_path.length() > 3)             window_element_class::tooltip.image.load_image            (window_element_class::tooltip.image_path);
    }
};

