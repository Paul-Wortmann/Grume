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
#include "../game/game.hpp"
#include "../core/misc.hpp"

extern game_class         game;

UI_manager_class::UI_manager_class(void)
{
    UI_manager_class::data.event.id             = EVENT_NONE;
    UI_manager_class::data.event.value          = EVENT_VALUE_NONE;
    UI_manager_class::data.number_of_UI_forms   = 0;
}

UI_form_struct *UI_manager_class::UI_form_add(int UI_form_UID)
{
    if (UI_manager_class::data.number_of_UI_forms == 0)
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
    UI_manager_class::last->data.enabled                            = false;
    UI_manager_class::last->data.set_behind                         = false;
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
    UI_manager_class::last->data.size.x                             = 0.0f;
    UI_manager_class::last->data.size.y                             = 0.0f;
    UI_manager_class::last->data.size.z                             = 0.0f;
    UI_manager_class::last->data.title_bar.text                     = NULL;
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
    UI_manager_class::last->data.title.text                         = NULL;
    UI_manager_class::last->data.UID                                = UI_form_UID;
    UI_manager_class::last->data.zoom.enabled                       = true;
    UI_manager_class::last->data.zoom.maximum                       = 0.01f;
    UI_manager_class::last->data.zoom.value                         = 0.0f;
    UI_manager_class::last->data.zoom.speed                         = 0.001f;
    UI_manager_class::data.number_of_UI_forms++;
    return (UI_manager_class::last);
};

void UI_manager_class::setup_textures(void)
{
    // - Normal item tool tip -
    UI_manager_class::data.tooltip_textures.normal.background  = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_manager_class::data.tooltip_textures.normal.divider     = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_divider_2.png");
    UI_manager_class::data.tooltip_textures.normal.header      = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_header_2.png");
    UI_manager_class::data.tooltip_textures.normal.socket      = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_socket.png");
    // - Magic item tool tip -
    UI_manager_class::data.tooltip_textures.magic.background   = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_manager_class::data.tooltip_textures.magic.divider      = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_divider_1.png");
    UI_manager_class::data.tooltip_textures.magic.header       = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_header_1.png");
    UI_manager_class::data.tooltip_textures.magic.socket       = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_socket.png");
    // - Epic item tool tip -
    UI_manager_class::data.tooltip_textures.epic.background    = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_manager_class::data.tooltip_textures.epic.divider       = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_divider_0.png");
    UI_manager_class::data.tooltip_textures.epic.header        = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_header_0.png");
    UI_manager_class::data.tooltip_textures.epic.socket        = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_socket.png");
    // - Set item tool tip -
    UI_manager_class::data.tooltip_textures.setitem.background = game.texture_manager.add_texture("data/textures/UI/menu/item_stat_background.png");
    UI_manager_class::data.tooltip_textures.setitem.divider    = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_divider_3.png");
    UI_manager_class::data.tooltip_textures.setitem.header     = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_header_3.png");
    UI_manager_class::data.tooltip_textures.setitem.socket     = game.texture_manager.add_texture("data/textures/UI/menu/tooltip_socket.png");
};

void UI_manager_class::setup(void)
{
    UI_manager_class::setup_textures();
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
    //--- Enable windows. ---
    UI_manager_class::UI_form_enable(UID_MENU_MAIN);
    //--- sort the list ---
    UI_manager_class::UI_form_list_sort();
    // --- Allow specific textures to be rotated ----
    texture_type *temp_pointer;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_normal.png");
    temp_pointer->data.rotate_able = true;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_highlighted.png");
    temp_pointer->data.rotate_able = true;
    temp_pointer = game.texture_manager.add_texture("data/textures/UI/menu/arrow_disabled.png");
    temp_pointer->data.rotate_able = true;
    //UI_manager_class::UI_form_list_log();
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
};

void UI_manager_class::UI_form_disable(int UI_form_UID)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            UI_form_pointer->data.enabled = false;
        }
    }
};

bool UI_manager_class::UI_form_is_enable(int UI_form_UID)
{
    bool return_value = false;
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if (UI_form_pointer->data.UID == UI_form_UID)
        {
            return_value = UI_form_pointer->data.enabled;
        }
    }
    return (return_value);
};

int UI_manager_class::UI_form_get_list_position(int UI_form_UID)
{
    int return_value = 0;
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        return_value++;
        if (UI_form_pointer->data.UID == UI_form_UID) break;
    }
    return (return_value);
};

bool UI_manager_class::UI_form_get_is_top_of_list(int UI_form_UID)
{
    UI_form_struct *UI_form_pointer = UI_manager_class::root;
    for (UI_form_pointer = UI_manager_class::root; UI_form_pointer->next != NULL; UI_form_pointer = UI_form_pointer->next);
    return (UI_form_pointer->data.UID == UI_form_UID);
};

void UI_manager_class::UI_form_list_sort(void)
{
    if ((UI_manager_class::data.number_of_UI_forms > 1) && (!UI_manager_class::data.element_drag_in_progress))
    {
        UI_form_struct *UI_form_pointer_2;
        UI_form_struct *UI_form_pointer_3;
        UI_form_pointer_3 = new UI_form_struct;
        for (UI_form_struct *UI_form_pointer_4 = UI_manager_class::root; UI_form_pointer_4->next!=NULL; UI_form_pointer_4 = UI_form_pointer_4->next)
        {
            for (UI_form_struct *UI_form_pointer_1 = UI_manager_class::root; UI_form_pointer_1->next!=NULL; UI_form_pointer_1 = UI_form_pointer_1->next)
            {
                if ((UI_form_pointer_1->data.enabled) && (!UI_form_pointer_1->data.set_behind) && (UI_form_pointer_1->next != NULL))
                {
                    UI_form_pointer_2 = UI_form_pointer_1->next;
                    UI_form_pointer_3->data = UI_form_pointer_1->data;
                    UI_form_pointer_1->data = UI_form_pointer_2->data;
                    UI_form_pointer_2->data = UI_form_pointer_3->data;
                }
            }
        }
    }
}

