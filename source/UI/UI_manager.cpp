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

#include "menu_main.hpp"
#include "UI_manager.hpp"
#include "../game.hpp"

extern game_class         game;

UI_manager_class::UI_manager_class(void)
{
    UI_manager_class::event.id             = 0;
    UI_manager_class::number_of_UI_forms   = 0;
}

UI_form_struct *UI_manager_class::add_window(int UI_form_UID)
{
    if (UI_manager_class::number_of_UI_forms == 0)
    {
        UI_manager_class::root           = new UI_form_struct;
        UI_manager_class::root->next     = NULL;
        UI_manager_class::root->previous = NULL;
        UI_manager_class::last           = root;
    }
    else
    {
        UI_form_struct* temp_pointer;
        temp_pointer = new UI_form_struct;
        temp_pointer = UI_manager_class::root;
        if (temp_pointer != NULL)
        {
            while (temp_pointer->next != NULL)
            {
                if (temp_pointer->UID == UI_form_UID)
                {
                    return(temp_pointer);
                }
                temp_pointer = temp_pointer->next;
            }
        }
        UI_manager_class::last->previous = UI_manager_class::last;
        UI_manager_class::last->next     = new UI_form_struct;
        UI_manager_class::last           = UI_manager_class::last->next;
        UI_manager_class::last->next     = NULL;
    }
    UI_manager_class::last->active                             = false;
    UI_manager_class::last->color.disabled.r                   = 255;
    UI_manager_class::last->color.disabled.g                   = 255;
    UI_manager_class::last->color.disabled.b                   = 255;
    UI_manager_class::last->color.disabled.a                   = 255;
    UI_manager_class::last->color.highlighted.r                = 255;
    UI_manager_class::last->color.highlighted.g                = 255;
    UI_manager_class::last->color.highlighted.b                = 255;
    UI_manager_class::last->color.highlighted.a                = 255;
    UI_manager_class::last->color.normal.r                     = 255;
    UI_manager_class::last->color.normal.g                     = 255;
    UI_manager_class::last->color.normal.b                     = 255;
    UI_manager_class::last->color.normal.a                     = 255;
    UI_manager_class::last->drag_active                        = false;
    UI_manager_class::last->drag_enabled                       = true;
    UI_manager_class::last->drag_offset_x                      = 0.0f;
    UI_manager_class::last->drag_offset_y                      = 0.0f;
    UI_manager_class::last->enabled                            = false;
    UI_manager_class::last->event.id                           = EVENT_NONE;
    UI_manager_class::last->mouse_delay.enabled                = true;
    UI_manager_class::last->mouse_delay.maximum                = 30;
    UI_manager_class::last->mouse_delay.ready                  = false;
    UI_manager_class::last->mouse_delay.value                  = 0;
    UI_manager_class::last->mouse_over_menu                    = false;
    UI_manager_class::last->mouse_over_title                   = false;
    UI_manager_class::last->number_of_elements                 = 0;
    UI_manager_class::last->position.x                         = 0.0f;
    UI_manager_class::last->position.y                         = 0.0f;
    UI_manager_class::last->position.z                         = 0.0f;
    UI_manager_class::last->set_behind                         = false;
    UI_manager_class::last->size.x                             = 0.0f;
    UI_manager_class::last->size.y                             = 0.0f;
    UI_manager_class::last->size.z                             = 0.0f;
    UI_manager_class::last->title_bar.text                     = "";
    UI_manager_class::last->title_bar.position.x               = 0.0f;
    UI_manager_class::last->title_bar.position.y               = 0.0f;
    UI_manager_class::last->title_bar.position.z               = 0.0f;
    UI_manager_class::last->title_bar.size.x                   = 0.0f;
    UI_manager_class::last->title_bar.size.y                   = 0.0f;
    UI_manager_class::last->title_bar.size.z                   = 0.0f;
    UI_manager_class::last->title_color.r                      = 255;
    UI_manager_class::last->title_color.g                      = 255;
    UI_manager_class::last->title_color.b                      = 255;
    UI_manager_class::last->title_color.a                      = 255;
    UI_manager_class::last->title.position.x                   = 0.0f;
    UI_manager_class::last->title.position.y                   = 0.0f;
    UI_manager_class::last->title.position.z                   = 0.0f;
    UI_manager_class::last->title.size.x                       = 0.0f;
    UI_manager_class::last->title.size.y                       = 0.0f;
    UI_manager_class::last->title.size.z                       = 0.0f;
    UI_manager_class::last->title.text                         = "Not set";
    UI_manager_class::last->UID                                = UI_form_UID;
    UI_manager_class::last->zoom.enabled                       = true;
    UI_manager_class::last->zoom.maximum                       = 0.01f;
    UI_manager_class::last->zoom.value                         = 0.0f;
    UI_manager_class::last->zoom.speed                         = 0.001f;
    UI_manager_class::number_of_UI_forms++;
    return(UI_manager_class::last);
};

