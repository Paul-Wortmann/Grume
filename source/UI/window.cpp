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
    window_class::drag_enabled                       = true;
    window_class::event                              = 0;
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
    window_class::texture.base.image_path            = "";
    window_class::texture.normal.image_path          = "";
    window_class::texture.highlighted.image_path     = "";
    window_class::texture.disabled.image_path        = "";
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
        window_class::texture.base.image.draw(false,window_class::position.x,window_class::position.y,window_class::position.z,window_class::size.x,window_class::size.y);
        window_class::font.write(window_class::title_color.r,window_class::title_color.g,window_class::title_color.b,window_class::title_color.a,window_class::title.position.x,window_class::title.position.y,window_class::title.size.x,window_class::title.size.y,window_class::title.text);
        // ------------------------- Render elements -------------------------
        if (window_class::number_of_elements > 0)
        {
            for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
            {
                if (window_class::element[element_number].active)
                {
                    window_class::element[element_number].render();
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
                    window_class::element[element_number].render_tooltips();
                }
            }
        }
    }
};

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

int window_class::process(void)
{
    float drag_delta_x = 0.0f;
    float drag_delta_y = 0.0f;
    int   return_value = 0;
    bool  return_mouse_over = false;
    bool  allow_drag        = true;
    if(window_class::enabled)
    {
        window_class::mouse_delay.process();
        if (!game.window_manager.drag_in_progress) window_class::mouse_over_menu = window_class::get_mouse_over_menu();
        //else window_class::mouse_over_menu = false;
        if (window_class::mouse_over_menu)
        {
            // ------------------------- Process elements -------------------------
            if (window_class::number_of_elements > 0)
            {
                for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
                {
                    if ((window_class::element[element_number].active) && (return_value == 0))
                    {
                        window_class::element[element_number].mouse_delay.process();
                        return_value = window_class::element[element_number].process();
                        if (return_value > 0) return_value += (element_number * 100);
                        if (return_value != 0) allow_drag   = false;
                        if (window_class::element[element_number].mouse_over)
                        {
                            allow_drag        = false;
                            return_mouse_over = true;
                        }
                    }
                }
            }
            // ------------------------- Drag -------------------------
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
                if (window_class::drag_enabled)
                {
                    if ((!game.window_manager.drag_in_progress) && (window_class::mouse_over_title) && (game.core.io.mouse_button_left) && (allow_drag))// start drag
                    {
                        window_class::drag_offset_x                = window_class::position.x - game.core.io.mouse_x;
                        window_class::drag_offset_y                = window_class::position.y - game.core.io.mouse_y;
                        window_class::drag_active                  = true;
                        game.window_manager.drag_in_progress       = true;
                        game.window_manager.event                  = 65535; // stack sort is needed.
                    }
                }
            }
        // ------------------------- X -------------------------
        }
        if (!window_class::mouse_over_title) window_class::mouse_over_title = return_mouse_over;
    }
    window_class::event = return_value;
    //if (return_value > 0) game.core.log.file_write("returning event -> ",return_value, " - from UID - ", window_class::UID);
    return(return_value);
};



void window_class::reload_textures(void)
{
    if (window_class::texture.normal.image_path.length() > 3)      window_class::texture.normal.image.load_image     (window_class::texture.normal.image_path);
    if (window_class::texture.highlighted.image_path.length() > 3) window_class::texture.highlighted.image.load_image(window_class::texture.highlighted.image_path);
    if (window_class::texture.disabled.image_path.length() > 3)    window_class::texture.disabled.image.load_image   (window_class::texture.disabled.image_path);
    if (window_class::texture.base.image_path.length() > 3)        window_class::texture.base.image.load_image       (window_class::texture.base.image_path);
    // Reload textures for choice selection counts
    for (int choice_selection_per_menu_count = 0; choice_selection_per_menu_count < MAX_CHOICE_SELECTIONS_PER_MENU; choice_selection_per_menu_count++)
    {
        for (int choice_selection_count = 0; choice_selection_count < MAX_CHOICE_SELECTION; choice_selection_count++)
        {
            if (window_class::choice_selection[choice_selection_per_menu_count].data[choice_selection_count].image_path.length() > 3)
            {
                window_class::choice_selection[choice_selection_per_menu_count].data[choice_selection_count].image.load_image(window_class::choice_selection[choice_selection_per_menu_count].data[choice_selection_count].image_path);
            }
        }
    }
    // Reload textures for all elements
    for (int element_number = 0; element_number < window_class::number_of_elements; element_number++)
    {
        window_class::element[element_number].reload_textures();
    }
};
