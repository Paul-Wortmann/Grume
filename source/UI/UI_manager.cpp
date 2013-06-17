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

#include "UI_manager.hpp"
#include "../game.hpp"

extern game_class         game;

UI_manager_class::UI_manager_class(void)
{
    UI_manager_class::event.id             = 0;
    UI_manager_class::number_of_UI_forms   = 0;
}

UI_form_struct *UI_manager_class::UI_form_add(int UI_form_UID)
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
                if (temp_pointer->data.UID == UI_form_UID)
                {
                    return (temp_pointer);
                }
                temp_pointer = temp_pointer->next;
            }
        }
        temp_pointer                     = UI_manager_class::last;
        UI_manager_class::last->next     = new UI_form_struct;
        UI_manager_class::last           = UI_manager_class::last->next;
        UI_manager_class::last->next     = NULL;
        UI_manager_class::last->previous = temp_pointer;
    }
    UI_manager_class::last->data.active                             = false;
    UI_manager_class::last->data.color.disabled.r                   = 255;
    UI_manager_class::last->data.color.disabled.g                   = 255;
    UI_manager_class::last->data.color.disabled.b                   = 255;
    UI_manager_class::last->data.color.disabled.a                   = 255;
    UI_manager_class::last->data.color.highlighted.r                = 255;
    UI_manager_class::last->data.color.highlighted.g                = 255;
    UI_manager_class::last->data.color.highlighted.b                = 255;
    UI_manager_class::last->data.color.highlighted.a                = 255;
    UI_manager_class::last->data.color.normal.r                     = 255;
    UI_manager_class::last->data.color.normal.g                     = 255;
    UI_manager_class::last->data.color.normal.b                     = 255;
    UI_manager_class::last->data.color.normal.a                     = 255;
    UI_manager_class::last->data.drag_active                        = false;
    UI_manager_class::last->data.drag_enabled                       = true;
    UI_manager_class::last->data.drag_offset_x                      = 0.0f;
    UI_manager_class::last->data.drag_offset_y                      = 0.0f;
    UI_manager_class::last->data.enabled                            = false;
    UI_manager_class::last->data.event.id                           = EVENT_NONE;
    UI_manager_class::last->data.mouse_delay.enabled                = true;
    UI_manager_class::last->data.mouse_delay.maximum                = 30;
    UI_manager_class::last->data.mouse_delay.ready                  = false;
    UI_manager_class::last->data.mouse_delay.value                  = 0;
    UI_manager_class::last->data.mouse_over_menu                    = false;
    UI_manager_class::last->data.mouse_over_title                   = false;
    UI_manager_class::last->data.number_of_choice_selections        = 0;
    UI_manager_class::last->data.number_of_elements                 = 0;
    UI_manager_class::last->data.position.x                         = 0.0f;
    UI_manager_class::last->data.position.y                         = 0.0f;
    UI_manager_class::last->data.position.z                         = 0.0f;
    UI_manager_class::last->data.set_behind                         = false;
    UI_manager_class::last->data.size.x                             = 0.0f;
    UI_manager_class::last->data.size.y                             = 0.0f;
    UI_manager_class::last->data.size.z                             = 0.0f;
    UI_manager_class::last->data.title_bar.text                     = "";
    UI_manager_class::last->data.title_bar.position.x               = 0.0f;
    UI_manager_class::last->data.title_bar.position.y               = 0.0f;
    UI_manager_class::last->data.title_bar.position.z               = 0.0f;
    UI_manager_class::last->data.title_bar.size.x                   = 0.0f;
    UI_manager_class::last->data.title_bar.size.y                   = 0.0f;
    UI_manager_class::last->data.title_bar.size.z                   = 0.0f;
    UI_manager_class::last->data.title_color.r                      = 255;
    UI_manager_class::last->data.title_color.g                      = 255;
    UI_manager_class::last->data.title_color.b                      = 255;
    UI_manager_class::last->data.title_color.a                      = 255;
    UI_manager_class::last->data.title.position.x                   = 0.0f;
    UI_manager_class::last->data.title.position.y                   = 0.0f;
    UI_manager_class::last->data.title.position.z                   = 0.0f;
    UI_manager_class::last->data.title.size.x                       = 0.0f;
    UI_manager_class::last->data.title.size.y                       = 0.0f;
    UI_manager_class::last->data.title.size.z                       = 0.0f;
    UI_manager_class::last->data.title.text                         = "Not set";
    UI_manager_class::last->data.UID                                = UI_form_UID;
    UI_manager_class::last->data.zoom.enabled                       = true;
    UI_manager_class::last->data.zoom.maximum                       = 0.01f;
    UI_manager_class::last->data.zoom.value                         = 0.0f;
    UI_manager_class::last->data.zoom.speed                         = 0.001f;
    UI_manager_class::number_of_UI_forms++;
    return (UI_manager_class::last);
};