void UI_manager_class::setup(void)
{
    setup_menu_main(UID_MENU_MAIN);
}

void UI_manager_class::render(void)
{
    UI_form_struct *UI_form_pointer;
    UI_form_pointer = UI_manager_class::root;
    while (UI_form_pointer != NULL)
    {
        // ----------------------------- render UI form ---------------------------------
        if(UI_form_pointer->enabled)
        {
            // ------------------------- Render menu background and title -------------------------
            game.texture_manager.draw(UI_form_pointer->texture.base,false,UI_form_pointer->position.x,UI_form_pointer->position.y,UI_form_pointer->position.z,UI_form_pointer->size.x,UI_form_pointer->size.y);
            game.font_manager.write(UI_form_pointer->font,UI_form_pointer->title_color.r,UI_form_pointer->title_color.g,UI_form_pointer->title_color.b,UI_form_pointer->title_color.a,UI_form_pointer->title.position.x,UI_form_pointer->title.position.y,UI_form_pointer->title.size.x,UI_form_pointer->title.size.y,UI_form_pointer->title.text);
            // ------------------------- Render elements -------------------------
            if (UI_form_pointer->number_of_elements > 0)
            {
                for (int element_number = 0; element_number < UI_form_pointer->number_of_elements; element_number++)
                {
                    if (UI_form_pointer->element[element_number].active)
                    {
                        float zoom_value = (UI_form_pointer->element[element_number].zoom.enabled) ? UI_form_pointer->element[element_number].zoom.value : 0.0f;
                        float temp_float = 0.0f;
                        if (UI_form_pointer->element[element_number].active)
                        {
                            switch (UI_form_pointer->element[element_number].type)
                            {
                                case IMAGE:
                                    if (UI_form_pointer->element[element_number].selected) game.texture_manager.draw(UI_form_pointer->element[element_number].texture.highlighted,false,UI_form_pointer->element[element_number].position.x,UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,UI_form_pointer->element[element_number].size.x+zoom_value,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                    game.texture_manager.draw(UI_form_pointer->element[element_number].texture.normal,false,UI_form_pointer->element[element_number].position.x,UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,UI_form_pointer->element[element_number].size.x+zoom_value,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                    if ((UI_form_pointer->element[element_number].title.enabled) && (UI_form_pointer->element[element_number].mouse_over))
                                    {
                                        game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.highlighted.r,UI_form_pointer->element[element_number].color.highlighted.g,UI_form_pointer->element[element_number].color.highlighted.b,UI_form_pointer->element[element_number].color.highlighted.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                    }
                                break;
                                case BUTTON:
                                    switch (UI_form_pointer->element[element_number].state)
                                    {
                                        case NORMAL:
                                            game.texture_manager.draw(UI_form_pointer->element[element_number].texture.normal,false,UI_form_pointer->element[element_number].position.x,UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,UI_form_pointer->element[element_number].size.x+zoom_value,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.normal.r,UI_form_pointer->element[element_number].color.normal.g,UI_form_pointer->element[element_number].color.normal.b,UI_form_pointer->element[element_number].color.normal.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        case HIGHLIGHTED:
                                            game.texture_manager.draw(UI_form_pointer->element[element_number].texture.highlighted,false,UI_form_pointer->element[element_number].position.x,UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,UI_form_pointer->element[element_number].size.x+zoom_value,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.highlighted.r,UI_form_pointer->element[element_number].color.highlighted.g,UI_form_pointer->element[element_number].color.highlighted.b,UI_form_pointer->element[element_number].color.highlighted.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        case DISABLED:
                                            game.texture_manager.draw(UI_form_pointer->element[element_number].texture.disabled,false,UI_form_pointer->element[element_number].position.x,UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,UI_form_pointer->element[element_number].size.x+zoom_value,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.disabled.r,UI_form_pointer->element[element_number].color.disabled.g,UI_form_pointer->element[element_number].color.disabled.b,UI_form_pointer->element[element_number].color.disabled.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        default:
                                        break;
                                    }
                                break;
                                case TEXTLABEL:
                                    switch (UI_form_pointer->element[element_number].state)
                                    {
                                        case NORMAL:
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.normal.r,UI_form_pointer->element[element_number].color.normal.g,UI_form_pointer->element[element_number].color.normal.b,UI_form_pointer->element[element_number].color.normal.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        case HIGHLIGHTED:
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.highlighted.r,UI_form_pointer->element[element_number].color.highlighted.g,UI_form_pointer->element[element_number].color.highlighted.b,UI_form_pointer->element[element_number].color.highlighted.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        case DISABLED:
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.disabled.r,UI_form_pointer->element[element_number].color.disabled.g,UI_form_pointer->element[element_number].color.disabled.b,UI_form_pointer->element[element_number].color.disabled.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        default:
                                        break;
                                    }
                                break;
                                case SLIDER:
                                break;
                                case BAR:
                                    switch (UI_form_pointer->element[element_number].state)
                                    {
                                        case NORMAL:
                                            temp_float = (UI_form_pointer->element[element_number].value / UI_form_pointer->element[element_number].value_max) * (UI_form_pointer->element[element_number].size.x+zoom_value);
                                            game.texture_manager.draw(UI_form_pointer->element[element_number].texture.normal,false,UI_form_pointer->element[element_number].position.x-((UI_form_pointer->element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,temp_float,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.normal.r,UI_form_pointer->element[element_number].color.normal.g,UI_form_pointer->element[element_number].color.normal.b,UI_form_pointer->element[element_number].color.normal.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        case HIGHLIGHTED:
                                            temp_float = (UI_form_pointer->element[element_number].value / UI_form_pointer->element[element_number].value_max) * (UI_form_pointer->element[element_number].size.x+zoom_value);
                                            game.texture_manager.draw(UI_form_pointer->element[element_number].texture.highlighted,false,UI_form_pointer->element[element_number].position.x-((UI_form_pointer->element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,temp_float,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.highlighted.r,UI_form_pointer->element[element_number].color.highlighted.g,UI_form_pointer->element[element_number].color.highlighted.b,UI_form_pointer->element[element_number].color.highlighted.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
                                        break;
                                        case DISABLED:
                                            temp_float = (UI_form_pointer->element[element_number].value / UI_form_pointer->element[element_number].value_max) * (UI_form_pointer->element[element_number].size.x+zoom_value);
                                            game.texture_manager.draw(UI_form_pointer->element[element_number].texture.disabled,false,UI_form_pointer->element[element_number].position.x-((UI_form_pointer->element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,temp_float,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
                                            if (UI_form_pointer->element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.disabled.r,UI_form_pointer->element[element_number].color.disabled.g,UI_form_pointer->element[element_number].color.disabled.b,UI_form_pointer->element[element_number].color.disabled.a,UI_form_pointer->element[element_number].title.position.x,UI_form_pointer->element[element_number].title.position.y,UI_form_pointer->element[element_number].title.size.x,UI_form_pointer->element[element_number].title.size.y,UI_form_pointer->element[element_number].title.text);
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
                                    if (UI_form_pointer->element[element_number].value > -1)
                                    {
                                        game.texture_manager.draw(UI_form_pointer->element[element_number].texture.normal,false,UI_form_pointer->element[element_number].position.x,UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].position.z,UI_form_pointer->element[element_number].size.x+zoom_value,UI_form_pointer->element[element_number].size.y+zoom_value,UI_form_pointer->element[element_number].texture.angle);
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
            if (UI_form_pointer->number_of_elements > 0)
            {
                for (int element_number = 0; element_number < UI_form_pointer->number_of_elements; element_number++)
                {
                    if (UI_form_pointer->element[element_number].active)
                    {
                        if ((UI_form_pointer->element[element_number].active) && (UI_form_pointer->element[element_number].tooltip.enabled))
                        {
                            if (UI_form_pointer->element[element_number].mouse_over)
                            {
                                if ((UI_form_pointer->element[element_number].tooltip.enabled) && (UI_form_pointer->element[element_number].tooltip.image_enabled))
                                {
                                    float temp_size_x = UI_form_pointer->element[element_number].tooltip.image_size.x;
                                    float temp_size_y = UI_form_pointer->element[element_number].tooltip.image_size.y;
                                    game.texture_manager.draw(UI_form_pointer->element[element_number].tooltip.image,false,game.core.io.mouse_x+(temp_size_x*0.25f),game.core.io.mouse_y+(temp_size_y*0.25f),UI_form_pointer->element[element_number].tooltip.position.z,temp_size_x,temp_size_y,UI_form_pointer->element[element_number].texture.angle);
                                }
                                game.font_manager.write(UI_form_pointer->element[element_number].font,UI_form_pointer->element[element_number].color.highlighted.r,UI_form_pointer->element[element_number].color.highlighted.g,UI_form_pointer->element[element_number].color.highlighted.b,UI_form_pointer->element[element_number].color.highlighted.a,game.core.io.mouse_x,game.core.io.mouse_y,UI_form_pointer->element[element_number].tooltip.size.x,UI_form_pointer->element[element_number].tooltip.size.y,UI_form_pointer->element[element_number].tooltip.text);
                            }
                        }
                    }
                }
            }
        }
        // -------------------------------------------------------------------------------
        UI_form_pointer = UI_form_pointer->next;
    }
};

void UI_manager_class::process(void)
{
    UI_form_struct *UI_form_pointer;
    UI_form_pointer = UI_manager_class::root;
    while (UI_form_pointer != NULL)
    {
        // ----------------------------- process UI form ---------------------------------
        event_struct return_value;
        float        drag_delta_x      = 0.0f;
        float        drag_delta_y      = 0.0f;
        bool         return_mouse_over = false;
        bool         allow_drag        = true;
        bool         window_in_focus   = true;
        return_value.id                = EVENT_NONE;
        if (UI_form_pointer->enabled)
        {
            // ------------------------- Process mouse delay -------------------------
            if (UI_form_pointer->mouse_delay.enabled)
            {
                UI_form_pointer->mouse_delay.value++;
                if (UI_form_pointer->mouse_delay.value >= UI_form_pointer->mouse_delay.maximum)
                {
                    UI_form_pointer->mouse_delay.ready = true;
                    UI_form_pointer->mouse_delay.value = UI_form_pointer->mouse_delay.maximum;
                }
            }
            // ------------------------- Process elements -------------------------
            if ((UI_form_pointer->number_of_elements > 0) && (!UI_form_pointer->drag_active))
            {
                for (int element_number = 0; element_number < UI_form_pointer->number_of_elements; element_number++)
                {
                    if ((UI_form_pointer->element[element_number].active) && ((return_value.id == EVENT_NONE) || (return_value.id == EVENT_ELEMENT_DRAG)))
                    {
                        // ---------------------------------------------------------------------------------------
                        UI_form_pointer->element[element_number].mouse_over = (game.core.physics.point_in_quadrangle(UI_form_pointer->element[element_number].position.x,UI_form_pointer->element[element_number].size.x,UI_form_pointer->element[element_number].position.y,UI_form_pointer->element[element_number].size.y,game.core.io.mouse_x,game.core.io.mouse_y));
                        float drag_delta_x = 0.0f;
                        float drag_delta_y = 0.0f;
                        bool  allow_drag   = UI_form_pointer->element[element_number].dragable;
                        bool  allow_process = true;
                        UI_form_pointer->element[element_number].clicked = false;
                        // ------------------------- Process mouse delay -------------------------
                        if (UI_form_pointer->element[element_number].mouse_delay.enabled)
                        {
                            UI_form_pointer->element[element_number].mouse_delay.value++;
                            if (UI_form_pointer->element[element_number].mouse_delay.value >= UI_form_pointer->element[element_number].mouse_delay.maximum)
                            {
                                UI_form_pointer->element[element_number].mouse_delay.ready = true;
                                UI_form_pointer->element[element_number].mouse_delay.value = UI_form_pointer->element[element_number].mouse_delay.maximum;
                            }
                        }
                        // ------------------------- -------------------------
                        if ((UI_form_pointer->element[element_number].event.id == EVENT_ELEMENT_MOUSE_RIGHT) || (UI_form_pointer->element[element_number].event.id == EVENT_ELEMENT_MOUSE_LEFT)) UI_form_pointer->element[element_number].event.id = EVENT_NONE;
                        if (!UI_form_pointer->element[element_number].active) allow_process = false;
                        if ((UI_form_pointer->element[element_number].type == ITEM) && (UI_form_pointer->element[element_number].value < 0)) allow_process = false;
                        if (allow_process)
                        {
                            if (UI_form_pointer->element[element_number].state != DISABLED)
                            {
                                // ------------------------- Drag n drop -------------------------
                                if (UI_form_pointer->element[element_number].drag_active)
                                {
                                    if (game.core.io.mouse_button_left)
                                    {
                                        drag_delta_x = UI_form_pointer->element[element_number].position.x;
                                        drag_delta_y = UI_form_pointer->element[element_number].position.y;
                                        UI_form_pointer->element[element_number].position.x = game.core.io.mouse_x + UI_form_pointer->element[element_number].drag_offset_x;
                                        UI_form_pointer->element[element_number].position.y = game.core.io.mouse_y + UI_form_pointer->element[element_number].drag_offset_y;
                                        drag_delta_x = drag_delta_x - UI_form_pointer->element[element_number].position.x;
                                        drag_delta_y = drag_delta_y - UI_form_pointer->element[element_number].position.y;
                                        UI_form_pointer->element[element_number].title.position.x     -= drag_delta_x;
                                        UI_form_pointer->element[element_number].title.position.y     -= drag_delta_y;
                                    }
                                    else
                                    {
                                        /*
                                        int window_over  = game.UI_manager.mouse_over_window();
                                        int window_from  = UI_form_pointer->element[element_number].window_UID;
                                        int element_from = UI_form_pointer->element[element_number].element_UID;
                                        int element_over = 0;
                                        UI_form_pointer->element[element_number].position.x = UI_form_pointer->element[element_number].position_origional.x;
                                        UI_form_pointer->element[element_number].position.y = UI_form_pointer->element[element_number].position_origional.y;
                                        if (window_over != MOUSE_OVER_MAP)
                                        {
                                            element_over = game.UI_manager.mouse_over_element(window_over);
                                            if (element_over != MOUSE_OVER_MAP)
                                            {
                                                //swap
                                                swap_elements(window_from,element_from,window_over,element_over);
                                            }
                                        }
                                        */
                                        game.UI_manager.element_drag_in_progress       = false;
                                        game.UI_manager.drag_in_progress               = false;
                                        UI_form_pointer->element[element_number].drag_active  = false;
                                        UI_form_pointer->element[element_number].event.id     = EVENT_NONE;
                                    }
                                }
                                else
                                {
                                    if ((UI_form_pointer->element[element_number].dragable) && (window_in_focus) && (UI_form_pointer->element[element_number].mouse_over) && (!game.UI_manager.drag_in_progress))
                                    {
                                        if ((game.core.io.mouse_button_left) && (allow_drag))// start drag
                                        {
                                            UI_form_pointer->element[element_number].position_origional.x   = UI_form_pointer->element[element_number].position.x;
                                            UI_form_pointer->element[element_number].position_origional.y   = UI_form_pointer->element[element_number].position.y;
                                            UI_form_pointer->element[element_number].drag_offset_x          = UI_form_pointer->element[element_number].position.x - game.core.io.mouse_x;
                                            UI_form_pointer->element[element_number].drag_offset_y          = UI_form_pointer->element[element_number].position.y - game.core.io.mouse_y;
                                            UI_form_pointer->element[element_number].drag_active            = true;
                                            game.UI_manager.drag_in_progress         = true;
                                            game.UI_manager.element_drag_in_progress = true;
                                        }
                                    }
                                }
                                if (UI_form_pointer->element[element_number].mouse_over)
                                {
                                    // ----------------- highlighting element ------------------------------
                                    if (window_in_focus)
                                    {
                                        if ((UI_form_pointer->element[element_number].state  != HIGHLIGHTED) && (UI_form_pointer->element[element_number].sound.on_mouse_over.enabled)) game.sound_manager.play(UI_form_pointer->element[element_number].sound.on_mouse_over.sound);
                                        UI_form_pointer->element[element_number].state        = HIGHLIGHTED;
                                    }
                                    else
                                    {
                                        UI_form_pointer->element[element_number].state        = NORMAL;
                                    }
                                    // ------------------------- clicked element -------------------------
                                    float dragged_by_x = 0.0f;
                                    float dragged_by_y = 0.0f;
                                    if (UI_form_pointer->element[element_number].position_origional.x > UI_form_pointer->element[element_number].position.x) dragged_by_x = UI_form_pointer->element[element_number].position_origional.x - UI_form_pointer->element[element_number].position.x;
                                    else dragged_by_x = UI_form_pointer->element[element_number].position.x - UI_form_pointer->element[element_number].position_origional.x;
                                    if (UI_form_pointer->element[element_number].position_origional.y > UI_form_pointer->element[element_number].position.y) dragged_by_y = UI_form_pointer->element[element_number].position_origional.y - UI_form_pointer->element[element_number].position.y;
                                    else dragged_by_y = UI_form_pointer->element[element_number].position.y - UI_form_pointer->element[element_number].position_origional.y;
                                    if (((dragged_by_x < 0.01f) && (dragged_by_y < 0.01f) && (window_in_focus)) || ((!game.UI_manager.drag_in_progress) && (window_in_focus)))
                                    {
                                        if (UI_form_pointer->element[element_number].click_enabled)
                                        {
                                            if (((game.core.io.mouse_button_left) || (game.core.io.mouse_button_right)) && (UI_form_pointer->element[element_number].mouse_over))
                                            {
                                                if((UI_form_pointer->element[element_number].mouse_delay.ready) || (!UI_form_pointer->element[element_number].mouse_delay.enabled))
                                                {
                                                    if (game.core.io.mouse_button_right) UI_form_pointer->element[element_number].event.id = EVENT_ELEMENT_MOUSE_RIGHT;
                                                    if (game.core.io.mouse_button_left)  UI_form_pointer->element[element_number].event.id = EVENT_ELEMENT_MOUSE_LEFT;
                                                    if (UI_form_pointer->element[element_number].sound.on_click.enabled) game.sound_manager.play(UI_form_pointer->element[element_number].sound.on_click.sound);
                                                    UI_form_pointer->element[element_number].clicked = true;
                                                    if (UI_form_pointer->element[element_number].mouse_delay.enabled)
                                                    {
                                                        UI_form_pointer->element[element_number].mouse_delay.ready = false;
                                                        UI_form_pointer->element[element_number].mouse_delay.value = 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    UI_form_pointer->element[element_number].state = NORMAL;
                                }
                            }
                            if (UI_form_pointer->element[element_number].state == HIGHLIGHTED)
                            {
                                UI_form_pointer->element[element_number].zoom.value += UI_form_pointer->element[element_number].zoom.speed;
                                if (UI_form_pointer->element[element_number].zoom.value > UI_form_pointer->element[element_number].zoom.maximum) UI_form_pointer->element[element_number].zoom.value = UI_form_pointer->element[element_number].zoom.maximum;
                            }
                            if ((UI_form_pointer->element[element_number].state != HIGHLIGHTED) && (UI_form_pointer->element[element_number].zoom.value > 0.0f))
                            {
                                UI_form_pointer->element[element_number].zoom.value -= UI_form_pointer->element[element_number].zoom.speed;
                                if (UI_form_pointer->element[element_number].zoom.value < 0.0f) UI_form_pointer->element[element_number].zoom.value = 0.0f;
                            }
                        }
                        else UI_form_pointer->element[element_number].event.id = EVENT_NONE;
                        return_value.id = UI_form_pointer->element[element_number].event.id;
                        // ------------------------------------------------------------------------------------------
                        if (return_value.id != EVENT_NONE)
                        {
                            switch (return_value.id)
                            {
                                case EVENT_ELEMENT_DRAG:
                                    //game.UI_manager.source.element = element_number;
                                break;
                                default:
                                    return_value.id += (element_number * EVENT_BUTTON_MULTIPLIER);
                                break;
                            }
                            allow_drag       = false;
                        }
                        if (UI_form_pointer->element[element_number].mouse_over)
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
                if (!game.UI_manager.drag_in_progress)
                {
                    UI_form_pointer->mouse_over_menu = (game.core.physics.point_in_quadrangle(UI_form_pointer->position.x,UI_form_pointer->size.x,UI_form_pointer->position.y,UI_form_pointer->size.y,game.core.io.mouse_x,game.core.io.mouse_y));
                }
                if (!game.UI_manager.drag_in_progress)
                {
                    UI_form_pointer->mouse_over_title = (game.core.physics.point_in_quadrangle(UI_form_pointer->title_bar.position.x,UI_form_pointer->title_bar.size.x,UI_form_pointer->title_bar.position.y,UI_form_pointer->title_bar.size.y,game.core.io.mouse_x,game.core.io.mouse_y));
                }
                if (UI_form_pointer->drag_active)
                {
                    if (game.core.io.mouse_button_left)
                    {
                        drag_delta_x = UI_form_pointer->position.x;
                        drag_delta_y = UI_form_pointer->position.y;
                        UI_form_pointer->position.x = game.core.io.mouse_x + UI_form_pointer->drag_offset_x;
                        UI_form_pointer->position.y = game.core.io.mouse_y + UI_form_pointer->drag_offset_y;
                        drag_delta_x = drag_delta_x - UI_form_pointer->position.x;
                        drag_delta_y = drag_delta_y - UI_form_pointer->position.y;
                        UI_form_pointer->title.position.x     -= drag_delta_x;
                        UI_form_pointer->title.position.y     -= drag_delta_y;
                        UI_form_pointer->title_bar.position.x -= drag_delta_x;
                        UI_form_pointer->title_bar.position.y -= drag_delta_y;
                        if(UI_form_pointer->number_of_elements > 0)
                        {
                            for (int element_number = 0; element_number < UI_form_pointer->number_of_elements; element_number++)
                            {
                                if (UI_form_pointer->element[element_number].active)
                                {
                                    UI_form_pointer->element[element_number].position.x       -= drag_delta_x;
                                    UI_form_pointer->element[element_number].position.y       -= drag_delta_y;
                                    UI_form_pointer->element[element_number].title.position.x -= drag_delta_x;
                                    UI_form_pointer->element[element_number].title.position.y -= drag_delta_y;
                                }
                            }
                        }
                    }
                    else
                    {
                        UI_form_pointer->drag_active             = false;
                        game.UI_manager.drag_in_progress  = false;
                    }
                }
                else
                {
                    if ((UI_form_pointer->drag_enabled) && (window_in_focus))
                    {
                        if ((!game.UI_manager.drag_in_progress) && (UI_form_pointer->mouse_over_title) && (game.core.io.mouse_button_left) && (allow_drag))// start drag
                        {
                            UI_form_pointer->drag_offset_x                = UI_form_pointer->position.x - game.core.io.mouse_x;
                            UI_form_pointer->drag_offset_y                = UI_form_pointer->position.y - game.core.io.mouse_y;
                            UI_form_pointer->drag_active                  = true;
                            game.UI_manager.drag_in_progress       = true;
                            return_value.id                            = EVENT_WINDOW_STACK_SORT;
                        }
                    }
                    // user clicked on window, that is not title or an element.
                    if ((game.core.io.mouse_button_left) && (return_value.id == EVENT_NONE) && (!UI_form_pointer->active))
                    {
                        return_value.id = EVENT_WINDOW_STACK_SORT;
                    }
                }
                // ------------------------- X -------------------------
                if (!UI_form_pointer->mouse_over_title) UI_form_pointer->mouse_over_title = return_mouse_over;
            }
        }
        //if (return_value > 0) game.core.log.file_write("returning event -> ",return_value, " - from UID - ", UI_form_pointer->UID);
        //if (return_value == EVENT_WINDOW_STACK_SORT) game.core.log.file_write("returning event -> ",return_value, " - from UID - ", UI_form_pointer->UID);
        UI_form_pointer->event = return_value;
        // ----------------------------- process UI form events ---------------------------------
        if (UI_form_pointer->enabled)
        {
            if (game.UI_manager.event.id == EVENT_NONE)
            {
                switch(UI_form_pointer->UID)
                {
                    case UID_MENU_MAIN:
                        process_menu_main(UI_form_pointer);
                    break;
                    case UID_MENU_GAME_NEW:
                        //process_menu_game_new(UI_form_pointer);
                    break;
                    case UID_MENU_GAME_LOAD:
                        //process_menu_game_load(UI_form_pointer);
                    break;
                    case UID_MENU_GAME_SAVE:
                        //process_menu_game_save(UI_form_pointer);
                    break;
                    case UID_MENU_OPTIONS:
                        //process_menu_options(UI_form_pointer);
                    break;
                    case UID_PCPROFILE:
                        //process_player_profile(UI_form_pointer);
                    break;
                    case UID_ACTIONBAR:
                        //process_action_bar(UI_form_pointer);
                    break;
                    case UID_CHARACTER:
                        //process_character_window(UI_form_pointer);
                    break;
                    case UID_EQUIPMENT:
                        //process_equipment_window(UI_form_pointer);
                    break;
                    case UID_INVENTORY:
                        //process_inventory_window(UI_form_pointer);
                    break;
                    case UID_QUEST_LOG:
                        //process_quest_log_window(UI_form_pointer);
                    break;
                    case UID_SKILLBOOK:
                        //process_skillbook_window(UI_form_pointer);
                    break;
                    default:
                        game.core.log.file_write("Unable to process UID - ",UI_form_pointer->UID);
                    break;
                }
            }
        }
        // -------------------------------------------------------------------------------
        UI_form_pointer = UI_form_pointer->next;
    }
    switch (game.UI_manager.event.id)
    {
        case EVENT_WINDOW_STACK_SORT: //window has requested a window stack sort;
            //game.UI_manager.window_stack_sort();
            game.UI_manager.event.id = EVENT_NONE;
        break;
        default:
            game.UI_manager.event.id = EVENT_NONE;
        break;
    }
};