void UI_manager_class::UI_form_list_sort(int UI_form_UID)
{
    if ((UI_manager_class::data.number_of_UI_forms > 1) && (!UI_manager_class::data.element_drag_in_progress) && (UI_manager_class::UI_form_is_enable(UI_form_UID)) && (UI_form_UID <= UI_manager_class::data.number_of_UI_forms) && (UI_form_UID >= 0))
    {
        //game.core.log.file_write("Pushing form to list top -> ",UI_form_UID);
        //UI_form_list_log();
        UI_form_struct *UI_form_pointer_2;
        UI_form_struct *UI_form_pointer_3;
        UI_form_pointer_3 = new UI_form_struct;
        while (!UI_manager_class::UI_form_get_is_top_of_list(UI_form_UID))
        {
            for (UI_form_struct *UI_form_pointer_4 = UI_manager_class::root; UI_form_pointer_4->next!=NULL; UI_form_pointer_4 = UI_form_pointer_4->next)
            {
                for (UI_form_struct *UI_form_pointer_1 = UI_manager_class::root; UI_form_pointer_1->next!=NULL; UI_form_pointer_1 = UI_form_pointer_1->next)
                {
                    if ((UI_form_pointer_1->data.enabled) && (!UI_form_pointer_1->data.set_behind) && (UI_form_pointer_1->next != NULL))
                    {
                        UI_form_pointer_2 = UI_form_pointer_1->next;
                        if (UI_form_pointer_2->data.UID != UI_form_UID)
                        {
                            UI_form_pointer_3->data = UI_form_pointer_1->data;
                            UI_form_pointer_1->data = UI_form_pointer_2->data;
                            UI_form_pointer_2->data = UI_form_pointer_3->data;
                        }
                    }
                }
            }
        }
    }
}

void UI_manager_class::UI_form_list_log(void)
{
    int list_pos = 0;
    game.core.log.file_write("------------------------------------------");
    game.core.log.file_write("| UI list status                         |");
    game.core.log.file_write("------------------------------------------");
    game.core.log.file_write("| Active   | List pos| Set Behind  | UID |");
    for (UI_form_struct *UI_form_pointer_tmp = UI_manager_class::root; UI_form_pointer_tmp != NULL; UI_form_pointer_tmp = UI_form_pointer_tmp->next)
    {
        if (UI_form_pointer_tmp->data.enabled&&UI_form_pointer_tmp->data.set_behind)
        {
            if (list_pos < 10) game.core.log.file_write("| Enabled  |    ",list_pos,"    | Set_behind  | ",UI_form_pointer_tmp->data.UID);
            else  game.core.log.file_write("| Enabled  |    ",list_pos,"   | Set_behind  | ",UI_form_pointer_tmp->data.UID);
        }
        if (!UI_form_pointer_tmp->data.enabled&&UI_form_pointer_tmp->data.set_behind)
        {
            if (list_pos < 10) game.core.log.file_write("| Disabled |    ",list_pos,"    | Set_behind  | ",UI_form_pointer_tmp->data.UID);
            else game.core.log.file_write("| Disabled |    ",list_pos,"   | Set_behind  | ",UI_form_pointer_tmp->data.UID);
        }
        if (UI_form_pointer_tmp->data.enabled&&!UI_form_pointer_tmp->data.set_behind)
        {
            if (list_pos < 10) game.core.log.file_write("| Enabled  |    ",list_pos,"    | normal      | ",UI_form_pointer_tmp->data.UID);
            else game.core.log.file_write("| Enabled  |    ",list_pos,"   | normal      | ",UI_form_pointer_tmp->data.UID);
        }
        if (!UI_form_pointer_tmp->data.enabled&&!UI_form_pointer_tmp->data.set_behind)
        {
            if (list_pos < 10) game.core.log.file_write("| Disabled |    ",list_pos,"    | normal      | ",UI_form_pointer_tmp->data.UID);
            else game.core.log.file_write("| Disabled |    ",list_pos,"   | normal      | ",UI_form_pointer_tmp->data.UID);
        }
        list_pos++;
    }
    game.core.log.file_write("| List size -> ",UI_manager_class::data.number_of_UI_forms);
    game.core.log.file_write("------------------------------------------");
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

int UI_manager_class::UI_form_mouse_over_element(int UI_form_UID)
{
    int return_value = MOUSE_OVER_MAP;
    UI_form_struct*  UI_form_pointer  = UI_form_get(UI_form_UID);
    for (int element_count = 0; element_count < UI_form_pointer->data.number_of_elements; element_count++)
    {
        if ((UI_form_pointer->data.element[element_count].active) && (UI_form_pointer->data.element[element_count].drag_active) && (UI_form_pointer->data.element[element_count].mouse_over))
        {
            return_value = element_count;
        }
    }
    return (return_value);
};

int UI_manager_class::UI_form_mouse_over_element(int UI_form_UID, int UI_element_number)
{
    int return_value = MOUSE_OVER_MAP;
    UI_form_struct*  UI_form_pointer  = UI_manager_class::UI_form_get(UI_form_UID);
    for (int element_count = 0; element_count < UI_form_pointer->data.number_of_elements; element_count++)
    {
        if ((element_count != UI_element_number) || (return_value == MOUSE_OVER_MAP))
        {
            if ((UI_form_pointer->data.element[element_count].active) && (UI_form_pointer->data.element[element_count].mouse_over))
            {
                return_value = element_count;
            }
        }
    }
    return (return_value);
};

int UI_manager_class::UI_form_mouse_over_form(int UI_form_UID)
{
    int return_value = MOUSE_OVER_MAP;
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if ((UI_form_pointer->data.UID != UI_form_UID) || (return_value == MOUSE_OVER_MAP))
        {
            if ((UI_form_pointer->data.enabled) && (UI_form_pointer->data.mouse_over_menu))
            {
                return_value = UI_form_pointer->data.UID;
            }
        }
    }
    return (return_value);
};

int  UI_manager_class::UI_form_mouse_over_form(void)
{
    int return_value = MOUSE_OVER_MAP;
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if ((UI_form_pointer->data.enabled) && (UI_form_pointer->data.mouse_over_menu))
        {
            return_value = UI_form_pointer->data.UID;
        }
    }
    return (return_value);
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
    UI_manager_class::data.event.id    = EVENT_UI_LIST_SORT;
    UI_manager_class::data.event.value = UI_form_UID_dst;
    game.core.io.mouse_button_left = false;
};