void UI_manager_class::setup(void)
{
    setup_action_bar      (UID_ACTIONBAR);
    setup_player_profile  (UID_PCPROFILE);
    setup_character_window(UID_CHARACTER);
    setup_equipment_window(UID_EQUIPMENT);
    setup_inventory_window(UID_INVENTORY);
    setup_menu_game_load  (UID_MENU_GAME_LOAD);
    setup_menu_game_new   (UID_MENU_GAME_NEW);
    setup_menu_game_save  (UID_MENU_GAME_SAVE);
    setup_menu_main       (UID_MENU_MAIN);
    setup_menu_options    (UID_MENU_OPTIONS);
    setup_quest_log_window(UID_QUEST_LOG);
    setup_skillbook_window(UID_SKILLBOOK);
    //--- Set the main menu as the default active window. ---
    UI_manager_class::UI_form_set_active(UID_MENU_MAIN);
    //--- Enable windows. ---
    UI_manager_class::UI_form_enable(UID_MENU_MAIN);
    // --- Allow specific textures to be rotated ----
    texture_type *temp_pointer;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    temp_pointer->rotate_able = true;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    temp_pointer->rotate_able = true;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    temp_pointer->rotate_able = true;
}

UI_form_struct *UI_manager_class::UI_form_get(int UI_form_UID)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            return(UI_form_pointer);
        }
    }
    return(NULL);
};

void UI_manager_class::UI_form_enable(int UI_form_UID)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            UI_form_pointer->data.enabled = true;
        }
    }
    UI_manager_class::UI_form_stack_sort();
};

void UI_manager_class::UI_form_disable(int UI_form_UID)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            UI_form_pointer->data.enabled = false;
            UI_form_pointer->data.active  = false;
        }
    }
};

void UI_manager_class::UI_form_stack_sort(void)
{
    if (!UI_manager_class::element_drag_in_progress)
    {
        if (UI_manager_class::number_of_UI_forms > 1) // only processed if there are actually windows in the list to sort.
        {
            // ----------------------------- show unsorted list ---------------------------
            game.core.log.file_write("---------------- unsorted ---------------------");
            for (UI_form_struct *UI_form_pointer_1 = UI_manager_class::last; UI_form_pointer_1!=NULL; UI_form_pointer_1 = UI_form_pointer_1->previous)
            {
                if (UI_form_pointer_1->data.active) game.core.log.file_write("Active UID found -> ",UI_form_pointer_1->data.UID);
                else game.core.log.file_write("UID not active -> ",UI_form_pointer_1->data.UID);
            }
            // ----------------------------- do sort ---------------------------
            UI_form_struct *UI_form_pointer_2;
            UI_form_struct *UI_form_pointer_3;
            UI_form_pointer_3 = new UI_form_struct;
            for (UI_form_struct *UI_form_pointer_4 = UI_manager_class::root; UI_form_pointer_4->next!=NULL; UI_form_pointer_4 = UI_form_pointer_4->next)
            {
                for (UI_form_struct *UI_form_pointer_1 = UI_manager_class::root; UI_form_pointer_1->next!=NULL; UI_form_pointer_1 = UI_form_pointer_1->next)
                {
                    if ((UI_form_pointer_1->data.active) && (UI_form_pointer_1->next != NULL))
                    {
                        UI_form_pointer_2 = UI_form_pointer_1->next;
                        //swap data
                        UI_form_pointer_3->data = UI_form_pointer_1->data;
                        UI_form_pointer_1->data = UI_form_pointer_2->data;
                        UI_form_pointer_2->data = UI_form_pointer_3->data;
                        break;
                    }
                }
            }
        }
    }
    // ----------------------------- show sorted list ---------------------------
    game.core.log.file_write("------------------ sorted ---------------------");
    int active_count = 0;
    for (UI_form_struct *UI_form_pointer_1 = UI_manager_class::last; UI_form_pointer_1!=NULL; UI_form_pointer_1 = UI_form_pointer_1->previous)
    {
        if (UI_form_pointer_1->data.active) game.core.log.file_write("Active UID found -> ",UI_form_pointer_1->data.UID);
        else game.core.log.file_write("UID not active -> ",UI_form_pointer_1->data.UID);
        if (UI_form_pointer_1->data.active) active_count++;
    }
    game.core.log.file_write("Active window found -> ", active_count);
    game.core.log.file_write("-----------------------------------------------");
}

void UI_manager_class::UI_form_set_active(int UI_form_UID)
{
    //possibly push active window to the top of the list?
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID) UI_form_pointer->data.active  = true;
        else UI_form_pointer->data.active  = false;
    }
};

bool UI_manager_class::UI_form_get_active(int UI_form_UID)
{
    bool return_value = false;
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            return_value = UI_form_pointer->data.active;
        }
    }
    return (return_value);
};

void UI_manager_class::UI_form_set_position(int UI_form_UID_src, int UI_form_UID_dst)
{
    UI_form_struct *UI_form_pointer_src;
    UI_form_pointer_src = UI_manager_class::UI_form_get(UI_form_UID_src);
    UI_form_struct *UI_form_pointer_dst;
    UI_form_pointer_dst = UI_manager_class::UI_form_get(UI_form_UID_dst);
    if ((UI_form_pointer_src != NULL) && (UI_form_pointer_dst != NULL))
    {
        float move_delta_x                         = UI_form_pointer_dst->data.position.x;
        float move_delta_y                         = UI_form_pointer_dst->data.position.y;
        UI_form_pointer_dst->data.position.x       = UI_form_pointer_src->data.position.x;
        UI_form_pointer_dst->data.position.y       = UI_form_pointer_src->data.position.y;
        move_delta_x                               = move_delta_x - UI_form_pointer_dst->data.position.x;
        move_delta_y                               = move_delta_y - UI_form_pointer_dst->data.position.y;
        UI_form_pointer_dst->data.title.position.x     -= move_delta_x;
        UI_form_pointer_dst->data.title.position.y     -= move_delta_y;
        UI_form_pointer_dst->data.title_bar.position.x -= move_delta_x;
        UI_form_pointer_dst->data.title_bar.position.y -= move_delta_y;
        if(UI_form_pointer_dst->data.number_of_elements > 0)
        {
            for (int element_number = 0; element_number < UI_form_pointer_dst->data.number_of_elements; element_number++)
            {
                if (UI_form_pointer_dst->data.element[element_number].active)
                {
                    UI_form_pointer_dst->data.element[element_number].position.x       -= move_delta_x;
                    UI_form_pointer_dst->data.element[element_number].position.y       -= move_delta_y;
                    UI_form_pointer_dst->data.element[element_number].title.position.x -= move_delta_x;
                    UI_form_pointer_dst->data.element[element_number].title.position.y -= move_delta_y;
                }
            }
        }
    }
};

void UI_manager_class::UI_form_mouse_reset(int UI_form_UID)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            UI_form_pointer->data.mouse_delay.value = 0;
            UI_form_pointer->data.mouse_delay.ready = false;
        }
    }
};

void UI_manager_class::UI_form_set_event(int UI_form_UID, int EVENT_ID)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            UI_form_pointer->data.event.id = EVENT_ID;
        }
    }
};

void UI_manager_class::UI_form_transition(int UI_form_UID_src, int UI_form_UID_dst)
{
    UI_manager_class::UI_form_disable(UI_form_UID_src);
    UI_manager_class::UI_form_set_position(UI_form_UID_src,UI_form_UID_dst);
    UI_manager_class::UI_form_mouse_reset(UI_form_UID_dst);
    UI_manager_class::UI_form_mouse_reset(UI_form_UID_src);
    UI_manager_class::UI_form_set_event(UI_form_UID_dst,EVENT_NONE);
    UI_manager_class::UI_form_set_event(UI_form_UID_src,EVENT_NONE);
    UI_manager_class::UI_form_enable(UI_form_UID_dst);
    UI_manager_class::UI_form_set_active(UI_form_UID_dst);
    UI_manager_class::event.id = EVENT_UI_STACK_SORT;
    game.core.io.mouse_button_left = false;
};