void UI_manager_class::render(void)
{
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        // ----------------------------- render UI form ---------------------------------
        if(UI_form_pointer->data.enabled)
        {
            // ------------------------- Render menu background and title -------------------------
            game.texture_manager.draw(UI_form_pointer->data.texture.base,false,UI_form_pointer->data.position.x,UI_form_pointer->data.position.y,UI_form_pointer->data.position.z,UI_form_pointer->data.size.x,UI_form_pointer->data.size.y);
            if (UI_form_pointer->data.title.text) game.texture_manager.draw(UI_form_pointer->data.title.text,false,UI_form_pointer->data.title.position.x,UI_form_pointer->data.title.position.y,UI_form_pointer->data.title.position.z,UI_form_pointer->data.title.text->data.width,UI_form_pointer->data.title.text->data.height);
            // ------------------------- Render elements -------------------------
            if (UI_form_pointer->data.number_of_elements > 0)
            {
                for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
                {
                    if (UI_form_pointer->data.element[element_number].active)
                    {
                        float zoom_value = (UI_form_pointer->data.element[element_number].zoom.enabled) ? UI_form_pointer->data.element[element_number].zoom.value : 0.0f;
                        float temp_float = 0.0f;
                        switch (UI_form_pointer->data.element[element_number].type)
                        {
                            case UI_ELEMENT_IMAGE:
                                if (UI_form_pointer->data.element[element_number].selected) game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.highlighted,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                if ((UI_form_pointer->data.element[element_number].title.enabled) && (UI_form_pointer->data.element[element_number].mouse_over))
                                {
                                    game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                }
                            break;
                            case UI_ELEMENT_BUTTON:
                                switch (UI_form_pointer->data.element[element_number].state)
                                {
                                    case UI_NORMAL:
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    case UI_HIGHLIGHTED:
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.highlighted,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    case UI_DISABLED:
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.disabled,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    default:
                                    break;
                                }
                            break;
                            case UI_ELEMENT_TEXTLABEL:
                                switch (UI_form_pointer->data.element[element_number].state)
                                {
                                    case UI_NORMAL:
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    case UI_HIGHLIGHTED:
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    case UI_DISABLED:
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    default:
                                    break;
                                }
                            break;
                            case UI_ELEMENT_SLIDER:
                            break;
                            case UI_ELEMENT_BAR:
                                switch (UI_form_pointer->data.element[element_number].state)
                                {
                                    case UI_NORMAL:
                                        temp_float = (UI_form_pointer->data.element[element_number].value / UI_form_pointer->data.element[element_number].value_max) * (UI_form_pointer->data.element[element_number].size.x+zoom_value);
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x-((UI_form_pointer->data.element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,temp_float,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    case UI_HIGHLIGHTED:
                                        temp_float = (UI_form_pointer->data.element[element_number].value / UI_form_pointer->data.element[element_number].value_max) * (UI_form_pointer->data.element[element_number].size.x+zoom_value);
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.highlighted,false,UI_form_pointer->data.element[element_number].position.x-((UI_form_pointer->data.element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,temp_float,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    case UI_DISABLED:
                                        temp_float = (UI_form_pointer->data.element[element_number].value / UI_form_pointer->data.element[element_number].value_max) * (UI_form_pointer->data.element[element_number].size.x+zoom_value);
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.disabled,false,UI_form_pointer->data.element[element_number].position.x-((UI_form_pointer->data.element[element_number].size.x/2)+zoom_value)+(temp_float/2.0f),UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,temp_float,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                        if (UI_form_pointer->data.element[element_number].title.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,UI_form_pointer->data.element[element_number].title.position.x,UI_form_pointer->data.element[element_number].title.position.y,UI_form_pointer->data.element[element_number].title.position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    break;
                                    default:
                                    break;
                                }
                            break;
                            case UI_ELEMENT_TOGGLE:
                            break;
                            case UI_ELEMENT_CHECKBOX:
                            break;
                            case UI_ELEMENT_DROPDOWN:
                            break;
                            case UI_ELEMENT_SELECTION:
                            break;
                            case UI_ELEMENT_ITEM:
                                if ((UI_form_pointer->data.element[element_number].value > -1)&&(!UI_form_pointer->data.element[element_number].drag_active))
                                {
                                    game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                                    if ((!UI_form_pointer->data.element[element_number].drag_active)&&(UI_form_pointer->data.element[element_number].quantity > 1))
                                    {
                                        UI_form_pointer->data.element[element_number].title.text = new texture_type;
                                        float temp_x = UI_form_pointer->data.element[element_number].position.x - (UI_form_pointer->data.element[element_number].size.x/2.5f);
                                        float temp_y = UI_form_pointer->data.element[element_number].position.y - (UI_form_pointer->data.element[element_number].size.y/2.5f);
                                        game.texture_manager.load_string(UI_form_pointer->data.element[element_number].title.text,game.font_manager.root,int_to_string(UI_form_pointer->data.element[element_number].quantity),0.8f,255,255,255,255,TEXTURE_RENDER_LEFT);
                                        game.texture_manager.draw(UI_form_pointer->data.element[element_number].title.text,false,temp_x,temp_y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].title.text->data.width,UI_form_pointer->data.element[element_number].title.text->data.height);
                                    }
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
    }
    // ------------------------- Render element tool tips -------------------------
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if ((UI_form_pointer->data.enabled) && (UI_form_pointer->data.mouse_over_menu))
        {
            if (UI_form_pointer->data.number_of_elements > 0)
            {
                for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
                {
                    if ((!UI_manager_class::data.element_drag_in_progress)&&(UI_form_pointer->data.element[element_number].mouse_over)&&(UI_form_pointer->data.element[element_number].active)&&(UI_form_pointer->data.element[element_number].state == UI_HIGHLIGHTED))
                    {
                        if ((UI_form_pointer->data.element[element_number].tooltip.enabled) && (UI_form_pointer->data.element[element_number].tooltip.image_enabled))
                        {
                            float temp_size_x = UI_form_pointer->data.element[element_number].tooltip.image_size.x;
                            float temp_size_y = UI_form_pointer->data.element[element_number].tooltip.image_size.y;
                            game.texture_manager.draw(UI_form_pointer->data.element[element_number].tooltip.image,false,game.core.io.mouse_x+(temp_size_x*0.25f),game.core.io.mouse_y+(temp_size_y*0.25f),UI_form_pointer->data.element[element_number].tooltip.position.z,temp_size_x,temp_size_y,UI_form_pointer->data.element[element_number].texture.angle);
                        }
                        if (UI_form_pointer->data.element[element_number].tooltip.enabled) game.texture_manager.draw(UI_form_pointer->data.element[element_number].tooltip.text,false,game.core.io.mouse_x,game.core.io.mouse_y,UI_form_pointer->data.element[element_number].tooltip.position.z,UI_form_pointer->data.element[element_number].tooltip.text->data.width,UI_form_pointer->data.element[element_number].tooltip.text->data.height);
                        // ------------------- Display Item stats -----------------------------
                        if ((UI_form_pointer->data.element[element_number].type == UI_ELEMENT_ITEM)&&(UI_form_pointer->data.element[element_number].value >= 0))
                        {
                            std::string   temp_string         = "";
                            std::string   sign_string         = " ";
                            effect_type*  effect_pointer      = new effect_type;
                            item_type*    item_pointer        = new item_type;
                            item_type*    socket_item_pointer = new item_type;
                            texture_type* texture_pointer     = new texture_type;
                            item_pointer = game.item_manager.add_item(UI_form_pointer->data.element[element_number].value);
                            float texture_background_x = game.core.io.mouse_x;
                            float texture_background_y = game.core.io.mouse_y;
                            float texture_background_size_x = 0.0f;
                            float texture_background_size_y = 0.0f;
                            float texture_divider_size_x = 0.0f;
                            float texture_divider_size_y = 0.0f;
                            texture_type* texture_pointer_name = new texture_type;
                            texture_pointer_name = game.texture_manager.add_texture(game.font_manager.root,item_pointer->data.name.c_str(),0.8f,0,0,255,255,255,255,TEXTURE_STRING);
                            texture_pointer_name->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                            float texture_background_padding = texture_pointer_name->data.height;
                            float texture_header_size_y      = texture_background_padding*2;
                            float texture_temp_x = texture_background_x+(texture_background_padding/2.0f);
                            float texture_temp_y = texture_background_y-(texture_background_padding/2.0f);
                            float texture_background_size_x_temp = texture_pointer_name->data.width;
                            if (item_pointer->data.number_of_item_sockets > 0)
                            {
                                for (int socket_count = 0; socket_count < item_pointer->data.number_of_item_sockets; socket_count++)
                                {
                                    texture_background_size_y += texture_background_padding;
                                    if (item_pointer->data.socket[socket_count].enabled)
                                    {
                                        int effect_count = 0;
                                        socket_item_pointer = game.item_manager.add_item(item_pointer->data.socket[socket_count].value);
                                        effect_pointer = game.effect_manager.add_effect(socket_item_pointer->data.effect[effect_count].type);
                                        if (socket_item_pointer->data.effect[effect_count].value >  0) sign_string = "+";
                                        if (socket_item_pointer->data.effect[effect_count].value == 0) sign_string = " ";
                                        if (socket_item_pointer->data.effect[effect_count].value <  0) sign_string = "-";
                                        temp_string = effect_pointer->data.name + " -> " + sign_string + int_to_string(socket_item_pointer->data.effect[effect_count].value);
                                        texture_pointer = game.texture_manager.add_texture(game.font_manager.root,temp_string.c_str(),0.8f,0,0,255,255,255,255,TEXTURE_STRING);
                                        game.texture_manager.draw(texture_pointer,false,texture_temp_x+texture_background_padding,texture_temp_y,UI_form_pointer->data.element[element_number].position.z,texture_pointer->data.width,texture_pointer->data.height);
                                        if (texture_pointer->data.width+texture_background_padding > texture_background_size_x_temp) texture_background_size_x_temp = texture_pointer->data.width+texture_background_padding;
                                    }
                                }
                                texture_background_size_y += texture_background_padding;
                            }
                            if (item_pointer->data.number_of_item_effects > 0)
                            {
                                texture_background_size_y += (texture_background_padding/2.0f);
                                for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                                {
                                    if (item_pointer->data.effect[effect_count].enabled)
                                    {
                                        effect_pointer = game.effect_manager.add_effect(item_pointer->data.effect[effect_count].type);
                                        temp_string = effect_pointer->data.name + " -> " + int_to_string(item_pointer->data.effect[effect_count].value);
                                        texture_pointer = game.texture_manager.add_texture(game.font_manager.root,temp_string.c_str(),0.8f,0,0,255,255,255,255,TEXTURE_STRING);
                                        if (texture_pointer->data.width > texture_background_size_x_temp) texture_background_size_x_temp = texture_pointer->data.width;
                                        texture_background_size_y += texture_background_padding;
                                    }
                                }
                            }
                            texture_background_size_x += texture_background_size_x_temp+(texture_background_padding*1.5f);
                            texture_background_size_y += texture_pointer_name->data.height+texture_background_padding;
                            switch (item_pointer->data.qaulity_type)
                            {
                                case ITEM_QUALITY_MAGIC:
                                    game.UI_manager.data.tooltip_textures.magic.background->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.UI_manager.data.tooltip_textures.magic.header->data.render_positioning     = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.magic.background,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_background_size_y);
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.magic.header    ,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_header_size_y);
                                break;
                                case ITEM_QUALITY_EPIC:
                                    game.UI_manager.data.tooltip_textures.epic.background->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.UI_manager.data.tooltip_textures.epic.header->data.render_positioning     = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.epic.background,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_background_size_y);
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.epic.header    ,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_header_size_y);
                                break;
                                case ITEM_QUALITY_SET:
                                    game.UI_manager.data.tooltip_textures.setitem.background->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.UI_manager.data.tooltip_textures.setitem.header->data.render_positioning     = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.setitem.background,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_background_size_y);
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.setitem.header    ,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_header_size_y);
                                break;
                                case ITEM_QUALITY_NORMAL:
                                default:
                                    game.UI_manager.data.tooltip_textures.normal.background->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.UI_manager.data.tooltip_textures.normal.header->data.render_positioning     = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.normal.background,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_background_size_y);
                                    game.texture_manager.draw(game.UI_manager.data.tooltip_textures.normal.header    ,false,texture_background_x,texture_background_y,UI_form_pointer->data.element[element_number].position.z,texture_background_size_x,texture_header_size_y);
                                break;
                            };
                            game.texture_manager.draw(texture_pointer_name,false,texture_temp_x,texture_temp_y,UI_form_pointer->data.element[element_number].position.z,texture_pointer_name->data.width,texture_pointer_name->data.height);
                            if (item_pointer->data.number_of_item_effects > 0)
                            {
                                texture_temp_y -= (texture_background_padding/2.0f);
                                for (int effect_count = 0; effect_count < item_pointer->data.number_of_item_effects; effect_count++)
                                {
                                    if (item_pointer->data.effect[effect_count].enabled)
                                    {
                                        effect_pointer = game.effect_manager.add_effect(item_pointer->data.effect[effect_count].type);
                                        texture_temp_y -= texture_background_padding;
                                        if (item_pointer->data.effect[effect_count].value >  0) sign_string = "+";
                                        if (item_pointer->data.effect[effect_count].value == 0) sign_string = " ";
                                        if (item_pointer->data.effect[effect_count].value <  0) sign_string = "-";
                                        temp_string = effect_pointer->data.name + " -> " + sign_string + int_to_string(item_pointer->data.effect[effect_count].value);
                                        texture_pointer = game.texture_manager.add_texture(game.font_manager.root,temp_string.c_str(),0.8f,0,0,255,255,255,255,TEXTURE_STRING);
                                        texture_pointer->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                        game.texture_manager.draw(texture_pointer,false,texture_temp_x,texture_temp_y,UI_form_pointer->data.element[element_number].position.z,texture_pointer->data.width,texture_pointer->data.height);
                                    }
                                }
                            }
                            if (item_pointer->data.number_of_item_sockets > 0)
                            {
                                texture_divider_size_x = texture_background_size_x - texture_background_padding;
                                texture_divider_size_y = texture_background_padding/4.0f;
                                texture_temp_y -= (texture_background_padding);
                                switch (item_pointer->data.qaulity_type)
                                {
                                    case ITEM_QUALITY_MAGIC:
                                        texture_pointer = game.UI_manager.data.tooltip_textures.magic.divider;
                                    break;
                                    case ITEM_QUALITY_EPIC:
                                        texture_pointer = game.UI_manager.data.tooltip_textures.epic.divider;
                                    break;
                                    case ITEM_QUALITY_SET:
                                        texture_pointer = game.UI_manager.data.tooltip_textures.setitem.divider;
                                    break;
                                    case ITEM_QUALITY_NORMAL:
                                    default:
                                        texture_pointer = game.UI_manager.data.tooltip_textures.normal.divider;
                                    break;
                                }
                                texture_pointer->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                game.texture_manager.draw(texture_pointer,false,texture_temp_x,texture_temp_y-texture_background_padding/4.0f,UI_form_pointer->data.element[element_number].position.z,texture_divider_size_x,texture_divider_size_y);
                                for (int socket_count = 0; socket_count < item_pointer->data.number_of_item_sockets; socket_count++)
                                {
                                    texture_temp_y -= (texture_background_padding);
                                    switch (item_pointer->data.qaulity_type)
                                    {
                                        case ITEM_QUALITY_MAGIC:
                                            texture_pointer = game.UI_manager.data.tooltip_textures.magic.socket;
                                        break;
                                        case ITEM_QUALITY_EPIC:
                                            texture_pointer = game.UI_manager.data.tooltip_textures.epic.socket;
                                        break;
                                        case ITEM_QUALITY_SET:
                                            texture_pointer = game.UI_manager.data.tooltip_textures.setitem.socket;
                                        break;
                                        case ITEM_QUALITY_NORMAL:
                                        default:
                                            texture_pointer = game.UI_manager.data.tooltip_textures.normal.socket;
                                        break;
                                    }
                                    texture_pointer->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                    game.texture_manager.draw(texture_pointer,false,texture_temp_x,texture_temp_y,UI_form_pointer->data.element[element_number].position.z,texture_background_padding,texture_background_padding);
                                    if (item_pointer->data.socket[socket_count].enabled)
                                    {
                                        int effect_count = 0;
                                        socket_item_pointer = game.item_manager.add_item(item_pointer->data.socket[socket_count].value);
                                        texture_pointer = socket_item_pointer->data.image;
                                        texture_pointer->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                        game.texture_manager.draw(texture_pointer,false,texture_temp_x,texture_temp_y,UI_form_pointer->data.element[element_number].position.z,texture_background_padding,texture_background_padding);
                                        effect_pointer = game.effect_manager.add_effect(socket_item_pointer->data.effect[effect_count].type);
                                        if (socket_item_pointer->data.effect[effect_count].value >  0) sign_string = "+";
                                        if (socket_item_pointer->data.effect[effect_count].value == 0) sign_string = " ";
                                        if (socket_item_pointer->data.effect[effect_count].value <  0) sign_string = "-";
                                        temp_string = effect_pointer->data.name + " -> " + sign_string + int_to_string(socket_item_pointer->data.effect[effect_count].value);
                                        texture_pointer = game.texture_manager.add_texture(game.font_manager.root,temp_string.c_str(),0.8f,0,0,255,255,255,255,TEXTURE_STRING);
                                        texture_pointer->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                        game.texture_manager.draw(texture_pointer,false,texture_temp_x+texture_background_padding,texture_temp_y,UI_form_pointer->data.element[element_number].position.z,texture_pointer->data.width,texture_pointer->data.height);
                                    }
                                    else
                                    {
                                        texture_pointer = game.texture_manager.add_texture(game.font_manager.root,"Empty socket",0.8f,0,0,255,255,255,255,TEXTURE_STRING);
                                        texture_pointer->data.render_positioning = TEXTURE_RENDER_DOWN+TEXTURE_RENDER_LEFT;
                                        game.texture_manager.draw(texture_pointer,false,texture_temp_x+texture_background_padding,texture_temp_y,UI_form_pointer->data.element[element_number].position.z,texture_pointer->data.width,texture_pointer->data.height);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    // render dragged item
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        if ((UI_form_pointer->data.enabled) && (UI_form_pointer->data.number_of_elements > 0))
        {
            for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
            {
                if ((UI_form_pointer->data.element[element_number].type == UI_ELEMENT_ITEM) && (UI_form_pointer->data.element[element_number].value > -1) && (UI_form_pointer->data.element[element_number].drag_active))
                {
                    float zoom_value = (UI_form_pointer->data.element[element_number].zoom.enabled) ? UI_form_pointer->data.element[element_number].zoom.value : 0.0f;
                    game.texture_manager.draw(UI_form_pointer->data.element[element_number].texture.normal,false,UI_form_pointer->data.element[element_number].position.x,UI_form_pointer->data.element[element_number].position.y,UI_form_pointer->data.element[element_number].position.z,UI_form_pointer->data.element[element_number].size.x+zoom_value,UI_form_pointer->data.element[element_number].size.y+zoom_value,UI_form_pointer->data.element[element_number].texture.angle);
                }
            }
        }
    }
};

event_struct  UI_manager_class::process_form_elements(UI_form_struct *UI_form_pointer,bool window_in_focus)
{
    event_struct      return_value;
    return_value.id = EVENT_NONE;
    // ------------------------- Process elements -------------------------
    if ((UI_form_pointer->data.number_of_elements > 0) && (!UI_form_pointer->data.drag_active))
    {
        for (int element_number = 0; element_number < UI_form_pointer->data.number_of_elements; element_number++)
        {
            if ((UI_form_pointer->data.element[element_number].active) && ((return_value.id == EVENT_NONE) || (return_value.id == EVENT_UI_ELEMENT_DRAG)))
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
                if ((UI_form_pointer->data.element[element_number].type == UI_ELEMENT_ITEM) && (UI_form_pointer->data.element[element_number].value < 0)) allow_process = false;
                if (allow_process)
                {
                    if (UI_form_pointer->data.element[element_number].state != UI_DISABLED)
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
                                int window_from  = UI_form_pointer->data.UID;
                                int element_from = UI_form_pointer->data.element[element_number].element_UID;
                                int window_over  = game.UI_manager.UI_form_mouse_over_form(window_from);
                                int element_over = 0;
                                UI_form_pointer->data.element[element_number].position.x = UI_form_pointer->data.element[element_number].position_origional.x;
                                UI_form_pointer->data.element[element_number].position.y = UI_form_pointer->data.element[element_number].position_origional.y;
                                if (window_over != MOUSE_OVER_MAP)
                                {
                                    element_over = game.UI_manager.UI_form_mouse_over_element(window_over,element_from);
                                    if (element_over != MOUSE_OVER_MAP)
                                    {
                                        swap_elements(window_from,element_from,window_over,element_over);
                                    }
                                }
                                game.UI_manager.data.element_drag_in_progress              = false;
                                game.UI_manager.data.drag_in_progress                      = false;
                                UI_form_pointer->data.element[element_number].drag_active  = false;
                                UI_form_pointer->data.element[element_number].event.id     = EVENT_NONE;
                            }
                        }
                        else
                        {
                            if ((UI_form_pointer->data.element[element_number].dragable) && (window_in_focus) && (UI_form_pointer->data.element[element_number].mouse_over) && (!game.UI_manager.data.drag_in_progress))
                            {
                                if ((game.core.io.mouse_button_left) && (allow_drag))// start drag
                                {
                                    UI_form_pointer->data.element[element_number].position_origional.x   = UI_form_pointer->data.element[element_number].position.x;
                                    UI_form_pointer->data.element[element_number].position_origional.y   = UI_form_pointer->data.element[element_number].position.y;
                                    UI_form_pointer->data.element[element_number].drag_offset_x          = UI_form_pointer->data.element[element_number].position.x - game.core.io.mouse_x;
                                    UI_form_pointer->data.element[element_number].drag_offset_y          = UI_form_pointer->data.element[element_number].position.y - game.core.io.mouse_y;
                                    UI_form_pointer->data.element[element_number].drag_active            = true;
                                    game.UI_manager.data.drag_in_progress         = true;
                                    game.UI_manager.data.element_drag_in_progress = true;
                                }
                            }
                        }
                        if (UI_form_pointer->data.element[element_number].mouse_over)
                        {
                            // ----------------- highlighting element ------------------------------
                            if (window_in_focus)
                            {
                                if ((UI_form_pointer->data.element[element_number].state  != UI_HIGHLIGHTED) && (UI_form_pointer->data.element[element_number].sound.on_mouse_over.enabled)) game.sound_manager.play(UI_form_pointer->data.element[element_number].sound.on_mouse_over.sound);
                                UI_form_pointer->data.element[element_number].state        = UI_HIGHLIGHTED;
                            }
                            else
                            {
                                UI_form_pointer->data.element[element_number].state        = UI_NORMAL;
                            }
                            // ------------------------- clicked element -------------------------
                            float dragged_by_x = 0.0f;
                            float dragged_by_y = 0.0f;
                            if (UI_form_pointer->data.element[element_number].position_origional.x > UI_form_pointer->data.element[element_number].position.x) dragged_by_x = UI_form_pointer->data.element[element_number].position_origional.x - UI_form_pointer->data.element[element_number].position.x;
                            else dragged_by_x = UI_form_pointer->data.element[element_number].position.x - UI_form_pointer->data.element[element_number].position_origional.x;
                            if (UI_form_pointer->data.element[element_number].position_origional.y > UI_form_pointer->data.element[element_number].position.y) dragged_by_y = UI_form_pointer->data.element[element_number].position_origional.y - UI_form_pointer->data.element[element_number].position.y;
                            else dragged_by_y = UI_form_pointer->data.element[element_number].position.y - UI_form_pointer->data.element[element_number].position_origional.y;
                            if (((dragged_by_x < 0.01f) && (dragged_by_y < 0.01f) && (window_in_focus)) || ((!game.UI_manager.data.drag_in_progress) && (window_in_focus)))
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
                            UI_form_pointer->data.element[element_number].state = UI_NORMAL;
                        }
                    }
                    if (UI_form_pointer->data.element[element_number].state == UI_HIGHLIGHTED)
                    {
                        UI_form_pointer->data.element[element_number].zoom.value += UI_form_pointer->data.element[element_number].zoom.speed;
                        if (UI_form_pointer->data.element[element_number].zoom.value > UI_form_pointer->data.element[element_number].zoom.maximum) UI_form_pointer->data.element[element_number].zoom.value = UI_form_pointer->data.element[element_number].zoom.maximum;
                    }
                    if ((UI_form_pointer->data.element[element_number].state != UI_HIGHLIGHTED) && (UI_form_pointer->data.element[element_number].zoom.value > 0.0f))
                    {
                        UI_form_pointer->data.element[element_number].zoom.value -= UI_form_pointer->data.element[element_number].zoom.speed;
                        if (UI_form_pointer->data.element[element_number].zoom.value < 0.0f) UI_form_pointer->data.element[element_number].zoom.value = 0.0f;
                    }
                }
                else UI_form_pointer->data.element[element_number].event.id = EVENT_NONE;
                return_value.id    = UI_form_pointer->data.element[element_number].event.id;
                // ------------------------------------------------------------------------------------------
                if (return_value.id != EVENT_NONE)
                {
                    return_value.value = UI_form_pointer->data.UID;
                    return_value.id += (element_number * EVENT_BUTTON_MULTIPLIER);
                    allow_drag       = false;
                }
                if (UI_form_pointer->data.element[element_number].mouse_over)
                {
                    allow_drag        = false;
                }
            }
        }
    }
    return (return_value);
};

void UI_manager_class::process_forms(void)
{
    event_struct      return_value;
    return_value.id    = EVENT_NONE;
    return_value.value = EVENT_VALUE_NONE;
    bool window_in_focus            = true;
    bool front_window_found         = false;
    for (UI_form_struct *UI_form_pointer = UI_manager_class::last; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->previous)
    {
        // ----------------------------- process UI form ---------------------------------
        float        drag_delta_x       = 0.0f;
        float        drag_delta_y       = 0.0f;
        bool         return_mouse_over  = false;
        bool         allow_drag         = true;
        if (UI_form_pointer->data.enabled)
        {
            UI_form_pointer->data.mouse_over_menu = (game.core.physics.point_in_quadrangle(UI_form_pointer->data.position.x,UI_form_pointer->data.size.x,UI_form_pointer->data.position.y,UI_form_pointer->data.size.y,game.core.io.mouse_x,game.core.io.mouse_y));
            if (UI_form_pointer->data.mouse_over_menu)
            {
                if ((!front_window_found) || ((UI_form_pointer->data.set_behind)))
                {
                    window_in_focus    = true;
                    front_window_found = true;
                }
                else window_in_focus = false;
            }
            else window_in_focus = false;
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
            //-----------------------------------------------------------------------------------------------------
            return_value = process_form_elements(UI_form_pointer,window_in_focus);
            //-----------------------------------------------------------------------------------------------------
            if (return_value.id == EVENT_NONE)
            {
                // ------------------------- Drag -------------------------
                if (!game.UI_manager.data.drag_in_progress)
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
                        UI_form_pointer->data.drag_active  = false;
                        game.UI_manager.data.drag_in_progress   = false;
                    }
                }
                else
                {
                    if ((UI_form_pointer->data.drag_enabled) && (window_in_focus))
                    {
                        if ((!game.UI_manager.data.drag_in_progress) && (UI_form_pointer->data.mouse_over_title) && (game.core.io.mouse_button_left) && (allow_drag))// start drag
                        {
                            UI_form_pointer->data.drag_offset_x                = UI_form_pointer->data.position.x - game.core.io.mouse_x;
                            UI_form_pointer->data.drag_offset_y                = UI_form_pointer->data.position.y - game.core.io.mouse_y;
                            UI_form_pointer->data.drag_active                  = true;
                            game.UI_manager.data.drag_in_progress                   = true;
                            if (UI_manager_class::UI_form_get_list_position(UI_form_pointer->data.UID) != UI_manager_class::data.number_of_UI_forms)
                            {
                                return_value.id    = EVENT_UI_FORM_DRAG;
                                return_value.value = UI_form_pointer->data.UID;
                            }
                            //game.core.log.file_write("List size -> ",UI_manager_class::data.number_of_UI_forms);
                            //game.core.log.file_write("UID -> ",UI_form_pointer->data.UID," - Position in list -> ",UI_manager_class::UI_form_get_list_position(UI_form_pointer->data.UID));
                        }
                        if ((!game.UI_manager.data.drag_in_progress) && (!UI_form_pointer->data.mouse_over_title) && (game.core.io.mouse_button_left))
                        {
                            return_value.id    = EVENT_UI_LIST_SORT;
                            return_value.value = UI_form_pointer->data.UID;
                        }
                    }
                    // user clicked on window, that is not title or an element.
                    if ((game.core.io.mouse_button_left) && (return_value.id == EVENT_NONE) && (!UI_form_pointer->data.enabled))
                    {
                        if (UI_manager_class::UI_form_get_list_position(UI_form_pointer->data.UID) != UI_manager_class::data.number_of_UI_forms)
                        {
                            return_value.id    = EVENT_UI_LIST_SORT;
                            return_value.value = UI_form_pointer->data.UID;
                        }
                    }
                }
                // ------------------------- X -------------------------
                if (!UI_form_pointer->data.mouse_over_title) UI_form_pointer->data.mouse_over_title = return_mouse_over;
            }
        }
        UI_form_pointer->data.event = return_value;
        if ((UI_form_pointer->data.event.id == EVENT_UI_LIST_SORT) || (UI_form_pointer->data.event.id == EVENT_UI_FORM_DRAG))
        {
            if (!UI_manager_class::UI_form_get_is_top_of_list(UI_form_pointer->data.UID))
            {
                game.UI_manager.data.event.value = UI_form_pointer->data.UID;
                game.UI_manager.data.event       = return_value;
            }
            UI_form_pointer->data.event.id    = EVENT_NONE;
            UI_form_pointer->data.event.value = EVENT_VALUE_NONE;
        }
    }
};

void UI_manager_class::process(void)
{
    UI_manager_class::process_forms();
    switch (game.UI_manager.data.event.id)
    {
        case EVENT_UI_LIST_SORT:
            if (game.UI_manager.data.drag_in_progress) break;
        case EVENT_UI_FORM_DRAG:
            game.UI_manager.UI_form_list_sort(game.UI_manager.data.event.value);
            game.UI_manager.data.event.id    = EVENT_NONE;
            game.UI_manager.data.event.value = EVENT_VALUE_NONE;
        break;
        default:
            game.UI_manager.data.event.id    = EVENT_NONE;
            game.UI_manager.data.event.value = EVENT_VALUE_NONE;
        break;
    }
    for (UI_form_struct *UI_form_pointer = UI_manager_class::root; UI_form_pointer != NULL; UI_form_pointer = UI_form_pointer->next)
    {
        // ----------------------------- process UI form events ---------------------------------
        if (UI_form_pointer->data.enabled)
        {
            if (game.UI_manager.data.event.id == EVENT_NONE)
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
};

void UI_manager_class::swap_elements(int UI_form_UID_src, int UI_element_src, int UI_form_UID_dst, int UI_element_dst)
{
    bool posible_swap        = true;
    bool allow_swap_elements = false;
    if (((UI_form_UID_src == UID_INVENTORY) || (UI_form_UID_src == UID_ACTIONBAR) || (UI_form_UID_src == UID_EQUIPMENT)) &&
        ((UI_form_UID_dst == UID_INVENTORY) || (UI_form_UID_dst == UID_ACTIONBAR) || (UI_form_UID_dst == UID_EQUIPMENT))) allow_swap_elements = true;
    UI_form_struct* UI_form_UID_src_pointer = game.UI_manager.UI_form_get(UI_form_UID_src);
    UI_form_struct* UI_form_UID_dst_pointer = game.UI_manager.UI_form_get(UI_form_UID_dst);
    item_type* item_pointer_src = game.item_manager.add_item(UI_form_UID_src_pointer->data.element[UI_element_src].value);
    item_type* item_pointer_dst = game.item_manager.add_item(UI_form_UID_dst_pointer->data.element[UI_element_dst].value);
    //game.core.log.file_write("Moving element from - ",UI_form_UID_src," - ",UI_element_src," to - ",UI_form_UID_dst," - ",UI_element_dst);
    if     ((allow_swap_elements)&&(UI_form_UID_src == UI_form_UID_dst)&&(UI_element_src == UI_element_dst)) allow_swap_elements = false;
    if     ((allow_swap_elements)
        &&  (UI_form_UID_src_pointer->data.element[UI_element_src].type == UI_ELEMENT_ITEM)
        &&  (UI_form_UID_dst_pointer->data.element[UI_element_dst].type == UI_ELEMENT_ITEM))
    {
        if     ((UI_form_UID_src_pointer->data.element[UI_element_src].value == UI_form_UID_dst_pointer->data.element[UI_element_dst].value)
            &&  (item_pointer_src->data.stackable)
            &&  (item_pointer_src->data.quantity_max > 1)
            &&  (UI_form_UID_src_pointer->data.element[UI_element_src].quantity >= 1)
            &&  (UI_form_UID_dst_pointer->data.element[UI_element_dst].quantity >= 1)
            &&  (UI_form_UID_src_pointer->data.element[UI_element_src].value >= 0)
            &&  (UI_form_UID_dst_pointer->data.element[UI_element_dst].value >= 0))
        {
            UI_form_UID_dst_pointer->data.element[UI_element_dst].quantity += UI_form_UID_src_pointer->data.element[UI_element_src].quantity;
            if (UI_form_UID_dst_pointer->data.element[UI_element_dst].quantity > item_pointer_src->data.quantity_max)
            {
                UI_form_UID_src_pointer->data.element[UI_element_src].quantity  = UI_form_UID_dst_pointer->data.element[UI_element_dst].quantity - item_pointer_src->data.quantity_max;
                UI_form_UID_dst_pointer->data.element[UI_element_dst].quantity  = item_pointer_src->data.quantity_max;
            }
            else UI_form_UID_src_pointer->data.element[UI_element_src].quantity = 0;
            if (UI_form_UID_src_pointer->data.element[UI_element_src].quantity <= 0)
            {
                UI_form_UID_src_pointer->data.element[UI_element_src].quantity = 0;
                UI_form_UID_src_pointer->data.element[UI_element_src].value    = -1;
            }
            posible_swap = false;
        }
        if   ((item_pointer_dst->data.number_of_item_sockets >= 1) && (item_pointer_src->data.type == ITEM_GEM))
        {
            bool socket_done = false;
            for (int socket_count = 0; socket_count < item_pointer_dst->data.number_of_item_sockets+1; socket_count++)
            {
                if ((!socket_done)&&(!item_pointer_dst->data.socket[socket_count].enabled))
                {
                    socket_done = true;
                    item_pointer_dst->data.socket[socket_count].enabled = true;
                    item_pointer_dst->data.socket[socket_count].type    = item_pointer_src->data.type;
                    item_pointer_dst->data.socket[socket_count].value   = item_pointer_src->data.UID;
                    UI_form_UID_src_pointer->data.element[UI_element_src].quantity = 0;
                    UI_form_UID_src_pointer->data.element[UI_element_src].value    = -1;
                }
            }
            if (socket_done) posible_swap = false;
        }
        if (posible_swap)
        {
            bool allow_swap = false;
            switch (UI_form_UID_dst)
            {
                case UID_ACTIONBAR:
                    if ((item_pointer_src->data.type     == ITEM_POTION) ||
                        (item_pointer_src->data.sub_type == ITEM_POTION_SMALL) ||
                        (item_pointer_src->data.sub_type == ITEM_POTION_MEDIUM) ||
                        (item_pointer_src->data.sub_type == ITEM_POTION_LARGE) ||
                        (item_pointer_src->data.type     == ITEM_SPELL))
                            allow_swap = true;
                break;
                case UID_INVENTORY:
                    switch (UI_form_UID_src)
                    {
                        case UID_ACTIONBAR:
                    if  ((item_pointer_dst->data.type     != ITEM_SPELL)
                    and ((item_pointer_dst->data.type     == ITEM_POTION) ||
                         (item_pointer_dst->data.sub_type == ITEM_POTION_SMALL) ||
                         (item_pointer_dst->data.sub_type == ITEM_POTION_MEDIUM) ||
                         (item_pointer_dst->data.sub_type == ITEM_POTION_LARGE) ||
                         (item_pointer_dst->data.type     == ITEM_SPELL) ||
                         (UI_form_UID_dst_pointer->data.element[UI_element_dst].value == -1)))
                            allow_swap = true;
                        break;
                        case UID_EQUIPMENT:
                            if ((item_pointer_src->data.type == UI_form_UID_dst_pointer->data.element[UI_element_dst].sub_type) ||
                                (UI_form_UID_dst_pointer->data.element[UI_element_dst].value == -1))
                                    allow_swap = true;
                        break;
                        case UID_INVENTORY:
                            allow_swap = true;
                        break;
                        default:
                            allow_swap = false;
                        break;
                    }
                break;
                case UID_EQUIPMENT:
                    if (item_pointer_src->data.type == UI_form_UID_dst_pointer->data.element[UI_element_dst].sub_type)
                        allow_swap = true;
                break;
                default:
                    allow_swap = false;
                break;
            }
            if (allow_swap)
            {
                int temp_value    = UI_form_UID_src_pointer->data.element[UI_element_src].value;
                int temp_quantity = UI_form_UID_src_pointer->data.element[UI_element_src].quantity;
                texture_type* temp_texture_pointer = UI_form_UID_src_pointer->data.element[UI_element_src].texture.normal;
                UI_form_UID_src_pointer->data.element[UI_element_src].value          = UI_form_UID_dst_pointer->data.element[UI_element_dst].value;
                UI_form_UID_src_pointer->data.element[UI_element_src].quantity       = UI_form_UID_dst_pointer->data.element[UI_element_dst].quantity;
                UI_form_UID_src_pointer->data.element[UI_element_src].texture.normal = UI_form_UID_dst_pointer->data.element[UI_element_dst].texture.normal;
                UI_form_UID_dst_pointer->data.element[UI_element_dst].value          = temp_value;
                UI_form_UID_dst_pointer->data.element[UI_element_dst].quantity       = temp_quantity;
                UI_form_UID_dst_pointer->data.element[UI_element_dst].texture.normal = temp_texture_pointer;
                if ((UI_form_UID_src == UID_EQUIPMENT) || (UI_form_UID_dst == UID_EQUIPMENT))
                {
                    if (UI_form_UID_dst == UID_EQUIPMENT)
                    {
                        game.item_manager.equip_item  (item_pointer_src);
                        game.item_manager.unequip_item(item_pointer_dst);
                    }
                    else
                    {
                        game.item_manager.equip_item  (item_pointer_dst);
                        game.item_manager.unequip_item(item_pointer_src);
                    }
                }
            }
        }
        if (item_pointer_src->data.sound_move) game.sound_manager.play(item_pointer_src->data.sound_move);
    }
    else game.sound_manager.play(item_pointer_src->data.sound_move);
};