void UI_manager_class::render(void)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::last; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->previous)
    {
        // ----------------------------- render UI form ---------------------------------
        if(UI_form_pointer->data.enabled)
        {
            // ------------------------- Render menu background and title -------------------------
            game.texture_manager.draw(UI_form_pointer->data.texture.base,false,UI_form_pointer->data.position.x,UI_form_pointer->data.position.y,UI_form_pointer->data.position.z,UI_form_pointer->data.size.x,UI_form_pointer->data.size.y);
            game.font_manager.write(UI_form_pointer->data.font,UI_form_pointer->data.title_color.r,UI_form_pointer->data.title_color.g,UI_form_pointer->data.title_color.b,UI_form_pointer->data.title_color.a,UI_form_pointer->data.title.position.x,UI_form_pointer->data.title.position.y,UI_form_pointer->data.title.size.x,UI_form_pointer->data.title.size.y,UI_form_pointer->data.title.text);
            // ------------------------- Render elements -------------------------
            if (UI_form_pointer->data.number_of_elements > 0)
            {
                for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
                {
                    if (UI_form_pointer->data.element[element_number].active)
                    {
                        float zoom_value = (UI_form_pointer->data.element[element_number].zoom.enabled) ? UI_form_pointer->data.element[element_number].zoom.value : 0.0f;
                        float temp_float = 0.0f;
                        if (UI_form_pointer->data.element[element_number].active)
                        {
                            switch (UI_form_pointer->data.element[element_number].type)
                            {
                                case IMAGE:
                                    if (UI_form_pointer->data.element[element_number].selected) game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.highlighted,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                    game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                    if ((UI_form_pointer->data.element[element_number].title.enabled) && (UI_form_pointer->data.element[element_number].mouse_over))
                                    {
                                        game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.highlighted.r,UI_form_pointer->data.element[element_number].color.highlighted.g,UI_form_pointer->data.element[element_number].color.highlighted.b,UI_form_pointer->data.element[element_number].color.highlighted.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                    }
                                break;
                                case BUTTON:
                                    switch (UI_form_pointer->data.element[element_number].state)
                                    {
                                        case NORMAL:
                                            game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.normal.r,UI_form_pointer->data.element[element_number].color.normal.g,UI_form_pointer->data.element[element_number].color.normal.b,UI_form_pointer->data.element[element_number].color.normal.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        case HIGHLIGHTED:
                                            game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.highlighted,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.highlighted.r,UI_form_pointer->data.element[element_number].color.highlighted.g,UI_form_pointer->data.element[element_number].color.highlighted.b,UI_form_pointer->data.element[element_number].color.highlighted.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        case DISABLED:
                                            game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.disabled,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.disabled.r,UI_form_pointer->data.element[element_number].color.disabled.g,UI_form_pointer->data.element[element_number].color.disabled.b,UI_form_pointer->data.element[element_number].color.disabled.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        default:
                                        break;
                                    }
                                break;
                                case TEXTLABEL:
                                    switch (UI_form_pointer->data.element[element_number].state)
                                    {
                                        case NORMAL:
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.normal.r,UI_form_pointer->data.element[element_number].color.normal.g,UI_form_pointer->data.element[element_number].color.normal.b,UI_form_pointer->data.element[element_number].color.normal.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        case HIGHLIGHTED:
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.highlighted.r,UI_form_pointer->data.element[element_number].color.highlighted.g,UI_form_pointer->data.element[element_number].color.highlighted.b,UI_form_pointer->data.element[element_number].color.highlighted.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        case DISABLED:
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.disabled.r,UI_form_pointer->data.element[element_number].color.disabled.g,UI_form_pointer->data.element[element_number].color.disabled.b,UI_form_pointer->data.element[element_number].color.disabled.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        default:
                                        break;
                                    }
                                break;
                                case SLIDER:
                                break;
                                case BAR:
                                    switch (UI_form_pointer->data.element[element_number].state)
                                    {
                                        case NORMAL:
                                            temp_float = (UI_form_pointer->data.element[element_number].value / UI_form_pointer->data.element[element_number].value_max) * (UI_form_pointer->data.element[element_number].size.x+zoom_value);
                                            game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x-((UI_form_pointer->data.element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,temp_float,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.normal.r,UI_form_pointer->data.element[element_number].color.normal.g,UI_form_pointer->data.element[element_number].color.normal.b,UI_form_pointer->data.element[element_number].color.normal.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        case HIGHLIGHTED:
                                            temp_float = (UI_form_pointer->data.element[element_number].value / UI_form_pointer->data.element[element_number].value_max) * (UI_form_pointer->data.element[element_number].size.x+zoom_value);
                                            game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.highlighted,false,UI_form_pointer->data.element[element_number].position.x-((UI_form_pointer->data.element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,temp_float,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.highlighted.r,UI_form_pointer->data.element[element_number].color.highlighted.g,UI_form_pointer->data.element[element_number].color.highlighted.b,UI_form_pointer->data.element[element_number].color.highlighted.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
                                        break;
                                        case DISABLED:
                                            temp_float = (UI_form_pointer->data.element[element_number].value / UI_form_pointer->data.element[element_number].value_max) * (UI_form_pointer->data.element[element_number].size.x+zoom_value);
                                            game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.disabled,false,UI_form_pointer->data.element[element_number].position.x-((UI_form_pointer->data.element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,temp_float,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                            if (UI_form_pointer->data.element[element_number].title.enabled) game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.disabled.r,UI_form_pointer->data.element[element_number].color.disabled.g,UI_form_pointer->data.element[element_number].color.disabled.b,UI_form_pointer->data.element[element_number].color.disabled.a,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.size.x,UI_form_pointer->data.element[element_number].title.size.y,UI_form_pointer->data.element[element_number].title.text);
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
                                    if (UI_form_pointer->data.element[element_number].value > -1)
                                    {
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
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
            if (UI_form_pointer->data.number_of_elements > 0)
            {
                for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
                {
                    if (UI_form_pointer->data.element[element_number].active)
                    {
                        if ((UI_form_pointer->data.element[element_number].active) && (UI_form_pointer->data.element[element_number].tooltip.enabled))
                        {
                            if (UI_form_pointer->data.element[element_number].mouse_over)
                            {
                                if ((UI_form_pointer->data.element[element_number].tooltip.enabled) && (UI_form_pointer->data.element[element_number].tooltip.image_enabled))
                                {
                                    float temp_size_x = UI_form_pointer->data.element[element_number].tooltip.image_size.x;
                                    float temp_size_y = UI_form_pointer->data.element[element_number].tooltip.image_size.y;
                                    game.texture_manager.draw(UI_form_pointer->data.element[element_number].tooltip.image,false,game.core.io.mouse_x+(temp_size_x*0.25f),game.core.io.mouse_y+(temp_size_y*0.25f),UI_form_pointer->data.element[element_number].tooltip.position.z,temp_size_x,temp_size_y,UI_form_pointer->data.element[element_number].texture.angle);
                                }
                                game.font_manager.write(UI_form_pointer->data.element[element_number].font,UI_form_pointer->data.element[element_number].color.highlighted.r,UI_form_pointer->data.element[element_number].color.highlighted.g,UI_form_pointer->data.element[element_number].color.highlighted.b,UI_form_pointer->data.element[element_number].color.highlighted.a,game.core.io.mouse_x,game.core.io.mouse_y,UI_form_pointer->data.element[element_number].tooltip.size.x,UI_form_pointer->data.element[element_number].tooltip.size.y,UI_form_pointer->data.element[element_number].tooltip.text);
                            }
                        }
                    }
                }
            }
        }
        // -------------------------------------------------------------------------------
    }
};

void UI_manager_class::process(void)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        // ----------------------------- process UI form ---------------------------------
        event_struct return_value;
        float        drag_delta_x      = 0.0f;
        float        drag_delta_y      = 0.0f;
        bool         return_mouse_over = false;
        bool         allow_drag        = true;
        bool         window_in_focus   = true;
        return_value.id                = EVENT_NONE;
        if (UI_form_pointer->data.enabled)
        {
            // ------------------------- Process mouse delay -------------------------
            if (UI_form_pointer->data.mouse_delay.enabled)
            {
                UI_form_pointer->data.mouse_delay.value++;
                if (UI_form_pointer->data.mouse_delay.value >= UI_form_pointer->data.mouse_delay.maximum)
                {
                    UI_form_pointer->data.mouse_delay.ready = true;
                    UI_form_pointer->data.mouse_delay.value = UI_form_pointer->data.mouse_delay.maximum;
                }
            }
            // ------------------------- Process elements -------------------------
            if ((UI_form_pointer->data.number_of_elements > 0) && (!UI_form_pointer->data.drag_active))
            {
                for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
                {
                    if ((UI_form_pointer->data.element[element_number].active) && ((return_value.id == EVENT_NONE) || (return_value.id == EVENT_ELEMENT_DRAG)))
                    {
                        // ---------------------------------------------------------------------------------------
                        UI_form_pointer->data.element[element_number].mouse_over = (game.core.physics.point_in_quadrangle(UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].size.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].size.y,game.core.io.mouse_x,game.core.io.mouse_y));
                        float drag_delta_x = 0.0f;
                        float drag_delta_y = 0.0f;
                        bool  allow_drag   = UI_form_pointer->data.element[element_number].dragable;
                        bool  allow_process = true;
                        UI_form_pointer->data.element[element_number].clicked = false;
                        // ------------------------- Process mouse delay -------------------------
                        if (UI_form_pointer->data.element[element_number].mouse_delay.enabled)
                        {
                            UI_form_pointer->data.element[element_number].mouse_delay.value++;
                            if (UI_form_pointer->data.element[element_number].mouse_delay.value >= UI_form_pointer->data.element[element_number].mouse_delay.maximum)
                            {
                                UI_form_pointer->data.element[element_number].mouse_delay.ready = true;
                                UI_form_pointer->data.element[element_number].mouse_delay.value = UI_form_pointer->data.element[element_number].mouse_delay.maximum;
                            }
                        }
                        // ------------------------- -------------------------
                        if ((UI_form_pointer->data.element[element_number].event.id == EVENT_ELEMENT_MOUSE_RIGHT) || (UI_form_pointer->data.element[element_number].event.id == EVENT_ELEMENT_MOUSE_LEFT)) UI_form_pointer->data.element[element_number].event.id = EVENT_NONE;
                        if (!UI_form_pointer->data.element[element_number].active) allow_process = false;
                        if ((UI_form_pointer->data.element[element_number].type == ITEM) && (UI_form_pointer->data.element[element_number].value < 0)) allow_process = false;
                        if (allow_process)
                        {
                            if (UI_form_pointer->data.element[element_number].state != DISABLED)
                            {
                                // ------------------------- Drag n drop -------------------------
                                if (UI_form_pointer->data.element[element_number].drag_active)
                                {
                                    if (game.core.io.mouse_button_left)
                                    {
                                        drag_delta_x = UI_form_pointer->data.element[element_number].position.x;
                                        drag_delta_y = UI_form_pointer->data.element[element_number].position.y;
                                        UI_form_pointer->data.element[element_number].position.x = game.core.io.mouse_x + UI_form_pointer->data.element[element_number].drag_offset_x;
                                        UI_form_pointer->data.element[element_number].position.y = game.core.io.mouse_y + UI_form_pointer->data.element[element_number].drag_offset_y;
                                        drag_delta_x = drag_delta_x - UI_form_pointer->data.element[element_number].position.x;
                                        drag_delta_y = drag_delta_y - UI_form_pointer->data.element[element_number].position.y;
                                        UI_form_pointer->data.element[element_number].title.position.x     -= drag_delta_x;
                                        UI_form_pointer->data.element[element_number].title.position.y     -= drag_delta_y;
                                    }
                                    else
                                    {
                                        /*
                                        int window_over  = game.UI_manager.mouse_over_window();
                                        int window_from  = UI_form_pointer->data.element[element_number].window_UID;
                                        int element_from = UI_form_pointer->data.element[element_number].element_UID;
                                        int element_over = 0;
                                        UI_form_pointer->data.element[element_number].position.x = UI_form_pointer->data.element[element_number].position_origional.x;
                                        UI_form_pointer->data.element[element_number].position.y = UI_form_pointer->data.element[element_number].position_origional.y;
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
                                        UI_form_pointer->data.element[element_number].drag_active  = false;
                                        UI_form_pointer->data.element[element_number].event.id     = EVENT_NONE;
                                    }
                                }
                                else
                                {
                                    if ((UI_form_pointer->data.element[element_number].dragable) && (window_in_focus) && (UI_form_pointer->data.element[element_number].mouse_over) && (!game.UI_manager.drag_in_progress))
                                    {
                                        if ((game.core.io.mouse_button_left) && (allow_drag))// start drag
                                        {
                                            UI_form_pointer->data.element[element_number].position_origional.x   = UI_form_pointer->data.element[element_number].position.x;
                                            UI_form_pointer->data.element[element_number].position_origional.y   = UI_form_pointer->data.element[element_number].position.y;
                                            UI_form_pointer->data.element[element_number].drag_offset_x          = UI_form_pointer->data.element[element_number].position.x - game.core.io.mouse_x;
                                            UI_form_pointer->data.element[element_number].drag_offset_y          = UI_form_pointer->data.element[element_number].position.y - game.core.io.mouse_y;
                                            UI_form_pointer->data.element[element_number].drag_active            = true;
                                            game.UI_manager.drag_in_progress         = true;
                                            game.UI_manager.element_drag_in_progress = true;
                                        }
                                    }
                                }
                                if (UI_form_pointer->data.element[element_number].mouse_over)
                                {
                                    // ----------------- highlighting element ------------------------------
                                    if (window_in_focus)
                                    {
                                        if ((UI_form_pointer->data.element[element_number].state  != HIGHLIGHTED) && (UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled)) game.sound_manager.play(UI_form_pointer->data.element[element_number].sound.on_mouse_over.sound);
                                        UI_form_pointer->data.element[element_number].state        = HIGHLIGHTED;
                                    }
                                    else
                                    {
                                        UI_form_pointer->data.element[element_number].state        = NORMAL;
                                    }
                                    // ------------------------- clicked element -------------------------
                                    float dragged_by_x = 0.0f;
                                    float dragged_by_y = 0.0f;
                                    if (UI_form_pointer->data.element[element_number].position_origional.x > UI_form_pointer->data.element[element_number].position.x) dragged_by_x = UI_form_pointer->data.element[element_number].position_origional.x - UI_form_pointer->data.element[element_number].position.x;
                                    else dragged_by_x = UI_form_pointer->data.element[element_number].position.x - UI_form_pointer->data.element[element_number].position_origional.x;
                                    if (UI_form_pointer->data.element[element_number].position_origional.y > UI_form_pointer->data.element[element_number].position.y) dragged_by_y = UI_form_pointer->data.element[element_number].position_origional.y - UI_form_pointer->data.element[element_number].position.y;
                                    else dragged_by_y = UI_form_pointer->data.element[element_number].position.y - UI_form_pointer->data.element[element_number].position_origional.y;
                                    if (((dragged_by_x < 0.01f) && (dragged_by_y < 0.01f) && (window_in_focus)) || ((!game.UI_manager.drag_in_progress) && (window_in_focus)))
                                    {
                                        if (UI_form_pointer->data.element[element_number].click_enabled)
                                        {
                                            if (((game.core.io.mouse_button_left) || (game.core.io.mouse_button_right)) && (UI_form_pointer->data.element[element_number].mouse_over))
                                            {
                                                if((UI_form_pointer->data.element[element_number].mouse_delay.ready) || (!UI_form_pointer->data.element[element_number].mouse_delay.enabled))
                                                {
                                                    if (game.core.io.mouse_button_right) UI_form_pointer->data.element[element_number].event.id = EVENT_ELEMENT_MOUSE_RIGHT;
                                                    if (game.core.io.mouse_button_left)  UI_form_pointer->data.element[element_number].event.id = EVENT_ELEMENT_MOUSE_LEFT;
                                                    if (UI_form_pointer->data.element[element_number].sound.on_click.enabled) game.sound_manager.play(UI_form_pointer->data.element[element_number].sound.on_click.sound);
                                                    UI_form_pointer->data.element[element_number].clicked = true;
                                                    if (UI_form_pointer->data.element[element_number].mouse_delay.enabled)
                                                    {
                                                        UI_form_pointer->data.element[element_number].mouse_delay.ready = false;
                                                        UI_form_pointer->data.element[element_number].mouse_delay.value = 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    UI_form_pointer->data.element[element_number].state = NORMAL;
                                }
                            }
                            if (UI_form_pointer->data.element[element_number].state == HIGHLIGHTED)
                            {
                                UI_form_pointer->data.element[element_number].zoom.value += UI_form_pointer->data.element[element_number].zoom.speed;
                                if (UI_form_pointer->data.element[element_number].zoom.value > UI_form_pointer->data.element[element_number].zoom.maximum) UI_form_pointer->data.element[element_number].zoom.value = UI_form_pointer->data.element[element_number].zoom.maximum;
                            }
                            if ((UI_form_pointer->data.element[element_number].state != HIGHLIGHTED) && (UI_form_pointer->data.element[element_number].zoom.value > 0.0f))
                            {
                                UI_form_pointer->data.element[element_number].zoom.value -= UI_form_pointer->data.element[element_number].zoom.speed;
                                if (UI_form_pointer->data.element[element_number].zoom.value < 0.0f) UI_form_pointer->data.element[element_number].zoom.value = 0.0f;
                            }
                        }
                        else UI_form_pointer->data.element[element_number].event.id = EVENT_NONE;
                        return_value.id = UI_form_pointer->data.element[element_number].event.id;
                        // ------------------------------------------------------------------------------------------
                        if (return_value.id != EVENT_NONE)
                        {
                            return_value.id += (element_number * EVENT_BUTTON_MULTIPLIER);
                            allow_drag       = false;
                        }
                        if (UI_form_pointer->data.element[element_number].mouse_over)
                        {
                            allow_drag        = false;
                            return_mouse_over = true;
                        }
                    }
                }
            }
            //-----------------------------------------------------------------------------------------------------
            //if (window_in_focus)
            if (return_value.id == EVENT_NONE)
            {
                // ------------------------- Drag -------------------------
                if (!game.UI_manager.drag_in_progress)
                {
                    UI_form_pointer->data.mouse_over_menu = (game.core.physics.point_in_quadrangle(UI_form_pointer->data.position.x,UI_form_pointer->data.size.x,UI_form_pointer->data.position.y,UI_form_pointer->data.size.y,game.core.io.mouse_x,game.core.io.mouse_y));
                }
                if (!game.UI_manager.drag_in_progress)
                {
                    UI_form_pointer->data.mouse_over_title = (game.core.physics.point_in_quadrangle(UI_form_pointer->data.title_bar.position.x,UI_form_pointer->data.title_bar.size.x,UI_form_pointer->data.title_bar.position.y,UI_form_pointer->data.title_bar.size.y,game.core.io.mouse_x,game.core.io.mouse_y));
                }
                if (UI_form_pointer->data.drag_active)
                {
                    if (game.core.io.mouse_button_left)
                    {
                        drag_delta_x = UI_form_pointer->data.position.x;
                        drag_delta_y = UI_form_pointer->data.position.y;
                        UI_form_pointer->data.position.x = game.core.io.mouse_x + UI_form_pointer->data.drag_offset_x;
                        UI_form_pointer->data.position.y = game.core.io.mouse_y + UI_form_pointer->data.drag_offset_y;
                        drag_delta_x = drag_delta_x - UI_form_pointer->data.position.x;
                        drag_delta_y = drag_delta_y - UI_form_pointer->data.position.y;
                        UI_form_pointer->data.title.position.x     -= drag_delta_x;
                        UI_form_pointer->data.title.position.y     -= drag_delta_y;
                        UI_form_pointer->data.title_bar.position.x -= drag_delta_x;
                        UI_form_pointer->data.title_bar.position.y -= drag_delta_y;
                        if(UI_form_pointer->data.number_of_elements > 0)
                        {
                            for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
                            {
                                if (UI_form_pointer->data.element[element_number].active)
                                {
                                    UI_form_pointer->data.element[element_number].position.x       -= drag_delta_x;
                                    UI_form_pointer->data.element[element_number].position.y       -= drag_delta_y;
                                    UI_form_pointer->data.element[element_number].title.position.x -= drag_delta_x;
                                    UI_form_pointer->data.element[element_number].title.position.y -= drag_delta_y;
                                }
                            }
                        }
                    }
                    else
                    {
                        UI_form_pointer->data.drag_active             = false;
                        game.UI_manager.drag_in_progress  = false;
                    }
                }
                else
                {
                    if ((UI_form_pointer->data.drag_enabled) && (window_in_focus))
                    {
                        if ((!game.UI_manager.drag_in_progress) && (UI_form_pointer->data.mouse_over_title) && (game.core.io.mouse_button_left) && (allow_drag))// start drag
                        {
                            UI_form_pointer->data.drag_offset_x                = UI_form_pointer->data.position.x - game.core.io.mouse_x;
                            UI_form_pointer->data.drag_offset_y                = UI_form_pointer->data.position.y - game.core.io.mouse_y;
                            UI_form_pointer->data.drag_active                  = true;
                            game.UI_manager.drag_in_progress              = true;
                            return_value.id                               = EVENT_UI_STACK_SORT;
                        }
                    }
                    // user clicked on window, that is not title or an element.
                    if ((game.core.io.mouse_button_left) && (return_value.id == EVENT_NONE) && (!UI_form_pointer->data.active))
                    {
                        return_value.id = EVENT_UI_STACK_SORT;
                    }
                }
                // ------------------------- X -------------------------
                if (!UI_form_pointer->data.mouse_over_title) UI_form_pointer->data.mouse_over_title = return_mouse_over;
            }
        }
        //if (return_value > 0) game.core.log.file_write("returning event -> ",return_value, " - from UID - ", UI_form_pointer->data.UID);
        //if (return_value == EVENT_UI_STACK_SORT) game.core.log.file_write("returning event -> ",return_value, " - from UID - ", UI_form_pointer->data.UID);
        UI_form_pointer->data.event = return_value;
        // ----------------------------- process UI form events ---------------------------------
        if (UI_form_pointer->data.enabled)
        {
            if (game.UI_manager.event.id == EVENT_NONE)
            {
                switch(UI_form_pointer->data.UID)
                {
                    case UID_MENU_MAIN:
                        process_menu_main(UI_form_pointer);
                    break;
                    case UID_MENU_GAME_NEW:
                        process_menu_game_new(UI_form_pointer);
                    break;
                    case UID_MENU_GAME_LOAD:
                        process_menu_game_load(UI_form_pointer);
                    break;
                    case UID_MENU_GAME_SAVE:
                        process_menu_game_save(UI_form_pointer);
                    break;
                    case UID_MENU_OPTIONS:
                        process_menu_options(UI_form_pointer);
                    break;
                    case UID_PCPROFILE:
                        process_player_profile(UI_form_pointer);
                    break;
                    case UID_ACTIONBAR:
                        process_action_bar(UI_form_pointer);
                    break;
                    case UID_CHARACTER:
                        process_character_window(UI_form_pointer);
                    break;
                    case UID_EQUIPMENT:
                        process_equipment_window(UI_form_pointer);
                    break;
                    case UID_INVENTORY:
                        process_inventory_window(UI_form_pointer);
                    break;
                    case UID_QUEST_LOG:
                        process_quest_log_window(UI_form_pointer);
                    break;
                    case UID_SKILLBOOK:
                        process_skillbook_window(UI_form_pointer);
                    break;
                    default:
                        game.core.log.file_write("Unable to process UID - ",UI_form_pointer->data.UID);
                    break;
                }
            }
        }
        // -------------------------------------------------------------------------------
    }
    switch (game.UI_manager.event.id)
    {
        case EVENT_UI_STACK_SORT: //window has requested a window stack sort;
            game.UI_manager.UI_form_stack_sort();
            game.UI_manager.event.id = EVENT_NONE;
        break;
        default:
            game.UI_manager.event.id = EVENT_NONE;
        break;
    }
};
